/* LICENCE BLOCK
MotionrCal3DImp.cpp
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

#include "MotionCal3dImp.h"
#include "Cal3dMathsConversion.h"
#include "PiavcaAPI/PiavcaCore.h"


using namespace Piavca;

MotionCal3DImp::MotionCal3DImp(tstring motionFilename, CalCoreSkeleton *skel)
	:cal3DSkel(skel)
{
	// load the animation from file
	cal3DAnim = CalLoader::loadCoreAnimation(motionFilename);
	if(!cal3DAnim)
		Piavca::Error(_T("Error loading animation file ") + motionFilename);

	// check that the skeleton is valid
	if(!skel)
		Piavca::Error(_T("Invalid skeleton passed to MotionCal3DImp constructor, maybe the animation is being loaded before the skeleton file"));

	// set up all the equivalences between Piavca joint Ids and Cal3D Bone ids
	tracksMap.assign(Piavca::Core::getCore()->getMaxJointId()+1, -1);
	//std::vector<CalCoreBone *> &calbonevec = skel->getVectorCoreBone();
	std::vector< std::pair< tstring, int > > jointAssociations = Piavca::Core::getCore()->getJointNameAssociations();
	for(int i = 0; i < jointAssociations.size(); i++)
	{
		int boneId = skel->getCoreBoneId(TStringToString(jointAssociations[i].first));
		if(boneId >= 0)
		{
			//std::cout << "found track " << jointAssociations[i].first << std::endl;
			tracksMap[jointAssociations[i].second] = boneId;
		}
	}
}

MotionCal3DImp::~MotionCal3DImp()
{
	//Sdelete cal3DAnim;
}

MotionCal3DImp::MotionCal3DImp(const MotionCal3DImp &mot)
	:cal3DAnim(mot.cal3DAnim), tracksMap(mot.tracksMap) {};

const MotionCal3DImp &MotionCal3DImp::operator=(const MotionCal3DImp &mot)
{
	cal3DAnim = mot.cal3DAnim;
	tracksMap = mot.tracksMap;
	return *this;
};

MotionImp *MotionCal3DImp::clone() {return new MotionCal3DImp(*this);};

float MotionCal3DImp::getMotionLength() const
{
	return cal3DAnim->getDuration();
};

float MotionCal3DImp::getFloatValueAtTimeInternal(int trackId, float time)
{
	Piavca::Error("attempted to call a float method on a quaternion only Cal3D animation\n");
	return 0.0;
}

Vec MotionCal3DImp::getVecValueAtTimeInternal(int trackId, float time) 
{
	if(trackId != root_position_id)
	{
		Piavca::Error("attempted to call a Vec method on a non-root track of a Cal3D animation\n");
		return Vec();
	}
	else if (isNull(trackId))
	{
		Piavca::Error("Called getVecValueAtTime on an invalid track id");
		return Vec();
	}
	else
	{
		if(time > getMotionLength()) time = getMotionLength();
		CalCoreTrack *track = cal3DAnim->getCoreTrack(tracksMap[trackId]);
		CalVector translation;
		CalQuaternion rotation;
		track->getState(time, translation, rotation);
		CalCoreBone *bone = cal3DSkel->getCoreBone(tracksMap[trackId]);
		Vec baseTrans = CalVecToVec(bone->getTranslation());
		return CalVecToVec(translation);// - baseTrans;
	}
}

Quat MotionCal3DImp::getQuatValueAtTimeInternal(int trackId, float time)
{
	if(trackId == root_position_id)
	{
		Piavca::Error("attempted to call a Quat method on root position track of a Cal3D animation\n");
		return Quat();
	}
	else if (isNull(trackId))
	{
		Piavca::Error("Called getQuatValueAtTimeInternal on an invalid track id");
		return Quat();
	}
	else
	{	
		std::cout << "MotionCal3DImp " << time << " " << getMotionLength() << std::endl;
		if(time > getMotionLength()) time = getMotionLength();
		CalCoreTrack *track = cal3DAnim->getCoreTrack(tracksMap[trackId]);
		CalVector translation;
		CalQuaternion rotation;
		track->getState(time, translation, rotation);
		if(trackId == root_orientation_id) return CalQuatToQuat(rotation);
		CalCoreBone *bone = cal3DSkel->getCoreBone(tracksMap[trackId]);
		Quat baseRot = CalQuatToQuat(bone->getRotation());
		return CalQuatToQuat(rotation)*baseRot.inverse();
	}
}

int MotionCal3DImp::getNumKeyframes(int trackId)
{
	CalCoreTrack *track = cal3DAnim->getCoreTrack(tracksMap[trackId]);
	return track->getCoreKeyframeCount();
};

float MotionCal3DImp::getKeyframeTime(int trackId, int keyframe)
{
	CalCoreTrack *track = cal3DAnim->getCoreTrack(tracksMap[trackId]);
	return track->getCoreKeyframe(keyframe)->getTime();
};


void MotionCal3DImp::addFloatTrack(int trackId, float initialValue)
{
	Piavca::Error(_T("Trying to write to a read-only Cal3D motion"));	
};
void MotionCal3DImp::addVecTrack(int trackId, const Vec &initialValue)
{
	Piavca::Error(_T("Trying to write to a read-only Cal3D motion"));	
};
void MotionCal3DImp::addQuatTrack(int trackId, const Quat &initialValue)
{
	Piavca::Error(_T("Trying to write to a read-only Cal3D motion"));	
};

void MotionCal3DImp::setFloatKeyframe(int trackId, float time, float value)
{
	Piavca::Error(_T("Trying to write to a read-only Cal3D motion"));	
};
void MotionCal3DImp::setFloatKeyframe(int trackId, float time, float value, float velocity)
{
	Piavca::Error(_T("Trying to write to a read-only Cal3D motion"));	
};

void MotionCal3DImp::setVecKeyframe(int trackId, float time, Vec value)
{
	Piavca::Error(_T("Trying to write to a read-only Cal3D motion"));	
};
void MotionCal3DImp::setVecKeyframe(int trackId, float time, Vec value, Vec velocity)
{
	Piavca::Error(_T("Trying to write to a read-only Cal3D motion"));	
};

void MotionCal3DImp::setQuatKeyframe(int trackId, float time, Quat value)
{
	Piavca::Error(_T("Trying to write to a read-only Cal3D motion"));	
};
void MotionCal3DImp::setQuatKeyframe(int trackId, float time, Quat value, Quat velocity)
{
	Piavca::Error(_T("Trying to write to a read-only Cal3D motion"));	
};

void MotionCal3DImp::deleteAllTracks()
{
	Piavca::Error(_T("Trying to write to a read-only Cal3D motion"));	
};
void MotionCal3DImp::clearTrack(int trackId, bool createFirstFrame)
{
	Piavca::Error(_T("Trying to write to a read-only Cal3D motion"));	
};
void MotionCal3DImp::clearAllTracks(bool createFirstFrame )
{
	Piavca::Error(_T("Trying to write to a read-only Cal3D motion"));	
};
