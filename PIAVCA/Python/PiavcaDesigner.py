#! /usr/bin/env python

print "PiavcaDesigner"

import sys

import Piavca
import Piavca.JointNames
Piavca.JointNames.loadDefaults()


from Piavca.PiavcaDesigner import PiavcaDesigner

app = Piavca.getWXApp()


	
try:
	Piavca.JointNames.importJointNames("Joints.txt")
except IOError:
	print "could not open Joints file Joints.txt, will probably work anyway"
try:
	Piavca.JointNames.importExpressionNames("Expressions.txt")
except IOError:
	print "could not open Expressions file Expressions.txt, will probably work anyway"
	
#Piavca.Core.getCore().setHardware(False)
	
extra_panel = None
if len(sys.argv) > 1:
	sys.path.append(".")
	print sys.argv[1]
	module = __import__(sys.argv[1])
	print module
	print module.__file__
	extra_panel = [getattr(module, "create_panel")]

#print 'file', Piavca.PiavcaDesigner.__file__	
	
pd = PiavcaDesigner(extra_panels=extra_panel)
	
app.MainLoop()