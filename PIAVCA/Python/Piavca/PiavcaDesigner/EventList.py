
import wx

from GenericList import GenericList

class EventList(GenericList):
	def __init__(self, backend, parent=None, id=-1, pos=wx.DefaultPosition, size=wx.DefaultSize, style=0, name="ListBoxController"):
		GenericList.__init__(self, backend, parent, id, pos, size, style, name)
			
	def getItems(self):
		return ["item %02d"% x for x in range(20,30)]