
import wx


class HeirarchyView(wx.Panel):
	def __init__(self, backend, parent=None, id=-1, pos=wx.DefaultPosition, size=wx.DefaultSize, style=0, name="HeirarchyView"):
		wx.Panel.__init__(self, parent, id, pos, size, style, name)
		self.backend = backend
		
	def update(self):
		pass