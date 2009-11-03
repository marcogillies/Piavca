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
 * The Original Code is Proxemics.cpp.
 *
 * The Initial Developer of the Original Code is Marco (Mark) Gillies.
 * Portions created by the Initial Developer are Copyright (C) 2008
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

#include "Proxemics.h"
#include "PiavcaCore.h"
#include "Avatar.h"
#include "BlendBetween.h"
#include "TypeConvert.h"

using namespace Piavca;



//! a generic function for setting parameters
bool Proxemics::setParameter(tstring paramName, tstring value)
{
	if(paramName == _T("Distance") || paramName == _T("distance"))
	{
		setDistance(convert<float>(value));
		return true;
	}
	if(paramName == _T("Threshold") || paramName == _T("threshold"))
	{
		setThreshold(convert<float>(value));
		return true;
	}
	if(paramName == _T("AngleThreshold") || paramName == _T("angleThreshold") || paramName == _T("anglethreshold"))
	{
		setAngleThreshold(convert<float>(value));
		return true;
	}
	if(paramName == _T("DistanceOff") || paramName == _T("distanceOff") || paramName == _T("distanceoff"))
	{
		setDistanceOff(convert<bool>(value));
		return true;
	}
	if(paramName == _T("ForwardDirection") || paramName == _T("forwardDirection") || paramName == _T("forwarddirection"))
	{
		setForwardDirection(convert<Vec>(value));
		return true;
	}
	if(paramName == _T("Target") || paramName == _T("target"))
	{
		setTarget(convert<Vec>(value));
		return true;
	}
	if(paramName == _T("ForwardMotionName") || paramName == _T("forwardMotionName") || paramName == _T("forwardmotionname"))
	{
		setForwardMotionName(value);
		return true;
	}
	if(paramName == _T("BackwardMotionName") || paramName == _T("backwardMotionName") || paramName == _T("backwardmotionname"))
	{
		setBackwardMotionName(value);
		return true;
	}
	if(paramName == _T("LeftMotionName") || paramName == _T("leftMotionName") || paramName == _T("leftmotionname"))
	{
		setLeftMotionName(value);
		return true;
	}
	if(paramName == _T("RightMotionName") || paramName == _T("rightMotionName") || paramName == _T("rightmotionname"))
	{
		setRightMotionName(value);
		return true;
	}
	if(paramName == _T("RestMotionName") || paramName == _T("restMotionName") || paramName == _T("restmotionname"))
	{
		setRestMotionName(value);
		return true;
	}
	if(paramName == _T("TargetMotionName") || paramName == _T("targettMotionName") || paramName == _T("targetmotionname"))
	{
		setTargetMotionName(value);
		return true;
	}
	return ChoiceMotion::setParameter(paramName, value);
}

void Proxemics::addMotion(Motion *mot)
{
	std::cout << "proxemics: add motion\n";
	ChoiceMotion::addMotion(mot);
	refreshMotions();
}


void Proxemics::removeMotionByIndex(int index)
{
	ChoiceMotion::removeMotionByIndex(index);
	refreshMotions();
}

void Proxemics::setTarget(const Vec &target)
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

Vec Proxemics::getTarget()
{
	if (currentValueTarget)
	{
		return currentValueTarget->getVecValueAtTime(targetJointId, 0.0);
	}
	else
		return Vec();
};

void Proxemics::refreshMotions()
{
	std::cout << "proxemics: efresh motions\n";
	Step_forward = getMotionIndex(Step_forward_name);
	Step_backward = getMotionIndex(Step_backward_name);
	Turn_left = getMotionIndex(Turn_left_name);
	Turn_right = getMotionIndex(Turn_right_name);
	Rest = getMotionIndex(Rest_name);
	Target = getMotionIndex(Target_name);
	setTargetId(Target);
}

void Proxemics::setTargetId(int targetId)
{

	std::cout << "proxemics: setting target id " << targetId << std::endl;

	Motion *mot = NULL;
	if (targetId >= 0)
		mot = getMotion(targetId);
	if (mot == NULL)
	{
		std::cout << "proxemics: null motion \n";
		if (!currentValueTarget)
			targetMot = mot;
	}
	else
	{
		std::cout << "proxemics: found motion \n";
		targetMot = mot;
		if (currentValueTarget)
		{
			Motion::Dispose(currentValueTarget);//->Dispose();
			currentValueTarget = NULL;
		}
	}
}

int Proxemics::makeChoice(bool restart)
{
		//std:: cout << "Proxemics makeChoice" << std::endl;
		if(restart)
		{
			return Rest;
		}
		if(distanceOff) 
		{
			std::cout << "proxemics: distance off\n";
			return Rest;
		}
		if(!m_avatar) 
		{
			std::cout << "proxemics: no avatar\n";
			return Rest;
		}
		if (targetMot == NULL)
		{
			std::cout << "proxemics: no target\n";
			return Rest;
		}
		//std:: cout << "Proxemics makeChoice, we're in" << std::endl;
		// work out the average position of the other characters
		
		Vec targetPos = targetMot->getVecValueAtTime(targetJointId, Piavca::Core::getCore()->getTime());
		
		std::cout << "Proxemics: target pos: " << targetPos << std::endl;

		targetPos = targetPos/m_avatar->getScale();
		// subtract your own position and work out distance
		Vec displacement = targetPos - m_avatar->getRootPosition();
		
		std::cout << "Proxemics: displacement: " << displacement << std::endl;
		
		// get rid of the component in the up direction
		//displacement[1] = 0.0; // we aren't interested in up an down distance
		Vec up = getUpDirection();
		m_avatar->getRootOrientation().transformInPlace(up);
		up = up*displacement.dot(up);
		displacement = displacement - up;
		
		std::cout << "Proxemics: displacement: " << displacement << std::endl;
		
		float distance = fabs(displacement.mag());
		Vec direction = displacement.normalized();
		
		std::cout << "Proxemics: distance: " << distance << std::endl;
		std::cout << "Proxemics: direction: " << direction << std::endl;
		
		// if we have a turning motion then we try to turn to face the
		// average position
		if(Turn_left > 0)
		{
			// get the direction you are pointing to
			Vec forward = forwardDirection;//m_avatar->getForwardDirection();
			m_avatar->getRootOrientation().transformInPlace(forward);
			//forward[1] = 0.0; // we aren't intereseted in up down distance
			//forward.normalize();

			Vec left = Piavca::Quat(Piavca::Pi/2.0f, getUpDirection()).transform(forward);
			std::cout << "Proxemics: left: " << left << std::endl;
			float dot = forward.dot(direction);
			float angle = acos(dot);
			float angleSign = left.dot(direction);
			std::cout << "Proxemics: forward: " << forward << std::endl;
			std::cout << "Proxemics: angle: " << angle << std::endl;
			if(fabs(angle) > anglethreshold)
			{
				std::cout << "proxemics: turn\n";
				//Core::getCore()->log() << Core::getCore()->getTime();
				//Core::getCore()->log() << " proxemics_turn_towards\n";
				int index = angleSign > 0.0 ? Turn_left : Turn_right;
				Piavca::Motion *m = getMotion(index);
				BlendBetween *bb = dynamic_cast<BlendBetween *>(m);
				if (bb)
				{
					//std::cout << "angle" << angle << std::endl;
					float blendfactor = angle/(Piavca::Pi/2.0f);
					std::cout << "Proxemics: blendfactor: " << blendfactor << std::endl;
					if(blendfactor > 1.0f) blendfactor = 1.0f;
					bb->setBlendFactor(blendfactor);
				}
				//Piavca::BlendBetween *bb = new Piavca::BlendBetween(mots[Rest], m, blendfactor);
				//MultiMotionCombiner::reset();
				//setMotion(bb);
				return index ;
			}
		}
	

		// if we haven't turned we can try moving forward or back
		// figure out how far away you want to be from the
		// other characters

		// if you are too far or too near step forward or back
		if((distance - desiredDistance) > threshold)
		{
			std::cout << "proxemics: step forward\n";
			//Core::getCore()->log() << Core::getCore()->getTime();
			//Core::getCore()->log() << " proxemics_step_forward\n";
			//MultiMotionCombiner::reset();
			return Step_forward;
		}		
		if((distance - desiredDistance) < -threshold)
		{
			std::cout << "proxemics: step back\n";
			//Core::getCore()->log() << Core::getCore()->getTime();
			//Core::getCore()->log() << " proxemics_step_back\n";
			//MultiMotionCombiner::reset();
			return Step_backward;
		}
		return Rest;
};
