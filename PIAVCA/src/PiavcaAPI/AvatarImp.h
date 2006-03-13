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
 * The Original Code is AvatarImp.h.
 *
 * The Initial Developer of the Original Code is Marco (Mark) Gillies.
 * Portions created by the Initial Developer are Copyright (C) BT plc. 2004
 * All Rights Reserved.
 *
 * ***** END LICENSE BLOCK ***** */

#ifndef AVATAR_IMP_H
#define AVATAR_IMP_H

//#include "Joint.h"
#include "PiavcaDefs.h"
//#include "PlatformDefs.h"

#include <vector>
using std::vector;


#include "Quat.h"
#include "Vec.h"
#include "PiavcaException.h"

#include "Motion.h"
#include "TimeCallback.h"

namespace Piavca
{
	class PIAVCA_DECL Avatar;

//! an exception that gets thrown when a type specific method is called on the wrong type of joint
class InvalidJointEndException : public CException
{
public:
	InvalidJointEndException(const tstring &jointName):CException(jointName + _PSTR(" does not have a known single end point\n")){}
};

//! the implemenataion class for the Avatars
/*!
 *	Each platform has a concrete subtype of this class which actually does the 
 *	work of the avatar class. The Avatar class is an interface class that contains
 *	a pointer to a AvatarImp object and forwards all method calls to this
 *	object. The object will be of the concrete type corresponding to the platform
 *	being used. 
 */
class AvatarImp{
protected:
	AvatarImp() {};

	//! The Avatar object that is the front end to this object
	Avatar *frontEnd;

	//! Given a Avatar object this returns its implementation 
	/*!
	 *	This is used by a similar method in the platform specific implementation
	 *	that is used to get the implementation in platform specific code
	 */
	static AvatarImp *getAvatarImpInternal(Avatar *avatar);

	/*! This is a function that does platform specific per-frame stuff
	 *  Called by timeStep
	 */
	virtual void	platformSpecific_timeStep (float time) = 0;
public:

	//! destructor
	virtual ~AvatarImp() {};

	//! \name Facial Animation Methods (based on morph target like system)
	//!@{
	virtual bool  setNeutralFacialExpression(tstring expressionName)=0;
	virtual bool  addFacialExpression(tstring expressionName)=0;
	virtual int   getFacialExpressionId(tstring expressionName)=0;
	virtual bool  setFacialExpressionWeight(int id, float weight, float timeInterval = 0.5)=0;
	virtual float getFacialExpressionWeight(int id)=0;
	virtual void  clearFacialExpressionWeights()=0;
	//virtual void  updateFacialExpressions(float time)=0;//! whether the joint is present in the avatar
	virtual bool isExpressionNull(int expressionId)const=0;
	virtual void updateFacialExpressions(){};
	
	//!@}


	//! \name Root position and orientation
	//@{ 
	/*!
	 *	get or set the root position and orientation of the avatar
	 */
	virtual void	setRootPosition			(const Vec &Position) = 0;
	virtual Vec		getRootPosition			() = 0;
	virtual void	setRootOrientation		(const Quat &Orientation) = 0;
	virtual Quat	getRootOrientation		() = 0;
	//@}

	//! creates a new joint
	/*!
	 *	It will only succeed if there is a piece of geometry corresponding to the name
	 *	if not it returns false
	 */
	virtual bool createJoint(tstring jointName)=0;

	//! returns the ID of the parent of the joint in the joint heirarchy (or a negative value if it doesn't exist
	virtual int getParent(int jointId)const =0;
	//! whether a joint is actually present in the avatar
	virtual bool isNull(int jointId)const=0;

	//! get the name of the joint corresponding to an ID
	virtual const tstring getJointName(int jointId)=0;

	//! check whether the joint has been changed by user input
	virtual bool hasChanged(int jointId)=0;
	//! clears the changed flag for the joint
	virtual void clearChange(int jointId)=0;

	//! set the value of the orientation of a joint
	/*!
	 *	The joint is specified via an ID.
	 *	This can be done in various coordinate systems, 
	 *	jointlocal is the coordante space of the joint (default)
	 *	local is the space of the avatar root
	 *	world is the world coordinates
	 *	using the second two is likely to be much less efficient
	 */
	virtual void	setJointOrientation		(int jointId, const Quat &val, jointCoord worldCoord = JOINTLOCAL_COORD) = 0;
	//! get the orientation of a joint
	/*!
	 *	The joint is specified via an ID.
	 *	This can be done in various coordinate systems, 
	 *	jointlocal is the coordante space of the joint (default)
	 *	local is the space of the avatar root
	 *	world is the world coordinates
	 *	using the second two is likely to be much less efficient
	 */
	virtual Quat	getJointOrientation		(int jointId, jointCoord worldCoord = JOINTLOCAL_COORD) = 0;
	
	//! get the current position of the start of the joint
	/*!
	 *	calculated from the root position and joint angles by forward kinematics
	 *	This can be done in various coordinate systems, 
	 *	jointlocal is the coordante space of the joint 
	 *	local is the space of the avatar root (default)
	 *	world is the world coordinates
	 */
	virtual Vec		getJointBasePosition	(int jointId, jointCoord worldCoord = LOCAL_COORD) = 0;

	//! scales the root by a non-uniform scale vector
	virtual void   scaleRoot (Vec scale)=0;
	//! scales a joint by a non-uniform scale vector
	virtual void   scaleJoint (int jointId, Vec scale)=0;

	friend class Avatar;
	friend class Piavca::Core;
};

};

#endif //AVATAR_IMP_H
