/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
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
 * The Original Code is MotionSaver.cpp.
 *
 * The Initial Developer of the Original Code is Marco (Mark) Gillies.
 * Portions created by the Initial Developer are Copyright (C) 2005
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
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

#include <fstream>
#include "MotionSaver.h"
#include "PiavcaAPI/PiavcaCore.h"
#include "PiavcaAPI/PiavcaError.h"

using namespace Piavca;

void MotionSaver::setMotion(Motion *mot)
{
	MotionFilter::setMotion(mot);
	if (mot)
		tmot = new KeyframeMotion(mot->isFacial());
}

PIAVCA_EXPORT float  MotionSaver::getFloatValueAtTimeInternal (int trackId, float time)
{
	if(!filterMot)
	{
		Piavca::Error(_T("MotionSaver: trying to get a value from a null motion"));
	}
	float val =  filterMot->getFloatValueAtTime(trackId, time);
	if(tmot->isNull(trackId))
		tmot->addFloatTrack(trackId, val);
	tmot->setFloatKeyframe(trackId, time, val);
	return val;
};

PIAVCA_EXPORT Vec  MotionSaver::getVecValueAtTimeInternal (int trackId, float time)
{
	if(!filterMot)
	{
		Piavca::Error(_T("MotionSaver: trying to get a value from a null motion"));
	}
	Vec val =  filterMot->getVecValueAtTime(trackId, time);
	if(tmot->isNull(trackId))
		tmot->addVecTrack(trackId, val);
	tmot->setVecKeyframe(trackId, time, val);
	return val;
};

PIAVCA_EXPORT Quat  MotionSaver::getQuatValueAtTimeInternal (int trackId, float time)
{
	if(!filterMot)
	{
		Piavca::Error(_T("MotionSaver: trying to get a value from a null motion"));
	}
	Quat val =  filterMot->getQuatValueAtTime(trackId, time);
	if(tmot->isNull(trackId))
		tmot->addQuatTrack(trackId, val);
	tmot->setQuatKeyframe(trackId, time, val);
	return val;
};

PIAVCA_EXPORT void MotionSaver::collectFrames(float framerate)
{
	for(float time = 0; time < getMotionLength(); time += framerate)
	{
		for(int i = begin(); i < end(); i++)
		{
			trackType type = getTrackType(i);
			if(type == FLOAT_TYPE) getFloatValueAtTime(i, time);
			if(type == VEC_TYPE) getVecValueAtTime(i, time);
			if(type == QUAT_TYPE) getQuatValueAtTime(i, time);
		}
	}
}

PIAVCA_EXPORT void MotionSaver::save(tstring filename)
{
	std::ofstream of(TStringToString(filename).c_str());
	if(tmot->isFacial())
		of << "facial\n";
	else
		of << "body\n";
	for (int track = tmot->begin(); track != tmot->end(); tmot->next(track))
	{
		if(tmot->isFacial())
			of << Core::getCore()->getExpressionName(track) << " ";
		else
			of << Core::getCore()->getJointName(track) << " ";
		trackType type =  tmot->getTrackType(track);
		switch (type) 
		{
		case FLOAT_TYPE: of << "FLOAT "; break;
		case VEC_TYPE:   of << "VEC "; break;
		case QUAT_TYPE:  of << "QUAT "; break;
		default: Piavca::Error(_T("Unknown track type\n"));
		}
		float lastKeyframeTime = -100.0;
		int count = 0;
		std::cout << tmot->getNumKeyframes(track) << " keyframes\n";
		for(int i = 0; i < tmot->getNumKeyframes(track); i++)
		{
			float t = tmot->getKeyframeTime(track, i);
			// avoid writing out keyframes that are too close together
			if(fabs(t - lastKeyframeTime) < 0.01)
				continue;
			lastKeyframeTime = t;
			count++;
			of << t << " ";
			switch (type) 
			{
			case FLOAT_TYPE: of << tmot->getFloatValueAtTime(track, t) << " "; break;
			case VEC_TYPE:   of << tmot->getVecValueAtTime(track, t) << " "; break;
			case QUAT_TYPE:  of << tmot->getQuatValueAtTime(track, t) << " "; break;
			default: Piavca::Error(_T("Unknown track type\n"));
			}
		}
		std::cout << "wrote " << count << " keyframes\n";
		of << std::endl;
	}
}