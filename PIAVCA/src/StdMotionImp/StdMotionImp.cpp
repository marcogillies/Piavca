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
	std::string::size_type dot_pos = motionFileName.find('.');
	std::string suff = motionFileName.substr(dot_pos+1);
	std::transform(suff.begin(), suff.end(), suff.begin(), tolower);
	if(suff == "bvh")
	{
		tracks.assign(Piavca::Core::getCore()->getMaxJointId()+1, static_cast<BaseMotionTrack *>(0));
	
		facial = false;
		readBvhMotion(Piavca::Core::getCore(), this, TStringToString(motionFileName), flags, basePosture, test);
	}
	else
	{
		std::ifstream is(TStringToString(motionFileName).c_str());
		if(!is)
			Piavca::Error(_T("Could not open file ") + motionFileName);
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
						//std::cout << "setting first frame " << qval << std::endl;
					}	
					//std::cout << "setting frame " << time << qval << std::endl;
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
	facial_tracks.reserve(mot.facial_tracks.size());
	for (std::vector< BaseMotionTrack * >::size_type  i = 0; i < mot.facial_tracks.size(); i++)
	{
		if(mot.facial_tracks[i])
			facial_tracks.push_back(mot.facial_tracks[i]->clone());
		else
			facial_tracks.push_back(NULL);
	}
};
	
const StandardMotionImp &StandardMotionImp::operator=(const StandardMotionImp &mot)
{
	deleteAllTracks();
	facial = mot.facial;
	tracks = mot.tracks;
	facial_tracks = mot.facial_tracks;
	return (*this);
};

trackType StandardMotionImp::getTrackType(int trackId)const 
{
	if(trackId >= 0)
	{
		if (tracks[trackId] == NULL)
			return NULL_TYPE;
		else
			return tracks[trackId]->getTrackType();
	}
	else
	{
		trackId = -trackId;
		if (facial_tracks[trackId] == NULL)
			return NULL_TYPE;
		else
			return facial_tracks[trackId]->getTrackType();
	}
};

float StandardMotionImp::getMotionLength() const
{
	float max = 0.0;
	for (std::vector< BaseMotionTrack * >::size_type  i = 0; i < tracks.size(); i++)
	{
		if(tracks[i] && tracks[i]->getLength() > max)
			max = tracks[i]->getLength();
	}
	for (std::vector< BaseMotionTrack * >::size_type  i = 0; i < facial_tracks.size(); i++)
	{
		if(facial_tracks[i] && facial_tracks[i]->getLength() > max)
			max = facial_tracks[i]->getLength();
	}
	return max;
};

void StandardMotionImp::addFloatTrack(int trackId, float initialValue)
{
    if(trackId >= 0)
	{
		if (trackId > Core::getCore()->getMaxJointId())
		{
			Piavca::Error(_PSTR("Null trackId passed in to addFloatTrack"));
			return;
		}
		if(static_cast<size_t>(trackId) >= tracks.size() )
		{
			tracks.insert(tracks.end(), trackId - (tracks.size()-1), NULL);
		}
		if(tracks[trackId] == NULL)
			tracks[trackId] = new MotionTrack<float>(initialValue, FLOAT_TYPE);
		else
			setFloatKeyframe(trackId, 0.0, initialValue);
	}
	else
	{
		if (trackId < Core::getCore()->getMaxExpressionId())
		{
			Piavca::Error(_PSTR("Null trackId passed in to addFloatTrack"));
			return;
		}
		trackId = -trackId;
		if(static_cast<size_t>(trackId) >= facial_tracks.size())
		{
			facial_tracks.insert(facial_tracks.end(), trackId - (facial_tracks.size()-1), NULL);
		}
		if(facial_tracks[trackId] == NULL)
			facial_tracks[trackId] = new MotionTrack<float>(initialValue, FLOAT_TYPE);
		else
			setFloatKeyframe(-trackId, 0.0, initialValue);
	}
};
void StandardMotionImp::addVecTrack(int trackId, const Vec &initialValue)
{
    if(trackId >= 0)
	{
		if (trackId > Core::getCore()->getMaxJointId())
		{
			Piavca::Error(_PSTR("Null trackId passed in to addVecTrack"));
			return;
		}
		if(static_cast<size_t>(trackId) >= tracks.size() )
		{
			tracks.insert(tracks.end(), trackId - (tracks.size()-1), NULL);
		}
		if(tracks[trackId] == NULL)
			tracks[trackId] = new MotionTrack<Vec>(initialValue, VEC_TYPE);
		else
			setVecKeyframe(trackId, 0.0, initialValue);
	}
	else
	{
		if (trackId < Core::getCore()->getMaxExpressionId())
		{
			Piavca::Error(_PSTR("Null trackId passed in to addVecTrack"));
			return;
		}
		trackId = -trackId;
		if(static_cast<size_t>(trackId) >= facial_tracks.size())
		{
			facial_tracks.insert(facial_tracks.end(), trackId - (facial_tracks.size()-1), NULL);
		}
		if(facial_tracks[trackId] == NULL)
			facial_tracks[trackId] = new MotionTrack<Vec>(initialValue, VEC_TYPE);
		else
			setVecKeyframe(-trackId, 0.0, initialValue);
	}
};
void StandardMotionImp::addQuatTrack(int trackId, const Quat &initialValue)
{
    if(trackId >= 0)
	{
		if (trackId > Core::getCore()->getMaxJointId())
		{
			Piavca::Error(_PSTR("Null trackId passed in to addQuatTrack"));
			return;
		}
		if(static_cast<size_t>(trackId) >= tracks.size())
		{
			tracks.insert(tracks.end(), trackId - (tracks.size()-1), NULL);
		}
		if(tracks[trackId] == NULL)
			tracks[trackId] = new MotionTrack<Quat>(initialValue, QUAT_TYPE);
		else
			setQuatKeyframe(trackId, 0.0, initialValue);
	}
	else
	{
		if (trackId < Core::getCore()->getMaxExpressionId())
		{
			Piavca::Error(_PSTR("Null trackId passed in to addQuatTrack"));
			return;
		}
		trackId = -trackId;
		if(static_cast<size_t>(trackId) >= facial_tracks.size())
		{
			facial_tracks.insert(facial_tracks.end(), trackId - (facial_tracks.size()-1), NULL);
		}
		if(facial_tracks[trackId] == NULL)
			facial_tracks[trackId] = new MotionTrack<Quat>(initialValue, QUAT_TYPE);
		else
			setQuatKeyframe(-trackId, 0.0, initialValue);
	}
};

void StandardMotionImp::setFloatKeyframe(int trackId, float time, float value)
{
    BaseMotionTrack *track = getTrack(trackId);
    if(track == NULL)
	{
		Piavca::Error(_PSTR("setFloatKeyframe called on a Null track"));
		return;
	}
	track->setFloatKeyframe(time, value);
}; 
void StandardMotionImp::setFloatKeyframe(int trackId, float time, float value, float velocity)
{
    BaseMotionTrack *track = getTrack(trackId);
    if(track == NULL)
	{
		Piavca::Error(_PSTR("setFloatcKeyframe called on a Null track"));
		return;
	}
	track->setFloatKeyframe(time, value, velocity);
};  
	
void StandardMotionImp::setVecKeyframe(int trackId, float time, Vec value)
{
	BaseMotionTrack *track = getTrack(trackId);
    if(track == NULL)
	{
		Piavca::Error(_PSTR("setVecKeyframe called on a Null track"));
		return;
	}
	track->setVecKeyframe(time, value);
}; 
	
void StandardMotionImp::setVecKeyframe(int trackId, float time, Vec value, Vec velocity)
{
    BaseMotionTrack *track = getTrack(trackId);
    if(track == NULL)
	{
		Piavca::Error(_PSTR("setVecKeyframe called on a Null track"));
		return;
	}
    track->setVecKeyframe(time, value, velocity);
}; 
	
void StandardMotionImp::setQuatKeyframe(int trackId, float time, Quat value)
{
    BaseMotionTrack *track = getTrack(trackId);
    if(track == NULL)
	{
		Piavca::Error(_PSTR("setQuatKeyframe called on a Null track"));
		return;
	}
    track->setQuatKeyframe(time, value);
};
void StandardMotionImp::setQuatKeyframe(int trackId, float time, Quat value, Quat velocity)
{
    BaseMotionTrack *track = getTrack(trackId);
    if(track == NULL)
	{
		Piavca::Error(_PSTR("setQuatKeyframe called on a Null track"));
		return;
	}
	tracks[trackId]->setQuatKeyframe(time, value, velocity);
}; 


int StandardMotionImp::getNumKeyframes(int trackId)
{
	BaseMotionTrack *track = getTrack(trackId);
    if(track == NULL)
	{
		Piavca::Error(_PSTR("getNumKeyframes called on a Null track"));
		return 0;
	}
	return track->getNumKeyframes();	
};

float StandardMotionImp::getKeyframeTime(int trackId, int keyframe)
{
	BaseMotionTrack *track = getTrack(trackId);
    if(track == NULL)
	{
		Piavca::Error(_PSTR("getKeyframeTime called on a Null track"));
		return 0.0;
	}
	return track->getTime(keyframe);
};
	
float StandardMotionImp::getFloatValueAtTimeInternal(int trackId, float time)  
{
    BaseMotionTrack *track = getTrack(trackId);
    if(track == NULL)
	{
		Piavca::Error(_PSTR("getFloatValueAtTimeInternal called on a Null track"));
		return 0.0;
	}
	return track->getFloatValAtTime(time);
};
Vec StandardMotionImp::getVecValueAtTimeInternal(int trackId, float time)  
{
    BaseMotionTrack *track = getTrack(trackId);
    if(track == NULL)
	{
		Piavca::Error(_PSTR("getVecValueAtTimeInternal called on a Null track"));
		return Vec();
	}
	return track->getVecValAtTime(time);
};
Quat StandardMotionImp::getQuatValueAtTimeInternal(int trackId, float time) 
{
	BaseMotionTrack *track = getTrack(trackId);
    if(track == NULL)
	{
		Piavca::Error(_PSTR("getQuatValueAtTimeInternal called on a Null track"));
		return Quat();
	}
	return track->getQuatValAtTime(time);
};


void StandardMotionImp::deleteAllTracks()
{
	for (std::vector< BaseMotionTrack * >::size_type i = 0; i < tracks.size(); i++)
	{
		delete tracks[i];
		tracks[i] = NULL;
	}
	for (std::vector< BaseMotionTrack * >::size_type i = 0; i < facial_tracks.size(); i++)
	{
		delete facial_tracks[i];
		facial_tracks[i] = NULL;
	}
};
void StandardMotionImp::clearTrack(int trackId, bool createFirstFrame)
{
	BaseMotionTrack *track = getTrack(trackId);
    if(track == NULL)
	{
		Piavca::Error(_PSTR("clearTrack called on a Null track"));
		return;
	}
	if(track)
		track->clear(createFirstFrame);
}

void StandardMotionImp::clearAllTracks(bool createFirstFrame)
{
	for (std::vector< BaseMotionTrack * >::size_type i = 0; i < tracks.size(); i++)
	{
		if(tracks[i])
			tracks[i]->clear(createFirstFrame);
	}
	for (std::vector< BaseMotionTrack * >::size_type i = 0; i < facial_tracks.size(); i++)
	{
		if(facial_tracks[i])
			facial_tracks[i]->clear(createFirstFrame);
	}
};
