
import Piavca

from InterruptableSequence import InterruptableSequence
from ExpMapBlend import ExpMapBlend
try:
	from PCAMot import PCAMot
except Piavca.PiavcaImportException:
	print "scipy not available, please install scipy if you want to use PCAMot"