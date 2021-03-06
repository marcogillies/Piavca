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
 * The Original Code is ChoiceMotion.h.
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


#ifndef CHOICE_MOTION_H
#define CHOICE_MOTION_H

#include "MotionFilter.h"

namespace Piavca
{

typedef std::vector< Motion * > MotionVec;

//! A motion which has a number of child motions, and which can select one at a time to play
/*!
 *	This has a number of child motions depending on how child motion are selected. 
 *  In the base class a new motion is selected when an event with its name is chosen. 
 *  Otherwise the last motion is played again. 
 *  ChoiceMotions need to be put in loop motions in order to continue playing new motions.
 */
class ChoiceMotion : public MotionFilter
{
	int currentChoice;

	bool smooth;
	bool resetTime;
	float windowLength;
	bool resetOnEvent;
	bool accumulateRoot;
	bool eventsToAllChildren;


	// parameters passed on to the repositioner
	bool maintainUp;
	bool rotateAboutUp;
	bool resetOnPlay;
	bool restartOnPlay;
	Vec upDirection;
	
protected:
	bool eventHappened;
	MotionVec mots; 
	MotionVec listeners;
	
	virtual void updateListeners();
public:
	ChoiceMotion()
		:currentChoice(0), smooth(true), resetTime(true), resetOnPlay(false),  restartOnPlay(false), 
		windowLength(0.5f), resetOnEvent(true), accumulateRoot(true), eventsToAllChildren(false),
		maintainUp(false), rotateAboutUp(true), upDirection(0.0, 0.0, 1.0), eventHappened(false)
		{};
	//! pass in a vector of motions to be used.
	ChoiceMotion(const MotionVec &mpv);
	ChoiceMotion(const ChoiceMotion &cl);
	~ChoiceMotion();

	virtual Motion *clone(){return new ChoiceMotion(*this);};

	//! returns the name of the type
	Piavca::tstring getClassName(){return "ChoiceMotion";};

	//! casts a motion to this type
	static ChoiceMotion *castToThisType(Motion *m){return dynamic_cast<ChoiceMotion *>(m);};
	
	
	//! whether transitions between motions are smoothed
	void setSmooth(bool s)
	{
		smooth = s;	
	};
	bool getSmooth()
	{
		return smooth;	
	};

	//! whether the start time is reset each time a new motion is played
	void setResetTime(bool r)
	{
		resetTime = r;	
	};
	bool getResetTime()
	{
		return resetTime;	
	};

	//! the blending window for smooth transitions
	void setWindowLength(float w)
	{
		windowLength = w;	
	};
	float getWindowLength()
	{
		return windowLength;	
	};

	//! whether a new motion is chosen immediately when an event is received
	void setResetOnEvent(bool r)
	{
		resetOnEvent = r;	
	};
	bool getResetOnEvent()
	{
		return resetOnEvent;	
	};

	//! Whether a child motion is reset each time it is played
	void setResetOnPlay(bool r)
	{
		resetOnPlay = r;	
	};
	bool getResetOnPlay()
	{
		return resetOnPlay;	
	};
	
	//! Whether a child motion should restart from its initial state each time it is played
	void setRestartOnPlay(bool r)
	{
		restartOnPlay = r;	
	};
	bool getRestartOnPlay()
	{
		return restartOnPlay;	
	};
	


	//! whether events are propagated down to all children on just the current one 
	void setEventsToAllChildren(bool r)
	{
		eventsToAllChildren = r;	
	};
	bool getEventsToAllChildren()
	{
		return eventsToAllChildren;	
	};

	//! whether changes to the root position made by one motion are continued into the next one
	void setAccumulateRoot(bool a)
	{
		accumulateRoot = a;	
	};
	bool getAccumulateRoot()
	{
		return accumulateRoot;	
	};
	
	//! whether vertical root changes are accumulated or not
	void setMaintainUp(bool b){maintainUp = b;};
	bool getMaintainUp(){return maintainUp;};

	
	//! whether root rotations are accumulated just about the vertical axis, or in all directions
	void setRotateAboutUp(bool b){rotateAboutUp = b;};
	bool getRotateAboutUp(){return rotateAboutUp;};

	//! the direction vector that is used as up
	void setUpDirection(Vec v)
	{
		upDirection = v;
		upDirection.normalize();
	};
	Vec getUpDirection(){return upDirection;};
	
	//! a generic function for setting parameters
	virtual bool setParameter(tstring paramName, tstring value);

	
	
	void printInfo();


	//! handle listeners (motions that recieve events from the choice motion
	//!@{
	int getNumListeners();
	void addListener(Motion *listener);
	Motion *getListener(int i);
	//!@}

	
	//! gets the length of the motion in seconds
	virtual float getMotionLength() const;

	
	int getLastMotion();

	//! adds a new child motion
	virtual void addMotion(Motion *mot);

	//! gets the index of a child motion give its name
	int getMotionIndex(tstring motionName);

	
	//! gets the number of child motions
	int getNumMotions();

	
	//! gets a child motion by index
	Motion *getMotionByIndex(int index);

	//! gets the currently playing motion
	Motion *getMotion();
	
	//! In a heirarchy of Choice motions, get the actual leaf motion that is currently playing
	Motion *getLeafMotion();
	
	//! gets a child motion by index
	Motion *getMotion(int index);
	
	//! gets a child motion by name
	Motion *getMotion(tstring motionName);
	
	//! removes the ith child motion
	void removeMotionByIndex(int index);
	
	//! removes all child motions
	void clear();

	//! finds the first submotion with a given name
	virtual Motion *findSub(tstring nm);

	//! finds the first submotion with a given type
	virtual Motion *findSubByType(const type_info &ty);

	virtual void cleanRecursionState();


	//! sets which motion is currently being played
	void setChoice(int i);
	//! sets which motion is currently being played (by name)
	void setChoice(tstring name);
	//! gets the current choice 
	int getCurrentChoice()
	{
		return currentChoice;
	}
	
	/*! chooses the next motion to play
	 * In the base class it just chooses the current one again but it can be overridden in subclasses.
	 */
	virtual int makeChoice(bool restart = false);
	
	//! handles an event (plays the motion with the same name as the event)
	void handleEvent(tstring ev);
	virtual bool canHandleEvent(tstring ev);

	//! gets the names of all events
	virtual std::vector<Piavca::tstring> getEventNames();
	
	//! resets the motion, updating to a new current motion
	/*!
	 * It can be called by the client to interrupt the current motion.
	 */
	virtual bool reset(bool restart=false);
};

};

#endif //CHOICE_MOTION_H
