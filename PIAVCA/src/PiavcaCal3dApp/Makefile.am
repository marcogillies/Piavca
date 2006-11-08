bin_PROGRAMS = PiavcaCal3dApp
PiavcaCal3dApp_SOURCES = PiavcaCal3dApp.cpp

# set the include path found by configure
INCLUDES= -I$(top_srcdir)/src $(all_includes)

PiavcaCal3dApp_CPPFLAGS = $(SWIG_PYTHON_CPPFLAGS)

PiavcaCal3dApp_LDADD = ../PiavcaCal3dImp/libPiavcaCal3dImp.la ../PiavcaPythonInterface/libPiavcaPythonInterface.la

# the library search path.
#PiavcaCal3dApp_LDFLAGS = $(PYTHON_LDFLAGS) -R/usr/local/lib -L../PiavcaCal3dImp -L../PiavcaAPI -L../PiavcaNVCLib -L../PiavcaPythonInterface -L../StdMotionImp -lglut -lcal3d -lPiavcaCal3dImp -lPiavcaPythonInterface -lStdMotionImp -lPiavcaNVCLib -lPiavcaAPI $(all_libraries) 
PiavcaCal3dApp_LDFLAGS = $(PYTHON_LDFLAGS) -R/usr/local/lib  -L../PiavcaCal3dImp -lglut -lcal3d $(all_libraries)
