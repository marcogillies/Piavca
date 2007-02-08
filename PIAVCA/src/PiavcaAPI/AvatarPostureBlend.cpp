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

#include "AvatarPostureBlend.h"
#include "Avatar.h"
#include "PiavcaError.h"
#include "PiavcaCore.h"
#include "KeyframeMotion.h"

using namespace Piavca;


AvatarPostureBlend::AvatarPostureBlend(Motion *mot, float interval, bool _tracksFromAvatar) 
	:SequentialBlend(NULL, mot, interval, 0.0), 
	tracksFromAvatar(_tracksFromAvatar)//, avatar(av) 
{
	if (mot)
			setMotion1(new KeyframeMotion(mot->isFacial()));
	//setMaintainY(true);
	
};

void AvatarPostureBlend::load(Avatar *av)
{
	SequentialBlend::load(av);
	KeyframeMotion *tmot = dynamic_cast<KeyframeMotion *>(mot1);
	if(!tmot)
		Piavca::Error(_T("Motion blending from a non writable motion"));
	tmot->clearAllTracks();
	if(!mot2)
		return;
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

void AvatarPostureBlend::setMotion(Motion *mot)
{
	setMotion2(mot);
	if (!mot) 
		return;
	if(!mot1)
		setMotion1(new KeyframeMotion(mot->isFacial()));
	KeyframeMotion *tmot = dynamic_cast<KeyframeMotion *>(mot1);
	if(mot1 && !tmot)
		Piavca::Error(_T("Motion blending from a non writable motion"));
		
	tmot->clearAllTracks();
	if(!mot2)
		return;
	if(tracksFromAvatar)
	{
		if(!m_avatar)
			return;
		if(mot2->isFacial())
		{	
			for(int track = m_avatar->beginExpression(); track < m_avatar->endExpression(); m_avatar->nextExpression(track))
				tmot->addFloatTrack(track, 0.0f);
		}
		else
		{
			tmot->addVecTrack(root_position_id, Vec());
			tmot->addQuatTrack(root_orientation_id, Quat());
			for(int track = m_avatar->begin(); track < m_avatar->end(); m_avatar->next(track))
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
};

void AvatarPostureBlend::reblend(float time)
{
	if(!m_avatar) return;
	KeyframeMotion *tmot = dynamic_cast<KeyframeMotion *>(mot1);
	if(!tmot)
		Piavca::Error(_T("Motion blending from a non writable motion"));

	if(tmot->isFacial())
	{
		for(int expr = m_avatar->beginExpression(); expr < m_avatar->endExpression(); m_avatar->nextExpression(expr))
		{
	 		if(!tmot->isNull(expr))
				tmot->setFloatKeyframe(expr, 0, m_avatar->getFacialExpressionWeight(expr));
		}
	}
	else
	{
		if(!tmot->isNull(root_position_id))
				tmot->setVecKeyframe(root_position_id, 0, m_avatar->getRootPosition());
		if(!tmot->isNull(root_orientation_id))
				tmot->setQuatKeyframe(root_orientation_id, 0, m_avatar->getRootOrientation());
		for(int joint = m_avatar->begin(); joint < m_avatar->end(); m_avatar->next(joint))
		{
	 		if(!tmot->isNull(joint))
				tmot->setQuatKeyframe(joint, 0, m_avatar->getJointOrientation(joint));
		}
	}
	calculateRootOffsets();
	setBlendStart(time);
	if(mot2) mot2->setStartTime(startTime+blendStart+blendInterval);
};

void AvatarPostureBlend::reblend()
{
	reblend(Core::getCore()->getTime());
};
