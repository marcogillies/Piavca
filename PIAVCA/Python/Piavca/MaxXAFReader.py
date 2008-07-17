

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
# The Original Code is XMLMotionFile.py
#
# The Initial Developer of the Original Code is
# Marco (Mark) Gillies
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
import types 
import string

#print dir(Piavca)

	
import xml.dom.minidom as minidom

class MaxXAFMotion(Piavca.KeyframeMotion):
	def __init__(self, filename=""):
		Piavca.KeyframeMotion.__init__(self)
		self.__disown__()
		
		self.tickrate = 30.0*160.0
		self.startTick = 0.0
		
		self.setFilename(filename)
		
	def clone(self):
		newmot = MaxXAFMotion(self.filename)
		return newmot
	
	def getClassName(self):
		return "MaxXAFMotion"

	def getFilename(self):
		return self.filename

	def setFilename(self, filename):
		self.filename = filename 
		if self.filename == "":
			return
		
		dom = minidom.parse(filename) 
		
		#mot = Piavca.KeyframeMotion()
		
		for topLevel in dom.childNodes:
			for mainelement in topLevel.childNodes:
				if mainelement.nodeName == "SceneInfo":
					startTick = mainelement.getAttribute("startTick")
					try:
						self.startTick = float(startTick)
					except ValueError:
						pass
					fps = 30.0
					try:
						fps = float(mainelement.getAttribute("frameRate"))
					except ValueError:
						pass
					ticksPerFrame = 160.0
					try:
						ticksPerFrame = float(mainelement.getAttribute("ticksPerFrame"))
					except ValueError:
						pass
					self.tickrate = fps*ticksPerFrame
				if mainelement.nodeName == "Node":
					for nodechild in mainelement.childNodes:
						#print nodechild.nodeName
						if nodechild.nodeName == "Controller":
							nm = nodechild.getAttribute("name")
							#print nm
							nm_elements = nm.split()
							track = Piavca.Core.getCore().nullId
							for el in nm_elements:
								#print el, Piavca.Core.getCore().getTrackId(el)
								track = Piavca.Core.getCore().getTrackId(el)
								if track != Piavca.Core.getCore().nullId:
									break
							if track != Piavca.Core.getCore().nullId:
								print "found track", el, track
								keyframes = []
								for keyset in nodechild.childNodes:
									print keyset.nodeName
									if keyset.nodeName == "Keys" or keyset.nodeName == "Samples":
										for key in keyset.childNodes:
											if key.nodeName == "Key":
												t = key.getAttribute("t")
												try: 
													t = float(t)
												except ValueError:
													continue
												
												v = key.getAttribute("v")
												#try: 
												#	v = float(t)
												#except ValueError:
												#	continue
												keyframes.append((t,v))
										print keyframes
										v = keyframes[0][1]
										v = str(v)
										v = v.strip()
										v = v.split()
										print v
										if len(v) == 1:
											print "scalar", v
											try:
												v = float(v[0])
												print "float", v
												self.addFloatTrack(track, v)
												for t, v in keyframes:
													print t, v
													v = str(v)
													v = v.strip()
													v = float(v)
													v = v/100.0
													t = t/self.tickrate
													print track, t, v
													self.setFloatKeyframe(track, t, v)
											except ValueError:
												continue
										elif len(v) == 3:
											try:
												v = Piavca.Vec(float(v[0]), float(v[1]), float(v[2]))
												self.addVecTrack(track, v)
												for t, v in keyframes:
													t = t/self.tickrate
													v = Piavca.Vec(float(v[0]), float(v[1]), float(v[2]))
													self.setVecKeyframe(track, t, v)
											except:
												continue
										elif len(v) == 4:
											try:
												v = Piavca.Quat(float(v[0]), float(v[1]), float(v[2]))
												self.addQuatTrack(track, v)
												for t, v in keyframes:
													t = t/self.tickrate
													v = Piavca.Quat(float(v[3]), float(v[0]), float(v[1]), float(v[2]))
													self.setQuattKeyframe(track, t, v)
											except:
												continue
		#Piavca.loadMotion(name, mot)
		
		#impl = minidom.getDOMImplementation()
		#doc = impl.createDocument("", "PiavcaMotions", None)
		#f = open(filename, "w")
		#dom.writexml(f, "", "\t", "\n")
		dom.unlink
		
if __name__ == "__main__":
	import sys
	
	Piavca.Core.getCore().addExpressionNameSet(["Blink"])
	Piavca.Core.getCore().addExpressionNameSet(["mouthE"])
	
	readXAFAnim(sys.argv[1], sys.argv[2])	
	