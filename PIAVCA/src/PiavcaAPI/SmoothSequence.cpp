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
 * The Original Code is SmoothSequence.cpp.
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

#include "SmoothSequence.h"
#include "MotionTransition.h"
#include "Reposition.h"
#include "SubMotion.h"
#include "PiavcaError.h"
#include "TypeConvert.h"

using namespace Piavca;

bool SmoothSequence::setParameter(tstring paramName, tstring value)
{
	if(paramName == _T("BlendInterval") || paramName == _T("blendInterval") || paramName == _T("blendinterval"))
	{
		setBlendInterval(convert<float>(value));
		return true;
	}
	if(paramName == _T("BlendStart") || paramName == _T("blendStart") || paramName == _T("blendstart"))
	{
		setBlendStart(convert<float>(value));
		return true;
	}
	return Sequence::setParameter(paramName, value);
}

void SmoothSequence::create()
{
	std::cout << "Smooth Sequence::create" << std::endl;
	if (!originalMotion1)
	{
		std::cout << "Smooth Sequence::create: no orgininal motion 1" << std::endl;
		Sequence::setMotion1(NULL);
		if (originalMotion2)
			Sequence::setMotion2(originalMotion2);
		else 
			Sequence::setMotion2(NULL);
		return;
	}

	if (!originalMotion2)
	{
		std::cout << "Smooth Sequence::create: no orgininal motion 1" << std::endl;
		Sequence::setMotion2(NULL);
		if (originalMotion1)
			Sequence::setMotion1(originalMotion1);
		else 
			Sequence::setMotion1(NULL);
		return;
	}
	std::cout << "Smooth Sequence::create: setting motion 1" << std::endl;
	if (blendStart < 0)
		Sequence::setMotion1(originalMotion1);
	else
		Sequence::setMotion1(new SubMotion(originalMotion1, 
						originalMotion1->getStartTime(),
						blendStart));

	std::cout << "Smooth Sequence::create: processing motion 2" << std::endl;
	Motion *m2 = originalMotion2;
	if(m_accumulateRoot)
	{
		std::cout << "Smooth Sequence::create: accumulate root" << std::endl;
		float endTime = getMotion1()->getEndTime();
		Vec rootPos = getMotion1()->getVecValueAtTime(root_position_id, endTime);
		Quat rootOri = getMotion1()->getQuatValueAtTime(root_orientation_id, endTime);

		std::cout << "Smooth Sequence::create: reposition" << std::endl;
		m2 = new Reposition(m2, rootPos, rootOri);
	}


	std::cout << "Smooth Sequence::create: transition" << std::endl;
	MotionTransition *trans = new MotionTransition(getMotion1(), m2);
	trans->setWindow(blendInterval);
	std::cout << "Smooth Sequence::create: setting motion 2" << std::endl;
	setMotion2(new Sequence(trans, m2));
}
