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
 * The Original Code is MotionFilter.h.
 *
 * The Initial Developer of the Original Code is Marco (Mark) Gillies.
 * Portions created by the Initial Developer are Copyright (C) BT plc. 2004
 * All Rights Reserved.
 *
 * ***** END LICENSE BLOCK ***** */


#ifndef MOTION_FILTER_H
#define MOTION_FILTER_H

#include "Motion.h"

namespace Piavca
{
	//! A motion class whose output is some transformation of another motion.
	/*!  This class is an abstract base class that just provides some common features between motion filters.
	 *	To actaully do anything you have to override the get[Float/Quat/Vec]ValueAtTime
	 *  methods to perform whatever opertation you want on the other motion.
	 */
    class PIAVCA_DECL MotionFilter : public Motion
	{
	protected:
	   Motion *filterMot; 
	public:
		//! default constructor
		MotionFilter():Motion(), filterMot(NULL)
		{

		}
		//! pass in the motion to be filtered.
		MotionFilter(Motion *mot) 
			:Motion(), filterMot(mot)
		{
			if(filterMot) filterMot->Reference();
			//if(mot) filterMot = mot->clone(); else filterMot = NULL;
		};
		MotionFilter(const MotionFilter &mf)
			:Motion(mf)//, filterMot(mf.filterMot->clone())
		{
			if(mf.filterMot) 
			{
				filterMot = mf.filterMot->clone();
				filterMot->Reference();
			}
			else 
				filterMot = NULL;
		};
		virtual ~MotionFilter()
		{
			if(filterMot) filterMot->Dispose();
		}

		void printInfo()
		{
			Motion::printInfo();
			debug_prefix++;
			if(filterMot)filterMot->printInfo();
			debug_prefix--;
		};

		//! finds the first submotion with a given name
		virtual Motion *findSub(tstring nm)
		{
			Motion *m = Motion::findSub(nm);
			if(m) 
				return m;
			if(filterMot)
				return filterMot->findSub(nm);
			return NULL;
		};


		//! finds the first submotion with a given type
		virtual Motion *findSubByType(const type_info &ty)
		{
			Motion *m = Motion::findSubByType(ty);
			if(m) 
				return m;
			if(filterMot) m = filterMot->findSubByType(ty);
			return m;
		};

		virtual void load(Avatar *av)
		{
			Motion::load(av);
			if(filterMot)filterMot->load(av);
		}
		virtual void unload()
		{
			Motion::unload();
			if(filterMot)filterMot->unload();
		}
		virtual bool loaded()
		{
			if(filterMot)
				return Motion::loaded() || filterMot->loaded();
			else
				return Motion::loaded();
		}

		virtual void setStartTime(float time)
		{
			Motion::setStartTime(time);
			if(filterMot)filterMot->setStartTime(time);
		}
	    
		void setMotion(Motion *mot)
		{
			if(mot)
				mot->Reference();
			if(filterMot)
				filterMot->Dispose();
			filterMot = mot;
			if(avatar && filterMot)filterMot->load(avatar);
			// this isn't as stupid as it looks, it makes sure the
			// timings of the filter motion are updated properly
			setStartTime(startTime);
		}

		//! gets the length of the motion in seconds
		float getMotionLength() const
		{
			if(filterMot)
				return filterMot->getMotionLength();	
			else
				return 0;
		};

		//! whether it is a face or body motion
		virtual bool isFacial()
		{
			if(filterMot)
				return filterMot->isFacial();
			else
				return false;
		};

		//! given an iterator tests whether it actually points to anything or if its null
		virtual bool isNull(int trackId)const 
		{
			if(filterMot)
				return filterMot->isNull(trackId);
			else
				return true;
		};
		//! get the type of the track corresponding to an iterator
		trackType getTrackType(int trackId)const 
		{
			if(filterMot)
				return filterMot->getTrackType(trackId);
			else
				return NULL_TYPE;
		};
	};
};

#endif //MOTION_FILTER_H
