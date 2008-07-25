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
 * The Original Code is PointAt.cpp.
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
#include "PiavcaAPI/Avatar.h"


#include "PointAt.h"

#include <algorithm>

using namespace Piavca;


void PointAt::setMotion(Motion *mot)
{
	if (mot == NULL)
	{
		if (!currentValueTarget)
			MotionFilter::setMotion(mot);
	}
	else
	{
		MotionFilter::setMotion(mot);
		if (currentValueTarget)
		{
			currentValueTarget = NULL;
		}
	}
};

Motion *PointAt::getMotion()
{
	if (currentValueTarget)
	{
		return NULL;
	}
	else
	{
		return MotionFilter::getMotion();
	}
};

void PointAt::setTarget(const Vec &target)
{
	if (!currentValueTarget)
	{
		//targetMotion->Dispose();
		currentValueTarget = new CurrentValueMotion();
		currentValueTarget->Reference();
		MotionFilter::setMotion(currentValueTarget);
		targetJointId = 0;
	}
	currentValueTarget->setVecValue(targetJointId, target);
};

Vec PointAt::getTarget()
{
	if (currentValueTarget)
	{
		return currentValueTarget->getVecValueAtTime(targetJointId, 0.0);
	}
	else
		return Vec();
};
/*
void PointAt::setTargetMotion(Motion *target)
{
	currentValueTarget = NULL;
	targetMotion->Dispose();
	targetMotion = target;
}

Motion *PointAt::getTargetMotion()
{
	if (currentValueTarget)
		return NULL;
	else
		return targetMotion;
};
*/
//! get the value of a track at a given time (only works for floats)
float PointAt::getFloatValueAtTimeInternal(int trackId, float time)
{	
	Piavca::Error(_T("Trying to get a Float value from a Quat track"));
	return 0.0;
};


Vec PointAt::getVecValueAtTimeInternal(int trackId, float time)
{
	Piavca::Error(_T("Trying to get a Vec value from a Quat track"));
	return Vec();
}

Quat PointAt::getQuatValueAtTimeInternal(int trackId, float time)
{
	
	if(!m_avatar) return Quat();

	//std::cout << "body active " << bodyActive << std::endl;

	Quat finalOri;
	
	if (filterMot == NULL)
		return Quat();

	if (targetJointId == Piavca::Core::nullId)
		return Quat();

	Vec subjectVec = filterMot->getVecValueAtTime(targetJointId, time);
	
	Vec localPos = subjectVec;
	//std::cout << "pos " << localPos << std::endl;
		
	if(!local)
	{
		localPos = localPos/m_avatar->getScale();
		localPos -= m_avatar->getRootPosition();
		m_avatar->getRootOrientation().inverse().transformInPlace(localPos);
		// express relative to the joint we are turning
		int pointtojoint = trackId;
		
		Vec jointPos = m_avatar->getJointBasePosition(pointtojoint);
		int parentId = m_avatar->getParent(pointtojoint);
		Vec parentPos;
		if(parentId != Piavca::Core::getCore()->nullId)
			parentPos = m_avatar->getJointBasePosition(parentId);
		Quat parentOri;
		if(parentId != Piavca::Core::getCore()->nullId)
			parentOri = m_avatar->getJointOrientation(parentId, LOCAL_COORD);
		Quat parentOriUntransed;
		if(parentId != Piavca::Core::getCore()->nullId)
			parentOriUntransed = m_avatar->getJointOrientation(parentId);
		
		jointPos -= parentPos;
		parentOri.inverse().transformInPlace(jointPos);
		
		localPos -= parentPos;
		parentOri.inverse().transformInPlace(localPos);
		localPos -= jointPos;

	}
	
	localPos += offset;
		
	finalOri.pointAt(forwardDirection, localPos);
	return finalOri;
	
};
