import Piavca
from Piavca.PiavcaDesigner.ParameterControls import *

# calculate the distance of a frame from the averange
# defined by the expmap
def calculateDistance(mot, t, expmaps):
	sum = 0.0
	for j in Piavca.joints(mot):
		# don't take the root into account as we reposition the motion
		if j == Piavca.root_orientation_id or j == Piavca.root_position_id :
			continue
		if mot.isNull(j):
			continue
		joint_type = mot.getTrackType(j)
		if joint_type & Piavca.FLOAT_TYPE and expmaps[(j,Piavca.FLOAT_TYPE)]:
			sum += abs(mot.getFloatValueAtTime(j, t) - expmaps[(j,Piavca.FLOAT_TYPE)])
		if joint_type & Piavca.VEC_TYPE and expmaps[(j,Piavca.VEC_TYPE)]:
			sum +=(mot.getVecValueAtTime(j, t) - expmaps[(j,Piavca.VEC_TYPE)]).mag()
		if joint_type & Piavca.QUAT_TYPE and expmaps[(j,Piavca.QUAT_TYPE)]:
			sum +=expmaps[(j,Piavca.QUAT_TYPE)].logMap(mot.getQuatValueAtTime(j, t)).mag()
	return sum

def findMinima(mot, compMotion, compFrame, threshold, fps):
	expmaps = {}
		
	# create a set of exponential maps 
	# what this does is find the average joint 
	# rotations of all of start and end poses of the
	# interruptions, and get them in a form where
	# its easy to calculate the distance of a new quaternion to
	# them
	for j in Piavca.joints(mot):
		# don't take the root into account as we reposition the motion
		if j == Piavca.root_orientation_id or j == Piavca.root_position_id :
			continue
		if mot.isNull(j):
			continue
		joint_type = mot.getTrackType(j)
		# the joint orientations of 
		# this joint at the start and end 
		# frames of the interruptions
		for t in (Piavca.FLOAT_TYPE, Piavca.VEC_TYPE, Piavca.QUAT_TYPE):
			if not(t & joint_type) or not(t & compMotion.getTrackType(j)) :
				continue
				
			frame = Piavca.getValAtTime(compMotion, j, compFrame, t)	
			
			if t == Piavca.QUAT_TYPE:
				expmaps[(j,t)] = Piavca.ExpMap.TangentSpace([frame])
			elif t == Piavca.VEC_TYPE:
				expmaps[(j,t)] = frame
			else:
				expmaps[(j,t)] = frame
	
	d_minus = None
	d = None
	d_plus = None
				
	# find local minima of the distance function 
	# if its lower than a threshold then we add it to the set of
	# of possible transition points
	minima = []
	values = []
	#print "start time", seq.getStartTime(), "end time", seq.getEndTime()
	for i in range(int(mot.getStartTime()*fps), int(mot.getEndTime()*fps)-1):
		d_plus = calculateDistance(mot, float(i+1)/fps, expmaps)
		print d, d_plus, threshold
		if d :
			if d < d_plus:
				if d_minus == None or d < d_minus:
					print d, d_plus, threshold
					if d < threshold:
						#if len(minima) == 0:
						values.append(d)
						minima.append(float(i)/fps)
		d_minus = d
		d = d_plus
		
	return minima

class FindTransitions:
	
	def createControls(self, frame):
		self.backend = frame.backend
		controls = []
		
		self.motion = MotionParamEntry("motion", None, frame)
		controls.append(("motion", self.motion))
		
		self.comparisonMotion = MotionParamEntry("comparisonMotion", None, frame)
		controls.append(("comparisonMotion", self.comparisonMotion))
		
		self.comparisonFrame = FloatParamEntry("comparisonFrame", None, frame)
		self.comparisonFrame.setValue(0)
		controls.append(("comparisonFrame", self.comparisonFrame))
		
		self.threshold = FloatParamEntry("threshold", None, frame)
		self.threshold.setValue(40)
		controls.append(("threshold", self.threshold))
		
		self.fps = FloatParamEntry("Frames per second", None, frame)
		self.fps.setValue(20)
		controls.append(("Frames per second", self.fps))
		
		self.name = StringParamEntry("name", None, frame)
		self.name.setValue("")
		controls.append(("name", self.name))
		
		list = [""] + self.backend.getMotionFramesNames()
		print "list of frame lists", list
		self.FrameLists = ChoiceListParamEntry(list, "FrameLists", None, frame)
		controls.append(("FrameLists", self.FrameLists))
		
		return controls, []
		
	def getMotion(self):
		mot = self.motion.getValue()
		compMotion = self.comparisonMotion.getValue()
		compFrame = self.comparisonFrame.getValue()
		
		fps = self.fps.getValue()
		threshold = self.threshold.getValue()	
		name = self.name.getValue()	
		
		framelist = self.FrameLists.getValue()
		
		list = self.backend.getMotionFramesByName(framelist)
		
		if list == None:
			
			minima = findMinima(mot, compMotion, compFrame, threshold, fps)
		
			print minima
			self.backend.addMotionFrames(name, minima)
			self.backend.setMotionFrames(name)
		else:
			self.backend.setMotionFrames(framelist)
		
				
		return Piavca.SubMotion(mot, 0, mot.getMotionLength())
		