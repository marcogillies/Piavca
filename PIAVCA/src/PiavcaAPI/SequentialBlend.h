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

#ifndef SEQUENTIAL_BLEND_H
#define SEQUENTIAL_BLEND_H

//#include "Motion.h"
#include "TwoMotionCombiner.h"
#include "PiavcaCore.h"

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
		bool m_accumulateRoot;
	    
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
	    SequentialBlend(Motion *mot1=NULL, Motion *mot2=NULL, float interval = 0.2, float start = 0.0) 
			:TwoMotionCombiner(mot1, mot2), 
			blendInterval(interval), blendStart(start), 
			maintainY(false), m_accumulateRoot(true)
		{
			calculateRootOffsets();
			//maintainY = true;
		};
		SequentialBlend(const SequentialBlend &sb)
			:TwoMotionCombiner(sb), 
			blendInterval(sb.blendInterval), blendStart(sb.blendStart),
			m1End(sb.m1End), m2Start(sb.m2Start), oriOffset(sb.oriOffset),
			maintainY(sb.maintainY), m_accumulateRoot(sb.m_accumulateRoot)
			{};
	
		virtual Motion *clone(){return new SequentialBlend(*this);};

		virtual void setMaintainY(bool b){maintainY = b;};
		virtual void setAccumulateRoot(bool b){m_accumulateRoot = b;};
		virtual void setStartTime(float time)
		{
			
			//if(name != _T(""))
			//	std::cout << "SequentialBlend::setStartTime " << name << " " 
			//		<< blendStart << " "  << startTime << std::endl; 
			blendStart += time - startTime;
			Motion::setStartTime(time);
			float t = Piavca::Core::getCore()->getTime();
			//if(name != _T(""))
			///	std::cout << "SequentialBlend::setStartTime " << name << " " 
			//		<< blendStart << " " << t << " " << startTime << std::endl; 
			//if(startTime > t)
			//	std::cout << "starting later\n";
			if(mot1) mot1->setStartTime(time);
			if(mot2) mot2->setStartTime(blendStart+blendInterval);
		}

		//! gets the motion length (transition start + blend interval + length of second motion)
		float getMotionLength() const
		{
			if(mot2)
				return (blendStart - startTime) + blendInterval + mot2->getMotionLength();
			else
				return (blendStart - startTime) + blendInterval;	
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
			float t = Piavca::Core::getCore()->getTime();
			/*std::cout << "SequentialBlend::setBlendStart " 
				<< start << " " << t << " " << startTime << std::endl; 
			if(start > t)
				std::cout << "late start " << start << " " << t << std::endl;*/
			//if(name != _T(""))
			//	std::cout << "SequentialBlend::setBlendStart " << name << " " 
			//		<< blendStart << " "  << startTime << std::endl; 
			blendStart = start;
			//if(name != _T(""))
			//	std::cout << "SequentialBlend::setBlendStart " << name << " " 
			//		<< blendStart << " " << t << " " << startTime << std::endl; 
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
