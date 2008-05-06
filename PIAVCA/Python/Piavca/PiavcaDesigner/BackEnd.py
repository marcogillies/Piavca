

from wx.lib.dialogs import *

import time, types

import Piavca
import Piavca.XMLMotionFile

from MotionProxy import MotionProxy

class BackEnd:
	avatar = None
	motion = None
	submotion = None
	selectedSubMotion = None
	playing = False
	
	def __init__(self, frontend):
		self.frontend = frontend
		Piavca.Core.getCore().setAutoTimeOff()
			
	def readfile(self, filename):
		if filename[-4:] == ".cfg":
			self.avatar = Piavca.Avatar(filename[:-4])
		else:
			Piavca.XMLMotionFile.parse(filename)
		if self.avatar == None:
			print self.getAvatarNames()
			print self.getMotionNames()
			if len(self.getAvatarNames()) > 0:
				self.setAvatar(self.getAvatarNames()[0])
		self.frontend.update()
		
	def update(self):
		self.frontend.update()
			
	def setAvatar(self, avatarname):
		avatar = Piavca.Core.getCore().getAvatar(str(avatarname.encode("latin-1")))
		if avatar == None:
			raise ValueError("no avatar named" + str(avatarname.encode("latin-1")))
		else:
			self.avatar = avatar
			self.update()
			
			
	def getAvatar(self):
		return self.avatar
			
	def getAvatarNames(self):
		core = Piavca.Core.getCore()
		return core.getAvatarNames()
			
	def setMotion(self, motionname):
		print "motion name", motionname, type(motionname)
		motion = self.getMotionByName(motionname)
		print "motion", motion
		if motion == None:
			raise ValueError("no motion named" + str(motionname))
		else:
			print "motion", motion, "ownership", motion.thisown
			if motion.getName() == "":
				dialog_return = textEntryDialog (message="Please enter a name for this motion")
				motion_name = dialog_return.text.encode("latin-1")
				Piavca.loadMotion(motion_name, motion)
			self.motion = motion
			self.submotion = motion
			print "avatar", self.avatar
			if self.avatar:
				print "playing", self.avatar, self.motion
				self.avatar.playMotionDirect(self.motion)
			self.update()
			
	def setSubMotion(self, motion):
		self.submotion = motion
		self.update()
			
	def getMotion(self):
		return self.motion		
	
	def getMotionByName(self, name):
		if name[:10] == "__Type__::":
			typename = name[10:]
			cl = getattr(Piavca, typename)
			if type(cl) == types.TypeType and issubclass(cl, Piavca.Motion):
				motion =  cl()
				motion.thisown = False
				motion.Reference()
				return motion
			else:
				ValueError(typename+" is not a motion class")
		else:
			print "motion name", name, type(name)
			motion = Piavca.getMotion(str(name.encode("latin-1")))
			if motion == None:
				raise ValueError("no motion named" + str(name))
			else:
				return motion
	
	def getMotionProxy(self, motion):
		if type(motion) == "":
			motion = Piavca.getMotion(str(motion))
		if motion == None:
			return None
		else:
			return MotionProxy(motion, self)

	def getCurrentMotionProxy(self):
		print "getting proxy for", self.motion
		return self.getMotionProxy(self.motion)

	def getCurrentSubMotionProxy(self):
		print "getting proxy for", self.submotion
		return self.getMotionProxy(self.submotion)
			
	def getMotionNames(self):
		core = Piavca.Core.getCore()
		motionnames = core.getMotionNames()
		return  motionnames
	
	def getMotionTypeNames(self):
		return Piavca.XMLMotionFile.getMotionTypeNames()
	
	def addSubMotion(self, motiontype):
		pass
	
	def addSubMotionByType(self, motiontypename):
		pass
	
	def playpause(self):
		self.playing = not self.playing
		self.lastTime = Piavca.Core.getCore().getSystemTime()
		
	def getPlaying(self):
		return self.playing
		
	def setTime(self, t):
		Piavca.Core.getCore().setCurrentTime(t)
		
	def setTimeFraction(self, t):
		if self.motion:
			t = t*self.motion.getMotionLength()
			self.setTime(t)
		
	def getTime(self):
		return Piavca.getTime()
		
	def getTimeFraction(self):
		if self.motion:
			t = self.getTime()
			if self.motion.getMotionLength() > 0.00001:
				t = t/self.motion.getMotionLength()
			else:
				t = 0.0
			return t
		else:
			return 0
		
	def timeStep(self):
		if self.playing  and self.motion:
			newtime = self.getTime()
			newtime += Piavca.Core.getCore().getSystemTime() - self.lastTime
			self.lastTime = Piavca.Core.getCore().getSystemTime()
			while newtime > self.motion.getMotionLength() :
				newtime -= self.motion.getMotionLength()
			self.setTime(newtime)
		
	
		