#ifndef TIME_RANGE_MOTION_H
#define TIME_RANGE_MOTION_H

#include "PiavcaAPI/MotionFilter.h"

namespace Piavca
{

	class TimeRangeMotion : public MotionFilter
	{
		float start, end;
	public:
		TimeRangeMotion();
		TimeRangeMotion(Motion *m, float _start, float _end);
		TimeRangeMotion(const TimeRangeMotion &sm);
	
		virtual Motion *clone();

		//! Sets the start of the range to be played
		void setStart(float s);
		//! Sets the end of the range to be played
		void setEnd(float e);
	    
	    //! calculates the values of a keyframe
	    PIAVCA_EXPORT virtual float  getFloatValueAtTimeInternal (int trackId, float time);
	    //! calculates the values of a keyframe
	    PIAVCA_EXPORT virtual Vec  getVecValueAtTimeInternal (int trackId, float time);	    
	    //! calculates the values of a keyframe
	    PIAVCA_EXPORT virtual Quat  getQuatValueAtTimeInternal (int trackId, float time);
	};

}

#endif //TIME_RANGE_MOTION_H
