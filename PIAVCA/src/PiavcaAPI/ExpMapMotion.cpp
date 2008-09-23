/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
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
 * The Original Code is ExpMapMotion.cpp.
 *
 * The Initial Developer of the Original Code is Marco (Mark) Gillies.
 * Portions created by the Initial Developer are Copyright (C) 2008
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
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

#include "ExpMapMotion.h"
#include "PiavcaCore.h"

using namespace Piavca;

ExpMapMotion::ExpMapMotion(Motion *mot)
:MotionFilter(mot)
{
	tangentSpaces = std::vector<TangentSpace>(Piavca::Core::getCore()->getMaxJointId()+1, TangentSpace());
}

ExpMapMotion::ExpMapMotion(std::vector<TangentSpace> tangents, Motion *mot)
:MotionFilter(mot), tangentSpaces(tangents)
{
	
};

ExpMapMotion::ExpMapMotion(const ExpMapMotion &em)
:MotionFilter(em), tangentSpaces(em.tangentSpaces)
{
	
};

int ExpMapMotion::getTrackType(int trackId)const
{
	int mottype = MotionFilter::getTrackType(trackId);
	int newtype = 0;
	if (mottype & FLOAT_TYPE)
		newtype |= FLOAT_TYPE;
	//if (mottype & QUAT_TYPE && mottype & VEC_TYPE)
	//{
	//	newtype |= QUAT_TYPE;
	//	newtype |= VEC_TYPE;
	//}
	if (mottype & QUAT_TYPE || mottype & VEC_TYPE)
		newtype |= QUAT_TYPE;
	return newtype;
}

Quat ExpMapMotion::getQuatValueAtTimeInternal (int trackId, float time)
{
	int mottype = MotionFilter::getTrackType(trackId);
	if (mottype & VEC_TYPE)
		return tangentSpaces[trackId].expMap(MotionFilter::getVecValueAtTimeInternal(trackId, time));
	else if (mottype & QUAT_TYPE)
		return MotionFilter::getQuatValueAtTimeInternal(trackId, time);
}