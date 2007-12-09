
from OpenGL.GL import *
from OpenGL.GLUT import *

from math import *


GLTB_TIME_EPSILON = 10
gltb_lasttime = 0
gltb_lastposition =(0.0, 0.0, 0.0)
gltb_angle = 0.0
gltb_upaxis = (0.0, 1.0, 0.0)
gltb_rightaxis = (1.0, 0.0, 0.0)
gltb_orientmodel = (1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0)
gltb_rotateaxis = (0.0, 0.0, 0.0)
gltb_translation = (0.0, 0.0, 0.0)
gltb_transform = (1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0)
gltb_camera_pos = [0.0, 1.0, 0.0]
gltb_width = 0
gltb_height = 0
gltb_tracking = GL_FALSE
gltb_animate = GL_TRUE

def gltbInit():
    global gltb_angle
    gltb_angle = 0.0

def _gltbPointToVector(x, y, width, height):
    # project x, y onto a hemi-sphere centered within width, height.
    width = max(width, 200)
    height = max(height, 100)
    i = (2.0 * x - width) / width
    j = (height - 2.0 * y) / height
    d = sqrt(i * i + j * j)
    if (d>1.0):
        d = 1.0
    k = cos((3.14159265 / 2.0) * d)
    a = 1.0 / sqrt(i * i + j * j + k * k)
    i *= a
    j *= a
    k *= a
    return (i,j,k)

def _gltbAnimate():
    pass


def _gltbStartMotion(x, y, time):
    global gltb_tracking, gltb_lasttime, gltb_width, gltb_height, gltb_lastposition
    #print "start motion"
    gltb_tracking = GL_TRUE
    gltb_lasttime = time
    gltb_lastposition = _gltbPointToVector(x, y, gltb_width, gltb_height)

def _gltbStopMotion( time):
    global gltb_tracking, gltb_lasttime, gltb_animate, gltb_angle

    gltb_tracking = GL_FALSE

    if time - gltb_lasttime < GLTB_TIME_EPSILON and gltb_animate:
#        glutIdleFunc(_gltbAnimate)
        pass
    else:
        gltb_angle = 0

    if gltb_animate:
#       glutIdleFunc(0)
        pass

def crossProduct(b,c):
    i = b[1] * c[2] - c[1] * b[2]
    j = b[2] * c[0] - c[2] * b[0]
    k = b[0] * c[1] - c[0] * b[1]
    return (i,j,k)

def _gltbOrientModel():
    global gltb_orientmodel, gltb_rightaxis, gltb_upaxis
    toward = crossProduct(gltb_rightaxis, gltb_upaxis)
    #gltb_orientmodel = (gltb_rightaxis[0], gltb_rightaxis[1], gltb_rightaxis[2], 0, gltb_upaxis[0], gltb_upaxis[1], gltb_upaxis[2], 0, toward[0], toward[1], toward[2], 1)
    gltb_orientmodel = (gltb_rightaxis[0], gltb_upaxis[0], toward[0], 0, gltb_rightaxis[1], gltb_upaxis[1], toward[1], 0, gltb_rightaxis[2], gltb_upaxis[2], toward[2], 0, 0,0,0,1)

def gltbAnimate(animate):
    global gltb_animate
    gltb_animate = animate

def gltbConfigUp( x, y, z ):
    global gltb_upaxis
    gltb_upaxis = (x,y,z)
    _gltbOrientModel()

def gltbConfigRight( x, y, z ):
    global gltb_rightaxis
    gltb_rightaxis = (x,y,z)
    _gltbOrientModel()

def gltbMatrix():
    global gltb_transform, gltb_angle, gltb_rotateaxis, gltb_lastposition, gltb_orientmodel, gltb_camera_pos
	
    #print gltb_camera_pos
	
    glPushMatrix()
    glLoadIdentity()
    glRotatef(gltb_angle, gltb_rotateaxis[0], gltb_rotateaxis[1], gltb_rotateaxis[2])
    glTranslatef(gltb_translation[0], gltb_translation[2], gltb_translation[1])
    glMultMatrixf(gltb_transform)
    gltb_transform = glGetFloatv(GL_MODELVIEW_MATRIX)
    glPopMatrix()
    glMultMatrixf(gltb_transform)
    glMultMatrixf(gltb_orientmodel)


def gltbReshape(width, height):
    global gltb_width, gltb_height
    gltb_width  = width
    gltb_height = height

def gltbMouseDown(x, y):
    #print "mouse down"
    _gltbStartMotion(x, y, glutGet(GLUT_ELAPSED_TIME))

def gltbMouseUp():
    _gltbStopMotion(glutGet(GLUT_ELAPSED_TIME))

def gltbMotionRotateAboutFocus(x, y):
    global gltb_rotateaxis, gltb_width, gltb_height, gltb_lastposition, gltb_lasttime, gltb_angle

    if gltb_tracking == GL_FALSE:
        return

    current_position = _gltbPointToVector(x, y, gltb_width, gltb_height)

    # calculate the angle to rotate by (directly proportional to the
    #length of the mouse movement) 
    dx = current_position[0] - gltb_lastposition[0]
    dy = current_position[1] - gltb_lastposition[1]
    dz = current_position[2] - gltb_lastposition[2]
    gltb_angle = 90.0 * sqrt(dx * dx + dy * dy + dz * dz)

    #calculate the axis of rotation (cross product) 
    gltb_rotateaxis = (gltb_lastposition[1] * current_position[2] - gltb_lastposition[2] * current_position[1], gltb_lastposition[2] * current_position[0] - gltb_lastposition[0] * current_position[2], 0)

    #reset for next time
    gltb_lasttime = glutGet(GLUT_ELAPSED_TIME)
    gltb_lastposition = current_position

def gltbInOutMotion(x, y):
    global gltb_rotateaxis, gltb_width, gltb_height, gltb_lastposition, gltb_lasttime, gltb_angle, gltb_translation

    if gltb_tracking == GL_FALSE:
        return

    current_position = _gltbPointToVector(x, y, gltb_width, gltb_height)

    # calculate the angle to rotate by (directly proportional to the
    #length of the mouse movement) 
    dx = current_position[0] - gltb_lastposition[0]
    dy = current_position[1] - gltb_lastposition[1]
    dz = current_position[2] - gltb_lastposition[2]
    
    gltb_translation = (0, dy, 0)
    #print gltb_translation

    #reset for next time
    gltb_lasttime = glutGet(GLUT_ELAPSED_TIME)
    gltb_lastposition = current_position

