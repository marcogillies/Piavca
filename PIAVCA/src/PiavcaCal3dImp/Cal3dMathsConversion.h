/* LICENCE BLOCK
Cal3DMathsConversion.h
Copyright (C) 2005 Marco (Mark) Gillies

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include <limits>

//#include "PlatformDefs.h"
#include "PiavcaAPI/Quat.h"
#include "PiavcaAPI/Vec.h"

using Piavca::Vec;
using Piavca::Quat;

#include <cal3d/cal3d.h>


inline Vec CalVecToVec(const CalVector &cv) {
  return Vec(cv.x, cv.y, cv.z);
};

inline CalVector VecToCalVec(const Vec &v) {
  return CalVector(v[0], v[1], v[2]);
};

inline Quat CalQuatToQuat(const CalQuaternion &cq) {
  return Quat(cq.w, cq.x, cq.y, cq.z).inverse();
};

inline CalQuaternion QuatToCalQuat(const Quat &q) {
  Quat q1 = q.inverse();
  return CalQuaternion(q1.I(), q1.J(), q1.K(), q1.S());
};
