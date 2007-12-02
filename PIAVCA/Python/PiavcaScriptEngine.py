#!/usr/local/bin/python

import sys

import Piavca
#Piavca.PiavcaGlut.init()
Piavca.PiavcaGlut.init(Piavca.Core.getCorePointerAsLong())
from Piavca import runScriptEngine

if len(sys.argv) > 1:
	path = sys.argv[1]
else:
	path = None
script_engine = runScriptEngine.run(path)
	
print "about to start glut"
Piavca.PiavcaGlut.start()
