========================================================================
    Piavca_base Project Overview
========================================================================

This is a subsidiary Python project that creates and manages a Glut rendering window.

It uses SWIG (www.swig.org) to do the python wrapping. By default the swig files are 
not rebuilt, so that you don't need swig to build Piavca. Its unlikely that you'll need to change 
this project but if you make any changes to the PiavcaGlut.h header file you will need to 
rebuild the swig wrappers:

To rebuild you need to do the following:

NB DO NOT DO THIS UNLESS YOU HAVE CHANGED THE INTERFACE TO PiavcaGlut AND HAVE SWIG INSTALLED

1) right click on PiavcaGlut.i and choose properties->General->Exclude From Build and choose No

2) right click on PiavcaGlut.i and choose compile (or compile it however you want).

3) Rebuild the project

4) if you are resubmitting changes to the repository, turn Exclude From Build on again.

