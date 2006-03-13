/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
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
 * The Original Code is LookAtMotion.cpp.
 *
 * The Initial Developer of the Original Code is Marco (Mark) Gillies.
 * Portions created by the Initial Developer are Copyright (C) 2005
 * the Initial Developer. All Rights Reserved.
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


#include "PiavcaAPI/PiavcaDefs.h"

#include "LookAtMotion.h"
#include "AvatarMotionQueue.h"

#include <algorithm>

using namespace Piavca;

void LookAtMotion::init()
{
	if(endTime < 0) endTime = std::numeric_limits<float>::max() -10.0;

	reyeId = Core::getCore()->getJointId("right_eye");
	oldReyeVal = Quat();
	leyeId = Core::getCore()->getJointId("left_eye");
	oldLeyeVal = Quat();
	headId = Core::getCore()->getJointId("head");
	oldHeadVal = Quat();
	bodyId = Core::getCore()->getJointId("body");
	oldBodyVal = Quat();
	headActive = false;
	bodyActive = false;
	if(reyeId < 0 && leyeId < 0)
	{
		lookLeftId = Core::getCore()->getExpressionId("look_left");
		if(lookLeftId >= 0) oldLookLeftVal = 0.0;
		lookRightId = Core::getCore()->getExpressionId("look_right");
		if(lookRightId >= 0) oldLookRightVal = 0.0;
		lookUpId = Core::getCore()->getExpressionId("look_up");
		if(lookUpId >= 0) oldLookUpVal = 0.0;
		lookDownId = Core::getCore()->getExpressionId("look_down");
		if(lookDownId >= 0) oldLookDownVal = 0.0;
		if(lookLeftId < 0 && lookUpId < 0
			&& lookRightId < 0 && lookDownId < 0)
			headActive = true;
	}
	
	blendStartTime = Core::getCore()->getTime();
	blendEndTime = Core::getCore()->getTime() + interval;
}

void LookAtMotion::reblend(float time)
{
	//std::cout << "lookat reblend: ";
	if(reyeId >= 0) oldReyeVal = getQuatValueAtTime(reyeId, time);
	if(leyeId >= 0) oldLeyeVal = getQuatValueAtTime(leyeId, time);
	if(headId >= 0) oldHeadVal = getQuatValueAtTime(headId, time);
	if(bodyId >= 0) oldBodyVal = getQuatValueAtTime(bodyId, time);
	
	if(lookLeftId >= 0)  oldLookLeftVal  = getFloatValueAtTime(lookLeftId, time);
	if(lookRightId >= 0) oldLookRightVal = getFloatValueAtTime(lookRightId, time);
	if(lookUpId >= 0)    oldLookUpVal    = getFloatValueAtTime(lookUpId, time);
	if(lookDownId >= 0)  oldLookDownVal  = getFloatValueAtTime(lookDownId, time);

	blendStartTime = time;
	blendEndTime = time + interval;
	//std::cout << "end time " << endTime << "blend start " << blendStartTime << " blend end " << blendEndTime << std::endl;
}

void LookAtMotion::load(Avatar *av)
{
	Motion::load(av);
	// as the lookat motion also animates the face
	// we need to add in a facial version of the motion
	// to the queue when we load it into the avatar.
	LookAtToFacial *facialVer = new LookAtToFacial(this);
	facialVer->setName(getName() +_T("_facial"));

	AvatarMotionQueue *amq = AvatarMotionQueue::getQueue(av, true);
	amq->removeBackgroundMotionByType(typeid(LookAtToFacial));
	amq->addBackgroundMotion(facialVer->getName(), facialVer);
}

bool LookAtMotion::canLookAt(Vec location)
{
		if(!avatar) return true;
		Vec zvec = avatar->getForwardDirection();

		// transfrom into local space of avatar
		Vec localPos = location;
		
		localPos -= avatar->getRootPosition();
		avatar->getRootOrientation().inverse().transformInPlace(localPos);
		
		Quat finalOri;
		finalOri.pointAt(zvec, localPos);

		float angle; Vec axis;
		finalOri.getAngleAxis(angle, axis);
		
		if(fabs(angle) > headbodyLimit)
			return false;
		else 
			return true;
}

//! get the value of a track at a given time (only works for floats)
float LookAtMotion::getFloatValueAtTimeInternal(int trackId, float time)
{	
	if(!(trackId == lookLeftId || trackId == lookRightId
		|| trackId == lookUpId || trackId == lookDownId))
		return 0;
	if(!avatar) return 0;

	Vec subjectVec;
	if(AvatarTarget)
	{
		subjectVec = AvatarTarget->getJointBasePosition(targetJointId, LOCAL_COORD);
		AvatarTarget->getRootOrientation().transformInPlace(subjectVec);
		subjectVec += AvatarTarget->getRootPosition();
	}
	else {if (ObjectTarget)
	{
		subjectVec = ObjectTarget->getPosition();
	}
	else
		subjectVec = LocationTarget;
	}

	Vec zvec = avatar->getForwardDirection();

	// transfrom into local space of avatar
	Vec localPos = subjectVec;
	
	if(AvatarTarget || ObjectTarget || !local)
	{
		localPos -= avatar->getRootPosition();
		avatar->getRootOrientation().inverse().transformInPlace(localPos);
		// express relative to the joint we are turning
		Vec jointPos = avatar->getJointBasePosition(headId);
		Quat jointOri = avatar->getJointOrientation(headId);
		int parentId = avatar->getParent(headId);
		Vec parentPos;
		if(parentId >= 0)
			parentPos = avatar->getJointBasePosition(parentId);
		Quat parentOri;
		if(parentId >= 0)
			parentOri = avatar->getJointOrientation(parentId, LOCAL_COORD);
		Quat parentOriUntransed;
		if(parentId >= 0)
			parentOriUntransed = avatar->getJointOrientation(parentId);
		
		jointPos -= parentPos;
		parentOri.inverse().transformInPlace(jointPos);
		
		localPos -= parentPos;
		parentOri.inverse().transformInPlace(localPos);
		localPos -= jointPos;
		jointOri.inverse().transformInPlace(localPos);
	}
	
	if(trackId == lookLeftId || trackId == lookRightId)
	{
		Vec forward = zvec;
		forward[1] = 0.0; // we aren't intereseted in up down distance
		forward.normalize();
		localPos[1] = 0.0; // we aren't intereseted in up down distance
		localPos.normalize();

		Vec left = Piavca::Quat(Piavca::Pi/2.0, Vec::YAxis()).transform(forward);
		float dot = forward.dot(localPos);
		float angle = acos(dot);
		float angleSign = left.dot(localPos);
		if(trackId == lookLeftId && angleSign > 0.0)
		{
			if(angle > eyesLimit)
			{
				LookAtMotion *nonConstThis = const_cast<LookAtMotion *>(this);
				if(headId >= 0 && !headActive) nonConstThis->headActive = true;
				else if(bodyId >= 0 && !bodyActive) nonConstThis->bodyActive = true;
				angle = eyesLimit;
			}
			float val = angle/eyesMorphAngle;
			if(time > blendEndTime)
				return val;
			else
			{
				float blendTime = (time - blendStartTime)/(blendEndTime - blendStartTime);
				return (1 - blendTime)*oldLookLeftVal + val*blendTime;
			}		
		}
		if(trackId == lookRightId && angleSign < 0.0)
		{
			if(angle > eyesLimit)
			{
				LookAtMotion *nonConstThis = const_cast<LookAtMotion *>(this);
				if(headId >= 0 && !headActive) nonConstThis->headActive = true;
				else if(bodyId >= 0 && !bodyActive) nonConstThis->bodyActive = true;
				angle = eyesLimit;
			}
			float val = angle/eyesMorphAngle;
			if(time > blendEndTime)
				return val;
			else
			{
				float blendTime = (time - blendStartTime)/(blendEndTime - blendStartTime);
				return (1 - blendTime)*oldLookRightVal + val*blendTime;
			}
		}	
	}
	if(trackId == lookUpId || trackId == lookDownId)
	{
		Vec forward = zvec;
		forward[0] = 0.0; // we aren't intereseted in up down distance
		forward.normalize();
		localPos[0] = 0.0; // we aren't intereseted in up down distance
		localPos.normalize();

		Vec up = Piavca::Quat(Piavca::Pi/2.0, Vec::XAxis()).transform(forward);
		float dot = forward.dot(localPos);
		float angle = acos(dot);
		float angleSign = up.dot(localPos);
		if(trackId == lookUpId && angleSign > 0.0)
		{
			if(angle > eyesLimit)
			{
				LookAtMotion *nonConstThis = const_cast<LookAtMotion *>(this);
				if(headId >= 0 && !headActive) nonConstThis->headActive = true;
				else if(bodyId >= 0 && !bodyActive) nonConstThis->bodyActive = true;
				angle = eyesLimit;
			}
			float val = angle/eyesMorphAngle;
			if(time > blendEndTime)
				return val;
			else
			{
				float blendTime = (time - blendStartTime)/(blendEndTime - blendStartTime);
				return (1 - blendTime)*oldLookUpVal + val*blendTime;
			}
		}
		if(trackId == lookDownId && angleSign < 0.0)
		{
			if(angle > eyesLimit)
			{
				LookAtMotion *nonConstThis = const_cast<LookAtMotion *>(this);
				if(headId >= 0 && !headActive) nonConstThis->headActive = true;
				else if(bodyId >= 0 && !bodyActive) nonConstThis->bodyActive = true;
				angle = eyesLimit;
			}
			float val = angle/eyesMorphAngle;
			if(time > blendEndTime)
				return val;
			else
			{
				float blendTime = (time - blendStartTime)/(blendEndTime - blendStartTime);
				return (1 - blendTime)*oldLookDownVal + val*blendTime;
			}
		}	
	}
	return 0.0;
};


Quat LookAtMotion::getQuatValueAtTimeInternal(int trackId, float time)
{
	if(trackId == bodyId) return Quat();

	//std::cout << "Look at Motion\n";
	if(!(trackId == headId || trackId == bodyId 
		|| trackId == reyeId || trackId == leyeId)) return Quat();
	
	if(!avatar) return Quat();

	//std::cout << "body active " << bodyActive << std::endl;

	Quat finalOri;
	if((trackId == headId && !headActive)
		|| (trackId == bodyId && !bodyActive))
	{
		finalOri = Quat();
	}
	else
	{
		
		if(trackId == bodyId ) std::cout << "look at body\n";
		Vec subjectVec;
		if(AvatarTarget)
		{
			subjectVec = AvatarTarget->getJointBasePosition(targetJointId, LOCAL_COORD);
			AvatarTarget->getRootOrientation().transformInPlace(subjectVec);
			subjectVec += AvatarTarget->getRootPosition();
		}
		else {if (ObjectTarget)
		{
			subjectVec = ObjectTarget->getPosition();
		}
		else
			subjectVec = LocationTarget;
		}
	
		if(trackId == headId 
			&& ((subjectVec - oldTargetPos_head).mag() < 0.05
				&& (avatar->getRootPosition() - oldRootPos_head).mag() < 0.05))
		{
				finalOri = oldHeadOri;
		}
		else if (trackId == bodyId
			&& ((subjectVec - oldTargetPos_body).mag() < 0.05
				&& (avatar->getRootPosition() - oldRootPos_body).mag() < 0.05))
		{
				finalOri = oldBodyOri;
		}
		else
		{

			Vec zvec = avatar->getForwardDirection();

			// transfrom into local space of avatar
			Vec localPos = subjectVec;
			
			if(AvatarTarget || ObjectTarget || !local)
			{
				localPos -= avatar->getRootPosition();
				avatar->getRootOrientation().inverse().transformInPlace(localPos);
				// express relative to the joint we are turning
				int pointtojoint = trackId;
				if(trackId == bodyId && headId >= 0)
					pointtojoint = headId;
				Vec jointPos = avatar->getJointBasePosition(pointtojoint);
				int parentId = avatar->getParent(pointtojoint);
				Vec parentPos;
				if(parentId >= 0)
					parentPos = avatar->getJointBasePosition(parentId);
				Quat parentOri;
				if(parentId >= 0)
					parentOri = avatar->getJointOrientation(parentId, LOCAL_COORD);
				Quat parentOriUntransed;
				if(parentId >= 0)
					parentOriUntransed = avatar->getJointOrientation(parentId);
				
				jointPos -= parentPos;
				parentOri.inverse().transformInPlace(jointPos);
				
				localPos -= parentPos;
				parentOri.inverse().transformInPlace(localPos);
				localPos -= jointPos;
			}
			
			//if(trackId == bodyId)// && !turnBodyVertical)
			//{
			//	std::cout << "look at: getting rid of y axis\n" ;
			//	localPos[1] = 0.0;
			//}

			// split the rotation into a vertical (xz) and horizontal(y) rotation
			Quat xzOri, yOri;
			yOri.pointAt(zvec, Vec(localPos[0], 0, localPos[2]));
			if(trackId != bodyId || turnBodyVertical)
			{
				float horixMag = Vec(localPos[0], 0, localPos[2]).mag();
				xzOri.pointAt(zvec, Vec(0, localPos[1], horixMag));
			}

			//finalOri.pointAt(zvec, localPos);

			float limit;
			if(trackId == reyeId || trackId == leyeId)
				limit = eyesLimit;
			else 
				limit = headbodyLimit;

			Quat *ori = &xzOri;
			for(int dummy = 0; dummy < 2; dummy++, ori = &yOri)
			{
				float angle; Vec axis;
				ori->getAngleAxis(angle, axis);
				if(trackId == bodyId && !turnBodyFull)
				{
					angle = angle/2.0;
				}
				if(trackId == bodyId && turnBodyFull)
				{
					angle = angle*1.5;
				}
				if(fabs(angle) > limit)
				{
					if(trackId == headId)
					{
						LookAtMotion *nonConstThis = const_cast<LookAtMotion *>(this);
						if(bodyId >= 0 && !bodyActive)
						{
							nonConstThis->bodyActive = true;
							angle = angle > 0 ? angle - limit : angle+limit;
						}
						if(fabs(angle) > limit)
							angle = angle > 0 ? limit : -limit;
						ori->setAngleAxis(angle, axis);
					}
					else
					{
						LookAtMotion *nonConstThis = const_cast<LookAtMotion *>(this);
						if(headId >= 0 && !headActive) nonConstThis->headActive = true;
						else if(bodyId >= 0 && !bodyActive) nonConstThis->bodyActive = true;
						angle = angle > 0 ? limit : -limit;
						ori->setAngleAxis(angle, axis);
					}
				}
				if(trackId == headId)
					std::cout << "head: ";
				if(trackId == bodyId)
					std::cout << "body: ";
				std::cout << angle << std::endl;
			}
			// combine the two rotation axes
			finalOri = xzOri*yOri;
			
			if(trackId == headId) 
			{
				LookAtMotion *nonConstThis = const_cast<LookAtMotion *>(this);
				nonConstThis->oldHeadOri = finalOri;
				nonConstThis->oldTargetPos_head = subjectVec;
				nonConstThis->oldRootPos_head = avatar->getRootPosition();
			}
			if(trackId == bodyId)
			{
				LookAtMotion *nonConstThis = const_cast<LookAtMotion *>(this);
				nonConstThis->oldBodyOri = finalOri;
				nonConstThis->oldTargetPos_body = subjectVec;
				nonConstThis->oldRootPos_body = avatar->getRootPosition();
			}
		}
		
	}

	
	
	if(time > blendEndTime)
		return finalOri;
	else
	{
		Quat oldOrientation;
		if(trackId == reyeId) oldOrientation = oldReyeVal;
		if(trackId == leyeId) oldOrientation = oldLeyeVal;
		if(trackId == headId) oldOrientation = oldHeadVal;
		if(trackId == bodyId) oldOrientation = oldBodyVal;

		float blendTime = (time - blendStartTime)/(blendEndTime - blendStartTime);
		std::cout << "Lookat motion blending: " << oldOrientation << " "
			<< finalOri << " " << blendTime << std::endl;
		return Piavca::slerp(oldOrientation, finalOri, blendTime);
	}
};