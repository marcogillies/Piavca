========================================================================
    PiavcaAPI Project Overview
========================================================================

This is the main API for Piavca. It aims to be completely platform independent and
doesn't rely on any libraries such as Cal3d. It can be ported to a different low
level library without any problems.

NB If you make any changes to the API header files and you want them to be refected in the
Python interface you will need to regenerate the python wrappers (you need SWIG: www.swig.org).
For instructions see the ReadMe file in Piavca/Python/Piavca/Piavca_base.
