#piavca_SOURCES = piavca.cpp

# set the include path found by configure
INCLUDES= -I$(top_srcdir)/src $(all_includes)

nvcincludedir = $(includedir)/Piavca/PiavcaNVCLib

nvcinclude_HEADERS = AvatarMotionQueue.h BodyToFacial.h ChangeMotionLength.h ChangeMotionProp.h ChoiceLoopMotion.h DiadicGazeMotion.h LookAtMotion.h MaskedMotion.h MotionParser.h MotionSaver.h MultiMotionLoop.h OnTheSpot.h Piavca.h ProxemicsLoop.h RandomAddLoop.h RandomBlendLoop.h RandomGazeMotion.h RandomLoopMotion.h RandomTimingsLoop.h ScaleMotionRoot.h ScaleMotionSpeed.h ScaleMotion.h TimeOffset.h TurnMotion.h ZeroMotion.h

noinst_LTLIBRARIES = libPiavcaNVCLib.la

libPiavcaNVCLib_la_SOURCES = AvatarMotionQueue.cpp LookAtMotion.cpp \
	MaskedMotion.cpp MotionParser.cpp MotionSaver.cpp SubMotion.cpp TimeRangeMotion.cpp
