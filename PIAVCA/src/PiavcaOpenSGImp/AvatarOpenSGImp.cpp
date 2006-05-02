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
#include "PiavcaAPI/PiavcaCore.h"

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
	
	//Set up OpenSG nodes for each submesh

	//The cal3d renderer will give us the mesh data we need
	CalRenderer* renderer = new CalRenderer(cal_model->getRenderer());

	int meshCount = renderer->getMeshCount();

	int numBuffers = 1;
	if(doubleBuffer) numBuffers = 2;

	//Set up a vector of OpenSG geometries to store the submeshes
	std::vector< OSG::GeometryPtr > tempVecGeo; tempVecGeo.clear();
	mGeometries.resize(meshCount, tempVecGeo);

	//std::cout << "mesh count " << meshCount <<std::endl;
	for (int i=0; i < meshCount; i++)
	{
		// get each submesh
		int submeshCount = renderer->getSubmeshCount( i );
		for (int j=0; j < submeshCount; j++)
		{
			// create a geometry object to represent the submesh
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
		    OSG::GeoPLengthsPtr length = OSG::GeoPLengthsUI32::create();
   			beginEditCP(length, OSG::GeoPLengthsUI32::GeoPropDataFieldMask);
   				 // the length of a single triangle is four ;-)
    			length->addValue(3.0*faceCount);
    		endEditCP(length, OSG::GeoPLengthsUI32::GeoPropDataFieldMask);

			int v;
			// GeoPositions3f stores the positions of all vertices used in 
    		// this specific geometry core
  			// add a vertex for each vertex in the submesh
			OSG::GeoPositions3fPtr pos = OSG::GeoPositions3f::create();
  			beginEditCP(pos, OSG::GeoPositions3f::GeoPropDataFieldMask);
    			for (v = 0; v < vertexCount; v++)
		        	pos->addValue(OSG::Pnt3f(mVertices[0][i][j][3*v], 
		        				mVertices[0][i][j][3*v+1], 
								mVertices[0][i][j][3*v+2]));
    		endEditCP(pos, OSG::GeoPositions3f::GeoPropDataFieldMask);
			delete mVertices[0][i][j];
			mVertices[0][i][j] = (float *) pos->getData();
		    
		    // normals
		    OSG::GeoNormals3fPtr norms = OSG::GeoNormals3f::create();
		    beginEditCP(norms, OSG::GeoNormals3f::GeoPropDataFieldMask);
		        for (v = 0; v < vertexCount; v++)
		        	norms->addValue(OSG::Vec3f(mNormals[0][i][j][3*v], 
		        				mNormals[0][i][j][3*v+1], 
								mNormals[0][i][j][3*v+1]));
		    endEditCP(norms, OSG::GeoNormals3f::GeoPropDataFieldMask);
			delete mNormals[0][i][j];
			mNormals[0][i][j] = (float *) norms->getData();
			

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

			//create the material
			OSG::SimpleTexturedMaterialPtr mat = OSG::SimpleTexturedMaterial::create();
			unsigned char meshColor[4];
			
			// create the ambient, diffuse and specular colours from 
			// the renderer
			beginEditCP(mat);
    			renderer->getAmbientColor(&meshColor[0]);
    			mat->setAmbient(OSG::Color3f(meshColor[0]/256.0f,
          					meshColor[1]/256.0f,meshColor[2]/256.0f));
    			renderer->getDiffuseColor(&meshColor[0]);
    			mat->setDiffuse(OSG::Color3f(meshColor[0]/256.0f,
    						meshColor[1]/256.0f,meshColor[2]/256.0f));
    			renderer->getSpecularColor(&meshColor[0]);
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

			// set up the geometry object from the data we have just created
		    beginEditCP(mGeometries[i][j]);
			    mGeometries[i][j]->setTypes(type);
			    mGeometries[i][j]->setLengths(length);
			    mGeometries[i][j]->setIndices(indices);
			    mGeometries[i][j]->setPositions(pos);
			    mGeometries[i][j]->setNormals(norms);
			    mGeometries[i][j]->setMaterial(mat);
			    if(renderer->getMapCount() > 0)
			    	mGeometries[i][j]->setTexCoords(texcoords);
				mGeometries[i][j]->setDlistCache(false);
    		endEditCP(mGeometries[i][j]);
			
		    OSG::NodePtr geoNode = OSG::Node::create();
		    beginEditCP(geoNode);
		        geoNode->setCore(mGeometries[i][j]);
		    endEditCP(geoNode);
		    
		    
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
	static float prevTime = Piavca::Core::getCore()->getTime();
	static int framecount = 0;
	static float cal3dTime = 0;
	static float meshTime = 0;

	float time1 = Piavca::Core::getCore()->getTime();
	AvatarCal3DImp::prerender();
	float time2 = Piavca::Core::getCore()->getTime();
	cal3dTime += time2 - time1;
	//CalRenderer* renderer = new CalRenderer(cal_model->getRenderer());

	//// go through all the meshes, copying the data into the
	//// opensg objects
	//int meshCount = renderer->getMeshCount();
	//for (int i=0; i < meshCount; i++)
	//{
	//	int submeshCount = renderer->getSubmeshCount( i );
	//	for (int j=0; j < submeshCount; j++)
	//	{
	//		renderer->selectMeshSubmesh( i, j );

	//		// The number of vertices (equal numbers of vertices, normals, and texture coords)
	//		int vertexCount = renderer->getVertexCount();
	//		//std::cout << "vertex count " << vertexCount << std::endl;
	//		int v;
	//		// the position data field
	//	    OSG::GeoPositions3fPtr pos = OSG::GeoPositions3fPtr::dcast(mGeometries[i][j]->getPositions());
	//		// copy all the vertex positions
 // 			beginEditCP(pos, OSG::GeoPositions3f::GeoPropDataFieldMask);
 //   			for (v = 0; v < vertexCount; v++)
	//				pos->setValue(OSG::Pnt3f(mVertices[0][i][j][3*v], 
	//	        				mVertices[0][i][j][3*v+1], 
	//							mVertices[0][i][j][3*v+2]), v);
 //   		endEditCP(pos, OSG::GeoPositions3f::GeoPropDataFieldMask);
	//	    
	//	    // update normals
	//	    OSG::GeoNormals3fPtr norms = OSG::GeoNormals3fPtr::dcast(mGeometries[i][j]->getNormals());
	//	    beginEditCP(norms, OSG::GeoNormals3f::GeoPropDataFieldMask);
	//	        for (v = 0; v < vertexCount; v++)
	//				norms->setValue(OSG::Vec3f(mNormals[0][i][j][3*v], 
	//	        				mNormals[0][i][j][3*v+1], 
	//							mNormals[0][i][j][3*v+1]), v);
	//	    endEditCP(norms, OSG::GeoNormals3f::GeoPropDataFieldMask);	
	//	}
	//}
 //  delete renderer;
   float time3 = Piavca::Core::getCore()->getTime();
	meshTime += time3 - time2;
   
	/*framecount ++;
	float time = Piavca::Core::getCore()->getTime();
	if((time - prevTime) > 10.0)
	{
		std::cout << "framerate " << framecount/(time - prevTime) 
			<< " cal3d time " << cal3dTime/framecount  
			<< " mesh time " << meshTime/framecount << std::endl;
		framecount = 0;
		cal3dTime = 0.0;
		meshTime = 0.0;
		prevTime = time;
	}*/
};
