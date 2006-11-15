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
 * The Original Code is Quat.cpp.
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


//#ifdef PIAVCA_DLL
//#define PIAVCA_EXPORT __declspec( dllexport ) 
//#else
//#define PIAVCA_EXPORT
//#endif

#include "PiavcaDefs.h"
#include "Quat.h"
#include "PiavcaError.h"
#include <math.h>
#include <limits>

#include <assert.h>

//using namespace UCLAvatars;

using namespace Piavca;

Quat::Quat()								
{
	S() = 1.0; 
	I() = 0.0; 
	J() = 0.0; 
	K() = 0.0;
};
	
Quat::Quat(float s, float i, float j, float k)
{
	S() = s; 
	I() = i; 
	J() = j; 
	K() = k;
};

Quat::Quat(const float q[4])					
{
	vals[0] = q[0]; 
	vals[1] = q[1]; 
	vals[2] = q[2]; 
	vals[3] = q[3];
};


Quat::Quat(float Angle, const Vec &Axis)	
{
	setAngleAxis(Angle, Axis);
};

Quat::Quat(const Quat &q)					
{
	S() = q.S(); 
	I() = q.I(); 
	J() = q.J(); 
	K() = q.K();
};
	

void Quat::setAngleAxis(float Angle, float x, float y, float z)
{
	float sA = static_cast<float>(sin(Angle/2.0));
	float cA = static_cast<float>(cos(Angle/2.0));

	I() = x*sA;
	J() = y*sA;
	K() = z*sA;
	S() = cA;
}
	
void Quat::getAngleAxis(float &Angle, Vec &Axis) const
{
	Angle = static_cast<float>(acosf(S())*2.0);

	float s = sinf(Angle/2.0f);
	if(s > 0.01)
	{
		Axis.X() = I()/s;
		Axis.Y() = J()/s;
		Axis.Z() = K()/s;
	}
	else
	{
		Angle = 0.0f;
		Axis.X() = 0.0f;
		Axis.Y() = 1.0f;
		Axis.Z() = 0.0f;
	};
}

float Quat::getAngle()const
{
	return static_cast<float>(acosf(S())*2.0);
};
	

Quat &Quat::pointAt(const Vec &original, const Vec &desired)
{
	Vec normOrig = original.normalized();
	Vec normDes  = desired.normalized();
	Vec cross    = normOrig.cross(normDes);
	float dot		 = normOrig.dot(normDes);

	// c2 is a bit of an odd thing. It is twice the 
	// cosine of half the angle between the vectors
	// we need this because the i,j,k components of 
	// the quaternion have to be the axis divided by 
	// the sine of half the angle of rotation
	// now the cross product gives us the axis multiplied
	// by the sine of the whole angle. To get what we want
	// we need to divide this by twice the cosine of half
	// the angle (based on the half angle formulae)
	// c2 itself is calculated from the dot product (i.e.
	// the cosine of the whole angle) using a half angle 
	// identity
	float c2 = (float)sqrt((1.0f+dot)*2.0f);

	if(fabs(c2) > 0.00001)
	{
		// the normal case where c2 (the cos of the angles 
		// between the vectors) is non-zero 
		S() = c2/2.0f;
		I() = cross.X()/c2;
		J() = cross.Y()/c2;
		K() = cross.Z()/c2;
	}
	else
	{
		// this is the case where s is zero
		// this only happens when the dot product between
		// the two vectors is -1 
		// This means that the vectors are co-linear and in opposite 
		// directions
		// what we need to do is to rotate pvNormOrig by 180deg around
		// and arbitrary vector normal to pvNormOrig

		// first we need to calculate this normal vector
		// to get this vector we start with pvOriginal and set the 
		// z value to 0, swap the x and y values and negate the y val
		// this fails if pvNormOrig is parallel to the z-axis 
		// so we do the same setting the x-axis to 0
		Vec normVec;
		if(fabs(normOrig.X() + normOrig.Y()) > 0.00001)
		{
			normVec = Vec(-normOrig.Y(), normOrig.X(), 0.0f);
		}
		else
		{
			normVec = Vec(0.0f, -normOrig.Z(), normOrig.Y());
		}
		
		// cos(180/2) = 0 and sin(180/2) = 1 so the formulae reduce to:
		S() = 0;
		I() = normVec.X();
		J() = normVec.Y();
		K() = normVec.Z();	
	}
	return (*this);
}

const Quat Quat::operator*(const Quat &q) const
{
	Quat retVal;
	retVal.S() = S()*q.S() - I()*q.I() - J()*q.J() - K()*q.K();
	retVal.I() = S()*q.I() + I()*q.S() + J()*q.K() - K()*q.J();
	retVal.J() = S()*q.J() + J()*q.S() + K()*q.I() - I()*q.K();
	retVal.K() = S()*q.K() + K()*q.S() + I()*q.J() - J()*q.I();

	return retVal;
}


void Quat::normalise()
{
	float norm = sqrt(S()*S() + I()*I() + J()*J() + K()*K());
	if(fabs(norm) > 0.00001)
	{
		S() /= norm;
		I() /= norm;
		J() /= norm;
		K() /= norm;
	}
	// there isn't really anything sensible to do if norm is
	// zero but setting it to the null quaternion seems OK
	else
	{
		S() = 1.0;
		I() = 0.0;
		J() = 0.0;
		K() = 0.0;
	}
}

void Quat::Scale(float f)
{
	// get the angle and its sign (actually its just half the angle
	// cos that's how quaternions work)
	float Angle = static_cast<float>(acosf(S()));
	float s = static_cast<float>(sin(Angle));

	// scale the angle by f
	Angle *= f;
	float sf = static_cast<float>(sin(Angle));
	// you actually want to divide by the original sin and
	// multiply by the new sin
	sf = sf/s;
	// if the angle is non-zero do the scale
	// (if not your scaling zero which does nothing so
	// don't bother)
	if(s > 0.00001)
	{
		S() = cos (Angle);
		I() *= sf;
		J() *= sf;
		K() *= sf;
	}
}

// get the x-rotation of the quaternion
// Few, finally found an easy way to do this
// it was in Ken Shoemake's original paper all along
// In this version I just call all the individual Euler
// the method works by combining the fomulae to go from 
// a quaternion to a matrix and then that to go from
// a matrix to Euler angles
// See Ken Shoemake "Animating Rotation with Quaternion 
// curves" (siggraph 85)
// I return minus the angle because the quaternion definition
// I use is the inverse of Shoemake's
float Quat::Xangle()
{
	float sinYangle = -(2.0f * I() * K() - 2.0f * J() * S());
	float cosYangle = sqrtf(1.0f - sinYangle * sinYangle);
	
	float sinXangle, cosXangle;
	if(fabs(cosYangle) < 0.0001)
	{
		sinXangle = -(2.0f * J() * K() - 2.0f * I() * S());
		cosXangle = 1.0f - 2.0f * I() * I() - 2.0f * K() * K();
	}
	else
	{
		sinXangle = 2.0f * J() * K() + 2.0f * I() * S();
		sinXangle /= cosYangle;
		cosXangle = 1.0f - 2.0f * I() * I() - 2.0f * J() * J();
		cosXangle /= cosYangle;
	}
	return -atan2f(sinXangle, cosXangle);
}
// get the y-rotation of the quaternion
// Few finally found an easy way to do this
// it was in Ken Shoemake's original paper all along
// In this version I just call all the individual Euler
// the method works by combining the fomulae to go from 
// a quaternion to a matrix and then that to go from
// a matrix to Euler angles
// See Ken Shoemake "Animating Rotation with Quaternion 
// curves" (siggraph 85)
// I return minus the angle because the quaternion definition
// I use is the inverse of Shoemake's
float Quat::Yangle()
{
	float sinYangle = -(2.0f * I() * K() - 2.0f * J() * S());
	return -asinf(sinYangle);
}

// get the z-rotation of the quaternion
// Few finally found an easy way to do this
// it was in Ken Shoemake's original paper all along
// In this version I just call all the individual Euler
// the method works by combining the fomulae to go from 
// a quaternion to a matrix and then that to go from
// a matrix to Euler angles
// See Ken Shoemake "Animating Rotation with Quaternion 
// curves" (siggraph 85)
// I return minus the angle because the quaternion definition
// I use is the inverse of Shoemake's
float Quat::Zangle()
{
	float sinYangle = -(2.0f * I() * K() - 2.0f * J() * S());
	float cosYangle = sqrtf(1.0f -sinYangle * sinYangle);
	
	if(fabs(cosYangle) < 0.0001)
	{
		return 0.0f;
	}
	else
	{
		float sinZangle, cosZangle;
		sinZangle = 2.0f * I() * J() + 2.0f * K() * S();
		sinZangle /= cosYangle;
		cosZangle = 1.0f - 2.0f * J() * J() - 2.0f * K() * K();
		cosZangle /= cosYangle;
		return -atan2f(sinZangle, cosZangle);
	}
};

void Quat::getEulerAngles(float &X, float &Y, float &Z)
{
	X = Xangle();
	Y = Yangle();
	Z = Zangle();
};

float Quat::spherical_distance(const Quat &q1, const Quat &q2)
{
	float ct = q1.S()*q2.S() + q1.I()*q2.I() + q1.J()*q2.J() + q1.K()*q2.K();

	Quat to, retVal;
	if (ct < 0.0)
	{
		ct = -ct;
		to =  Quat(-q2.S(), -q2.I(), -q2.J(), -q2.K());
	}
	else 
	{
		to = q2;
	}
	// just in case ct is greater than 1 by floating point errors
	// if its more than 1.1 there's probably something really wrong
	//assert(ct < 1.1);
	// otherwise assume its floating point errors and fudge
	if(ct > 1.0) ct = 1.0;
	return (float)acosf(ct);
};


PIAVCA_DECL Quat Piavca::slerp(const Quat &q1, const Quat &q2, float t)
{
	float ct = q1.S()*q2.S() + q1.I()*q2.I() + q1.J()*q2.J() + q1.K()*q2.K();

	Quat to, retVal;
	if (ct < 0.0)
	{
		ct = -ct;
		to =  Quat(-q2.S(), -q2.I(), -q2.J(), -q2.K());
	}
	else 
	{
		to = q2;
	}
	// just in case ct is greater than 1 by floating point errors
	// if its more than 1.1 there's probably something really wrong
	//assert(ct < 1.1);
	// otherwise assume its floating point errors and fudge
	if(ct > 1.0) ct = 1.0;
	float theta = (float)acosf(ct);
	float st = (float)sin(theta);
	if(fabs(st) < std::numeric_limits<float>::epsilon()) return q1;
	float startscale = (float)sin((1.0-t)*theta)/st;
	float endscale = (float)sin(t*theta)/st;
	retVal.S() = startscale*q1.S() + endscale*to.S();
	retVal.I() = startscale*q1.I() + endscale*to.I();
	retVal.J() = startscale*q1.J() + endscale*to.J();
	retVal.K() = startscale*q1.K() + endscale*to.K();

	if(retVal != retVal)
	{
		Piavca::Error(_T("got a NaN when doing a quaternion slerp"));	
	};

	return retVal;
}


PIAVCA_DECL std::ostream &operator<<(std::ostream &os, const Piavca::Quat &q)
{
	os << "[" << q[0] << " " << q[1] << " " << q[2] << " " << q[3] << "]";
	return os;
};


PIAVCA_DECL std::istream &operator>>(std::istream &is, Piavca::Quat &q)
{
	while(is.peek() == ' ')
		is.ignore();
	if(is.peek() == '[')
		is.ignore();
	for (int i =0; i < 4; i++)
	{
		if(!(is >> q[i]))break;
		if(is.peek() == ',')
			is.ignore();
		if(is.peek() == ';')
			is.ignore();
	}
	if(is.peek() == ']')
		is.ignore();
	while(is.peek() == ' ')
		is.ignore();
	return is;
}
