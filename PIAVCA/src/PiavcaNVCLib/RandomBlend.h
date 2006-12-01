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
 * The Original Code is RandomBlendLoop.h.
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


#ifndef RANDOM_BLEND_H
#define RANDOM_BLEND_H

#include "MultiMotionCombiner.h"

namespace Piavca
{

//! A MultiMotionCombiner which, instead of choosing one motion at a time, blends between a groups of motions
/*!
 *	The Motions to blend are chosen at random, as are the number of motions and the 
 *  weights.
 */
class RandomBlend : public MultiMotionCombiner
{
	std::vector<float> weights;
public:
	RandomBlend(){};
	//! pass in a vector of motions to be used.
	RandomBlend(const MotionVec &mv)
		:MultiMotionCombiner(mv)
	{
		weights.assign(mv.size(), 1.0f);
	};
	RandomBlend(const RandomBlend &rbl)
		:MultiMotionCombiner(rbl) {};
	~RandomBlend(){};
	virtual Motion *clone(){return new RandomBlend(*this);};

	virtual void addMotion(Motion *mot)
	{
		MultiMotionCombiner::addMotion(mot);
		if(mot)
		{
			weights.push_back(1.0f);
		}
	};

	virtual void addMotion(Motion *mot, float weight)
	{
		MultiMotionCombiner::addMotion(mot);
		if(mot)
		{
			weights.push_back(weight);
		}
	};

	virtual void shift()
	{
		MotionVec::size_type numChosen = rand()%mots.size()+1;
		Motion *totalMot = NULL;
		for (MotionVec::size_type i = 0; i < numChosen; i++)
		{
			vector<float>::size_type chosen;
			do
			{
				chosen = rand()%weights.size();
			}while(((float)(rand()%100))/100 > weights[chosen]);
			Motion *chosenmot = mots[chosen];
			if(totalMot)
			{
				float weight = weights[chosen]*((float)(rand()%1000))/1000.0f;
				totalMot = new BlendBetween(totalMot, chosenmot, weight);
			}
			else
			{
				totalMot = chosenmot;
			}
		}
		setMotion(totalMot);
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

#endif //RANDOM_BLEND_H
