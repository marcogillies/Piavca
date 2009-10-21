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
 * The Original Code is SequentialChoiceMotion.h.
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


#ifndef SEQUENTIAL_CHOICE_MOTION_H
#define SEQUENTIAL_CHOICE_MOTION_H

#include "ChoiceMotion.h"

namespace Piavca
{

//! A ChoiceMotion where the the choices are played sequentially one after the other
class SequentialChoiceMotion : public ChoiceMotion
{
	bool passEventsToChildren;
public:
	SequentialChoiceMotion():ChoiceMotion(), passEventsToChildren(true) {};
	SequentialChoiceMotion(const MotionVec &mpv):ChoiceMotion(mpv), passEventsToChildren(true){};
	SequentialChoiceMotion(const SequentialChoiceMotion &c):ChoiceMotion(c), passEventsToChildren(c.passEventsToChildren){};
	
	~SequentialChoiceMotion(){};

	virtual Motion *clone(){return new SequentialChoiceMotion(*this);};

	//! returns the name of the type
	Piavca::tstring getClassName(){return "SequentialChoiceMotion";};

	//! casts a motion to this type
	static SequentialChoiceMotion *castToThisType(Motion *m){return dynamic_cast<SequentialChoiceMotion *>(m);};

	//! sets the start time of the motion. Called when its loaded into an avatar.
	virtual void  setStartTime(float t);

	//! whether next events are passed on to the motions children first or not
	void setPassEventsToChildren(bool b)
	{	
		passEventsToChildren = b;
	}
	bool getPassEventsToChildren()
	{	
		return passEventsToChildren;
	}
	
	//! a generic function for setting parameters
	virtual bool setParameter(tstring paramName, tstring value);

	//! handles an event (plays the motion with the same name as the event)
	virtual void handleEvent(tstring ev);
	virtual bool canHandleEvent(tstring ev);

	//! gets the names of all events
	virtual std::vector<Piavca::tstring> getEventNames();
	
	virtual int makeChoice();
};

};

#endif //SEQUENTIAL_CHOICE_MOTION_H
