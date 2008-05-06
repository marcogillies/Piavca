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
	    SelfBlend(Motion *mot=NULL, float interval = 0.2);
		SelfBlend(const SelfBlend &sb):SequentialBlend(sb){};
	
		virtual Motion *clone(){return new SelfBlend(*this);};

		//! returns the name of the type
		Piavca::tstring getClassName(){return "SelfBlend";};

		//! casts a motion to this type
		static SelfBlend *castToThisType(Motion *m){return dynamic_cast<SelfBlend *>(m);};
	    
		virtual void reset();

		//! saves the current state of the motion and start blending the motion back into that from the start
	    void reblend();
		//! saves the state of the motion at time and start blending the motion back into that from the start
	    virtual void reblend(float time);
		//! sets the motion to be blended in
		virtual void setMotion(Motion *mot);
		//! sets the motion to be blended in
		virtual Motion *getMotion();
	};
};


#endif //SELF_BLEND_H
