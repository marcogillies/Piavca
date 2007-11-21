import sys

try:
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
		
except:
	etype, eval = sys.exc_info()[:2]
	file = open("PiavcaError.txt", "w")
	file.write("Error loading initXVRPiavca.py\n")
	file.write(str(etype) + " " + str(eval))
	file.close()
	raise 
	