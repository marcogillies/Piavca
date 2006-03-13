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
 * The Original Code is TimeCallback.h.
 *
 * The Initial Developer of the Original Code is Marco (Mark) Gillies.
 * Portions created by the Initial Developer are Copyright (C) BT plc. 2004
 * All Rights Reserved.
 *
 * ***** END LICENSE BLOCK ***** */

#ifndef TIME_CALLBACK_H
#define TIME_CALLBACK_H

#include "PiavcaDefs.h"

namespace Piavca
{
	class PIAVCA_DECL Avatar;
	class PIAVCA_DECL Core;
	
	//! A callback that is called by the API every frame, the user writes code by creating a subclass of the callback
	/*!
	 *	The user can add data and implement the changeTime method (which is the one that is called everyframe).
	 *	The callback system is currently under developement
	 */
	class PIAVCA_DECL TimeCallback
	{
	  tstring name;
	public:
		TimeCallback(tstring _name):name(_name){};
		virtual ~TimeCallback(){};

		tstring getName (){return name;};

		//! This is a setup method for the callback
		/*!
		 *	It's called when the callback is registered
		 */
		virtual void init(Piavca::Core *core) = 0;

		//! implement this to make the callback do things
		/*!
		 *	It's called every frame with by the API
		 */
		virtual void timeStep(Piavca::Core *core, float time) = 0;
	};
	
	//! A callback that is called by the API every frame on an avatar
	/*!
	 *	It is very similar to the TimeCallback class but the changeTime method takes an avatar
	 *	which can be updated.
	 */
	class PIAVCA_DECL AvatarTimeCallback
	{
	  tstring name;
	public:
		AvatarTimeCallback(tstring _name):name(_name){};
		virtual ~AvatarTimeCallback(){};

		tstring getName (){return name;};

		//! This is a setup method for the callback
		/*!
		 *	It's called when the callback is registered
		 */
		virtual void init(Avatar *avatar) = 0;

		//! implement this to make the callback do things
		/*!
		 *	It's called every frame with by the API which passes in the avatar
		 *	to which the callback is attatched
		 */
		virtual void timeStep(Avatar *avatar, float time) = 0;
	};

};

#endif //TIME_CALLBAC_H
