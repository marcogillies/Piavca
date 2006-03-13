lib_LTLIBRARIES = libPiavcaOpenSGImp.la
libPiavcaOpenSGImp_la_SOURCES = PiavcaOpenSGCore.cpp AvatarOpenSGImp.cpp TextureHandlerOpenSG.cpp

opensgimpincludedir = $(includedir)/Piavca/PiavcaOpenSGImp
opensgimpinclude_HEADERS = AvatarOpenSGImp.h PiavcaOpenSGCore.h TextureHandlerOpenSG.h


# set the path to the installed osg-config executable here
# i.e. if you installed in /usr/local it is
OSGCONFIG := /usr/local/bin/osg-config
OSGLDFLAGS := $(shell $(OSGCONFIG) --libs Base System GLUT)

CXX = "$(shell $(OSGCONFIG) --compiler)"
libPiavcaOpenSGImp_la_CCFLAGS = $(shell $(OSGCONFIG) --cflags Base System GLUT)
libPiavcaOpenSGImp_la_LDFLAGS = -R/usr/local/lib/dbg $(OSGLDFLAGS)

# set the include path found by configure
INCLUDES= -I../../../src/ $(all_includes)


#PiavcaOpenSGApp_CPPFLAGS = $(SWIG_PYTHON_CPPFLAGS)

# the library search path.
#PiavcaOpenSGApp_LDFLAGS = $(PYTHON_LDFLAGS) -R/usr/local/lib -L../PiavcaCal3dImp -L../PiavcaAPI -L../PiavcaNVCLib -L../PiavcaPythonInterface -L../StdMotionImp -lglut -lcal3d -lPiavcaCal3dImp -lPiavcaPythonInterface -lStdMotionImp -lPiavcaNVCLib -lPiavcaAPI $(all_libraries) 
