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
 * The Original Code is PyMotion.cpp.
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

#include "PyMotion.h"


using namespace Piavca;

extern Quat PyQuat_AsQuat(PyObject *obj);
extern Vec PyVec_AsVec(PyObject *obj);


PyMotion::PyMotion(PyObject *pObj):pyObj(pObj) 
{
	Py_INCREF(pyObj);
};

PyMotion::~PyMotion()
{
	Py_DECREF(pyObj);
};

bool PyMotion::isNull(int trackId) const
{
	PyObject *pyMethod, *pyArgs, *pyValue;
	bool retVal;

	pyMethod = PyObject_GetAttrString(pyObj, "isNull");
	if(pyMethod && PyCallable_Check(pyMethod))
	{
		pyArgs = Py_BuildValue("(l)", (long) trackId);
		pyValue = PyEval_CallObject(pyMethod, pyArgs);
		if(PyErr_Occurred() || pyValue == NULL)
		{
			PyErr_Print();
			retVal =  true;
		}
		else
		{
			retVal = PyInt_AsLong(pyValue);
		}
		Py_DECREF(pyArgs);
		Py_DECREF(pyValue);
		Py_DECREF(pyMethod);
	}
	else
		retVal = true;
	return retVal;
};

float PyMotion::getMotionLength() const
{
	PyObject *pyMethod, *pyValue;
	float retVal;

	pyMethod = PyObject_GetAttrString(pyObj, "getMotionLength");
	if(pyMethod && PyCallable_Check(pyMethod))
	{
		pyValue = PyEval_CallObject(pyMethod, NULL);
		if(PyErr_Occurred() || pyValue == NULL)
		{
			PyErr_Print();
			retVal =  0.0;
		}
		else
		{
			retVal = PyFloat_AsDouble(pyValue);
		}
		Py_DECREF(pyValue);
		Py_DECREF(pyMethod);
	}
	else
		retVal = 0.0;
	return retVal;
};

trackType PyMotion::getTrackType(int trackId) const
{
	PyObject *pyMethod, *pyArgs, *pyValue;
	int retVal;

	pyMethod = PyObject_GetAttrString(pyObj, "getTrackType");
	if(pyMethod && PyCallable_Check(pyMethod))
	{
		pyArgs = Py_BuildValue("(l)", (long) trackId);
		pyValue = PyEval_CallObject(pyMethod, pyArgs);
		if(PyErr_Occurred() || pyValue == NULL)
		{
			PyErr_Print();
			retVal =  QUAT_TYPE;
		}
		else
		{
			retVal = PyInt_AsLong(pyValue);
		}
		Py_DECREF(pyArgs);
		Py_DECREF(pyValue);
		Py_DECREF(pyMethod);
	}
	else
		retVal = QUAT_TYPE;
	return (trackType) retVal;
};

float PyMotion::getFloatValueAtTime(int trackId, float time) const
{
	PyObject *pyMethod, *pyArgs, *pyValue;
	float retVal;

	pyMethod = PyObject_GetAttrString(pyObj, "getFloatValueAtTime");
	if(pyMethod && PyCallable_Check(pyMethod))
	{
		pyArgs = Py_BuildValue("(ld)", (long) trackId, (double) time);
		pyValue = PyEval_CallObject(pyMethod, pyArgs);
		if(PyErr_Occurred() || pyValue == NULL)
		{
			PyErr_Print();
			retVal =  0.0;
		}
		else
		{
			retVal = PyFloat_AsDouble(pyValue);
		}
		Py_DECREF(pyArgs);
		Py_DECREF(pyValue);
		Py_DECREF(pyMethod);
	}
	else
		retVal = 0.0;
	return retVal;
};

Vec PyMotion::getVecValueAtTime(int trackId, float time) const
{
	PyObject *pyMethod, *pyArgs, *pyValue;
	Vec retVal, *res; //retVal initialised to zero vector

	pyMethod = PyObject_GetAttrString(pyObj, "getVecValueAtTime");
	if(pyMethod && PyCallable_Check(pyMethod))
	{
		pyArgs = Py_BuildValue("(ld)", (long) trackId, (double) time);
		pyValue = PyEval_CallObject(pyMethod, pyArgs);
		if(PyErr_Occurred() || pyValue == NULL)
		{
			PyErr_Print();
		}
		else
		{
			retVal = PyVec_AsVec(pyValue);
		}
		Py_DECREF(pyArgs);
		Py_DECREF(pyMethod);
	}
	return retVal;
};


Quat PyMotion::getQuatValueAtTime(int trackId, float time) const
{
	PyObject *pyMethod, *pyArgs, *pyValue;
	Quat retVal, *res; //retVal initialised to zero quaternion

	pyMethod = PyObject_GetAttrString(pyObj, "getQuatValueAtTime");
	if(pyMethod && PyCallable_Check(pyMethod))
	{
		pyArgs = Py_BuildValue("(ld)", (long) trackId, (double) time);
		pyValue = PyEval_CallObject(pyMethod, pyArgs);
		if(PyErr_Occurred() || pyValue == NULL)
		{
			PyErr_Print();
		}
		else
		{
			retVal = PyQuat_AsQuat(pyValue);
		}
		Py_DECREF(pyArgs);
		Py_DECREF(pyValue);
		Py_DECREF(pyMethod);
	}
	return retVal;
};