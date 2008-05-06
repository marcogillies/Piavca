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
 * The Original Code is Subtract.h.
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


#ifndef SUBTRACT_H
#define SUBTRACT_H

#include "PiavcaAPI/TwoMotionCombiner.h"


namespace Piavca
{
	//! Subtracts one motion (motion1) from the other (motion2)
	/*!	The results is the difference between the effects of both motions (in fact
	 *	with rotations this is achieved with quaternion multiplication but
	 *	the effect is similar to vector subtraction. 
	 */
    class PIAVCA_DECL Subtract : public TwoMotionCombiner
	{
	public:
		Subtract(Motion *m1=NULL, Motion *m2=NULL) :TwoMotionCombiner(m1,m2)
		{
		
		};
		Subtract(const Subtract &su)
			:TwoMotionCombiner(su){};

		virtual Motion *clone(){return new Subtract(*this);};

		//! returns the name of the type
		Piavca::tstring getClassName(){return "Subtract";};

		//! casts a motion to this type
		static Subtract *castToThisType(Motion *m){return dynamic_cast<Subtract *>(m);};
	    
		//! calculates the values of a keyframe
		/*!  The results is  mot1 - mot2
		 */
	    virtual float getFloatValueAtTimeInternal (int trackId, float time);
	    
	    //! calculates the values of a keyframe
		/*!  The results is mot1 - mot2
		 */
	   virtual Vec   getVecValueAtTimeInternal   (int trackId, float time);
	    
	    //! calculates the values of a keyframe
		/*!  The results is the quaternion multiplication of the two motions
		 *  (which is similar to vector addition).
		 */
	    virtual Quat  getQuatValueAtTimeInternal  (int trackId, float time);
	};
};

#endif //SUBTRACT_H
