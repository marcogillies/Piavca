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
 * The Original Code is ProxemicsLoop.h.
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


#ifndef PROXEMICS_LOOP_H
#define PROXEMICS_LOOP_H

#include "ChoiceLoopMotion.h"

namespace Piavca
{

//! a MultiMotionLoop that implements proxemics behaviour.
/*!
 *	Proxemics consists in maintianing a desired personal distance
 *  to another avatar (or group of avatars) by stepping forwards or
 *  backwards. It also consists in turning to face the other avatar.
 */
class ProxemicsLoop : public MultiMotionLoop
{
	enum {Step_forward, Step_backward, Rest, Turn_left, Turn_right};
protected:
	vector<Avatar *> otherAvatars;
	float desiredDistance, threshold, anglethreshold;
	bool distanceOff;
public:
	/*! 
	 *	You have to pass in 5 motions: as stepForward and back,
	 *  a turn left and right and a rest motion which should be zero keyframes
	 *  and is used to blend with the turning motions to get the exact angle
	 *  of turn you want.
	 *  You also pass in a desired distance to the other avatar,
	 *  a time at which to stop and a blend interval.
	 */
	ProxemicsLoop(Motion *stepForward=NULL, Motion *stepBackward=NULL,
		Motion *rest=NULL, Motion *turnLeft=NULL, Motion *turnRight=NULL,
		float distance = 1.0f, float endTime = -1.0f, float interval = 0.01f)
		:MultiMotionLoop(vector<Motion *>(), endTime, interval), 
		desiredDistance(distance), threshold(0.2f), anglethreshold(Piavca::Pi/8.0f), distanceOff(false)
	{
		if(!stepForward)
			stepForward = Piavca::Core::getCore()->getMotion("stepForward");
		if(!stepForward) Piavca::Warning(_T("Proxemics: No step forward motion"));
		addMotion(stepForward);
		if(!stepBackward)
			stepBackward = Piavca::Core::getCore()->getMotion("stepBackward");
		if(!stepBackward) Piavca::Warning(_T("Proxemics: No step backward motion"));
		addMotion(stepBackward);
		if(!rest)
			rest = Piavca::Core::getCore()->getMotion("rest");
		if(!rest) Piavca::Warning(_T("Proxemics: No rest motion"));
		addMotion(rest);
		if(!turnLeft)
			turnLeft = Piavca::Core::getCore()->getMotion("turnLeft");
		if(!turnLeft) Piavca::Warning(_T("Proxemics: No turn left motion"));
		addMotion(turnLeft);
		if(!turnRight)
			turnRight = Piavca::Core::getCore()->getMotion("turnRight");
		if(!turnRight) Piavca::Warning(_T("Proxemics: No turn right motion"));
		addMotion(turnRight);
		
		if(mots[Rest])setMotion(mots[Rest]);
	};
	ProxemicsLoop(const ProxemicsLoop &rl)
		:MultiMotionLoop(rl), 
		desiredDistance(rl.desiredDistance), 
		threshold(rl.threshold), anglethreshold(rl.anglethreshold),  distanceOff(rl.distanceOff),
		otherAvatars(rl.otherAvatars) {};
	~ProxemicsLoop(){};
	virtual Motion *clone(){return new ProxemicsLoop(*this);};

	//! sets the desired distance to another avatar
	void setDistance (float d){desiredDistance = d;};
	//! sets the threshold, the allowable error in distance before moving
	void setThreshold(float t){threshold = t;};
	//! sets the threshold, the allowable error in distance before moving
	void setAngleThreshold(float a){anglethreshold = a;};
	//! turns off maintaining distance
	void turnOff(bool b){distanceOff = b;};

	//! adds an avatar to perform proxemics behaviour to
	void addAvatar(Avatar *av)
	{
		otherAvatars.push_back(av);
	};
	//! removes an avatar
	void removeAvatar (tstring name)
	{
		for(vector<Avatar *>::iterator i = otherAvatars.begin();
			i != otherAvatars.end(); i++)
			if((*i)->getName() == name)
				otherAvatars.erase(i);
	};

	//! removes all avatar
	void removeAllAvatars(){otherAvatars.clear();};

	//! called each time through the loop
	virtual void reblend(float time)
	{
		
		if(distanceOff) return;
		// work out the average position of the other characters
		Vec averagePos;
		float number = 0.0f;
		int headJoint = Piavca::Core::getCore()->getJointId(_T("Head"));
		for(std::vector<Avatar *>::iterator i = otherAvatars.begin(); 
			i != otherAvatars.end();
			i++)
		{	
			//std::cout << (*i)->getName() << std::endl;
			Vec avatarPos = (*i)->getJointBasePosition(headJoint, WORLD_COORD);
			
			//std::cout << "Proxemics: avatar head pos " << avatarPos << std::endl;
			  
                      	//(*i)->getRootOrientation().transformInPlace(avatarPos);
			//avatarPos += (*i)->getRootPosition();
			//std::cout << "Proxemics: avatar pos " << avatarPos << std::endl;
			averagePos += avatarPos;
			number += 1.0;
		};
		// if there are no other characters
		if(number < 0.01)
			return;
		averagePos /= number;

		// subtract your own position and work out distance
		Vec displacement = averagePos - m_avatar->getRootPosition();
		displacement[1] = 0.0; // we aren't interested in up an down distance
		float distance = fabs(displacement.mag());
		Vec direction = displacement.normalized();
		
		// if we have a turning motion then we try to turn to face the
		// average position
		if(mots[Turn_left])
		{
			// get the direction you are pointing to
			Vec forward = m_avatar->getForwardDirection();
			m_avatar->getRootOrientation().transformInPlace(forward);
			forward[1] = 0.0; // we aren't intereseted in up down distance
			forward.normalize();

			Vec left = Piavca::Quat(Piavca::Pi/2.0f, Vec::YAxis()).transform(forward);
			float dot = forward.dot(direction);
			float angle = acos(dot);
			float angleSign = left.dot(direction);
			if(fabs(angle) > anglethreshold)
			{
				Core::getCore()->log() << Core::getCore()->getTime();
				Core::getCore()->log() << " proxemics_turn_towards\n";
				Piavca::Motion *m = angleSign > 0.0 ? mots[Turn_left] : mots[Turn_right];
				std::cout << "angle" << angle << std::endl;
				float blendfactor = angle/(Piavca::Pi/2.0f);
				if(blendfactor > 1.0f) blendfactor = 1.0f;
				Piavca::BlendBetween *bb = new Piavca::BlendBetween(mots[Rest], m, blendfactor);
				MultiMotionLoop::reblend(time);
				setMotion(bb);
				return;
			}
		}
	

		// if we haven't turned we can try moving forward or back
		// figure out how far away you want to be from the
		// other characters

		// if you are too far or too near step forward or back
		if((distance - desiredDistance) > threshold)
		{
			Core::getCore()->log() << Core::getCore()->getTime();
			Core::getCore()->log() << " proxemics_step_forward\n";
			MultiMotionLoop::reblend(time);
			setMotion(mots[Step_forward]);
		}		
		if((distance - desiredDistance) < -threshold)
		{
			Core::getCore()->log() << Core::getCore()->getTime();
			Core::getCore()->log() << " proxemics_step_back\n";
			MultiMotionLoop::reblend(time);
			setMotion(mots[Step_backward]);
		}
	};
};

};

#endif //PROXEMICS_LOOP_H
