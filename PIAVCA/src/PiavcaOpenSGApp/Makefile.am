bin_PROGRAMS = PiavcaOpenSGApp
PiavcaOpenSGApp_SOURCES = PiavcaOpenSGApp.cpp

#PiavcaOpenSGApp_CXX="$(shell /usr/local/bin/osg-config --compiler)"
#PiavcaOpenSGApp_CC = LALA

# set the path to the installed osg-config executable here
# i.e. if you installed in /usr/local it is
OSGCONFIG := /usr/local/bin/osg-config
OSGCPPFLAGS := $(shell $(OSGCONFIG) --cflags Base System GLUT)
OSGLDFLAGS := $(shell $(OSGCONFIG) --libs Base System GLUT)

PiavcaOpenSGApp_LDADD = ../PiavcaCal3dImp/libPiavcaCal3dImp.la ../PiavcaOpenSGImp/libPiavcaOpenSGImp.la ../PiavcaPythonInterface/libPiavcaPythonInterface.la

CXX = "$(shell $(OSGCONFIG) --compiler)"
PiavcaOpenSGApp_CPPFLAGS = $(SWIG_PYTHON_CPPFLAGS) $(OSGCPPFLAGS)
PiavcaOpenSGApp_LDFLAGS = $(PYTHON_LDFLAGS) -R/usr/local/lib/ -R/usr/local/lib/dbg -lglut -lcal3d  $(all_libraries) $(OSGLDFLAGS)

# set the include path found by configure
INCLUDES= -I../../../src/ $(all_includes)


#PiavcaOpenSGApp_CPPFLAGS = $(SWIG_PYTHON_CPPFLAGS)

# the library search path.
#PiavcaOpenSGApp_LDFLAGS = $(PYTHON_LDFLAGS) -R/usr/local/lib -L../PiavcaCal3dImp -L../PiavcaAPI -L../PiavcaNVCLib -L../PiavcaPythonInterface -L../StdMotionImp -lglut -lcal3d -lPiavcaCal3dImp -lPiavcaPythonInterface -lStdMotionImp -lPiavcaNVCLib -lPiavcaAPI $(all_libraries) 
