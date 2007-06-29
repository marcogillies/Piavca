#piavca_SOURCES = piavca.cpp

# set the include path found by configure
INCLUDES= -I$(top_srcdir)/src -I/usr/local/include/ $(all_includes)


cal3dimpincludedir = $(includedir)/Piavca/PiavcaCal3dImp
cal3dimpinclude_HEADERS = AvatarCal3dImp.h Cal3dMathsConversion.h MotionCal3dImp.h PiavcaCal3dCore.h TextureHandler.h tga.h

lib_LTLIBRARIES = libPiavcaCal3dImp.la

libPiavcaCal3dImp_la_SOURCES = AvatarCal3dImp.cpp MotionCal3dImp.cpp PiavcaCal3dCore.cpp TextureHandler.cpp tga.cpp

#libPiavcaCal3dImp_la_LIBADD = ../PiavcaAPI/libPiavcaAPI.la ../StdMotionImp/libStdMotionImp.la

