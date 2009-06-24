import Piavca
import Piavca.CreationScripts.MotionGraph 
from Piavca.PiavcaDesigner.ParameterControls import *

class MotionGraph:
	
	def createControls(self, frame):
		controls = []
		
		self.Motions = MotionSetParamEntry("Motions", None, frame)
		controls.append(("Motions", self.Motions))
		self.pcaFile = FilenameParamEntry("PCAFile", None, frame)
		self.pcaFile.setValue("")
		controls.append(("PCAFile", self.pcaFile))
		self.fps = FloatParamEntry("Frames per second", None, frame)
		self.fps.setValue(20)
		controls.append(("Frames per second", self.fps))
		self.numNodes = IntParamEntry("NumNodes", None, frame)
		self.numNodes.setValue(6)
		controls.append(("NumNodes", self.numNodes))
		
		return controls
		
	def getMotion(self):
		motions = self.Motions.getValue()
		fps = self.fps.getValue()
		numNodes = self.numNodes.getValue()
		pcaFile = self.pcaFile.getValue()
		
		mot = Piavca.CreationScripts.MotionGraph.MotionGraph(motions, pcaFile, fps, numNodes)
		return mot