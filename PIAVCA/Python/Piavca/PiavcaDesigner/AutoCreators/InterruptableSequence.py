
import Piavca
import Piavca.CreationScripts.InterruptableSequence 
from Piavca.PiavcaDesigner.ParameterControls import *

class InterruptableSequence:
	
	def createControls(self, frame):
		controls = []
		
		self.motion = MotionParamEntry("motion", None, frame)
		controls.append(("motion", self.motion))
		self.Interruptions = MotionSetParamEntry("Interruptions", None, frame)
		controls.append(("Interruptions", self.Interruptions))
		self.fps = FloatParamEntry("Frames per second", None, frame)
		self.fps.setValue(20)
		controls.append(("Frames per second", self.fps))
		self.threshold = FloatParamEntry("threshold", None, frame)
		self.threshold.setValue(40)
		controls.append(("threshold", self.threshold))
		self.window = FloatParamEntry("window", None, frame)
		self.window.setValue(0.5)
		controls.append(("window", self.window))
		
		return controls
		
	def getMotion(self):
		mot = self.motion.getValue()
		interruptions = self.Interruptions.getValue()
		fps = self.fps.getValue()
		threshold = self.threshold.getValue()
		window = self.window.getValue()
		
		mot, numMinima = Piavca.CreationScripts.InterruptableSequence.InterruptableSequence(mot, interruptions, fps, threshold, window)
		return mot