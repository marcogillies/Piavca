
#include "MotionAdder.h"
#include "PiavcaError.h"

using namespace Piavca;

float MotionAdder::getFloatValueAtTimeInternal (int trackId, float time)
{
	// if this track doesn't exist in mot2 use mot1 otherwise interpolated between them
	if(!mot1 || mot1->isNull(trackId))
	{
		if(!mot2 || mot2->isNull(trackId))
		{
			Piavca::Error(_T("trying to blend two invalid tracks"));
		}
		return mot2->getFloatValueAtTime(trackId, time)*scaleSecond;
	}
	if(!mot2 || mot2->isNull(trackId))
		return mot1->getFloatValueAtTime(trackId, time);
		else
	return mot1->getFloatValueAtTime(trackId, time)
		+  mot2->getFloatValueAtTime(trackId, time)*scaleSecond;
};

//! calculates the values of a keyframe
/*!  The results is the sum of the two motions.
	*/
Vec   MotionAdder::getVecValueAtTimeInternal   (int trackId, float time)
{
	// if this track doesn't exist in mot2 use mot1 otherwise interpolated between them
	if(!mot1 || mot1->isNull(trackId))
	{
		if(!mot2 || mot2->isNull(trackId))
		{
			Piavca::Error(_T("trying to blend two invalid tracks"));
		}
		return mot2->getVecValueAtTime(trackId, time)*scaleSecond;
	}
	if(!mot2 || mot2->isNull(trackId))
		return mot1->getVecValueAtTime(trackId, time);
	else
		return mot1->getVecValueAtTime(trackId, time)
			+  mot2->getVecValueAtTime(trackId, time)*scaleSecond;
};

//! calculates the values of a keyframe
/*!  The results is the quaternion multiplication of the two motions
	*  (which is similar to vector addition).
	*/
Quat  MotionAdder::getQuatValueAtTimeInternal  (int trackId, float time)
{
	// if this track doesn't exist in mot2 use mot1 otherwise interpolated between them
	Quat retVal;
	if(!mot1 || mot1->isNull(trackId))
	{
		if(!mot2 || mot2->isNull(trackId))
		{
			Piavca::Error(_T("trying to blend two invalid tracks"));
		}
		retVal = mot2->getQuatValueAtTime(trackId, time);
		retVal.Scale(scaleSecond);
	}
	else
	{
		if(!mot2 || mot2->isNull(trackId))
		{
			retVal = mot1->getQuatValueAtTime(trackId, time);
		}
		else
		{
			retVal = mot2->getQuatValueAtTime(trackId, time);
			retVal.Scale(scaleSecond);
			// this multiplication does mot1 then mot2
			retVal = retVal * mot1->getQuatValueAtTime(trackId, time);
		}
	}
	return retVal;
};