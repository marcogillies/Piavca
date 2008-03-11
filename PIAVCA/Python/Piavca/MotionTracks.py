
import wx

import Piavca
try:
	import SlowSubSpace
	SlowSubspaceAvailable = 1
except:
	SlowSubspaceAvailable = 0
	
import Track
#import ComponentAnalysis

#from wx import *
from wx.lib.dialogs import *
#import MotionGraph

default_tracks={"Arms": ["LShoulder", "LUpperArm", "LForeArm", "LHand", "RShoulder", "RUpperArm", "RForeArm", "RHand"], "Legs":["LThigh", "LCalf", "LFoot", "RThigh", "RCalf", "RFoot"], "Head": ["Head", "Neck"] }

# A display of a motion divided into sub tracks which display
# different tracks
class MotionTracks(wx.VListBox):
	
	def __init__(self, avatar, motion, motion_name, tracksFile, parent, id):
		# the MotionTracks are based on the wxPython VListBox
		print "list constructor"
		wx.VListBox.__init__(self, parent, id)
		print "after parent constructor"

		self.distancemeasure = None

		# the Motion tracks will control time in Piavca, not 
		# the piavca timer
		Piavca.Core.getCore().setAutoTimeOff()
		self.showfootplants = 0
		self.SetTime(0)
		self.playing = 0
		
		# the avatar the motion is played on
		self.avatar = avatar
		# the motion being analysed
		self.motion = motion
		self.motion_name = motion_name
		self.motiongraph = None
		# play the motion on the avatar
		self.avatar.playMotionDirect(motion)

		# set up the parameters of the tracks
		self.track_height = 20
		self.name_length = 60
		self.track_length = Track.TimeToPosition(motion.getMotionLength())
		print "track length", self.track_length
		self.selectedTrack = None
		# read in a specification of which tracks to use
		self.ReadTracks(tracksFile)
		
		# the last track that the user interacted with 
		# (for undoing)
		self.LastClickedTrack = None

		# the size of the window
		windowlength = self.GetLength()
		windowheight = self.GetHeight()
		self.SetSize(wx.Size(windowlength, windowheight))
		print "end of list constructor"
		print "item count", self.GetItemCount()

		# start without any Principal Components
		#self.pcs = ComponentAnalysis.ComponentAnalysis()
		self.pcs = None
		try:
			self.pcs = Piavca.PCAMotion()
		except:
			pass
			
	# the physical length (in pixels) of the tracks
	def GetLength(self):
		return self.name_length + self.track_length
		
	# the height of the window
	def GetHeight(self):
		return len(self.tracks)*self.track_height

	# convert beween a position in the window and a time
	def PositionToTime(self, pos):
		return pos*self.frames_per_second
	
	def GetMotionLength(self):
		return self.PositionToTime(self.GetLength())

	# read in a specification of which tracks to use from file
	def ReadTracks(self, tracksFile):
		self.tracks = []
		self.tracks.append(Track.Track(self.motion, "All", None))
		try:
			file = open(tracksFile, 'r')
			# each line contains a name for the track 
			# followed by a list of joint names
			for line in file.readlines():
				joints = line.split()
				self.tracks.append(Track.Track(self.motion, joints[0], joints[1:]))
			print "tracks from file"
		except IOError:
			for trackname in default_tracks.keys():
				self.tracks.append(Track.Track(self.motion, trackname, default_tracks[trackname]))
		print "tracks used", self.tracks
		self.SetItemCount(len(self.tracks))

	# the height of an individual track (they are all the same height)
	def OnMeasureItem (self, i):
		return self.track_height

	# the background is drawn in white
	def OnDrawBackground(self, dc, rect, item):
		#print "drawing background", item
		if item == self.selectedTrack :
			dc.SetBrush(wx.Brush("orange"))
		else:
			dc.SetBrush(wx.Brush("white"))
		dc.DrawRectangle(rect.GetX(), rect.GetY(), rect.GetWidth(), rect.GetHeight())
		
		dc.SetBrush(wx.Brush("blue"))
		dc.DrawRectangle(Track.TimeToPosition(self.time)+self.name_length, rect.GetTop(), 5, rect.GetHeight())

	# the tracks themselves handle drawing their own representation
	def OnDrawItem (self, dc, rect, item):
		#print "drawing", item
		namerect = wx.Rect(rect.GetX()+5, rect.GetY(), self.name_length-5, rect.GetHeight())
		dc.DrawLabel(self.tracks[item].GetName(), namerect)
		trackrect = wx.Rect(rect.GetX() + self.name_length, rect.GetY(), rect.GetWidth() - self.name_length, rect.GetHeight())
		return self.tracks[item].OnDraw(dc, trackrect, self.name_length)
	
	# when a track is selected you should play that track on the avatar
	def PlayTrack(self, track):
		Piavca.Core.getCore().setCurrentTime(0)
		self.avatar.playMotionDirect(self.tracks[track].GetMotion())
		Piavca.Core.getCore().setCurrentTime(self.time)

	# called when the user clicks on a track
	def AddPoint (self, x, y):
		print "adding point", x, Track.PositionToTime(x)
		# work out which track is clicked and then pass on the event 
		# to that track
		i = y/self.track_height
		if( i < len(self.tracks) and x > self.name_length):
			self.LastClickedTrack = self.tracks[i]
			self.tracks[i].AddPoint(Track.PositionToTime(x-self.name_length))
			# if the track clicked on is the currently playing track
			# reload it so that any changes are taken account of
			if i == self.selectedTrack :
				self.PlayTrack(i)
			self.Refresh()

	
	def Undo (self):
		if self.LastClickedTrack != None :
			self.LastClickedTrack.UndoAddPoint()
			self.Refresh()

	# choose a track to play
	def SelectTrack(self, i):
		if i < len(self.tracks) :
			self.selectedTrack = i
			self.PlayTrack(i)

	# set the current time 
	def SetTime(self, t):
		self.time = t
		Piavca.Core.getCore().setCurrentTime(t)
		if self.distancemeasure != None:
			print self.distancemeasure(self.reference_time, t*25, self.framearray)
		if self.showfootplants:
			if self.avatar:
				jointId = Piavca.Core.getCore().getJointId("RFoot")
				#print "right foot",
				new_right = self.avatar.getJointBasePosition(jointId, Piavca.WORLD_COORD)
				diff = new_right - self.prev_right
				#print diff.mag(), 
				if diff.mag() > 0.1:
					print "right foot moving"
				self.prev_right = new_right
				jointId = Piavca.Core.getCore().getJointId("LFoot")
				print "left foot",
				new_left =  self.avatar.getJointBasePosition(jointId, Piavca.WORLD_COORD)
				diff = new_left - self.prev_left
				#print diff.mag()
				if diff.mag() > 0.1:
					print "left foot moving"
				self.prev_left = new_left
				
	def GetTime(self):
		return self.time
	
	def GetTimeInSplit(self):
		if self.selectedTrack == None:
			#print "no selected track"
			return float(self.GetTime())/self.motion.getMotionLength()
		splits = self.tracks[self.selectedTrack].GetSplits()
		if len(splits) == 0:
			#print "no splits"
			return float(self.GetTime())/self.motion.getMotionLength()
		t = self.GetTime()
		#for split in splits:
			#print split.GetStart(), split.GetEnd()
		if t < splits[0].GetStart():
			#print "before start"
			return 0
		for i in range(len(splits)-1):
			if t >= splits[i].GetStart() and t < splits[i+1].GetStart() :
				#print "in internal split"
				return float(t - splits[i].GetStart())/(splits[i].GetEnd() - splits[i].GetStart())
		return float(t - splits[-1].GetStart())/(splits[-1].GetEnd() - splits[-1].GetStart())
		

	# start playing the motion
	def Play(self):
		print "play"
		self.startTime = Piavca.Core.getCore().getSystemTime() - self.time
		self.playing = 1

	# stop (pause) playing the motion
	def Stop(self):
		print "stop"
		self.playing = 0
		
	def Save(self):
		if self.selectedTrack == None:
			return
		
		dialog_return = saveFileDialog()
		path = dialog_return.paths[0]
		if path == "":
			return
		
		#dialog = wxFileDialog ( None, style = wxSAVE )
		# The user pressed the "OK" button in the dialog
		#if dialog.ShowModal() == wxID_OK:
		#	print 'Position of selection:', dialog.GetPath()
		#	path = dialog.GetPath()
		#	dotpos = path.rfind(".")
		#	scriptpath = path[:dotpos]+".act"
		#else:
		#	path = None
		#	print 'You did not select anything.'
		#	return
		#dialog.Destroy()
		
		#preloaded = [(self.motion, self.motion_name)]
		
		# save the motion pack file
		motstosave = []
		motion = self.tracks[self.selectedTrack].GetMotion()
		if self.tracks[self.selectedTrack].IsMasked():
			if motion.getName() == "":
				motion.setName(self.motion_name+"_masked")
			motstosave.append(motion)
		splits = self.tracks[self.selectedTrack].GetSplits()
		for i, split in enumerate(splits):
			mot = Piavca.SubMotion(motion, split.GetStart(), split.GetEnd())
			mot.setName(self.motion_name+"_split_"+str(i))
			motstosave.append(mot)
		if self.motiongraph:
			if self.motiongraph.getName() == "":
				self.motiongraph.setName(self.motion_name+"_motiongraph")
			motstosave.append(self.motiongraph)
		Piavca.XMLMotionFile.saveMotions(path, motstosave)
		
		# save the scripts file
		dotpos = path.rfind(".")
		scriptpath = path[:dotpos]+".act"
		scriptfile = open(scriptpath, "w")
		for motion in motstosave:
			scriptfile.write("script ")
			scriptfile.write(motion.getName())
			scriptfile.write("\n")
			
			scriptfile.write("0 motion ")
			scriptfile.write(motion.getName())
			scriptfile.write("\n")
			
			scriptfile.write("stop\n")
		scriptfile.close()
		
		# save the main conf file
		confpath = path[:dotpos]+".conf"
		conffile = open(confpath, "w")
		
		conffile.write("avatar ")
		conffile.write(self.avatar.getName())
		conffile.write("\n")
		
		conffile.write("motionpack default ")
		slashpos = path.rfind("\\")
		if slashpos < 0:
			slashpos = path.rfind("/")
		if slashpos < 0:
			slashpos = 0
		conffile.write(path[slashpos+1:])
		conffile.write("\n")
		
		conffile.write("script default ")
		slashpos = scriptpath.rfind("\\")
		if slashpos < 0:
			slashpos = scriptpath.rfind("/")
		if slashpos < 0:
			slashpos = 0
		conffile.write(scriptpath[slashpos+1:])
		conffile.write("\n")
		
		conffile.write("GUI ")
		conffile.write(self.avatar.getName())
		conffile.write("\n")
		
		conffile.close()
		
		
	def showFootplants(self, e):
		self.showfootplants = 1
		jointId = Piavca.Core.getCore().getJointId("RFoot")
		self.prev_right = self.avatar.getJointBasePosition(jointId, Piavca.WORLD_COORD)
		jointId = Piavca.Core.getCore().getJointId("LFoot")
		self.prev_left = self.avatar.getJointBasePosition(jointId, Piavca.WORLD_COORD)
		
	
	# perform a PCA on the current Track
	def PCA (self):
		if self.pcs == None:
			print "CANNOT DO PCA, scipy isn't loaded"
		print "doing pca"
		motion = self.tracks[self.selectedTrack].GetMotion()
		splits = self.tracks[self.selectedTrack].GetSplits()
		motions = [Piavca.SubMotion(motion, split.GetStart(), split.GetEnd()) for split in splits]
		splits = [(0, split.GetStart(), split.GetEnd()) for split in splits]
		length = Track.PositionToTime(self.track_length)*Track.frames_per_second
		#self.pcs.do_pca([motion], splits, length, Track.frames_per_second)
		self.pcs.addMotions(motions)
		self.pcs.setFramesPerSecond(Track.frames_per_second)
		self.pcs.create()
		#self.pcs.setMotion(motion)
		
		# load the PCAs into the avatar to play them
		Piavca.Core.getCore().setCurrentTime(0)
		#self.avatar.playMotionDirect(Piavca.PyMotion(self.pcs))
		self.avatar.playMotionDirect(self.pcs)
		Piavca.Core.getCore().setCurrentTime(self.time)
		
	def VQ(self):
		pass
		#if self.pcs != None:
		#	self.pcs.
		
	def setPCWeight(self, i, v):
		if self.pcs == None:
			print "CANNOT DO PCA, scipy isn't loaded"
		self.pcs.setWeight(i,v)
		
	def setPCQuant(self, i):
		self.pcs.showQuant(i)
		
	def ProjectMotion(self):
		if self.pcs == None:
			print "CANNOT DO PCA, scipy isn't loaded"
		#self.pcs.projectMotion(self.tracks[self.selectedTrack].GetMotion())
		motion = self.tracks[self.selectedTrack].GetMotion()
		self.pcs.setMotion(motion)
		
	def ProjectSubtract(self):
		if self.pcs == None:
			print "CANNOT DO PCA, scipy isn't loaded"
		#self.pcs.projectMotion(self.tracks[self.selectedTrack].GetMotion())
		motion = self.tracks[self.selectedTrack].GetMotion()
		self.pcs.setMotion(motion)
		
		Piavca.Core.getCore().setCurrentTime(0)
		#self.avatar.playMotionDirect(Piavca.PyMotion(self.pcs))
		self.avatar.playMotionDirect(Piavca.Subtract(motion, self.pcs))
		Piavca.Core.getCore().setCurrentTime(self.time)
		
	def AddPCSToMotion(self):
		if self.pcs == None:
			print "CANNOT DO PCA, scipy isn't loaded"
		motion = self.tracks[self.selectedTrack].GetMotion()
		newpcs = self.pcs.clone()
		newpcs.setMotion(motion)
		self.pcs.setMotion(None)
		
		Piavca.Core.getCore().setCurrentTime(0)
		#self.avatar.playMotionDirect(Piavca.PyMotion(self.pcs))
		#self.avatar.playMotionDirect(Piavca.Subtract(motion, self.pcs))
		#self.avatar.playMotionDirect(self.pcs)
		self.avatar.playMotionDirect(Piavca.MotionAdder(self.pcs, Piavca.Subtract(motion, newpcs)))
		Piavca.Core.getCore().setCurrentTime(self.time)

	# perform a PCA on the current Track
	def LoadPCA (self):#, filename):
		if self.pcs == None:
			print "CANNOT DO PCA, scipy isn't loaded"

		dialog_return = openFileDialog()
		path = dialog_return.paths[0]
		if path == "":
			path = "pcs.txt"

		self.pcs.setFilename(path)
		self.pcs.create()
		#self.pcs.Load(filename)
		
		# load the PCAs into the avatar to play them
		Piavca.Core.getCore().setCurrentTime(0)
		#self.avatar.playMotionDirect(Piavca.PyMotion(self.pcs))
		self.avatar.playMotionDirect(self.pcs)
		Piavca.Core.getCore().setCurrentTime(self.time)
			
	# pefrom a slow subspace analysis on the current track
	def SlowSubspace (self):
		if self.pcs == None:
			print "CANNOT DO PCA, scipy isn't loaded"
		print "doing slow subspace"
		motion = self.tracks[self.selectedTrack].GetMotion()
		splits = self.tracks[self.selectedTrack].GetSplits()
		motions = [Piavca.SubMotion(motion, split.GetStart(), split.GetEnd()) for split in splits]
		splits = [(0, split.GetStart(), split.GetEnd()) for split in splits]
		length = Track.PositionToTime(self.track_length)*Track.frames_per_second
		
		#self.pcs.do_pca([motion], splits, length, Track.frames_per_second)
		self.pcs.addMotions(motions)
		self.pcs.setFramesPerSecond(Track.frames_per_second)
		
		ssa = SlowSubSpace.SlowSubSpace()
		
		val = None
		dialog = wxTextEntryDialog ( None, message="enter slow subspace trade off (alpha)" )
		dialog.SetValue("0.2")
		# The user pressed the "OK" button in the dialog
		if dialog.ShowModal() == wxID_OK:
			print 'Position of selection:', dialog.GetValue()
			val = float(dialog.GetValue())
			print val
		else:
			path = None
			print 'You did not select anything.'
		dialog.Destroy()
		if val != None:
			ssa.setAlpha(val)
			
		val = None
		dialog = wxTextEntryDialog ( None, message="enter percentage to keep" )
		dialog.SetValue("0.99")
		# The user pressed the "OK" button in the dialog
		if dialog.ShowModal() == wxID_OK:
			print 'Position of selection:', dialog.GetValue()
			val = float(dialog.GetValue())
			print val
		else:
			path = None
			print 'You did not select anything.'
		dialog.Destroy()
		if val != None:
			ssa.setPercentageToKeep(val)
			
		self.pcs.setAnalysis(ssa)
		self.pcs.create()
		#self.pcs.setMotion(motion)
		
		# load the PCAs into the avatar to play them
		Piavca.Core.getCore().setCurrentTime(0)
		#self.avatar.playMotionDirect(Piavca.PyMotion(self.pcs))
		self.avatar.playMotionDirect(self.pcs)
		Piavca.Core.getCore().setCurrentTime(self.time)
	
	# move the time forward, when we are playing
	def AdvanceTime(self):
		if(self.playing):
			newtime = Piavca.Core.getCore().getSystemTime() - self.startTime
			while newtime > Track.PositionToTime(self.track_length) :
				newtime -= Track.PositionToTime(self.track_length)
			self.SetTime(newtime)

	def ShowDistances(self, e):
		weights = []
		file = open("TrackWeights.txt", "r")
		for line in file.readlines():
			for joint in line.split():
				joint = joint.split("=")
				weight = float(joint[1])
				joint = joint[0]
				jointid = Piavca.Core.getCore().getJointId(joint)
				print joint, jointid, weight
				if( not self.motion.isNull(jointid)):
					weights.append((jointid, float(1.0)))
		self.distancemeasure = Piavca.DistanceMeasure(10, weights)
		self.framearray = Piavca.makeFrameArray(self.motion, 25.0)
		self.reference_time = self.time

	def MotionGraph(self, e):
		weights = []
		file = open("TrackWeights.txt", "r")
		for line in file.readlines():
			for joint in line.split():
				joint = joint.split("=")
				weight = float(joint[1])
				joint = joint[0]
				jointid = Piavca.Core.getCore().getJointId(joint)
				print joint, jointid, weight
				if( not self.motion.isNull(jointid)):
					weights.append((jointid, float(1.0)))
		#distancemeasure = MotionGraph.DistanceMeasure(10, weights)
		print "creating distance measure"
		distancemeasure = Piavca.DistanceMeasure(weights)
		#loading motions
		motions = []
		if self.selectedTrack != None:
			splits = self.tracks[self.selectedTrack].GetSplits()
			if splits != []:
				for split in splits:
					motions.append(split.GetSubMotion())
			else:
				motions.append(self.motion)
		print "creating graph"
		self.motiongraph = Piavca.MotionGraph(motions)
		
		val = 4.0#None
		#dialog = wxTextEntryDialog ( None, message="enter same motion threshold" )
		#dialog.SetValue("4")
		# The user pressed the "OK" button in the dialog
		#if dialog.ShowModal() == wxID_OK:
		#	print 'Position of selection:', dialog.GetValue()
		#	val = float(dialog.GetValue())
		#	print val
		#else:
		#	path = None
		#	print 'You did not select anything.'
		#dialog.Destroy()
		if val != None:
			self.motiongraph.setThresholdSame(val)
		
		val = 4.0#None
		#dialog = wxTextEntryDialog ( None, message="enter different motion threshold" )
		#dialog.SetValue("4")
		# The user pressed the "OK" button in the dialog
		#if dialog.ShowModal() == wxID_OK:
		#	print 'Position of selection:', dialog.GetValue()
		#	val = float(dialog.GetValue())
		#	print val
		#else:
		#	path = None
		#	print 'You did not select anything.'
		#dialog.Destroy()
		if val != None:
			self.motiongraph.setThresholdDiff(val)
		
		#self.motiongraph.constructGraph(distancemeasure, 12, 20, 10)
		self.motiongraph.setJointWeightsFile("TrackWeights.txt")
		self.motiongraph.setFPS(10)
		self.motiongraph.create()
		
		# load the Motion Graph into the avatar to play them
		Piavca.Core.getCore().setCurrentTime(0)
		self.avatar.playMotionDirect(self.motiongraph)
		Piavca.Core.getCore().setCurrentTime(self.time)
	
	def SaveMotionGraph(self,e):
		try:
			dialog = wxFileDialog ( None, style = wxSAVE )
			# The user pressed the "OK" button in the dialog
			if dialog.ShowModal() == wxID_OK:
				print 'Position of selection:', dialog.GetPath()
				path = dialog.GetPath()
			else:
				path = None
				print 'You did not select anything.'
			dialog.Destroy()
		except:
			path = "motiongraph.pik"
		
		if path != None:
			self.motiongraph.saveGraph(path)
	
	def LoadMotionGraph(self,e):
		motions = []
		if self.selectedTrack != None:
			splits = self.tracks[self.selectedTrack].GetSplits()
			if splits != []:
				for split in splits:
					motions.append(split.GetSubMotion())
			else:
				motions.append(self.motion)
		self.motiongraph = Piavca.MotionGraph(motions)
		self.motiongraph.loadGraph("motiongraph.txt")
		
		# load the Motion Graph into the avatar to play them
		Piavca.Core.getCore().setCurrentTime(0)
		self.avatar.playMotionDirect(self.motiongraph)
		Piavca.Core.getCore().setCurrentTime(self.time)
	

	# left clicking does one of 2 things
	# If it is in the name area it selects a track
	# if it is in the track area it changes the current time
	def OnLeftClick (self, x, y):
		print "OnLeftClick"
		self.restartPlaying = 0
		if x < self.name_length :
			i = y/self.track_height
			if( i < len(self.tracks)):
				self.SelectTrack(i)
		else:
			self.SetTime(Track.PositionToTime(x-self.name_length))
			# restart playing to get make sure it plays from the new time
			if self.playing:
				self.Stop()
				self.restartPlaying = 1
			else:
				self.restartPlaying = 0
				

	# moving the mouse with the left button held down changes the current time
	def OnMouseMove (self, x, y):
		self.SetTime(Track.PositionToTime(x-self.name_length))

	# when the left button comes up stop changing time and restart playing
	def OnLeftUp (self):
		# restart playing to get make sure it plays from the new time
		if self.restartPlaying:
			self.Play()
		

	# right clicking creates splits in the track
	def OnRightClick (self, x, y):
		if x < self.name_length :
			pass
		else:
			self.AddPoint(x, y)


	# save the motion corresponding to the current track to file
	#def Save(self):
	#	self.tracks[self.selectedTrack].Save()

	# saves the current split settings
	def SaveSplits (self):
		self.tracks[self.selectedTrack].SaveSplits()

	# loads the split settings from file
	def LoadSplits (self):
		self.tracks[self.selectedTrack].LoadSplits()
		
