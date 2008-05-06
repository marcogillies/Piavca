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
 * The Original Code is TurnMotion.h.
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


#ifndef TURN_MOTION_H
#define TURN_MOTION_H

#include "PiavcaAPI/MotionFilter.h"
//#include "PiavcaCore.h"

namespace Piavca
{
	//! turn a motion through a given rotation over the course of its run
	/*!
	 *	For now the turning method is pretty rubbish, just turning the root position and orientation.
	 */
    class TurnMotion : public MotionFilter
	{
	    Quat rotation;
	    
	public:
	    TurnMotion(Motion *m=NULL, Quat rot=Quat()) :MotionFilter(m), rotation(rot)
		{
		};
		TurnMotion(const TurnMotion &tm):MotionFilter(tm), rotation(tm.rotation){};

		virtual Motion *clone(){return new TurnMotion(*this);};

		//! returns the name of the type
		Piavca::tstring getClassName(){return "TurnMotion";};

		//! casts a motion to this type
		static TurnMotion *castToThisType(Motion *m){return dynamic_cast<TurnMotion *>(m);};

	    //! calculates the values of a keyframe
	    PIAVCA_EXPORT virtual float getFloatValueAtTimeInternal (int trackId, float time)
		{
		    return filterMot->getFloatValueAtTime(trackId, time);
		};
	    
	    //! calculates the values of a keyframe
	    PIAVCA_EXPORT virtual Vec getVecValueAtTimeInternal (int trackId, float time)
		{
		    if(trackId == root_position_id)
			{
			    // rotate the direction of motion
			    // find the vector travelled over the motion and rotate it
			    float EndTime = filterMot->getMotionLength();
			    if(EndTime < time) EndTime = time;
			    Vec EndPos = filterMot->getVecValueAtTime(trackId, EndTime);
			    Vec StartPos = filterMot->getVecValueAtTime(trackId, 0.0);
			    // the interpolation, start at current motion at frame 0 and end up with fully rotated motion
			    Vec AddOn = (rotation.transform(EndPos - StartPos) - (EndPos - StartPos)) * time/EndTime;
			    return filterMot->getVecValueAtTime(trackId, time) + AddOn;
			}
		    else
			return filterMot->getVecValueAtTime(trackId, time);
		};
	    
	    //! calculates the values of a keyframe
	    PIAVCA_EXPORT virtual Quat getQuatValueAtTimeInternal (int trackId, float time)
		{
		    if(trackId == root_orientation_id)
			{
			    // make sure the end orientation is equal to rotation
			    // find the end ori and then create an offset Orientation
			    // which interpolates between 0 and rotation
			    float EndTime = filterMot->getMotionLength();
			    if(EndTime < time) EndTime = time;
			    Quat EndOri = filterMot->getQuatValueAtTime(trackId, EndTime);
			    Quat OriOffset = rotation;
			    OriOffset = OriOffset/EndOri;
			    OriOffset.Scale(time/EndTime);
			    Quat q = OriOffset * filterMot->getQuatValueAtTime(trackId, time);
				q.normalise();
				return q;
			}
		    else
			return filterMot->getQuatValueAtTime(trackId, time);
		};

	    void setRotation(Quat rot){rotation = rot;};
	};
};

#endif //TURN_MOTION_H
