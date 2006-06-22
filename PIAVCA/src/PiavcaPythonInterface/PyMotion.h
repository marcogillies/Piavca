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
 * The Original Code is PyMotion.h.
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


#ifndef PY_MOTION_H
#define PY_MOTION_H

#include <Python.h>
#include "PiavcaAPI/Motion.h"


namespace Piavca
{
	class PyMotion : public Motion
	{
		//! the python object that actually implements the functionality
		PyObject *pyObj;
	public:

		PyMotion():pyObj(NULL){};
		PyMotion(PyObject *pObj);
		PyMotion(const PyMotion &pm):pyObj(pm.pyObj){};

		Motion *clone(){return new PyMotion(*this);};

		virtual ~PyMotion();

		void setPyObj(PyObject *pObj){pyObj = pObj;};

		//! returns a point to the motion object as swig won't recognise the python overload?
		Motion *getMotionPtr(){return this;};

		//! gets the time of the end of the motion
		virtual float getMotionLength() const;

		//! given a track ID tests whether it actually points to anything or if its null
		virtual bool isNull(int trackId) const;
		//! get the type of the track corresponding to an ID
		virtual trackType getTrackType(int trackId) const;

	
		//! get the value of a track at a given time (only works for floats)
		virtual float getFloatValueAtTimeInternal(int trackId, float time) ;
		//! get the value of a track at a given time (only works for Vecs)
		virtual Vec getVecValueAtTimeInternal(int trackId, float time) ;
		//! get the value of a track at a given time (only works for Quats) 
		virtual Quat getQuatValueAtTimeInternal(int trackId, float time) ;
	};
};


#endif
