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
 * The Original Code is ChangeMotionLength.h.
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


#ifndef CHANGE_MOTION_LENGTH_H
#define CHANGE_MOTION_LENGTH_H

#include "ScaleMotionSpeed.h"

namespace Piavca 
{
	//! Rescales the duration (length) of a motion. The motion will be speeded up or slowed down to get the new length. Is based on ScaleMotionSpeed.
	class PIAVCA_DECL ChangeMotionLength : public ScaleMotionSpeed
	{
		float length;
	public:
		ChangeMotionLength(Motion *mot=NULL, float len=1.0f)
			: ScaleMotionSpeed(mot), length(len)
		{
			if(filterMot)
			{
				float motLen = mot->getMotionLength();
				float scale;
				if(motLen >= 0.0001)
				{
					scale = motLen/length;
					setScaleFactor(scale);
				}
			}
		};
		ChangeMotionLength(const ChangeMotionLength &cml)
			:ScaleMotionSpeed(cml), length(cml.length){};
	
		virtual Motion *clone(){return new ChangeMotionLength(*this);};

		//! returns the name of the type
		Piavca::tstring getClassName(){return "ChangeMotionLength";};

		//! casts a motion to this type
		static ChangeMotionLength *castToThisType(Motion *m){return dynamic_cast<ChangeMotionLength *>(m);};

		//! the new length of the motion
		void setLength(float len)
		{
			length = len;
			if(filterMot)
			{
				float motLen = filterMot->getMotionLength();
				float scale;
				if(motLen >= 0.0001)
				{
					scale = motLen/length;
					setScaleFactor(scale);
				}
			}
		};


		//! gets the length of the motion in seconds
		float getLength() const
		{
			return length;
		};

		//! gets the length of the motion in seconds
		virtual float getMotionLength() const
		{
			return getLength();
		};

		virtual void setMotion(Motion *mot)
		{
			ScaleMotionSpeed::setMotion(mot);
			if(filterMot)
			{
				float motLen = mot->getMotionLength();
				float scale;
				if(motLen >= 0.0001)
				{
					scale = motLen/length;
					setScaleFactor(scale);
				}
			}
		};
	};

};


#endif //CHANGE_MOTION_LENGTH_H
