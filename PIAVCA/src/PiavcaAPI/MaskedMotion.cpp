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
 * The Original Code is MaskedMotion.cpp.
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


#include "MaskedMotion.h"
#include "PiavcaAPI/PiavcaCore.h"
#include "PiavcaAPI/PiavcaError.h"

using namespace Piavca;


MotionMask::MotionMask(const MotionMask &mm)
	:m_body(mm.m_body), m_facial(mm.m_facial)
{
};

const MotionMask &MotionMask::operator=(const MotionMask &mm)
{
	m_body = mm.m_body;
	m_facial = mm.m_facial;
	return *this;
};

void MotionMask::setMask(int track, bool val)
{
	int maxTrack = Core::getCore()->getMaxTrackId();
	int minTrack = Core::getCore()->getMinTrackId();

	if(track < minTrack || track > maxTrack)
	{
		Piavca::Error(_T("Unknown track id when setting motion mask"));
		return;
	}

	if(track > 0)
	{
		if(track >= (int)m_body.size())
			for(int i = (int)m_body.size(); i < maxTrack; i++)
				m_body.push_back(false);
		m_body[track] = val;
	}
	else
	{
		track = - track;
		if (track >= (int)m_facial.size())
			for(int i = (int)m_facial.size(); i < -minTrack; i++)
				m_facial.push_back(false);
		m_facial[track] = val;
	}
};
bool MotionMask::getMask(int track) const
{
	if(track > 0 && track < (int)m_body.size())
		return m_body[track];
	track = -track;
	if(track < (int)m_facial.size())
		return m_facial[track];
	return false;
};


void MotionMask::clearMask()
{
	for(int i = 0; i < (int)m_body.size(); i++)
		m_body[i] = false;
	for(int i = 0; i < (int)m_facial.size(); i++)
		m_facial[i] = false;
};

MaskedMotion::MaskedMotion()
	: MotionFilter()
{

};

MaskedMotion::MaskedMotion(Motion *_mot, const MotionMask &_mask) 
	:MotionFilter(_mot), mask(_mask)   {};
MaskedMotion::MaskedMotion(const MaskedMotion &mm)
	:MotionFilter(mm),  mask(mm.mask)
	{};

void MaskedMotion::setMotionMask(std::vector<std::string> v)
{
	mask.clearMask();
	for (int i = 0; i < v.size(); i++)
	{
		int trackid = Core::getCore()->getTrackId(StringToTString(v[i]));
		mask.setMask(trackid, true);
	}
};

StringVector MaskedMotion::getMotionMask()
{
	int maxTrack = Core::getCore()->getMaxTrackId();
	int minTrack = Core::getCore()->getMinTrackId();
	StringVector v;
	for(int i = minTrack; i < maxTrack; i++)
	{
		if(mask.getMask(i))
			v.push_back(Core::getCore()->getTrackName(i));
	}
	return v;
};

float MaskedMotion::getFloatValueAtTimeInternal (int trackId, float time)
{
	// if motion1 has its mask as true then play it 
	// otherwise if motion2 is has a true mask play it
	if(filterMot && mask.getMask(trackId) && !filterMot->isNull(trackId))
		return filterMot->getFloatValueAtTime(trackId, time);
	else 
		return 0.0f;
}

Vec MaskedMotion::getVecValueAtTimeInternal (int trackId, float time)
{
	// if motion1 has its mask as true then play it 
	// otherwise if motion2 is has a true mask play it
	if(filterMot && mask.getMask(trackId) && !filterMot->isNull(trackId))
		return filterMot->getVecValueAtTime(trackId, time);
	else
		return Vec();
}

Quat MaskedMotion::getQuatValueAtTimeInternal (int trackId, float time)
{
	// if motion1 has its mask as true then play it 
	// otherwise if motion2 is has a true mask play it
	if(filterMot && mask.getMask(trackId) && !filterMot->isNull(trackId))
		return filterMot->getQuatValueAtTime(trackId, time);
	else
		return Quat();
}
