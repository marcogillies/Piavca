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
 * The Original Code is RandomBlendLoop.h.
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


#ifndef RANDOM_BLEND_LOOP_H
#define RANDOM_BLEND_LOOP_H

#include "PiavcaAPI/LoopMotion.h"

namespace Piavca
{

//! A MultiMotionLoop which, instead of choosing one motion at a time, blends between a groups of motions
/*!
 *	The Motions to blend are chosen at random, as are the number of motions and the 
 *  weights.
 */
class RandomBlendLoop : public RandomTimingsLoop
{
	RandomBlend *randomblend;
public:
	//! pass in a vector of motions to be used.
	RandomBlendLoop(const MotionVec &mv, float endTime = -1.0, float interval = 0.01)
		:RandomTimingsLoop(NULL, endTime, interval)
	{
		randomblend = new RandomBlend(mv);
		setMotion(randomblend);
	};
	//! create an empty loop
	RandomBlendLoop(float endTime = -1.0, float interval = 0.01)
		:RandomTimingsLoop(NULL, endTime, interval)
	{
		randomblend = new RandomBlend;
		setMotion(randomblend);
	};
	RandomBlendLoop(const RandomBlendLoop &rbl)
		:RandomTimingsLoop(rbl)
	{
		randomblend = dynamic_cast<RandomBlend *>(getMotion());
	};
	~RandomBlendLoop(){};
	virtual Motion *clone(){return new RandomBlendLoop(*this);};

	virtual void addMotion(Motion *mot)
	{
		randomblend->addMotion(mot);
	};

	virtual void addMotion(Motion *mot, float weight)
	{
		randomblend->addMotion(mot, weight);
	};

	virtual void shift()
	{
		randomblend->shift();
	};
};

};

#endif //RANDOM_BLEND_LOOP_H
