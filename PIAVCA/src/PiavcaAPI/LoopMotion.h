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

#ifndef LOOP_MOTION_H
#define LOOP_MOTION_H

#include "PostureBlend.h"

namespace Piavca
{
    //! a motion filter that makes a motion loop continuously
	class PIAVCA_DECL LoopMotion : public PostureBlend
	{
		bool lock;
		float endTime;
	protected:
		bool reblend_flag;
	public:
		//! pass in the motion to loop and an optional blend interval, 
		/*!  (How long it takes to blend from the end back to the beginning)
		 */
		LoopMotion(Motion *mot = NULL, float _endTime = -1, float interval = 0.01)
			:PostureBlend(mot, interval), lock(false), reblend_flag(false), endTime(_endTime) {} ;
		LoopMotion(const LoopMotion &l)
			:PostureBlend(l), lock(false), reblend_flag(false), endTime(l.endTime){};

		virtual Motion *clone(){return new LoopMotion(*this);};

		virtual float getMotionLength()const
		{
			//if(endTime < 0)
			//	std::cout << "returning negative time\n";
			return endTime;
		};

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
				&& (reblend_flag
				|| ((endTime < 0 || time < endTime)
				&& (!mot2 ||
				(mot2->getMotionLength() > 0 && time > mot2->getEndTime())))))
			{
			    LoopMotion *nonConstThis = const_cast<LoopMotion *>(this);
				nonConstThis->lock = true;
				nonConstThis->reblend(time);
				nonConstThis->lock = false;
				reblend_flag = false;
			}
			//std::cout << "loop motion " << time << " " << blendStart << std::endl;
			return PostureBlend::getFloatValueAtTimeInternal(trackId, time);
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
				&& (reblend_flag
				|| ((endTime < 0 || time < endTime)
				&& (!mot2 ||
				(mot2->getMotionLength() > 0 && time > mot2->getEndTime())))))
			{
				LoopMotion *nonConstThis = const_cast<LoopMotion *>(this);
				nonConstThis->lock = true;
				nonConstThis->reblend(time);
				nonConstThis->lock = false;
				reblend_flag = false;
			}
			Vec v = PostureBlend::getVecValueAtTimeInternal(trackId, time);
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
				&& (reblend_flag
				|| ((endTime < 0 || time < endTime)
				&& (!mot2 ||
				(/*mot2->getMotionLength() > 0 &&*/ time > mot2->getEndTime())))))
			{
				//std::cout << "Loop Motion Time " << time << " ";
				//std::cout << mot2->getEndTime() << " ";
				//std::cout << mot2->getStartTime() << " ";
				//std::cout << mot2->getMotionLength() << std::endl;
				LoopMotion *nonConstThis = const_cast<LoopMotion *>(this);
				nonConstThis->lock = true;
				nonConstThis->reblend(time);
				nonConstThis->lock = false;
				reblend_flag = false;
			}
			return PostureBlend::getQuatValueAtTimeInternal(trackId, time);
		};
	};
};


#endif //LOOP_MOTION_H
