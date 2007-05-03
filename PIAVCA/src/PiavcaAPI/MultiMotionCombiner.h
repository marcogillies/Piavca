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
			mots[i]->Dispose();
	}
	virtual Motion *clone(){return new MultiMotionCombiner(*this);};

	void printInfo()
	{
		Motion::printInfo();
		debug_prefix++;
		for(MotionVec::size_type i = 0; i < mots.size(); i++)
			mots[i]->printInfo();
		debug_prefix--;
	};

	//adds a new motion
	virtual void addMotion(Motion *mot)
	{
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

	
};

};

#endif //MULTI_MOTION_COMBINER_H