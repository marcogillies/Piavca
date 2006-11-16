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

#include "PiavcaDefs.h"

#include "SelfBlend.h"
#include "PiavcaException.h"
#include "KeyframeMotion.h"
#include "PiavcaError.h"
#include "PiavcaCore.h"

using namespace Piavca;

SelfBlend::SelfBlend(Motion *mot, float interval) 
	: SequentialBlend(NULL, mot, interval, 0.0) 
{
	if(!mot) return;
	
	KeyframeMotion *tmot = new KeyframeMotion(mot->isFacial());
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
	KeyframeMotion *tmot;
	if(mot && (!mot1 || mot->isFacial() != mot1->isFacial()))
	{
		tmot = new KeyframeMotion(mot->isFacial());
		setMotion1(tmot);
	}
	else
		tmot = dynamic_cast<KeyframeMotion *>(mot1);
	setMotion2(mot);

	if(!mot2) return;
	
	mot2->reset();
	//SelfBlend *sb = dynamic_cast<SelfBlend *>(mot2);
	//if(sb) sb->reblend(Piavca::Core::getCore()->getTime());

	if(!tmot)
		Piavca::Error(_T("Motion blending from a non writable motion"));

	for (int track = mot2->begin(); track < mot2->end(); mot2->next(track))
	{
		switch(mot2->getTrackType(track))
		{
		case FLOAT_TYPE:  if(tmot->isNull(track)) 
							  tmot->addFloatTrack(track, mot2->getFloatValueAtTime(track, mot2->getStartTime()));
						  //else
						//	  tmot->setFloatKeyframe(track, 0.0, mot2->getFloatValueAtTime(track, mot2->getStartTime()));
						  break;
		case VEC_TYPE:    if(tmot->isNull(track)) 
							  tmot->addVecTrack(track, mot2->getVecValueAtTime(track, mot2->getStartTime()));
						  //else
						//	  tmot->setVecKeyframe(track, 0.0, mot2->getVecValueAtTime(track, mot2->getStartTime()));
						  break;
		case QUAT_TYPE:   if(tmot->isNull(track)) 
							  tmot->addQuatTrack(track, mot2->getQuatValueAtTime(track, mot2->getStartTime()));
						  //else
							//  tmot->setQuatKeyframe(track, 0.0, mot2->getQuatValueAtTime(track, mot2->getStartTime()));
						  break;
		default:		  Piavca::Error(_T("Unknown track type"));
		}
	}
	//std::cout << "self blend set motion\n";
	calculateRootOffsets();
};

void SelfBlend::reset()
{
	reblend();	
};

void SelfBlend::reblend()
{
	reblend(Core::getCore()->getTime());
};

void SelfBlend::reblend(float time)
{
	if(!mot2) return;
	//std::cout << "reblend " << time << " "<< blendStart << " "<< blendInterval << std::endl;
	KeyframeMotion *tmot = dynamic_cast<KeyframeMotion *>(mot1);
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
	setBlendStart(time);
	calculateRootOffsets();
	
	mot2->reset();
	//SelfBlend *sb = dynamic_cast<SelfBlend *>(mot2);
	//if(sb) sb->reblend(Piavca::Core::getCore()->getTime());
	//if(mot2) mot2->setStartTime(startTime+blendStart+blendInterval);
};

