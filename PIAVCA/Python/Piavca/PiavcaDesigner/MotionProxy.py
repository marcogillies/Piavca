
import Piavca



class MotionProxy:
	def __init__(self, motion, backend):
		self.motion = motion
		self.motion.Reference()
		self.motion.thisown = False
		self.backend = backend
		
#		motiontype = None
#		motiontypes = []
#		motiontypename = "unknown"
#		for key in allPiavca.keys():
#			if type(allPiavca[key]) == types.TypeType and isinstance(motion, allPiavca[key]):
#				motiontypes.append(allPiavca[key])
#				if motiontype == None or issubclass(allPiavca[key], motiontype):
#					motiontype = allPiavca[key]
#					motiontypename = key
		
	def getName(self):
		print "motion", self.motion, self.motion.thisown
		return type(self.motion).__name__ + "  " + self.motion.getName()
	
	def select(self):
		self.backend.setSubMotion(self.motion)
	
	def getChildren(self):
		motion = self.motion
		motionlist = []
		if hasattr(motion, "getNumMotions"):
			n = motion.getNumMotions()
			for i in range(n):
				m = motion.getMotionByIndex(i)
				m = Piavca.getRealMotionType(m)
				motionlist.append(MotionProxy(m, self.backend))
		elif hasattr(motion, "getMotion1"):
			m = motion.getMotion1()
			m = Piavca.getRealMotionType(m)
			if m != None:
				motionlist.append(MotionProxy(m, self.backend))
			m = motion.getMotion2()
			m = Piavca.getRealMotionType(m)
			if m != None:
				motionlist.append(MotionProxy(m, self.backend))
		elif hasattr(motion, "getMotion"):
			m = motion.getMotion()
			m = Piavca.getRealMotionType(m)
			if m != None:
				motionlist.append(MotionProxy(m, self.backend))
		return motionlist
	
	def addChild(self, name):
		print "adding child", name
		newmotion = self.backend.getMotionByName(name)
		print newmotion
		if hasattr(self.motion, "addMotion"):
			self.motion.addMotion(newmotion)
		elif hasattr(self.motion, "setMotion"):
			self.motion.setMotion(newmotion)
		elif hasattr(self.motion, "setMotion1"):
			if self.motion.getMotion1():
				self.motion.setMotion2(newmotion)
			else:
				self.motion.setMotion1(newmotion)
			#raise NotImplementedError("don't know what to do with adding to two motion combiners")
		#self.backend.update()
	
	def getParameters(self):
		parameters = {}
		
		mtype = type(self.motion)
		for key in mtype.__dict__.keys():
			if key[:3] == "get":
				print key
				if hasattr(self.motion, "set" + key[3:]):
					print key
					method = getattr(self.motion, key)
					value = method()
					print key[3:], value
					parameters[key[3:]] = value
		return parameters
	
	def getParameterVal(self, name):
		if hasattr(self.motion, "get" + name):
			method = getattr(self.motion, "get" + name)
			val = method()
			print "getting ", name, "=", val
			return val
		else:
			return None
		
	def setParameterVal(self, name, val):
		print "setting ", name, "=", val, type(val)
		method = getattr(self.motion, "set" + name)
		return method(val)
	
	def setRange(self):
		start, end = self.backend.getRange()
		start += self.motion.getStart()
		end += self.motion.getStart()
		self.motion.setStart(start)
		self.motion.setEnd(end)
		self.backend.resetRange()
		self.backend.update()
	
	def resetRange(self):
		self.motion.setStart(0)
		self.motion.setEnd(-1)
		self.backend.resetRange()
		self.backend.update()
		
	def PublishEvents(self):
		print self.motion.getEventNames()
		Piavca.addEvents(self.motion.getEventNames())
		print Piavca.getEvents()
		self.backend.update()
					