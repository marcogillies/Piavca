
import Piavca

import wx
from wx.lib.dialogs import *
from wx import glcanvas

import thread

from OpenGL.GL import *
from OpenGL.GLUT import *
from gltb import *

import PiavcaWXCanvas


class FreeCameraCanvas(PiavcaWXCanvas.PiavcaWXCanvasBase):
	rot_sensitivity = 0.01
	trans_sensitivity = 1.0
	
	def __init__(self, parent, initial_position = Piavca.Vec(), initial_rotation = Piavca.Quat()):
		PiavcaWXCanvas.PiavcaWXCanvasBase.__init__(self, parent)
		self.cameraPos = initial_position
		self.cameraRot = initial_rotation
		self.cameraPitch = 0.0
		self.cameraYaw = 0.0
		
		self.positionCallbacks = []
		
	def setPosition(self, v):
		self.cameraPos = v
		self.updatePositionCallback()
		
	def calcRotation(self):
		self.cameraRot = Piavca.Quat(self.cameraPitch, Piavca.Vec_XAxis())
		self.cameraRot = Piavca.Quat(self.cameraYaw, Piavca.Vec_YAxis())*self.cameraRot
		
	def setPitch(self, a):
		self.cameraPitch = a
		print "set pitch", self.cameraPitch
		self.calcRotation()
		self.updatePositionCallback()

	def setYaw(self, a):
		self.cameraYaw = a
		self.calcRotation()
		self.updatePositionCallback()

	def pushCameraPosition(self):
		angle = self.cameraRot.getAngle()
		axis = self.cameraRot.getAxis()
		glRotatef(Piavca.radToDeg(angle), axis[0], axis[1], axis[2])
	   	glTranslatef(self.cameraPos[0], self.cameraPos[1], self.cameraPos[2])

	def leftDown(self, x, y):
		#print "left down..."
		self.prevX, self.prevY = x, y
		
	def rightDown(self, x, y):
		#print "right down..."
		self.prevX, self.prevY = x, y
		print self.prevX, self.prevY
		
	def middleDown(self, x, y):
		#print "right down..."
		self.prevX, self.prevY = x, y
		print self.prevX, self.prevY
		
	def leftMove(self, x, y):
		#print "left button dragging", x, y
		if hasattr(self, "prevX"):
			self.cameraYaw += self.rot_sensitivity*(x-self.prevX)
			self.cameraPitch += self.rot_sensitivity*(y-self.prevY)
			self.calcRotation()
			self.updatePositionCallback()
			print self.cameraYaw, self.cameraPitch
		self.prevX, self.prevY = x, y
		
	def rightMove(self, x, y):
		#print "right butting dragging", x, y, self.prevX, self.prevY
		if hasattr(self, "prevX"):
			trans = Piavca.Vec(0.0, 0.0, (y-self.prevY))
			trans = trans*self.trans_sensitivity
			trans = self.cameraRot.inverse().transform(trans)
			self.cameraPos = self.cameraPos + trans
			self.updatePositionCallback()
			print self.cameraPos
		self.prevX, self.prevY = x, y
		
	def middleMove(self, x, y):
		#print "right butting dragging", x, y, self.prevX, self.prevY
		if hasattr(self, "prevX"):
			trans = Piavca.Vec((x-self.prevX), -(y-self.prevY), 0.0)
			trans = trans*self.trans_sensitivity
			trans = self.cameraRot.inverse().transform(trans)
			self.cameraPos = self.cameraPos + trans
			self.updatePositionCallback()
			print self.cameraPos
		self.prevX, self.prevY = x, y
		
	def updatePositionCallback(self):
		print "updating callbacks"
		for cb in  self.positionCallbacks:
			print cb
			cb(self.cameraPos, self.cameraRot)
		
	def loadPositionCallback(self, cb):
		self.positionCallbacks.append(cb)		