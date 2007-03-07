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
#include "AvatarPosture.h"
#include "MotionTransition.h"
#include "Avatar.h"
#include "PiavcaError.h"
#include "PiavcaCore.h"
#include "KeyframeMotion.h"

using namespace Piavca;


AvatarPostureBlend::AvatarPostureBlend(Motion *mot, float _interval, bool _tracksFromAvatar) 
	:Sequence(NULL, mot), interval(_interval), 
	originalMotion(mot), repositioner(NULL), 
	tracksFromAvatar(_tracksFromAvatar)//, avatar(av) 
{
	reblend();
};

Motion *AvatarPostureBlend::getMotion()
{
	return originalMotion;
}

void AvatarPostureBlend::load(Avatar *av)
{
	Sequence::load(av);	
	reblend();
};

bool AvatarPostureBlend::isNull(int trackId) const 
{
	if (tracksFromAvatar)
		return Sequence::isNull(trackId);
	else
		return (!mot2 || mot2->isNull(trackId));
};

void AvatarPostureBlend::setMotion(Motion *mot)
{
	originalMotion = mot;
	if(repositioner)
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
	reblend();
};

void AvatarPostureBlend::reblend(float time)
{
	if(!originalMotion) return;
	if(!getAvatar()) return;
	
	AvatarPosture *posture = new AvatarPosture(originalMotion->isFacial());
	posture->getPostureFromAvatar(getAvatar());
	MotionTransition *trans = new MotionTransition(posture, mot2);
	setMotion1(NULL);
	
	if(!repositioner)
	{
		repositioner = new Reposition(originalMotion);
		repositioner->setMaintainY(true);
		repositioner->setStartPosition(getAvatar()->getRootPosition());
		repositioner->setStartOrientation(getAvatar()->getRootOrientation());
		setMotion2(repositioner);
	}
	else
		repositioner->setStartFromMotion(this, time);

	setStartTime(time);
	originalMotion->reset();
};

void AvatarPostureBlend::reblend()
{
	reblend(Core::getCore()->getTime());
};
