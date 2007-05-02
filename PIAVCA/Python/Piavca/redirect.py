
import sys
import wx
import thread, time

app = wx.PySimpleApp()

class outputRedirection(wx.Frame):
	def __init__(self, filename=None):
		wx.Frame.__init__(self, None)
		bs = wx.BoxSizer(wx.VERTICAL)
		self.txt = wx.TextCtrl(self, style=wx.TE_MULTILINE)
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
	def write(self, s):
		if self.filename != None:
			try:
				outputfile = open(self.filename, "a")
				outputfile.write(s)
				outputfile.close()
			except:
				pass
		#if self.outputfile:
			#self.outputfile.write(s)
		self.txt.AppendText(s)
	def writeline(self, s):
		self.write(s)
		self.write("\n")
		

outputer = outputRedirection("python_output.txt")
outputer.Show(True)
outputer.Layout()

sys.stderr = outputer
sys.stdout = outputer

thread.start_new_thread(app.MainLoop, ())
