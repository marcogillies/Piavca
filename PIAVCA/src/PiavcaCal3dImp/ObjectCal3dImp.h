#ifndef OBJECT_DIVE_IMP_H
#define OBJECT_DIVE_IMP_H

#include "PiavcaAPI/ObjectImp.h"
#include "PiavcaAPI/Quat.h"
#include "PiavcaAPI/Vec.h"


namespace Piavca
{

//! the implemenataion class for the Objects on the Dive platform
/*!
 *	This is a subtype of the ObjectImp class and does all the
 *	actual work of the Object class. The platform independent Object
 *	interface class forwards all method calls to an object of this type.
 *	(via a ObjectImp pointer).
 */
class ObjectDiveImp : public ObjectImp{
public:
	//! a pointer to the Dive actor for the object
	actor *Actor;
	//! the root of the Object in the scene graph
	objid_t root_id;
	//! the current scale factor of the object
	Vec rootScale;

	//! private constructor means that the user cannot create it
	/*!
	 *	Must be created via a TaraObjectFactory object
	 */
	ObjectDiveImp():rootScale(1.0, 1.0, 1.0){};
public:

	//! destructor
	virtual ~ObjectDiveImp(){};

	//! given a UCLObject object get its implementation 
	static ObjectDiveImp *getObjectImp(Object *Object) 
	{
		ObjectDiveImp *diveimp = dynamic_cast<ObjectDiveImp *>(getObjectImpInternal(Object)); 
		if(diveimp)
			return diveimp;
		else
		{
			Piavca::Error(_T("Trying to use a non dive Object in dive"));
			return NULL;
		}
	};

	//! \name position and orientation
	//@{ 
	/*!
	 *	get or set the root position and orientation of the Object
	 */
	virtual void	setPosition		    (const Vec &Position);
	virtual Vec	    getPosition			();
	virtual void	setOrientation		(const Quat &Orientation);
	virtual Quat	getOrientation		();
	//@}

	//! scales the root by a non-uniform scale vector
	virtual void   scale (Vec scale);

	friend class PiavcaDiveCore;
};

};


#endif //OBJECT_DIVE_IMP_H
