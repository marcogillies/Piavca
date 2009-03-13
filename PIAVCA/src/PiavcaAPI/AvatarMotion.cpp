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
 * The Original Code is AvatarMotion.cpp.
 *
 * The Initial Developer of the Original Code is Marco (Mark) Gillies.
 * Portions created by the Initial Developer are Copyright (C) BT plc. 2009
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
 *
 * ***** END LICENSE BLOCK ***** */

#include "AvatarMotion.h"
#include "PiavcaError.h"

using namespace Piavca;

//! given a track ID tests whether it actually points to anything or if its null
bool AvatarMotion::isNull(int trackId) const 
{
	if (m_wrapped_avatar)
		return m_wrapped_avatar->isNull(trackId);
	return true;
}

//! get the type of the track corresponding to an ID
int AvatarMotion::getTrackType(int trackId)const 
{
	if(isNull(trackId))
		return NULL_TYPE;
	if  (trackId < 0)
		return FLOAT_TYPE;
	else
		return QUAT_TYPE | VEC_TYPE;
};

//! get the value of a track at a given time (only works for floats)
float AvatarMotion::getFloatValueAtTimeInternal(int trackId, float time)
{
	if (!(getTrackType(trackId) & FLOAT_TYPE))
		Piavca::Error("AvatarMotion::Trying to get a float value from a joint or null expression"); 
	return m_wrapped_avatar->getFacialExpressionWeight(trackId);
};
//! get the value of a track at a given time (only works for Vecs)
Vec AvatarMotion::getVecValueAtTimeInternal(int trackId, float time)
{
	if (!(getTrackType(trackId) & VEC_TYPE))
	{
		if(isNull(trackId))
			std::cout << "The track " << trackId << " is null" << std::endl;
		std::cout << "The track " << trackId << " is of type " << getTrackType(trackId) << std::endl;
		Piavca::Error("AvatarMotion::Trying to get a vec value from an expression or null joint"); 
	}
	if (global)
		return m_wrapped_avatar->getJointBasePosition(trackId, WORLD_COORD);
	else
		return m_wrapped_avatar->getJointBasePosition(trackId, JOINTLOCAL_COORD);
};
//! get the value of a track at a given time (only works for Quats) 
Quat AvatarMotion::getQuatValueAtTimeInternal(int trackId, float time)
{
	if (!(getTrackType(trackId) & QUAT_TYPE))
		Piavca::Error("AvatarMotion::Trying to get a quat value from an expression or null joint"); 
	if (global)
		return m_wrapped_avatar->getJointOrientation(trackId, WORLD_COORD);
	else
		return m_wrapped_avatar->getJointOrientation(trackId, JOINTLOCAL_COORD);
};