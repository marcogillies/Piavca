

import Piavca

import wx
from wx.lib.dialogs import *
from wx import glcanvas

import thread

from OpenGL.GL import *
from OpenGL.GLUT import *
from gltb import *

import PiavcaWXCanvas

# Note that the following function doesn't actually initialise GLUT,
# it just causes a Piavca::PiavcaCal3DCore() object to be
# created. There should be a separate function to create a
# context-less OpenGL render core.


class ViewerCanvas(PiavcaWXCanvas.PiavcaWXCanvasBase):
	def __init__(self, parent):
		PiavcaWXCanvas.PiavcaWXCanvasBase.__init__(self, parent)
		self.floorFlag = False
		self.prevY = None
		self.prevX = None
		self.verticalMove = 0.0
		self.horizontalMove = 0.0
		self.zoom = -3
		self.transSensitivity = 0.1
		if Piavca.Core.getCore().numAvatars() > 0:
			self.setAvatar(Piavca.Core.getCore().getAvatar(0))
		else:
			self.setAvatar(None)

	def setAvatar(self, avatar):
		self.avatar = avatar

	def custom_init(self):
		gltbInit()
		gltbAnimate(GL_FALSE)
		gltbConfigUp(0,0,1)

	def resize(self, size):
		gltbReshape(size.width, size.height)

	def leftDown(self, x, y):
		gltbMouseDown(x, y)

	def mouseUp(self):
		gltbMouseUp()
		self.prevX = None
		self.prevY = None
		
	def leftMove(self, x, y):
		gltbMotionRotateAboutFocus(x, y)
		
	def rightDown(self, x, y):
		self.prevY = y
		self.prevX = x
		
	def middleDown(self, x, y):
		self.prevY = y
		self.prevX = x

	def middleMove(self, x, y):
		if self.prevY != None:
			#print "mouse move"
			#print y - self.prevY, y, self.prevY
			self.verticalMove += -self.transSensitivity*(y-self.prevY)*0.2
			self.horizontalMove += self.transSensitivity*(x-self.prevX)*0.2
		self.prevY = y
		self.prevX = x

	def rightMove(self, x, y):
		if self.prevY != None:
			#print "mouse move"
			#print y - self.prevY, y, self.prevY
			self.zoom += -self.transSensitivity*(y-self.prevY)*0.2
		self.prevY = y

	def updateCameraPosition(self):
		avatar = self.avatar # Piavca.Core.getCore().getAvatar(0)
		if avatar:
			#self.initialAvatarBound = avatar.getBaseBoundBox()
			#self.initialAvatarRoot = avatar.getRootPosition()
	
			self.focusRoot = avatar.getRootPosition()
			self.focusBound = avatar.getBaseBoundBox();
		else:
			#self.initialAvatarBound = Piavca.Bound()
			#self.initialAvatarRoot = Piavca.Vec()
	
			self.focusRoot = Piavca.Vec()
			self.focusBound = Piavca.Bound()
			
#		print "initialAvatarRoot", self.initialAvatarRoot
#		print "initialAvatarBound", self.initialAvatarBound
#		print "focusRoot", self.focusRoot
#		print "focusBound", self.focusBound
		self.focusBound.min = self.initialAvatarBound.min+self.focusRoot-self.initialAvatarRoot;
		self.focusBound.max = self.initialAvatarBound.max+self.focusRoot-self.initialAvatarRoot;
#		print "focusBound", self.focusBound

	def pushCameraPosition(self):
	   	centre = (self.focusBound.min+self.focusBound.max)/2.0
		halfWidths = self.focusBound.max - centre
		maxDim = max(max(halfWidths[0],halfWidths[1]), halfWidths[2]) 
#		print "centre", centre
#		print "maxDim", maxDim
	
		glTranslatef(self.horizontalMove, self.verticalMove, self.zoom)
		#glTranslatef(0.0, 0.0, self.zoom)
		gltbMatrix()
		glPushMatrix()
		if maxDim > 0.00000001:
			glScalef(self.scaleBias/maxDim, self.scaleBias/maxDim, self.scaleBias/maxDim)
		glPushMatrix()
		glTranslatef(-centre[0],-centre[1],-centre[2])
		
	def popCameraPosition(self):
		glPopMatrix()
		glPopMatrix()
		
	def resetCameraPosition(self):
		self.scaleBias = 1.0
		
	def initCameraPosition(self):
		avatar = self.avatar # Piavca.Core.getCore().getAvatar(0)
		if avatar:
			self.initialAvatarBound = avatar.getBoundBox()#avatar.getBaseBoundBox()
			self.initialAvatarRoot = avatar.getRootPosition()
		else:
			self.initialAvatarBound = Piavca.Bound()
			self.initialAvatarRoot = Piavca.Vec()
			
		print "updating camera position, avatar root:", self.initialAvatarRoot
			
		self.updateCameraPosition()

	def floorOn(self):
		self.floorFlag = True

	def floorOff(self):
		self.floorFlag = True

	def drawFloor(self):
		floorScale = 50.0
		floorSize = 500.0

		tmp = (self.focusBound.min+self.focusBound.max)/2.0;
		centre = (round(tmp[0]/floorScale)*floorScale, round(tmp[1]/floorScale)*floorScale, self.focusBound.min[2] )
	
		cols = int(floorSize/floorScale);
		color = 0;
		glDisable(GL_LIGHTING);
	
		x = centre[0] - floorSize/2;
		y = centre[1] - floorSize/2;
		color = ((round(x/floorScale)) + (round(y/floorScale)))%2;

		for i in range(cols):
			color += ((cols+1)%2)
			for j in range(cols):
				color = color + 1
				if color%2 == 0 :
					glColor3f(0.5,0.5,0.5)
				else:
					glColor3f(0.75,0.75,0.75)
	
				glBegin(GL_QUADS)
				glVertex3f(x,y,0)
				glVertex3f(x+floorScale,y,0)
				glVertex3f(x+floorScale,y+floorScale,0)
				glVertex3f(x,y+floorScale,0)
				glEnd()
				y += floorScale
			y = centre[1] - floorSize/2
			x += floorScale
		glEnable(GL_LIGHTING)

		

	def drawCustomElements(self):
		if self.floorFlag:
			self.drawFloor()
