/* LICENCE BLOCK
PiavcarOpenSGCore.cpp
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

#include "PiavcaOpenSGCore.h"
#include "AvatarOpenSGImp.h"
#include "TextureHandlerOpenSG.h"

using namespace Piavca;

PiavcaOpenSGCore::PiavcaOpenSGCore() {
	// set up the root node of OpenSG
	rootNode = OSG::Node::create();
	
	// set up transform for it
	OSG::TransformPtr transCore = OSG::Transform::create();
	OSG::Matrix m;
	m.setIdentity();
	beginEditCP(transCore);
	    transCore->setMatrix(m);
	endEditCP(transCore);
	        
	// now "insert" the core into the node
	beginEditCP(rootNode);
	    rootNode->setCore(transCore);
	endEditCP(rootNode);
};

TextureHandler *PiavcaOpenSGCore::createTextureHandler()
{
	return new TextureHandlerOpenSG();
}

AvatarCal3DImp *PiavcaOpenSGCore::createAvatarImp(tstring avatarId, TextureHandler *th, bool bailOnMissedJoints, const Vec &Position, const Quat &Orientation)
{
	// create an avatar
	AvatarOpenSGImp *avatarImp = new AvatarOpenSGImp(avatarId, th, bailOnMissedJoints, Position, Orientation);
	// get the OpenSG node assciated with the avatar
	OSG::NodePtr avatarNode = avatarImp->getNode();
	std::cout << "adding avatar node\n";
	
	// at the OpenSG node to the graph
	beginEditCP(rootNode);
	    rootNode->addChild(avatarNode);
	endEditCP(rootNode);
	return avatarImp;
};
