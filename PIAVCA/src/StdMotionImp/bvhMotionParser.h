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
 * The Original Code is bvhParser.h.
 *
 * The Initial Developer of the Original Code is Marco (Mark) Gillies.
 * Portions created by the Initial Developer are Copyright (C) BT plc. 2004
 * All Rights Reserved.
 *
 * ***** END LICENSE BLOCK ***** */


#ifndef BVH_MOTION_PARSER_H
#define BVH_MOTION_PARSER_H

#include "PiavcaAPI/PiavcaException.h"

namespace Piavca{

	class MotionImp;
	class Core;
	class Motion;
	
	void readBvhMotion(Piavca::Core *core, MotionImp *mot, std::string fileName, int flags, Motion *basePosture = NULL, bool test = false);

};

#endif //BVH_MOTION_PARSER_H
