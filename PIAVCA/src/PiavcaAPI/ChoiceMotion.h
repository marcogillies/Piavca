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

#include "MultiMotionCombiner.h"
#include "ScaleMotionSpeed.h"

namespace Piavca
{

//! a MultiMotionCombiner where the client can choose which motion is played
class ChoiceMotion : public MultiMotionCombiner
{
	int currentChoice;
public:
	ChoiceMotion():currentChoice(0){};
	//! pass in a vector of motions to be used.
	ChoiceMotion(const MotionVec &mpv)
		:MultiMotionCombiner(mpv), currentChoice(0)
	{
	};
	ChoiceMotion(const ChoiceMotion &cl)
		:MultiMotionCombiner(cl), currentChoice(cl.currentChoice){};
	~ChoiceMotion(){};
	virtual Motion *clone(){return new ChoiceMotion(*this);};


	//! sets which motion is currently being played
	void setCurrentChoice(int i)
	{
		if(i < 0 || i >= static_cast<int>(mots.size()))
			Piavca::Error(_T("Illegal motion choice"));
		currentChoice = i;
	};
	//! sets which motion is currently being played (by name)
	void setCurrentChoice(tstring name)
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
	
	//! handles an event (plays the motion with the same name as the event)
	void event(tstring ev)
	{
		for(int i = 0; i < int(mots.size()); i++)
			if (mots[i]->getName() == ev)
			{
				currentChoice = i;
				reset();
				break;
			}
		MultiMotionCombiner::event(ev);
	}

	//! called each time around the loop
	/*!
	 * It can be called by the client to interrupt the current motion.
	 */
	virtual void reset()
	{
		if(mots.size() > 0)
			setMotion(mots[currentChoice]);
	};
};

};

#endif //CHOICE_MOTION_H
