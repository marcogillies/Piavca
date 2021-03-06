#! /usr/bin/env python

import sys
import os
import time

import Piavca
#Piavca.PiavcaGlut.init(Piavca.Core.getCorePointerAsLong())
import Piavca.JointNames
Piavca.JointNames.loadDefaults()

import Piavca.FreeCameraCanvas


import wx
from wx.lib.dialogs import *
from wx import glcanvas

app = Piavca.getWXApp()
canvas = app.showWindows(canvastype = Piavca.FreeCameraCanvas.FreeCameraCanvas)
canvas.setPosition(Piavca.Vec(0.0, 100, 33))
canvas.setPitch(Piavca.degToRad(-90.0))

app.getCanvas().setClearColour(1.0, 1.0, 1.0)

if len(sys.argv) > 1:
	path = sys.argv[1]
else:
	dialog_return = openFileDialog ()
	path = dialog_return.paths[0]

dirname = os.path.dirname(path)
os.chdir(dirname)

try:
	Piavca.JointNames.importJointNames("Joints.txt")
except IOError:
	print "could not open Joints file Joints.txt, will probably work anyway"
try:
	Piavca.JointNames.importExpressionNames("Expressions.txt")
except IOError:
	print "could not open Expressions file Expressions.txt, will probably work anyway"


(splitext, ext) = os.path.splitext(path)
print "filename", splitext, "extention", ext
if ext == ".conf":
	script_engine = ScriptEngine("character controller", filename, app)
else:
	if ext == ".cfg":
		basename = os.path.basename(splitext)
		avatar = Piavca.Avatar(str(basename))
	else:
		import Piavca.XMLMotionFile
		basename = os.path.basename(path)
		Piavca.XMLMotionFile.parse(basename)
		avatar = Piavca.Core.getCore().getAvatar(0)
		Piavca.setUpEventsGUI()

	print "loaded avatar"

	if len(sys.argv) > 2:
		motion_name = sys.argv[2]
	else:
		motnames = Piavca.Core.getCore().getMotionNames()
		print motnames
		dialog_return = singleChoiceDialog (lst=["None"]+motnames)
		motion_name = dialog_return.selection

	mot = Piavca.Core.getCore().getMotion(str(motion_name))
	if mot != None:
		mot.Reference()
		avatar.play_motion(Piavca.LoopMotion(mot))	
	avatar.play_motion(mot)	

	avatar.showMotionAtTime(Piavca.getTime())
		
	print "loaded motion"


#if len(sys.argv) > 1:
#	path = sys.argv[1]
#else:
#	dialog_return = openFileDialog ()
#	path = dialog_return.paths[0]

#dirname = os.path.dirname(path)
#os.chdir(dirname)
#(splitext, ext) = os.path.splitext(path)
#basename = os.path.basename(splitext)

#try:
#	Piavca.JointNames.importJointNames("Joints.txt")
#except IOError:
#	print "could not open Joints file Joints.txt, will probably work anyway"
#try:
#	Piavca.JointNames.importExpressionNames("Expressions.txt")
#except IOError:
#	print "could not open Expressions file Expressions.txt, will probably work anyway"


#app = MyApp()


#avatar = Piavca.Avatar(str(basename))

#print "loaded avatar"

#if len(sys.argv) > 2:
#	motion_name = sys.argv[2]
#else:
#	motnames = Piavca.Core.getCore().getMotionNames()
#	print motnames
#	dialog_return = singleChoiceDialog (lst=["None"]+motnames)
#	motion_name = dialog_return.selection

#mot = Piavca.Core.getCore().getMotion(str(motion_name))
#if mot != None:
#	mot.Reference()
#	avatar.play_motion(Piavca.LoopMotion(mot))	

print "loaded motion"


#import Piavca.redirect
#Piavca.redirect.redirect()

print "created app"

app.MainLoop()

