#piavca_SOURCES = piavca.cpp

# set the include path found by configure
INCLUDES= -I$(srcdir)/.. $(all_includes)

pyintincludedir = $(includedir)/Piavca/PiavcaPythonInterface
pyintinclude_HEADERS = PiavcaPythonApp.h

BUILT_SOURCES = Piavca_wrap.cpp
SWIG_SOURCES = Piavca.i 

#pkgpython_PYTHON = your_extension.py
#pkgpyexec_LTLIBRARIES = _your_extension.la
#_your_extension_la_SOURCES = $(srcdir)/swig_wrap.cpp $(SWIG_SOURCES)
libPiavcaPythonInterface_la_CPPFLAGS = $(PYTHON_CPPFLAGS) $(SWIG_PYTHON_CPPFLAGS)
#_your_extension_la_LDFLAGS = -module
#_your_extension_la_LIBADD = ../src/libproject.la

$(srcdir)/Piavca_wrap.cpp : $(SWIG_SOURCES)
	$(SWIG) $(SWIG_PYTHON_OPT) -I$(srcdir)/.. -o $@ $<
lib_LTLIBRARIES = libPiavcaPythonInterface.la

libPiavcaPythonInterface_la_SOURCES = PiavcaPythonApp.cpp PyMotion.cpp  $(SWIG_SOURCES) Piavca_wrap.cpp
