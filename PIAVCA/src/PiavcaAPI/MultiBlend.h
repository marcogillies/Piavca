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
 * The Original Code is MultiBlend.h.
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


#ifndef MULTI_BLEND_H
#define MULTI_BLEND_H

#include "MultiMotionCombiner.h"
#include "CurrentValueMotion.h"


namespace Piavca
{
	//! Does a weighted blend of a number of different motions
    class PIAVCA_DECL MultiBlend : public MultiMotionCombiner 
    // TwoMotionCombiner
	{
		CurrentValueMotion *currentValueWeights;
		Motion *weightMot;
		tstring Weight_name;
	public:
		MultiBlend():MultiMotionCombiner(), currentValueWeights(NULL), weightMot(NULL), Weight_name("") {};
		MultiBlend(const MotionVec &mv) :MultiMotionCombiner(mv),currentValueWeights(NULL), weightMot(NULL), Weight_name("") {};
		//MotionAdder(Motion *m1=NULL, Motion *m2=NULL/*, float _scaleSecond = 1.0*/) :TwoMotionCombiner(m1,m2){};//, scaleSecond(_scaleSecond){};
		MultiBlend(const MultiBlend &ma)
			:MultiMotionCombiner(ma),currentValueWeights(NULL), weightMot(NULL), Weight_name("") {};//, scaleSecond(ma.scaleSecond){};

		virtual Motion *clone(){return new MultiBlend(*this);};

		//! returns the name of the type
		Piavca::tstring getClassName(){return "MultiBlend";};

		//! casts a motion to this type
		static MultiBlend *castToThisType(Motion *m){return dynamic_cast<MultiBlend *>(m);};
		
		//! a generic function for setting parameters
		virtual bool setParameter(tstring paramName, tstring value);
		
		//! a generic function for setting parameters relating to specific submotions
		virtual bool setMotionParameter(int motIndex, tstring paramName, tstring value);

		void setWeightMotionName(tstring name)
		{
			Weight_name = name;
			int Weight_id = getMotionIndex(name);
			std::cout << "proxemics: setting target motion name" << Weight_name << " " << Weight_id << std::endl;
			setWeightId(Weight_id);
		}
		tstring getWeightMotionName()
		{
			return Weight_name;
		}

		//! sets the weight assiged to a particular motion
		void setWeight(int id, float val);
		float getWeight(int id, float time = -1);
		void setWeightId(int weightId);

	    
		//! calculates the values of a keyframe
		/*!  The results is the sum of the two motions.
		 */
	    virtual float getFloatValueAtTimeInternal (int trackId, float time);
	    
	    //! calculates the values of a keyframe
		/*!  The results is the sum of the two motions.
		 */
	   virtual Vec   getVecValueAtTimeInternal   (int trackId, float time);
	    
	    //! calculates the values of a keyframe
		/*!  The results is the quaternion multiplication of the two motions
		 *  (which is similar to vector addition).
		 */
	    virtual Quat  getQuatValueAtTimeInternal  (int trackId, float time);
	};
};

#endif //MULTI_BLEND_H
