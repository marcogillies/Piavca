
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
		
		self.popup = wx.Menu()
		item = self.popup.Append(-1,"Publish Events")
		self.Bind(wx.EVT_MENU, self.PublishEvents, item)
		item = self.popup.Append(-1,"Delete")
		self.Bind(wx.EVT_MENU, self.Delete, item)
		self.Bind(wx.EVT_CONTEXT_MENU, self.OnShowPopUp)
		
		dt = MotionDropTarget(self)
		self.SetDropTarget(dt)

	def OnClick(self, event):
		print "starting motionview.OnClick"
		self.motionproxy.select()
		print "ending motionview.OnClick"
		
	def receiveText(self, data):
		print "dropped", data
		self.motionproxy.addChild(data)
		
	def OnShowPopUp(self, event):
		#print "pop up"
		pos = event.GetPosition()
		pos = self.ScreenToClient(pos)
		self.PopupMenu(self.popup, pos)
		
	def PublishEvents(self, event):
		print "Publish Events"
		self.motionproxy.PublishEvents()
		
	def Delete(self, event):
		print "Delete"
		self.motionproxy.delete()
		
		
		