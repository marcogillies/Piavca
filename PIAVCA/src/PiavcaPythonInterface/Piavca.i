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
 * The Original Code is Piavca.i.
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

%module(directors="1") Piavca
%{

#define NO_PIAVCA_DLL

#include "PiavcaNVCLib/Piavca.h"
#include "PyTimeCallback.h"
//#include "PyMotion.h"

#include <sstream>

//#include "PiavcaDllImports.h"


Piavca::Avatar *GetAvatarPointer(long l)
{
	Piavca::Avatar *a = (Piavca::Avatar *) l;
	return a;
};
Piavca::Core *GetPiavcaCorePointer(long l)
{
	return (Piavca::Core *) l;
};

using namespace Piavca;

Quat PyQuat_AsQuat(PyObject *obj)
{
	Quat retVal, *res;
	if ((SWIG_ConvertPtr(obj,(void **) &res, SWIGTYPE_p_Piavca__Quat, 1 | 0 )) != -1)
	{
		retVal =  *res;
	}
	return retVal;
}

Vec PyVec_AsVec(PyObject *obj)
{
	Vec retVal, *res;
	if ((SWIG_ConvertPtr(obj,(void **) &res, SWIGTYPE_p_Piavca__Vec, 1 | 0 )) != -1)
	{
		retVal =  *res;
	}
	return retVal;
}

//PyObject *GetPythonJointIterator(JointIterator joint)
//{
//    JointIterator *jointptr = new JointIterator((JointIterator &) joint);
//	PyObject *pythonJoint = SWIG_NewPointerObj((void *) jointptr, SWIGTYPE_p_JointIterator, 1);
//	return pythonJoint;
//};
%}


#define PIAVCA_DECL
#define PIAVCA_EXPORT
#define PIAVCA_IMPORT

//%define tstring const char * %enddef
//#define tstring const char *

namespace std {
template <class T> class vector;
class istringstream;
class type_info;
}

%typemap(in) tstring
{
	$1 = StringToTString(PyString_AsString($input));
}

%typemap(out) tstring
{
	$result = PyString_FromString(TStringToString($1).c_str());
}

%typemap(out) tstring&
{
	$result = PyString_FromString(TStringToString(*$1).c_str());
}

%typemap(in) std::string
{
	$1 = PyString_AsString($input);
}

%typemap(out) std::string
{
	$result = PyString_FromString($1.c_str());
}

%typemap(out) std::string&
{
	$result = PyString_FromString((*$1).c_str());
}

%typemap(typecheck) tstring = char *;
%typemap(typecheck) tstring& = char *;
%typemap(typecheck) Piavca::tstring = char *;
%typemap(typecheck) Piavca::tstring& = char *;
%typemap(typecheck) string = char *;
%typemap(typecheck) string& = char *;
%typemap(typecheck) std::string = char *;
%typemap(typecheck) std::string& = char *;

%typemap(out) float&
{
	$result = PyFloat_FromDouble(*$1);
}

%typemap(in) AvatarTimeCallback*
{
	if ((SWIG_ConvertPtr($input,(void **) &$1, SWIGTYPE_p_Piavca__PyAvatarTimeCallback,SWIG_POINTER_EXCEPTION | 0 )) == -1) SWIG_fail;
    //$1 = static_cast<AvatarTimeCallback *>($input);
}

%typemap(in) TimeCallback*
{
	if ((SWIG_ConvertPtr($input,(void **) &$1, SWIGTYPE_p_Piavca__PyTimeCallback,SWIG_POINTER_EXCEPTION | 0 )) == -1) SWIG_fail;
    //$1 = static_cast<AvatarTimeCallback *>($input);
}


//%typemap(in) PyMotion *
//{
//	if ((SWIG_ConvertPtr($input,(void **) &$1, SWIGTYPE_p_Piavca__PyMotion,SWIG_POINTER_EXCEPTION | 0 )) == -1) SWIG_fail;
 //   //$1 = static_cast<AvatarTimeCallback *>($input);
//}

%typemap(in) Piavca::MotionList
{
	PyObject *keys = PyDict_Keys($input);
	PyObject *py_name, *py_mot, *py_tup;
	Piavca::tstring name;
	Motion *mot;
	for(int i = 0; i < PyList_Size(keys); i++)
	{
		motionSpec ms;
		py_name = PyList_GetItem(keys,i);
		py_tup = PyDict_GetItem($input, py_name);
		ms.name = PyString_AsString(py_name);
		py_mot = PyTuple_GetItem(py_tup, 0);
		if ((SWIG_ConvertPtr(py_mot,(void **) &(ms.mot), SWIGTYPE_p_Piavca__Motion,SWIG_POINTER_EXCEPTION | 0 )) == -1) return NULL;
		py_tup = PyTuple_GetItem(py_tup, 1);
		ms.clamp.clamped = PyInt_AsLong(PyTuple_GetItem(py_tup, 0));
		ms.clamp.threshold = PyFloat_AsDouble(PyTuple_GetItem(py_tup, 1));
		//$1.push_back(std::make_pair(name, std::make_pair(Piavca::Motion(*mot), clamp)));
		$1.push_back(ms);
	}
}

%typemap(in) Piavca::clampSpec
{
	$1.clamped = PyInt_AsLong(PyTuple_GetItem($input, 0));
	$1.threshold = PyFloat_AsDouble(PyTuple_GetItem($input, 1));
}


%typemap(in) Piavca::StringVector
{
	PyObject *py_str;
	Piavca::tstring tstr;
	for (int i = 0; i < PyList_Size($input); i++)
	{
		py_str = PyList_GetItem($input, i);
		tstr = StringToTString(PyString_AsString(py_str));
		$1.push_back(tstr);
	}
}

%typemap(out) std::vector< std::pair<TString, float> > 
{
	int len = $1.size();
	$result = PyDict_New();
	for (int i = 0; i < len; i++)
	{
		PyDict_SetItem($result,  
			PyString_FromString(TStringToString((*(&($1)))[i].first).c_str()),
			PyFloat_FromDouble($1[i].second));
	}
}


%typemap(out) std::vector<std::string>
{
	int len = $1.size();
	$result = PyList_New(0);
	for (int i = 0; i < len; i++)
	{
		PyList_Append($result,  
			PyString_FromString((*(&($1)))[i].c_str()));
	}
}

%typemap(out) std::vector<Piavca::tstring>
{
	int len = $1.size();
	$result = PyList_New(0);
	for (int i = 0; i < len; i++)
	{
		PyList_Append($result,  
			PyString_FromString(TStringToString((*(&($1)))[i]).c_str()));
	}
}


%feature("director:except") {
    if ($error != NULL) {
        //std::cout << "got a director exception" << std::endl;
        PyErr_Print();
        Piavca::Error("error when calling a python director method");
    }
}

%exception {
    try { $action }
    catch (Swig::DirectorException &e) { SWIG_fail; }
    catch (Piavca::Exception &e) 
    {
        std::cout << "Piavca Exception: " << e.getDetails() << std::endl; 
        SWIG_fail; 
    }
}

Piavca::Avatar *GetAvatarPointer(long l);
Piavca::Core *GetPiavcaCorePointer(long l);

%ignore Piavca::Vec::operator[];
%ignore Piavca::Vec::operator=;
%ignore Piavca::Quat::operator[];
%ignore Piavca::Quat::operator=;
%ignore operator<<;
%ignore operator>>;


%include "PiavcaAPI/Vec.h"

%extend Piavca::Vec {
	PyObject *__getitem__(PyObject *args)
	{	
		int i;
		//if(!PyArg_ParseTuple(args, "i", &i))
		//	return NULL;
		i = (int) PyInt_AsLong(args);
		return Py_BuildValue("d", (*self)[i]);
	}
	PyObject *__setitem__(PyObject *arg1, PyObject *arg2)
	{
		int i;
		float f;
		//if(!PyArg_ParseTuple(args, "if", &i, &f))
		//	return NULL;
		i = (int) PyInt_AsLong(arg1);
		f = (float) PyFloat_AsDouble(arg2);

		(*self)[i] = f;
	
		Py_INCREF(Py_None);
		return Py_None;
	}	
	PyObject *__repr__()
	{
		std::ostringstream os;
		os << (*self);
		return Py_BuildValue("s", os.str().c_str());
	}	
}


%include "PiavcaAPI/Quat.h"

%extend Piavca::Quat {
	PyObject *__getitem__(PyObject *args)
	{	
		int i;
		//if(!PyArg_ParseTuple(args, "i", &i))
		//	return NULL;
		i = (int) PyInt_AsLong(args);
		return Py_BuildValue("d", (*self)[i]);
	}
	PyObject *__setitem__(PyObject *arg1, PyObject *arg2)
	{
		int i;
		float f;
		//if(!PyArg_ParseTuple(arg1, "i", &i))
		//	return NULL;
		i = (int) PyInt_AsLong(arg1);
		f = (float) PyFloat_AsDouble(arg2);
		(*self)[i] = f;
	
		Py_INCREF(Py_None);
		return Py_None;
	}
	PyObject *__repr__()
	{
		std::ostringstream os;
		os << (*self);
		return Py_BuildValue("s", os.str().c_str());
	}	
}


%rename(__eq__) operator==;
%rename(__ne__) operator!=;


%ignore Piavca::KeyframeMotion::operator=;
%ignore Piavca::MaskedMotion::operator=;
%ignore Piavca::MotionMask::operator=;
%ignore Piavca::flagStruct::operator=;

%ignore Piavca::Avatar::Avatar(const Avatar &av);

%feature("ref")   Piavca::Motion "$this->Reference();"
%feature("unref") Piavca::Motion "$this->Dispose();"

%feature("ref")   Piavca::ScaleMotionRoot "$this->Reference();"
%feature("unref") Piavca::ScaleMotionRoot "$this->Dispose();"

%feature("ref")   Piavca::ScaleMotionSpeed "$this->Reference();"
%feature("unref") Piavca::ScaleMotionSpeed "$this->Dispose();"

%feature("director") Motion;   
%feature("director") KeyframeMotion;   
%feature("director") MotionFilter;  
%feature("director") TwoMotionCombiner;    
%feature("director") SelfBlend;        
%feature("director") SequentialBlend;       
%feature("director") LoopMotion;           
%feature("director") ScaleMotion;           
%feature("director") ScaleMotionSpeed;           
%feature("director") ScaleMotionRoot;            
%feature("director") TimeOffset;            
%feature("director") TurnMotion;            
%feature("director") BlendBetween;      
%feature("director") MotionAdder;     
%feature("director") Subtract;        
%feature("director") MaskedMotion;      
%feature("director") ChoiceLoopMotion;    
%feature("director") RandomLoopMotion;   
%feature("director") RandomBlendLoop;   
%feature("director") RandomAddLoop;   
%feature("director") LookAtMotion;     
%feature("director") RandomGazeMotion;     
%feature("director") ZeroMotion;     
%feature("director") MotionSaver;    
%feature("director") SubMotion;    
%feature("director") TimeRangeMotion;    
%feature("director") TimeWarp;     
%feature("director") RandomTimingsLoop;   
%feature("director") DiadicGazeMotion;
%feature("director") TimeCallback;    
%feature("director") AvatarTimeCallback;    


%include "piavca_doc.i"

%include "PiavcaAPI/TimeCallback.h"
%include "PiavcaCore.i"
%include "PiavcaAPI/PiavcaDefs.h"
%include "PiavcaAPI/Motion.h"
%include "PiavcaAPI/KeyframeMotion.h"
%include "Avatar.i"
%include "PiavcaNVCLib/AvatarMotionQueue.h"
%include "PiavcaAPI/Object.h"
%include "PiavcaPythonInterface/PyTimeCallback.h"
//%include "PyMotion.h"

%include "PiavcaAPI/MathsUtils.h"
%include "PiavcaAPI/MotionFilter.h"
%include "PiavcaAPI/TwoMotionCombiner.h"
%include "PiavcaNVCLib/ScaleMotion.h"
%include "PiavcaNVCLib/ScaleMotionSpeed.h"
%include "PiavcaNVCLib/ScaleMotionRoot.h"
%include "PiavcaNVCLib/TimeOffset.h"
%include "PiavcaNVCLib/TurnMotion.h"
%include "PiavcaAPI/SequentialBlend.h"
%include "PiavcaAPI/SelfBlend.h"
%include "PiavcaAPI/LoopMotion.h"
%include "PiavcaNVCLib/RandomTimingsLoop.h"
%include "PiavcaAPI/AvatarPostureBlend.h"
%include "PiavcaAPI/BlendBetween.h"
%include "PiavcaAPI/MotionAdder.h"
%include "PiavcaNVCLib/Subtract.h"
%include "PiavcaNVCLib/MaskedMotion.h"
%include "PiavcaNVCLib/MotionTransition.h"
%include "PiavcaNVCLib/MultiMotionCombiner.h"
%include "PiavcaNVCLib/ChoiceMotion.h"
%include "PiavcaNVCLib/RandomChoiceMotion.h"
%include "PiavcaNVCLib/ChoiceLoopMotion.h"
%include "PiavcaNVCLib/RandomLoopMotion.h"
%include "PiavcaNVCLib/RandomBlend.h"
%include "PiavcaNVCLib/RandomAdd.h"
%include "PiavcaNVCLib/RandomBlendLoop.h"
%include "PiavcaNVCLib/RandomAddLoop.h"
%include "PiavcaNVCLib/ProxemicsLoop.h"
%include "PiavcaNVCLib/LookAtMotion.h"
%include "PiavcaNVCLib/RandomGazeMotion.h"
%include "PiavcaNVCLib/ZeroMotion.h"
%include "PiavcaNVCLib/MotionSaver.h"
%include "PiavcaNVCLib/MotionParser.h"
%include "PiavcaNVCLib/SubMotion.h"
%include "PiavcaNVCLib/TimeRangeMotion.h"
%include "PiavcaNVCLib/TimeWarp.h"
%include "PiavcaNVCLib/DiadicGazeMotion.h"
