
import Piavca
import Piavca.redirect
Piavca.redirect.redirect()

#Piavca.PiavcaGlut.initCore()

def timeStep():
	#print "rendering"
	#Piavca.PiavcaGlut.timeStep()
	Piavca.Core.getCore.timeStep()
	
def render():
	#print "rendering"
	#Piavca.PiavcaGlut.render()
	Piavca.render()
	
def getCorePointer():
	return Piavca.Core.getCorePointerAsLong()