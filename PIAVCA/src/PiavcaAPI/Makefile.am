#piavca_SOURCES = piavca.cpp

# set the include path found by configure
INCLUDES= -I$(top_srcdir)/src $(all_includes)

apiincludedir = $(includedir)/Piavca/PiavcaAPI

apiinclude_HEADERS = Avatar.h AvatarImp.h AvatarMotionQueue.h AvatarPosture.h AvatarPostureBlend.h BlendBetween.h ChangeMotionLength.h ChangeMotionProp.h ChoiceLoopMotion.h ChoiceMotion.h DiadicGazeMotion.h Hermite.h KeyframeMotion.h LookAtMotion.h LoopMotion.h MaskedMotion.h MathsUtils.h MotionAdder.h MotionFilter.h MotionImp.h Motion.h MotionParser.h MotionPosture.h MotionSaver.h MotionTransition.h MultiMotionCombiner.h MultiMotionLoop.h ObjectImp.h Object.h OnTheSpot.h Piavca.h PiavcaCore.h PiavcaDefs.h PiavcaError.h PiavcaException.h PostureBlend.h Proxemics.h ProxemicsLoop.h Quat.h RandomAdd.h RandomAddLoop.h RandomBlend.h RandomBlendLoop.h RandomChoiceMotion.h RandomGazeMotion.h RandomLoopMotion.h RandomTimingsLoop.h Reposition.h ScaleMotion.h ScaleMotionRoot.h ScaleMotionSpeed.h SelfBlend.h Sequence.h SmoothSequence.h SubMotion.h Subtract.h TimeCallback.h TimeOffset.h TimeRangeMotion.h TimeWarp.h TurnMotion.h TwoMotionCombiner.h Vec.h ZeroMotion.h

noinst_LTLIBRARIES = libPiavcaAPI.la

libPiavcaAPI_la_SOURCES = Avatar.cpp AvatarImp.cpp AvatarMotionQueue.cpp AvatarPosture.cpp AvatarPostureBlend.cpp \ 	PiavcaCore.cpp\
	Hermite.cpp Motion.cpp Object.cpp Quat.cpp Vec.cpp SequentialBlend.cpp \
	LookAtMotion.cpp MaskedMotion.cpp MotionParser.cpp MotionSaver.cpp MotionPosture.cpp MotionTransition.cpp PostureBlend.cpp \
	Reposition.cpp BlendBetween.cpp MotionAdder.cpp PiavcaError.cpp \
	Sequence.cpp SmoothSequence.cpp SubMotion.cpp Subtract.cpp TimeRangeMotion.cpp\
	TwoMotionCombiner.cpp KeyframeMotion.cpp
