/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1
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
 * The Original Code is AvatarPostureBlend.h.
 *
 * The Initial Developer of the Original Code is Marco (Mark) Gillies.
 * Portions created by the Initial Developer are Copyright (C) BT plc. 2004
 * All Rights Reserved.
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

#ifndef AVATAR_POSTURE_BLEND_H
#define AVATAR_POSTURE_BLEND_H

//#include "Motion.h"
//#include "PiavcaCore.h"
#include "SequentialBlend.h"

namespace Piavca
{
	class PIAVCA_DECL Avatar;

	//! A motion blend operator that blends a motion into the current position of an avatar
	/*!  This class will blend smoothly from the current postion of an avatar to the motion
	 *	and will have the motion start at the current position and orientation of the avatar
	 *  rather than its own start point (see SequentialBlend docs for some details)
	 */
    class PIAVCA_DECL AvatarPostureBlend : public SequentialBlend
	{
		//Avatar *avatar;
		bool tracksFromAvatar;
	public:
		/*! 
		 *	Pass in the motion to be blended in, 
		 *  the length of time over which the blend should happen,
		 *  add a flag which specifies whether the tracks that the motion has should
		 *  be those in the blended in motion or those in the avatar
		 */
	    AvatarPostureBlend(Motion *mot=NULL, float interval = 0.2, bool tracksFromAvatar=false);
		AvatarPostureBlend(const AvatarPostureBlend &apb)
			:SequentialBlend(apb), tracksFromAvatar(apb.tracksFromAvatar){};

		virtual Motion *clone(){return new AvatarPostureBlend(*this);};

		virtual void load(Avatar *av);

		void setMotion(Motion *mot);

		//! restart the blend (i.e. start blending from the current avatar posture) at the current time
	    void reblend();
	    //! restart the blend (i.e. start blending from the current avatar posture) at the current time
	    void reblend(float time);
	};
};

#endif //AVATAR_POSTURE_BLEND_H
