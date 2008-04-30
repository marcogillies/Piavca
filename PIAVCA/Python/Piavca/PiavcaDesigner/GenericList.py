
import wx

class GenericList(wx.Panel):
	def __init__(self, backend, parent=None, id=-1, pos=wx.DefaultPosition, size=wx.DefaultSize, style=0, name="ListBoxController"):
		wx.Panel.__init__(self, parent, id, pos, size, style, name)
		
		self.backend = backend
		
		self.list = wx.ListCtrl(self,-1,style=wx.LC_LIST)
		
		self.Bind(wx.EVT_LIST_ITEM_ACTIVATED, self.OnItemActivated)
		
		# finally, put the list in a sizer for the panel to manage
		# the layout
		sizer = wx.BoxSizer()
		sizer.Add(self.list, 1, wx.EXPAND)
		self.SetSizer(sizer)
		
	def update(self):
		self.list.ClearAll()
		for i, x in enumerate(self.getItems()):
			self.list.InsertStringItem(i, str(x))
		
			
	def getItems(self):
		pass
			
	def OnItemActivated(self, evt):
		pass