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
 * The Original Code is ChoiceLoopMotion.h.
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


#ifndef CHOICE_LOOP_MOTION_H
#define CHOICE_LOOP_MOTION_H

#include "MultiMotionLoop.h"
#include "ScaleMotionSpeed.h"

namespace Piavca
{

//! a MultiMotionLoop where the client can choose which motion is played
class ChoiceLoopMotion : public RandomTimingsLoop
{
	ChoiceMotion *choicemotion;
public:
	ChoiceLoopMotion():RandomTimingsLoop()
	{
		choicemotion = new ChoiceMotion();
		setMotion(choicemotion);
	};
	//! pass in a vector of motions to be used.
	ChoiceLoopMotion(const MotionVec &mpv, float endTime = -1.0, float interval = 0.01)
		:RandomTimingsLoop(NULL, endTime, interval)
	{
		choicemotion = new ChoiceMotion(mpv);
		setMotion(choicemotion);
	};
	ChoiceLoopMotion(const ChoiceLoopMotion &cl)
		:RandomTimingsLoop(cl)
	{
		choicemotion = dynamic_cast<ChoiceMotion *>(getMotion());
	};
	~ChoiceLoopMotion(){};
	
	virtual Motion *clone(){return new ChoiceLoopMotion(*this);};

	//! returns the name of the type
	Piavca::tstring getClassName(){return "ChoiceLoopMotion";};

	//! casts a motion to this type
	static ChoiceLoopMotion *castToThisType(Motion *m){return dynamic_cast<ChoiceLoopMotion *>(m);};


	//! sets which motion is currently being played
	void setCurrentChoice(int i)
	{
		choicemotion->setCurrentChoice(i);
	};
	//! sets which motion is currently being played (by name)
	void setCurrentChoice(tstring name)
	{
		choicemotion->setCurrentChoice(name);
	};

	virtual void addMotion(Motion *mot)
	{
		choicemotion->addMotion(mot);
	};
};

};

#endif //CHOICE_LOOP_MOTION_H
