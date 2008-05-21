

import wx
from wx.lib.dialogs import *

import Piavca

class ParamEntry(wx.Panel):
	def __init__(self, param_name, motionproxy,  parent=None, id=-1, pos=wx.DefaultPosition, size=wx.DefaultSize, style=0, name="ParamEntry"):
		wx.Panel.__init__(self, parent, id, pos, size, style, name)
		self.param_name = param_name
		self.motionproxy = motionproxy
		
		self.sizer = wx.BoxSizer()
		
		self.initSubtype()
		
		self.update()
		
		self.SetSizer(self.sizer)
		self.Layout()
		self.Fit()
	
	def update(self):
		print "paramentry:update"
		self.setValue(self.motionproxy.getParameterVal(self.param_name))
		print "paramentry:update:end"
		
	def OnTextEntry(self, event):
		print "paramentry:OnTextEntry"
		val = self.getValue()
		if val != None:
			self.motionproxy.setParameterVal(self.param_name, val)
			self.motionproxy.backend.timeUpdate()
		print "paramentry:OnTextEntry:end"
		
	def setValue(self, val):
		pass
		
	def getValue(self, val):
		pass
	
	
class ButtonParamEntry(ParamEntry):
	
	def initSubtype(self):	
		self.button = wx.Button(self, -1, self.param_name)
		self.Bind(wx.EVT_BUTTON, self.OnButton, self.button)
		self.sizer.Add(self.button, 1, wx.EXPAND)
	
	def OnButton(self, evt):
		print "paramentry:OnButton"
		meth = getattr(self.motionproxy, self.param_name)
		meth()
		self.motionproxy.backend.timeUpdate()
		print "paramentry:OnButton:end"
	
		
class ScalarParamEntry(ParamEntry):
	
	def initSubtype(self):	
		self.text = wx.TextCtrl(self, -1, "")
		self.Bind(wx.EVT_TEXT, self.OnTextEntry, self.text)
		self.sizer.Add(self.text, 1, wx.EXPAND)
		
	def setValue(self, val):
		print "paramentry:setValue"
		self.text.SetValue(str(val))
		print "paramentry:setValue:end"
		
class StringParamEntry(ScalarParamEntry):
	
	def getValue(self):
		return self.text.GetValue()
	
class FilenameParamEntry(StringParamEntry):
	
	def initSubtype(self):	
		StringParamEntry.initSubtype(self)
		self.button = wx.Button(self, -1, "Browse")
		self.Bind(wx.EVT_BUTTON, self.BrowseFile, self.button)
		self.sizer.Add(self.button, 1, wx.EXPAND)
		
	def BrowseFile(self, evt):
		dialog_return = openFileDialog ()
		filename = dialog_return.paths[0].encode("latin-1")
		self.setValue(filename)
		self.OnTextEntry(evt)
		
class IntParamEntry(ScalarParamEntry):
	
	def getValue(self):
		try:
			val = int(self.text.GetValue())
			return val
		except ValueError:
			return None
		
class FloatParamEntry(ScalarParamEntry):
	
	def getValue(self):
		try:
			val = float(self.text.GetValue())
			return val
		except ValueError:
			return None
		
		
class MultiParamEntry(ParamEntry):
	
	def initSubtype(self):	
		self.texts = []
		for i in range(self.dim):
			self.texts.append(wx.TextCtrl(self, -1, ""))
			self.Bind(wx.EVT_TEXT, self.OnTextEntry, self.texts[-1])
			self.sizer.Add(self.texts[-1], 1, wx.EXPAND)
		
	def setValue(self, val):
		print "paramentry:setValue"
		for i in range(self.dim):
			self.texts[i].SetValue(str(val[i]))
		print "paramentry:setValue:end"
		
class VecParamEntry(ScalarParamEntry):
	dim = 3 
	def getValue(self):
		try:
			val = [float(self.texts[i].GetValue()) for i in range(self.dim)]
			val = Piavca.Vec(val[0], val[1], val[2])
			return val
		except ValueError:
			return None
			self.texts[i].SetValue(str(val[i]))
		
class QuatParamEntry(ScalarParamEntry):
	dim = 4
	def getValue(self):
		try:
			val = [float(self.texts[i].GetValue()) for i in range(self.dim)]
			val = Piavca.Quat(Piavca.degToRad(val[0]), Piavca.Vec(val[1], val[2], val[3]))
			return val
		except ValueError:
			return None
		

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
			print label, ctrl
			self.parametersSizer.Detach(label)
			self.parametersSizer.Detach(ctrl)
			label.Destroy()
			ctrl.Destroy()
		
		motionproxy = self.backend.getCurrentSubMotionProxy()
		if motionproxy == None:
			self.typelabel.SetLabel("")
		else:
			self.typelabel.SetLabel(motionproxy.getName())
			
			parameters = motionproxy.getParameters()
			print parameters
		
			
			self.children = []
			for param_name in parameters.keys():
				valtype = type(parameters[param_name])
				if valtype == str:
					if param_name == "Filename":
						ctrl = FilenameParamEntry(param_name, motionproxy, self)
					else:
						ctrl = StringParamEntry(param_name, motionproxy, self)
				if valtype == int:
					ctrl = IntParamEntry(param_name, motionproxy, self)
				if valtype == float:
					ctrl = FloatParamEntry(param_name, motionproxy, self)
				if valtype == Piavca.Vec:
					ctrl = VecParamEntry(param_name, motionproxy, self)
				if valtype == Piavca.Quat:
					ctrl = QuatParamEntry(param_name, motionproxy, self)
				
				self.addChildControl(param_name, ctrl)
				
				
			if "Start" in parameters.keys() and "End" in parameters.keys():
				ctrl = ButtonParamEntry("setRange", motionproxy, self)
				self.addChildControl("", ctrl)
				ctrl = ButtonParamEntry("resetRange", motionproxy, self)
				self.addChildControl("", ctrl)
			
		self.parametersSizer.Layout()
		self.mainSizer.Layout()
		self.Fit()
		
			
		