
import Piavca
from EigenAnalysis import *
from PCA import *

class EigenMotion(Piavca.MotionFilter):
	def __init__(self, mot = None, analysis = None):
		if mot != None:
			Piavca.MotionFilter.__init__(self, mot)
		else:
			Piavca.MotionFilter.__init__(self)
		self.__disown__()
		
		self.filename = None
		self.analysis = analysis
		self.input_motions = []
		self.frames_per_second = 20
		self.num_pcs = 0
		
	def clone(self):
		#return self
		newMot = EigenMotion()
		newMot.filename = self.filename
		newMot.analysis = self.analysis
		newMot.input_motions = self.input_motions
		newMot.frames_per_second = self.frames_per_second
		newMot.num_pcs = self.num_pcs
		#self.load(None)
		#newMot.load(None)
		#print "dicts"
		#print self.__dict__.keys()
		#print newMot.__dict__.keys()
		return newMot
			
	def setEigenAnalysisFile(self, filename):
		self.filename = filename
		
	def setAnalysis(self, analysis):
		self.analysis = analysis
		
	def setFramesPerSecond(self, fps):
		self.frames_per_second = fps
		
	def setFilename(self, filename):
		self.filename = filename
		
	def addMotion(self, motion):
		self.input_motions.append(motion)
		
	def addMotions(self, motions):
		self.input_motions = self.input_motions + motions
		
	def create(self):
		if self.filename:
			self.LoadAnalysis(self.filename)
		else:
			if self.input_motions == []:
				motions = [self.getMotion()]
			else:
				motions = self.input_motions
			self.analysis.do_analysis(motions, self.frames_per_second)
		self.num_pcs = self.analysis.num_pcs
		
	# set the value of a PC weight 
	def setWeight (self, pc, w):
		print "setting weight", pc, w
		self.analysis.setWeight(pc, w)
				
	# set the value of a PC weight 
	def setWeights (self, w):
		self.analysis.setWeights(w)
		
	def Save(self, filename):
		self.analysis.Save(filename)
		
	def LoadAnalysis(self, filename):
		self.analysis.Load(filename)
		
	def preFrame(self, time):
		if self.getMotion():
			self.analysis.setWeights(self.analysis.projectMotionAtTime(self.getMotion(), time))
	
	# whether a joint is valid (to implement Piavca.Motion)
	def isNull (self, trackid):
		return self.analysis.jointmap[trackid] == None

	# length of a motion (to implement Piavca.Motion)
	def getMotionLength (self):
		return self.analysis.getMotionLength()

	# type of a motion track (to implement Piavca.Motion)
	def getTrackType (self, trackid):
		return self.analysis.joint_types[trackid]

	# get the value of the motion at a given time
	# takes the internal matrix representation and 
	# maps back to quaternion space
	def getQuatValueAtTimeInternal (self, trackid, t):
		if(not self.isNull(trackid)):
			return self.analysis.getTrackValue(trackid, time)

class PCAMotion(EigenMotion):
	def __init__(self, mot = None):
		EigenMotion.__init__(self, mot, PCA())

		
		
