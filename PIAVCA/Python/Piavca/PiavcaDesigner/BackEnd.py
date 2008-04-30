
import time

import Piavca
import Piavca.XMLMotionFile

class BackEnd:
	avatar = None
	motion = None
	selectedSubMotion = None
	playing = False
	
	def __init__(self, frontend, filename=None):
		self.frontend = frontend
		if filename != None:
			self.readfile(filename)
		Piavca.Core.getCore().setAutoTimeOff()
			
	def readfile(self, filename):
		if filename[-4:] == ".cfg":
			self.avatar = Piavca.Avatar(filename[:-4])
		else:
			Piavca.XMLMotionFile.parse(filename)
			
	def setAvatar(self, avatarname):
		avatar = Piavca.Core.getCore().getAvatar(avatarname)
		if avatar == None:
			raise ValueError("no avatar named" + str(avatarname))
		else:
			self.avatar = avatar
			self.frontend.update()
			
			
	def getAvatar(self):
		return self.avatar
			
	def getAvatarNames(self):
		core = Piavca.Core.getCore()
		return core.getAvatarNames()
			
	def setMotion(self, motionname):
		print "motion name", motionname, type(motionname)
		motion = Piavca.Core.getCore().getMotion(str(motionname.encode("latin-1")))
		if motion == None:
			raise ValueError("no motion named" + str(avatarname))
		else:
			self.motion = motion
			self.avatar.playMotionDirect(self.motion)
			self.frontend.update()
			
	def getMotion(self):
		return self.motion		
			
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
			t = t/self.motion.getMotionLength()
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
		
	
		