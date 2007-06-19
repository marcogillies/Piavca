
import sys
import os
import time


import Piavca
Piavca.PiavcaGlut.init()
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
	path = dialog_return.paths[0]

print path
pathend = path.rfind("\\")
if pathend < -1:
	pathend = path.rfind("/")
if pathend < -1:
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

avatar = Piavca.Avatar(filename)

if len(sys.argv) > 2:
	motion_name = sys.argv[2]
else:
	motnames = Piavca.Core.getCore().getMotionNames()
	print motnames
	dialog_return = singleChoiceDialog (lst=motnames)
	motion_name = dialog_return.selection

#motion_name = "biped_mocap_final"
mot = Piavca.Core.getCore().getMotion(motion_name)
mot.Reference()


frame=Piavca.AnimationInterface(None,-1,'Motion editor', avatar, mot, motion_name)
frame.Show()

thread.start_new_thread(app.MainLoop, ())
		
		
Piavca.PiavcaGlut.start()
	
