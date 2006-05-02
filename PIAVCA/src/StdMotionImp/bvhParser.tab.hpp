/* A Bison parser, made by GNU Bison 1.875.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     HIERARCHY = 258,
     ROOT = 259,
     OFFSET = 260,
     CHANNELS = 261,
     JOINT = 262,
     END_SITE = 263,
     MOTION = 264,
     FRAMES = 265,
     FRAME_TIME = 266,
     NUMBER = 267,
     NUMBER_INT = 268,
     NAME = 269,
     DOF_NAME = 270,
     L_BRACK = 271,
     R_BRACK = 272
   };
#endif
#define HIERARCHY 258
#define ROOT 259
#define OFFSET 260
#define CHANNELS 261
#define JOINT 262
#define END_SITE 263
#define MOTION 264
#define FRAMES 265
#define FRAME_TIME 266
#define NUMBER 267
#define NUMBER_INT 268
#define NAME 269
#define DOF_NAME 270
#define L_BRACK 271
#define R_BRACK 272




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 115 "d:\\code\\Piavca\\src\\StdMotionImp\\bvhParser.ypp"
typedef union YYSTYPE {
  int intVal;
  float floatVal;
  char * name;
  std::vector<int> *intList;
} YYSTYPE;
/* Line 1248 of yacc.c.  */
#line 77 "d:\\code\\Piavca\\src\\StdMotionImp\\bvhParser.tab.hpp"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE bvhlval;



