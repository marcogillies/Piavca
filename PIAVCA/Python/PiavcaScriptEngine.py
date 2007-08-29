#!/usr/bin/python2.4

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
	
Piavca.PiavcaGlut.start()
