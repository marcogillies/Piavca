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
		virtual void init(Core *core) = 0;

		//! implement this to make the callback do things
		/*!
		 *	It's called every frame with by the API
		 */
		virtual void timeStep(Core *core, float time) = 0;
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
