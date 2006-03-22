
#include <fstream>
#include "MotionSaver.h"
#include "PiavcaAPI/PiavcaCore.h"
#include "PiavcaAPI/PiavcaError.h"

using namespace Piavca;

PIAVCA_EXPORT float  MotionSaver::getFloatValueAtTimeInternal (int trackId, float time)
{
	if(!filterMot)
	{
		Piavca::Error(_T("MotionSaver: trying to get a value from a null motion"));
	}
	float val =  filterMot->getFloatValueAtTime(trackId, time);
	if(tmot->isNull(trackId))
		tmot->addFloatTrack(trackId, val);
	tmot->setFloatKeyframe(trackId, time, val);
	return val;
};

PIAVCA_EXPORT Vec  MotionSaver::getVecValueAtTimeInternal (int trackId, float time)
{
	if(!filterMot)
	{
		Piavca::Error(_T("MotionSaver: trying to get a value from a null motion"));
	}
	Vec val =  filterMot->getVecValueAtTime(trackId, time);
	if(tmot->isNull(trackId))
		tmot->addVecTrack(trackId, val);
	tmot->setVecKeyframe(trackId, time, val);
	return val;
};

PIAVCA_EXPORT Quat  MotionSaver::getQuatValueAtTimeInternal (int trackId, float time)
{
	if(!filterMot)
	{
		Piavca::Error(_T("MotionSaver: trying to get a value from a null motion"));
	}
	Quat val =  filterMot->getQuatValueAtTime(trackId, time);
	if(tmot->isNull(trackId))
		tmot->addQuatTrack(trackId, val);
	tmot->setQuatKeyframe(trackId, time, val);
	return val;
};

PIAVCA_EXPORT void MotionSaver::collectFrames(float framerate)
{
	for(float time = 0; time < getMotionLength(); time += framerate)
	{
		for(int i = begin(); i < end(); i++)
		{
			trackType type = getTrackType(i);
			if(type == FLOAT_TYPE) getFloatValueAtTime(i, time);
			if(type == VEC_TYPE) getVecValueAtTime(i, time);
			if(type == QUAT_TYPE) getQuatValueAtTime(i, time);
		}
	}
}

PIAVCA_EXPORT void MotionSaver::save(tstring filename)
{
	std::ofstream of(TStringToString(filename).c_str());
	if(tmot->isFacial())
		of << "facial\n";
	else
		of << "body\n";
	for (int track = tmot->begin(); track != tmot->end(); tmot->next(track))
	{
		if(tmot->isFacial())
			of << Core::getCore()->getExpressionName(track) << " ";
		else
			of << Core::getCore()->getJointName(track) << " ";
		trackType type =  tmot->getTrackType(track);
		switch (type) 
		{
		case FLOAT_TYPE: of << "FLOAT "; break;
		case VEC_TYPE:   of << "VEC "; break;
		case QUAT_TYPE:  of << "QUAT "; break;
		default: Piavca::Error(_T("Unknown track type\n"));
		}
		float lastKeyframeTime = -100.0;
		int count = 0;
		std::cout << tmot->getNumKeyframes(track) << " keyframes\n";
		for(int i = 0; i < tmot->getNumKeyframes(track); i++)
		{
			float t = tmot->getKeyframeTime(track, i);
			// avoid writing out keyframes that are too close together
			if(fabs(t - lastKeyframeTime) < 0.01)
				continue;
			lastKeyframeTime = t;
			count++;
			of << t << " ";
			switch (type) 
			{
			case FLOAT_TYPE: of << tmot->getFloatValueAtTime(track, t) << " "; break;
			case VEC_TYPE:   of << tmot->getVecValueAtTime(track, t) << " "; break;
			case QUAT_TYPE:  of << tmot->getQuatValueAtTime(track, t) << " "; break;
			default: Piavca::Error(_T("Unknown track type\n"));
			}
		}
		std::cout << "wrote " << count << " keyframes\n";
		of << std::endl;
	}
}