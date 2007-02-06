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
 * The Original Code is SubMotion.cpp.
 *
 * The Initial Developer of the Original Code is Marco (Mark) Gillies.
 * Portions created by the Initial Developer are Copyright (C) 2005
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

#include "SubMotion.h"
#include "PiavcaAPI/PiavcaError.h"

using namespace Piavca;

float SubMotion::getAdjustedTime(float time)
{
	time = time - getStartTime();
	std::cout << "start " << start << " time " << time << " ";
	if(start >= 0) time += start;
	std::cout << time << " end " << end << " ";
	if(end >= 0 && time > end) time = end;
	std::cout << " time " << time << std::endl;
	return time + getStartTime();
}

SubMotion::SubMotion()
	:MotionFilter(), start(-1), end(-1)
{

};

SubMotion::SubMotion(Motion *m, float _start, float _end)
	:MotionFilter(m), start(_start), end(_end)
{
	if(filterMot)
	{
		//std::cout << "Submotion constructor: start " << start << " end " << end << std::endl;
		if (filterMot->getMotionLength() < start)
			Piavca::Error(_T("SubMotion: start is greater than motion length"));
	}
};

SubMotion::SubMotion(const SubMotion &sm)
	:MotionFilter(sm), start(sm.start), end(sm.end)
{

};

Motion *SubMotion::clone()
{
	return new SubMotion(*this);
};

//! gets the length of the motion in seconds
float SubMotion::getMotionLength() const
{
	if(filterMot)
	{
		//std::cout << "Submotion: start " << start << " end " << end << std::endl;
		float s = 0;
		if(start >= 0) s = start;
		//std::cout << "s " << s << std::endl;
		float e = filterMot->getMotionLength();
		if(end >= 0 && end < e) e = end;
		//std::cout << "e " << e << std::endl;
		if ((e-s) <= 0) Piavca::Error(_T("Motion length < 0"));
		return e - s;	
	}
	else
		return 0;
};

//! Sets the start of the range to be played
void SubMotion::setStart(float s)
{
	start = s;
};
//! Sets the end of the range to be played
void SubMotion::setEnd(float e)
{
	end = e;
};

//! calculates the values of a keyframe
PIAVCA_EXPORT float  SubMotion::getFloatValueAtTimeInternal (int trackId, float time)
{
	if(!filterMot)
	{
		Piavca::Error(_T("Scale motion speed: trying to get a value from a null motion"));
	}
	return filterMot->getFloatValueAtTime(trackId, getAdjustedTime(time));
};

//! calculates the values of a keyframe
PIAVCA_EXPORT Vec  SubMotion::getVecValueAtTimeInternal (int trackId, float time)
{
	if(!filterMot)
	{
		Piavca::Error(_T("Scale motion speed: trying to get a value from a null motion"));
	}
	return  filterMot->getVecValueAtTime(trackId, getAdjustedTime(time));
};

//! calculates the values of a keyframe
PIAVCA_EXPORT Quat  SubMotion::getQuatValueAtTimeInternal (int trackId, float time)
{
	if(!filterMot)
	{
		Piavca::Error(_T("Scale motion speed: trying to get a value from a null motion"));
	}
	return filterMot->getQuatValueAtTime(trackId, getAdjustedTime(time));
};
