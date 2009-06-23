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
 * The Original Code is ChoiceMotion.cpp.
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

#include "ChoiceMotion.h" 
#include "Sequence.h"
#include "SavedFramesTransition.h"
#include "SubMotion.h"
#include "Reposition.h"

using namespace Piavca;

ChoiceMotion::ChoiceMotion(const MotionVec &mpv)
		:MotionFilter(), mots(mpv), currentChoice(0), resetOnPlay(false),
		smooth(true), resetTime(true), windowLength(0.5f), 
		resetOnEvent(true), accumulateRoot(true), eventsToAllChildren(false),
		maintainUp(false), rotateAboutUp(true), upDirection(0.0, 1.0, 0.0)
{
	MotionVec::size_type i;
	for(i = 0; i < mpv.size(); i++)
	{
		addMotion(mpv[i]);
		//mots[i]->Reference();
	}
};
ChoiceMotion::ChoiceMotion(const ChoiceMotion &cl)
:MotionFilter(cl), mots(cl.mots), currentChoice(cl.currentChoice), resetOnPlay(cl.resetOnPlay),
	smooth(cl.smooth), resetTime(cl.resetTime), windowLength(cl.windowLength), 
	resetOnEvent(cl.resetOnEvent), accumulateRoot(cl.accumulateRoot), eventsToAllChildren(cl.eventsToAllChildren),
	maintainUp(cl.maintainUp), rotateAboutUp(cl.rotateAboutUp), upDirection(cl.upDirection)
{
	for(MotionVec::size_type i = 0; i < cl.mots.size(); i++)
	{
		addMotion(cl.mots[i]->clone());
		//mots[i] = mots[i]->clone();
		//mots[i]->Reference();
	}
};
ChoiceMotion::~ChoiceMotion()
{
	setMotion(NULL);
	for(MotionVec::size_type i = 0; i < mots.size(); i++)
		mots[i]->Dispose();
	mots.clear();
};

void ChoiceMotion::printInfo()
{
	Motion::printInfo();
	debug_prefix++;
	for(MotionVec::size_type i = 0; i < mots.size(); i++)
		mots[i]->printInfo();
	debug_prefix--;
};


float ChoiceMotion::getMotionLength() const
{
	float len = MotionFilter::getMotionLength();
	if (smooth)
		len -= windowLength;
	return len;
};

//adds a new child motion
void ChoiceMotion::addMotion(Motion *mot)
{
	if(mot)
	{
		mots.push_back(mot);
		mots.back()->Reference();
		//hasPlayed.push_back(false);
		if(mots.size() == 1) setMotion(mots.back());
	}
}

//! gets the index of a child motion give its name
int ChoiceMotion::getMotionIndex(tstring motionName)
{
	for (int i = 0; i < mots.size(); i++)
		if (mots[i]->getName() == motionName)
			return i;
	return -1;
}


//! gets the number of child motions
int ChoiceMotion::getNumMotions()
{
	return mots.size();
};


//! gets a child motion by index
Motion *ChoiceMotion::getMotionByIndex(int index)
{
	if (index < 0 || index >= mots.size())
		Piavca::Error(_T("invalid index"));
	return mots[index];
}


//! gets a child motion by index
Motion *ChoiceMotion::getMotion()
{
	return MotionFilter::getMotion();
}

Motion *ChoiceMotion::getLeafMotion()
{
	Motion *m = getMotion();
	ChoiceMotion *cm = dynamic_cast<ChoiceMotion *>(m);
	if (cm)
		return cm->getMotion();
	else
		return m;
}

//! gets a child motion by index
Motion *ChoiceMotion::getMotion(int index)
{
	return getMotionByIndex(index);
}

//! gets a child motion by name
Motion *ChoiceMotion::getMotion(tstring motionName)
{
	int i = getMotionIndex(motionName);
	if (i < 0)
		return NULL;
	else
		return getMotionByIndex(i);
}

//! removes the ith child motion
void ChoiceMotion::removeMotionByIndex(int index)
{
	mots[index]->Dispose();
	mots.erase(mots.begin() + index);
}

//! removes all child motions
void ChoiceMotion::clear()
{
	for (int i = 0; i < mots.size(); i++)
		mots[i]->Dispose();
	mots.clear();
}

Motion *ChoiceMotion::findSub(tstring nm)
{
	Motion *m = Motion::findSub(nm);
	if(m) 
		return m;
	for (MotionVec::size_type i = 0; i < mots.size(); i++)
	{
		m = mots[i]->findSub(nm);
		if(m) return m;
	}
	return NULL;
};

//! finds the first submotion with a given type
Motion *ChoiceMotion::findSubByType(const type_info &ty)
{
	Motion *m = Motion::findSubByType(ty);
	if(m) 
		return m;
	for (MotionVec::size_type i = 0; i < mots.size(); i++)
	{
		m = mots[i]->findSubByType(ty);
		if(m) return m;
	}
	return NULL;
};

void ChoiceMotion::cleanRecursionState()
{
	MotionFilter::cleanRecursionState();
	for(MotionVec::size_type i = 0; i < mots.size(); i++)
	{
		mots[i]->cleanRecursionState();
	}
}


//! sets which motion is currently being played
void ChoiceMotion::setChoice(int i)
{
	if(/*i < 0 ||*/ i >= static_cast<int>(mots.size()))
		Piavca::Error(_T("Illegal motion choice"));
	currentChoice = i;
};
//! sets which motion is currently being played (by name)
void ChoiceMotion::setChoice(tstring name)
{
	for(MotionVec::size_type i=0; i < mots.size(); i++)
		if(mots[i]->findSub(name)) 
		{
			currentChoice = static_cast<int>(i);
			//reblend(Piavca::Core::getCore()->getTime());
			return;
		}
	Piavca::Error(tstring(_T("Unknown choice ")) + name);
};


int ChoiceMotion::makeChoice()
{

	std::cout << "ChoiceMotion makeChoice: " << std::endl;
	return getCurrentChoice();
}

//! handles an event (plays the motion with the same name as the event)
void ChoiceMotion::event(tstring ev)
{
	for(int i = 0; i < int(mots.size()); i++)
		if (mots[i]->getName() == ev)
		{
			currentChoice = i;
			std::cout << "Choice Motion: event " << ev << std::endl;
			eventHappened = true;
			if(resetOnEvent)
				reset();
			break;
		}
	if (eventsToAllChildren)
	{
		for(int i = 0; i < int(mots.size()); i++)
			mots[i]->event(ev);
	}
	else
	{
		MotionFilter::event(ev);
	}
}
bool ChoiceMotion::canHandleEvent(tstring ev)
{
	for(int i = 0; i < int(mots.size()); i++)
		if (mots[i]->getName() == ev)
		{
			return true;
		}
	return MotionFilter::canHandleEvent(ev);
}

//! gets the names of all events
std::vector<Piavca::tstring> ChoiceMotion::getEventNames()
{
	std::vector<Piavca::tstring> names;
	for(int i = 0; i < int(mots.size()); i++)
		if (mots[i]->getName() != _T(""))
		{
			names.push_back(mots[i]->getName());
		}
	return names;
}

//! called each time around the loop
/*!
 * It can be called by the client to interrupt the current motion.
 */
bool ChoiceMotion::reset()
{
	if(mots.size() <= 0)
		return true;
	std::cout << "ChoiceMotion reset, about to make choice: " << std::endl;
	int choice = makeChoice();
	eventHappened = false;
	if (choice < 0)
		return false;
	std::cout << "ChoiceMotion reset, choice: " << choice << std::endl;
	if (choice != currentChoice)
	{
		if(currentChoice >= 0 && currentChoice < (int)mots.size())
			mots[currentChoice]->event("__finished__");
		mots[choice]->event("__chosen__");
	}
	setChoice(choice);
	Motion *mot = mots[currentChoice];
	
	if (resetOnPlay && !mot->reset())
		return false;
	
	if (smooth)
	{
		if (accumulateRoot)
		{
			Reposition *repositioner = new Reposition(mot);
			//repositioner->setMaintainY(true);
			repositioner->setUpDirection(upDirection);
			repositioner->setMaintainUp(maintainUp);
			repositioner->setRotateAboutUp(rotateAboutUp);
			repositioner->setStartFromMotion(this, Piavca::Core::getCore()->getTime());
			mot = repositioner;
		}

		//Motion *oldmot = getMotion();
		float t1 = Piavca::Core::getCore()->getTime();
		float t2 = windowLength;
		MotionTransition *trans = new SavedFramesTransition(this, mot/*->clone()*/, t1, t2, windowLength);
		//SubMotion *remainder = new SubMotion();
		//remainder->setMotion(mot);
		//remainder->setStart(windowLength);
		// //remainder->setEnd(mot->getMotionLength() - windowLength);
		//mot = new Sequence(trans, remainder);
		mot = trans;
	};
	
	setMotion(mot);

	if (resetTime)
		setStartTime(Piavca::Core::getCore()->getTime());
	return true;
};