
import wx
import wx.lib.buttons as buttons

class MotionDropTarget(wx.TextDropTarget):
	def __init__(self, motionview):
		wx.TextDropTarget.__init__(self)
		self.motionview = motionview
		
	def OnDropText(self, x, y, data):
		self.motionview.receiveText(data)

class MotionView(buttons.GenButton):
	def __init__(self, motionproxy, parent=None, id=-1, pos=wx.DefaultPosition, size=wx.DefaultSize, style=0, name="MotionView"):
		buttons.GenButton.__init__(self, parent, id, "", pos, size, style, name=name)
		self.motionproxy = motionproxy
		self.SetLabel(self.motionproxy.getName())
		self.Bind(wx.EVT_BUTTON, self.OnClick, self)
		
		dt = MotionDropTarget(self)
		self.SetDropTarget(dt)

	def OnClick(self, event):
		self.motionproxy.select()
		
	def receiveText(self, data):
		print "dropped", data
		self.motionproxy.addChild(data)
		
		
		