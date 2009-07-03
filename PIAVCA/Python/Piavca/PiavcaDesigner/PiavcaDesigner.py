
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
import Piavca.ViewerCanvas

from BackEnd import BackEnd

class PiavcaDesigner(wx.Frame):
	mainHeight = 500
	timelineHeight = 25
	viewerwidth=400
	hierarchywidth=400
	listwidth=300
	
	
	def __init__(self, parent=None, extra_panels=None, id=-1, size=(1000, 600)):
		self.backend = BackEnd(self)
		
		self.filename = None
		
		wx.Frame.__init__(self, parent, id, "Piavca Designer")
		self.statusbar = self.CreateStatusBar()
		
		
		menubar = wx.MenuBar()
		
		filemenu = wx.Menu()
		open = filemenu.Append(wx.NewId(), "Open", "")
		self.Bind(wx.EVT_MENU, self.Open, open)
		imp = filemenu.Append(wx.NewId(), "Import", "")
		self.Bind(wx.EVT_MENU, self.Import, imp)
		save = filemenu.Append(wx.NewId(), "&Save\tCtrl+s", "")
		self.Bind(wx.EVT_MENU, self.Save, save)
		saveas = filemenu.Append(wx.NewId(), "SaveAs", "")
		self.Bind(wx.EVT_MENU, self.SaveAs, saveas)
		quit = filemenu.Append(wx.NewId(), "Quit", "")
		self.Bind(wx.EVT_MENU, self.Quit, quit)
		
		editmenu = wx.Menu()
		delete = editmenu.Append(wx.NewId(), "Delete\tdel", "")
		self.Bind(wx.EVT_MENU, self.backend.Delete, delete)
		publishevents = editmenu.Append(wx.NewId(), "Publish Events", "")
		self.Bind(wx.EVT_MENU, self.backend.PublishEvents, publishevents)
	
		menubar.Append(filemenu, "&File")
		menubar.Append(editmenu, "&Edit")
		self.SetMenuBar(menubar)
		
		self.totalheight = self.mainHeight+self.timelineHeight
		self.totalwidth = self.viewerwidth+self.hierarchywidth+self.listwidth
		
		self.splitter1 = wx.SplitterWindow(self, -1)#, size=(1000, 500))
		self.splitter2 = wx.SplitterWindow(self.splitter1, -1)
		#p2 = wx.Panel(self.splitter2, style=wx.SUNKEN_BORDER)
		
		
		#p1 = wx.Panel(self.splitter2, style=wx.SUNKEN_BORDER)
		#self.viewer = Piavca.FreeCameraCanvas.FreeCameraCanvas(self.splitter2)
		self.viewer = Piavca.ViewerCanvas.ViewerCanvas(self.splitter2)
		Piavca.getWXApp().setCanvas(self.viewer)
		self.viewer.tracking = False
		self.heirarchy = HeirarchyView.HeirarchyView(self.backend, self.splitter2)#, style=wx.SUNKEN_BORDER)
		self.listboxes = ListBoxController.ListBoxController(self.backend, self.splitter1, extra_panels=extra_panels, style=wx.SUNKEN_BORDER)
		
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
		
	def Open(self, event):
		self.backend.clear()
		self.Import(event)
		
	def Import(self, event):
		dialog_return = openFileDialog (wildcard="XML Motion files (*.xml)|*.xml|Cal3d Character files files (*.cfg)|*.cfg")
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
		self.backend.readfile(filename)
		
	def getSaveName(self):
		dialog_return = saveFileDialog (wildcard="*.xml", filename=".xml") #"XML Motion files (*.xml)|*.xml")
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
		return filename
	
	def _save(self, filename=None):
		if filename == None:
			filename = self.getSaveName()
		self.filename = filename
		self.backend.save(filename)
		
	def SaveAs(self, evt):
		self._save()
		
	def Save(self, evt):
		self._save(self.filename)
		
	def Quit(self,event):
		self.Close()
		
	def update(self):
		for child in self.children:
			child.update()
			
		if self.viewer.avatar != self.backend.getAvatar():
			self.viewer.setAvatar(self.backend.getAvatar())
			self.viewer.initCameraPosition()
			self.viewer.SetFocus()

		# this line is a bit of a hack, its the only way I could get the 
		# heirarchy view to update its layout properly
		self.splitter2.SetSashPosition(self.splitter2.GetSashPosition())
		print "finished update"
		
	def OnIdle(self, event):
		self.backend.timeStep()
		#self.Layout()
		#self.Refresh()

if __name__ == "__main__":
	app = Piavca.getWXApp()
	#canvas = app.showWindows(canvastype = Piavca.FreeCameraCanvas.FreeCameraCanvas)	
	#app.getCanvas().setClearColour(1, 1, 1)
	#pd.Show()
	
		
#	if len(sys.argv) > 1:
#		path = sys.argv[1]
#	else:
#		dialog_return = openFileDialog (wildcard="Cal3d Character files files (*.cfg)|*.cfg|XML Motion files (*.xml)|*.xml")
#		path = dialog_return.paths[0].encode("latin-1")
#	
#	print path
#	pathend = path.rfind("\\")
#	if pathend < 0:
#		pathend = path.rfind("/")
#	if pathend < 0:
#		filename = path
#	else:
#		filename = path[pathend+1:]
#		path = path[:pathend+1]
#		if path != "":
#			os.chdir(path)
#	print filename, path
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

	pd = PiavcaDesigner()
	
	app.MainLoop()