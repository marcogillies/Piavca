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
 * The Original Code is PointAt.h.
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



#ifndef POINT_AT_H
#define POINT_AT_H

#include "PiavcaAPI/MotionFilter.h"
#include "PiavcaAPI/Vec.h"
#include "PiavcaAPI/CurrentValueMotion.h"
#include "PiavcaAPI/PiavcaCore.h"


#include <limits>
#include <vector>
using std::vector;

namespace Piavca 
{
	typedef int joint_id;

	/*!	A motion class that makes the avatar look at a target.
	 *  The avatar will turn to look at the given target with eyes, head, and body.
	 *  The target can either be an avatar, an object or a vector location.
	 */
	class PIAVCA_DECL PointAt : public MotionFilter
	{
		//Motion *targetMotion;
		CurrentValueMotion *currentValueTarget;
		int targetJointId;
		int jointId;
		bool local;
		Vec forwardDirection;

		void init();
	public:
		/*! create with a location target
		 *  There is also a local flag, to indicate whether the vector is local
		 *  to the avatar or in world coordinates.
		 *  NB: LookAtMotion assumes you are using a motion queue,
		 *  it won't work properly otherwise.
		 */
		PointAt()
			:MotionFilter(), /*targetMotion(NULL),*/ currentValueTarget(NULL), 
			targetJointId(Piavca::Core::nullId), jointId(Piavca::Core::nullId),
			local(false), forwardDirection(Vec::YAxis())
		{
		};
		//! create with an vector target
		PointAt(int joint, const Piavca::Vec &target, bool _local=false)
			:MotionFilter(), /*targetMotion(NULL),*/ currentValueTarget(NULL), 
			targetJointId(0), jointId(joint),
			local(_local), forwardDirection(Vec::YAxis())
		{
			setTarget(target);
		};
		/*! create with an motion target.
		 *  Pass in an avatar, and a joint of that avatar to look at
		 */
		PointAt(int joint, Motion *target, int target_joint)
			:MotionFilter(target), /*targetMotion(target),*/ currentValueTarget(NULL), 
			targetJointId(target_joint), jointId(joint),
			local(false), forwardDirection(Vec::ZAxis())
		{
		};
		
		PointAt(const PointAt &pa)
			:MotionFilter(pa), /*targetMotion(NULL),*/ currentValueTarget(NULL), 
			targetJointId(pa.targetJointId), jointId(pa.jointId),
			local(pa.local), forwardDirection(pa.forwardDirection)
		{
			if (pa.currentValueTarget)
			{
				setTarget(pa.currentValueTarget->getVecValueAtTime(0, 0.0));
			}
			//else
			//{
			//	setTargetMotion(pa.targetMotion->clone());
			//}

		};
	
		//! creates a copy of the motion
		virtual Motion *clone(){return new PointAt(*this);};

		//! returns the name of the type
		Piavca::tstring getClassName(){return "PointAt";};

		//! casts a motion to this type
		static PointAt *castToThisType(Motion *m){return dynamic_cast<PointAt *>(m);};
		

		//! whether you can access a motions value at frames other than the current one
		virtual bool isRandomAccess(){return false;};


		void setTarget(const Vec &target);
		Vec getTarget();

		virtual void setMotion(Motion *mot);
		virtual Motion *getMotion();

		//void setTargetMotion(Motion *target);
		//Motion *getTargetMotion();

		void setLocal(bool l)
		{
			local = l;
		};

		bool getLocal()
		{
			return local;
		};


		void setJointId(int id)
		{
			jointId = id;
		};

		joint_id getJointId()
		{
			return jointId;
		};


		void setTargetJointId(int id)
		{
			targetJointId = id;
		};

		int getTargetJointId()
		{
			return targetJointId;
		};

		
		void setForwardDirection(const Vec &v)
		{
			forwardDirection = v;
		};


		Vec getForwardDirection()
		{
			return forwardDirection;
		}


		//! given a track ID tests whether it actually points to anything or if its null
		bool isNull(int trackId) const 
		{
			return !(trackId == jointId);
		}

		//! get the type of the track corresponding to an ID
		virtual int getTrackType(int trackId)const 
		{
			if  (trackId == jointId)
				return QUAT_TYPE;
			else
				return NULL_TYPE;
		};

		//! get the value of a track at a given time (only works for floats)
		virtual float getFloatValueAtTimeInternal(int trackId, float time);
		//! get the value of a track at a given time (only works for Vecs)
		virtual Vec getVecValueAtTimeInternal(int trackId, float time);
		//! get the value of a track at a given time (only works for Quats) 
		virtual Quat getQuatValueAtTimeInternal(int trackId, float time);
	};

	
};



#endif //POINT_AT_H
