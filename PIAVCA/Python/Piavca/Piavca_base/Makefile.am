#piavca_SOURCES = piavca.cpp

# set the include path found by configure
INCLUDES= -I$(srcdir)/.. $(all_includes)



#pyfilesdir = $(pythondir)  
#/Piavca/
#pyfiles_PYTHON = ../../../Python/Piavca/Piavca_base.py $(srcdir)/../../Python/Piavca/__init__.py $(srcdir)/../../#Python/Piavca/MotionFile.py

BUILT_SOURCES = Piavca_wrap.cpp 
SWIG_SOURCES = Piavca.i 

pkgpython_PYTHON = $(srcdir)/../../Python/Piavca/Piavca_base.py $(srcdir)/../../Python/Piavca/__init__.py $(srcdir)/../../Python/Piavca/AnimationTrack.py $(srcdir)/../../Python/Piavca/ConversationInterface.py $(srcdir)/../../Python/Piavca/EigenAnalysis.py $(srcdir)/../../Python/Piavca/EigenMotion.py $(srcdir)/../../Python/Piavca/ExpMap.py  $(srcdir)/../../Python/Piavca/FootPlantOnSpot.py  $(srcdir)/../../Python/Piavca/GraphSearch.py  $(srcdir)/../../Python/Piavca/JointNames.py $(srcdir)/../../Python/Piavca/MotionFile.py $(srcdir)/../../Python/Piavca/MotionGraph.py $(srcdir)/../../Python/Piavca/MotionTracks.py $(srcdir)/../../Python/Piavca/PCA.py $(srcdir)/../../Python/Piavca/redirect.py $(srcdir)/../../Python/Piavca/runScriptEngine.py $(srcdir)/../../Python/Piavca/ScriptEngine.py $(srcdir)/../../Python/Piavca/SoundEngine.py $(srcdir)/../../Python/Piavca/SpeechToText.py $(srcdir)/../../Python/Piavca/Split.py $(srcdir)/../../Python/Piavca/StrongConnectivity.py $(srcdir)/../../Python/Piavca/Track.py $(srcdir)/../../Python/Piavca/XMLMotionFile.py

bin_SCRIPTS = $(srcdir)/../../Python/Viewer.py $(srcdir)/../../Python/PiavcaScriptEngine.py $(srcdir)/../../Python/MotionEditor.py

pkgpyexec_LTLIBRARIES = _Piavca_base.so.la
#_your_extension_la_SOURCES = $(srcdir)/swig_wrap.cpp $(SWIG_SOURCES)
#_your_extension_la_LIBADD = ../src/libproject.la

$(srcdir)/Piavca_wrap.cpp : $(SWIG_SOURCES)
#	$(SWIG) $(SWIG_PYTHON_OPT) -I$(srcdir)/.. -o $@ $<
	$(SWIG) $(SWIG_PYTHON_OPT) -I$(srcdir)/.. -o $@ -outdir $(srcdir)/../../Python/Piavca $<
#lib_LTLIBRARIES = libPiavcaPythonInterface.la

_Piavca_base_so_la_SOURCES = $(SWIG_SOURCES) Piavca_wrap.cpp
_Piavca_base_so_la_CPPFLAGS = $(PYTHON_CPPFLAGS) $(SWIG_PYTHON_CPPFLAGS)
_Piavca_base_so_la_LDFLAGS = -module -shared $(PYTHON_LDFLAGS)  -lglut -lcal3d $(all_libraries)
_Piavca_base_so_la_LIBADD = ../PiavcaAPI/libPiavcaAPI.la ../PiavcaCal3dImp/libPiavcaCal3dImp.la ../StdMotionImp/libStdMotionImp.la 
