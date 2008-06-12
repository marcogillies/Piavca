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

#ifndef _OSGCHARACTERMODEL_H_
#define _OSGCHARACTERMODEL_H_
#ifdef __sgi
#pragma once
#endif

#include <OSGConfig.h>

#include "OSGCharacterModelBase.h"

#include <cal3d/cal3d.h>

OSG_BEGIN_NAMESPACE

/*! \brief CharacterModel class. See \ref 
           PageContribCharacterModel for a description.
*/

class /*OSG_CONTRIBLIB_DLLMAPPING*/ CharacterModel : public CharacterModelBase
{
  private:

    typedef CharacterModelBase Inherited;

    /*==========================  PUBLIC  =================================*/
  public:

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

    // Variables should all be in CharacterModelBase.

    /*---------------------------------------------------------------------*/
    /*! \name                  Constructors                                */
    /*! \{                                                                 */

    CharacterModel(void);
    CharacterModel(const CharacterModel &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~CharacterModel(void); 

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                     Helpers                                  */
    /*! \{                                                                 */

    CalCoreModel *loadConfig(std::string filename);
    void convertMaterials(std::string configfile);

    void activateShader(void);
    void deactivateShader(void);

    /*! \}                                                                 */
    
    /*==========================  PRIVATE  ================================*/
  private:

    friend class FieldContainer;
    friend class CharacterModelBase;

    friend class Character;

    CalCoreModel *_coreModel;


    static void initMethod(void);

    // prohibit default functions (move to 'public' if you need one)

    void operator =(const CharacterModel &source);
};

typedef CharacterModel *CharacterModelP;

OSG_END_NAMESPACE

#include "OSGCharacterModelBase.inl"
#include "OSGCharacterModel.inl"

#define OSGCHARACTERMODEL_HEADER_CVSID "@(#)$Id: OSGCharacterModel.h,v 1.1 2005/09/25 21:55:05 dirk Exp $"

#endif /* _OSGCHARACTERMODEL_H_ */
