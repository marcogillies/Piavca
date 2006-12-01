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


#ifndef RANDOM_CHOICE_MOTION_H
#define RANDOM_CHOICE_MOTION_H

#include "ChoiceMotion.h"

namespace Piavca
{

//! a choice motion where a new motion is chosen randomly at each reset
class RandomChoiceMotion : public ChoiceMotion
{
protected:
	vector<float> weights;
public:
	RandomChoiceMotion(){};
	//! pass in a vector of motions to be used, and a vector with a weight for each motion.
	/*!
	 *	The weights determine the probability of playing each motio
	 */
	RandomChoiceMotion(const MotionVec &mv, vector<float> ws)
		:ChoiceMotion(mv), weights(ws)
	{
		if(mots.size() != weights.size())
			Piavca::Error(_T("Trying to create a random loop motion with different numbers of motions and weights"));
		float sum = 0.0;
		vector<float>::size_type i;
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
	RandomChoiceMotion(const RandomChoiceMotion &rl)
		:ChoiceMotion(rl), weights(rl.weights){};
	~RandomChoiceMotion(){};
	virtual Motion *clone(){return new RandomChoiceMotion(*this);};

	static RandomChoiceMotion *convertTo(Motion *m)
	{
		return dynamic_cast<RandomChoiceMotion *>(m);
	};

	virtual void addMotion(Motion *mot, float weight = 1.0f)
	{
		ChoiceMotion::addMotion(mot);
		if(mot)
		{
			weights.push_back(weight);
		}
	};

	void setProbability(int index, float prob)
	{
		if(index >= 0 && index < (int)weights.size())
			weights[index] = prob;
		
		float sum = 0.0;
		vector<float>::size_type i;
		for(i = 0; i < weights.size(); i++)
		{
			sum += weights[i];
		}
		for(i = 0; i < weights.size(); i++)
		{
			weights[i] = weights[i]/sum;
		}
	}

	virtual void shift()
	{
		vector<float>::size_type i;
		do
		{
			i = rand()%weights.size();
		}while(((float)(rand()%100))/100 > weights[i]);
		setCurrentChoice(static_cast<int>(i));
		ChoiceMotion::reset();
	}

	//! called each time around the loop
	/*!
	 * It can be called by the client to interrupt the current motion.
	 */
	virtual void reset()
	{
		shift();
	};
};

};

#endif //RANDOM_CHOICE_MOTION_H
