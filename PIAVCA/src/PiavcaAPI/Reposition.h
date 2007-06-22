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
 * The Original Code is Reposition.h.
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


#ifndef REPOSITION_H
#define REPOSITION_H

#include "PiavcaAPI/Motion.h"
#include "PiavcaAPI/MotionFilter.h"
//#include "PiavcaCore.h"

namespace Piavca
{
	//! a motion filter that starts a motion from a new position and orientation
    class PIAVCA_DECL Reposition : public MotionFilter
	{
	    Vec start_position;
		Quat start_orientation;
		Vec originalStart;
		Quat oriOffset;

		// if this is true we keep start a new motion from the previous
		// y value (as well as x-z) otherwise we reblend to the starting 
		// y value of the second motion
		bool maintainY;

		void calculateRootOffsets();
	    
	public:
		/*!
		 *	Pass in the motion to be filtered and a scale factor
		 */
	    Reposition(Motion *m=NULL, Vec pos = Vec(), Quat ori = Quat()) 
			:MotionFilter(m), start_position(pos), start_orientation(ori),
			maintainY(false)
		{
			calculateRootOffsets();
		};
		Reposition(const Reposition &r)
			:MotionFilter(r), 
			start_position(r.start_position), 
			start_orientation(r.start_orientation),
			maintainY(r.maintainY)
		{
		};
	
		virtual Motion *clone(){return new Reposition(*this);};

		//! Sets the new starting position of the motion
	    void setStartPosition(Vec pos)
		{
			start_position = pos;
			calculateRootOffsets();
		};
		//! Sets the new starting orientation of the motion
	    void setStartOrientation(Quat ori)
		{
			start_orientation = ori;
			calculateRootOffsets();
		};

		//! Gets the new starting position of the motion
	    Vec getStartPosition()
		{
			return start_position;
		};
		//! Gets the new starting orientation of the motion
	    Quat getStartOrientation()
		{
			return start_orientation;
		};

		void setStartFromMotion(Motion *m, float time);

		void setMotion(Motion *m);

		virtual void setMaintainY(bool b){maintainY = b;};

		//! given a track ID tests whether it actually points to anything or if its null
		virtual bool isNull(int trackId)const;
		
		//! get the type of the track corresponding to an ID
		virtual int getTrackType(int trackId)const;

	    //! calculates the values of a keyframe
	    PIAVCA_EXPORT virtual float  getFloatValueAtTimeInternal (int trackId, float time);
	    
	    //! calculates the values of a keyframe
	    PIAVCA_EXPORT virtual Vec  getVecValueAtTimeInternal (int trackId, float time);
	    
	    //! calculates the values of a keyframe
	    PIAVCA_EXPORT virtual Quat  getQuatValueAtTimeInternal (int trackId, float time);
	};
};

#endif //REPOSITION_H
