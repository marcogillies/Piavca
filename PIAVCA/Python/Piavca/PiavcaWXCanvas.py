

import Piavca

import wx
from wx.lib.dialogs import *
from wx import glcanvas

import thread

try:
	from OpenGL.GL import *
	from OpenGL.GLUT import *
	glPresent = True
except ImportError:
	glPresent = False




# Note that the following function doesn't actually initialise GLUT,
# it just causes a Piavca::PiavcaCal3DCore() object to be
# created. There should be a separate function to create a
# context-less OpenGL render core.

if glPresent:

	class PiavcaWXCanvasBase(glcanvas.GLCanvas):
		def __init__(self, parent):
			print "init canvas"
			glcanvas.GLCanvas.__init__(self, parent, -1)
			self.init = False
			# initial mouse position
			self.size = None
			self.Bind(wx.EVT_ERASE_BACKGROUND, self.OnEraseBackground)
			self.Bind(wx.EVT_SIZE, self.OnSize)
			self.Bind(wx.EVT_PAINT, self.OnPaint)
			self.Bind(wx.EVT_LEFT_DOWN, self.OnMouseDown)
			self.Bind(wx.EVT_LEFT_UP, self.OnMouseUp)
			self.Bind(wx.EVT_RIGHT_DOWN, self.OnMouseDown)
			self.Bind(wx.EVT_RIGHT_UP, self.OnMouseUp)
			self.Bind(wx.EVT_MIDDLE_DOWN, self.OnMouseDown)
			self.Bind(wx.EVT_MIDDLE_UP, self.OnMouseUp)
			self.Bind(wx.EVT_MOTION, self.OnMouseMotion)
			self.Bind(wx.EVT_CHAR, self.OnKeyboard)
			self.Bind(wx.EVT_IDLE, self.OnIdle)
			self.scaleBias = 1.0
			self.tracking = 1
			
			self.dragging = False
			
			self.axisFlag = False
			
			self.clear_colour = (0,0,0)
			
			self.plugins = []
			
		def setCurrent(self):
			if self.GetContext():
				self.SetCurrent()
				glViewport(0, 0, 640, 480)
			
		def setClearColour(self, r, g, b):
			self.clear_colour = (r,g,b)

		def OnEraseBackground(self, event):
			pass # Do nothing, to avoid flashing.

		def OnSize(self, event):
			size = self.size = self.GetClientSize()
			if size.width >=0 :
				width = size.width
			else:
				width = 0
			if size.height >=0 :
				height = size.height
			else:
				height = 0
			if self.GetContext():
				self.SetCurrent()
				glViewport(0, 0, width, height)
			event.Skip()

		def resize(self, size):
			pass

		def OnPaint(self, event):
			dc = wx.PaintDC(self)
			self.SetCurrent()
			if not self.init:
				self.InitGL()
				self.init = True
			self.OnDraw()

		def OnMouseDown(self, evt):
			self.CaptureMouse()
			x, y = evt.GetPosition()
			print "mouse down"
			if evt.LeftIsDown():
				print "right down"
				self.leftDown(x,y)
			elif evt.RightIsDown():
				print "right down"
				self.rightDown(x,y)
			elif evt.MiddleIsDown():
				print "niddle Down"
				self.middleDown(x,y)
		
		def leftDown(self, x, y):
			pass
		
		def rightDown(self, x, y):
			pass
		
		def middleDown(self, x, y):
			pass

		def OnMouseUp(self, evt):
			print "mouse up"
			self.dragging = False
			self.mouseUp()
			self.ReleaseMouse()

		def mouseUp(self):
			pass
				
		def OnMouseMotion(self, evt):
			if evt.Dragging():
				x, y = evt.GetPosition()
				if evt.LeftIsDown():
					self.dragging = True
					self.leftMove(x,y)
				elif evt.RightIsDown():
					self.dragging = True
					self.rightMove(x,y)
				elif evt.MiddleIsDown():
					self.dragging = True
					self.middleMove(x,y)
				else:
					self.mouseUpMove(x,y)
				self.Refresh(False)
		
		def leftMove(self, x, y):
			pass
		
		def rightMove(self, x, y):
			pass
		
		def middleMove(self, x, y):
			pass
		
		def mouseUpMove(self, x, y):
			pass

		def OnKeyboard(self, evt):
			try:
				char = chr(evt.KeyCode)
			except ValueError:
				print "KeyInput.KeyPressedCB not ASCII"
				return

			print "KeyInput.KeyPressedCB", char
			for plugin in self.plugins:
				if hasattr(plugin, "KeyEvent"):
					plugin.KeyEvent(char)
			
			
		def OnDraw(self):
			self.draw()

		def OnIdle(self, evt):
			self.draw()
			evt.RequestMore()

		def InitGL(self):
			self.custom_init()

			# set viewing projection
			glMatrixMode(GL_PROJECTION)
			glFrustum(-0.5, 0.5, -0.5, 0.5, 1.0, 1000.0)

			glMatrixMode(GL_MODELVIEW)

			glEnable(GL_DEPTH_TEST)
			glEnable(GL_LIGHTING)
			glEnable(GL_LIGHT0)
			glEnable(GL_NORMALIZE)
			self.initCameraPosition()
			
		def custom_init(self):
			pass

		def updateCameraPosition(self):
			pass

		def pushCameraPosition(self):
		   pass
			
		def popCameraPosition(self):
			pass
			
		def resetCameraPosition(self):
			pass
			
		def initCameraPosition(self):
			pass
			
		def axisOn(self):
			self.axisFlag = True
			
		def axisOff(self):
			self.axisFlag = False	
		
		def drawAxes(void):
			glScalef(50,50,50)
			glDisable(GL_LIGHTING)
			# Draw the x-axis in red
			glColor3f(1.0, 0.0, 0.0);
			glBegin(GL_LINES);
			glVertex3f(0,0,0);
			glVertex3f(1,0,0)
			glEnd()
			glBegin(GL_TRIANGLE_FAN)
			glVertex3f(1.0, 0.0,  0.0 )
			glVertex3f(0.8, 0.07, 0.0 )
			glVertex3f(0.8, 0.0,  0.07)
			glVertex3f(0.8,-0.07, 0.0 )
			glVertex3f(0.8, 0.0, -0.07)
			glVertex3f(0.8, 0.07, 0.0 )
			glEnd()
		
			# Draw the y-axis in green
			glColor3f(0.0, 1.0, 0.0)
			glBegin(GL_LINES)
			glVertex3f(0,0,0)
			glVertex3f(0,1,0)
			glEnd()
			glBegin(GL_TRIANGLE_FAN)
			glVertex3f( 0.0,  1.0, 0.0 )
			glVertex3f( 0.07, 0.8, 0.0 )
			glVertex3f( 0.0,  0.8, 0.07)
			glVertex3f(-0.07, 0.8, 0.0 )
			glVertex3f( 0.0,  0.8,-0.07)
			glVertex3f( 0.07, 0.8, 0.0 )
			glEnd()
		
			# Draw the z-axis in blue
			glColor3f(0.0, 0.0, 1.0)
			glBegin(GL_LINES)
			glVertex3f(0,0,0)
			glVertex3f(0,0,1)
			glEnd()
			glBegin(GL_TRIANGLE_FAN)
			glVertex3f( 0.0,  0.0,  1.0)
			glVertex3f( 0.07, 0.0,  0.8)
			glVertex3f( 0.0,  0.07, 0.8)
			glVertex3f(-0.07, 0.0,  0.8)
			glVertex3f( 0.0, -0.07, 0.8)
			glVertex3f( 0.07, 0.0,  0.8)
			glEnd()
			glEnable(GL_LIGHTING)
					
		def drawCustomElements(self):
			pass
		
		def draw(self):
			if self.tracking:
				self.updateCameraPosition()

			# clear color and depth buffers
			glClearColor(self.clear_colour[0], self.clear_colour[1], self.clear_colour[2], 1)
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
			glMatrixMode(GL_MODELVIEW)
			glLoadIdentity()
			self.pushCameraPosition()

			self.drawCustomElements()
			
			#timestep
			Piavca.Core.getCore().timeStep();
		
			self.renderPlugins()
		
			#updates mesh
			Piavca.Core.getCore().prerender();
			
			# render the model
			Piavca.Core.getCore().render();

			if self.axisFlag:
				self.drawAxes()
			self.popCameraPosition()
			self.SwapBuffers()
			
		# plugins system 
		def addPlugin(self, plugin):
			self.plugins.append(plugin)
			
		def renderPlugins(self):
			for plugin in self.plugins:
				plugin.render()
				
else:
	PiavcaWXCanvasBase = None
