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
 * The Original Code is StdMotionCore.h.
 *
 * The Initial Developer of the Original Code is Marco (Mark) Gillies.
 * Portions created by the Initial Developer are Copyright (C) BT plc. 2004
 * All Rights Reserved.
 *
 * ***** END LICENSE BLOCK ***** */

#ifndef STD_MOTION_CORE_H
#define STD_MOTION_CORE_H

#include "PiavcaAPI/PiavcaDefs.h"

#include "PiavcaAPI/PiavcaCore.h"

namespace Piavca
{
class MotionImp;

	//! A core class with a factory method that creates motion objects based on the standard implementation.
	/*!
	 *	This is a subtype of the UCL avatar factory 
	 *	
	 */
    class PIAVCA_DECL StdMotionCore : public Core
	{
	protected:
		//! creates the motion implementation (it in fact creates a StandardMotionImp object)
		MotionImp *createMotionImp(tstring filename, bool facial, int flags, Motion *bsaePosture = NULL);
	public:
		StdMotionCore() {};
		virtual ~StdMotionCore() {};//Core::~Core();};		
	};

};


#endif //TD_MOTION_CORE_H
