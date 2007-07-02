
import wx
import string

import Piavca

import Split

frames_per_second = 24.0
pixels_per_frame = 5.0

# convert between times in seconds and positions on the time sliders
def TimeToPosition(pos):
	return pos*frames_per_second*pixels_per_frame

def PositionToTime(pos):
	return pos/(frames_per_second*pixels_per_frame)

# a graphical representation of a subtrack of a motion
# a subtrack is the motion played on a subset of the joints
class Track :
	def __init__(self, motion,  name, joints):
		# name
		self.name = name
		# joint that the track shows
		#self.joints = joints

		# the set of subranges
		self.splits = []
		# last place clicked
		self.latestPoint = None

		if joints == None:
			self.motion = motion
			self.masked = 0
			return
		
		self.masked = 1
		
		# a piavca.MaskedMotion that implements playing only 
		# the specified joints
		maskedMotion = Piavca.MaskedMotion()
		#self.maskedMotion.setUseSecondary(0)
		maskedMotion.setMotion(motion)
		self.motion = maskedMotion
		for joint in joints:
			print joint
			jointid = Piavca.Core.getCore().getJointId(joint)
			print joint, jointid
			maskedMotion.addToMask(jointid)

	def GetName(self):
		return self.name

	# gets a motion that plays only the specified tracks of 
	# the original motion
	def GetMotion(self):
		return self.motion

	# the splits (subranges) of the motion
	def GetSplits (self):
		return self.splits
		
	def IsMasked (self):
		return self.masked
	
	# called when some one clicks on the track
	# if its the first click, just mark the point, 
	# if its the second click, add a split between the last 
	# click and this one
	def AddPoint(self, x):
		print self.name, "adding point", x
		if self.latestPoint == None :
			self.latestPoint = x
		else:
			# create a new split between the last click and this one
			# (getting the order right)
			if(x > self.latestPoint):
				self.splits.append(Split.Split(self.motion, self.latestPoint, x))
			else:
				self.splits.append(Split.Split(self.motion, x, self.latestPoint))
			
			# add the split to the total motion represented by the track
			# If this is the first split, we need to replace the masked motion
			# with the current split, otherwise add the new split to the
			# previous ones
			#if self.motion == self.maskedMotion :
			#	self.motion = self.splits[-1].GetMotion()
			#else:
			#	self.motion = Piavca.MotionAdder(self.splits[-1].GetMotion(), self.motion)
			
			self.latestPoint = None

	# undo the last click
	def UndoAddPoint (self):
		if self.latestPoint == None :
			if len(self.splits) :
				self.splits.pop()
		else:
			self.latestPoint = None
		

	# the draw function of the track
	# this dipsplays the current splits etc.
	def OnDraw (self, dc, rect, offset):

		# draw the background bars
		dc.SetBrush(wx.Brush("pink"))
		for split in self.splits :
			left = TimeToPosition(split.GetStart()) + offset
			width = TimeToPosition(split.GetEnd() - split.GetStart())
			height = rect.GetHeight()
			top = rect.GetTop()
			dc.DrawRectangle(left, top, width, height)

		#draw the end points
		radius = rect.GetHeight()/2
		y = rect.GetTop() + radius
		x = rect.GetLeft()
		dc.SetBrush(wx.Brush("red"))
		#print "drawing", self.name
		# draw all the splits
		for split in self.splits:
			#print "split", TimeToPosition(split.GetStart()), TimeToPosition(split.GetEnd())
			dc.DrawRectangle(TimeToPosition(split.GetStart())+offset, rect.GetTop(), 5, rect.GetHeight())
			dc.DrawRectangle(TimeToPosition(split.GetEnd())+offset, rect.GetTop(), 5, rect.GetHeight())
			#dc.DrawCircle(split.GetStart(), y, radius)
			#dc.DrawCircle(split.GetEnd(), y, radius)
		# draw the last selected point
		if(self.latestPoint != None):
			dc.DrawRectangle(TimeToPosition(self.latestPoint)+offset, rect.GetTop(), 5, rect.GetHeight())
			#dc.DrawCircle(self.latestPoint, y, radius)

	# save the motion represented by the track
	def Save (self):
		i = 0
		for split in self.splits :
			filename = "split%d.paf" % i
			split.Save(filename)
			i += 1

	def SaveSplits (self):
		filename = "%s.txt" % self.GetName()
		print filename
		file = open (filename, "w")
		for split in self.splits:
			print split.GetStart(), split.GetEnd()
			file.write("%f %f, " % (split.GetStart(), split.GetEnd())) 
		file.close()

	def LoadSplits (self):
		filename = "%s.txt" % self.GetName()
		print filename
		file = open (filename, "r")
		lines = file.readlines()
		for line in lines :
			print line
			splits = string.split(line, ",")
			print splits
			self.splits = []
			for split in splits:
				if (split == ""):
					continue
				split = string.split(split)
				if split == []:
					continue
				print split
				split = Split.Split(self.motion, float(split[0]), float(split[1]))
				self.splits.append(split)
		for s in self.splits:
			print s
			
			
		
		

