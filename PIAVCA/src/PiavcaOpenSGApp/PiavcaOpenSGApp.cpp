// File : 01firstapp.cpp

//what follows here is the smallest OpenSG programm possible
//most things used here are explained now or on the next few pages, so don't 
//worry if not everything is clear right at the beginning...

//#define OSG_WITH_GLUT

//Some needed include files - these will become more, believe me ;)
#include <OpenSG/OSGConfig.h>
#include <OpenSG/OSGGLUT.h>
#include <OpenSG/OSGSimpleGeometry.h>
#include <OpenSG/OSGTransform.h>
//#include <OpenSG/OSGGLUTWindowBase.h>
#include <OpenSG/OSGGLUTWindow.h>
#include <OpenSG/OSGPointLight.h>
#include <OpenSG/OSGSimpleSceneManager.h>

#include <GL/glut.h>

#include "PiavcaPythonInterface/PiavcaPythonApp.h"
#include "PiavcaOpenSGImp/PiavcaOpenSGCore.h"
#include "PiavcaOpenSGImp/AvatarOpenSGImp.h"


//In most cases it is useful to add this line, otherwise every OpenSG command
//must be preceeded by an extra OSG::
OSG_USING_NAMESPACE




//The SimpleSceneManager is a useful class which helps us to 
//manage simple configurations. It will be discussed in detail later on
SimpleSceneManager *mgr;
TransformPtr transCore;
Piavca::PiavcaOpenSGCore *core;


NodePtr scene;

//we have a forward declaration here, just to have a better order 
//of codepieces
int setupGLUT( int *argc, char *argv[] );

// load in joint names and expressions
void loadJointNames(std::string filename, bool expressions);

int main(int argc, char **argv)
{
    std::string path = "";
#ifndef WIN32
  for(int i = 0; i < argc-1; i++)
  {
  	if(std::string(argv[i]) == "-path")
  	{
  		path = std::string(argv[i+1]) + "/";
  		chdir(path.c_str());
  		argc = argc - 2;
  		for ( /*nothing*/; i < argc; i++)
  			argv[i] = argv[i+2];
  		break;
  	}
  }	
#endif
    
    // Init the OpenSG subsystem
    osgInit(argc,argv);
    
    core = new Piavca::PiavcaOpenSGCore();
    loadJointNames("JointNames.txt", false);
    loadJointNames("ExpressionNames.txt", true);
    
    // We create a GLUT Window (that is almost the same for most applications)
    int winid = setupGLUT(&argc, argv);
    GLUTWindowPtr gwin= GLUTWindow::create();
    gwin->setId(winid);
    gwin->init();

	// This will be our whole scene for now : an incredible torus
    NodePtr torus = makeTorus(.5, 2, 16, 16);
    NodePtr box = makeBox(150,38,177, 2, 2, 2);
    NodePtr transNode = Node::create();
        
	transCore = Transform::create();
	Matrix m;
	        
	// now provide some data...
	        
	// no rotation at the beginning
	m.setIdentity();
	        
	// set the core to the matrix we created
	beginEditCP(transCore);
	    transCore->setMatrix(m);
	endEditCP(transCore);

	//geoNode = geoTest();
	        
	// now "insert" the core into the node
	beginEditCP(transNode);
	    transNode->setCore(transCore);
	    // add the torus as a child to
	    // the transformation node
	    transNode->addChild(core->getNode());
	    //transNode->addChild(box);
	endEditCP(transNode);
	        
	NodePtr root = Node::create();
	PointLightPtr pLight = PointLight::create();
    NodePtr pLightTransformNode = Node::create();
    TransformPtr pLightTransform = Transform::create();
    
    NodePtr pLightNode = Node::create();
    beginEditCP(pLightNode);
        pLightNode->setCore(Group::create());
    endEditCP(pLightNode);
    
    Matrix Lightmat;
    Lightmat.setIdentity();
    Lightmat.setTranslate(50,-250,100);
    
    beginEditCP(pLightTransform);
        pLightTransform->setMatrix(Lightmat);
    endEditCP(pLightTransform);
    
    beginEditCP(pLightTransformNode);
        pLightTransformNode->setCore(pLightTransform);
        pLightTransformNode->addChild(pLightNode);
    endEditCP(pLightTransformNode);

    beginEditCP(pLight);
        pLight->setPosition(Pnt3f(0,0,0));
    
        //Attenuation parameters
        pLight->setConstantAttenuation(1);
        pLight->setLinearAttenuation(0);
        pLight->setQuadraticAttenuation(0);
        
        //color information
        pLight->setDiffuse(Color4f(1,1,1,1));
        pLight->setAmbient(Color4f(0.2,0.2,0.2,1));
        pLight->setSpecular(Color4f(0.2,0.2,0.2,0.2));
        
        //set the beacon
        pLight->setBeacon(pLightNode);
    endEditCP  (pLight);
    
    beginEditCP(root);
        root->setCore(pLight);
        root->addChild(transNode);
        root->addChild(pLightTransformNode);
    endEditCP(root);
	        
	// "declare" the transformation as root
	scene = root;  

    // Create and setup our little friend - the SSM
    mgr = new SimpleSceneManager;
    mgr->setWindow(gwin);
    mgr->setRoot(scene);
    mgr->setHeadlight(false);
    
    Piavca::InitPiavcaPython(Piavca::Core::getCore(), _T("init_piavca"));
    
    mgr->showAll();
    
    Navigator * nav = mgr->getNavigator();
    nav->setFrom(nav->getFrom()+Vec3f(0,200,90));
    nav->setFrom(Vec3f(0, -200, 90));
    nav->setAt(Vec3f(0, 6, 90));
    nav->setUp(Vec3f(0, 0, 1));
    
    // Give Control to the GLUT Main Loop
    glutMainLoop();
     
    Piavca::EndPiavcaPython(Piavca::Core::getCore());

    return 0;
}

void loadJointNames(std::string filename, bool expressions)
{
  //std::string jointsFilename = path + "JointNames.txt";
  std::ifstream file(filename.c_str(), std::ios::in );
  if(!file)
  {
	  Piavca::Error("Failed to open joint/expression names file '" 
	  	+ filename + "'\n");
	  return;
  }

  Piavca::StringVector jointVec;
  std::string jointName;
  while(true)
  {
	// read the next model configuration line
    std::string strBuffer;
    std::getline(file, strBuffer);

    // stop if we reached the end of file
    if(file.eof()) 
	{
		if(expressions)
			Piavca::Core::getCore()->addExpressionNameSet(jointVec);
		else
			Piavca::Core::getCore()->addJointNameSet(jointVec);
		jointVec.clear();
		break;
	}

    // check if an error happend while reading from the file
    if(!file)
    {
    	if (expressions)
			Piavca::Error("Error while reading from the expression names file");
		else
			Piavca::Error("Error while reading from the joint names file");
		return;
    }

	// find the first non-whitespace character
    std::string::size_type pos=0, new_pos;

	while (true)
	{
		pos = strBuffer.find_first_not_of(" \t", pos);

		// check for empty lines and comments
		if((pos == std::string::npos) || (strBuffer[pos] == '\n') 
			|| (strBuffer[pos] == '\r') || (strBuffer[pos] == 0)
			|| strBuffer[pos] == '#') 
		{
			if(!jointVec.empty())
			{
				if(expressions)
					Piavca::Core::getCore()->addExpressionNameSet(jointVec);
				else
					Piavca::Core::getCore()->addJointNameSet(jointVec);
				jointVec.clear();
			}
			break;
		}

		
		if(strBuffer[pos] == '\"')
		{
			pos++;
			new_pos = strBuffer.find_first_of("\"", pos);
			if(new_pos == std::string::npos)
				Piavca::Error("Unmatched quotes in joint names file");
			jointName = strBuffer.substr(pos, new_pos - pos);
			pos = new_pos+1;
		}
		else
		{
			new_pos = strBuffer.find_first_of(" =\t\n\r", pos);
			jointName = strBuffer.substr(pos, new_pos - pos);
			pos = new_pos;
		}
		jointVec.push_back(StringToTString(jointName));
		std::cout << jointName << "; ";
		
	}
  };
  std::cout << std::endl;

}

// react to size changes
void reshape(int w, int h)
{
    mgr->resize(w, h);
    glutPostRedisplay();
}

// just redraw our scene if this GLUT callback is invoked
void display(void)
{
	static float prevTime = Piavca::Core::getCore()->getTime();
	static int framecount = 0;
	static float updateTime = 0;
	static float prerenderTime = 0;
	static float renderTime = 0;
	
	float time1 = Piavca::Core::getCore()->getTime();
	Piavca::Core::getCore()->timeStep();
	float time2 = Piavca::Core::getCore()->getTime();
	updateTime += time2 - time1;
	Piavca::Core::getCore()->prerender();
	float time3 = Piavca::Core::getCore()->getTime();
	prerenderTime += time3 - time2;

    mgr->redraw();
	float time4 = Piavca::Core::getCore()->getTime();
	renderTime += time4 - time3;
	
	framecount ++;
	float time = Piavca::Core::getCore()->getTime();
	if((time - prevTime) > 10.0)
	{
		std::cout << "framerate " << framecount/(time - prevTime) 
			<< " update time " << updateTime/framecount
			<< " prerender time " << prerenderTime/framecount  
			<< " render time " << renderTime/framecount << std::endl;
		framecount = 0;
		updateTime = 0.0;
		prerenderTime = 0.0;
		renderTime = 0.0;
		prevTime = time;
	}
}

// react to mouse motions with pressed buttons
void motion(int x, int y)
{
    mgr->mouseMove(x, y);
    glutPostRedisplay();
}

// react to mouse button presses
void mouse(int button, int state, int x, int y)
{
    if (state)
        mgr->mouseButtonRelease(button, x, y);
    else
        mgr->mouseButtonPress(button, x, y);
        
    glutPostRedisplay();
}

//The GLUT subsystem is set up here. This is very similar to other GLUT 
//applications. If you have worked with GLUT before, you may have the 
//feeling of meeting old friends again, if you have not used GLUT before 
//that is no problem. GLUT will be introduced briefly on the next section

int setupGLUT(int *argc, char *argv[])
{
    glutInit(argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    
    int winid = glutCreateWindow("Piavca OpenSG Example Application");
    
    // register the GLUT callback functions
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutReshapeFunc(reshape);
    glutMotionFunc(motion);
    glutMouseFunc(mouse);

    return winid;
}
