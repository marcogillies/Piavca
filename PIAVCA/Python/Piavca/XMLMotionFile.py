
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
# The Original Code is XMLMotionFile.py
#
# The Initial Developer of the Original Code is
# Marco (Mark) Gillies
# Portions created by the Initial Developer are Copyright (C) 2007
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

def stringToValueList(s):
	value = str(s).strip()
	value = str(value).strip("[]()")
	# first try treating it as a list of numbers
	# delete trailing commas or semicolons
	valuestripped = value.strip(",;")
	valuelist = valuestripped.split(",")
	if len(valuelist) <= 1:
		valuelist = valuestripped.split(";")
		if len(valuelist) <= 1:
			valuelist = valuestripped.split()
	valuelist = [v.strip().strip("[]()") for v in valuelist]
	return valuelist
	
def ValueListToVec(valuelist):
	vec = [float(x) for x in valuelist]
	vec = Piavca.Vec(vec[0], vec[1], vec[2])
	return vec
	
def ValueListToQuat(valuelist):
	quat = [float(x) for x in valuelist]
	quat = Piavca.Quat(Piavca.degToRad(quat[0]), Piavca.Vec(quat[1], quat[2], quat[3]))
	return quat

# take an attribute in textural form and parse it into the possible types it can take
def parseAttribute(attrValue, type, elementType):
	
	value = str(attrValue).strip()
	if value == "":
		return ["", None]

	valuelist = stringToValueList(attrValue)
	
	#print "attr value", value, valuelist, type, elementType
	
	possible_values = []
	
	# maybe its a quaternion
	if (type == Piavca.Quat or type == types.NoneType) and len(valuelist) == 4:
		try:
			quat = ValueListToQuat(valuelist)
			possible_values.append(quat)
		# didn't work so try next option
		except ValueError:
			pass
			
	# maybe its a Vec
	if (type == Piavca.Vec or type == types.NoneType) and len(valuelist) == 3:
		try:
			vec = ValueListToVec(valuelist)
			possible_values.append(vec)
		# didn't work so try next option
		except ValueError:
			pass
			
	# might be just a single value
	if len(valuelist) == 1:
		
		if type == bool or type == types.NoneType:
			if value == "True" or value == "true":
				possible_values.append(True)
			if value == "False" or value == "false":
				possible_values.append(False)
		
		if type == int or type == types.NoneType:
			try:
				i = int(value)
				possible_values.append(i)
			except ValueError:
				pass
			
		if type == float or type == types.NoneType:
			#print "found a float value"
			try:
				f = float(value)
				possible_values.append(f)
			except ValueError:
				pass
				
		if type == "Joint":
			try:
				i = int(value)
				possible_values.append(i)
			except ValueError:
				i = Piavca.Core.getCore().getTrackName(value)
				possible_values.append(i)
		
		#if value == "True" or value == "true":
		#	possible_values.append(True)
		#if value == "False" or value == "false":
		#	possible_values.append(False)
	
	# maybe its a list of numbers
	if type == types.NoneType or (type == list and (elementType == float or elementType == None)):
		try:
			vec = [float(x) for x in valuelist]
			possible_values.append(vec)
		# didn't work so try next option
		except ValueError:
			pass
	# maybe its a list of motion names
	# try:
		# motions = []
		# for name in valuelist:
			##print "seeing if attribute is a motion", name
			# mot = Piavca.getMotion(name)
			# if mot == None:
				# raise ValueError
			# motions.append(mot)
		# possible_values.append(motions)
	# didn't work so try next option
	# except ValueError:
		# pass
	# maybe its a list of avatar names
	# try:
		# avatars = []
		# for name in valuelist:
			# av = Piavca.Core.getCore().getAvatar(name)
			# if av == None:
				# raise ValueError
			# avatars.append(av)
		# possible_values.append(avatars)
	# didn't work so try next option
	# except ValueError:
		# pass
	# maybe its just a list of strings
	if type == types.NoneType or type == Piavca.MotionMask or (type == list and (elementType == str or elementType == None)):
		try:
			valuelist = [v.strip(" '\"") for v in valuelist]
			##print valuelist
			possible_values.append(valuelist)
		##didn't work so try next option
		except ValueError:
			pass
		
	# maybe its  a joint with a space in the name
	if type == "Joint":
		try:
			i = int(value)
			possible_values.append(i)
		except ValueError:
			i = Piavca.Core.getCore().getTrackId(value)
			#print "got joint id"
			possible_values.append(i)
		
	# if all else fails, treat it as a string
	if type == types.NoneType or type == str:
		try:
			possible_values.append(value)
		except ValueError:
			pass
		
	return possible_values

# add method
	
def setAttribute(mot, attrName, attrValue, firstArg = None):
	# if the attribute is empty don't try to set it
	if attrValue == "":
		return
	attrName = str(attrName)
	if not hasattr(mot, "set" + string.upper(attrName[0]) + attrName[1:]):
		print "could not find attribute", attrName
		return 0
	meth = getattr(mot, "set" + string.upper(attrName[0]) + attrName[1:])
	if not hasattr(mot, "get" + string.upper(attrName[0]) + attrName[1:]):
		print "could not find attribute", attrName
		return 0
	getmeth = getattr(mot, "get" + string.upper(attrName[0]) + attrName[1:])
	val = getmeth()
	valtype = type(val)
	if attrName[-len("JointId"):] == "JointId" or attrName[-len("ExpressionId"):] == "ExpressionId" or attrName[-len("TrackId"):] == "TrackId":
		#print "Found joint attribute"
		valtype = "Joint"
	element_type = None
	if valtype == list and len(val) > 0:
		element_type = type(val[0])
	
	#print "attrName", attrValue, val, valtype, element_type
	
	if firstArg == None:
		method = meth
	else:
		method = lambda x : meth(firstArg, x)
	
	possible_values = parseAttribute(attrValue, valtype, element_type)
	#print possible_values
	for value in possible_values:
		#print "trying value", value, type(value)
		try:
			method(value)
			return 1
		except ValueError:
			pass
		except NotImplementedError:
			pass
		except TypeError:
			pass
	
	# if we've got here, nothing works!
	raise ValueError("Invalid value "+attrValue+" for attribute "+attrName)
	return 0
		
def addElement(mot, eleName, arglist):
	eleName = str(eleName)
	if not hasattr(mot, "add" + string.upper(eleName[0]) + eleName[1:]):
		print "could not find element", eleName
		return 0
	method = getattr(mot, "add" + string.upper(eleName[0]) + eleName[1:])
	
	# create a dictionary for each possible combination of argument value types
	args = [{}]
	for name, value in arglist:
		#print "element attrs", name, value
		possible_values = parseAttribute(value, None, None)
		temp_args = []
		for arg in args:
			#print arg
			for value in possible_values:
				new_arg = dict(arg)
				new_arg[str(name)] = value
				temp_args.append(new_arg)
		args = temp_args
	
	#print args
	# call the method by keyword args, trying each dictionary in turn
	for arg in args:
		#print arg
		try:
			method(**arg)
			return 1
		except ValueError:
			pass
		except TypeError:
			pass
	
	# if we've got here, nothing works!
	raise ValueError("Invalid value "+arglist+" for attribute "+eleName)
	return 0
	
def getMotionTypeNames():
	motionTypeNames = []
	for key in Piavca.__dict__.keys():
		#print "****", key, Piavca.__dict__[key]
		if type(Piavca.__dict__[key]) == types.TypeType and issubclass(Piavca.__dict__[key], Piavca.Motion):
			motionTypeNames.append(key)
	return motionTypeNames
	
def readMotions(motions):
	mots = []
	element_list = []
	child_motion_list = []
	for motion in motions:
		if motion.nodeType == minidom.Node.ELEMENT_NODE:
			#print "current node", motion.nodeName
			if motion.nodeName == "Avatar":
				name = str(motion.getAttribute("name"))
				if name == "":
					name = str(motion.getAttribute("Name"))
				if name == "":
					print "Avatar statement without a name"
					
				position = str(motion.getAttribute("position"))
				if position == "":
					position = str(motion.getAttribute("Position"))
				if position != "":
					position = str(position).strip()
					position = stringToValueList(position)
					position = ValueListToVec(position)
				else:
					position = Piavca.Vec()
					
				rotation = str(motion.getAttribute("rotation"))
				if rotation == "":
					rotation = str(motion.getAttribute("Rotation"))
				if rotation != "":
					rotation = str(rotation).strip()
					rotation = stringToValueList(rotation)
					rotation = ValueListToQuat(rotation)
				else:
					rotation = Piavca.Quat()
					
				avatar = Piavca.Avatar(name)
				#print "loaded avatar", name, position, rotation
				avatar.setRootPosition(position)
				avatar.setRootOrientation(rotation)
				for child in motion.childNodes:
					if child.nodeType != minidom.Node.ELEMENT_NODE:
						continue
					if child.nodeName != "Event":
						#print "expected a Event statement as a child of an avatar but got", child.nodeName
						continue
					name = str(child.getAttribute("name"))
					if name == "":
						name = str(child.getAttribute("Name"))
					if name == "":
						print "Event statement without a name"
					Piavca.addEvent(avatar, name)
					
			elif motion.nodeName == "Motion":
				#print "found a motion statement", motion
				for i in range(motion.attributes.length):
					#print motion.attributes.item(i).name, motion.attributes.item(i).nodeValue
					unknownAttrs=[]
					if motion.attributes.item(i).name != "name":
						unknownAttrs.append((motion.attributes.item(i).name, motion.attributes.item(i).nodeValue))
				name = str(motion.getAttribute("name"))
				if name == "":
					name = str(motion.getAttribute("Name"))
				if name == "":
					print "Motion statement without a name"
				else:
					#print "*"+name+"*"
					mot = Piavca.getMotion(name)
					#print mot
					if mot == None:
						print "could not find motion", name
					else:
						mots.append((mot, str(motion.nodeName), unknownAttrs))
						#print "mots", mots
						
			elif motion.nodeName == "File":
				name = str(motion.getAttribute("name"))
				filename = str(motion.getAttribute("filename"))
				Paivca.loadMotion(name, filename)
						
			elif motion.nodeName == "Keyframes":
				for i in range(motion.attributes.length):
					#print motion.attributes.item(i).name, motion.attributes.item(i).nodeValue
					unknownAttrs=[]
					if motion.attributes.item(i).name != "name":
						unknownAttrs.append((motion.attributes.item(i).name, motion.attributes.item(i).nodeValue))
				name = str(motion.getAttribute("name"))
				mot = Piavca.KeyframeMotion()
				mot.thisown = False
				for child in motion.childNodes:
					if child.nodeType != minidom.Node.ELEMENT_NODE:
						continue
					if child.nodeName != "Key":
						print "expected a key statement as a child of a keyframe motion but got", child.nodeName
						continue
					key_type = str(child.getAttribute("type"))
					key_value = str(child.getAttribute("value"))
					key_time = float(child.getAttribute("time"))
					key_joint = str(child.getAttribute("joint"))
					if key_type == "FLOAT" or key_type == "Float" or key_type == "float":
						key_joint = Piavca.Core.getCore().getExpressionId(key_joint)
					else:
						key_joint = Piavca.Core.getCore().getJointId(key_joint)
					if key_joint == Piavca.Core.getCore().nullId :
						raise ValueError("Unknown Joint Id " + str(child.getAttribute("joint")))
						Piavca.Core.getCore().addJointNameSet([key_joint])
					if key_type == "FLOAT" or key_type == "Float" or key_type == "float":
						if mot.isNull(key_joint):
							mot.addFloatTrack(key_joint, 0.0)
						key_value = float(key_value)
						mot.setFloatKeyframe(key_joint, float(key_time), key_value)
					if key_type== "VEC" or key_type == "Vec" or key_type == "vec":
						if mot.isNull(key_joint):
							mot.addVecTrack(key_joint, Piavca.Vec())
						valuelist = stringToValueList(key_value)
						key_value = ValueListToVec(valuelist)
						mot.setVecKeyframe(key_joint, float(key_time), key_value)
					if key_type == "QUAT" or key_type == "Quat" or key_type == "quat":
						if mot.isNull(key_joint):
							mot.addQuatTrack(key_joint, Piavca.Quat())
						valuelist = stringToValueList(key_value)
						key_value = ValueListToQuat(valuelist)
						mot.setQuatKeyframe(key_joint, float(key_time), key_value)
				if name != "":
					Piavca.loadMotion(name, mot)
							
			else:
				try:
					#print "other motion types", motion.nodeName
					cl = getattr(Piavca, motion.nodeName)
					if type(cl) == types.TypeType and issubclass(cl, Piavca.Motion):
						#print "found motion type", motion.nodeName
						mot = cl()
						
						storedMotName = mot.getName()
						storedMotStr = str(mot)
						if mot == None:
							raise "could not create motion " + motion.nodeName
							continue
						mot.thisown = False
						unknownAttrs=[]
						for i in range(motion.attributes.length):
							if str(motion.attributes.item(i).name) == "name" or str(motion.attributes.item(i).name) == "Name":
								name = str(motion.attributes.item(i).nodeValue)
								#print "========================motion name", name
								if name != "":
									Piavca.loadMotion(name, mot)
								continue
							attrName = motion.attributes.item(i).name
							attrValue = motion.attributes.item(i).nodeValue
							#print attrName, attrValue
							if not setAttribute(mot, attrName, attrValue):
								unknownAttrs.append((attrName, attrValue))
						child_motion_list.append((mot, motion.childNodes))
												
						mot.create()
						mots.append((mot, str(motion.nodeName), unknownAttrs))
					else:
						raise str(motion.nodeName) + " is not a motion type, its type is: " + str(type(cl))
						# add to a "add list" instead, parse attributes into a dictionary
				except AttributeError, e:
					print "Attribute Error:", e
					
					elementName = motion.nodeName
					attrList = []	
					for i in range(motion.attributes.length):
						
						attrName = motion.attributes.item(i).name
						attrValue = motion.attributes.item(i).nodeValue
						attrList.append((attrName, attrValue))
					element_list.append((elementName, attrList))
					#print "element list", element_list
		
	for mot, childNodes in child_motion_list:
		children, elements = readMotions(childNodes)
		added = 0
		if len(children) == 1:
			if hasattr(mot, "addMotion"):
				getattr(mot, "addMotion")(children[0][0])
				for attrName, attrValue in children[0][2]:
					attrName = "Motion" + string.upper(attrName[0]) + attrName[1:]
					if not setAttribute(mot, attrName, attrValue):
						print children[0][1], "unknown attribute", attrName
				added = 1
			elif hasattr(mot, "setMotion"):
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
			if hasattr(mot, "addMotion"):
				getattr(mot, "addMotion")(children[0][0])
				for attrName, attrValue in children[0][2]:
					attrName = "Motion" + string.upper(attrName[0]) + attrName[1:]
					if not setAttribute(mot, attrName, attrValue):
						print children[0][1], "unknown attribute", attrName
				getattr(mot, "addMotion")(children[1][0])
				for attrName, attrValue in children[1][2]:
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
				#print "should be", motion.nodeName, storedMotName, storedMotStr
				#print "XML Motion File add motion", mot.getName(), mot
				#print len(children)
				for i, child in enumerate(children):
					#method(child[0])
					mot.addMotion(child[0])
					#print "added motion", i , child[1]
					for attrName, attrValue in child[2]:
						attrName = "Motion" + string.upper(attrName[0]) + attrName[1:]
						if not setAttribute(mot, attrName, attrValue, i):
							print child[1], "unknown attribute", attrName
							
		for elementName, attrList in elements:
			#print "element", elementName, attrList
			if not addElement(mot, elementName, attrList):
				print "couldn't find motion type", elementName

					
	#print mots
	#print len(mots)
	#print [mot[0] for mot in mots]
	#print "finished reading motions", [mot[0].getName() for mot in mots]
	return mots, element_list

def saveMotions(filename, motions, element = None, doc = None, avatars=[]):
	writeout = 0
	if element == None:
		impl = minidom.getDOMImplementation()
		doc = impl.createDocument("", "PiavcaMotions", None)
		element = doc.documentElement
		writeout = 1
	
	allPiavca = Piavca.__dict__
	#print allPiavca
	
	members_to_ignore = ["getQuatValueAtTime", "getVecValueAtTime", "getFloatValueAtTime", "getQuatValueAtTimeInternal", 
						"getVecValueAtTimeInternal", "getFloatValueAtTimeInternal", "getMotionLength"]
	
	for avatar in avatars:
		avatar_el = doc.createElement("Avatar")
		avatar_el.setAttribute("name", avatar.getName())
		avatar_el.setAttribute("position", str(avatar.getRootPosition()))
		q = avatar.getRootOrientation()
		angle = q.getAngle()
		axis = q.getAxis()
		avatar_el.setAttribute("rotation", str(angle) + " " + str(axis))
		
		events = Piavca.getEvents(avatar)
		for event in events:
			el = doc.createElement("Event")
			el.setAttribute("name", event)
			avatar_el.appendChild(el)
			
		element.appendChild(avatar_el)
	
	for motion in motions:
		motiontype = None
		motiontypes = []
		motiontypename = "unknown"
		for key in allPiavca.keys():
			if type(allPiavca[key]) == types.TypeType and isinstance(motion, allPiavca[key]):
				motiontypes.append(allPiavca[key])
				if motiontype == None or issubclass(allPiavca[key], motiontype):
					motiontype = allPiavca[key]
					motiontypename = key
		#print name, "is a", motiontypename
		if motiontype == None:
			print "Motion is of unknown type"
			continue
		if motiontype == Piavca.KeyframeMotion:
			print "don't save keyframe motions"
			continue
		#print motion.getName(), motiontypename
		el = doc.createElement(motiontypename)
		#el.setAttribute("name", name)
		#print motion.__dict__
		ignorelist = set(["getStartTime", "getMotion", "getMotion1", "getMotion2"])
		for mtype in motiontypes:
			for key in mtype.__dict__.keys():
				if key[:3] == "get":
					#print key
					if key in ignorelist:
						continue
					if hasattr(motion, "set" + key[3:]):
						#print key
						method = getattr(motion, key)
						value = method()
						if type(value) == Piavca.Quat:
							value = str(Piavca.radToDeg(value.getAngle())) + " " + str(value.getAxis())
						else:
							value = str(value)
						if key[-len("JointId"):] == "JointId" or key[-len("ExpressionId"):] == "ExpressionId" or key[-len("TrackId"):] == "TrackId":
							value = Piavca.Core.getCore().getTrackName(method())
							
						# don't save empty names, it screws things up
						if key[3:] != "Name" or value != "":
							# check if its  a quaternion
							
							el.setAttribute(key[3:], value)
		motionlist = []
		if hasattr(motion, "getNumMotions"):
			n = motion.getNumMotions()
			for i in range(n):
				m = motion.getMotionByIndex(i)
				if m == None:
					continue
				m = Piavca.getRealMotionType(m)
				motionlist.append(m)
		elif hasattr(motion, "getMotion1"):
			m = motion.getMotion1()
			if m != None:
				m = Piavca.getRealMotionType(m)
				motionlist.append(m)
			m = motion.getMotion2()
			if m != None:
				m = Piavca.getRealMotionType(m)
				motionlist.append(m)
		elif hasattr(motion, "getMotion"):
			m = motion.getMotion()
			if m != None:
				m = Piavca.getRealMotionType(m)
				motionlist.append(m)
				
		for m in motionlist:
			if m.getName() != "":
				sub_el = doc.createElement("Motion")
				sub_el.setAttribute("name", m.getName())
				el.appendChild(sub_el)
			else:
				saveMotions(filename, [m], el, doc)
				
		element.appendChild(el)
		
	file = open(filename, "w")
	doc.writexml(file, "", "\t", "\n")
	file.close()
	
def saveAll(filename):
	core = Piavca.Core.getCore()
	motions = core.getMotionNames()
	#print motions
	motions = [Piavca.getMotion(motion) for motion in motions]
	
	avatars = core.getAvatarNames()
	#print avatars
	avatars = [core.getAvatar(avatar) for avatar in avatars]
	
	
	saveMotions(filename, motions=motions, avatars=avatars)
	
def writeOutMotionTypes(filename):
	file = open(filename, "w")
	for key in Piavca.__dict__.keys():
		#print "****", key, Piavca.__dict__[key]
		if type(Piavca.__dict__[key]) == types.TypeType and issubclass(Piavca.__dict__[key], Piavca.Motion):
			print >> file, key, ":", 
			motiontype = Piavca.__dict__[key]
			if hasattr(motiontype, "addMotion"):
				print >> file, "Many Child Motions"
			elif hasattr(motiontype, "setMotion"):
				print >> file, "1 Child Motion"
			elif hasattr(motiontype, "setMotion1"):
				print >> file, "2 Child Motions"
			else:
				print >> file, "Procedural Motion"
			for k in motiontype.__dict__.keys():
				if k[:3] == "set":
					param = k[3:]
					if param == "Motion" or param == "Motion1" or param == "Motion2":
						continue
					print >> file, "	", param
			#print >> file, "\n"
				
def parse(filename):
	dom = minidom.parse(filename) 
	for topLevel in dom.childNodes:
		readMotions(topLevel.childNodes)
	dom.unlink
	print "finished parsing all motions"
	
