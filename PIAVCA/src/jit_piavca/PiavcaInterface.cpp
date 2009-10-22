/*
 *  PiavcaInterface.cpp
 *  max.jit.piavca
 *
 *  Created by Marco Gillies on 22/10/2009.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

extern "C" {
#include "PiavcaInterface.h"
};
	
#include "PiavcaAPI/Piavca.h"


#include <string>

void piavcaInit()
{
	Piavca::Core::getCore()->setHardware(false);
}

void piavcaLoadFile(char * file)
{
	std::string filename(file);
	int pathpos = filename.find_last_of("/");
	//std::cout << filename << " " << pathpos << " ";
	std::string path = filename.substr(0, pathpos);// + "/";
	
#ifdef _MSC_VER 
	_chdir(path.c_str());
#else
	chdir(path.c_str());
#endif
	
	int dotpos = filename.find_last_of(".");
	std::string suffix = filename.substr(dotpos+1);
	if (suffix == "cfg")
	{
		std::string avatarname = filename.substr(pathpos+1, dotpos-pathpos-1);
		//std::cout << avatarname << std::endl;
		
		Piavca::Avatar *av = new Piavca::Avatar(StringToTString(avatarname));
	}
	else
	{
		//std::cout << "file to load " << filename.substr(pathpos+1) << std::endl;
		Piavca::Core::getCore()->loadXMLFile(StringToTString(filename.substr(pathpos+1)));
	}
	
}


void piavcaPlayMotion(char *avatar, char*motion)
{
	Piavca::Avatar *av = Piavca::Core::getCore()->getAvatar(StringToTString(avatar));
	if (av)
	{
		Piavca::Motion *mot = Piavca::Core::getCore()->getMotion(StringToTString(motion));
		if (mot)
		{
			av->loadMotion(mot);
			av->playMotion();
		}
	}
}

void piavcaDraw()
{
	Piavca::Core::getCore()->timeStep();
	
	Piavca::Core::getCore()->prerender();
	
	Piavca::Core::getCore()->render();
}
