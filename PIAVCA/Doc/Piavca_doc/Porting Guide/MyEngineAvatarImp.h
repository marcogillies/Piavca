#ifndef MYENGINE_PIAVCA_IMP_H
#define MYENGINE_PIAVCA_IMP_H


#include "PiavcaAPI/PiavcaDefs.h"

// a hypothetical scene graph based graphics engine
namespace MyEngine{

class SceneGraph;
class TransformNode;

}

#include "PiavcaAPI/PiavcaDefs.h"
#include "PiavcaAPI/AvatarImp.h"
#include "PiavcaAPI/Quat.h"
#include "PiavcaAPI/Vec.h"

namespace Piavca
{
class Motion;


// A class to hold joint information
// I use a class to hold the transform corresponding to the node 
// in case there is any other data I want to hold with it
struct JointHolder
{
	// the transform node corresponding to the joint
	MyEngine::TransformNode *trans;
	// any other data can go here
	JointHolder():trans(NULL) {};
};
//! the implemenataion class for the Avatars on the MyEngine platform
/*!
 *	This is a subtype of the AvatarImp class and does all the
 *	actual work of the avatar class. The platform independent UCLAvatar
 *	interface class forwards all method calls to an object of this type.
 *	(via a AvatarImp pointer).
 */
class MyEngineAvatarImp : public AvatarImp{
	// the root of the avatar in the scene graph
	MyEngine::TransformNode *rootTransform;
	// a lookup table for the joints 
	vector <JointHolder> joints;

	//! private constructor means that the user cannot create it
	/*!
	 *	Must be created via a MyEnginePiavcaCore object
	 */
	MyEngineAvatarImp(){};
public:

	//! destructor
	virtual ~MyEngineAvatarImp(){};

	//! given an Avatar object get its implementation 
	// this is useful if you want to add platform specific functionality to an avatar
	static MyEngineAvatarImp *getAvatarImp(Avatar &avatar) {return dynamic_cast<MyEngineAvatarImp *>(getAvatarImpInternal(avatar));};

	//! \name Root position and orientation
	//@{ 
	/*!
	 *	get or set the root position and orientation of the avatar
	 */
	virtual void	setRootPosition			(const Vec &Position)
	{
		rootTransform->setPosition(Position.X(),Position.Y(),Position.Z());		
	};
	virtual Vec		getRootPosition			()
	{
		MyEngine::Vec p = rootTransform->getPosition();
		return Vec(p[0], p[1], p[2]);
	};
	virtual void	setRootOrientation		(const Quat &Orientation)
	{
		float angle; Vec axis;
		Orientation.getAngleAxis(angle, axis);
		
		rootTransform->setRotationAngle(angle);
		rootTransform->setRotationAxis(axis.X(). axis.Y(). axis.Z());
	};
	virtual Quat	getRootOrientation		()
	{
		MyEngine::Vec axis = rootTransform->getRotationAxis();
		float angle = rootTransform->getRotationAngle();
		return Quat(angle, Vec(axis[0], axis[1], axis[2]));
	};
	//@}

	//! creates a new joint
	/*!
	 *	It will only succeed if there is a piece of geometry corresponding to the name
	 *	if not it returns false
	 */
	bool createJoint(tstring JointName)
	{
		int id = Core::getCore()->getJointId(JointName);
		if(id > 0)
		{
			joints[id].trans = //get transform that is a child of the root transform and called JointName
			if(joints[id].trans)
				return true;
		}
		return false;
	};

	//! returns the ID of the parent of the joint in the joint heirarchy (or a negative value if it doesn't exist
	int getParent(int jointId)const 
	{
		// get the parent joint Id
		// can either be done by searching the scene graph or 
		// storing the ID of the parent in the JointHolder struct of each joint
	};
	//! whether a joint is actually present in the avatar
	bool isNull(int jointId)const{return (jointId < 0 || jointId >= joints.size() || joints[jointId].trans == NULL);};

	//! get the name of the joint corresponding to an iterator
	const tstring &getJointName(int jointId)
	{
		//get the name of the joint, e.g.
		joints[id].trans->getName();
	};

	//! check whether the joint iterator has been changed
	// If the underlying engine has changed the avatar in anyway and wants to notify 
	// Piavca code about it return true. For example I implemented a picking function 
	// in the Tara implementation where the user could click on an avatars joint drag it around. 
	// This let the piavca code know that this had happened. The clearChange method lets the 
	// engine know that the change has been dealt with
	bool hasChanged(int jointId){return false};
	//! clears the changed flag for the joint
	void clearChange(int jointId){};

	//! set the value of the orientation of a joint
	/*!
	 *	The joint is specified via an ID.
	 *	This can be done in various coordinate systems, 
	 *	jointlocal is the coordante space of the joint (default)
	 *	local is the space of the avatar root
	 *	world is the world coordinates
	 *	using the second two is likely to be much less efficient
	 */
	virtual void	setJointOrientation		(int jointId, const Quat &val, jointCoord worldCoord = JOINTLOCAL_COORD)
	{
		float angle; Vec axis;
		val.getAngleAxis(angle, axis);
		if( worldCoord = JOINTLOCAL_COORD)
		{
			joints[jointId].trans->setRotationAxis(axis.X(), axis.Y(), axis.Z());
			joints[jointId].trans->setRotationAngle(angle);
		}
		else
		{
			// a bit more complex, set in their world coordinates or relative to the root
		}
	};
	//! get the orientation of a joint
	/*!
	 *	The joint is specified via an ID.
	 *	This can be done in various coordinate systems, 
	 *	jointlocal is the coordante space of the joint (default)
	 *	local is the space of the avatar root
	 *	world is the world coordinates
	 *	using the second two is likely to be much less efficient
	 */
	virtual Quat	getJointOrientation		(int jointId, jointCoord worldCoord = JOINTLOCAL_COORD)
	{
		// pretty much as above	
	};
	
	//! get the current position of the start point of the joint
	/*!
	 *	calculated from the root position and joint angles by forward kinematics
	 *	This can be done in various coordinate systems, 
	 *	jointlocal is the coordante space of the joint 
	 *	local is the space of the avatar root (default)
	 *	world is the world coordinates
	 */
	virtual Vec		getJointBasePosition	(int jointId, jointCoord worldCoord = LOCAL_COORD)
	{
		// in the joints own coordinates this is [0, 0, 0]
		// for the other coordinates you need to transform into the appropriate
		// coordinate frame
	};

	friend class MyEnginePiavcaCore;
};

};


#endif //MYENGINE_AVATAR_IMP_H