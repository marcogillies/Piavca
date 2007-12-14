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
# The Original Code is ParameterMotion.py
#
# The Initial Developer of the Original Code is
#  Marco Gillies
# Portions created by the Initial Developer are Copyright (C) 2007
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

import Piavca
import types

class ParameterMotion (Piavca.MotionFilter):
	def __init__(self, filterMot=None, parameterMot=None):
		if filterMot == None:
			Piavca.MotionFilter.__init__(self)
		else:
			Piavca.MotionFilter.__init__(self, filterMot)
		self.parameterLookup = []
		self.fMot = filterMot
		self.setParameterMot(parameterMot)
		
	def clone(self):
		new_mot = ParameterMotion(self, self.fMot, self.parameterMot)
		
	def setMotion(self, mot):
		self.parameterLookup = []
		MotionFilter.setMotion(self, mot)
		self.fMot = mot
		if self.parameterMot != None and self.getMotion() != None:
			self.setUpParameters()
		
	def setParameterMot(self, parameterMot):
		self.parameterLookup = []
		self.parameterMot = parameterMot
		if self.parameterMot != None and self.getMotion() != None:
			self.setUpParameters()
			
	def setUpParameters(self):
		self.parameterLookup = []
	
		# find all subtypes
		motiontypes = [type(self.fMot)]
		for key in Piavca.__dict__.keys():
			if type(Piavca.__dict__[key]) == types.TypeType and isinstance(self.fMot, Piavca.__dict__[key]):
				motiontypes.append(Piavca.__dict__[key])
		
		for mtype in motiontypes:
			for key in mtype.__dict__.keys():
				if key[:3] == "set":
					print key
					jointId = Piavca.Core.getCore().getJointId(key[3:])
					if not self.parameterMot.isNull(jointId):
						print key[3:]	
						method = getattr(self.fMot, key)
						self.parameterLookup.append((jointId, key, method))
						
		print self.parameterLookup
						
	def preFrame(self, t):
		#print "parameter motion preframe"
		for jointId, name, method in self.parameterLookup:
			#print "setting attribute", jointId, name, method
			type = self.parameterMot.getTrackType(jointId)
			#print "motion type", type
			if type & Piavca.FLOAT_TYPE:
				try:
					#print "setting float attribute", jointId, name, method
					value = self.parameterMot.getFloatValueAtTime(jointId, t)
					method(value)
					continue
				except:
					pass
			if type & Piavca.VEC_TYPE:
				try:
					#print "setting vec attribute", jointId, name, method
					value = self.parameterMot.getVecValueAtTime(jointId, t)
					method(value)
					continue
				except:
					pass
			if type & Piavca.QUAT_TYPE:
				try:
					#print "setting quat attribute", jointId, name, method
					value = self.parameterMot.getQuatValueAtTime(jointId, t)
					method(value)
					continue
				except:
					pass
			raise AttributeError("could not call method " + name)
				
		Piavca.MotionFilter.preFrame(self, t)

		
