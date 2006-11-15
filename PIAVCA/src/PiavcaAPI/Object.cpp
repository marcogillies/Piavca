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

#include "ObjectImp.h"

#include "PiavcaError.h"
#include "PiavcaCore.h"
#include "Object.h"

using namespace Piavca;

Object::Object(const Object &av) 
{
	Piavca::Error(_T("trying to copy an Object, not allowed"));
};

const Object &Object::operator=(const Object &av) 
{
	Piavca::Error(_T("trying to assign an Object, not allowed")); 
	return (*this);
};

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
