# File: hello1.py

import sys

import Piavca
Piavca.PiavcaGlut.init()
from Piavca import runScriptEngine

if len(sys.argv) > 1:
	path = sys.argv[1]
else:
	path = None
runScriptEngine.run(path)
	
Piavca.PiavcaGlut.start()
