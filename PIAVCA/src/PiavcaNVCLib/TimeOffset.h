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
 * The Original Code is TimeOffset.h.
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


#ifndef TIME_OFFSET_H
#define TIME_OFFSET_H

#include "PiavcaAPI/MotionFilter.h"

namespace Piavca
{
	//! changes the start time of a motion by an offset
	class TimeOffset : public MotionFilter
	{
		float offset;
	public:
		TimeOffset(Motion *mot=NULL, float offs=0.0f):MotionFilter(mot), offset(offs){};
		TimeOffset(const TimeOffset &to):MotionFilter(to), offset(to.offset){};
	
		virtual Motion *clone(){return new TimeOffset(*this);};

		virtual void setStartTime(float time)
		{
			Motion::setStartTime(time);
			if(filterMot)filterMot->setStartTime(time+offset);
		}
	
	    //! calculates the values of a keyframe
	    PIAVCA_EXPORT virtual float  getFloatValueAtTimeInternal (int trackId, float time)
		{
			if(!filterMot)
			{
				Piavca::Error(_T("TimeOffset: trying to get a value from a null motion"));
			}
		    return filterMot->getFloatValueAtTime(trackId, time);
		};
	    
	    //! calculates the values of a keyframe (vec values are scaled)
	    PIAVCA_EXPORT virtual Vec  getVecValueAtTimeInternal (int trackId, float time)
		{
		    if(!filterMot)
			{
				Piavca::Error(_T("TimeOffset: trying to get a value from a null motion"));
			}
			return  filterMot->getVecValueAtTime(trackId, time);
		};
	    
	    //! calculates the values of a keyframe
	    PIAVCA_EXPORT virtual Quat  getQuatValueAtTimeInternal (int trackId, float time)
		{
		    if(!filterMot)
			{
				Piavca::Error(_T("TimeOffset: trying to get a value from a null motion"));
			}
		    return filterMot->getQuatValueAtTime(trackId, time);
		};

		//! Sets the scale factor for the postion components of the motion.
	    void setOffset(float offs)
		{
			offset = offs;
			if(filterMot)filterMot->setStartTime(getStartTime()+offset);
		};
	};
}
#endif //TIME_OFFSET_H
