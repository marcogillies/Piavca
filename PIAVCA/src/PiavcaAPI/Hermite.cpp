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
 * The Original Code is Hermite.cpp.
 *
 * The Initial Developer of the Original Code is Marco (Mark) Gillies.
 * Portions created by the Initial Developer are Copyright (C) BT plc. 2004
 * All Rights Reserved.
 *
 * ***** END LICENSE BLOCK ***** */


//#ifdef PIAVCA_DLL
//#define __declspec( dllexport ) 
//#else
//#define PIAVCA_EXPORT
//#endif

#include "Hermite.h"
#include "Vec.h"
#include "Quat.h"
#include "PiavcaDefs.h"

#include <assert.h>

#include <fstream>

namespace Piavca
{

float HermiteEvaluate(float t, float length, float p0, float d0, float p1, float d1)
{
	t /= length;
	float result = 2.0f*p0 - 2.0f*p1 + d0 + d1; // coeffs of t cubed
	result = -3.0f*p0 + 3.0f*p1 - 2.0f*d0 - d1 + t*result; //coeffs of t squared
	result = d0 + t*result; //coeffs of t
	result = p0 + t*result;  //constant

	return result;
}

Vec HermiteEvaluate(float t, float length, Vec p0, Vec d0, Vec p1, Vec d1)
{
	return Vec(	HermiteEvaluate(t, length, p0[0], d0[0], p1[0], d1[0]),
				HermiteEvaluate(t, length, p0[1], d0[1], p1[1], d1[1]),
				HermiteEvaluate(t, length, p0[2], d0[2], p1[2], d1[2]));
};


Quat HermiteEvaluate(float t, float length, Quat p0, Quat d0, Quat p1, Quat d1)
{
	//return Quat();
  //static std::ofstream file("splineLog.txt");

  //file << t << " ";

  Quat old_d0 = d0;
  Quat old_d1 = d1;

  t /= length;
  //d0.Scale(length/3.0);
  //d1.Scale(length/3.0);
  d0.Scale(1.0f/3.0f);
  d1.Scale(1.0f/3.0f);
  Quat q1 = d0 * p0; 
  Quat q2 = d1.inverse() * p1;
  q1.normalise(); q2.normalise();  

  //file << "p0 " << p0 << " ";
  //file << "d0 " << d0 << " ";
  //file << "old d0 " << old_d0 << " ";
  //file << "p1 " << p1 << " ";
  //file << "d1 " << d1 << " ";
  //file << "old d1 " << old_d1 << " ";
  //file << "q1 " << q1 << " ";
  //file << "q2 " << q2 << " ";

  Quat P00(slerp(p0,q1,t));
  Quat P01(slerp(q1,q2,t));
  Quat P02(slerp(q2,p1,t));
  
  Quat P10(slerp(P00,P01,t));
  Quat P11(slerp(P01,P02,t));

  //return slerp(P10,P11,t);

  Quat q = slerp(P10, P11, t);
  //file << "return "<< q << std::endl;

	//TEMP
  //q = slerp(p0, p1, t);
  
  if(q != q)
  {
		Piavca::Error(_T("Got a NaN when interpolating quaternions"));	
  };
  q.normalise();


  return q;
};

}
