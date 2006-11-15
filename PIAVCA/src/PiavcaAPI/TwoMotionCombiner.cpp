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
 * The Original Code is TwoMotionCombiner.cpp.
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

#include "TwoMotionCombiner.h"
#include "PiavcaError.h"

using namespace Piavca;

TwoMotionCombiner::TwoMotionCombiner():Motion(), mot1(NULL), mot2(NULL)
{

};
TwoMotionCombiner::TwoMotionCombiner(Motion *m1, Motion *m2) 
	:Motion(), mot1(m1), mot2(m2)
{
	//if(m1) mot1 = m1->clone(); else mot1 = NULL;
	//if(m2) mot2 = m2->clone(); else mot2 = NULL;
	if(mot1) mot1->Reference();
	if(mot2) mot2->Reference();
	if(mot1 && mot2 && (mot1->isFacial() != mot2->isFacial()))
		Piavca::Error(_T("Trying to combine a facial and a body motion"));
};
TwoMotionCombiner::TwoMotionCombiner(const TwoMotionCombiner &tmc)
	:Motion(tmc) //mot1(tmc.mot1), mot2(tmc.mot2)
{
	if(tmc.mot1) 
	{
		mot1 = tmc.mot1->clone(); 
		mot1->Reference();
	}
	else mot1 = NULL;
	if(tmc.mot2) 
	{
		mot2 = tmc.mot2->clone(); 
		mot2->Reference();
	}
	else mot2 = NULL;
};
TwoMotionCombiner::~TwoMotionCombiner()
{
	if(mot1) mot1->Dispose();
	if(mot2) mot2->Dispose();
}

void TwoMotionCombiner::printInfo()
{
	Motion::printInfo();
	debug_prefix++;
	if(mot1)mot1->printInfo();
	if(mot2)mot2->printInfo();
	debug_prefix--;
};

//! finds the first submotion with a given name
Motion *TwoMotionCombiner::findSub(tstring nm)
{
	Motion *m = Motion::findSub(nm);
	if(m) 
		return m;
	if(mot1) m = mot1->findSub(nm);
	if(m) 
		return m;
	if(mot2) m = mot2->findSub(nm);
	return m;
};

//! finds the first submotion with a given type
Motion *TwoMotionCombiner::findSubByType(const type_info &ty)
{
	Motion *m = Motion::findSubByType(ty);
	if(m) 
		return m;
	if(mot1) m = mot1->findSubByType(ty);
	if(m) 
		return m;
	if(mot2) m = mot2->findSubByType(ty);
	return m;
};

void TwoMotionCombiner::load(Avatar *av)
{
	Motion::load(av);
	if(mot1)mot1->load(av);
	if(mot2)mot2->load(av);
}
void TwoMotionCombiner::unload()
{
	Motion::unload();
	if(mot1)mot1->unload();
	if(mot2)mot2->unload();
}
bool TwoMotionCombiner::loaded()
{
	bool retval = Motion::loaded();
	if(mot1)retval |= mot1->loaded();
	if(mot2)retval |= mot2->loaded();
	return retval;
}

void TwoMotionCombiner::setStartTime(float time)
{
	Motion::setStartTime(time);
	if(mot1)mot1->setStartTime(time);
	if(mot2)mot2->setStartTime(time);
}

void TwoMotionCombiner::reset()
{
	if(mot1)mot1->reset();
	if(mot2)mot2->reset();
};

//! gets the length of the combined motion (by default the length of the longer of the two)
float TwoMotionCombiner::getMotionLength() const
{
	float l1 = 0.0;
	float l2 = 0.0;
	if(mot1) l1 = mot1->getMotionLength();
	if(mot2) l2 = mot2->getMotionLength();
	if(l1 > l2)
		return l1;
	else 
		return l2;
};

//! whether it is a face or body motion
bool TwoMotionCombiner::isFacial()
{
	if(mot1) return mot1->isFacial();
	if(mot2) return mot2->isFacial();
	return false;
};

bool TwoMotionCombiner::isRandomAccess()
{
	bool ra1 = true, ra2 = true;
	if(mot1) ra1 = mot1->isRandomAccess();
	if(mot2) ra2 = mot2->isRandomAccess();
	return ra1 && ra2;
}


//! given a track ID tests whether it actually points to anything or if its null
/*!
	*	is null if the track is null in both motions.
	*/
bool TwoMotionCombiner::isNull(int trackId)const 
{
	return (!mot1 || mot1->isNull(trackId)) && (!mot2 || mot2->isNull(trackId));
};

//! get the type of the track corresponding to an iterator
trackType TwoMotionCombiner::getTrackType(int trackId)const 
{
	if(mot1 && !mot1->isNull(trackId))
		return mot1->getTrackType(trackId);
	else
		if(mot2 && !mot2->isNull(trackId))
			return mot2->getTrackType(trackId);
		else 
			return NULL_TYPE;
};

void TwoMotionCombiner::setMotion1(Motion *mot)
{
	if(mot) mot->Reference();
	if(mot1) mot1->Dispose(); 
	//delete mot1;
	mot1 = mot;
	if(m_avatar && mot1)mot1->load(m_avatar);
	if(mot1 && mot2 && (mot1->isFacial() != mot2->isFacial()))
		Piavca::Error(_T("Trying to combine a facial and a body motion"));
	// this isn't as stupid as it looks, it makes sure the
	// timings of the new motion are updated properly
	setStartTime(startTime);
};
void TwoMotionCombiner::setMotion2(Motion *mot)
{
	if(mot) mot->Reference();
	if(mot2) mot2->Dispose(); 
	//delete mot2;
	mot2= mot;
	if(m_avatar && mot2)mot2->load(m_avatar);
	if(mot1 && mot2 && (mot1->isFacial() != mot2->isFacial()))
		Piavca::Error(_T("Trying to combine a facial and a body motion"));
	// this isn't as stupid as it looks, it makes sure the
	// timings of the new motion are updated properly
	setStartTime(startTime);
};
