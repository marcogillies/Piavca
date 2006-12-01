/* LICENCE BLOCK
PiavcarCal3DCore.cpp
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

//#ifdef PIAVCA_DLL
//#define PIAVCA_EXPORT __declspec( dllimport ) 
//#else
//#define PIAVCA_EXPORT
//#endif

#include "PiavcaCal3dCore.h"
#include "PiavcaAPI/PiavcaDefs.h"
#include "PiavcaAPI/Avatar.h"
#include "PiavcaAPI/KeyframeMotion.h"
#include "AvatarCal3dImp.h"
#include "MotionCal3dImp.h"
#include "Cal3dMathsConversion.h"
#include "tga.h"
#include "TextureHandler.h"
//#include "bvhHeirarchyParser.h"
using namespace Piavca;


#include <fstream>
#include <assert.h>
#include <algorithm>


#ifdef _WIN32
#include <windows.h>
#endif

#include <GL/gl.h>

PiavcaCal3DCore::PiavcaCal3DCore():start_time(0.0) {
	start_time = getTimeInternal(true);
};

TextureHandler *PiavcaCal3DCore::createTextureHandler()
{
	return new TextureHandler();
}

AvatarCal3DImp *PiavcaCal3DCore::createAvatarImp(tstring avatarId, TextureHandler *th, bool bailOnMissedJoints, const Vec &Position, const Quat &Orientation)
{
	return new AvatarCal3DImp(avatarId, th, bailOnMissedJoints, Position, Orientation);
}
		

AvatarImp *PiavcaCal3DCore::createAvatarImp(tstring avatarId, bool bailOnMissedJoints, const Vec &Position, const Quat &Orientation)
{
  TextureHandler *th = createTextureHandler();
  AvatarCal3DImp *avatarImp = createAvatarImp(avatarId, th, bailOnMissedJoints, Position, Orientation);
  avatarImp->loadTextures();
  return avatarImp;
}


ObjectImp *PiavcaCal3DCore::createObjectImp(tstring objectId, const Vec &Position, const Quat &Orientation)
{
	return NULL;
}

#ifdef _WIN32
#include <windows.h>
#endif

#ifdef __linux__
#include <sys/time.h>
#endif


double PiavcaCal3DCore::getTimeInternal(bool print)
{
#ifdef _WIN32
	float tick = (float) GetTickCount();
	return tick/1000.0 - start_time;
#endif

#ifdef __linux__
  struct timeval now;
  gettimeofday(&now, 0);
  if(print)
  {
	  std::cout << "time details " <<  static_cast<float>(now.tv_sec) << " " <<  static_cast<float>(now.tv_usec) << " " << start_time << std::endl;
	  std::cout << "time " << static_cast<double>(now.tv_sec) + static_cast<double>(now.tv_usec) / 1000000.0 - static_cast<double>(start_time) << std::endl;
  };
  return static_cast<double>(now.tv_sec) + static_cast<double>(now.tv_usec) / 1000000.0 - static_cast<double>(start_time);
#endif

#ifdef __IRIX__
	what do we do here?
#endif
};

void PiavcaCal3DCore::prerender()
{
	for (int i = 0; i < (int) avatars.size(); i++)
	{
		AvatarCal3DImp::getAvatarImp(avatars[i])->prerender();
	}
}

void PiavcaCal3DCore::render()
{
	//std::cout << "Piavca core render\n";
	for (int i = 0; i < (int) avatars.size(); i++)
	{
		AvatarCal3DImp::getAvatarImp(avatars[i])->render();
	}
}