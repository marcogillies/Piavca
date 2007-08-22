#!/usr/bin/python2.4

import sys
import os
import time

#print sys.path

import Piavca
Piavca.PiavcaGlut.init(Piavca.Core.getCorePointerAsLong())
import Piavca.JointNames
Piavca.JointNames.loadDefaults()
import wx
from wx.lib.dialogs import *

import thread

app = wx.PySimpleApp()
	
if len(sys.argv) > 1:
	path = sys.argv[1]
else:
	dialog_return = openFileDialog ()
	path = dialog_return.paths[0].encode("latin-1")

print path
pathend = path.rfind("\\")
if pathend < 0:
	pathend = path.rfind("/")
print pathend, path[0]
if pathend < 0:
	filename = path
else:
	filename = path[pathend+1:]
	path = path[:pathend+1]
	if path != "":
		os.chdir(path)
print filename, "**", path
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

avatar = Piavca.Avatar(str(filename))

if len(sys.argv) > 2:
	motion_name = sys.argv[2]
else:
	motnames = Piavca.Core.getCore().getMotionNames()
	print motnames
	dialog_return = singleChoiceDialog (lst=["None"]+motnames)
	motion_name = dialog_return.selection.encode("latin-1")

#motion_name = "biped_mocap_final"
mot = Piavca.Core.getCore().getMotion(str(motion_name))
if mot != None:
	mot.Reference()
	avatar.play_motion(Piavca.LoopMotion(mot))	
		
Piavca.PiavcaGlut.start()
	
