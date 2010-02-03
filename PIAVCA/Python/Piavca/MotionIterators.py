#
#  MotionIterators.py
#  piavca
#
#  Created by Marco Gillies on 03/02/2010.
#  Copyright (c) 2010 __MyCompanyName__. All rights reserved.
#

import Piavca

def quatPose(mot, t):
	return [mot.getQuatValueAtTime(j,t) for j in  Piavca.joints(mot) if mot.getTrackType(j) == Piavca.QUAT_TYPE]
	

def MotionIterator(mot, fps = 20, posefunc = quatPose):
	return (posefunc(mot, float(t)/fps) for t in range(0, int(mot.getMotionLength()*fps)))
	
	#increment = 1.0/fps
	#currentTime = 0.0
	#while(currentTime < mot.getMotionLength())
	#	yield posefunc(mot, currentTime)
	#	currentTime += increment
		
def MotionList(mot, fps = 20, posefunc = quatPose):
	return [p for p in MotionIterator(mot, fps, posefunc)]