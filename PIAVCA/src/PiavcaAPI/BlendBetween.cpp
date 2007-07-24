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
 * The Original Code is BlendBetween.cpp.
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

#include "BlendBetween.h"
#include "PiavcaError.h"

using namespace Piavca;

BlendBetween::BlendBetween(Motion *m1, Motion *m2, float _blend) 
			:TwoMotionCombiner(m1,m2), blend(_blend)
{
};

BlendBetween::BlendBetween(const BlendBetween &b)
	:TwoMotionCombiner(b), blend(b.blend)
{
};

float BlendBetween::getFloatValueAtTimeInternal (int trackId, float time)
{
	// if this track doesn't exist in mot2 use mot1 otherwise interpolated between them
	if(mot2->isNull(trackId))
	{
		if(mot1->isNull(trackId))
		{
			Piavca::Error(_T("trying to blend between two invalid tracks"));
			return 0.0;
		}
		return mot1->getFloatValueAtTime(trackId, time);
	}
	if(mot1->isNull(trackId))
		return mot2->getFloatValueAtTime(trackId, time);
	return static_cast<float>(mot1->getFloatValueAtTime(trackId, time)*blend
			+  mot2->getFloatValueAtTime(trackId, time)*(1.0-blend));
};

Vec BlendBetween::getVecValueAtTimeInternal   (int trackId, float time)
{
	// if this track doesn't exist in mot2 use mot1 otherwise interpolated between them
	if(mot2->isNull(trackId))
	{
		if(mot1->isNull(trackId))
		{
			Piavca::Error(_T("trying to blend between two invalid tracks"));
			return Vec();
		}
		return mot1->getVecValueAtTime(trackId, time);
	}
	if(mot1->isNull(trackId))
		return mot2->getVecValueAtTime(trackId, time);
	return mot1->getVecValueAtTime(trackId, time)*blend
			+  mot2->getVecValueAtTime(trackId, time)*(1.0f-blend);
};

Quat BlendBetween::getQuatValueAtTimeInternal  (int trackId, float time)
{
	// if this track doesn't exist in mot2 use mot1 otherwise interpolated between them
	if(mot2->isNull(trackId))
	{
		if(mot1->isNull(trackId))
		{
			Piavca::Error(_T("trying to blend between two invalid tracks"));
			return Quat();
		}
		return mot1->getQuatValueAtTime(trackId, time);
	}
	if(mot1->isNull(trackId))
		return mot2->getQuatValueAtTime(trackId, time);
	return slerp(mot1->getQuatValueAtTime(trackId, time),
				mot2->getQuatValueAtTime(trackId, time), blend);
};
