# make sure we can find the piavca modules
import sys

sys.path.append("../src/PiavcaPythonInterface/")
sys.path.append("../Python/")
print sys.path

# load piavca (This loads a python wrapper module which in turn loads the C++ code)
import Piavca
from ScriptEngine import ScriptEngine

s = ScriptEngine("master.conf")

# hack to make TK work, it expects the name of the app to be
# in sys.argv[0] but argv is not set up if python is run from
# within a windows app as it is here
sys.argv = ['Piavca']

# but we're not actually using tk in this example
#from Tkinter import *

# create an avatar, this loads cally.cfg
#cally = Piavca.Avatar("cally")
# position and rotate the avatar
#cally.setRootPosition(Piavca.Vec(0.0, 250.0, -200))
#cally.setRootOrientation(Piavca.Quat(Piavca.degToRad(-90), Piavca.Vec(0, 0, 1)))
# we could also change her facial expression
#avatar.setFacialExpressionWeight("smile", 1.0)

# we could load a motion from bvh or piavca's own .paf file but we don't
#mot = Piavca.Core.getCore().loadMotion("walk", "walk_cycle.bvh")
#mot = Piavca.Core.getCore().loadMotion("testmot", "output.paf")
#avatar.play_motion(mot)

# we could build up motion out of piavca's various motion operators
# the base gesture[1-4] motions are cal3d animations loaded as part of cally.cfg
#random_gesture = Piavca.RandomBlendLoop(-1, 2.0)
#random_gesture.addMotion(Piavca.ScaleMotionSpeed(Piavca.Core.getCore().getMotion("gesture1"), 2.0))
#random_gesture.addMotion(Piavca.ScaleMotionSpeed(Piavca.Core.getCore().getMotion("gesture2"), 2.0))
#random_gesture.addMotion(Piavca.ScaleMotionSpeed(Piavca.Core.getCore().getMotion("gesture3"), 2.0))
#random_gesture.addMotion(Piavca.ScaleMotionSpeed(Piavca.Core.getCore().getMotion("gesture4"), 2.0))
#random_gesture.addMotion(Piavca.ScaleMotionSpeed(Piavca.Core.getCore().getMotion("gestureL1"), 2.0))
#random_gesture.addMotion(Piavca.ScaleMotionSpeed(Piavca.Core.getCore().getMotion("gestureL2"), 2.0))
#random_gesture.addMotion(Piavca.ScaleMotionSpeed(Piavca.Core.getCore().getMotion("gestureL3"), 2.0))
#random_gesture.addMotion(Piavca.ScaleMotionSpeed(Piavca.Core.getCore().getMotion("gestureL4"), 2.0))
#random_gesture.addMotion(Piavca.ScaleMotionSpeed(Piavca.Core.getCore().getMotion("gestureR1"), 2.0))
#random_gesture.addMotion(Piavca.ScaleMotionSpeed(Piavca.Core.getCore().getMotion("gestureR2"), 2.0))
#random_gesture.addMotion(Piavca.ScaleMotionSpeed(Piavca.Core.getCore().getMotion("gestureR3"), 2.0))
#random_gesture.addMotion(Piavca.ScaleMotionSpeed(Piavca.Core.getCore().getMotion("gestureR4"), 2.0))

#mot = Piavca.Core.getCore().getMotion("nod")
#mot2 = Piavca.ScaleMotionRoot(mot, 0.0025)
#mot3 = Piavca.ScaleMotionSpeed(mot2, 2.0)
#mot4 = Piavca.LoopMotion(mot3)

#avatar.play_motion(Piavca.AddMotion(randomgesture, mot4)

#what we actually do is load the MotionFile module  (an auxilliary module written in Python)
# This loads in motion descriptions form a standard Piavca file format
#import MotionFile
# load in the motion descriptions from file
#MotionFile.readMotionFile("motions.conf")

# play one of the motions defined in the file
#cally.play_motion(Piavca.Core.getCore().getMotion("gestures"))
