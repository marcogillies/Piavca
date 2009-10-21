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
#include "TypeConvert.h"

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


//! a generic function for setting parameters
bool MotionTransition::setParameter(tstring paramName, tstring value)
{
	if(paramName == _T("Window") || paramName == _T("window"))
	{
		setWindow(convert<float>(value));
		return true;
	}
	if(paramName == _T("TransitionTime1") || paramName == _T("transitionTime1") || paramName == _T("transitiontime1"))
	{
		setTransitionTime1(convert<float>(value));
		return true;
	}
	if(paramName == _T("TransitionTime2") || paramName == _T("transitionTime2") || paramName == _T("transitiontime2"))
	{
		setTransitionTime2(convert<float>(value));
		return true;
	}
	return TwoMotionCombiner::setParameter(paramName, value);
}

void MotionTransition::setStartTime(float time)
{
	//std::cout << "setStartTime " << time << " ";
	Motion::setStartTime(time);
	if(mot1) 
		mot1->setStartTime(time-transitionTime1);
	if(mot2) 
		mot2->setStartTime(time-transitionTime2+window);
}
void MotionTransition::setTransitionTime1(float t1)
{
	transitionTime1 = t1;
	if (mot1 && transitionTime1 < 0)
	{
		transitionTime1 = mot1->getEndTime() - window;
		if( transitionTime1 < 0)
			transitionTime1 = 0.0;
	}
};
void MotionTransition::setTransitionTime2(float t2)
{
	transitionTime2 = t2;
	if (transitionTime2 < 0)
	{
		transitionTime2 = window;
	}
};

float MotionTransition::getCombinedFloatValue (int trackId, float time) 
{
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

Vec  MotionTransition::getCombinedVecValue (int trackId, float time)
{
	float t = time - getStartTime();
	Vec v1;
	if(!mot1->isNull(trackId) && (mot1->getTrackType(trackId) & VEC_TYPE))
		v1 = mot1->getVecValueAtTime(trackId, time);//transitionTime1);//+time);
    Vec v2 = mot2->getVecValueAtTime(trackId, time);//transitionTime2);//-window+time);

	//return v2;

    if (fabs(window) < 0.0001)
		t = 0;
	else
		t = t/window;
	float a = transfunc->eval(t);
    //return v1*a + v2*(1-a);
    return v1*(1-a) + v2*(a);	
};

Quat MotionTransition::getCombinedQuatValue (int trackId, float time)
{
	float t = time - getStartTime();
	Quat q1 = mot1->getQuatValueAtTime(trackId, time);//transitionTime1);//+time);
    Quat q2 = mot2->getQuatValueAtTime(trackId, time);//transitionTime2);//-window+time);

	//return q2;

	//Quat q1 = mot1->getQuatValueAtTime(trackId, transitionTime1+t);//transitionTime1);//+time);
    //Quat q2 = mot2->getQuatValueAtTime(trackId, transitionTime2+t-window);//transitionTime2);//-window+time);
	//if (trackId == root_orientation_id)
	//{
	//	std::cout << "motion transition " << q1 << " " << q2 << " " << transitionTime2-window+time << " " << t << " ";
	//	return q2;
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
