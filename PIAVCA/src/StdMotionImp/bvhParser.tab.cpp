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

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0

/* If NAME_PREFIX is specified substitute the variables and functions
   names.  */
#define yyparse bvhparse
#define yylex   bvhlex
#define yyerror bvherror
#define yylval  bvhlval
#define yychar  bvhchar
#define yydebug bvhdebug
#define yynerrs bvhnerrs


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




/* Copy the first part of user declarations.  */
#line 22 "c:\\Documents and Settings\\marco\\My Documents\\code\\Piavca\\src\\StdMotionImp\\bvhParser.ypp"

// A parser


#include "bvhMotionParser.h"

#include <assert.h>

#include <stdio.h>
#include <malloc.h>
#include <string>
#include <vector>
//using std::vector;
extern int yylex();
int yyerror(char *s);


#define YYMAXDEPTH 40000

#include "PiavcaAPI/PiavcaDefs.h"
#include "PiavcaAPI/MotionImp.h"
#include "PiavcaAPI/Motion.h"
#include "StdMotionImp.h"
#include "PiavcaAPI/Quat.h"
#include "PiavcaAPI/Vec.h"
#include "PiavcaAPI/MathsUtils.h"
#include "PiavcaAPI/PiavcaCore.h"
using Piavca::Quat;
using Piavca::Vec;

// define a big stack to avoid overflow on long bits of motion
//#define YYMAXDEPTH 500000

Piavca::MotionImp *g_pMotion;
Piavca::Core *g_pCore;
std::string g_FileName;
FILE *g_file;
int g_noFrames;
bool g_bTest;
float g_StartTime;
bool g_SkipFrame;

Piavca::Motion *g_pBasePosture;

int linenum;
extern char *bvhtext;

bool g_bArmUp, g_bArmDown;
int g_ArmUpAxis;
 int g_LeftArmTrack, g_RightArmTrack;
bool g_ReverseOrder;

struct trackStruct{
  Piavca::tstring name;
  int trackId;
  int channel[9];
  bool negateChannel[9];
  Quat currentRot;
  Vec currentEuler;
  //Quat coordSystem; 
  Quat multiplier;
};


std::vector <trackStruct> tracks;
int currentTrack, currentChannel;
float currentTime, frameTime;
int rootOriTrackId, rootPosTrackId;
//int g_CurrentTrackIteratorId;
Quat currentRootOri;
Vec currentRootPos;
int rootChannel[9];

/*
Vec getAxis(int i)
{
	switch (i)
	{
	case 0:	return Vec(-1.0, 0.0, 0.0);
	case 1:	return Vec(0.0, 1.0, 0.0);
	case 2:	return Vec(0.0, 0.0, 1.0);
	default: assert(0);
	}
}
*/

Vec g_Axes[3];





/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 115 "c:\\Documents and Settings\\marco\\My Documents\\code\\Piavca\\src\\StdMotionImp\\bvhParser.ypp"
typedef union YYSTYPE {
  int intVal;
  float floatVal;
  char * name;
  std::vector<int> *intList;
} YYSTYPE;
/* Line 191 of yacc.c.  */
#line 217 "c:\\Documents and Settings\\marco\\My Documents\\code\\Piavca\\src\\StdMotionImp\\bvhParser.tab.cpp"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 229 "c:\\Documents and Settings\\marco\\My Documents\\code\\Piavca\\src\\StdMotionImp\\bvhParser.tab.cpp"

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# if YYSTACK_USE_ALLOCA
#  define YYSTACK_ALLOC alloca
# else
#  ifndef YYSTACK_USE_ALLOCA
#   if defined (alloca) || defined (_ALLOCA_H)
#    define YYSTACK_ALLOC alloca
#   else
#    ifdef __GNUC__
#     define YYSTACK_ALLOC __builtin_alloca
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC malloc
#  define YYSTACK_FREE free
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE))				\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   40

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  18
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  18
/* YYNRULES -- Number of rules. */
#define YYNRULES  25
/* YYNRULES -- Number of states. */
#define YYNSTATES  49

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   272

#define YYTRANSLATE(YYX) 						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned char yyprhs[] =
{
       0,     0,     3,     6,     9,    13,    19,    24,    28,    31,
      33,    35,    38,    41,    43,    45,    48,    53,    54,    57,
      60,    65,    68,    71,    74,    76
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const yysigned_char yyrhs[] =
{
      19,     0,    -1,    20,    31,    -1,     3,    21,    -1,     4,
      14,    22,    -1,    16,    23,    24,    27,    17,    -1,     5,
      12,    12,    12,    -1,     6,    13,    25,    -1,    26,    25,
      -1,    26,    -1,    15,    -1,    27,    29,    -1,    27,    28,
      -1,    29,    -1,    28,    -1,    28,    28,    -1,     8,    16,
      23,    17,    -1,    -1,    30,    22,    -1,     7,    14,    -1,
       9,    32,    33,    34,    -1,    10,    13,    -1,    11,    12,
      -1,    34,    35,    -1,    35,    -1,    12,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   136,   136,   141,   158,   161,   164,   174,   178,   179,
     182,   209,   210,   211,   212,   215,   216,   217,   220,   230,
     262,   265,   268,   271,   272,   275
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "HIERARCHY", "ROOT", "OFFSET", "CHANNELS", 
  "JOINT", "END_SITE", "MOTION", "FRAMES", "FRAME_TIME", "NUMBER", 
  "NUMBER_INT", "NAME", "DOF_NAME", "L_BRACK", "R_BRACK", "$accept", 
  "bvh_file", "heirarchy_sec", "root_node", "joint_body", "offset_spec", 
  "channel_spec", "channel_list", "channel", "joint_list", "end_site", 
  "joint_spec", "joint_name", "motion_sec", "no_frames", "frame_time", 
  "keyframe_list", "keyframe", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    18,    19,    20,    21,    22,    23,    24,    25,    25,
      26,    27,    27,    27,    27,    28,    28,    28,    29,    30,
      31,    32,    33,    34,    34,    35
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     2,     2,     3,     5,     4,     3,     2,     1,
       1,     2,     2,     1,     1,     2,     4,     0,     2,     2,
       4,     2,     2,     2,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       0,     0,     0,     0,     0,     3,     1,     0,     2,     0,
       0,     0,     0,     4,    21,     0,     0,     0,     0,    22,
      25,    20,    24,     0,     0,    17,    23,     0,     0,     0,
       0,     0,    14,    13,     0,     6,    10,     7,     9,    19,
       0,     5,    12,    11,    15,    18,     8,     0,    16
};

/* YYDEFGOTO[NTERM-NUM]. */
static const yysigned_char yydefgoto[] =
{
      -1,     2,     3,     5,    13,    18,    25,    37,    38,    31,
      44,    33,    34,     8,    11,    16,    21,    22
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -24
static const yysigned_char yypact[] =
{
       2,     3,     6,     0,    -3,   -24,   -24,     4,   -24,    -1,
       5,     1,     8,   -24,   -24,     7,     9,    10,    11,   -24,
     -24,     9,   -24,    12,    13,    -4,   -24,    15,    14,    16,
      17,    -7,    20,   -24,    -1,   -24,   -24,   -24,    14,   -24,
       8,   -24,    20,   -24,    20,   -24,   -24,    18,   -24
};

/* YYPGOTO[NTERM-NUM].  */
static const yysigned_char yypgoto[] =
{
     -24,   -24,   -24,   -24,   -18,   -20,   -24,   -15,   -24,   -24,
     -23,    -6,   -24,   -24,   -24,   -24,   -24,    19
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const unsigned char yytable[] =
{
      29,    30,    32,    29,    30,     1,     6,     4,    42,     7,
      41,     9,    15,    17,    10,    12,    45,    24,    14,    19,
      47,    20,    23,    46,    27,    43,    28,    35,    30,    36,
      39,     0,     0,    40,     0,    48,     0,     0,     0,     0,
      26
};

static const yysigned_char yycheck[] =
{
       7,     8,    25,     7,     8,     3,     0,     4,    31,     9,
      17,    14,    11,     5,    10,    16,    34,     6,    13,    12,
      40,    12,    12,    38,    12,    31,    13,    12,     8,    15,
      14,    -1,    -1,    16,    -1,    17,    -1,    -1,    -1,    -1,
      21
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,     3,    19,    20,     4,    21,     0,     9,    31,    14,
      10,    32,    16,    22,    13,    11,    33,     5,    23,    12,
      12,    34,    35,    12,     6,    24,    35,    12,    13,     7,
       8,    27,    28,    29,    30,    12,    15,    25,    26,    14,
      16,    17,    28,    29,    28,    22,    25,    23,    17
};

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrlab1

/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)         \
  Current.first_line   = Rhs[1].first_line;      \
  Current.first_column = Rhs[1].first_column;    \
  Current.last_line    = Rhs[N].last_line;       \
  Current.last_column  = Rhs[N].last_column;
#endif

/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (0)

# define YYDSYMPRINT(Args)			\
do {						\
  if (yydebug)					\
    yysymprint Args;				\
} while (0)

# define YYDSYMPRINTF(Title, Token, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr, 					\
                  Token, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (cinluded).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short *bottom, short *top)
#else
static void
yy_stack_print (bottom, top)
    short *bottom;
    short *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned int yylineno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %u), ",
             yyrule - 1, yylineno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname [yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname [yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YYDSYMPRINT(Args)
# define YYDSYMPRINTF(Title, Token, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#if YYMAXDEPTH == 0
# undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  register const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

#endif /* !YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    {
      YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
# ifdef YYPRINT
      YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
    }
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yydestruct (int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yytype, yyvaluep)
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  switch (yytype)
    {

      default:
        break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short	yyssa[YYINITDEPTH];
  short *yyss = yyssa;
  register short *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	short *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YYDSYMPRINTF ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */
  YYDPRINTF ((stderr, "Shifting token %s, ", yytname[yytoken]));

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 136 "c:\\Documents and Settings\\marco\\My Documents\\code\\Piavca\\src\\StdMotionImp\\bvhParser.ypp"
    {
  //std::cout << "successfully read bvh file\n";
  ;}
    break;

  case 3:
#line 141 "c:\\Documents and Settings\\marco\\My Documents\\code\\Piavca\\src\\StdMotionImp\\bvhParser.ypp"
    {
  rootPosTrackId = g_pCore->getJointId(_PSTR("Root Position"));
  rootOriTrackId = g_pCore->getJointId(_PSTR("Root Orientation"));
  //for (unsigned int i = 0; i < tracks.size(); i++)
  //{
  //  tracks[i].trackId = g_pCore->getJointId(tracks[i].name);
  //  if(tracks[i].trackId < 0)
  //     std::cout << "failed to find joint " << tracks[i].name << std::endl;
  //}
  currentTime = 0.0; 
  currentChannel = 0;		
  currentTrack = -1;
  currentRootOri = Quat();
  currentRootPos = Vec();
  ;}
    break;

  case 4:
#line 158 "c:\\Documents and Settings\\marco\\My Documents\\code\\Piavca\\src\\StdMotionImp\\bvhParser.ypp"
    {delete yyvsp[0].intList;;}
    break;

  case 5:
#line 161 "c:\\Documents and Settings\\marco\\My Documents\\code\\Piavca\\src\\StdMotionImp\\bvhParser.ypp"
    {yyval.intList = yyvsp[-1].intList;;}
    break;

  case 6:
#line 165 "c:\\Documents and Settings\\marco\\My Documents\\code\\Piavca\\src\\StdMotionImp\\bvhParser.ypp"
    {
     if(currentTrack >= 0)
       {
			//(*g_CurrentTrackIterator)->setOffset(Vec($2,$3,$4));
			//std::cout << Piavca::TStringToString(tracks[currentTrack].name) << " offset " << $2 << " " << $3 << " " << $4 << endl;
       }
   ;}
    break;

  case 7:
#line 175 "c:\\Documents and Settings\\marco\\My Documents\\code\\Piavca\\src\\StdMotionImp\\bvhParser.ypp"
    {currentChannel = 0;;}
    break;

  case 8:
#line 178 "c:\\Documents and Settings\\marco\\My Documents\\code\\Piavca\\src\\StdMotionImp\\bvhParser.ypp"
    {;}
    break;

  case 9:
#line 179 "c:\\Documents and Settings\\marco\\My Documents\\code\\Piavca\\src\\StdMotionImp\\bvhParser.ypp"
    {;}
    break;

  case 10:
#line 182 "c:\\Documents and Settings\\marco\\My Documents\\code\\Piavca\\src\\StdMotionImp\\bvhParser.ypp"
    {
				  if(currentTrack >= 0)
				    {
				      if(yyvsp[0].intVal >= 0)
						{
							tracks[currentTrack].channel[currentChannel] = yyvsp[0].intVal;
							tracks[currentTrack].negateChannel[currentChannel] = false;
						}
						else
						{
							if(yyvsp[0].intVal == -6)
								tracks[currentTrack].channel[currentChannel] = 0;
							else
								tracks[currentTrack].channel[currentChannel] = -yyvsp[0].intVal;
							tracks[currentTrack].negateChannel[currentChannel] = true;
						}	

				    }
				  else
				    {
				      rootChannel[currentChannel] = yyvsp[0].intVal;
				    }
				  currentChannel++;
				  
                                ;}
    break;

  case 11:
#line 209 "c:\\Documents and Settings\\marco\\My Documents\\code\\Piavca\\src\\StdMotionImp\\bvhParser.ypp"
    {yyval.intList = yyvsp[-1].intList; for(unsigned int i = 0; i < yyvsp[0].intList->size(); i++) yyval.intList->push_back((*yyvsp[0].intList)[i]); delete yyvsp[0].intList;;}
    break;

  case 12:
#line 210 "c:\\Documents and Settings\\marco\\My Documents\\code\\Piavca\\src\\StdMotionImp\\bvhParser.ypp"
    {yyval.intList = yyvsp[-1].intList;;}
    break;

  case 13:
#line 211 "c:\\Documents and Settings\\marco\\My Documents\\code\\Piavca\\src\\StdMotionImp\\bvhParser.ypp"
    {yyval.intList = yyvsp[0].intList;;}
    break;

  case 14:
#line 212 "c:\\Documents and Settings\\marco\\My Documents\\code\\Piavca\\src\\StdMotionImp\\bvhParser.ypp"
    {yyval.intList = new vector<int>();;}
    break;

  case 15:
#line 215 "c:\\Documents and Settings\\marco\\My Documents\\code\\Piavca\\src\\StdMotionImp\\bvhParser.ypp"
    {;}
    break;

  case 16:
#line 216 "c:\\Documents and Settings\\marco\\My Documents\\code\\Piavca\\src\\StdMotionImp\\bvhParser.ypp"
    {;}
    break;

  case 17:
#line 217 "c:\\Documents and Settings\\marco\\My Documents\\code\\Piavca\\src\\StdMotionImp\\bvhParser.ypp"
    {;}
    break;

  case 18:
#line 221 "c:\\Documents and Settings\\marco\\My Documents\\code\\Piavca\\src\\StdMotionImp\\bvhParser.ypp"
    {
				       if(g_pBasePosture != NULL && !g_pBasePosture->isNull(tracks[yyvsp[-1].intVal].trackId))
					 tracks[yyvsp[-1].intVal].multiplier = g_pBasePosture->getQuatValueAtTime(tracks[yyvsp[-1].intVal].trackId, 0.0).inverse();
				       yyvsp[0].intList->push_back(yyvsp[-1].intVal);
				       //std::cout << std::endl;
				       yyval.intList = yyvsp[0].intList;
                                     ;}
    break;

  case 19:
#line 230 "c:\\Documents and Settings\\marco\\My Documents\\code\\Piavca\\src\\StdMotionImp\\bvhParser.ypp"
    {	
  tracks.push_back(trackStruct());
  currentTrack = static_cast<int>(tracks.size())-1;
  tracks[currentTrack].channel[0] = -1;
  tracks[currentTrack].channel[1] = -1;
  tracks[currentTrack].channel[2] = -1;
  tracks[currentTrack].channel[3] = -1;
  tracks[currentTrack].channel[4] = -1;
  tracks[currentTrack].channel[5] = -1;
  tracks[currentTrack].channel[6] = -1;
  tracks[currentTrack].channel[7] = -1;
  tracks[currentTrack].channel[8] = -1;
  tracks[currentTrack].currentRot = Quat(1.0, 0.0, 0.0, 0.0);
  tracks[currentTrack].multiplier = Quat(1.0, 0.0, 0.0, 0.0);
  //tracks[currentTrack].coordSystem = Quat(1.0, 0.0, 0.0, 0.0);
  currentChannel = 0;
  tracks[currentTrack].name = StringToTString(yyvsp[0].name);
  tracks[currentTrack].trackId = g_pCore->getJointId(tracks[currentTrack].name);
  if(tracks[currentTrack].trackId >= 0)
      g_pMotion->addQuatTrack(tracks[currentTrack].trackId, Piavca::Quat());
  else
	{
		g_pCore->addJointNameSet(Piavca::StringVector(1, tracks[currentTrack].name));
		tracks[currentTrack].trackId = g_pCore->getJointId(tracks[currentTrack].name);
		g_pMotion->addQuatTrack(tracks[currentTrack].trackId, Piavca::Quat());
	}

  yyval.intVal = currentTrack;
  //fprintf(g_file, "\nadded joint %s\n", $2);
 ;}
    break;

  case 20:
#line 262 "c:\\Documents and Settings\\marco\\My Documents\\code\\Piavca\\src\\StdMotionImp\\bvhParser.ypp"
    {;}
    break;

  case 21:
#line 265 "c:\\Documents and Settings\\marco\\My Documents\\code\\Piavca\\src\\StdMotionImp\\bvhParser.ypp"
    {	g_noFrames = yyvsp[0].intVal;;}
    break;

  case 22:
#line 268 "c:\\Documents and Settings\\marco\\My Documents\\code\\Piavca\\src\\StdMotionImp\\bvhParser.ypp"
    {	frameTime = yyvsp[0].floatVal; ;}
    break;

  case 23:
#line 271 "c:\\Documents and Settings\\marco\\My Documents\\code\\Piavca\\src\\StdMotionImp\\bvhParser.ypp"
    {;}
    break;

  case 24:
#line 272 "c:\\Documents and Settings\\marco\\My Documents\\code\\Piavca\\src\\StdMotionImp\\bvhParser.ypp"
    {;}
    break;

  case 25:
#line 276 "c:\\Documents and Settings\\marco\\My Documents\\code\\Piavca\\src\\StdMotionImp\\bvhParser.ypp"
    {
			if(currentTrack < 0)
			{	
				if(currentChannel > 8 || rootChannel[currentChannel] < 0)
				{
					currentChannel = 0;
					if(g_pBasePosture != NULL && !g_pBasePosture->isNull(rootOriTrackId))
					    currentRootOri = g_pBasePosture->getQuatValueAtTime(rootOriTrackId, 0.0).inverse()*currentRootOri;
					if(g_pBasePosture != NULL && !g_pBasePosture->isNull(rootPosTrackId))
					    currentRootPos -= g_pBasePosture->getVecValueAtTime(rootPosTrackId, 0.0);
					if(!g_SkipFrame)
					{
						g_pMotion->setVecKeyframe(rootPosTrackId, currentTime - g_StartTime, currentRootPos);
						g_pMotion->setQuatKeyframe(rootOriTrackId, currentTime - g_StartTime, currentRootOri);
					};
					currentRootOri = Quat();
					currentRootPos = Vec();
					currentTrack = 0;
				}
			}
			else
			{
				if(currentChannel > 8 || tracks[currentTrack].channel[currentChannel] < 0)
				{
					currentChannel = 0;
					//std::cout << "reading track " << tracks[currentTrack].name << " " << tracks[currentTrack].trackId  << std::endl;
					//std::cout.flush();
					if(tracks[currentTrack].trackId >= 0)
					    {
					      //if(g_pBasePosture != NULL && !g_pBasePosture->isNull(tracks[currentTrack].trackId))
					      //    tracks[currentTrack].currentRot = g_pBasePosture->getQuatValueAtTime(tracks[currentTrack].trackId, 0.0).inverse()*tracks[currentTrack].currentRot;
						  Quat rot;
						  if(g_pBasePosture)
							rot = g_pBasePosture->getQuatValueAtTime(tracks[currentTrack].trackId, 0.0).inverse() * tracks[currentTrack].currentRot;
					      else
							rot = tracks[currentTrack].currentRot;
					      //Quat rot = tracks[currentTrack].coordSystem.inverse()*tracks[currentTrack].multiplier*tracks[currentTrack].currentRot*tracks[currentTrack].coordSystem;
					      if(!g_SkipFrame)
						      g_pMotion->setQuatKeyframe(tracks[currentTrack].trackId, currentTime - g_StartTime, rot);
					    }
					tracks[currentTrack].currentRot = Quat();
					if(++currentTrack >= static_cast<int>(tracks.size()))
					{
						currentTime += frameTime;
						currentTrack = -1;
						//fprintf(g_file, "\nframecountdown %i\n", g_noFrames);
						g_noFrames--;
						if(g_SkipFrame)
						{
							g_SkipFrame = false;
							g_StartTime = currentTime;
						}
					}
					//if(currentTrack == 5) currentTrack++;
				}
			}
		 if(currentTrack < 0)
	      {
			if(rootChannel[currentChannel] > 2 && rootChannel[currentChannel] < 6)
			{
				// the way the zaxis points is opposite to the normal bvh convention so flip it
				//currentRootPos[rootChannel[currentChannel] - 3] = rootChannel[currentChannel] == 3 ? -$1 : $1; 
			    currentRootPos += g_Axes[rootChannel[currentChannel] - 3]*yyvsp[0].floatVal;
			}
			else
			{
				currentRootOri = Quat(-Piavca::degToRad(yyvsp[0].floatVal), g_Axes[rootChannel[currentChannel]])*currentRootOri;
			}
	      }
	    else
	      {
		  // ignore position
		  if(tracks[currentTrack].channel[currentChannel] <= 2)
		      {
			  fprintf(g_file, " %s ", TStringToString(tracks[currentTrack].name).c_str());
			  float angle = yyvsp[0].floatVal;
			  float correction = 0.0;
			  if(g_bArmUp) correction = -90.0;
			  if(g_bArmDown) correction = 90.0;
			  //if(tracks[currentTrack].trackId == g_LeftArmTrack)
			  //    std::cout << "(" << tracks[currentTrack].channel[currentChannel] << "," << angle << ") ";
			  if(tracks[currentTrack].channel[currentChannel] == g_ArmUpAxis)
			      {
				  if(tracks[currentTrack].trackId == g_LeftArmTrack)
				      angle += correction;
				  if(tracks[currentTrack].trackId == g_RightArmTrack)
				      angle -= correction;
			      }
			  //tracks[currentTrack].currentRot = 
			  //    Quat(-Piavca::degToRad(angle), g_Axes[tracks[currentTrack].channel[currentChannel]])*tracks[currentTrack].currentRot;
			  float a = -Piavca::degToRad(angle);
			  if(tracks[currentTrack].negateChannel[currentChannel])
				a = -a;
			  //if(tracks[currentTrack].trackId == g_LeftArmTrack 
				//&& currentChannel == 2) a = - a;
			 if(g_ReverseOrder)
				tracks[currentTrack].currentRot = 
			        Quat(a, g_Axes[tracks[currentTrack].channel[currentChannel]])*tracks[currentTrack].currentRot;
			 else
			    tracks[currentTrack].currentRot = 
			        tracks[currentTrack].currentRot*Quat(a, g_Axes[tracks[currentTrack].channel[currentChannel]]);
			  if(g_bTest)
			      tracks[currentTrack].currentEuler[tracks[currentTrack].channel[currentChannel]] = yyvsp[0].floatVal;
		      }
	      }
		 currentChannel++;
		 fprintf(g_file, " %f ", yyvsp[0].floatVal);
	    
	  ;}
    break;


    }

/* Line 991 of yacc.c.  */
#line 1443 "c:\\Documents and Settings\\marco\\My Documents\\code\\Piavca\\src\\StdMotionImp\\bvhParser.tab.cpp"

  yyvsp -= yylen;
  yyssp -= yylen;


  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  YYSIZE_T yysize = 0;
	  int yytype = YYTRANSLATE (yychar);
	  char *yymsg;
	  int yyx, yycount;

	  yycount = 0;
	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  for (yyx = yyn < 0 ? -yyn : 0;
	       yyx < (int) (sizeof (yytname) / sizeof (char *)); yyx++)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      yysize += yystrlen (yytname[yyx]) + 15, yycount++;
	  yysize += yystrlen ("syntax error, unexpected ") + 1;
	  yysize += yystrlen (yytname[yytype]);
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "syntax error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[yytype]);

	      if (yycount < 5)
		{
		  yycount = 0;
		  for (yyx = yyn < 0 ? -yyn : 0;
		       yyx < (int) (sizeof (yytname) / sizeof (char *));
		       yyx++)
		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
		      {
			const char *yyq = ! yycount ? ", expecting " : " or ";
			yyp = yystpcpy (yyp, yyq);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yycount++;
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("syntax error; also virtual memory exhausted");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror ("syntax error");
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      /* Return failure if at end of input.  */
      if (yychar == YYEOF)
        {
	  /* Pop the error token.  */
          YYPOPSTACK;
	  /* Pop the rest of the stack.  */
	  while (yyss < yyssp)
	    {
	      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
	      yydestruct (yystos[*yyssp], yyvsp);
	      YYPOPSTACK;
	    }
	  YYABORT;
        }

      YYDSYMPRINTF ("Error: discarding", yytoken, &yylval, &yylloc);
      yydestruct (yytoken, &yylval);
      yychar = YYEMPTY;

    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab2;


/*----------------------------------------------------.
| yyerrlab1 -- error raised explicitly by an action.  |
`----------------------------------------------------*/
yyerrlab1:

  /* Suppress GCC warning that yyerrlab1 is unused when no action
     invokes YYERROR.  */
#if defined (__GNUC_MINOR__) && 2093 <= (__GNUC__ * 1000 + __GNUC_MINOR__)
  __attribute__ ((__unused__))
#endif


  goto yyerrlab2;


/*---------------------------------------------------------------.
| yyerrlab2 -- pop states until the error token can be shifted.  |
`---------------------------------------------------------------*/
yyerrlab2:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
      yydestruct (yystos[yystate], yyvsp);
      yyvsp--;
      yystate = *--yyssp;

      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;


  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*----------------------------------------------.
| yyoverflowlab -- parser overflow comes here.  |
`----------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 388 "c:\\Documents and Settings\\marco\\My Documents\\code\\Piavca\\src\\StdMotionImp\\bvhParser.ypp"



extern FILE *bvhin;

namespace Piavca
{

void readBvhMotion(Piavca::Core *core, MotionImp *mot, std::string fileName, int flags, Motion *basePosture, bool test)
{
	linenum = 0;

    g_bTest = test;
    g_pBasePosture = basePosture;

    g_LeftArmTrack = Piavca::Core::getCore()->getJointId(_PSTR("upper_left_arm"));
    g_RightArmTrack = Piavca::Core::getCore()->getJointId(_PSTR("upper_right_arm"));
    
    g_StartTime = 0;
    g_ArmUpAxis = 2;
    Vec xAxis = Vec::XAxis();
    if(flags & TRANS_NEG_X) xAxis = -xAxis;
    Vec yAxis = Vec::YAxis();
    if(flags & TRANS_NEG_Y) yAxis = -yAxis;
    Vec zAxis = Vec::ZAxis();
    if(flags & TRANS_NEG_Z) zAxis = -zAxis;
    if(flags & TRANS_SWAP_XZ)
	{
	    g_Axes[0] = zAxis;
	    g_Axes[1] = yAxis;
	    g_Axes[2] = xAxis;
	    //g_ArmUpAxis = 0;
	}
    else {if(flags & TRANS_SWAP_XY)
	{
	    g_Axes[0] = yAxis;
	    g_Axes[1] = xAxis;
	    g_Axes[2] = zAxis;
	    //g_ArmUpAxis = 2;
	}
    else {if(flags & TRANS_SWAP_YZ)
	{
	    g_Axes[0] = xAxis;
	    g_Axes[1] = zAxis;
	    g_Axes[2] = yAxis;
	    //g_ArmUpAxis = 1;
	}
    else {if(flags & TRANS_CYCLE_ZXY)
	{
	    g_Axes[0] = zAxis;
	    g_Axes[1] = xAxis;
	    g_Axes[2] = yAxis;
	    //g_ArmUpAxis = 1;
	}
    else {if(flags & TRANS_CYCLE_YZX)
	{
	    g_Axes[0] = yAxis;
	    g_Axes[1] = zAxis;
	    g_Axes[2] = xAxis;
	    //g_ArmUpAxis = 0;
	}
    else {
	    g_Axes[0] = xAxis;
	    g_Axes[1] = yAxis;
	    g_Axes[2] = zAxis;
	    //g_ArmUpAxis = 2;
    }}}}}

    if(flags & TRANS_ARM_UP)
		g_bArmUp = true;
    if(flags & TRANS_ARM_DOWN)
		g_bArmDown = true;
		
    if(flags & TRANS_REVERSE_ORDER)
		g_ReverseOrder = true;
	else
		g_ReverseOrder = false;
    if(flags & TRANS_SKIP_FIRST_FRAME)
		g_SkipFrame = true;
	else
		g_SkipFrame = false;

    //if((g_bArmUp && g_bArmDown))
    //throw Piavca::PiavcaException("error: motion correction specifies both raising and lowering arms");
    
    g_pCore = core;

    g_FileName = fileName;
    bvhin = fopen(fileName.c_str(),"r");
    g_file = fopen("bvhreaderOut.txt", "w");
    if (bvhin == NULL) {
	//throw FileNotFoundException(StringToTString(fileName));
	Piavca::Error(Piavca::tstring(_T("Could not open file ")) + StringToTString(fileName));
	return;
    }
    if (g_file == NULL) {
	//throw FileNotFoundException(_T("bvhreaderOut.txt"));
	Piavca::Error(Piavca::tstring(_T("Could not open file ")) + StringToTString(fileName));
	return;
    }
    mot->deleteAllTracks();
    g_pMotion = mot;
    
    currentTrack = -1;
    currentChannel = 0;
    currentTime = 0.0;
    
    
    rootChannel[0] = -1;
    rootChannel[1] = -1;
    rootChannel[2] = -1;
    rootChannel[3] = -1;
    rootChannel[4] = -1;
    rootChannel[5] = -1;
    rootChannel[6] = -1;
    rootChannel[7] = -1;
    rootChannel[8] = -1;
    g_pMotion->addVecTrack(g_pCore->getJointId(_PSTR("Root Position")), Piavca::Vec());
    g_pMotion->addQuatTrack(g_pCore->getJointId(_PSTR("Root Orientation")), Piavca::Quat());

    tracks.clear();
    
    do 
    {
	    yyparse();
	}
	while(!(feof(bvhin)));
    //std::cout << "finished parsing\n";
    // hmm... bit of a hack, because the parser never gets to the bit that finalises the last keyframe
    // of the last track do it explicitely
    if(tracks[currentTrack].trackId >= 0)
	{
	    if(g_pBasePosture != NULL && !g_pBasePosture->isNull(tracks[currentTrack].trackId))
		tracks[currentTrack].currentRot = g_pBasePosture->getQuatValueAtTime(tracks[currentTrack].trackId, 0.0).inverse()*tracks[currentTrack].currentRot;
	    g_pMotion->setQuatKeyframe(tracks[currentTrack].trackId, currentTime, tracks[currentTrack].currentRot);
	}
    //std::cout << "really finished\n";
    //if(g_bTest)
     // g_pMotion->setVecKeyframe(tracks[currentTrack].testTrack, currentTime, tracks[currentTrack].currentEuler);
    fflush(g_file);
    assert(g_noFrames == 1);
    fclose(g_file);
    fclose(bvhin);
}

};

int yyerror(char *s)
{
  fclose(g_file);
  std::cerr << "bvh parse error at line " << linenum << " token " << bvhtext << ": " << s << std::endl; 
  Piavca::Error(Piavca::tstring(_T("Error in file: ")) + StringToTString(g_FileName)+ _T(" ") + StringToTString(s));
  return 0;
}

