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
 * The Original Code is MotionImp.h.
 *
 * The Initial Developer of the Original Code is Marco (Mark) Gillies.
 * Portions created by the Initial Developer are Copyright (C) BT plc. 2004
 * All Rights Reserved.
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

#ifndef MOTION_IMP_H
#define MOTION_IMP_H

//#include "PlatformDefs.h"

#include "Vec.h"
#include "Quat.h"

#include "Motion.h"

namespace Piavca
{
class PIAVCA_DECL Avatar;
class PIAVCA_DECL Core;
class PIAVCA_DECL Motion;
class PIAVCA_DECL KeyframeMotion;
//enum trackType;
//! An implementation class for KeyframeMotions, see the track Motion object for full details.
class PIAVCA_DECL MotionImp
{
protected:
	//KeyframeMotion *frontEnd;
	int refCount;
	
	//! whether the motions is body or facial motion
	bool facial;

	MotionImp(bool _facial = false):refCount(0), facial(_facial) {};
public:

	virtual ~MotionImp(){};

	//! returns a pointer to a copy of the motion imp
	/*!
	 *	This creates a clone that is of the same
	 *	dynamic type of the Motion Imp.
	 *	The caller now owns the clone.
	 */
	virtual MotionImp *clone() = 0;

	//! given an iterator tests whether it actually points to anything or if its null
	virtual bool isNull(int trackId) const = 0;
	//! get the name of the track corresponding to an iterator
	//virtual tstring getTrackName(int trackId) const = 0;
	//! get the type of the track corresponding to an iterator
	virtual int getTrackType(int trackId) const = 0;
	
	//! returns the length of the motion
	virtual float getMotionLength() const=0;

	/*! \name add tracks of a specific type
	 *	you can specify an initial value
	 */
	//@{
	//! add a float track
	virtual void addFloatTrack(int trackId, float initialValue) = 0;
	//! add a Vec track
	virtual void addVecTrack(int trackId, const Vec &initialValue)  = 0;
	//! add a Quat track
	virtual void addQuatTrack(int trackId, const Quat &initialValue) = 0;
	//@}

	/*! \name operations on tracks
	 *	These work by passing in the ID of the 
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
	virtual void setFloatKeyframe(int trackId, float time, float value) = 0;
	//! set keyframe value (or create a new one) with a user specified velocity (only works for floats)
	virtual void setFloatKeyframe(int trackId, float time, float value, float velocity) = 0; 
	
	//! set keyframe value (or create a new one) (only works for Vecs)
	virtual void setVecKeyframe(int trackId, float time, Vec value) = 0;
	//! set keyframe value (or create a new one) with a user specified velocity (only works for Vecs)
	virtual void setVecKeyframe(int trackId, float time, Vec value, Vec velocity) = 0; 
	
	//! set keyframe value (or create a new one) (only works for Quats)
	virtual void setQuatKeyframe(int trackId, float time, Quat value) = 0;
	//! set keyframe value (or create a new one) with a user specified velocity (only works for Quats)
	virtual void setQuatKeyframe(int trackId, float time, Quat value, Quat velocity) = 0; 
	
	//! returns the number of keyframes that a particular track has
	virtual int getNumKeyframes(int trackId, int type) = 0;
	//! returns the time of a particular keyframe 
	virtual float getKeyframeTime(int trackId, int type, int keyframe)=0;

	//! get the keyframe value at time (only works for floats)
	virtual float getFloatValueAtTimeInternal(int trackId, float time) = 0;
	//! get the keyframe value at time (only works for Vecs)
	virtual Vec getVecValueAtTimeInternal(int trackId, float time) = 0;
	//! get the keyframe value at time (only works for Quats) 
	virtual Quat getQuatValueAtTimeInternal(int trackId, float time) = 0;
	//@}

	//! delete all tracks
	virtual void deleteAllTracks() = 0;
	//! clears a particular track (deletes all keyframes without deleting the track itself)
	virtual void clearTrack(int trackId, bool createFirstFrame = true) = 0;
	//! clear all tracks (deletes all keyframes without deleting the tracks themselves)
	virtual void clearAllTracks(bool createFirstFrame = true) = 0;

	//friend class Motion;
	friend class KeyframeMotion;
	friend class Core;
};


};

#endif //MOTION_IMP_H
