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
 * The Original Code is Avatar.i.
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


%rename(playMotionDirect) Piavca::Avatar::playMotion(Motion *); 

%apply int *INPUT { int &jointId };
%apply int *INPUT { int &expressionId };

%include "PiavcaAPI/Avatar.h"

/*
%typemap(in) AvatarTimeCallback*
{
	if ((SWIG_ConvertPtr($input,(void **) &$1, SWIGTYPE_p_Piavca__PyAvatarTimeCallback,SWIG_POINTER_EXCEPTION | 0 )) == -1) SWIG_fail;
}
 */

// add wrapper funcitont to the avatar object to allow joint/expression names
// as inputs instead of joint/expression ids
/*
%extend Piavca::Avatar {
	bool  setFacialExpressionWeight(const char *name, float weight)
	{
		int exprId = Piavca::Core::getCore()->getExpressionId(StringToTString(name));
		if(exprId < 0)
			Piavca::Error(tstring(_T("Unknown facial expression")) + StringToTString(name));
		return self->setFacialExpressionWeight(exprId, weight);
	}
	
	float getFacialExpressionWeight(const char *name)
	{
		return self->getFacialExpressionWeight(
			Piavca::Core::getCore()->getExpressionId(StringToTString(name)));
	}
	
	void	setJointOrientation		(const char *jointName, const Quat &val, const char * worldCoord = "JOINTLOCAL_COORD")
	{
		if(std::string(worldCoord) == "LOCAL_COORD")
			self->setJointOrientation(
				Piavca::Core::getCore()->getExpressionId(StringToTString(jointName)),
				val, Piavca::LOCAL_COORD);
		if(std::string(worldCoord) == "JOINTLOCAL_COORD")
			self->setJointOrientation(
				Piavca::Core::getCore()->getExpressionId(StringToTString(jointName)),
				val, Piavca::JOINTLOCAL_COORD);
		if(std::string(worldCoord) == "WORLD_COORD")
			self->setJointOrientation(
				Piavca::Core::getCore()->getExpressionId(StringToTString(jointName)),
				val, Piavca::LOCAL_COORD);
	};
	
	Quat	getJointOrientation		(const char * jointName, const char * worldCoord = "JOINTLOCAL_COORD")
	{
		if(std::string(worldCoord) == "LOCAL_COORD")
			return self->getJointOrientation(
				Piavca::Core::getCore()->getExpressionId(StringToTString(jointName)),
				Piavca::LOCAL_COORD);
		if(std::string(worldCoord) == "JOINTLOCAL_COORD")
			return self->getJointOrientation(
				Piavca::Core::getCore()->getExpressionId(StringToTString(jointName)),
				Piavca::JOINTLOCAL_COORD);
		if(std::string(worldCoord) == "WORLD_COORD")
			return self->getJointOrientation(
				Piavca::Core::getCore()->getExpressionId(StringToTString(jointName)),
				Piavca::LOCAL_COORD);
	};

	
	
	
	Vec		getJointBasePosition	(const char * jointName, const char * worldCoord = "LOCAL_COORD")
	{
		if(std::string(worldCoord) == "LOCAL_COORD")
			return self->getJointBasePosition(
				Piavca::Core::getCore()->getExpressionId(StringToTString(jointName)),
				Piavca::LOCAL_COORD);
		if(std::string(worldCoord) == "JOINTLOCAL_COORD")
			return self->getJointBasePosition(
				Piavca::Core::getCore()->getExpressionId(StringToTString(jointName)),
				Piavca::JOINTLOCAL_COORD);
		if(std::string(worldCoord) == "WORLD_COORD")
			return self->getJointBasePosition(
				Piavca::Core::getCore()->getExpressionId(StringToTString(jointName)),
				Piavca::LOCAL_COORD);
	};

	// a new user friendly version of playMotion
	void play_motion(Motion *m)
	{
		Piavca::AvatarMotionQueue::getQueue(self)->enqueueMotion(_T(""), m);
  
	}
	void play_motion(const char *motionName)
	{
		Motion *m = Piavca::Core::getCore()->getMotion(StringToTString(motionName));
		Piavca::AvatarMotionQueue::getQueue(self )->enqueueMotion
				(StringToTString(motionName), m);
	}

	// a new user friendly version of playMotion
	void add_background_motion(Motion *m)
	{
		Piavca::AvatarMotionQueue::getQueue(self )->addBackgroundMotion(_T(""), m);
  
	}
	void add_background_motion(const char *motionName)
	{
		Motion *m = Piavca::Core::getCore()->getMotion(StringToTString(motionName));
		Piavca::AvatarMotionQueue::getQueue(self )->addBackgroundMotion
				(StringToTString(motionName), m);
  
	}
	
	// a new user friendly version of playMotion
	void interrupt_motion()
	{
		Piavca::AvatarMotionQueue::getQueue(self)->interrupt();
  
	}
	
	void stop_motion(const char *motionName)
	{
		Piavca::AvatarMotionQueue::getQueue(self)->removeMotion(motionName);
		Piavca::AvatarMotionQueue::getQueue(self)->removeBackgroundMotion(motionName);
	}
	
	void reposition_relative(const Vec &pos)
	{
		if(Piavca::AvatarMotionQueue::hasQueue(self))
		{
			Piavca::AvatarMotionQueue::getQueue(self)->repositionRelative(pos);
		}
		else
		{
			self->setRootPosition(pos - self->getRootPosition());
		}
	};
	
	void reposition_absolute(const Vec &pos)
	{
		if(Piavca::AvatarMotionQueue::hasQueue(self))
		{
			Piavca::AvatarMotionQueue::getQueue(self)->repositionAbsolute(pos);
		}
		else
		{
			self->setRootPosition(pos);
		}
	};

}
*/