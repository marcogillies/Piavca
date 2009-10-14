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


    //! Creates a smooth transition between two motions
    class PIAVCA_DECL MotionTransition : public TwoMotionCombiner
	{
	protected:
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

		//! returns the name of the type
		Piavca::tstring getClassName(){return "MotionTransition";};

		//! casts a motion to this type
		static MotionTransition *castToThisType(Motion *m){return dynamic_cast<MotionTransition *>(m);};


		static const int MotionStart = -1;
		static const int MotionEnd = -1;

		//! the function used to do the transition
		void setTransitionFunction(TransitionFunction *tf){transfunc = tf;};
		
		//! the time in the first motion where the transition occurs
		virtual void setTransitionTime1(float t1=MotionEnd);
		virtual float getTransitionTime1()
		{
			return transitionTime1;
		};
		//! the time in the second motion where the transition occurs
		virtual void setTransitionTime2(float t2=MotionStart);
		virtual float getTransitionTime2()
		{
			return transitionTime2;
		};

		//! the blending window for smooth transitions
		void setWindow(float w){window = w;};
		float getWindow(){return window;};
		
		
		void setMotion1(Motion *mot)
		{
			TwoMotionCombiner::setMotion1(mot);
			// sort out the transition times for the new motion
			setTransitionTime1(transitionTime1);
		};

		virtual void setStartTime(float time);

		//float getMotionLength() const
		//{
		//	return window;
		//}

	    

		//! gets a combined value of two float tracks if both are valid
		virtual float getCombinedFloatValue (int trackId, float time);

		//! gets a combined value of two Vec tracks if both are valid
		virtual Vec  getCombinedVecValue (int trackId, float time);

		//! gets a combined value of two quaternion tracks if both are valid
		virtual Quat getCombinedQuatValue (int trackId, float time);
};

};

#endif //MOTION_TRANSITION_H
