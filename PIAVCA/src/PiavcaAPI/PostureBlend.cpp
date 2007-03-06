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
 * The Original Code is PostureBlend.cpp.
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

#include "PostureBlend.h"
#include "PiavcaException.h"
#include "KeyframeMotion.h"
#include "MotionTransition.h"
#include "MotionPosture.h"
#include "SubMotion.h"
#include "PiavcaError.h"
#include "PiavcaCore.h"

using namespace Piavca;

PostureBlend::PostureBlend(Motion *mot, float _interval) 
	: Sequence(NULL, mot), interval(_interval), 
	originalMotion(mot), repositioner(NULL), accumulateRoot(true)
{
};


Motion *PostureBlend::getMotion()
{
	return originalMotion;
}

void PostureBlend::setMotion(Motion *mot)
{
	originalMotion = mot;
	if(accumulateRoot && repositioner)
	{
		repositioner->setMotion(mot);
		setMotion2(repositioner);
	}
	else
	{
		setMotion2(mot);
	}

	if(!originalMotion) return;
	
	originalMotion->reset();
};


void PostureBlend::reset()
{
	reblend();	
};

void PostureBlend::reblend()
{
	reblend(Core::getCore()->getTime());
};

void PostureBlend::reblend(float time)
{
	if(!originalMotion) return;

	MotionPosture *posture = new MotionPosture(this);
	posture->getPostureFromMotion(this, time);
	MotionTransition *trans = new MotionTransition(posture, mot2);
	//MotionTransition *trans = new MotionTransition(posture, NULL);
	trans->setWindow(interval);
	setMotion1(trans);
	//setMotion2(
	//if (interval < originalMotion->getMotionLength())
	//	setMotion2(new SubMotion(originalMotion, interval, -1));
	//else
	//	setMotion2(new SubMotion(originalMotion, originalMotion->getMotionLength(), -1));

	if(accumulateRoot)
	{
		if(!repositioner)
		{
			repositioner = new Reposition(originalMotion);
			repositioner->setStartFromMotion(originalMotion, time);
			setMotion2(repositioner);
		}
		else
			repositioner->setStartFromMotion(this, time);
	}

	setStartTime(time);
	originalMotion->reset();
};

