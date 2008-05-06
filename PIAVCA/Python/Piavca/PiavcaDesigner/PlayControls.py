
import wx

from TimeLine import TimeLine

class PlayControls(wx.Panel):
	buttonwidth = 50
	
	def __init__(self, backend, parent=None, id=-1, pos=wx.DefaultPosition, size=wx.DefaultSize, style=0, name="PlayControls"):
		wx.Panel.__init__(self, parent, id, pos, size, style, name)
		
		self.backend = backend
		
		
		self.playButton = wx.Button(self, -1, ">")
		self.Bind(wx.EVT_BUTTON, self.Play, self.playButton)
		self.toStartButton = wx.Button(self, -1, "|<")
		self.Bind(wx.EVT_BUTTON, self.ToStart, self.toStartButton)
		self.toEndButton = wx.Button(self, -1, ">|")
		self.Bind(wx.EVT_BUTTON, self.ToEnd, self.toEndButton)
		
		self.children = []
		#size = self.GetClientSize()
		self.timeline=TimeLine(self.backend, self)#, size=(size.width-3*self.buttonwidth, size.height))
		self.children.append(self.timeline)
		
		sizer = wx.BoxSizer(wx.HORIZONTAL)
		sizer.Add(self.toStartButton, 0, wx.EXPAND)
		sizer.Add(self.playButton, 0, wx.EXPAND)
		sizer.Add(self.toEndButton, 0, wx.EXPAND)
		sizer.Add(self.timeline, 1, wx.EXPAND)
		self.SetSizer(sizer)
		sizer.Fit(self)
		
	def Play(self, evt):
		self.backend.playpause()
		if self.backend.getPlaying():
			self.playButton.SetLabel("||")
		else:
			self.playButton.SetLabel(">")
			
	def ToStart(self, evt):
		self.backend.setTimeFraction(0.0)
			
	def ToEnd(self, evt):
		self.backend.setTimeFraction(1.0)
		
	def update(self):
		for child in self.children:
			child.update()