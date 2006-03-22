/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1
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
 * The Original Code is MotionAdder.h.
 *
 * The Initial Developer of the Original Code is Marco (Mark) Gillies.
 * Portions created by the Initial Developer are Copyright (C) BT plc. 2004
 * All Rights Reserved.
 *
 * ***** END LICENSE BLOCK ***** */


#ifndef MOTION_ADDER_H
#define MOTION_ADDER_H

#include "TwoMotionCombiner.h"


namespace Piavca
{
	//! Adds the result of two motions, performing them simultaneously.
	/*!	The results is the sum of the effects of both motions (in fact
	 *	with rotations this is achieved with quaternion multiplication but
	 *	the effect is similar to vector addition. An optional parameter can 
	 *	scale the effect of the second motion.
	 */
    class PIAVCA_DECL MotionAdder : public TwoMotionCombiner
	{
		float scaleSecond;
	public:
		MotionAdder(Motion *m1, Motion *m2, float _scaleSecond = 1.0) :TwoMotionCombiner(m1,m2), scaleSecond(_scaleSecond){};
		MotionAdder(const MotionAdder &ma)
			:TwoMotionCombiner(ma), scaleSecond(ma.scaleSecond){};

		virtual Motion *clone(){return new MotionAdder(*this);};

		//! this is a scale factor applied to the second motion
		void setScaleSecond(float s){scaleSecond = s;};
	    
		//! calculates the values of a keyframe
		/*!  The results is the sum of the two motions.
		 */
	    virtual float getFloatValueAtTimeInternal (int trackId, float time);
	    
	    //! calculates the values of a keyframe
		/*!  The results is the sum of the two motions.
		 */
	   virtual Vec   getVecValueAtTimeInternal   (int trackId, float time);
	    
	    //! calculates the values of a keyframe
		/*!  The results is the quaternion multiplication of the two motions
		 *  (which is similar to vector addition).
		 */
	    virtual Quat  getQuatValueAtTimeInternal  (int trackId, float time);
	};
};

#endif //MOTION_ADDER_H
