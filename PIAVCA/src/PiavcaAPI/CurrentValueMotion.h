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
 * The Original Code is CurrentValueMotion.h.
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


#ifndef CURRENT_VALUE_MOTION_H
#define CURRENT_VALUE_MOTION_H

#include "PiavcaAPI/KeyframeMotion.h"

namespace Piavca
{
	//! A motion class that allows use to set constant values for joint rotations
	/*!
	 *	Useful for using realtime streams of data to control character animation
	 *  without having to create a specialist motion class.
	 *  Currently implemented as a KeyframeMotion which maybe isn't the most efficient way of doing it.
	 */
    class PIAVCA_DECL CurrentValueMotion : public KeyframeMotion
	{   
	public:
		/*!
		 *	Pass in the motion to be filtered and a scale factor
		 */
	    CurrentValueMotion() 
			:KeyframeMotion()
		{
		};
		CurrentValueMotion(const CurrentValueMotion &cvm)
			:KeyframeMotion(cvm)
		{
		};
	
		virtual Motion *clone(){return new CurrentValueMotion(*this);};

		//! returns the name of the type
		Piavca::tstring getClassName(){return "CurrentValueMotion";};

		//! casts a motion to this type
		static CurrentValueMotion *castToThisType(Motion *m){return dynamic_cast<CurrentValueMotion *>(m);};

		//! Sets a value for a float track
	    void setFloatValue(int trackId, float val)
		{
			if(isNull(trackId) || !(getTrackType(trackId) & FLOAT_TYPE))
				addFloatTrack(trackId, val);
			else
				setFloatKeyframe(trackId, 0.0, val);
		};

		//! Sets a value for a vec track
	    void setVecValue(int trackId, Vec &val)
		{
			if(isNull(trackId) || !(getTrackType(trackId) & VEC_TYPE))
				addVecTrack(trackId, val);
			else
				setVecKeyframe(trackId, 0.0, val);
		};

		//! Sets a value for a Quat track
	    void setQuatValue(int trackId, Quat &val)
		{
			if(isNull(trackId) || !(getTrackType(trackId) & QUAT_TYPE))
				addQuatTrack(trackId, val);
			else
				setQuatKeyframe(trackId, 0.0, val);
		};
	};
};

#endif //CURRENT_VALUE_MOTION_H
