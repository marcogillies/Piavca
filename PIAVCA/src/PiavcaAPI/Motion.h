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
 * The Original Code is Motion.h.
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


#ifndef MOTION_H
#define MOTION_H

//#include "PlatformDefs.h"

#include "PiavcaAPI/Vec.h"
#include "PiavcaAPI/Quat.h"

//#include "PiavcaException.h"
//#include "PiavcaCore.h"
//#include "TrackIterator.h"

//#include "MotionImp.h"
#include <typeinfo>
using std::type_info;

#include <assert.h>
#include <iterator>

namespace Piavca
{
	class Avatar;

	//! an enum defining the types that can be included in motion tracks
	enum trackType {NULL_TYPE=0, FLOAT_TYPE=1, VEC_TYPE=2, QUAT_TYPE=4};


	//! An exception class that is thrown when a type specific method of Motion is called with an iterator of the wrong type.
	//class WrongTrackTypeException : public CException
	//{	
	//public:
	//	WrongTrackTypeException(tstring details):CException(details){};
	//};

	//! This enum specifies a number of tweaks that can be performed when reading in a bvh file
	enum motion_corrections
	{
		TRANS_NONE = 0, /*!< no tweaks done */
		TRANS_SWAP_XZ = 1, /*!< swap the X and Z axes */ 
		TRANS_SWAP_XY = 2, /*!< swap the X and Y axes */ 
		TRANS_SWAP_YZ = 4, /*!< swap the Y and Z axes */ 
		TRANS_CYCLE_YZX = 8, /*!< cycle the axes so y->x z->y x->z */ 
		TRANS_CYCLE_ZXY = 16, /*!< cycle the axes so z->x x->y y->z*/ 
		TRANS_NEG_X = 32, /*!< negate the (final, after swapping) X axis */  
		TRANS_NEG_Y = 64, /*!< negate the (final, after swapping) Y axis */  
		TRANS_NEG_Z = 128, /*!< negate the (final, after swapping) Z axis */ 
		TRANS_ARM_UP = 256, /*!< correct for rest posture, from crucifix to arms by side */ 
		TRANS_ARM_DOWN = 512, /*!< correct for rest posture, from arms by side to crucifix */ 
		TRANS_REVERSE_ORDER = 1024, /*!< reverse the order in which the XYZ rotations are performed */
		TRANS_SKIP_FIRST_FRAME = 2048, /*!< does not read in the first frame of the animation */
		TRANS_NO_ROOT_POS_CORRECTION = 4096 /*!< don't apply the corrections to the root position */
	};


//! An abstract interface to represent motion.
/*!
 *  This is an abstract interface that represents all types of animation in a way that is independent of 
 *  individual Avatars. It can be used to represent keyframe animation, motion combination, procedural animatio
 *	or real time animation streams. The key abstraction is that motion consists of a number of tracks, each
 *  normally corresponding to a joint of the avatar. The track is a continuous, time varying stream of data value (either of
 *	float, Vec or Quat type). The fundamental operation on a track is to query it for its value at a given time.
 *  Like joints tracks are represented by integer IDs, the IDs of a corresponding track and joint are the same
 *  so testing for equivelence is easy. Tracks are accessed by passing the appropriate ID to a method of
 *  the motion object.
 */

class PIAVCA_DECL Motion
{
	//! assignment private, you can't copy motion instances, use a pointer
	const Motion &operator=(const Motion &av){assert(0); return (*this);}
	//bool bTemp;
	int refCount;
	bool ownedByCore;
	// if the motion has been visited in an event recursion
	bool visited;
protected:
	Avatar *m_avatar;
	float startTime;
	tstring name;
	float pausedTime;
	float offsetTime;

	// used for debug printouts
	static int debug_prefix;

	//! a pointer to the Piavca::Core object that manages all the avatars and motions
	//Piavca::Core *core;
	//! the granularity at which keyframes can be set 
	/*!
	 *  Though time is represented in floating point, keyframes can only be 
	 *	set as integers to avoid problems with rounding errors. The granularity is 
	 *	the conversion factor between the two.
	 */
	//float keyframeGranularity;
public:
	//! default constructor
	Motion():m_avatar(NULL), startTime(0), pausedTime(-1), offsetTime(0), refCount(0), ownedByCore(false), name(_T("")), visited(false) 
	{
	};
	Motion(const Motion &mot):m_avatar(NULL), startTime(mot.startTime), pausedTime(-1), offsetTime(0), refCount(0), ownedByCore(false), name(mot.name), visited(false)
	{
	};
	
	virtual ~Motion(){};

	//! creates a copy of the motion
	virtual Motion *clone()=0;

	//! returns the name of the type
	virtual Piavca::tstring getClassName(){return "Motion";};

	//! casts a motion to this type
	static Motion *castToThisType(Motion *m){return m;};
	
	//! initializes the motion
	virtual void create();

	//! prints out info about the motion heirarchy
	virtual void printInfo();
	
	int getId() const
	{
		return (int) (this);
	};

	bool operator==(const Motion *m)const {return m != NULL && (*this) == (*m);};
	bool operator==(const Motion &m)const {return getId() == m.getId();};
	bool operator!=(const Motion *m)const {return !((*this) == m);};
	bool operator!=(const Motion &m)const {return !((*this) == m);};

	//! called when the motion is loaded into an avatar
	virtual void load(Avatar *av)
	{
		m_avatar = av;
	};
	//! called when the motion is unloaded from an avatar
	virtual void unload()
	{
		m_avatar = NULL;
	}
	//! checks if the motion has been loaded into an avatar
	virtual bool loaded()
	{
		return !(m_avatar == NULL);
	}
	//! gets the avatar that the motion is loaded into
	virtual Avatar *getAvatar()
	{
		return m_avatar;
	}
	//! sets the start time of the motion. Called when its loaded into an avatar.
	virtual void  setStartTime(float t)
	{
		startTime = t;
	};
	//! return the start time of the motion
	float getStartTime(){return startTime;};
	//! returns the end time of the motion
	float getEndTime()  {return startTime + getMotionLength();};

	//! does any resetting needed 
	virtual void reset(){};

	virtual void event(tstring ev)
	{
		//std::cout << "event in motion " << getName() << std::endl;
		visited = true;
	};
	
	virtual std::vector<Piavca::tstring> getEventNames()
	{
		return std::vector<Piavca::tstring>();
	}

	virtual void cleanRecursionState()
	{
		visited = false;
	};

	bool wasVisited()
	{
		return visited;
	};

	//! send a message to sub motions that an "event" happened
	void sendEvent(tstring ev)
	{
		event(ev);
		cleanRecursionState();
	}

	//! registers an owner for a motion, the motion will not be deleted until disposed is called.
	/*!
	 *	Internally this increments the reference count.
	 */
	void Reference(){refCount++;};


	//!	decrements the references count and deletes the motion if it reaches zero
	void Dispose();
	//! makes a motion temporary so that it is removed when all avatars have finished with it
	void makeTemp(){ownedByCore = false;};

	//! gives a name to the motion
	void setName(tstring nm){name = nm;};
	//! returns the name of the motion
	tstring getName(){return name;};

	//! finds the first submotion with a given name
	virtual Motion *findSub(tstring nm){if(nm == name) return this; else return NULL;};

	//! finds the first submotion with a given type
	virtual Motion *findSubByType(const type_info &ty)
	{
		const type_info &thistype = typeid(*this);
		if(ty == thistype) 
			return this; 
		else 
			return NULL;
	};

	//! keyframes can only be set with a certain granularity, this sets it
	/*!
	 *  Though time is represented in floating point, keyframes can only be 
	 *	set as integers to avoid problems with rounding errors. The granularity is 
	 *	the conversion factor between the two.
	 */
	//void setKeyframeGranularity(float gran) {keyframeGranularity = gran;};
	//! keyframes can only be set with a certain granularity, this gets it
	/*!
	 *  Though time is represented in floating point, keyframes can only be 
	 *	set as integers to avoid problems with rounding errors. The granularity is 
	 *	the conversion factor between the two.
	 */
	//float getKeyframeGranularity() {return keyframeGranularity;};

	//! gets the time of the end of the motion
	virtual float getMotionLength() const 
	{
		// by default assume infinte time, or something close
		// this will cuase a bug if Piavca is ever run constantly for over 
		// a million years without interruption. I guess its unlikely
		return 5.0e15;
	};

	//! whether it is a face or body motion
	virtual bool isFacial(){return false;};

	//! whether you can access a motions value at frames other than the current one
	virtual bool isRandomAccess(){return false;};

	//! the ID of the first track that is present in the motion (the ordering is arbitrary)
	int begin() const ;
	//! the last track + 1
	int end() const;
	//! given a track ID get the next valid ID
	int next(int &trackId)const ;
	//! given a track ID tests whether it actually points to anything or if its null
	virtual bool isNull(int trackId) const =0;
	// ! get the name of the track corresponding to an ID
	//virtual tstring getTrackName(int trackId)const = 0;
	//! get the type of the track corresponding to an ID
	virtual int getTrackType(int trackId)const = 0;
	//@}

	//! pause the motion so that it can be restarted from the current point
	void pause();
	void unpause();

	/*! do any processing that needs to be done at the start of a frame.
	 *	This is called before get{Float/Vec/Quat}ValueAtTime
	 */
	virtual void preFrame(float time);

	//! get the value of a track at a given time (only works for floats)
	float getFloatValueAtTime(int trackId, float time)
	{
		if(pausedTime >=0)
			return getFloatValueAtTimeInternal(trackId, pausedTime);
		else
			return getFloatValueAtTimeInternal(trackId, time+offsetTime);
	};
	//! get the value of a track at a given time (only works for Vecs)
	Vec getVecValueAtTime(int trackId, float time)
	{
		if(pausedTime >=0)
			return getVecValueAtTimeInternal(trackId, pausedTime);
		else
			return getVecValueAtTimeInternal(trackId, time+offsetTime);
	};
	//! get the value of a track at a given time (only works for Quats) 
	Quat getQuatValueAtTime(int trackId, float time)
	{		
		if(pausedTime >=0)
			return getQuatValueAtTimeInternal(trackId, pausedTime);
		else
			return getQuatValueAtTimeInternal(trackId, time+offsetTime);
	};
	
	//! internal version of getFloatValueAtTime, to be overridden
	virtual float getFloatValueAtTimeInternal(int trackId, float time)
	{
		return 0.0f;	
	};
	//! internal version of getVecValueAtTime, to be overridden
	virtual Vec getVecValueAtTimeInternal(int trackId, float time)
	{
		return Vec();
	};
	//! internal version of getQuatValueAtTime, to be overridden
	virtual Quat getQuatValueAtTimeInternal(int trackId, float time)
	{
		return Quat();
	};
	//@}

	friend class Core;
};


};

#endif //MOTION_H
