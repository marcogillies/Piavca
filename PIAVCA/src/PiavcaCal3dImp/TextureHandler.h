/* LICENCE BLOCK
TextureHandler.h
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


#ifndef TEXTURE_HANDLER_H
#define TEXTURE_HANDLER_H

#include "tga.h"
#ifdef _WIN32
#include <windows.h>
#endif

#if defined(__APPLE__)
	#include <OpenGL/gl.h>
#else
	#include <GL/gl.h>
#endif

#include <string>

namespace Piavca {

//! A class for handling textures
/*!
 *  The base version is pretty simple but it is set up so there can
 *  be a clever version for handling textures for multi-pipe rendering
 */
class TextureHandler
{
public:
	TextureHandler(){};
	virtual ~TextureHandler(){};

	//! loads a texture and returns an id (NB but not the real texture id!)
	/*!
	 *	The id returned is specific to the texture handler and can
	 *  be mapped to a real GL texture id using getTextureId.
	 *  This is done to enable one texture handler id to map to 
	 *  multiple GL texture ids in multi-pipe renderers
	 */
	virtual GLuint loadTexture(const std::string& strFilename);
	//! maps from the texture handlers version of an id to the GL texture id
	virtual GLuint getTextureId(GLuint i);
};

}; // namespace


#endif //TEXTURE_HANDLER_H
