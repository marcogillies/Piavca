/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is StdMotionImp.h.
 *
 * The Initial Developer of the Original Code is Marco (Mark) Gillies.
 * Portions created by the Initial Developer are Copyright (C) BT plc. 2004
 * All Rights Reserved.
 *
 * ***** END LICENSE BLOCK ***** */


#ifndef STANDARD_MOTION_IMP_H
#define STANDARD_MOTION_IMP_H


#include <vector>
#include <map>
#include <algorithm>

using std::vector;
using std::map;

#include "../PiavcaAPI/PiavcaDefs.h"

#include "../PiavcaAPI/Vec.h"
#include "../PiavcaAPI/Quat.h"
#include "../PiavcaAPI/Hermite.h"

//#include "StandardTrackIteratorImp.h"
#include "../PiavcaAPI/TrackMotion.h"

#include "../PiavcaAPI/PiavcaException.h"



namespace Piavca
{

class BaseMotionTrack;

//! This is the standard implementation of the Motions class.
/*!
 *	This is a platform independant implementation. Other subtypes can be made that use platform
 *	specific enhancements. The motion in contains a vector of motion tracks that can be 
 *	accessed by name or through a trackiterator. The class itself should be created using the 
 *	StdMotionAvatarFactory and only manipulated through the Motion interface class.
 */
class PIAVCA_DECL StandardMotionImp : public MotionImp
{
	//! the tracks themselves
	/*!
	 *	Currently not sure of the best data type to use
	 */
	vector <BaseMotionTrack *> tracks;

public:
	//! creates an empty motion (no tracks)
	StandardMotionImp(bool _facial = false) :MotionImp(_facial)
	{
		int numTracks; 
		if(facial)
			numTracks = Piavca::Core::getCore()->getMaxExpressionId()+1;
		else
			numTracks = Piavca::Core::getCore()->getMaxJointId()+1;
		tracks.assign(numTracks, static_cast<BaseMotionTrack *>(0));
	};
	//! read in from a bvh file
	StandardMotionImp(tstring motionFileName, int flags, Motion *basePosture = NULL, bool test = false);
	
	StandardMotionImp(const StandardMotionImp &mot);
	const StandardMotionImp &operator=(const StandardMotionImp &mot);

	//! creates a copy of the motion imp
	/*!
	 *	This is a virtual method in MotionImp which allows you to get a (pointer to a) copy of a
	 *	motion imp correctly without knowing what type it is. 
	 */
	MotionImp *clone();

	~StandardMotionImp(){deleteAllTracks();tracks.clear();};

	//! given an iterator tests whether it actually points to anything or if its null
	bool isNull(int trackId) const  {return (trackId < 0 || trackId >= static_cast<int>(tracks.size()) || tracks[trackId] == NULL);};
	//! get the name of the track corresponding to an iterator
	//tstring getTrackName(int trackId)const {return tracks[trackId]->getName();};
	//! get the type of the track corresponding to an iterator
	trackType getTrackType(int trackId)const ;
	
	//! returns the length of the motion
	virtual float getMotionLength() const;
	
	//! gets the number of keyframes defined for a track
	//virtual int getNumKeyframes(int trackId)const{return tracks[trackId]->getNumKeyframes();};
	//! gets the i th keyframe time of a particular track
	//virtual float getKeyframe(int trackId, int i)const{return tracks[trackId]->getTime(i);};
	//! gets the last calcuated keyframe for a track 
	/*!
	 *	For standard motions this is the same as the number of keyframes
	 */
	//virtual int getLastCalculatedKeyframe(int trackId){return tracks[trackId]->getNumKeyframes()-1;};

	/*! \name add tracks of a specific type
	 *	Returns an iterator that points to the track
	 */
	//@{
	//! add a float track
	void addFloatTrack(int trackId, float initialValue);
	//! add a Vec track
	void addVecTrack(int trackId, const Vec &initialValue);
	//! add a Quat track
	void addQuatTrack(int trackId, const Quat &initialValue);
	//@}

	/*! \name operations on tracks
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

	//! returns the number of keyframes that a particular track has
	int getNumKeyframes(int trackId);
	//! returns the time of a particular keyframe 
	float getKeyframeTime(int trackId, int keyframe);

	//! get the keyframe value at time (only works for floats)
	float getFloatValueAtTimeInternal(int trackId, float time);
	//! get the keyframe value at time (only works for Vecs)
	Vec getVecValueAtTimeInternal(int trackId, float time) ;
	//! get the keyframe value at time (only works for Quats) 
	Quat getQuatValueAtTimeInternal(int trackId, float time);
	//@}

	//! delete all tracks
	void deleteAllTracks();
	//! clears a particular track (deletes all keyframes without deleting the track itself)
	void clearTrack(int trackId, bool createFirstFrame = true);
	//! clear all tracks (deletes all keyframes without deleting the tracks themselves)
	void clearAllTracks(bool createFirstFrame = true);
};


};

#endif //STANDARD_MOTION_IMP_H
