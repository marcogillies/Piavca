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
 * The Original Code is Object.cpp.
 *
 * The Initial Developer of the Original Code is Marco (Mark) Gillies.
 * Portions created by the Initial Developer are Copyright (C) BT plc. 2004
 * All Rights Reserved.
 *
 * ***** END LICENSE BLOCK ***** */

#include "ObjectImp.h"

#include "PiavcaCore.h"
#include "Object.h"

using namespace Piavca;

// create an ObjectImp from the factory
void Object::initObject(	
			tstring objectId, 
			const Vec &Position, 
			const Quat &Orientation)
{
	Core::getCore()->initObject(this, objectId, Position, Orientation);
	if(imp)
	  {
	    imp->frontEnd = this;
	  }
};

// Given an Object object this returns its implementation 
/*
*	This is used by a similar method in the platform specific implementation
*	that is used to get the implementation in platform specific code
*/
ObjectImp *ObjectImp::getObjectImpInternal(Object *obj){return obj->imp;};
