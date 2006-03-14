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
 * The Original Code is RandomGazeMotion.h.
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


#ifndef RANDOM_GAZE_MOTION_H
#define RANDOM_GAZE_MOTION_H

#include "LookAtMotion.h"
#include <math.h>

namespace Piavca
{


struct flagStruct 
{
	bool headActive;
	bool bodyActive;
	bool turnBodyVertical;
	bool turnBodyFull;
	bool leanTowards;
	flagStruct()
		:headActive(false), bodyActive(false), 
		 turnBodyVertical(false), turnBodyFull(false),
		 leanTowards(false) {}
	flagStruct(const flagStruct &f)
		:headActive(f.headActive), bodyActive(f.bodyActive), 
		turnBodyVertical(f.turnBodyVertical), 
		turnBodyFull(f.turnBodyFull),
		leanTowards(f.leanTowards) {}
	const flagStruct &operator=(const flagStruct &f)
	{
		headActive = f.headActive;
		bodyActive = f.bodyActive;
		turnBodyVertical = f.turnBodyVertical;
		turnBodyFull = f.turnBodyFull;
		leanTowards = f.leanTowards;
		return *this;
	}
};

struct AvatarTargetStruct
{
	Avatar *avatar;
	int joint;
	flagStruct flags;
	AvatarTargetStruct(Avatar *a, int j, flagStruct f):avatar(a), joint(j), flags(f){};
	AvatarTargetStruct(const AvatarTargetStruct &ats): avatar(ats.avatar), joint(ats.joint), flags(ats.flags){};
};

typedef std::vector < AvatarTargetStruct > AvatarTargetVec;

struct ObjectTargetStruct
{
	Object *object;
	flagStruct flags;
	ObjectTargetStruct(Object *a, flagStruct f):object(a), flags(f){};
	ObjectTargetStruct(const ObjectTargetStruct &ats): object(ats.object), flags(ats.flags){};
};

typedef std::vector < ObjectTargetStruct > ObjectTargetVec;

class RandomGazeMotion : public LoopMotion
{
protected:
	LookAtMotion *mot;
	AvatarTargetVec avatarTargets;
	ObjectTargetVec objectTargets;
	std::vector <std::pair<Vec, float> > directionTable;
	float lookAtLocationProb;
	float meanGazeLength;
	float gazeCoeff, gazeDivisor;

	//! sets up values to those given by Lee, badler, badler paper
	void init()
	{
		gazeCoeff = -6.9;
		gazeDivisor = 15.7;
		meanGazeLength = 5.0; //made up number
		directionTable.push_back(std::make_pair(Vec( 0.0,  0.0, 0.0),100.0));
		directionTable.push_back(std::make_pair(Vec( 1.0,  0.0, 0.0), 15.5));
		directionTable.push_back(std::make_pair(Vec( 1.0,  1.0, 0.0),  6.5));
		directionTable.push_back(std::make_pair(Vec( 0.0,  1.0, 0.0), 17.7));
		directionTable.push_back(std::make_pair(Vec(-1.0,  1.0, 0.0),  7.4));
		directionTable.push_back(std::make_pair(Vec(-1.0,  0.0, 0.0), 16.8));
		directionTable.push_back(std::make_pair(Vec(-1.0, -1.0, 0.0),  7.9));
		directionTable.push_back(std::make_pair(Vec( 0.0, -1.0, 0.0), 20.4));
		directionTable.push_back(std::make_pair(Vec( 1.0, -1.0, 0.0),  7.8));
		normaliseDirectionTable();
	}
public:
	RandomGazeMotion(float endTime = -1.0, float interval = 0.01)
		:LoopMotion(NULL, endTime, interval), 
		lookAtLocationProb(0.5)
	{
		init();
		Vec loc = randomLocation();
		float length = meanGazeLength*(static_cast<float>(rand()%1000)/1000.0 + 0.5);
		mot = new LookAtMotion(loc, length+Core::getCore()->getTime(), true);
		setMotion(mot);
	};
	RandomGazeMotion(const RandomGazeMotion &rg)
		:LoopMotion(rg), mot(rg.mot), 
		avatarTargets(rg.avatarTargets), objectTargets(rg.objectTargets),
		directionTable(rg.directionTable), lookAtLocationProb(rg.lookAtLocationProb),
		meanGazeLength(rg.meanGazeLength), 
		gazeCoeff(rg.gazeCoeff), gazeDivisor(rg.gazeDivisor)
	{
		mot = dynamic_cast<LookAtMotion *>(rg.mot->clone());
		setMotion(mot);
	}
	~RandomGazeMotion(){};
	virtual Motion *clone(){return new RandomGazeMotion(*this);};

	void clearDirectionTable() { directionTable.clear(); };
	void addDirection(const Vec &dir, float prob) { directionTable.push_back(std::make_pair(dir, prob)); };
	
	void normaliseDirectionTable()
	{
		float total = 0;
		int i;
		for(i = 0; i < directionTable.size(); i++)
		{
			directionTable[i].first.normalize();
			total += directionTable[i].second;
		}
		for(i = 0; i < directionTable.size(); i++)
		{
			directionTable[i].second /= total;
		}
	};

	void addAvatarTarget(Avatar *av, int joint, flagStruct f = flagStruct()) 
	{ 
		avatarTargets.push_back(AvatarTargetStruct(av, joint, f));
	};
	void addObjectTarget(Object *obj, flagStruct f = flagStruct()) 
	{	
		objectTargets.push_back(ObjectTargetStruct(obj, f)); 
	};	

	void setTargetFlags(tstring name, flagStruct flags)
	{
		int i;
		for(int i = 0; i < avatarTargets.size(); i++)
		{	
			if(avatarTargets[i].avatar && avatarTargets[i].avatar->getName() == name)
			{
				
				avatarTargets[i].flags = flags;
			}
		}
		for(int i = 0; i < objectTargets.size(); i++)
		{	
			if(objectTargets[i].object && objectTargets[i].object->getName() == name)
			{
				objectTargets[i].flags = flags;
			}
		}
	};

	void setGazeParams(float coeff, float divisor)
	{
		gazeCoeff = coeff;
		gazeDivisor = divisor;
	};
	void setLookAtLocationProb(float prob) { lookAtLocationProb = prob; };
	void setMeanGazeLength(float f){ meanGazeLength = f; };
	void setEyesLimit(float f){mot->setEyesLimit(f);};
	void setHeadBodyLimit(float f){mot->setHeadBodyLimit(f);};
	void setEyesMorphAngle(float f)  {mot->setEyesMorphAngle(f);};

	Vec randomLocation()
	{
		float mag = gazeCoeff*log(static_cast<float>(rand()%150)/(10.0*gazeDivisor));
		mag = degToRad(mag);
		//std::cout << "gaze angle " << mag << std::endl;
		if(directionTable.size() <= 0)
			return Vec(0.0, 0.0, 1.0);
		int i;
		do {
			i = rand()%directionTable.size();
		}while (((float)(rand()%100))/100 > directionTable[i].second);
		Vec dir = (directionTable[i].first.normalized());
		dir *= tan(mag);
		dir += Vec::ZAxis();
		return dir;
		//return (directionTable[i].first.normalized())*mag;
	}

	virtual bool lookAt(tstring name, bool force = false)
	{
		mot->setHeadActive(false);
		mot->setBodyActive(false);
		mot->setTurnBodyVertical(false);
		mot->setTurnBodyFull(false);
		mot->setLeanTowards(false);
		if(name == _T(""))
		{
			mot->reblend(Core::getCore()->getTime());
			mot->setTarget(randomLocation());
			float endTime = meanGazeLength*(static_cast<float>(rand()%1000)/1000.0 + 0.5);
			mot->setEndTime(endTime+Core::getCore()->getTime());
			return true;
		}
		int i;
		for(int i = 0; i < avatarTargets.size(); i++)
		{	
			if(avatarTargets[i].avatar && avatarTargets[i].avatar->getName() == name)
			{
				// check that the target can be turned to comfortably
				if(!force && !mot->canLookAt(avatarTargets[i].avatar->getRootPosition()))
					return false;
				mot->reblend(Core::getCore()->getTime());
				mot->setTarget(avatarTargets[i].avatar, avatarTargets[i].joint);
				mot->setHeadActive(avatarTargets[i].flags.headActive);
				mot->setBodyActive(avatarTargets[i].flags.bodyActive);
				mot->setTurnBodyVertical(avatarTargets[i].flags.turnBodyVertical);
				mot->setTurnBodyFull(avatarTargets[i].flags.turnBodyFull);
				mot->setLeanTowards(avatarTargets[i].flags.leanTowards);
				float endTime = meanGazeLength*(static_cast<float>(rand()%1000)/1000.0 + 0.5);
				mot->setEndTime(endTime+Core::getCore()->getTime());
				return true;
			}
		}
		for(int i = 0; i < objectTargets.size(); i++)
		{	
			if(objectTargets[i].object && objectTargets[i].object->getName() == name)
			{
				// check that the target can be turned to comfortably
				if(!force && !mot->canLookAt(objectTargets[i].object->getPosition()))
					return false;
				mot->reblend(Core::getCore()->getTime());
				mot->setTarget(objectTargets[i].object);
				mot->setHeadActive(objectTargets[i].flags.headActive);
				mot->setBodyActive(objectTargets[i].flags.bodyActive);
				mot->setTurnBodyVertical(objectTargets[i].flags.turnBodyVertical);
				mot->setTurnBodyFull(objectTargets[i].flags.turnBodyFull);
				mot->setLeanTowards(objectTargets[i].flags.leanTowards);
				float endTime = meanGazeLength*(static_cast<float>(rand()%1000)/1000.0 + 0.5);
				mot->setEndTime(endTime+Core::getCore()->getTime());
				return true;
			}
		}
		return false;
	}
	
	virtual void reblend(float time)
	{
		if(mot2 != mot)
			setMotion(mot);
		mot->reblend(time);
		mot->setHeadActive(false);
		mot->setBodyActive(false);
		mot->setTurnBodyVertical(false);
		mot->setTurnBodyFull(false);
		mot->setLeanTowards(false);
		if((avatarTargets.size() == 0 && objectTargets.size() == 0)
		   || rand()%1000 > lookAtLocationProb*1000)
		{
			Vec v = randomLocation();
			//std::cout << "gaze vector " << v << std::endl;
			mot->setTarget(v, true);
		}
		else
		{
			int i = 0;
			while (true)
			{
				i++; 
				//if we've been searching for ages and haven't found 
				// a target we can look at look at a location
				if(i > (avatarTargets.size() + objectTargets.size()))
				{
					Vec v = randomLocation();
					//std::cout << "gaze vector " << v << std::endl;
					mot->setTarget(v, true);
					break;
				}
				int ind = rand()%(avatarTargets.size() + objectTargets.size());
				if(ind <  avatarTargets.size())
				{
					// check that the target can be turned to comfortably
					if(!mot->canLookAt(avatarTargets[ind].avatar->getRootPosition()))
						continue;
					mot->setHeadActive(avatarTargets[ind].flags.headActive);
					mot->setBodyActive(avatarTargets[ind].flags.bodyActive);
					mot->setTurnBodyVertical(avatarTargets[ind].flags.turnBodyVertical);
					mot->setTurnBodyFull(avatarTargets[ind].flags.turnBodyFull);
					mot->setLeanTowards(avatarTargets[ind].flags.leanTowards);
					mot->setTarget(avatarTargets[ind].avatar, avatarTargets[ind].joint);
					//std::cout << "gaze target " << avatarTargets[ind].first->getName() << std::endl;
					break;
				}
				else
				{
					// check that the target can be turned to comfortably
					if(!mot->canLookAt(objectTargets[ind].object->getPosition()))
						continue;
					mot->setHeadActive(objectTargets[ind-avatarTargets.size()].flags.headActive);
					mot->setBodyActive(objectTargets[ind-avatarTargets.size()].flags.bodyActive);
					mot->setTurnBodyVertical(objectTargets[ind-avatarTargets.size()].flags.turnBodyVertical);
					mot->setTurnBodyFull(objectTargets[ind-avatarTargets.size()].flags.turnBodyFull);
					mot->setLeanTowards(objectTargets[ind-avatarTargets.size()].flags.leanTowards);
					mot->setTarget(objectTargets[ind-avatarTargets.size()].object);
					//std::cout << "gaze target " << objectTargets[ind]->getName() << std::endl;
					break;
				}
			}
		}
		float endTime = meanGazeLength*(static_cast<float>(rand()%1000)/1000.0 + 0.5);
		mot->setEndTime(endTime+Core::getCore()->getTime());
	};
};

};

#endif //RANDOM_GAZE_MOTION_H
