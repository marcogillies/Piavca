/* LICENCE BLOCK
PiavcaGlut.cpp
Copyright (C) 2005 Marco (Mark) Gillies

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

//----------------------------------------------------------------------------//
// Includes                                                                   //
//----------------------------------------------------------------------------//


//#include "PiavcaNVCLib/Piavca.h"

#ifdef _WIN32
#include <windows.h>
#include <direct.h>
#endif

#include <iostream>
#include <string>
#include <vector>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "PiavcaGlut.h"

#include "cal3d/cal3d.h"

#include "PiavcaAPI/Piavca.h"

//#include "Python.h"

#include "PiavcaPythonInterface/PiavcaPythonApp.h"
//#include "PiavcaPythonInterface/Piavca_wrap.h"


#include "PiavcaCal3dImp/PiavcaCal3dCore.h"

// a structure holding various parameters of the display


struct displayParams
{
	Piavca::PiavcaCal3DCore *core;
	bool zooming, turning;
	int width, height;
	int lastMouseX, lastMouseY;
	float leftright, updown, distance;
	float leftright_delta, updown_delta, zoom_delta;
	float tiltAngle, twistAngle;	
} g_Params;

void timeStep()
{
	static int i =0;
	static float lastTime = Piavca::Core::getCore()->getTime();
	//std::cout << "frame " << i << std::endl;
	//std::cout.flush();
	i++;
	float time = Piavca::Core::getCore()->getTime();
	if(time - lastTime > 1.0)
	{
		//std::cout << time << " " << lastTime << std::endl;
		//std::cout << "frame rate " << i << std::endl;
		i = 0;
		lastTime = time;
	}
	//CalError::printLastError();
	try
	{
	    Piavca::Core::getCore()->timeStep();
	}
	catch (Piavca::Exception &e)
	{
	    std::cout << "Piavca Exception: " <<  e.getDetails() << std::endl;
		//Piavca::PrintPythonErrors();
	}
	//catch (...)
	//{
	//	Piavca::PrintPythonErrors();
	//}
	//Piavca::RunPythonMethod(Piavca::Core::getCore(), "headMove", Piavca::Vec(1, 2, 3));
	//std::cout << TStringToString(Piavca::Core::getCore()->getMessages());
    // update the screen
}

//----------------------------------------------------------------------------//
// GLUT callback functions                                                    //
//----------------------------------------------------------------------------//

int render()
{
	//updates piavca's state
	timeStep();
	//updates mesh
	g_Params.core->prerender();
	
	// render the model
	g_Params.core->render();

	return 0;
}

void displayFunc()
{
  static float prevTime = Piavca::Core::getCore()->getTime();
  static int framecount = 0;
  static float updateTime = 0;
  static float prerenderTime = 0;
  static float renderTime = 0;

  //std::cout << "display function \n";

  float time1 = Piavca::Core::getCore()->getTime();
  timeStep();	
  glutPostRedisplay();	
  float time2 = Piavca::Core::getCore()->getTime();
  updateTime += time2 - time1;
	 
  g_Params.core->prerender();
  float time3 = Piavca::Core::getCore()->getTime();
  prerenderTime += time3 - time2;

  // clear the vertex and face counters
  //m_vertexCount = 0;
  //m_faceCount = 0;

  // clear all the buffers
  //glClearColor(0.0f, 0.0f, 0.3f, 0.0f);
  glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // set the projection transformation
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  //gluPerspective(45.0f, (GLdouble)g_Params.width / (GLdouble)g_Params.height, 0.01, 10000);
  float height = 0.4142135*0.01;
  float width = (height*g_Params.width)/ g_Params.height;
  glFrustum(-(GLdouble)(width),(GLdouble)(width), -(GLdouble)(height),(GLdouble)(height), 0.01, 10000);

  // set the model transformation
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  // light attributes
  const GLfloat light_ambient[]  = { 0.3f, 0.3f, 0.3f, 1.0f };
  const GLfloat light_diffuse[]  = { 0.52f, 0.5f, 0.5f, 1.0f };
  const GLfloat light_specular[] = { 0.1f, 0.1f, 0.1f, 1.0f };

  // setup the light attributes
  glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
  glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

  // set the light position
  GLfloat lightPosition[] = { 0.0f, -1.0f, 1.0f, 1.0f };
  glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

  // set camera position
  glTranslatef(g_Params.leftright, g_Params.updown, 0.0f);
  glTranslatef(0.0f, 0.0f, -g_Params.distance);
  glRotatef(g_Params.twistAngle, 0.0f, 1.0f, 0.0f);
  glRotatef(g_Params.tiltAngle, 1.0f, 0.0f, 0.0f);
  glTranslatef(0.0f, 0.0f, -90.0f);


  // render the model
  g_Params.core->render();

  // swap the front- and back-buffer
  glutSwapBuffers();
  
	float time4 = Piavca::Core::getCore()->getTime();
	renderTime += time4 - time3;
	
	framecount ++;
	float time = Piavca::Core::getCore()->getTime();
	if((time - prevTime) > 10.0)
	{
		std::cout << "framerate " << framecount/(time - prevTime) 
			<< " update time " << updateTime/framecount  
			<< " prerender time " << prerenderTime/framecount  
			<< " render time " << renderTime/framecount << std::endl;
		framecount = 0;
		updateTime = 0.0;
		prerenderTime = 0.0;
		renderTime = 0.0;
		prevTime = time;
	}
  
}

void exitFunc()
{
	delete g_Params.core;
}

void idleFunc()
{


}

void keyboardFunc(unsigned char key, int x, int y)
{
  switch(key)
  {
    // test for quit event
    case 27:
    case 'q':
    case 'Q':
      exit(0);
      break;
	case 'd':
	  g_Params.leftright += g_Params.leftright_delta;
	  break;
	case 'a':
	  g_Params.leftright -= g_Params.leftright_delta;
	  break;
	case 's':
	  g_Params.updown += g_Params.updown_delta;
	  break;
	case 'w':
	  g_Params.updown -= g_Params.updown_delta;
	  break;
	case 'z':
	  g_Params.distance -= g_Params.zoom_delta;
	  break;
	case 'Z':
	  g_Params.distance += g_Params.zoom_delta;
	  break;
	case 'r':
		g_Params.tiltAngle = -70.0f;
		g_Params.twistAngle = -45.0f;
		g_Params.distance = 270.0f;
		g_Params.updown = 0.0f;
		g_Params.leftright = 0.0f;
	  break;
    default:
      break;
  }
}

void motionFunc(int x, int y)
{
  // update twist/tilt angles
  if(g_Params.turning)
  {
    // calculate new angles
    g_Params.twistAngle += (float)(x - g_Params.lastMouseX);
    g_Params.tiltAngle += (float)(y - g_Params.lastMouseY);
  }

  // update distance
  if(g_Params.zooming)
  {
    // calculate new distance
    g_Params.distance -= (float)(y - g_Params.lastMouseY) / 0.02f;
    if(g_Params.distance < 0.0f) g_Params.distance = 0.0f;
  }

  // update internal mouse position
  g_Params.lastMouseX = x;
  g_Params.lastMouseY = y;
}

void mouseFunc(int button, int state, int x, int y)
{
  if(state == GLUT_DOWN)
  {
    if(button == GLUT_LEFT_BUTTON)
	  {
	    g_Params.zooming = true;
	  }
	
	  if(button == GLUT_RIGHT_BUTTON)
	  {
	    g_Params.turning = true;
	  }
	  g_Params.lastMouseX = x;
	  g_Params.lastMouseY = y;
  }
  else if(state == GLUT_UP)
  {
    if(button == GLUT_LEFT_BUTTON)
	  {
	    g_Params.zooming = false;
	  }
	
	  if(button == GLUT_RIGHT_BUTTON)
	  {
	    g_Params.turning = false;
	  }
	  g_Params.lastMouseX = x;
	  g_Params.lastMouseY = y;
  }
}

void reshapeFunc(int w, int h)
{
  // set the new width/height values
  g_Params.width = w;
  g_Params.height = h;
  
  glViewport(0, 0, w, h);
}


void initCore()
{
	g_Params.core = new Piavca::PiavcaCal3DCore();
}

//----------------------------------------------------------------------------//
// Main entry point of the application                                        //
//----------------------------------------------------------------------------//

int init(int argc, char *argv[])
{ 
	
  // initialize the GLUT system
  glutInit(&argc, argv);

  g_Params.core = new Piavca::PiavcaCal3DCore();
  g_Params.zooming = false;
  g_Params.turning = false;
  g_Params.width = 800;
  g_Params.height = 600;
  g_Params.lastMouseX = 0; 
  g_Params.lastMouseY = 0;
  g_Params.leftright = 0; 
  g_Params.leftright_delta = 10; 
  g_Params.updown = 85;  
  g_Params.updown_delta = 10; 
  g_Params.zoom_delta = 3; 
  //g_Params.updown = -100; 
  g_Params.distance = 50;
  //g_Params.distance = 300;
  g_Params.tiltAngle = -90; 
  g_Params.twistAngle = 0;	

  // register our own exit callback
  atexit(exitFunc);

  // set all GLUT modes
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(g_Params.width, g_Params.height);
  glutCreateWindow("Piavca Example App");

  // register all GLUT callback functions
  glutIdleFunc(idleFunc);
  glutMouseFunc(mouseFunc);
  glutMotionFunc(motionFunc);
  glutPassiveMotionFunc(motionFunc);
  glutReshapeFunc(reshapeFunc);
  glutDisplayFunc(displayFunc);
  glutKeyboardFunc(keyboardFunc);

  return 0;
}

int init()
{
	char *name = "PiavcaGlut";
	return init(1, &name);
}

int start()
{
  // run the GLUT message loop
  glutMainLoop();
  return 0;
}

//----------------------------------------------------------------------------//
