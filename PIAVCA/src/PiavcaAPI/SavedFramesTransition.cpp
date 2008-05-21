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
 * The Original Code is SavedFramesTransition.cpp.
 *
 * The Initial Developer of the Original Code is Marco (Mark) Gillies.
 * Portions created by the Initial Developer are Copyright (C) Mark Gillies 2008
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

#include "SavedFramesTransition.h"
#include "PiavcaAPI/PiavcaError.h"
#include "PiavcaAPI/KeyframeMotion.h"

using namespace Piavca;



SavedFramesTransition::SavedFramesTransition(Motion *m1, Motion *m2, float transtime1, float transtime2, float w, TransitionFunction *tf) 
	:MotionTransition(NULL,m2,transtime1,transtime2,w,tf)
{
	setMotion1(m1);
};

SavedFramesTransition::SavedFramesTransition(const SavedFramesTransition &mt)
	:MotionTransition(mt)
{
};

void SavedFramesTransition::saveMotion()
{
	KeyframeMotion *kf = new KeyframeMotion;
	for (int track = originalMotion1->begin(); track < originalMotion1->end(); originalMotion1->next(track))
	{
		int type = originalMotion1->getTrackType(track);
		if (type & FLOAT_TYPE)
		{
			kf->addFloatTrack(track, originalMotion1->getFloatValueAtTime(track, transTimeOriginal));
		}
		if (type & VEC_TYPE)
		{
			kf->addVecTrack(track, originalMotion1->getVecValueAtTime(track, transTimeOriginal));
					}
		if (type & QUAT_TYPE)
		{
			kf->addQuatTrack(track, originalMotion1->getQuatValueAtTime(track, transTimeOriginal));
		}
	}
	float fps = 20.0f;
	for (float t = 0.0f; t < window; t+= 1.0f/fps)
	{
		for (int track = originalMotion1->begin(); track < originalMotion1->end(); originalMotion1->next(track))
		{
			int type = originalMotion1->getTrackType(track);
			if (type & FLOAT_TYPE)
			{
				kf->setFloatKeyframe(track, t, originalMotion1->getFloatValueAtTime(track, transTimeOriginal+t));
			}
			if (type & VEC_TYPE)
			{
				kf->setVecKeyframe(track, t, originalMotion1->getVecValueAtTime(track, transTimeOriginal+t));
			}
			if (type & QUAT_TYPE)
			{
				kf->setQuatKeyframe(track, t, originalMotion1->getQuatValueAtTime(track, transTimeOriginal+t));
			}
		}
	};
	TwoMotionCombiner::setMotion1(kf);
};

void SavedFramesTransition::setTransitionTime1(float t1)
{
	transTimeOriginal = t1;
	if (originalMotion1 && transitionTime1 < 0)
	{
		transTimeOriginal = originalMotion1->getEndTime() - window;
		if( transTimeOriginal < 0)
			transTimeOriginal = 0.0;
	};
	MotionTransition::setTransitionTime1(0.0f);
	saveMotion();
};

void SavedFramesTransition::setMotion1(Motion *mot)
{
	originalMotion1 = mot;
	// sort out the transition times for the new motion
	setTransitionTime1(transitionTime1);
};