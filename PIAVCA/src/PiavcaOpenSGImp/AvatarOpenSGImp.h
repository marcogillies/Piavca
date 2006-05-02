/* LICENCE BLOCK
AvatarOpenSGImp.h
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

#ifndef AVATAROPENSGIMP_H_
#define AVATAROPENSGIMP_H_

//Some needed include files - these will become more, believe me ;)
#include <OpenSG/OSGConfig.h>
#include <OpenSG/OSGSimpleGeometry.h>
#include <OpenSG/OSGTransform.h>

#include "PiavcaCal3dImp/AvatarCal3dImp.h"
#include "PiavcaAPI/PiavcaError.h"

namespace Piavca
{
	
class AvatarOpenSGImp : public AvatarCal3DImp
{
	//! the root node of the avatar
	OSG::NodePtr rootNode;
	//! the root transform of the avatar
	OSG::TransformPtr rootTrans;
	
	//! vector of OpenSG geomentry objects corresponding to the Cal3D Meshes
	std::vector < std::vector < OSG::GeometryPtr > >  mGeometries;	

	AvatarOpenSGImp(tstring avatarId, TextureHandler *_textureHandler, bool bailOnMissedJoints, const Vec &Position, const Quat &Orientation);
	
	
	/*! This is a function that does platform specific per-frame stuff
	 *  Called by timeStep
	 */
	virtual void	platformSpecific_timeStep (float time)
	{
		int i,j;
		for(i =0; i < mGeometries.size(); i++)
			for(j =0; j < mGeometries[i].size(); j++)
			{
				beginEditCP(OSG::GeoPositions3fPtr::dcast(mGeometries[i][j]->getPositions()), OSG::GeoPositions3f::GeoPropDataFieldMask);
				beginEditCP(OSG::GeoNormals3fPtr::dcast(mGeometries[i][j]->getNormals()), OSG::GeoNormals3f::GeoPropDataFieldMask);
			}
		AvatarCal3DImp::platformSpecific_timeStep(time);
    	for(i =0; i < mGeometries.size(); i++)
			for(j =0; j < mGeometries[i].size(); j++)
			{
				endEditCP(OSG::GeoPositions3fPtr::dcast(mGeometries[i][j]->getPositions()), OSG::GeoPositions3f::GeoPropDataFieldMask);
				endEditCP(OSG::GeoNormals3fPtr::dcast(mGeometries[i][j]->getNormals()), OSG::GeoNormals3f::GeoPropDataFieldMask);	
			}
	}

public:
	//! destructor
	virtual ~AvatarOpenSGImp(){};
	
	//! given a UCLAvatar object get its implementation 
	static AvatarOpenSGImp *getAvatarImp(Avatar *avatar) 
	{
		AvatarOpenSGImp *OpenSGimp = dynamic_cast<AvatarOpenSGImp *>(getAvatarImpInternal(avatar)); 
		if(OpenSGimp)
			return OpenSGimp;
		else
		{
			Piavca::Error(_T("Trying to use a non OpenSG avatar in OpenSG"));
			return NULL;
		}
	};
	
	virtual void	setRootPosition			(const Vec &Position);
	virtual Vec		getRootPosition			();
	virtual void	setRootOrientation		(const Quat &Orientation);
	virtual Quat	getRootOrientation		();

	virtual void prerender();

	//! this method does nothing as OpenSG handles the rendering
	virtual void render(){};

	//! returns the root node of the avatar
	OSG::NodePtr getNode(){return rootNode;};
	
	friend class PiavcaOpenSGCore;
};
	
}


#endif /*AVATAROPENSGIMP_H_*/
