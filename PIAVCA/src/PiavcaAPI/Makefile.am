#piavca_SOURCES = piavca.cpp

# set the include path found by configure
INCLUDES= -I../../../src/ $(all_includes)

apiincludedir = $(includedir)/Piavca/PiavcaAPI

apiinclude_HEADERS = Avatar.h AvatarImp.h AvatarPostureBlend.h BlendBetween.h Hermite.h LoopMotion.h MathsUtils.h MotionAdder.h MotionFilter.h MotionImp.h Motion.h ObjectImp.h Object.h PiavcaCore.h PiavcaDefs.h PiavcaException.h Quat.h SelfBlend.h SequentialBlend.h TimeCallback.h TrackMotion.h TwoMotionCombiner.h Vec.h

noinst_LTLIBRARIES = libPiavcaAPI.la

libPiavcaAPI_la_SOURCES = Avatar.cpp AvatarPostureBlend.cpp PiavcaCore.cpp Hermite.cpp Motion.cpp Object.cpp Quat.cpp Vec.cpp SequentialBlend.cpp SelfBlend.cpp
