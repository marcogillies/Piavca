/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1
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
 * The Original Code is BlendBetween.h.
 *
 * The Initial Developer of the Original Code is Marco (Mark) Gillies.
 * Portions created by the Initial Developer are Copyright (C) BT plc. 2004
 * All Rights Reserved.
 *
 * ***** END LICENSE BLOCK ***** */

#ifndef BLEND_BETWEEN_H
#define BLEND_BETWEEN_H

#include "TwoMotionCombiner.h"
//#include "PiavcaCore.h"


namespace Piavca
{
    //! A motion manipulator class that interpolates between two motions.
	/*!	The resulting motion is an interpolation between the two motion using 
	 *	slerp for quaternions with a parameter value blend. This class blends 
	 *	the two motions concurrently rather blending from one to another as 
	 *	sequential blend does.
	 */
    class BlendBetween : public TwoMotionCombiner
	{
	    float blend; 
	    
	public:
	    //! Pass in the two motion and the interpolation parameter blend (has to be between 0 and 1)
	    BlendBetween(Motion *m1, Motion *m2, float _blend) ;
		BlendBetween(const BlendBetween &b);

		virtual Motion *clone()
		{
			return new BlendBetween(*this);
		}

	    //! calculates the values of a keyframe.
		/*!	The result is the linear interpolation of the values of the two motions
		 *  or if the track does not exist in the one motion, the value of the other
		 */
	    virtual float getFloatValueAtTimeInternal (int trackId, float time);
	    
	    //! calculates the values of a keyframe.
		/*!	The result is the linear interpolation of the values of the two motions
		 *  or if the track does not exist in the one motion, the value of the other
		 */
	    virtual Vec   getVecValueAtTimeInternal   (int trackId, float time);
	    
	    //! calculates the values of a keyframe.
		/*!	The result is the linear interpolation (slerp) of the values of the two motions
		 *  or if the track does not exist in the one motion, the value of the other
		 */
	    virtual Quat  getQuatValueAtTimeInternal  (int trackId, float time);

		void setBlendFactor(float _blend){blend = _blend;};
};

};

#endif //BLEND_BETWEEN_H
