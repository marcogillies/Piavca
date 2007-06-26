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

joint_specs = ["Root Position, rootpos"
"Root Orientation, pelvis, HumaniodRoot01, rootori",
"HumaniodRoot01 Spine, Cally Spine, Bip01 Pelvis, pelvic",
"HumaniodRoot01 Spine1, Cally Spine1, Bip01 Spine1, lower_tbone, hip, hanim_vc7, abdomen, Spine0, body, thorax",
"HumaniodRoot01 Spine2, Bip01 Spine2, Spine1, Chest, chest, tbone",
"HumaniodRoot01 Neck, Cally Neck, Bip01 Neck, neck, Neck, hanim_vc4",
"HumaniodRoot01 Head, Cally Head, Bip01 Head, face, head, Head, hanim_skullbase",
"HumaniodRoot01 L Clavicle, Cally L Clavicle, Bip01 L Clavicle, left_shoulder, LShoulder, LClavicle, hanim_l_shoulder, lCollar, LeftCollar, lclavicle",
"HumaniodRoot01 L UpperArm, Cally L UpperArm, Bip01 L UpperArm, upper_left_arm, LUpperArm, lShldr, LeftShoulder, lhumerus",
"HumaniodRoot01 L Forearm, Cally L Forearm, Bip01 L Forearm, lower_left_arm, LForeArm, LForearm, lForeArm, left_elbow, LeftElbow, lradius, LElbow",
"HumaniodRoot01 L Hand, Cally L Hand, Bip01 L Hand, left_wrist, LWrist, LHand, lHand, LeftWrist, lhand",
"HumaniodRoot01 R Clavicle, Cally R Clavicle, Bip01 R Clavicle, right_shoulder, RShoulder, RClavicle, hanim_r_shoulder, rCollar, RightCollar, rclavicle",
"HumaniodRoot01 R UpperArm, Cally R UpperArm, Bip01 R UpperArm, upper_right_arm, RUpperArm, rShldr, RightShoulder, rhumerus",
"HumaniodRoot01 R Forearm, Cally R Forearm, Bip01 R Forearm, lower_right_arm, RForeArm, RForearm, rForeArm, right_elbow, RightElbow, rradius, RElbow, ",
"HumaniodRoot01 R Hand, Cally R Hand, Bip01 R Hand, right_wrist, RWrist, RHand, rHand, RightWrist, rhand",
"legs",
"left_hip, lButtock",
"HumaniodRoot01 L Thigh, Cally L Thigh, Bip01 L Thigh, upper_left_leg, LThigh, lThigh, left_hip, LHip, LeftHip, lfemur",
"HumaniodRoot01 L Calf, Cally L Calf, Bip01 L Calf, lower_left_leg, LCalf, lShin, left_knee, LeftKnee, ltibia",
"HumaniodRoot01 L Foot, Cally L Foot, Bip01 L Foot, left_foot, LFoot, lFoot, LeftAnkle, lfoot",
"righthip, rButtock",
"HumaniodRoot01 R Thigh, Cally R Thigh, Bip01 R Thigh, upper_right_leg, RThigh, rThigh, right_hip, RHip, RightHip, rfemur",
"HumaniodRoot01 R Calf, Cally R Calf, Bip01 R Calf, lower_right_leg, RCalf, rShin, right_knee, RightKnee, rtibia",
"HumaniodRoot01 R Foot, Cally R Foot, Bip01 R Foot, right_foot, RFoot, rFoot, RightAnkle, rfoot",
"BODY",
"figureHair"]

def loadNames(namelist, joints=1):
	for line in namelist:
		if line[0] == "#":
			continue
		line = line.split(",")
		line = [l.strip() for l in line]
		if line[-1] == "":
			line = line[:-1]
		if joints :
			#print line
			Piavca.Core.getCore().addJointNameSet(line)
		else:
			#print line
			Piavca.Core.getCore().addExpressionNameSet(line)		

def loadDefaults():
	loadNames(joint_specs,1)			
			
def importNames(filename, joints=1):
	file = open(filename, "r")
	lines = file.readlines()
	file.close()
	loadNames(lines, joints)
	
			
def importJointNames(filename):
	importNames(filename, 1)	
			
def importExpressionNames(filename):
	importNames(filename, 0)