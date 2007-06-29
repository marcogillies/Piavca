#piavca_SOURCES = piavca.cpp



# set the include path found by configure
INCLUDES= -I$(srcdir)/.. $(all_includes)


#pyfilesdir = $(includedir)/Piavca/Python
#pyfiles_PYTHON = PiavcaGlut.py PiavcaGlut.so
#pkgpyexecdir = $(includedir)/Piavca/Python


BUILT_SOURCES = PiavcaGlut_wrap.cpp
SWIG_SOURCES = PiavcaGlut.i 

pkgpython_PYTHON = $(srcdir)/../../Python/Piavca/PiavcaGlut.py
pkgpyexec_LTLIBRARIES = _PiavcaGlut.so.la
#_your_extension_la_SOURCES = $(srcdir)/swig_wrap.cpp $(SWIG_SOURCES)
_PiavcaGlut_so_la_CPPFLAGS = $(PYTHON_CPPFLAGS) $(SWIG_PYTHON_CPPFLAGS)
_PiavcaGlut_so_la_LDFLAGS = -module -shared $(PYTHON_LDFLAGS)  -lglut -lcal3d $(all_libraries)
#_your_extension_la_LIBADD = ../src/libproject.la

$(srcdir)/PiavcaGlut_wrap.cpp : $(SWIG_SOURCES)
	$(SWIG) $(SWIG_PYTHON_OPT) -I$(srcdir)/.. -o $@ -outdir $(srcdir)/../../Python/Piavca/ $<
#lib_LTLIBRARIES = libPiavcaPythonInterface.la

_PiavcaGlut_so_la_SOURCES = $(SWIG_SOURCES) PiavcaGlut_wrap.cpp PiavcaGlut.cpp

_PiavcaGlut_so_la_LIBADD = ../PiavcaAPI/libPiavcaAPI.la ../PiavcaCal3dImp/libPiavcaCal3dImp.la ../StdMotionImp/libStdMotionImp.la 


#_PiavcaGlut_so_la_LIBADD = ../PiavcaCal3dImp/libPiavcaCal3dImp.la
