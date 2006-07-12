/* LICENCE BLOCK
PiavcaCal3DApp.cpp
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
#endif

#include <iostream>
#include <string>
#include <vector>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "cal3d/cal3d.h"


#include "PiavcaAPI/Avatar.h"
#include "PiavcaAPI/TrackMotion.h"
#include "PiavcaAPI/LoopMotion.h"
#include "PiavcaAPI/PiavcaError.h"
#include "PiavcaNVCLib/OnTheSpot.h"
#include "PiavcaNVCLib/AvatarMotionQueue.h"

#include "PiavcaPythonInterface/PiavcaPythonApp.h"


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
	Piavca::Core::getCore()->timeStep();
    // update the screen
    glutPostRedisplay();	
}

//----------------------------------------------------------------------------//
// GLUT callback functions                                                    //
//----------------------------------------------------------------------------//

void displayFunc()
{
  static float prevTime = Piavca::Core::getCore()->getTime();
  static int framecount = 0;
  static float updateTime = 0;
  static float prerenderTime = 0;
  static float renderTime = 0;

  float time1 = Piavca::Core::getCore()->getTime();
  timeStep();	
  float time2 = Piavca::Core::getCore()->getTime();
  updateTime += time2 - time1;
	 
  g_Params.core->prerender();
  float time3 = Piavca::Core::getCore()->getTime();
  prerenderTime += time3 - time2;

  // clear the vertex and face counters
  //m_vertexCount = 0;
  //m_faceCount = 0;

  // clear all the buffers
  glClearColor(0.0f, 0.0f, 0.3f, 0.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // set the projection transformation
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0f, (GLdouble)g_Params.width / (GLdouble)g_Params.height, 0.01, 10000);

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
  glRotatef(g_Params.tiltAngle, 1.0f, 0.0f, 0.0f);
  glRotatef(g_Params.twistAngle, 0.0f, 0.0f, 1.0f);
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

//----------------------------------------------------------------------------//
// Main entry point of the application                                        //
//----------------------------------------------------------------------------//

int main(int argc, char *argv[])
{
	std::string path = "";
#ifndef WIN32
  for(int i = 0; i < argc-1; i++)
  {
  	if(std::string(argv[i]) == "-path")
  	{
  		path = std::string(argv[i+1]) + "/";
  		chdir(path.c_str());
  		argc = argc - 2;
  		for ( /*nothing*/; i < argc; i++)
  			argv[i] = argv[i+2];
  		break;
  	}
  }	
#endif
  
	
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

  std::cout << "reading joint names\n";

  std::string jointsFilename = path + "JointNames.txt";
  std::ifstream file(jointsFilename.c_str(), std::ios::in );
  if(!file)
  {
	  Piavca::Error("Failed to open joint names file '" 
	  	+ jointsFilename + "'\n");
  }

  Piavca::StringVector jointVec;
  std::string jointName;
  while(true)
  {
	// read the next model configuration line
    std::string strBuffer;
    std::getline(file, strBuffer);

    // stop if we reached the end of file
    if(file.eof()) 
	{
		Piavca::Core::getCore()->addJointNameSet(jointVec);
		jointVec.clear();
		break;
	}

    // check if an error happend while reading from the file
    if(!file)
    {
		Piavca::Error("Error while reading from the joint names file");
		return NULL;
    }

	// find the first non-whitespace character
    std::string::size_type pos=0, new_pos;

	while (true)
	{
		pos = strBuffer.find_first_not_of(" \t", pos);

		// check for empty lines and comments
		if((pos == std::string::npos) || (strBuffer[pos] == '\n') 
			|| (strBuffer[pos] == '\r') || (strBuffer[pos] == 0)
			|| strBuffer[pos] == '#') 
		{
			if(!jointVec.empty())
			{
				Piavca::Core::getCore()->addJointNameSet(jointVec);
				jointVec.clear();
			}
			break;
		}

		
		if(strBuffer[pos] == '\"')
		{
			pos++;
			new_pos = strBuffer.find_first_of("\"", pos);
			if(new_pos == std::string::npos)
				Piavca::Error("Unmatched quotes in joint names file");
			jointName = strBuffer.substr(pos, new_pos - pos);
			pos = new_pos+1;
		}
		else
		{
			new_pos = strBuffer.find_first_of(" =\t\n\r", pos);
			jointName = strBuffer.substr(pos, new_pos - pos);
			pos = new_pos;
		}
		jointVec.push_back(StringToTString(jointName));
		std::cout << jointName << "; ";
		
	}
  };
  std::cout << std::endl;


  std::string expressionFilename = path + "ExpressionNames.txt";
  std::ifstream expressionFile(expressionFilename.c_str(), std::ios::in );
  if(!expressionFile)
  {
	  Piavca::Error("Failed to open expression names file '" );
  }

  Piavca::StringVector expressionVec;
  std::string expressionName;
  while(true)
  {
	// read the next model configuration line
    std::string strBuffer;
    std::getline(expressionFile, strBuffer);

    // stop if we reached the end of file
    if(expressionFile.eof()) 
	{
		Piavca::Core::getCore()->addExpressionNameSet(expressionVec);
		expressionVec.clear();
		break;
	}

    // check if an error happend while reading from the file
    if(!expressionFile)
    {
		Piavca::Error("Error while reading from the expression names file");
		return NULL;
    }

	// find the first non-whitespace character
    std::string::size_type pos=0, new_pos;

	while (true)
	{
		pos = strBuffer.find_first_not_of(" \t", pos);

		// check for empty lines and comments
		if((pos == std::string::npos) || (strBuffer[pos] == '\n') 
			|| (strBuffer[pos] == '\r') || (strBuffer[pos] == 0)
			|| strBuffer[pos] == '#') 
		{
			if(!jointVec.empty())
			{
				Piavca::Core::getCore()->addExpressionNameSet(expressionVec);
				expressionVec.clear();
			}
			break;
		}

		
		if(strBuffer[pos] == '\"')
		{
			pos++;
			new_pos = strBuffer.find_first_of("\"", pos);
			if(new_pos == std::string::npos)
				Piavca::Error("Unmatched quotes in expression names file");
			expressionName = strBuffer.substr(pos, new_pos - pos);
			pos = new_pos+1;
		}
		else
		{
			new_pos = strBuffer.find_first_of(" =\t\n\r", pos);
			expressionName = strBuffer.substr(pos, new_pos - pos);
			pos = new_pos;
		}
		expressionVec.push_back(StringToTString(expressionName));
		std::cout << expressionName << "; ";
		
	}
  };
  std::cout << std::endl;


  //std::string avatarFilename = "cally";
  //Piavca::Avatar *av = new Piavca::Avatar(avatarFilename);
  //Piavca::Motion *gbo = new Piavca::TrackMotion(StringToTString("gesture_both_out.bvh"), 
	  //Piavca::TRANS_REVERSE_ORDER 
//	  Piavca::TRANS_NEG_X 
//	  | Piavca::TRANS_SWAP_XZ
	  // Piavca::TRANS_NEG_Y 
//	  | Piavca::TRANS_ARM_DOWN);
  //Piavca::Motion *walk = new Piavca::TrackMotion(StringToTString("walk_cycle.bvh"), 
	  //Piavca::TRANS_NEG_Z 
	  //| Piavca::TRANS_SWAP_XZ
	  //| Piavca::TRANS_ARM_DOWN);
  //Piavca::AvatarMotionQueue::getQueue(av)->enqueueMotion("walk", new Piavca::OnTheSpot(new Piavca::LoopMotion(walk)));
  //Piavca::AvatarMotionQueue::getQueue(av)->enqueueMotion("walk", Piavca::Core::getCore()->getMotion("walk");
  //av->setFacialExpressionWeight(Piavca::Core::getCore()->getExpressionId(_T("smile")), 1.0);

  std::cout << "finished loading joints\n";

  Piavca::InitPiavcaPython(Piavca::Core::getCore(), _T("PyTest"));

	//glutSetCursor(GLUT_CURSOR_LEFT_ARROW);

  // run the GLUT message loop
  glutMainLoop();

  
  EndPiavcaPython(Piavca::Core::getCore());

  return 0;
}

//----------------------------------------------------------------------------//
