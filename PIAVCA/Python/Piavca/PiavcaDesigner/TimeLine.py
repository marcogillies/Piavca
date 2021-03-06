
import wx

class TimeLine(wx.Panel):
	rangeStart = None

	def __init__(self, backend, parent=None, id=-1, pos=wx.DefaultPosition, size=wx.DefaultSize, style=0, name="TimeLine"):
		wx.Panel.__init__(self, parent, id, pos, size, style, name)
		
		self.backend = backend
		
		self.Bind(wx.EVT_IDLE, self.OnIdle)
		self.Bind(wx.EVT_PAINT, self.OnPaint)
		self.Bind(wx.EVT_SIZE, self.OnResize)
		#self.Bind(wx.EVT_LEFT_DOWN, self.OnMouseDown)
		self.Bind(wx.EVT_LEFT_UP, self.OnMouseUp)
		self.Bind(wx.EVT_LEFT_DOWN, self.OnMouseDown)
		self.Bind(wx.EVT_MOTION, self.OnMouseMove)
		
	def OnIdle(self, event):
		self.drawToBuffer()
		self.Refresh(False)
		
	def drawToBuffer(self):
		size = self.GetClientSize()
		self.buffer = wx.EmptyBitmap(size.width, size.height)
		dc = wx.BufferedDC(None, self.buffer)
		dc.SetBackground(wx.Brush("light gray"))
		dc.Clear()
		
		self.drawRange(dc)
		self.drawFrames(dc)
		self.drawTime(dc)
		
	def drawRange(self, dc):
		size = self.GetClientSize()
		range = self.backend.getRangeFraction()
		#print "drawing range", range
		# get rid of rally big ranges, as they crash DrawRectagle
		if (range[1] - range[0]) > 30000:
			#print range[1], range[0]
			range = (range[0], 30000 + range[0]) 
		#print range, size.width
		dc.DrawRectangle(size.width*range[0], 0, size.width*(range[1]-range[0]), size.height)
		
		
	def drawTime(self,dc):
		size = self.GetClientSize()
		time = self.backend.getTimeFraction()
		pos = int(time*size.width)
		#print time, pos
		dc.SetPen(wx.Pen("blue", 5, wx.SOLID))
		dc.DrawLine(pos, 0, pos, size.height)
		
	def drawFrames(self, dc):
		frames = self.backend.getMotionFrames()
		if frames != None:
			size = self.GetClientSize()

			dc.SetPen(wx.Pen("green", 5, wx.SOLID))
			for frame in frames:
				time = self.backend.getTimeFraction(frame)
				pos = int(time*size.width)
				dc.DrawLine(pos, 0, pos, size.height)
		
	def OnResize(self, event):
		self.drawToBuffer()
		
	def OnPaint(self, event):
		dc = wx.BufferedPaintDC(self, self.buffer)
		
	def UpdateTime(self, event):
		size = self.GetClientSize()
		pos = event.GetPositionTuple()
		t = float(pos[0])/float(size.width)
		self.backend.setTimeFraction(t)
		
	# if the time is next to one of the stored frame lists snap it
	def constrainByFrames(self, t):	
		frames = self.backend.getMotionFrames()
		if frames != None:
			size = self.GetClientSize()
			pos = int(t*size.width)
			for frame in frames:
				frametime = self.backend.getTimeFraction(frame)
				framepos = int(frametime*size.width)
				if abs(pos-framepos) < 3:
					print "constraining", pos, framepos, t, frametime
					t = frametime
					break
		return t

		
	def SetRange(self, event):
		#size = self.GetClientSize()
		#pos = event.GetPositionTuple()
		#t = float(pos[0])/float(size.width)
		self.backend.setRangeFraction(self.rangeStart, self.constrainByFrames(self.backend.getTimeFraction()))
		range = self.backend.getRangeFraction()
		print "range", range
		
	
		
	def OnMouseMove(self, event):
		if event.Dragging() and event.LeftIsDown():
			# if shift is down we are selecting a range so we don't want the
			# time to be updated
			self.UpdateTime(event)
			if event.ShiftDown():
				if self.rangeStart == None:
					self.rangeStart = self.constrainByFrames(self.backend.getTimeFraction())
				self.SetRange(event)
				
		
	def OnMouseUp(self, event):
		self.UpdateTime(event)
		if event.ShiftDown():
			if self.rangeStart == None:
				self.rangeStart = self.backend.getTimeFraction()
			self.SetRange(event)
			
		self.rangeStart = None
		
	def OnMouseDown(self, event):
		if event.ShiftDown():
			self.UpdateTime(event)
			self.rangeStart = self.backend.getTimeFraction()
		