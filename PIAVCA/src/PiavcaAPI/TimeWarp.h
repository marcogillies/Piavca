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
 * The Original Code is ScaleMotionSpeed.h.
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


#ifndef TIME_WARP_H
#define TIME_WARP_H
#include "PiavcaAPI/MotionFilter.h"
//#include "PiavcaCore.h"
#include "TypeConvert.h"

namespace Piavca
{
	//! A motion filter that scales the motion's speed based on the output of another motion (the warp function).
    class PIAVCA_DECL TimeWarp : public MotionFilter
	{
	    Motion *warpFunc; 
	    
	public:
		/*!
		 *	Pass in the motion to be filtered and a scale factor
		 */
	    TimeWarp(Motion *m=NULL, Motion *warp=NULL) :MotionFilter(m), warpFunc(warp)
		{
		};
		TimeWarp(const TimeWarp &tw)
			:MotionFilter(tw), warpFunc(tw.warpFunc){};
	
		virtual Motion *clone(){return new TimeWarp(*this);};

		//! returns the name of the type
		Piavca::tstring getClassName(){return "TimeWarp";};

		//! casts a motion to this type
		static TimeWarp *castToThisType(Motion *m){return dynamic_cast<TimeWarp *>(m);};

		//! gets the length of the motion in seconds
		virtual float getMotionLength() const
		{
			if(warpFunc)
				return warpFunc->getMotionLength();
			else if(filterMot)
				return filterMot->getMotionLength();	
			else
				return 0;
		};
	    
	    //! calculates the values of a keyframe
	    PIAVCA_EXPORT virtual float  getFloatValueAtTimeInternal (int trackId, float time)
		{
			if(!filterMot)
			{
				Piavca::Error(_T("Scale motion speed: trying to get a value from a null motion"));
			}
			float t = time;
			if(warpFunc && warpFunc->getTrackType(trackId) & FLOAT_TYPE)
				t = warpFunc->getFloatValueAtTime(trackId, time);
		    return filterMot->getFloatValueAtTime(trackId, t);
		};
	    
	    //! calculates the values of a keyframe
	    PIAVCA_EXPORT virtual Vec  getVecValueAtTimeInternal (int trackId, float time)
		{
		    if(!filterMot)
			{
				Piavca::Error(_T("Scale motion speed: trying to get a value from a null motion"));
			}
			float t = time;
			if(warpFunc && warpFunc->getTrackType(trackId) & FLOAT_TYPE)
				t = warpFunc->getFloatValueAtTime(trackId, time);
		    return  filterMot->getVecValueAtTime(trackId, t);
		};
	    
	    //! calculates the values of a keyframe
	    PIAVCA_EXPORT virtual Quat  getQuatValueAtTimeInternal (int trackId, float time)
		{
		    if(!filterMot)
			{
				Piavca::Error(_T("Scale motion speed: trying to get a value from a null motion"));
			}
			float t = time;
			if(warpFunc && warpFunc->getTrackType(trackId) & FLOAT_TYPE)
				t = warpFunc->getFloatValueAtTime(trackId, time);
		    return filterMot->getQuatValueAtTime(trackId, t);
		};

		//! Sets the scale factor for the postion components of the motion.
	    void setWarp(Motion *warp){warpFunc = warp;};
		Motion *getWarp(){return warpFunc;};
		
		//! a generic function for setting parameters
		virtual bool setParameter(tstring paramName, tstring value)
		{
			if(paramName == _T("Warp") || paramName == _T("warp"))
			{
				setWarp(convert<Motion *>(value));
				return true;
			}
			return MotionFilter::setParameter(paramName, value);
		}
	};
};

#endif //TIME_WARP_H
