
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
import types 
import string

#print dir(Piavca)

	
import xml.dom.minidom as minidom

def setAttribute(mot, attrName, attrValue, firstArg = None):
	attrName = str(attrName)
	if not hasattr(mot, "set" + string.upper(attrName[0]) + attrName[1:]):
		print "could not find attribute", attrName
		return 0
	meth = getattr(mot, "set" + string.upper(attrName[0]) + attrName[1:])
	if firstArg == None:
		method = meth
	else:
		method = lambda x : meth(firstArg, x)
	value = str(attrValue).strip()
	# first try treating it as a list of numbers
	# delete trailing commas or semicolons
	valuestripped = value.strip(",;")
	valuelist = valuestripped.split()
	if len(valuelist) <= 1:
		valuelist = valuestripped.split(",")
		if len(valuelist) <= 1:
			valuelist = valuestripped.split(";")
	# maybe its a quaternion
	if len(valuelist) == 4:
		try:
			quat = [float(x) for x in valuelist]
			quat = Piavca.Quat(Piavca.degToRad(quat[0]), Piavca.Vec(quat[1], quat[2], quat[3]))
			method(quat)
			return 1
		# didn't work so try next option
		except ValueError:
			pass
	# maybe its a Vec
	if len(valuelist) == 3:
		try:
			vec = [float(x) for x in valuelist]
			vec = Piavca.Vec(vec[1], vec[2], vec[3])
			method(vec)
			return 1
		# didn't work so try next option
		except ValueError:
			pass
	if len(valuelist) > 1:
		# maybe its a list of numbers
		try:
			vec = [float(x) for x in valuelist]
			method(vec)
			return 1
		# didn't work so try next option
		except ValueError:
			pass
		# maybe its a list of motion names
		try:
			motions = []
			for name in valuelist:
				mot = Piavca.Core.getCore().getMotion(name)
				if mot == None:
					raise ValueError
				motions.append(mot)
			method(motions)
			return 1
		# didn't work so try next option
		except ValueError:
			pass
		# maybe its a list of avatar names
		try:
			avatars = []
			for name in valuelist:
				av = Piavca.Core.getCore().getAvatar(name)
				if av == None:
					raise ValueError
				avatars.append(av)
			method(avatars)
			return 1
		# didn't work so try next option
		except ValueError:
			pass
		# maybe its just a list of strings
		try:
			method(valuelist)
			return 1
		# didn't work so try next option
		except ValueError:
			pass
	
	# OK, if we get here it seems to be just a single value
	# could be a number
	try:
		method(float(value))
		return 1
	except ValueError:
		pass
		
	# or a string
	try:
		method(value)
		return 1
	except ValueError:
		pass
	
	# if we've got here, nothing works!
	raise ValueError("Invalid value"+value+"for attribute"+"attrName")
	return 0
			
	
def readMotions(motions):
	mots = []
	for motion in motions:
		if motion.nodeType == minidom.Node.ELEMENT_NODE:
			if motion.nodeName == "Motion":
				#print "found a motion statement", motion
				for i in range(motion.attributes.length):
					#print motion.attributes.item(i).name, motion.attributes.item(i).nodeValue
					unknownAttrs=[]
					if motion.attributes.item(i).name != "name":
						unknownAttrs.append((motion.attributes.item(i).name, motion.attributes.item(i).nodeValue))
				name = str(motion.getAttribute("name"))
				if name == "":
					print "Motion statement without a name"
				else:
					#print "*"+name+"*"
					mot = Piavca.Core.getCore().getMotion(name)
					#print mot
					if mot == None:
						print "could not find motion", name
					else:
						mots.append((mot, str(motion.nodeName), unknownAttrs))
						#print "mots", mots
			else:
				try:
					cl = getattr(Piavca, motion.nodeName)
					if type(cl) == types.TypeType and issubclass(cl, Piavca.Motion):
						#print "found motion type", motion
						mot = cl()
						if mot == None:
							print "could not find motion", name
							continue
						unknownAttrs=[]
						for i in range(motion.attributes.length):
							if str(motion.attributes.item(i).name) == "name":
								name = str(motion.attributes.item(i).nodeValue)
								Piavca.Core.getCore().loadMotion(name, mot)
							attrName = motion.attributes.item(i).name
							attrValue = motion.attributes.item(i).nodeValue
							#print attrName, attrValue
							if not setAttribute(mot, attrName, attrValue):
								unknownAttrs.append((attrName, attrValue))
						children = readMotions(motion.childNodes)
						added = 0
						if len(children) == 1:
							if hasattr(mot, "setMotion"):
								getattr(mot, "setMotion")(children[0][0])
								for attrName, attrValue in children[0][2]:
									attrName = "Motion" + string.upper(attrName[0]) + attrName[1:]
									if not setAttribute(mot, attrName, attrValue):
										print children[0][1], "unknown attribute", attrName
								added = 1
							elif hasattr(mot, "setMotion1"):
								getattr(mot, "setMotion1")(children[0][0])
								for attrName, attrValue in children[0][2]:
									attrName = "Motion1" + string.upper(attrName[0]) + attrName[1:]
									if not setAttribute(mot, attrName, attrValue):
										print children[0][1], "unknown attribute", attrName
								added = 1
						elif len(children) == 2:
							if hasattr(mot, "setMotion1"):
								getattr(mot, "setMotion1")(children[0][0])
								for attrName, attrValue in children[0][2]:
									attrName = "Motion1" + string.upper(attrName[0]) + attrName[1:]
									if not setAttribute(mot, attrName, attrValue):
										print children[0][1], "unknown attribute", attrName
								if hasattr(mot, "setMotion2"):
									getattr(mot, "setMotion2")(children[1][0])
									for attrName, attrValue in children[1][2]:
										attrName = "Motion2" + string.upper(attrName[0]) + attrName[1:]
										if not setAttribute(mot, attrName, attrValue):
											print children[0][1], "unknown attribute", attrName
									added = 1
						if not added:
							if hasattr(mot, "addMotion"):
								method = getattr(mot, "addMotion")
								for i, child in enumerate(children):
									method(child[0])
									for attrName, attrValue in child[2]:
										attrName = "Motion" + string.upper(attrName[0]) + attrName[1:]
										if not setAttribute(mot, attrName, attrValue, i):
											print child[1], "unknown attribute", attrName
								
						mots.append((mot, str(motion.nodeName), unknownAttrs))
					else:
						print motion.nodeName, "is not a motion", motion
				except AttributeError:
					print "couldn't find motion type", motion
	return mots


def parse(filename):
	dom = minidom.parse(filename) 
	for topLevel in dom.childNodes:
		readMotions(topLevel.childNodes)
	dom.unlink