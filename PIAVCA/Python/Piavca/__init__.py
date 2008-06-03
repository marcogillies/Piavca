
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
# The Original Code is __init__.py
#
# The Initial Developer of the Original Code is
# Marco Gillies.
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


from Piavca_base import * 
#import PiavcaGlut

from ImportException import PiavcaImportException

from FootPlantOnSpot import FootPlantOnSpot
from FSM import FSM
from ParameterMotion import ParameterMotion
from PositionHandler import PositionResponse, PositionShiftResponse	
from AudioMotion import AudioMotion
try:
	from EigenMotion import *
	from MotionGraph import *
	from ClusterMotionGraph import *
except PiavcaImportException:
	print "scipy not available, please install scipy to use EigenMotion and Motion Graph"

from MotionFile import readMotionFile
from ScriptEngine import ScriptEngine 
from ConversationInterface import ConversationInterface
try :
	from SpeechToText import SpeechToText
except PiavcaImportException:
	SpeechToText = None 
try:
	from AnimationTrack import AnimationInterface, AnimationInterfaceCallback
	from PiavcaWXApp import getWXApp, setWXApp
except PiavcaImportException:
	print "wxPython unavailable, please install wxPython for GUI functions"

try:
	from EventsGUI import setUpEventsGUI
except PiavcaImportException:
	print "wxPython unavailable, please install wxPython for GUI functions"

	
Core.init()

from CoreProxy import getTime, loadMotion, getMotion, getRealMotionType, clear
from CoreProxy import addEvents, addEvent, getEvents, removeEvent

def render ():
	core = Core.getCore()
	core.timeStep()
	core.prerender()
	core.render()
