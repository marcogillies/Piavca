
import wx

from GenericList import GenericList


class MotionList(GenericList):
	def __init__(self, backend,  parent=None, id=-1, pos=wx.DefaultPosition, size=wx.DefaultSize, style=0, name="ListBoxController"):
		GenericList.__init__(self, backend,  parent, id, pos, size, style, name)
			
	def getItems(self):
		return self.backend.getMotionNames()
			
	def OnItemActivated(self, evt):
		item = evt.GetItem()
		print "activating", item.GetText()
		self.backend.setMotion(item.GetText())