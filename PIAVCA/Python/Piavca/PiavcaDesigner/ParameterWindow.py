

import wx
from wx.lib.dialogs import *

import Piavca

from ParameterControls import *

class ParameterWindow(wx.Panel):
	def __init__(self, backend,  parent=None, id=-1, pos=wx.DefaultPosition, size=wx.DefaultSize, style=0, name="ParameterWindow"):
		wx.Panel.__init__(self, parent, id, pos, size, style, name)
		self.backend = backend
		
		self.mainSizer = wx.BoxSizer(wx.VERTICAL)
		
		self.typelabel = wx.StaticText(self, -1, "")
		self.mainSizer.Add(self.typelabel, 0, wx.ALIGN_LEFT)
		
		self.parametersSizer = wx.FlexGridSizer(cols=2, hgap=5, vgap=5)
		self.parametersSizer.AddGrowableCol(1)
		
		self.mainSizer.Add(self.parametersSizer, 0, wx.EXPAND)
		
		self.SetSizer(self.mainSizer)
		
		self.children = []
		
	def addChildControl(self, name, ctrl):
		self.children.append((wx.StaticText(self, -1, name), ctrl))
		self.parametersSizer.Add(self.children[-1][0], 0, wx.ALIGN_LEFT)
		self.parametersSizer.Add(self.children[-1][1], 1, wx.EXPAND)
		
	def update(self):
		# get rid of existing controls
		for label, ctrl in self.children:
			#print label, ctrl
			self.parametersSizer.Detach(label)
			self.parametersSizer.Detach(ctrl)
			label.Destroy()
			ctrl.Destroy()
		
		motionproxy = self.backend.getCurrentSubMotionProxy()
		if motionproxy == None:
			self.typelabel.SetLabel("")
		else:
			# print "parameter window get name"
			self.typelabel.SetLabel(motionproxy.getName())
			
			parameters = motionproxy.getParameters()
			#print parameters
		
			
			self.children = []
			for param_name in parameters.keys():
				if param_name == "Name":
					continue
				if param_name == "StartTime":
					continue
				valtype = type(parameters[param_name])
				ctrl = None
				if valtype == str:
					if param_name == "Filename":
						ctrl = FilenameParamEntry(param_name, motionproxy, self)
					else:
						ctrl = StringParamEntry(param_name, motionproxy, self)
				if valtype == bool:
					ctrl = BoolParamEntry(param_name, motionproxy, self)
				if valtype == int:
					if param_name[-len("JointId"):] == "JointId":
						ctrl = JointParamEntry(param_name, motionproxy, self)
					else:
						ctrl = IntParamEntry(param_name, motionproxy, self)
				if valtype == float:
					ctrl = FloatParamEntry(param_name, motionproxy, self)
				if valtype == Piavca.Vec:
					ctrl = VecParamEntry(param_name, motionproxy, self)
				if valtype == Piavca.Quat:
					ctrl = QuatParamEntry(param_name, motionproxy, self)
				if valtype == Piavca.MotionMask:
					ctrl = MaskParamEntry(param_name, motionproxy, self)
				if valtype == list:
					# print "got a multi-type", param_name
					# print parameters[param_name]
					if len(parameters[param_name]) > 0:
						print "it has members", len(parameters[param_name]) 
						innervaltype = type(parameters[param_name][0][2])
						print "type of members", innervaltype
						if innervaltype == float:
							ctrl = FloatListParamEntry(param_name, motionproxy, self)
						if innervaltype == Piavca.Vec:
							ctrl = VecListParamEntry(param_name, motionproxy, self)
						if innervaltype == Piavca.Quat:
							ctrl = QuatListParamEntry(param_name, motionproxy, self)
				
				if ctrl:
					self.addChildControl(param_name, ctrl)
				
				
			if "Start" in parameters.keys() and "End" in parameters.keys():
				ctrl = ButtonParamEntry("setRange", motionproxy, self)
				self.addChildControl("", ctrl)
				ctrl = ButtonParamEntry("resetRange", motionproxy, self)
				self.addChildControl("", ctrl)
			
		self.parametersSizer.Layout()
		self.mainSizer.Layout()
		self.Fit()
		
			
		