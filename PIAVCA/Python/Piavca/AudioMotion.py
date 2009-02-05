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
# The Original Code is AudioMotion.py
#
# The Initial Developer of the Original Code is Marco Gillies
# Portions created by the Initial Developer are Copyright (C) 2008
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
import Piavca.SoundEngine

# This isn't really a motion at all, it just wraps a motion interface 
# around audio playing functionality
class AudioMotion(Piavca.Motion):
	def __init__(self, filename = ""):
		Piavca.Motion.__init__(self)
		self.__disown__()
		
		self.setFilename(filename)
		self.playing = False
		
	def clone(self):
		newmot = AudioMotion(self.filename)
		return newmot
	
	def getClassName(self):
		return "AudioMotion"
		
	def setFilename(self, filename): 
		self.filename = filename
		if self.filename != "":
			se = Piavca.SoundEngine.getSoundEngine()
			se.addSound(filename, filename)
		self.playing = False
		
	def getFilename(self): 
		return self.filename
			
	def load(self, av):
		Piavca.Motion.load(self, av)
		self.playing = False
		
	def unload(self):
		Piavca.Motion.unload(self)
		self.playing = False
		
	def reset(self):
		Piavca.Motion.reset(self)
		self.playing = False
		return True
		
	def isNull(self, trackid):
		return True
	
	def getTrackType(self, trackid):
		return Piavca.NULL_TYPE
	
	def getMotionLength(self):
		se = Piavca.SoundEngine.getSoundEngine()
		l = se.getClipLength(self.getFilename())
		#print "getting audio motion length", self.getFilename(), l
		return l
	
	def preFrame(self, t):
		#print "Audio Motion preframe"
		Piavca.Motion.preFrame(self, t)
		if self.filename == "":
			return
		se = Piavca.SoundEngine.getSoundEngine()
		if not self.playing or se.getCurrentlyPlaying() != self.filename:
			se.playRandomAccess(self.filename)
			self.playing = True
		t = t - self.getStartTime()
		se.updateRandomAccess(t)
		