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
 * The Original Code is ChangeMotionProp.h.
 *
 * The Initial Developer of the Original Code is Vinoba Vinayagamoorthy.
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


#ifndef CHANGE_MOTION_PROP_H
#define CHANGE_MOTION_PROP_H

#include "PiavcaAPI/MotionFilter.h"
//#include "PiavcaCore.h"

namespace Piavca
{
	//! a motion filter that scales the motion's speed
	class PIAVCA_DECL ChangeMotionProp : public MotionFilter
	{
	    float scaleFactor; 
	    float sWindow;
	    float eWindow;
	    float midscale;

	public:
		/*!
		 *	Pass in the motion to be filtered and a scale factor
		 */
	    ChangeMotionProp(Motion *m=NULL, float scale=1.0, float mscale=1, float sw=0.2, float ew=0.2) 
			:MotionFilter(m), scaleFactor(scale), midscale(mscale), sWindow(sw), eWindow(ew) { };
		ChangeMotionProp(const ChangeMotionProp &sm)
			:MotionFilter(sm), scaleFactor(sm.scaleFactor), midscale(sm.midscale), sWindow(sm.sWindow), eWindow(sm.eWindow) { };
		virtual Motion *clone(){return new ChangeMotionProp(*this);};

		//! gets the length of the motion in seconds
		float getMotionLength() const
		{
			float tempt;
			float orgt;
			if(filterMot) {
				orgt = filterMot->getMotionLength();
				tempt = (sWindow*orgt) + (orgt - (sWindow*orgt) - (eWindow*orgt))/scaleFactor + (eWindow*orgt);
				return tempt;	
			}
			else
				return 0;
		};

	    //! gets the value of the motion for a given track at a given time (float -> morph target)
	    PIAVCA_EXPORT virtual float  getFloatValueAtTimeInternal (int trackId, float time)
		{
			if(!filterMot)
			{
				Piavca::Error(_T("Scale motion speed: trying to get a value from a null motion"));
			}
			float t = (time - startTime)*scaleFactor + startTime;
		    return filterMot->getFloatValueAtTime(trackId, t);
		};
	    
	    //! gets the value of the motion for a given track at a given time (vec -> root)
	    PIAVCA_EXPORT virtual Vec  getVecValueAtTimeInternal (int trackId, float time)
		{
		    if(!filterMot)
			{
				Piavca::Error(_T("Scale motion speed: trying to get a value from a null motion"));
			}
			float t = (time - startTime)*scaleFactor + startTime;
		    return  filterMot->getVecValueAtTime(trackId, t);
		};
	    
	    //! gets the value of the motion for a given track at a given time (quat -> joint rotation)
		// startTime = time you start playing the motion
	    PIAVCA_EXPORT virtual Quat  getQuatValueAtTimeInternal (int trackId, float time)
		{
		    if(!filterMot)
			{
				Piavca::Error(_T("Scale motion speed: trying to get a value from a null motion"));
			}
			float t;
			float tdiff = time - startTime;
			float tlen  = filterMot->getMotionLength();
			float nlen  = this->getMotionLength();
			float t1    = sWindow*tlen;
			float t2    = tlen - eWindow*tlen;
			float t2a   = t1 + (t2 - t1)/scaleFactor;
			float tscale = 1.0;
				tscale = midscale;

			if((tdiff > 0) && (tdiff <= t1)){
				t = tdiff + startTime;
				//std::cout << tlen << " " << nlen << " " << tdiff << " S " << t << " " << scaleFactor << " " << (t-time) << std::endl;
			}
			else if((tdiff > t1) && (tdiff <= t2a)){
				t = (tdiff-t1)*scaleFactor + t1 + startTime;
				//std::cout << tlen << " " << nlen << " " << tdiff << " M " << t << " " << scaleFactor << " " << (t-time) << std::endl;
			}
			else if((tdiff > t2a) && (tdiff <= nlen)){
				t = tdiff + (t2 - t2a) + startTime;
				//std::cout << tlen << " " << nlen << " " << tdiff << " E " << t << " " << scaleFactor << " " << (t-time) << std::endl;
			}
			else {
				t = tdiff + (tlen-nlen) + startTime;
			}

			//std::cout << "scale " << tscale << std::endl;
			Quat q = filterMot->getQuatValueAtTime(trackId, t);
			q.Scale(tscale);
			return q;

		};

		//! Sets the scale factor for the postion components of the motion.
	    void setScaleFactor(float scale){scaleFactor = scale;};
		//! Sets the scale factor for the postion components of the motion.
	    void setMidScaleFactor(float scale){midscale = scale;};
		//! Sets the start window for the postion components of the motion.
	    void setStartWindow(float swin){sWindow = swin;};
		//! Sets the end window for the postion components of the motion.
	    void setEndWindow(float ewin){eWindow = ewin;};

	};
};

#endif //CHANGE_MOTION_PROP_H

