//****************************************************************************//
// hardwaremodel.cpp                                                       //
// Copyright (C) 2004 Desmecht Laurent                                        //
//****************************************************************************//
// This library is free software; you can redistribute it and/or modify it    //
// under the terms of the GNU Lesser General Public License as published by   //
// the Free Software Foundation; either version 2.1 of the License, or (at    //
// your option) any later version.                                            //
//****************************************************************************//

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif


#include "hardwaremodel.h"

#include "cal3d/error.h"
#include "cal3d/coremodel.h"
#include "cal3d/model.h"
#include "cal3d/coremesh.h"
#include "cal3d/bone.h"
#include "cal3d/corematerial.h"
#include "cal3d/coresubmesh.h"
#include "cal3d/coresubmorphtarget.h"
#include "cal3d/coreskeleton.h"
#include "cal3d/skeleton.h"

#include <string.h>	// for memcpy

using namespace Piavca;

 /*****************************************************************************/
/** Constructs the hardware model instance.
  *
  * This function is the default constructor of the hardware model instance.
  *****************************************************************************/


PiavcaHardwareModel::PiavcaHardwareModel(CalCoreModel *pCoreModel)
  : m_selectedHardwareMesh(-1)
{
  assert(pCoreModel);
  m_pCoreModel = pCoreModel;

  m_pVertexBuffer = NULL;
  m_pIndexBuffer = NULL;
  m_pNormalBuffer = NULL;
  m_pWeightBuffer = NULL;
  m_pMatrixIndexBuffer = NULL;
  int i;
  for( i = 0 ; i < 8 ; i++)
    m_pTextureCoordBuffer[i]=NULL;
  m_textureCoordNum=0;
  
  for( i = 0 ; i < 8 ; i++)
    m_pTangentSpaceBuffer [i]=NULL; 

  m_totalFaceCount=0;
  m_totalVertexCount=0;
}


/*****************************************************************************/
/** Set the vertex (position) buffer of the hardware model instance.
  *
  * This function set the vertex (position) buffer the hardware model instance.
  *
  * @param pVertexBuffer A pointer to the vertex buffer.
  * @param stride  The number of byte to add to find the next element
  *
  *****************************************************************************/

void PiavcaHardwareModel::setVertexBuffer( char *pVertexBuffer, int stride)
{
  m_pVertexBuffer = pVertexBuffer;
  m_vertexStride = stride;
}

 /*****************************************************************************/
/** Set the index buffer of the hardware model instance.
  *
  * This function set the index buffer the hardware model instance.
  *
  * @param pIndexBuffer A pointer to the index buffer.
  *
  *****************************************************************************/

void PiavcaHardwareModel::setIndexBuffer( CalIndex *pIndexBuffer)
{
  m_pIndexBuffer= pIndexBuffer;
}

 /*****************************************************************************/
/** Set the normal buffer of the hardware model instance.
  *
  * This function set the normal buffer the hardware model instance.
  *
  * @param pNormalBuffer A pointer to the normal buffer.
  * @param stride  The number of byte to add to find the next element
  *
  *****************************************************************************/

void PiavcaHardwareModel::setNormalBuffer( char *pNormalBuffer, int stride)
{
  m_pNormalBuffer = pNormalBuffer;
  m_normalStride = stride;
}

 /*****************************************************************************/
/** Set the weight buffer of the hardware model instance.
  *
  * This function set the weight buffer the hardware model instance.
  *
  * @param pWeightBuffer A pointer to the weight buffer.
  * @param stride  The number of byte to add to find the next element
  *
  *****************************************************************************/


void PiavcaHardwareModel::setWeightBuffer( char *pWeightBuffer, int stride)
{
  m_pWeightBuffer = pWeightBuffer;
  m_weightStride = stride;
}

 /*****************************************************************************/
/** Set the matrix index buffer of the hardware model instance.
  *
  * This function set the matrix index buffer the hardware model instance.
  *
  * @param pMatrixIndexBuffer A pointer to the matrix index buffer.
  * @param stride  The number of byte to add to find the next element
  *
  *****************************************************************************/


void PiavcaHardwareModel::setMatrixIndexBuffer( char *pMatrixIndexBuffer, int stride)
{
  m_pMatrixIndexBuffer = pMatrixIndexBuffer;
  m_matrixIndexStride = stride;
}

 /*****************************************************************************/
/** Set the number the texture coordinate of the hardware model instance.
  *
  * This function set the number the texture coordinate the hardware model instance.
  *
  * @param textureCoordNum A integer with the number the texture coordinate.
  *
  *****************************************************************************/

void PiavcaHardwareModel::setTextureCoordNum(int textureCoordNum)
{
  if( 0<= textureCoordNum && textureCoordNum < 8)
  {
    m_textureCoordNum=textureCoordNum;       
  }      
}

 /*****************************************************************************/
/** Set the texture coordinate buffer of the hardware model instance.
  *
  * This function set the texture coordinate buffer the hardware model instance.
  *
  * @param mapId A integer to the texture stage
  * @param pTextureCoordBuffer A pointer to the texture coord buffer.
  * @param stride  The number of byte to add to find the next element
  *
  *****************************************************************************/


void PiavcaHardwareModel::setTextureCoordBuffer(int mapId, char *pTextureCoordBuffer, int stride)
{
  if( 0 <= mapId && mapId < 8)
  {
    m_pTextureCoordBuffer[mapId] = pTextureCoordBuffer;
    m_textureCoordStride[mapId] = stride;   
  } 
}

 /*****************************************************************************/
/** Set the tangent space buffer of the hardware model instance.
  *
  * This function set the tangent space buffer the hardware model instance.
  *
  * @param mapId A integer to the texture stage
  * @param pTangentSpaceBuffer A pointer to the tangent space buffer.
  * @param stride  The number of byte to add to find the next element
  *
  *****************************************************************************/

void PiavcaHardwareModel::setTangentSpaceBuffer(int mapId, char *pTangentSpaceBuffer, int stride)
{
  if( 0 <= mapId && mapId < 8)
  {
    m_pTangentSpaceBuffer[mapId] = pTangentSpaceBuffer;
    m_tangentSpaceStride[mapId] = stride;   
  } 
}

 /*****************************************************************************/
/** Set the list of core mesh ids to use for building the hardware model instance.
  * setCoreMeshIds must be called before the load method otherwise it will have
  * no effect. If setCoreMeshIds is not called, the hardware model instance will
  * use all the core mesh ids from the core model.
  *
  * @param coreMeshIds a vector of core mesh ids
  *
  *****************************************************************************/

void PiavcaHardwareModel::setCoreMeshIds(const std::vector<int>& coreMeshIds)
{
  m_coreMeshIds = coreMeshIds;
}


 /*****************************************************************************/
/** adds vertex and normal buffers for a morph target
  *
  * @param pMorphVertexBuffer the vertex buffer for the morph target
  * @param pMorphNormalBuffer the normal buffer for the morph target
  *
  *****************************************************************************/

void PiavcaHardwareModel::addMorphBuffer( char *pMorphVertexBuffer, char *pMorphNormalBuffer)
{
	m_MorphVertexBuffers.push_back(pMorphVertexBuffer);
	m_MorphNormalBuffers.push_back(pMorphNormalBuffer);
}


 /*****************************************************************************/
/** Returns the hardware mesh vector.
  *
  * This function returns the vector that contains all hardware mesh of the
  * core mesh instance.
  *
  * @return A reference to the hardware mesh vector.
  *****************************************************************************/


std::vector<PiavcaHardwareModel::HardwareMesh> & PiavcaHardwareModel::getVectorHardwareMesh()
{
  return m_vectorHardwareMesh;
}

 /*****************************************************************************/
/** Returns the hardware mesh vector.
  *
  * This function returns the vector that contains all hardware mesh of the
  * core mesh instance.
  *
  * @return A reference to the hardware mesh vector.
  *****************************************************************************/

const std::vector<PiavcaHardwareModel::HardwareMesh> & PiavcaHardwareModel::getVectorHardwareMesh() const
{
  return m_vectorHardwareMesh;
}

 /*****************************************************************************/
/** Provides access to the ambient color.
  *
  * This function returns the ambient color of the material of the selected
  * hardware mesh.
  *
  * @param pColorBuffer A pointer to the user-provided buffer where the color
  *                     data is written to.
  *****************************************************************************/


void PiavcaHardwareModel::getAmbientColor(unsigned char *pColorBuffer) const
{
    if( m_selectedHardwareMesh >= 0 && m_selectedHardwareMesh < int(m_vectorHardwareMesh.size()) 
    && m_vectorHardwareMesh[m_selectedHardwareMesh].pCoreMaterial!=0)
  {
    const CalCoreMaterial::Color& color = m_vectorHardwareMesh[m_selectedHardwareMesh].pCoreMaterial->getAmbientColor();
    pColorBuffer[0] = color.red;
    pColorBuffer[1] = color.green;
    pColorBuffer[2] = color.blue;
    pColorBuffer[3] = color.alpha;
  }
  else
  {
    pColorBuffer[0] = 0;
    pColorBuffer[1] = 0;
    pColorBuffer[2] = 0;
    pColorBuffer[3] = 0;    
  } 
}

 /*****************************************************************************/
/** Provides access to the diffuse color.
  *
  * This function returns the diffuse color of the material of the selected
  * hardware mesh.
  *
  * @param pColorBuffer A pointer to the user-provided buffer where the color
  *                     data is written to.
  *****************************************************************************/


void PiavcaHardwareModel::getDiffuseColor(unsigned char *pColorBuffer) const
{
    if( m_selectedHardwareMesh >= 0 && m_selectedHardwareMesh < int(m_vectorHardwareMesh.size())
    && m_vectorHardwareMesh[m_selectedHardwareMesh].pCoreMaterial!=0)
  {
    const CalCoreMaterial::Color& color = m_vectorHardwareMesh[m_selectedHardwareMesh].pCoreMaterial->getDiffuseColor();
    pColorBuffer[0] = color.red;
    pColorBuffer[1] = color.green;
    pColorBuffer[2] = color.blue;
    pColorBuffer[3] = color.alpha;
  }
  else
  {
    pColorBuffer[0] = 0;
    pColorBuffer[1] = 0;
    pColorBuffer[2] = 0;
    pColorBuffer[3] = 0;    
  } 
}
 
/*****************************************************************************/
/** Provides access to the specular color.
  *
  * This function returns the specular color of the material of the selected
  * hardware.
  *
  * @param pColorBuffer A pointer to the user-provided buffer where the color
  *                     data is written to.
  *****************************************************************************/

void PiavcaHardwareModel::getSpecularColor(unsigned char *pColorBuffer) const
{
    if( m_selectedHardwareMesh >= 0 && m_selectedHardwareMesh < int(m_vectorHardwareMesh.size())
    && m_vectorHardwareMesh[m_selectedHardwareMesh].pCoreMaterial!=0)
  {
    const CalCoreMaterial::Color& color = m_vectorHardwareMesh[m_selectedHardwareMesh].pCoreMaterial->getSpecularColor();
    pColorBuffer[0] = color.red;
    pColorBuffer[1] = color.green;
    pColorBuffer[2] = color.blue;
    pColorBuffer[3] = color.alpha;
  }
  else
  {
    pColorBuffer[0] = 0;
    pColorBuffer[1] = 0;
    pColorBuffer[2] = 0;
    pColorBuffer[3] = 0;    
  } 
}

/*****************************************************************************/
/** Returns the shininess factor.
  *
  * This function returns the shininess factor of the material of the selected
  * hardware mesh..
  *
  * @return The shininess factor.
  *****************************************************************************/


float PiavcaHardwareModel::getShininess() const
{
    if( m_selectedHardwareMesh >= 0 && m_selectedHardwareMesh < int(m_vectorHardwareMesh.size())
    && m_vectorHardwareMesh[m_selectedHardwareMesh].pCoreMaterial!=0)
  {
    return m_vectorHardwareMesh[m_selectedHardwareMesh].pCoreMaterial->getShininess();
  }
  else
  {
    return 50.0f;
  } 
}


/*****************************************************************************/
/** Returns whether the current mesh has morph targets
  *
  *
  * @return A boolean factor.
  *****************************************************************************/


bool PiavcaHardwareModel::hasMorphTargets() const
{
  if( m_selectedHardwareMesh >= 0 && m_selectedHardwareMesh < int(m_vectorHardwareMesh.size()))
  {
    return m_vectorHardwareMesh[m_selectedHardwareMesh].hasMorphs;
  }
  else
  {
    return false;
  } 
}

 /*****************************************************************************/
/** Returns the bone space rotation of the bone boneId.
  *
  * This function returns the rotation to bring a point into the
  *bone instance space of the bone boneId of the selected hardware mesh.
  *
  * @param boneId A integer with the bone number
  * @return The rotation to bring a point into bone space.
  *****************************************************************************/

const CalQuaternion & PiavcaHardwareModel::getRotationBoneSpace(int boneId, CalSkeleton *pSkeleton) const
{
  const std::vector<CalBone *>& vectorBone = pSkeleton->getVectorBone();
  return vectorBone[m_vectorHardwareMesh[m_selectedHardwareMesh].m_vectorBonesIndices[boneId]]->getRotationBoneSpace();
}

 /*****************************************************************************/
/** Returns the bone space translation of the bone boneId.
  *
  * This function returns the translation to bring a point into the
  *bone instance space of the bone boneId of the selected hardware mesh.
  *
  * @param boneId A integer with the bone number
  * @return The translation to bring a point into bone space.
  *****************************************************************************/


const CalVector & PiavcaHardwareModel::getTranslationBoneSpace(int boneId, CalSkeleton *pSkeleton) const
{
  const std::vector<CalBone *>& vectorBone = pSkeleton->getVectorBone();
  return vectorBone[m_vectorHardwareMesh[m_selectedHardwareMesh].m_vectorBonesIndices[boneId]]->getTranslationBoneSpace();
}

 /*****************************************************************************/
/** Returns the number of hardware meshes.
  *
  * This function returns the number of hardware meshes in the hardware model
  * instance.
  *
  * @return The number of hardware meshes.
  *****************************************************************************/



int PiavcaHardwareModel::getHardwareMeshCount() const
{
  return m_vectorHardwareMesh.size();
}

 /*****************************************************************************/
/** Returns the number of faces.
  *
  * This function returns the number of faces in the selected hardware mesh instance.
  *
  * @return The number of faces.
  *****************************************************************************/


int PiavcaHardwareModel::getFaceCount() const
{
    if( m_selectedHardwareMesh >= 0 && m_selectedHardwareMesh < int(m_vectorHardwareMesh.size()))
  {
    return m_vectorHardwareMesh[m_selectedHardwareMesh].faceCount;
  }
  return 0;   
}

/*****************************************************************************/
/** Returns the number of vertex.
  *
  * This function returns the number of vertex in the selected hardware mesh instance.
  *
  * @return The number of vertex.
  *****************************************************************************/

int PiavcaHardwareModel::getVertexCount() const
{
    if( m_selectedHardwareMesh >= 0 && m_selectedHardwareMesh < int(m_vectorHardwareMesh.size()))
  {
    return m_vectorHardwareMesh[m_selectedHardwareMesh].vertexCount;
  }
  return 0;   
}

/*****************************************************************************/
/** Returns the number of bone.
  *
  * This function returns the number of bone in the selected hardware mesh instance.
  *
  * @return The number of bone.
  *****************************************************************************/


int PiavcaHardwareModel::getBoneCount() const
{
    if( m_selectedHardwareMesh >= 0 && m_selectedHardwareMesh < int(m_vectorHardwareMesh.size()))
  {
    return m_vectorHardwareMesh[m_selectedHardwareMesh].m_vectorBonesIndices.size();
  }
  return 0;   
}

/*****************************************************************************/
/** Returns the base vertex index.
  *
  * This function returns the base vertex index of the selected hardware mesh instance.
  *
  * @return a integer with the base vertex index.
  *****************************************************************************/


int PiavcaHardwareModel::getBaseVertexIndex() const
{
    if( m_selectedHardwareMesh >= 0 && m_selectedHardwareMesh < int(m_vectorHardwareMesh.size()))
  {
    return m_vectorHardwareMesh[m_selectedHardwareMesh].baseVertexIndex;
  }
  return 0;   
}


/*****************************************************************************/
/** Returns the base vertex index from the start of the current set of morphs.
  *
  * This function returns the base vertex index of the selected hardware mesh instance
  * from the start of the current run of meshes with morphs
  *
  * @return a integer with the base vertex index.
  *****************************************************************************/


int PiavcaHardwareModel::getBaseMorphVertexIndex() const
{
    if( m_selectedHardwareMesh >= 0 && m_selectedHardwareMesh < int(m_vectorHardwareMesh.size()))
  {
	  return m_vectorHardwareMesh[m_selectedHardwareMesh].morphBaseVertexIndex;
  }
  return 0;   
}

/*****************************************************************************/
/** Returns the start index.
  *
  * This function returns the start index of the selected hardware mesh instance.
  *
  * @return a integer with the start index.
  *****************************************************************************/


int PiavcaHardwareModel::getStartIndex() const
{
    if( m_selectedHardwareMesh >= 0 && m_selectedHardwareMesh < int(m_vectorHardwareMesh.size()))
  {
    return m_vectorHardwareMesh[m_selectedHardwareMesh].startIndex;
  }
  return 0;   
}


 /*****************************************************************************/
/** Selects a hardware mesh for rendering data queries.
  *
  * This function selects a hardware mesh for further rendering data queries.
  *
  * @param meshId The ID of the hardware mesh that should be used for further rendering
  *               data queries.
  *
  * @return One of the following values:
  *         \li \b true if successful
  *         \li \b false if an error happened
  *****************************************************************************/


bool PiavcaHardwareModel::selectHardwareMesh(size_t meshId)
{
  if( meshId < m_vectorHardwareMesh.size()) 
  {
    m_selectedHardwareMesh=meshId;    
    return true;
  }
  return false;   
}

/*****************************************************************************/
/** Returns the number of faces in the hardware model instance.
  *
  * This function returns the number of faces in the hardware model instance.
  *
  * @return The number of faces.
  *****************************************************************************/


int PiavcaHardwareModel::getTotalFaceCount() const
{
  return m_totalFaceCount;
}

/*****************************************************************************/
/** Returns the number of vertices in the hardware model instance.
  *
  * This function returns the number of vertices in the hardware model instance.
  *
  * @return The number of vertices.
  *****************************************************************************/


int PiavcaHardwareModel::getTotalVertexCount() const
{
  return m_totalVertexCount;
}


 /*****************************************************************************/
/** Provides access to a specified map user data.
  *
  * This function returns the user data stored in the specified map of the
  * material of the selected hardware mesh.
  *
  * @param mapId The ID of the map.
  *
  * @return One of the following values:
  *         \li the user data stored in the specified map
  *         \li \b 0 if an error happened
  *****************************************************************************/

Cal::UserData PiavcaHardwareModel::getMapUserData(int mapId)
{
  if( m_selectedHardwareMesh >= 0 && m_selectedHardwareMesh < int(m_vectorHardwareMesh.size()))
  {
    if(m_vectorHardwareMesh[m_selectedHardwareMesh].pCoreMaterial==0)
      return 0;
    
    // get the map vector
        std::vector<CalCoreMaterial::Map>& vectorMap = m_vectorHardwareMesh[m_selectedHardwareMesh].pCoreMaterial->getVectorMap();
    
    
        // check if the map id is valid
        if((mapId < 0) || (mapId >= (int)vectorMap.size()))
        {
      CalError::setLastError(CalError::INVALID_HANDLE, __FILE__, __LINE__);
      return 0;
        }
        
        return vectorMap[mapId].userData;
  }
  return 0;
}

 /*****************************************************************************/
/** Provides access to a specified map user data.
  *
  * This function returns the user data stored in the specified map of the
  * material of the selected hardware mesh.
  *
  * @param mapId The ID of the map.
  *
  * @return One of the following values:
  *         \li the user data stored in the specified map
  *         \li \b 0 if an error happened
  *****************************************************************************/

const Cal::UserData PiavcaHardwareModel::getMapUserData(int mapId) const
{
  if( m_selectedHardwareMesh >= 0 && m_selectedHardwareMesh < int(m_vectorHardwareMesh.size()))
  {
    if(m_vectorHardwareMesh[m_selectedHardwareMesh].pCoreMaterial==0)
      return 0;

    // get the map vector
    std::vector<CalCoreMaterial::Map>& vectorMap = m_vectorHardwareMesh[m_selectedHardwareMesh].pCoreMaterial->getVectorMap();


    // check if the map id is valid
    if((mapId < 0) || (mapId >= (int)vectorMap.size()))
    {
      CalError::setLastError(CalError::INVALID_HANDLE, __FILE__, __LINE__);
      return 0;
    }

    return vectorMap[mapId].userData;
  }
  return 0;
}

/*****************************************************************************/
/** Compute the information needed to use the hardware model .
*
* This function Compute the information needed to use the hardware model,
* it fill vertex buffers with the model data
*
* @param baseVertexIndex The base vertex Index.
* @param startIndex The start index.
* @param maxBonesPerMesh The maximun of bone by hardware mesh
*
* @return One of the following values:
*         \li \b true if succeed
*         \li \b false if an error happened
*****************************************************************************/



bool PiavcaHardwareModel::load(int baseVertexIndex, int startIndex,int maxBonesPerMesh)
{
  if(m_pVertexBuffer==NULL ||  m_pNormalBuffer ==NULL|| m_pWeightBuffer ==NULL || m_pMatrixIndexBuffer ==NULL)
  {
    CalError::setLastError(CalError::INVALID_HANDLE, __FILE__, __LINE__);
    return false;   
  }

  int mapId;
  for(mapId = 0; mapId < m_textureCoordNum; mapId++)
  {
    if(m_pTextureCoordBuffer[mapId]==NULL)
    {
      CalError::setLastError(CalError::INVALID_HANDLE, __FILE__, __LINE__);
      return false;         
    }  
  } 
  
  m_vectorVertexIndiceUsed.resize(50000);
  int vertexCount=baseVertexIndex;
  int faceIndexCount = startIndex;
        
        // unused.
  //CalCoreSkeleton * pCoreSkeleton = m_pCoreModel->getCoreSkeleton();
  //std::vector< CalCoreBone *>& vectorBone = pCoreSkeleton->getVectorCoreBone();

  // if unspecified, fill with all core mesh ids
  if(m_coreMeshIds.empty())
  {
    for(int coreMeshId = 0; coreMeshId < m_pCoreModel->getCoreMeshCount(); coreMeshId++)
      m_coreMeshIds.push_back(coreMeshId);
  }
    
  bool prevHadMorphs = false;
  int morphStartIndex = 0;

  for(std::vector<int>::iterator meshIdIt = m_coreMeshIds.begin();meshIdIt != m_coreMeshIds.end(); meshIdIt++)
  {
    int meshId = *meshIdIt;
    CalCoreMesh *pCoreMesh = m_pCoreModel->getCoreMesh(meshId);
    int submeshCount= pCoreMesh->getCoreSubmeshCount();
    int submeshId;
    for(submeshId = 0 ;submeshId < submeshCount ; submeshId++)
    {     
      CalCoreSubmesh *pCoreSubmesh = pCoreMesh->getCoreSubmesh(submeshId);
      
      std::vector<CalCoreSubmesh::Vertex>& vectorVertex = pCoreSubmesh->getVectorVertex();
      std::vector<CalCoreSubmesh::Face>& vectorFace = pCoreSubmesh->getVectorFace();
                        // unused.
      //std::vector< std::vector<CalCoreSubmesh::TextureCoordinate> >& vectorTex = pCoreSubmesh->getVectorVectorTextureCoordinate();
      
      HardwareMesh hardwareMesh;

      hardwareMesh.meshId = meshId;
      hardwareMesh.submeshId = submeshId;
      
      hardwareMesh.baseVertexIndex=vertexCount;     
      hardwareMesh.startIndex=faceIndexCount;
      hardwareMesh.m_vectorBonesIndices.clear();  

	  if(pCoreSubmesh->getCoreSubMorphTargetCount() > 0)
	  {
		hardwareMesh.hasMorphs = true;
		if (!prevHadMorphs)
		{
			morphStartIndex = hardwareMesh.baseVertexIndex;
			prevHadMorphs = true;
		}
		hardwareMesh.morphBaseVertexIndex = hardwareMesh.baseVertexIndex - morphStartIndex;
	  }
	  else
	  {
	    prevHadMorphs = false;
		hardwareMesh.hasMorphs = false;
		hardwareMesh.morphBaseVertexIndex = 0;
	  }
      
      hardwareMesh.vertexCount=0;
      hardwareMesh.faceCount=0;     
      
      int startIndex=hardwareMesh.startIndex;
      
      int faceId;     
      for( faceId =0 ;faceId<pCoreSubmesh->getFaceCount();faceId++)
      {
        if(canAddFace(hardwareMesh,vectorFace[faceId],vectorVertex,maxBonesPerMesh))
        {
          m_pIndexBuffer[startIndex+hardwareMesh.faceCount*3]=   addVertex(hardwareMesh,vectorFace[faceId].vertexId[0],pCoreSubmesh,maxBonesPerMesh);
          m_pIndexBuffer[startIndex+hardwareMesh.faceCount*3+1]= addVertex(hardwareMesh,vectorFace[faceId].vertexId[1],pCoreSubmesh,maxBonesPerMesh);
          m_pIndexBuffer[startIndex+hardwareMesh.faceCount*3+2]= addVertex(hardwareMesh,vectorFace[faceId].vertexId[2],pCoreSubmesh,maxBonesPerMesh);
          hardwareMesh.faceCount++;
        }
        else
        {
          vertexCount+=hardwareMesh.vertexCount;
          faceIndexCount+=hardwareMesh.faceCount*3;
          hardwareMesh.pCoreMaterial= m_pCoreModel->getCoreMaterial(pCoreSubmesh->getCoreMaterialThreadId());
          
		  hardwareMesh.usedIndices.clear();

          m_vectorHardwareMesh.push_back(hardwareMesh);
          
          hardwareMesh.baseVertexIndex=vertexCount;
          hardwareMesh.startIndex=faceIndexCount;
          
          hardwareMesh.m_vectorBonesIndices.clear();
          hardwareMesh.vertexCount=0; 
          hardwareMesh.faceCount=0;
          
          startIndex=hardwareMesh.startIndex;
          
          m_pIndexBuffer[startIndex+hardwareMesh.faceCount*3]=   addVertex(hardwareMesh,vectorFace[faceId].vertexId[0],pCoreSubmesh,maxBonesPerMesh);
          m_pIndexBuffer[startIndex+hardwareMesh.faceCount*3+1]= addVertex(hardwareMesh,vectorFace[faceId].vertexId[1],pCoreSubmesh,maxBonesPerMesh);
          m_pIndexBuffer[startIndex+hardwareMesh.faceCount*3+2]= addVertex(hardwareMesh,vectorFace[faceId].vertexId[2],pCoreSubmesh,maxBonesPerMesh);
          hardwareMesh.faceCount++;         
        }
      }
      
      vertexCount+=hardwareMesh.vertexCount;
      faceIndexCount+=hardwareMesh.faceCount*3;
      hardwareMesh.pCoreMaterial= m_pCoreModel->getCoreMaterial(pCoreSubmesh->getCoreMaterialThreadId());
      
      m_vectorHardwareMesh.push_back(hardwareMesh);
      
    }
  }
  
    m_vectorVertexIndiceUsed.clear();


  m_totalFaceCount=0;
  m_totalVertexCount=0;

  for(size_t hardwareMeshId = 0; hardwareMeshId <  m_vectorHardwareMesh.size(); hardwareMeshId++)
  {
    m_totalFaceCount+=m_vectorHardwareMesh[hardwareMeshId].faceCount;
    m_totalVertexCount+=m_vectorHardwareMesh[hardwareMeshId].vertexCount;
  }

    
    return true;
}  



bool PiavcaHardwareModel::canAddFace(HardwareMesh &hardwareMesh, CalCoreSubmesh::Face & face,std::vector<CalCoreSubmesh::Vertex>& vectorVertex, int maxBonesPerMesh) const
{
  size_t boneCount=hardwareMesh.m_vectorBonesIndices.size();
  
  for(unsigned faceIndex=0;faceIndex<3;faceIndex++)
  {
    for(size_t influenceIndex=0;influenceIndex< vectorVertex[face.vertexId[faceIndex]].vectorInfluence.size();influenceIndex++)
    {
      unsigned boneIndex=0;
      while(boneIndex< hardwareMesh.m_vectorBonesIndices.size() 
        && hardwareMesh.m_vectorBonesIndices[boneIndex]!=vectorVertex[face.vertexId[faceIndex]].vectorInfluence[influenceIndex].boneId)
        boneIndex++;
      
      if(boneIndex==hardwareMesh.m_vectorBonesIndices.size())
        boneCount++;
    }
  }
  
  /// @todo Change maxBonesPerMesh to a size_t?
        if(int(boneCount)>maxBonesPerMesh)
    return false;
  
  return true;  
}



int PiavcaHardwareModel::addVertex(HardwareMesh &hardwareMesh, int indice, CalCoreSubmesh *pCoreSubmesh, int maxBonesPerMesh)
{
  int i=0;
  
  if (indice >= hardwareMesh.usedIndices.size())
  {
	hardwareMesh.usedIndices.insert(hardwareMesh.usedIndices.end(), indice - hardwareMesh.usedIndices.size()+1, -1);
  }
  if (hardwareMesh.usedIndices[indice] >= 0)
	  return hardwareMesh.usedIndices[indice];

  //while(i< hardwareMesh.vertexCount && m_vectorVertexIndiceUsed[i]!=indice)
  //  i++;
  
  //if(i != hardwareMesh.vertexCount)
  //  return i;

  i = hardwareMesh.vertexCount;
  hardwareMesh.usedIndices[indice] = i;
  
  std::vector<CalCoreSubmesh::Vertex>& vectorVertex = pCoreSubmesh->getVectorVertex();
  std::vector< std::vector<CalCoreSubmesh::TextureCoordinate> >& vectorvectorTextureCoordinate = pCoreSubmesh->getVectorVectorTextureCoordinate();
  std::vector< std::vector<CalCoreSubmesh::TangentSpace> >& vectorvectorTangentSpace = pCoreSubmesh->getVectorVectorTangentSpace();

  m_vectorVertexIndiceUsed[hardwareMesh.vertexCount]=indice;
  
  memcpy(&m_pVertexBuffer[(hardwareMesh.baseVertexIndex+i)*m_vertexStride],&vectorVertex[indice].position,sizeof(CalVector));

  memcpy(&m_pNormalBuffer[(hardwareMesh.baseVertexIndex+i)*m_normalStride],&vectorVertex[indice].normal,sizeof(CalVector));

  
  if(hardwareMesh.hasMorphs)
  {
	  for (size_t morphIndex = 0; morphIndex < m_MorphVertexBuffers.size(); morphIndex++)
	  {
		  if (morphIndex < pCoreSubmesh->getCoreSubMorphTargetCount())
		  {
			const std::vector<CalCoreSubMorphTarget::BlendVertex> &vectorMorphVertex = pCoreSubmesh->getCoreSubMorphTarget(morphIndex)->getVectorBlendVertex();
			//const CalCoreSubmesh *morphSubmesh = pCoreSubmesh->getCoreSubMorphTarget(morphIndex)->getCoreSubmesh();
			//const std::vector<CalCoreSubmesh::Vertex>& vectorMorphVertex = morphSubmesh->getVectorVertex();
			CalVector position = vectorMorphVertex[indice].position;
			position -= vectorVertex[indice].position;
			CalVector normal = vectorMorphVertex[indice].normal;
			normal -= vectorVertex[indice].normal;

			memcpy(&m_MorphVertexBuffers[morphIndex][(hardwareMesh.morphBaseVertexIndex+i)*m_vertexStride],&position,sizeof(CalVector));
			memcpy(&m_MorphNormalBuffers[morphIndex][(hardwareMesh.morphBaseVertexIndex+i)*m_normalStride],&normal,sizeof(CalVector));
		  }
		  else
		  {
			memset(&m_MorphVertexBuffers[morphIndex][(hardwareMesh.morphBaseVertexIndex+i)*m_vertexStride],0,sizeof(CalVector));
			memset(&m_MorphNormalBuffers[morphIndex][(hardwareMesh.morphBaseVertexIndex+i)*m_normalStride],0,sizeof(CalVector));
		  }
	  }
  }
  

  /// @todo change m_textureCoordName to size_t?
  size_t mapId;
  for(mapId = 0; int(mapId) < m_textureCoordNum; mapId++)
  {
    if( vectorvectorTextureCoordinate.size() > mapId)
      memcpy(&m_pTextureCoordBuffer[mapId][(hardwareMesh.baseVertexIndex+i)*m_textureCoordStride[mapId]],&vectorvectorTextureCoordinate[mapId][indice],sizeof(CalCoreSubmesh::TextureCoordinate));
    else
      memset(&m_pTextureCoordBuffer[mapId][(hardwareMesh.baseVertexIndex+i)*m_textureCoordStride[mapId]],0,sizeof(CalCoreSubmesh::TextureCoordinate));
    
  }

  for(mapId = 0; mapId < 8 ; mapId++)
  {
    if(m_pTangentSpaceBuffer[mapId] != NULL)
    {
      if(vectorvectorTangentSpace.size() > mapId && pCoreSubmesh->isTangentsEnabled(mapId))
        memcpy(&m_pTangentSpaceBuffer[mapId][(hardwareMesh.baseVertexIndex+i)*m_tangentSpaceStride[mapId]],&vectorvectorTangentSpace[mapId][indice],sizeof(CalCoreSubmesh::TangentSpace));
      else
        memset(&m_pTangentSpaceBuffer[mapId][(hardwareMesh.baseVertexIndex+i)*m_tangentSpaceStride[mapId]],0,sizeof(CalCoreSubmesh::TangentSpace));
    }
  }
  
  for(size_t l=0 ; l<4 ; l++)
  {
    if(l < vectorVertex[indice].vectorInfluence.size())
    { 
      int BoneId = vectorVertex[indice].vectorInfluence[l].boneId;

      float newBoneId = (float)addBoneIndice(hardwareMesh,BoneId,maxBonesPerMesh);
    
      memcpy(&m_pWeightBuffer[(hardwareMesh.baseVertexIndex+i)*m_weightStride+l * sizeof(float) ], &vectorVertex[indice].vectorInfluence[l].weight ,sizeof(float));     
      memcpy(&m_pMatrixIndexBuffer[(hardwareMesh.baseVertexIndex+i)*m_matrixIndexStride+l * sizeof(float) ], &newBoneId ,sizeof(float));      
    }
    else
    {
      memset(&m_pWeightBuffer[(hardwareMesh.baseVertexIndex+i)*m_weightStride+l * sizeof(float) ], 0 ,sizeof(float));     
      memset(&m_pMatrixIndexBuffer[(hardwareMesh.baseVertexIndex+i)*m_matrixIndexStride+l * sizeof(float) ], 0 ,sizeof(float));
    }
  }

  hardwareMesh.vertexCount++;
  return i;
}


int PiavcaHardwareModel::addBoneIndice(HardwareMesh &hardwareMesh, int Indice, int maxBonesPerMesh)
{ 
  size_t i=0;
  while(i< hardwareMesh.m_vectorBonesIndices.size()  && hardwareMesh.m_vectorBonesIndices[i]!=Indice)
    i++;

  if( i != hardwareMesh.m_vectorBonesIndices.size())
    return i;

  /// @todo change maxBonesPerMesh to size_t?
        if(int(hardwareMesh.m_vectorBonesIndices.size())<maxBonesPerMesh)
  {
    hardwareMesh.m_vectorBonesIndices.push_back(Indice);
    return i;
  }
  else 
  {
    return -1;
  }
}
