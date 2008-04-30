
import sys, os, time

import wx
from wx.lib.dialogs import *

import HeirarchyView
import ListBoxController
import PlayControls


import Piavca
import Piavca.JointNames
Piavca.JointNames.loadDefaults()

import Piavca.FreeCameraCanvas

from BackEnd import BackEnd

class PiavcaDesigner(wx.Frame):
	mainHeight = 500
	timelineHeight = 25
	viewerwidth=400
	hierarchywidth=400
	listwidth=300
	
	
	def __init__(self, filename, parent=None, id=-1, size=(1000, 600)):
		
		self.backend = BackEnd(self, filename)
		
		wx.Frame.__init__(self, parent, id, "Piavca Designer")
		self.statusbar = self.CreateStatusBar()
		menubar = wx.MenuBar()
		menu1 = wx.Menu()
		menu1.Append(wx.NewId(), "Open", "")
		menubar.Append(menu1, "&File")
		self.SetMenuBar(menubar)
		
		self.totalheight = self.mainHeight+self.timelineHeight
		self.totalwidth = self.viewerwidth+self.hierarchywidth+self.listwidth
		
		self.splitter1 = wx.SplitterWindow(self, -1)#, size=(1000, 500))
		self.splitter2 = wx.SplitterWindow(self.splitter1, -1)
		#p2 = wx.Panel(self.splitter2, style=wx.SUNKEN_BORDER)
		
		
		#p1 = wx.Panel(self.splitter2, style=wx.SUNKEN_BORDER)
		self.viewer = Piavca.FreeCameraCanvas.FreeCameraCanvas(self.splitter2)
		self.heirarchy = HeirarchyView.HeirarchyView(self.backend, self.splitter2, style=wx.SUNKEN_BORDER)
		self.listboxes = ListBoxController.ListBoxController(self.backend, self.splitter1, style=wx.SUNKEN_BORDER)
		
		self.children = []
		self.children.append(self.heirarchy)
		self.children.append(self.listboxes)
		
		#self.horizSplitter.Initialize(p1)
		self.splitter1.SplitVertically(self.splitter2, self.listboxes)
		self.splitter2.SplitVertically(self.viewer, self.heirarchy)
		
		self.playcontrols = PlayControls.PlayControls(self.backend, self, size=(self.totalwidth, self.timelineHeight))
		
		self.sizer=wx.BoxSizer(wx.VERTICAL)
		self.sizer.Add(self.splitter1, 1, flag=wx.EXPAND)
		self.sizer.Add(self.playcontrols, flag=wx.EXPAND)
		self.SetSizer(self.sizer)
		#self.Fit()
		self.SetAutoLayout(1)
		self.sizer.Fit(self)
		self.Show(True)
		self.Layout()
		
		
		
		self.Bind(wx.EVT_IDLE, self.OnIdle)
		
		self.SetSizeWH(self.totalwidth, self.totalheight)
		
		self.splitter1.SetSashPosition(self.viewerwidth+self.hierarchywidth, redraw=True)
		self.splitter2.SetSashPosition(self.viewerwidth)
		#self.SendSizeEvent((1000,500))
		
		self.update()
		
	def update(self):
		for child in self.children:
			child.update()
		
	def OnIdle(self, event):
		self.backend.timeStep()

if __name__ == "__main__":
	app = Piavca.getWXApp()
	#canvas = app.showWindows(canvastype = Piavca.FreeCameraCanvas.FreeCameraCanvas)	
	#app.getCanvas().setClearColour(1, 1, 1)
	#pd.Show()
	
		
	if len(sys.argv) > 1:
		path = sys.argv[1]
	else:
		dialog_return = openFileDialog (wildcard="*.cfg")
		path = dialog_return.paths[0].encode("latin-1")
	
	print path
	pathend = path.rfind("\\")
	if pathend < 0:
		pathend = path.rfind("/")
	if pathend < 0:
		filename = path
	else:
		filename = path[pathend+1:]
		path = path[:pathend+1]
		if path != "":
			os.chdir(path)
	print filename, path
#	if filename[-4:] == ".cfg":
#		filename = filename[:-4]
#	print filename
		
	try:
		Piavca.JointNames.importJointNames("Joints.txt")
	except IOError:
		print "could not open Joints file Joints.txt, will probably work anyway"
	try:
		Piavca.JointNames.importExpressionNames("Expressions.txt")
	except IOError:
		print "could not open Expressions file Expressions.txt, will probably work anyway"
		
	print "creating avatar"
	
#	avatar = Piavca.Avatar(filename)
#	
#	print "loaded avatar"
#	
#	if len(sys.argv) > 2:
#		motion_name = sys.argv[2]
#	else:
#		motnames = Piavca.Core.getCore().getMotionNames()
#		print motnames
#		dialog_return = singleChoiceDialog (lst=motnames)
#		motion_name = dialog_return.selection.encode("latin-1")
#	
#	#motion_name = "biped_mocap_final"
#	mot = Piavca.Core.getCore().getMotion(motion_name)
#	mot.Reference()
#	
#	
#	avatar.playMotionDirect(mot)

	pd = PiavcaDesigner(filename)
	
	app.MainLoop()