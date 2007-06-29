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
 * The Original Code is Hermite.h.
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

/*!
 *	Functions for hermite interpolations.
 */
#ifndef HERMITE_H
#define HERMITE_H

#include "Quat.h"
#include "PiavcaError.h"
#include <float.h>
//#include "PiavcaCore.h"

#ifdef WIN32
	#define isnan _isnan
#endif

namespace Piavca
{
class PIAVCA_DECL Vec;

inline bool checkNaN(float f) 
{
	return isnan(f);
}

//! Calculates tangents for a hermite curve at the control points.
/*!
 *	The interpolation curves are piecewise hermite curves. This means that 
 *	between two control points the curves are a cubic hermite curve. A hermite curve 
 *	is defined by two control points which are the end points of the curve and the two
 *	tangents (velocities) at these end points. The keyframes give the successive control 
 *	points of the motion curves but the tangents are also needed. They can be provided by 
 *	the client but generally they will calculated automatically using this function. 
 *	The method used is based on the average of the previous and successive keyframe. 
 *	It is based on Catmull-Rom curves
 */
template <class T>
T keyframeTangent(T current, T prev, float prevTime, T next, float nextTime)
{
	T nextDiff = next - current;
	T prevDiff = current - prev;
	float timeMultiple = nextTime+prevTime;
	float nextTimeDiv = nextTime/timeMultiple;
	float prevTimeDiv = prevTime/timeMultiple;
	T retVal = static_cast<T>((nextDiff*nextTimeDiv + prevDiff*prevTimeDiv)/2.0);
	//if(retVal != retVal)
	if(checkNaN(retVal))
	{
		std::cout << "keyframe tangent " << current << " " << prev << " " << prevTime << " " << next << " " << nextTime << std::endl;
		std::cout << timeMultiple << " " << nextTimeDiv << " " << prevTimeDiv << " " << retVal << std::endl;
		Piavca::Error(_T("Got a NaN when calculating keyframe tangents"));	
	};
	return retVal;
	//return ((next - current)*(nextTime/(nextTime*prevTime)) + (current - prev)*(prevTime/(nextTime*prevTime)))/2.0;
};

//! A slightly different method is used for calculating tangents of quaternion curves.
/*!
 *	The maths is equivalent but it needs to be translated into quaternion speak
 */
inline Quat keyframeTangent(Quat current, Quat prev, float prevTime, Quat next, float nextTime)
{
	Quat q1 = next*current.inverse(); //q1.Scale(nextTime/(nextTime*prevTime));
	Quat q2 = current*prev.inverse(); //q2.Scale(prevTime/(nextTime*prevTime));
	return slerp(q1, q2, 0.5);
	//return slerp(q1, q2, nextTime/(nextTime*prevTime));
};

//! evaluate a hermite curve at time t
/*!
 *	length is the length of time between the two successive keyframes. p0 and p1
 *	are the two keyframes that bracket time t. d0 and d1 are the tangents (velocities)
 *	at these keyframes
 */
//@{
//! float hermite
PIAVCA_EXPORT float HermiteEvaluate(float t, float length, float p0, float d0, float p1, float d1);
//! Vec hermite
PIAVCA_EXPORT Vec HermiteEvaluate(float t, float length, Vec p0, Vec d0, Vec p1, Vec d1);
//! Quat hermite
PIAVCA_EXPORT Quat HermiteEvaluate(float t, float length, Quat p0, Quat d0, Quat p1, Quat d1);
//@}
};

#endif // HERMITE_H
