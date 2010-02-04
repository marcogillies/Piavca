#!/usr/bin/env python2.6
#
#  DynamicTimewarp.py
#  DynamicTimewarp
#
#  Created by Marco Gillies on 13/12/2009.
#  Copyright (c) 2009 __MyCompanyName__. All rights reserved.
#

import operator
from itertools import izip

def poseDifference(p1, p2):
	#p1 = [p for p in p1]
	#print p1
	#p2 = [p for p in p2]
	#print p2
	jointdifferences = (j1.dist(j2) for j1, j2 in izip(p1[1:], p2[1:]))
	jointdifferences = [j for j in jointdifferences]
	print jointdifferences
	return reduce(operator.add, jointdifferences, 0.0)
	

def DynamicTimewarpWithCost(seq1, seq2, dist):
	print "in dynamic timewarp"
	DTW = [[[0, (0, 0)] for s2 in seq2] for s1 in seq1]
	for i in range(len(seq1)):
		DTW[i][0][0] = 10000000000.0
	for j in range(len(seq2)):
		DTW[0][j][0] = 10000000000.0
	DTW[0][0][0] = 0	
	
	#print "initialized DT"
	
	for i in range(1,len(seq1)):
		for j in range(1,len(seq2)):
			cost = dist (seq1[i], seq2[j])
			#print cost
			pval, pi, pj = min([(DTW[i-1][j][0], i-1, j), (DTW[i][j-1][0], i, j-1), (DTW[i-1][j-1][0], i-1, j-1)])
			DTW[i][j][0] = cost + pval
			DTW[i][j][1] = (pi,pj)
			
	#for a in DTW:
	#	for b in a:
	#		print b[1],
	#	print ""
	
	#print "finished main DT loop"
	
	i = len(seq1)-1
	j = len(seq2)-1
	cost = DTW[i][j][0]
	warp = range(len(seq2))
	while i != 0 or j != 0:
		i,j = DTW[i][j][1]
		#print i,j
		warp[j] =i
		
	print "finished DT", cost	
	return cost, warp
	
def DynamicTimewarpCost(seq1, seq2, dist):
	return DynamicTimewarpWithCost(seq1, seq2, dist)[0]
	
def DynamicTimewarp(seq1, seq2, dist):
	return DynamicTimewarpWithCost(seq1, seq2, dist)[1]
	
if __name__ == "__main__":
	
	from math import *
	from random import randint
	
	s1 = [sin(radians(x)) for x in range(0, 360, 10)]
	print s1
	
	timewarp1 = [2*x for x in range(9)] + [18 + 2*(x-9)/3 for x in range(9, 36)] 
	s2 = [s1[timewarp1[i]] for i in range(36)]
	print s2
	cost, warp = DynamicTimewarpWithCost(s1, s2, lambda x, y: abs(x-y))
	print [(i,j) for i,j in enumerate(timewarp1)]
	print timewarp1
	print warp
	
	i = 0
	timewarp2 = []
	while i < len(s1):
		timewarp2.append(i)
		i += randint(0,1)
	print timewarp2
	s3 = [s1[timewarp2[i]] for i in range(len(timewarp2))]
	print s3
	warp = DynamicTimewarp(s1, s3, lambda x, y: abs(x-y))
	print [(i,j) for i,j in enumerate(timewarp2)]
	print timewarp2
	print warp
	