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
#include <algorithm>

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
		/*!
		 *	Pass in the two motions you want to combine
		 */
	    TwoMotionCombiner(Motion *m1, Motion *m2) 
			:Motion(), mot1(m1), mot2(m2)
		{
			//if(m1) mot1 = m1->clone(); else mot1 = NULL;
			//if(m2) mot2 = m2->clone(); else mot2 = NULL;
			if(mot1) mot1->Reference();
			if(mot2) mot2->Reference();
			if(mot1 && mot2 && (mot1->isFacial() != mot2->isFacial()))
				Piavca::Error(_T("Trying to combine a facial and a body motion"));
		};
		TwoMotionCombiner(const TwoMotionCombiner &tmc)
			:Motion(tmc) //mot1(tmc.mot1), mot2(tmc.mot2)
		{
			if(tmc.mot1) 
			{
				mot1 = tmc.mot1->clone(); 
				mot1->Reference();
			}
			else mot1 = NULL;
			if(tmc.mot2) 
			{
				mot2 = tmc.mot2->clone(); 
				mot2->Reference();
			}
			else mot2 = NULL;
		};
		virtual ~TwoMotionCombiner()
		{
			if(mot1) mot1->Dispose();
			if(mot2) mot2->Dispose();
		}
	
		//virtual Motion *clone(){return new TwoMotionCombiner(*this);};

		//! finds the first submotion with a given name
		virtual Motion *findSub(tstring nm)
		{
			Motion *m = Motion::findSub(nm);
			if(m) 
				return m;
			if(mot1) m = mot1->findSub(nm);
			if(m) 
				return m;
			if(mot2) m = mot2->findSub(nm);
			return m;
		};

		//! finds the first submotion with a given type
		virtual Motion *findSubByType(const type_info &ty)
		{
			Motion *m = Motion::findSubByType(ty);
			if(m) 
				return m;
			if(mot1) m = mot1->findSubByType(ty);
			if(m) 
				return m;
			if(mot2) m = mot2->findSubByType(ty);
			return m;
		};

		virtual void load(Avatar *av)
		{
			Motion::load(av);
			if(mot1)mot1->load(av);
			if(mot2)mot2->load(av);
		}
		virtual void unload()
		{
			Motion::unload();
			if(mot1)mot1->unload();
			if(mot2)mot2->unload();
		}
		virtual bool loaded()
		{
			bool retval = Motion::loaded();
			if(mot1)retval |= mot1->loaded();
			if(mot2)retval |= mot2->loaded();
			return retval;
		}

		virtual void setStartTime(float time)
		{
			Motion::setStartTime(time);
			if(mot1)mot1->setStartTime(time);
			if(mot2)mot2->setStartTime(time);
		}
	    
		//! gets the length of the combined motion (by default the length of the longer of the two)
		float getMotionLength() const
		{
			float l1 = 0.0;
			float l2 = 0.0;
			if(mot1) l1 = mot1->getMotionLength();
			if(mot2) l2 = mot2->getMotionLength();
			if(l1 > l2)
				return l1;
			else 
				return l2;
		};

		//! whether it is a face or body motion
		virtual bool isFacial()
		{
			if(mot1) return mot1->isFacial();
			if(mot2) return mot2->isFacial();
			return false;
		};

		
		//! given a track ID tests whether it actually points to anything or if its null
		/*!
		 *	is null if the track is null in both motions.
		 */
		bool isNull(int trackId)const {return (!mot1 || mot1->isNull(trackId)) && (!mot2 || mot2->isNull(trackId));};
		
		//! get the type of the track corresponding to an iterator
		trackType getTrackType(int trackId)const 
		{
			if(mot1 && !mot1->isNull(trackId))
				return mot1->getTrackType(trackId);
			else
				return mot2->getTrackType(trackId);
		};

		void setMotion1(Motion *mot)
		{
			if(mot) mot->Reference();
			if(mot1) mot1->Dispose(); 
			//delete mot1;
			mot1 = mot;
			if(avatar && mot1)mot1->load(avatar);
			if(mot1 && mot2 && (mot1->isFacial() != mot2->isFacial()))
				Piavca::Error(_T("Trying to combine a facial and a body motion"));
			// this isn't as stupid as it looks, it makes sure the
			// timings of the new motion are updated properly
			setStartTime(startTime);
		};
		void setMotion2(Motion *mot)
		{
			if(mot) mot->Reference();
			if(mot2) mot2->Dispose(); 
			//delete mot2;
			mot2= mot;
			if(avatar && mot2)mot2->load(avatar);
			if(mot1 && mot2 && (mot1->isFacial() != mot2->isFacial()))
				Piavca::Error(_T("Trying to combine a facial and a body motion"));
			// this isn't as stupid as it looks, it makes sure the
			// timings of the new motion are updated properly
			setStartTime(startTime);
		};

		Motion *getMotion1(){return mot1;};
		Motion *getMotion2(){return mot2;}; 
	};
};

#endif //TWO_MOTION_COMBINER_H
