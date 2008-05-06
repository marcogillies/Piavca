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
 * The Original Code is OnTheSpot.h.
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


#ifndef ON_THE_SPOT_H
#define ON_THE_SPOT_H

#include "PiavcaAPI/MotionFilter.h"

namespace Piavca
{
	//! a motion filter that zeros the root position motion so the avatar doesn't move
    class PIAVCA_DECL OnTheSpot : public MotionFilter
	{
	public:
		/*!
		 *	Pass in the motion to be filtered and a scale factor
		 */
	    OnTheSpot(Motion *m=NULL) :MotionFilter(m)
		{
		};
		OnTheSpot(const OnTheSpot &sm) :MotionFilter(sm){};
	
		virtual Motion *clone(){return new OnTheSpot(*this);};

		//! returns the name of the type
		Piavca::tstring getClassName(){return "OnTheSpot";};

		//! casts a motion to this type
		static OnTheSpot *castToThisType(Motion *m){return dynamic_cast<OnTheSpot *>(m);};
	    
	    //! calculates the values of a keyframe
	    PIAVCA_EXPORT virtual float  getFloatValueAtTimeInternal (int trackId, float time)
		{
			if(!filterMot)
				return 0.0;
			return filterMot->getFloatValueAtTime(trackId, time);
		};
	    
	    //! calculates the values of a keyframe
	    PIAVCA_EXPORT virtual Vec  getVecValueAtTimeInternal (int trackId, float time)
		{
		    if(!filterMot)
				return Vec();
			if(trackId == root_position_id)
				return Vec();
			return  filterMot->getVecValueAtTime(trackId, time);
		};
	    
	    //! calculates the values of a keyframe
	    PIAVCA_EXPORT virtual Quat  getQuatValueAtTimeInternal (int trackId, float time)
		{
		    if(!filterMot)
				return Quat();
		    return filterMot->getQuatValueAtTime(trackId, time);
		};

	};
};

#endif //ON_THE_SPOT_H
