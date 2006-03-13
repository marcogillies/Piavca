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
 * The Original Code is StdMotionImp.cpp.
 *
 * The Initial Developer of the Original Code is Marco (Mark) Gillies.
 * Portions created by the Initial Developer are Copyright (C) BT plc. 2004
 * All Rights Reserved.
 *
 * ***** END LICENSE BLOCK ***** */


//#ifdef PIAVCA_DLL
//#define PIAVCA_EXPORT __declspec( dllimport ) 
//#else
//#define PIAVCA_EXPORT
//#endif

#include "PiavcaAPI/PiavcaDefs.h"
#include "StdMotionImp.h"
#include "MotionTrack.h"
#include "bvhMotionParser.h"

#include <assert.h>
#include <utility>
#include <algorithm>
#include "PiavcaAPI/Avatar.h"
#include "PiavcaAPI/PiavcaCore.h"

using namespace Piavca;

tstring lookupTypeName(trackType type)
{
	switch (type)
	{
	case FLOAT_TYPE :	return tstring(_T("float"));
	case VEC_TYPE :		return tstring(_T("Vec"));
	case QUAT_TYPE :	return tstring(_T("Quat"));
	default :			Piavca::Error(_T("Unknown track type")); return tstring(_T(""));
	}
}

tstring BaseMotionTrack::generateExceptionText(trackType calledType)const 
{
	return _T("Attempted to call a ") + lookupTypeName(calledType) + _T(" method on a ") + lookupTypeName(type) + _T("track\n");
}

MotionImp *StandardMotionImp::clone()
{
	return new StandardMotionImp(*this);
}

StandardMotionImp::StandardMotionImp(const tstring motionFileName, int flags, Motion *basePosture, bool test)
{
	tracks.assign(Piavca::Core::getCore()->getMaxJointId()+1, static_cast<BaseMotionTrack *>(0));
	
	std::string::size_type dot_pos = motionFileName.find('.');
	std::string suff = motionFileName.substr(dot_pos+1);
	std::transform(suff.begin(), suff.end(), suff.begin(), tolower);
	if(suff == "bvh")
	{
		facial = false;
		readBvhMotion(Piavca::Core::getCore(), this, TStringToString(motionFileName), flags, basePosture, test);
	}
	else
	{
		std::ifstream is(TStringToString(motionFileName).c_str());
		std::string motiontype;
		is >> motiontype;
		std::transform(motiontype.begin(), motiontype.end(), motiontype.begin(), tolower);
		if(motiontype == "facial")
			facial = true;
		else if(motiontype == "body")
			facial = false;
		else 
			Piavca::Error(_T("Unknown motion type ") + StringToTString(motiontype));
		std::string jointName;
		while (is >> jointName)
		{
			std::string type;
			trackType tracktype;
			while(is >> type)
			{
				if(type == "FLOAT") 
				{
					tracktype = FLOAT_TYPE;
					break;
				}
				else if(type == "VEC")
				{
					 tracktype = VEC_TYPE;
					 break;
				}
				else if(type == "QUAT") 
				{
					tracktype = QUAT_TYPE;
					break;
				}
				else 
				{
					jointName = jointName + " " + type;
				}
			}
			std::cout << jointName << std::endl;
			int trackId;
			if(facial)
				trackId = Core::getCore()->getExpressionId(jointName);
			else
				trackId = Core::getCore()->getJointId(jointName);
			if(trackId < 0)
				Piavca::Error(_T("Unknown joint or expression name ") + StringToTString(jointName));
			
			float time;
			float fval;
			Vec vval;
			Quat qval;
			switch (tracktype)
			{
			case FLOAT_TYPE :
				while(is >> time >> fval)
				{
					if(isNull(trackId)) addFloatTrack(trackId, fval);
					setFloatKeyframe(trackId, time, fval);
				}
				break;
			case VEC_TYPE :
				while(is >> time >> vval)
				{
					if(isNull(trackId)) addVecTrack(trackId, vval);
					setVecKeyframe(trackId, time, vval);
				}
				break;
			case QUAT_TYPE :
				while(is >> time >> qval)
				{
					if(isNull(trackId)) 
					{
						addQuatTrack(trackId, qval);
						std::cout << "setting first frame " << qval << std::endl;
					}	
					std::cout << "setting frame " << time << qval << std::endl;
					setQuatKeyframe(trackId, time, qval);
				}
				break;
			}
			is.clear();
//			while (is >> time)
//			{
//				switch (tracktype)
//				{
//				case FLOAT_TYPE :
//					is >> fval;
//					if(isNull(trackId)) addFloatTrack(trackId, fval);
//					setFloatKeyframe(trackId, time, fval);
//					break;
//				case VEC_TYPE :
//					is >> vval;
//					if(isNull(trackId)) addVecTrack(trackId, vval);
//					setVecKeyframe(trackId, time, vval);
//					break;
//				case QUAT_TYPE :
//					is >> qval;
//					if(isNull(trackId)) 
//					{
//						addQuatTrack(trackId, qval);
//						std::cout << "setting first frame " << qval << std::endl;
//					}	
//					std::cout << "setting frame " << time << qval << std::endl;
//					setQuatKeyframe(trackId, time, qval);
//					break;
//				}
//			}
		};
	}
};
	
	
StandardMotionImp::StandardMotionImp(const StandardMotionImp &mot)
{
	facial = mot.facial;
	tracks.reserve(mot.tracks.size());
	for (std::vector< BaseMotionTrack * >::size_type  i = 0; i < mot.tracks.size(); i++)
	{
		if(mot.tracks[i])
			tracks.push_back(mot.tracks[i]->clone());
		else
			tracks.push_back(NULL);
	}
};
	
const StandardMotionImp &StandardMotionImp::operator=(const StandardMotionImp &mot)
{
	deleteAllTracks();
	facial = mot.facial;
	tracks = mot.tracks;
	return (*this);
};

trackType StandardMotionImp::getTrackType(int trackId)const 
{
	if(trackId < 0 || tracks[trackId] == NULL)
		return NULL_TYPE;
	else
		return tracks[trackId]->getTrackType();
};

float StandardMotionImp::getMotionLength() const
{
	float max = 0.0;
	for (std::vector< BaseMotionTrack * >::size_type  i = 0; i < tracks.size(); i++)
	{
		if(tracks[i] && tracks[i]->getLength() > max)
			max = tracks[i]->getLength();
	}
	return max;
};

void StandardMotionImp::addFloatTrack(int trackId, float initialValue)
{
    if(trackId < 0)
	{
		Piavca::Error(_PSTR("Null trackId passed in to addFloatTrack"));
		return;
	}
	if(static_cast<size_t>(trackId) >= tracks.size() 
		&&  trackId <= Core::getCore()->getMaxJointId())
	{
		tracks.insert(tracks.end(), trackId - (tracks.size()-1), NULL);
	}
	if(tracks[trackId] == NULL)
		tracks[trackId] = new MotionTrack<float>(initialValue, FLOAT_TYPE);
	else
		setFloatKeyframe(trackId, 0.0, initialValue);
};
void StandardMotionImp::addVecTrack(int trackId, const Vec &initialValue)
{
    if(trackId < 0)
	{
		Piavca::Error(_PSTR("Null trackId passed in to addVecTrack"));
		return;
	}
	if(static_cast<size_t>(trackId) >= tracks.size() 
		&&  trackId <= Core::getCore()->getMaxJointId())
	{
		tracks.insert(tracks.end(), trackId - (tracks.size()-1), NULL);
	}
	if(tracks[trackId] == NULL)
		tracks[trackId] = new MotionTrack<Vec>(initialValue, VEC_TYPE);
	else
		setVecKeyframe(trackId, 0.0, initialValue);
};
void StandardMotionImp::addQuatTrack(int trackId, const Quat &initialValue)
{
    if(trackId < 0)
	{
		Piavca::Error(_PSTR("Null trackId passed in to addQuatTrack"));
		return;
	}
	if(static_cast<size_t>(trackId) >= tracks.size() 
		&&  trackId <= Core::getCore()->getMaxJointId())
	{
		tracks.insert(tracks.end(), trackId - (tracks.size()-1), NULL);
	}

	if(tracks[trackId] == NULL)
		tracks[trackId] = new MotionTrack<Quat>(initialValue, QUAT_TYPE);
	else
		setQuatKeyframe(trackId, 0.0, initialValue);
};

void StandardMotionImp::setFloatKeyframe(int trackId, float time, float value)
{
    if(trackId < 0)
	{
		Piavca::Error(_PSTR("Null trackId passed in to setFloatKeyframe"));
		return;
	}
    if(tracks[trackId] == NULL)
	{
		Piavca::Error(_PSTR("setFloatKeyframe called on track missing in motion"));
		return;
	}
	tracks[trackId]->setFloatKeyframe(time, value);
}; 
void StandardMotionImp::setFloatKeyframe(int trackId, float time, float value, float velocity)
{
    if(trackId < 0)
	{
		Piavca::Error(_PSTR("Null trackId passed in to setFloatKeyframe"));
		return;
	}
    if(tracks[trackId] == NULL)
	{
		Piavca::Error(_PSTR("setFloatcKeyframe called on track missing in motion"));
		return;
	}
	tracks[trackId]->setFloatKeyframe(time, value, velocity);
};  
	
void StandardMotionImp::setVecKeyframe(int trackId, float time, Vec value)
{
    if(trackId < 0)
	{
		Piavca::Error(_PSTR("Null trackId passed in to setVecKeyframe"));
		return;
	}
    if(tracks[trackId] == NULL)
	{
		Piavca::Error(_PSTR("setVecKeyframe called on track missing in motion"));
		return;
	}
	tracks[trackId]->setVecKeyframe(time, value);
}; 
	
void StandardMotionImp::setVecKeyframe(int trackId, float time, Vec value, Vec velocity)
{
    if(trackId < 0)
	{
		Piavca::Error(_PSTR("Null trackId passed in to setVecKeyframe"));
		return;
	}
    if(tracks[trackId] == NULL)
	{
		Piavca::Error(_PSTR("setVecKeyframe called on track missing in motion"));
		return;
	}
	tracks[trackId]->setVecKeyframe(time, value, velocity);
}; 
	
void StandardMotionImp::setQuatKeyframe(int trackId, float time, Quat value)
{
    if(trackId < 0)
	{
		Piavca::Error(_PSTR("Null trackId passed in to setQuatcKeyframe"));
		return;
	}
    if(tracks[trackId] == NULL)
	{
		Piavca::Error(_PSTR("setQuatKeyframe called on track missing in motion"));
		return;
	}
	tracks[trackId]->setQuatKeyframe(time, value);
};
void StandardMotionImp::setQuatKeyframe(int trackId, float time, Quat value, Quat velocity)
{
    if(trackId < 0)
	{
		Piavca::Error(_PSTR("Null trackId passed in to setQuatcKeyframe"));
		return;
	}
    if(tracks[trackId] == NULL)
	{
		Piavca::Error(_PSTR("setQuatKeyframe called on track missing in motion"));
		return;
	}
	tracks[trackId]->setQuatKeyframe(time, value, velocity);
}; 


int StandardMotionImp::getNumKeyframes(int trackId)
{
	return tracks[trackId]->getNumKeyframes();	
};

float StandardMotionImp::getKeyframeTime(int trackId, int keyframe)
{
	return tracks[trackId]->getTime(keyframe);
};
	
float StandardMotionImp::getFloatValueAtTimeInternal(int trackId, float time)  
{
    if(trackId < 0)
	{
		Piavca::Error(_PSTR("Null trackId passed in to getFloatValueAtTime"));
		return 0.0;
	}
    if(tracks[trackId] == NULL)
	{
		Piavca::Error(_PSTR("getFloatValueAtTime called on track missing in motion"));
		return 0.0;
	}
	return tracks[trackId]->getFloatValAtTime(time);
};
Vec StandardMotionImp::getVecValueAtTimeInternal(int trackId, float time)  
{
    if(trackId < 0)
	{
		Piavca::Error(_PSTR("Null trackId passed in to getVecValueAtTime"));
		return Vec();
	}
    if(tracks[trackId] == NULL)
	{
		Piavca::Error(_PSTR("getVecValueAtTime called on track missing in motion"));
		return Vec();
	}
	return tracks[trackId]->getVecValAtTime(time);
};
Quat StandardMotionImp::getQuatValueAtTimeInternal(int trackId, float time) 
{
    if(trackId < 0)
	{
		Piavca::Error(_PSTR("Null trackId passed in to getQuatValueAtTime"));
		return Quat();
	}
    if(tracks[trackId] == NULL)
	{
		Piavca::Error(_PSTR("getQuatValueAtTime called on track missing in motion"));
		return Quat();
	}
	//std::cout << tracks[trackId]->getQuatValAtTime(time) << std::endl;
	return  tracks[trackId]->getQuatValAtTime(time);
};


void StandardMotionImp::deleteAllTracks()
{
	for (std::vector< BaseMotionTrack * >::size_type i = 0; i < tracks.size(); i++)
	{
		delete tracks[i];
		tracks[i] = NULL;
	}
};
void StandardMotionImp::clearTrack(int trackId, bool createFirstFrame)
{
	if(tracks[trackId])
		tracks[trackId]->clear(createFirstFrame);
}

void StandardMotionImp::clearAllTracks(bool createFirstFrame)
{
	for (std::vector< BaseMotionTrack * >::size_type i = 0; i < tracks.size(); i++)
	{
		if(tracks[i])
			tracks[i]->clear(createFirstFrame);
	}
};
