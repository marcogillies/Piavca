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
 * The Original Code is MotionTransition.cpp.
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

#include "MotionTransition.h"
#include "PiavcaAPI/PiavcaError.h"

using namespace Piavca;


float LinearTransition::eval(float t)
{
	if (t < 0) 
		return 0;
	if (t > 1)
		return 1;
	return t;		
};

float SmoothTransition::eval(float t)
{
	if (t < 0) 
		return 0;
	if (t > 1)
		return 1;
	return (3 - 2*t)*t*t;	
};

MotionTransition::MotionTransition(Motion *m1, Motion *m2, float transtime1, float transtime2, float w, TransitionFunction *tf) 
	:TwoMotionCombiner(m1,m2), transfunc(tf), 
	transitionTime1(transtime1), transitionTime2(transtime2), window(w)
{
	if (transfunc == NULL)
		transfunc = new SmoothTransition();
	setTransitionTime1(transtime1);
	setTransitionTime2(transtime2);
};

MotionTransition::MotionTransition(const MotionTransition &mt)
	:TwoMotionCombiner(mt), transfunc(mt.transfunc), 
	transitionTime1(mt.transitionTime1), transitionTime2(mt.transitionTime2), window(mt.window)
{
};


void MotionTransition::setStartTime(float time)
{
	//std::cout << "setStartTime " << time << " ";
	Motion::setStartTime(time);
	if(mot1) 
		mot1->setStartTime(time-transitionTime1);
	if(mot2) 
		mot2->setStartTime(time-transitionTime2+window);
}


float MotionTransition::getFloatValueAtTimeInternal (int trackId, float time)
{
	// if this track doesn't exist in mot2 use mot1 otherwise interpolated between them
	if(!mot2 || mot2->isNull(trackId))
	{
		if(!mot1 || mot1->isNull(trackId))
		{
			Piavca::Error(_T("trying to transition between two invalid tracks"));
			return 0.0;
		}
		return mot1->getFloatValueAtTime(trackId, time);
	}
	if(!mot1 || mot1->isNull(trackId))
		return mot2->getFloatValueAtTime(trackId, time);


	float t = time - getStartTime();
	float f1 = mot1->getFloatValueAtTime(trackId, time);//transitionTime1);//+time);
    float f2 = mot2->getFloatValueAtTime(trackId, time);//transitionTime2);//-window+time);
    if (fabs(window) < 0.0001)
		t = 0;
	else
		t = t/window;
	float a = transfunc->eval(t);
	//return a*f1 + (1-a)*f2;
    return (1-a)*f1 + a*f2;
};

Vec MotionTransition::getVecValueAtTimeInternal   (int trackId, float time)
{
	// if this track doesn't exist in mot2 use mot1 otherwise interpolated between them
	if(!mot2 || mot2->isNull(trackId))
	{
		if(!mot1 || mot1->isNull(trackId))
		{
			Piavca::Error(_T("trying to transition between two invalid tracks"));
			return Vec();
		}
		return mot1->getVecValueAtTime(trackId, time);
	}
	if(!mot1 || mot1->isNull(trackId))
		return mot2->getVecValueAtTime(trackId, time);

	
	float t = time - getStartTime();
	Vec v1 = mot1->getVecValueAtTime(trackId, time);//transitionTime1);//+time);
    Vec v2 = mot2->getVecValueAtTime(trackId, time);//transitionTime2);//-window+time);
    if (fabs(window) < 0.0001)
		t = 0;
	else
		t = t/window;
	float a = transfunc->eval(t);
    //return v1*a + v2*(1-a);
    return v1*(1-a) + v2*(a);
};

Quat MotionTransition::getQuatValueAtTimeInternal  (int trackId, float time)
{
	// if this track doesn't exist in mot2 use mot1 otherwise interpolated between them
	if(!mot2 || mot2->isNull(trackId))
	{
		if(!mot1 || mot1->isNull(trackId))
		{
			Piavca::Error(_T("trying to transition between two invalid tracks"));
			return Quat();
		}
		return mot1->getQuatValueAtTime(trackId, time);
	}
	if(!mot1 || mot1->isNull(trackId))
		return mot2->getQuatValueAtTime(trackId, time);


	float t = time - getStartTime();
	Quat q1 = mot1->getQuatValueAtTime(trackId, time);//transitionTime1);//+time);
    Quat q2 = mot2->getQuatValueAtTime(trackId, time);//transitionTime2);//-window+time);
	//Quat q1 = mot1->getQuatValueAtTime(trackId, transitionTime1+t);//transitionTime1);//+time);
    //Quat q2 = mot2->getQuatValueAtTime(trackId, transitionTime2+t-window);//transitionTime2);//-window+time);
	//if (trackId == 6)
	//{
	//	std::cout << "motion transition " << q1 << " " << q2 << " " << transitionTime2-window+time << " " << t << " ";
	//}
	if (fabs(window) < 0.0001)
		t = 0;
	else
		t = t/window;
	float a = transfunc->eval(t);
    Quat q =  slerp(q1, q2, a);
	//if (trackId == 6)
	//	std::cout << " "  << a << " " << q << std::endl;
	return q;
};