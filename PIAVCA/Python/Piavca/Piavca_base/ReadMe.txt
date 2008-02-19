========================================================================
    Piavca_base Project Overview
========================================================================

Piavca_base is the main binary for the Python Interface of Piavca. It wraps
the main API for use from Python.

It uses SWIG (www.swig.org) to do the python wrapping. By default the swig files are 
not rebuilt, so that you don't need swig to build Piavca. However, if you make any changes
to the Piavca API and want them reflected in Python then you will need to rebuild the 
bindings.

To rebuild you need to do the following:


NB DO NOT DO THIS UNLESS YOU HAVE CHANGED THE INTERFACE TO PIAVCA AND HAVE SWIG INSTALLED

1) If you have added a new header file import it in PiavcaAPI/Piavca.h and then add an import
statement to the end of Piavca.i

2) right click on Piavca.i and choose properties->General->Exclude From Build and choose No

3) right click on Piavca.i and choose compile (or compile it however you want).

4) Rebuild the project

5) if you are resubmitting changes to the repository, turn Exclude From Build on again.

