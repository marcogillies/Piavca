
import wx

from MotionGroup import MotionGroup

class HeirarchyView(wx.Panel):
	def __init__(self, backend, parent=None, id=-1, pos=wx.DefaultPosition, size=wx.DefaultSize, style=0, name="HeirarchyView"):
		wx.Panel.__init__(self, parent, id, pos, size, style, name)
		self.SetBackgroundColour("white")
		self.backend = backend
		
		self.motionGroup = None
		
		self.sizer = wx.BoxSizer(wx.VERTICAL)
		#self.vsizer = wx.BoxSizer(wx.VERTICAL)
		#self.vsizer.Add(self.hsizer, 1, wx.EXPAND)
		self.SetSizer(self.sizer)
		
	def update(self):
		motionproxy = self.backend.getCurrentMotionProxy()
		
		# first we need to remove the existing motion group
		if self.motionGroup != None:
			print "deleting old group", self.motionGroup
			self.sizer.Detach(self.motionGroup)
			print "detatching group"
			self.motionGroup.Destroy()
			print "destroying group"
			self.motionGroup = None
			print "destroyed group"
			#print self.motionGroup
			#self.ClearBackground()
			self.sizer.Layout()
		
		print motionproxy
		if motionproxy != None:
			print "creating motion group"
			self.motionGroup = MotionGroup(motionproxy, self)
			self.sizer.Add(self.motionGroup, 1, wx.EXPAND)
			self.Fit()
			self.Layout()
		else:
			self.motionGroup = None
		print "finished updating heirarchy view"
		self.Refresh()