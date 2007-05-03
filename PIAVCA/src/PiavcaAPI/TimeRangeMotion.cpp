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
 * The Original Code is TimeRangeMotion.cpp.
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

#include "TimeRangeMotion.h"
#include "PiavcaAPI/PiavcaError.h"

using namespace Piavca;

TimeRangeMotion::TimeRangeMotion()
	:MotionFilter(), start(-1), end(-1)
{

};

TimeRangeMotion::TimeRangeMotion(Motion *m, float _start, float _end)
	:MotionFilter(m), start(_start), end(_end)
{
	
};

TimeRangeMotion::TimeRangeMotion(const TimeRangeMotion &sm)
	:MotionFilter(sm), start(sm.start), end(sm.end)
{

};

Motion *TimeRangeMotion::clone()
{
	return new TimeRangeMotion(*this);
};

//! Sets the start of the range to be played
void TimeRangeMotion::setStart(float s)
{
	start = s;
};
//! Sets the end of the range to be played
void TimeRangeMotion::setEnd(float e)
{
	end = e;
};

//! calculates the values of a keyframe
PIAVCA_EXPORT float  TimeRangeMotion::getFloatValueAtTimeInternal (int trackId, float time)
{
	if(!filterMot)
	{
		Piavca::Error(_T("Scale motion speed: trying to get a value from a null motion"));
	}
	if( (start < 0 || time >= start) && (end < 0 || time <= end))
		return filterMot->getFloatValueAtTime(trackId, time);
	else 
		return 0;
};

//! calculates the values of a keyframe
PIAVCA_EXPORT Vec  TimeRangeMotion::getVecValueAtTimeInternal (int trackId, float time)
{
	if(!filterMot)
	{
		Piavca::Error(_T("Scale motion speed: trying to get a value from a null motion"));
	}
	if( (start < 0 || time >= start) && (end < 0 || time <= end))
		return  filterMot->getVecValueAtTime(trackId, time);
	else
		return Vec();
};

//! calculates the values of a keyframe
PIAVCA_EXPORT Quat  TimeRangeMotion::getQuatValueAtTimeInternal (int trackId, float time)
{
	if(!filterMot)
	{
		Piavca::Error(_T("Scale motion speed: trying to get a value from a null motion"));
	}
	Quat q;
	if( (start < 0 || time >= start) && (end < 0 || time <= end))
	{
		q = filterMot->getQuatValueAtTime(trackId, time);
		//std::cout << "time range motion " << q << " " << time << " " << start << " " << end << std::endl;
	}
	else
	{
		q = Quat();
		std::cout << "time range motion out of range" << " " << time << " " << start << " " << end << std::endl;
	}
	return q;
};
