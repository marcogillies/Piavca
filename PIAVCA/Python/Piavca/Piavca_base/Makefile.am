#piavca_SOURCES = piavca.cpp

# set the include path found by configure
INCLUDES= -I$(srcdir)/.. -I$(srcdir)/../../../src $(all_includes)


#pyfilesdir = $(pythondir)  
#/Piavca/
#pyfiles_PYTHON = ../../../Python/Piavca/Piavca_base.py $(srcdir)/../../Python/Piavca/__init__.py $(srcdir)/../../#Python/Piavca/MotionFile.py

BUILT_SOURCES = Piavca_wrap.cpp 
SWIG_SOURCES = Piavca.i 

pkgpython_PYTHON = $(srcdir)/Piavca_base.py $(srcdir)/../__init__.py $(srcdir)/../AnimationTrack.py $(srcdir)/../ConversationInterface.py  $(srcdir)/../DataStream.py $(srcdir)/../EigenAnalysis.py $(srcdir)/../EigenMotion.py $(srcdir)/../ExpMap.py  $(srcdir)/../FootPlantOnSpot.py $(srcdir)/../FSM.py  $(srcdir)/../GraphSearch.py  $(srcdir)/../JointNames.py $(srcdir)/../MotionFile.py $(srcdir)/../MotionGraph.py $(srcdir)/../MotionTracks.py $(srcdir)/../PCA.py $(srcdir)/../ParameterMotion.py $(srcdir)/../PositionHandler.py $(srcdir)/../redirect.py $(srcdir)/../runScriptEngine.py $(srcdir)/../ScriptEngine.py $(srcdir)/../SoundEngine.py $(srcdir)/../SpeechToText.py $(srcdir)/../Split.py $(srcdir)/../StrongConnectivity.py $(srcdir)/../Track.py $(srcdir)/../XMLMotionFile.py

bin_SCRIPTS = $(srcdir)/../../Viewer.py $(srcdir)/../../wxViewer.py $(srcdir)/../../gltb.py $(srcdir)/../../PiavcaScriptEngine.py $(srcdir)/../../MotionEditor.py

pkgpyexec_LTLIBRARIES = _Piavca_base.so.la
#_your_extension_la_SOURCES = $(srcdir)/swig_wrap.cpp $(SWIG_SOURCES)
#_your_extension_la_LIBADD = ../src/libproject.la

$(srcdir)/Piavca_wrap.cpp : $(SWIG_SOURCES)
	$(SWIG) $(SWIG_PYTHON_OPT) -I$(srcdir)/../../../src -o $@ $<
#	$(SWIG) $(SWIG_PYTHON_OPT) -I$(srcdir)/.. -o $@ -outdir $(srcdir)/../../Python/Piavca $<
#lib_LTLIBRARIES = libPiavcaPythonInterface.la

_Piavca_base_so_la_SOURCES = $(SWIG_SOURCES) Piavca_wrap.cpp
_Piavca_base_so_la_CPPFLAGS = $(PYTHON_CPPFLAGS) $(SWIG_PYTHON_CPPFLAGS)
_Piavca_base_so_la_LDFLAGS = -module $(SHARED_LIB) -no-undefined $(GL_LIB) $(PYTHON_LDFLAGS)  -lcal3d $(all_libraries) 
_Piavca_base_so_la_LIBADD = ../../../src/PiavcaCal3dImp/libPiavcaCal3dImp.la ../../../src/StdMotionImp/libStdMotionImp.la ../../../src/PiavcaAPI/libPiavcaAPI.la  
	
post_build: all
	if test ! -f _Piavca_base.so; then ln -s .libs/_Piavca_base.so _Piavca_base.so; fi