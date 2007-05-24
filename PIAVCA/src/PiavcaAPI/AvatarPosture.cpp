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
 * The Original Code is MotionPosture.cpp.
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


#include "Avatar.h"
#include "AvatarPosture.h"
#include "PiavcaError.h"
#include "PIAVCACore.h"

using namespace Piavca;

void AvatarPosture::load(Avatar *av)
{
	KeyframeMotion::load(av);
	getPostureFromAvatar(av);
}

void AvatarPosture::getPostureFromAvatar(Avatar *av)
{
	clearAllTracks();
	if (! av)
		return;

	if(isFacial())
	{	
		for(int track = av->beginExpression(); track != Core::nullId; av->nextExpression(track))
			if (isNull(track) || !(getTrackType(track) & FLOAT_TYPE))
				addFloatTrack(track, av->getFacialExpressionWeight(track));
			else
				setFloatKeyframe(track, 0, av->getFacialExpressionWeight(track));
	}
	else
	{
		if (isNull(root_position_id) || !(getTrackType(root_position_id) & VEC_TYPE))
			addVecTrack(root_position_id, av->getRootPosition());
		else
			setVecKeyframe(root_position_id, 0, av->getRootPosition());
		if (isNull(root_orientation_id) || !(getTrackType(root_orientation_id) & QUAT_TYPE))
			addQuatTrack(root_orientation_id, av->getRootOrientation());
		else
			setQuatKeyframe(root_orientation_id, 0, av->getRootOrientation());

		for(int joint = av->begin(); joint != Core::nullId; av->next(joint))
			if (isNull(joint) || !(getTrackType(joint) & QUAT_TYPE))
				addQuatTrack(joint, av->getJointOrientation(joint));
			else
				setQuatKeyframe(joint, 0, av->getJointOrientation(joint));
	}

	
};

