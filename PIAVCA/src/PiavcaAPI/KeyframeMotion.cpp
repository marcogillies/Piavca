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
 * The Original Code is KeyframeMotion.cpp.
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

#include "KeyframeMotion.h"
#include "PiavcaCore.h"
#include "PiavcaError.h"

using namespace Piavca;


void KeyframeMotion::initMotion(tstring fileName, bool facial, int flags, Motion *basePosture)
{
	Core::getCore()->initMotion(this, fileName, facial, flags, basePosture);
	imp->refCount++;
};

KeyframeMotion::KeyframeMotion(MotionImp *_imp): imp(_imp)
{
	imp->refCount++;
};


// assignment from a motion, create a new set of tracks and save the motion to them
const KeyframeMotion &KeyframeMotion::operator=(Motion &mot)
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

KeyframeMotion *Piavca::copyMotionPosture(Motion *mot, float time)
{
	KeyframeMotion *tmot = new KeyframeMotion(mot->isFacial());

	for (int track = mot->begin(); track < mot->end(); mot->next(track))
	{
		switch(mot->getTrackType(track))
		{
		case FLOAT_TYPE:  tmot->addFloatTrack(track, mot->getFloatValueAtTime(track, time));
						  break;
		case VEC_TYPE:    tmot->addVecTrack(track, mot->getVecValueAtTime(track, time));
						  break;
		case QUAT_TYPE:   tmot->addQuatTrack(track, mot->getQuatValueAtTime(track, time));
						  break;
		default:		  Error(_T("Unknown track type"));
		}
	}
	return tmot;
}
