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
 * The Original Code is AvatarPostureBlend.cpp.
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

#include "AvatarPostureBlend.h"
#include "Avatar.h"
#include "PiavcaException.h"
#include "TrackMotion.h"

using namespace Piavca;


AvatarPostureBlend::AvatarPostureBlend(Motion *mot, float interval, bool _tracksFromAvatar) 
	:SequentialBlend(new TrackMotion(mot->isFacial()), mot, interval, 0.0), 
	tracksFromAvatar(_tracksFromAvatar)//, avatar(av) 
{
	setMaintainY(true);
	
};

void AvatarPostureBlend::load(Avatar *av)
{
	SequentialBlend::load(av);
	TrackMotion *tmot = dynamic_cast<TrackMotion *>(mot1);
	if(!tmot)
		Piavca::Error(_T("Motion blending from a non writable motion"));
	tmot->clearAllTracks();
	if(tracksFromAvatar)
	{
		if(mot2->isFacial())
		{	
			for(int track = av->beginExpression(); track < av->endExpression(); av->nextExpression(track))
				tmot->addFloatTrack(track, 0.0f);
		}
		else
		{
			tmot->addVecTrack(root_position_id, Vec());
			tmot->addQuatTrack(root_orientation_id, Quat());
			for(int track = av->begin(); track < av->end(); av->next(track))
				tmot->addQuatTrack(track, Quat());
		}
	}
	else
	{
		for (int track = mot2->begin(); track < mot2->end(); mot2->next(track))
		{
			switch(mot2->getTrackType(track))
			{
			case FLOAT_TYPE:  tmot->addFloatTrack(track, 0.0);
							break;
			case VEC_TYPE:    tmot->addVecTrack(track, Vec());
							break;
			case QUAT_TYPE:   tmot->addQuatTrack(track, Quat());
							break;
			default:		  Piavca::Error(_T("Unknown track type"));
			}
		}
	}
	reblend(0.0);
}

void AvatarPostureBlend::reblend(float time)
{
	if(!avatar) return;
	TrackMotion *tmot = dynamic_cast<TrackMotion *>(mot1);
	if(!tmot)
		Piavca::Error(_T("Motion blending from a non writable motion"));

	if(tmot->isFacial())
	{
		for(int expr = avatar->beginExpression(); expr < avatar->endExpression(); avatar->nextExpression(expr))
		{
	 		if(!tmot->isNull(expr))
				tmot->setFloatKeyframe(expr, 0, avatar->getFacialExpressionWeight(expr));
		}
	}
	else
	{
		if(!tmot->isNull(root_position_id))
				tmot->setVecKeyframe(root_position_id, 0, avatar->getRootPosition());
		if(!tmot->isNull(root_orientation_id))
				tmot->setQuatKeyframe(root_orientation_id, 0, avatar->getRootOrientation());
		for(int joint = avatar->begin(); joint < avatar->end(); avatar->next(joint))
		{
	 		if(!tmot->isNull(joint))
				tmot->setQuatKeyframe(joint, 0, avatar->getJointOrientation(joint));
		}
	}
	calculateRootOffsets();
	setBlendStart(time);
	if(mot2) mot2->setStartTime(startTime+blendStart+blendInterval);
};
