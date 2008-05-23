

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
	defaultLength = 100.0
	updateflag = False
	
	def __init__(self, frontend):
		self.frontend = frontend
		Piavca.Core.getCore().setAutoTimeOff()
		self.setRange(0.0,0.0)
			
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
		
	def clear(self):
		self.avatar = None
		motion = None
		submotion = None
		selectedSubMotion = None
		playing = False
		Piavca.clear()
		self.update()
		
	def save(self, filename):
		Piavca.XMLMotionFile.saveAll(filename)
		
	def update(self):
		self.updateflag = True
		#self.resetRange()
		#self.frontend.update()
		
	def timeUpdate(self):
		if abs(self.lastMotionLength - self.motion.getMotion().getMotionLength()) > 0.0001:
			self.resetRange()
			
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
	
	def getEvents(self):
		if self.avatar:
			return Piavca.getEvents(self.avatar)
		else:
			return []
	
	def triggerEvent(self, event):
		if self.avatar:
			self.avatar.event(event)
	
	def PublishEvents(self, evt=None):
		if self.getCurrentSubMotionProxy():
			self.getCurrentSubMotionProxy().PublishEvents()
			
	def setMotion(self, motionname):
		self.setTimeFraction(0.0)
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
			self.motion = MotionProxy(motion, self)#motion
			self.submotion = self.motion
			print "avatar", self.avatar
			if self.avatar:
				print "playing", self.avatar, self.motion
				self.avatar.playMotionDirect(self.motion.getMotion())
			self.resetRange()
			self.update()
			
	def setSubMotion(self, motionproxy):
		self.submotion = motionproxy
		self.update()
		
	def resetRange(self):
		if self.motion:
			length = self.motion.getMotion().getMotionLength()
			if length < 0:
				length = self.defaultLength
			self.setRange(0.0, length)
		else:
			self.setRange(0.0,0.0)
		
	def setRange(self, start, end):
		self.range = (start, end)
		if self.motion:
			self.lastMotionLength = self.motion.getMotion().getMotionLength()
		else:
			self.lastMotionLength = None
		
	def getRange(self):
		return self.range
			
	def getRangeFraction(self):
		return (self.getTimeFraction(self.range[0]), self.getTimeFraction(self.range[1]))
	
	def setRangeFraction(self, start, end):
		self.setRange(self.getTimeFromFraction(start), self.getTimeFromFraction(end))
			
	def getMotion(self):
		return self.motion.getMotion()		
	
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
		return self.motion

	def getCurrentSubMotionProxy(self):
		print "getting proxy for", self.submotion
		return self.submotion
			
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

	def Delete(self, evt=None):
		
		if self.getCurrentSubMotionProxy():
			self.getCurrentSubMotionProxy().delete()
	
	def playpause(self):
		self.playing = not self.playing
		self.lastTime = Piavca.Core.getCore().getSystemTime()
		
	def getPlaying(self):
		return self.playing
		
	def setTime(self, t):
		Piavca.Core.getCore().setCurrentTime(t)
		
	def setTimeFraction(self, t):
		if self.motion:
			self.setTime(self.getTimeFromFraction(t))
		
	def getTime(self):
		return Piavca.getTime()
		
	def getTimeFraction(self, t = None):
		if self.motion:
			if t == None:
				t = self.getTime()
			if self.motion.getMotion().getMotionLength() > 0.00001:
				t = t/self.motion.getMotion().getMotionLength()
			elif self.motion.getMotion().getMotionLength() < 0:
				t = t/self.defaultLength
			else:
				t = 0.0
			return t
		else:
			return 0
		
	def getTimeFromFraction(self, t):
		if self.motion:
			length = self.motion.getMotion().getMotionLength()
			if length < 0:
				length = self.defaultLength
			return t*length
		else:
			return t
		
		
	def timeStep(self):
		if self.updateflag:
			self.updateflag = False
			self.resetRange()
			self.frontend.update()
			
		if self.playing  and self.motion:
			if self.range[1] - self.range[0] <= 0.0:
				self.setTime(0.0+self.range[0])
			newtime = self.getTime()
			newtime += Piavca.Core.getCore().getSystemTime() - self.lastTime
			#print "time step", newtime
			self.lastTime = Piavca.Core.getCore().getSystemTime()
			#while newtime > self.motion.getMotionLength() :
			#	newtime -= self.motion.getMotionLength()
			while newtime > self.range[1] :
				newtime -= self.range[1]
				newtime += self.range[0]
			self.setTime(newtime)
		
	
		