
#include "TimeRangeMotion.h"
#include "PiavcaAPI/PiavcaError.h"

using namespace Piavca;

TimeRangeMotion::TimeRangeMotion()
	:MotionFilter(), start(-1), end(-1)
{

};

TimeRangeMotion::TimeRangeMotion(Motion *m, float _start, float _end)
	:MotionFilter(m), start(_start), end(_end)
{
	
};

TimeRangeMotion::TimeRangeMotion(const TimeRangeMotion &sm)
	:MotionFilter(sm), start(sm.start), end(sm.end)
{

};

Motion *TimeRangeMotion::clone()
{
	return new TimeRangeMotion(*this);
};

//! Sets the start of the range to be played
void TimeRangeMotion::setStart(float s)
{
	start = s;
};
//! Sets the end of the range to be played
void TimeRangeMotion::setEnd(float e)
{
	end = e;
};

//! calculates the values of a keyframe
PIAVCA_EXPORT float  TimeRangeMotion::getFloatValueAtTimeInternal (int trackId, float time)
{
	if(!filterMot)
	{
		Piavca::Error(_T("Scale motion speed: trying to get a value from a null motion"));
	}
	if( (start < 0 || time >= start) && (end < 0 || time <= end))
		return filterMot->getFloatValueAtTime(trackId, time);
	else 
		return 0;
};

//! calculates the values of a keyframe
PIAVCA_EXPORT Vec  TimeRangeMotion::getVecValueAtTimeInternal (int trackId, float time)
{
	if(!filterMot)
	{
		Piavca::Error(_T("Scale motion speed: trying to get a value from a null motion"));
	}
	if( (start < 0 || time >= start) && (end < 0 || time <= end))
		return  filterMot->getVecValueAtTime(trackId, time);
	else
		return Vec();
};

//! calculates the values of a keyframe
PIAVCA_EXPORT Quat  TimeRangeMotion::getQuatValueAtTimeInternal (int trackId, float time)
{
	if(!filterMot)
	{
		Piavca::Error(_T("Scale motion speed: trying to get a value from a null motion"));
	}
	Quat q;
	if( (start < 0 || time >= start) && (end < 0 || time <= end))
	{
		q = filterMot->getQuatValueAtTime(trackId, time);
		//std::cout << "time range motion " << q << " " << time << " " << start << " " << end << std::endl;
	}
	else
	{
		q = Quat();
		std::cout << "time range motion out of range" << " " << time << " " << start << " " << end << std::endl;
	}
	return q;
};
