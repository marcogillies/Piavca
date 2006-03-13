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
 * The Original Code is RandomLoopMotion.h.
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


#ifndef RANDOM_LOOP_MOTION_H
#define RANDOM_LOOP_MOTION_H

#include "ChoiceLoopMotion.h"

namespace Piavca
{

//! a MultiMotionLoop where a new motion is chosen each time around the loop.
class RandomLoopMotion : public ChoiceLoopMotion
{
protected:
	vector<float>weights;
public:
	//! pass in a vector of motions to be used, and a vector with a weight for each motion.
	/*!
	 *	The weights determine the probability of playing each motio
	 */
	RandomLoopMotion(const MotionVec &mv, vector<float> ws, float endTime = -1.0, float interval = 0.01)
		:ChoiceLoopMotion(mv, endTime, interval), weights(ws)
	{
		if(mots.size() != weights.size())
			Piavca::Error(_T("Trying to create a random loop motion with different numbers of motions and weights"));
		float sum = 0.0;
		int i;
		for(i = 0; i < weights.size(); i++)
		{
			sum += weights[i];
		}
		for(i = 0; i < weights.size(); i++)
		{
			weights[i] = weights[i]/sum;
		}
		do
		{
			i = rand()%weights.size();
		}while(((float)(rand()%100))/100 > weights[i]);
		setMotion(mots[i]);
	};
	RandomLoopMotion(const RandomLoopMotion &rl)
		:ChoiceLoopMotion(rl), weights(rl.weights){};
	~RandomLoopMotion(){};
	virtual Motion *clone(){return new RandomLoopMotion(*this);};

	//! called each time around the loop
	/*!
	 * It can be called by the client to interrupt the current motion.
	 */
	virtual void reblend(float time)
	{
		int i;
		do
		{
			i = rand()%weights.size();
		}while(((float)(rand()%100))/100 > weights[i]);
		setCurrentChoice(i);
		ChoiceLoopMotion::reblend(time);
	};
};

};

#endif //RANDOM_LOOP_MOTION_H
