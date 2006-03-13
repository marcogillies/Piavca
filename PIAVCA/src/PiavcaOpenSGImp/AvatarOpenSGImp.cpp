/* LICENCE BLOCK
AvatarOpenSGImp.cpp
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

#include "AvatarOpenSGImp.h"
#include "TextureHandlerOpenSG.h"
#include <OpenSG/OSGGeometry.h>
#include <OpenSG/OSGSimpleTexturedMaterial.h>
#include <OpenSG/OSGGeoFunctions.h>

using namespace Piavca;

AvatarOpenSGImp::AvatarOpenSGImp(tstring avatarId, TextureHandler *_textureHandler, bool bailOnMissedJoints, const Vec &Position, const Quat &Orientation)
	:AvatarCal3DImp(avatarId, _textureHandler, bailOnMissedJoints, Position, Orientation)
{
	//! set up the root node and transform
	rootNode = OSG::Node::create();
	rootTrans = OSG::Transform::create();
	OSG::Matrix m;
	// no rotation at the beginning
	m.setIdentity();
	// set the core to the matrix we created
	beginEditCP(rootTrans, OSG::Transform::MatrixFieldMask);
	    rootTrans->setMatrix(m);
	endEditCP(rootTrans, OSG::Transform::MatrixFieldMask);
	// now "insert" the core into the node
	beginEditCP(rootNode);
	    rootNode->setCore(rootTrans);
	    // add the torus as a child to
	    // the transformation node
	    //transNode->addChild(torus);
	endEditCP(rootNode);
	
	//Find the amounts of memory we will need for each submesh
	CalRenderer* renderer = new CalRenderer(cal_model->getRenderer());

	int meshCount = renderer->getMeshCount();

	int numBuffers = 1;
	if(doubleBuffer) numBuffers = 2;

	//Initialize mVertices, mNormals, mFaces, mTextureCoordCounts sizes for
	//the mesh count with dummy vectors
	std::vector< OSG::GeometryPtr > tempVecGeo; tempVecGeo.clear();
	//std::vector< std::vector< OSG::GeometryPtr > > tempVecVecGeo; tempVecGeo.clear();

	//mGeometries.resize(numBuffers, tempVecVecF);

	mGeometries.resize(meshCount, tempVecGeo);

	//std::cout << "mesh count " << meshCount <<std::endl;
	for (int i=0; i < meshCount; i++)
	{
		int submeshCount = renderer->getSubmeshCount( i );

		//std::cout << "submesh count " << submeshCount <<std::endl;
		for (int j=0; j < submeshCount; j++)
		{
			mGeometries[i].push_back(OSG::Geometry::create());
			std::cout << "submesh " << i << " " << j << " " << std::endl;
			renderer->selectMeshSubmesh( i, j );

			// GeoPTypes defines the types of primitives to be used
			// in this case triangles
    		OSG::GeoPTypesPtr type = OSG::GeoPTypesUI8::create();
    		beginEditCP(type, OSG::GeoPTypesUI8::GeoPropDataFieldMask);
    			type->addValue(GL_TRIANGLES);
		    endEditCP(type, OSG::GeoPTypesUI8::GeoPropDataFieldMask);
			
			// The number of vertices (equal numbers of vertices, normals, and texture coords)
			int vertexCount = renderer->getVertexCount();
			int faceCount = renderer->getFaceCount();
		    //std::cout << "vertex count " << vertexCount << std::endl;
   			OSG::GeoPLengthsPtr length = OSG::GeoPLengthsUI32::create();
   			beginEditCP(length, OSG::GeoPLengthsUI32::GeoPropDataFieldMask);
   				 // the length of a single quad is four ;-)
    			length->addValue(3.0*faceCount);
    		endEditCP(length, OSG::GeoPLengthsUI32::GeoPropDataFieldMask);

			int v;
			// GeoPositions3f stores the positions of all vertices used in 
    		// this specific geometry core
  			OSG::GeoPositions3fPtr pos = OSG::GeoPositions3f::create();
  			beginEditCP(pos, OSG::GeoPositions3f::GeoPropDataFieldMask);
    			for (v = 0; v < vertexCount; v++)
		        	pos->addValue(OSG::Pnt3f(mVertices[0][i][j][3*v], 
		        				mVertices[0][i][j][3*v+1], 
								mVertices[0][i][j][3*v+2]));
    		endEditCP(pos, OSG::GeoPositions3f::GeoPropDataFieldMask);
		    
		    // normals
		    OSG::GeoNormals3fPtr norms = OSG::GeoNormals3f::create();
		    beginEditCP(norms, OSG::GeoNormals3f::GeoPropDataFieldMask);
		        for (v = 0; v < vertexCount; v++)
		        	norms->addValue(OSG::Vec3f(mNormals[0][i][j][3*v], 
		        				mNormals[0][i][j][3*v+1], 
								mNormals[0][i][j][3*v+1]));
		    endEditCP(norms, OSG::GeoNormals3f::GeoPropDataFieldMask);
			

			// the index buffer
			OSG::GeoIndicesUI32Ptr indices = OSG::GeoIndicesUI32::create();
		    beginEditCP(indices, OSG::GeoIndicesUI32::GeoPropDataFieldMask);
		        for (int ind = 0; ind < faceCount; ind++)
		        {
			        indices->addValue(mFaces[0][i][j][3*ind]);
			        indices->addValue(mFaces[0][i][j][3*ind+1]);   
			        indices->addValue(mFaces[0][i][j][3*ind+2]);   
		        }   
		    endEditCP(indices, OSG::GeoIndicesUI32::GeoPropDataFieldMask);

			
			OSG::SimpleTexturedMaterialPtr mat = OSG::SimpleTexturedMaterial::create();
			unsigned char meshColor[4];
			
			beginEditCP(mat);
    			renderer->getAmbientColor(&meshColor[0]);
    			//std::cout << "Ambient " << (int)meshColor[0] << " " 
    			//						<< (int)meshColor[1] << " " 
    			//						<< (int)meshColor[2] << std::endl; 
          		mat->setAmbient(OSG::Color3f(meshColor[0]/256.0f,
          					meshColor[1]/256.0f,meshColor[2]/256.0f));
    			renderer->getDiffuseColor(&meshColor[0]);
    			//std::cout << "Diffuse " << (int)meshColor[0] << " " 
    			//						<< (int)meshColor[1] << " " 
    			//						<< (int)meshColor[2] << std::endl; 
          		mat->setDiffuse(OSG::Color3f(meshColor[0]/256.0f,
    						meshColor[1]/256.0f,meshColor[2]/256.0f));
    			renderer->getSpecularColor(&meshColor[0]);
    			//std::cout << "Specular " << (int)meshColor[0] << " " 
    			//						<< (int)meshColor[1] << " " 
    			//						<< (int)meshColor[2] << std::endl; 
          		mat->setSpecular(OSG::Color3f(meshColor[0]/256.0f,
    						meshColor[1]/256.0f,meshColor[2]/256.0f));
    			float shininess = /*50.0f; */renderer->getShininess();
          		mat->setShininess(shininess);
			endEditCP(mat);
			
			OSG::GeoTexCoords2fPtr texcoords = OSG::GeoTexCoords2f::create();
			// texture coordinates
		    if(renderer->getMapCount() > 0)
			{
				GLuint textureId = (long)renderer->getMapUserData(0);
				OSG::ImagePtr image = dynamic_cast<TextureHandlerOpenSG *>(textureHandler)->getImagePtr(textureId);
				beginEditCP(mat);
	          		mat->setImage(image);
				endEditCP(mat);
				
		   	 	beginEditCP(norms, OSG::GeoTexCoords2f::GeoPropDataFieldMask);
		        	for (v = 0; v < vertexCount; v++)
		        		texcoords->addValue(OSG::Vec2f(mTextureCoords[0][i][j][2*v], 
		        					mTextureCoords[0][i][j][2*v+1]));
					//std::cout << v << std::endl;
		    	endEditCP(norms, OSG::GeoTexCoords2f::GeoPropDataFieldMask);
			};

			// need to sort out textures
			// set the texture coordinate buffer and state if necessary
			//if(renderer->getMapCount() > 0)
			//{
			//	mTextureCoords[buffer][i][j] = new float[vertexCount * 2];
			//}
			//else
			//{
				//If there are no texture coords, allocate space for a dummy value
			//	mTextureCoords[buffer][i][j] = new float[1];
			//}

			//GeometryPtr mGeometries[i][j] = Geometry::create();
		    beginEditCP(mGeometries[i][j]);
			    mGeometries[i][j]->setTypes(type);
			    mGeometries[i][j]->setLengths(length);
			    mGeometries[i][j]->setIndices(indices);
			    mGeometries[i][j]->setPositions(pos);
			    mGeometries[i][j]->setNormals(norms);
			    mGeometries[i][j]->setMaterial(mat);
			    if(renderer->getMapCount() > 0)
			    	mGeometries[i][j]->setTexCoords(texcoords);
    		endEditCP(mGeometries[i][j]);
			
		    OSG::NodePtr geoNode = OSG::Node::create();
		    beginEditCP(geoNode);
		        geoNode->setCore(mGeometries[i][j]);
		    endEditCP(geoNode);
		    
//		    OSG::NodePtr geoNode = OSG::calcVertexNormalsGeo(mGeometries[i][j], 1.0);
//		    //SimpleMaterialPtr mat = SimpleMaterial::create();
		    
//		    OSG::GeometryPtr geo = OSG::GeometryPtr::dcast(geoNode->getCore());
//		    beginEditCP(geo);
//		        geo->setMaterial(mat);
//		    endEditCP(geo);
		    
		    //OSG::NodePtr box = OSG::makeBox(150,38,150, 2, 2, 2);
			beginEditCP(rootNode);
			    rootNode->addChild(geoNode);
			endEditCP(rootNode);
			
		}
	}
	std::cout << "index size " << sizeof(CalIndex) << std::endl;
   delete renderer;
};

void	AvatarOpenSGImp::setRootPosition		(const Vec &Position)
{
	OSG::Matrix m = rootTrans->getMatrix();
	m.setTranslate(Position[0], Position[1], Position[2]);
	beginEditCP(rootTrans, OSG::Transform::MatrixFieldMask);
	    rootTrans->setMatrix(m);
	endEditCP(rootTrans, OSG::Transform::MatrixFieldMask);
};
Vec		AvatarOpenSGImp::getRootPosition		()
{
	OSG::Matrix m = rootTrans->getMatrix();
	OSG::Vec3f translation;
	OSG::Quaternion rotation; 
	OSG::Vec3f scaleFactor; 
	OSG::Quaternion scaleOrientation;
	m.getTransform (translation, rotation, scaleFactor, scaleOrientation);	
	return Vec(translation[0], translation[1], translation[2]);
};
void	AvatarOpenSGImp::setRootOrientation		(const Quat &Orientation)
{
	OSG::Matrix m = rootTrans->getMatrix();
	OSG::Quaternion q;
	q.setValueAsQuat(Orientation.I(), Orientation.J(), Orientation.K(), Orientation.S());
	m.setRotate(q);
	beginEditCP(rootTrans, OSG::Transform::MatrixFieldMask);
	    rootTrans->setMatrix(m);
	endEditCP(rootTrans, OSG::Transform::MatrixFieldMask);
};
Quat	AvatarOpenSGImp::getRootOrientation		()
{
	OSG::Matrix m = rootTrans->getMatrix();
	OSG::Vec3f translation;
	OSG::Quaternion rotation; 
	OSG::Vec3f scaleFactor; 
	OSG::Quaternion scaleOrientation;
	m.getTransform (translation, rotation, scaleFactor, scaleOrientation);	
	return Quat(rotation.w(), rotation.x(), rotation.y(), rotation.z());
};

void AvatarOpenSGImp::prerender()
{
//	OSG::Pnt3f c, max, min;
//	OSG::DynamicVolume &vol = getNode()->getVolume(false);
//	vol.getCenter(c);
//	vol.getBounds(min, max);
//	std::cout << "centre " << c << " ";
//	std::cout << " min " << min << " ";
//	std::cout << " max " << max << std::endl;
	
	AvatarCal3DImp::prerender();
	//Find the amounts of memory we will need for each submesh
	CalRenderer* renderer = new CalRenderer(cal_model->getRenderer());

	int meshCount = renderer->getMeshCount();
	//std::cout << "mesh count " << meshCount <<std::endl;
	for (int i=0; i < meshCount; i++)
	{
		int submeshCount = renderer->getSubmeshCount( i );
		//std::cout << "submesh count " << submeshCount <<std::endl;
		for (int j=0; j < submeshCount; j++)
		{
			//std::cout << "submesh " << i << " " << j << " " << std::endl;
			renderer->selectMeshSubmesh( i, j );


			//if(j > 10) break;
						
			// The number of vertices (equal numbers of vertices, normals, and texture coords)
			int vertexCount = renderer->getVertexCount();
			//std::cout << "vertex count " << vertexCount << std::endl;
			int v;
			// the position data field
		    OSG::GeoPositions3fPtr pos = OSG::GeoPositions3fPtr::dcast(mGeometries[i][j]->getPositions());
			// GeoPositions3f stores the positions of all vertices used in 
    		// this specific geometry core
  			beginEditCP(pos, OSG::GeoPositions3f::GeoPropDataFieldMask);
    			for (v = 0; v < vertexCount; v++)
		        	pos->setValue(OSG::Pnt3f(mVertices[0][i][j][3*v], 
		        				mVertices[0][i][j][3*v+1], 
								mVertices[0][i][j][3*v+2]), v);
    		endEditCP(pos, OSG::GeoPositions3f::GeoPropDataFieldMask);
		    
		    // update normals
		    OSG::GeoNormals3fPtr norms = OSG::GeoNormals3fPtr::dcast(mGeometries[i][j]->getNormals());
		    beginEditCP(norms, OSG::GeoNormals3f::GeoPropDataFieldMask);
		        for (v = 0; v < vertexCount; v++)
		        	norms->setValue(OSG::Vec3f(mNormals[0][i][j][3*v], 
		        				mNormals[0][i][j][3*v+1], 
								mNormals[0][i][j][3*v+1]), v);
		    endEditCP(norms, OSG::GeoNormals3f::GeoPropDataFieldMask);

			// the index buffer
//			int faceCount = renderer->getFaceCount();
//		    OSG::GeoIndicesUI32Ptr indices = OSG::GeoIndicesUI32Ptr::dcast(mGeometries[i][j]->getIndices());
//		    beginEditCP(indices, OSG::GeoIndicesUI32::GeoPropDataFieldMask);
//		        for (int ind = 0; ind < faceCount; ind++)
//		        {
//			        indices->setValue(mFaces[0][i][j][3*ind], 3*ind);
//			        indices->setValue(mFaces[0][i][j][3*ind+1], 3*ind+1);   
//			        indices->setValue(mFaces[0][i][j][3*ind+2], 3*ind+2);   
//		        }   
//		    endEditCP(indices, OSG::GeoIndicesUI32::GeoPropDataFieldMask);
			
		}
	}
   delete renderer;
};
