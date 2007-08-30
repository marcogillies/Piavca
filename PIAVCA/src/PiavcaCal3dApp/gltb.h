
/* 
 * A.Steed, 2005
 * This code has a long history. Originally I got it from Nate Robbin's 
 * web page, where it is still publically available without any copyright statement. 
 * The original comment that he left in the code are in the next comment block. 
 * I have since modified and extended it somewhat. In the spirit of the original code
 * this code is offered without any restrictions on its use.
 */

/* 
 *  Simple trackball-like motion adapted (ripped off) from projtex.c
 *  (written by David Yu and David Blythe).  See the SIGGRAPH '96
 *  Advanced OpenGL course notes.
 *
 *
 *  Usage:
 *  
 *  o  call gltbInit() in before any other gltb call
 *  o  call gltbReshape() from the reshape callback
 *  o  call gltbMatrix() to get the trackball matrix rotation
 *  o  call gltbStartMotion() to begin trackball movememt
 *  o  call gltbStopMotion() to stop trackball movememt
 *  o  call gltbMotion() from the motion callback
 *  o  call gltbAnimate(GL_TRUE) if you want the trackball to continue 
 *     spinning after the mouse button has been released
 *  o  call gltbAnimate(GL_FALSE) if you want the trackball to stop 
 *     spinning after the mouse button has been released
 *
 *  Typical setup:
 *
 *
    void
    init(void)
    {
      gltbInit(GLUT_MIDDLE_BUTTON);
      gltbAnimate(GL_TRUE);
      . . .
    }

    void
    reshape(int width, int height)
    {
      gltbReshape(width, height);
      . . .
    }

    void
    display(void)
    {
      glPushMatrix();

      gltbMatrix();
      . . . draw the scene . . .

      glPopMatrix();
    }

    void
    mouse(int button, int state, int x, int y)
    {
      gltbMouse(button, state, x, y);
      . . .
    }

    void
    motion(int x, int y)
    {
      gltbMotion(x, y);
      . . .
    }

    int
    main(int argc, char** argv)
    {
      . . .
      init();
      glutReshapeFunc(reshape);
      glutDisplayFunc(display);
      glutMouseFunc(mouse);
      glutMotionFunc(motion);
      . . .
    }
 *
 * */


/* functions */
void
gltbInit(GLuint button);

/* Call this function if your UP vector isn't the normal OpenGL up vector (+Y) */
void 
gltbConfigUp(float x, float y, float z);


/* Call this function if your RIGHT vector isn't the normal OpenGL right vector (+X) */
void 
gltbConfigRight(float x, float y, float z);


void
gltbMatrix(void);

void
gltbReshape(int width, int height);

void
gltbMouse(int button, int state, int x, int y);

void
gltbMotion(int x, int y);

void
gltbAnimate(GLboolean animate);
