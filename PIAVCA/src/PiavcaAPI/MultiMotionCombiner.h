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
 * The Original Code is MultiMotionCombiner.h.
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


#ifndef MULTI_MOTION_COMBINER_H
#define MULTI_MOTION_COMBINER_H

#include "PiavcaAPI/MotionFilter.h"

namespace Piavca
{

typedef std::vector< Motion * > MotionVec;

//! A loop class with a set of different motions.
/*!
 *	One of these motions is chosen each time around the loop.
 *  This is a base class for other loop classes.
 *  It is a template so that it can either be a sub class of a 
 *  normal LoopMotion or a RandomTimingsLoop (or something else)
 */
class MultiMotionCombiner : public MotionFilter
{
protected:
	MotionVec mots;
public:
	//! pass in a vector of motions to be used.
	MultiMotionCombiner(const MotionVec &mv)
		:MotionFilter(), mots(mv)
	{
		MotionVec::size_type i;
		for(i = 0; i < mots.size(); i++)
		{
			mots[i]->Reference();
		}
		if(mots.size() > 0)setMotion(mots[0]);
	};
	//! create an empty multi-motionloop
	MultiMotionCombiner()
		:MotionFilter(), mots()
	{
	};
	MultiMotionCombiner(const MultiMotionCombiner &rl)
		:MotionFilter(rl), mots(rl.mots)
	{
		for(MotionVec::size_type i = 0; i < mots.size(); i++)
		{
			mots[i] = mots[i]->clone();
			mots[i]->Reference();
		}
	}
	~MultiMotionCombiner()
	{
		for(MotionVec::size_type i = 0; i < mots.size(); i++)
			Motion::Dispose(mots[i]);//->Dispose();
	}
	virtual Motion *clone(){return new MultiMotionCombiner(*this);};

	//! returns the name of the type
	Piavca::tstring getClassName(){return "MultiMotionCombiner";};

	//! casts a motion to this type
	static MultiMotionCombiner *castToThisType(Motion *m){return dynamic_cast<MultiMotionCombiner *>(m);};

	void printInfo()
	{
		Motion::printInfo();
		debug_prefix++;
		for(MotionVec::size_type i = 0; i < mots.size(); i++)
			mots[i]->printInfo();
		debug_prefix--;
	};
	
	int getLastMotion()
	{
		return getNumMotions()-1;
	}

	//adds a new motion
	virtual void addMotion(Motion *mot)
	{
		std::cout << "in Mutlimotioncombiner::addMotion\n";
		if(mot)
		{
			mots.push_back(mot);
			mots.back()->Reference();
			if(mots.size() == 1) setMotion(mots.back());
		}
	}

	int getMotionIndex(tstring motionName)
	{
		for (int i = 0; i < mots.size(); i++)
			if (mots[i]->getName() == motionName)
				return i;
		return -1;
	}

	int getNumMotions()
	{
		return mots.size();
	};

	Motion *getMotionByIndex(int index)
	{
		if (index < 0 || index >= mots.size())
			Piavca::Error(_T("invalid index"));
		return mots[index];
	}
	
	Motion *getMotion(int index)
	{
		return getMotionByIndex(index);
	}
	
	Motion *getMotion(tstring motionName)
	{
		int i = getMotionIndex(motionName);
		if (i < 0)
			return NULL;
		else
			return getMotionByIndex(i);
	}
	
	void removeMotionByIndex(int index)
	{
		Motion::Dispose(mots[index]);//->Dispose();
		mots.erase(mots.begin() + index);
	}
	
	void clear()
	{
		for (int i = 0; i < mots.size(); i++)
			Motion::Dispose(mots[i]);//->Dispose();
		mots.clear();
	}

	//! finds the first submotion with a given name
	virtual Motion *findSub(tstring nm)
	{
		Motion *m = Motion::findSub(nm);
		if(m) 
			return m;
		for (MotionVec::size_type i = 0; i < mots.size(); i++)
		{
			m = mots[i]->findSub(nm);
			if(m) return m;
		}
		return NULL;
	};

	//! finds the first submotion with a given type
	virtual Motion *findSubByType(const type_info &ty)
	{
		Motion *m = Motion::findSubByType(ty);
		if(m) 
			return m;
		for (MotionVec::size_type i = 0; i < mots.size(); i++)
		{
			m = mots[i]->findSubByType(ty);
			if(m) return m;
		}
		return NULL;
	};

	virtual void load(Avatar *av)
	{
		Motion::load(av);
		for(MotionVec::size_type i = 0; i < mots.size(); i++)
			mots[i]->load(av);
	}
	virtual void unload()
	{
		Motion::unload();
		for(MotionVec::size_type i = 0; i < mots.size(); i++)
			mots[i]->unload();
	}
	virtual bool loaded(Avatar *av)
	{
		bool retval = Motion::loaded();
		for(MotionVec::size_type i = 0; i < mots.size(); i++)
			retval |= mots[i]->loaded();
		return retval;
	}
		
	//! gets the avatar that the motion is loaded into
	virtual Avatar *getAvatar()
	{
		Avatar *av = Motion::getAvatar();
		if (av)
			return av;
		for(MotionVec::size_type i = 0; i < mots.size(); i++)
		{
			av = mots[i]->getAvatar();
			if (av) return av;
		}
		return NULL;
	}
		
	virtual void preFrame(float time)
	{
		for(MotionVec::size_type i = 0; i < mots.size(); i++)
		{
			mots[i]->preFrame(time);
		}
	}

	virtual void setStartTime(float time)
	{
		Motion::setStartTime(time);
		for(MotionVec::size_type i = 0; i < mots.size(); i++)
		{
			mots[i]->setStartTime(time);
		}
	}

	//! does any resetting needed 
	bool reset(bool restart=false)
	{
		bool retVal = true;
		for(MotionVec::size_type i = 0; i < mots.size(); i++)
		{
			retVal = retVal & mots[i]->reset(restart);
		}
		return retVal;
	};

	
	//! send a message to sub motions that an "event" happened
	virtual void handleEvent(tstring ev)
	{
		Motion::handleEvent(ev);
		//std::cout << "event in motion combiner " << getName() << std::endl;
		for(MotionVec::size_type i = 0; i < mots.size(); i++)
		{
			mots[i]->passEvent(ev);
		}
	}
	virtual bool canHandleEvent(tstring ev)
	{
		for(MotionVec::size_type i = 0; i < mots.size(); i++)
		{
			if(mots[i]->canHandleEvent(ev))
				return true;
		}
		return false;
	};

	virtual void cleanRecursionState()
	{
		Motion::cleanRecursionState();
		for(MotionVec::size_type i = 0; i < mots.size(); i++)
		{
			mots[i]->cleanRecursionState();
		}
	}

	//! gets the length of the motion in seconds
	float getMotionLength() const
	{
		float max = 0.0;
		for(MotionVec::size_type i = 0; i < mots.size(); i++)
		{
			float val = mots[i]->getMotionLength();
			if (val > max)
				max = val;
		}
		return max;
	};

	//! whether it is a face or body motion
	//virtual bool isFacial()
	//{
	//	bool retVal = false;
	//	for(MotionVec::size_type i = 0; i < mots.size(); i++)
	//	{
	//		retVal = retVal & mots[i]->isFacial();
	//	}
	//	return retVal;
	//};	

	//! given an iterator tests whether it actually points to anything or if its null
	virtual bool isNull(int trackId)const 
	{
		bool retVal = true;
		for(MotionVec::size_type i = 0; i < mots.size(); i++)
		{
			retVal = retVal & mots[i]->isNull(trackId);
		}
		return retVal;
	};
	//! get the type of the track corresponding to an iterator
	int getTrackType(int trackId)const 
	{
		int retVal = 0;
		for(MotionVec::size_type i = 0; i < mots.size(); i++)
		{
			retVal = retVal | mots[i]->getTrackType(trackId);
		}
		return retVal;
	};
};

};

#endif //MULTI_MOTION_COMBINER_H
