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

#ifndef BLEND_BETWEEN_H
#define BLEND_BETWEEN_H

#include "TwoMotionCombiner.h"
//#include "PiavcaCore.h"


namespace Piavca
{
    //! Interpolates between two motions.
	/*!	The resulting motion is an interpolation between the two motion using 
	 *	slerp for quaternions with a parameter value blend. This class blends 
	 *	the two motions concurrently rather blending from one to another as 
	 *	sequential blend does.
	 */
    class PIAVCA_DECL BlendBetween : public TwoMotionCombiner
	{
	    float blend; 
	    
	public:
	    //! Pass in the two motion and the interpolation parameter blend (has to be between 0 and 1)
	    BlendBetween(Motion *m1=NULL, Motion *m2=NULL, float _blend=0.0f);
		BlendBetween(const BlendBetween &b);

		virtual Motion *clone()
		{
			return new BlendBetween(*this);
		}

		//! returns the name of the type
		Piavca::tstring getClassName(){return "BlendBetween";};

		//! casts a motion to this type
		static BlendBetween *castToThisType(Motion *m){return dynamic_cast<BlendBetween *>(m);};



		//! gets a combined value of two float tracks if both are valid
		virtual float getCombinedFloatValue (int trackId, float time);

		//! gets a combined value of two Vec tracks if both are valid
		virtual Vec  getCombinedVecValue (int trackId, float time);

		//! gets a combined value of two quaternion tracks if both are valid
		virtual Quat getCombinedQuatValue (int trackId, float time);

		void setBlendFactor(float _blend){blend = _blend;};
		float getBlendFactor(){return blend;};
		
		//! a generic function for setting parameters
		virtual bool setParameter(tstring paramName, tstring value);
};

};

#endif //BLEND_BETWEEN_H
