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
 * The Original Code is MathUtils.h.
 *
 * The Initial Developer of the Original Code is Marco (Mark) Gillies.
 * Portions created by the Initial Developer are Copyright (C) BT plc. 2004
 * All Rights Reserved.
 *
 * ***** END LICENSE BLOCK ***** */


#ifndef MATHS_UTILS_H
#define MATHS_UTILS_H


namespace Piavca
{
	//! Pi the constant
	const float Pi = 3.14159265358979323846f;
	//! convert and angle in degrees to radians
	inline float degToRad(float angle){return angle*Pi/180.0f;};
	//! convert and angle in radians to degrees
	inline float radToDeg(float angle){return angle*180.0f/Pi;};
}

#endif //MATHS_UTILS_H
