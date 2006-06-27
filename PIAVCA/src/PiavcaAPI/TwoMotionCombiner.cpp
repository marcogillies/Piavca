
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
	if(avatar && mot1)mot1->load(avatar);
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
	if(avatar && mot2)mot2->load(avatar);
	if(mot1 && mot2 && (mot1->isFacial() != mot2->isFacial()))
		Piavca::Error(_T("Trying to combine a facial and a body motion"));
	// this isn't as stupid as it looks, it makes sure the
	// timings of the new motion are updated properly
	setStartTime(startTime);
};
