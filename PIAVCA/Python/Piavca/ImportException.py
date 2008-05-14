
class PiavcaImportException(Exception):
	def __init__(self, value=""):
		self.value = value
	def __str__(self):
		return "harmless import error " + str(self.value)