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
 * The Original Code is Avatar.h.
 *
 * The Initial Developer of the Original Code is Marco (Mark) Gillies.
 * Portions created by the Initial Developer are Copyright (C) BT plc. 2004
 * All Rights Reserved.
 *
 * ***** END LICENSE BLOCK ***** */

#ifndef AVATAR_H
#define AVATAR_H

//#include "Joint.h"
#include "PiavcaDefs.h"
//#include "PlatformDefs.h"
#include "AvatarImp.h"
#include "PiavcaCore.h"

#include <vector>
using std::vector;

#include <assert.h>

#include "Vec.h"
#include "Quat.h"
#include "MathsUtils.h"


namespace Piavca
{
//class AvatarMotionQueue;

// supporting class that deals with motion
class PIAVCA_DECL Motion;

//! an exception that is thrown if an invalid joint id is passed to the avatar
class PIAVCA_DECL InvalidJointIdException : public CException
{
	int jointId;
public:
	InvalidJointIdException(int i, tstring details):CException(details), jointId(i){};
	InvalidJointIdException(const InvalidJointIdException &e):CException(e), jointId(e.jointId){};
	const InvalidJointIdException &operator=(const InvalidJointIdException &e){details=e.details; jointId = e.jointId; return (*this);}; 
};


//! The actual avatar class
/*!
 *	This class is the main component of the Piavca API and represents a character for skeletal animation.
 *	It has fairly basic simple functionality, just altering root position and orientation, 
 *	loading and playing motion and directly altering joint orientations
 *	It is an interfaces class that forwards all its method calls to an
 *	implementation class which is an platform specific class that does all
 *	the work. The class is structured as a bridge pattern from Design Patterns. An interface class contains a pointer
 *	to an implementation object and forwards all method calls to it. The implementation object is in fact of a 
 *	platform specific sub-type of the implementation class. The joints themselves are not exposed to the client and are
 *	accessed via integer IDs. These IDs are unique for a given joint across all avatars and motions.
 *  any actions on joints area achieved by passing the ID to an appropriate method
 */
class PIAVCA_DECL Avatar{
	
protected:
	
	//! The implementation class, all methods get forwarded to it
	AvatarImp *imp;
    
    // Motion Queue
    //AvatarMotionQueue *amq;

	//! the current motion of the avatar
	Motion *mot;
	//! whether the motion is currently playing
	bool motionEnabled;
	//! whether the avatar owns the motion (and should therefore delete it)
	//bool motionOwned;
	//! when the loaded piece of motion starts.
	//float motionStartTime;

	//! the motion that controls the characters scale
	Motion *facialMot;
	//! whether the scale motion is currently playing
	bool facialMotionEnabled;
	//! whether the avatar owns the motion (and should therefore delete it)
	//bool facialMotionOwned;
	//! when the scale motion starts.
	//float facialMotionStartTime;

	//! the motion that controls the characters scale
	Motion *scaleMot;
	//! whether the scale motion is currently playing
	bool scaleMotionEnabled;
	//! whether the avatar owns the motion (and should therefore delete it)
	//bool scaleMotionOwned;
	//! when the scale motion starts.
	//float scaleMotionStartTime;
	
	//! a motion factory used for creating avatars
	/*!
	 *	This will in fact be a platform specific sub-type of UCLAvatarFactory.
	 *	It is not owned by this class.
	 */
	//Piavca::Core *core;

	//! callbacks that are called every frame
	std::vector<AvatarTimeCallback *> callbacks;

	//! a vector for the direction that the avatar points forwards towards in its rest position
	Vec forwardDirection;

	//! a flag that is used to turn off updates of an avatar
	bool active;

	//! A flag that shows whether the avatar has been changed from the user interface
	bool changed;
	//! A flag that shows whether the avatar is currently being edited from the user interface
	bool beingEdited;
	//! whether the root position or orientation have changed due to user interaction
	bool rootChanged;

	//! the name of the character
	tstring name;
	//! initialise a Avatar in a platform dependent way using the core
	void initAvatar(tstring avatarId, bool bailOnMissedJoints, const Vec &Position, const Quat &Orientation);

	/*! This is a function that does platform specific per-frame stuff
	 *  Called by timeStep
	 */
	void platformSpecific_timeStep (float time){imp->platformSpecific_timeStep(time);};
private:
	//! \name you can't copy them
	//{@
	//! copy constructor
	Avatar(const Avatar &av) {assert(0);};
	//! assignment
	const Avatar &operator=(const Avatar &av) {assert(0); return (*this);};
	//@}
	
	//! destructor can only be called by the core, use Core::removeAvatar to delete an avatar
	virtual ~Avatar() 
	{
		delete imp; 
		if(mot)mot->Dispose();
		if(facialMot)facialMot->Dispose();
		if(scaleMot)scaleMot->Dispose();
		//if(motionOwned) delete mot;
		//if(facialMotionOwned) delete facialMot;
		//if(scaleMotionOwned) delete scaleMot;
		for(unsigned int i = 0; i < callbacks.size(); i++)
			delete callbacks[i];
	};

	//! this validates the various motions that are loaded to check they have the correct track types
	void validateMotions();
public:
	//! create an avatar
	/*!
	 *	The avatar needs to be initialised with an implementation. The 
	 *	type of the implementation depends on the platform and so it 
	 *	cannot be created directly in platform independant code. To 
	 *	get around this it is created by a static factory method in the 
	 *	which itself uses the Piavca::Core class and its platform dependent implementation 
	 *	to create the implementation of the avatar. The constructor needs an identifier
	 *	string that it uses to find platform specific data needed to create
	 *	the avatar, for example the mesh file. The user can also pass in 
	 *	a position and orientation for the avatar.
	 *  If bail on missed joints is true it will fail to create the avatar
     *  if not all the needed joints are present in the model and will result
	 *  in an invalid avatar (this can be tested with the isValid method).
	 */
	Avatar(tstring avatarId, 
		   bool bailOnMissedJoints = false, 
		   const Vec &Position = Vec(0.0, 0.0, 0.0), 
		   const Quat &Orientation = Quat(1.0, 0.0, 0.0, 0.0),
		   const Vec &forwardDir = Vec(0.0, 0.0, 1.0))
		: name(avatarId), active(true), changed(false), rootChanged (false), 
		beingEdited(false), forwardDirection(forwardDir), //amq(NULL), 
		mot(NULL), scaleMot(NULL), facialMot(NULL)
		//motionOwned(true), facialMotionOwned(true), scaleMotionOwned(true)
	{
		std::string::size_type dotpos = 0;
		dotpos = name.find_first_of(".", dotpos);
		if(dotpos != name.npos)
			name = name.substr(0, dotpos);
		initAvatar(avatarId, bailOnMissedJoints, Position, Orientation);
	};

	Avatar(const char *avatarId): 
		name(StringToTString(avatarId)), active(true), changed(false), rootChanged (false), 
		beingEdited(false), forwardDirection(0, 0, 1), //amq(NULL), 
		mot(NULL), scaleMot(NULL), facialMot(NULL)
		//motionOwned(true), facialMotionOwned(true), scaleMotionOwned(true)
	{
		initAvatar(StringToTString(avatarId), false, Vec(), Quat());
	};

	//! get hold of the piavca core
	//Piavca::Core *getCore() const {return core;};
	//! set the current piavca core object
	//void setCore(Piavca::Core *c){core = c;};

	bool isValid(){return imp != NULL;};

	//! turn on updates on the avatar
	virtual void activate();
	//! turn off updates on the avatar
	virtual void deactivate();


	//! get the name of the avatar
	tstring getName(){return name;};
	//! set the name of the avatar
	tstring setName(tstring newName){return name = newName;};

	//! whether the avatar is being edited in the user interface
	bool getEditFlag()     {return beingEdited;}
	//! this method should if the avatar is being edited in the interface
	void setEditFlag()     {beingEdited = true;}
	//! clear the edit flag once the edit has finished
	void clearEditFlag()   {beingEdited = false;}

	//! whether the Avatar has been changed by a user interface edit
	bool getChangedFlag()  {return changed;}
	//! this method should if the avatar has been changed in the interface	
	void setChangedFlag()  {changed = true;}
	//! clear the changed flag once the change has been dealt with
	void clearChangedFlag(){changed = false;}

	//! returns the local direction at which the avatar points forward
	const Vec &getForwardDirection(){return forwardDirection;};
	//! sets the local direction at which the avatar points forward
	void setForwardDirection(const Vec &dir){forwardDirection = dir;};

	//! \name Facial Animation Methods (based on morph target like system)
	//!@{
	//bool  setNeutralFacialExpression(tstring expressionName){return imp->setNeutralFacialExpression(expressionName);};
	//bool  addFacialExpression(tstring expressionName){return imp->addFacialExpression(expressionName);};
	//int   getFacialExpressionId(tstring expressionName){return imp->getFacialExpressionId(expressionName);};
	//! set the weight of a facial expression (used in the blend)
	bool  setFacialExpressionWeight(int id, float weight, float timeInterval = 0.5){return imp->setFacialExpressionWeight(id, weight);};
	//! get the weight of an expression
	float getFacialExpressionWeight(int id){return imp->getFacialExpressionWeight(id);};
	//! set all expression weights to zero
	void  clearFacialExpressionWeights(){imp->clearFacialExpressionWeights();};
	//void  updateFacialExpressions(float time){imp->updateFacialExpressions(time);};
	//! the ID of the first joint that is present in the avatar (the ordering is arbitrary)
	int beginExpression() const {int i=0; while(isExpressionNull(i) && i < end())i++; return i;};
	//! the last joint + 1
	int endExpression () const;
	//! given a joint ID this returns the next joint ID that is present in the avatar
	int nextExpression(int &expressionId) 
	{
		int maxExpression = Core::getCore()->getMaxExpressionId();
		while(isExpressionNull(++expressionId) && expressionId <= maxExpression); 
		return expressionId;
	};
	//! whether the joint is present in the avatar
	bool isExpressionNull(int expressionId)const{return imp->isExpressionNull(expressionId);};
	//!@}


	//! \name Root position and orientation
	//@{ 
	/*!
	 *	get or set the root position and orientation of the avatar
	 */
	void	setRootPosition			(const Vec &Position) {imp->setRootPosition(Position);};
	Vec		getRootPosition			() {return imp->getRootPosition();};
	void	setRootOrientation		(const Quat &Orientation) {imp->setRootOrientation(Orientation);};
	//! set the root orientation from an angle in radians (assumed to be about the verticle)
	void	setRootAngle			(float angle) {imp->setRootOrientation(Quat(angle, Vec(0.0, 1.0, 0.0)));};
	//! set the root orientation from an angle in degrees (assumed to be about the verticle)
	void	setRootAngleDeg			(float angle) {imp->setRootOrientation(Quat(degToRad(angle), Vec(0.0, 1.0, 0.0)));};
	Quat	getRootOrientation		() {return imp->getRootOrientation();};
	//@}

	//! creates a new joint
	/*!
	 *	It will only succeed if there is a piece of geometry corresponding to the name
	 *	if not it returns false.
	 */
	bool createJoint(tstring jointName){return imp->createJoint(jointName);};

	//! the ID of the first joint that is present in the avatar (the ordering is arbitrary)
	int begin() const {int i=0; while(isNull(i) && i < end())i++; return i;};
	//! the last joint + 1
	int end () const;
	//! given a joint ID this returns the next joint ID that is present in the avatar
	int next(int &jointId) 
	{
		int maxJoint = Core::getCore()->getMaxJointId();
		while(isNull(++jointId) && jointId <= maxJoint); 
		return jointId;
	};
	//! returns the ID of the parent of the joint in the joint heirarchy (or a negative value if it doesn't exist
	int getParent(int jointId)const{return imp->getParent(jointId);};
	//! get the name of the joint corresponding to an ID
	const tstring getJointName(int jointId){return imp->getJointName(jointId);};
	//! whether the joint is present in the avatar
	bool isNull(int jointId)const{return imp->isNull(jointId);};

	//! check whether the joint has been changed by user input
	bool hasChanged(int jointId){return imp->hasChanged(jointId);};
	//! clears the changed flag for the joint
	void clearChange(int jointId){imp->clearChange(jointId);};
	//@}

	//! set the value of the orientation of a joint
	/*!
	 *	The joint is specified via an ID.
	 *	This can be done in various coordinate systems, 
	 *	jointlocal is the coordante space of the joint (default)
	 *	local is the space of the avatar root
	 *	world is the world coordinates
	 *	using the second two is likely to be much less efficient
	 */
	void	setJointOrientation		(int jointId, const Quat &val, jointCoord worldCoord = JOINTLOCAL_COORD)
		{imp->setJointOrientation(jointId, val, worldCoord);};
	//! get the orientation of a joint
	/*!
	 *	The joint is specified via an ID.
	 *	This can be done in various coordinate systems, 
	 *	jointlocal is the coordante space of the joint (default)
	 *	local is the space of the avatar root
	 *	world is the world coordinates
	 *	using the second two is likely to be much less efficient
	 */
	Quat	getJointOrientation		(int jointId, jointCoord worldCoord = JOINTLOCAL_COORD)
		{return imp->getJointOrientation(jointId, worldCoord);};

	//! set all the joint orientations from a vector of joint IDs and values
	/*!
	 *	This can be done in various coordinate systems, 
	 *	jointlocal is the coordante space of the joint (default)
	 *	local is the space of the avatar root
	 *	world is the world coordinates
	 *	using the second two is likely to be much less efficient
	 */
	void	setJointOrientation(std::vector< std::pair<int, Quat > > jointOrientation, jointCoord worldCoord = JOINTLOCAL_COORD)
	{
		for (std::vector< std::pair<int, Quat > >::size_type i = 0; i < jointOrientation.size(); i++)
		{
			setJointOrientation(jointOrientation[i].first, jointOrientation[i].second, worldCoord);
		}
	};

	//! get the current position of the start point of the joint
	/*!
	 *	calculated from the root position and joint angles by forward kinematics
	 *	This can be done in various coordinate systems, 
	 *	jointlocal is the coordante space of the joint 
	 *	local is the space of the avatar root (default)
	 *	world is the world coordinates
	 */
	Vec		getJointBasePosition	(int jointId, jointCoord worldCoord = LOCAL_COORD)
		{return imp->getJointBasePosition(jointId, worldCoord);};


	//! scales the root by a non-uniform scale vector
	void   scaleRoot (Vec scale){imp->scaleRoot(scale);};
	//! scales a joint by a non-uniform scale vector
	void   scaleJoint (int jointId, Vec scale){imp->scaleJoint(jointId, scale);};

	//! set the current time
	/*!
	*	This is used for animation, it sets the time within the current piece of motion 
	*	and puts the avatar in the correct position for that motion at that time
	*/
	void	timeStep	(float time);

	/*! \name motion
	 *	Motion is handled by a separate class
	 *	The motion itself can be read in from a bvh file or can be a subclass of motion that
	 *  handles things like motion	transforms and motion combinations (see the motion class docs for details)
	 */
	//@{
	//! load motion as a motion object
	/*!
	 *	The start time allows the client to specify a time in world time for
	 *	the motion to start running
	 */
	inline void	loadMotion				(Motion *motion)
	{
		if(motion->isFacial())
		{
			Piavca::Error(_T("Trying to load facial motion as body motion"));
			return;
		}
		// have to Reference of the new motion before
		// disposing the old one in case they are the same
		if(motion)
		{
			if(motion->loaded())motion = motion->clone();
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
	void unloadMotion()
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

	//! get a pointer to the motion so it can be manipulated by the client
	Motion *getMotion()				{return mot;};
	//! get a const pointer to the motion so it can be seen by the client
	const Motion *getMotion			() const {return mot;};
	
	//! starts playing the motion at the current time
	void playMotion();
	//! starts the motion playing at time
	void playMotion(float time)
	  {
		motionEnabled = true;
	    //motionStartTime = time;
		mot->setStartTime(time);
	  };
	void playMotion(Motion *m, float time)
	{
		loadMotion(m);
		playMotion(time);
	};
	void playMotion(Motion *m)
	{
		loadMotion(m);
		playMotion();
	};
	//! stops the motion playing
	void stopMotion(){ motionEnabled = false;};
	//! restarts the motion without changing the start time
	void restartMotion(){ motionEnabled = true;};
	
	//! changes the start time of the motion
	void setMotionStartTime(float startTime) 
	{
		mot->setStartTime(startTime);
		//motionStartTime = startTime;
	};
	//! get the time when the current motion starts
	float getMotionStartTime(){return mot->getStartTime();};
	//! get the time when the current motion should end
	float getMotionEndTime()
	  {
	    if(mot && motionEnabled)
			return mot->getEndTime();//mot->getMotionLength() + motionStartTime;
	    else
	      return 0;
	  };

	//! displays the motion on the avatar at time
	void showMotionAtTime(float time) ;
	// saves the current posture as a frame in the motion
	//savePostureToMotion(float time, bool createNewTracks=true);
	//@}

	/*! \name facial motion
	 *	This is handled the same way as normaly motion but it affects the 
	 *  facial expression weights
	 */
	//@{
	//! load a facial motion as a motion object
	/*!
	 *	The start time allows the client to specify a time in world time for
	 *	the motion to start running
	 */
	void	loadFacialMotion				(Motion *motion)
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
			if(motion->loaded())motion = motion->clone();
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
	void unloadFacialMotion()
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

	//! get a pointer to the motion so it can be manipulated by the client
	Motion *getFacialMotion()				{return facialMot;};
	//! get a const pointer to the motion so it can be seen by the client
	const Motion *getFacialMotion			() const {return facialMot;};
	
	//! starts playing the motion at the current time
	void playFacialMotion();
	//! starts the motion playing at time
	void playFacialMotion(float time)
	  {
		facialMotionEnabled = true;
	    //facialMotionStartTime = time;
		facialMot->setStartTime(time);
	  };
	//! starts the motion playing at time
	void playFacialMotion(Motion *m, float time)
	{
		loadFacialMotion(m);
		playFacialMotion(time);
	};
	//! starts playing the motion at the current time
	void playFacialMotion(Motion *m)
	{
		loadFacialMotion(m);
		playFacialMotion();
	};
	//! stops the motion playing
	void stopFacialMotion(){ facialMotionEnabled = false;};
	//! restarts the motion without changing the start time
	void restartFacialMotion(){ facialMotionEnabled = true;};
	
	//! changes the start time of the motion
	void setFacialMotionStartTime(float startTime) {facialMot->setStartTime(startTime);};
	//! get the time when the current motion starts
	float getFacialMotionStartTime(){return facialMot->getStartTime();};
	//! get the time when the current motion should end
	float getFacialMotionEndTime()
	  {
	    if(facialMot && facialMotionEnabled)
	      return facialMot->getEndTime();//getMotionLength() + facialMotionStartTime;
	    else
	      return 0;
	  };

	//! displays the motion on the avatar at time
	void showFacialMotionAtTime(float time) ;
	// saves the current posture as a frame in the motion
	//savePostureToMotion(float time, bool createNewTracks=true);
	//@}
	

	/*! \name scale motion
	 *	This is handled the same way as normaly motion but it affects the 
	 *  scale factors of the joints
	 */
	//@{
	//! load a scale motion as a motion object
	/*!
	 *	The start time allows the client to specify a time in world time for
	 *	the motion to start running
	 */
	void	loadScaleMotion				(Motion *motion)
	{
		if(motion->isFacial())
		{
			Piavca::Error(_T("Trying to load facial motion as body scale motion"));
			return;
		}
		// have to Reference of the new motion before
		// disposing the old one in case they are the same
		if(motion)
		{
			if(motion->loaded())motion = motion->clone();
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
	void unloadScaleMotion()
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

	//! get a pointer to the motion so it can be manipulated by the client
	Motion *getScaleMotion()				{return scaleMot;};
	//! get a const pointer to the motion so it can be seen by the client
	const Motion *getScaleMotion			() const {return scaleMot;};
	
	//! starts playing the motion at the current time
	void playScaleMotion();
	//! starts the motion playing at time
	void playScaleMotion(float time)
	  {
		scaleMotionEnabled = true;
	    //scaleMotionStartTime = time;
		scaleMot->setStartTime(time);
	  };
	//! starts the motion playing at time
	void playScaleMotion(Motion *m, float time)
	{
		loadScaleMotion(m);
		playScaleMotion(time);
	};
	//! starts playing the motion at the current time
	void playScaleMotion(Motion *m)
	{
		loadScaleMotion(m);
		playScaleMotion();
	};
	//! stops the motion playing
	void stopScaleMotion(){ scaleMotionEnabled = false;};
	//! restarts the motion without changing the start time
	void restartScaleMotion(){ scaleMotionEnabled = true;};
	
	//! changes the start time of the motion
	void setScaleMotionStartTime(float startTime) {scaleMot->setStartTime(startTime);};
	//! get the time when the current motion starts
	float getScaleMotionStartTime(){return scaleMot->getStartTime();};
	//! get the time when the current motion should end
	float getScaleMotionEndTime()
	  {
	    if(scaleMot && scaleMotionEnabled)
	      return scaleMot->getEndTime();//getMotionLength() + scaleMotionStartTime;
	    else
	      return 0;
	  };

	//! displays the motion on the avatar at time
	void showScaleMotionAtTime(float time) ;
	// saves the current posture as a frame in the motion
	//savePostureToMotion(float time, bool createNewTracks=true);
	//@}
	
	/*!	\name Time call back methods
	 *	These methods deal with callbacks that are called whenever the time changes.
	 *	There can be multiple callbacks.
	 */
	//@{
	//! registers a callback so that it is called on the avatar every frame
	void registerCallback(AvatarTimeCallback *cb)
	{
		callbacks.push_back(cb);
		cb->init(this);
	};
	//! deletes a callback
	void removeCallback(tstring cbName)
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
	//! get a pointer to a callback
	AvatarTimeCallback *getCallback(tstring cbName)
	  {
	    for(std::vector< AvatarTimeCallback * >::size_type i = 0; i < callbacks.size(); i++)
	      {
			if(callbacks[i]->getName() == cbName)
			 return callbacks[i];
	      }
	    return NULL;
	  };

	//! gets the number of registered callbacks (for iterating through them)
	int getNumCallbacks(){return callbacks.size();};
	//! get a callback based on its index (the indeces are arbitrary this is just useful for finding a callback)
	AvatarTimeCallback *getCallback(int i){return callbacks[i];};
	//@}

	friend class AvatarImp;
	friend class Piavca::Core;

};

};

#endif //AVATAR_H
