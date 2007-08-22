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
 * The Original Code is Bound.cpp.
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

#include "Bound.h"

using namespace Piavca;

Bound::Bound()									
{
	min[0] = 0.0; 
	min[1] = 0.0; 
	min[2] = 0.0;
	max[0] = 0.0; 
	max[1] = 0.0; 
	max[2] = 0.0;
};
Bound::Bound(float x1, float y1, float z1, float x2, float y2, float z2)			
{
	min[0] = x1; 
	min[1] = y1; 
	min[2] = z1;
	max[0] = x2; 
	max[1] = y2; 
	max[2] = z2;
};
Bound::Bound(const float u[3], const float v[3])					
{
	min[0] = u[0]; 
	min[1] = u[1]; 
	min[2] = u[2];
	max[0] = v[0]; 
	max[1] = v[1]; 
	max[2] = v[2];
};

Bound::Bound(const Bound &v)						
{
	*this = v;
};

	
Bound::~Bound()
{
};

const Bound Bound::operator+(const Bound &v) const	
{
	Bound retVal;
	retVal.min[0] = ((v.min[0] < min[0])? v.min[0] : min[0]);
	retVal.min[1] = ((v.min[1] < min[1])? v.min[1] : min[1]);
	retVal.min[2] = ((v.min[2] < min[2])? v.min[2] : min[2]);

	retVal.max[0] = ((v.max[0] > max[0])? v.max[0] : max[0]);
	retVal.max[1] = ((v.max[1] > max[1])? v.max[1] : max[1]);
	retVal.max[2] = ((v.max[2] > max[2])? v.max[2] : max[2]);
	return retVal;
};

const Bound &Bound::operator+=(const Bound &v)		
{
	min[0] = ((v.min[0] < min[0])? v.min[0] : min[0]);
	min[1] = ((v.min[1] < min[1])? v.min[1] : min[1]);
	min[2] = ((v.min[2] < min[2])? v.min[2] : min[2]);

	max[0] = ((v.max[0] > max[0])? v.max[0] : max[0]);
	max[1] = ((v.max[1] > max[1])? v.max[1] : max[1]);
	max[2] = ((v.max[2] > max[2])? v.max[2] : max[2]);
	return *this;
};

std::ostream &operator<<(std::ostream &os, const Bound &v)
{
	os << "[" << v.min << " " << v.max << "]";
	return os;
};


PIAVCA_DECL std::istream &operator>>(std::istream &is, Piavca::Bound &v)
{
	//Outer
	while(is.peek() == ' ')
		is.ignore();
	if(is.peek() == '[')
		is.ignore();

	//Min
	while(is.peek() == ' ')
		is.ignore();
	if(is.peek() == '[')
		is.ignore();
	for (int i =0; i < 3; i++)
	{
		is >> v.min[i];
		if(is.peek() == ',')
			is.ignore();
		if(is.peek() == ';')
			is.ignore();
	}
	if(is.peek() == ']')
		is.ignore();

	//Max
	while(is.peek() == ' ')
		is.ignore();
	if(is.peek() == '[')
		is.ignore();
	for (int i =0; i < 3; i++)
	{
		is >> v.max[i];
		if(is.peek() == ',')
			is.ignore();
		if(is.peek() == ';')
			is.ignore();
	}
	if(is.peek() == ']')
		is.ignore();
	while(is.peek() == ' ')
		is.ignore();

	//Outer
	if(is.peek() == ']')
		is.ignore();
	while(is.peek() == ' ')
		is.ignore();
	return is;
}

