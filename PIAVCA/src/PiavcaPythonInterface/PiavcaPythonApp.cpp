/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is PiavcaPythonApp.cpp.
 *
 * The Initial Developer of the Original Code is Marco (Mark) Gillies.
 * Portions created by the Initial Developer are Copyright (C) 2005
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */


#ifdef PIAVCA_DLL
#define PIAVCA_EXPORT __declspec( dllexport ) 
#else
#define PIAVCA_EXPORT
#endif

#if defined(_WIN32) || defined(__WIN32__)
#       if defined(_MSC_VER)
#               if defined(STATIC_LINKED)
#                       define SWIGEXPORT(a) a
#                       define SWIGIMPORT(a) extern a
#               else
#                       define SWIGEXPORT(a) __declspec(dllexport) a
#                       define SWIGIMPORT(a) extern a
#               endif
#       else
#               if defined(__BORLANDC__)
#                       define SWIGEXPORT(a) a _export
#                       define SWIGIMPORT(a) a _export
#               else
#                       define SWIGEXPORT(a) a
#                       define SWIGIMPORT(a) a
#               endif
#       endif
#else
#       define SWIGEXPORT(a) a
#       define SWIGIMPORT(a) a
#endif

extern "C" 
{
	SWIGEXPORT(void) init_Piavca_base(void) ;
};
//#undef _DEBUG

#include "PiavcaPythonApp.h"

#include <Python.h>

#include "PiavcaAPI/PiavcaCore.h"
#include "PiavcaAPI/Avatar.h"
#include "PiavcaAPI/TimeCallback.h"
#include "PiavcaAPI/PiavcaError.h"
#include "PyTimeCallback.h"
//#include "PlatformDefs.h"

#include <iostream>

#include <stdio.h>
#include <stdlib.h>


using namespace Piavca;

PyObject *g_pPyMod = 0;
	


#include <iostream>
#include <fstream>
#include <sstream>

//#ifdef NO_CONSOLE_PRESENT
bool no_console_present = false;
std::ostringstream *strstrm;
std::streambuf *saved_cout;
std::streambuf *saved_cerr;

std::wostringstream *wstrstrm;
std::wstreambuf *saved_wcout;
std::wstreambuf *saved_wcerr;
//#endif

PIAVCA_EXPORT void PyTimeCallback::init(Piavca::Core *core)
{
	PyObject_CallMethod(pyCallbackObj, "callbackInit", "(l)", (long) core);
	if(PyErr_Occurred())
	{
		PyErr_Print();
		PyObject *ErrorType, *ErrorValue, *ErrorTraceback, *ErrorString;
		PyErr_Fetch(&ErrorType, &ErrorValue, &ErrorTraceback);
		ErrorString = PyObject_Str(ErrorType);
		std::cout << "Python Exception:\n";
		std::cout << PyString_AsString(ErrorString) << std::endl;
		ErrorString = PyObject_Str(ErrorValue);
		Piavca::tstring error_string = StringToTString(PyString_AsString(ErrorString));
		std::cout << PyString_AsString(ErrorString) << std::endl;
		ErrorString = PyObject_Str(ErrorTraceback);
		std::cout << PyString_AsString(ErrorString) << std::endl;

		EndPiavcaPython(core);
		Piavca::Error(_T("Error running script: ") + error_string);
		return;
	}
	//Py_DECREF(pyArgs);
	//Py_DECREF(pyInitMethod);
};

PIAVCA_EXPORT void PyTimeCallback::timeStep(Piavca::Core *core, float time)
{
	//PyObject *pyMethod, *pyArgs;

	
	//std::cout << "in callback method\n";
 	PyObject_CallMethod(pyCallbackObj, "callbackMethod", "(lf)", (long) core, time);
	//pyMethod = PyObject_GetAttrString(pyCallbackObj, "callbackMethod");
	//pyArgs = Py_BuildValue("(lf)", (long) core, time);
	//PyEval_CallObject(pyMethod, pyArgs);
	if(PyErr_Occurred())
	{
		std::cout << "callback error\n";
		PyErr_Print();
		PyObject *ErrorType, *ErrorValue, *ErrorTraceback, *ErrorString;
		PyErr_Fetch(&ErrorType, &ErrorValue, &ErrorTraceback);
		ErrorString = PyObject_Str(ErrorType);
		std::cout << "Python Exception:\n";
		std::cout << PyString_AsString(ErrorString) << std::endl;
		ErrorString = PyObject_Str(ErrorValue);
		Piavca::tstring error_string = StringToTString(PyString_AsString(ErrorString));
		std::cout << PyString_AsString(ErrorString) << std::endl;
		ErrorString = PyObject_Str(ErrorTraceback);
		std::cout << PyString_AsString(ErrorString) << std::endl;

		EndPiavcaPython(core);
		Piavca::Error(_T("Error running script: ") + error_string);
		return;
	}

	//std::string res = strstrm->str();
	//std::cout << "hello\n";

	//res = strstrm->str();
//#ifdef NO_CONSOLE_PRESENT
	if(no_console_present)
	{
		/*pyMethod = PyObject_GetAttrString(g_pPyMod, "PrintOutput");
		if(pyMethod)
		{
			pyArgs = Py_BuildValue("(s)", strstrm->str().c_str());
			PyEval_CallObject(pyMethod, pyArgs);
			if(PyErr_Occurred())
			{
				PyErr_Print();
				//EndPiavcaPython(core);
				//exit(0);
			}
			else
			{
				strstrm->str("");
				wstrstrm->str(L"");
			}
		}*/
	}
//#endif

	//Py_DECREF(pyArgs);
	//Py_DECREF(pyMethod);
};


PIAVCA_EXPORT void PyAvatarTimeCallback::init(Avatar *avatar)
{
	//PyObject *pyInitMethod, *pyArgs;

	//pyInitMethod = PyObject_GetAttrString(pyCallbackObj, "callbackInit");
	//pyArgs = Py_BuildValue("(l)", (long) avatar);
	//PyEval_CallObject(pyInitMethod, pyArgs);
	if(PyErr_Occurred())
	{
		PyErr_Print();
		PyObject *ErrorType, *ErrorValue, *ErrorTraceback, *ErrorString;
		PyErr_Fetch(&ErrorType, &ErrorValue, &ErrorTraceback);
		ErrorString = PyObject_Str(ErrorType);
		std::cout << "Python Exception:\n";
		std::cout << PyString_AsString(ErrorString) << std::endl;
		ErrorString = PyObject_Str(ErrorValue);
		Piavca::tstring error_string = StringToTString(PyString_AsString(ErrorString));
		std::cout << PyString_AsString(ErrorString) << std::endl;
		ErrorString = PyObject_Str(ErrorTraceback);
		std::cout << PyString_AsString(ErrorString) << std::endl;

		EndPiavcaPython(Piavca::Core::getCore());
		Piavca::Error(_T("Error running script: ") + error_string);
		return;
	}
	//Py_DECREF(pyArgs);
	//Py_DECREF(pyInitMethod);

	//head = avatar->getJointIterator(_T"Head");
};

PIAVCA_EXPORT void PyAvatarTimeCallback::timeStep(Avatar *avatar, float time)
{
	PyObject *pyMethod, *pyArgs;

	pyMethod = PyObject_GetAttrString(pyCallbackObj, "callbackMethod");
	pyArgs = Py_BuildValue("(lf)", (long) avatar, time);
	PyEval_CallObject(pyMethod, pyArgs);
	if(PyErr_Occurred())
	{
		PyErr_Print();
		PyObject *ErrorType, *ErrorValue, *ErrorTraceback, *ErrorString;
		PyErr_Fetch(&ErrorType, &ErrorValue, &ErrorTraceback);
		ErrorString = PyObject_Str(ErrorType);
		std::cout << "Python Exception:\n";
		std::cout << PyString_AsString(ErrorString) << std::endl;
		ErrorString = PyObject_Str(ErrorValue);
		Piavca::tstring error_string = StringToTString(PyString_AsString(ErrorString));
		std::cout << PyString_AsString(ErrorString) << std::endl;
		ErrorString = PyObject_Str(ErrorTraceback);
		std::cout << PyString_AsString(ErrorString) << std::endl;

		EndPiavcaPython(Piavca::Core::getCore());
		Piavca::Error(_T("Error running script: ") + error_string);
		return;
	}
	
//#ifdef NO_CONSOLE_PRESENT
	if(no_console_present)
	{
		std::string res = strstrm->str();
		std::wstring wres = wstrstrm->str();

		pyMethod = PyObject_GetAttrString(g_pPyMod, "PrintOutput");
		if(pyMethod)
		{
			pyArgs = Py_BuildValue("(s)", strstrm->str().c_str());
			PyEval_CallObject(pyMethod, pyArgs);
			pyArgs = Py_BuildValue("(s)", WStringToString(wstrstrm->str()).c_str());
			PyEval_CallObject(pyMethod, pyArgs);
			if(PyErr_Occurred())
			{
				PyErr_Print();
				PyObject *ErrorType, *ErrorValue, *ErrorTraceback, *ErrorString;
				PyErr_Fetch(&ErrorType, &ErrorValue, &ErrorTraceback);
				ErrorString = PyObject_Str(ErrorType);
				std::cout << "Python Exception:\n";
				std::cout << PyString_AsString(ErrorString) << std::endl;
				ErrorString = PyObject_Str(ErrorValue);
				Piavca::tstring error_string = StringToTString(PyString_AsString(ErrorString));
				std::cout << PyString_AsString(ErrorString) << std::endl;
				ErrorString = PyObject_Str(ErrorTraceback);
				std::cout << PyString_AsString(ErrorString) << std::endl;

				EndPiavcaPython(Piavca::Core::getCore());
				Piavca::Error(_T("Error running script: ") + error_string);
				return;
			}
			else
			{	
				//strstrm->str("");
				//wstrstrm->str(L"");
			}
		}
	}
//#endif

	Py_DECREF(pyArgs);
	Py_DECREF(pyMethod);

	//av->setJointOrientation(head, Quat(time*1.5, Vec(0.0, 1.0, 0.0)));
}; 


void Piavca::PrintPythonErrors()
{
	PyErr_Print();
}

void Piavca::InitPiavcaPython(Piavca::Core *core, tstring fileName, bool no_console)
{ 
	PyObject *pyInitMethod, *pyArgs;
	std::cout << "in InitPiavcaPython\n";
	no_console_present = no_console;
//#ifdef NO_CONSOLE_PRESENT
	if(no_console_present)
	{
		//file = new std::ofstream("PiavcaCout.txt");
		strstrm = new std::ostringstream();
		saved_cout = std::cout.rdbuf();
		std::cout.rdbuf(strstrm->rdbuf());
		saved_cerr = std::cerr.rdbuf();
		std::cerr.rdbuf(strstrm->rdbuf());
		
		wstrstrm = new std::wostringstream();
		saved_wcout = std::wcout.rdbuf();
		std::wcout.rdbuf(wstrstrm->rdbuf());
		saved_wcerr = std::wcerr.rdbuf();
		std::wcerr.rdbuf(wstrstrm->rdbuf());

		freopen("piavcaStdout.txt", "w", stdout);
	}
//#endif
	
	std::cout << "ABOUT TO LOAD PYTHON" << std::endl;

	PyImport_AppendInittab( "_Piavca_base", init_Piavca_base); 

	Py_Initialize();

	std::cout << "initialised python\n";

	//g_pPyMod = PyImport_ImportModule("PiavcaTest");
	//g_pPyMod = PyImport_ImportModule("MotionAvTest");
	//g_pPyMod = PyImport_ImportModule("MotionEditor");
	
	//g_pPyMod = PyImport_ImportModule("IMClient");
	
	//g_pPyMod = PyImport_ImportModule("RunPiavca");
	char *buf = new char[fileName.size()+1];
	TStringToString(fileName).copy(buf, fileName.size());
	buf[fileName.size()] ='\0';
	g_pPyMod = PyImport_ImportModule(buf);
	delete buf;
	//g_pPyMod = PyImport_ImportModule("QuickPiavcaText");
	//g_pPyMod = PyImport_ImportModule("PiavcaSimple");
	//g_pPyMod = PyImport_ImportModule("IMClient_old");
	if(PyErr_Occurred())
	{
		//PyObject *pyTracebackmod = PyImport_ImportModule("traceback");	
		//PyObject *pyArgs = Py_BuildValue("()");
		//PyObject *pyMethod = PyObject_GetAttrString(pyTracebackmod, "format_exc");
		//PyObject *pyStr = PyEval_CallObject(pyMethod, pyArgs);
		//char *c = PyString_AsString(pyStr);
		//std::cout << c << std::endl;

		std::cout << "python bailed during module import\n";
		PyErr_Print();
		PyObject *ErrorType, *ErrorValue, *ErrorTraceback, *ErrorString;
		PyErr_Fetch(&ErrorType, &ErrorValue, &ErrorTraceback);
		ErrorString = PyObject_Str(ErrorType);
		std::cout << "Python Exception:\n";
		std::cout << PyString_AsString(ErrorString) << std::endl;
		Piavca::tstring error_value = StringToTString(PyString_AsString(ErrorString));
		ErrorString = PyObject_Str(ErrorValue);
		Piavca::tstring error_string = StringToTString(PyString_AsString(ErrorString));
		std::cout << PyString_AsString(ErrorString) << std::endl;
		ErrorString = PyObject_Str(ErrorTraceback);
		Piavca::tstring error_traceback = StringToTString(PyString_AsString(ErrorString));
		std::cout << PyString_AsString(ErrorString) << std::endl;
		fflush(stdout);
		fflush(stderr);

		EndPiavcaPython(core);
		Piavca::Error(_T("Error running script: ") + error_string);
		return;
		//exit(0);
	}

	std::cout << "loaded module\n";

	pyInitMethod = PyObject_GetAttrString(g_pPyMod, "PiavcaStartUp");
	if(pyInitMethod)
	{
		pyArgs = Py_BuildValue("(l)", (long) core);
		PyEval_CallObject(pyInitMethod, pyArgs);
		if(PyErr_Occurred())
		{
			//PyErr_Print();
			PyObject *ErrorType, *ErrorValue, *ErrorTraceback, *ErrorString;
			PyErr_Fetch(&ErrorType, &ErrorValue, &ErrorTraceback);
			ErrorString = PyObject_Str(ErrorType);
			std::cout << "Python Exception:\n";
			std::cout << PyString_AsString(ErrorString) << std::endl;
			ErrorString = PyObject_Str(ErrorValue);
			Piavca::tstring error_string = StringToTString(PyString_AsString(ErrorString));
			std::cout << PyString_AsString(ErrorString) << std::endl;
			ErrorString = PyObject_Str(ErrorTraceback);
			std::cout << PyString_AsString(ErrorString) << std::endl;

			EndPiavcaPython(core);
			Piavca::Error(_T("Error running script: ") + error_string);
			return;
		}
	}
	else
	{
		PyErr_Clear();
		std::cout << "failed to find PiavcaStartUp method\n";
	}

	std::cout << "finished running start up method\n";

//#ifdef NO_CONSOLE_PRESENT
	
	if(no_console_present)
	{
		//std::string res = strstrm->str();
		PyObject *pyPrintMethod = PyObject_GetAttrString(g_pPyMod, "PrintOutput");
		if(pyPrintMethod)
		{
			pyArgs = Py_BuildValue("(s)", strstrm->str().c_str());
			PyEval_CallObject(pyPrintMethod, pyArgs);
			pyArgs = Py_BuildValue("(s)", WStringToString(wstrstrm->str()).c_str());
			PyEval_CallObject(pyPrintMethod, pyArgs);
			if(PyErr_Occurred())
			{
				PyErr_Print();
				PyObject *ErrorType, *ErrorValue, *ErrorTraceback, *ErrorString;
				PyErr_Fetch(&ErrorType, &ErrorValue, &ErrorTraceback);
				ErrorString = PyObject_Str(ErrorType);
				std::cout << "Python Exception:\n";
				std::cout << PyString_AsString(ErrorString) << std::endl;
				ErrorString = PyObject_Str(ErrorValue);
				Piavca::tstring error_string = StringToTString(PyString_AsString(ErrorString));
				std::cout << PyString_AsString(ErrorString) << std::endl;
				ErrorString = PyObject_Str(ErrorTraceback);
				std::cout << PyString_AsString(ErrorString) << std::endl;

				EndPiavcaPython(core);
				Piavca::Error(_T("Error running script: ") + error_string);
				return;
			}
			else
			{
				//strstrm->str("");
				//wstrstrm->str(L"");
			}
		}
	}
//#endif

	//core->registerTimeCallback(new PyTimeCallback(pyMod));

	//Avatar *avatar = new Avatar(StringToPiavcaString("Avatar"));
	//avatar->registerNonStaticTimeCallback(new PyAvatarTimeCallback(pyMod));

	//avatar->loadMotion(StringToPiavcaString("../Ballet01.bvh"));
	//avatar->loadMotion(StringToPiavcaString("../COWBOY1.bvh"));
	//avatar->enableMotion(true);
}


void Piavca::RunPythonMethod(Piavca::Core *core, char *methodName)
{
	PyObject *pyArgs = Py_BuildValue("()");
	RunPythonMethod(core, methodName, pyArgs);
};

void Piavca::RunPythonMethod(Piavca::Core *core, char *methodName, int arg)
{
	PyObject *pyArgs = Py_BuildValue("(i)", arg);
	RunPythonMethod(core, methodName, pyArgs);
};

void Piavca::RunPythonMethod(Piavca::Core *core, char *methodName, float arg)
{
	PyObject *pyArgs = Py_BuildValue("(f)", arg);
	RunPythonMethod(core, methodName, pyArgs);
};

void Piavca::RunPythonMethod(Piavca::Core *core, char *methodName, std::string arg)
{
	PyObject *pyArgs = Py_BuildValue("(s#)", arg.c_str(), arg.length());
	RunPythonMethod(core, methodName, pyArgs);
};

void Piavca::RunPythonMethod(Piavca::Core *core, char *methodName, const Vec &arg)
{
	PyObject *pyArgs = Py_BuildValue("([fff])", arg[0], arg[1], arg[2]);
	RunPythonMethod(core, methodName, pyArgs);
};

void Piavca::RunPythonMethod(Piavca::Core *core, char *methodName, float farg, const Vec &varg)
{
	PyObject *pyArgs = Py_BuildValue("(f[fff])", farg, varg[0], varg[1], varg[2]);
	RunPythonMethod(core, methodName, pyArgs);
};


void Piavca::RunPythonMethod(Piavca::Core *core, char *methodName, PyObject *pyArgs)
{
	PyObject *pyMethod = PyObject_GetAttrString(g_pPyMod, methodName);
	if(pyMethod)
	{
		PyEval_CallObject(pyMethod, pyArgs);
		if(PyErr_Occurred())
		{
			PyErr_Print();
			PyObject *ErrorType, *ErrorValue, *ErrorTraceback, *ErrorString;
			PyErr_Fetch(&ErrorType, &ErrorValue, &ErrorTraceback);
			ErrorString = PyObject_Str(ErrorType);
			std::cout << "Python Exception:\n";
			std::cout << PyString_AsString(ErrorString) << std::endl;
			ErrorString = PyObject_Str(ErrorValue);
			Piavca::tstring error_string = StringToTString(PyString_AsString(ErrorString));
			std::cout << PyString_AsString(ErrorString) << std::endl;
			ErrorString = PyObject_Str(ErrorTraceback);
			std::cout << PyString_AsString(ErrorString) << std::endl;

			EndPiavcaPython(core);
			tstring tmethodName = StringToTString(methodName);
			Piavca::Error(_T("Error running method: ") + tmethodName + _T(" ") + error_string);
			return;
		}
	}
	else
	{
		PyErr_Clear();
		std::cout << "failed to find method" << methodName << std::endl;
	}
}

void Piavca::EndPiavcaPython(Piavca::Core *core)
{
	PyObject *pyFinalizeMethod, *pyArgs;

	std::cout << "in finalise function\n";
	std::ofstream file("PiavcaCout.txt");
	std::wofstream wfile("PiavcaCout.txt");

//#ifdef NO_CONSOLE_PRESENT
	if(no_console_present)
	{
		file << strstrm->str();
		strstrm->str("");

		wfile << wstrstrm->str();
		wstrstrm->str(L"");
	}
//#endif

	if(g_pPyMod)
	{
		pyFinalizeMethod = PyObject_GetAttrString(g_pPyMod, "PiavcaEnd");
		if(pyFinalizeMethod)
		{
			pyArgs = Py_BuildValue("(l)", (long) core);
			PyEval_CallObject(pyFinalizeMethod, pyArgs);
			if(PyErr_Occurred())
			{
				PyErr_Print();
				PyObject *ErrorType, *ErrorValue, *ErrorTraceback, *ErrorString;
				PyErr_Fetch(&ErrorType, &ErrorValue, &ErrorTraceback);
				ErrorString = PyObject_Str(ErrorType);
				std::cout << "Python Exception:\n";
				std::cout << PyString_AsString(ErrorString) << std::endl;
				ErrorString = PyObject_Str(ErrorValue);
				Piavca::tstring error_string = StringToTString(PyString_AsString(ErrorString));
				std::cout << PyString_AsString(ErrorString) << std::endl;
				ErrorString = PyObject_Str(ErrorTraceback);
				std::cout << PyString_AsString(ErrorString) << std::endl;

				EndPiavcaPython(core);
				Piavca::Error(_T("Error running script: ") + error_string);
				return;
				}
				Py_DECREF(g_pPyMod);
		}
		else
		{
			PyErr_Clear();
			std::cout << "failed to find PiavcaEnd method\n";
		}
	}	
	
//#ifndef NO_CONSOLE_PRESENT
	if(!no_console_present)
	{
		std::cout << "Press any key to exit\n";
		//std::string temp;
		std::cin.get();
	}
//#endif

//#ifdef NO_CONSOLE_PRESENT
	if(no_console_present)
	{
		file << strstrm->str();
		std::cout.rdbuf(saved_cout);
		std::cerr.rdbuf(saved_cerr);
		
		wfile << wstrstrm->str();
		std::wcout.rdbuf(saved_wcout);
		std::wcerr.rdbuf(saved_wcerr);

		//delete file;
		delete strstrm;
	}
	else
//#else
	{
		std::cout.flush();
		std::cerr.flush();
	}
//#endif
}
