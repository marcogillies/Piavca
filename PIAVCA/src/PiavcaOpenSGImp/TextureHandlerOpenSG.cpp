/* LICENCE BLOCK
TextureHandlerOpenSG.cpp
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

#include "TextureHandlerOpenSG.h"

#include "PiavcaAPI/PiavcaError.h"

using namespace Piavca;


TextureHandlerOpenSG::~TextureHandlerOpenSG()
{
	for (int i = 0; i < images.size(); i++)
		subRefCP(images[i]);
};

GLuint TextureHandlerOpenSG::loadTexture(const std::string& strFilename)
{
  images.push_back(OSG::Image::create());
  images.back()->read(strFilename.c_str());	
  addRefCP(images.back());
  return images.size()-1;
}

// looks pretty stupid as a method, but it can be overloaded
// and in multi-pipe code it can do clever stuff about getting
// the right texture for the pipe your in
GLuint TextureHandlerOpenSG::getTextureId(GLuint i)
{
	Piavca::Error(_T("Shouldn't be requesting a texture id for an OpenSG texture"));
	return i;
}

OSG::ImagePtr TextureHandlerOpenSG::getImagePtr(GLuint i)
{
	if(i >= images.size())
		Piavca::Error(_T("Unknown texture Id"));
	return images[i];	
}