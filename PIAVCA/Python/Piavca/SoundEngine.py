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

try:
	import pymedia.audio.sound as sound
	import pymedia.audio.acodec as acodec
	import pymedia.muxer as muxer
	pymediapresent = 1
except ImportError:
	print "pymedia unavailable, please install pymedia to enable sound playback"
	pymediapresent = 0

import wave

try:
	import pyTTS
	ttsAvailable = 1
except ImportError:
	print "Could Not Find pyTTS text-to-speech Engine"
	print "text to speech functionality will not be available"
	print "This engine only runs on windows"
	print "If you are running windows please intall it to get text-to-speech"
	ttsAvailable = 0
	
class SoundEngine:
	def __init__(self, samplerate = 44100, channels = 2, format = sound.AFMT_S16_LE):
		self.samplerate = samplerate
		self.channels = channels
		self.format = format
		
		# create an audio output device
		self.output = sound.Output(samplerate, channels, format )

		self.sounds = {}
		
		if ttsAvailable:
			self.tts = pyTTS.Create()
		
	def addSound(self, name, filename):
		print "adding", name, filename
		input_file= wave.open( filename, 'rb' )
			
		s = input_file.readframes(500000)
		frames = s
		while s:
			s = input_file.readframes(500000)
			frames = frames + s
			
		self.sounds[name] = frames
	
	def loadSounds(self, filename):
		f = open(filename, "r")
		lines = f.readlines()
		f.close()
		
		for line in lines:
			line = line.split()
			if len(line) < 2:
				continue
			self.addSound(line[0], line[1])
		
	def play(self, name):
		#print name, len(self.sounds[name])
		self.output.play(self.sounds[name])
			
	def say(self, text):
		if ttsAvailable:
			self.tts.Speak(text, pyTTS.tts_async, pyTTS.tts_purge_before_speak)
		else:
			print "no Text-To-Speech available"
			print text

		
import time
if __name__ == "__main__":
	se = SoundEngine()
	se.addSound("intro", "intro.wav")
	se.addSound("outro", "outro.wav")
	
	se.say("hello")
	se.say("how are you?")
	
	time.sleep(1.0)
	
	#se.play("outro")
	#se.play("intro")
