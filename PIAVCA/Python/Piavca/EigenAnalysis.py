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
import Piavca.ExpMap

import string
import re
import math

#import mdp
import scipy

import sys
import time

#sys.path.append("../ExponentialMap/ExpMap/")

#import ExpMap

#import Track

# perform an EigenAnalysis (e.g. PCA) on motion data
class EigenAnalysis :
	def __init__ (self):
		# the number of principal components to use
		self.num_pcs = 0
		# exponential map parameters
		self.expmaps = []
		# a list of all joints giving their type (or None if they are null)
		self.joint_types = []
		# mapping between joint ids and array indices
		self.jointmap = []
		# the cluster means for vector quantization
		self.quants = None
		self.precentageToKeep = 0.99
		
	def clone(self):
		newEA = EigenAnalysis()
		newEA.num_pcs = self.num_pcs
		newEA.expmaps = list(self.expmaps)
		newEA.joint_types = list(self.joint_types)
		newEA.jointmap = list(self.jointmap)
		if self.quants != None:
			newEA.quants = list(self.quants)
		newEA.precentageToKeep = self.precentageToKeep
		newEA.pcs = scipy.array(self.pcs)
		newEA.weights = scipy.zeros((newEA.num_pcs,),'d')
		newEA.generateMotion()
		return newEA
		

	# this has to be calculated by the sub types
	def get_matrix (self, data):
		pass
		
	def setPercentageToKeep(self, percent):
		self.precentageToKeep = percent
		
	def get_eigenvectors (self, mat):
		vals, vecs = scipy.linalg.eigh(mat)
		sum = 0.0
		for i in range(len(vals)-1, -1, -1):
			if vals[i] <= 0.0:
				break
			sum += vals[i]
			#print sum
		accumulate = 0.0
		pcs = []
		for i in range(len(vals)-1, -1, -1):
			if vals[i] <= 0.0:
				break
			accumulate += vals[i]
			#print i, vals[i], accumulate
			#print vecs[i]
			pcs.append(scipy.transpose(vecs)[i])
			print i, vals[i], len(vals), accumulate/sum
			if accumulate/sum > self.precentageToKeep: break
		print "number of pcs ", len(pcs)
		return scipy.matrix(pcs)
		
	def preprocessData(self, motions, fps):
		# the eigen analysis can be performed either on postures
		# of short motion clips defined by the splits
		length = motions[0].getMotionLength()
		ranges = [(i, 0.0, motions[i].getMotionLength()) for i in range(len(motions))]
					
		# joint rotations mapped by the exponential map
		mappedvals = []
		# a list of all joints giving their type (or None if they are null)
		self.joint_types = [Piavca.NULL_TYPE]
			
		# mapping between joint ids and array indices
		# (root is not handled at the moment)
		self.jointmap = [None]
		
		# begin an iteration over joints that calculates the 
		# exponential map parameters for each joint and then
		# maps the values onto the tangent space
		i = 0
		# for profiling
		quatlisttime = 0
		tangentspacetime = 0
		logmaptime = 0
		# this bit assumes that all motions have the same number of valid joints
		for joint in range(1, motions[0].end()) :
			if( not motions[0].isNull(joint)):
				print "joint ", joint, " type ", motions[0].getTrackType(joint)
				self.joint_types.append(motions[0].getTrackType(joint))
				# if there are no splits we are acting directly on the postures
				starttime = time.clock()
				
				# take a bunch of samples of postures
				quatlist = []
				for motion  in motions:
					length = int ((motion.getMotionLength())*fps)
					quatlist = quatlist + [motion.getQuatValueAtTime(joint, (float(t)/fps)) for t in range(length)]
				length = len(quatlist)

				qtime = time.clock()
				quatlisttime += qtime - starttime
					
				# create a tangent space based on the averages of the postures
				expmap = Piavca.ExpMap.TangentSpace(quatlist)
					
				ttime = time.clock()
				tangentspacetime += ttime - qtime
				#print "doing log maps"
					
				# save the calculated tangent space
				self.expmaps.append(expmap)
				# map all of the sampled joint rotations onto the tangent space
				mappedvals.append([expmap.logMap(q) for q in quatlist])
					
				ltime = time.clock()
				logmaptime += ltime - ttime
					
				# add the current joint to the joint map
				self.jointmap.append(len(mappedvals)-1)        
			else:
				# if the joint was null put nothing on the joint map
				self.jointmap.append(None)
				self.joint_types.append(Piavca.NULL_TYPE)

		# profiling info
		#print "quatlist time ", quatlisttime, "tangent space time", tangentspacetime, "log map time", logmaptime

		# length is the number of observations 
		# each is of mappedvals*3 data items (each mapped val corresponds to a
		# joint rotation mapped to a 3 vector)
		self.no_vals = len(mappedvals)
		self.no_vals = 3*self.no_vals
		
		#print length, no_vals
		#print "size of input ", len(mappedvals)
		print "generating matrix*************"
		# fill out a blank matrix
		self.length = length
		data = scipy.zeros((length, self.no_vals),'d')
		# fill it with the data we have just created
		# (the log-mapped joint rotations)
		i = 0
		for mappedval in mappedvals :
			#print length, len(mappedval)
			j = 0
			for v in mappedval:
				#print j, i
				data[j][3*i] = v[0]
				data[j][3*i+1] = v[1]
				data[j][3*i+2] = v[2]
				j+=1
			i+=1
		
		return data
	
	def do_analysis (self, motions, fps):
		print "start Component Analysis"
		data = self.preprocessData(motions, fps)
		
		mat = self.get_matrix(data)
		newpcs = self.get_eigenvectors(mat)
		
		self.num_pcs = len(newpcs)
		self.pcs = scipy.transpose(scipy.array(newpcs)) 
		# initially set all PC weights to 0     
		self.weights = scipy.zeros((self.num_pcs,),'d')

		# regenrate the motion based on the new PCA model (and 0 weights)
		self.generateMotion()
	
	# do the preprocessing stage of vector quantization
	def KMeans(self, projectedWeights, NumQuants):
		self.quants, distortion = scipy.cluster.vq.kmeans(projectedWeights, NumQuants)
		#print distortion
		#print "cluster centres"
		#print self.quants
		return self.VectorQuantize(projectedWeights)
	
	# vector quantise some data
	def VectorQuantize(self, x):
		#print "cluster centres"
		#print self.quants
		#print x
		qs, dist = scipy.cluster.vq.vq(x, self.quants)
		#print "vq returned"
		return qs
		
	# save to file
	def Save (self, filename):
		f = open(filename, 'w')
		
		f.write("Num Pcs: " + repr(self.num_pcs) + "\n")
		#f.write("Using Splits: " + repr(self.using_splits) + "\n")

		f.write("Exp Maps: ")
		for expMap in self.expmaps :
			f.write(repr(expMap.mean()) + " ")
		f.write("\n")
		
		f.write("Joint Types: ")
		for joint_type in self.joint_types :
			f.write(repr(joint_type) + " ")
		f.write("\n")
		
		f.write("Joint Map: ")
		for joint in self.jointmap :
			f.write(repr(joint) + " ")
		f.write("\n")
		
		if self.quants != None:
			f.write("Quants: ")
			for quant in self.quants :
				for number in quant:
					f.write(repr(number) + " ")
				f.write("; ")
			f.write("\n")
		
		f.write("length: " + repr(len(self.vecs)) + "\n")
		
		f.write("data:\n")
		for j in range(len(self.pcs[0])):
			for i in range(len(self.pcs)):
				f.write(str(self.pcs[i,j]) + " ")
			f.write("\n")
		
		#f.write("PC data:\n")
		#for i in range(self.length):
		#   for j in range(self.no_vals):
		#       f.write(str(data[i][j]) + " ")
		#   f.write("\n")
		
		#print "expmaps"
		#i = 0
		#for expmap in self.expmaps :
		#   print i, expmap.mean()
		#   i += 1
		#print "jointmap"
		#i = 0
		#for joint in self.jointmap :
		#   print i, joint
		#   i += 1
	
	def Load(self, filename):
		f = open (filename, "r")
		
		lines = f.readlines()
		data_portion = 0
		i = 0
		for line in lines :
			if not data_portion :
				contents = string.split(line, ":")
				print contents
				if contents[0] == "Num Pcs":
					self.num_pcs = int(contents[1])
					print self.num_pcs
				#if contents[0] == "Using Splits":
				#	self.using_splits = int(contents[1])
				#	print self.using_splits
				if contents[0] == "Exp Maps":
					print "expmaps"
					self.expmaps = []
					print "expmaps"
					number_pattern = re.compile("-?((([0-9]+)|([0-9]*\.[0-9]+))([eE][-+]?[0-9]+)?)")
					print "expmaps"
					quat_pattern = re.compile("\[[^\]]*\]")
					print "created regexp"
					matches = quat_pattern.findall(contents[1])
					print "got matches"
					for match in matches :
						print "match"
						numbers = string.split(match[1:-1])
						print numbers
						q = Piavca.Quat(float(numbers[0]), float(numbers[1]), float(numbers[2]), float(numbers[3]))
						print q
						self.expmaps.append(Piavca.ExpMap.TangentSpace(q))
					print matches
				if contents[0] == "Joint Types":
					self.joint_types = []
					numbers = string.split(contents[1])
					for number in numbers:
						self.joint_types.append(int(number))
				if contents[0] == "Joint Map":
					self.jointmap = []
					numbers = string.split(contents[1])
					for number in numbers:
						if number == "None":
							self.jointmap.append(None)
						else:
							self.jointmap.append(int(number))
				if contents[0] == "Quants":
					self.quants = []
					quants = string.split(contents[1], ";")
					for quant in quants: 
						if quant == "":
							continue
						if quant == "\n":
							continue
						q = []
						numbers = string.split(quant)
						for number in numbers:
							if number == "":
								continue
							q.append(float(number))
						if q != []:
							self.quants.append(q)
					#print self.quants
					self.quants = scipy.array(self.quants)
				if contents[0] == "length":
					self.pcs = scipy.zeros((int(contents[1]), self.num_pcs),'d')
				if(contents[0] == "data"):
					data_portion = 1
			else:
				numbers = string.split(line)
				if numbers == [] :
					continue
				#print len(numbers)
				for j in range(len(numbers)):
					self.pcs[j][i] = float(numbers[j])
				i += 1
			#print self.pcs
		self.weights = scipy.zeros((self.num_pcs,),'d')
		self.generateMotion()
		
		#print "expmaps"
		#i = 0
		#for expmap in self.expmaps :
		#   print i, expmap.mean()
		#   i += 1
		#print "jointmap"
		#i = 0
		#for joint in self.jointmap :
		#   print i, joint
		#   i += 1
				
	# set the value of a PC weight 
	def setWeight (self, pc, w):
		#print i, w 
		self.weights[pc] = w
		self.generateMotion()
				
	# set the value of a PC weight 
	def setWeights (self, w):
		#print i, w 
		for i in range(self.num_pcs):
			self.weights[i] = w[i]
		self.generateMotion()

	# project the weights onto the PCA to generate a new motion
	# (creates the motion in an internal motion format, use
	# getQuatValueAtTime to get it as joint rotations)
	def generateMotion (self):
		self.vecs = self.pcs*scipy.asmatrix(self.weights).T
		self.vecs = self.vecs.T
		self.vecs = scipy.asarray(self.vecs)[0]
		
	def projectBack (self, vals):
		weights =  scipy.dot(vals,self.pcs)
		return weights
	
	def projectMotion (self, motion, frames_per_second = 20.0):
		projections = []
		for t in range(int(motion.getMotionLength()*frames_per_second)):
			time = float(t)/frames_per_second
			projections.append((time, projectMotionsAtTime(motion, time)))
		return projections
		
	
	
	def projectMotionAtTime (self, motion, time):
		mappedvals = []
		i = 0
		for joint in range(1, motion.end()) :
			if( not motion.isNull(joint)):
				#print "joint ", joint, " type ", motion.getTrackType(joint)
				# if there are no splits we are acting directly on the postures
				
				# take a bunch of samples of postures
				q = motion.getQuatValueAtTime(joint, float(time))
				mappedvals.append(self.expmaps[i].logMap(q))
				i += 1
				
		vals = scipy.zeros((len(mappedvals)*3,),'d')
		j = 0
		for vecs in mappedvals:
			vals[j]   = vecs[0]
			vals[j+1] = vecs[1]
			vals[j+2] = vecs[2]
			j += 3
		#print vals
		return self.projectBack(vals)
		
	def getTrackValue(self, trackid, time):
		i = self.jointmap[trackid]
		if i != None :
			v = Piavca.Vec(self.vecs[3*i], self.vecs[3*i+1], self.vecs[3*i+2])
			return  self.expmaps[i].expMap(v)
		else:
			return Piavca.Quat()
			
	
	def getMotionLength (self):
		return 0
		
	
