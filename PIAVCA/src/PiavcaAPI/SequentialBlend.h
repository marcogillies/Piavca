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
 * The Original Code is SequentialBlend.h.
 *
 * The Initial Developer of the Original Code is Marco (Mark) Gillies.
 * Portions created by the Initial Developer are Copyright (C) BT plc. 2004
 * All Rights Reserved.
 *
 * ***** END LICENSE BLOCK ***** */

#ifndef SEQUENTIAL_BLEND_H
#define SEQUENTIAL_BLEND_H

//#include "Motion.h"
#include "TwoMotionCombiner.h"

namespace Piavca
{
	//! Initially plays one motion up to a given time then blends into another motion
	/*!
	 *	This can be used to smoothly transition between motions and is used to implement a number of different 
	 *	motion effects like LoopMotion and AvatarPostureBlend. The seoond motion starts in the ending root position and orientation
	 *	of the first one rather than its own starting conditions. The transition is controlled by a start time
	 *	and an interval (length of the transition). The smooth blend is not very sophisticated (just an interpolation)
	 *	but it will look OK if the start of the second motion is not too different from the end of the first (don't use this
	 *	to try to transition between lying down and standing up for instance)
	 */
	class PIAVCA_DECL SequentialBlend : public TwoMotionCombiner
	{
	protected:
	    float blendInterval;
		float blendStart;
	    
		Vec m1End, m2Start;
		Quat oriOffset;

		// if this is true we keep start a new motion from the previous
		// y value (as well as x-z) otherwise we reblend to the starting 
		// y value of the second motion
		bool maintainY;

	    //! get the value of a keyframed transformed appropriately if it is the root position
	    Vec getTransformedVec(int trackId, float t)const;
	    //! get the value of a keyframed transformed appropriately if it is the root position
	    Quat getTransformedQuat(int trackId, float t)const;

		void calculateRootOffsets();
	    
	public:
		/*!
		 *	Pass in the two motions, the blend interval (length of the transition) and the start time
		 *	of the transition. To get the second motion to start at the end of the first pass in
		 *	the length of the second motion as the blend start time.
		 */
	    SequentialBlend(Motion *mot1, Motion *mot2, float interval = 0.2, float start = 0.0) 
			:TwoMotionCombiner(mot1, mot2), blendInterval(interval), blendStart(start), maintainY(false)
		{
			calculateRootOffsets();
			//maintainY = true;
		};
		SequentialBlend(const SequentialBlend &sb)
			:TwoMotionCombiner(sb), 
			blendInterval(sb.blendInterval), blendStart(sb.blendStart),
			m1End(sb.m1End), m2Start(sb.m2Start), oriOffset(sb.oriOffset),
			maintainY(sb.maintainY)
			{};
	
		virtual Motion *clone(){return new SequentialBlend(*this);};

		virtual void setMaintainY(bool b){maintainY = b;};
		virtual void setStartTime(float time)
		{
			blendStart += time - startTime;
			Motion::setStartTime(time);
			if(mot1) mot1->setStartTime(time);
			if(mot2) mot2->setStartTime(blendStart+blendInterval);
		}

		//! gets the motion length (transition start + blend interval + length of second motion)
		float getMotionLength() const
		{
			if(mot2)
				return blendStart + blendInterval + mot2->getMotionLength();
			else
				return blendStart + blendInterval;	
		};

	    //! calculates the values of a keyframe
	    virtual float getFloatValueAtTimeInternal (int trackId, float time);
	    
	    //! calculates the values of a keyframe
	    virtual Vec   getVecValueAtTimeInternal   (int trackId, float time);
	    
	    //! calculates the values of a keyframe
	    virtual Quat  getQuatValueAtTimeInternal  (int trackId, float time);
	    
		//! set the time at which tbe blend between the motions starts
		void setBlendStart(float start)
		{
			blendStart = start;
			if(mot2) mot2->setStartTime(blendStart+blendInterval);
		};
		//! sets the length of the transition between the two motions.
		void setBlendInterval(float interval)
		{
			blendInterval = interval;
			if(mot2) mot2->setStartTime(blendStart+blendInterval);
		};

		//! get the time at which tbe blend between the motions starts
		float getBlendStart(){return blendStart;};
		//! gets the length of the transition between the two motions.
		float getBlendInterval(){return blendInterval;};

	};
};

#endif //SEQUENTIAL_BLEND_H
