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
# The Original Code is FootPlantOnSpot.py
#
# The Initial Developer of the Original Code is Marco Gillies
# Portions created by the Initial Developer are Copyright (C) 2007
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

# maintains footplants for transitions in motions where the character isn't 
# locomoting and so the feet are mostly planted
class FootPlantOnSpot(Piavca.MotionFilter):
	def __init__(self, mot = None, footplants=None):
		if mot != None:
			Piavca.MotionFilter.__init__(self, mot)
		else:
			Piavca.MotionFilter.__init__(self)
		self.__disown__()
		self.setFootPlants(footplants)
		#print "plantedFoot", self.plantedFoot
		#print "liftedKnee", self.liftedKnee
		#print "pos, ori", self.plantPos, self.plantOri
	
	def clone(self):
		newMot = FootPlantOnSpot(self.filterMot, self.footplants)
		return newMot
		
	def setFootPlants(self, footplants):
		self.footplants = footplants
		
		self.plantedFoot = None
		self.liftedKnee = None
		
		# if neither are planted we don't need to do anything
		if None == self.footplants[0][0] and None == self.footplants[0][1]:
			return
			
		# if both are planted we choose one to lift
		if self.footplants[0][0] != None and self.footplants[0][1] != None:
			# if either foot is unplanted at the end we lift that one
			if self.footplants[1][0] == None:
				self.plantedFoot = Piavca.Core.getCore().getJointId("LFoot")
				self.plantPos, self.plantOri = self.footplants[0][0]
				return
			if self.footplants[1][1] == None:
				self.plantedFoot = Piavca.Core.getCore().getJointId("RFoot")
				self.plantPos, self.plantOri = self.footplants[0][1]
				return
			
			#otherwise we must choose one to lift
			if random.random() > 0.5:
				self.plantedFoot = Piavca.Core.getCore().getJointId("LFoot")
				self.plantPos, self.plantOri = self.footplants[0][0]
				self.liftedKnee = Piavca.Core.getCore().getJointId("RKnee")
			else:
				self.plantedFoot = Piavca.Core.getCore().getJointId("RFoot")
				self.plantPos, self.plantOri = self.footplants[0][1]
				self.liftedKnee = Piavca.Core.getCore().getJointId("LKnee")
			return
			
		if self.footplants[0][0] != None:
			self.plantedFoot = Piavca.Core.getCore().getJointId("LFoot")
			self.plantPos, self.plantOri = self.footplants[0][0]
			return 
			
		if self.footplants[0][1] != None:
			self.plantedFoot = Piavca.Core.getCore().getJointId("RFoot")
			self.plantPos, self.plantOri = self.footplants[0][1]
			return 
	
	def isNull(self, trackId):
		#print "footplant isnull"
		if self.plantedFoot == None:
			if trackId == Piavca.root_position_id :
				return 0
			if trackId == Piavca.root_orientation_id :
				return 0
			#if trackId == self.liftedKnee :
			#	return 0
		return Piavca.MotionFilter.isNull(self, trackId)
		
	#def getTrackType (self, trackid):
	#	if self.plantedFoot == None:
	#		if trackId == Piavca.root_position_id :
	#			return Piavca.VEC_TYPE
	#		if trackId == Piavca.root_orientation_id :
	#			return Piavca.QUAT_TYPE
	#		if trackId == self.liftedKnee :
	#			return Piavca.QUAT_TYPE
	#	return Piavca.NULL_TYPE
	
	#def load(self, avatar):
	#	Piavca.MotionFilter.load(self, avatar)
	#	self.preFrame(Piavca.Core.getCore().getTime())
		
	def setStartTime(self, time):
		Piavca.MotionFilter.setStartTime(self, time)
		if self.getAvatar() != None:
			self.preFrame(Piavca.Core.getCore().getTime())
	
	def preFrame(self, time):
		#print "Footplants, preFrame"
		Piavca.MotionFilter.preFrame(self, time)
		#print "Footplants, preFrame"
		if self.plantedFoot == None:
			return
		av = self.getAvatar()
		ori = av.getRootOrientation()
		pos = av.getRootPosition()
		#print "old ori", ori, "old pos", pos
		pos = av.getJointBasePosition(self.plantedFoot, Piavca.WORLD_COORD)
		#print "old foot pos", pos
		av.showMotionAtTime(time, self.getMotion(),0)
		ori = av.getJointOrientation(self.plantedFoot, Piavca.WORLD_COORD)
		pos = av.getJointBasePosition(self.plantedFoot, Piavca.WORLD_COORD)
		#print "rootpos", av.getRootPosition()
		#print "current pos, ori", pos, ori
		#print "jointlocal", av.getJointOrientation(self.plantedFoot, Piavca.JOINTLOCAL_COORD), av.getJointOrientation(self.plantedFoot, Piavca.JOINTLOCAL_COORD)
		#print "world", av.getJointOrientation(self.plantedFoot, Piavca.WORLD_COORD), av.getJointOrientation(self.plantedFoot, Piavca.WORLD_COORD)
		#if abs(ori[0]+ori[1]+ori[2]+ori[3]) < 0.0001:
		#	asdf
		
		#self.rootOri = self.plantOri * ori.inverse()
		self.rootOri = Piavca.Quat()#self.plantOri * ori.inverse()
		#print "plant ori", self.plantOri, "current ori", ori
		#print "plant pos", self.plantPos, " current pos ", self.rootOri.transform(pos)
		#self.rootPos = self.plantPos - self.rootOri.transform(pos)
		self.rootPos = self.plantPos - pos
		#print "root pos in preframe", self.rootPos
		#print "root ori in preframe", self.rootOri
		#print "new plant ori", self.rootOri*ori
		#print "new plant pos", self.rootOri.transform(pos) + self.rootPos
		
	def getVecValueAtTimeInternal(self, trackId, time):
		#print "Footplant.vecvalue"
		#print "planted foot", self.plantedFoot
		if self.plantedFoot != None:
			if trackId == Piavca.root_position_id :
				#print "root pos", self.rootPos,
				v = Piavca.MotionFilter.getVecValueAtTimeInternal(self, trackId, time)
				#print v
				v = v+self.rootPos
				#print v
				return v
		return Piavca.MotionFilter.getVecValueAtTimeInternal(self, trackId, time)
		
	def getQuatValueAtTimeInternal(self, trackId, time):
		#print "Footplant.quatvalue"
		if self.plantedFoot != None:
			if trackId == Piavca.root_orientation_id :
				#print "root ori", self.rootOri,
				q = self.rootOri*Piavca.MotionFilter.getQuatValueAtTimeInternal(self, trackId, time)
				#print q
				return q
			if trackId == self.liftedKnee and not self.isNull(self.liftedKnee):
				t = time - self.getStartTime()
				t = t/self.getMotion().getMotionLength()
				q = self.getMotion().getQuatValueAtTimeInternal(trackId, time)
				angle = q.getAngle()
				addon = t*(1 - t)
				angle = angle + 1.5*addon
				q.setAngleAxis(angle, q.getAxis())
				#print q
				return q
		return Piavca.MotionFilter.getQuatValueAtTimeInternal(self, trackId, time)
