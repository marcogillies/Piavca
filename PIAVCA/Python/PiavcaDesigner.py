#! /usr/bin/env python

print "PiavcaDesigner"

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
	
Piavca.Core.getCore().setHardware(False)
	
pd = PiavcaDesigner()
	
app.MainLoop()