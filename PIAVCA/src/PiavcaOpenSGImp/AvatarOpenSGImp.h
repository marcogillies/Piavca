/* LICENCE BLOCK
AvatarCal3DImp.h
Copyright (C) 2005 Marco (Mark) Gillies

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef AVATAR_OPENSG_IMP_H
#define AVATAR_OPENSG_IMP_H

#include <utility>
#include <map>
using std::map;
#include <vector>
using std::vector;

#include <cal3d/cal3d.h>

//#include "PlatformDefs.h"

#include "PiavcaAPI/AvatarImp.h"
#include "PiavcaAPI/Quat.h"
#include "PiavcaAPI/Vec.h"
#include "PiavcaCal3dImp/AvatarCal3DImp.h"
//#include "JointIteratorTaraImp.h"

#include "OSGCharacter.h"

namespace Piavca
{

//! the implemenataion class for the Avatars on the OpenSG platform
/*!
 *	This subtypes a lot of the AvatarCa3dImp functionality, but works via
 *  an OpenSG Cal3d node
 */
class PIAVCA_DECL AvatarOpenSGImp : public AvatarImp {
protected:
	osg::CharacterPtr charac;
	osg::NodePtr osg_node;

	// a look up table to map between Piavca joint id's and Cal3D joint indexes
	vector <JointHolder> joints;
	// a look up table to map between Piavca expression id's and Cal3D morph target indexes
	vector <FacialExpressionHolder> expressions;
public:	
	//! private constructor means that the user cannot create it
	/*!
	 *	Must be created via a TaraAvatarFactory object
	 */
	AvatarOpenSGImp(osg::CharacterPtr character, osg::NodePtr node, bool bailOnMissedJoints, const Vec &Position, const Quat &Orientation);

	//! loads all textures from file
	void loadTextures();

	/*! This is a function that does platform specific per-frame stuff
	 *  Called by timeStep
	 */
	virtual void	platformSpecific_timeStep (float time);
	Bound bb, base_bb;
	bool bb_dirty_flag;
public:

	//! destructor
	virtual ~AvatarOpenSGImp(){};

	//! given a UCLAvatar object get its implementation 
	static AvatarOpenSGImp *getAvatarImp(Avatar *avatar) ;

	//! hides a part of the avatars body so it is not rendered
	virtual void hideBodyPart(tstring partname);
	//! shows a part of the avatars body so it is rendered
	virtual void showBodyPart(tstring partname);

	//! \name Facial Animation Methods (based on morph target like system)
	//!@{
	virtual bool  setNeutralFacialExpression(tstring expressionName);
	virtual bool  addFacialExpression(tstring expressionName);
	virtual int   getFacialExpressionId(tstring expressionName);
	virtual bool  setFacialExpressionWeight(int id, float weight, float timeInterval = 0.5);
	virtual float getFacialExpressionWeight(int id);
	virtual void  clearFacialExpressionWeights()
	{
	    for(int i=0; i< (int)expressions.size(); i++)
	      setFacialExpressionWeight(i, 0.0);
	};
	virtual void updateFacialExpressions();
	//virtual void  updateFacialExpressions(float time);
	//! whether the expression is present in the avatar
	bool isExpressionNull(int expressionId)const
	{
		expressionId = -expressionId;
		return (expressionId < 0 || expressionId >= (int)expressions.size() || expressions[expressionId].morphtargetId < 0);
	};
	//!@}

	//! \name Root position and orientation
	//@{ 
	/*!
	 *	get or set the root position and orientation of the avatar
	 */
	virtual void	setRootPosition			(const Vec &Position);
	virtual Vec		getRootPosition			();
	virtual void	setRootOrientation		(const Quat &Orientation);
	virtual Quat	getRootOrientation		();
	//@}

	//! creates a new joint
	/*!
	 *	It will only succeed if there is a piece of geometry corresponding to the name
	 *	if not it returns false
	 */
	bool createJoint(tstring JointName);

	//! whether a joint is actually present in the avatar
	bool isNull(int jointId)const
	{
		return (jointId < 0 || jointId >= (int)joints.size() || joints[jointId].cal3dId < 0);
	};

	int getParent(int jointId)const;

	//! get the name of the joint corresponding to an iterator
	const tstring getJointName(int jointId);

	//! check whether the joint iterator has been changed by user input
	bool hasChanged(int jointId);
	//! clears the changed flag for the joint
	void clearChange(int jointId);

	//! set the value of the orientation of a joint
	/*!
	 *	The joint is specified via an itertor.
	 *	This can be done in various coordinate systems, 
	 *	jointlocal is the coordante space of the joint (default)
	 *	local is the space of the avatar root
	 *	world is the world coordinates
	 *	using the second two is likely to be much less efficient
	 */
	virtual void	setJointOrientation		(int jointId, const Quat &val, jointCoord worldCoord = JOINTLOCAL_COORD);
	//! get the orientation of a joint
	/*!
	 *	The joint is specified via an itertor.
	 *	This can be done in various coordinate systems, 
	 *	jointlocal is the coordante space of the joint (default)
	 *	local is the space of the avatar root
	 *	world is the world coordinates
	 *	using the second two is likely to be much less efficient
	 */
	virtual Quat	getJointOrientation		(int jointId, jointCoord worldCoord = JOINTLOCAL_COORD);
	
	//! set the value of the position of a joint
	/*!
	 *	The joint is specified via an ID.
	 *	This can be done in various coordinate systems, 
	 *	jointlocal is the coordante space of the joint (default)
	 *	local is the space of the avatar root
	 *	world is the world coordinates
	 *	using the second two is likely to be much less efficient
	 */
	virtual void	setJointPosition	(int jointId, const Vec &val, jointCoord worldCoord = JOINTLOCAL_COORD);
	
	//! get the current position of the start point of the joint
	/*!
	 *	calculated from the root position and joint angles by forward kinematics
	 *	This can be done in various coordinate systems, 
	 *	jointlocal is the coordante space of the joint 
	 *	local is the space of the avatar root (default)
	 *	world is the world coordinates
	 */
	virtual Vec		getJointBasePosition	(int jointId, jointCoord worldCoord = LOCAL_COORD);
	
	//! scales the root by a non-uniform scale vector
	virtual void   scaleRoot (Vec scale);
	//! scales a joint by a non-uniform scale vector
	virtual void   scaleJoint (int jointId, Vec scale);


	//! to be called before the rendering state 
	/*!
	 *  It is used to swap the render buffers
	 */
	virtual void prerender()
	{
		
	};

	//! does a GL Render of the character
	virtual void render();

	//! get a bounding box in local coordinates
	virtual Bound getBoundBox();

	//! get a bounding box of the avatar in its base pose in local coordinates
	virtual Bound getBaseBoundBox();


	friend class PiavcaOpenSGCore;
};

};


#endif //AVATAR_OPENSG_IMP_H
