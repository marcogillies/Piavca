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
 * The Original Code is Sequence.h.
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

#ifndef SEQUENCE_H
#define SEQUENCE_H

//#include "Motion.h"
#include "TwoMotionCombiner.h"
#include "PiavcaCore.h"

namespace Piavca
{
	//! Initially plays one motion up to a given time then  another motion
	class PIAVCA_DECL Sequence : public TwoMotionCombiner
	{
	public:
		/*!
		 *	Pass in the two motions
		 */
	    Sequence(Motion *mot1=NULL, Motion *mot2=NULL) 
			:TwoMotionCombiner(mot1, mot2) 
		{
		};
		Sequence(const Sequence &sb)
			:TwoMotionCombiner(sb)
			{};
	
		virtual Motion *clone(){return new Sequence(*this);};

		//! returns the name of the type
		Piavca::tstring getClassName(){return "Sequence";};

		//! casts a motion to this type
		static Sequence *castToThisType(Motion *m){return dynamic_cast<Sequence *>(m);};

		virtual void setStartTime(float time);

		//! gets the motion length (length of first motion + length of second motion)
		float getMotionLength() const
		{
			if(mot1)
			{
				if(mot2)
					return mot1->getMotionLength() + mot2->getMotionLength();
				else
					return mot1->getMotionLength();	
			}
			else
			{
				if(mot2)
					return mot2->getMotionLength();
				else
					return 0;	
			}
		};

	    

		//! gets a combined value of two float tracks if both are valid
		virtual float getCombinedFloatValue (int trackId, float time);

		//! gets a combined value of two Vec tracks if both are valid
		virtual Vec  getCombinedVecValue (int trackId, float time);

		//! gets a combined value of two quaternion tracks if both are valid
		virtual Quat getCombinedQuatValue (int trackId, float time);
	};
};

#endif //SEQUENCE_H
