
#include "TrackMotion.h"
#include "PiavcaCore.h"
#include "PiavcaError.h"

using namespace Piavca;


void TrackMotion::initMotion(tstring fileName, bool facial, int flags, Motion *basePosture)
{
	Core::getCore()->initMotion(this, fileName, facial, flags, basePosture);
	imp->refCount++;
};

TrackMotion::TrackMotion(MotionImp *_imp): imp(_imp)
{
	imp->refCount++;
};


// assignment from a motion, create a new set of tracks and save the motion to them
const TrackMotion &TrackMotion::operator=(Motion &mot)
{
	deleteAllTracks();
	float motionLength = mot.getMotionLength();
	float keyframeSpacing = 0.1f;
	int maxKeyframe = static_cast<int>(motionLength/keyframeSpacing) + 1;
	int i;
	for(int track = mot.begin(); track < mot.end(); mot.next(track))
	{
		switch(mot.getTrackType(track))
		{
		case FLOAT_TYPE:
			addFloatTrack(track, mot.getFloatValueAtTime(track, 0));
			for( i = 0; i <= maxKeyframe; i++) 
				setFloatKeyframe(track, i*keyframeSpacing, mot.getFloatValueAtTime(track, i*keyframeSpacing));
			break;
		case VEC_TYPE:
			addVecTrack(track, mot.getVecValueAtTime(track, 0));
			for( i = 0; i <= maxKeyframe; i++) 
				setVecKeyframe(track, i*keyframeSpacing, mot.getVecValueAtTime(track, i*keyframeSpacing));
			break;
		case QUAT_TYPE:
			addQuatTrack(track, mot.getQuatValueAtTime(track, 0));
			for( i = 0; i <= maxKeyframe; i++) 
				setQuatKeyframe(track, i*keyframeSpacing, mot.getQuatValueAtTime(track, i*keyframeSpacing));
			break;
		default: Piavca::Error(_T("Unknown track type"));
		}
	}
	return *this;
};

TrackMotion *Piavca::copyMotionPosture(Motion *mot, float time)
{
	TrackMotion *tmot = new TrackMotion(mot->isFacial());

	for (int track = mot->begin(); track < mot->end(); mot->next(track))
	{
		switch(mot->getTrackType(track))
		{
		case FLOAT_TYPE:  tmot->addFloatTrack(track, mot->getFloatValueAtTime(track, time));
						  break;
		case VEC_TYPE:    tmot->addVecTrack(track, mot->getVecValueAtTime(track, time));
						  break;
		case QUAT_TYPE:   tmot->addQuatTrack(track, mot->getQuatValueAtTime(track, time));
						  break;
		default:		  Error(_T("Unknown track type"));
		}
	}
	return tmot;
}
