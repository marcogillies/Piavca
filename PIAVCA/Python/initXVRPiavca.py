
import Piavca
import Piavca.redirect
Piavca.redirect.redirect()

Piavca.PiavcaGlut.initCore()

def timeStep():
	#print "rendering"
	Piavca.PiavcaGlut.timeStep()
	
def render():
	#print "rendering"
	Piavca.PiavcaGlut.render()
	
def getCorePointer():
	return Piavca.Core.getCorePointerAsLong()