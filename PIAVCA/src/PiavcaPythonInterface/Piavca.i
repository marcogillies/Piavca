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


%module Piavca
%{

#define NO_PIAVCA_DLL

#include "PiavcaNVCLib/Piavca.h"
#include "PyTimeCallback.h"
#include "PyMotion.h"

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
			PyString_FromString(TStringToString($1[i].first).c_str()),
			PyFloat_FromDouble($1[i].second));
	}
}

Piavca::Avatar *GetAvatarPointer(long l);
Piavca::Core *GetPiavcaCorePointer(long l);

%ignore Piavca::Vec::operator[];

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
	PyObject *__setitem__(PyObject *args)
	{
		int i;
		float f;
		if(!PyArg_ParseTuple(args, "if", &i, &f))
			return NULL;
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
	PyObject *__setitem__(PyObject *args)
	{
		int i;
		float f;
		if(!PyArg_ParseTuple(args, "if", &i, &f))
			return NULL;
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

/*
%extend Piavca::TrackIterator {
	PyObject *__eq__(PyObject *args)
	{
		PyObject *obj1 = 0;
		TrackIterator *jip1;
		TrackIterator *jip2;
		
		if(!PyArg_ParseTuple(args,(char *)"O",&obj1)) goto fail;
		if ((SWIG_ConvertPtr(obj1,(void **) &jip1, SWIGTYPE__TrackIterator,SWIG_POINTER_EXCEPTION) == -1)) SWIG_fail;
		
		int result = ((*self) == (*jip2)); 
		    
		PyObject *resultobj = PyInt_FromLong(result);
		return resultobj;
		fail:
		return NULL;
	}
}
*/

%ignore Piavca::Avatar::Avatar(const Avatar &av);

%feature("ref")   Piavca::Motion "$this->Reference();"
%feature("unref") Piavca::Motion "$this->Dispose();"

%feature("ref")   Piavca::ScaleMotionRoot "$this->Reference();"
%feature("unref") Piavca::ScaleMotionRoot "$this->Dispose();"

%feature("ref")   Piavca::ScaleMotionSpeed "$this->Reference();"
%feature("unref") Piavca::ScaleMotionSpeed "$this->Dispose();"

%include "PiavcaAPI/TimeCallback.h"
%include "PiavcaCore.i"
%include "PiavcaAPI/PiavcaDefs.h"
%include "PiavcaAPI/Motion.h"
%include "PiavcaAPI/TrackMotion.h"
%include "Avatar.i"
%include "PiavcaNVCLib/AvatarMotionQueue.h"
%include "PiavcaAPI/Object.h"
%include "PiavcaPythonInterface/PyTimeCallback.h"
%include "PiavcaPythonInterface/PyMotion.h"

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
%include "PiavcaNVCLib/MaskedMotion.h"
%include "PiavcaNVCLib/MultiMotionLoop.h"
%include "PiavcaNVCLib/ChoiceLoopMotion.h"
%include "PiavcaNVCLib/RandomLoopMotion.h"
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
//%include "PiavcaNVCLib/DiadicGazeMotion.h"
