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
 * The Original Code is SmoothSequence.h.
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

#ifndef SMOOTH_SEQUENCE_H
#define SMOOTH_SEQUENCE_H

//#include "Motion.h"
#include "Sequence.h"
#include "PiavcaCore.h"

namespace Piavca
{
	//! A version of Sequence that uses MotionTranstions and Reposition to achieve a smooth transition between the two motions. 
	/*!
	 *	(SequentialChoice is now preferred)
	 */
	class PIAVCA_DECL SmoothSequence : public Sequence
	{
	protected:
	    float blendInterval;
		float blendStart;
		bool m_accumulateRoot;
		bool maintainY;

		Motion *originalMotion1, *originalMotion2;
	    
	public:
		/*!
		 *	Pass in the two motions, the blend interval (length of the transition) and the start time
		 *	of the transition. To get the second motion to start at the end of the first pass in
		 *	the length of the second motion as the blend start time.
		 */
	    SmoothSequence(Motion *mot1=NULL, Motion *mot2=NULL, float interval = 0.2, float start = -1) 
			:Sequence(mot1, mot2), 
			blendInterval(interval), blendStart(-1),
			maintainY(false), m_accumulateRoot(true),
			originalMotion1(NULL), originalMotion2(NULL)
		{
			create();
		};
		SmoothSequence(const SmoothSequence &sb)
			:Sequence(sb), 
			blendInterval(sb.blendInterval), blendStart(sb.blendStart),
			maintainY(sb.maintainY), m_accumulateRoot(sb.m_accumulateRoot),
			originalMotion1(sb.originalMotion1), originalMotion2(sb.originalMotion2)
		{
			create();
		};
	
		virtual Motion *clone(){return new SmoothSequence(*this);};

		//! returns the name of the type
		Piavca::tstring getClassName(){return "SmoothSequence";};

		//! casts a motion to this type
		static SmoothSequence *castToThisType(Motion *m){return dynamic_cast<SmoothSequence *>(m);};

		void create();

		//! whether vertical root changes are accumulated or not
		virtual void setMaintainY(bool b){maintainY = b;};
		//! whether changes to the root position made by one motion are continued into the next one
		virtual void setAccumulateRoot(bool b){m_accumulateRoot = b;};

		void setMotion1(Motion *mot)
		{
			originalMotion1 = mot;
			create();
		};

		void setMotion2(Motion *mot)
		{
			std::cout << "Smooth Sequence::setMotion2 " << mot << std::endl;
			originalMotion2 = mot;
			create();
		};
	    
		//! set the time at which tbe blend between the motions starts
		void setBlendStart(float start)
		{
			blendStart = start;
			create();
		};
		//! sets the length of the transition between the two motions.
		void setBlendInterval(float interval)
		{
			blendInterval = interval;
			create();
		};

		//! get the time at which tbe blend between the motions starts
		float getBlendStart(){return blendStart;};
		//! gets the length of the transition between the two motions.
		float getBlendInterval(){return blendInterval;};

	};
};

#endif //SMOOTH_SEQUENCE_H
