
import wx

from GenericList import GenericList


class MotionList(GenericList):
	def __init__(self, backend,  parent=None, id=-1, pos=wx.DefaultPosition, size=wx.DefaultSize, style=0, name="MotionList"):
		GenericList.__init__(self, backend,  parent, id, pos, size, style, name)
		
		self.Bind(wx.EVT_LIST_BEGIN_DRAG, self.OnDragStart)
			
	def getItems(self):
		return self.backend.getMotionNames()
			
	def OnItemActivated(self, evt):
		text = self.getText(evt.GetIndex())
		#item = evt.GetItem()
		print "activating", text
		self.backend.setMotion(text)
		
	def OnDragStart(self, evt):
		text = self.getText(evt.GetIndex())
		print "starting to drag", text
		print evt.GetItem().GetText()
		data = wx.TextDataObject(text)
		dropSource = wx.DropSource(self)
		dropSource.SetData(data)
		result = dropSource.DoDragDrop()
		print "dragging result", result 
		if result == wx.DragCopy or result == wx.DragMove:
			self.backend.update()