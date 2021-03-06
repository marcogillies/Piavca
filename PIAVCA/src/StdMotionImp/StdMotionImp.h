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
 * Contributor(s):
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
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
#include "../PiavcaAPI/KeyframeMotion.h"

#include "../PiavcaAPI/PiavcaError.h"
#include "../PiavcaAPI/PiavcaCore.h"



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
	vector < vector<BaseMotionTrack *> > tracks;
	vector < vector<BaseMotionTrack *> > facial_tracks;

	BaseMotionTrack *getTrack(int trackId, int tracktype);

public:
	//! creates an empty motion (no tracks)
	StandardMotionImp(bool _facial = false) :MotionImp(_facial)
	{
		
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

	~StandardMotionImp(){deleteAllTracks();tracks.clear();facial_tracks.clear();};

	//! given an iterator tests whether it actually points to anything or if its null
	bool isNull(int trackId) const  
	{
		if(trackId >= 0)
			return (trackId >= static_cast<int>(tracks.size()) || tracks[trackId].empty());
		else
			return ((-trackId) >= static_cast<int>(facial_tracks.size()) || facial_tracks[(-trackId)].empty());
	};
	//! get the type of the track corresponding to an iterator
	int getTrackType(int trackId)const ;
	
	//! returns the length of the motion
	virtual float getMotionLength() const;
	
	
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
	int getNumKeyframes(int trackId, int type);
	//! returns the time of a particular keyframe 
	float getKeyframeTime(int trackId, int type, int keyframe);

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
