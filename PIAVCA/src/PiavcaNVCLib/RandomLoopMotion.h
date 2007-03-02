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
class RandomLoopMotion : public RandomTimingsLoop
{
protected:
	RandomChoiceMotion *randomchoicemotion;
public:
	RandomLoopMotion()
	{
		randomchoicemotion = new RandomChoiceMotion;
		setMotion(randomchoicemotion);
	};
	//! pass in a vector of motions to be used, and a vector with a weight for each motion.
	/*!
	 *	The weights determine the probability of playing each motio
	 */
	RandomLoopMotion(const MotionVec &mv, vector<float> ws, float endTime = -1.0, float interval = 0.01)
		:RandomTimingsLoop(NULL, endTime, interval) 
	{
		randomchoicemotion = new RandomChoiceMotion(mv, ws);
		setMotion(randomchoicemotion);
	};
	RandomLoopMotion(const RandomLoopMotion &rl)
		:RandomTimingsLoop(rl)
	{
		randomchoicemotion = dynamic_cast<RandomChoiceMotion *>(rl.randomchoicemotion->clone());
	};
	~RandomLoopMotion(){};
	virtual Motion *clone(){return new RandomLoopMotion(*this);};

	static RandomLoopMotion *convertTo(Motion *m)
	{
		return dynamic_cast<RandomLoopMotion *>(m);
	};

	virtual void addMotion(Motion *mot, float weight = 1.0f)
	{
		randomchoicemotion->addMotion(mot, weight);
	};

	void setProbability(int index, float prob)
	{
		randomchoicemotion->setProbability(index, prob);
	}

	void setMotionProb(int index, float prob)
	{
		randomchoicemotion->setMotionProb(index, prob);
	}

	void setMotionProb(tstring motName, float prob)
	{
		randomchoicemotion->setMotionProb(motName, prob);
	}

	virtual void shift()
	{
		randomchoicemotion->shift();
	};

	virtual void reblend(float time)
	{
		shift();
		RandomTimingsLoop::reblend(time);
	}
};

};

#endif //RANDOM_LOOP_MOTION_H
