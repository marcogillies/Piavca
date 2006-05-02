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
 * The Original Code is Vec.cpp.
 *
 * The Initial Developer of the Original Code is Marco (Mark) Gillies.
 * Portions created by the Initial Developer are Copyright (C) BT plc. 2004
 * All Rights Reserved.
 *
 * ***** END LICENSE BLOCK ***** */


//#ifdef PIAVCA_DLL
//#define PIAVCA_EXPORT __declspec( dllexport ) 
//#else
//#define PIAVCA_EXPORT
//#endif

#include "Vec.h"

using namespace Piavca;

Vec::Vec()									
{
	vals[0] = 0.0; 
	vals[1] = 0.0; 
	vals[2] = 0.0;
};
Vec::Vec(float x, float y, float z)			
{
	vals[0] = x; 
	vals[1] = y; 
	vals[2] = z;
};
Vec::Vec(const float v[3])					
{
	vals[0] = v[0]; 
	vals[1] = v[1]; 
	vals[2] = v[2];
};

Vec::Vec(const Vec &v)						
{
	*this = v;
};

	
Vec::~Vec()
{
};

float Vec::mag()	const 						
{
	return sqrt(X()*X() + Y()*Y() + Z()*Z());
};

float Vec::dot(const Vec &v) const			
{
	return  X()*v.X() + Y()*v.Y() + Z()*v.Z();
};

 Vec Vec::cross(const Vec &v) const 
{
	Vec retVal;
	retVal.X() = Y()*v.Z() - Z()*v.Y();
	retVal.Y() = Z()*v.X() - X()*v.Z();
	retVal.Z() = X()*v.Y() - Y()*v.X();
	return retVal;
}


std::ostream &operator<<(std::ostream &os, const Vec &v)
{
	os << "[" << v[0] << " " << v[1] << " " << v[2] << "]";
	return os;
};


PIAVCA_DECL std::istream &operator>>(std::istream &is, Piavca::Vec &v)
{
	while(is.peek() == ' ')
		is.ignore();
	if(is.peek() == '[')
		is.ignore();
	for (int i =0; i < 3; i++)
	{
		is >> v[i];
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