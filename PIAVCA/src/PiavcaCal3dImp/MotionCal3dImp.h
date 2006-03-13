/* LICENCE BLOCK
MotionCal3DImp.h
Copyright (C) 2005 Marco (Mark) Gillies

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef MOTION_CAL3D_IMP_H
#define MOTION_CAL3D_IMP_H

#include "PiavcaAPI/MotionImp.h"
#include "PiavcaAPI/Motion.h"
#include "PiavcaAPI/Quat.h"
#include "PiavcaAPI/Vec.h"

#include <cal3d/cal3d.h>

#include <vector>

namespace Piavca
{

class PIAVCA_DECL MotionCal3DImp : public MotionImp
{
	CalCoreAnimation *cal3DAnim;
	CalCoreSkeleton *cal3DSkel;
	std::vector<int> tracksMap;
public:
	MotionCal3DImp(tstring motionFilename, CalCoreSkeleton *skel);
	virtual ~MotionCal3DImp(void);

	MotionCal3DImp(const MotionCal3DImp &mot);
	const MotionCal3DImp &operator=(const MotionCal3DImp &mot);

	//! creates a copy of the motion imp
	/*!
	 *	This is a virtual method in MotionImp which allows you to get a (pointer to a) copy of a
	 *	motion imp correctly without knowing what type it is. 
	 */
	MotionImp *clone();

	//! given an iterator tests whether it actually points to anything or if its null
	bool isNull(int trackId) const  {return (trackId < 0 || trackId >= static_cast<int>(tracksMap.size()) || tracksMap[trackId] < 0);};
	//! get the type of the track corresponding to an iterator
	trackType getTrackType(int trackId)const 
	{
		if(trackId < 0 || tracksMap[trackId] < 0)
			return NULL_TYPE;
		else if (trackId == root_position_id)
			return VEC_TYPE;
		else
			return QUAT_TYPE;
	};

	//! returns the length of the motion
	virtual float getMotionLength() const;

	/*! \name accessor operations on tracks
	 *	These work by passing in the iterator corresponding to the 
	 *	track you want to perform the operation on.
	 *	Each operation is type specific, if you perform an operation
	 *	on a track of the wrong type it will result in an exception.
	 *	It's a bit messy
	 *	but it is probably the easiest way of doing it (without having to 
	 *	bother with run time type inference). The way I see it working is
	 *	that when they are called you will normally know what type the 
	 *	track is, for example, when you update a joint you will know that 
	 *	the track is a Quat (or whatever the type is). This means that
	 *	won't have to check what type it is.
	 */
	//@{
	//! get the keyframe value at time (only works for floats)
	float getFloatValueAtTimeInternal(int trackId, float time);
	//! get the keyframe value at time (only works for Vecs)
	Vec getVecValueAtTimeInternal(int trackId, float time) ;
	//! get the keyframe value at time (only works for Quats) 
	Quat getQuatValueAtTimeInternal(int trackId, float time);
	//@}

	
	//! returns the number of keyframes that a particular track has
	int getNumKeyframes(int trackId);
	//! returns the time of a particular keyframe 
	float getKeyframeTime(int trackId, int keyframe);

	/*! \name methods to write to tracks, Cal3D motions are read only so none of these will work
	 *	Returns an iterator that points to the track
	 */
	//@{
	//! add a float track
	void addFloatTrack(int trackId, float initialValue);
	//! add a Vec track
	void addVecTrack(int trackId, const Vec &initialValue);
	//! add a Quat track
	void addQuatTrack(int trackId, const Quat &initialValue);
	
	//! set keyframe value (or create a new one) (only works for floats)
	void setFloatKeyframe(int trackId, float time, float value);
	//! set keyframe value (or create a new one) with a user specified velocity (only works for floats)
	void setFloatKeyframe(int trackId, float time, float value, float velocity);
	
	//! set keyframe value (or create a new one) (only works for Vecs)
	void setVecKeyframe(int trackId, float time, Vec value);
	//! set keyframe value (or create a new one) with a user specified velocity (only works for Vecs)
	void setVecKeyframe(int trackId, float time, Vec value, Vec velocity);
	
	//! set keyframe value (or create a new one) (only works for Quats)
	void setQuatKeyframe(int trackId, float time, Quat value);
	//! set keyframe value (or create a new one) with a user specified velocity (only works for Quats)
	void setQuatKeyframe(int trackId, float time, Quat value, Quat velocity);

	//! delete all tracks
	void deleteAllTracks();
	//! clears a particular track (deletes all keyframes without deleting the track itself)
	void clearTrack(int trackId, bool createFirstFrame = true);
	//! clear all tracks (deletes all keyframes without deleting the tracks themselves)
	void clearAllTracks(bool createFirstFrame = true);
	//!@}

	friend class PiavcaCal3DCore;
};

}; // namespace Piavca

#endif //MOTION_CAL3D_IMP_H
