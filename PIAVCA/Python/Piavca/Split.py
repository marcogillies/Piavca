
import Piavca

# a range of from a motion track. 
# This specifies a subrange of a motion from a start and end time
class Split :
	def __init__(self, mot, start = 0, end = -1):
		self.start = start # start time
		self.end = end # end time (if -1 it's the end of the motion)

		# the motion you are taking a range of
		self.originalMotion = mot 
		# a Piavca.rangeMotion that represents the split
		self.rangeMotion = Piavca.TimeRangeMotion(mot, start, end) 

	# return the submotion
	def GetMotion(self):
		return self.rangeMotion

	# return the submotion
	def GetSubMotion(self):
		return Piavca.SubMotion(self.originalMotion, self.start, self.end)

	def GetStart(self):
		return self.start

	def GetEnd(self):
		return self.end
	
	# save the submotion as a piavca motion file
	def Save(self, filename):
		SubMotion = Piavca.SubMotion(self.originalMotion, self.start, self.end)
		saver = Piavca.MotionSaver(SubMotion)
		saver.collectFrames(0.05)
		saver.save(filename)
