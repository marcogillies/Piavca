/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is Motion.cpp.
 *
 * The Initial Developer of the Original Code is Marco (Mark) Gillies.
 * Portions created by the Initial Developer are Copyright (C) BT plc. 2004
 * All Rights Reserved.
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */


//#ifdef PIAVCA_DLL
//#define PIAVCA_EXPORT __declspec( dllexport ) 
//#else
//#define PIAVCA_EXPORT
//#endif
//#define PIAVCA_IMPORT __declspec( dllimport ) 

#include "PiavcaDefs.h"
#include "PiavcaCore.h"
#include "Motion.h"
#include "KeyframeMotion.h"
#include "Avatar.h"
#include "PiavcaError.h"

#include <assert.h>
#include <algorithm>

using namespace Piavca;

int Motion::debug_prefix = 0;

void Motion::create()
{
	
};

void Motion::printInfo()
{
	for(int i = 0; i < debug_prefix; i++)
		std::cout << " > ";
	std::cout << typeid(*this).name() << " " << getName() << std::endl;
};

// the granularity at which keyframes can be set 
//float Motion::keyframeGranularity = 1.0/1000.0;

int Motion::end() const 
{
	return Core::getCore()->getMaxJointId()+1;
};
int Motion::next(int &trackId)const 
{
	int maxTrack = Core::getCore()->getMaxJointId();
	while(isNull(++trackId)&&trackId<=maxTrack);
	return trackId;
};

void Motion::Dispose()
{	
	//Core::getCore()->disposeMotion(mot);
	refCount--;
	if(refCount <= 0)
		Core::getCore()->removeMotion(this);
};

void Motion::pause()
{
	// negative pausedTime == not paused
	// if you are already paused this command should have no effect
	if(pausedTime < 0)
		pausedTime = Core::getCore()->getTime();
}

void Motion::unpause()
{
	// negative pausedTime == not paused
	if(pausedTime >= 0)
	{
		// reset the start time so that the motion restarts at the 
		// place it started
		offsetTime = -(Core::getCore()->getTime()-pausedTime);
		pausedTime = -1;
	}
}

void Motion::preFrame(float time)
{
}

#include <iostream>
#include <fstream>
#include <string>
//using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;

struct PrintQuatKeyframe{
	Motion *mot;
	float time;
	ofstream *outFile;
	void operator()(int track)
	{
		Quat q = mot->getQuatValueAtTime(track, time);
		// yeah... this bits kind of dodgy
		float temp = q.I();
		q.I() = q.J();
		q.J() = temp;
		float x, y, z;
		q.getEulerAngles(y, x, z);
		(*outFile) << radToDeg(z)  << " " << radToDeg(x)  << " " << radToDeg(y) << " ";
	}
};

void Motion::saveMotion(tstring filename)
{
	// open bvh template file and the save file
	/*
	std::string filePath = PiavcaStringToString(getCore()->dir) + "bvhTemplate.bvh";
	std::cout << filePath << std::endl;
	ifstream templateFile(filePath.c_str());
	ofstream outFile(PiavcaStringToString(filename).c_str());
	*/
	std::string filePath = TStringToString(Core::getCore()->dir) + "bvhTemplate.bvh";
	std::cout << filePath << std::endl;
	ifstream templateFile(filePath.c_str());
	ofstream outFile(TStringToString(filename).c_str());

	// put the heirarch section into the file
	std::string word;
	vector <int> tracks;
	char c;
	while (templateFile.get(c))
	{
		if(c == '$') break;
		outFile.put(c);
	}
	// calculate the number of keyframes to save
	// and write to file
	float motionLength = getMotionLength();
	int noKeyframes = static_cast<int>(motionLength*25.0) + 1;
	float keyframeTime = (noKeyframes > 1) ? (motionLength/static_cast<float>((noKeyframes-1))) : 0.04f;

	outFile << "MOTION Frames: " << noKeyframes << endl;
	outFile << "Frame Time: " << keyframeTime << endl;

	// work out the order in which to write the tracks
	// the order of tracks is stored in the template file
	int rootPos = Core::getCore()->getJointId(_T("Root Position"));
	tracks.push_back(Core::getCore()->getJointId(_T("Root Orientation")));
	while (templateFile >> word)
	{
		tracks.push_back(Core::getCore()->getJointId(StringToTString(word)));
	}
	// print out all the keyframes
	PrintQuatKeyframe keyframePrinter;
	keyframePrinter.mot = this;
	keyframePrinter.outFile = &outFile;
	float tm = 0.0;
	for(int i = 0; i < noKeyframes; i++)
	{
		Vec v = getVecValueAtTime(rootPos, tm);
		outFile << v[2] << " " << v[1] << " " << v[0] << " ";
		keyframePrinter.time = tm;
		std::for_each(tracks.begin(), tracks.end(), keyframePrinter);
		outFile << endl;
		tm = tm + keyframeTime;
	}
	outFile << endl;
}

