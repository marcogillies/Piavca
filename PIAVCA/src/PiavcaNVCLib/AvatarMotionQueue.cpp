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
 * The Original Code is AvatarMotionQueue.cpp.
 *
 * The Initial Developer of the Original Code is Shri Pavar and Marco (Mark) Gillies.
 * Portions created by the Initial Developer are Copyright (C) 2004
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


//#include <ctime>
#include "PiavcaAPI/PiavcaError.h"
#include "AvatarMotionQueue.h"
#include "TurnMotion.h"
#include "PiavcaAPI/TrackMotion.h"
#include "ScaleMotionRoot.h"
#include "PiavcaAPI/AvatarPostureBlend.h"
#include "PiavcaAPI/SelfBlend.h"
#include "TimeOffset.h"
#include "ZeroMotion.h"

using namespace Piavca;

Motion* AvatarMotionQueue::blendMotion(Motion *m, Avatar *av, float scaleFactor)
{
    return new AvatarPostureBlend(new ScaleMotionRoot(m, scaleFactor), //av, 
		/*interval=*/0.2f, /*tracksFromAvatar=*/true);
}

AvatarMotionQueue::AvatarMotionQueue(float scale
                                     //, float start
                                     , float time
									 , bool _facial
                                     , int factor)
    : AvatarTimeCallback("AvatarMotionQueue")
    , selfBlend(NULL)
	, adder(NULL)
    , scaleFactor(scale)
    //, startTime(start)
    , delayTime(time)
    , delayFactor(factor)
    , facial(_facial)
    , interruptMot (false) 
{
	
};

void AvatarMotionQueue::init(Avatar *avatar)
{    
    // Extract the current avatar motion 
    Motion *motion;
	if(facial)
		motion = avatar->getFacialMotion();
	else
		motion = avatar->getMotion();

    if (motion) // If a motion already exists for this avatar then queue it
		enqueueMotion("", motion);
    else // Else randomly select a single motion & queue that
	{
		//enqueueRandomMotions();	
		// actually don't load an empty motion
		enqueueMotion("", new TrackMotion(facial));
	}
    
    motion = dequeueMotion();
    
    // & use it to initialise the avatar "mega-motion" 
    selfBlend = new SelfBlend(motion, 0.6f);
	currentMotion = motion;
	//selfBlend->setBlendInterval(0.0);
	adder = new MotionAdder(NULL, selfBlend);
	avatarBlend = new AvatarPostureBlend(new ScaleMotionRoot(adder, scaleFactor), //avatar, 
		/*interval=*/0.2f, /*tracksFromAvatar=*/true);
	//avatarBlend->setBlendInterval(0.0);	
	avatarBlend->Reference();
		
	motionStartTime = Piavca::Core::getCore()->getTime();
	if(facial)
	{
		avatar->loadFacialMotion(avatarBlend);
		avatar->playFacialMotion();
	}
	else
	{
		avatar->loadMotion(avatarBlend);
		avatar->playMotion();
	}
};

void AvatarMotionQueue::timeStep(Avatar *avatar, float time)
{  
    float delay = delayTime * delayFactor;

	bool background = queueTopIsBackground();
	float startTime = avatarBlend->getStartTime();
	//if(isFacial())
	//	std::cout << time << " " << startTime 
	//						<< " " << selfBlend->getEndTime()
	//						<< " " << selfBlend->getMotionLength()
	//						<< " " << background
	//						<< " " << interruptMot
	//						<< " " << queueTopTime() << std::endl;
	if(interruptMot || background || (time > startTime && time > (selfBlend->getEndTime())))
    {
		//std::cout << "changing motion\n";
		float at_time = queueTopTime();
		if(at_time > 0.0 && at_time < time)
		{
			interruptMot = false;
			Motion *motion = dequeueMotion();
			if (motion)
			{ 
				//std::cout << "found motion " << time << " " << startTime << " " << delay << std::endl;
				//std::cout << selfBlend->getMotionLength() << std::endl;
				if(background)
				{
					if(adder)
						adder->setMotion1(new MotionAdder(adder->getMotion1(), new TimeOffset(motion, (time-motionStartTime))));
					else
						adder = new MotionAdder(new TimeOffset(motion, (time-motionStartTime)), selfBlend);
					// we've handed ownership over to the adder so we give up ownership
					//delete motion;
					motion->Dispose();
				}
				else
				{
					//float t = time - startTime 
					//		- avatarBlend->getBlendStart() 
					//		- avatarBlend->getBlendInterval()
					//		+ delay;
					selfBlend->reblend( time );
					selfBlend->setMotion(motion);
					currentMotion = motion;
					// we've handed ownership over to the self blend so we give up ownership
					//delete motion;
					motion->Dispose();
				}

			}
		}
    }

	for (std::list < MotionAdder * >::iterator i = removeList.begin();
		i != removeList.end(); )
	{
		MotionAdder *child = dynamic_cast<MotionAdder *>((*i)->getMotion1());
		if(child)
		{
			if(child->getMotion2()->getEndTime() < Core::getCore()->getTime())
			{
				(*i)->setMotion1(child->getMotion1());
				i = removeList.erase(i);
				continue;
			}
		}
		i++;
	}
};

void AvatarMotionQueue::enqueueMotion(std::string name, Motion* motion, float atTime)
{
	if(!motion)
	{
		//std::cout << "NULL Motion\n";
		Piavca::Error(_T("Trying to put an null motion on the queue"));
		return;
	}
	if(facial && !motion->isFacial())
	{
		Piavca::Error(_T("trying to put a body motion onto a facial queue"));
		return;
	}
	if(!facial && motion->isFacial())
	{
		Piavca::Error(_T("trying to put a facial motion onto a body queue"));
		return;
	}
	if(motion)motion->Reference();
	if(name != _T("")) motion->setName(name);
	std::cout << "queuing motion " << name << " " << atTime << " " << Core::getCore()->getTime() << std::endl;
	motionQueue.push_back(queueElement(name, motion, atTime+Core::getCore()->getTime()));
};

Motion* AvatarMotionQueue::dequeueMotion()
{
    Motion* m = NULL;
    if (! motionQueue.empty() )
    {
        m = motionQueue.front().mot;
        motionQueue.pop_front();
    }
    return m;
};

float AvatarMotionQueue::queueTopTime()
{
    float t = 0.0;
    if (! motionQueue.empty() )
    {
        t = motionQueue.front().atTime;
    }
    return t;
};

bool AvatarMotionQueue::queueTopIsBackground()
{
    bool bg = false;
    if (! motionQueue.empty() )
    {
        bg = motionQueue.front().background;
    }
    return bg;
};

void AvatarMotionQueue::clearQueue()
{
	for(std::list< queueElement >::iterator i = motionQueue.begin();
		i != motionQueue.end(); i++)
		(*i).mot->Dispose();
	motionQueue.clear();
	interruptMot = true;
}

void AvatarMotionQueue::enqueueRandomMotions(int num)
{
    Piavca::Core* core = Piavca::Core::getCore();
    const std::vector<std::string>& motionNames = core->getMotionNames(num);

    int x;
    Motion* m = NULL;

    // Set evil seed (initial seed)
	// Use the system time as it will be different each time the program is run
	srand( static_cast<unsigned int>(Core::getCore()->getTime()*1000.0f) );

    for (int i = 0; i < num; i++) 
	{
		int count = 0;
        do
		{
			x = static_cast<int>(num * rand() / (RAND_MAX + 1.0));
			m = core->getMotion(motionNames[x]);
			count++;
			if(count >= num*3)
			{
				if(facial)
					Piavca::Error(_T("Trying to enqueue random facial motions but all motions are body motions"));
				else
					Piavca::Error(_T("Trying to enqueue random body motions but all motions are facial motions"));
				return;
			}
		}
		while(m->isFacial() != facial);
		if(!m)
			Piavca::Error(_T("some how got a null motion ")
				+ motionNames[x] + _T("when trying to queue random motions"));
		m->Reference();
		enqueueMotion(motionNames[x], m);
    }
}


 void AvatarMotionQueue::addBackgroundMotion(tstring name, Piavca::Motion *mot, float atTime)
 {
	if(facial && !mot->isFacial())
	{
		Piavca::Error(_T("trying to put a body motion onto a facial queue"));
		return;
	}
	if(!facial && mot->isFacial())
	{
		Piavca::Error(_T("trying to put a facial motion onto a body queue"));
		return;
	}
	if(mot)mot->Reference();
	if(name != _T("")) mot->setName(name);
	motionQueue.push_back(queueElement(name, mot, atTime+Core::getCore()->getTime(), true));
 };

 
  void AvatarMotionQueue::clearAllBackgroundMotions()
  {	
	  adder->setMotion2(selfBlend);
	  adder->setMotion1(NULL);
  };
  void AvatarMotionQueue::clearFinishedBackgroundMotions()
  {
	  MotionAdder *temp_adder_parent = adder;
	  MotionAdder *temp_adder_child = dynamic_cast<MotionAdder *>(adder->getMotion1());
	  while (temp_adder_parent && temp_adder_child)
	  {
		  if(temp_adder_child->getMotion2()->getEndTime() 
			  < Core::getCore()->getTime())
		  {
			// slightly hacky way of replacing a motion with a single framed
			// track motion of its current position
			//SelfBlend *s = new SelfBlend(temp_adder_child->getMotion2());
			//s->reblend();
			//temp_adder_child->setMotion2(s->getMotion1());
			//s->Dispose();
			temp_adder_child->setMotion2(
				new SequentialBlend(
					temp_adder_child->getMotion2(), 
					new ZeroMotion(temp_adder_child->isFacial()),
					1.0, Piavca::Core::getCore()->getTime()));
			//removeList.push_back(temp_adder_parent);
			//temp_adder_parent->setMotion1(temp_adder_child->getMotion1());
		  }
		  //else
		  //{
			temp_adder_parent = temp_adder_child;
		  //}
		  temp_adder_child = dynamic_cast<MotionAdder *>(temp_adder_parent->getMotion1());
	  };
  };

  
  void AvatarMotionQueue::removeMotion(tstring name)
  {
	  if(currentMotion && currentMotion->findSub(name))
	  {
		  interrupt();
		  selfBlend->reblend();
		  selfBlend->setMotion(NULL);
		  currentMotion = NULL;
	  };
	  for(std::list< queueElement >::iterator it = motionQueue.begin();
		  it != motionQueue.end(); it++)
	  {
		  if(it->mot->findSub(name))
		  {
			  it->mot->Dispose();
			  it = motionQueue.erase(it);
		  }
	  };
  }
  
  void AvatarMotionQueue::removeBackgroundMotion(tstring name)
  {
	  MotionAdder *temp_adder_parent = adder;
	  MotionAdder *temp_adder_child = dynamic_cast<MotionAdder *>(adder->getMotion1());
	  while (temp_adder_parent && temp_adder_child)
	  {
		  if(temp_adder_child->getMotion2()->findSub(name))
		  {
			// slightly hacky way of replacing a motion with a single framed
			// track motion of its current position
			//SelfBlend *s = new SelfBlend(temp_adder_child->getMotion2());
			//s->reblend();
			//temp_adder_child->setMotion2(s->getMotion1());
			//s->Dispose();
			//temp_adder_child->setMotion2(
			//	copyMotionPosture(temp_adder_child->getMotion2(),
			//	Piavca::Core::getCore()->getTime()));
			temp_adder_child->setMotion2(
				new SequentialBlend(
					temp_adder_child->getMotion2(), 
					new ZeroMotion(temp_adder_child->isFacial()),
					1.0, Piavca::Core::getCore()->getTime()));
			//removeList.push_back(temp_adder_parent);
			//temp_adder_parent->setMotion1(temp_adder_child->getMotion1());
		  }
		  //else
		  //{
			temp_adder_parent = temp_adder_child;
		  //}
		  temp_adder_child = dynamic_cast<MotionAdder *>(temp_adder_parent->getMotion1());
	  };
  };
  
  void AvatarMotionQueue::pauseBackgroundMotion(tstring name)
  {
	  MotionAdder *temp_adder_parent = adder;
	  MotionAdder *temp_adder_child = dynamic_cast<MotionAdder *>(adder->getMotion1());
	  while (temp_adder_parent && temp_adder_child)
	  {
		  if(temp_adder_child->getMotion2()->findSub(name))
		  {
			temp_adder_child->getMotion2()->pause();
		  }
		  temp_adder_parent = temp_adder_child;
		  temp_adder_child = dynamic_cast<MotionAdder *>(temp_adder_parent->getMotion1());
	  };
  };

  void AvatarMotionQueue::unpauseBackgroundMotion(tstring name)
  {
	  MotionAdder *temp_adder_parent = adder;
	  MotionAdder *temp_adder_child = dynamic_cast<MotionAdder *>(adder->getMotion1());
	  while (temp_adder_parent && temp_adder_child)
	  {
		  if(temp_adder_child->getMotion2()->findSub(name))
		  {
			temp_adder_child->getMotion2()->unpause();
		  }
		  temp_adder_parent = temp_adder_child;
		  temp_adder_child = dynamic_cast<MotionAdder *>(temp_adder_parent->getMotion1());
	  };
  };

  void AvatarMotionQueue::removeBackgroundMotionByType(const type_info &ty)
  {
	  MotionAdder *temp_adder_parent = adder;
	  MotionAdder *temp_adder_child = dynamic_cast<MotionAdder *>(adder->getMotion1());
	  while (temp_adder_parent && temp_adder_child)
	  {
		  if(temp_adder_child->getMotion2()->findSubByType(ty))
		  {
			// slightly hacky way of replacing a motion with a single framed
			// track motion of its current position
			//SelfBlend *s = new SelfBlend(temp_adder_child->getMotion2());
			//s->reblend();
			//temp_adder_child->setMotion2(s->getMotion1());
			//s->Dispose();
			temp_adder_child->setMotion2(
				new SequentialBlend(
					temp_adder_child->getMotion2(), 
					new ZeroMotion(temp_adder_child->isFacial()),
					1.0, Piavca::Core::getCore()->getTime()));
			//removeList.push_back(temp_adder_parent);
			//temp_adder_parent->setMotion1(temp_adder_child->getMotion1());
		  }
		  //else
		  //{
			temp_adder_parent = temp_adder_child;
		  //}
		  temp_adder_child = dynamic_cast<MotionAdder *>(temp_adder_parent->getMotion1());
	  };
  };
  
  /*void AvatarMotionQueue::clearBackgroundMotion(Motion *mot)
  {
	  MotionAdder *temp_adder_parent = adder;
	  MotionAdder *temp_adder_child = dynamic_cast<MotionAdder *>(adder->getMotion1());
	  while (temp_adder_parent && temp_adder_child)
	  {
		  if(temp_adder_child->getMotion2() == mot)
		  {
			temp_adder_parent->setMotion1(temp_adder_child->getMotion1());
		  }
		  else
		  {
			temp_adder_parent = temp_adder_child;
			temp_adder_child = dynamic_cast<MotionAdder *>(temp_adder_parent->getMotion1());
		  }
	  };
  };*/

  
AvatarMotionQueue *AvatarMotionQueue::getQueue(Avatar *avatar, bool facial)
{
	// Check if a motion queue exists for this avatar & create one if it does not
    AvatarMotionQueue *amq = NULL;
	int i;
	for (i = 0; i < avatar->getNumCallbacks(); i++)
	{
		amq = dynamic_cast<AvatarMotionQueue *>(avatar->getCallback(i));
		if(amq && amq->isFacial() == facial) break;
		amq = NULL;
	}

    if (!amq) // IF no motion queue curently exists for this avatar then create one
    {
		float startTime = Core::getCore()->getTime();
        amq = new AvatarMotionQueue(1.0f, 0.2f, facial);

        avatar->registerCallback(amq);
		Motion *motion = amq->getMotion();
		if (!motion)
		{
			tstring errMsg = _T("Avatar ");
			errMsg += avatar->getName();
			errMsg += _T(" is not initialised with a motion !");
			Piavca::Error(errMsg);
			return NULL;
		}
	}
	
	Motion *avatarMot;
	if(facial) 
		avatarMot = avatar->getFacialMotion();
	else
		avatarMot = avatar->getMotion();
	if(amq->getMotion() != avatarMot)
	{
		Motion *motion = amq->getMotion();
		amq->reblend();
		amq->interrupt();
		if (!motion)
		{
			tstring errMsg = _T("Avatar ");
			errMsg += avatar->getName();
			errMsg += _T(" is not initialised with a motion !");
			Piavca::Error(errMsg);
			return NULL;
		}

		if(facial)
		{
			avatar->loadFacialMotion(motion);
			avatar->playFacialMotion();
		}
		else
		{
			avatar->loadMotion(motion);
			avatar->playMotion();
		}
	}
	
	return amq;
}
