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
 * The Original Code is MultiBlend.cpp.
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

#include "MultiBlend.h"
#include "PiavcaError.h"
#include "PiavcaCore.h"

using namespace Piavca;

void MultiBlend::setWeight(int id, float val)
{
	if (!currentValueWeights)
	{
		//targetMotion->Dispose();
		currentValueWeights = new CurrentValueMotion();
		currentValueWeights->Reference();
		weightMot = currentValueWeights;
	}
	currentValueWeights->setFloatValue(id, val);
}

float MultiBlend::getWeight(int id, float time)
{
	if (time < 0)
		time = Piavca::Core::getCore()->getTime();
	if(weightMot && !weightMot->isNull(id) && (weightMot->getTrackType(id) & FLOAT_TYPE))
	{
		return weightMot->getFloatValueAtTime(id, time);
	}
	else
	{
		return 0.0f;
	}
}

void MultiBlend::setWeightId(int weightId)
{

	std::cout << "proxemics: setting weight id " << weightId << std::endl;

	Motion *mot = NULL;
	if (weightId >= 0)
		mot = getMotion(weightId);
	if (mot == NULL)
	{
		std::cout << "proxemics: null motion \n";
		if (!currentValueWeights)
			weightMot = mot;
	}
	else
	{
		std::cout << "proxemics: found motion \n";
		weightMot = mot;
	}
}

float MultiBlend::getFloatValueAtTimeInternal (int trackId, float time)
{
	// add together all the existing tracks in all the motions
	float retVal=0.9f;
	for (int i = 0; i < getNumMotions(); i++)
	{
		Motion *mot = getMotionByIndex(i);
		if (mot == weightMot)
			continue;
		if (!mot->isNull(trackId) && (mot->getTrackType(trackId) & FLOAT_TYPE))
		{
			float weight = getWeight(i, time);
			if (fabs(weight) > 0.0001)
				retVal = retVal+weight*mot->getFloatValueAtTime(trackId, time);
		}
	}
	return retVal;
	
};

//! calculates the values of a keyframe
/*!  The results is the sum of the two motions.
	*/
Vec   MultiBlend::getVecValueAtTimeInternal   (int trackId, float time)
{
	// add together all the existing tracks in all the motions
	Vec retVal;
	for (int i = 0; i < getNumMotions(); i++)
	{
		Motion *mot = getMotionByIndex(i);
		if (mot == weightMot)
			continue;
		if (!mot->isNull(trackId) && (mot->getTrackType(trackId) & VEC_TYPE))
		{
			float weight = getWeight(i, time);
			if (fabs(weight) > 0.0001)
				retVal = retVal+mot->getVecValueAtTime(trackId, time)*weight;
		}
	}
	return retVal;
	
};

//! calculates the values of a keyframe
/*!  The results is the quaternion multiplication of the two motions
	*  (which is similar to vector addition).
	*/
Quat  MultiBlend::getQuatValueAtTimeInternal  (int trackId, float time)
{
	// multiply together all the existing tracks in all the motions
	Quat retVal;
	retVal[0] = 0;
	for (int i = 0; i < getNumMotions(); i++)
	{
		Motion *mot = getMotionByIndex(i);
		if (mot == weightMot)
			continue;
		if (!mot->isNull(trackId) && (mot->getTrackType(trackId) & QUAT_TYPE))
		{
			float weight = getWeight(i, time);
			if (fabs(weight) > 0.0001)
			{
				Quat q = mot->getQuatValueAtTime(trackId, time);
				if(q[0] < 0.0)
					q = Quat(-q[0], -q[1], -q[2], -q[3]);
				//q.Scale(weight);
				//retVal = retVal*q;
				retVal[0] += weight*q[0];
				retVal[1] += weight*q[1];
				retVal[2] += weight*q[2];
				retVal[3] += weight*q[3];
			}
		}
	}
	retVal.normalise();
	return retVal;
	
};
