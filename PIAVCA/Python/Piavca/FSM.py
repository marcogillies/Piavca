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
# The Original Code is FSM.py
#
# The Initial Developer of the Original Code is
#  Marco Gillies
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
# ***** END LICENSE BLOCK ****

import Piavca

class FSM (Piavca.ChoiceMotion):
	def __init__(self, fsmfile= None, fsm=None, choicemot=None):
		if choicemot != None:
			Piavca.ChoiceMotion.__init__(self, choicemot)
		else:
			Piavca.ChoiceMotion.__init__(self)
		if fsm:
			self.fsm = fsm
		else:
			self.fsm = {}
		self.currentState = None
		self.__disown__()
	
	def clone(self):
		newMot = FSM(fsm=self.fsm, choicemot=self)
		newMot.currentState = self.fsm[self.fsm.keys()[0]][1]
		return newMot
		
	#def addMotion(self, motion):
	#	Piavca.ChoiceMotion.addMotion(self, motion)
			
	def addState(self, name, motion):
		print "adding state", name, motion
		if type(name) != type(""):
			raise TypeError("state labels have to be strings")
		try:
			motion_number = int(motion)
		except ValueError:
			motion_number = self.getMotionIndex(motion)
			if motion_number < 0:
				raise ValueError("could not find motion" + str(motion))
		self.fsm[name] = (motion_number, {})
		print "adding state", name, motion
		if self.currentState == None:
			self.currentState = self.fsm[name][1]
	
	def addTransition(self, s1, s2, event):
		if type(s1) != type(""):
			raise TypeError("state labels have to be strings")
		if type(s2) != type(""):
			raise TypeError("state labels have to be strings")
		self.fsm[s1][1][event] = str(s2)
	
	def event(self, event):
		if not self.wasVisited():
			#print "In FSM:", event, self.currentState
			if self.currentState.has_key(event):
				state = self.currentState[event]
				#print "state", state, self.currentState
				motion, self.currentState = self.fsm[state]
				self.setCurrentChoice(motion)
				self.reset()
				#print event, state
			else:
				print "could not find", event, "in", self.currentState.keys()
		Piavca.ChoiceMotion.event(self, event)
			
class FSMLoop (Piavca.LoopMotion):
	def __init__(self, fsmfile= None, fsm=None):
		Piavca.LoopMotion.__init__(self)
		self.fsmmot = FSM(fsmfile, fsm)
		self.setMotion(self.fsmmot)
			
	def addState(self, name, motion):
		self.fsmmot.addState(name, motion_number)
	
	def addTransition(self, s1, s2, event):
		self.fsmmot.addTransition(s1, s2, event)
	
	def event(self, event):
		self.fsmmot(event)
		
	def reblend(self, time):
		self.event("motion_end")
		Piavca.LoopMotion.reblend(self, time)