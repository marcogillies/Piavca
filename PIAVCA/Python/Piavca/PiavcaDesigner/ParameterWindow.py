

import wx

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
		self.setValue(self.motionproxy.getParameterVal(self.param_name))
		
	def OnTextEntry(self, event):
		val = self.getValue()
		if val != None:
			self.motionproxy.setParameterVal(self.param_name, val)
		
	def SetValue(self, val):
		pass
		
	def GetValue(self, val):
		pass
		
class ScalarParamEntry(ParamEntry):
	
	def initSubtype(self):	
		self.text = wx.TextCtrl(self, -1, "")
		self.Bind(wx.EVT_TEXT, self.OnTextEntry, self.text)
		self.sizer.Add(self.text, 1, wx.EXPAND)
		
	def setValue(self, val):
		self.text.SetValue(str(val))
		
class StringParamEntry(ScalarParamEntry):
	
	def getValue(self):
		return self.text.GetValue()
		
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
		for i in range(self.dim):
			self.texts[i].SetValue(str(val[i]))
		
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
		
	def update(self):
		# get rid of existing controls
		for label, ctrl in self.children:
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
					ctrl = StringParamEntry(param_name, motionproxy, self)
				if valtype == int:
					ctrl = IntParamEntry(param_name, motionproxy, self)
				if valtype == float:
					ctrl = FloatParamEntry(param_name, motionproxy, self)
				if valtype == Piavca.Vec:
					ctrl = VecParamEntry(param_name, motionproxy, self)
				if valtype == Piavca.Quat:
					ctrl = QuatParamEntry(param_name, motionproxy, self)
				
				self.children.append((wx.StaticText(self, -1, param_name), ctrl))
				self.parametersSizer.Add(self.children[-1][0], 0, wx.ALIGN_LEFT)
				self.parametersSizer.Add(self.children[-1][1], 1, wx.EXPAND)
			
		self.parametersSizer.Layout()
		self.mainSizer.Layout()
		self.Fit()
		
			
		