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
	//if(mot1 && mot2 && (mot1->isFacial() != mot2->isFacial()))
	//	Piavca::Error(_T("Trying to combine a facial and a body motion"));
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
	if(mot1) Motion::Dispose(mot1);//->Dispose();
	if(mot2) Motion::Dispose(mot2);//->Dispose();
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

//! gets the avatar that the motion is loaded into
Avatar *TwoMotionCombiner::getAvatar()
{
	Avatar *av = Motion::getAvatar();
	if(!av && mot1)av = mot1->getAvatar();
	if(!av && mot2)av = mot2->getAvatar();
	return av;
}

void TwoMotionCombiner::setStartTime(float time)
{
	Motion::setStartTime(time);
	if(mot1)mot1->setStartTime(time);
	if(mot2)mot2->setStartTime(time);
}

bool TwoMotionCombiner::reset(bool restart)
{
	bool retval = true;
	if(mot1)
		retval &= mot1->reset(restart);
	if(mot2)
		retval &= mot2->reset(restart);
	return retval;
};

void TwoMotionCombiner::handleEvent(tstring ev)
{
	Motion::handleEvent(ev);
	//std::cout << "event in motion " << getName() << std::endl;
	if(mot1)mot1->passEvent(ev);
	if(mot2)mot2->passEvent(ev);
};

bool TwoMotionCombiner::canHandleEvent(tstring ev)
{
	bool retval = false;
	if (mot1)
		retval |= mot1->canHandleEvent(ev);
	if (mot2)
		retval |= mot2->canHandleEvent(ev);
	return retval;
};

void TwoMotionCombiner::cleanRecursionState()
{
	Motion::cleanRecursionState();
	if(mot1)mot1->cleanRecursionState();
	if(mot2)mot2->cleanRecursionState();
};


void TwoMotionCombiner::preFrame(float time)
{
	if(mot1) mot1->preFrame(time);
	if(mot2) mot2->preFrame(time);
}

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
//bool TwoMotionCombiner::isFacial()
//{
//	if(mot1) return mot1->isFacial();
//	if(mot2) return mot2->isFacial();
//	return false;
//};

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
int TwoMotionCombiner::getTrackType(int trackId)const 
{
	if(mot1 && !mot1->isNull(trackId))
		if(mot2 && !mot2->isNull(trackId))
			return mot1->getTrackType(trackId) | mot2->getTrackType(trackId);
		else 
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
	if(mot1) Motion::Dispose(mot1);//->Dispose(); 
	//delete mot1;
	mot1 = mot;
	if(m_avatar && mot1)mot1->load(m_avatar);
	//if(mot1 && mot2 && (mot1->isFacial() != mot2->isFacial()))
	//	Piavca::Error(_T("Trying to combine a facial and a body motion"));
	// this isn't as stupid as it looks, it makes sure the
	// timings of the new motion are updated properly
	setStartTime(startTime);
};
void TwoMotionCombiner::setMotion2(Motion *mot)
{
	if(mot) mot->Reference();
	if(mot2) Motion::Dispose(mot2);//->Dispose(); 
	//delete mot2;
	mot2= mot;
	if(m_avatar && mot2)mot2->load(m_avatar);
	//if(mot1 && mot2 && (mot1->isFacial() != mot2->isFacial()))
	//	Piavca::Error(_T("Trying to combine a facial and a body motion"));
	// this isn't as stupid as it looks, it makes sure the
	// timings of the new motion are updated properly
	setStartTime(startTime);
};


int TwoMotionCombiner::getLastMotion()
{
	if(getMotion2())
		return 2;
	if(getMotion1())
		return 1;
	else
		return 0;
}

void TwoMotionCombiner::addMotion(Motion *mot)
{
	if(mot1)
		setMotion2(mot);
	else
		setMotion1(mot);
}


float TwoMotionCombiner::getCombinedFloatValue (int trackId, float time) 
{
	return 0.0f;	
};

Vec  TwoMotionCombiner::getCombinedVecValue (int trackId, float time)
{
	return Vec();	
};

Quat TwoMotionCombiner::getCombinedQuatValue (int trackId, float time)
{
	return Quat();
};

float TwoMotionCombiner::getFloatValueAtTimeInternal (int trackId, float time)
{
	// if this track doesn't exist in mot2 use mot1 otherwise interpolated between them
	if(!mot2 || mot2->isNull(trackId) || !(mot2->getTrackType(trackId) & FLOAT_TYPE))
	{
		if(!mot1 || mot1->isNull(trackId) || !(mot1->getTrackType(trackId) & FLOAT_TYPE))
		{
			Piavca::Error(_T("trying to combine two invalid tracks"));
			return 0.0;
		}
		return mot1->getFloatValueAtTime(trackId, time);
	}
	if(!mot1 || mot1->isNull(trackId) || !(mot1->getTrackType(trackId) & FLOAT_TYPE))
		return mot2->getFloatValueAtTime(trackId, time);
	return getCombinedFloatValue(trackId, time);
};

Vec TwoMotionCombiner::getVecValueAtTimeInternal   (int trackId, float time)
{
	// if this track doesn't exist in mot2 use mot1 otherwise interpolated between them
	if(!mot2 || mot2->isNull(trackId) || !(mot2->getTrackType(trackId) & VEC_TYPE))
	{
		if(!mot1 || mot1->isNull(trackId) || !(mot1->getTrackType(trackId) & VEC_TYPE))
		{
			Piavca::Error(_T("trying to combine two invalid tracks"));
			return Vec();
		}
		return mot1->getVecValueAtTime(trackId, time);
	}
	if(!mot1 || mot1->isNull(trackId) || !(mot1->getTrackType(trackId) & VEC_TYPE))
		return mot2->getVecValueAtTime(trackId, time);
	return getCombinedVecValue(trackId, time);
};

Quat TwoMotionCombiner::getQuatValueAtTimeInternal  (int trackId, float time)
{
	// if this track doesn't exist in mot2 use mot1 otherwise interpolated between them
	if(!mot2 || mot2->isNull(trackId) || !(mot2->getTrackType(trackId) & QUAT_TYPE))
	{
		if(!mot1 || mot1->isNull(trackId) || !(mot1->getTrackType(trackId) & QUAT_TYPE))
		{
			Piavca::Error(_T("trying to combine two invalid tracks"));
			return Quat();
		}
		return mot1->getQuatValueAtTime(trackId, time);
	}
	if(!mot1 || mot1->isNull(trackId) || !(mot1->getTrackType(trackId) & QUAT_TYPE))
		return mot2->getQuatValueAtTime(trackId, time);
	return getCombinedQuatValue(trackId, time);
};
