
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
from scipy import array
import math

class ClusterMotionGraph(Piavca.MotionGraph):
	def __init__(self, motions=[], pcs=None, window = 1.0):
		self.pcs = pcs
		self.pcFile != None
		self.num_quants = 10
		Piavca.MotionGraph.__init__(self, motions, window)
		
	def setNumQuants(self, num):	
		self.num_quants = num
		
	def setPCs(self, pcs):
		self.pcs = pcs
		
	def setPCFile(self, pcfile):
		self.pcFile = pcfile
		if self.pcFile:
			self.pcs = Piavca.PCA()
			self.pcs.load(self.pcfile)
		else:
			self.pcs = None
	
	def calcDistance(self, v1, v2):
		dist = 0.0
		for i, j in zip(v1, v2):
			d = i-j
			dist += d*d
		#print "dist", dist
		#print v1, v2
		dist = math.sqrt(dist)
		return dist
	
	def calcVelocityDotProd(self, expmaps, frame1, frame2, outfile=None):
		
		if outfile != None:
			print >> outfile, frame1, ",", frame2,
		dots = []
		for p0, p1, p2 in zip(expmaps[frame1[0]][frame1[1]],expmaps[frame1[0]][frame1[1]+1],expmaps[frame2[0]][frame2[1]]):
			v1 = p1 - p0
			v2 = p2 - p0
			dots.append(v1.dot(v2))
			if outfile != None:
				print >> outfile, dots[-1], ",",
		if outfile != None:
			print >> outfile, ""
		return dots
	
	def NegativeDotProdCount(self, expmaps, frame1, frame2, outfile=None):
		
		if outfile != None:
			print >> outfile, frame1, ",", frame2, ",",
		dots = self.calcVelocityDotProd(expmaps, frame1, frame2)
		count = 0 
		for d in dots:
			if d < 0:
				count += 1
		
		if outfile != None:
			print >> outfile, count, ",", len(dots)
		return count
	
	def findTransitions(self, avatar=None):
		
		if self.pcs == None:
			if self.pcFile != None:
				print "found pc file"
				self.pcs = Piavca.PCA()
				self.pcs.load(self.pcfile)
			else:
				Piavca.Error("No Principal components specified for cluster Motion graph")
		else:
			print "found pcs"
		
		self.fps = 20.0
		projectedMotions = []
		expmaps = []
		# project all the motions onto the pcs
		for motion in self.motions:
			print "motion", motion, motion.getStart(), motion.getEnd()
			projectedMotions.append([pw[1] for pw in self.pcs.projectMotion(motion, frames_per_second=self.fps)])#, file_extension="weights_out_"+ str(motion.getStart()))])
			expmaps.append(self.pcs.getExpMaps(motion, frames_per_second=self.fps))
			f = open("weights_out_"+ str(motion.getStart()) +".csv", "w")
			for weightset in projectedMotions[-1]:
				for w in weightset:
					print >> f, w, ",",
				print >> f, ""
			f.close()
			#f = open("expmaps_out_"+ str(motion.getStart()) +".csv", "w")
			#for e in expmaps[-1]:
			#	for w in e:
			#		print >> f, w, ",",
			#	print >> f, ""
			#f.close()
			
				
		if self.pcs.quants == None:
			print "calculating cluster centres"
			weights = []
			for projmot in projectedMotions:
				weights = weights + projmot
			weights = array(weights)
			quantizedWeights = self.pcs.KMeans(weights, self.num_quants)
		
		self.num_quants = self.pcs.numQuants()
			
			
		quants = []
		for projmot in projectedMotions:
			quants.append(self.pcs.VectorQuantizeWithDistance(array(projmot)))
		
		print self.pcs.pcs
		print self.pcs.quants
			
		f = open("quanta_out.csv", "w")
		for q in quants[0][0]:
			print >> f, q
		f.close()
			
		minima = [[] for i in range(self.num_quants)]
		cluster_counts = [0 for i in range(self.num_quants)]
		
		f = open("minima_out.csv", "w")
		for motNum, (motQuants, motDists) in enumerate(quants):
			print "ClusterMotionGraph, finding minima in motion", motNum, "length", len(motQuants)
			currentQuant = None
			currentMinimum = None
			currentMinimumVal = 1000000.0
			added = False
			for i in range(1, len(motQuants)-1):
				print >> f, motQuants[i], ",", motDists[i]
				cluster_counts[motQuants[i]] += 1
				if motQuants[i] != currentQuant:
					if currentQuant != None and not added:
						minima[currentQuant].append((motNum, currentMinimum))
					added = False
					currentQuant = motQuants[i]
					currentMinimum =i
					currentMimimumVal = motDists[i]
				else:
					if motDists[i] < currentMinimumVal:
						currentMinimum =i
						currentMimimumVal = motDists[i]
				if motQuants[i-1] == motQuants[i] and motQuants[i] == motQuants[i+1]:
					if motDists[i-1] > motDists[i] and motDists[i] < motDists[i+1]:
						minima[motQuants[i]].append((motNum, i))
						added = True
		
			if currentQuant != None and not added:
				minima[currentQuant].append((motNum, currentMinimum))
		f.close()				
		
#		for motNum, (motQuants, motDists) in enumerate(quants):
#			print "ClusterMotionGraph, finding minima in motion", motNum
#			currentQuant = None
#			currentMinimum = None
#			currentMinimumVal = 1000000.0
#			for i, (q, dist) in enumerate(zip(motQuants, motDists)):
#				if q != currentQuant:
#					if currentQuant != None:
#						minima[currentQuant].append((motNum, currentMinimum))
#					currentQuant = q
#					currentMinimum =i
#					currentMimimumVal = dist
#				else:
#					if dist < currentMinimumVal:
#						currentMinimum =i
#						currentMimimumVal = dist
		
		
		print "cluster stats"
		for i, s in enumerate(minima):
			print i, len(s), cluster_counts[i]
		print "ClusterMotionGraph: setting up transitions"
		f = open("expmaps_out.csv", "w")
		transitions = []
		for hub in minima:
			for motNum1, frame1 in hub:
				for motNum2, frame2 in hub:
					dist = self.calcDistance(projectedMotions[motNum1][frame1], projectedMotions[motNum2][frame2])
					#if self.NegativeDotProdCount(expmaps, (motNum1, frame1), (motNum2, frame2), f) < 6:
					transitions.append((frame1, motNum1, frame2, motNum2, dist))
					
		f.close()
		
		self.quants = quants
		return transitions
	
	def init_nodes(self, transitions, avatar=None):
		Piavca.MotionGraph.init_nodes(self, transitions, avatar)
		for k in self.nodes.keys():
			mot, frame = k
			self.nodes[k].cluster = self.quants[mot][0][frame]
			
		del self.quants
			