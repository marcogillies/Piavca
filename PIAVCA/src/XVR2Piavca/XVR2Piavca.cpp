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
#include "PiavcaAPI/Piavca.h"

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


#include "PiavcaPythonInterface/PiavcaPythonApp.h"

#include "PiavcaCal3dImp/PiavcaCal3dCore.h"

// called every frame, does the rendering
extern "C" __declspec(dllexport) char* displayFunc();
// initialise piavca, passes in a directory to run from 
// and a python script
extern "C" __declspec(dllexport) char* onInitial(char* _path, char * script);
// runs a python method 
extern "C" __declspec(dllexport) char* runMethod(char* method);
extern "C" __declspec(dllexport) char* runMethodInt(char* method, int arg);
extern "C" __declspec(dllexport) char* runMethodFloat(char* method, float arg);
extern "C" __declspec(dllexport) char* runMethodStr(char* method, char *arg);
extern "C" __declspec(dllexport) char* runMethodVec(char* method, float arg1, float arg2, float arg3);
extern "C" __declspec(dllexport) char* runMethodAngleAxis(char* method, float arg0, float arg1, float arg2, float arg3);
// does any clean up needed
extern "C" __declspec(dllexport) char* exitFunc();

// returns the last error message/warning
extern "C" __declspec(dllexport) char* GetLastMessage();
// gets anything that was printed to cout, generally longer 
// and worder info than GetLastMessage
extern "C" __declspec(dllexport) char* GetLastOutput();

char* Str = new char[2048];
char* dirFile = new char[256];
char* output = new char[1024];

std::ostringstream *_strstrm = NULL;
std::streambuf *_saved_cout = NULL;
std::streambuf *_saved_cerr = NULL;

std::wostringstream *_wstrstrm = NULL;
std::wstreambuf *_saved_wcout = NULL;
std::wstreambuf *_saved_wcerr = NULL;

//Piavca::PiavcaCal3DCore *g_pCore;
void *initScript = NULL;
void *userScript = NULL;

char *get_messages()
{
	//string s = TStringToString(Piavca::Core::getCore()->getMessages());
	//s._Copy_s(Str, 256, 256);
	string s = "";
	if(_strstrm)
	{
		s = _strstrm->str();
	}
	s.copy(Str, 2048);
	if (s.size() < 2048)
		Str[s.size()] = '\0';	
	else
		Str[2047] = '\0';	
	if(_strstrm)
	{
		_strstrm->str("");
	}
	return Str;
}

// this updates the state of piavca
//void timeStep()
//{
//	Piavca::Core::getCore()->timeStep();
//}

//----------------------------------------------------------------------------//
// GLUT callback functions                                                    //
//----------------------------------------------------------------------------//

// call the rendering code
extern "C" __declspec(dllexport) char* displayFunc()
{	
	string s = "";
	if(userScript != NULL)
		s = runMethod("timeStep");
	std::cout << s;
	//std::cout << "rendering\n";
	if(initScript != NULL)
	{
		try 
		{
			RunPythonMethod(Piavca::Core::getCore(), "render", initScript);
			//s = s + "\n" + string(get_messages()) + "\n";
		}
		catch (Piavca::Exception &e)
		{
			//s = s + "\n" + string(get_messages()) + "\n" + TStringToString(e.getDetails());
			//s._Copy_s(Str, 256, 256);
		}
	}
	//s.copy(Str, 1024);
	return get_messages();
	//updates piavca's state
	//timeStep();
	//updates mesh
	//g_pCore->prerender();
	
	// render the model
	//g_pCore->render();
}

// cleans up the state of piavca on exit
extern "C" __declspec(dllexport) char* exitFunc()
{
	std::cout.rdbuf(_saved_cout);
	std::cerr.rdbuf(_saved_cerr);
	std::wcout.rdbuf(_saved_wcout);
	std::wcerr.rdbuf(_saved_wcerr);
	//fclose(stderr);

	//delete g_pCore;

	string s = "";
	if(userScript != NULL)
		s=runMethod("finalize");
	std::cout << s;
	if(initScript != NULL)
	{
		try 
		{
			RunPythonMethod(Piavca::Core::getCore(), "finalize", initScript);
		}
		catch (Piavca::Exception &e)
		{
			std::cout << TStringToString(e.getDetails()) << std::endl;
			//s._Copy_s(Str, 256, 256);
		}
	}
	//s.copy(Str, 2048);
	return get_messages();
	
}

// initialise piavca, passes in a path to a director to run from 
// and a python script file to load
extern "C" __declspec(dllexport) char *onInitial(char* _path, char *script)
{
	//return (char *)0;
	try
	{
		int argc = 1;
		char* argv = "piavcaxvr";
		std::string path = "";//dirFile;
		//path += "/";
		path += _path;
		path = path + "//";
		//path = ".\\";
  		_chdir(path.c_str());
	  	
		//g_pCore = new Piavca::PiavcaCal3DCore();

		_strstrm = new std::ostringstream();
		_saved_cout = std::cout.rdbuf();
		std::cout.rdbuf(_strstrm->rdbuf());
		_saved_cerr = std::cerr.rdbuf();
		std::cerr.rdbuf(_strstrm->rdbuf());
		
		_wstrstrm = new std::wostringstream();
		_saved_wcout = std::wcout.rdbuf();
		std::wcout.rdbuf(_wstrstrm->rdbuf());
		_saved_wcerr = std::wcerr.rdbuf();
		std::wcerr.rdbuf(_wstrstrm->rdbuf());

		string filename = path + "piavcaStdout.txt";
		std::cout << filename << std::endl;
		freopen(filename.c_str(), "w", stdout);
		filename = path + "piavcaStderr.txt";
		std::cout << filename << std::endl;
		freopen(filename.c_str(), "w", stderr);
		//fprintf(stderr, "test");
	  
	// write a message to the output that can be read from XVR
//#ifdef WIN32
//	strcpy_s(Str, 256, "reading joint names");
//#else
	strcpy(Str, "reading joint names");
//#endif

	// read in the names of joints
	/*
	std::string jointsFilename = path + "JointNames.txt";
	std::ifstream file(jointsFilename.c_str(), std::ios::in );
	if(!file)
	{
	  std::cout << "Failed to open joint names file '" << jointsFilename << std::endl;
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
	}

	// read in facial expression names
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


		// load an avatar (this bit is normally done from python)
		//std::string avatarFilename = "cally";
		//Piavca::Avatar *av = new Piavca::Avatar(avatarFilename);
		//Piavca::Motion *walk = Piavca::Core::getCore()->getMotion("walk");
		//Piavca::AvatarMotionQueue::getQueue(av)->enqueueMotion("walk", new Piavca::LoopMotion(walk));
		  
		std::cout << "finished loading joints\n";

		//////////////////////////////////////////////////Str Variable///////////////////////////////////

		//#ifdef WIN32
		//	strcpy_s(Str, 256, "finished loading joints");
		//#else
			strcpy(Str, "finished loading joints");
		//#endif	
	}
    */
	//////////////////////////////////////////////////Python ///////////////////////////////////////
	// load in a script
	Piavca::InitPython();
	try
	{
		initScript = Piavca::ImportModule(_T("initXVRPiavca"));
	}
	catch (Piavca::Exception &e)
	{
		std::cout << "An error occured while importing the Piavca Initialization module\n";
		std::cout << "This may be due to a problem with your Piavca installations\n";
		std::cout << "Please see the file PiavcaStderr.txt, in the workind directory for details\n";
		throw;
	}
	Piavca::tstring tscript = StringToTString(script);
	if(tscript != _T(""))
	{
		userScript = Piavca::ImportModule(tscript);
		//Piavca::InitPiavcaPython(Piavca::Core::getCore(), tscript, true);
	}
  }
  catch (Piavca::Exception &e)
  {
	string s = TStringToString(e.getDetails());
	//s = string(get_messages()) + "\n" + s;
	//s._Copy_s(Str, 256, 256);
	//s.copy(Str, 2048);
	std::cout << s << std::endl;;

	return get_messages();
  }


//#ifdef WIN32
//	strcpy_s(Str, 256, "");
//#else
	//strcpy(Str, "");
//#endif

	return get_messages();
}

// calls a method defined in python
extern "C" __declspec(dllexport) char* runMethod(char* method)
{
	try 
	{
		RunPythonMethod(Piavca::Core::getCore(), method, userScript);
	}
	catch (Piavca::Exception &e)
	{
		std::cout << TStringToString(e.getDetails()) << std::endl;
		return get_messages();
	}

	return get_messages();
}

// calls a method defined in python
extern "C" __declspec(dllexport) char* runMethodInt(char* method, int arg)
{
	try 
	{
		RunPythonMethod(Piavca::Core::getCore(), method, arg, userScript);
	}
	catch (Piavca::Exception &e)
	{
		std::cout << TStringToString(e.getDetails()) << std::endl;
		return get_messages();
	}

	return get_messages();
}

// calls a method defined in python
extern "C" __declspec(dllexport) char* runMethodFloat(char* method, float arg)
{
	try 
	{
		RunPythonMethod(Piavca::Core::getCore(), method, arg, userScript);
	}
	catch (Piavca::Exception &e)
	{
		std::cout << TStringToString(e.getDetails()) << std::endl;
		return get_messages();
	}

	return get_messages();
}

// calls a method defined in python
extern "C" __declspec(dllexport) char* runMethodStr(char* method, char * arg)
{
	try 
	{
		RunPythonMethod(Piavca::Core::getCore(), method, arg, userScript);
	}
	catch (Piavca::Exception &e)
	{
		std::cout << TStringToString(e.getDetails()) << std::endl;
		return get_messages();
	}

	return get_messages();
}

// calls a method defined in python
extern "C" __declspec(dllexport) char* runMethodVec(char* method, float arg1, float arg2, float arg3)
{
	try 
	{
		RunPythonMethod(Piavca::Core::getCore(), method, Piavca::Vec(arg1, arg2, arg3), userScript);
	}
	catch (Piavca::Exception &e)
	{
		std::cout << TStringToString(e.getDetails()) << std::endl;
		return get_messages();
	}

	return get_messages();
}

// calls a method defined in python
extern "C" __declspec(dllexport) char* runMethodAngleAxis(char* method, float arg0, float arg1, float arg2, float arg3)
{
	try 
	{
		RunPythonMethod(Piavca::Core::getCore(), method, arg0, Piavca::Vec(arg1, arg2, arg3), userScript);
	}
	catch (Piavca::Exception &e)
	{
		std::cout << TStringToString(e.getDetails()) << std::endl;
		return get_messages();
	}

	return get_messages();
}


//gets the last error message/warning
extern "C" __declspec(dllexport) char* GetLastMessage()
{
	return Str;
}

std::string output_string;

extern "C" __declspec(dllexport) char* GetLastOutput()
{
	output_string = _strstrm->str();
	output_string = output_string /*+ "\n"*/ + WStringToString(_wstrstrm->str());// + "\n";
	_strstrm->str("");
	_wstrstrm->str(L"");
	return const_cast<char *>(output_string.c_str());
	//s.copy(output, 1024);
	//return output;
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
