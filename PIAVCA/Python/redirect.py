
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
		self.txt.SetValue("yaya")
		if filename != None:
			self.outputfile = open(filename, "w")
		else:
			self.outputfile = None
	def write(self, s):
		if self.outputfile:
			self.outputfile.write(s)
		self.txt.AppendText(s)
	def writeline(self, s):
		self.write(s)
		self.write("\n")
		

outputer = outputRedirection()
outputer.Show(True)
outputer.Layout()

sys.stderr = outputer
sys.stdout = outputer

thread.start_new_thread(app.MainLoop, ())
