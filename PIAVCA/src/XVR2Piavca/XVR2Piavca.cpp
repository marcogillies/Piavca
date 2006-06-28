// XVR2Piavca.cpp : Defines the entry point for the DLL application.
//

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
//#include "stdafx.h"


#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

//----------------------------------------------------------------------------//
// Includes                                                                   //
//----------------------------------------------------------------------------//

#define NO_PIAVCA_DLL
#include "PiavcaNVCLib/Piavca.h"

#ifdef _WIN32
//#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers
#include <windows.h>
#endif

#include <direct.h>

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
#include "PiavcaNVCLib/OnTheSpot.h"
#include "PiavcaNVCLib/AvatarMotionQueue.h"
#include "PiavcaAPI/Quat.h"

#include "PiavcaPythonInterface/PiavcaPythonApp.h"

#include "PiavcaCal3dImp/PiavcaCal3dCore.h"

// called every frame, does the rendering
extern "C" __declspec(dllexport) void displayFunc();
// initialise piavca, passes in a directory to run from 
// and a python script
extern "C" __declspec(dllexport) char* onInitial(char* _path, char * script);
// runs a python method 
extern "C" __declspec(dllexport) char* runMethod(char* method);
// does any clean up needed
extern "C" __declspec(dllexport) void exitFunc();

// returns the last error message/warning
extern "C" __declspec(dllexport) char* GetLastMessage();

char* Str = new char[256];
char* dirFile = new char[256];

Piavca::PiavcaCal3DCore *g_pCore;

// this updates the state of piavca
void timeStep()
{
	Piavca::Core::getCore()->timeStep();
}

//----------------------------------------------------------------------------//
// GLUT callback functions                                                    //
//----------------------------------------------------------------------------//

// call the rendering code
extern "C" __declspec(dllexport) void displayFunc()
{	
	//updates piavca's state
	timeStep();
	//updates mesh
	g_pCore->prerender();
	
	// render the model
	g_pCore->render();
}

// cleans up the state of piavca on exit
extern "C" __declspec(dllexport) void exitFunc()
{
	delete g_pCore;
}

// initialise piavca, passes in a path to a director to run from 
// and a python script file to load
extern "C" __declspec(dllexport) char *onInitial(char* _path, char *script)
{
	try
	{
		int argc = 1;
		char* argv = "piavcaxvr";
		std::string path = dirFile;
		path += "/";
		path += _path;
		path = path + "//";
		//path = ".\\";
  		_chdir(path.c_str());
	  	
		g_pCore = new Piavca::PiavcaCal3DCore();
		/*g_Params.zooming = false;
		g_Params.turning = false;
		g_Params.width = 800;
		g_Params.height = 600;
		g_Params.lastMouseX = 0; 
		g_Params.lastMouseY = 0;
		g_Params.leftright = 0; 
		g_Params.updown = -100; 
		g_Params.distance = 300;
		g_Params.tiltAngle = -90; 
		g_Params.twistAngle = 0;	
		*/
	  
	// write a message to the output that can be read from XVR
#ifdef WIN32
	strcpy_s(Str, 256, "reading joint names");
#else
	strcpy(Str, "reading joint names");
#endif

	// read in the names of joints
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
			//strcpy(Str, jointName);
			
		}
	};
	std::cout << std::endl;

	// read in facial expression names
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


	// load an avatar (this bit is normally done from python)
	//std::string avatarFilename = "cally";
	//Piavca::Avatar *av = new Piavca::Avatar(avatarFilename);
	//Piavca::Motion *walk = Piavca::Core::getCore()->getMotion("walk");
	//Piavca::AvatarMotionQueue::getQueue(av)->enqueueMotion("walk", new Piavca::LoopMotion(walk));
	  
	std::cout << "finished loading joints\n";

	//////////////////////////////////////////////////Str Variable///////////////////////////////////

#ifdef WIN32
	strcpy_s(Str, 256, "finished loading joints");
#else
	strcpy(Str, "finished loading joints");
#endif	

	//////////////////////////////////////////////////Python ///////////////////////////////////////
	// load in a script
	Piavca::tstring tscript = StringToTString(script);
	if(tscript != _T(""))
	{
		Piavca::InitPiavcaPython(Piavca::Core::getCore(), tscript);
	}
  }
  catch (Piavca::Exception &e)
  {
	string s = TStringToString(e.getDetails());
	s._Copy_s(Str, 256, 256);
	//s.copy(Str, 256);

	return Str;
  }


#ifdef WIN32
	strcpy_s(Str, 256, "");
#else
	strcpy(Str, "");
#endif

  return Str;
}

// calls a method defined in python
extern "C" __declspec(dllexport) char* runMethod(char* method)
{
	try 
	{
		RunPythonMethod(Piavca::Core::getCore(), method);
	}
	catch (Piavca::Exception &e)
	{
		string s = TStringToString(e.getDetails());
		s._Copy_s(Str, 256, 256);
		//s.copy(Str, 256);

		return Str;
	}

	
#ifdef WIN32
	strcpy_s(Str, 256, "");
#else
	strcpy(Str, "");
#endif

	return Str;
}

//gets the last error message/warning
extern "C" __declspec(dllexport) char* GetLastMessage()
{
	return Str;
}


BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
	if(ul_reason_for_call == DLL_PROCESS_ATTACH)
		GetCurrentDirectory(256,dirFile);
    return TRUE;
}
