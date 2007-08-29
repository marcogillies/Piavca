#print "before wx import"
import wx
from wx.lib.dialogs import *
#print "after wx import"

import pickle
import time

import MotionTracks, DataStream

# ids of various widgets
ID_ABOUT=001
ID_SAVE=010
ID_SAVE_SPLITS=011
ID_LOAD_SPLITS=012
ID_SAVE_PCA=013
ID_LOAD_PCA=014
ID_PROJECT_MOTION=015
ID_PROJECT_SUBTRACT=0151
ID_ADD_PCS=0152
ID_DISTANCE_MEASURE=016
ID_MOTION_GRAPH=017
ID_SAVE_MOTION_GRAPH=020
ID_LOAD_MOTION_GRAPH=021
ID_LOAD_DATA_STREAM=022
ID_LIST=100
ID_PLAY=101
ID_STOP=110
ID_PCA =112
ID_SS =113
ID_UNDO =114
ID_EXIT=111

# a GUI for animation editing
# it inherits a lot of its functionality from a sub-widget, MotionTracks
class AnimationInterface(wx.Frame):
	""" We simply derive a new class of Frame. """
	def __init__(self,parent,id, title, avatar, motion, motion_name):
		print "start of interface constructor"
		# set up a parent frame object
		wx.Frame.__init__(self,parent,wx.ID_ANY,title,size=(500,150),
				  style=wx.DEFAULT_FRAME_STYLE|wx.NO_FULL_REPAINT_ON_RESIZE)

		# give it scroll bars
		self.scroll=wx.ScrolledWindow(self,-1) 
		
		# create the motion tracks
		self.tracks = MotionTracks.MotionTracks(avatar, motion, motion_name, "Tracks.txt", self.scroll, ID_LIST)
		
		# set up a bunch of size parameters
		windowheight = self.tracks.GetHeight() + 100
		windowlength = self.tracks.GetLength()
		if windowlength > 600:
			windowlength = 600
		print "Height", windowheight, "Length", windowlength
		self.SetSize(wx.Size(windowheight, windowlength))

		# scroll around the animation trakcs
		dx = 10
		self.scroll.SetScrollbars(dx,0,self.tracks.GetLength()/dx+1,0) 
		
		# buttons
		# play the current motion
		self.play=wx.Button(self, ID_PLAY, label=">")
		# stop the current motion
		self.stop = wx.Button(self, ID_STOP, label="!!")
		# perform a PCA on the current motion
		self.pca = wx.Button(self, ID_PCA, label="PCA")
		# perform a slow subspace analysis on the current motion
		# undo adding a split
		self.undo = wx.Button(self, ID_UNDO, label="Undo")
		# bind buttons to events
		wx.EVT_BUTTON (self, ID_PLAY, self.Play)
		wx.EVT_BUTTON (self, ID_STOP, self.Stop)
		wx.EVT_BUTTON (self, ID_PCA, self.PCA)
		wx.EVT_BUTTON (self, ID_UNDO, self.Undo)

		# Use some sizers to see layout options
		self.sizer1=wx.BoxSizer(wx.HORIZONTAL)
		self.sizer1.Add(self.play,1 )
		self.sizer1.Add(self.stop,1)
		self.sizer1.Add(self.pca,1)
		
		if MotionTracks.SlowSubspaceAvailable:
			self.slow = wx.Button(self, ID_SS, label="Slow Subspace")	
			wx.EVT_BUTTON (self, ID_SS, self.SlowSubspace)
			self.sizer1.Add(self.slow,1)
			
		self.sizer1.Add(self.undo,1)

		
		self.sizer2=wx.BoxSizer(wx.VERTICAL)
		self.sizer2.Add(self.sizer1,0)
		self.sizer2.Add(self.scroll,1,wx.EXPAND)

		self.SetSizer(self.sizer2)
		self.SetAutoLayout(1)
		self.sizer2.Fit(self)

		# sliders to edit principal component weights
		self.sliders = None
		# buttons to select independent components
		self.ICButtons = None
		
		# display a data stream 
		self.dataStream = None

		# mouse click events
		wx.EVT_LEFT_DOWN ( self.tracks, self.OnLeftClick)
		wx.EVT_LEFT_UP ( self.tracks, self.OnLeftUp)
		wx.EVT_RIGHT_DOWN ( self.tracks, self.OnRightClick)
		wx.EVT_MOTION ( self.tracks, self.OnMouseMove)


		self.CreateStatusBar() # A Statusbar in the bottom of the window

		# Setting up the menu.
		filemenu= wx.Menu()
		filemenu.Append(ID_ABOUT, "&About"," Information about this program")
		filemenu.Append(ID_SAVE, "&Save"," Save the currently selected track")
		filemenu.Append(ID_SAVE_SPLITS, "&SaveSplits"," Save the splits of the currently selected track")
		filemenu.Append(ID_LOAD_SPLITS, "&LoadSplits"," Load splits from file to the currently selected track")
		filemenu.Append(ID_SAVE_PCA, "&SavePCA"," Saves the current PCA data to file")
		filemenu.Append(ID_LOAD_PCA, "&LoadPCA"," Loads PCA data from")
		filemenu.Append(ID_PROJECT_MOTION, "&ProjectMotion"," Projects the original motion back onto the pcs")
		filemenu.Append(ID_PROJECT_SUBTRACT, "&ProjectSubtract"," subtracts the project of the motion onto the pcs")
		filemenu.Append(ID_ADD_PCS, "&AddPCSToMotion"," adds the current pcs weights to the motion")
		filemenu.Append(ID_DISTANCE_MEASURE, "&ShowFootplants"," Print the footplants")
		filemenu.Append(ID_MOTION_GRAPH, "&MotionGraph"," Creates a motion graph from the motion")
		filemenu.Append(ID_SAVE_MOTION_GRAPH, "&SaveMotionGraph"," Saves the current motion graph")
		filemenu.Append(ID_LOAD_MOTION_GRAPH, "&LoadMotionGraph"," Load a motion graph from file")
		filemenu.Append(ID_LOAD_DATA_STREAM, "&LoadDataStream"," Load and display a data stream from file")
		
		filemenu.Append(ID_EXIT,"E&xit"," Terminate the program")
		
		# Creating the menubar.
		menuBar = wx.MenuBar()
		menuBar.Append(filemenu,"&File") # Adding the "filemenu" to the MenuBar
		self.SetMenuBar(menuBar)  # Adding the MenuBar to the Frame content.
		wx.EVT_MENU(self, ID_ABOUT, self.OnAbout) # attach the menu-event ID_ABOUT to the
								   # method self.OnAbout
		#wx.EVT_MENU(self, ID_OPEN, self.OnOpen) 
		wx.EVT_MENU(self, ID_SAVE, self.OnSave)  
		wx.EVT_MENU(self, ID_SAVE_SPLITS, self.OnSaveSplits) 
		wx.EVT_MENU(self, ID_LOAD_SPLITS, self.OnLoadSplits) 
		wx.EVT_MENU(self, ID_SAVE_PCA, self.OnSavePCA) 
		wx.EVT_MENU(self, ID_LOAD_PCA, self.OnLoadPCA) 
		wx.EVT_MENU(self, ID_PROJECT_MOTION, self.OnProjectMotion) 
		wx.EVT_MENU(self, ID_PROJECT_SUBTRACT, self.OnProjectSubtract) 
		wx.EVT_MENU(self, ID_ADD_PCS, self.OnAddPCSToMotion) 
		wx.EVT_MENU(self, ID_DISTANCE_MEASURE, self.tracks.showFootplants) 
		wx.EVT_MENU(self, ID_MOTION_GRAPH, self.tracks.MotionGraph) 
		wx.EVT_MENU(self, ID_SAVE_MOTION_GRAPH, self.tracks.SaveMotionGraph) 
		wx.EVT_MENU(self, ID_LOAD_MOTION_GRAPH, self.tracks.LoadMotionGraph) 
		wx.EVT_MENU(self, ID_LOAD_DATA_STREAM, self.loadDataStream) 
		wx.EVT_MENU(self, ID_EXIT, self.OnExit)   

		# show the window
		self.Show(True)
		self.Layout()
		
		self.timer = wx.Timer(self)
		wx.EVT_TIMER(self, -1, self.OnFrameEvent)
		self.lasttime = 0.0
		self.timer.Start(40.0)

	# blah blah
	def OnAbout (self,e) :
		d= wx.MessageDialog( self, " A motion editor \n"
				    " in wxPython","About Motion Editor", wx.OK)
				    # Create a message dialog box
		d.ShowModal() # Shows it
		d.Destroy() # finally destroy it when finished.

	def OnExit(self,e):
		self.Close(True)  # Close the frame.

	# mouse clicks are passed on to the MotionTracks widget
	def OnLeftClick(self,e):
		print "OnLeft Click", e.GetX(), e.GetY()
		self.tracks.OnLeftClick(e.GetX(), e.GetY())
		self.tracks.Refresh()
		self.tracks.Update()
		e.Skip()

	# mouse clicks are passed on to the MotionTracks widget
	def OnMouseMove(self,e):
		if e.LeftIsDown() :
			print e.GetX(), e.GetY()
			self.tracks.OnMouseMove(e.GetX(), e.GetY())
			self.tracks.Refresh()
			self.tracks.Update()
			e.Skip()

	# mouse clicks are passed on to the MotionTracks widget
	def OnLeftUp(self,e):
		print "On Left Up", e.GetX(), e.GetY()
		self.tracks.OnLeftUp()
		self.tracks.Refresh()
		self.tracks.Update()
		e.Skip()

	# undo adding a split
	def Undo (self, e):
		self.tracks.Undo()
		
	# mouse clicks are passed on to the MotionTracks widget
	def OnRightClick(self,e):
		print e.GetX(), e.GetY()
		self.tracks.OnRightClick(e.GetX(), e.GetY())
		e.Skip()

	# play the current motion
	def Play(self, e):
		self.tracks.Play()

	# stop the current motion
	def Stop(self, e):
		self.tracks.Stop()

	# set up some sliders used to set PC weights
	def SetUpComponentSliders (self):
		id = 200
		self.sliders = []
		
		self.sizer3=wx.BoxSizer(wx.HORIZONTAL)
		# add a slider to each PC
		for i in range (self.tracks.pcs.num_pcs) :
			self.sliders.append(wx.Slider(self, id + i, 0, 0, 100) )
			wx.EVT_SLIDER (self, id + i, lambda e, ind = i : self.tracks.setPCWeight(ind, self.sliders[ind].GetValue()/100.0))
			self.sizer3.Add(self.sliders[i],1)
		self.sizer2.Add(self.sizer3)
		self.sizer2.Fit(self)

	# peform a PC
	def PCA (self, e):
		self.tracks.PCA()
		if self.sliders == None:
			self.SetUpComponentSliders()

	# peform a slow subspace analysis
	def SlowSubspace (self, e):
		self.tracks.SlowSubspace()
		if self.sliders == None:
			self.SetUpComponentSliders()
			
	def loadDataStream(self, e):
		dialog_return = openFileDialog(wildcard="*.csv")
		path = dialog_return.paths[0]
		if path == "":
			return
		self.dataStream = DataStream.SequenceDisplay(self, path)
		self.sizer2.Add(self.dataStream)
		self.sizer2.Fit(self)
		
		
	# save the current motion
	def OnSave(self, e):
		self.tracks.Save()
		
	# save the current splits
	def OnSaveSplits(self, e):
		self.tracks.SaveSplits()
		
	# load splits from file
	def OnLoadSplits(self, e):
		self.tracks.LoadSplits()
		
	# save the current principal components
	def OnSavePCA(self, e):
		self.tracks.pcs.Save("pcs.txt")
		#f = open("pcs.txt", "w")
		#pickle.dump(self.tracks.pcs, f)
		#f.close()
		
	# save splits from file
	def OnLoadPCA(self, e):
		self.tracks.LoadPCA("pcs.txt")
		if self.sliders == None:
			self.SetUpComponentSliders()
			
	# project the current motion back onto the PCs
	def OnProjectMotion(self, e):
		self.tracks.ProjectMotion()
			
	# project the current motion back onto the PCs
	def OnProjectSubtract(self, e):
		self.tracks.ProjectSubtract()
			
	# project the current motion back onto the PCs
	def OnAddPCSToMotion(self, e):
		self.tracks.AddPCSToMotion()

	# called every frame, used to advance the time when playing motions
	def TimeStep(self):
		#print "time stepping", time.time()
		#wx.Frame.Update(self)
		self.tracks.AdvanceTime()
		self.tracks.Refresh()
		self.tracks.Update()
		
		if self.dataStream:
			self.dataStream.setTimeNormalized(self.tracks.GetTimeInSplit())

	def OnFrameEvent(self,e):
		if time.time() - self.lasttime > 0.04 :
			self.TimeStep()
			self.lasttime = time.time()

	# called every frame, used to advance the time when playing motions
	def Update(self):
		print "update"
		wx.Frame.Update(self)
		self.TimeStep()


# a call back object for piavca that updates the interface
class AnimationInterfaceCallback:
	def __init__(self, Window):
		self.interface = Window
	def callbackInit(self, core):
		print "starting callback"
	def callbackMethod(self, core, time):
		pass
		#print "in callback"
		#self.interface.TimeStep()

