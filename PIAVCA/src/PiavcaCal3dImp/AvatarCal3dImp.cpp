
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

#include "AvatarCal3dImp.h"

#include "PiavcaAPI/Avatar.h"
#include "PiavcaAPI/Motion.h"
#include "PiavcaAPI/PiavcaCore.h"
#include "StdMotionImp/StdMotionImp.h"
#include "PiavcaAPI/Vec.h"
#include "PiavcaAPI/Quat.h"
#include "Cal3dMathsConversion.h"

#include "MotionCal3dImp.h"


#ifdef _WIN32
#include <windows.h>
#endif

#include <GL/gl.h>
#include <string>

#include "TextureHandler.h"

using namespace Piavca;

#include <assert.h>
#include <algorithm>
using std::cout;
using std::endl;


AvatarCal3DImp *AvatarCal3DImp::getAvatarImp(Avatar *avatar) 
{
	AvatarCal3DImp *Cal3Dimp = dynamic_cast<AvatarCal3DImp *>(getAvatarImpInternal(avatar)); 
	if(Cal3Dimp)
		return Cal3Dimp;
	else
	{
		Piavca::Error(_T("Trying to use a non Cal3D avatar in Cal3D"));
		return NULL;
	}
};

AvatarCal3DImp::AvatarCal3DImp(tstring avatarId, TextureHandler *_textureHandler, bool bailOnMissedJoints, const Vec &Position, const Quat &Orientation)
  : cal_model(NULL), previous_time(0), renderBuffer(0), 
    updateBuffer(0), textureHandler(_textureHandler) 
{
	if(doubleBuffer) 
	{
		renderBuffer = 0;
		updateBuffer = 1;
	}

	joints.assign(Piavca::Core::getCore()->getMaxJointId()+1, JointHolder());
	expressions.assign(Piavca::Core::getCore()->getMaxExpressionId()+1, FacialExpressionHolder());
  
    // open the model configuration file
	std::string strFilename = avatarId + ".cfg";
	std::ifstream file;
	file.open(strFilename.c_str(), std::ios::in | std::ios::binary);
	if(!file)
	{
		Piavca::Error("Failed to open model configuration file '" + strFilename + "'." );
	}

	CalCoreModel *cal_core_model = new CalCoreModel("dummy");

	// initialize the data path
	std::string strPath = "./";


	int lastMeshId = -1;
	// parse all lines from the model configuration file
	int line;
	for(line = 1; ; line++)
	{
		// read the next model configuration line
		std::string strBuffer;
		std::getline(file, strBuffer);

		// stop if we reached the end of file
		if(file.eof()) break;

		// check if an error happend while reading from the file
		if(!file)
		{
			Piavca::Error("Error while reading from the model configuration file '" + strFilename + "'.");

		}

		// find the first non-whitespace character
		std::string::size_type pos;
		pos = strBuffer.find_first_not_of(" \t");

		// check for empty lines
		if((pos == std::string::npos) || (strBuffer[pos] == '\n') || (strBuffer[pos] == '\r') || (strBuffer[pos] == 0)) continue;

		// check for comment lines
		if(strBuffer[pos] == '#') continue;

		// get the key
		std::string strKey;
		strKey = strBuffer.substr(pos, strBuffer.find_first_of(" =\t\n\r", pos) - pos);
		pos += strKey.size();

		// get the '=' character
		pos = strBuffer.find_first_not_of(" \t", pos);
		if((pos == std::string::npos) || (strBuffer[pos] != '='))
		{
			std::ostringstream os;
			os << strFilename << "(" << line << "): Invalid syntax.";
			Piavca::Error(StringToTString(os.str()));
		}

		// find the first non-whitespace character after the '=' character
		pos = strBuffer.find_first_not_of(" \t", pos + 1);

		// get the data
		std::string strData;
		strData = strBuffer.substr(pos, strBuffer.find_first_of("\n\r", pos) - pos);

		// handle the model creation
		if(strKey[0] == '#')
		{
			// do nothing this is a comment
		}
		else if(strKey == "path")
		{
			// set the new path for the data files if one hasn't been set already
			strPath = strData;
		}
		else if(strKey == "skeleton")
		{
			// load core skeleton
			std::cout << "Loading skeleton '" << strData << "'..." << std::endl;
			if(!cal_core_model->loadCoreSkeleton(strPath + strData))
			{
				CalError::printLastError();
				Piavca::Error(_T("Error loading skeleton"));
			}
		}
		else if(strKey == "mesh")
		{
			// load core mesh
			std::cout << "Loading mesh '" << strData << "'..." << std::endl;
			lastMeshId = cal_core_model->loadCoreMesh(strPath + strData);
			std::cout << "Finished Loading mesh '" << strData << "'..." << std::endl;
			if(lastMeshId == -1)
			{
				CalError::printLastError();
				Piavca::Error(_T("Error loading mesh"));
			}
		}
		else if(strKey == "material")
		{
			// load core material
			std::cout << "Loading material '" << strData << "'..." << std::endl;
			if(cal_core_model->loadCoreMaterial(strPath + strData) == -1)
			{
				CalError::printLastError();
				Piavca::Error(_T("Error loading material"));
			}
		}
		else if(strKey == "morphtarget")
		{
			std::cout << "Loading mesh as morph target '" << strData << "'..." << std::endl;
			CalCoreMesh *pCoreMesh = CalLoader::loadCoreMesh(strPath + strData);
			if(pCoreMesh == 0 || lastMeshId < 0) 
			{
				CalError::printLastError();
				Piavca::Error(_T("Error loading morph targets"));
			}
			int morphtargetId = cal_core_model->getCoreMesh(lastMeshId)->addAsMorphTarget(pCoreMesh);
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
			expressions[expressionId].name = StringToTString(strName);
			expressions[expressionId].meshId = lastMeshId;
			expressions[expressionId].morphtargetId = morphtargetId;
		}
		else if(strKey == "animation")
		{
			std::cout << "Loading animation '" << strData << "'..." << std::endl;
			// extract the animation name
 			std::string::size_type pos = 0;
			pos = strData.find_first_of(".", pos);
			std::string strName = strData.substr(0, pos);
			// load an animation
			MotionImp *imp = new MotionCal3DImp(strData, cal_core_model->getCoreSkeleton());
			Motion *tmot = new TrackMotion(imp);
			Piavca::Core::getCore()->loadMotion(StringToTString(strName), tmot); 
		}
		else if(strKey == "scale")
		{
			// do nothing, you can scale things in the cal3d miniviewer, but not piavca
		}
		else
		{
			std::ostringstream os;
			os << strFilename << "(" << line << "): Invalid syntax.";
			Piavca::Error(StringToTString(os.str()));
		}
	}

	// explicitely close the file
	file.close();


	// make one material thread for each material
	// NOTE: this is not the right way to do it, but this viewer can't do the right
	// mapping without further information on the model etc.
	int materialId;
	for(materialId = 0; materialId < cal_core_model->getCoreMaterialCount(); materialId++)
	{
		// create the a material thread
		cal_core_model->createCoreMaterialThread(materialId);

		// initialize the material thread
		cal_core_model->setCoreMaterialId(materialId, 0, materialId);
	}

  // Calculate Bounding Boxes

	cal_core_model->getCoreSkeleton()->calculateBoundingBoxes(cal_core_model);

	// create the model from the core model
	cal_model = new CalModel(cal_core_model);

	// attach all meshes to the model
	int meshId;
	for(meshId = 0; meshId < cal_core_model->getCoreMeshCount(); meshId++)
	{
		std::cout << meshId << " ";
		cal_model->attachMesh(meshId);
	}

	// set the material set of the whole model
	cal_model->setMaterialSet(0);

	int i,j;
	// load the joint map
	CalSkeleton *skel = cal_model->getSkeleton();
	std::vector< std::pair< tstring, int > > jointAssociations = Piavca::Core::getCore()->getJointNameAssociations();
	for(i = 0; i < (int) jointAssociations.size(); i++)
	{
		int cal3Did = skel->getCoreSkeleton()->getCoreBoneId(TStringToString(jointAssociations[i].first));
		if(cal3Did > 0)
		{
			std::cout << "found joint " << jointAssociations[i].first << std::endl;
			joints[jointAssociations[i].second].cal3dId = cal3Did;
			joints[jointAssociations[i].second].name = jointAssociations[i].first;
		}
	}
	// find the parents of each joint
	for(i = 0; i < (int) joints.size(); i++)
	{	  
		if(joints[i].cal3dId < 0) continue;
		CalCoreBone *corebone = skel->getBone(joints[i].cal3dId)->getCoreBone();
		int parentId = corebone->getParentId();
		for(j = 0; j < (int) joints.size(); j++)
			if(joints[j].cal3dId == parentId)
			{
				joints[i].parent = j;
				break;
			}
	}

	//Find the amounts of memory we will need for each submesh
	CalRenderer* renderer = new CalRenderer(cal_model->getRenderer());

	int meshCount = renderer->getMeshCount();

	int numBuffers = 1;
	if(doubleBuffer) numBuffers = 2;

	//Initialize mVertices, mNormals, mFaces, mTextureCoordCounts sizes for
	//the mesh count with dummy vectors
	std::vector< float* > tempVecF; tempVecF.clear();
	std::vector< int* > tempVecI; tempVecI.clear();
	std::vector< int > tempVec0; tempVec0.clear();

	std::vector< std::vector< float* > > tempVecVecF; tempVecF.clear();
	std::vector< std::vector< int* > > tempVecVecI; tempVecI.clear();
	std::vector< std::vector< int > > tempVecVec0; tempVec0.clear();

	mVertices.resize(numBuffers, tempVecVecF);
	mNormals.resize(numBuffers, tempVecVecF);
	mFaces.resize(numBuffers, tempVecVecI);
	mTextureCoords.resize(numBuffers, tempVecVecF);
	mTextureCoordCounts.resize(numBuffers, tempVecVec0);
	mFaceCounts.resize(numBuffers, tempVecVec0);

	int buffer;
	for (buffer = 0; buffer < numBuffers; buffer++)
	{
		mVertices[buffer].resize(meshCount, tempVecF);
		mNormals[buffer].resize(meshCount, tempVecF);
		mFaces[buffer].resize(meshCount, tempVecI);
		mTextureCoords[buffer].resize(meshCount, tempVecF);
		mTextureCoordCounts[buffer].resize(meshCount, tempVec0);
		mFaceCounts[buffer].resize(meshCount, tempVec0);

		for (i=0; i < meshCount; i++)
		{
			int submeshCount = renderer->getSubmeshCount( i );

			//Initialize the data vectors for proper submesh size (with NULL data)
			mVertices[buffer][i].resize(submeshCount, NULL);
			mNormals[buffer][i].resize(submeshCount, NULL);
			mFaces[buffer][i].resize(submeshCount, NULL);
			mTextureCoords[buffer][i].resize(submeshCount, NULL);
			mTextureCoordCounts[buffer][i].resize(submeshCount, 0);
			mFaceCounts[buffer][i].resize(submeshCount, 0);

			for (j=0; j < submeshCount; j++)
			{
				renderer->selectMeshSubmesh( i, j );

				//Get vertex count (equal numbers of vertices, normals, and texture coords)
				int vertexCount = renderer->getVertexCount();

				//Get face count
				int faceCount = renderer->getFaceCount();

				//Declare all the memory
				mVertices[buffer][i][j] = new float[vertexCount * 3];
				mNormals[buffer][i][j] = new float[vertexCount * 3];
				mFaces[buffer][i][j] = new int[faceCount * 3];

				// set the texture coordinate buffer and state if necessary
				if(renderer->getMapCount() > 0)
				{
					mTextureCoords[buffer][i][j] = new float[vertexCount * 2];
				}
				else
				{
					//If there are no texture coords, allocate space for a dummy value
					mTextureCoords[buffer][i][j] = new float[1];
				}

			}
		}
	}
	delete renderer;

  
  // create a rest pose motion for the avatar
  TrackMotion *tmot = new TrackMotion(false);
  //std::cout << getRootPosition() << std::endl;
  tmot->addVecTrack(root_position_id, getRootPosition());
  //std::cout << avatarImp->getRootOrientation() << std::endl;
  tmot->addQuatTrack(root_orientation_id, getRootOrientation());
  for(int track = 0; track < Piavca::Core::getCore()->getMaxJointId(); track++)
	  if(!isNull(track))
	  {
		//std::cout << getJointOrientation(track) << std::endl;
		tmot->addQuatTrack(track, getJointOrientation(track));
	  }
  Core::getCore()->loadMotion(avatarId + _T("_rest"), tmot);
  
  platformSpecific_timeStep(Piavca::Core::getCore()->getTime());
  
  renderer = new CalRenderer(cal_model->getRenderer());
  for (buffer = 0; buffer < numBuffers; buffer++)
	{
	  for (i=0; i < meshCount; i++)
	  {
		int submeshCount = renderer->getSubmeshCount( i );
	
		for (j=0; j < submeshCount; j++)
		{
		  renderer->selectMeshSubmesh( i, j );
		  // get the texture coordinates of the submesh
		  mTextureCoordCounts[buffer][i][j] = renderer->getTextureCoordinates(0, mTextureCoords[buffer][i][j] ) ;
		
		  // get the faces of the submesh
		  mFaceCounts[buffer][i][j] = renderer->getFaces( mFaces[buffer][i][j] ) ;
		}
	  }
	}
  
   delete renderer;

};

void AvatarCal3DImp::loadTextures()
{
	// initialize the data path
	std::string strPath = "./";
	// load all textures and store the opengl texture id in the corresponding map in the material
	// NB this bit is GL specific!!!
	CalCoreModel *cal_core_model = cal_model->getCoreModel();
	int materialId;
	for(materialId = 0; materialId < cal_core_model->getCoreMaterialCount(); materialId++)
	{
		// get the core material
		CalCoreMaterial *pCoreMaterial;
		pCoreMaterial = cal_core_model->getCoreMaterial(materialId);

		// loop through all maps of the core material
		int mapId;
		for(mapId = 0; mapId < pCoreMaterial->getMapCount(); mapId++)
		{
			// get the filename of the texture
			std::string strFilename;
			strFilename = pCoreMaterial->getMapFilename(mapId);

			// load the texture from the file
			GLuint textureId;
			textureId = textureHandler->loadTexture(strPath + strFilename);

			// store the opengl texture id in the user data of the map
			pCoreMaterial->setMapUserData(mapId, (Cal::UserData)textureId);
		}
	}

}

bool  AvatarCal3DImp::setNeutralFacialExpression(tstring expressionName)
{
	return true;
};

bool AvatarCal3DImp::addFacialExpression(tstring expressionName)
{
  return true;
};

int   AvatarCal3DImp::getFacialExpressionId(tstring expressionName)
{
	return Piavca::Core::getCore()->getExpressionId(expressionName);
};

bool  AvatarCal3DImp::setFacialExpressionWeight(int id, float weight, float timeInterval)
{
	if(id < 0 || id >= (int)expressions.size())
	{
		std::cout << "Unknown facial expression id " << id << std::endl;
		return false;
	}
	if(expressions[id].meshId < 0 
		//|| expressions[id].subMeshId < 0 
		|| expressions[id].morphtargetId < 0)
	{
		std::cout << "Facial expression not present " << id << std::endl;
		return false;
	}
   if(!cal_model)
   {
       Piavca::Error("setFacialExpressionWeight called on empty avatar");
	   return false;
   }

   CalMesh *mesh = cal_model->getMesh(expressions[id].meshId);
   if(!mesh)
   {
       Piavca::Error("setJointOrientation called on avatar with no head mesh");
	   return false;
   }
   for (int i = 0; i < mesh->getSubmeshCount(); i++)
   {
		CalSubmesh *subMesh = mesh->getSubmesh(i);
		if(expressions[id].morphtargetId >= subMesh->getMorphTargetWeightCount())
		{
			Piavca::Error("setFacialExpressionWeight called on expression that does not exist");
			return false;
		}
		subMesh->setMorphTargetWeight(expressions[id].morphtargetId, weight);
   }
   return true;
};

void AvatarCal3DImp::updateFacialExpressions()
{
}

float AvatarCal3DImp::getFacialExpressionWeight(int id)
{
	if(id < 0 || id >= (int)expressions.size())
	{
		std::cout << "Unknown facial expression id " << id << std::endl;
		return false;
	}
	if(expressions[id].meshId < 0 
		//|| expressions[id].subMeshId < 0 
		|| expressions[id].morphtargetId < 0)
	{
		std::cout << "Facial expression not present " << id << std::endl;
		return 0.0;
	}
   if(!cal_model)
   {
       Piavca::Error("getFacialExpressionWeight called on empty avatar");
	   return 0.0;
   }

   CalMesh *mesh = cal_model->getMesh(expressions[id].meshId);
   if(!mesh)
   {
       Piavca::Error("getFacialExpressionWeight called on avatar with no head mesh");
	   return 0.0;
   }
   CalSubmesh *subMesh = mesh->getSubmesh(0);
   if(!subMesh)
   {
       Piavca::Error("getFacialExpressionWeight called on avatar with no face submesh");
	   return 0.0;
   }
   if(expressions[id].morphtargetId >= subMesh->getMorphTargetWeightCount())
   {
       Piavca::Error("getFacialExpressionWeight called on expression that does not exist");
	   return 0.0;
   }
   return subMesh->getMorphTargetWeight(expressions[id].morphtargetId);
};

int AvatarCal3DImp::getParent(int jointId)const
{
	if(jointId < 0)
	{
		Piavca::Error("Null jointId passed in to getParent");
		return -1;
	}
	if(joints[jointId].name == "")
	{
		Piavca::Error("getParent called on joint missing in avatar");
		return -1;
	}
	return joints[jointId].parent;
};

const tstring AvatarCal3DImp::getJointName(int jointId)
{
	if(jointId < 0)
	{
		Piavca::Error("Null jointId passed in to getJointName");
		return _T("");
	}
	if(joints[jointId].name == _T(""))
	{
		Piavca::Error("getJointName called on joint missing in avatar");
	}
	return joints[jointId].name;
};

bool AvatarCal3DImp::createJoint(tstring JointName)
{
	while(Piavca::Core::getCore()->getMaxJointId() >= (int)joints.size())
		joints.push_back(JointHolder());
    
    int jointId = Piavca::Core::getCore()->getJointId(JointName);
    if(jointId < 0) 
		return false;
    
	CalSkeleton *skel = cal_model->getSkeleton();
	int cal3Did = skel->getCoreSkeleton()->getCoreBoneId(TStringToString(JointName));
	if(cal3Did > 0)
	{
		joints[jointId].cal3dId = cal3Did;
		joints[jointId].name = JointName;
		CalCoreBone *corebone = skel->getBone(cal3Did)->getCoreBone();
		joints[jointId].parent = corebone->getParentId();
		return true;
	}
	return false;
}

bool AvatarCal3DImp::hasChanged(int jointId)
{
	if(jointId < 0)
	{
		Piavca::Error("Null jointId passed in to hasChanged");
		return false;
	}
	if(joints[jointId].name == "")
	{
		Piavca::Error("hasChanged called on joint missing in avatar");
		return false;
	}
	return joints[jointId].changed;
};

void AvatarCal3DImp::clearChange(int jointId)
{
	if(jointId < 0)
	{
		Piavca::Error("Null jointId passed in to clearChange");
		return;
	}
	if(joints[jointId].name == "")
	{
		Piavca::Error("clearChange called on joint missing in avatar");
		return;
	}
	joints[jointId].changed = false;
};

void	AvatarCal3DImp::setRootPosition (const Vec &Position)
{
  if(!cal_model)
   {
       Piavca::Error("setJointOrientation called on empty avatar");
	   return;
   }

   CalVector calv(VecToCalVec(Position));
   
   CalSkeleton *skel = cal_model->getSkeleton();
   if(!skel)
   {
       Piavca::Error("setJointOrientation called on avatar with no skeleton");
	   return;
   }
   CalBone *bone = skel->getBone(0);
   if(!bone)
   {
       Piavca::Error("setJointOrientation called on joint that does not exist in avatar");
	   return;
   }
   calv += bone->getCoreBone()->getTranslation();
   bone->setTranslation(calv);
}
Vec		AvatarCal3DImp::getRootPosition ()
{
   cal_model->getSkeleton()->calculateState();
   if(!cal_model)
   {
       Piavca::Error("setJointOrientation called on empty avatar");
	   return Vec();
   }   
   CalSkeleton *skel = cal_model->getSkeleton();
   if(!skel)
   {
       Piavca::Error("setJointOrientation called on avatar with no skeleton");
	   return Vec();
   }
   CalBone *bone = skel->getBone(0);
   if(!bone)
   {
       Piavca::Error("setJointOrientation called on joint that does not exist in avatar");
	   return Vec();
   }
   return CalVecToVec(bone->getTranslationAbsolute());
}
void	AvatarCal3DImp::setRootOrientation	(const Quat &Orientation)
{
   cal_model->getSkeleton()->calculateState();
   if(!cal_model)
   {
       Piavca::Error("setJointOrientation called on empty avatar");
	   return;
   }

   CalQuaternion calq = QuatToCalQuat(Orientation);
   
   CalSkeleton *skel = cal_model->getSkeleton();
   if(!skel)
   {
       Piavca::Error("setJointOrientation called on avatar with no skeleton");
	   return;
   }
   CalBone *bone = skel->getBone(0);
   if(!bone)
   {
       Piavca::Error("setJointOrientation called on joint that does not exist in avatar");
	   return;
   }
   calq *= bone->getCoreBone()->getRotation();
   bone->setRotation(calq);
};

Quat	AvatarCal3DImp::getRootOrientation ()
{	
   if(!cal_model)
   {
       Piavca::Error("setJointOrientation called on empty avatar");
	   return Quat();
   }   
   CalSkeleton *skel = cal_model->getSkeleton();
   if(!skel)
   {
       Piavca::Error("setJointOrientation called on avatar with no skeleton");
	   return Quat();
   }
   CalBone *bone = skel->getBone(0);
   if(!bone)
   {
       Piavca::Error("setJointOrientation called on joint that does not exist in avatar");
	   return Quat();
   }
   return CalQuatToQuat(bone->getRotationAbsolute());
};


void AvatarCal3DImp::setJointOrientation(int jointId, const Quat &Orientation, jointCoord worldCoord)
{
   if(jointId < 0)
   {
       Piavca::Error("Null joint Id passed in to setJointOrientation");
	   return;
   }
   if(joints[jointId].cal3dId < 0)
   {
       Piavca::Error("setJointOrientation called on joint missing in avatar");
	   return;
   }
   if(!cal_model)
   {
       Piavca::Error("setJointOrientation called on empty avatar");
	   return;
   }

   CalQuaternion calq = QuatToCalQuat(Orientation);
   
   CalSkeleton *skel = cal_model->getSkeleton();
   if(!skel)
   {
       Piavca::Error("setJointOrientation called on avatar with no skeleton");
	   return;
   }
   CalBone *bone = skel->getBone(joints[jointId].cal3dId);
   if(!bone)
   {
       Piavca::Error("setJointOrientation called on joint that does not exist in avatar");
	   return;
   }
   calq *= bone->getCoreBone()->getRotation();
   bone->setRotation(calq);
   bone->setTranslation(bone->getCoreBone()->getTranslation());
};
	
Quat AvatarCal3DImp::getJointOrientation	(int jointId, jointCoord worldCoord)
{
  
  if(jointId < 0)
  {
      Piavca::Error("Null joint Id passed in to getJointOrientation");
	  return Quat();
  }
  if(joints[jointId].cal3dId < 0)
  {
      Piavca::Error("getJointOrientation called on joint missing in avatar");
	  return Quat();
  }
   if(!cal_model)
   {
       Piavca::Error("getJointOrientation called on empty avatar");
	   return Quat();
   }

   CalQuaternion calq;
   
   CalSkeleton *skel = cal_model->getSkeleton();
   if(!skel)
   {
       Piavca::Error("getJointOrientation called on avatar with no skeleton");
	   return Quat();
   }
   CalBone *bone = skel->getBone(joints[jointId].cal3dId);
   if(!bone)
   {
       Piavca::Error("getJointOrientation called on joint that does not exist in avatar");
	   return Quat();
   }

  switch (worldCoord)	
      {
      case JOINTLOCAL_COORD:	
		  {
			calq = bone->getRotation();
			Quat q = CalQuatToQuat(calq);
			q = q * CalQuatToQuat(bone->getCoreBone()->getRotation()).inverse();
			return q;
		  }
	  break;
      case WORLD_COORD:
			calq = bone->getRotationAbsolute();
			return CalQuatToQuat(calq);
	  break;
      case LOCAL_COORD:
		  {
			calq = bone->getRotationAbsolute();
			Quat q = CalQuatToQuat(calq);
			q = getRootOrientation().inverse()*q;
			return q;
		  }
			break;
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
      default:	assert(0);
      }
  return Quat();
}
	
Vec AvatarCal3DImp::getJointBasePosition (int jointId, jointCoord worldCoord)
{

  if(jointId < 0)
  {
      Piavca::Error("Null joint Id passed in to getJointBasePosition");
	  return Vec();
  }
  if(joints[jointId].cal3dId < 0)
  {
      Piavca::Error("getJointBasePosition called on joint missing in avatar");
	  return Vec();
  }
   if(!cal_model)
   {
       Piavca::Error("getJointBasePosition called on empty avatar");
	   return Vec();
   }

   CalVector calv;
   
   CalSkeleton *skel = cal_model->getSkeleton();
   if(!skel)
   {
       Piavca::Error("getJointBasePosition called on avatar with no skeleton");
	   return Vec();
   }
   CalBone *bone = skel->getBone(joints[jointId].cal3dId);
   if(!bone)
   {
       Piavca::Error("getJointBasePosition called on joint that does not exist in avatar");
	   return Vec();
   }

  switch (worldCoord)	
      {
      case JOINTLOCAL_COORD:	
			calv = bone->getTranslation();
			return CalVecToVec(calv);
	  break;
      case WORLD_COORD:
			calv = bone->getTranslationAbsolute();
			return CalVecToVec(calv);
	  break;
      case LOCAL_COORD:
		  {
			calv = bone->getTranslationAbsolute();
			Vec v = CalVecToVec(calv);
			v -= getRootPosition();
			return v;
		  }
	  break;
      default:	assert(0);
      }
  return Vec(); 
};

void AvatarCal3DImp::scaleRoot(Vec scale)
{
	Piavca::Warning(_T("Scaling unimplemented under Cal3D"));
}

void   AvatarCal3DImp::scaleJoint (int jointId, Vec scale)
{
	Piavca::Warning(_T("Scaling unimplemented under Cal3D"));
};

void	AvatarCal3DImp::platformSpecific_timeStep (float time)
{
	// calculate the amount of elapsed seconds
	float elapsedSeconds = Core::getCore()->getTime() - previous_time;
	previous_time = Core::getCore()->getTime();

	
	// don't do a full Cal3D update as that plays the cal3d animations
	// which overwrites any animations that piavca has played
	//cal_model->update(elapsedSeconds);
	cal_model->getSkeleton()->calculateState();
	cal_model->getPhysique()->update();
    cal_model->getSpringSystem()->update(previous_time);

	
	CalRenderer* renderer = new CalRenderer(cal_model->getRenderer());

	//Get the mesh data for all meshes and submeshes
	 int meshCount = renderer->getMeshCount() ;

	// get all meshes of the model
	int meshId;
	for(meshId = 0; meshId < meshCount; meshId++)
	{
      int submeshId, submeshCount ;

      submeshCount = renderer->getSubmeshCount( meshId ) ;

      // get all submeshes of the mesh
      for(submeshId = 0; submeshId < submeshCount; submeshId++)
      {

         // select mesh and submesh and grab all the data
         if ( renderer->selectMeshSubmesh(meshId, submeshId) )
         {

            // get the transformed vertices of the submesh
            renderer->getVertices( mVertices[renderBuffer][meshId][submeshId] );

            // get the transformed normals of the submesh
            renderer->getNormals( mNormals[renderBuffer][meshId][submeshId] ) ;

            // get the texture coordinates of the submesh
            //mTextureCoordCounts[renderBuffer][meshId][submeshId] = renderer->getTextureCoordinates(0, mTextureCoords[renderBuffer][meshId][submeshId] ) ;

            // get the faces of the submesh
            //mFaceCounts[renderBuffer][meshId][submeshId] = renderer->getFaces( mFaces[renderBuffer][meshId][submeshId] ) ;
         }
         else
         {
			 Piavca::Error(_T("AvatarCal3DImp: Attempting to update for an invalid submesh (this is bad)"));
         }

      }
   }

   //renderer->destroy();
   delete renderer;


};

void	AvatarCal3DImp::render ()
{
  //std::cout << "avatar.prerender\n";
  // get the renderer of the model
  CalRenderer *pCalRenderer = cal_model->getRenderer();

  // begin the rendering loop
  if(pCalRenderer->beginRendering())
  {
    // set global OpenGL states
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

	glEnable (GL_BLEND); 
	glBlendFunc (GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

    // we will use vertex arrays, so enable them
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);

    // get the number of meshes
    int meshCount = pCalRenderer->getMeshCount();

    // render all meshes of the model
    for(int meshId = 0; meshId < meshCount; meshId++)
    {
      // get the number of submeshes
      int submeshCount = pCalRenderer->getSubmeshCount(meshId);

      // render all submeshes of the mesh
      for(int submeshId = 0; submeshId < submeshCount; submeshId++)
      {
        // select mesh and submesh for further data access
        if(pCalRenderer->selectMeshSubmesh(meshId, submeshId))
        {
          unsigned char meshColor[4];
          GLfloat materialColor[4];

          // set the material ambient color
          pCalRenderer->getAmbientColor(&meshColor[0]);
          materialColor[0] = meshColor[0] / 255.0f;  materialColor[1] = meshColor[1] / 255.0f; materialColor[2] = meshColor[2] / 255.0f; materialColor[3] = meshColor[3] / 255.0f;
          glMaterialfv(GL_FRONT, GL_AMBIENT, materialColor);

          // set the material diffuse color
          pCalRenderer->getDiffuseColor(&meshColor[0]);
		  // if the object is transparent, don't bother rendering it
		  if( meshColor[3] == 0) 
				continue;
          materialColor[0] = meshColor[0] / 255.0f;  materialColor[1] = meshColor[1] / 255.0f; materialColor[2] = meshColor[2] / 255.0f; materialColor[3] = meshColor[3] / 255.0f;
          glMaterialfv(GL_FRONT, GL_DIFFUSE, materialColor);

          // set the material specular color
          pCalRenderer->getSpecularColor(&meshColor[0]);
          materialColor[0] = meshColor[0] / 255.0f;  materialColor[1] = meshColor[1] / 255.0f; materialColor[2] = meshColor[2] / 255.0f; materialColor[3] = meshColor[3] / 255.0f;
          glMaterialfv(GL_FRONT, GL_SPECULAR, materialColor);

          // set the material shininess factor
          float shininess;
          shininess = 50.0f; //pCalRenderer->getShininess();
          glMaterialfv(GL_FRONT, GL_SHININESS, &shininess);

          // get the transformed vertices of the submesh
          //static float meshVertices[30000][3];
          //int vertexCount = pCalRenderer->getVertices(&meshVertices[0][0]);

          // get the transformed normals of the submesh
          //static float meshNormals[30000][3];
          //pCalRenderer->getNormals(&meshNormals[0][0]);

          // get the texture coordinates of the submesh
          //static float meshTextureCoordinates[30000][2];
          //int textureCoordinateCount = pCalRenderer->getTextureCoordinates(0, &meshTextureCoordinates[0][0]);

          // get the faces of the submesh
          //static CalIndex meshFaces[50000][3];
          //int faceCount = pCalRenderer->getFaces(&meshFaces[0][0]);

          // set the vertex and normal buffers
          glVertexPointer(3, GL_FLOAT, 0, mVertices[renderBuffer][meshId][submeshId]);
          glNormalPointer(GL_FLOAT, 0, mNormals[renderBuffer][meshId][submeshId]);

          // set the texture coordinate buffer and state if necessary
          if((pCalRenderer->getMapCount() > 0) && (mTextureCoordCounts[renderBuffer][meshId][submeshId] > 0))
          {
            glEnable(GL_TEXTURE_2D);
            glEnableClientState(GL_TEXTURE_COORD_ARRAY);
            glEnable(GL_COLOR_MATERIAL);

            // set the texture id we stored in the map user data
			GLuint textureId = (long)pCalRenderer->getMapUserData(0);
			textureId = textureHandler->getTextureId(textureId);
            glBindTexture(GL_TEXTURE_2D, textureId);

            // set the texture coordinate buffer
            glTexCoordPointer(2, GL_FLOAT, 0, mTextureCoords[renderBuffer][meshId][submeshId]);
            glColor3f(1.0f, 1.0f, 1.0f);
          }

          // draw the submesh
		  
          if(sizeof(CalIndex)==2)
            glDrawElements(GL_TRIANGLES, mFaceCounts[renderBuffer][meshId][submeshId] * 3, GL_UNSIGNED_SHORT, mFaces[renderBuffer][meshId][submeshId]);
          else
            glDrawElements(GL_TRIANGLES, mFaceCounts[renderBuffer][meshId][submeshId] * 3, GL_UNSIGNED_INT, mFaces[renderBuffer][meshId][submeshId]);

          // disable the texture coordinate state if necessary
          if((pCalRenderer->getMapCount() > 0) && (mTextureCoordCounts[renderBuffer][meshId][submeshId] > 0))
          {
            glDisable(GL_COLOR_MATERIAL);
            glDisableClientState(GL_TEXTURE_COORD_ARRAY);
            glDisable(GL_TEXTURE_2D);
          }

          // adjust the vertex and face counter
          //m_vertexCount += vertexCount;
          //m_faceCount += faceCount;

        }
      }
    }

    // clear vertex array state
    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);

    // clear light
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    glDisable(GL_DEPTH_TEST);

    // end the rendering
    pCalRenderer->endRendering();
  }

};