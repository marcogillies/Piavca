
/* LICENCE BLOCK
AvatarCal3DImp.cpp
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

//#ifdef PIAVCA_DLL
//#define PIAVCA_EXPORT __declspec( dllimport ) 
//#else
//#define PIAVCA_EXPORT
//#endif

#include "AvatarOpenSGImp.h"

#include "PiavcaAPI/Avatar.h"
#include "PiavcaAPI/Motion.h"
#include "PiavcaAPI/PiavcaCore.h"
#include "StdMotionImp/StdMotionImp.h"
#include "PiavcaAPI/Vec.h"
#include "PiavcaAPI/Quat.h"

// hack to make everything work with both cal3d 10 and 11
//#ifndef CAL_REF_PTR_H
//typedef CalCoreMesh *CalCoreMeshPtr;
//#define get_pointer(x) (x)
//#endif
//
//
//#ifdef _WIN32
//#include <windows.h>
//#endif
//
//#if defined(__APPLE__)
//	#include <OpenGL/gl.h>
//#else
//	#include <GL/gl.h>
//#endif

#include <string>

using namespace Piavca;

#include <assert.h>
#include <algorithm>
using std::cout;
using std::endl;

#include "OSGCharacterModel.h"
//#include "OSGCharacterBase.inl"


AvatarOpenSGImp *AvatarOpenSGImp::getAvatarImp(Avatar *avatar) 
{
	AvatarOpenSGImp *OpenSGimp = dynamic_cast<AvatarOpenSGImp *>(getAvatarImpInternal(avatar)); 
	if(OpenSGimp)
		return OpenSGimp;
	else
	{
		Piavca::Error(_T("Trying to use a non OpenSG avatar in OpenSG"));
		return NULL;
	}
};

AvatarOpenSGImp::AvatarOpenSGImp(osg::CharacterPtr character, osg::NodePtr node, bool bailOnMissedJoints, const Vec &Position, const Quat &Orientation)
: AvatarImp(), charac(character), osg_node(node)
{
	
	std::cout << "start of the AvatarOpenSGimp constructor\n";
	expressions.assign((-Piavca::Core::getCore()->getMaxExpressionId())+1, FacialExpressionHolder());

	if (charac == NULL) return;

	// if there are any joints in the Cal3d Skeleton that don't already exist in 
	// Piavca add them
	osg::CharacterModelPtr model = charac->getModel();
	osg::MFString bone_names = model->getBoneNames();
   
	int i;
	for(int i = 0; i < (int) bone_names.size(); i++)
	{
		int jointid = Piavca::Core::getCore()->getJointId(StringToTString(bone_names[i]));
		if (jointid == Piavca::Core::nullId)
		{
			StringVector jointNames;
			if (i == 0)
			{
				//std::cout << "ROOT JOINT " <<  bone_names[i] << std::endl;
				jointNames.push_back(_T("Root Orientation"));
			}
			jointNames.push_back(StringToTString(bone_names[i]));
			//std::cout << "Adding Joint "<< i << ": " << bone_names[i] << std::endl;
			Piavca::Core::getCore()->addJointNameSet(jointNames);
		}	
	}
	joints.assign(Piavca::Core::getCore()->getMaxJointId()+1, JointHolder());
		
	//std::cout << "looking for joints\n";
	for(int i = 0; i < (int) bone_names.size(); i++)
	{
		int jointid = Piavca::Core::getCore()->getJointId(StringToTString(bone_names[i]));
		if (jointid != Piavca::Core::nullId)
		{
			joints[jointid].cal3dId = i;
			joints[jointid].name = StringToTString(bone_names[i]);
		}
	}

	
	// find the parents of each joint
	CalCoreModel *calModel = model->getCalCoreModel();
	CalCoreSkeleton *skel = calModel->getCoreSkeleton();
	for(i = 0; i < (int) joints.size(); i++)
	{	  
		if(joints[i].cal3dId < 0) continue;
		CalCoreBone *corebone = skel->getCoreBone(joints[i].cal3dId);
		int parentId = corebone->getParentId();
		for(int j = 0; j < (int) joints.size(); j++)
			if(joints[j].cal3dId == parentId)
			{
				joints[i].parent = j;
				break;
			}
	}

   //platformSpecific_timeStep (Piavca::Core::getCore()->getTime());
   base_bb = getBoundBox();
   std::cout << "at end of OpenSGAvatar constructor\n";

	/* need to include morphtargets
		else if(strKey == "morphtarget")
		{
			std::string strFilename = strPath + strData;
			std::cout << "Loading mesh as morph target '" << strFilename << "'..." << std::endl;
			CalCoreMeshPtr pCoreMesh = CalLoader::loadCoreMesh(strFilename);
			if(pCoreMesh == 0 || lastMeshId < 0) 
			{
				CalError::printLastError();
				Piavca::Error(_T("Error loading morph targets"));
			}
			int morphtargetId = cal_core_model->getCoreMesh(lastMeshId)->addAsMorphTarget(get_pointer(pCoreMesh));
			if(morphtargetId < 0) 
			{
				CalError::printLastError();
				Piavca::Error(_T("Error loading morph targets"));
			}

			// find the first non-whitespace character
			std::string::size_type pos = 0;
			pos = strData.find_first_of(".", pos);
			std::string strName = strData.substr(0, pos);
			int expressionId = Piavca::Core::getCore()->getExpressionId(StringToTString(strName));
			if(expressionId == Piavca::Core::nullId)
			{
				StringVector exprNames;
				exprNames.push_back(StringToTString(strName));
				std::cout << "Adding Joint "<< strName << std::endl;
				Piavca::Core::getCore()->addExpressionNameSet(exprNames);
				expressionId = Piavca::Core::getCore()->getExpressionId(StringToTString(strName));
			}
			// facial expression ids are negative, to distinguish then from
			// joint ids
			expressionId = -expressionId;
			if(expressionId >= expressions.size())
			{
				expressions.insert(expressions.end(), expressionId - (expressions.size()-1), FacialExpressionHolder());
			}
			expressions[expressionId].name = StringToTString(strName);
			expressions[expressionId].meshId = lastMeshId;
			expressions[expressionId].morphtargetId = morphtargetId;
		}
		*/
		/* need to sort out loading animations 
		else if(strKey == "animation")
		{
			std::string strFilename = strPath + strData;
			std::cout << "Loading animation '" << strFilename << "'..." << std::endl;
			// extract the animation name
 			std::string::size_type pos = 0;
			pos = strData.find_first_of(".", pos);
			std::string strName = strData.substr(0, pos);
			// load an animation
			MotionImp *imp = new MotionCal3DImp(strFilename, cal_core_model->getCoreSkeleton());
			Motion *tmot = new KeyframeMotion(imp);
			Piavca::Core::getCore()->loadMotion(StringToTString(strName), tmot); 
		}
		*/
		

};


void AvatarOpenSGImp::hideBodyPart(tstring partname)
{
	
};

void AvatarOpenSGImp::showBodyPart(tstring partname)
{
	
}

void AvatarOpenSGImp::loadTextures()
{
	
}

bool  AvatarOpenSGImp::setNeutralFacialExpression(tstring expressionName)
{
	return true;
};

bool AvatarOpenSGImp::addFacialExpression(tstring expressionName)
{
  return true;
};

int   AvatarOpenSGImp::getFacialExpressionId(tstring expressionName)
{
	return Piavca::Core::getCore()->getExpressionId(expressionName);
};

bool  AvatarOpenSGImp::setFacialExpressionWeight(int id, float weight, float timeInterval)
{
	
   return true;
};

void AvatarOpenSGImp::updateFacialExpressions()
{
}

float AvatarOpenSGImp::getFacialExpressionWeight(int id)
{
   return 0.0f;
};

int AvatarOpenSGImp::getParent(int jointId)const
{
	if(jointId < 0)
	{
		Piavca::Error(_T("Null jointId passed in to getParent"));
		return -1;
	}
	if(joints[jointId].name == _T(""))
	{
		Piavca::Error(_T("getParent called on joint missing in avatar"));
		return -1;
	}
	return joints[jointId].parent;
};

const tstring AvatarOpenSGImp::getJointName(int jointId)
{
	if(jointId < 0)
	{
		Piavca::Error(_T("Null jointId passed in to getJointName"));
		return _T("");
	}
	if(joints[jointId].name == _T(""))
	{
		Piavca::Error(_T("getJointName called on joint missing in avatar"));
	}
	return joints[jointId].name;
};

bool AvatarOpenSGImp::createJoint(tstring JointName)
{
	return false;
}

bool AvatarOpenSGImp::hasChanged(int jointId)
{
	if(jointId < 0)
	{
		Piavca::Error(_T("Null jointId passed in to hasChanged"));
		return false;
	}
	if(joints[jointId].name == _T(""))
	{
		Piavca::Error(_T("hasChanged called on joint missing in avatar"));
		return false;
	}
	return joints[jointId].changed;
};

void AvatarOpenSGImp::clearChange(int jointId)
{
	if(jointId < 0)
	{
		Piavca::Error(_T("Null jointId passed in to clearChange"));
		return;
	}
	if(joints[jointId].name == _T(""))
	{
		Piavca::Error(_T("clearChange called on joint missing in avatar"));
		return;
	}
	joints[jointId].changed = false;
};

void	AvatarOpenSGImp::setRootPosition (const Vec &Position)
{
   bb_dirty_flag = true;
   if(!charac)
   {
       Piavca::Error(_T("setRootOrientation called on empty avatar"));
	   return;
   }
   osg::Vec3f v(Position.X(), Position.Y(), Position.Z());
   //q.setValueAsQuat(Orientation.I(), Orientation.J(), Orientation.K(), Orientation.S());
   charac->setBonePosRel(v, 0);
   /*
	bb_dirty_flag = true;
   if(!charac)
   {
       Piavca::Error("setJointOrientation called on empty avatar");
	   return;
   }
   
   charac->getBoneQuats()[0].setValueAsQuat(Orientation.I(), Orientation.J(), Orientation.K(), Orientation.S());
   */
}
Vec		AvatarOpenSGImp::getRootPosition ()
{
   if(!charac)
   {
       Piavca::Error(_T("setJointOrientation called on empty avatar"));
	   return Vec();
   }   
   osg::MFVec3f bone_vecs = charac->getBonePosRel();
   if(bone_vecs.size() <= 0)
   {
       Piavca::Error(_T("getRootOrientation called on an avatar with no joints"));
	   return Vec();
   }   
   osg::Vec3f v = bone_vecs[0];
   return Vec(v.x(), v.y(), v.z());
}
void	AvatarOpenSGImp::setRootOrientation	(const Quat &Orientation)
{
   bb_dirty_flag = true;
   if(!charac)
   {
       Piavca::Error(_T("setRootOrientation called on empty avatar"));
	   return;
   }
   osg::Quaternion q;
   q.setValueAsQuat(Orientation.I(), Orientation.J(), Orientation.K(), Orientation.S());
   charac->setBoneQuatRel(q, 0);
};

Quat	AvatarOpenSGImp::getRootOrientation ()
{	
   if(!charac)
   {
       Piavca::Error(_T("setJointOrientation called on empty avatar"));
	   return Quat();
   }   
   osg::MFQuaternion bone_quats = charac->getBoneQuatsRel();
   if(bone_quats.size() <= 0)
   {
       Piavca::Error(_T("getRootOrientation called on an avatar with no joints"));
	   return Quat();
   }   
   osg::Quaternion q = bone_quats[0];
   return Quat(q.w(), q.x(), q.y(), q.z());
};


void AvatarOpenSGImp::setJointOrientation(int jointId, const Quat &Orientation, jointCoord worldCoord)
{
   bb_dirty_flag = true;
   if(jointId < 0)
   {
       Piavca::Error(_T("Null joint Id passed in to setJointOrientation"));
	   return;
   }
   if(joints[jointId].cal3dId < 0)
   {
       Piavca::Error(_T("setJointOrientation called on joint missing in avatar"));
	   return;
   }
   if(!charac)
   {
       Piavca::Error(_T("setJointOrientation called on empty avatar"));
	   return;
   }
   osg::MFQuaternion bone_quats = charac->getBoneQuatsRel();
   if(bone_quats.size() <= 0)
   {
       Piavca::Error(_T("setJointOrientation called on an avatar with no joints"));
   }   
   osg::Quaternion q;
   q.setValueAsQuat(Orientation.I(), Orientation.J(), Orientation.K(), Orientation.S());
   charac->setBoneQuatRel(q, joints[jointId].cal3dId);
};
	
Quat AvatarOpenSGImp::getJointOrientation	(int jointId, jointCoord worldCoord)
{
  
  if(jointId < 0)
  {
      Piavca::Error(_T("Null joint Id passed in to getJointOrientation"));
	  return Quat();
  }
  if(joints[jointId].cal3dId < 0)
  {
      Piavca::Error(_T("getJointOrientation called on joint missing in avatar"));
	  return Quat();
  }
   if(!charac)
   {
       Piavca::Error(_T("getJointOrientation called on empty avatar"));
	   return Quat();
   }
   osg::MFQuaternion bone_quats = charac->getBoneQuatsRel();
   if(bone_quats.size() <= 0)
   {
       Piavca::Error(_T("getJointOrientation called on an avatar with no joints"));
	   return Quat();
   }   
   


   switch (worldCoord)	
      {
      case JOINTLOCAL_COORD:	
		  {
			osg::Quaternion q = charac->getBoneQuatsRel()[joints[jointId].cal3dId];
			return Quat(q.w(), q.x(), q.y(), q.z());
		  }
	  break;
      case WORLD_COORD:	
		  {
			osg::Quaternion q = charac->getBoneQuatsAbs()[joints[jointId].cal3dId];
			return Quat(q.w(), q.x(), q.y(), q.z());
		  }
	  break;
      case LOCAL_COORD:
		  {	
			osg::Quaternion q = charac->getBoneQuatsAbs()[joints[jointId].cal3dId];
			Quat _q(q.w(), q.x(), q.y(), q.z());
			_q = getRootOrientation().inverse()*_q;
			return _q;
		  }
	  break;
      /*
	  case BASE_COORD:
		  {
			calq = bone->getCoreBone()->getRotation();
			return CalQuatToQuat(calq);
		  }
	  break;
      case INCLUDINGBASE_COORD:	
			calq = bone->getRotation();
			return CalQuatToQuat(calq);
	  break;
	  */
      default:	assert(0);
      }
  return Quat();
}


void AvatarOpenSGImp::setJointPosition(int jointId, const Vec &Position, jointCoord worldCoord)
{
   bb_dirty_flag = true;
   if(jointId < 0)
   {
       Piavca::Error(_T("Null joint Id passed in to setJointPosition"));
	   return;
   }
   if(joints[jointId].cal3dId < 0)
   {
       Piavca::Error(_T("setJointPosition called on joint missing in avatar"));
	   return;
   }
   if(!charac)
   {
       Piavca::Error(_T("setJointPosition called on empty avatar"));
	   return;
   }
   osg::MFVec3f bone_pos = charac->getBonePosRel();
   if(bone_pos.size() <= 0)
   {
       Piavca::Error(_T("setJointPosition called on an avatar with no joints"));
   }   
   osg::Vec3f v(Position.X(), Position.Y(), Position.Z());
   charac->setBonePosRel(v, joints[jointId].cal3dId);
};


Vec AvatarOpenSGImp::getJointBasePosition (int jointId, jointCoord worldCoord)
{
	 if(jointId < 0)
  {
      Piavca::Error(_T("Null joint Id passed in to getJointBasePosition"));
	  return Vec();
  }
  if(joints[jointId].cal3dId < 0)
  {
      Piavca::Error(_T("getJointBasePosition called on joint missing in avatar"));
	  return Vec();
  }
   if(!charac)
   {
       Piavca::Error(_T("getJointBasePosition called on empty avatar"));
	   return Vec();
   }
   osg::MFVec3f bone_pos = charac->getBonePosRel();
   if(bone_pos.size() <= 0)
   {
       Piavca::Error(_T("getJointBasePosition called on an avatar with no joints"));
	   return Vec();
   }   
   


   switch (worldCoord)	
      {
      case JOINTLOCAL_COORD:	
		  {
			osg::Vec3f v = charac->getBonePosRel()[joints[jointId].cal3dId];
			return Vec(v.x(), v.y(), v.z());
		  }
	  break;
      case WORLD_COORD:	
		  {
			osg::Vec3f v = charac->getBonePosAbs()[joints[jointId].cal3dId];
			return Vec(v.x(), v.y(), v.z());
		  }
	  break;
      case LOCAL_COORD:
		  {	
			osg::Vec3f v = charac->getBonePosAbs()[joints[jointId].cal3dId];
			Vec _v(v.x(), v.y(), v.z());
			_v = _v-getRootPosition();
			return _v;
		  }
	  break;
      /*
	  case BASE_COORD:
		  {
			calq = bone->getCoreBone()->getRotation();
			return CalQuatToQuat(calq);
		  }
	  break;
      case INCLUDINGBASE_COORD:	
			calq = bone->getRotation();
			return CalQuatToQuat(calq);
	  break;
	  */
      default:	assert(0);
      }
  return Vec();
};

void AvatarOpenSGImp::scaleRoot(Vec scale)
{
	Piavca::Warning(_T("Scaling unimplemented under Cal3D"));
}

void   AvatarOpenSGImp::scaleJoint (int jointId, Vec scale)
{
	Piavca::Warning(_T("Scaling unimplemented under Cal3D"));
};

void	AvatarOpenSGImp::platformSpecific_timeStep (float time)
{
	beginEditCP(charac, osg::Character::BoneQuatsRelFieldMask);
    endEditCP(charac, osg::Character::BoneQuatsRelFieldMask);
	beginEditCP(charac, osg::Character::BonePosRelFieldMask);
    endEditCP(charac, osg::Character::BonePosRelFieldMask);
};

void	AvatarOpenSGImp::render ()
{
  

};

Bound AvatarOpenSGImp::getBoundBox(void)
{

	osg::DynamicVolume vol = osg_node->getVolume();
	osg::Pnt3f min,max;
	vol.getBounds(min, max);

	bb.min[0] = min.x();
	bb.min[1] = min.y();
	bb.min[2] = min.z();
	bb.max[0] = max.x();
	bb.max[1] = max.y();
	bb.max[2] = max.z();

	return bb;

}

Bound AvatarOpenSGImp::getBaseBoundBox(void)
{
	return base_bb;	
};