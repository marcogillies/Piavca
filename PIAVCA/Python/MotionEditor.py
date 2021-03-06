#! /usr/bin/env python

import sys
import os
import time


import Piavca
#Piavca.PiavcaGlut.init()
#Piavca.PiavcaGlut.init(Piavca.Core.getCorePointerAsLong())
import Piavca.JointNames
Piavca.JointNames.loadDefaults()
import wx
from wx.lib.dialogs import *

import thread

app = Piavca.getWXApp()
#app = wx.PySimpleApp()

import Piavca.FreeCameraCanvas
canvas = app.showWindows(canvastype = Piavca.FreeCameraCanvas.FreeCameraCanvas)	
app.getCanvas().setClearColour(1, 1, 1)
	
if len(sys.argv) > 1:
	path = sys.argv[1]
else:
	dialog_return = openFileDialog (wildcard="*.cfg")
	path = dialog_return.paths[0].encode("latin-1")

print path
pathend = path.rfind("\\")
if pathend < 0:
	pathend = path.rfind("/")
if pathend < 0:
	filename = path
else:
	filename = path[pathend+1:]
	path = path[:pathend+1]
	if path != "":
		os.chdir(path)
print filename, path
if filename[-4:] == ".cfg":
	filename = filename[:-4]
print filename
	
try:
	Piavca.JointNames.importJointNames("Joints.txt")
except IOError:
	print "could not open Joints file Joints.txt, will probably work anyway"
try:
	Piavca.JointNames.importExpressionNames("Expressions.txt")
except IOError:
	print "could not open Expressions file Expressions.txt, will probably work anyway"

Piavca.Core.getCore().setHardware(False)
	
print "creating avatar"

avatar = Piavca.Avatar(filename)

print "loaded avatar"

if len(sys.argv) > 2:
	motion_name = sys.argv[2]
else:
	motnames = Piavca.Core.getCore().getMotionNames()
	print motnames
	dialog_return = singleChoiceDialog (lst=motnames)
	motion_name = dialog_return.selection.encode("latin-1")

#motion_name = "biped_mocap_final"
mot = Piavca.Core.getCore().getMotion(motion_name)
mot.Reference()


frame=Piavca.AnimationInterface(None,-1,'Motion editor', avatar, mot, motion_name)
frame.Show()

class PauseCallback(Piavca.TimeCallback):
	def __init__(self):
		Piavca.TimeCallback.__init__(self, "pause")	
	def init(self, core):
		pass
	def timeStep(self, core, t):
		time.sleep(0.1)
		
cb = PauseCallback()
cb.thisown = 0
Piavca.Core.getCore().registerCallback(cb)


app.MainLoop()
#thread.start_new_thread(app.MainLoop, ())
		
		
#Piavca.PiavcaGlut.start()
	
