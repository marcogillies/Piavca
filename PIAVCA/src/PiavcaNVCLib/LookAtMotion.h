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
 * The Original Code is LookAtMotion.h.
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



#ifndef LOOK_AT_MOTION_H
#define LOOK_AT_MOTION_H

#include "PiavcaAPI/Motion.h"
#include "PiavcaAPI/MotionFilter.h"
#include "PiavcaAPI/Object.h"
#include "PiavcaAPI/Avatar.h"
#include "PiavcaAPI/PiavcaError.h"


#include <limits>
#include <vector>
using std::vector;

namespace Piavca 
{
	/*!	A motion class that makes the avatar look at a target.
	 *  The avatar will turn to look at the given target with eyes, head, and body.
	 *  The target can either be an avatar, an object or a vector location.
	 */
	class PIAVCA_DECL LookAtMotion : public Motion
	{
		Avatar *AvatarTarget;
		int targetJointId;
		Object *ObjectTarget;
		Vec     LocationTarget;
		bool local;
		float endTime;
		float interval;
		float blendStartTime, blendEndTime;
		float eyesLimit, headbodyLimit;
		float eyesMorphAngle;
		int reyeId, leyeId, headId, bodyId;
		Quat oldReyeVal, oldLeyeVal, oldHeadVal, oldBodyVal;
		bool headActive, bodyActive; 
		bool turnBodyVertical, turnBodyFull;
		bool leanTowards;
		int lookLeftId, lookRightId, lookUpId, lookDownId;
		float oldLookLeftVal, oldLookRightVal, oldLookUpVal, oldLookDownVal;

		Vec oldTargetPos_head, oldRootPos_head;
		Vec oldTargetPos_body, oldRootPos_body;
		Quat oldHeadOri, oldBodyOri;

		void init();
	public:
		/*! create with an avatar target.
		 *  Pass in an avatar, and a joint of that avatar to look at
		 */
		LookAtMotion(Avatar *target, int joint, float _endTime = -1, float _interval = 0.5)
			:Motion(), AvatarTarget(target), targetJointId(joint), ObjectTarget(NULL),
			endTime(_endTime), local(false), 
			eyesLimit(Piavca::Pi/12.0f), headbodyLimit(Piavca::Pi/3.0f),
			eyesMorphAngle(Piavca::Pi/8.0f),
			headActive(false), bodyActive(false), turnBodyVertical(false), turnBodyFull(false),
			reyeId(-1), leyeId(-1), headId(-1), bodyId(-1), interval(_interval),
			lookLeftId(-1), lookRightId(-1), lookUpId(-1), lookDownId(-1)
		{
			init();
		};
		//! create with an object target
		LookAtMotion(Object *target, float _endTime = -1, float _interval = 0.5)
			:Motion(), AvatarTarget(NULL), targetJointId(-1), ObjectTarget(target),
			endTime(_endTime), local(false), 
			eyesLimit(Piavca::Pi/12.0f), headbodyLimit(Piavca::Pi/2.0f),
			eyesMorphAngle(Piavca::Pi/8.0f),
			headActive(false), bodyActive(false), turnBodyVertical(false), turnBodyFull(false),
			reyeId(-1), leyeId(-1), headId(-1), bodyId(-1), interval(_interval),
			lookLeftId(-1), lookRightId(-1), lookUpId(-1), lookDownId(-1)
		{
			init();
		};
		/*! create with a location target
		 *  There is also a local flag, to indicate whether the vector is local
		 *  to the avatar or in world coordinates.
		 *  NB: LookAtMotion assumes you are using a motion queue,
		 *  it won't work properly otherwise.
		 */
		LookAtMotion(const Vec &target, float _endTime = -1, bool _local = false, float _interval = 0.5)
			:Motion(), LocationTarget(target), AvatarTarget(NULL), targetJointId(-1), ObjectTarget(NULL),
			endTime(_endTime), local(_local), 
			eyesLimit(Piavca::Pi/12.0f), headbodyLimit(Piavca::Pi/2.0f),
			eyesMorphAngle(Piavca::Pi/8.0f),
			headActive(false), bodyActive(false), turnBodyVertical(false), turnBodyFull(false),
			reyeId(-1), leyeId(-1), headId(-1), bodyId(-1), interval(_interval),
			lookLeftId(-1), lookRightId(-1), lookUpId(-1), lookDownId(-1)
		{
			init();
		};
		LookAtMotion(const LookAtMotion &lam)
			:Motion(lam), AvatarTarget(lam.AvatarTarget), targetJointId(lam.targetJointId),
			ObjectTarget(lam.ObjectTarget), LocationTarget(lam.LocationTarget),
			endTime(lam.endTime), local(lam.local), interval(lam.interval),
			eyesLimit(lam.eyesLimit), headbodyLimit(lam.headbodyLimit),
			eyesMorphAngle(lam.eyesMorphAngle),
			headActive(lam.headActive), bodyActive(lam.bodyActive), turnBodyFull(lam.turnBodyFull),
			turnBodyVertical(lam.turnBodyVertical),
			reyeId(lam.reyeId), leyeId(lam.leyeId), 
			headId(lam.headId), bodyId(lam.bodyId),
			lookLeftId(lam.lookLeftId), lookRightId(lam.lookRightId), 
			lookUpId(lam.lookUpId), lookDownId(lam.lookDownId)
		{};
	
		//! creates a copy of the motion
		virtual Motion *clone(){return new LookAtMotion(*this);};
		
		virtual bool isFacial(){return false;};

		//! whether you can access a motions value at frames other than the current one
		virtual bool isRandomAccess(){return false;};

		virtual void load(Avatar *av);

		void reblend(float time);

		/*! sets the target to an avatar.
		 *  Pass in an avatar, and a joint of that avatar to look at
		 */
		void setTarget(Avatar *target, int joint)
		{
			ObjectTarget = NULL;
			AvatarTarget = target;
			targetJointId = joint;
			local = false;
		}
		//! sets the target to an object
		void setTarget(Object *target)
		{
			ObjectTarget = target;
			AvatarTarget = NULL;
			targetJointId = -1;
			local = false;
		}
		/*! sets the target to a location
		 *  There is also a local flag, to indicate whether the vector is local
		 *  to the avatar or in world coordinates
		 */
		void setTarget(Vec target, bool _local = false)
		{
			ObjectTarget = NULL;
			AvatarTarget = NULL;
			targetJointId = -1;
			LocationTarget = target;
			local = _local;
		}

		tstring getTargetName()
		{
			if(AvatarTarget)return AvatarTarget->getName();
			if(ObjectTarget)return ObjectTarget->getName();
			return _T("");
		}

		void setHeadActive(bool b = true){headActive = b;};
		void setBodyActive(bool b = true){bodyActive = b;};
		void setTurnBodyVertical(bool b = true){turnBodyVertical = b;};
		void setTurnBodyFull(bool b = true){turnBodyFull = b;};
		void setLeanTowards(bool b = true){leanTowards = b;};

		void setEyesLimit(float f){eyesLimit = f;};
		void setHeadBodyLimit(float f){headbodyLimit = f;};
		void setEyesMorphAngle(float f){eyesMorphAngle = f;};
		
		//! sets when the avatar should stop looing
		void setEndTime (float time){endTime = time;};

		//! returns the length of the motion
		virtual float getMotionLength() const {return endTime - startTime;};

		//! given a track ID tests whether it actually points to anything or if its null
		bool isNull(int trackId) const 
		{
			return !(trackId == reyeId || trackId == leyeId 
				|| trackId == headId || trackId == bodyId);
		}
		//! this is a version of isNull that is used when the LookAtMotion is pretending to be facial
		bool isNullFacial(int trackId) const 
		{
			return !(trackId == lookLeftId || trackId == lookRightId
				|| trackId == lookUpId || trackId == lookDownId);
		}
		//! get the type of the track corresponding to an ID
		virtual trackType getTrackType(int trackId)const { return QUAT_TYPE;};

		//! works out whether the avatar can comfortably turn to look at a position
		bool canLookAt(Vec location);

		//! get the value of a track at a given time (only works for floats)
		virtual float getFloatValueAtTimeInternal(int trackId, float time);
		//! get the value of a track at a given time (only works for Vecs)
		virtual Vec getVecValueAtTimeInternal(int trackId, float time);
		//! get the value of a track at a given time (only works for Quats) 
		virtual Quat getQuatValueAtTimeInternal(int trackId, float time);
	};

	//! a motion filter that takes a LookAtMotion and pretends its a facial motion
    class PIAVCA_DECL LookAtToFacial : public MotionFilter
	{
	public:
		/*!
		 *	Pass in the motion to be filtered and a scale factor
		 */
		LookAtToFacial(LookAtMotion *m): MotionFilter(m){};
		LookAtToFacial(const LookAtToFacial &sm): MotionFilter(sm){};
	
		virtual Motion *clone(){return new LookAtToFacial(*this);};

		virtual void load(Avatar *av){Motion::load(av);};
	    
		virtual bool isFacial(){return true;};

		virtual bool isNull(int trackId) const
		{
			Motion *nonConstMot = const_cast<Motion *>(filterMot);
			LookAtMotion *lam = dynamic_cast< LookAtMotion *>(nonConstMot);
			if(lam)
				return lam->isNullFacial(trackId);
			else
				return true;
		};

	    //! calculates the values of a keyframe
	    PIAVCA_EXPORT virtual float  getFloatValueAtTimeInternal (int trackId, float time)
		{
			if(!filterMot)
			{
				Piavca::Error(_T("Scale motion: trying to get a value from a null motion"));
			}
			return filterMot->getFloatValueAtTime(trackId, time);
		};
	    
	    //! calculates the values of a keyframe (vec values are scaled)
	    PIAVCA_EXPORT virtual Vec  getVecValueAtTimeInternal (int trackId, float time)
		{
		    if(!filterMot)
			{
				Piavca::Error(_T("Scale motion: trying to get a value from a null motion"));
			}
			return  filterMot->getVecValueAtTime(trackId, time);
		};
	    
	    //! calculates the values of a keyframe
	    PIAVCA_EXPORT virtual Quat  getQuatValueAtTimeInternal (int trackId, float time)
		{
		    if(!filterMot)
			{
				Piavca::Error(_T("Scale motion: trying to get a value from a null motion"));
			}
		    return filterMot->getQuatValueAtTime(trackId, time);
		};
	};

};



#endif //LOOK_AT_MOTION_H
