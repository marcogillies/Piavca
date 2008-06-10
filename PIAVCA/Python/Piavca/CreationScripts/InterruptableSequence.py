
import Piavca

# calculate the distance of a frame from the averange
# defined by the expmap
def calculateDistance(mot, t, expmaps):
	sum = 0.0
	for j in Piavca.joints(mot):
		joint_type = mot.getTrackType(j)
		if joint_type & Piavca.FLOAT_TYPE:
			sum += abs(mot.getFloatValueAtTime(j, t) - expmaps[(j,Piavca.FLOAT_TYPE)])
		if joint_type & Piavca.VEC_TYPE:
			sum +=(mot.getVecValueAtTime(j, t) - expmaps[(j,Piavca.VEC_TYPE)]).mag()
		if joint_type & Piavca.QUAT_TYPE:
			sum +=expmaps[(j,Piavca.QUAT_TYPE)].logMap(mot.getQuatValueAtTime(j, t)).mag()
	return sum
			

# create a motion from seq that can be smoothly interrupted
# by any of the motions in interruptions
def InterruptableSequence(seq, interruptions, fps = 20):
	expmaps = {}
	
	# create a set of exponential maps 
	# what this does is find the average joint 
	# rotations of all of start and end poses of the
	# interruptions, and get them in a form where
	# its easy to calculate the distance of a new quaternion to
	# them
	for j in Piavca.joints(seq):
		joint_type = seq.getTrackType(j)
		# the joint orientations of 
		# this joint at the start and end 
		# frames of the interruptions
		for t in (Piavca.FLOAT_TYPE, Piavca.VEC_TYPE, Piavca.QUAT_TYPE):
			if not(t & joint_type) :
				continue
			extremeFrames = []
			for m in interruptions:
				if not( m.getTrackType(j) & t) :
					continue
				start_time = m.getStartTime()
				extremeFrames.append(Piavca.getValAtTime(m, j, start_time, t))
				end_time = m.getEndTime()
				extremeFrames.append(Piavca.getValAtTime(m, j, end_time, t))
				
			if len(extremeFrames) == 0:
				expmaps[(j,t)] = None
			if t == Piavca.QUAT_TYPE:
				expmaps[(j,t)] = Piavca.ExpMap.TangentSpace(extremeFrames)
			elif t == Piavca.VEC_TYPE:
				expmaps[(j,t)] = sum(extremeFrames, Piavca.Vec())/float(len(extremeFrames))
			else:
				expmaps[(j,t)] = sum(extremeFrames)/float(len(extremeFrames))
	
	
	d_minus = None
	d = None
	d_plus = None
				
	minima = []
	for i in range(int(seq.getStartTime()*fps), int(seq.getEndTime()*fps)-1):
		d_plus = calculateDistance(seq, float(i+1)/fps, expmaps)
		if d :
			if d < d_plus:
				if d_minus == None or d < d_minus:
					minima.append(float(i)/fps)
		d_minus = d
		d = d_plus
		
	print minima	
	
	submots = [Piavca.SubMotion(seq, start, end) for start, end in zip(minima[:-1], minima[1:])]
	choice1 = Piavca.ChoiceMotion()
	for mot in submots:
		choice1.addMotion(mot)
	choice2 = Piavca.ChoiceMotionWithDefault()
	choice2.addMotion(choice1)
	for mot in interruptions:
		choice2.addMotion(mot)
	return choice2
										
if __name__ == "__main__":
	import os
	os.chdir("../../../../../Data/performing_presence/scenario2008/bill/")
	import Piavca.XMLMotionFile
	Piavca.XMLMotionFile.parse("submotsTemp.xml")
	m = InterruptableSequence(Piavca.getMotion("second_projections2_fully_labelled_megan"), [Piavca.getMotion(m) for m in ["submot1", "submot2"]])
	Piavca.loadMotion("interrupSeq", m)
	Piavca.XMLMotionFile.saveAll("InterrupSeq_output.xml")
			