#
#  SubMotion.py
#  piavca
#
#  Created by Marco Gillies on 18/04/2011.
#  Copyright (c) 2011 Goldsmiths, University of London. All rights reserved.
#

import Piavca

class SubMotionCreator:
	
	def createControls(self, frame):
		self.backend = frame.backend
		controls = []
		
		#self.motion = MotionParamEntry("motion", None, frame)
		#controls.append(("motion", self.motion))
		#self.Interruptions = MotionSetParamEntry("Interruptions", None, frame)
		#controls.append(("Interruptions", self.Interruptions))
		#self.fps = FloatParamEntry("Frames per second", None, frame)
		#self.fps.setValue(20)
		#controls.append(("Frames per second", self.fps))
		#self.threshold = FloatParamEntry("threshold", None, frame)
		#self.threshold.setValue(40)
		#controls.append(("threshold", self.threshold))
		#self.window = FloatParamEntry("window", None, frame)
		#self.window.setValue(0.5)
		#controls.append(("window", self.window))
		
		return controls, []
		
	def getMotion(self):
	
		mot = self.backend.motion.getMotion()
		
		if (mot == None):
			return None
			
		start, end = self.backend.getRange()
		#start += mot.getStartTime()
		#end += mot.getStart()
		submot = Piavca.SubMotion(mot, start, end)
	
		return submot