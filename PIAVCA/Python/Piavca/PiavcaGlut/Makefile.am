#piavca_SOURCES = piavca.cpp



# set the include path found by configure
INCLUDES= -I$(srcdir)/.. -I$(srcdir)/../../../src $(all_includes)


#pyfilesdir = $(includedir)/Piavca/Python
#pyfiles_PYTHON = PiavcaGlut.py PiavcaGlut.so
#pkgpyexecdir = $(includedir)/Piavca/Python


BUILT_SOURCES = PiavcaGlut_wrap.cpp
SWIG_SOURCES = PiavcaGlut.i 

pkgpython_PYTHON = $(srcdir)/PiavcaGlut.py
pkgpyexec_LTLIBRARIES = _PiavcaGlut.so.la
#_your_extension_la_SOURCES = $(srcdir)/swig_wrap.cpp $(SWIG_SOURCES)
_PiavcaGlut_so_la_CPPFLAGS = $(PYTHON_CPPFLAGS) $(SWIG_PYTHON_CPPFLAGS) $(GLUT_LIB)
_PiavcaGlut_so_la_LDFLAGS = -module $(SHARED_LIB) $(PYTHON_LDFLAGS)  $(GLUT_LIB) -lcal3d $(all_libraries)
#_your_extension_la_LIBADD = ../src/libproject.la

$(srcdir)/PiavcaGlut_wrap.cpp : $(SWIG_SOURCES)
	$(SWIG) $(SWIG_PYTHON_OPT) -I$(srcdir)/../../../src -o $@ $<
#$(srcdir)/PiavcaGlut_wrap.cpp : $(SWIG_SOURCES)
#	$(SWIG) $(SWIG_PYTHON_OPT) -I$(srcdir)/.. -o $@ -outdir $(srcdir)/../../Python/Piavca/ $<
#lib_LTLIBRARIES = libPiavcaPythonInterface.la

_PiavcaGlut_so_la_SOURCES = $(SWIG_SOURCES) PiavcaGlut_wrap.cpp PiavcaGlut.cpp

_PiavcaGlut_so_la_LIBADD = ../../../src/PiavcaAPI/libPiavcaAPI.la ../../../src/PiavcaCal3dImp/libPiavcaCal3dImp.la ../../../src/StdMotionImp/libStdMotionImp.la 


#_PiavcaGlut_so_la_LIBADD = ../PiavcaCal3dImp/libPiavcaCal3dImp.la

_PiavcaGlut.so: all
	

post_build: all
	if test ! -f _PiavcaGlut.so; then ln -s .libs/_PiavcaGlut.so _PiavcaGlut.so; fi