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
 * The Original Code is Quat.h.
 *
 * The Initial Developer of the Original Code is Marco (Mark) Gillies.
 * Portions created by the Initial Developer are Copyright (C) BT plc. 2004
 * All Rights Reserved.
 *
 * ***** END LICENSE BLOCK ***** */


#ifndef QUAT_H
#define QUAT_H

#include "PiavcaDefs.h"
#include "Vec.h"

namespace Piavca
{

//! A Quaternion class
/*!
 *	Quaternions are representations of rotations that have a number of advantages over other representation.
 *	They are rather complicated but if you just want to use them as rotations this library should be quite 
 *	simple, you can set them from a rotation angle and axis (either via a constructor or the setAngleAxis method)
 *	and then use the various methods. To concatenate rotation multiply them together, with the first rotation
 *	to be applied coming second in the multiplication. To rotate a vector use the transform methods. To interpolate
 *	quaternions use the slerp function.
 *
 *	I won't talk too much about the internals there are plenty of good references on quaternions (just look on 
 *	the net). Briefly a quaternion has four compontents, the last three of which are proportional to the 
 *	axis of rotation. All the components also depend on the angle. The quaternions always have to have a 
 *	magnitude of one to represent a valid rotation.
 */
class PIAVCA_DECL Quat
{
	float vals[4];
public:
	//! default constructor creates a zero rotation quaternion.
	Quat();
	Quat(float s, float i, float j, float k);
	Quat(const float q[4]);
	//! a constuctor from angle axis representation of a rotation
	Quat(float Angle, const Vec &Axis);

	Quat(const Quat &q);
	const Quat &operator=(const Quat &q)
	{
		S() = q.S(); 
		I() = q.I(); 
		J() = q.J(); 
		K() = q.K(); 
		return (*this);
	};

	~Quat(){};

	//! \name inline methods as access to components
	//!@{
	const float &S() const					{return vals[0];}; //!< depends only on the angle
	const float &I() const					{return vals[1];}; //!< depends on the angle & X-component of the axis
	const float &J() const					{return vals[2];}; //!< depends on the angle & Y-component of the axis
	const float &K() const					{return vals[3];}; //!< depends on the angle & Z-component of the axis
	
	float &S()								{return vals[0];}; //!< depends only on the angle
	float &I()								{return vals[1];}; //!< depends on the angle & X-component of the axis
	float &J()								{return vals[2];}; //!< depends on the angle & Y-component of the axis
	float &K()								{return vals[3];}; //!< depends on the angle & Z-component of the axis
	//!@}

	//! access members by index
	float &operator[](int i)				{return vals[i];};
	//! access members by index
	const float &operator[](int i) const 	{return vals[i];};


	//! set the value of the Quat from the angle axis rotation representation
	void setAngleAxis(float Angle, const Vec &Axis)	
	{
		setAngleAxis(Angle, Axis.X(), Axis.Y(), Axis.Z());
	};
	//! set the value of the Quat from the angle axis rotation representation
	void setAngleAxis(float Angle, float x, float y, float z);
	//! get rotation as an angle and an axis
	void getAngleAxis(float &Angle, Vec &Axis) const;
	//! get the rotation angle (more efficient that getting angle and axis)
	float getAngle()const;
	//! get the axis of rotation (a convenience function)
	Vec getAxis()const{Vec axis; float angle; getAngleAxis(angle, axis); return axis;};

	
	//! get the rotation as a set of Euler angles
	void getEulerAngles(float &X, float &Y, float &Z);

	//! get the component of the rotation about the X-axis
	float Xangle();
	//! get the component of the rotation about the Y-axis
	float Yangle();
	//! get the component of the rotation about the Z-axis
	float Zangle();

	//! set the Quat to the quaternion that would rotate original so it points in the direction of desired
	Quat &pointAt(const Vec &original, const Vec &desired);

	//! \name Algebraic operators
	//!@{
	//! multiplication
	/*!
	 *	Used to concatenate two rotations, the first two be applied goes on the right.
	 */
	const Quat operator*(const Quat &q) const;
	//! multiplication
	/*!
	 *	Used to concatenate two rotations, the first two be applied goes on the rhs.
	 */
	const Quat &operator*=(const Quat &q)		
	{
		(*this) = (*this)*q; 
		return (*this);
	};
	//! division
	/*!
	 *	equivalent to multiplication by the inverse, can be used to remove a component 
	 *	of a rotation
	 */ 
	const Quat operator/(const Quat &q) const 	
	{
		return (*this)*q.inverse();
	};
	//! division
	/*!
	 *	equivalent to multiplication by the inverse, can be used to remove a component 
	 *	of a rotation
	 */ 
	const Quat &operator/=(const Quat &q)		
	{
		(*this) = (*this)/q; 
		return (*this);
	};
	//!@}

	//! \name comparison operators
	//@{
	bool operator==(const Quat &q)	const		
	{
		return S() == q.S() && I() == q.I() && J() == q.J() && K() == q.K();
	};
	bool operator!=(const Quat &q)	const 		
	{
		return !((*this) == q);
	};
	//@}

	//! scales a quaternion by a float value
	/*!
	 *	Not the same as just multiplying. It scales the angle without affecting the axis.
	 */
	void Scale(float f);

	//! returns the inverse of the Quat while leaving it unchanged. (The inverse gives the oppostite rotation)
	Quat inverse() const						
	{
		return Quat(S(), -I(), -J(), -K());
	};
	//! inverts the quaternion in place. (The inverse gives the oppostite rotation)
	void invert()								
	{
		I() = -I(); 
		J() = - J(); 
		K() = -K();
	};

	//! normalizes the quaternion in place
	void normalise();

	//! trasform (rotate) a vector by the quaternion
	Vec transform(const Vec &v)	const			
	{
		Quat res = (*this)*Quat(0.0, v.X(), v.Y(), v.Z())*inverse(); 
		return Vec(res.I(), res.J(), res.K());
	};
	//! trasform (rotate) a vector by the quaternion in place
	void transformInPlace(Vec &v) const 		
	{
		v = transform(v);
	};

	//! interpolates two quaternions
	friend PIAVCA_DECL Quat slerp(const Quat &q1, const Quat &q2, float t);
};

PIAVCA_DECL Quat slerp(const Quat &q1, const Quat &q2, float t);

};

#include <iostream>

PIAVCA_DECL std::ostream &operator<<(std::ostream &os, const Piavca::Quat &q);
PIAVCA_DECL std::istream &operator>>(std::istream &is, Piavca::Quat &q);

#endif //QUAT_H
