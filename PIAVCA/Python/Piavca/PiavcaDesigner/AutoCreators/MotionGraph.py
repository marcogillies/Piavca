import Piavca
try:
	import Piavca.CreationScripts.MotionGraph 
	importSuccessful = True
except ImportError:
	importSuccessful = False
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
		self.threshold = FloatParamEntry("Threshold", None, frame)
		self.threshold.setValue(1.0)
		controls.append(("Threshold", self.threshold))
		
		return controls, []
		
	def getMotion(self):
		if not importSuccessful:
			return None
		motions = self.Motions.getValue()
		fps = self.fps.getValue()
		numNodes = self.numNodes.getValue()
		pcaFile = self.pcaFile.getValue()
		threshold = self.threshold.getValue()
		
		mot = Piavca.CreationScripts.MotionGraph.MotionGraph(motions, pcaFile, fps, numNodes,threshold)
		return mot