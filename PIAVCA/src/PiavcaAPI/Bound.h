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
 * The Original Code is Bound.h.
 *
 * The Initial Developer of the Original Code is Anthony Steed.
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
 *
 * ***** END LICENSE BLOCK ***** */

#ifndef PIAVCA_BOUND_H
#define PIAVCA_BOUND_H

#include "PiavcaDefs.h"
#include "Vec.h"

namespace Piavca{

//! a vector class
/*!
 *	This should be a fairly standard implementation of 3-space vectors, with most normal operations.
 *	They are represented as an array of three floats.
 */ 
class PIAVCA_DECL Bound
{
public:
	Vec min;
	Vec max;
	Bound();
	Bound(float x1, float y1, float z1, float x2, float y2, float z2);
	Bound(const float u[3], const float v[3]);
	Bound(const Bound &v);
	const Bound &operator=(const Bound &v)		
	{
		min = v.min;
		max = v.max;
		return (*this);
	};

	~Bound();

	//! \name Algebraic operators
	//!@{
	const Bound operator+(const Bound &v) const;
	const Bound &operator+=(const Bound &v);
	//!@}

	//! \name comparison operators
	//!@{
	bool operator==(const Bound &v)const {return min == v.min && max == v.max;};
	bool operator!=(const Bound &v)const {return !((*this) == v);};
	//!@}
};



inline bool checkNaN(Bound &v)
{
	return checkNaN(v.min) || checkNaN(v.max) ;
}

};


#include <iostream>

PIAVCA_DECL std::ostream &operator<<(std::ostream &os, const Piavca::Bound &v);
PIAVCA_DECL std::istream &operator>>(std::istream &is, Piavca::Bound &v);


#endif //PIAVCA_BOUND_H
