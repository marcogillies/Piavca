import Piavca
import MotionFile
from JointNames import *
import sys, thread
from SoundEngine import *

class scriptCallback:
	def __init__(self, time, args):
		self.time = time
	def getTime(self):
		return self.time
	def __call__(self, avatar):
		raise "help, unimplemented callback"
		
class motionCallback(scriptCallback):
	def __init__(self, time, args):
		scriptCallback.__init__(self, time, args)
		self.motionName = args[0]
	def __call__(self, avatar):
		avatar.play_motion(Piavca.Core.getCore().getMotion(self.motionName))
		
class backgroundMotionCallback(scriptCallback):
	def __init__(self, time, args):
		scriptCallback.__init__(self, time, args)
		self.motionName = args[0]
	def __call__(self, avatar):
		avatar.add_background_motion(Piavca.Core.getCore().getMotion(self.motionName))
		
class stopMotionCallback(scriptCallback):
	def __init__(self, time, args):
		scriptCallback.__init__(self, time, args)
		self.motionName = args[0]
	def __call__(self, avatar):
		print "stopping motion", self.motionName
		avatar.stop_motion(self.motionName)
		
class soundCallback(scriptCallback):
	def __init__(self, time, args, soundengine):
		scriptCallback.__init__(self, time, args)
		self.soundname = args[0]
		self.soundengine = soundengine
	def __call__(self, avatar):
		thread.start_new_thread(self.soundengine.play, (self.soundname,))
		
		
class sayCallback(scriptCallback):
	def __init__(self, time, args, soundengine):
		scriptCallback.__init__(self, time, args)
		self.text = args[0]
		self.soundengine = soundengine
	def __call__(self, avatar):
		self.soundengine.say(self.text)
		
class ScriptEngine(Piavca.TimeCallback):
	def __init__(self, name, filename):
		Piavca.TimeCallback.__init__(self, name)
	
		self.scripts = {}
		self.currentscript = {}
		self.starttimes = {}
		self.soundEngine = SoundEngine()
		
		inputfile = open(filename, "r")
		lines = inputfile.readlines()
		inputfile.close()
		for line in lines:
			line = line.strip()
			if len(line) <= 0 or line[0] == "#":
				continue
			line = line.split()
			if len(line) <= 0:
				continue
			if line[0] == "soundpack":
				self.soundEngine.loadSounds(line[2])
			elif line[0] == "expressions":
				importExpressionNames(line[1])
			elif line[0] == "joints":
				importJointNames(line[1])
			elif line[0] == "avatar":
				print "avatar", line[1]
				avatar = Piavca.Avatar(line[1])
				i = 2
				while i < len(line):
					if line[i] == "position" or line[i] == "pos":
						pos = Piavca.Vec(float(line[i+1]), float(line[i+2]), float(line[i+3]))
						avatar.setRootPosition(pos)
						i = i+3
					elif line[i] == "rotation" or line[i] == "rot":
						angle = Piavca.degToRad(float(line[i+1]))
						axis = Piavca.Vec(float(line[i+2]), float(line[i+3]), float(line[i+4]))
						avatar.setRootOrientation(Piavca.Quat(angle, axis))
						i = i+4
					i += 1
			elif line[0] == "motionpack":
				print "motionpack", line[2]
				MotionFile.readMotionFile("motions.conf")
			elif line[0] == "script":
				self.loadScripts(line[2])
				
		Piavca.Core.getCore().registerCallback(self)
				
	def loadScripts(self, scriptfile):
		print "load scripts", scriptfile
		#return
		inputfile = open(scriptfile, "r")
		lines = inputfile.readlines()
		inputfile.close()
		readingscript = 0
		self.faceMotion = None
		for line in lines:
			line = line.split()
			if len(line) <= 0:
				continue
			print line
			if not readingscript and line[0] == "script":
				readingscript = 1
				scriptname = line[1]
				print "entering script", scriptname
				script = []
				continue
			if readingscript:
				if line[0] == "stop":
					readingscript = 0
					print "script", scriptname
					print script
					self.scripts[scriptname] = script
					self.faceMotion = None
				else:
					time = float(line[0])
					script.append(self.getCallback(line[1], time, line[2:]))
					
	def getCallback(self, callbackname, time, args):
		if callbackname == "motion":
			return motionCallback(time, args)
		if callbackname == "backgroundmotion":
			return backgroundMotionCallback(time, args)
		if callbackname == "stop":
			return stopMotionCallback(time, args)
		if callbackname == "sound":
			return soundCallback(time, args, self.soundEngine)
		if callbackname == "say":
			return sayCallback(time, args, self.soundEngine)
		if callbackname == "expression":
			print "expression keyword not yet supported"
			return None
			if self.faceMotion == None :
				self.faceMotion = Piavca.KeyframeMotion(1)
			self.faceMotion.addKeyframe(Piavca.Core.getCore().getExpressionId(args[0]), time, float(args[1]))
			return None
	
	def playScript(self, avatarname, scriptname):
		print "keys", self.scripts.keys()
		self.currentscript[avatarname] = self.scripts[scriptname]
		self.starttimes[avatarname] = Piavca.Core.getCore().getTime()
		for item in self.currentscript[avatarname]:
			item.done = 0
	
	# callback initialization, don't need to do anything
	def init(self, core):
		pass
		
	def timeStep(self, core, time):
		for avatar in self.currentscript.keys():
			#print avatar
			if self.currentscript[avatar] :
				for item in self.currentscript[avatar]:
					if (not item.done) and item.getTime() < (time - self.starttimes[avatar]):
						item(Piavca.Core.getCore().getAvatar(avatar))
						item.done = 1
			
		
if __name__ == "__main__":
	analyzer = ScriptEngine(sys.argv[1])
	