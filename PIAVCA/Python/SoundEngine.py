
import pymedia.audio.sound as sound
import pymedia.audio.acodec as acodec
import pymedia.muxer as muxer

import wave

try:
	import pyTTS
	ttsAvailable = 1
except ImportError:
	print "Could Not Find pyTTS text-to-speech Engine"
	print "text to speech functionality will not be available"
	print "This engine only runs on windows"
	print "If you are running windows please intall it to get text-to-speech"
	ttsAvaiable = 0
	
class SoundEngine:
	def __init__(self, samplerate = 44100, channels = 2, format = sound.AFMT_S16_LE):
		self.samplerate = samplerate
		self.channels = channels
		self.format = format
		
		# create an audio output device
		self.output = sound.Output(samplerate, channels, format )

		self.sounds = {}
		
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
		self.tts.Speak(text, pyTTS.tts_async, pyTTS.tts_purge_before_speak)

		
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
