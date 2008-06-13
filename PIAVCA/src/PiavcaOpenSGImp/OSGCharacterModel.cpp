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

#include <OSGConfig.h>
#include <OSGPathHandler.h>
#include <OSGSimpleMaterial.h>
#include <OSGImage.h>
#include <OSGTextureChunk.h>

#include "OSGCharacterModel.h"

OSG_USING_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class osg::CharacterModel
The CoreModel, based on the Cal3D CoreModel component. 
*/

/***************************************************************************\
 *                           Class variables                               *
\***************************************************************************/

/***************************************************************************\
 *                           Class methods                                 *
\***************************************************************************/

void CharacterModel::initMethod (void)
{
}


/***************************************************************************\
 *                           Instance methods                              *
\***************************************************************************/

/*-------------------------------------------------------------------------*\
 -  private                                                                 -
\*-------------------------------------------------------------------------*/

/*----------------------- constructors & destructors ----------------------*/

CharacterModel::CharacterModel(void) :
    Inherited()
{
}

CharacterModel::CharacterModel(const CharacterModel &source) :
    Inherited(source)
{
}

CharacterModel::~CharacterModel(void)
{
}

/*----------------------------- class specific ----------------------------*/

void CharacterModel::changed(BitVector whichField, UInt32 origin)
{
    Inherited::changed(whichField, origin);
    
    if(whichField & ConfigFileFieldMask)
    {
        _coreModel = loadConfig(getConfigFile());
        if(_coreModel)
        {
            // Only need to do this once, not every time the 
            // Cal3D Model is needed, that's why it's not
            // done in loadConfig()
            convertMaterials(getConfigFile()); 
            
            CharacterModelPtr cp(this);     
            beginEditCP(cp, NumAnimationsFieldMask);
            cp->setNumAnimations(_coreModel->getCoreAnimationCount());
            endEditCP(cp, NumAnimationsFieldMask);
        }
    }

}

void CharacterModel::dump(      UInt32    , 
                         const BitVector ) const
{
    SLOG << "Dump CharacterModel NI" << std::endl;
}

CalCoreModel *CharacterModel::loadConfig(std::string filename)
{
    PathHandler ph;
    std::string pfile;
    
    ph.setBaseFile(filename.c_str());
    
    // open the model configuration file
    std::ifstream file;
    file.open(filename.c_str(), std::ios::in | std::ios::binary);
    if(!file)
    {
        SWARNING << "Failed to open model configuration file '" 
                 << filename << "'." << endLog;
        return NULL;
    }

    CalCoreModel *model = new CalCoreModel("dummy");
    
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
            SWARNING << "Error while reading from the model configuration file '" 
                     << filename << "'." << endLog;
            return NULL;
        }

        // find the first non-whitespace character
        std::string::size_type pos;
        pos = strBuffer.find_first_not_of(" \t");

        // check for empty lines
        if((pos == std::string::npos) || (strBuffer[pos] == '\n') || 
           (strBuffer[pos] == '\r') || (strBuffer[pos] == 0)) 
            continue;

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
            SWARNING << filename << "(" << line << "): Invalid syntax." 
                     << endLog;
            return false;
        }

        // find the first non-whitespace character after the '=' character
        pos = strBuffer.find_first_not_of(" \t", pos + 1);

        // get the data
        std::string strData;
        strData = strBuffer.substr(pos, 
                            strBuffer.find_first_of("\n\r", pos) - pos);

        // handle the model creation
        if(strKey == "scale")
        {
            // set rendering scale factor
            //m_scale = atof(strData.c_str());
        }
        else if(strKey == "skeleton")
        {
            pfile = ph.findFile(strData.c_str());

            // load core skeleton
            SINFO << "Loading skeleton '" << pfile << "'..." << endLog;
            
            if(!model->loadCoreSkeleton(pfile.c_str()))
            {
                CalError::printLastError();
                return false;
            }
                        
            // **************** Load Bone Names *****************
    				CharacterModelPtr cp(this);
    				CalCoreSkeleton *skel = model->getCoreSkeleton();
						std::vector<CalCoreBone *>& bones = skel->getVectorCoreBone();
				
						for(int i = 0; i < (int) bones.size(); i++) {
		    				std::string name = bones[i]->getName();
    						getBoneNames().push_back(name);
    						std::cout << "Added BoneName " << i << ": " << name << std::endl;
    				}
						
						if(!getBoneNames().empty()) {
        				std::cout << "Printing BoneNames Field:" << std::endl;
		            for(int i = 0; i < (int) bones.size(); i++) {
	            			std::cout << "boneNames [" << i << "]: " << getBoneNames()[i].c_str() << std::endl;
            		}
						}
            
        		if(getBoneNames().empty()) {
		        		std::cout << "Warning:  BoneNames Field Empty!" << std::endl;
        		}
        		// ************** End Load Bone Names ***************
    		}
     
        else if(strKey == "animation")
        {
            pfile = ph.findFile(strData.c_str());
            
            // load core animation
            SINFO << "Loading animation '" << pfile 
                  << "'..." << endLog;
            if(model->loadCoreAnimation(pfile.c_str()) == -1)
            {
                CalError::printLastError();
                return false;
            }
        }
        else if(strKey == "mesh")
        {
            pfile = ph.findFile(strData.c_str());

            // load core mesh
            SINFO << "Loading mesh '" << pfile << "'..." << endLog;
            if(model->loadCoreMesh(pfile.c_str()) == -1)
            {
                CalError::printLastError();
                return false;
            }
        }
        else if(strKey == "material")
        {
            pfile = ph.findFile(strData.c_str());

            // load core material
            SINFO << "Loading material '" << pfile << "'..." << endLog;
            if(model->loadCoreMaterial(pfile.c_str()) == -1)
            {
                CalError::printLastError();
                return false;
            }
        }
        else
        {
            // everything else triggers an error message, but is ignored
            SWARNING << filename << "(" << line << "): Invalid syntax." 
                     << endLog;
        }
    }

    // create material threads
    int mid;
    for(mid = 0; mid < model->getCoreMaterialCount(); mid++)
    {
        model->createCoreMaterialThread(mid);
        model->setCoreMaterialId(mid, 0, mid);
    }

    file.close();

    return model;
}

void CharacterModel::convertMaterials(std::string configfile)
{
    getMaterials().clear();
    UInt32 mcnt = 0;
    PathHandler ph;
    
    ph.setBaseFile(configfile.c_str());
       
    for(int mid = 0; mid < _coreModel->getCoreMaterialCount(); mid++)
    {
        CalCoreMaterial *coremat = _coreModel->getCoreMaterial(mid);
        SimpleMaterialPtr mat = SimpleMaterial::create();

        beginEditCP(mat);

        CalCoreMaterial::Color &calamb = coremat->getAmbientColor();
        CalCoreMaterial::Color &caldif = coremat->getDiffuseColor();
        CalCoreMaterial::Color &calspec = coremat->getSpecularColor();

        mat->setAmbient(Color3f(calamb.red / 255.0f, calamb.green / 255.0f, calamb.blue / 255.0f));
        mat->setDiffuse(Color3f(caldif.red / 255.0f, caldif.green / 255.0f, caldif.blue / 255.0f));
        mat->setSpecular(Color3f(calspec.red / 255.0f, calspec.green / 255.0f, calspec.blue / 255.0f));
        
        mat->setShininess(coremat->getShininess() * 100.f);
        mat->setLit(true);
        mat->setColorMaterial(GL_NONE);
        
        for(int mapId = 0; mapId < coremat->getMapCount(); mapId++)
        {
            std::string file = coremat->getMapFilename(mapId);
            std::string pfile = ph.findFile(file.c_str());
            SINFO << "Loading texture '" << pfile << "'..." << endLog;

            ImagePtr img = Image::create();
            
             if(!img->read(pfile.c_str()))
            {
                SWARNING << "CharacterModel::convertMaterials: error "
                         << "loading image " << file << endLog;
            }
            else
            {
                // amz with my test scene paladin.cfg all textures were
                // upside down so I disabled the vertical flipping perhaps
                // they fixed the bug in Cal3D?
#if 0
                beginEditCP(img);
                {
                // For some reason Cal3D expects textures upside down ???
                UInt32 bpl = img->getBpp() * img->getWidth();
                UChar8 *t = img->getData(), 
                       *b = t + (img->getHeight() - 1) * bpl,
                        dum;

                for(UInt32 y = img->getHeight() / 2; y > 0; --y)
                {
                    for(UInt32 x = bpl; x > 0; --x, ++t, ++b)
                    {
                        dum = *t;
                        *t = *b;
                        *b = dum;
                    }
                    b -= bpl * 2;
                }
                }
                endEditCP(img);
#endif
                
                TextureChunkPtr tex = TextureChunk::create();
                
                beginEditCP(tex);
                tex->setImage(img);
                tex->setEnvMode(GL_MODULATE);
                endEditCP(tex);
                
                mat->addChunk(tex);
            }
        }
            
        endEditCP(mat);
        
        coremat->setUserData((Cal::UserData)mcnt);
        getMaterials().push_back(mat);
        mcnt ++;
    }    
}

void CharacterModel::activateShader(void)
{
    for(UInt32 i = 0; i < getMaterials().size(); ++i)
    {
        ChunkMaterialPtr m = getMaterials(i);
        
        beginEditCP(m);
        m->addChunk(getShader());
        endEditCP(m);
    }
}

void CharacterModel::deactivateShader(void)
{
    for(UInt32 i = 0; i < getMaterials().size(); ++i)
    {
        ChunkMaterialPtr m = getMaterials(i);
        
        beginEditCP(m);
        m->subChunk(getShader());
        endEditCP(m);
    }
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
    static Char8 cvsid_cpp       [] = "@(#)$Id: OSGCharacterModel.cpp,v 1.3 2007/01/04 11:16:30 a-m-z Exp $";
    static Char8 cvsid_hpp       [] = OSGCHARACTERMODELBASE_HEADER_CVSID;
    static Char8 cvsid_inl       [] = OSGCHARACTERMODELBASE_INLINE_CVSID;

    static Char8 cvsid_fields_hpp[] = OSGCHARACTERMODELFIELDS_HEADER_CVSID;
}

#ifdef __sgi
#pragma reset woff 1174
#endif

