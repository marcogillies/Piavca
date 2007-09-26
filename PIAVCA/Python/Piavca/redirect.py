
import sys
try:
	import wx
	wxpresent = 1
	app = wx.PySimpleApp()
except ImportError:
	wxpresent = 0
import thread, time


class outputRedirection:
	def __init__(self, filename=None):
		self.frame = None
		if wxpresent:
			self.frame = wx.Frame(None)
			bs = wx.BoxSizer(wx.VERTICAL)
			self.txt = wx.TextCtrl(self.frame, style=wx.TE_MULTILINE)
			bs.Add(self.txt,1,wx.EXPAND|wx.LEFT|wx.RIGHT,30)
			self.txt.SetValue("yaya\n")
			self.txt.SetValue(filename+"\n")
		self.filename = filename
		if filename != None:
			try:
				outputfile = open(filename, "w")
				outputfile.write("")
				outputfile.close()
			except:
				self.txt.SetValue("could not open output file "+filename+"\n")
		if not wxpresent:
			self.write("WX Python was not found so graphical output is not available")
		self.outputFunc = None
	def Show(self):
		if wxpresent:
			self.frame.Show(True)
			self.frame.Layout()
	def setOutputFunc(self, func):
		self.outputFunc = func
		if not wxpresent:
			self.write("WX Python was not found so graphical output is not available")
	def write(self, s):
		if wxpresent:
			self.txt.AppendText(s)
		if self.filename != None:
			try:
				outputfile = open(self.filename, "a")
				outputfile.write(s)
				outputfile.close()
			except:
				pass
		if self.outputFunc != None:
			self.outputFunc(s)
		#if self.outputfile:
			#self.outputfile.write(s)
	def writeline(self, s):
		self.write(s)
		self.write("\n")
		
def redirect(filename="python_output.txt"):
	outputer = outputRedirection(filename)
	outputer.Show()

	outputer.write("Piavca\n")

	import Piavca
		
	#outputer.setOutputFunc(Piavca.PiavcaGlut.outputMessage)

	outputer.write("output redirection\n")

	sys.stderr = outputer
	sys.stdout = outputer

	#print "hello"

	print "output redirection successful"
	
	if wxpresent:
		thread.start_new_thread(app.MainLoop, ())