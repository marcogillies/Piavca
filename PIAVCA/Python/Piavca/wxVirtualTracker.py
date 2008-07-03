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
# The Original Code is wxVirtualTracker.py
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
# ***** END LICENSE BLOCK ****

import Piavca


try:
	from OpenGL.GL import *
	from OpenGL.GLU import *
	from OpenGL.GLUT import *
	glPresent = True
except ImportError:
	glPresent = False

# This class is a virtual tracker represented as a sphere in the wxGL canvas. It can be moved around with the 
# keyboard/mouse
# useful for testing IK and similar code
class wxVirtualTracker (Piavca.CurrentValueMotion):
	def __init__(self, currentValMot=None):
		if currentValMot != None:
			Piavca.CurrentValueMotion.__init__(self, currentValMot)
		else:
			Piavca.CurrentValueMotion.__init__(self)
		self.setVecValue(Piavca.root_position_id, Piavca.Vec())
		
		self.loadToCanvas()
		self.radius = 10.0
		
		self.__disown__()
		
	def loadToCanvas(self):
		app = Piavca.getWXApp()
		canvas = app.getCanvas()
		if canvas:
			canvas.addPlugin(self)
			
			self.quad = gluNewQuadric()
			
			return True
		else:
			return False
	
	def clone(self):
		newMot = wxVirtualTracker(currentValMot=self)
		self.setVecValue(Piavca.root_position_id, self.getVecValueAtTime(Piavca.root_position_id, 0.0))
		return newMot
		
	def setPosition(self, pos):
		self.setVecValue(Piavca.root_position_id, pos)
		
	def getPosition(self):
		return self.getVecValueAtTime(Piavca.root_position_id, 0.0)
		
	def setRadius(self, rad):
		self.radius = rad
		
	def getRadius(self):
		return self.radius
		
	def render(self):
		v = self.getVecValueAtTime(Piavca.root_position_id, 0.0)
                print "rendering tracker at", v
		glPushMatrix()
		glTranslatef(v[0], v[1], v[2])
		#glBegin()
		gluSphere(self.quad, self.radius, 12, 12)
		#glEnd()
		glPopMatrix()
		
	def KeyEvent(self, key):
		print "Virtual Tracker key event", key
		v = self.getVecValueAtTime(Piavca.root_position_id, 0.0)
		print v
		if key == "d":
			v += Piavca.Vec.XAxis()*0.02*self.radius
		elif key == "a":
			v -= Piavca.Vec.XAxis()*0.02*self.radius
		elif key == "w":
			v += Piavca.Vec.YAxis()*0.02*self.radius
		elif key == "s":
			v -= Piavca.Vec.YAxis()*0.02*self.radius
		elif key == "q":
			v += Piavca.Vec.ZAxis()*0.02*self.radius
		elif key == "z":
			v -= Piavca.Vec.ZAxis()*0.02*self.radius
		print v
		self.setVecValue(Piavca.root_position_id, v)
              
