# File: hello1.py


#sys.path.append("..\..\Piavca\src\PiavcaPythonInterface")
#sys.path.append("..\..\Piavca\Python")
#sys.path.append("..\..\")
#sys.path.append("..\..\ExponentialMap\ExpMap")

import Piavca
Piavca.PiavcaGlut.init()
from Piavca import runScriptEngine

if len(sys.argv) > 1:
	path = sys.argv[1]
else:
	path = None
runScriptEngine.run(path)
	
Piavca.PiavcaGlut.start()
