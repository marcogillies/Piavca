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
class ProxemicsLoop : public RandomTimingsLoop
{
	Proxemics *proxemics;
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
		:RandomTimingsLoop(NULL, endTime, interval)
	{
		proxemics = new Proxemics(stepForward, stepBackward, rest, turnLeft, turnRight, distance);
		setMotion(proxemics);
	};
	ProxemicsLoop(const ProxemicsLoop &rl)
		:RandomTimingsLoop(rl)
	{
		proxemics = dynamic_cast<Proxemics *>(getMotion());
	};
	~ProxemicsLoop(){};
	
	virtual Motion *clone(){return new ProxemicsLoop(*this);};

	//! returns the name of the type
	Piavca::tstring getClassName(){return "ProxemicsLoop";};

	//! casts a motion to this type
	static ProxemicsLoop *castToThisType(Motion *m){return dynamic_cast<ProxemicsLoop *>(m);};

	//! sets the desired distance to another avatar
	void setDistance (float d){proxemics->setDistance(d);};
	//! sets the threshold, the allowable error in distance before moving
	void setThreshold(float t){proxemics->setThreshold(t);};
	//! sets the threshold, the allowable error in distance before moving
	void setAngleThreshold(float a){proxemics->setAngleThreshold(a);};
	//! turns off maintaining distance
	void turnOff(bool b){proxemics->turnOff(b);};

	//! sets the position of the other person (if its not accessed as an avatar pointer)
	void setOtherPosition(const Vec &v)
	{
		proxemics->setOtherPosition(v);
	}
	
	//! adds an avatar to perform proxemics behaviour to
	void addAvatar(Avatar *av)
	{
		proxemics->addAvatar(av);
	};
	//! removes an avatar
	void removeAvatar (tstring name)
	{
		proxemics->removeAvatar(name);
	};

	//! removes all avatar
	void removeAllAvatars(){proxemics->removeAllAvatars();};

};

};

#endif //PROXEMICS_LOOP_H
