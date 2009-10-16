#include "testApp.h"

#include "PiavcaAPI/Piavca.h"

GLfloat lightOnePosition[] = {40.0, 40, 100.0, 0.0};
GLfloat lightOneColor[] = {0.99, 0.99, 0.99, 1.0};

GLfloat lightTwoPosition[] = {-40.0, 40, 100.0, 0.0};
GLfloat lightTwoColor[] = {0.99, 0.99, 0.99, 1.0};

//--------------------------------------------------------------
void testApp::setup(){

	ofBackground(255,255,255);
	
	ofSetVerticalSync(true);
	
    //some model / light stuff
    glEnable (GL_DEPTH_TEST);
    glShadeModel (GL_SMOOTH);
	
    /* initialize lighting */
    glLightfv (GL_LIGHT0, GL_POSITION, lightOnePosition);
    glLightfv (GL_LIGHT0, GL_DIFFUSE, lightOneColor);
    glEnable (GL_LIGHT0);
    glLightfv (GL_LIGHT1, GL_POSITION, lightTwoPosition);
    glLightfv (GL_LIGHT1, GL_DIFFUSE, lightTwoColor);
    glEnable (GL_LIGHT1);
    glEnable (GL_LIGHTING);
    glColorMaterial (GL_FRONT_AND_BACK, GL_DIFFUSE);
    glEnable (GL_COLOR_MATERIAL);
	
#ifndef _MSC_VER 
	chdir(ofToDataPath("Bill").c_str());
#else
	_chdir(ofToDataPath("Bill").c_str());
#endif
	Piavca::Core::init();
	Piavca::Core::getCore()->setHardware(false);
	
	char *cwd = new char[1024];
	getcwd(cwd, 1024);
	std::cout << cwd << std::endl;
	
	Piavca::Avatar *av = new Piavca::Avatar("bill");
	Piavca::Motion *mot = Piavca::Core::getCore()->getMotion("actions");
	av->playMotion(new Piavca::LoopMotion(new Piavca::Reposition(mot)));
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

	
    //lets tumble the world with the mouse
    glPushMatrix();
	
	//draw in middle of the screen
	glTranslatef(ofGetWidth()/2,ofGetHeight()/2,0);
	//tumble according to mouse
	glRotatef(-mouseY,1,0,0);
	glRotatef(mouseX,0,1,0);
	
	ofSetColor(255, 255, 255, 255);
	
	Piavca::Core::getCore()->timeStep();
	
	Piavca::Core::getCore()->prerender();
	
	Piavca::Core::getCore()->render();
	
    glPopMatrix();
	
    ofSetColor(0x000000);
    ofDrawBitmapString("fps: "+ofToString(ofGetFrameRate(), 2), 10, 15);
}


//--------------------------------------------------------------
void testApp::keyPressed  (int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

