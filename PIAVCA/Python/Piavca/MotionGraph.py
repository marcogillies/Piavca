
# ***** BEGIN LICENSE BLOCK *****
# Version: MPL 1.1/GPL 2.0/LGPL 2.1
#
# The contents of this file are subject to the Mozilla Public License Version
# 1.1 (the "License"); you may not use this file except in compliance with
# the License. You may obtain a copy of the License at
# http://www.mozilla.org/MPL/
#
# Software distributed under the License is distributed on an "AS IS" basis,
# WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
# for the specific language governing rights and limitations under the
# License.
#
# The Original Code is __________________________________________.
#
# The Initial Developer of the Original Code is
# ____________________________________________.
# Portions created by the Initial Developer are Copyright (C) 2___
# the Initial Developer. All Rights Reserved.
#
# Contributor(s):
#
# Alternatively, the contents of this file may be used under the terms of
# either the GNU General Public License Version 2 or later (the "GPL"), or
# the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
# in which case the provisions of the GPL or the LGPL are applicable instead
# of those above. If you wish to allow use of your version of this file only
# under the terms of either the GPL or the LGPL, and not to allow others to
# use your version of this file under the terms of the MPL, indicate your
# decision by deleting the provisions above and replace them with the notice
# and other provisions required by the GPL or the LGPL. If you do not delete
# the provisions above, a recipient may use your version of this file under
# the terms of any one of the MPL, the GPL or the LGPL.
#
# ***** END LICENSE BLOCK *****

import Piavca
import random
import cPickle as pickle
import copy
from StrongConnectivity import StronglyConnectedComponents
import Piavca.ExpMap as ExpMap
import time

def makeFrameArray(motion, fps):
	print "creating frame array...."
	m = ({}, {}, {})
	length = int(motion.getMotionLength()*fps)
	for joint in range(motion.begin(), 0) + range(1, Piavca.Core.getCore().getMaxJointId()) :
		#print "current joint", joint
		if( not motion.isNull(joint)):
			#print joint, "is not null"
			type = motion.getTrackType(joint)
			if type & Piavca.FLOAT_TYPE:
				#print "float track"
				type = Piavca.FLOAT_TYPE
				m[0][joint] = [motion.getFloatValueAtTime(joint, float(t)/float(fps)) for t in range(length)]
			elif type & Piavca.QUAT_TYPE:
				#print "quat track"
				type = Piavca.QUAT_TYPE
				m[0][joint] = [motion.getQuatValueAtTime(joint, float(t)/float(fps)) for t in range(length)]
				#print m[0][joint]
			elif type & Piavca.VEC_TYPE:
				#print "vec track"
				type = Piavca.VEC_TYPE
				m[0][joint] = [motion.getVecValueAtTime(joint, float(t)/float(fps)) for t in range(length)]
			else:
				Piavca.PiavcaError("Unknown track type " + str(type))
			m[1][joint] = []
			for i in range(1, len(m[0][joint])):
				q1 = m[0][joint][i-1]
				q2 = m[0][joint][i]
				if type & Piavca.QUAT_TYPE:
					m[1][joint].append(q2/q1)
				else:
					m[1][joint].append(q2-q1)
			m[2][joint] = type
	print "finished creating frame array..."
	return m, length

class DistanceMeasure:
	def __init__(self, facial=0, jointWeights=None, velocityWeight=1):
		self.velocityWeight = velocityWeight
		if jointWeights == None:
			self.jointWeights = [(i, 1.0) for i in range(Piavca.Core.getCore().getMinTrackId(), Piavca.Core.getCore().getMaxTrackId())]
			#if facial:
			#	self.jointWeights = [(i, 1.0) for i in range(Piavca.Core.getCore().getMaxJointId())]
			#else:
			#	self.jointWeights = [(i, 1.0) for i in range(Piavca.Core.getCore().getMaxExpressionId())]
		else:
			self.jointWeights = jointWeights
		#print "joint weights", self.jointWeights
		self.expmap = ExpMap.TangentSpace([Piavca.Quat()])
		self.time = 0
		self.logtime = 0
		self.opcount =0
		
	def setVelocityWeight(self, velocityWeight):
		self.velocityWeight = velocityWeight
		
	def readJointWeightsFile(self, filename):
		self.jointWeights = []
		file = open(filename, "r")
		for line in file.readlines():
			for joint in line.split():
				joint = joint.split("=")
				weight = float(joint[1])
				joint = joint[0]
				jointid = Piavca.Core.getCore().getJointId(joint)
				#print joint, jointid, weight
				self.jointWeights.append((jointid, float(1.0)))
		file.close()
		
	def distance(self, f1, f2, type):
		#print type
		if type & Piavca.FLOAT_TYPE:
			return abs(f1-f2)
		elif type & Piavca.QUAT_TYPE:
			#print "quat difference"
			return Piavca.Quat.spherical_distance(f1, f2)
		elif type & Piavca.VEC_TYPE:
			v = f2 - f2
			return v.mag()
		else:
			Piavca.PiavcaError("Unknown track type " + str(type))
		
	def __call__(self, t1, t2, mot1, mot2 = None):
		if mot2 == None:
			mot2 = mot1
		dist = 0.0
		starttime = time.time()
		t1 = int(t1)
		t2 = int(t2)
		vw = self.velocityWeight
		#print self.jointWeights
		#print "calculating measure with window = ", self.window
		for joint, weight in self.jointWeights:
			if not mot1[0].has_key(joint) or not mot2[0].has_key(joint) :
				continue
			#print mot1[2][joint], mot2[2][joint]
			if mot1[2][joint] != mot2[2][joint]:
					Piavca.PiavcaError("trying to take the distance between tracks of different types")
			
			if joint != Piavca.Core.nullId:
				f1 = mot1[0][joint][t1]
				f2 = mot2[0][joint][t2]
				
				dist += weight*self.distance(f1, f2, mot1[2][joint])
				self.opcount += 1
			
			v1 = mot1[1][joint][t1]
			v2 = mot2[1][joint][t2]
			
			dist += vw*weight*self.distance(v1, v2, mot1[2][joint])
			self.opcount += 1
			
		self.time += time.time() - starttime
		return dist
	def printtime(self):
		print "distance metric time",  self.time
		print "log norm time",  self.logtime
		print "opcount",  self.opcount
	def cleartime(self):
		self.time = 0
		self.logtime = 0
		self.opcount = 0
	

class Node:
	def __init__(self, frame, time, motion):
		self.frame = frame
		self.time = time
		self.motion = motion
		self.children = []
		self.nextNode = None
		self.transitions = {}
		self.transitionCosts = {}
	def copy(self):
		newNode = Node(self.frame, self.time, self.motion)
		newNode.children = list(self.children)
		newNode.nextNode = self.nextNode
		return newNode
	def addChild(self, child, cost):
		if not (child in self.children):
			self.children.append(child)
			self.transitionCosts[child] = cost
	def addTransition(self, child, mot):
		self.transitions[child] = mot
	def getTransition(self, child):
		return self.transitions[child]
	def clearChildren(self):
		self.children = []
	def __iter__(self):
		return iter(self.children)
	def __getstate__(self):
		state = dict(self.__dict__)
		#print state
		state["transitions"] = {}
		return state

# A motion graph is a transitioning construct so we inherit from LoopMotion
class MotionGraph (Piavca.LoopMotion):
	def __init__(self, motions=[], window = 1.0):
		Piavca.LoopMotion.__init__(self)
		self.setAccumulateRoot(0)
		self.setBlendInterval(0.0)
		self.motions = list(motions)
		self.window = window
		self.fps = 25
		if len(self.motions) > 0:
			self.measure = DistanceMeasure(facial=self.motions[0].isFacial())
		else:
			self.measure = None
		self.threshold_same = 4
		self.threshold_diff = 8
		self.filename = ""
		self.jointsWeightsFile = ""
		self.nextmotions = []
		self.minClipLength = 1.0/float(self.fps)
		
	def clone(self):
		newMot = MotionGraph(self.motions, self.window)
		
		self.fps = self.fps
		self.measure = self.measure
		self.threshold_same = self.threshold_same
		self.threshold_diff = self.threshold_diff
		newMot.setFilename(self.filename)
		self.jointsWeightsFile = self.jointsWeightsFile
		
		try:
			newMot.nodes = {}
			for key in self.nodes.keys():
				newMot.nodes[key] = self.nodes[key].copy()
			newMot._createTransitionMots()
			print self.nextnode
			print self.nodes[(self.nextnode.motion, self.nextnode.frame)]
			newMot.nextnode = newMot.nodes[(self.nextnode.motion, self.nextnode.frame)]
			newMot.reblend(Piavca.Core.getCore().getTime())
		except AttributeError:
			pass
		print "finished MotionGraph.clone"
		
	def addMotion(self, mot):
		self.motions.append(mot)
		if self.measure == None:
			self.measure = DistanceMeasure(facial=self.motions[0].isFacial())
		
	def getNumMotions(self):
		return len(self.motions)
		
	def getMotionByIndex(self, i):
		return self.motions[i]
	
	def setWindow(self, w):
		self.window = w
	
	def setFPS(self, fps):
		self.fps = fps
	
	def setThresholdSame(self, thresh):
		self.threshold_same = thresh
	
	def setThresholdDiff(self, thresh):
		self.threshold_diff = thresh
		
	def setJointWeightsFile(self, filename):
		self.jointsWeightsFile = filename
		if filename != "":
			self.measure.readJointWeightsFile(filename)
			
	def setMinClipLength(self, length):
		self.minClipLength = length
	
	def getWindow(self):
		return self.window
	
	def getFPS(self):
		return self.fps
	
	def getThresholdSame(self):
		return self.threshold_same
	
	def getThresholdDiff(self):
		return self.threshold_diff
		
	def getJointWeightsFile(self):
		return self.jointsWeightsFile	
			
	def getMinClipLength(self):
		return self.minClipLength
		
	def setFilename(self, filename):
		if type(filename) != type(""):
			raise TypeError, "filename has to be a string"
		self.filename = filename
		
	def getFilename(self):
		return self.filename
	
	# create the graph
	def create(self, avatar = None):		
		transitions = self.findTransitions(avatar)
			
		# cull the transitions
		transitions.sort()
		# split the transitions up by starting point
		split_trans = []
		sub_trans = []
		for trans in transitions:
			if len(sub_trans) > 0 and (trans[0] != sub_trans[-1][0] or trans[1] != sub_trans[-1][1]):
				split_trans.append(sub_trans)
				sub_trans = []
			sub_trans.append(trans)
			
		# dump the transitions out to file, in case we want to recalculate later
		file = open("transition_back.txt", "w")
		pickle.dump(transitions, file)
		file.close()
		newtrans = []
		outfile = open("SelectTransitions.out", "w")
		
		# new set of transitions with bad ones weeded out
		for trans_set in split_trans:
			outfile.write(str(trans_set) + "\n")
			trans, vals = self.selectTransitions(trans_set, self.fps)#, outfile)
			outfile.write(str(vals) + "\n")
			outfile.write(str(trans) + "\n")
			if len (trans) > 0:
					newtrans = newtrans + trans
		outfile.close()
		transitions = newtrans
		
		
		# now that we've found the transitions we need to create the graph
		self.init_nodes(transitions, avatar)
		self.reblend(Piavca.Core.getCore().getTime())
		
	def findTransitions(self, avatar=None):
		if self.jointsWeightsFile != "":
			self.measure.readJointWeightsFile(self.jointsWeightsFile)
		if self.filename != "":
			self.loadGraph(self.filename)
			print "loaded graph"
			return
		print "creating graph"
		# create a cached array of the frames of each motion
		for i, motion in enumerate(self.motions):
			framearray, numframes = makeFrameArray(motion, self.fps)
			self.motions[i] = motion, framearray, numframes
		# calculate the matrix of frame distances and find local minima
		# we only keep three rows of the matrix of frame distances
		# at any given time to save memory
		transitions = []
		for motindex1, m1 in enumerate(self.motions):
			motion1, framearray1, numframes1 = m1
			print "outerloop", motindex1, motion1, numframes1
			startframe1 = int(self.window*self.fps)
			endframe1 = numframes1-int(self.window*self.fps)-1
			print startframe1, endframe1, numframes1, int(self.window*self.fps)
			for motindex2, m2 in enumerate(self.motions) :
				starttime = time.time()
				motion2, framearray2, numframes2 = m2
				if motindex1 == motindex2 :
					threshold = self.threshold_same
				else:
					threshold = self.threshold_diff
				print "inner loop", motindex1, motindex2, motion2, numframes2
				startframe2 = int(self.window*self.fps)
				endframe2 = numframes2-int(self.window*self.fps)-1
				#print startframe2, endframe2, numframes2, measure.window
				
				# initialise the distance (sub)matrix with the first two rows
				distancematrix = []
				distancematrix.append(None) 
				distancematrix.append([self.measure(startframe1, f, framearray1, framearray2) for f in range(startframe2,endframe2)])
				distancematrix.append([self.measure(startframe1+1, f, framearray1, framearray2) for f in range(startframe2,endframe2)])
				initial_distance_time = time.time() - starttime

				conditiontime = 0 
				testtime = 0
				loop_distance_time = 0
				# search through the current row looking for local minima
				for i in range(startframe1, endframe1):
					frametransitions = []
					for j in range(1, endframe2-startframe2-1):
						# compare the current frame with all its neighbours
						innerloop_start_time = time.time()
						condition = distancematrix[1][j] < distancematrix[1][j-1] 
						condition = condition and distancematrix[1][j] < distancematrix[1][j+1] 
						#print "condition", condition, 
						if distancematrix[0] != None:
							c1 = distancematrix[1][j] < distancematrix[0][j]
							c1 = c1 and distancematrix[1][j] < distancematrix[0][j-1]
							c1 = c1 and distancematrix[1][j] < distancematrix[0][j+1]				   
							#print "c1", c1,
							condition = condition and c1
						if distancematrix[2] != None:
							c2 = distancematrix[1][j] < distancematrix[2][j]
							c2 = c2 and distancematrix[1][j] < distancematrix[2][j-1]
							c2 = c2 and distancematrix[1][j] < distancematrix[2][j+1] 
							#print "c2", c2,
							condition = condition and c2
						condtime = time.time()
						
						# if we've found a minimum we need to test if the distance value is below a threshold
						# if so add the new transition
						#print distancematrix[1][j]
						#if condition :
						#print (i,j+startframe2), distancematrix[1][j]
						if condition and distancematrix[1][j] < threshold :
							if motindex1 != motindex2 or abs(i-(j+startframe2)) > 3*int(self.window*self.fps) :
								print (i,j+startframe2), distancematrix[1][j]
								frametransitions.append((i,motindex1,j+startframe2,  motindex2, distancematrix[1][j]))
						testtime += time.time() - condtime
						conditiontime += condtime - innerloop_start_time
						
					transitions = transitions + frametransitions
					outer_loop_start_time = time.time()
					
					# go to the next row in the matrix
					distancematrix[0] = distancematrix[1]
					distancematrix[1] = distancematrix[2]
					if i < endframe1-1:
						distancematrix[2] = [self.measure(i+1, f, framearray1, framearray2) for f in range(startframe2,endframe2)]
					loop_distance_time += time.time() - outer_loop_start_time
				print "initial distance time", initial_distance_time
				print "loop distance time", loop_distance_time
				print "condition time", conditiontime
				print "test_time time", testtime
				self.measure.cleartime()
				self.measure.printtime()
				print ""
				#print "transitions", transitions
				#prevframe = None
				
		# get rid of the cached frame values
		for i, m in enumerate(self.motions):
			motion, framearray, numframes = m
			self.motions[i] = motion
			
		return transitions	
		
		
	# this function creates the graph
	def init_nodes(self, transitions, avatar=None):
		self.nodes = {}
		# add an edge for each transition
		for transition in transitions:
			# if either end of the transition is new add a node
			if not self.nodes.has_key((transition[1], transition[0])):
				self.nodes[(transition[1], transition[0])] = Node(transition[0], float(transition[0])/self.fps, transition[1])
			if not self.nodes.has_key((transition[3], transition[2])):
				self.nodes[(transition[3], transition[2])] = Node(transition[2], float(transition[2])/self.fps, transition[3])
			# add the edge
			self.nodes[(transition[1], transition[0])].addChild((transition[3], transition[2]), transition[4])

		# add a continuation  edge between each node and the next node along the motion
		#print self.nodes.keys()
		keys = self.nodes.keys()
		keys.sort()
		#print keys
		for n1, n2 in zip(keys[:-1], keys[1:]):
			#print n1, n2
			if n1[0] == n2[0]:
				#self.nodes[n1].addChild(n2)
				self.nodes[n1].nextNode = n2
				
		print "old next nodes", [(n, self.nodes[n].nextNode) for n in keys]
				
		# we don't want motion clips that are too short, so for each continuation edge, we extend it along the 
		# current motion until its up to a minimum length
		minClipLength = int(self.minClipLength * self.fps)
		for n in keys:
			self.nodes[n].tempNext = self.nodes[n].nextNode
			if self.nodes[n].tempNext == None:
				continue
			while (len(self.nodes[self.nodes[n].tempNext].children) == 1 or self.nodes[n].tempNext[1] - self.nodes[n].frame < minClipLength) and self.nodes[self.nodes[n].tempNext].nextNode != None:
				self.nodes[n].tempNext = self.nodes[self.nodes[n].tempNext].nextNode
			
		for n in keys:
			self.nodes[n].nextNode = self.nodes[n].tempNext
			if self.nodes[n].nextNode != None:
				self.nodes[n].addChild(self.nodes[n].nextNode, 0.0)
			del self.nodes[n].tempNext
				
		print "new next nodes", [(n, self.nodes[n].nextNode) for n in keys]
		
		#print self.nodes.keys()
		#for n in self.nodes.keys():
		#	print "node", n, [x for x in self.nodes[n]]
		
		# find the largest strongly connected component of the graph
		maxcc = {}
		for cc in StronglyConnectedComponents(self.nodes):
			#print "cc", cc
			if len(cc) > len(maxcc):
				maxcc = cc
		#print "maxcc", maxcc
		
		# create a new graph using only nodes in the largest 
		# strongly connected component
		ccnodes = {}
		for n in maxcc.keys():
			#print n,
			ccnodes[n] = copy.copy(self.nodes[n])
			ccnodes[n].clearChildren()
			ccnodes[n].nextNode = None
			# only use children that are in the largest component
			for child in maxcc[n]:
				ccnodes[n].addChild(child, self.nodes[n].transitionCosts[child])
				if child == self.nodes[n].nextNode :
					ccnodes[n].nextNode = child
			#print ccnodes[n].children
		self.nodes = ccnodes
		#print self.nodes.keys()
		print "new next nodes", [(n, self.nodes[n].nextNode) for n in self.nodes.keys()]
		
		# add new continuation nodes, that may have been lost in the scc process
		keys = self.nodes.keys()
		keys.sort()
		#print keys
		for n1, n2 in zip(keys[:-1], keys[1:]):
			#print n1, n2
			if self.nodes[n1].nextNode == None and n1[0] == n2[0]:
				#self.nodes[n1].addChild(n2)
				self.nodes[n1].nextNode = n2
				self.nodes[n1].tempNext = self.nodes[n].nextNode
				if self.nodes[n1].tempNext == None:
					del self.nodes[n1].tempNext
					continue
				while (len(self.nodes[self.nodes[n1].tempNext].children) == 1 or self.nodes[n1].tempNext[1] - self.nodes[n1].frame < minClipLength) and self.nodes[self.nodes[n1].tempNext].nextNode != None:
					self.nodes[n1].tempNext = self.nodes[self.nodes[n1].tempNext].nextNode
				self.nodes[n1].nextNode = self.nodes[n1].tempNext
				if self.nodes[n1].nextNode != None:
					self.nodes[n1].addChild(self.nodes[n1].nextNode, 0)
				del self.nodes[n1].tempNext
		
		# initialise the transitions motions
		self._createTransitionMots(avatar)
		# initialise a suitable first node
		if len(self.nodes.keys()) > 0:
			self.nextnode = self.nodes[self.nodes.keys()[0]]
		else:
			self.nextnode = None
		#self.reblend(Piavca.Core.getCore().getTime())
		
	# choose which transitions to use
	# this version chooses all transitions but this can be overridden
	def selectTransitions(self, transitions, fps):#, outfile):
		return transitions, []
	
	# intiialise a graph from transitions that had been dumped to file
	def testTransitions(self, transitionsfile, fps, window, k, d, avatar = None):
		self.window = window
		self.fps = fps
		file = open(transitionsfile, "r")
		transitions = pickle.load(file)
		file.close()
		split_trans = []
		sub_trans = []
		for trans in transitions:
			if len(sub_trans) > 0 and (trans[0] != sub_trans[-1][0] or trans[1] != sub_trans[-1][1]):
				split_trans.append(sub_trans)
				sub_trans = []
			sub_trans.append(trans)
			
		outfile = open("SelectTransitions.out", "w")
		newtrans = []
		for trans_set in split_trans:
			outfile.write(str(trans_set) + "\n")
			#print "trans_set", trans_set
			print "k,d", k, d
			x = self.selectTransitions(trans_set, self.fps, k, d)#, outfile)
			#print "x", x
			trans, vals = x
			outfile.write(str(vals) + "\n")
			outfile.write(str(trans) + "\n\n")
			if len (trans) > 0:
					newtrans = newtrans + trans
		#print newtrans
		self.init_nodes(newtrans)
	
	# create the motions that transitions between nodes
	def _createTransitionMots(self, avatar = None):
		# go through all the nodes, creating motions for all outgoing edges
		for n in self.nodes.keys():
			#print "node", n, self.nodes[n].nextNode, self.nodes[n].children
			for child in self.nodes[n]:
				# if it is a continuation node, then the motion is just a sub-clip of the original motion
				if child == self.nodes[n].nextNode :
					starttime = self.nodes[n].time
					endtime = self.nodes[child].time
					#print "start time end time", starttime, endtime
					#print "motion number ", self.nodes[n].motion, len(self.motions)
					#print n
					#print self.nodes[n]
					#print self.nodes[n].motion
					#print self.motions[self.nodes[n].motion]
					if starttime > endtime:
						print "zero length", starttime, endtime
						endtime = starttime
					edgeMot = Piavca.SubMotion(self.motions[self.nodes[n].motion].clone(), starttime, endtime)
				# if it is a transition edge, we need to create a transition
				else:   
					mot1 = self.motions[self.nodes[n].motion]
					t1 = self.nodes[n].time
					mot2 = self.motions[self.nodes[child].motion]
					t2 = self.nodes[child].time
					#mot2 = Piavca.SubMotion(mot2, t2-self.window, t2)
					#mot2 = Piavca.Reposition(mot2)
					#mot2.setStartFromMotion(self, Piavca.Core.getCore().getTime())
					#t2 = self.window
					#print "start time end time", t1, t2
					
					#edgeMot = Piavca.MotionTransition(mot1.clone(), None, t1, t2, self.window)
					edgeMot = Piavca.MotionTransition(mot1.clone(), mot2.clone(), t1, t2, self.window)
					if avatar != None:
						edgeMot.footplant_spec = [[1,1],[1,1]]
						for i, m in enumerate([(t1, mot1), (t2, mot2)]):
							time, mot = m
							for j, jointname in enumerate(["LFoot", "RFoot"]):
								jointId = Piavca.Core.getCore().getJointId(jointname)
								avatar.showMotionAtTime(time, mot, 0)
								pos = avatar.getJointBasePosition(jointId, Piavca.WORLD_COORD)
								for t in [time-0.5, time-0.1, time+0.1, time+0.5]:
									avatar.showMotionAtTime(t, mot, 0)
									new_pos = avatar.getJointBasePosition(jointId, Piavca.WORLD_COORD)
									diff = new_pos - pos
									if diff.mag() > 0.1:
										edgeMot.footplant_spec[i][j] = None
										break
						#print edgeMot.footplant_spec
					
					#edgeMot = MotionTransition(mot1, t1, mot2, t2, self.window)
				self.nodes[n].addTransition(child, edgeMot)
	
	def saveGraph(self, filename): 
		print "Saving graph"
		file = open(filename, "w")
		pickle.dump(self.nodes, file)
		pickle.dump(self.window, file)
		self.setFilename(filename)

	def loadGraph(self, filename, avatar = None):
		file = open(filename, "r")
		self.nodes = pickle.load(file)
		self.window = pickle.load(file)
		self._createTransitionMots(avatar)
		self.nextnode = self.nodes[self.nodes.keys()[0]]
		self.setFilename(filename)
		self.reblend(Piavca.Core.getCore().getTime())

	# pick which motion to play
	# this function should be overridden in subtypes to produce different functionalities
	# this version just picks a child of the current node at random
	def chooseNextMotion(self, time):
		if len(self.nextmotions) == 0:
			candidates = self.nextnode.children
			#print candidates
			choice = random.choice(candidates)
			#choice = self.nextnode.nextNode
			print self.nextnode.motion, self.nextnode.time
			print choice
			motion = self.nextnode.getTransition(choice)
			if choice == self.nextnode.nextNode or self.nodes[choice].nextNode == None:
				motion = self.nextnode.getTransition(choice)
				self.setBlendInterval(0)
				self.nextnode = self.nodes[choice]
				print "Next Node"
			else:
				motion = self.nextnode.getTransition(choice)
				self.setBlendInterval(0)
				self.nextnode = self.nodes[choice]
				print "Transition**"
				
				#self.setBlendInterval(1)
				#self.nextnode = self.nodes[choice]
				#motion = self.nextnode.getTransition(self.nextnode.nextNode)
				#self.nextnode = self.nodes[self.nextnode.nextNode]
			#if self.getMotion() != None:
			#	print self.getQuatValueAtTime(Piavca.root_orientation_id, Piavca.Core.getCore().getTime())
			#	print self.getQuatValueAtTime(Piavca.root_orientation_id, Piavca.Core.getCore().getTime()-1.0)
			self.motions[self.nextnode.motion].setStartTime(0)
			#print self.motions[self.nextnode.motion].getQuatValueAtTime(Piavca.root_orientation_id, self.nextnode.time)
			self.motions[choice[0]].setStartTime(0)
			#print self.motions[choice[0]].getQuatValueAtTime(Piavca.root_orientation_id, float(choice[1])/10.0)
			motion.setStartTime(0)
			#print motion.getQuatValueAtTime(Piavca.root_orientation_id, 0) 
			#print motion.getQuatValueAtTime(Piavca.root_orientation_id, 1) 
			#print motion.getQuatValueAtTime(Piavca.root_orientation_id, motion.getEndTime()) 
			#self.nextnode = self.nodes[choice]
			i=0
			while i<10 and self.nextnode.nextNode != None:
				self.nextmotions.append(self.nextnode.getTransition(self.nextnode.nextNode))
				self.setBlendInterval(0)
				self.nextnode = self.nodes[self.nextnode.nextNode]
				i = i + 1
			
			print "clip length", self.nextnode.time - float(choice[1])/self.fps
		else:
			motion = self.nextmotions.pop(0)
			self.setBlendInterval(0)
			
		return motion

	# this is called at the end of each clip
	# (part of the LoopMotion interface) and 
	# is used to choose the next clip
	def reblend(self, time):
		#print "motion graph reblend"
		# get the next motion and play it
		motion = self.chooseNextMotion(time)
		#print "motion", motion
		try:
			footplant_spec = motion.footplant_spec
		except AttributeError:
			#print "got attribute error"
			footplant_spec = None
		self.setAccumulateRoot(1)
		avatar = self.getAvatar()
		if avatar:
			avatar.showMotionAtTime(time)
			pos = avatar.getRootPosition()
			#print "avatar position", pos, "time", time
			#print "motion position", self.getVecValueAtTime(Piavca.root_position_id, time)
		if footplant_spec:
			self.setAccumulateRoot(0)
			if avatar != None:
				print "footplants", footplant_spec
				plantedfeet = 0
				if footplant_spec[0][0] != None :
					plantedfeet += 1
					jointid = Piavca.Core.getCore().getJointId("LFoot")
					pos = avatar.getJointBasePosition(jointid, Piavca.WORLD_COORD)
					ori = avatar.getJointOrientation(jointid, Piavca.WORLD_COORD)
					footplant_spec[0][0] = (pos, ori)
				if footplant_spec[0][1]  != None:
					plantedfeet += 1
					jointid = Piavca.Core.getCore().getJointId("RFoot")
					pos = avatar.getJointBasePosition(jointid, Piavca.WORLD_COORD)
					ori = avatar.getJointOrientation(jointid, Piavca.WORLD_COORD)
					footplant_spec[0][1] = (pos, ori)
				if plantedfeet == 0:
					print "****************** neither planted ************************"
				#print "motion is footplant", footplant_spec
				motion = Piavca.FootPlantOnSpot(motion, footplant_spec)
		else:
			pass#print "############# next node"
		Piavca.LoopMotion.reblend(self,time)
		#print "motion", motion
		self.setMotion(motion)
