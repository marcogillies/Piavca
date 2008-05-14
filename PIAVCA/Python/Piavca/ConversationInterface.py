try:
	import aiml
	aimlAvailable = True
except ImportError:
	aimlAvailable = False

from ImportException import PiavcaImportException	
try:
	import SpeechToText
	speechToTextAvailable = True
except PiavcaImportException:
	speechToTextAvailable = False
	

wxAvailable = 1
try:
	import wx
	import thread
except ImportError:
	wxAvailable = 0
	
class ConversatioInterfaceUnsupportedError(Exception):
	pass
	
class ConversationInterface:
	def __init__(self, script_interface, character, grammar, initializer=None):
		if not aimlAvailable:
			print "** AIML is not installed, so the Conversation Interface cannot be used"
			print "** Please install AIML Program Y (PyAIML)"
			raise ConversatioInterfaceUnsupportedError, "AIML not available"
		self.scriptEngine = script_interface
		self.kernel = aiml.Kernel()
		self.kernel.learn(grammar)
		self.character = character
		if initializer != None :
			self.kernel.respond(initializer)
			
	def respond(self, text):
		print text
		response = self.kernel.respond(text)
		print response
		self.scriptEngine.utterance(self.character, response)
			
	def respondToText(self, e):
		# if the enter key has just been pressed, respond
		if self.textctrl.GetValue()[-1] == "\n":
			# get the last line of text (get item -2, because -1 is always the empty string)
			lines = self.textctrl.GetValue().split("\n")
			if len(lines) <= self.currentline :
				return
			self.currentline = len(lines)
			text = lines[-2]
			self.respond(text)
			
	def GUI(self):
		if not wxAvailable:
			print "** wxPyuthon is not installed, so the Conversation Interface GUI cannot be used"
			print "** Please install wxPython user interface library"
			raise ConversatioInterfaceUnsupportedError, "wx not available"
		app = wx.PySimpleApp()

		ID_TXT = 1
		frame=wx.Frame(None,-1)
		#sizer=wx.BoxSizer(wx.HORIZONTAL)
		self.textctrl = wx.TextCtrl(frame,ID_TXT,style=wx.TE_MULTILINE)
		wx.EVT_TEXT (self.textctrl, ID_TXT, self.respondToText)
		
		frame.Show(True)
		frame.Layout()

		self.currentline = 0
		thread.start_new_thread(app.MainLoop, ())
		
	def respondToSpeech(self):
		while (1):
			print "waiting for text"
			text = self.speechInterface.getText()
			print "got text from speech input:", text
			self.respond(text)
		
	def SpeechInterface(self):
		if not speechToTextAvailable:
			print "** The Speech Interface is not installed"
			print "** Please install microsoft Speech API and compile the speech interface"
			raise ConversatioInterfaceUnsupportedError, "Speech To Text not available"
		self.speechInterface = SpeechToText.SpeechToText()
		
		thread.start_new_thread(self.respondToSpeech, ())

