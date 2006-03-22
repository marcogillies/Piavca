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
 * The Original Code is SelfBlend.cpp.
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

#include "PiavcaDefs.h"

#include "SelfBlend.h"
#include "PiavcaException.h"
#include "TrackMotion.h"
#include "PiavcaError.h"
#include "PiavcaCore.h"

using namespace Piavca;

SelfBlend::SelfBlend(Motion *mot, float interval) 
	: SequentialBlend(NULL, mot, interval, 0.0) 
{
	if(!mot) return;
	
	TrackMotion *tmot = new TrackMotion(mot->isFacial());
	setMotion1(tmot);

	for (int track = mot2->begin(); track < mot2->end(); mot2->next(track))
	{
		switch(mot2->getTrackType(track))
		{
		case FLOAT_TYPE:  tmot->addFloatTrack(track, mot2->getFloatValueAtTime(track, mot2->getStartTime()));
						  break;
		case VEC_TYPE:    tmot->addVecTrack(track, mot2->getVecValueAtTime(track, mot2->getStartTime()));
						  break;
		case QUAT_TYPE:   tmot->addQuatTrack(track, mot2->getQuatValueAtTime(track, mot2->getStartTime()));
						  break;
		//case FLOAT_TYPE:  tmot->addFloatTrack(track, mot2->getFloatValueAtTime(track, 0.0));
		//				  break;
		//case VEC_TYPE:    tmot->addVecTrack(track, mot2->getVecValueAtTime(track, 0.0));
		//				  break;
		//case QUAT_TYPE:   tmot->addQuatTrack(track, mot2->getQuatValueAtTime(track, 0.0));
		//				  break;
		default:		  Piavca::Error(_T("Unknown track type"));
		}
	}
};

void SelfBlend::setMotion(Motion *mot)
{
	TrackMotion *tmot;
	if(mot && (!mot1 || mot->isFacial() != mot1->isFacial()))
	{
		tmot = new TrackMotion(mot->isFacial());
		setMotion1(tmot);
	}
	else
		tmot = dynamic_cast<TrackMotion *>(mot1);
	setMotion2(mot);

	if(!mot2) return;
	
	if(!tmot)
		Piavca::Error(_T("Motion blending from a non writable motion"));

	for (int track = mot2->begin(); track < mot2->end(); mot2->next(track))
	{
		switch(mot2->getTrackType(track))
		{
		case FLOAT_TYPE:  if(tmot->isNull(track)) 
							  tmot->addFloatTrack(track, mot2->getFloatValueAtTime(track, mot2->getStartTime()));
						  else
							  tmot->setFloatKeyframe(track, 0.0, mot2->getFloatValueAtTime(track, mot2->getStartTime()));
						  break;
		case VEC_TYPE:    if(tmot->isNull(track)) 
							  tmot->addVecTrack(track, mot2->getVecValueAtTime(track, mot2->getStartTime()));
						  else
							  tmot->setVecKeyframe(track, 0.0, mot2->getVecValueAtTime(track, mot2->getStartTime()));
						  break;
		case QUAT_TYPE:   if(tmot->isNull(track)) 
							  tmot->addQuatTrack(track, mot2->getQuatValueAtTime(track, mot2->getStartTime()));
						  else
							  tmot->setQuatKeyframe(track, 0.0, mot2->getQuatValueAtTime(track, mot2->getStartTime()));
						  break;
		default:		  Piavca::Error(_T("Unknown track type"));
		}
	}
	calculateRootOffsets();
};

void SelfBlend::reblend()
{
	reblend(Core::getCore()->getTime());
};

void SelfBlend::reblend(float time)
{
	if(!mot2) return;
	//std::cout << "reblend " << time << " "<< blendStart << " "<< blendInterval << std::endl;
	TrackMotion *tmot = dynamic_cast<TrackMotion *>(mot1);
	if(!tmot)
		Piavca::Error(_T("Motion blending from a non writable motion"));
	
	for(int track = tmot->begin(); track < tmot->end(); tmot->next(track))
	{
		switch(mot1->getTrackType(track))
		{
		case FLOAT_TYPE:  tmot->setFloatKeyframe(track, 0, getFloatValueAtTime(track, time));
						  break;
		case VEC_TYPE:    tmot->setVecKeyframe(track, 0, getVecValueAtTime(track, time));
						  break;
		case QUAT_TYPE:   tmot->setQuatKeyframe(track, 0, getQuatValueAtTime(track, time));
						  break;
		default:		  Piavca::Error(_T("Unknown track type"));
		}
	}
	calculateRootOffsets();
	setBlendStart(time);
	//if(mot2) mot2->setStartTime(startTime+blendStart+blendInterval);
};

