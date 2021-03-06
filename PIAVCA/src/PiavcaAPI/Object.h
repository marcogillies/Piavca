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
 * The Original Code is Object.h.
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


#ifndef OBJECT_H
#define OBJECT_H

#include "PiavcaDefs.h"
#include "ObjectImp.h"
//#include "PiavcaCore.h"

#include <vector>
using std::vector;

#include "Vec.h"
#include "Quat.h"
#include "MathsUtils.h"

namespace Piavca {

class Core;

//! A class for representing inanimate objects in PIAVCA.
/*!
 *	This works much like an avatar, except its only got a root and
 *  not joints/facial exprssions.
 */
class PIAVCA_DECL Object{
	
protected:
	
	//! The implementation class, all methods get forwarded to it
	ObjectImp *imp;

	//! the name of the character
	tstring name;
	//! initialise a Avatar in a platform dependent way using the core
	void initObject(tstring objectId, const Vec &Position, const Quat &Orientation);
private:
	//! \name you can't copy them
	//{@
	//! copy constructor
	Object(const Object &av);
	//! assignment
	const Object &operator=(const Object &av);
	//@}
	
	//! destructor can only be called by the core, use Core::removeAvatar to delete an avatar
	virtual ~Object() 
	{
		delete imp; 
	};
public:
	//! create an object
	/*!
	 *	The object needs to be initialised with an implementation. The 
	 *	type of the implementation depends on the platform and so it 
	 *	cannot be created directly in platform independant code. To 
	 *	get around this it is created by a static factory method in the 
	 *	which itself uses the Piavca::Core class and its platform dependent implementation 
	 *	to create the implementation of the avatar. The constructor needs an identifier
	 *	string that it uses to find platform specific data needed to create
	 *	the avatar, for example the mesh file. The user can also pass in 
	 *	a position and orientation for the object.
	 */
	Object(tstring objectId, 
		   const Vec &Position = Vec(0.0, 0.0, 0.0), 
		   const Quat &Orientation = Quat(1.0, 0.0, 0.0, 0.0))
		: name(objectId)
	{
		initObject(objectId, Position, Orientation);
	};


	//! get the name of the avatar
	tstring getName(){return name;};
	//! set the name of the avatar
	tstring setName(tstring newName){return name = newName;};

	//! \name position and orientation
	//@{ 
	/*!
	 *	get or set the root position and orientation of the avatar
	 */
	void	setPosition			(const Vec &Position) {imp->setPosition(Position);};
	Vec		getPosition			() {return imp->getPosition();};
	void	setOrientation		(const Quat &Orientation) {imp->setOrientation(Orientation);};
	//! set the orientation from an angle in radians (assumed to be about the verticle)
	void	setAngle			(float angle) {imp->setOrientation(Quat(angle, Vec(0.0, 1.0, 0.0)));};
	//! set the orientation from an angle in degrees (assumed to be about the verticle)
	void	setAngleDeg			(float angle) {imp->setOrientation(Quat(degToRad(angle), Vec(0.0, 1.0, 0.0)));};
	Quat	getOrientation		() {return imp->getOrientation();};
	//@}

	//! scales the root by a non-uniform scale vector
	void   scale (Vec scale){imp->scale(scale);};

	friend class ObjectImp;
	friend class Piavca::Core;

};

};


#endif //OBJECT_H
