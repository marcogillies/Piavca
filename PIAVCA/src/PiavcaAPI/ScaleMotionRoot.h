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
 * The Original Code is ScaleMotionRoot.h.
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


#ifndef SCALE_MOTION_ROOT_H
#define SCALE_MOTION_ROOT_H

#include "PiavcaAPI/MotionFilter.h"
//#include "PiavcaCore.h"

namespace Piavca
{
	//! a motion filter that scales the displacement (position) parts of the motion
	/*!
	 *	This is basically useful for converting bvh files that are expressed in feet and inches to metres
	 *	but might also be useful for motion retargeting.
	 */
    class PIAVCA_DECL ScaleMotionRoot : public MotionFilter
	{
	    float scaleFactor; 
	    
	public:
		/*!
		 *	Pass in the motion to be filtered and a scale factor
		 */
	    ScaleMotionRoot(Motion *m=NULL, float scale=1.0) :MotionFilter(m), scaleFactor(scale)
		{
		};
		ScaleMotionRoot(const ScaleMotionRoot &sm)
			:MotionFilter(sm), scaleFactor(sm.scaleFactor){};
		virtual ~ScaleMotionRoot(){};
	
		virtual Motion *clone(){return new ScaleMotionRoot(*this);};

		//! returns the name of the type
		Piavca::tstring getClassName(){return "ScaleMotionRoot";};

		//! casts a motion to this type
		static ScaleMotionRoot *castToThisType(Motion *m){return dynamic_cast<ScaleMotionRoot *>(m);};
	    
	    //! calculates the values of a keyframe
	    PIAVCA_EXPORT virtual float  getFloatValueAtTimeInternal (int trackId, float time)
		{
			if(!filterMot)
			{
				Piavca::Error(_T("Scale motion root: trying to get a value from a null motion"));
			}
		    return filterMot->getFloatValueAtTime(trackId, time);
		};
	    
	    //! calculates the values of a keyframe (vec values are scaled)
	    PIAVCA_EXPORT virtual Vec  getVecValueAtTimeInternal (int trackId, float time)
		{
		    if(!filterMot)
			{
				Piavca::Error(_T("Scale motion root: trying to get a value from a null motion"));
			}
			if(trackId == root_position_id)
			    return  filterMot->getVecValueAtTime(trackId, time)*scaleFactor;
			else
			    return  filterMot->getVecValueAtTime(trackId, time);
		};
	    
	    //! calculates the values of a keyframe
	    PIAVCA_EXPORT virtual Quat  getQuatValueAtTimeInternal (int trackId, float time)
		{
		    if(!filterMot)
			{
				Piavca::Error(_T("Scale motion root: trying to get a value from a null motion"));
			}
		    return filterMot->getQuatValueAtTime(trackId, time);
		};

		//! Sets the scale factor for the postion components of the motion.
	    void setScaleFactor(float scale){scaleFactor = scale;};
	};
};

#endif //SCALE_MOTION_ROOT_H
