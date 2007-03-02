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
 * The Original Code is Piavca.h.
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


#ifndef NO_PIAVCA_DLL
#define PIAVCA_CLIENT
#endif

#include "PiavcaAPI/PiavcaDefs.h"
#include "PiavcaAPI/PiavcaException.h"
#include "PiavcaAPI/PiavcaCore.h"
#include "PiavcaAPI/Avatar.h"
#include "PiavcaAPI/Object.h"
#include "PiavcaAPI/Motion.h"
#include "AvatarMotionQueue.h"
#include "PiavcaAPI/AvatarPostureBlend.h"
#include "PiavcaAPI/BlendBetween.h"
#include "PiavcaAPI/Hermite.h"
#include "PiavcaAPI/LoopMotion.h"
#include "LookAtMotion.h"
#include "MaskedMotion.h"
#include "PiavcaAPI/MotionTransition.h"
#include "PiavcaAPI/MathsUtils.h"
#include "PiavcaAPI/MotionAdder.h"
#include "Subtract.h"
#include "PiavcaAPI/MotionFilter.h"
#include "PiavcaAPI/Quat.h"
#include "RandomTimingsLoop.h"
#include "MultiMotionCombiner.h"
#include "ChoiceMotion.h"
#include "ChoiceLoopMotion.h"
#include "RandomChoiceMotion.h"
#include "RandomLoopMotion.h"
#include "RandomBlend.h"
#include "RandomBlendLoop.h"
#include "RandomAdd.h"
#include "RandomAddLoop.h"
#include "RandomGazeMotion.h"
#include "DiadicGazeMotion.h"
#include "Proxemics.h"
#include "ProxemicsLoop.h"
#include "ScaleMotion.h"
#include "ScaleMotionSpeed.h"
#include "ChangeMotionProp.h"
#include "ChangeMotionLength.h"
#include "ScaleMotionRoot.h"
#include "PiavcaAPI/MotionPosture.h"
#include "PiavcaAPI/AvatarPosture.h"
#include "PiavcaAPI/PostureBlend.h"
#include "PiavcaAPI/Sequence.h"
#include "PiavcaAPI/SmoothSequence.h"
#include "PiavcaAPI/Reposition.h"
#include "PiavcaAPI/SelfBlend.h"
#include "PiavcaAPI/TimeCallback.h"
#include "TimeOffset.h"
#include "PiavcaAPI/KeyframeMotion.h"
#include "TurnMotion.h"
#include "PiavcaAPI/TwoMotionCombiner.h"
#include "ZeroMotion.h"
#include "PiavcaAPI/Vec.h"
#include "MotionSaver.h"
#include "MotionParser.h"
#include "PiavcaAPI/SubMotion.h"
#include "TimeRangeMotion.h"
#include "TimeWarp.h"


