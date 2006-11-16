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
 * The Original Code is MotionSaver.h.
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


#ifndef MOTION_SAVER_H
#define MOTION_SAVER_H

#include "PiavcaAPI/MotionFilter.h"
#include "PiavcaAPI/KeyframeMotion.h"

namespace Piavca
{
	/*! Saves the kefyrames of a motion while its playing on a character
     *	This sits between a motion and a character passing the data 
	 *  unchanged between the two, but it also saves the data as keyframes.
	 *  Call save to save it to file in the Piavca (.pia) format
	 */
	class MotionSaver : public MotionFilter
	{
		KeyframeMotion *tmot;
	public:
		MotionSaver(Motion *mot):MotionFilter(mot)
		{
			tmot = new KeyframeMotion(mot->isFacial());
		};
		MotionSaver(const MotionSaver &to):MotionFilter(to), tmot(to.tmot){};
	
		virtual Motion *clone(){return new MotionSaver(*this);};
	
	    //! calculates the values of the filter motion on and saves them to a KeyframeMotion
	    PIAVCA_EXPORT virtual float  getFloatValueAtTimeInternal (int trackId, float time);
	    
	    //! calculates the values of the filter motion on and saves them to a KeyframeMotion
	    PIAVCA_EXPORT virtual Vec  getVecValueAtTimeInternal (int trackId, float time);
	    
	    //! calculates the values of the filter motion on and saves them to a KeyframeMotion
	    PIAVCA_EXPORT virtual Quat  getQuatValueAtTimeInternal (int trackId, float time);

		//! runs through the motion storing frame at the given framerate
		PIAVCA_EXPORT void collectFrames(float framerate);

		PIAVCA_EXPORT void save(tstring filename);
	};
}
#endif //MOTION_SAVER_H
