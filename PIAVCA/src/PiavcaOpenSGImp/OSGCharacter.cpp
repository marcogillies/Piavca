/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *               Copyright (C) 2000-2002 by the OpenSG Forum                 *
 *                                                                           *
 *                            www.opensg.org                                 *
 *                                                                           *
 *   contact: dirk@opensg.org, gerrit.voss@vossg.org, jbehr@zgdv.de          *
 *                                                                           *
\*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*\
 *                                License                                    *
 *                                                                           *
 * This library is free software; you can redistribute it and/or modify it   *
 * under the terms of the GNU Library General Public License as published    *
 * by the Free Software Foundation, version 2.                               *
 *                                                                           *
 * This library is distributed in the hope that it will be useful, but       *
 * WITHOUT ANY WARRANTY; without even the implied warranty of                *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU         *
 * Library General Public License for more details.                          *
 *                                                                           *
 * You should have received a copy of the GNU Library General Public         *
 * License along with this library; if not, write to the Free Software       *
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.                 *
 *                                                                           *
\*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*\
 *                                Changes                                    *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                                                                           *
\*---------------------------------------------------------------------------*/

//---------------------------------------------------------------------------
//  Includes
//---------------------------------------------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include <sstream> //for float to string conversion


#include <cal3d/cal3d.h>


#include <OSGConfig.h>
#include <OSGRenderAction.h>
#include <OSGSHLChunk.h>
#include <OSGWindow.h>
#include <OSGGLEXT.h>

#include "OSGCharacterModel.h"
#include "OSGCharacter.h"


OSG_USING_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class osg::Character
An instance of a CharacterModel.        
*/

/***************************************************************************\
 *                           Class variables                               *
\***************************************************************************/

const int MAXBONESPERMESH = 29;


/*! OpenGL extension indices.
*/
UInt32 Character::_extMultitexture;
UInt32 Character::_arbSHL100;

/*! OpenGL extension function indices.
*/
UInt32 Character::_funcglClientActiveTextureARB;
UInt32 Character::_funcglGetUniformLocationARB;
UInt32 Character::_funcglUniformMatrix4fvARB;

/***************************************************************************\
 *                           Class methods                                 *
\***************************************************************************/

void Character::initMethod (void)
{
    RenderAction::registerEnterDefault(getClassType(),
        osgTypedMethodFunctor2BaseCPtrRef<Action::ResultE, CharacterPtr,
              CNodePtr, Action *>(&Character::renderActionHandler));
}


/***************************************************************************\
 *                           Instance methods                              *
\***************************************************************************/

/*-------------------------------------------------------------------------*\
 -  private                                                                 -
\*-------------------------------------------------------------------------*/

/*----------------------- constructors & destructors ----------------------*/

Character::Character(void) :
    Inherited(),
    _calModel(NULL)
{
    _extMultitexture        = 
        Window::registerExtension("GL_ARB_multitexture");
    _arbSHL100        = 
        Window::registerExtension("GL_ARB_shading_language_100");
        
    _funcglClientActiveTextureARB = Window::registerFunction(
                            OSG_DLSYM_UNDERSCORE"glClientActiveTextureARB",
                            _extMultitexture);
        
    _funcglGetUniformLocationARB = Window::registerFunction(
                            OSG_DLSYM_UNDERSCORE"glGetUniformLocationARB",
                            _arbSHL100);
        
    _funcglUniformMatrix4fvARB = Window::registerFunction(
                            OSG_DLSYM_UNDERSCORE"glUniformMatrix4fvARB",
                            _arbSHL100);
}

Character::Character(const Character &source) :
    Inherited(source),
    _calModel(NULL)
{
}

Character::~Character(void)
{
    if(_calModel)
        delete _calModel;
}

// Little helper macro for growing memory block.
#undef c3dalloc
#define c3dalloc(var, count, type, mult)            \
if(count * mult >= var.size())                      \
{                                                   \
    var.resize(count * mult);                       \
}

/*----------------------------- class specific ----------------------------*/

void Character::changed(BitVector whichField, UInt32 origin)
{
    Inherited::changed(whichField, origin);
    
    if(whichField & ModelFieldMask)
    {
        if(_calModel)
            delete _calModel;
        
        CalCoreModel *core = getModel()->_coreModel;
        
        _calModel = new CalModel(core);
        
        // Attach meshes
        for(int m = 0; m < core->getCoreMeshCount(); m++)
        {
            _calModel->attachMesh(m);
        }
        _calModel->setMaterialSet(0);
        
        
        if(core->getCoreAnimationCount() > 0)
        {
            if(core->getCoreAnimationCount() > 1)
            {
                _calModel->getMixer()->executeAction(
                        getCurrentAnimation(), 0.0f, getBlendTime());
            }
            else
            {
                _calModel->getMixer()->blendCycle(
                        getCurrentAnimation(), 1.0f, getBlendTime());
            }
        }
        
        //_calModel->update(0.);
        
      	// Update the volume
        DynamicVolume vol;
        vol.setEmpty();
			
				CalRenderer *crend = _calModel->getRenderer();

        // begin the rendering loop
        if(!crend->beginRendering())
        {
            FWARNING(("Character::changed: beginRendering failed!\n"));
            return;
        }

        std::vector<CalMesh *>& mvec = _calModel->getVectorMesh();
        
        for(Int32 meshind = 0; meshind < mvec.size(); ++meshind)
        {
            CalMesh *mesh = mvec[meshind];
            
            for(Int32 submeshind = 0; submeshind < mesh->getSubmeshCount(); 
                submeshind++)
            {
                CalSubmesh *sm = mesh->getSubmesh(submeshind);
               
                if(!crend->selectMeshSubmesh(meshind, submeshind))
                {
                    FWARNING(("Character::changed: "
                              "selectMeshSubmesh failed!\n"));
                    return;
                }

                UInt32 vcount = sm->getVertexCount();
                c3dalloc(_vertices, vcount, float, 3);
                crend->getVertices(&_vertices[0]);
                    
                for(int i = 0; i < vcount * 3; i += 3)
                {
                    Pnt3f p(_vertices[i], _vertices[i+1], _vertices[i+2]);
                    vol.extendBy(p);
                }
            }
        }

        crend->endRendering();
        
        CharacterPtr cp(this);     
        beginEditCP(cp, ModelVolumeFieldMask);
        cp->setModelVolume(vol);
        endEditCP(cp, ModelVolumeFieldMask);
        
        _drawWrappers.clear();
    }
    
    if(whichField & CurrentAnimationFieldMask)
    {
        for(int i = 0; i < getModel()->getNumAnimations(); ++i)
        {
            _calModel->getMixer()->blendCycle(i, 
                            (i == getCurrentAnimation())?1.0f:0.0f, 
                            getBlendTime());
        }
    }
    
    if(whichField & UseShaderForGeometryFieldMask)
    {
        if(getUseShaderForGeometry())
        {
            if(getModel()->getShader() == NullFC)
            {
                FNOTICE(("Character::changed: no shader set, not switching!\n"));
            }
            else
            {
                _calModel->disableInternalData();
                getModel()->activateShader();
                initializeHWData();
            }
        }
        else
        {
            // Can't go back, Cal3D doesn't support it.
            //_calModel->enableInternalData();
            FWARNING(("Character::changed: can't turn shader off!\n"));
            getModel()->deactivateShader();
            freeHWData();
        }
    }
    
    //******************************************* boneQuats manager ************************************************
    if(whichField & BoneQuatsFieldMask) {
    		
    		std::cout << "debug 1 " << std::endl;
    		
    		//get all bones in cal3d model (used for loading and manipulation
    		CalSkeleton *skel = _calModel->getSkeleton();
				std::vector<CalBone *>& allCalBones = skel->getVectorBone();
    	
    		//if we haven't populated the boneQuats field yet...
    		if (getBoneQuats().empty()) {
    		
    				std::cout << "Populating boneQuats field..." << std::endl;
    			
	    			//for all bones
						for(int i = 0; i < (int) allCalBones.size(); i++) {
 				
 								//get one bone
	 							CalBone *currentBone = allCalBones[i];
  						
	  						//get currentBone quaternion (cal3d quaternion type)
	  						CalQuaternion cal3dBoneQuat = currentBone->getRotation();
	  		
	  	 					//convert cal3dBoneQuat to OpenSG Quaternion type
    						Quaternion openSGBoneQuat;
		    				openSGBoneQuat.setValueAsQuat(cal3dBoneQuat.x, cal3dBoneQuat.y, cal3dBoneQuat.z, cal3dBoneQuat.w);

	   						//add current bone (openSGBoneQuat) to boneQuats field vector
				   			getBoneQuats().push_back(openSGBoneQuat);
			   			
				   			std::cout << "Stored BoneQuat[" << i << "] = " << getBoneQuats()[i] << " *** Source: _calModel bone[" << i << "] = " << cal3dBoneQuat.x << ", " << cal3dBoneQuat.y << ", " << cal3dBoneQuat.z << ", " << cal3dBoneQuat.w << std::endl;
    				};
  			};
 				
		  	//if boneQuats field is populated, this function is called for bone manipulation...
		  	if(!getBoneQuats().empty()) {

			     	for(int i = 0; i < (int) allCalBones.size(); i++) {

								CalBone *currentBone = allCalBones[i];

								//get currentBone quaternion (cal3d quaternion type)
	  						CalQuaternion cal3dBoneQuat = currentBone->getRotation();
						
								//convert cal3d quaternion type into OpenSG Quaternion
								Quaternion openSGQuatfromCal3d;
   							openSGQuatfromCal3d.setValueAsQuat(cal3dBoneQuat.x, cal3dBoneQuat.y, cal3dBoneQuat.z, cal3dBoneQuat.w);

								if (openSGQuatfromCal3d != getBoneQuats()[i]) {
										
										std::cout << "Updating cal3d character from boneQuats field..." << std::endl;
																				
										float calx = getBoneQuats()[i][0];
										float caly = getBoneQuats()[i][1];
										float calz = getBoneQuats()[i][2];
										float calw = getBoneQuats()[i][3];
										
										CalQuaternion copyQuat(calx, caly, calz, calw);
										
										//set cal3d object rotation
  									CalBone *boneMod = skel->getBone(i);
  									boneMod->setRotation(copyQuat);

	  								CalQuaternion finalQuat = boneMod->getRotation();
	 									std::cout << "Modified Cal3d character boneQuat[" << i << "]: " << finalQuat.x << ", " << finalQuat.y  << ", " << finalQuat.z << ", " << finalQuat.w << std::endl;
		  					};
  					};
    		};
    };
		//******************************************* end of boneQuats manager ********************************************
		
};
    

void Character::dump(      UInt32    , 
                         const BitVector ) const
{
    SLOG << "Dump Character NI" << std::endl;
}


void Character::adjustVolume(Volume & volume)
{
    volume.extendBy(getModelVolume());
}

void Character::initializeHWData(void)
{
    const int nvert = 30000;
    const int nind  = 50000;
    
    // Switch to hardware...  
    _calModel->disableInternalData();
    
    
    // There is no easy way to find the number beforehand. 
    // Let's just hope these are big enough...
    _vertices.resize(nvert * 3);
    _normals.resize(nvert * 3);
    _texcoords.resize(nvert * 2);
    _weights.resize(nvert * 4);
    _matrixIndices.resize(nvert * 4);

    _indices.resize(nind * 3);
    
    _calHWModel = new CalHardwareModel(getModel()->_coreModel);
    _calHWModel->setVertexBuffer((char*)&_vertices[0],3*sizeof(float));
    _calHWModel->setNormalBuffer((char*)&_normals [0],3*sizeof(float));
    _calHWModel->setWeightBuffer((char*)&_weights [0],4*sizeof(float));
    _calHWModel->setMatrixIndexBuffer((char*)&_matrixIndices[0],4*sizeof(float));
    _calHWModel->setTextureCoordNum(1);
    _calHWModel->setTextureCoordBuffer(0,(char*)&_texcoords[0],2*sizeof(float));
    _calHWModel->setIndexBuffer(&_indices[0]);

    _calHWModel->load( 0, 0, MAXBONESPERMESH);

    // Check sizes
    if(_calHWModel->getTotalVertexCount() > nvert)
    {
        FWARNING(("Character::initializeHWData: hw model had %d "
            "(> %d) vertices. Memory has been corrupted!\n",
            _calHWModel->getTotalVertexCount(), nvert));
    }
    if(_calHWModel->getTotalFaceCount() > nind)
    {
        FWARNING(("Character::initializeHWData: hw model had %d "
            "(> %d) indices. Memory has been corrupted!\n",
            _calHWModel->getTotalFaceCount(), nind));
    }
    // Fit sizes
    _vertices.resize(_calHWModel->getTotalVertexCount() * 3);
    _normals.resize(_calHWModel->getTotalVertexCount() * 3);
    _texcoords.resize(_calHWModel->getTotalVertexCount() * 2);
    _weights.resize(_calHWModel->getTotalVertexCount() * 4);
    _matrixIndices.resize(_calHWModel->getTotalVertexCount() * 4);

    _indices.resize(_calHWModel->getTotalFaceCount() * 3);

    // make indices relative to global buffer

    int mid;
    for(mid = 0; mid < _calHWModel->getHardwareMeshCount(); mid++)
    {
        _calHWModel->selectHardwareMesh(mid);

        int fid;
        for(fid = 0; fid < _calHWModel->getFaceCount(); fid++)
        {
            CalIndex base = _calHWModel->getBaseVertexIndex();
            _indices[fid * 3 +     _calHWModel->getStartIndex()] += base;
            _indices[fid * 3 + 1 + _calHWModel->getStartIndex()] += base;
            _indices[fid * 3 + 2 + _calHWModel->getStartIndex()] += base;
        }
    }
}

void Character::freeHWData(void)
{
    // Nothing to here.
}


void Character::drawMeshes(std::vector<Int32> &meshes, Window *win)
{
    CharacterModelPtr charmod = getModel();

    CalRenderer *crend = _calModel->getRenderer();

    // begin the rendering loop
    if(!crend->beginRendering())
    {
        FWARNING(("Character::drawPrimitives: beginRendering failed!\n"));
        return;
    }

    // Vertex Data
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);

    if(getUseShaderForGeometry())
    {
        void (OSG_APIENTRY*_glClientActiveTextureARB) (GLenum type)=
                (void (OSG_APIENTRY*) (GLenum type))
                win->getFunction(_funcglClientActiveTextureARB);
        GLint (OSG_APIENTRY*_glGetUniformLocationARB) (GLuint program, 
                const char *name)=
                (GLint (OSG_APIENTRY*) (GLuint program,
                const char *name))
                win->getFunction(_funcglGetUniformLocationARB);
        void (OSG_APIENTRY*_glUniformMatrix4fvARB) (GLint location, GLsizei count,
                 GLboolean transpose, const GLfloat *value)=
                (void (OSG_APIENTRY*) (GLint location, GLsizei count,
                 GLboolean transpose, const GLfloat *value))
                win->getFunction(_funcglUniformMatrix4fvARB);
         
        
        glVertexPointer(3, GL_FLOAT, 0, &_vertices[0]);
        glNormalPointer(GL_FLOAT, 0, &_normals[0]);
        
        _glClientActiveTextureARB(GL_TEXTURE0_ARB);
        glTexCoordPointer(2, GL_FLOAT, 0, &_texcoords[0]);
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);
        
        _glClientActiveTextureARB(GL_TEXTURE1_ARB);
        glTexCoordPointer(4, GL_FLOAT, 0, &_weights[0]);
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);
        
        _glClientActiveTextureARB(GL_TEXTURE2_ARB);
        glTexCoordPointer(4, GL_FLOAT, 0, &_matrixIndices[0]);
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);

        glErr("get boneMatrices uniform precheck");
        GLuint program = (GLuint) win->getGLObjectId(
                                     getModel()->getShader()->getGLId());
        GLint loc = _glGetUniformLocationARB(program, "boneMatrices");

        if(loc == -1)
        {
            glErr("get boneMatrices uniform");
            FWARNING(("Character::drawMeshes: can't determine "
                      "boneMatrices location!\n"));
        }


	    for(int hwmid = 0; hwmid< _calHWModel->getHardwareMeshCount(); hwmid++)
	    {
		    _calHWModel->selectHardwareMesh(hwmid);

            std::vector<Matrix> matrices;
            
		    for(int bid = 0; bid < _calHWModel->getBoneCount(); bid++)
		    {
			    CalQuaternion rotationBoneSpace = 
                        _calHWModel->getRotationBoneSpace   (
                                bid, _calModel->getSkeleton());
			    CalVector translationBoneSpace = 
                        _calHWModel->getTranslationBoneSpace(
                                bid, _calModel->getSkeleton());

			    CalMatrix rotationMatrix = rotationBoneSpace;

			    Matrix transformation(
                    rotationMatrix.dxdx, rotationMatrix.dxdy,
                    rotationMatrix.dxdz, translationBoneSpace.x,
                    
                    rotationMatrix.dydx, rotationMatrix.dydy,
                    rotationMatrix.dydz, translationBoneSpace.y,
                    
                    rotationMatrix.dzdx, rotationMatrix.dzdy,
                    rotationMatrix.dzdz, translationBoneSpace.z,
                    
                    0,0,0,1);
                    
                matrices.push_back(transformation);
		    }
            
            if(loc != -1)
            {
                _glUniformMatrix4fvARB(loc, matrices.size(), false,
                                &matrices[0][0][0]);
            }

		    if(sizeof(CalIndex)==2)
            {
			    glDrawElements(GL_TRIANGLES, _calHWModel->getFaceCount() * 3, 
                               GL_UNSIGNED_SHORT,
                               &_indices[_calHWModel->getStartIndex()]);
		    }
            else
			{
                glDrawElements(GL_TRIANGLES, _calHWModel->getFaceCount() * 3, 
                               GL_UNSIGNED_INT, 
                               &_indices[_calHWModel->getStartIndex()]);
            }
	    }
      
        _glClientActiveTextureARB(GL_TEXTURE2_ARB);
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);
        
        _glClientActiveTextureARB(GL_TEXTURE1_ARB);
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);

        _glClientActiveTextureARB(GL_TEXTURE0_ARB);
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    }
    else // Use CPU for meshing
    {
        std::vector<CalMesh *>& mvec = _calModel->getVectorMesh();
        
        // render the meshes stored in the vector
        for(std::vector<Int32>::iterator it = meshes.begin();
            it != meshes.end(); it != meshes.end() ? ++it : it)
        {
            UInt32 mid = *it++;
            CalMesh *mesh = mvec[mid];

            while(it != meshes.end() && *it >= 0)
            {
                UInt32 submid = *it++;

                CalSubmesh *sm = mesh->getSubmesh(submid);           
                CalCoreSubmesh *csm = sm->getCoreSubmesh();

                if(!crend->selectMeshSubmesh(mid, submid))
                {
                    FWARNING(("Character::drawPrimitives: "
                              "selectMeshSubmesh failed!\n"));
                    return;
                }

                int vertices_count = sm->getVertexCount();            
                c3dalloc(_vertices, vertices_count, float, 3);
                crend->getVertices(&_vertices[0]);

                c3dalloc(_normals, vertices_count, float, 3);
                crend->getNormals(&_normals[0]);

                c3dalloc(_texcoords, vertices_count, float, 2);
                int tc_count = crend->getTextureCoordinates(0, 
                                &_texcoords[0]);

                int indices_count = sm->getFaceCount();            
                c3dalloc(_indices, indices_count, CalIndex, 3);
                crend->getFaces(&_indices[0]);

                glVertexPointer(3, GL_FLOAT, 0, &_vertices[0]);
                glNormalPointer(GL_FLOAT, 0, &_normals[0]);

                if((crend->getMapCount() > 0) && (tc_count > 0))
                {
                    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
                    glTexCoordPointer(2, GL_FLOAT, 0, &_texcoords[0]);
                }

                if(sizeof(CalIndex)==2)
                {
                    glDrawElements(GL_TRIANGLES, indices_count * 3, 
                                    GL_UNSIGNED_SHORT, &_indices[0]);
                }
                else
                {
                    glDrawElements(GL_TRIANGLES, indices_count * 3, 
                                    GL_UNSIGNED_INT,   &_indices[0]);
                }
                
                if((crend->getMapCount() > 0) && (tc_count > 0))
                {
                    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
                }
            }
        }
    }
    
    // clear vertex array state
    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);

    // end the rendering
    crend->endRendering();
}


Action::ResultE Character::renderActionHandler(Action *action)
{
    RenderAction *a = dynamic_cast<RenderAction *>(action);

    // Build the DrawWrappers, if necessary
    if(_drawWrappers.empty())
    {
        CharacterPtr character(this);     
 
        _drawWrappers.resize(getModel()->getMaterials().size());
        
        for(std::vector<DrawWrapper>::iterator it = _drawWrappers.begin();
            it != _drawWrappers.end(); ++it)
        {
            it->clearMeshes();
            it->setCharacter(character);
        }

        std::vector<CalMesh *>& mvec = _calModel->getVectorMesh();
        
        for(Int32 meshind = 0; meshind < mvec.size(); ++meshind)
        {
            CalMesh *mesh = mvec[meshind];
            
            for(Int32 submeshind = 0; submeshind < mesh->getSubmeshCount(); 
                submeshind++)
            {
                CalSubmesh *sm = mesh->getSubmesh(submeshind);
                int cmi = sm->getCoreMaterialId();
                
                CalCoreMaterial *coremat;
                coremat = getModel()->_coreModel->getCoreMaterial(cmi);
                
                if(coremat != NULL)
                {
                    UInt32 ind = reinterpret_cast<ptrdiff_t>(
                                    coremat->getUserData());

                    _drawWrappers[ind].addMesh(meshind, submeshind);
                }
            }
        }
    }
    
    static Time last = 0;
    Time now = getSystemTime();
    
    if(last == 0)
        last = now;
    
    Time delta;
    
    if(getDelta() >= 0)
    {
        delta = getDelta();
    }
    else
    {
        delta = (now - last) * getTimeScale();
    }
    
    //_calModel->update(delta);
    _calModel->getSkeleton()->calculateState();
    _calModel->getPhysique()->update();
		_calModel->getSpringSystem()->update(delta);
    
    
    last = now;
    
    for(UInt32 i = 0; i < _drawWrappers.size(); ++i)
    {
        _drawWrappers[i].drop(action, getModel()->getMaterials(i));
    }

    return Action::Continue;
}


/*------------------------------------------------------------------------*/
/*                              cvs id's                                  */

#ifdef OSG_SGI_CC
#pragma set woff 1174
#endif

#ifdef OSG_LINUX_ICC
#pragma warning( disable : 177 )
#endif

namespace
{
    static Char8 cvsid_cpp       [] = "@(#)$Id: OSGCharacter.cpp,v 1.5 2007/01/15 19:54:53 dirk Exp $";
    static Char8 cvsid_hpp       [] = OSGCHARACTERBASE_HEADER_CVSID;
    static Char8 cvsid_inl       [] = OSGCHARACTERBASE_INLINE_CVSID;

    static Char8 cvsid_fields_hpp[] = OSGCHARACTERFIELDS_HEADER_CVSID;
}

#ifdef __sgi
#pragma reset woff 1174
#endif

