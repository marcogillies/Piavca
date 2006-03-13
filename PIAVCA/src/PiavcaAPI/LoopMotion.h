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
 * The Original Code is LoopMotion.h.
 *
 * The Initial Developer of the Original Code is Marco (Mark) Gillies.
 * Portions created by the Initial Developer are Copyright (C) BT plc. 2004
 * All Rights Reserved.
 *
 * ***** END LICENSE BLOCK ***** */

#ifndef LOOP_MOTION_H
#define LOOP_MOTION_H

#include "SelfBlend.h"

namespace Piavca
{
    //! a motion filter that makes a motion loop continuously
	class PIAVCA_DECL LoopMotion : public SelfBlend
	{
		bool lock;
		float endTime;
	public:
		//! pass in the motion to loop and an optional blend interval, 
		/*!  (How long it takes to blend from the end back to the beginning)
		 */
		LoopMotion(Motion *mot, float _endTime = -1, float interval = 0.01)
			:SelfBlend(mot, interval), lock(false), endTime(_endTime) {} ;
		LoopMotion(const LoopMotion &l)
			:SelfBlend(l), lock(false), endTime(l.endTime){};

		virtual Motion *clone(){return new LoopMotion(*this);};

		virtual float getMotionLength()const{return endTime;};

		void setEndTime(float t){endTime = t;};

	    //! calculates the values of a keyframe
	    /*!  if the end has been reached it reblends to start again at the beginning
		 */
	    virtual float getFloatValueAtTimeInternal (int trackId, float time)
		{
			// if we've reached the end of the motion we have to reblend to start it again
			// as reblend calls this function again we have to check whether its being
			// called recursively and not do the reblend
			if(!lock 
				&& (endTime < 0 || time < endTime)
				&& (time > mot2->getEndTime()))
			{
			    LoopMotion *nonConstThis = const_cast<LoopMotion *>(this);
				nonConstThis->lock = true;
				nonConstThis->reblend(time);
				nonConstThis->lock = false;
			}
			//std::cout << "loop motion " << time << " " << blendStart << std::endl;
			return SelfBlend::getFloatValueAtTimeInternal(trackId, time);
		};
	    
	     //! calculates the values of a keyframe
	    /*!  if the end has been reached it reblends to start again at the beginning
		 */
	    virtual Vec   getVecValueAtTimeInternal   (int trackId, float time)
		{
			// if we've reached the end of the motion we have to reblend to start it again
			// as reblend calls this function again we have to check whether its being
			// called recursively and not do the reblend
			if(!lock 
				&& (endTime < 0 || time < endTime)
				&& (time > mot2->getEndTime()))
			{
				LoopMotion *nonConstThis = const_cast<LoopMotion *>(this);
				nonConstThis->lock = true;
				nonConstThis->reblend(time);
				nonConstThis->lock = false;
			}
			Vec v = SelfBlend::getVecValueAtTimeInternal(trackId, time);
			//std::cout << "loop motion: " << v << std::endl;
			return v;
		};
	    
	    //! calculates the values of a keyframe
	    /*!  if the end has been reached it reblends to start again at the beginning
		 */
	    virtual Quat  getQuatValueAtTimeInternal  (int trackId, float time)
		{
			// if we've reached the end of the motion we have to reblend to start it again
			// as reblend calls this function again we have to check whether its being
			// called recursively and not do the reblend
			if(!lock 
				&& (endTime < 0 || time < endTime)
				&& (time > mot2->getEndTime()))
			{
				LoopMotion *nonConstThis = const_cast<LoopMotion *>(this);
				nonConstThis->lock = true;
				nonConstThis->reblend(time);
				nonConstThis->lock = false;
			}
			return SelfBlend::getQuatValueAtTimeInternal(trackId, time);
		};
	};
};


#endif //LOOP_MOTION_H
