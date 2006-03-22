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
 * The Original Code is SelfBlend.h.
 *
 * The Initial Developer of the Original Code is Marco (Mark) Gillies.
 * Portions created by the Initial Developer are Copyright (C) BT plc. 2004
 * All Rights Reserved.
 *
 * ***** END LICENSE BLOCK ***** */

#ifndef SELF_BLEND_H
#define SELF_BLEND_H

//#include "Motion.h"
//#include "PiavcaCore.h"
#include "SequentialBlend.h"

namespace Piavca
{
	//! A SequentialBlend motion manipuator that blends a motion into itself.
	/*!
	 *  It contains a method reblend which when called will save the motions current state 
	 *  and then starts blending the motion in from the start. This is used in implementing the 
	 *	loop motion class but has other uses. For example if there is a parameterised motion and 
	 *	you want to change the parameters and blend the new motion in smoothly use a selfBlend.
	 *  and call reblend just before changing the parameters.
	 */
    class PIAVCA_DECL SelfBlend : public SequentialBlend
	{
	public:
		/*! pass in the motion to be blended and an optional blend interval */
	    SelfBlend(Motion *mot, float interval = 0.2);
		SelfBlend(const SelfBlend &sb):SequentialBlend(sb){};
	
		virtual Motion *clone(){return new SelfBlend(*this);};
	    
		//! saves the current state of the motion and start blending the motion back into that from the start
	    void reblend();
		//! saves the state of the motion at time and start blending the motion back into that from the start
	    virtual void reblend(float time);
		//! sets the motion to be blended in
		virtual void setMotion(Motion *mot);
	};
};


#endif //SELF_BLEND_H
