
import Piavca
import Piavca.CreationScripts.InterruptableSequence 
from Piavca.PiavcaDesigner.ParameterControls import *

class ExpMapBlend:
	
	def createControls(self, frame):
		controls = []
		
		self.Motions = MotionSetParamEntry("Motions", None, frame)
		controls.append(("Motions", self.Motions))
		
		return controls
		
	def getMotion(self):
		motions = self.Motions.getValue()
		
		blend = Piavca.MultiBlend()
		print motions
		tangentSpaces = Piavca.TangentSpace_calculateTangentSpacesFromMotionAverages(motions)
		for mot in motions:
			lm = Piavca.LogMapMotion(tangentSpaces, mot)
			lm.setName(mot.getName())
			print lm, type(lm)
			blend.addMotion(lm)
		em = Piavca.ExpMapMotion(tangentSpaces, blend)
		mask = Piavca.MaskedMotion()
		mask.setMotion(blend)
		mask.addToMask(Piavca.root_position_id)
		
		override = Piavca.OverrideMotion(mask, em)
		
		return override