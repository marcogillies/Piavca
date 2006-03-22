#ifndef SUB_MOTION_H
#define SUB_MOTION_H

#include "PiavcaAPI/MotionFilter.h"

namespace Piavca
{

	class SubMotion : public MotionFilter
	{
		float start, end;

		float getAdjustedTime(float time);
	public:
		SubMotion();
		SubMotion(Motion *m, float _start, float _end);
		SubMotion(const SubMotion &sm);
	
		virtual Motion *clone();

		//! gets the length of the motion in seconds
		virtual float getMotionLength() const;

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

#endif //SUB_MOTION_H
