
#include "BlendBetween.h"
#include "PiavcaError.h"

using namespace Piavca;

BlendBetween::BlendBetween(Motion *m1, Motion *m2, float _blend) 
			:TwoMotionCombiner(m1,m2), blend(_blend)
{
};

BlendBetween::BlendBetween(const BlendBetween &b)
	:TwoMotionCombiner(b), blend(b.blend)
{
};

float BlendBetween::getFloatValueAtTimeInternal (int trackId, float time)
{
	// if this track doesn't exist in mot2 use mot1 otherwise interpolated between them
	if(mot2->isNull(trackId))
	{
		if(mot1->isNull(trackId))
		{
			Piavca::Error(_T("trying to blend between two invalid tracks"));
			return 0.0;
		}
		return mot1->getFloatValueAtTime(trackId, time);
	}
	if(mot1->isNull(trackId))
		return mot2->getFloatValueAtTime(trackId, time);
	return static_cast<float>(mot1->getFloatValueAtTime(trackId, time)*blend
			+  mot2->getFloatValueAtTime(trackId, time)*(1.0-blend));
};

Vec BlendBetween::getVecValueAtTimeInternal   (int trackId, float time)
{
	// if this track doesn't exist in mot2 use mot1 otherwise interpolated between them
	if(mot2->isNull(trackId))
	{
		if(mot1->isNull(trackId))
		{
			Piavca::Error(_T("trying to blend between two invalid tracks"));
			return Vec();
		}
		return mot1->getVecValueAtTime(trackId, time);
	}
	if(mot1->isNull(trackId))
		return mot2->getVecValueAtTime(trackId, time);
	return mot1->getVecValueAtTime(trackId, time)*blend
			+  mot2->getVecValueAtTime(trackId, time)*(1.0f-blend);
};

Quat BlendBetween::getQuatValueAtTimeInternal  (int trackId, float time)
{
	// if this track doesn't exist in mot2 use mot1 otherwise interpolated between them
	if(mot2->isNull(trackId))
	{
		if(mot1->isNull(trackId))
		{
			Piavca::Error(_T("trying to blend between two invalid tracks"));
			return Quat();
		}
		return mot1->getQuatValueAtTime(trackId, time);
	}
	if(mot1->isNull(trackId))
		return mot2->getQuatValueAtTime(trackId, time);
	return slerp(mot1->getQuatValueAtTime(trackId, time),
				mot2->getQuatValueAtTime(trackId, time), blend);
};