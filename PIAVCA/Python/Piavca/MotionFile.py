# ***** BEGIN LICENSE BLOCK *****
# Version: MPL 1.1/GPL 2.0/LGPL 2.1
#
# The contents of this file are subject to the Mozilla Public License Version
# 1.1 (the "License"); you may not use this file except in compliance with
# the License. You may obtain a copy of the License at
# http://www.mozilla.org/MPL/
#
# Software distributed under the License is distributed on an "AS IS" basis,
# WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
# for the specific language governing rights and limitations under the
# License.
#
# The Original Code is __________________________________________.
#
# The Initial Developer of the Original Code is
# ____________________________________________.
# Portions created by the Initial Developer are Copyright (C) 2___
# the Initial Developer. All Rights Reserved.
#
# Contributor(s):
#
# Alternatively, the contents of this file may be used under the terms of
# either the GNU General Public License Version 2 or later (the "GPL"), or
# the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
# in which case the provisions of the GPL or the LGPL are applicable instead
# of those above. If you wish to allow use of your version of this file only
# under the terms of either the GPL or the LGPL, and not to allow others to
# use your version of this file under the terms of the MPL, indicate your
# decision by deleting the provisions above and replace them with the notice
# and other provisions required by the GPL or the LGPL. If you do not delete
# the provisions above, a recipient may use your version of this file under
# the terms of any one of the MPL, the GPL or the LGPL.
#
# ***** END LICENSE BLOCK *****

import Piavca
import os
import XMLMotionFile

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
flaglookup["-cycle_zxy"] = Piavca.TRANS_CYCLE_ZXY
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
	filename = filename[filestart:]
	dotpos = filename.rfind(".")
	if filename[dotpos+1] == "x":
		XMLMotionFile.parse(filename)
		return
	in_file = open(filename,"r")
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
