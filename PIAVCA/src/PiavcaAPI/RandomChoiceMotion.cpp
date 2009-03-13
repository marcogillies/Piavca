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
 * The Original Code is RandomChoiceMotion.cpp.
 *
 * The Initial Developer of the Original Code is Marco (Mark) Gillies.
 * Portions created by the Initial Developer are Copyright (C) 2008
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

#include "RandomChoiceMotion.h"

using namespace Piavca;

RandomChoiceMotion::RandomChoiceMotion(const MotionVec &mv, std::vector<float> ws)
		:ChoiceMotion(mv), probs(ws), probsUnnormalised(true)
{
	if(mots.size() != probs.size())
		Piavca::Error(_T("Trying to create a random loop motion with different numbers of motions and weights"));
	reset();
};

void RandomChoiceMotion::normaliseProbs()
{
	float sum = 0.0f;
	for (int i = 0; i < (int) probs.size(); i++)
		sum += probs[i];
	if (sum > 0.000001f)
		for (int i = 0; i < (int) probs.size(); i++)
				probs[i] /= sum;

	probsUnnormalised = false;

}



void RandomChoiceMotion::addMotion(Motion *mot, float prob)
{
	ChoiceMotion::addMotion(mot);
	if(mot)
	{
		setProbability(getNumMotions()-1,prob);
	}
};

void RandomChoiceMotion::setProbability(int index, float prob)
{
	if (probs.size() < getNumMotions())
	{
		probs.insert(probs.end(), getNumMotions() - probs.size(), 0.0f);
	};
	
	if(index >= 0 && index < (int)probs.size())
		probs[index] = prob;
	
	probsUnnormalised = true;
}

void RandomChoiceMotion::setMotionProb(int index, float prob)
{
	setProbability(index, prob);
}

void RandomChoiceMotion::setMotionProb(tstring motName, float prob)
{
	int index = getMotionIndex(motName);
	if (index >= 0)
		setProbability(index, prob);
}

int RandomChoiceMotion::makeChoice()
{
	if (eventHappened)
		return ChoiceMotion::makeChoice();
	if (probsUnnormalised)
		normaliseProbs();
	int r = rand()%1000;
	int cum_sum = 0;
	for (int i = 0; i < (int) probs.size(); i++)
	{
		cum_sum += int(probs[i]*1000.0f);
		if (cum_sum > r)
			return i;
	}
	// if we get to here somethings gone wrong, and we haven't found a choice
	
	// maybe its because all probabilities are 0, 
	// then we just choose one with uniform probability
	if (cum_sum <= 0)
		return rand()%getNumMotions();
	
	// otherwise assum its an off by one error, return the last choice 
	// and keep your fingers crossed
	return getNumMotions()-1;		
}