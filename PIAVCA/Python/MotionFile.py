import Piavca
import os

Piavca.MotionParser.setUpMotionCommands()

flaglookup = {}

flaglookup["none"] = Piavca.TRANS_NONE
flaglookup["-swap_xz"] = Piavca.TRANS_SWAP_XZ
flaglookup["-swap_zx"] = Piavca.TRANS_SWAP_XZ
flaglookup["-swap_xy"] = Piavca.TRANS_SWAP_XY
flaglookup["-swap_yx"] = Piavca.TRANS_SWAP_XY
flaglookup["-swap_yz"] = Piavca.TRANS_SWAP_YZ
flaglookup["-swap_zy"] = Piavca.TRANS_SWAP_YZ
flaglookup["-cycle_yzx"] = Piavca.TRANS_CYCLE_YZX
flaglookup["-cycyle_zxy"] = Piavca.TRANS_CYCLE_ZXY
flaglookup["-negate_x"] = Piavca.TRANS_NEG_X
flaglookup["-negate_y"] = Piavca.TRANS_NEG_Y
flaglookup["-negate_z"] = Piavca.TRANS_NEG_Z
flaglookup["-arm_up"] = Piavca.TRANS_ARM_UP
flaglookup["-arm_down"] = Piavca.TRANS_ARM_DOWN
flaglookup["-reverse_order"] = Piavca.TRANS_REVERSE_ORDER
flaglookup["-skip_first_frame"] = Piavca.TRANS_SKIP_FIRST_FRAME

def getMotionFlags(flagspecs):
	flags = 0
	for spec in flagspecs:
		flags |= flaglookup[spec]
	return flags

def readMotionFile (filename):
	filestart = 0
	pathpos = filename.rfind("/")
	if pathpos < 0 :
		pathpos = filename.rfind("\\")
	prev_dir = os.getcwd()
	if pathpos >= 0 :
		os.chdir(filename[0:pathpos])
		filestart = pathpos+1
	#print os.getcwd()
	in_file = open(filename[filestart:],"r")
	for line in in_file.readlines():
		print line
		if line[0] == '#' :
			continue
		items = line.split()
		if len(items) == 0: 
			continue
		if(items[1] == "file"):
			Piavca.Core.getCore().loadMotion(items[0], items[2], getMotionFlags(items[3:]))
		else:
			mot = Piavca.MotionParser.parseMotion(' '.join(items[1:]), 1.0)
			Piavca.Core.getCore().loadMotion(items[0], mot)
	os.chdir(prev_dir)
