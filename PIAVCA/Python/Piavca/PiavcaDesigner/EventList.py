
import wx

from GenericList import GenericList

class EventList(GenericList):
	def __init__(self, backend, parent=None, id=-1, pos=wx.DefaultPosition, size=wx.DefaultSize, style=0, name="ListBoxController"):
		GenericList.__init__(self, backend, parent, id, pos, size, style, name)
			
	def getItems(self):
		return self.backend.getEvents()
			
	def OnItemActivated(self, evt):
		text = self.getText(evt.GetIndex())
		print "triggering event", text
		self.backend.triggerEvent(text)