from Piavca_base import * 
import PiavcaGlut
from MotionFile import readMotionFile
from ScriptEngine import ScriptEngine 
from FootPlantOnSpot import FootPlantOnSpot
try:
	from EigenMotion import *
	from MotionGraph import *
except ImportError:
	print "scipy not available, please install scipy to use EigenMotion and Motion Graph"
from ConversationInterface import ConversationInterface
try :
	from SpeechToText import SpeechToText
except ImportError:
	SpeechToText = None 
try:
	from AnimationTrack import AnimationInterface, AnimationInterfaceCallback
except ImportError:
	print "wxPython unavailable, please install wxPython for GUI functions"
	
Core.init()

def render ():
	core = Piavca.Core.getCore()
	core.timeStep()
	core.prerender()
	core.render()
