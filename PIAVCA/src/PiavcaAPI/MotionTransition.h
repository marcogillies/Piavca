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
 * The Original Code is MotionTransition.h.
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

#ifndef MOTION_TRANSITION_H
#define MOTION_TRANSITION_H

#include "PiavcaAPI/TwoMotionCombiner.h"

namespace Piavca
{
	
	class PIAVCA_DECL TransitionFunction
	{
	public:
		TransitionFunction(){};
		virtual float eval(float t)=0;
	};

	class PIAVCA_DECL LinearTransition : public TransitionFunction
	{
	public:
		LinearTransition():TransitionFunction(){};
		virtual float eval(float t);
	};

	class PIAVCA_DECL SmoothTransition : public TransitionFunction
	{
	public:
		SmoothTransition():TransitionFunction(){};
		virtual float eval(float t);
	};


    //! A motion manipulator class that interpolates between two motions.
	/*!	The resulting motion is an interpolation between the two motion using 
	 *	slerp for quaternions with a parameter value blend. This class blends 
	 *	the two motions concurrently rather blending from one to another as 
	 *	sequential blend does.
	 */
    class PIAVCA_DECL MotionTransition : public TwoMotionCombiner
	{
	    float transitionTime1, transitionTime2, window;
		TransitionFunction *transfunc;
	    
	public:
	    //! Pass in the two motion and the interpolation parameter blend (has to be between 0 and 1)
	    MotionTransition(Motion *m1=NULL, Motion *m2=NULL, float transtime1=-1.0f, float transtime2=-1.0f, float w=1.0f, TransitionFunction *tf=NULL);
		MotionTransition(const MotionTransition &mt);

		virtual Motion *clone()
		{
			return new MotionTransition(*this);
		}

		static const int MotionStart = -1;
		static const int MotionEnd = -1;

		void setTransitionFunction(TransitionFunction *tf){transfunc = tf;};
		void setTransitionTime1(float t1=MotionEnd)
		{
			transitionTime1 = t1;
			if (mot1 && transitionTime1 < 0)
			{
				transitionTime1 = mot1->getEndTime() - window;
				if( transitionTime1 < 0)
					transitionTime1 = 0.0;
			}

		};
		void setTransitionTime2(float t2=MotionStart)
		{
			transitionTime2 = t2;
			if (transitionTime2 < 0)
			{
				transitionTime2 = window;
			}
		};
		void setWindow(float w){window = w;};
		void setMotion1(Motion *mot)
		{
			TwoMotionCombiner::setMotion1(mot);
			// sort out the transition times for the new motion
			setTransitionTime1(transitionTime1);
		};

		virtual void setStartTime(float time);

		float getMotionLength() const
		{
			return window;
		}

	    //! calculates the values of a keyframe.
		/*!	The result is the linear interpolation of the values of the two motions
		 *  or if the track does not exist in the one motion, the value of the other
		 */
	    virtual float getFloatValueAtTimeInternal (int trackId, float time);
	    
	    //! calculates the values of a keyframe.
		/*!	The result is the linear interpolation of the values of the two motions
		 *  or if the track does not exist in the one motion, the value of the other
		 */
	    virtual Vec   getVecValueAtTimeInternal   (int trackId, float time);
	    
	    //! calculates the values of a keyframe.
		/*!	The result is the linear interpolation (slerp) of the values of the two motions
		 *  or if the track does not exist in the one motion, the value of the other
		 */
	    virtual Quat  getQuatValueAtTimeInternal  (int trackId, float time);
};

};

#endif //MOTION_TRANSITION_H
