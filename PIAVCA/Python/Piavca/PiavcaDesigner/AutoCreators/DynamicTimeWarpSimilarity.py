#
#  DynamicTimeWarpSimilarity.py
#  piavca
#
#  Created by Marco Gillies on 03/02/2010.
#  Copyright (c) 2010 __MyCompanyName__. All rights reserved.
#


import Piavca
from Piavca.DynamicTimewarp import *
from Piavca.MotionIterators import *
from Piavca.PiavcaDesigner.ParameterControls import *
from FindTransitions import findMinima
import itertools

class DynamicTimeWarpSimilarity:
	
	def createControls(self, frame):
		controls = []
		
		self.motion = MotionParamEntry("motion", None, frame)
		controls.append(("motion", self.motion))
		
		self.comparisonMotion = MotionParamEntry("comparisonMotion", None, frame)
		controls.append(("comparisonMotion", self.comparisonMotion))
		
		self.threshold = FloatParamEntry("threshold", None, frame)
		self.threshold.setValue(40)
		controls.append(("threshold", self.threshold))
		
		self.fps = FloatParamEntry("Frames per second", None, frame)
		self.fps.setValue(20)
		controls.append(("Frames per second", self.fps))
		
		self.queryButton = wx.Button(frame, -1, "Query")
		frame.Bind(wx.EVT_BUTTON, self.query, self.queryButton)
		#self.mainSizer.Add(self.queryButton, 0, wx.EXPAND)
		controls.append(("query", self.queryButton))

		self.list = wx.ListCtrl(frame,-1,style=wx.LC_LIST)
		frame.Bind(wx.EVT_LIST_ITEM_ACTIVATED, self.showResult)
		#self.mainSizer.Add(self.list, 1, wx.EXPAND)
		#controls.append(("motions", self.list))
		
		return controls, [self.list]

	def query(self, e):
		mot = self.motion.getValue()
		compMotion = self.comparisonMotion.getValue()
		
		fps = self.fps.getValue()
		threshold = self.threshold.getValue()	
		
		compMotSeq = MotionList(compMotion, fps)
		
		#frameslist = self.backend.getMotionFramesByName(framelist)
		frameslist = findMinima(mot, compMotion, 0.0, threshold, fps)
		print frameslist
		
		
		framepairs = itertools.chain(zip(frameslist[:-1], frameslist[1:]),zip(frameslist[:-2], frameslist[2:]),zip(frameslist[:-3], frameslist[3:])) 
		submots = ((MotionList(Piavca.SubMotion(mot, f1, f2), fps),f1,f2) for f1, f2 in framepairs)
		
		#submots = [a for a in submots]
		#print submots
		
		#print "about to call dynamic timewarp"
		
		results = [(DynamicTimewarpCost(compMotSeq, submot, poseDifference), f1, f2) for submot, f1, f2 in submots]
		results.sort()
		
		print "results", results
		
		for i, result in enumerate(results):
			self.list.InsertStringItem(i, str(result[0]) + " " + str(result[1]) + " " + str(result[2]))
		
	def showResult(self, e):
		pass
		
	def getMotion(self):
		motion = self.motion.getValue()
		
		return None