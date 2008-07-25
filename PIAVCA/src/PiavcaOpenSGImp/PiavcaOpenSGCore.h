/* LICENCE BLOCK
PiavcaOpenSGCore.h
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

#ifndef PIAVCA_OPENSG_CORE_H
#define PIAVCA_OPENSG_CORE_H


#include <string>
using std::string;

#include "PiavcaAPI/PiavcaDefs.h"

//typedef std::basic_string<XMLCh> xmlstring;

#include <map>
using std::map;

#include "PiavcaAPI/Vec.h"
#include "PiavcaAPI/Quat.h"
#include "PiavcaAPI/Avatar.h"
#include "StdMotionImp/StdMotionCore.h"

#include "PiavcaCal3dImp/PiavcaCal3dCore.h"

#include "AvatarOpenSGImp.h"

#include <OSGNodePtr.h>

namespace Piavca
{


	//! A factory class that is used to create avatar object in the OpenSG implementation
	/*!
	 *	This is a subtype of the PiavcaCal3dCore. 
	 */
    class PIAVCA_DECL PiavcaOpenSGCore : public PiavcaCal3DCore
	{
		osg::NodePtr graph_root;
	protected:
		//! Creates an avatar implementation (actually creates a AvatarOpenSGImp object)
		AvatarImp *createAvatarImp(tstring avatarId, bool bailOnMissedJoints, const Vec &Position, const Quat &Orientation);
		//! a version of createAvatarImp to be subclassed
		virtual AvatarOpenSGImp *createAvatarImp(osg::CharacterPtr character, osg::NodePtr node, bool bailOnMissedJoints, const Vec &Position, const Quat &Orientation);
		
	public:

		PiavcaOpenSGCore(osg::NodePtr root = osg::NodePtr());
		virtual ~PiavcaOpenSGCore() {};

		void loadAllAvatars();

		friend class NodeFinder;
	};

};


#endif //PIAVCA_OPENSG_CORE_H
