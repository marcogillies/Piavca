#! /usr/bin/env python

import sys
import os
import time

import Piavca
#Piavca.PiavcaGlut.init(Piavca.Core.getCorePointerAsLong())
import Piavca.JointNames
Piavca.JointNames.loadDefaults()

import Piavca.ViewerCanvas


import wx
from wx.lib.dialogs import *
#from wx import glcanvas

#import thread
#
#from OpenGL.GL import *
#from OpenGL.GLUT import *
#from gltb import *
#
## Note that the following function doesn't actually initialise GLUT,
## it just causes a Piavca::PiavcaCal3DCore() object to be
## created. There should be a separate function to create a
## context-less OpenGL render core.
#
#
#class MyCanvasBase(glcanvas.GLCanvas):
#	def __init__(self, parent):
#		print "init canvas"
#		glcanvas.GLCanvas.__init__(self, parent, -1)
#		self.init = False
#		# initial mouse position
#		self.size = None
#		self.Bind(wx.EVT_ERASE_BACKGROUND, self.OnEraseBackground)
#		self.Bind(wx.EVT_SIZE, self.OnSize)
#		self.Bind(wx.EVT_PAINT, self.OnPaint)
#		self.Bind(wx.EVT_LEFT_DOWN, self.OnMouseDown)
#		self.Bind(wx.EVT_LEFT_UP, self.OnMouseUp)
#		self.Bind(wx.EVT_MOTION, self.OnMouseMotion)
#		self.Bind(wx.EVT_IDLE, self.OnIdle)
#		self.scaleBias = 1.0
#		self.tracking = 1
#
#	def OnEraseBackground(self, event):
#		pass # Do nothing, to avoid flashing.
#
#	def OnSize(self, event):
#		size = self.size = self.GetClientSize()
#		if self.GetContext():
#			self.SetCurrent()
#			glViewport(0, 0, size.width, size.height)
#			gltbReshape(size.width, size.height)
#		event.Skip()
#
#	def OnPaint(self, event):
#		dc = wx.PaintDC(self)
#		self.SetCurrent()
#		if not self.init:
#			self.InitGL()
#			self.init = True
#		self.OnDraw()
#
#	def OnMouseDown(self, evt):
#		self.CaptureMouse()
#		x, y = evt.GetPosition()
#		if evt.LeftIsDown():
#			gltbMouseDown(x, y)
#
#	def OnMouseUp(self, evt):
#		gltbMouseUp()
#		self.ReleaseMouse()
#
#	def OnMouseMotion(self, evt):
#		if evt.Dragging() and evt.LeftIsDown():
#			x, y = evt.GetPosition()
#			gltbMotion(x, y)
#			self.Refresh(False)
#
#	def OnDraw(self):
#		self.draw()
#
#	def OnIdle(self, evt):
#		self.draw()
#		evt.RequestMore()
#
#	def InitGL(self):
#		gltbInit()
#		gltbAnimate(GL_FALSE)
#		gltbConfigUp(0,0,1)
#
#		# set viewing projection
#		glMatrixMode(GL_PROJECTION)
#		glFrustum(-0.5, 0.5, -0.5, 0.5, 1.0, 1000.0)
#
#		glMatrixMode(GL_MODELVIEW)
#
#		glEnable(GL_DEPTH_TEST)
#		glEnable(GL_LIGHTING)
#		glEnable(GL_LIGHT0)
#		glEnable(GL_NORMALIZE)
#		self.initCameraFocus()
#
#	def updateCameraFocus(self):
#		avatar = Piavca.Core.getCore().getAvatar(0)
#		self.initialAvatarBound = avatar.getBaseBoundBox()
#		self.initialAvatarRoot = avatar.getRootPosition()
#
#		self.focusRoot = avatar.getRootPosition()
#		self.focusBound = avatar.getBaseBoundBox();
#		self.focusBound.min = self.initialAvatarBound.min+self.focusRoot-self.initialAvatarRoot;
#		self.focusBound.max = self.initialAvatarBound.max+self.focusRoot-self.initialAvatarRoot;
#
#	def pushCameraFocus(self):
#	   	centre = (self.focusBound.min+self.focusBound.max)/2.0
#		halfWidths = self.focusBound.max - centre
#		maxDim = max(max(halfWidths[0],halfWidths[1]), halfWidths[2]) 
#	
#		glTranslatef(0.0, 0.0, -3.0)
#		gltbMatrix(1.0)
#		glPushMatrix()
#		glScalef(self.scaleBias/maxDim, self.scaleBias/maxDim, self.scaleBias/maxDim)
#		glPushMatrix()
#		glTranslatef(-centre[0],-centre[1],-centre[2])
#		
#	def popCameraFocus(self):
#		glPopMatrix()
#		glPopMatrix()
#		
#	def resetCameraFocus(self):
#		self.scaleBias = 1.0
#		
#	def initCameraFocus(self):
#		avatar = Piavca.Core.getCore().getAvatar(0)
#		self.initialAvatarBound = avatar.getBaseBoundBox()
#		self.initialAvatarRoot = avatar.getRootPosition()
#		self.updateCameraFocus()
#		
#	def drawAxes(void):
#		glScalef(50,50,50)
#		glDisable(GL_LIGHTING)
#		# Draw the x-axis in red
#		glColor3f(1.0, 0.0, 0.0);
#		glBegin(GL_LINES);
#		glVertex3f(0,0,0);
#		glVertex3f(1,0,0)
#		glEnd()
#		glBegin(GL_TRIANGLE_FAN)
#		glVertex3f(1.0, 0.0,  0.0 )
#		glVertex3f(0.8, 0.07, 0.0 )
#		glVertex3f(0.8, 0.0,  0.07)
#		glVertex3f(0.8,-0.07, 0.0 )
#		glVertex3f(0.8, 0.0, -0.07)
#		glVertex3f(0.8, 0.07, 0.0 )
#		glEnd()
#	
#		# Draw the y-axis in green
#		glColor3f(0.0, 1.0, 0.0)
#		glBegin(GL_LINES)
#		glVertex3f(0,0,0)
#		glVertex3f(0,1,0)
#		glEnd()
#		glBegin(GL_TRIANGLE_FAN)
#		glVertex3f( 0.0,  1.0, 0.0 )
#		glVertex3f( 0.07, 0.8, 0.0 )
#		glVertex3f( 0.0,  0.8, 0.07)
#		glVertex3f(-0.07, 0.8, 0.0 )
#		glVertex3f( 0.0,  0.8,-0.07)
#		glVertex3f( 0.07, 0.8, 0.0 )
#		glEnd()
#	
#		# Draw the z-axis in blue
#		glColor3f(0.0, 0.0, 1.0)
#		glBegin(GL_LINES)
#		glVertex3f(0,0,0)
#		glVertex3f(0,0,1)
#		glEnd()
#		glBegin(GL_TRIANGLE_FAN)
#		glVertex3f( 0.0,  0.0,  1.0)
#		glVertex3f( 0.07, 0.0,  0.8)
#		glVertex3f( 0.0,  0.07, 0.8)
#		glVertex3f(-0.07, 0.0,  0.8)
#		glVertex3f( 0.0, -0.07, 0.8)
#		glVertex3f( 0.07, 0.0,  0.8)
#		glEnd()
#		glEnable(GL_LIGHTING)
#
#
#	def drawFloor(self):
#		floorScale = 50.0
#		floorSize = 500.0
#
#		tmp = (self.focusBound.min+self.focusBound.max)/2.0;
#		centre = (round(tmp[0]/floorScale)*floorScale, round(tmp[1]/floorScale)*floorScale, self.focusBound.min[2] )
#	
#		cols = int(floorSize/floorScale);
#		color = 0;
#		glDisable(GL_LIGHTING);
#	
#		x = centre[0] - floorSize/2;
#		y = centre[1] - floorSize/2;
#		color = ((round(x/floorScale)) + (round(y/floorScale)))%2;
#
#		for i in range(cols):
#			color += ((cols+1)%2)
#			for j in range(cols):
#				color = color + 1
#				if color%2 == 0 :
#					glColor3f(0.5,0.5,0.5)
#				else:
#					glColor3f(0.75,0.75,0.75)
#	
#				glBegin(GL_QUADS)
#				glVertex3f(x,y,0)
#				glVertex3f(x+floorScale,y,0)
#				glVertex3f(x+floorScale,y+floorScale,0)
#				glVertex3f(x,y+floorScale,0)
#				glEnd()
#				y += floorScale
#			y = centre[1] - floorSize/2
#			x += floorScale
#		glEnable(GL_LIGHTING)
#	
#	def draw(self):
#		if self.tracking:
#			self.updateCameraFocus()
#
#		# clear color and depth buffers
#		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
#		glMatrixMode(GL_MODELVIEW)
#		glLoadIdentity()
#		self.pushCameraFocus()
#
#		self.drawFloor()
#		
#		#timestep
#		Piavca.Core.getCore().timeStep();
#	
#		#updates mesh
#		Piavca.Core.getCore().prerender();
#		
#		# render the model
#		Piavca.Core.getCore().render();
#
#		self.drawAxes()
#		self.popCameraFocus()
#		self.SwapBuffers()
#
#		
#class MyFrame(wx.Frame):
#	def __init__(
#			self, parent, ID, title, pos=wx.DefaultPosition,
#			size=wx.DefaultSize, style=wx.DEFAULT_FRAME_STYLE
#			):
#
#		wx.Frame.__init__(self, parent, ID, title, pos, size, style)
#		canvas = MyCanvasBase(self)
#		self.Bind(wx.EVT_CLOSE, self.OnCloseWindow)
#
#	def OnCloseWindow(self, event):
#		self.Destroy()
#
#
#class MyApp(wx.App):
#	def __init__(self):
#		wx.App.__init__(self, redirect=False, filename="PiavcaOut.txt")
#	def OnInit(self):
#		return True
#	def showWindows(self):
#		frame = MyFrame(None, -1, "Piavca Viewer", size=(400,400))
#		self.SetTopWindow(frame)
#		frame.Show(True)
#		return True

#app = wx.PySimpleApp()
#app = Piavca.PiavcaWXApp.PiavcaWXApp()
app = Piavca.getWXApp()
app.showWindows(canvastype = Piavca.ViewerCanvas.ViewerCanvas)

if len(sys.argv) > 1:
	path = sys.argv[1]
else:
	dialog_return = openFileDialog ()
	path = dialog_return.paths[0]

dirname = os.path.dirname(path)
os.chdir(dirname)

try:
	Piavca.JointNames.importJointNames("Joints.txt")
except IOError:
	print "could not open Joints file Joints.txt, will probably work anyway"
try:
	Piavca.JointNames.importExpressionNames("Expressions.txt")
except IOError:
	print "could not open Expressions file Expressions.txt, will probably work anyway"


(splitext, ext) = os.path.splitext(path)
print "filename", splitext, "extention", ext
if ext == ".conf":
	script_engine = ScriptEngine("character controller", filename, app)
else:
	if ext == ".cfg":
		basename = os.path.basename(splitext)
		avatar = Piavca.Avatar(str(basename))
	else:
		import Piavca.XMLMotionFile
		basename = os.path.basename(path)
		Piavca.XMLMotionFile.parse(basename)
		avatar = Piavca.Core.getCore().getAvatar(0)
		Piavca.setUpEventsGUI()

	print "loaded avatar"

	if len(sys.argv) > 2:
		motion_name = sys.argv[2]
	else:
		motnames = Piavca.Core.getCore().getMotionNames()
		print motnames
		dialog_return = singleChoiceDialog (lst=["None"]+motnames)
		motion_name = dialog_return.selection

	mot = Piavca.Core.getCore().getMotion(str(motion_name))
	if mot != None:
		mot.Reference()
		avatar.play_motion(Piavca.LoopMotion(mot))	
	avatar.play_motion(mot)	

	avatar.showMotionAtTime(Piavca.getTime())
		
	print "loaded motion"

	app.getCanvas().setAvatar(avatar)
	app.getCanvas().initCameraPosition()

#app = MyApp()

#import Piavca.redirect
#Piavca.redirect.redirect()

print "created app"

app.MainLoop()

