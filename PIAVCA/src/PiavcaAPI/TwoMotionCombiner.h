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
 * The Original Code is TwoMotionCombiner.h.
 *
 * The Initial Developer of the Original Code is Marco (Mark) Gillies.
 * Portions created by the Initial Developer are Copyright (C) BT plc. 2004
 * All Rights Reserved.
 *
 * ***** END LICENSE BLOCK ***** */


#ifndef TWO_MOTION_COMBINER_H
#define TWO_MOTION_COMBINER_H

#include "Motion.h"
//#include <algorithm>

namespace Piavca
{
	//! A motion manipulator that combine two different motion 
	/*!  This class is an abstract base class that just provides some common features between motion filters.
	 *	To actaully do anything you have to override the get[Float/Quat/Vec]ValueAtTime
	 *  methods to perform whatever opertation you want on the two motion.
	 */
    class PIAVCA_DECL TwoMotionCombiner : public Motion
	{
	protected:
	    Motion *mot1, *mot2;
	public:
		TwoMotionCombiner();
		/*!
		 *	Pass in the two motions you want to combine
		 */
	    TwoMotionCombiner(Motion *m1, Motion *m2) ;
		TwoMotionCombiner(const TwoMotionCombiner &tmc);
		virtual ~TwoMotionCombiner();
	
		void printInfo();

		//! finds the first submotion with a given name
		virtual Motion *findSub(tstring nm);
		//! finds the first submotion with a given type
		virtual Motion *findSubByType(const type_info &ty);

		virtual void load(Avatar *av);
		virtual void unload();
		virtual bool loaded();

		virtual void setStartTime(float time);
	    
		//! gets the length of the combined motion (by default the length of the longer of the two)
		float getMotionLength() const;

		//! whether it is a face or body motion
		virtual bool isFacial();

		
		//! given a track ID tests whether it actually points to anything or if its null
		/*!
		 *	is null if the track is null in both motions.
		 */
		bool isNull(int trackId)const;
		
		//! get the type of the track corresponding to an iterator
		trackType getTrackType(int trackId)const ;

		void setMotion1(Motion *mot);
		void setMotion2(Motion *mot);

		Motion *getMotion1(){return mot1;};
		Motion *getMotion2(){return mot2;}; 
	};
};

#endif //TWO_MOTION_COMBINER_H
