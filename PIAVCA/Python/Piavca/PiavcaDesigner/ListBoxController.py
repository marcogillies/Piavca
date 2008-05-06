
import wx

from AvatarList import AvatarList
from MotionsList import MotionList
from MotionTypeList import MotionTypeList
from EventList import EventList
from ParameterWindow import ParameterWindow

class ListBoxController(wx.Panel):
	def __init__(self, backend, parent=None, id=-1, pos=wx.DefaultPosition, size=wx.DefaultSize, style=0, name="ListBoxController"):
		wx.Panel.__init__(self, parent, id, pos, size, style, name)
		self.backend = backend
		
		self.nb = wx.Notebook(self, style=wx.NB_LEFT)
		
		self.children = []
		
		self.avatar_list = AvatarList(self.backend, self.nb)
		self.nb.AddPage(self.avatar_list, "Avatar")
		self.children.append(self.avatar_list)
		
		self.motion_list = MotionList(self.backend, self.nb)
		self.nb.AddPage(self.motion_list, "Motions")
		self.children.append(self.motion_list)
		
		self.motion_type_list = MotionTypeList(self.backend, self.nb)
		self.nb.AddPage(self.motion_type_list, "Motions Types")
		self.children.append(self.motion_type_list)
		
		self.event_list = EventList(self.backend, self.nb)
		self.nb.AddPage(self.event_list, "Events")
		self.children.append(self.event_list)
		
		self.parameter_window = ParameterWindow(self.backend, self.nb)
		self.nb.AddPage(self.parameter_window, "Parameters")
		self.children.append(self.parameter_window)
		
		
		# finally, put the notebook in a sizer for the panel to manage
		# the layout
		sizer = wx.BoxSizer()
		sizer.Add(self.nb, 1, wx.EXPAND)
		self.SetSizer(sizer)
		
	def update(self):
		for child in self.children:
			child.update()