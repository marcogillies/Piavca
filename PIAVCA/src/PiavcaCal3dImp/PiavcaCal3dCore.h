/* LICENCE BLOCK
PiavcaCal3DCore.h
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

#ifndef PIAVCA_Cal3D_CORE_H
#define PIAVCA_Cal3D_CORE_H

#include <cal3d/cal3d.h>

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




namespace Piavca
{
class AvatarImp;
class AvatarCal3DImp;
class TextureHandler;

	//! A factory class that is used to create avatar object in the Tara implementation
	/*!
	 *	This is a subtype of the UCL avatar factory. It also subtypes the StdMotionAvatarFactory as
	 *	it uses the standard motion implementation
	 */
    class PIAVCA_DECL PiavcaCal3DCore : public StdMotionCore
	{
		double start_time;
	protected:
		//! Creates an avatar implementation (actually creates a UCLAVatarTaraImp object)
		AvatarImp *createAvatarImp(tstring avatarId, bool bailOnMissedJoints, const Vec &Position, const Quat &Orientation);
		//! a version of createAvatarImp to be subclassed
		virtual AvatarCal3DImp *createAvatarImp(tstring avatarId, TextureHandler *th, bool bailOnMissedJoints, const Vec &Position, const Quat &Orientation);
		//! Creates an object implementation (actually creates a UCLAvatarTaraImp object)
		ObjectImp *createObjectImp(tstring avatarId, const Vec &Position, const Quat &Orientation);
		/*! creates a texture handler 
		 *  (of the correct subtype corresponding to the dynamic
		 *  type of the core)
		 */
		 virtual TextureHandler *createTextureHandler();
	public:
		PiavcaCal3DCore();
		virtual ~PiavcaCal3DCore() {};

		void setStartTime (float s){start_time = s;};
		double getTimeInternal(bool print);
	    virtual float getSystemTime() {return (float)getTimeInternal(false);};

		// called before rendering
		virtual void prerender();

		// does the Cal3D rendering of all the avatars
		virtual void render();
	};

};


#endif //PIAVCA_Cal3D_CORE_H
