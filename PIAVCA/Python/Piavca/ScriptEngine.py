
# ***** BEGIN LICENSE BLOCK *****
# Version: MPL 1.1/GPL 2.0/LGPL 2.1
#
# The contents of this file are subject to the Mozilla Public License Version
# 1.1 (the "License"); you may not use this file except in compliance with
# the License. You may obtain a copy of the License at
# http://www.mozilla.org/MPL/
#
# Software distributed under the License is distributed on an "AS IS" basis,
# WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
# for the specific language governing rights and limitations under the
# License.
#
# The Original Code is __________________________________________.
#
# The Initial Developer of the Original Code is
# ____________________________________________.
# Portions created by the Initial Developer are Copyright (C) 2___
# the Initial Developer. All Rights Reserved.
#
# Contributor(s):
#
# Alternatively, the contents of this file may be used under the terms of
# either the GNU General Public License Version 2 or later (the "GPL"), or
# the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
# in which case the provisions of the GPL or the LGPL are applicable instead
# of those above. If you wish to allow use of your version of this file only
# under the terms of either the GPL or the LGPL, and not to allow others to
# use your version of this file under the terms of the MPL, indicate your
# decision by deleting the provisions above and replace them with the notice
# and other provisions required by the GPL or the LGPL. If you do not delete
# the provisions above, a recipient may use your version of this file under
# the terms of any one of the MPL, the GPL or the LGPL.
#
# ***** END LICENSE BLOCK *****

import Piavca
import MotionFile
from JointNames import *
import sys, thread, re
from SoundEngine import *

wxAvailable = 1
try:
	import wx
	import thread
except ImportError:
	wxAvailable = 0
	
	
class scriptCallback:
	def __init__(self, time, args):
		self.time = time
	def getTime(self):
		return self.time
	def __call__(self, avatar):
		raise "help, unimplemented callback"
		
class motionCallback(scriptCallback):
	def __init__(self, time, args, interrupt = 0):
		scriptCallback.__init__(self, time, args)
		self.interrupt = interrupt
		if issubclass(args[0].__class__, Piavca.Motion) :
			self.motion = args[0]
			self.motion.Reference()
			self.motionName = ""
		else:
			self.motion = None
			self.motionName = args[0]
	def __call__(self, avatar):
		if self.motion == None:
			self.motion = Piavca.Core.getCore().getMotion(self.motionName)
			if self.motion == None:
				print "Could not find motion", self.motionName
				return
			self.motion.Reference()
		if self.interrupt:
			avatar.interrupt_motion()
		avatar.play_motion(self.motion)
		
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
		if not self.soundengine.hasSound(self.soundname):
			self.soundengine.addSound(self.soundname, self.soundname+".wav")
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
	
		loadDefaults()
		
		self.scripts = {}
		self.currentscript = {}
		self.starttimes = {}
		
		if pymediapresent:
			self.soundEngine = SoundEngine()
		else:
			self.soundEngine = None
			
		inputfile = open(filename, "r")
		lines = inputfile.readlines()
		inputfile.close()
		gui_list = []
		for line in lines:
			line = line.strip()
			commentpos = line.find("#")
			if commentpos >= 0:
				line = line[:commentpos]
			line = line.split()
			print line
			if len(line) <= 0:
				continue
			if line[0] == "soundpack":
				if len(line) == 2:
					spackname = line[1]
				else:
					spackname = line[2]
				if self.soundEngine != None:
					self.soundEngine.loadSounds(spackname)
				else:
					print "could not load sound packs as audio playback is not supported, please install pymedia"
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
				if len(line) == 2:
					mpackname = line[1]
				else:
					mpackname = line[2]
				print "motionpack", mpackname
				MotionFile.readMotionFile(mpackname)
			elif line[0] == "script":
				if len(line) == 2:
					spackname = line[1]
				else:
					spackname = line[2]
				self.loadScripts(spackname)
			elif line[0] == "GUI":
				gui_list.append(line[1])
			elif line[0] == "gui":
				gui_list.append(line[1])
				
		for gui_name in gui_list:
			self.GUI(gui_name)
				
		self.thisown = 0
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
			line = line.strip()
			commentpos = line.find("#")
			if commentpos >= 0:
				line = line[:commentpos]
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
					cb = self.getCallback(line[1], time, line[2:])
					if cb != None:
						script.append(cb)
					
	def getCallback(self, callbackname, time, args):
		if callbackname == "motion":
			return motionCallback(time, args, 1)
		if callbackname == "queue_motion":
			return motionCallback(time, args, 0)
		if callbackname == "backgroundmotion":
			return backgroundMotionCallback(time, args)
		if callbackname == "stop":
			return stopMotionCallback(time, args)
		if callbackname == "sound":
			if self.soundEngine != None:
				return soundCallback(time, args, self.soundEngine)
			else:
				print "could not load sounds as audio playback is not supported, please install pymedia"
				return None
		if callbackname == "say":
			return sayCallback(time, args, self.soundEngine)
		if callbackname == "expression":
			retVal = None
			if self.faceMotion == None :
				self.faceMotion = Piavca.KeyframeMotion(1)
				retVal = motionCallback(time, (self.faceMotion,))
			trackId = Piavca.Core.getCore().getExpressionId(args[0])
			if self.faceMotion.isNull(trackId):
				self.faceMotion.addFloatTrack(trackId, 0.0);
			self.faceMotion.setFloatKeyframe(trackId, time, float(args[1]))
			return retVal
	
	def playScript(self, avatarname, scriptname):
		print "keys", self.scripts.keys()
		self.currentscript[avatarname] = self.scripts[scriptname]
		self.starttimes[avatarname] = Piavca.Core.getCore().getTime()
		for item in self.currentscript[avatarname]:
			item.done = 0
			
	def utterance(self, avatarname, utterance):
		expr = re.compile("<[^>]*>")
		scripts = expr.findall(utterance)
		text = expr.sub("", utterance)
		self.soundEngine.say(text)
		for script in scripts:
			self.playScript(avatarname, script.strip("<> "))
	
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
			
	def GUI(self, avatarName):
		if not wxAvailable:
			print "can't instantiate GUI, wx python not present"

		app = wx.PySimpleApp()

		frame=wx.Frame(None,-1)
		sizer1=wx.BoxSizer(wx.HORIZONTAL)
		sizer2=wx.BoxSizer(wx.VERTICAL)

		id_counter = 0
		for scriptname in self.scripts.keys():
			button=wx.Button(frame, id_counter, label=scriptname)
			wx.EVT_BUTTON (frame, id_counter, lambda e, s = self, n=scriptname : s.playScript(avatarName, n))
			sizer1.Add(button,1 )
			id_counter+=1
			if id_counter % 6 == 0:
				sizer2.Add(sizer1,0)
				sizer1=wx.BoxSizer(wx.HORIZONTAL)
				
		sizer2.Add(sizer1,0)
			
		frame.SetSizer(sizer2)
		frame.SetAutoLayout(1)
		sizer2.Fit(frame)

		frame.Show(True)
		frame.Layout()

		thread.start_new_thread(app.MainLoop, ())
		

		
if __name__ == "__main__":
	analyzer = ScriptEngine(sys.argv[1])
	