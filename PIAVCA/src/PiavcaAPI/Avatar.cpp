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
 * The Original Code is Avatar.cpp.
 *
 * The Initial Developer of the Original Code is Marco (Mark) Gillies.
 * Portions created by the Initial Developer are Copyright (C) BT plc. 2004
 * All Rights Reserved.
 *
 * ***** END LICENSE BLOCK ***** */

//#ifdef PIAVCA_DLL
//#define PIAVCA_EXPORT __declspec( dllexport ) 
//#else
//#define PIAVCA_EXPORT
//#endif

#include "AvatarImp.h"
#include "TrackMotion.h"

#include "PiavcaCore.h"
#include "Avatar.h"

using namespace Piavca;
	


//! set the current time
/*!
	*	This is used for animation, it sets the time within the current piece of motion 
	*	and puts the avatar in the correct position for that motion at that time
	*/
 void	Avatar::timeStep	(float time) 
{
	//std::cout << " Avatar.cpp timestep BEGINNNNNNNNNNNNNNNNNNN" << std::endl;
	if(!active) return;

	unsigned int i;
	for (i = 0; i < callbacks.size(); i++)
		callbacks[i]->timeStep(this, time);
	//std::cout << " Avatar.cpp first for looppppppppppppppppppp" << std::endl;

	if(motionEnabled)
		showMotionAtTime(time);
	//std::cout << " Avatar.cpp if motion enabled check" << std::endl;

	if(scaleMotionEnabled)
		showScaleMotionAtTime(time);
	//std::cout << " Avatar.cpp if scale motion enabled check" << std::endl;

	if(facialMotionEnabled)
		showFacialMotionAtTime(time);
	//std::cout << " Avatar.cpp if show facial motion enabled check" << std::endl;

	imp->updateFacialExpressions();
	//std::cout << " Avatar.cpp timestep ENDDDDDDDDDDDDDDDDDDDDD" << std::endl;

	//updateFacialExpressions(time);

	platformSpecific_timeStep (time);
};


void Avatar::activate(){active = true;};
void Avatar::deactivate(){active = false;};

void Avatar::validateMotions()
{
	if(mot)
	{
		if(!mot->isNull(root_position_id) 
			&& mot->getTrackType(root_position_id) != VEC_TYPE)
		{
			Piavca::Error(_T("Trying to load a motion with a non-vector root position"));
			unloadMotion();
		}
		if(mot && !mot->isNull(root_orientation_id) 
			&& mot->getTrackType(root_orientation_id) != QUAT_TYPE)
		{
			Piavca::Error(_T("Trying to load a motion with a non-quaternion root orientation"));
			unloadMotion();
		};
		for (int joint = begin(); joint <= Core::getCore()->getMaxJointId(); next(joint))
		{
			if(mot && !mot->isNull(joint)
				&& mot->getTrackType(joint) != QUAT_TYPE)
			{
					Piavca::Error(_T("Trying to load a motion with a non-quaternion track"));
					unloadMotion();
					break;
			}
		}
	}
	if(facialMot)
	{
		for (int expr = beginExpression(); expr <= Core::getCore()->getMaxExpressionId(); nextExpression(expr))
		{
			if(!facialMot->isNull(expr)
				&& facialMot->getTrackType(expr) != FLOAT_TYPE)
			{
				Piavca::Error(_T("Trying to load a facial motion with a non-float track"));
				unloadFacialMotion();
				break;
			}
		}
	}
	if(scaleMot)
	{
		for (int joint = begin(); joint <= Core::getCore()->getMaxJointId(); next(joint))
		{
			if(!scaleMot->isNull(joint)
				&& scaleMot->getTrackType(joint) != FLOAT_TYPE
				&& scaleMot->getTrackType(joint) != VEC_TYPE)
			{
				Piavca::Error(_T("Trying to load a scale motion with a non-float and non-vector track"));
				unloadScaleMotion();
				break;
			}
		}
	}
};

void Avatar::showMotionAtTime	(float time)
{
	//std::cout << " Avatar.cpp showMotionAtTime BEGINNNNNNNNNNNNNNNNNNNNN" << std::endl;
	if(!mot)return;
	//std::cout << " Avatar.cpp showMotionAtTime motion is there" << mot << std::endl;
	time = Core::getCore()->getTime();
	//std::cout << " Avatar.cpp showMotionAtTime time is there " << time << std::endl;
	if(time < 0) return;
	// set the root position and orientation
	//std::cout << " Avatar.cpp showMotionAtTime about to do if-else " << std::endl;
	if(!mot->isNull(root_position_id))
	{
	    //std::cout << " Avatar.cpp showMotionAtTime in if-else " << std::endl;
		setRootPosition(mot->getVecValueAtTime(root_position_id, time));
		//std::cout << "root " << mot->getVecValueAtTime(root_position_id, time) << std::endl;
	}
	//else
	//  std::cout << "could not find root pos track" << std::endl;
	if(!mot->isNull(root_orientation_id))
	{
		setRootOrientation(mot->getQuatValueAtTime(root_orientation_id, time));
		//std::cout << "root " << mot->getQuatValueAtTime(root_orientation_id, time) << std::endl;
	}
	//else
	 //   std::cout << "could not find root pos track" << std::endl;
	
	// go through all the joints setting those for which there is a track
	for (int joint = begin(); joint <= Core::getCore()->getMaxJointId(); next(joint))
	{
		if(!mot->isNull(joint))
		{
			setJointOrientation(joint, mot->getQuatValueAtTime(joint, time));
			//std::cout << mot->getQuatValueAtTime(joint, time) << std::endl;
		}
		//else
		   // std::cout << "could not find track: " << joint << std::endl;
	}
	//std::cout << " Avatar.cpp showMotionAtTime BEGINNNNNNNNNNNNNNNNNNNNN" << std::endl;

};


void Avatar::showScaleMotionAtTime	(float time)
{
	if(!scaleMot)return;
	time = Core::getCore()->getTime();
	if(time < 0) return;
	// set the root position and orientation
	if(!scaleMot->isNull(root_position_id))
	{
		Vec s;
		if(scaleMot->getTrackType(root_position_id) == FLOAT_TYPE)
		{
			float factor = scaleMot->getFloatValueAtTime(root_position_id, time);
			s = Vec(factor, factor, factor);
		}
		else
		{
			s =  scaleMot->getVecValueAtTime(root_position_id, time);
		}
		scaleRoot(s);
	}
	
	// go through all the joints scaling those for which there is a track
	for (int joint = begin(); joint <= Core::getCore()->getMaxJointId(); next(joint))
	{
		if(!scaleMot->isNull(joint))
		{
			Vec s;
			if(scaleMot->getTrackType(joint) == FLOAT_TYPE)
			{
				float factor = scaleMot->getFloatValueAtTime(joint, time);
				s = Vec(factor, factor, factor);
			}
			else
			{
				s =  scaleMot->getVecValueAtTime(joint, time);
			}
			scaleJoint(joint, s);
		}
	}
};


void Avatar::showFacialMotionAtTime	(float time)
{
	if(!facialMot)return;
	time = Core::getCore()->getTime();
	if(time < 0) return;
	
	// go through all the expressions setting those for which there is a track
	for (int expr = beginExpression(); expr <= Core::getCore()->getMaxExpressionId(); nextExpression(expr))
	{
		if(!facialMot->isNull(expr))
		{
			//std::cout << "ShowMotion " << Core::getCore()->getExpressionName(expr) << " " << facialMot->getFloatValueAtTime(expr, time) << std::endl;
			setFacialExpressionWeight(expr, facialMot->getFloatValueAtTime(expr, time));
		}
	}
};


// The core object of the piavca application
//PIAVCA_EXPORT Piavca::Core *Avatar::core = NULL;

void Avatar::playMotion(){playMotion(Core::getCore()->getTime());};
void Avatar::playScaleMotion(){playScaleMotion(Core::getCore()->getTime());};
void Avatar::playFacialMotion(){playFacialMotion(Core::getCore()->getTime());};

// create a UCLAvatarImp from the factory
void Avatar::initAvatar(	
			tstring avatarId, 
			bool bailOnMissedJoints,
			const Vec &Position, 
			const Quat &Orientation)
{
	Core::getCore()->initAvatar(this, avatarId, bailOnMissedJoints, Position, Orientation);
	if(imp)
	  {
	    imp->frontEnd = this;
	    loadMotion(new TrackMotion());
	  }
};

int Avatar::end () const {return Core::getCore()->getMaxJointId()+1;}
int Avatar::endExpression () const {return Core::getCore()->getMaxExpressionId()+1;}

// Given a UCLAvatar object this returns its implementation 
/*
*	This is used by a similar method in the platform specific implementation
*	that is used to get the implementation in platform specific code
*/
AvatarImp *AvatarImp::getAvatarImpInternal(Avatar *avatar){return avatar->imp;};
