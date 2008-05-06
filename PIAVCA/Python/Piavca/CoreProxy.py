
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
	print "getMotion"
	print _motionLookup.keys()
	print name
	if _motionLookup.has_key(name):
		print "core proxy: found motion,", name
		return _motionLookup[name]
	else:
		motion = Core.getCore().getMotion(name)
		motion.Reference()
		motion.thisown = False
		return getRealMotionType(motion)
		