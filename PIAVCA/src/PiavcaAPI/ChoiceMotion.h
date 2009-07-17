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

//! a motion where the client can choose which of a set of child motions to play
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
	Vec upDirection;
	
protected:
	bool eventHappened;
	MotionVec mots; 
	MotionVec listeners;
	
	virtual void updateListeners();
public:
	ChoiceMotion()
		:currentChoice(0), smooth(true), resetTime(true), resetOnPlay(false), 
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
	
	
	
	void setSmooth(bool s)
	{
		smooth = s;	
	};
	bool getSmooth()
	{
		return smooth;	
	};

	void setResetTime(bool r)
	{
		resetTime = r;	
	};
	bool getResetTime()
	{
		return resetTime;	
	};

	void setWindowLength(float w)
	{
		windowLength = w;	
	};
	float getWindowLength()
	{
		return windowLength;	
	};

	void setResetOnEvent(bool r)
	{
		resetOnEvent = r;	
	};
	bool getResetOnEvent()
	{
		return resetOnEvent;	
	};

	void setResetOnPlay(bool r)
	{
		resetOnPlay = r;	
	};
	bool getResetOnPlay()
	{
		return resetOnPlay;	
	};


	
	void setEventsToAllChildren(bool r)
	{
		eventsToAllChildren = r;	
	};
	bool getEventsToAllChildren()
	{
		return eventsToAllChildren;	
	};

	void setAccumulateRoot(bool a)
	{
		accumulateRoot = a;	
	};
	bool getAccumulateRoot()
	{
		return accumulateRoot;	
	};
	
	//! parameters passed on to the repositioner
	//!@{
	void setMaintainUp(bool b){maintainUp = b;};
	bool getMaintainUp(){return maintainUp;};

	void setRotateAboutUp(bool b){rotateAboutUp = b;};
	bool getRotateAboutUp(){return rotateAboutUp;};

	void setUpDirection(Vec v)
	{
		upDirection = v;
		upDirection.normalize();
	};
	Vec getUpDirection(){return upDirection;};
	//!@}
	
	
	void printInfo();


	//! handle listeners (motions that recieve events from the choice motion
	//!@{
	int getNumListeners();
	void addListener(Motion *listener);
	Motion *getListener(int i);
	//!@}

	
	//! gets the length of the motion in seconds
	virtual float getMotionLength() const;


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
	virtual int makeChoice();
	
	//! handles an event (plays the motion with the same name as the event)
	void event(tstring ev);
	virtual bool canHandleEvent(tstring ev);

	//! gets the names of all events
	virtual std::vector<Piavca::tstring> getEventNames();
	
	//! resets the motion, updating to a new current motion
	/*!
	 * It can be called by the client to interrupt the current motion.
	 */
	virtual bool reset();
};

};

#endif //CHOICE_MOTION_H
