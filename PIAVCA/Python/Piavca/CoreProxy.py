
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
# The Original Code is CoreProxy.py
#
# The Initial Developer of the Original Code is
# Marco Gillies
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

#import Piavca
import Piavca_base
from Piavca_base import Core, Motion

import types

def getTime():
	return Core.getCore().getTime()

_motionLookup = {}

def loadMotion(name, motion):
	global _motionLookup
	if type(motion) != type(""):
		_motionLookup[name] = motion
	#print "proxy core", Core.getCore()
	Core.getCore().loadMotion(name, motion)
	
def getRealMotionType(motion):
	if motion != None and type(motion) == Motion:
		typeName = motion.getClassName()
		print "typename", typeName
		motionType = getattr(Piavca_base, typeName)
		print motionType
		if type(motionType) == types.TypeType and issubclass(motionType, Motion):
				return motionType.castToThisType(motion)
	return motion
	
def getMotion(name):
	global _motionLookup
	print "getMotion"
	print _motionLookup.keys()
	print name
	if _motionLookup.has_key(name):
		print "core proxy: found motion,", name
		return _motionLookup[name]
	else:
		motion = Core.getCore().getMotion(name)
		if motion != None:
			motion.Reference()
			motion.thisown = False
		return getRealMotionType(motion)
	
_events = {}

def addEvents(avatar, events):
	global _events
	if not _events.has_key(avatar.getName()):
		_events[avatar.getName()] = []
	_events[avatar.getName()] = _events[avatar.getName()] + events
	
def addEvent(avatar, event):
	global _events
	if not _events.has_key(avatar.getName()):
		_events[avatar.getName()] = []
	_events[avatar.getName()].append(event)
	
def getEvents(avatar):
	global _events
	if _events.has_key(avatar.getName()):
		return list(_events[avatar.getName()])
	else:
		return []

def removeEvent(avatareventname):
	global _events
	try:
		if _events.has_key(avatar.getName()):
			_events[avatar.getName()].remove(eventname)
	except ValueError:
		print "no such event", eventname
		
def clear():
	_motionLookup = {}
	_events = {}
	Core.getCore().reset()
	
def joints(o):
	j = o.begin()
	while (True):
		if j == o.end():
			break
		yield j
		j = o.next(j)
		
def getValAtTime(mot, joint, t, joint_type):
	if joint_type == Piavca_base.FLOAT_TYPE: 
		return mot.getFloatValueAtTime(joint, t)
	if joint_type == Piavca_base.VEC_TYPE: 
		return mot.getVecValueAtTime(joint, t)
	if joint_type == Piavca_base.QUAT_TYPE: 
		return mot.getQuatValueAtTime(joint, t)
	
		