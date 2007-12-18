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
	Vec otherPosition;
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
	bool followPosition;
public:

	DiadicGazeMotion(Avatar *other = NULL, float endTime = -1.0, float interval = 0.01)
		:RandomGazeMotion(endTime, interval), 
		otherAvatar(other), isTalking(neither), lookingAt(false), 
		talkingLookAt(1.8f), talkingLookAway(2.1f),
		listeningLookAt(2.5f), listeningLookAway(1.6f),
		neitherLookAt(1.2f), neitherLookAway(2.5f),
		gazeFollow(0), otherDiadicGaze(NULL), currentGazeFollowTarget(_T("")),
		followPosition(false)
	{
		std::cout << "In diadic gaze constructor\n";
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
		gazeFollowTargets(dg.gazeFollowTargets), currentGazeFollowTarget(dg.currentGazeFollowTarget),
		followPosition(false)
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

	virtual void event(tstring ev)
	{
		if (ev == _T("talking")) 
			setTalking(talking);
		if (ev == _T("listening")) 
			setTalking(listening);
		if (ev == _T("neither")) 
			setTalking(neither);
	}

	void setOther(Avatar *other)      
	{
		otherAvatar = other;
		if(otherAvatar)
			otherDiadicGaze = dynamic_cast<DiadicGazeMotion *>(otherAvatar->getMotion()->findSubByType(typeid(DiadicGazeMotion)));
	};
	Avatar *getOther()				  {return otherAvatar;};
	

	//! sets the position of the other person (if its not accessed as an avatar pointer)
	void setOtherPosition(const Vec &v)
	{
		//std::cout << "setting other position" << v << std::endl;
		otherPosition = v;
		if (lookingAt && !otherAvatar)
		{
			std::cout << "Diadic Gaze: setting other position " << otherPosition << std::endl;
			mot->setTarget(otherPosition);
			//mot->setTarget(otherPosition, true);
			//mot->setTarget(Vec(0.0, 100.0, 0.0), true);
		}
	}

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
			std::cout << "lookAt\n";
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
			std::cout << "look at timings " << time << " " << endTime << " " << endTime + time <<  std::endl;
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
		followPosition = false;
		if(/*!otherAvatar ||*/ lookingAt)
		{
			std::cout << "looking away\n";
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
			if( !otherAvatar)
			{
				mot->setTarget(otherPosition);
				mot->setHeadActive(true);
				followPosition = true;
			}
			else
			{
				mot->setTarget(otherAvatar, joint);
				mot->setHeadActive(true);
			}
			float meanGaze; 
			switch(isTalking)
			{
			case talking:  meanGaze = talkingLookAt;break;
			case listening: meanGaze = listeningLookAt;break;
			case neither: meanGaze = neitherLookAt;break;
			}
			float endTime = meanGaze*(static_cast<float>(rand()%1000)/1000.0f + 0.5f);
			std::cout << "look at timings " << time << " " << endTime << " " << endTime + time <<  std::endl;
			mot->setEndTime(endTime+time);
		}
		if(otherDiadicGaze) otherDiadicGaze->notifyChange(mot->getTargetName());
	};
};

};

#endif // DIADIC_GAZE_MOTION_H
