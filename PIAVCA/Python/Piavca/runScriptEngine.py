
print "running script engine"

import sys
import os
import time

import Piavca
from Piavca import ScriptEngine

import thread, time


class PauseCallback(Piavca.TimeCallback):
	def __init__(self, name):
		Piavca.TimeCallback.__init__(self, name)
		pass
	def init(self, core):
		print "starting callback"
	def timeStep(self, core, t):
		time.sleep(0.02)

def run(path=None):
	if path == None:
		try:
			import wx
			from wx.lib.dialogs import *
			
			app = wx.PySimpleApp()
			dialog_return = openFileDialog ()
			path = dialog_return.paths[0]
		except ImportError:
			print "please enter name of .conf file to use"
			path = sys.stdin.readline()

	print path
	pathend = path.rfind("\\")
	print pathend
	if pathend < 0:
		pathend = path.rfind("/")
	print pathend
	if pathend < 0:
		print "no path"
		filename = path
	else:
		print "path"
		filename = path[pathend+1:]
		path = path[:pathend+1]
		os.chdir(path)
	print filename, path
	if filename[-4:] == ".cfg":
		filename = filename[:-4]
	print filename

	script_engine = ScriptEngine("character controller", filename)	
	#script_engine.GUI("nancy")


	# a call back object for piavca that updates the interface
	 
	#cb = PauseCallback("pause")
	#cb.thisown = 0
	#Piavca.Core.getCore().registerCallback(cb)
