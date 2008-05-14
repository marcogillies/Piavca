
import wx

from MotionsList import MotionList


class MotionTypeList(MotionList):
			
	def getItems(self):
		items = self.backend.getMotionTypeNames()
		items.sort()
		return items
	
	def getText(self, item):
		return "__Type__::" + self.list.GetItemText(item)