/*
 *  oxfPiavca.cpp
 *  openFrameworks
 *
 *  Created by Marco Gillies on 19/10/2009.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "ofxPiavca.h"
#include "PiavcaAPI/Piavca.h"

void ofxPiavca::loadFile(string filename)
{
	Piavca::Core::getCore()->setHardware(false);
	
	int pathpos = filename.find_last_of("/");
	std::cout << filename << " " << pathpos << " ";
	string path = filename.substr(0, pathpos);// + "/";
	
#ifdef _MSC_VER 
	_chdir(ofToDataPath(path).c_str());
#else
	chdir(ofToDataPath(path).c_str());
#endif
	
	int dotpos = filename.find_last_of(".");
	string suffix = filename.substr(dotpos+1);
	if (suffix == "cfg")
	{
		string avatarname = filename.substr(pathpos+1, dotpos-pathpos-1);
		std::cout << avatarname << std::endl;
		
		Piavca::Avatar *av = new Piavca::Avatar(StringToTString(avatarname));
	}
	else
	{
		std::cout << "file to load " << filename.substr(pathpos+1) << std::endl;
		Piavca::Core::getCore()->loadXMLFile(StringToTString(filename.substr(pathpos+1)));
	}
}

void ofxPiavca::playMotion(string avatarName, string motionName)
{
	Piavca::Avatar *avatar = Piavca::Core::getCore()->getAvatar(avatarName);
	if (avatar)
	{
		Piavca::Motion *mot = Piavca::Core::getCore()->getMotion(motionName);
		if (mot)
		{
			avatar->loadMotion(mot);
			avatar->playMotion();
		}
	}
}

void ofxPiavca::event(string avatarName, string event)
{
	Piavca::Avatar *avatar = Piavca::Core::getCore()->getAvatar(avatarName);
	if (avatar)
	{
		avatar->event(event);
	}
}

void ofxPiavca::event(string event)
{
	for (int i = 0; i < Piavca::Core::getCore()->numAvatars(); i++)
		Piavca::Core::getCore()->getAvatar(i)->event(event);
}

void ofxPiavca::draw()
{
	Piavca::Core::getCore()->timeStep();
	
	Piavca::Core::getCore()->prerender();
	
	Piavca::Core::getCore()->render();
}