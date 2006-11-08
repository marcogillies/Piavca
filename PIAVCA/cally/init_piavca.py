# File: hello1.py

print "hello world"

import sys

sys.path.append("../src/PiavcaPythonInterface/")
sys.path.append("../Python/")

print sys.path

import Piavca

#sys.path.append("../../ExponentialMap/")
#import ExpMapTest

# hack to make TK work, it expects the name of the app to be
# in sys.argv[0] but argv is not set up if python is run from
# within a windows app as it is here
sys.argv = ['Piavca']

#from Tkinter import *



cally = Piavca.Avatar("cally")
cally.setRootPosition(Piavca.Vec(0.0, 250.0, -200))
cally.setRootOrientation(Piavca.Quat(Piavca.degToRad(-90), Piavca.Vec(0, 0, 1)))
#sally = Piavca.Avatar("sally")
#sally.setRootPosition(Piavca.Vec(40.0, 0, 0))
#sally.setRootOrientation(Piavca.Quat(Piavca.degToRad(-45), Piavca.Vec(0, 0, 1)))
#avatar.setFacialExpressionWeight("smile", 1.0)

#mot = Piavca.Core.getCore().loadMotion("walk", "walk_cycle.bvh")

#mot = Piavca.Core.getCore().loadMotion("testmot", "output.paf")
#avatar.play_motion(mot)

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
#saver = Piavca.MotionSaver(mot4)


import MotionFile

MotionFile.readMotionFile("motions.conf")

#cally.play_motion(Piavca.LoopMotion(Piavca.Core.getCore().getMotion("nod")))
#cally.play_motion(Piavca.Core.getCore().getMotion("gethit"))

#def PlayMotion ():
cally.play_motion(Piavca.Core.getCore().getMotion("gestures"))

#sally.play_motion(random_gesture)
#avatar.play_motion(saver)

print "finished adding motion"

#avatar.play_motion(Piavca.Core.getCore().getMotion("Cally_rest"))

#avatar.playMotionDirect(mot)

#import idlelib.PyShell

#idlelib.PyShell.main()

#from Tkinter import *

#avatar.registerCallback(Piavca.PyAvatarTimeCallback(testCallback, "test"))

#root = Tk()

#w = Label(root, text="Hello, world!")
#w.pack()

#def save():
#	print "saving"
#	saver.save("output.paf")

#b = Button(root, text="save", command=save)
#b.pack()

#class testCallback:
#	def __init__(self, Widget):
#		self.Widget = Widget
#	def callbackInit(self, core):
#		self.Widget.update()
#		print "starting callback"
#	def callbackMethod(self, core, time):
#		#print "in callback"
#		self.Widget.update()

	
#cb = Piavca.PyTimeCallback(testCallback(root), "test")
#cb.thisown = 0
#Piavca.Core.getCore().registerCallback(cb)

#root.mainloop()