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
 * The Original Code is ZeroMotion.h.
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


#ifndef ZERO_MOTION_H
#define ZERO_MOTION_H

#include "PiavcaAPI/Motion.h"

namespace Piavca 
{
	/*!	A motion class that makes the avatar look at a target.
	 *  The avatar will turn to look at the given target with eyes, head, and body.
	 *  The target can either be an avatar, an object or a vector location.
	 */
	class PIAVCA_DECL ZeroMotion : public Motion
	{
		bool facial;
	public:
		/*! create with an avatar target.
		 *  Pass in an avatar, and a joint of that avatar to look at
		 */
		ZeroMotion(bool _facial = false):Motion(), facial(_facial){};
		ZeroMotion(const ZeroMotion &zm):Motion(zm), facial(zm.facial){};
	
		//! creates a copy of the motion
		virtual Motion *clone(){return new ZeroMotion(*this);};
		
		virtual bool isFacial(){return facial;};

		//! whether you can access a motions value at frames other than the current one
		virtual bool isRandomAccess(){return true;};

		//! returns the length of the motion
		virtual float getMotionLength() const {return 0;};

		//! given a track ID tests whether it actually points to anything or if its null
		bool isNull(int trackId) const 
		{
			return false;
		}
		//! get the type of the track corresponding to an ID
		virtual int getTrackType(int trackId)const 
		{ 
			if(facial) 
				return FLOAT_TYPE;
			else
			{
				if(trackId == root_position_id)
					return VEC_TYPE;
				else
					return QUAT_TYPE;
			}	
		};
		
		//! get the value of a track at a given time (only works for floats)
		virtual float getFloatValueAtTimeInternal(int trackId, float time) {return 0.0;};
		//! get the value of a track at a given time (only works for Vecs)
		virtual Vec getVecValueAtTimeInternal(int trackId, float time) {return Vec();};
		//! get the value of a track at a given time (only works for Quats) 
		virtual Quat getQuatValueAtTimeInternal(int trackId, float time) {return Quat();};
	};

};



#endif //ZERO_MOTION_H
