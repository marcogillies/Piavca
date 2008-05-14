typedef union {
  int intVal;
  float floatVal;
  char * name;
  std::vector<int> *intList;
} YYSTYPE;
#define	HIERARCHY	257
#define	ROOT	258
#define	OFFSET	259
#define	CHANNELS	260
#define	JOINT	261
#define	END_SITE	262
#define	MOTION	263
#define	FRAMES	264
#define	FRAME_TIME	265
#define	NUMBER	266
#define	NUMBER_INT	267
#define	NAME	268
#define	DOF_NAME	269
#define	L_BRACK	270
#define	R_BRACK	271


extern YYSTYPE bvhlval;
