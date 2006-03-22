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
 * The Original Code is AvatarMotionQueue.h.
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

#ifndef AVATAR_MOTION_QUEUE_H
#define AVATAR_MOTION_QUEUE_H

#include "PiavcaAPI/PiavcaDefs.h"
#include "PiavcaAPI/Motion.h"
#include "PiavcaAPI/SelfBlend.h"
#include "PiavcaAPI/AvatarPostureBlend.h"
#include "PiavcaAPI/MotionAdder.h"
#include "PiavcaAPI/Avatar.h"
#include "PiavcaAPI/PiavcaCore.h"
#include "PiavcaAPI/TimeCallback.h"

#include <list>

namespace Piavca
{

struct queueElement
{
	Motion *mot;
	tstring name;
	float atTime;
	bool background;
	queueElement():mot(NULL), name(""), atTime(0.0), background(false){};
	queueElement( tstring n, Motion *m, float t, bool back = false)
		:mot(m), name(n), atTime(t), background(back){};
	queueElement(const queueElement &qe)
		:mot(qe.mot), name(qe.name), atTime(qe.atTime), background(qe.background){};

};

//! A Queue for managing motions
/*!
 *	You can put motions on the queue and they will be played in sequence 
 *  each waiting for the previous to finish.
 *  You can also add background motions that continuing playing at the same 
 *  time as the motions on the queue.
 */
class PIAVCA_DECL AvatarMotionQueue : public AvatarTimeCallback
{

 public:

  //Explicit default constructor
  AvatarMotionQueue()
      :AvatarTimeCallback("AvatarMotionQueue") {};

  /*!
   * Pass in a scale factor for the position component of the motions (e.g.
   * to convert between meters and inches. A delay time between motions.
   * a flag to say whether the queue handles facial or body motions. and a
   * multiplier for the delay.
   */
  AvatarMotionQueue(float scale, float delay = 0, bool facial = false, int factor = 10);

  virtual ~AvatarMotionQueue()
  {
	  //AvatarTimeCallback::~AvatarTimeCallback();
	  avatarBlend->Dispose();
  };
  
  /*! a static method, given an avatar returns that avatar's queue.
   *  The avatar has a queue for body and one for facial motions
   *  the facial flag distinguishes them.
   */
  static AvatarMotionQueue *AvatarMotionQueue::getQueue(Avatar *avatar, bool facial = false);

  //! This is a setup method for the callback
  /*!
   *	It's called when the callback is registered
   */
  virtual void init(Piavca::Avatar *avatar);
  
  //! implement this to make the callback do things
  /*!
   *	It's called every frame with by the API which passes in the avatar
   *	to which the callback is attatched
   */
  virtual void timeStep(Piavca::Avatar *avatar, float time);

  //! whether the queue handles facial or body motions
  bool isFacial(){return facial;};

  //! gets the start time of the current motion
  float getCurrentMotionStart()
  {
	if(currentMotion)
		return currentMotion->getStartTime();
	else
		return 0;
	//return startTime 
	//	  + selfBlend->getBlendStart() 
	//	  + selfBlend->getBlendInterval()
	//	  + avatarBlend->getBlendStart() 
	//	  + avatarBlend->getBlendInterval();
  }
  void reblend()
  {
	  //startTime = Piavca::Core::getCore()->getTime();
	  avatarBlend->reblend(Piavca::Core::getCore()->getTime());
  };

  //! sets how long it takes to blend between subsequent motions.
  void setBlendInterval(float t)
  {
	  selfBlend->setBlendInterval(t);
	  avatarBlend->setBlendInterval(t);
  }

  //! adds a motion to the queue
  /*!
   * You have to pass in a name for the motion and optionally a minimum 
   * time for it to start.
   */
  void enqueueMotion(tstring name, Piavca::Motion *motion, float atTime = 0.0);

  //! enqueue a number of randomly chosen motions
  void enqueueRandomMotions(int num = 0);

  //! tests whether the first motion on the queue is a background motion
  bool queueTopIsBackground();
  //! gets the minimum start time of the first motion on the queue
  float queueTopTime();
  //! pops a motion off the queue
  Piavca::Motion *dequeueMotion();

  //! returns the number of motions on the queue
  int getQueueSize() {return static_cast<int>(motionQueue.size());};

  //! change the delay
  void updateDelay(float delay) {delayTime = delay;};

  //! empties the queue
  void clearQueue();
  //! removes a named forground motion
  void removeMotion(tstring name);
  //! pauses a named forground motion
  void pauseMotion(tstring name){selfBlend->getMotion2()->pause();};
  //! unpauses a named forground motion
  void unpauseMotion(tstring name){selfBlend->getMotion2()->unpause();};
  //! removes all background motions from the queue
  void clearAllBackgroundMotions();
  //! removes any background motions that have stopped playing
  void clearFinishedBackgroundMotions();
  //! removes a named background motion
  void removeBackgroundMotion(tstring name);
  //! removes a background motion with a given type
  void removeBackgroundMotionByType(const type_info &ty);
  //! pauses a named background motion
  void pauseBackgroundMotion(tstring name);
  //! unpauses a named background motion
  void unpauseBackgroundMotion(tstring name);
  //void clearBackgroundMotion(Motion *mot);
  //! interrupts the queue 
  /*!
   *  so the next motion is played immediately, without waiting for the current one stop
   */
  void interrupt(){interruptMot = true;};

  //! return the resulting motion
  virtual Piavca::Motion *getMotion(){ return avatarBlend; };

  Piavca::Motion* blendMotion(Motion *m, Avatar *av, float scaleFactor);

  //! adds a new background motion to the queue
  /*!
   *  A background motion is played concurrently with any motions on the queue.
   *  You have to pass in a name and optionally minimum time at which it should start.
   */
  void addBackgroundMotion(tstring name, Piavca::Motion *motion, float atTime = 0.0);

 private:
  AvatarMotionQueue(const AvatarMotionQueue &amq) 
	  :AvatarTimeCallback(amq), scaleFactor(amq.scaleFactor)  //startTime(amq.startTime) 
		{};

  float scaleFactor, /*startTime,*/ delayTime;
  std::list< queueElement > motionQueue;
  std::list < MotionAdder * > removeList;
  int numToQ, delayFactor;
  bool facial;
  bool interruptMot;
  Motion *currentMotion;
  Piavca::SelfBlend* selfBlend;
  Piavca::MotionAdder *adder;
  Piavca::AvatarPostureBlend *avatarBlend;
};


}

#endif //AVATAR_MOTION_QUEUE_H
