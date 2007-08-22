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

#include "cal3d/cal3d.h"


#include "PiavcaAPI/Avatar.h"
#include "PiavcaAPI/KeyframeMotion.h"
#include "PiavcaAPI/LoopMotion.h"
#include "PiavcaAPI/PiavcaError.h"
#include "PiavcaAPI/PiavcaException.h"
#include "PiavcaAPI/OnTheSpot.h"
#include "PiavcaAPI/AvatarMotionQueue.h"
#include "PiavcaAPI/MotionParser.h"
#include "PiavcaAPI/Vec.h"
#include "PiavcaAPI/Bound.h"


#include "PiavcaCal3dImp/PiavcaCal3dCore.h"

#include "gltb.h"

// a structure holding various parameters of the display

struct displayParams
{
	Piavca::PiavcaCal3DCore *core;
	Piavca::Avatar *avatar;
	int width, height;
	float scaleBias;
	boolean tracking;
} g_Params = 
{
	NULL, 
	NULL,
	800, 600,
	1.0f,
	TRUE
};


//
// Camera control
//


Piavca::Bound initialAvatarBound;
Piavca::Vec initialAvatarRoot;
Piavca::Bound focusBound;
Piavca::Vec focusRoot;


void updateCameraFocus()
{
	// There are a number of ways of doing this.
	// You could get the bounding box each frame, but that would be slow, and the scaling 
	// of the object would changing each frame. To avoid size changing, we take the original bounding box
	// we do need to keep tracking the change in root position.

	Piavca::Avatar *avatar;
	avatar = Piavca::Core::getCore()->getAvatar(0);
	focusRoot = avatar->getRootPosition();
	focusBound.min = initialAvatarBound.min+focusRoot-initialAvatarRoot;
	focusBound.max = initialAvatarBound.max+focusRoot-initialAvatarRoot;
}

void pushCameraFocus()
{
	Piavca::Vec centre = (focusBound.min+focusBound.max)/2.0;
	Piavca::Vec halfWidths = focusBound.max - centre;
	float maxDim = max(max(halfWidths[0],halfWidths[1]), halfWidths[2]); 

	glTranslatef(0.0, 0.0, -3.0);
	gltbMatrix();
	glPushMatrix();
	glScalef(g_Params.scaleBias/maxDim, g_Params.scaleBias/maxDim, g_Params.scaleBias/maxDim);
	glPushMatrix();
	glTranslatef(-centre[0],-centre[1],-centre[2]);
}

void popCameraFocus()
{
	glPopMatrix();
	glPopMatrix();
}

void resetCameraFocus()
{
	g_Params.scaleBias = 1.0;
}

void initCameraFocus()
{
	Piavca::Avatar *avatar;
	avatar = Piavca::Core::getCore()->getAvatar(0);

	initialAvatarBound = avatar->getBoundBox();
	initialAvatarRoot = avatar->getRootPosition();
	updateCameraFocus();	
}

//
// Helper drawing functions
//

GLfloat floorScale = 50.0;
GLfloat floorSize = 500.0;

void drawFloor()
{
	// Center of avatar on floor
	Piavca::Vec centre = (focusBound.min+focusBound.max)/2.0;
	centre[2] = focusBound.min[2];

	centre[0] = ((int)(centre[0]/floorScale))*floorScale;
	centre[1] = ((int)(centre[1]/floorScale))*floorScale;

	{
		int cols = floorSize/floorScale;
		int color = 0;
		glDisable(GL_LIGHTING);
		float x = centre[0] - floorSize/2;
		float y = centre[1] - floorSize/2;
		color = (((int)(x/floorScale)) + ((int)(y/floorScale))) %2;
		for (int i=0;i<cols;i++)
		{
			color += ((cols+1)%2);
			for (int j=0;j<cols;j++)
			{
				color = color++;
				if (color%2 == 0)
				{
					glColor3f(0.5,0.5,0.5);
				}
				else
				{
					glColor3f(0.75,0.75,0.75);
				}
				glBegin(GL_QUADS);
				glVertex3f(x,y,0);
				glVertex3f(x+floorScale,y,0);
				glVertex3f(x+floorScale,y+floorScale,0);
				glVertex3f(x,y+floorScale,0);
				glEnd();
				y += floorScale;
			}
			y = centre[1] - floorSize/2;
			x += floorScale;
		}
		glEnable(GL_LIGHTING);
	}
}

void drawAvatarBound()
{
	glDisable(GL_LIGHTING);
	glColor3f(0.5,1,1);

	Piavca::Vec &v1=focusBound.min;
	Piavca::Vec &v2=focusBound.max;
	glBegin(GL_LINES);
	glVertex3f(v1[0], v1[1], v1[2]);
	glVertex3f(v2[0], v1[1], v1[2]);
	glVertex3f(v1[0], v2[1], v1[2]);
	glVertex3f(v2[0], v2[1], v1[2]);
	glVertex3f(v1[0], v2[1], v2[2]);
	glVertex3f(v2[0], v2[1], v2[2]);
	glVertex3f(v1[0], v1[1], v2[2]);
	glVertex3f(v2[0], v1[1], v2[2]);

	glVertex3f(v1[0], v1[1], v1[2]);
	glVertex3f(v1[0], v2[1], v1[2]);
	glVertex3f(v1[0], v1[1], v2[2]);
	glVertex3f(v1[0], v2[1], v2[2]);
	glVertex3f(v2[0], v1[1], v2[2]);
	glVertex3f(v2[0], v2[1], v2[2]);
	glVertex3f(v2[0], v1[1], v1[2]);
	glVertex3f(v2[0], v2[1], v1[2]);

	glVertex3f(v1[0], v1[1], v1[2]);
	glVertex3f(v1[0], v1[1], v2[2]);
	glVertex3f(v1[0], v2[1], v1[2]);
	glVertex3f(v1[0], v2[1], v2[2]);
	glVertex3f(v2[0], v2[1], v1[2]);
	glVertex3f(v2[0], v2[1], v2[2]);
	glVertex3f(v2[0], v1[1], v1[2]);
	glVertex3f(v2[0], v1[1], v2[2]);

	glEnd();
	glEnable(GL_LIGHTING);
}

//
// Main control functions
//

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
	}
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

  if (g_Params.tracking)
  {
	  updateCameraFocus();
  }

  // clear all the buffers
  //glClearColor(0.0f, 0.0f, 0.3f, 0.0f);
  glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // set the model transformation
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  pushCameraFocus();

  // render the model
  g_Params.core->render();

  // Draw bound box
  //drawAvatarBound(); // Avatar bounding box
  drawFloor(); // Floor object
  popCameraFocus();

  glutSwapBuffers();
  
  //Timing calculations
	float time4 = Piavca::Core::getCore()->getTime();
	renderTime += time4 - time3;
	
	framecount++;
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

void play_motion(int motid)
{
	Piavca::AvatarMotionQueue *amq = Piavca::AvatarMotionQueue::getQueue(g_Params.avatar);
	Piavca::Motion *m = Piavca::Core::getCore()->getMotion(motid);
	if (m == NULL)
	{
		std::cout << "could not find motion\n";
		return;
	}
	std::cout << "playing motion " << m->getName() << std::endl;
	amq->interrupt();
	amq->enqueueMotion(m->getName(), m);
}

void keyboardFunc(unsigned char key, int x, int y)
{
//	gltbKeyboard(key, x, y);
  switch(key)
  {
    // test for quit event
    case 27:
    case 'q':
    case 'Q':
      exit(0);
      break;
	case '-':
	case '_':
		g_Params.scaleBias *= 0.75;
		break;
	case '+':
	case '=':
		g_Params.scaleBias *= 1.25;
		break;
	case ' ':
		g_Params.tracking = !g_Params.tracking;
		break;
	case 'r':
		resetCameraFocus();
	  break;
	case '1':
		play_motion(0);
		break;
	case '2':
		play_motion(1);
		break;
	case '3':
		play_motion(2);
		break;
	case '4':
		play_motion(3);
		break;
	case '5':
		play_motion(4);
		break;
	case '6':
		play_motion(5);
		break;
	case '7':
		play_motion(6);
		break;
	case '8':
		play_motion(7);
		break;
	case '9':
		play_motion(8);
		break;
    default:
      break;
  }
}

void motionFunc(int x, int y)
{
	gltbMotion(x, y);
}

void mouseFunc(int button, int state, int x, int y)
{
  gltbMouse(button, state, x, y);
}

void reshapeFunc(int w, int h)
{
	gltbReshape(w,h);
	// set the new width/height values
	g_Params.width = w;
	g_Params.height = h;

	glMatrixMode(GL_PROJECTION);
	glViewport(0, 0, w, h);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)w/ (GLfloat)h, 1.0, 1024.0);
}

void openglInit()
{
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
	glEnable(GL_NORMALIZE);
	glEnable(GL_DEPTH_TEST);
//	glEnable(GL_CULL_FACE);
}

//----------------------------------------------------------------------------//
// Main entry point of the application                                        //
//----------------------------------------------------------------------------//

void piavcaInit(int argc, char *argv[])
{
	std::string path = "";
	std::string motionfile = "";
	std::string avatarfile = "";

	g_Params.core = new Piavca::PiavcaCal3DCore();

	//#ifndef WIN32
	for(int i = 0; i < argc-1; i++)
	{
		if(std::string(argv[i]) == "-path")
		{
			path = std::string(argv[i+1]) + "/";
#ifdef WIN32
			_chdir(path.c_str());
#else
			chdir(path.c_str());
#endif
			argc = argc - 2;
			for ( /*nothing*/; i < argc; i++)
				argv[i] = argv[i+2];
			//break;
		}
		if(std::string(argv[i]) == "-motions")
		{
			motionfile = std::string(argv[i+1]);
			argc = argc - 2;
			for ( /*nothing*/; i < argc; i++)
				argv[i] = argv[i+2];
			//break;
		}
	}	
	if (argc <= 1)
	{
		std::cout << "no avatar (.cfg) file provided as input\n";
		exit(0);
	}

	avatarfile = std::string(argv[1]);
	argc = argc - 1;
	for ( int i = 1; i < argc; i++)
		argv[i] = argv[i+1];

	int dotpos = avatarfile.find_last_of(".");
	std::cout << avatarfile << " " << dotpos << " ";
	avatarfile = avatarfile.substr(0, dotpos);
	std::cout << avatarfile << std::endl;


	std::cout << "reading joint names\n";
	std::string jointsFilename = path + "JointNames.txt";
	std::ifstream file(jointsFilename.c_str(), std::ios::in );
	if(!file)
	{
		std::cout << "Failed to open joint names file '" 
			<< jointsFilename << "'\n";
	}
	else
	{
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
				exit(-1);
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
	}

	std::string expressionFilename = path + "ExpressionNames.txt";
	std::ifstream expressionFile(expressionFilename.c_str(), std::ios::in );
	if(!expressionFile)
	{
		std::cout << "Failed to open expression names file '" << expressionFilename << std::endl;
	}
	else
	{
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
				exit(-1);
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
					if(!expressionVec.empty())
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
	}

	////////////////////////////////////////////////////////////////////////
	//
	// If you want to just use C++ the code below gives an example of how
	// you might create an avatar, load and play some motions
	//
	////////////////////////////////////////////////////////////////////////

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

	g_Params.avatar = new Piavca::Avatar(avatarfile);
	if(motionfile != "")
	{
		std::ifstream mFile(motionfile.c_str(), std::ios::in );
		if(!mFile)
		{
			std::cout << "Failed to open motion file '" << motionfile << std::endl;
		}
		else
		{
			Piavca::MotionParser::setUpMotionCommands();
			while(true)
			{
				std::string strBuffer;
				std::getline(mFile, strBuffer);

				// stop if we reached the end of file
				if(mFile.eof()) 
				{
					break;
				}

				// check if an error happened while reading from the file
				if(!mFile)
				{
					Piavca::Error("Error while reading from the motion file");
					exit(-1);
				}

				int pos = strBuffer.find_first_not_of(" \t");


				// check for empty lines and comments
				if((pos == std::string::npos) || (strBuffer[pos] == '\n') 
					|| (strBuffer[pos] == '\r') || (strBuffer[pos] == 0)
					|| strBuffer[pos] == '#') 
				{
					continue;
				}

				int new_pos = strBuffer.find_first_of(" =\t\n\r", pos);
				Piavca::tstring motionName = StringToTString(strBuffer.substr(pos, new_pos - pos));
				strBuffer = strBuffer.substr(new_pos);


				Piavca::Motion *m = Piavca::MotionParser::parseMotion(strBuffer);
				Piavca::Core::getCore()->loadMotion(motionName, m);
			}
		}
	}

	std::cout << "Use the number buttons to choose an animation to play\n";
	std::vector<std::string> motionNames = Piavca::Core::getCore()->getMotionNames(9);
	for (int i = 0; i < (int) motionNames.size(); i++)
	{
		std::cout << i+1 << ": " << motionNames[i] << std::endl;
	};

	// Set up bounds for tracking camera
	initCameraFocus();
}

int main(int argc, char *argv[])
{
	// initialize Piavca
	piavcaInit(argc, argv);

	// initialize GLUT
	glutInit(&argc, argv);

	// register the trackball handler
	gltbInit(GLUT_LEFT_BUTTON);
	gltbConfigUp(0.0,0.0,1.0);
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

	// OpenGL initialization
	openglInit();

	glutMainLoop();

	return 0;
}

//----------------------------------------------------------------------------//
