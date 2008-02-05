try:
	import wx
	wxPresent = True
except ImportError:
	wxPresent = False
	
if wxPresent:	
	from PiavcaWXCanvas import PiavcaWXCanvasBase
			
	class PiavcaWXFrame(wx.Frame):
		def __init__(
				self, parent, ID, title, pos=wx.DefaultPosition,
				size=(1280, 960), style=wx.DEFAULT_FRAME_STYLE,
				canvastype=None
				):
	
			wx.Frame.__init__(self, parent, ID, title, pos, size, style)
			if canvastype == None:
				canvastype = PiavcaWXCanvasBase
			self.canvas = canvastype(self)
			self.Bind(wx.EVT_CLOSE, self.OnCloseWindow)
			self.Bind(wx.EVT_SIZE, self.canvas.OnSize)
	
		def OnCloseWindow(self, event):
			self.Destroy()
			wx.Exit()
	
	
	class PiavcaWXApp(wx.App):
		def __init__(self):
			wx.App.__init__(self, redirect=False)#, filename="PiavcaOut.txt")
		def OnInit(self):
			return True
		def showWindows(self, canvastype = None):
			self.frame = PiavcaWXFrame(None, -1, "Piavca Viewer", size=(400,400), canvastype=canvastype)
			self.SetTopWindow(self.frame)
			self.frame.Show(True)
			return self.frame.canvas
		def getCanvas(self):
			return self.frame.canvas
	
_wxApp = None

def getWXApp():
	global _wxApp
	if wxPresent and _wxApp == None:
		_wxApp = PiavcaWXApp()
	return _wxApp

def setWXApp(app):
	global _wxApp
	_wxApp = app