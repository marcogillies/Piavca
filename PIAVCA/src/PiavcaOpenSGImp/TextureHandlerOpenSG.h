/* LICENCE BLOCK
TextureHandlerOpenSG.h
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

#ifndef TEXTURE_HANDLER_OPENSG_H
#define TEXTURE_HANDLER_OPENSG_H

#ifdef _WIN32
#include <windows.h>
#endif

#include <GL/gl.h>
#include <string>
#include <vector>

#include "PiavcaCal3dImp/TextureHandler.h"
#include <OpenSG/OSGImage.h>

namespace Piavca {

//! A class for handling textures, specialised for OPenSG

class TextureHandlerOpenSG : public TextureHandler
{
	std::vector<OSG::ImagePtr> images;
public:
	TextureHandlerOpenSG(){};
	~TextureHandlerOpenSG();

	//! loads a texture and returns an id (NB but not the real texture id!)
	/*!
	 *	In this case the id is used to fetch an OpenSG image object
	 */
	GLuint loadTexture(const std::string& strFilename);
	//! don't use GL texture Id is OpenSG so this shouldn't be called
	GLuint getTextureId(GLuint i);
	//! return the OpenSG images associated with the texture
	OSG::ImagePtr getImagePtr(GLuint i);
};

}; // namespace


#endif //TEXTURE_HANDLER_OPENSG_H
