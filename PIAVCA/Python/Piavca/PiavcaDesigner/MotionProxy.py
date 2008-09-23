
import Piavca



class MotionProxy:
	def __init__(self, motion, backend, parent=None):
		self.motion = motion
		self.motion.Reference()
		self.motion.thisown = False
		self.backend = backend
		self.parent = parent
		
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
		# print "motion proxy get name"
		#print "motion", self.motion, self.motion.thisown
		return type(self.motion).__name__ + "  " + self.motion.getName()
	
	def getMotion(self):
		return self.motion
	
	def select(self):
		self.backend.setSubMotion(self)
	
	def getChildren(self):
		motion = self.motion
		motionlist = []
		if hasattr(motion, "getNumMotions"):
			n = motion.getNumMotions()
			# print "number of children", n
			for i in range(n):
				m = motion.getMotionByIndex(i)
				m = Piavca.getRealMotionType(m)
				motionlist.append(MotionProxy(m, self.backend, self))
		elif hasattr(motion, "getMotion1"):
			m = motion.getMotion1()
			m = Piavca.getRealMotionType(m)
			if m != None:
				motionlist.append(MotionProxy(m, self.backend, self))
			m = motion.getMotion2()
			m = Piavca.getRealMotionType(m)
			if m != None:
				motionlist.append(MotionProxy(m, self.backend, self))
		elif hasattr(motion, "getMotion"):
			m = motion.getMotion()
			m = Piavca.getRealMotionType(m)
			if m != None:
				motionlist.append(MotionProxy(m, self.backend, self))
		# print "got motion list"
		return motionlist
	
	def addChild(self, name):
		# print "adding child", name
		newmotion = self.backend.getMotionByName(name)
		# print newmotion
		if newmotion == self.motion:
			print "can't add a motion to itself"
			return 
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
		
		# print "getting parameters"   
		mtype = type(self.motion)
		for key in dir(mtype):
			if key[:3] == "get" or key[:3] == "set":
				# print "parameter: ", key
				if parameters.has_key(key[3:]):
					continue
				val = self.getParameterVal(key[3:])
				if type(val) != type(None):
					parameters[key[3:]] = val
			
			# if key[:3] == "get":
				# print key, "set" + key[3:]
				# if hasattr(self.motion, "set" + key[3:]):
					# print key
					# if key[3:len("Motion")+3] == "Motion":
						# print "found Motion in paramname"
						# continue
					# if key[3:len("Weight")+3] == "Weight":
						# weights = [0 for i in range(self.motion.getNumMotions())]
						# for i in range(self.motion.getNumMotions()):
							# motName = self.motion.getMotion(i).getName()
							# weights[i] = (motName, self.motion.getWeight(i))
						# parameters[key[3:]] = weights
					# else:
						# method = getattr(self.motion, key)
						# print "got method"
						# value = method()
						# print "got value"
						# print key[3:], value
						# parameters[key[3:]] = value
			# if key == "setFloatValue" or key == "setQuatValue" or key == "setVecValue":
				# core = Piavca.Core.getCore()
				# names = [core.getTrackName(i) for i in range(core.getMinTrackId(), core.getMaxTrackId()+1)]
				# if key == "setFloatValue":
					# vals = [0.0 for n in names]
					# for i, n in enumerate(names):
						# if (not self.motion.isNull(i)) and self.motion.getTrackType(i) & Piavca.FLOAT_TYPE:
							# vals[i] = self.motion.getFloatValueAtTime(i,0)
				# if key == "setVecValue":
					# vals = [Piavca.Vec() for n in names]
					# for i, n in enumerate(names):
						# if (not self.motion.isNull(i)) and self.motion.getTrackType(i) & Piavca.VEC_TYPE:
							# vals[i] = self.motion.getVecValueAtTime(i,0)
				# if key == "setQuatValue":
					# vals = [Piavca.Quat() for n in names]
					# for i, n in enumerate(names):
						# if (not self.motion.isNull(i)) and self.motion.getTrackType(i) & Piavca.QUAT_TYPE:
							# vals[i] = self.motion.getQuattValueAtTime(i,0)
			
				# parameters[key[3:]] = zip(names, vals)
		# print "finished getting parameters"
		return parameters
	
	def getParameterVal(self, name):
		if hasattr(self.motion, "get" + name):
			# print name, "set" + name
			if hasattr(self.motion, "set" + name):
				# print name
				if name[:len("Motion")] == "Motion":
					# print "found Motion in paramname"
					return None
				if name[:len("Weight")] == "Weight":
					weights = [0 for i in range(self.motion.getNumMotions())]
					for i in range(self.motion.getNumMotions()):
						motName = self.motion.getMotion(i).getName()
						weights[i] = (i, motName, self.motion.getWeight(i))
					return weights
				else:
					method = getattr(self.motion, "get" + name)
					# print "got method"
					value = method()
					# print "got value"
					# print name, value
					return value
		if name == "FloatValue" or name == "QuatValue" or name == "VecValue":
			core = Piavca.Core.getCore()
			indices = [i for i in range(core.getMinTrackId(), core.getMaxTrackId()+1)]
			names = [core.getTrackName(i) for i in indices]
			if name == "FloatValue":
				vals = [0.0 for i in indices]
				for i, track in enumerate(indices):
					if (not self.motion.isNull(track)) and self.motion.getTrackType(track) & Piavca.FLOAT_TYPE:
						vals[i] = self.motion.getFloatValueAtTime(track,0)
			if name == "VecValue":
				vals = [Piavca.Vec() for i in indices]
				for i, track in enumerate(indices):
					if (not self.motion.isNull(track)) and self.motion.getTrackType(track) & Piavca.VEC_TYPE:
						vals[i] = self.motion.getVecValueAtTime(track,0)
			if name == "QuatValue":
				vals = [Piavca.Quat() for i in indices]
				for i, track in enumerate(indices):
					if (not self.motion.isNull(track)) and self.motion.getTrackType(track) & Piavca.QUAT_TYPE:
						vals[i] = self.motion.getQuattValueAtTime(track,0)
		
			return zip(indices, names, vals)
		
		else:
			return None
		
	def setParameterVal(self, name, val):
		#print "setting ", name, "=", val, type(val)
		method = getattr(self.motion, "set" + name)
		if type(val) == tuple:
			return method(val[0], val[1])
		else:
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
		if self.backend.getAvatar():
			Piavca.addEvents(self.backend.getAvatar(), self.motion.getEventNames())
			self.backend.update()
		
	def delete(self):
		print self.parent
		if not self.parent:
			print "no parent"
			return
		done = False
		parentMot = self.parent.getMotion()
		if hasattr(parentMot, "removeMotionByIndex"):
			#print "is multimotion"
			ind = parentMot.getMotionIndex(self.motion.getName())
			#print self.motion.getName(), ind
			if ind < 0:
				for i in range(parentMot.getNumMotions()):
					if self.motion == parentMot.getMotion(i):
						ind = i
						break
			#print ind
			if ind >= 0:
				parentMot.removeMotionByIndex(ind)
				done = True
		if not done and hasattr(parentMot, "setMotion1"):
			#print "is two motion"
			#print self.motion, parentMot.getMotion1(), parentMot.getMotion2()
			if parentMot.getMotion1() == self.motion:
				#print "is motion1"
				parentMot.setMotion1(None)
				done = True
			elif parentMot.getMotion2() == self.motion:
				#print "is motion2"
				parentMot.setMotion2(None)
				done = True
		if not done and hasattr(parentMot, "setMotion"):
			#print "is motion filter"
			#print self.motion, parentMot.getMotion()
			if parentMot.getMotion() == self.motion:
				print "is motion"
				parentMot.setMotion(None)
				done = True
		if done:
			self.backend.update()
				
					