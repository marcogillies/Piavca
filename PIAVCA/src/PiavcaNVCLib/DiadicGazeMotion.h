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
 * The Original Code is DiadicGazeMotion.h.
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


#ifndef DIADIC_GAZE_MOTION_H
#define DIADIC_GAZE_MOTION_H


namespace Piavca
{

//typedef std::vector < std::pair<Avatar *, int> > AvatarTargetVec;

class DiadicGazeMotion : public RandomGazeMotion
{
public:
	enum talkingstate {talking, listening, neither};
protected:
	Avatar *otherAvatar;
	DiadicGazeMotion *otherDiadicGaze;
	int joint;
	//bool talking;
	bool lookingAt;
	float talkingLookAt, talkingLookAway;
	float listeningLookAt, listeningLookAway;
	float neitherLookAt, neitherLookAway;
	// whether you follow the gaze of the other person
	float gazeFollow;
	vector<tstring> gazeFollowTargets;
	tstring currentGazeFollowTarget;
	talkingstate isTalking;
public:

	DiadicGazeMotion(Avatar *other, float endTime = -1.0, float interval = 0.01)
		:RandomGazeMotion(endTime, interval), 
		otherAvatar(other), isTalking(neither), lookingAt(false), 
		talkingLookAt(1.8f), talkingLookAway(2.1f),
		listeningLookAt(2.5f), listeningLookAway(1.6f),
		neitherLookAt(1.2f), neitherLookAway(2.5f),
		gazeFollow(0), otherDiadicGaze(NULL), currentGazeFollowTarget(_T(""))
	{
		joint = Core::getCore()->getJointId(_T("Head"));
		clearDirectionTable();
		addDirection(Vec( 1.0,  0.0, 0.0), 15.5f);
		addDirection(Vec( 1.0,  1.0, 0.0),  6.5f);
		addDirection(Vec( 0.0,  1.0, 0.0), 17.7f);
		addDirection(Vec(-1.0,  1.0, 0.0),  7.4f);
		addDirection(Vec(-1.0,  0.0, 0.0), 16.8f);
		addDirection(Vec(-1.0, -1.0, 0.0),  7.9f);
		addDirection(Vec( 0.0, -1.0, 0.0), 20.4f);
		addDirection(Vec( 1.0, -1.0, 0.0),  7.8f);
		normaliseDirectionTable();
		setTalking(neither);
		if(otherAvatar)
			otherDiadicGaze = dynamic_cast<DiadicGazeMotion *>(otherAvatar->getMotion()->findSubByType(typeid(DiadicGazeMotion)));
	};
	DiadicGazeMotion(const DiadicGazeMotion &dg)
		:RandomGazeMotion(dg),
		otherAvatar(dg.otherAvatar), joint(dg.joint),
		isTalking(dg.isTalking), lookingAt(dg.lookingAt),
		talkingLookAt(dg.talkingLookAt), talkingLookAway(dg.talkingLookAway),
		listeningLookAt(dg.listeningLookAt), listeningLookAway(dg.listeningLookAway),
		neitherLookAt(dg.neitherLookAt), neitherLookAway(dg.neitherLookAway),
		otherDiadicGaze(dg.otherDiadicGaze), gazeFollow(dg.gazeFollow),
		gazeFollowTargets(dg.gazeFollowTargets), currentGazeFollowTarget(dg.currentGazeFollowTarget)
		{}
	~DiadicGazeMotion(){};
	virtual Motion *clone(){return new DiadicGazeMotion(*this);};
	
	void setTalking(talkingstate t)           
	{
		isTalking = t;
		switch(isTalking)
		{
		case talking: setMeanGazeLength(talkingLookAway);break;
		case listening: setMeanGazeLength(listeningLookAway);break;
		case neither: setMeanGazeLength(neitherLookAway);break;
		}
	};
	void setTalkingLookAt(float f)    {talkingLookAt = f;};
	void setTalkingLookAway(float f)  {talkingLookAway = f;};
	void setListeningLookAt(float f)  {listeningLookAt = f;};
	void setListeningLookAway(float f){listeningLookAway = f;};
	void setNeitherLookAt(float f)    {neitherLookAt = f;};
	void setNeitherLookAway(float f)  {neitherLookAway = f;};
	void setGazeFollow(float f)  {gazeFollow = f;};

	void setOther(Avatar *other)      
	{
		otherAvatar = other;
		if(otherAvatar)
			otherDiadicGaze = dynamic_cast<DiadicGazeMotion *>(otherAvatar->getMotion()->findSubByType(typeid(DiadicGazeMotion)));
	};
	Avatar *getOther()				  {return otherAvatar;};

	void addGazeFollowTarget(tstring name){gazeFollowTargets.push_back(name);};
	void notifyChange(tstring target)
	{
		for(vector<tstring>::size_type i = 0; i < gazeFollowTargets.size(); i++)
			if(gazeFollowTargets[i] == target)
			{
				if((rand()%100 <= 100*gazeFollow)) lookAt(target);
				currentGazeFollowTarget = target;
				return;
			}
		currentGazeFollowTarget = _T("");
	};

	virtual bool lookAt(tstring name, bool force = false)
	{
		if(otherAvatar && otherAvatar->getName() == name
			&& rand()%10 < 3)
		{
			Core::getCore()->log() << Core::getCore()->getTime();
			Core::getCore()->log() << " gaze_look_at\n";
			float time = Core::getCore()->getTime();
			std::cout << "looking at\n";
			mot->reblend(time);
			lookingAt = true;
			mot->setTarget(otherAvatar, joint);
			
			float meanGaze; 
			switch(isTalking)
			{
			case talking:  meanGaze = talkingLookAt;break;
			case listening: meanGaze = listeningLookAt;break;
			case neither: meanGaze = neitherLookAt;break;
			}
			float endTime = meanGaze*(static_cast<float>(rand()%1000)/1000.0f + 0.5f);
			mot->setEndTime(endTime+time);	
			if(otherDiadicGaze) otherDiadicGaze->notifyChange(mot->getTargetName());
			return true;
		}
		else
		{
			Core::getCore()->log() << Core::getCore()->getTime();
			Core::getCore()->log() << " gaze_look_at_object\n";
			bool retval = RandomGazeMotion::lookAt(name, force);
			if(otherDiadicGaze) otherDiadicGaze->notifyChange(mot->getTargetName());
			return retval;
		}
	};

	virtual void reblend(float time)
	{
		if(!otherAvatar || lookingAt)
		{
			Core::getCore()->log() << Core::getCore()->getTime();
			Core::getCore()->log() << " gaze_look_away\n";
			lookingAt = false;
			bool lookedatgazefollow = false;
			if(currentGazeFollowTarget != _T(""))
				lookedatgazefollow = lookAt(currentGazeFollowTarget);
			if(!lookedatgazefollow)
				RandomGazeMotion::reblend(time);
		}
		else
		{
			std::cout << "looking at\n";
			Core::getCore()->log() << Core::getCore()->getTime();
			Core::getCore()->log() << " gaze_look_at\n";
			mot->reblend(time);
			lookingAt = true;
			mot->setTarget(otherAvatar, joint);
			
			float meanGaze; 
			switch(isTalking)
			{
			case talking:  meanGaze = talkingLookAt;break;
			case listening: meanGaze = listeningLookAt;break;
			case neither: meanGaze = neitherLookAt;break;
			}
			float endTime = meanGaze*(static_cast<float>(rand()%1000)/1000.0f + 0.5f);
			mot->setEndTime(endTime+time);
		}
		if(otherDiadicGaze) otherDiadicGaze->notifyChange(mot->getTargetName());
	};
};

};

#endif // DIADIC_GAZE_MOTION_H