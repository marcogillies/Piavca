
import wx

from MotionsList import MotionList


class MotionTypeList(MotionList):
			
	def getItems(self):
		return self.backend.getMotionTypeNames()
	
	def getText(self, item):
		return "__Type__::" + self.list.GetItemText(item)