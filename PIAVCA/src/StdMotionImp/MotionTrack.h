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
 * The Original Code is MotionTrack.h.
 *
 * The Initial Developer of the Original Code is Marco (Mark) Gillies.
 * Portions created by the Initial Developer are Copyright (C) BT plc. 2004
 * All Rights Reserved.
 *
 * ***** END LICENSE BLOCK ***** */


#ifndef MOTION_TRACK_H
#define MOTION_TRACK_H

#include "../PiavcaAPI/PiavcaDefs.h"

#include "../PiavcaAPI/Vec.h"
#include "../PiavcaAPI/Quat.h"
#include "../PiavcaAPI/Hermite.h"

//#include "StandardTrackIteratorImp.h"
#include "../PiavcaAPI/TrackMotion.h"

#include "../PiavcaAPI/PiavcaException.h"

#define keyframeGranularity 0.001

namespace Piavca {


//const float keyframeTime = 1/24;

//! The basic keyframe representation
/*!
 *	It is a template and can take either float, Vec or Quat values,
 *	most tracks represent joint orientations and therefore take Quat
 *	values
 */
template <class T>
struct keyframe
{
	//! the time at which the keyframe occurs
	/*!
	 *	This actual timing in the animation is calculated in floating point
	 *	but the keyframes are integers so that you can exactly compare two 
	 *	keyframes to see if they happen at the same time. Otherwise slight 
	 *	impresissions might mean two keyframes are created where only one 
	 *	should have been.
	 */
	int time;
	//! whether the user has specified velocities or the system should calculate them
	bool userVel;
	//! the value of the keyframe
	T value;
	//! the derivative at the keyframe
	T velocity;
};

template <class T>
bool operator<(keyframe<T> k, float t){return k.time < t;}; 
template <class T>
bool operator<(float t, keyframe<T> k){return t < k.time ;}; 
template <class T>
bool operator<(keyframe<T> k1, keyframe<T> k2){return k1.time < k2.time ;}; 

//! this is a base class for motion tracks (sequences of keyframes)
/*!
 *	The track holds a sequence of keyframes for one element (e.g. joint rotation).
 *	The reason there is a base class is that the tracks themselves are templates,
 *	they can be tracks of floats, Vecs or Quats. This is fine but you need to
 *	be able to handle a track irrespective of its type. For example, storing the tracks
 *	in a single data structure without knowing what type they are.
 *	This base type provides a way of doing this. You can access all the methods through
 *	the base type but trying to call a method of the wrong type (e.g. adding a float keyframe
 *	to a Vec track) results in an exception.
 *	Probably won't be part of the API itself as in some implementations this stuff might
 *	be handled in the underlying API.
 */
class PIAVCA_DECL BaseMotionTrack
{
	//! an enum giving the type of data contained in the track
	trackType type;
public:
	BaseMotionTrack(trackType _type):type(_type) {};
	BaseMotionTrack(const BaseMotionTrack &track):type(track.type) {};
	virtual ~BaseMotionTrack() {};

	
	virtual const Vec &getOffset() const = 0;
	virtual void       setOffset(const Vec &offs) = 0;
	
	//! Gets the keyframe that happens immediately before time
	/*!
	 *	Used to find which keyframes to interpolate to ge the value at time
	 */
	//virtual vector<keyframe <T> >::iterator getKeyframeBefore(float time) = 0;
	//! Produces a copy of the track
	/*!
	 *	Used to copy without knowing the type of the track
	 */
	virtual BaseMotionTrack *clone() = 0;
	
	//! Delete the keyframe at time
	virtual void deleteKeyframeAtTime(int time) = 0;
	//! Delete all keyframes
	virtual void clear(bool createFirstFrame = true) = 0;

	//! get the time of the last keyframe
	virtual float getLength() = 0;

	//! gets the number of keyframes defined for the track
	virtual int getNumKeyframes()const=0;
	//! gets the i th keyframe time
	virtual float getTime(int i)const=0;

	//! generate text for a wrong track type exception
	tstring generateExceptionText(trackType calledType)const;

	//! Calculate the velocities at each keyframe
	/*!
	 *	The client can explicitely specify velocities in which
	 *	case they are not recalculated.
	 *	The formula used is a varient of Catmull-Rom splines
	 */
	virtual void calcVelocities()const = 0;

	/*! \name Type specific methods
	 *	These are methods that depend on the type of the track.
	 *	There is one of each for each type. If one is called on a 
	 *	track with the wrong type an exception is thrown. It's a bit messy
	 *	but it is probably the easiest way of doing it (without having to 
	 *	bother with run time type inference). The way I see it working is
	 *	that when they are called you will normally know what type the 
	 *	track is, for example, when you update a joint you will know that 
	 *	the track is a Quat (or whatever the type is). This means that
	 *	won't have to check what type it is.
	 */
	//@{
	//! get the value of the keyframe at time (only for float tracks)
	virtual float	getFloatValAtTime(float time) const = 0;
	//! get the value of the keyframe at time (only for Vec tracks)
	virtual Vec	getVecValAtTime(float time) const  = 0;
	//! get the value of the keyframe at time (only for Quat tracks)
	virtual Quat	getQuatValAtTime(float time) const = 0;

	//! create a float key frame or set the value of an existing one (only works for float tracks)
	virtual void setFloatKeyframe(float time, float val) = 0;
	//! create a float key frame or set the value of an existing one with a user specified velocity (only works for float tracks)
	virtual void setFloatKeyframe(float time, float val, float vel) = 0;
	//! create a Vec key frame or set the value of an existing one (only works for Vec tracks)
	virtual void setVecKeyframe(float time, Vec val) = 0;
	//! create a Vec key frame or set the value of an existing one with a user specified velocity (only works for Vec tracks)
	virtual void setVecKeyframe(float time, Vec val, Vec vel) = 0;
	//! create a Quat key frame or set the value of an existing one (only works for Quat tracks)
	virtual void setQuatKeyframe(float time, Quat val) = 0;
	//! create a Quat key frame or set the value of an existing one with a user specified velocity (only works for Quat tracks)
	virtual void setQuatKeyframe(float time, Quat val, Quat vel) = 0;
	//@}

	//! get the type of the track
	trackType getTrackType() const {return type;};
	
};

//! Concrete Motion track
/*!
 *	This is the sub type of base motion track that actually does the 
 *	work, it is a template so can contain different types, float
 *	Vec or Quat. Tracks only contain keyframes of a single type.
 *	Probably won't be part of the API itself as in some implementations this stuff might
 *	be handled in the underlying API.
 */
template <class T>
class MotionTrack : public BaseMotionTrack
{
public:
	//typedef vector<keyframe <T> >::iterator iterator;
protected:
	//! the actual array of keyframes
	vector < keyframe<T> > track;
	//! the offset of the corresponding joint
	/*!
	 *	The offset is the distance of a joint from the start of the 
	 *	parent joint. This is read in from the heirarchy section of 
	 *	the bvh file. 
	 */ 
	Vec offset;
	//@{
	//! \name two internal variables
	mutable int lastkeyframe;
	mutable bool velocitiesInvalid;
	//@}
public:

	//! create a track
	/*!
	 *	trackName is, of course, the name of the track and is used to match the track with its 
	 *	joint which will have the same name. initialValue is the value the track should have at
	 *	time 0
	 */
	MotionTrack(const T &initialValue, trackType type):BaseMotionTrack(type), velocitiesInvalid(true)
	{
		keyframe<T> k;
		k.time = 0;
		k.value = initialValue;
		k.userVel = false;
		track.push_back(k);
		lastkeyframe = 0;
		//lastkeyframe = track.insert(track.begin(), k);
		velocitiesInvalid = true;
	};
	MotionTrack(const MotionTrack<T> &mt)
		:BaseMotionTrack(mt), track(mt.track), 
		velocitiesInvalid(mt.velocitiesInvalid),
		offset(mt.offset)
	{
		lastkeyframe = 0;
	};

	~MotionTrack(){};

	//! gets the values of the offset
	/*!
	 *	The offset is the distance of a joint from the start of the 
	 *	parent joint. This is read in from the heirarchy section of 
	 *	the bvh file. 
	 */ 
	const Vec &getOffset()const {return offset;};
	//! sets the values of the offset
	/*!
	 *	The offset is the distance of a joint from the start of the 
	 *	parent joint. This is read in from the heirarchy section of 
	 *	the bvh file. 
	 */ 
	void setOffset(const Vec &offs){offset = offs;};

	//! create a copy of the track
	/*!
	 *	Used by BaseMotionTrack to create a new track without knowing the type
	 */
	virtual BaseMotionTrack *clone() {return new MotionTrack<T>(*this);};

	//! get the time of the last keyframe
	virtual float getLength()
	{
	  //std::cout << TStringToString(getName()) <<  " " << track.size() << " " << track[track.size()-1].time*(MotionImp::keyframeGranularity) << std::endl;
	  //cout.flush();
		return static_cast<float>(track[track.size()-1].time*(keyframeGranularity));
	};


	//! gets the number of keyframes defined for the track
	virtual int getNumKeyframes()const{return static_cast<int>(track.size());};

	//! add a new keframe
	/*
	 *	This will normally be called from BaseMotionTrack
	 *	via a type specific method (see below)
	 */
	int setKeyframe(float time, const T &value) 
	{
		velocitiesInvalid = true;
		int prev = getKeyframeBefore(time);
		//int t = time/(MotionImp::keyframeGranularity);// there must be a better way of rounding numbers

		float correctedTime = static_cast<float>(time/(keyframeGranularity));
		float floored = floorf(correctedTime);
		if(correctedTime - floored > 0.5)
		  correctedTime = ceilf(correctedTime);
		else 
		  correctedTime = floored;
		
		int t = static_cast<int>(correctedTime);

		if(track.size() <= 0)
		  {
		    keyframe<T> k; 
		    k.time = t; 
		    k.value = value;
		    k.userVel = false;
		    track.push_back(k);
		  }
		if(track[prev].time == t)
		{
			track[prev].time = t;
			track[prev].value = value;
			track[prev].userVel = false;
			return lastkeyframe = prev;
		}
		else
		{
			keyframe<T> k; 
			k.time = t; 
			k.value = value;
			k.userVel = false;
			track.push_back(track[track.size()-1]);
			for(int i = static_cast<int>(track.size())-1; i > prev+1; i--)
			{
				track[i] = track[i-1];
			}	
			track[prev+1] = k;
			return lastkeyframe = prev+1;
			//return lastkeyframe = track.insert(prev+1, k);
		}
	};
	//! add a new keframe with a user specified velocity
	/*
	 *	This will normally be called from BaseMotionTrack
	 *	via a type specific method (see below)
	 */
	int setKeyframe(float time, const T &value, const T &velocity)
	{
		//int t = time/(MotionImp::keyframeGranularity);
		// there must be a better way of rounding numbers
		float correctedTime = static_cast<float>(time/(keyframeGranularity));
		float floored = floorf(correctedTime);
		if(correctedTime - floored > 0.5)
		  correctedTime = ceilf(correctedTime);
		else 
		  correctedTime = floored;
		
		int t = static_cast<int>(correctedTime);

		int prev = getKeyframeBefore(time);
		if(track[prev].time == t)
		{
			track[prev].time = t;
			track[prev].value = value;
			track[prev].userVel = true;
			track[prev].velocity = velocity;
			return lastkeyframe = prev;
		}
		else
		{
			keyframe<T> k; 
			k.time = t; 
			k.value = value;
			k.velocity = velocity;
			k.userVel = true;
			track.push_back(track[track.size()-1]);
			for(int i = static_cast<int>(track.size())-1; i > prev+1; i--)
			{
				track[i] = track[i-1];
			}	
			track[prev+1] = k;
			return lastkeyframe = prev+1;
			//return lastkeyframe = track.insert(prev+1, k);
		}
	};
	
	//! does an interpolation to get the value of the track at time t
	T getValAtTime(float t)  const
	{
		if(velocitiesInvalid)
			calcVelocities();
		int before = getKeyframeBefore(t);
		int after = before + 1;
		//std::cout << track[before].time << " "
		//	<< track[before].value << std::endl;
		if(after >= static_cast<int>(track.size()))
			return track[before].value;
		
		//std::cout << track[before].time << " "
		//	<< track[before].value << " "
		//	<< track[after].time << " "
		//	<< track[after].value << std::endl;
		//t *= MotionImp::keyframeGranularity;
		return HermiteEvaluate(static_cast<float>(t - track[before].time*(keyframeGranularity)), 
			static_cast<float>((track[after].time - track[before].time)*(keyframeGranularity)), 
			track[before].value, track[before].velocity, track[after].value, track[after].velocity);
	}
 

	//! get the value of keyframe i
	/*
	 *	This will normally be called from BaseMotionTrack
	 *	via a type specific method (see below)
	 */
	const T &getVal(int i) {return track[i].value;};
	//! get the velocity of keyframe i
	/*
	 *	This will normally be called from BaseMotionTrack
	 *	via a type specific method (see below)
	 */
	const T &getVel(int i) {return track[i].velocity;};
	//! get the time at which keyframe i happens
	float getTime(int i) const{return i < 0 ? -1.0f : static_cast<float>(track[i].time*keyframeGranularity);};
	//! get a reference to keyframe i
    const keyframe<T> &getKeyframe(int i) {return track[i];};

	//! Delete the keyframe at time
	void deleteKeyframeAtTime(int t)
	{
		int i = getKeyframeBefore(static_cast<float>(t));
		if(track[i].time == t)
		{
			//track.erase(i); 
			for (unsigned int j = i; j < track.size(); j++) 
				track[j] = track[j+1];
			track.pop_back();
			lastkeyframe = 0;
			//lastkeyframe = track.begin();
		}
	};
	//! delete all keyframes
	void clear(bool createFirstFrame= true)
    {
	  track.clear(); 
	  lastkeyframe = 0;
	  if(createFirstFrame)
		setKeyframe(0, T());
	};

	//! Gets the keyframe that happens immediately before time
	/*!
	 *	Used to find which keyframes to interpolate to get the value at time
	 */
	int getKeyframeBefore(float time) const
	{
		//std::cout << "in get keyframe before\n";
		float t = static_cast<float>(time/keyframeGranularity);

		// there must be a better way of rounding numbers
		float rounded = floorf(t);
		if(t - rounded > 0.5)
		  rounded = ceilf(t);
		
		int intTime = static_cast<int>(rounded);
		//if(lastkeyframe+1 == track.end() && (*lastkeyframe).time <= t)
		//	return lastkeyframe;
		if(lastkeyframe+1 == track.size() 
			&& static_cast<float>(track[lastkeyframe].time) <= t )
		{
		  //std::cout << "last keyframe\n";
			return lastkeyframe;
		}
		//if(lastkeyframe+1 == track.end() && (*lastkeyframe).time <= t)
		//	return lastkeyframe;
		if(lastkeyframe+1 < static_cast<int>(track.size())
			&& static_cast<float>(track[lastkeyframe].time) <= t 
			&& t <= static_cast<float>(track[lastkeyframe+1].time))
			{
				if(intTime == track[lastkeyframe+1].time)
				{
					//std::cout << "equal to next keyframe\n";
					return ++lastkeyframe;
				}
				else
				{
					//std::cout << ">= current keyframe\n";
					return lastkeyframe;
				}
			}

		if(lastkeyframe+1 < static_cast<int>(track.size()) 
			&& lastkeyframe+2 < static_cast<int>(track.size()) 
			&& static_cast<float>(track[lastkeyframe+1].time) <= t 
			&& t <= static_cast<float>(track[lastkeyframe+2].time))
		{
			lastkeyframe++;
			if(intTime == track[lastkeyframe+1].time)
			{
				//std::cout << "equal to after next keyframe\n";
				return ++lastkeyframe;
			}
			else
			{
				//std::cout << ">= next keyframe\n";
				return lastkeyframe;
			}

		}
		size_t span = 0;
		size_t start = 0;
		span = track.size();

		while (span > 1)
		{	// divide and conquer, find half that contains answer
			size_t span2 = span / static_cast<size_t>(2);
			size_t mid = start + span2;

			if (static_cast<float>(track[mid].time) < t)
			{
				start = mid; 
				span -= span2;
			}
			else
				span = span2;
		}
		lastkeyframe = static_cast<int>(start);
		//std::cout << "found frame" << intTime << " " << track[lastkeyframe].time  << " " << track[lastkeyframe+1].time << std::endl;
		if(lastkeyframe+1 < static_cast<int>(track.size())  
			&& intTime == track[lastkeyframe+1].time)
			{
				//std::cout << "== after found keyframe\n";
				return ++lastkeyframe;
			}
			else
			{
				//std::cout << ">= found frame\n";
				return lastkeyframe;
			}

	};

	//! Calculate the velocities at each keyframe
	/*!
	 *	The client can explicitely specify velocities in which
	 *	case they are not recalculated.
	 *	The formula used is a varient of Catmull-Rom splines
	 */
	void calcVelocities()const 
	{
	        MotionTrack<T> *nonConstThis = const_cast<MotionTrack<T> *>(this);
		if(!track[0].userVel)
			nonConstThis->track[0].velocity = T();
		if(!track[track.size()-1].userVel)
			nonConstThis->track[track.size()-1].velocity = T();
		for (unsigned int i = 1; i < track.size()-1; i++)
		{
			if (!track[i].userVel)
				nonConstThis->track[i].velocity = keyframeTangent(track[i].value, 
								    track[i-1].value, static_cast<float>(track[i].time - track[i-1].time), 
								    track[i+1].value, static_cast<float>(track[i+1].time - track[i].time));
		}
		velocitiesInvalid = false;
	};

	/*! \name Type specific methods
	 *	These are methods that depend on the type of the track.
	 *	There is one of each for each type. If one is called on a 
	 *	track with the wrong type an exception is thrown. It's a bit messy
	 *	but it is probably the easiest way of doing it (without having to 
	 *	bother with run time type inference). The way I see it working is
	 *	that when they are called you will normally know what type the 
	 *	track is, for example, when you update a joint you will know that 
	 *	the track is a Quat (or whatever the type is). This means that
	 *	won't have to check what type it is.
	 *	There are specialisations for each type that do not throw the exception
	 */
	//@{
	//! get the value of the keyframe at time (only for float tracks)
	virtual float	getFloatValAtTime(float t)const { Piavca::Error(generateExceptionText(FLOAT_TYPE)); return 0.0;};
	//! get the value of the keyframe at time (only for Vec tracks)
	virtual Vec	getVecValAtTime(float t)const   {Piavca::Error(generateExceptionText(VEC_TYPE));return Vec();};
	//! get the value of the keyframe at time (only for Quat tracks)
	virtual Quat	getQuatValAtTime(float t)const  {Piavca::Error(generateExceptionText(QUAT_TYPE)); return Quat();};

	//! create a float key frame or set the value of an existing one (only works for float tracks)
	void setFloatKeyframe(float time, float val) {Piavca::Error(generateExceptionText(FLOAT_TYPE));};
	//! create a float key frame or set the value of an existing one with a user specified velocity (only works for float tracks)
	void setFloatKeyframe(float time, float val, float vel) {Piavca::Error(generateExceptionText(FLOAT_TYPE));};
	//! create a Vec key frame or set the value of an existing one (only works for Vec tracks)
	void setVecKeyframe(float time, Vec val) {Piavca::Error(generateExceptionText(VEC_TYPE));};
	//! create a Vec key frame or set the value of an existing one with a user specified velocity (only works for Vec tracks)
	void setVecKeyframe(float time, Vec val, Vec vel) {Piavca::Error(generateExceptionText(VEC_TYPE));};
	//! create a Quat key frame or set the value of an existing one (only works for Quat tracks)
	void setQuatKeyframe(float time, Quat val) {Piavca::Error(generateExceptionText(QUAT_TYPE));};
	//! create a Quat key frame or set the value of an existing one with a user specified velocity (only works for Quat tracks)
	void setQuatKeyframe(float time, Quat val, Quat vel) {Piavca::Error(generateExceptionText(QUAT_TYPE));};
	//@}
friend class StandardMotionImp;
};

template<>
float	MotionTrack<float>::getFloatValAtTime(float t) const	{return getValAtTime(t);};
template<>
Vec	MotionTrack<Vec>::getVecValAtTime(float t) const	{return getValAtTime(t);};
template<>
Quat	MotionTrack<Quat>::getQuatValAtTime(float t) const	{return getValAtTime(t);};

template<>
void MotionTrack<float>::setFloatKeyframe(float time, float val) {setKeyframe(time, val);};
template<>
void MotionTrack<float>::setFloatKeyframe(float time, float val, float vel) {setKeyframe(time, val, vel);};
template<>
void MotionTrack<Vec>::setVecKeyframe(float time, Vec val) {setKeyframe(time, val);};
template<>
void MotionTrack<Vec>::setVecKeyframe(float time, Vec val, Vec vel) {setKeyframe(time, val, vel);};
template<>
void MotionTrack<Quat>::setQuatKeyframe(float time, Quat val) {setKeyframe(time, val);};
template<>
void MotionTrack<Quat>::setQuatKeyframe(float time, Quat val, Quat vel) {setKeyframe(time, val, vel);};
	
}; //namespace

#endif // MOTION_TRACK_H
