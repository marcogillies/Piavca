# ***** BEGIN LICENSE BLOCK *****
# Version: MPL 1.1/GPL 2.0/LGPL 2.1
#
# The contents of this file are subject to the Mozilla Public License Version
# 1.1 (the "License"); you may not use this file except in compliance with
# the License. You may obtain a copy of the License at
# http://www.mozilla.org/MPL/
#
# Software distributed under the License is distributed on an "AS IS" basis,
# WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
# for the specific language governing rights and limitations under the
# License.
#
# The Original Code is __________________________________________.
#
# The Initial Developer of the Original Code is
# ____________________________________________.
# Portions created by the Initial Developer are Copyright (C) 2___
# the Initial Developer. All Rights Reserved.
#
# Contributor(s):
#
# Alternatively, the contents of this file may be used under the terms of
# either the GNU General Public License Version 2 or later (the "GPL"), or
# the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
# in which case the provisions of the GPL or the LGPL are applicable instead
# of those above. If you wish to allow use of your version of this file only
# under the terms of either the GPL or the LGPL, and not to allow others to
# use your version of this file under the terms of the MPL, indicate your
# decision by deleting the provisions above and replace them with the notice
# and other provisions required by the GPL or the LGPL. If you do not delete
# the provisions above, a recipient may use your version of this file under
# the terms of any one of the MPL, the GPL or the LGPL.
#
# ***** END LICENSE BLOCK *****
from math import fabs, sin, cos, acos

import Piavca


class TangentSpace:
	def __init__(self, p):
		self.coordAxes = 4*[Piavca.Quat()]
		if type(p) == type(Piavca.Quat()):
			self._calcCoordAxes(p)
			return
		q = Piavca.Quat(0.0, 0.0, 0.0, 0.0)
		for val in p:
			if(val[0] < 0.0):
				 val = Piavca.Quat(-val[0], -val[1], -val[2], -val[3])
			q[0] += val[0]/len(p)
			q[1] += val[1]/len(p)
			q[2] += val[2]/len(p)
			q[3] += val[3]/len(p)	
		q.normalise()

		u = Piavca.Vec(0.0, 0.0, 0.0)
		count = 0;
		while 1:
			if count > 500 :
				raise u
			count += 1

			self._calcCoordAxes(q)
			u = Piavca.Vec()
			for val in p:
				val = self.logMap(val)
				u += val/len(p)
			q = self.expMap(u);
			#print "curent iter",  u, q

			if u.mag() < 0.00001: 
				break
		self._calcCoordAxes(q)
			

	def _dot(self, a, b):
		return a[0]*b[0] + a[1]*b[1] + a[2]*b[2] + a[3]*b[3]

	def _cross(self, q1, q2, q3):
		q = Piavca.Quat()
		q[0] =	 q1[1]*(q2[2]*q3[3] - q2[3]*q3[2]) 
		q[0] -=  q1[2]*(q2[1]*q3[3] - q2[3]*q3[1]) 
		q[0] +=  q1[3]*(q2[1]*q3[2] - q2[2]*q3[1])

		q[1] =	-q1[0]*(q2[2]*q3[3] -  q2[3]*q3[2]) 
		q[1] +=  q1[2]*(q2[0]*q3[3] - q2[3]*q3[0]) 
		q[1] -=  q1[3]*(q2[0]*q3[2] - q2[2]*q3[0])

		q[2] =	 q1[0]*(q2[1]*q3[3] - q2[3]*q3[1]) 
		q[2] -=  q1[1]*(q2[0]*q3[3] - q2[3]*q3[0]) 
		q[2] +=  q1[3]*(q2[1]*q3[0] - q2[0]*q3[1])

		q[3] =	-q1[0]*(q2[1]*q3[2] - q2[2]*q3[1]) 
		q[3] +=  q1[1]*(q2[0]*q3[2] - q2[2]*q3[0]) 
		q[3] -=  q1[2]*(q2[0]*q3[1] - q2[1]*q3[0])
		return q

	# calculates a set of coordinate axes. The first axis is q
	# and the other three are orthogonal to it. The basic way of doing 
	# this is to swap the S/I and J/K values of q negating one of them
	# to get two orthogonal axes and then cross these 3 axes
	# to get the remaining one.
	# This fails if either both S and I or  J and K are zero, if so 
	# two of the axes are either the S/I or J/K axes and the last is
	# got with the swap and negate method on the non-zero pair. As 
	# q is unit lenght only one of the pairs can be zero
	def _calcCoordAxes (self, q):
		self.coordAxes[0] = q
		if(fabs(q[0]) < 0.0001 and fabs(q[1]) < 0.0001) :
			self.coordAxes[1] = Piavca.Quat(1.0, 0.0, 0.0, 0.0)
			self.coordAxes[2] = Piavca.Quat(0.0, 1.0, 0.0, 0.0)
			self.coordAxes[3] = Piavca.Quat(0.0, 0.0, q[3], -q[2])
			self.coordAxes[3].normalise()
			return
		if(fabs(q[2]) < 0.0001 and fabs(q[3]) < 0.0001):
			self.coordAxes[1] = Piavca.Quat(q[1], -q[0], 0.0, 0.0) 
			self.coordAxes[1].normalise();
			self.coordAxes[2] = Piavca.Quat(0.0, 0.0, 1.0, 0.0)
			self.coordAxes[3] = Piavca.Quat(0.0, 0.0, 0.0, 1.0)
			return

		self.coordAxes[1] = Piavca.Quat(q[1], -q[0], 0.0, 0.0)
		self.coordAxes[1].normalise()
		self.coordAxes[2] = Piavca.Quat(0.0, 0.0, q[3], -q[2])
		self.coordAxes[2].normalise()
		self.coordAxes[3] = self._cross(self.coordAxes[0], self.coordAxes[1], self.coordAxes[2])
		self.coordAxes[3].normalise()

	
	# exponential map (maps from tangent plane to sphere)
	def expMap(self, p):
		theta = p.mag();

		if(fabs(theta) < 0.00001):
			convFactor = 0.0
		else:
			convFactor = sin(theta)/theta
		p1 = Piavca.Quat() 
		p2 = Piavca.Quat()
		p1[0] = cos (theta);
		p1[1] = p[0]*convFactor
		p1[2] = p[1]*convFactor
		p1[3] = p[2]*convFactor

		p2[0]  = p1[0]*self.coordAxes[0][0] + p1[1]*self.coordAxes[1][0] 
		p2[0] += p1[2]*self.coordAxes[2][0] + p1[3]*self.coordAxes[3][0]

		p2[1]  = p1[0]*self.coordAxes[0][1] + p1[1]*self.coordAxes[1][1] 
		p2[1] += p1[2]*self.coordAxes[2][1] + p1[3]*self.coordAxes[3][1]

		p2[2]  = p1[0]*self.coordAxes[0][2] + p1[1]*self.coordAxes[1][2] 
		p2[2] += p1[2]*self.coordAxes[2][2] + p1[3]*self.coordAxes[3][2]

		p2[3]  = p1[0]*self.coordAxes[0][3] + p1[1]*self.coordAxes[1][3] 
		p2[3] += p1[2]*self.coordAxes[2][3] + p1[3]*self.coordAxes[3][3]

		return p2

	# logorithmic map (maps from sphere to tangent plane)
	def logMap(self, q):
		p1 = q
		if(p1[0] < 0.0):
			p1 = Piavca.Quat(-p1[0], -p1[1], -p1[2], -p1[3])
		
		p2 = Piavca.Quat(self._dot(p1, self.coordAxes[0]),
			self._dot(p1, self.coordAxes[1]),
			self._dot(p1, self.coordAxes[2]),
			self._dot(p1, self.coordAxes[3]))
		p2.normalise()

		theta = acos(p2[0]);
		if(fabs(theta) < 0.0001):
			convFactor = 0.0
		else: 
			convFactor = theta/sin(theta)
		return Piavca.Vec(p2[1]*convFactor, p2[2]*convFactor, p2[3]*convFactor)

	def mean(self):
		return self.coordAxes[0]



	
