========================================================================
    StdMotionImp Project Overview
========================================================================

This is an implementation of Piavca animations based on the bvh file format. 

Together with PiavcaAPI it forms the core of Piavca. It was kept separate because
Piavca should be able to support multiple animation representations, for example it
also supports Cal3d Animations (in fact that is now the prefered representation). 
However, many bits of Piavca still use this code so it is really required for using 
Piavca (maybe I will integrate it into PiavcaAPI some day).

The bvh parser is written using Lex and Yacc (flex and bison to be exact). If you make 
any changes to it you will need a version of these two programs, if you install flex and bison
in your path it will work automatically under both unix and windows, if you use a different 
version under windows you might need to edit the project properties. However, its unlikely you
will want to change anything, as its been stable for a while, and I wouldn't recommend it as 
I've come to the conclusion that supporting bvh files is a nightmare, and now recommend using
cal3d Animations instead.
