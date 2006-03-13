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
 * ***** END LICENSE BLOCK ***** */


//#ifdef PIAVCA_DLL
//#define PIAVCA_EXPORT __declspec( dllexport ) 
//#else
//#define PIAVCA_EXPORT
//#endif
//#define PIAVCA_IMPORT __declspec( dllimport ) 

#include "PiavcaDefs.h"
#include "Motion.h"
#include "TrackMotion.h"
#include "Avatar.h"
#include "PiavcaCore.h"

#include <assert.h>
#include <algorithm>

using namespace Piavca;



// a motion factory used for creating avatars
//Piavca::Core *Motion::core = NULL;
// create a MotionImp from the factory
void TrackMotion::initMotion(tstring fileName, bool facial, int flags, Motion *basePosture)
{
	Core::getCore()->initMotion(this, fileName, facial, flags, basePosture);
	imp->refCount++;
};

TrackMotion::TrackMotion(MotionImp *_imp): imp(_imp)
{
	imp->refCount++;
};
// the granularity at which keyframes can be set 
//float Motion::keyframeGranularity = 1.0/1000.0;

int Motion::end() const {return Core::getCore()->getMaxJointId()+1;};
void Motion::Dispose()
{	
	//Core::getCore()->disposeMotion(mot);
	refCount--;
	if(refCount <= 0)
		Core::getCore()->removeMotion(this);
};


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


// assignment from a motion, create a new set of tracks and save the motion to them
const TrackMotion &TrackMotion::operator=(Motion &mot)
{
	deleteAllTracks();
	float motionLength = mot.getMotionLength();
	float keyframeSpacing = 0.1f;
	int maxKeyframe = static_cast<int>(motionLength/keyframeSpacing) + 1;
	int i;
	for(int track = mot.begin(); track < mot.end(); mot.next(track))
	{
		switch(mot.getTrackType(track))
		{
		case FLOAT_TYPE:
			addFloatTrack(track, mot.getFloatValueAtTime(track, 0));
			for( i = 0; i <= maxKeyframe; i++) 
				setFloatKeyframe(track, i*keyframeSpacing, mot.getFloatValueAtTime(track, i*keyframeSpacing));
			break;
		case VEC_TYPE:
			addVecTrack(track, mot.getVecValueAtTime(track, 0));
			for( i = 0; i <= maxKeyframe; i++) 
				setVecKeyframe(track, i*keyframeSpacing, mot.getVecValueAtTime(track, i*keyframeSpacing));
			break;
		case QUAT_TYPE:
			addQuatTrack(track, mot.getQuatValueAtTime(track, 0));
			for( i = 0; i <= maxKeyframe; i++) 
				setQuatKeyframe(track, i*keyframeSpacing, mot.getQuatValueAtTime(track, i*keyframeSpacing));
			break;
		default: Piavca::Error(_T("Unknown track type"));
		}
	}
	return *this;
};
