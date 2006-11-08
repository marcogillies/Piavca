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
 * The Original Code is MaskedMotion.cpp.
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


#include "MaskedMotion.h"
#include "PiavcaAPI/PiavcaCore.h"
#include "PiavcaAPI/PiavcaError.h"

using namespace Piavca;

MotionMask::MotionMask(bool _facial):facial(_facial)
{
	if(facial)
		m.assign(Core::getCore()->getMaxExpressionId(), false);
	else
		m.assign(Core::getCore()->getMaxJointId(), false);
}

MotionMask::MotionMask(const MotionMask &mm)
	:facial(mm.facial), m(mm.m)
{
};

const MotionMask &MotionMask::operator=(const MotionMask &mm)
{
	facial = mm.facial;
	m = mm.m;
	return *this;
};

void MotionMask::setMask(int track, bool val)
{
	int maxTrack;
	if(facial)
		maxTrack = Core::getCore()->getMaxExpressionId();
	else
		maxTrack = Core::getCore()->getMaxJointId();

	if(track < 0 || track > maxTrack)
	{
		Piavca::Error(_T("Unknown track id when setting motion mask"));
		return;
	}
	if(track >= (int)m.size())
		for(int i = (int)m.size(); i < maxTrack; i++)
			m.push_back(false);
	m[track]=val;
};
bool MotionMask::getMask(int track) const
{
	if(track > 0 && track < (int)m.size())
		return m[track];
	else
		return false;
};

MaskedMotion::MaskedMotion()
	: TwoMotionCombiner()
{

};

MaskedMotion::MaskedMotion(Motion *_mot1, const MotionMask &_mask1, Motion *_mot2, const MotionMask &_mask2, bool _useSecondary) 
	:TwoMotionCombiner(_mot1,_mot2), mask1(_mask1), 
		mask2(_mask2), useSecondary(_useSecondary)
	    {};
MaskedMotion::MaskedMotion(const MaskedMotion &mm)
	:TwoMotionCombiner(mm), 
	mask1(mm.mask1), mask2(mm.mask2), useSecondary(mm.useSecondary)
	{};

float MaskedMotion::getFloatValueAtTimeInternal (int trackId, float time)
{
	// if motion1 has its mask as true then play it 
	// otherwise if motion2 is has a true mask play it
	if(mot1 && mask1.getMask(trackId) && !mot1->isNull(trackId))
		return mot1->getFloatValueAtTime(trackId, time);
	if(mot2 && mask2.getMask(trackId) && !mot2->isNull(trackId))
		return mot1->getFloatValueAtTime(trackId, time);

	// if neither has its mask set then play whichever has a valid track
	if(useSecondary)
	{
		if(mot1 && !mot1->isNull(trackId))
			return mot1->getFloatValueAtTime(trackId, time);
		if(mot2 && !mot2->isNull(trackId))
			return mot1->getFloatValueAtTime(trackId, time);
	}
	else
	{
		if((mot1 && !mot1->isNull(trackId)) || (mot2 && !mot2->isNull(trackId)))
			return 0.0;
	}

	// if neither has a valid track then its an error
	Piavca::Error(_T("Track invalid in both motions of a motion mask"));
	return 0.0;
}

Vec MaskedMotion::getVecValueAtTimeInternal (int trackId, float time)
{
	// if motion1 has its mask as true then play it 
	// otherwise if motion2 is has a true mask play it
	if(mot1 && mask1.getMask(trackId) && !mot1->isNull(trackId))
		return mot1->getVecValueAtTime(trackId, time);
	if(mot2 && mask2.getMask(trackId) && !mot2->isNull(trackId))
		return mot1->getVecValueAtTime(trackId, time);

	// if neither has its mask set then play whichever has a valid track
	if(useSecondary)
	{
		if(mot1 && !mot1->isNull(trackId))
			return mot1->getVecValueAtTime(trackId, time);
		if(mot2 && !mot2->isNull(trackId))
			return mot1->getVecValueAtTime(trackId, time);
	}
	else
	{
		if((mot1 && !mot1->isNull(trackId)) || (mot2 && !mot2->isNull(trackId)))
			return Vec();
	}

	// if neither has a valid track then its an error
	Piavca::Error(_T("Track invalid in both motions of a motion mask"));
	return Vec();
}

Quat MaskedMotion::getQuatValueAtTimeInternal (int trackId, float time)
{
	// if motion1 has its mask as true then play it 
	// otherwise if motion2 is has a true mask play it
	if(mot1 && mask1.getMask(trackId) && !mot1->isNull(trackId))
		return mot1->getQuatValueAtTime(trackId, time);
	if(mot2 && mask2.getMask(trackId) && !mot2->isNull(trackId))
		return mot1->getQuatValueAtTime(trackId, time);

	// if neither has its mask set then play whichever has a valid track
	if(useSecondary)
	{
		if(mot1 && !mot1->isNull(trackId))
			return mot1->getQuatValueAtTime(trackId, time);
		if(mot2 && !mot2->isNull(trackId))
			return mot1->getQuatValueAtTime(trackId, time);
	}
	else
	{
		if((mot1 && !mot1->isNull(trackId)) || (mot2 && !mot2->isNull(trackId)))
			return Quat();
	}

	// if neither has a valid track then its an error
	Piavca::Error(_T("Track invalid in both motions of a motion mask"));
	return Quat();
}
