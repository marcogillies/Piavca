/*
 *  Simple trackball-like motion adapted (ripped off) from projtex.c
 *  (written by David Yu and David Blythe).  See the SIGGRAPH '96
 *  Advanced OpenGL course notes.
 */


#include <math.h>
#include <stdio.h>
#include <assert.h>
#include <GL/glut.h>
#include "gltb.h"


#define GLTB_TIME_EPSILON  10


static GLuint    gltb_lasttime;
static GLfloat   gltb_lastposition[3];

static GLfloat   gltb_angle = 0.0;
static GLfloat   gltb_upaxis[3] = {0.0f, 1.0f, 0.0f};
static GLfloat   gltb_rightaxis[3] = {1.0f, 0.0f, 0.0f};
static GLfloat   gltb_orientmodel[4][4] = {1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
										   0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f};
static GLfloat   gltb_rotateaxis[3];
static GLfloat   gltb_transform[4][4] = {1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
										  0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f};

static GLuint    gltb_width;
static GLuint    gltb_height;

static GLint     gltb_button = -1;
static GLboolean gltb_tracking = GL_FALSE;
static GLboolean gltb_animate = GL_TRUE;


static void
_gltbPointToVector(int x, int y, int width, int height, float v[3])
{
  float d, a;

  /* project x, y onto a hemi-sphere centered within width, height. */
  v[0] = (2.0 * x - width) / width;
  v[1] = (height - 2.0 * y) / height;
  d = sqrt(v[0] * v[0] + v[1] * v[1]);
  v[2] = cos((3.14159265 / 2.0) * ((d < 1.0) ? d : 1.0));
  a = 1.0 / sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
  v[0] *= a;
  v[1] *= a;
  v[2] *= a;
}

static void
_gltbAnimate(void)
{
  glutPostRedisplay();
}

void
_gltbStartMotion(int x, int y, int button, int time)
{
  assert(gltb_button != -1);

  gltb_tracking = GL_TRUE;
  gltb_lasttime = time;
  _gltbPointToVector(x, y, gltb_width, gltb_height, gltb_lastposition);
}

void
_gltbStopMotion(int button, unsigned time)
{
  assert(gltb_button != -1);

  gltb_tracking = GL_FALSE;

  if (time - gltb_lasttime < GLTB_TIME_EPSILON && gltb_animate) {
      glutIdleFunc(_gltbAnimate);
  } else {
    gltb_angle = 0;
    if (gltb_animate)
      glutIdleFunc(0);
  }
}

#define crossProduct(a,b,c) \
	(a)[0] = (b)[1] * (c)[2] - (c)[1] * (b)[2]; \
	(a)[1] = (b)[2] * (c)[0] - (c)[2] * (b)[0]; \
	(a)[2] = (b)[0] * (c)[1] - (c)[0] * (b)[1];

static void
_gltbOrientModel()
{
	GLfloat toward[3];
	crossProduct(toward, gltb_rightaxis, gltb_upaxis);
	gltb_orientmodel[0][0] = gltb_rightaxis[0];
	gltb_orientmodel[1][0] = gltb_rightaxis[1];
	gltb_orientmodel[2][0] = gltb_rightaxis[2];

	gltb_orientmodel[0][1] = gltb_upaxis[0];
	gltb_orientmodel[1][1] = gltb_upaxis[1];
	gltb_orientmodel[2][1] = gltb_upaxis[2];

	gltb_orientmodel[0][2] = toward[0];
	gltb_orientmodel[1][2] = toward[1];
	gltb_orientmodel[2][2] = toward[2];
}

void
gltbAnimate(GLboolean animate)
{
  gltb_animate = animate;
}

void
gltbInit(GLuint button)
{
  gltb_button = button;
  gltb_angle = 0.0;
}

void 
gltbConfigUp( float x, float y, float z )
{
	gltb_upaxis[0] = x;
	gltb_upaxis[1] = y;
	gltb_upaxis[2] = z;
	_gltbOrientModel();
}

void 
gltbConfigRight( float x, float y, float z )
{
	gltb_rightaxis[0] = x;
	gltb_rightaxis[1] = y;
	gltb_rightaxis[2] = z;
	_gltbOrientModel();
}

void
gltbMatrix(void)
{
  assert(gltb_button != -1);

  glPushMatrix();
  glLoadIdentity();
  glRotatef(gltb_angle, gltb_rotateaxis[0], gltb_rotateaxis[1], gltb_rotateaxis[2]);
  glMultMatrixf((GLfloat*)gltb_transform);
  glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat*)gltb_transform);
  glPopMatrix();

  glMultMatrixf((GLfloat*)gltb_transform);
  glMultMatrixf((GLfloat*)gltb_orientmodel);
}

void
gltbReshape(int width, int height)
{
  assert(gltb_button != -1);

  gltb_width  = width;
  gltb_height = height;
}

void
gltbMouse(int button, int state, int x, int y)
{
  assert(gltb_button != -1);

  if (state == GLUT_DOWN && button == gltb_button)
    _gltbStartMotion(x, y, button, glutGet(GLUT_ELAPSED_TIME));
  else if (state == GLUT_UP && button == gltb_button)
    _gltbStopMotion(button, glutGet(GLUT_ELAPSED_TIME));
}

void
gltbMotion(int x, int y)
{
  GLfloat current_position[3], dx, dy, dz;

  assert(gltb_button != -1);

  if (gltb_tracking == GL_FALSE)
    return;

  _gltbPointToVector(x, y, gltb_width, gltb_height, current_position);

  /* calculate the angle to rotate by (directly proportional to the
     length of the mouse movement) */
  dx = current_position[0] - gltb_lastposition[0];
  dy = current_position[1] - gltb_lastposition[1];
  dz = current_position[2] - gltb_lastposition[2];
  gltb_angle = 90.0 * sqrt(dx * dx + dy * dy + dz * dz);

  /* calculate the axis of rotation (cross product) */
  gltb_rotateaxis[0] = gltb_lastposition[1] * current_position[2] - 
               gltb_lastposition[2] * current_position[1];
  gltb_rotateaxis[1] = gltb_lastposition[2] * current_position[0] - 
               gltb_lastposition[0] * current_position[2];
  gltb_rotateaxis[2] = gltb_lastposition[0] * current_position[1] - 
               gltb_lastposition[1] * current_position[0];

  /* XXX - constrain motion */
  gltb_rotateaxis[2] = 0;

  /* reset for next time */
  gltb_lasttime = glutGet(GLUT_ELAPSED_TIME);
  gltb_lastposition[0] = current_position[0];
  gltb_lastposition[1] = current_position[1];
  gltb_lastposition[2] = current_position[2];

  /* remember to draw new position */
  glutPostRedisplay();
}
