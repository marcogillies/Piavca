
#include "SubMotion.h"
#include "PiavcaAPI/PiavcaError.h"

using namespace Piavca;

float SubMotion::getAdjustedTime(float time)
{
	time = time - getStartTime();
	//std::cout << "start " << start << " time " << time << " ";
	if(start >= 0) time += start;
	//std::cout << time << " end " << end << " ";
	if(end >= 0 && time > end) time = end;
	//std::cout << " time " << time << std::endl;
	return time + getStartTime();
}

SubMotion::SubMotion()
	:MotionFilter(), start(-1), end(-1)
{

};

SubMotion::SubMotion(Motion *m, float _start, float _end)
	:MotionFilter(m), start(_start), end(_end)
{
	
};

SubMotion::SubMotion(const SubMotion &sm)
	:MotionFilter(sm), start(sm.start), end(sm.end)
{

};

Motion *SubMotion::clone()
{
	return new SubMotion(*this);
};

//! gets the length of the motion in seconds
float SubMotion::getMotionLength() const
{
	if(filterMot)
	{
		float s = 0;
		if(start >= 0) s = start;
		float e = filterMot->getMotionLength();
		if(end >= 0 && end < e) e = end;
		return e - s;	
	}
	else
		return 0;
};

//! Sets the start of the range to be played
void SubMotion::setStart(float s)
{
	start = s;
};
//! Sets the end of the range to be played
void SubMotion::setEnd(float e)
{
	end = e;
};

//! calculates the values of a keyframe
PIAVCA_EXPORT float  SubMotion::getFloatValueAtTimeInternal (int trackId, float time)
{
	if(!filterMot)
	{
		Piavca::Error(_T("Scale motion speed: trying to get a value from a null motion"));
	}
	return filterMot->getFloatValueAtTime(trackId, getAdjustedTime(time));
};

//! calculates the values of a keyframe
PIAVCA_EXPORT Vec  SubMotion::getVecValueAtTimeInternal (int trackId, float time)
{
	if(!filterMot)
	{
		Piavca::Error(_T("Scale motion speed: trying to get a value from a null motion"));
	}
	return  filterMot->getVecValueAtTime(trackId, getAdjustedTime(time));
};

//! calculates the values of a keyframe
PIAVCA_EXPORT Quat  SubMotion::getQuatValueAtTimeInternal (int trackId, float time)
{
	if(!filterMot)
	{
		Piavca::Error(_T("Scale motion speed: trying to get a value from a null motion"));
	}
	return filterMot->getQuatValueAtTime(trackId, getAdjustedTime(time));
};
