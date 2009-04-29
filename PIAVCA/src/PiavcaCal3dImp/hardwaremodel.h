//****************************************************************************//
// hardwaremodel.h                                                         //
// Copyright (C) 2004 Desmecht Laurent                                        //
//****************************************************************************//
// This library is free software; you can redistribute it and/or modify it    //
// under the terms of the GNU Lesser General Public License as published by   //
// the Free Software Foundation; either version 2.1 of the License, or (at    //
// your option) any later version.                                            //
//****************************************************************************//

#ifndef HARDWAREMODEL_H
#define HARDWAREMODEL_H


#include "PiavcaAPI/PiavcaDefs.h"

#include "cal3d/global.h"
#include "cal3d/coresubmesh.h"


class CalCoreModel;
class CalSkeleton;
class CalCoreMaterial;

namespace Piavca {

class PIAVCA_DECL PiavcaHardwareModel
{
public:
  struct HardwareMesh
  {
    std::vector<int> m_vectorBonesIndices;
    
    int baseVertexIndex;
	int morphBaseVertexIndex;
    int vertexCount;
    int startIndex;
    int faceCount;
    CalCoreMaterial *pCoreMaterial;
	bool hasMorphs;

	std::vector <int> usedIndices;

    int meshId,submeshId;
  };

public:
  PiavcaHardwareModel(CalCoreModel *pCoreModel);
  ~PiavcaHardwareModel() { }
  
  void setVertexBuffer( char *pVertexBuffer, int stride); 
  void setIndexBuffer( CalIndex *pIndexBuffer); 
  void setNormalBuffer( char *pNormalBuffer, int stride); 
  void setWeightBuffer( char *pWeightBuffer, int stride); 
  void setMatrixIndexBuffer( char *pMatrixIndexBuffer, int stride); 
  void setTextureCoordNum(int textureCoordNum);
  void setTextureCoordBuffer(int mapId, char *pTextureCoordBuffer, int stride);
  void setTangentSpaceBuffer(int mapId, char *pTangentSpaceBuffer, int stride);
  void setCoreMeshIds(const std::vector<int>& coreMeshIds);
  void addMorphBuffer( char *pMorphVertexBuffer, char *pMorphNormalBuffer);

  bool load(int baseVertexIndex, int startIndex,int maxBonesPerMesh);
      
  std::vector<HardwareMesh> & getVectorHardwareMesh();
  const std::vector<HardwareMesh> & getVectorHardwareMesh() const;
  void getAmbientColor(unsigned char *pColorBuffer) const;
  void getDiffuseColor(unsigned char *pColorBuffer) const;
  void getSpecularColor(unsigned char *pColorBuffer) const;
  const CalQuaternion & getRotationBoneSpace(int boneId, CalSkeleton *pSkeleton) const;
  const CalVector & getTranslationBoneSpace(int boneId, CalSkeleton *pSkeleton) const;
  
  bool hasMorphTargets() const;

  float getShininess() const;
  
  int getHardwareMeshCount() const;
  int getFaceCount() const;
  int getVertexCount() const;
  int getBoneCount() const;

  int getBaseVertexIndex() const;
  int getBaseMorphVertexIndex() const;
  int getStartIndex() const;

  int getTotalFaceCount() const;
  int getTotalVertexCount() const;

  Cal::UserData getMapUserData(int mapId);
  const Cal::UserData getMapUserData(int mapId) const;

  
  bool selectHardwareMesh(size_t meshId);
  
private:
  bool canAddFace(HardwareMesh &hardwareMesh, CalCoreSubmesh::Face & face,std::vector<CalCoreSubmesh::Vertex>& vectorVertex, int maxBonesPerMesh) const;
  int  addVertex(HardwareMesh &hardwareMesh, int indice , CalCoreSubmesh *pCoreSubmesh, int maxBonesPerMesh);
  int  addBoneIndice(HardwareMesh &hardwareMesh, int Indice, int maxBonesPerMesh);  
    

private:
  
  std::vector<HardwareMesh> m_vectorHardwareMesh;
  std::vector<CalIndex>     m_vectorVertexIndiceUsed;
  int                       m_selectedHardwareMesh;
  std::vector<int>          m_coreMeshIds;
  CalCoreModel             *m_pCoreModel;
  
  
  char *m_pVertexBuffer;
  int   m_vertexStride;
  char *m_pNormalBuffer;
  int   m_normalStride;
  char *m_pWeightBuffer;
  int   m_weightStride;
  char *m_pMatrixIndexBuffer;
  int   m_matrixIndexStride;
  char *m_pTextureCoordBuffer[8];
  int   m_textureCoordStride[8];
  int   m_textureCoordNum;  
  char *m_pTangentSpaceBuffer[8];
  int   m_tangentSpaceStride[8];

  std::vector<char *> m_MorphVertexBuffers;
  std::vector<char *> m_MorphNormalBuffers;
  
  CalIndex *m_pIndexBuffer;

  int m_totalVertexCount;
  int m_totalFaceCount;
};

};


#endif //HARDWAREMODEL_H
