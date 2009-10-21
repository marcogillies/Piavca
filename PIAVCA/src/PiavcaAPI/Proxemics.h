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
 * The Original Code is Proxemics.h.
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


#ifndef PROXEMICS_H
#define PROXEMICS_H

#include "ChoiceMotion.h"
#include "CurrentValueMotion.h"
#include "PiavcaDefs.h"

namespace Piavca
{

//! A ChoiceMotion that implements proxemics behaviour.
/*!
 *	Proxemics consists in maintianing a desired personal distance
 *  to another avatar (or group of avatars) by stepping forwards or
 *  backwards. It also consists in turning to face the other avatar.
 */
class Proxemics : public ChoiceMotion
{
	//enum {Step_forward, Step_backward, Rest, Turn_left, Turn_right};
protected:
	tstring Step_forward_name, Step_backward_name, Rest_name, Turn_left_name, Turn_right_name, Target_name;
	int Step_forward, Step_backward, Rest, Turn_left, Turn_right, Target;
	//vector<Avatar *> otherAvatars;
	float desiredDistance, threshold, anglethreshold;
	Vec targetPos;
	bool distanceOff;

	
	CurrentValueMotion *currentValueTarget;
	Motion *targetMot;
	int targetJointId;
	Vec forwardDirection;//, upDirection;

public:
	/*! 
	 *	You have to pass in 5 motions: as stepForward and back,
	 *  a turn left and right and a rest motion which should be zero keyframes
	 *  and is used to blend with the turning motions to get the exact angle
	 *  of turn you want.
	 *  You also pass in a desired distance to the other avatar,
	 *  a time at which to stop and a blend interval.
	 */
	Proxemics(float distance = 1.0f)
		:ChoiceMotion(), targetMot(NULL), currentValueTarget(NULL), 
		targetJointId(root_position_id), forwardDirection(0.0, 1.0, 0.0), //upDirection(0.0, 0.0, 1.0),
		desiredDistance(distance), threshold(0.2f), anglethreshold(Piavca::Pi/8.0f), distanceOff(false)
	{
	};
	Proxemics(const Proxemics &rl)
		:ChoiceMotion(rl), 
		desiredDistance(rl.desiredDistance), targetMot(rl.targetMot), currentValueTarget(NULL), 
		targetJointId(rl.targetJointId), forwardDirection(rl.forwardDirection), //upDirection(rl.upDirection),
		threshold(rl.threshold), anglethreshold(rl.anglethreshold),  distanceOff(rl.distanceOff),
		Step_forward_name(rl.Step_forward_name), Step_backward_name(rl.Step_backward_name), Rest_name(rl.Rest_name), 
		Turn_left_name(rl.Turn_left_name), Turn_right_name(rl.Turn_right_name), Target_name(rl.Target_name)
		{
			if (rl.currentValueTarget)
			{
				setTarget(rl.currentValueTarget->getVecValueAtTime(0, 0.0));
			}
			refreshMotions();		
		};
	~Proxemics(){};
	
	virtual Motion *clone(){return new Proxemics(*this);};

	//! returns the name of the type
	Piavca::tstring getClassName(){return "Proxemics";};

	//! casts a motion to this type
	static Proxemics *castToThisType(Motion *m){return dynamic_cast<Proxemics *>(m);};
	
	//! called when the motion is loaded into an avatar
	virtual void load(Avatar *av)
	{
		ChoiceMotion::load(av);
		reset();
	};

	//! adds a new child motion
	virtual void addMotion(Motion *mot);
	
	//! removes the ith child motion
	void removeMotionByIndex(int index);

	//! sets the desired distance to another avatar
	void setDistance (float d){desiredDistance = d;};
	float getDistance (){return desiredDistance;};
	//! sets the threshold, the allowable error in distance before moving
	void setThreshold(float t){threshold = t;};
	float getThreshold (){return threshold;};
	//! sets the threshold, the allowable error in distance before moving
	void setAngleThreshold(float a){anglethreshold = a;};
	float getAngleThreshold (){return anglethreshold;};
	//! turns off maintaining distance
	void setDistanceOff(bool b){distanceOff = b;};
	bool getDistanceOff(){return distanceOff;};

	//! the direction vector which is used as forward
	void setForwardDirection(const Vec &v)
	{
		forwardDirection = v;
	};


	Vec getForwardDirection()
	{
		return forwardDirection;
	}
		
	//void setUpDirection(const Vec &v)
	//{
	//	upDirection = v;
	//	ChoiceMotion::setUpDirection(v);
	//};


	//Vec getUpDirection()
	//{
	//	return upDirection;
	//}

	//! the names of all the specific motions
	//!@{
	void setForwardMotionName(tstring name)
	{
		Step_forward_name = name;
		Step_forward = getMotionIndex(name);
	}
	tstring getForwardMotionName()
	{
		return Step_forward_name;
	}
	void setBackwardMotionName(tstring name)
	{
		Step_backward_name = name;
		Step_backward = getMotionIndex(name);
	}
	tstring getBackwardMotionName()
	{
		return Step_backward_name;
	}
	void setLeftMotionName(tstring name)
	{
		Turn_left_name = name;
		Turn_left = getMotionIndex(name);
	}
	tstring getLeftMotionName()
	{
		return Turn_left_name;
	}
	void setRightMotionName(tstring name)
	{
		Turn_right_name = name;
		Turn_right = getMotionIndex(name);
	}
	tstring getRightMotionName()
	{
		return Turn_right_name;
	}
	void setRestMotionName(tstring name)
	{
		Rest_name = name;
		Rest = getMotionIndex(name);
	}
	tstring getRestMotionName()
	{
		return Rest_name;
	}
	void setTargetMotionName(tstring name)
	{
		Target_name = name;
		Target = getMotionIndex(name);
		std::cout << "proxemics: setting target motion name" << Target_name << " " << Target << std::endl;
		setTargetId(Target);
	}
	tstring getTargetMotionName()
	{
		return Target_name;
	}
	//!@}
	
	//! a generic function for setting parameters
	virtual bool setParameter(tstring paramName, tstring value);

	//! sets the position of the other person (if its not accessed as an avatar pointer)
	void setTarget(const Vec &target);
	Vec getTarget();
	void setTargetId(int targetId);

	void refreshMotions();

	virtual int makeChoice();

};

};

#endif //PROXEMICS_H
