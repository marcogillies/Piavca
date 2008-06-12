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

#ifndef _OSGCHARACTER_H_
#define _OSGCHARACTER_H_
#ifdef __sgi
#pragma once
#endif

#include <OSGConfig.h>

#include "OSGCharacterBase.h"

#include <OSGRenderAction.h>
#include <OSGMaterial.h>
#include <cal3d/cal3d.h>

OSG_BEGIN_NAMESPACE

/*! \brief Character class. See \ref 
           PageContribCharacter for a description.
*/


class /*OSG_CONTRIBLIB_DLLMAPPING*/ Character : public CharacterBase
{
  private:

    typedef CharacterBase Inherited;

    /*==========================  PUBLIC  =================================*/
  public:

    /*---------------------------------------------------------------------*/
    /*! \name                  Rendering Stuff                             */
    /*! \{                                                                 */

    Action::ResultE renderActionHandler    (Action * action );
    
    void            adjustVolume     (Volume & volume);

    /*---------------------------------------------------------------------*/
    /*! \name                      Sync                                    */
    /*! \{                                                                 */

    virtual void changed(BitVector  whichField, 
                         UInt32     origin    );

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                     Output                                   */
    /*! \{                                                                 */

    virtual void dump(      UInt32     uiIndent = 0, 
                      const BitVector  bvFlags  = 0) const;

    /*! \}                                                                 */
    /*=========================  PROTECTED  ===============================*/
  protected:

    // Variables should all be in CharacterBase.

    /*---------------------------------------------------------------------*/
    /*! \name                  Constructors                                */
    /*! \{                                                                 */

    Character(void);
    Character(const Character &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~Character(void); 

    /*! \}                                                                 */
    
    /*==========================  PRIVATE  ================================*/
  private:

    friend class FieldContainer;
    friend class CharacterBase;

    // Local variables

    CalModel         *_calModel;
    CalHardwareModel *_calHWModel;
    
    std::vector<float>      _vertices;
    std::vector<float>      _normals;
    std::vector<float>      _texcoords;
    std::vector<CalIndex>   _indices;
    
    std::vector<float>      _weights;
    std::vector<float>      _matrixIndices;
    
    
    void initializeHWData(void);
    void freeHWData(void);
 

    void drawMeshes(std::vector<Int32> &meshes, Window *win);
   
    
    static void initMethod(void);

    // extension indices for used extensions;
    static UInt32           _extMultitexture;
    static UInt32           _arbSHL100;
    
    // extension indices for used fucntions;
    static UInt32           _funcglClientActiveTextureARB;
    static UInt32           _funcglGetUniformLocationARB;
    static UInt32           _funcglUniformMatrix4fvARB;

    // prohibit default functions (move to 'public' if you need one)

    void operator =(const Character &source);
    
    class DrawWrapper
    {
      public:

        DrawWrapper(void)
        {
            clearMeshes();
        }

        ~DrawWrapper()
        {}
    
        void setCharacter(CharacterPtr character)
        {
            _character = character;
        }
    
        void clearMeshes(void)
        {
            _meshes.clear();
            _actmesh = -1;
        }
        
        void addMesh(Int32 mesh, Int32 submesh)
        {
            if(_actmesh != mesh)
            {
                if(_actmesh != -1)
                    _meshes.push_back(-1);
                _meshes.push_back(mesh);
                _actmesh = mesh;
            }
            
            _meshes.push_back(submesh);
        }

        void drop(Action *action, MaterialPtr mat)
        {
            Material::DrawFunctor func;
            func = osgTypedMethodFunctor1ObjPtr(this, &Character::DrawWrapper::draw);

            RenderAction *ra = dynamic_cast<RenderAction*>(action);

            ra->dropFunctor(func, mat.getCPtr());
        }

      private:

        Action::ResultE draw(DrawActionBase *act)
        {
            _character->drawMeshes(_meshes, act->getWindow());

            return Action::Continue;
        }

        // Format for meshes: 
        // <mesh id> <submesh id>+ (-1 <mesh id> <submesh id>+)+
        std::vector<Int32>  _meshes;
        CharacterPtr        _character;
        Int32               _actmesh;
        
        friend class Character;
    };

    std::vector<DrawWrapper> _drawWrappers;
};

typedef Character *CharacterP;

OSG_END_NAMESPACE

#include "OSGCharacterBase.inl"
#include "OSGCharacter.inl"

#define OSGCHARACTER_HEADER_CVSID "@(#)$Id: OSGCharacter.h,v 1.2 2005/10/06 14:22:40 dirk Exp $"

#endif /* _OSGCHARACTER_H_ */
