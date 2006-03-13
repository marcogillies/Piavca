#ifndef MYENGINE_PIAVCA_CORE_H
#define MYENGINE_PIAVCA_CORE_H

#include "PiavcaAPI/PiavcaDefs.h"

// a hypothetical scene graph based graphics engine
namespace MyEngine{

class SceneGraph;
class TransformNode;

}

#include "../PiavcaAPI/Vec.h"
#include "../PiavcaAPI/Quat.h"
#include "PiavcaAPI/Avatar.h"
#include "StdMotionImp/StdMotionCore.h"

namespace Piavca
{
class AvatarImp;

	//! The Implementation of the core object
	/*!
	 *	This is a subtype of the Piavca::Core class. It also subtypes the StdMotionCore as
	 *	it uses the standard motion implementation
	 */
    class MyEnginePiavcaCore : public StdMotionCore
	{

		//! A pointer to the scene graph in which the avatars are to be created.
		MyEngine::SceneGraph *_graph;

	protected:
		//! Creates an avatar implementation (actually creates a MyEngineAvatarImp object)
		AvatarImp *createAvatarImp(tstring avatarId, bool bailOnMissedJoints, const Vec &Position, const Quat &Orientation)
		{
			//create a new Avatar implementation
			MyEngineAvatarImp *avatarImp = new MyEngineAvatarImp;
			// create an array of joints with one for each joint Id
			avatarImp->joints.assign(getMaxJointId()+1, NULL);

			// find the root transformation node of the avatar 
			// (in other implementations I assume its got the same name as the avatarId)
			avatarImp->rootTransform =  _graph->FindTransformByName(avatarId);

			// Its very important at this stage that none of the transform nodes 
			// used as joints have rotation set to no zero values in the neutral pose
			// in one implementation I've gone through the node here and pushed any 
			// non zero rotations down the heirarchy

			for(MyEngine::Transform *trans = /* each child of avatarImp->rootTransform*/)
			{
				// see if the transform corresponds to a joint
				// by checking the name
				int jointId = getJointId(trans->name);
				// if it is set that joint to be equal to trans
				if(jointId > 0)
					avatarImp->joints[jointId] = JointHolder(trans);
			}

			// set the root position and orientation
			avatarImp->setRootPosition(Position);
			avatarImp->setRootOrientation(Orientation);	
		};
	public:
		//! The constructor takes a pointer to the scene graph in which the avatars are to be created.
		MyEnginePiavcaCore(MyEngine::SceneGraph *graph):_graph(graph){};
		virtual ~MyEnginePiavcaCore() {StdMotionCore::~StdMotionCore();};

		//! get the current time
		float getTime()
		{
			// get the current time in seconds as a floating point number
			// implement is some suitable platform specific way
		};
	};

};


#endif //MYENGINE_PIAVCA_CORE_H