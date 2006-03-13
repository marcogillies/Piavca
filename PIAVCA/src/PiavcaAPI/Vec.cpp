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
	return is;
}