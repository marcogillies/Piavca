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
 * The Original Code is RandomAddLoop.h.
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


#ifndef RANDOM_ADD_LOOP_H
#define RANDOM_ADD_LOOP_H

//#include "MultiMotionLoop.h"
#include "PiavcaAPI/MotionAdder.h"
#include "ScaleMotion.h"

namespace Piavca
{

//! A MultiMotionLoop which, instead of choosing one motion at a time, adds together a groups of motions
/*!
 *	The Motions to blend are chosen at random, as are the number of motions.
 *  Each of the motions is scaled by a random ammount before being added.
 */
class RandomAddLoop : public RandomTimingsLoop
{
	RandomAdd *randomadd;
public:
	RandomAddLoop()
	{
		randomadd = new RandomAdd();
		setMotion(randomadd);
	};
	//! pass in a vector of motions to be used.
	RandomAddLoop(const MotionVec &mv, float endTime = -1.0, float interval = 0.01)
		:RandomTimingsLoop(NULL, endTime, interval)
	{
		randomadd = new RandomAdd(mv);
		setMotion(randomadd);
	};
	RandomAddLoop(const RandomAddLoop &rbl)
		:RandomTimingsLoop(rbl)
	{
		randomadd = dynamic_cast<RandomAdd *>(rbl.randomadd->clone());
	};
	~RandomAddLoop(){};
	
	virtual Motion *clone(){return new RandomAddLoop(*this);};

	//! returns the name of the type
	Piavca::tstring getClassName(){return "RandomAddLoop";};

	//! casts a motion to this type
	static RandomAddLoop *castToThisType(Motion *m){return dynamic_cast<RandomAddLoop *>(m);};

	virtual void addMotion(Motion *mot)
	{
		randomadd->addMotion(mot);
	};

	virtual void shift()
	{
		randomadd->shift();
	};

	virtual void reblend(float time)
	{
		shift();
		RandomTimingsLoop::reblend(time);
	}
};

};

#endif //RANDOM_ADD_LOOP_H
