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
 * The Original Code is RandomTimingsMotion.h.
 *
 * The Initial Developer of the Original Code is Marco (Mark) Gillies.
 * Portions created by the Initial Developer are Copyright (C) 2007
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


#ifndef RANDOM_TIMINGS_MOTION_H
#define RANDOM_TIMINGS_MOTION_H

#include "ScaleMotionSpeed.h"

namespace Piavca
{


//! A loop motion where the speed is altered randomly on each time round.
class RandomTimingsMotion : public ScaleMotionSpeed
{
protected:
	float minScale, maxScale;
public:
	/*! 
	 * pass in the motion to be looped, and optionally a time a which to stop
	 * add the interval between the start of the motion and when it restarts.
	 * and most importantly the minimum and maximum timings
	 */
	RandomTimingsMotion(Motion *mot=NULL,
		float min = 1.0, float max = 1.0)
		:ScaleMotionSpeed(mot), 
		minScale(min), maxScale(max)//,
		//scaleSpeed(NULL, 1.0)
		{
			reset();
		};
	RandomTimingsMotion(const RandomTimingsMotion &rtm)
		:ScaleMotionSpeed(rtm), 
		minScale(rtm.minScale), maxScale(rtm.maxScale)
		{
		};
	
	~RandomTimingsMotion(){};
	
	virtual Motion *clone(){return new RandomTimingsMotion(*this);};

	//! returns the name of the type
	Piavca::tstring getClassName(){return "RandomTimingsMotion";};

	//! casts a motion to this type
	static RandomTimingsMotion *castToThisType(Motion *m){return dynamic_cast<RandomTimingsMotion *>(m);};
	
	
	//! sets the minimum and maximum times that can be generated
	virtual void setTimingParams(float minTimeScale, float maxTimeScale)
	{
		minScale = minTimeScale;
		maxScale = maxTimeScale;
	}

	void setMinTimeScale(float minTimeScale)
	{
		minScale = minTimeScale;
	}

	void setMaxTimeScale(float maxTimeScale)
	{
		maxScale = maxTimeScale;
	}

	//! This is called each time around the loop
	virtual void reset()
	{
		ScaleMotionSpeed::reset();
		float tscale = ((float)(rand()%1000));
		tscale *= (maxScale - minScale)/1000.0f;
		tscale += minScale;
		setScaleFactor(tscale);
	}
};
};

#endif //RANDOM_TIMINGS_LOOP
