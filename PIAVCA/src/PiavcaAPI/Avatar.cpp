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
 *
 * ***** END LICENSE BLOCK ***** */

//#ifdef PIAVCA_DLL
//#define PIAVCA_EXPORT __declspec( dllexport ) 
//#else
//#define PIAVCA_EXPORT
//#endif

#include "AvatarImp.h"
#include "KeyframeMotion.h"
#include "TimeCallback.h"

#include "PiavcaError.h"
#include "PiavcaCore.h"
#include "Avatar.h"
#include "AvatarMotionQueue.h"

using namespace Piavca;
	
Avatar::Avatar(tstring avatarId, 
		   tstring strFilename,
		   bool bailOnMissedJoints,
		   const Vec &Position,
		   const Quat &Orientation
		   //const Vec &forwardDir
		   )
		: name(avatarId), active(true), changed(false), rootChanged (false), 
		beingEdited(false), //forwardDirection(forwardDir), //amq(NULL), 
		mot(NULL), scaleMot(NULL)//, facialMot(NULL)
		//motionOwned(true), facialMotionOwned(true), scaleMotionOwned(true)
{
	std::string::size_type dotpos = 0;
	dotpos = name.find_first_of(".", dotpos);
	if(dotpos != name.npos)
		name = name.substr(0, dotpos);
	initAvatar(avatarId, strFilename, bailOnMissedJoints, Position, Orientation);
	std::cout << "end of avatar constructor" << std::endl;
};
Avatar::Avatar(tstring avatarId, 
			   bool bailOnMissedJoints,
			   const Vec &Position,
			   const Quat &Orientation
			   //const Vec &forwardDir
			   )
			   : name(avatarId), active(true), changed(false), rootChanged (false), 
			   beingEdited(false), //forwardDirection(forwardDir), //amq(NULL), 
			   mot(NULL), scaleMot(NULL)//, facialMot(NULL)
			   //motionOwned(true), facialMotionOwned(true), scaleMotionOwned(true)
{
	std::string::size_type dotpos = 0;
	dotpos = name.find_first_of(".", dotpos);
	if(dotpos != name.npos)
		name = name.substr(0, dotpos);
	initAvatar(avatarId, avatarId, bailOnMissedJoints, Position, Orientation);
	std::cout << "end of avatar constructor" << std::endl;
};


Avatar::Avatar(tstring _name, AvatarImp *_imp)
:name(_name), imp(_imp), active(true), changed(false), rootChanged (false), 
			   beingEdited(false), mot(NULL), scaleMot(NULL)//, facialMot(NULL)
{

}


Avatar::~Avatar() 
{
	delete imp; 
	if(mot)mot->Dispose();
	//if(facialMot)facialMot->Dispose();
	if(scaleMot)scaleMot->Dispose();
	//if(motionOwned) delete mot;
	//if(facialMotionOwned) delete facialMot;
	//if(scaleMotionOwned) delete scaleMot;
	for(unsigned int i = 0; i < callbacks.size(); i++)
		delete callbacks[i];
};


//! set the current time
/*!
	*	This is used for animation, it sets the time within the current piece of motion 
	*	and puts the avatar in the correct position for that motion at that time
	*/
 void	Avatar::timeStep	(float time) 
{
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

	//if(facialMotionEnabled)
	//	showFacialMotionAtTime(time);
	//std::cout << " Avatar.cpp if show facial motion enabled check" << std::endl;

	imp->updateFacialExpressions();
	//std::cout << " Avatar.cpp timestep ENDDDDDDDDDDDDDDDDDDDDD" << std::endl;

	//updateFacialExpressions(time);

	platformSpecific_timeStep (time);
};


void Avatar::activate(){active = true;};
void Avatar::deactivate(){active = false;};

void Avatar::setJointOrientation(std::vector< std::pair<int, Quat > > jointOrientation, jointCoord worldCoord)
{
	for (std::vector< std::pair<int, Quat > >::size_type i = 0; i < jointOrientation.size(); i++)
	{
		setJointOrientation(jointOrientation[i].first, jointOrientation[i].second, worldCoord);
	}
};

void Avatar::loadMotion				(Motion *motion)
{
	//if(motion->isFacial())
	//{
	//	Piavca::Error(_T("Trying to load facial motion as body motion"));
	//	return;
	//}
	// have to Reference of the new motion before
	// disposing the old one in case they are the same
	if(motion)
	{
		if(motion->loaded() && motion->getAvatar() != this)
			motion = motion->clone();
		motion->Reference();
	}
	if(mot) 
	{
		mot->unload();
		mot->Dispose();
	}
	mot = motion;
	if(mot)
	{
		mot->load(this);
	};
	//mot->setStartTime(startTime);
	validateMotions();
};
void Avatar::unloadMotion()
{
	stopMotion();
	if(mot) 
	{
		mot->unload();
		mot->Dispose();
	}
	mot = NULL;
	motionEnabled = false;
}

void Avatar::setMotionStartTime(float startTime) 
{
	if(mot)
		mot->setStartTime(startTime);
};

float Avatar::getMotionStartTime()
{
	if(mot && motionEnabled)
		return mot->getStartTime();
	else
	    return 0;
};

float Avatar::getMotionEndTime()
{
	if(mot && motionEnabled)
		return mot->getEndTime();
	else
	    return 0;
};

/*void Avatar::loadFacialMotion(Motion *motion)
{
	if(!motion->isFacial())
	{
		Piavca::Error(_T("Trying to load body motion as facial motion"));
		return;
	}
	
	// have to Reference of the new motion before
	// disposing the old one in case they are the same
	if(motion)
	{
		if(motion->loaded() && motion->getAvatar() != this)
			motion = motion->clone();
		motion->Reference();
	}
	if(facialMot)
	{
		facialMot->unload();
		facialMot->Dispose();
	}
	facialMot = motion;
	if(facialMot)
	{
		facialMot->load(this);
	}
	validateMotions();
};
void Avatar::unloadFacialMotion()
{
	stopFacialMotion();
	if(facialMot)
	{	
		facialMot->unload();
		facialMot->Dispose();
	}
	facialMot = NULL;
	facialMotionEnabled = false;
}

void Avatar::setFacialMotionStartTime(float startTime) 
{
	if(facialMot)
	    facialMot->setStartTime(startTime);
};
float Avatar::getFacialMotionStartTime()
{
	if(facialMot && facialMotionEnabled)
	    return facialMot->getStartTime();
	else
	    return 0;
};
float Avatar::getFacialMotionEndTime()
{
	if(facialMot && facialMotionEnabled)
	    return facialMot->getEndTime();
	else
	    return 0;
};
*/
void Avatar::loadScaleMotion (Motion *motion)
{
	//if(motion->isFacial())
	//{
	//	Piavca::Error(_T("Trying to load facial motion as body scale motion"));
	//	return;
	//}
	// have to Reference of the new motion before
	// disposing the old one in case they are the same
	if(motion)
	{
		if(motion->loaded() && motion->getAvatar() != this)
			motion = motion->clone();
		motion->Reference();
	}
	if(scaleMot) 
	{
		scaleMot->Dispose();
		scaleMot->unload();
	}
	scaleMot = motion;
	if(scaleMot)
	{
		scaleMot->load(this);
	}
	validateMotions();
};
void Avatar::unloadScaleMotion()
{
	stopScaleMotion();
	if(scaleMot) 
	{
		scaleMot->unload();
		scaleMot->Dispose();
	}
	mot = NULL;
	scaleMotionEnabled = false;
}

void Avatar::setScaleMotionStartTime(float startTime) 
{
	if(scaleMot)
	    scaleMot->setStartTime(startTime);
};
	
float Avatar::getScaleMotionStartTime()
{
	if(scaleMot && scaleMotionEnabled)
	    return scaleMot->getStartTime();
	else
	    return 0;
};

float Avatar::getScaleMotionEndTime()
{
	if(scaleMot && scaleMotionEnabled)
	    return scaleMot->getEndTime();
	else
	    return 0;
};

void Avatar::validateMotions()
{
	if(mot)
	{
		if(!mot->isNull(root_position_id) 
			&& !(mot->getTrackType(root_position_id) & VEC_TYPE))
		{
			Piavca::Error(_T("Trying to load a motion with a non-vector root position"));
			unloadMotion();
		}
		if(mot && !mot->isNull(root_orientation_id) 
			&& !(mot->getTrackType(root_orientation_id) & QUAT_TYPE))
		{
			Piavca::Error(_T("Trying to load a motion with a non-quaternion root orientation"));
			unloadMotion();
		};
		for (int joint = begin(); joint != Core::nullId; joint = next(joint))
		{
			if(mot && !mot->isNull(joint)
				&& !(mot->getTrackType(joint) & QUAT_TYPE))
			{
					Piavca::Error(_T("Trying to load a motion with a non-quaternion track"));
					unloadMotion();
					break;
			}
		}
		for (int expr = beginExpression(); expr != Core::nullId; nextExpression(expr))
		{
			if(!mot->isNull(expr)
				&& !(mot->getTrackType(expr) & FLOAT_TYPE))
			{
				Piavca::Error(_T("Trying to load a motion with a non-float facial track"));
				unloadMotion();
				break;
			}
		}
	}
	/*
	if(facialMot)
	{
		for (int expr = beginExpression(); expr != Core::nullId; nextExpression(expr))
		{
			if(!facialMot->isNull(expr)
				&& !(facialMot->getTrackType(expr) & FLOAT_TYPE))
			{
				Piavca::Error(_T("Trying to load a facial motion with a non-float track"));
				unloadFacialMotion();
				break;
			}
		}
	}
	*/
	if(scaleMot)
	{
		for (int joint = begin(); joint != Core::nullId; joint = next(joint))
		{
			if(!scaleMot->isNull(joint)
				&& !(scaleMot->getTrackType(joint) & FLOAT_TYPE)
				&& !(scaleMot->getTrackType(joint) & VEC_TYPE))
			{
				Piavca::Error(_T("Trying to load a scale motion with a non-float and non-vector track"));
				unloadScaleMotion();
				break;
			}
		}
	}
};

void Avatar::showMotionAtTime	(float time, Motion *motion, bool detectChanges)
{
	static Vec lastPos;
	if(!motion)
		motion = this->mot;
	if(!motion)return;
	
	time = Core::getCore()->getTime();
	
	if(time < 0) return;

	motion->preFrame(time);

	Quat offset = Quat(1.57, Vec(0.0, 0.0, 1.0));

	// set the root position and orientation
	if(!motion->isNull(root_position_id))
	{
	    //std::cout << " Avatar.cpp showMotionAtTime in if-else " << std::endl;
		Vec v = motion->getVecValueAtTime(root_position_id, time);
		if (detectChanges)
		{
			Vec diff = v - lastPos;
			//if (diff.mag() > 1)
			//{
			//	std::cout << "Sudden Position Change " << diff.mag() << " " << lastPos << " " << v << std::endl;
			//}
			lastPos = v;
		}
		//std::cout << "root orientation in avatar" << v << std::endl;
		//v = Vec(v[0], v[2], v[1]);
		//v = offset.inverse().transform(v);
		//v = offset.transform(v);
		setRootPosition(v);
		//std::cout << "root " << mot->getVecValueAtTime(root_position_id, time) << std::endl;
	}
	//else
	//  std::cout << "could not find root pos track" << std::endl;
	if(!motion->isNull(root_orientation_id))
	{
		Quat q = motion->getQuatValueAtTime(root_orientation_id, time);
		//std::cout << "root orientation in avatar" << q << std::endl;
		//q = Quat(q.S(), q.I(), q.K(), q.J());
		//q = q*offset;
		//q = offset*q;
		setRootOrientation(q);
		//std::cout << "root " << mot->getQuatValueAtTime(root_orientation_id, time) << std::endl;
	}
	//else
	 //   std::cout << "could not find root pos track" << std::endl;
	
	// go through all the joints setting those for which there is a track
	for (int joint = begin(); joint != Core::nullId; joint = next(joint))
	{
		if(!motion->isNull(joint))
		{
			int type = motion->getTrackType(joint);
			if (type & QUAT_TYPE)
				setJointOrientation(joint, motion->getQuatValueAtTime(joint, time));
			//if (type & VEC_TYPE)
			//	setJointPosition(joint, motion->getVecValueAtTime(joint, time));
			//std::cout << mot->getQuatValueAtTime(joint, time) << std::endl;
		}
		//else
		   // std::cout << "could not find track: " << joint << std::endl;
	}
	//std::cout << " Avatar.cpp showMotionAtTime BEGINNNNNNNNNNNNNNNNNNNNN" << std::endl;
	
	// go through all the expressions setting those for which there is a track
	for (int expr = beginExpression(); expr != Core::nullId; nextExpression(expr))
	{
		if(!motion->isNull(expr))
		{
			//std::cout << "ShowMotion " << Core::getCore()->getExpressionName(expr) << " " << facialMot->getFloatValueAtTime(expr, time) << std::endl;
			setFacialExpressionWeight(expr, motion->getFloatValueAtTime(expr, time));
		}
	}
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
		if(scaleMot->getTrackType(root_position_id) & FLOAT_TYPE)
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
	for (int joint = begin(); joint != Core::nullId; joint = next(joint))
	{
		if(!scaleMot->isNull(joint))
		{
			Vec s;
			if(scaleMot->getTrackType(joint) & FLOAT_TYPE)
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

/*
void Avatar::showFacialMotionAtTime	(float time)
{
	if(!facialMot)return;
	time = Core::getCore()->getTime();
	if(time < 0) return;
	
	// go through all the expressions setting those for which there is a track
	for (int expr = beginExpression(); expr != Core::nullId; nextExpression(expr))
	{
		if(!facialMot->isNull(expr))
		{
			//std::cout << "ShowMotion " << Core::getCore()->getExpressionName(expr) << " " << facialMot->getFloatValueAtTime(expr, time) << std::endl;
			setFacialExpressionWeight(expr, facialMot->getFloatValueAtTime(expr, time));
		}
	}
};
*/
void Avatar::playMotion()
{
	playMotion(Core::getCore()->getTime());
};
void Avatar::playMotion(float time)
{
	motionEnabled = true;
	//motionStartTime = time;
	mot->setStartTime(time);
};
void Avatar::playMotion(Motion *m, float time)
{
	loadMotion(m);
	playMotion(time);
};
void Avatar::playMotion(Motion *m)
{
	loadMotion(m);
	playMotion();
};

void Avatar::playScaleMotion()
{
	playScaleMotion(Core::getCore()->getTime());
};
void Avatar::playScaleMotion(float time)
{
	scaleMotionEnabled = true;
	//scaleMotionStartTime = time;
	scaleMot->setStartTime(time);
};
void Avatar::playScaleMotion(Motion *m, float time)
{
	loadScaleMotion(m);
	playScaleMotion(time);
};
void Avatar::playScaleMotion(Motion *m)
{
	loadScaleMotion(m);
	playScaleMotion();
};

//void Avatar::playFacialMotion()
//{
//	playFacialMotion(Core::getCore()->getTime());
//};
//void Avatar::playFacialMotion(float time)
//{
//	facialMotionEnabled = true;
//	facialMot->setStartTime(time);
//};
//void Avatar::playFacialMotion(Motion *m, float time)
//{
//	loadFacialMotion(m);
//	playFacialMotion(time);
//};
//void Avatar::playFacialMotion(Motion *m)
//{
//	loadFacialMotion(m);
//	playFacialMotion();
//};

// create a UCLAvatarImp from the factory
void Avatar::initAvatar(	
			tstring avatarId, 
			tstring strFilename,
			bool bailOnMissedJoints,
			const Vec &Position, 
			const Quat &Orientation)
{
	Core::getCore()->initAvatar(this, strFilename, bailOnMissedJoints, Position, Orientation);
	std::cout << "end of init Avatar" << std::endl;
	std::cout.flush();
	if(imp)
	  {
	    imp->frontEnd = this;
	    loadMotion(new KeyframeMotion());
	  }
	std::cout << "real end of init avatar " << std::endl;
	std::cout.flush();
};

int Avatar::end ()  
{
	return Core::nullId;
	//return Core::getCore()->getMaxJointId()+1;
}
int Avatar::next(int jointId) 
{
	int maxJoint = Core::getCore()->getMaxJointId();
	while(isNull(++jointId) && jointId <= maxJoint); 
	if (jointId > maxJoint)
		jointId = Core::nullId;
	return jointId;
};


int Avatar::endExpression ()  
{
	return Core::getCore()->getMaxExpressionId()-1;
};
int Avatar::nextExpression(int &expressionId) 
{
	int maxExpression = Core::getCore()->getMaxExpressionId();
	while(isExpressionNull(--expressionId) && expressionId >= maxExpression); 
	if (expressionId < maxExpression)
		expressionId =  Core::nullId;
	return expressionId;
};

void Avatar::registerCallback(AvatarTimeCallback *cb)
{
	callbacks.push_back(cb);
	cb->init(this);
};

void Avatar::removeCallback(tstring cbName)
{
	for(std::vector< AvatarTimeCallback * >::iterator i = callbacks.begin(); i != callbacks.end(); i++)
	{
		if((*i)->getName() == cbName)
		{
			callbacks.erase(i);
			return;
		}
	}
};
	
AvatarTimeCallback *Avatar::getCallback(tstring cbName)
{
	for(std::vector< AvatarTimeCallback * >::size_type i = 0; i < callbacks.size(); i++)
	{
		if(callbacks[i]->getName() == cbName)
			return callbacks[i];
	}
	return NULL;
};

int Avatar::getNumCallbacks()
{
	return static_cast<int>(callbacks.size());
};

AvatarTimeCallback *Avatar::getCallback(int i)
{
	return callbacks[i];
};
	

void Avatar::event(tstring event)
{
	Motion *mot = getMotion();
	if (mot)
		mot->event(event);
}