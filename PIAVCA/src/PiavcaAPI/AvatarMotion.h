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
 * The Original Code is AvatarMotion.h.
 *
 * The Initial Developer of the Original Code is Marco (Mark) Gillies.
 * Portions created by the Initial Developer are Copyright (C) 2009
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



#ifndef AVATAR_MOTION_H
#define AVATAR_MOTION_H

#include "PiavcaAPI/Motion.h"
#include "PiavcaAPI/Vec.h"
#include "PiavcaAPI/Avatar.h"


#include <limits>
#include <vector>
using std::vector;

namespace Piavca 
{
	/*!	A motion class that wraps the movement of an avatar.
	 */
	class PIAVCA_DECL AvatarMotion : public Motion
	{
		Avatar *m_wrapped_avatar;
		bool global;
	public:
		/*! create with a location target
		 *  There is also a local flag, to indicate whether the vector is local
		 *  to the avatar or in world coordinates.
		 *  NB: LookAtMotion assumes you are using a motion queue,
		 *  it won't work properly otherwise.
		 */
		AvatarMotion(Avatar *av=NULL, bool _global=true)
			:Motion(), m_wrapped_avatar(av), global(_global)		{
		};
		//! creates a copy of the motion
		virtual Motion *clone(){return new AvatarMotion(*this);};

		//! returns the name of the type
		Piavca::tstring getClassName(){return "AvatarMotion";};

		//! casts a motion to this type
		static AvatarMotion *castToThisType(Motion *m){return dynamic_cast<AvatarMotion *>(m);};
		

		//! whether you can access a motions value at frames other than the current one
		virtual bool isRandomAccess(){return false;};


		//! the avatar whose motion is used
		void setWrappedAvatar(Avatar *avatar)
		{
			m_wrapped_avatar = avatar;
		};
		Avatar *getWrappedAvatar()
		{
			return 	m_wrapped_avatar;
		};
		

		//void setTargetMotion(Motion *target);
		//Motion *getTargetMotion();

		//! whether joint values are returned in global or local coordinates
		void setGlobal(bool g)
		{
			global = g;
		};

		bool getGlobal()
		{
			return global;
		};

		
		bool setParameter(tstring paramName, tstring value);
		
		//! given a track ID tests whether it actually points to anything or if its null
		bool isNull(int trackId) const ;

		//! get the type of the track corresponding to an ID
		virtual int getTrackType(int trackId)const ;

		//! get the value of a track at a given time (only works for floats)
		virtual float getFloatValueAtTimeInternal(int trackId, float time);
		//! get the value of a track at a given time (only works for Vecs)
		virtual Vec getVecValueAtTimeInternal(int trackId, float time);
		//! get the value of a track at a given time (only works for Quats) 
		virtual Quat getQuatValueAtTimeInternal(int trackId, float time);
	};

	
};



#endif //AVATAR_MOTION_H
