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
 * The Original Code is TrackMotion.h.
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
 *
 * ***** END LICENSE BLOCK ***** */

#ifndef TRACK_MOTION_H
#define TRACK_MOTION_H

//#include "PlatformDefs.h"

#include "Vec.h"
#include "Quat.h"

//#include "PiavcaException.h"
//#include "PlatformDefs.h"
//#include "TrackIterator.h"

#include "Motion.h"
#include "MotionImp.h"
#include <assert.h>
#include <iterator>


namespace Piavca
{

//! A specialisation of the Motion Interface to deal with keyframe motion data.
/*!
 *  Motion data can be read in from a bvh file. The actual underlying representation of the motion is forwarded 
 *  to an implementation class (MotionImp) so that it can be implemented differently on different platforms if
 *	there are more efficient methods (a default implementatio is provided). Track motion provide the ability to create
 *	tracks and store data to them, if you want to create mtoion data on the fly. You can also cache the values of another
 *  motion object and save it as keyframe data.
 */

	class PIAVCA_DECL TrackMotion : public Motion 
	{
	protected:
		//! the implementation class
		MotionImp *imp;
		//! initialise a Motion in a platform dependent way using the core
		void initMotion(tstring fileName, bool facial=false, int flags=0, Motion *basePosture = NULL);

	public:
		// ! create a motion object from an implementation
		//TrackMotion(MotionImp *_imp):imp(_imp), facial (false) {};//{imp->inter = this;};
		//! create a motion object from a bvh motion data file.
		/*!
		 *  Pass in the file name and some flags that can perform some tweaks 
		 *  (see dscription of motion_corrections enum)
		 */
		TrackMotion(tstring fileName, int flags = TRANS_NONE, Motion *basePosture = NULL) 
			: imp(0)
		{
			initMotion(fileName, false, flags, basePosture);
			//imp->inter = this;
		};

		//! default constructor, creates an empty motion
		TrackMotion(bool _facial = false): imp(0)
		{
			initMotion(_PSTR(""), _facial);
			//imp->inter = this;
		};
		
		TrackMotion(MotionImp *_imp);

		//! copy constructor
		TrackMotion(const TrackMotion &mot):Motion(mot), imp(0)
		{
			(*this) = mot;
		};
		//! assignment
		const TrackMotion &operator=(const TrackMotion &mot)
		{
			//facial = mot.facial;
			name = mot.name;
			if(imp && --imp->refCount <= 0) delete imp; 
			imp = mot.imp;
			if(imp)imp->refCount++;
			return (*this);
		};

		//! copy constructor from any motion object
		/*!
		 *  The other motion object might not be a TrackMotion object and so might 
		 *	not consist of keyframe data, the new motion is sampled at regular intervals
		 *	and the values saved as keyframes;
		 */
		TrackMotion(Motion &mot):imp(0)
		{
			initMotion(_PSTR(""));
			(*this) = mot;
		};
		//! assignment from any motion object
		/*!
		 *  The other motion object might not be a TrackMotion object and so might 
		 *	not consist of keyframe data, the new motion is sampled at regular intervals
		 *	and the values saved as keyframes;
		 */
		const TrackMotion &operator=(Motion &mot);

		~TrackMotion()
		{
			if(imp && --imp->refCount <= 0) delete imp;
		};

		virtual Motion *clone()
		{
			return new TrackMotion(*this);
		};


		//! gets the time of the last keyframe of the motion
		float getMotionLength() const 
		{
			return imp->getMotionLength();
		}

		//! whether it is a face or body motion
		virtual bool isFacial()
		{
			return imp->facial;
		};

		//! whether you can access a motions value at frames other than the current one
		virtual bool isRandomAccess(){return true;};

		//! given a track ID tests whether it actually points to anything or if its null
		bool isNull(int trackId)const 
		{
			return imp->isNull(trackId);
		};
		// ! get the name of the track corresponding to an iterator
		//tstring getTrackName(int trackId)const{return imp->getTrackName(trackId);};
		//! get the type of the track corresponding to a track ID
		trackType getTrackType(int trackId)const
		{
			return imp->getTrackType(trackId);
		};
		//@}

		//! \name create new tracks of a specific type
		//@{
		//! add a float track
		void addFloatTrack(int trackId, float initialValue)
		{
			imp->addFloatTrack(trackId, initialValue);
		};
		//! add a Vec track
		void addVecTrack(int trackId, const Vec &initialValue)
		{
			imp->addVecTrack(trackId, initialValue);
		};
		//! add a Quat track
		void addQuatTrack(int trackId, const Quat &initialValue)
		{
			imp->addQuatTrack(trackId, initialValue);
		};
		//@}

		/*! \name operations on tracks
		*	These work by passing in the ID of  the 
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
		void setFloatKeyframe(int trackId, float time, float value) 
		{
			imp->setFloatKeyframe(trackId, time, value);
		};
		//! set keyframe value (or create a new one) with a user specified velocity (only works for floats)
		void setFloatKeyframe(int trackId, float time, float value, float velocity)
		{
			imp->setFloatKeyframe(trackId, time, value, velocity);
		}; 
		
		//! set keyframe value (or create a new one) (only works for Vecs)
		void setVecKeyframe(int trackId, float time, Vec value)
		{
			imp->setVecKeyframe(trackId, time, value);
		};
		//! set keyframe value (or create a new one) with a user specified velocity (only works for Vecs)
		void setVecKeyframe(int trackId, float time, Vec value, Vec velocity)
		{
			imp->setVecKeyframe(trackId, time, value, velocity);
		}; 
		
		//! set keyframe value (or create a new one) (only works for Quats)
		void setQuatKeyframe(int trackId, float time, Quat value)
		{
			imp->setQuatKeyframe(trackId, time, value);
		};
		//! set keyframe value (or create a new one) with a user specified velocity (only works for Quats)
		void setQuatKeyframe(int trackId, float time, Quat value, Quat velocity)
		{
			imp->setQuatKeyframe(trackId, time, value, velocity);
		}; 
		
		//! returns the number of keyframes that a particular track has
		int getNumKeyframes(int trackId)
		{
			return imp->getNumKeyframes(trackId);
		};
		//! returns the time of a particular keyframe 
		float getKeyframeTime(int trackId, int keyframe)
		{
			return imp->getKeyframeTime(trackId, keyframe);
		};

		//! get the keyframe value at time (only works for floats)
		float getFloatValueAtTimeInternal(int trackId, float time)
		{
			float t = time-startTime; 
			if(t < 0) t = 0;
			return imp->getFloatValueAtTimeInternal(trackId, t);
		};
		//! get the keyframe value at time (only works for Vecs)
		Vec getVecValueAtTimeInternal(int trackId, float time)
		{
			float t = time-startTime; 
			if(t < 0) t = 0;
			return imp->getVecValueAtTimeInternal(trackId, t);
		};
		//! get the keyframe value at time (only works for Quats) 
		Quat getQuatValueAtTimeInternal(int trackId, float time)
		{
			float t = time-startTime; 
			if(t < 0) t = 0;
			return imp->getQuatValueAtTimeInternal(trackId, t);
		};
		//@}
		
		//! delete all tracks
		void deleteAllTracks()
		{
			imp->deleteAllTracks();
		};
		//! clears a particular track (deletes all keyframes without deleting the track itself)
		void clearTrack(int trackId, bool createFirstFrame = true)
		{
			imp->clearTrack(trackId, createFirstFrame);
		};
		//! clear all tracks (deletes all keyframes without deleting the tracks themselves)
		void clearAllTracks(bool createFirstFrame = true)
		{
			imp->clearAllTracks(createFirstFrame);
		}; 

		friend class Core;
	};

//! creates a Track Motion that is a copy of the given motion at a given time
TrackMotion *copyMotionPosture(Motion *mot, float time);

};

#endif //TRACK_MOTION_H
