
import wx

from MotionView import MotionView

class TreeLines(wx.Panel):
	def __init__(self, children, parent=None, id=-1, pos=wx.DefaultPosition, size=wx.DefaultSize, style=0, name="TreeLines"):
		wx.Panel.__init__(self, parent, id, pos, size, style, name)
		self.SetBackgroundColour("white")
		self.children = children
		self.buffer = None
		
		self.SetSizeWH(200, 50)
		
		self.Bind(wx.EVT_IDLE, self.OnIdle)
		self.Bind(wx.EVT_PAINT, self.OnPaint)
		self.Bind(wx.EVT_SIZE, self.OnResize)
		
	def OnIdle(self, event):
		self.drawToBuffer()
		self.Refresh(False)
		
	def drawToBuffer(self):
		size = self.GetClientSize()
		#print "drawing", size
		self.buffer = wx.EmptyBitmap(size.width, size.height)
		dc = wx.BufferedDC(None, self.buffer)
		dc.SetBackground(wx.Brush("white"))
		dc.Clear()#BackGround()
		#dc.DrawRectangle(0, 0, size.width, size.height)
		dc.SetPen(wx.Pen("black", 3, wx.SOLID))
		for child in self.children:
			childsize = child.GetClientSize()
			childpos = child.GetPosition()
			dc.DrawLine(size.width/2, 0, childpos.x + childsize.width/2, size.height)
		
	def OnResize(self, event):
		self.drawToBuffer()
		
	def OnPaint(self, event):
		if self.buffer:
			dc = wx.BufferedPaintDC(self, self.buffer)

class MotionGroup(wx.Panel):
	def __init__(self, motionproxy, parent=None, id=-1, pos=wx.DefaultPosition, size=wx.DefaultSize, style=0, name="MotionGroup"):
		wx.Panel.__init__(self, parent, id, pos, size, style, name)
		self.SetBackgroundColour("white")
		self.motionproxy = motionproxy
		self.view = MotionView(self.motionproxy, self)
		
		sizer = wx.BoxSizer(wx.VERTICAL)
		sizer.Add(self.view, 0,  wx.ALIGN_CENTER)
		
		children = self.motionproxy.getChildren()
		if len(children) > 0:
			childSizer = wx.BoxSizer(wx.HORIZONTAL)
			self.children = []
			for child in children:
				self.children.append(MotionGroup(child, self))
				childSizer.Add(self.children[-1])
			sizer.Add(TreeLines(self.children, self), 0, wx.EXPAND)
			sizer.Add(childSizer, 1, wx.ALIGN_CENTER)
			
		self.SetSizer(sizer)
		self.Fit()
		
		