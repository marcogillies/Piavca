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



class PositionHandler:
	def __init__(self):
		Piavca.Core.getCore().addJointNameSet(["OtherPosition"])
		self.shiftMotions = []
		self.paramMotions = []
		self.Motion = None
		self.cvm = Piavca.CurrentValueMotion()
		self.jointId = Piavca.Core.getCore().getJointId("OtherPosition")
		self.cvm.setVecValue(self.jointId, Piavca.Vec())
		self.alreadyShifted = False
		
	def addMotion(self, m):
		pm = Piavca.ParameterMotion(m, self.cvm)
		if self.Motion == None:
			self.Motion = pm
		else:
			self.Motion = Piavca.MotionAdder(self.Motion, pm)
		self.paramMotions.append(pm)
		
	def addShiftMotion(self, m):
		if self.Motion == None:
			self.Motion = m
		else:
			self.Motion = Piavca.MotionAdder(self.Motion, m)
		self.shiftMotions.append(m)
		
	def setPosition(self, p):
		#print "setting position ", p
		oldPos = Piavca.Vec()#self.cvm.getVecValueAtTime(self.jointId, 0)
		diff = p - oldPos
		if abs(diff.mag()) > 0.01:
			if not self.alreadyShifted:
				self.alreadyShifted = True
				for m in self.shiftMotions:
					print m
					m.reset()
		else:
			self.alreadyShifted = False
		self.cvm.setVecValue(self.jointId, p)

	def getMotion(self):
		return self.Motion
		