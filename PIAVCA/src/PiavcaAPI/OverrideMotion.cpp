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
 * The Original Code is OverrideMotion.cpp.
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

#include "OverrideMotion.h"
#include "PiavcaError.h"

using namespace Piavca;

int OverrideMotion::getTrackType(int trackId)const 
{
	if(mot1 && !mot1->isNull(trackId))
		return mot1->getTrackType(trackId);
	else
		if(mot2 && !mot2->isNull(trackId))
			return mot2->getTrackType(trackId);
		else 
			return NULL_TYPE;
};

float OverrideMotion::getFloatValueAtTimeInternal (int trackId, float time)
{
	// if this track doesn't exist in mot2 use mot1 otherwise interpolated between them
	if(!mot1 || mot1->isNull(trackId) || !(mot1->getTrackType(trackId) & FLOAT_TYPE))
	{
		if(!mot2 || mot2->isNull(trackId) || !(mot2->getTrackType(trackId) & FLOAT_TYPE))
		{
			Piavca::Error(_T("trying to play two invalid tracks"));
		}
		return mot2->getFloatValueAtTime(trackId, time);
	}
	else
		return mot1->getFloatValueAtTime(trackId, time);
};

Vec   OverrideMotion::getVecValueAtTimeInternal   (int trackId, float time)
{
	// if this track doesn't exist in mot2 use mot1 otherwise interpolated between them
	if(!mot1 || mot1->isNull(trackId) || !(mot1->getTrackType(trackId) & VEC_TYPE))
	{
		if(!mot2 || mot2->isNull(trackId) || !(mot2->getTrackType(trackId) & VEC_TYPE))
		{
			Piavca::Error(_T("trying to play two invalid tracks"));
		}
		return mot2->getVecValueAtTime(trackId, time);
	}
	else
		return mot1->getVecValueAtTime(trackId, time);
};

Quat  OverrideMotion::getQuatValueAtTimeInternal  (int trackId, float time)
{
	if(!mot1 || mot1->isNull(trackId) || !(mot1->getTrackType(trackId) & QUAT_TYPE))
	{
		if(!mot2 || mot2->isNull(trackId) || !(mot2->getTrackType(trackId) & QUAT_TYPE))
		{
			Piavca::Error(_T("trying to play two invalid tracks"));
		}
		return mot2->getQuatValueAtTime(trackId, time);
	}
	else
		return mot1->getQuatValueAtTime(trackId, time);
};
