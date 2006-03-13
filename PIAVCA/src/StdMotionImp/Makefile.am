#piavca_SOURCES = piavca.cpp

# set the include path found by configure
INCLUDES= -I../../../src/ $(all_includes)

AM_YFLAGS = -p bvh -d

AM_LFLAGS = -Pbvh -olex.yy.c

stdmotincludedir = $(includedir)/Piavca/StdMotionImp

stdmotinclude_HEADERS = StdMotionImp.h StdMotionCore.h

noinst_LTLIBRARIES = libStdMotionImp.la

libStdMotionImp_la_SOURCES = StdMotionImp.cpp StdMotionCore.cpp bvhParser.ypp bvhLexer.lpp 
