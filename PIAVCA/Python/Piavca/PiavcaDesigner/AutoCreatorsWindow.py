

import wx
from wx.lib.dialogs import *

import Piavca

import AutoCreators

class AutoCreatorsWindow(wx.Panel):
	def __init__(self, backend,  parent=None, id=-1, pos=wx.DefaultPosition, size=wx.DefaultSize, style=0, name="ParameterWindow"):
		wx.Panel.__init__(self, parent, id, pos, size, style, name)
		self.backend = backend
		
		self.creator = None
		self.children = []
		self.outSizedChildren = []
		
		self.mainSizer = wx.BoxSizer(wx.VERTICAL)
		
		choicelist = self.getChoiceList()
		self.choice = wx.Choice(self, -1, choices=choicelist)
		self.Bind(wx.EVT_CHOICE, self.OnChoice, self.choice)
		self.mainSizer.Add(self.choice, 1, wx.EXPAND)
		
		
		self.parametersSizer = wx.FlexGridSizer(cols=2, hgap=5, vgap=5)
		self.parametersSizer.AddGrowableCol(1)
		
		self.mainSizer.Add(self.parametersSizer, 0, wx.EXPAND)
		
		self.button = wx.Button(self, -1, "Create")
		self.Bind(wx.EVT_BUTTON, self.getMotion, self.button)
		self.mainSizer.Add(self.button, 1, wx.EXPAND)
		
		self.SetSizer(self.mainSizer)
				
		self.mainSizer.Layout()
		self.Fit()
		
		
	def getChoiceList(self):
		creators = dir(AutoCreators)
		creators = filter(lambda x : x[0] != "_" and x != "Piavca", creators)
		print creators
		return creators
	
	def OnChoice(self, evt):
		name = self.choice.GetStringSelection()
		cl = getattr(AutoCreators, name)
		self.creator = cl()
		self.backend.update()
		
	def getMotion(self, evt):
		if self.creator:
			mot = self.creator.getMotion()
			print "created motion", mot
			if mot:
				self.backend.addMotion(mot)
		
	def update(self):
		# get rid of existing controls
		for label, ctrl in self.children:
			#print label, ctrl
			self.parametersSizer.Detach(label)
			self.parametersSizer.Detach(ctrl)
			label.Destroy()
			ctrl.Destroy()
			
		for ctrl in self.outSizedChildren:
			self.parametersSizer.Detach(ctrl)
			ctrl.Destroy()
		
		self.children = []
		self.outSizedChildren = []
		
		if self.creator :
			
			controls, outSizedControls = self.creator.createControls(self)
			for name, ctrl in controls:	
				self.children.append((wx.StaticText(self, -1, name), ctrl))
				self.parametersSizer.Add(self.children[-1][0], 0, wx.ALIGN_LEFT)
				self.parametersSizer.Add(self.children[-1][1], 1, wx.EXPAND)
				
			for ctrl in outSizedControls:	
				self.outSizedChildren.append(ctrl)
				self.mainSizer.Add(self.outSizedChildren[-1], 1, wx.EXPAND)
						
				
		self.parametersSizer.Layout()
		self.mainSizer.Layout()
		self.Fit()
		
		