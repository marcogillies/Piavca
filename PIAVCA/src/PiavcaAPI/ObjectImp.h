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
 * The Original Code is ObjectImp.h.
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

#ifndef OBJECT_IMP_H
#define OBJECT_IMP_H

#include "PiavcaDefs.h"
//#include "PiavcaCore.h"

#include "Quat.h"
#include "Vec.h"

namespace Piavca
{
	class PIAVCA_DECL Object;


//! the implemenataion class for the Objects
/*!
 *	Each platform has a concrete subtype of this class which actually does the 
 *	work of the Object class. The Object class is an interface class that contains
 *	a pointer to a ObjectImp object and forwards all method calls to this
 *	object. The object will be of the concrete type corresponding to the platform
 *	being used. 
 */
class ObjectImp{
protected:
	ObjectImp() {};

	//! The Object object that is the front end to this object
	Object *frontEnd;

	//! Given a Object object this returns its implementation 
	/*!
	 *	This is used by a similar method in the platform specific implementation
	 *	that is used to get the implementation in platform specific code
	 */
	static ObjectImp *getObjectImpInternal(Object *oobject);
public:

	//! destructor
	virtual ~ObjectImp() {};


	//! \name position and orientation
	//@{ 
	/*!
	 *	get or set the position and orientation of the Object
	 */
	virtual void	setPosition			(const Vec &Position) = 0;
	virtual Vec		getPosition			() = 0;
	virtual void	setOrientation		(const Quat &Orientation) = 0;
	virtual Quat	getOrientation		() = 0;
	//@}

	//! scales the object by a non-uniform scale vector
	virtual void   scale (Vec scale)=0;

	friend class Object;
	friend class Core;
};

};

#endif //OBJECT_IMP_H
