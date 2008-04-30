
import wx

class TimeLine(wx.Panel):
	def __init__(self, backend, parent=None, id=-1, pos=wx.DefaultPosition, size=wx.DefaultSize, style=0, name="TimeLine"):
		wx.Panel.__init__(self, parent, id, pos, size, style, name)
		
		self.backend = backend
		
		self.Bind(wx.EVT_IDLE, self.OnIdle)
		self.Bind(wx.EVT_PAINT, self.OnPaint)
		self.Bind(wx.EVT_SIZE, self.OnResize)
		#self.Bind(wx.EVT_LEFT_DOWN, self.OnMouseDown)
		self.Bind(wx.EVT_LEFT_UP, self.OnMouseUp)
		self.Bind(wx.EVT_MOTION, self.OnMouseMove)
		
	def OnIdle(self, event):
		self.drawToBuffer()
		self.Refresh(False)
		
	def drawToBuffer(self):
		size = self.GetClientSize()
		self.buffer = wx.EmptyBitmap(size.width, size.height)
		dc = wx.BufferedDC(None, self.buffer)
		dc.SetBackground(wx.Brush("white"))
		#dc.CLear()
		dc.DrawRectangle(0, 0, size.width, size.height)
		self.drawTime(dc)
		
	def drawTime(self,dc):
		size = self.GetClientSize()
		time = self.backend.getTimeFraction()
		pos = int(time*size.width)
		#print time, pos
		dc.SetPen(wx.Pen("blue", 5, wx.SOLID))
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
		
	def OnMouseMove(self, event):
		if event.Dragging() and event.LeftIsDown():
			self.UpdateTime(event)
		
	def OnMouseUp(self, event):
		self.UpdateTime(event)
		