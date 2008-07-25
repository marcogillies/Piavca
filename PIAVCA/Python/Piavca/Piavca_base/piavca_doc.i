%feature("docstring") Piavca::Avatar " 

The actual avatar class.     
       
This class is the main component of the Piavca API and represents a character for skeletal animation. It has fairly basic simple functionality, just altering root position and orientation, loading and playing motion and directly altering joint orientations It is an interfaces class that forwards all its method calls to an implementation class which is an platform specific class that does all the work. The class is structured as a bridge pattern from Design Patterns. An interface class contains a pointer to an implementation object and forwards all method calls to it. The implementation object is in fact of a platform specific sub-type of the implementation class. The joints themselves are not exposed to the client and are accessed via integer IDs. These IDs are unique for a given joint across all avatars and motions. any actions on joints area achieved by passing the ID to an appropriate method      see also: Avatar.h";

%feature("docstring") Piavca::Avatar::setFacialExpressionWeight "
bool Piavca::Avatar::setFacialExpressionWeight(int id, float weight, float timeInterval=0.5)
         
set the weight of a facial expression (used in the blend)         
         
        ";
%feature("docstring") Piavca::Avatar::getFacialExpressionWeight "
float Piavca::Avatar::getFacialExpressionWeight(int id)
         
get the weight of an expression         
         
        ";
%feature("docstring") Piavca::Avatar::clearFacialExpressionWeights "
void Piavca::Avatar::clearFacialExpressionWeights()
         
set all expression weights to zero         
         
        ";
%feature("docstring") Piavca::Avatar::beginExpression "
int Piavca::Avatar::beginExpression() const 
         
the ID of the first joint that is present in the avatar (the ordering is arbitrary)         
         
        ";
%feature("docstring") Piavca::Avatar::endExpression "
int Avatar::endExpression() const 
         
the last joint + 1         
         
        ";
%feature("docstring") Piavca::Avatar::nextExpression "
int Avatar::nextExpression(int &expressionId)
         
given a joint ID this returns the next joint ID that is present in the avatar         
         
        ";
%feature("docstring") Piavca::Avatar::isExpressionNull "
bool Piavca::Avatar::isExpressionNull(int expressionId) const 
         
whether the joint is present in the avatar         
         
        ";
%feature("docstring") Piavca::Avatar::setRootPosition "
void Piavca::Avatar::setRootPosition(const Vec &Position)
         
        
         
get or set the root position and orientation of the avatar         ";
%feature("docstring") Piavca::Avatar::getRootPosition "
Vec Piavca::Avatar::getRootPosition()
         
        
         
        ";
%feature("docstring") Piavca::Avatar::setRootOrientation "
void Piavca::Avatar::setRootOrientation(const Quat &Orientation)
         
        
         
        ";
%feature("docstring") Piavca::Avatar::setRootAngle "
void Piavca::Avatar::setRootAngle(float angle)
         
set the root orientation from an angle in radians (assumed to be about the verticle)         
         
        ";
%feature("docstring") Piavca::Avatar::setRootAngleDeg "
void Piavca::Avatar::setRootAngleDeg(float angle)
         
set the root orientation from an angle in degrees (assumed to be about the verticle)         
         
        ";
%feature("docstring") Piavca::Avatar::getRootOrientation "
Quat Piavca::Avatar::getRootOrientation()
         
        
         
        ";
%feature("docstring") Piavca::Avatar::loadMotion "
void Avatar::loadMotion(Motion *motion)
         
load motion as a motion object         
         
The start time allows the client to specify a time in world time for the motion to start running         ";
%feature("docstring") Piavca::Avatar::unloadMotion "
void Avatar::unloadMotion()
         
        
         
        ";
%feature("docstring") Piavca::Avatar::getMotion "
Motion* Piavca::Avatar::getMotion()
         
get a pointer to the motion so it can be manipulated by the client         
         
        ";
%feature("docstring") Piavca::Avatar::getMotion "
const Motion* Piavca::Avatar::getMotion() const 
         
get a const pointer to the motion so it can be seen by the client         
         
        ";
%feature("docstring") Piavca::Avatar::playMotion "
void Avatar::playMotion()
         
starts playing the motion at the current time         
         
        ";
%feature("docstring") Piavca::Avatar::playMotion "
void Avatar::playMotion(float time)
         
starts the motion playing at time         
         
        ";
%feature("docstring") Piavca::Avatar::playMotion "
void Avatar::playMotion(Motion *m, float time)
         
        
         
        ";
%feature("docstring") Piavca::Avatar::playMotion "
void Avatar::playMotion(Motion *m)
         
        
         
        ";
%feature("docstring") Piavca::Avatar::stopMotion "
void Piavca::Avatar::stopMotion()
         
stops the motion playing         
         
        ";
%feature("docstring") Piavca::Avatar::restartMotion "
void Piavca::Avatar::restartMotion()
         
restarts the motion without changing the start time         
         
        ";
%feature("docstring") Piavca::Avatar::setMotionStartTime "
void Avatar::setMotionStartTime(float startTime)
         
changes the start time of the motion         
         
        ";
%feature("docstring") Piavca::Avatar::getMotionStartTime "
float Avatar::getMotionStartTime()
         
get the time when the current motion starts         
         
        ";
%feature("docstring") Piavca::Avatar::getMotionEndTime "
float Avatar::getMotionEndTime()
         
get the time when the current motion should end         
         
        ";
%feature("docstring") Piavca::Avatar::showMotionAtTime "
void Avatar::showMotionAtTime(float time)
         
displays the motion on the avatar at time         
         
        ";
%feature("docstring") Piavca::Avatar::loadFacialMotion "
void Avatar::loadFacialMotion(Motion *motion)
         
load a facial motion as a motion object         
         
The start time allows the client to specify a time in world time for the motion to start running         ";
%feature("docstring") Piavca::Avatar::unloadFacialMotion "
void Avatar::unloadFacialMotion()
         
        
         
        ";
%feature("docstring") Piavca::Avatar::getFacialMotion "
Motion* Piavca::Avatar::getFacialMotion()
         
get a pointer to the motion so it can be manipulated by the client         
         
        ";
%feature("docstring") Piavca::Avatar::getFacialMotion "
const Motion* Piavca::Avatar::getFacialMotion() const 
         
get a const pointer to the motion so it can be seen by the client         
         
        ";
%feature("docstring") Piavca::Avatar::playFacialMotion "
void Avatar::playFacialMotion()
         
starts playing the motion at the current time         
         
        ";
%feature("docstring") Piavca::Avatar::playFacialMotion "
void Avatar::playFacialMotion(float time)
         
starts the motion playing at time         
         
        ";
%feature("docstring") Piavca::Avatar::playFacialMotion "
void Avatar::playFacialMotion(Motion *m, float time)
         
starts the motion playing at time         
         
        ";
%feature("docstring") Piavca::Avatar::playFacialMotion "
void Avatar::playFacialMotion(Motion *m)
         
starts playing the motion at the current time         
         
        ";
%feature("docstring") Piavca::Avatar::stopFacialMotion "
void Piavca::Avatar::stopFacialMotion()
         
stops the motion playing         
         
        ";
%feature("docstring") Piavca::Avatar::restartFacialMotion "
void Piavca::Avatar::restartFacialMotion()
         
restarts the motion without changing the start time         
         
        ";
%feature("docstring") Piavca::Avatar::setFacialMotionStartTime "
void Avatar::setFacialMotionStartTime(float startTime)
         
changes the start time of the motion         
         
        ";
%feature("docstring") Piavca::Avatar::getFacialMotionStartTime "
float Avatar::getFacialMotionStartTime()
         
get the time when the current motion starts         
         
        ";
%feature("docstring") Piavca::Avatar::getFacialMotionEndTime "
float Avatar::getFacialMotionEndTime()
         
get the time when the current motion should end         
         
        ";
%feature("docstring") Piavca::Avatar::showFacialMotionAtTime "
void Avatar::showFacialMotionAtTime(float time)
         
displays the motion on the avatar at time         
         
        ";
%feature("docstring") Piavca::Avatar::loadScaleMotion "
void Avatar::loadScaleMotion(Motion *motion)
         
load a scale motion as a motion object         
         
The start time allows the client to specify a time in world time for the motion to start running         ";
%feature("docstring") Piavca::Avatar::unloadScaleMotion "
void Avatar::unloadScaleMotion()
         
        
         
        ";
%feature("docstring") Piavca::Avatar::getScaleMotion "
Motion* Piavca::Avatar::getScaleMotion()
         
get a pointer to the motion so it can be manipulated by the client         
         
        ";
%feature("docstring") Piavca::Avatar::getScaleMotion "
const Motion* Piavca::Avatar::getScaleMotion() const 
         
get a const pointer to the motion so it can be seen by the client         
         
        ";
%feature("docstring") Piavca::Avatar::playScaleMotion "
void Avatar::playScaleMotion()
         
starts playing the motion at the current time         
         
        ";
%feature("docstring") Piavca::Avatar::playScaleMotion "
void Avatar::playScaleMotion(float time)
         
starts the motion playing at time         
         
        ";
%feature("docstring") Piavca::Avatar::playScaleMotion "
void Avatar::playScaleMotion(Motion *m, float time)
         
starts the motion playing at time         
         
        ";
%feature("docstring") Piavca::Avatar::playScaleMotion "
void Avatar::playScaleMotion(Motion *m)
         
starts playing the motion at the current time         
         
        ";
%feature("docstring") Piavca::Avatar::stopScaleMotion "
void Piavca::Avatar::stopScaleMotion()
         
stops the motion playing         
         
        ";
%feature("docstring") Piavca::Avatar::restartScaleMotion "
void Piavca::Avatar::restartScaleMotion()
         
restarts the motion without changing the start time         
         
        ";
%feature("docstring") Piavca::Avatar::setScaleMotionStartTime "
void Avatar::setScaleMotionStartTime(float startTime)
         
changes the start time of the motion         
         
        ";
%feature("docstring") Piavca::Avatar::getScaleMotionStartTime "
float Avatar::getScaleMotionStartTime()
         
get the time when the current motion starts         
         
        ";
%feature("docstring") Piavca::Avatar::getScaleMotionEndTime "
float Avatar::getScaleMotionEndTime()
         
get the time when the current motion should end         
         
        ";
%feature("docstring") Piavca::Avatar::showScaleMotionAtTime "
void Avatar::showScaleMotionAtTime(float time)
         
displays the motion on the avatar at time         
         
        ";
%feature("docstring") Piavca::Avatar::registerCallback "
void Avatar::registerCallback(AvatarTimeCallback *cb)
         
registers a callback so that it is called on the avatar every frame         
         
        ";
%feature("docstring") Piavca::Avatar::removeCallback "
void Avatar::removeCallback(tstring cbName)
         
deletes a callback         
         
        ";
%feature("docstring") Piavca::Avatar::getCallback "
AvatarTimeCallback * Avatar::getCallback(tstring cbName)
         
get a pointer to a callback         
         
        ";
%feature("docstring") Piavca::Avatar::getNumCallbacks "
int Avatar::getNumCallbacks()
         
gets the number of registered callbacks (for iterating through them)         
         
        ";
%feature("docstring") Piavca::Avatar::getCallback "
AvatarTimeCallback * Avatar::getCallback(int i)
         
get a callback based on its index (the indeces are arbitrary this is just useful for finding a callback)         
         
        ";
%feature("docstring") Piavca::Avatar::Avatar "
Piavca::Avatar::Avatar(const Avatar &av)
         
copy constructor         
         
        ";
%feature("docstring") Piavca::Avatar::Avatar "
Avatar::Avatar(tstring avatarId, bool bailOnMissedJoints=false, const Vec &Position=Vec(0.0, 0.0, 0.0), const Quat &Orientation=Quat(1.0, 0.0, 0.0, 0.0), const Vec &forwardDir=Vec(0.0, 0.0, 1.0))
         
create an avatar         
         
The avatar needs to be initialised with an implementation. The type of the implementation depends on the platform and so it cannot be created directly in platform independant code. To get around this it is created by a static factory method in the which itself uses the Piavca::Core class and its platform dependent implementation to create the implementation of the avatar. The constructor needs an identifier string that it uses to find platform specific data needed to create the avatar, for example the mesh file. The user can also pass in a position and orientation for the avatar. If bail on missed joints is true it will fail to create the avatar if not all the needed joints are present in the model and will result in an invalid avatar (this can be tested with the isValid method).         ";
%feature("docstring") Piavca::Avatar::isValid "
bool Piavca::Avatar::isValid()
         
set the current piavca core object         
         
        ";
%feature("docstring") Piavca::Avatar::activate "
void Avatar::activate()
         
turn on updates on the avatar         
         
        ";
%feature("docstring") Piavca::Avatar::deactivate "
void Avatar::deactivate()
         
turn off updates on the avatar         
         
        ";
%feature("docstring") Piavca::Avatar::getName "
tstring Piavca::Avatar::getName()
         
get the name of the avatar         
         
        ";
%feature("docstring") Piavca::Avatar::setName "
tstring Piavca::Avatar::setName(tstring newName)
         
set the name of the avatar         
         
        ";
%feature("docstring") Piavca::Avatar::getForwardDirection "
const Vec& Piavca::Avatar::getForwardDirection()
         
returns the local direction at which the avatar points forward         
         
        ";
%feature("docstring") Piavca::Avatar::setForwardDirection "
void Piavca::Avatar::setForwardDirection(const Vec &dir)
         
sets the local direction at which the avatar points forward         
         
        ";
%feature("docstring") Piavca::Avatar::createJoint "
bool Piavca::Avatar::createJoint(tstring jointName)
         
creates a new joint         
         
It will only succeed if there is a piece of geometry corresponding to the name if not it returns false.         ";
%feature("docstring") Piavca::Avatar::begin "
int Piavca::Avatar::begin() const 
         
the ID of the first joint that is present in the avatar (the ordering is arbitrary)         
         
        ";
%feature("docstring") Piavca::Avatar::end "
int Avatar::end() const 
         
the last joint + 1         
         
        ";
%feature("docstring") Piavca::Avatar::next "
int Avatar::next(int &jointId)
         
given a joint ID this returns the next joint ID that is present in the avatar         
         
        ";
%feature("docstring") Piavca::Avatar::getParent "
int Piavca::Avatar::getParent(int jointId) const 
         
returns the ID of the parent of the joint in the joint heirarchy (or a negative value if it doesn't exist         
         
        ";
%feature("docstring") Piavca::Avatar::getJointName "
const tstring Piavca::Avatar::getJointName(int jointId)
         
get the name of the joint corresponding to an ID         
         
        ";
%feature("docstring") Piavca::Avatar::isNull "
bool Piavca::Avatar::isNull(int jointId) const 
         
whether the joint is present in the avatar         
         
        ";
%feature("docstring") Piavca::Avatar::hasChanged "
bool Piavca::Avatar::hasChanged(int jointId)
         
check whether the joint has been changed by user input         
         
        ";
%feature("docstring") Piavca::Avatar::clearChange "
void Piavca::Avatar::clearChange(int jointId)
         
clears the changed flag for the joint         
         
        ";
%feature("docstring") Piavca::Avatar::setJointOrientation "
void Piavca::Avatar::setJointOrientation(int jointId, const Quat &val, jointCoord worldCoord=JOINTLOCAL_COORD)
         
set the value of the orientation of a joint         
         
The joint is specified via an ID. This can be done in various coordinate systems, jointlocal is the coordante space of the joint (default) local is the space of the avatar root world is the world coordinates using the second two is likely to be much less efficient         ";
%feature("docstring") Piavca::Avatar::getJointOrientation "
Quat Piavca::Avatar::getJointOrientation(int jointId, jointCoord worldCoord=JOINTLOCAL_COORD)
         
get the orientation of a joint         
         
The joint is specified via an ID. This can be done in various coordinate systems, jointlocal is the coordante space of the joint (default) local is the space of the avatar root world is the world coordinates using the second two is likely to be much less efficient         ";
%feature("docstring") Piavca::Avatar::setJointOrientation "
void Avatar::setJointOrientation(std::vector< std::pair< int, Quat > > jointOrientation, jointCoord worldCoord=JOINTLOCAL_COORD)
         
set all the joint orientations from a vector of joint IDs and values         
         
This can be done in various coordinate systems, jointlocal is the coordante space of the joint (default) local is the space of the avatar root world is the world coordinates using the second two is likely to be much less efficient         ";
%feature("docstring") Piavca::Avatar::getJointBasePosition "
Vec Piavca::Avatar::getJointBasePosition(int jointId, jointCoord worldCoord=LOCAL_COORD)
         
get the current position of the start point of the joint         
         
calculated from the root position and joint angles by forward kinematics This can be done in various coordinate systems, jointlocal is the coordante space of the joint local is the space of the avatar root (default) world is the world coordinates         ";
%feature("docstring") Piavca::Avatar::scaleRoot "
void Piavca::Avatar::scaleRoot(Vec scale)
         
scales the root by a non-uniform scale vector         
         
        ";
%feature("docstring") Piavca::Avatar::scaleJoint "
void Piavca::Avatar::scaleJoint(int jointId, Vec scale)
         
scales a joint by a non-uniform scale vector         
         
        ";
%feature("docstring") Piavca::Avatar::timeStep "
void Avatar::timeStep(float time)
         
set the current time         
         
This is used for animation, it sets the time within the current piece of motion and puts the avatar in the correct position for that motion at that time         ";
%feature("docstring") Piavca::Avatar::initAvatar "
void Avatar::initAvatar(tstring avatarId, bool bailOnMissedJoints, const Vec &Position, const Quat &Orientation)
         
initialise a Avatar in a platform dependent way using the core         
         
        ";
%feature("docstring") Piavca::Avatar::platformSpecific_timeStep "
void Piavca::Avatar::platformSpecific_timeStep(float time)
         
        
         
This is a function that does platform specific per-frame stuff Called by timeStep         ";
%feature("docstring") Piavca::Avatar::~Avatar "
Avatar::~Avatar()
         
destructor can only be called by the core, use Core::removeAvatar to delete an avatar         
         
        ";
%feature("docstring") Piavca::Avatar::validateMotions "
void Avatar::validateMotions()
         
this validates the various motions that are loaded to check they have the correct track types         
         
        ";
%feature("docstring") Piavca::AvatarCal3DImp " 

the implemenataion class for the Avatars on the Tara platform     
       
This is a subtype of the UCLAvatarImp class and does all the actual work of the avatar class. The platform independent UCLAvatar interface class forwards all method calls to an object of this type. (via a UCLAvatarImp pointer).      see also: AvatarCal3dImp.h";

%feature("docstring") Piavca::AvatarCal3DImp::setNeutralFacialExpression "
bool AvatarCal3DImp::setNeutralFacialExpression(tstring expressionName)
         
        
         
        ";
%feature("docstring") Piavca::AvatarCal3DImp::addFacialExpression "
bool AvatarCal3DImp::addFacialExpression(tstring expressionName)
         
        
         
        ";
%feature("docstring") Piavca::AvatarCal3DImp::getFacialExpressionId "
int AvatarCal3DImp::getFacialExpressionId(tstring expressionName)
         
        
         
        ";
%feature("docstring") Piavca::AvatarCal3DImp::setFacialExpressionWeight "
bool AvatarCal3DImp::setFacialExpressionWeight(int id, float weight, float timeInterval=0.5)
         
        
         
        ";
%feature("docstring") Piavca::AvatarCal3DImp::getFacialExpressionWeight "
float AvatarCal3DImp::getFacialExpressionWeight(int id)
         
        
         
        ";
%feature("docstring") Piavca::AvatarCal3DImp::clearFacialExpressionWeights "
virtual void Piavca::AvatarCal3DImp::clearFacialExpressionWeights()
         
        
         
        ";
%feature("docstring") Piavca::AvatarCal3DImp::updateFacialExpressions "
void AvatarCal3DImp::updateFacialExpressions()
         
        
         
        ";
%feature("docstring") Piavca::AvatarCal3DImp::isExpressionNull "
bool Piavca::AvatarCal3DImp::isExpressionNull(int expressionId) const 
         
whether the expression is present in the avatar         
         
        ";
%feature("docstring") Piavca::AvatarCal3DImp::setRootPosition "
void AvatarCal3DImp::setRootPosition(const Vec &Position)
         
        
         
get or set the root position and orientation of the avatar         ";
%feature("docstring") Piavca::AvatarCal3DImp::getRootPosition "
Vec AvatarCal3DImp::getRootPosition()
         
        
         
        ";
%feature("docstring") Piavca::AvatarCal3DImp::setRootOrientation "
void AvatarCal3DImp::setRootOrientation(const Quat &Orientation)
         
        
         
        ";
%feature("docstring") Piavca::AvatarCal3DImp::getRootOrientation "
Quat AvatarCal3DImp::getRootOrientation()
         
        
         
        ";
%feature("docstring") Piavca::AvatarCal3DImp::AvatarCal3DImp "
AvatarCal3DImp::AvatarCal3DImp(tstring avatarId, TextureHandler *_textureHandler, bool bailOnMissedJoints, const Vec &Position, const Quat &Orientation)
         
private constructor means that the user cannot create it         
         
Must be created via a TaraAvatarFactory object         ";
%feature("docstring") Piavca::AvatarCal3DImp::loadTextures "
void AvatarCal3DImp::loadTextures()
         
loads all textures from file         
         
        ";
%feature("docstring") Piavca::AvatarCal3DImp::platformSpecific_timeStep "
void AvatarCal3DImp::platformSpecific_timeStep(float time)
         
        
         
This is a function that does platform specific per-frame stuff Called by timeStep         ";
%feature("docstring") Piavca::AvatarCal3DImp::~AvatarCal3DImp "
virtual Piavca::AvatarCal3DImp::~AvatarCal3DImp()
         
destructor         
         
        ";
%feature("docstring") Piavca::AvatarCal3DImp::createJoint "
bool AvatarCal3DImp::createJoint(tstring JointName)
         
creates a new joint         
         
It will only succeed if there is a piece of geometry corresponding to the name if not it returns false         ";
%feature("docstring") Piavca::AvatarCal3DImp::isNull "
bool Piavca::AvatarCal3DImp::isNull(int jointId) const 
         
whether a joint is actually present in the avatar         
         
        ";
%feature("docstring") Piavca::AvatarCal3DImp::getParent "
int AvatarCal3DImp::getParent(int jointId) const 
         
returns the ID of the parent of the joint in the joint heirarchy (or a negative value if it doesn't exist         
         
        ";
%feature("docstring") Piavca::AvatarCal3DImp::getJointName "
const tstring AvatarCal3DImp::getJointName(int jointId)
         
get the name of the joint corresponding to an iterator         
         
        ";
%feature("docstring") Piavca::AvatarCal3DImp::hasChanged "
bool AvatarCal3DImp::hasChanged(int jointId)
         
check whether the joint iterator has been changed by user input         
         
        ";
%feature("docstring") Piavca::AvatarCal3DImp::clearChange "
void AvatarCal3DImp::clearChange(int jointId)
         
clears the changed flag for the joint         
         
        ";
%feature("docstring") Piavca::AvatarCal3DImp::setJointOrientation "
void AvatarCal3DImp::setJointOrientation(int jointId, const Quat &val, jointCoord worldCoord=JOINTLOCAL_COORD)
         
set the value of the orientation of a joint         
         
The joint is specified via an itertor. This can be done in various coordinate systems, jointlocal is the coordante space of the joint (default) local is the space of the avatar root world is the world coordinates using the second two is likely to be much less efficient         ";
%feature("docstring") Piavca::AvatarCal3DImp::getJointOrientation "
Quat AvatarCal3DImp::getJointOrientation(int jointId, jointCoord worldCoord=JOINTLOCAL_COORD)
         
get the orientation of a joint         
         
The joint is specified via an itertor. This can be done in various coordinate systems, jointlocal is the coordante space of the joint (default) local is the space of the avatar root world is the world coordinates using the second two is likely to be much less efficient         ";
%feature("docstring") Piavca::AvatarCal3DImp::getJointBasePosition "
Vec AvatarCal3DImp::getJointBasePosition(int jointId, jointCoord worldCoord=LOCAL_COORD)
         
get the current position of the start point of the joint         
         
calculated from the root position and joint angles by forward kinematics This can be done in various coordinate systems, jointlocal is the coordante space of the joint local is the space of the avatar root (default) world is the world coordinates         ";
%feature("docstring") Piavca::AvatarCal3DImp::scaleRoot "
void AvatarCal3DImp::scaleRoot(Vec scale)
         
scales the root by a non-uniform scale vector         
         
        ";
%feature("docstring") Piavca::AvatarCal3DImp::scaleJoint "
void AvatarCal3DImp::scaleJoint(int jointId, Vec scale)
         
scales a joint by a non-uniform scale vector         
         
        ";
%feature("docstring") Piavca::AvatarCal3DImp::prerender "
virtual void Piavca::AvatarCal3DImp::prerender()
         
to be called before the rendering state         
         
It is used to swap the render buffers         ";
%feature("docstring") Piavca::AvatarCal3DImp::render "
void AvatarCal3DImp::render()
         
does a GL Render of the character         
         
        ";
%feature("docstring") Piavca::AvatarCal3DImp::getAvatarImp "
AvatarCal3DImp * AvatarCal3DImp::getAvatarImp(Avatar *avatar)
         
given a UCLAvatar object get its implementation         
         
        ";
%feature("docstring") Piavca::AvatarImp " 

the implemenataion class for the Avatars     
       
Each platform has a concrete subtype of this class which actually does the work of the avatar class. The Avatar class is an interface class that contains a pointer to a AvatarImp object and forwards all method calls to this object. The object will be of the concrete type corresponding to the platform being used.      see also: AvatarImp.h";

%feature("docstring") Piavca::AvatarImp::setNeutralFacialExpression "
virtual bool Piavca::AvatarImp::setNeutralFacialExpression(tstring expressionName)=0
         
        
         
        ";
%feature("docstring") Piavca::AvatarImp::addFacialExpression "
virtual bool Piavca::AvatarImp::addFacialExpression(tstring expressionName)=0
         
        
         
        ";
%feature("docstring") Piavca::AvatarImp::getFacialExpressionId "
virtual int Piavca::AvatarImp::getFacialExpressionId(tstring expressionName)=0
         
        
         
        ";
%feature("docstring") Piavca::AvatarImp::setFacialExpressionWeight "
virtual bool Piavca::AvatarImp::setFacialExpressionWeight(int id, float weight, float timeInterval=0.5)=0
         
        
         
        ";
%feature("docstring") Piavca::AvatarImp::getFacialExpressionWeight "
virtual float Piavca::AvatarImp::getFacialExpressionWeight(int id)=0
         
        
         
        ";
%feature("docstring") Piavca::AvatarImp::clearFacialExpressionWeights "
virtual void Piavca::AvatarImp::clearFacialExpressionWeights()=0
         
        
         
        ";
%feature("docstring") Piavca::AvatarImp::isExpressionNull "
virtual bool Piavca::AvatarImp::isExpressionNull(int expressionId) const =0
         
        
         
        ";
%feature("docstring") Piavca::AvatarImp::updateFacialExpressions "
virtual void Piavca::AvatarImp::updateFacialExpressions()
         
        
         
        ";
%feature("docstring") Piavca::AvatarImp::setRootPosition "
virtual void Piavca::AvatarImp::setRootPosition(const Vec &Position)=0
         
        
         
get or set the root position and orientation of the avatar         ";
%feature("docstring") Piavca::AvatarImp::getRootPosition "
virtual Vec Piavca::AvatarImp::getRootPosition()=0
         
        
         
        ";
%feature("docstring") Piavca::AvatarImp::setRootOrientation "
virtual void Piavca::AvatarImp::setRootOrientation(const Quat &Orientation)=0
         
        
         
        ";
%feature("docstring") Piavca::AvatarImp::getRootOrientation "
virtual Quat Piavca::AvatarImp::getRootOrientation()=0
         
        
         
        ";
%feature("docstring") Piavca::AvatarImp::~AvatarImp "
virtual Piavca::AvatarImp::~AvatarImp()
         
destructor         
         
        ";
%feature("docstring") Piavca::AvatarImp::createJoint "
virtual bool Piavca::AvatarImp::createJoint(tstring jointName)=0
         
creates a new joint         
         
It will only succeed if there is a piece of geometry corresponding to the name if not it returns false         ";
%feature("docstring") Piavca::AvatarImp::getParent "
virtual int Piavca::AvatarImp::getParent(int jointId) const =0
         
returns the ID of the parent of the joint in the joint heirarchy (or a negative value if it doesn't exist         
         
        ";
%feature("docstring") Piavca::AvatarImp::isNull "
virtual bool Piavca::AvatarImp::isNull(int jointId) const =0
         
whether a joint is actually present in the avatar         
         
        ";
%feature("docstring") Piavca::AvatarImp::getJointName "
virtual const tstring Piavca::AvatarImp::getJointName(int jointId)=0
         
get the name of the joint corresponding to an ID         
         
        ";
%feature("docstring") Piavca::AvatarImp::hasChanged "
virtual bool Piavca::AvatarImp::hasChanged(int jointId)=0
         
check whether the joint has been changed by user input         
         
        ";
%feature("docstring") Piavca::AvatarImp::clearChange "
virtual void Piavca::AvatarImp::clearChange(int jointId)=0
         
clears the changed flag for the joint         
         
        ";
%feature("docstring") Piavca::AvatarImp::setJointOrientation "
virtual void Piavca::AvatarImp::setJointOrientation(int jointId, const Quat &val, jointCoord worldCoord=JOINTLOCAL_COORD)=0
         
set the value of the orientation of a joint         
         
The joint is specified via an ID. This can be done in various coordinate systems, jointlocal is the coordante space of the joint (default) local is the space of the avatar root world is the world coordinates using the second two is likely to be much less efficient         ";
%feature("docstring") Piavca::AvatarImp::getJointOrientation "
virtual Quat Piavca::AvatarImp::getJointOrientation(int jointId, jointCoord worldCoord=JOINTLOCAL_COORD)=0
         
get the orientation of a joint         
         
The joint is specified via an ID. This can be done in various coordinate systems, jointlocal is the coordante space of the joint (default) local is the space of the avatar root world is the world coordinates using the second two is likely to be much less efficient         ";
%feature("docstring") Piavca::AvatarImp::getJointBasePosition "
virtual Vec Piavca::AvatarImp::getJointBasePosition(int jointId, jointCoord worldCoord=LOCAL_COORD)=0
         
get the current position of the start of the joint         
         
calculated from the root position and joint angles by forward kinematics This can be done in various coordinate systems, jointlocal is the coordante space of the joint local is the space of the avatar root (default) world is the world coordinates         ";
%feature("docstring") Piavca::AvatarImp::scaleRoot "
virtual void Piavca::AvatarImp::scaleRoot(Vec scale)=0
         
scales the root by a non-uniform scale vector         
         
        ";
%feature("docstring") Piavca::AvatarImp::scaleJoint "
virtual void Piavca::AvatarImp::scaleJoint(int jointId, Vec scale)=0
         
scales a joint by a non-uniform scale vector         
         
        ";
%feature("docstring") Piavca::AvatarImp::AvatarImp "
Piavca::AvatarImp::AvatarImp()
         
        
         
        ";
%feature("docstring") Piavca::AvatarImp::platformSpecific_timeStep "
virtual void Piavca::AvatarImp::platformSpecific_timeStep(float time)=0
         
        
         
This is a function that does platform specific per-frame stuff Called by timeStep         ";
%feature("docstring") Piavca::AvatarImp::getAvatarImpInternal "
AvatarImp * AvatarImp::getAvatarImpInternal(Avatar *avatar)
         
Given a Avatar object this returns its implementation.         
         
This is used by a similar method in the platform specific implementation that is used to get the implementation in platform specific code         ";
%feature("docstring") Piavca::AvatarMotionQueue " 

A Queue for managing motions.     
       
You can put motions on the queue and they will be played in sequence each waiting for the previous to finish. You can also add background motions that continuing playing at the same time as the motions on the queue.      see also: AvatarMotionQueue.h";

%feature("docstring") Piavca::AvatarMotionQueue::AvatarMotionQueue "
Piavca::AvatarMotionQueue::AvatarMotionQueue()
         
        
         
        ";
%feature("docstring") Piavca::AvatarMotionQueue::AvatarMotionQueue "
AvatarMotionQueue::AvatarMotionQueue(float scale, float delay=0, bool facial=false, int factor=10)
         
        
         
Pass in a scale factor for the position component of the motions (e.g. to convert between meters and inches. A delay time between motions. a flag to say whether the queue handles facial or body motions. and a multiplier for the delay.         ";
%feature("docstring") Piavca::AvatarMotionQueue::~AvatarMotionQueue "
virtual Piavca::AvatarMotionQueue::~AvatarMotionQueue()
         
        
         
        ";
%feature("docstring") Piavca::AvatarMotionQueue::init "
void AvatarMotionQueue::init(Piavca::Avatar *avatar)
         
This is a setup method for the callback.         
         
It's called when the callback is registered         ";
%feature("docstring") Piavca::AvatarMotionQueue::timeStep "
void AvatarMotionQueue::timeStep(Piavca::Avatar *avatar, float time)
         
implement this to make the callback do things         
         
It's called every frame with by the API which passes in the avatar to which the callback is attatched         ";
%feature("docstring") Piavca::AvatarMotionQueue::isFacial "
bool Piavca::AvatarMotionQueue::isFacial()
         
whether the queue handles facial or body motions         
         
        ";
%feature("docstring") Piavca::AvatarMotionQueue::getCurrentMotionStart "
float Piavca::AvatarMotionQueue::getCurrentMotionStart()
         
gets the start time of the current motion         
         
        ";
%feature("docstring") Piavca::AvatarMotionQueue::reblend "
void Piavca::AvatarMotionQueue::reblend()
         
        
         
        ";
%feature("docstring") Piavca::AvatarMotionQueue::setBlendInterval "
void Piavca::AvatarMotionQueue::setBlendInterval(float t)
         
sets how long it takes to blend between subsequent motions.         
         
        ";
%feature("docstring") Piavca::AvatarMotionQueue::enqueueMotion "
void AvatarMotionQueue::enqueueMotion(tstring name, Piavca::Motion *motion, float atTime=0.0)
         
adds a motion to the queue         
         
You have to pass in a name for the motion and optionally a minimum time for it to start.         ";
%feature("docstring") Piavca::AvatarMotionQueue::enqueueRandomMotions "
void AvatarMotionQueue::enqueueRandomMotions(int num=0)
         
enqueue a number of randomly chosen motions         
         
        ";
%feature("docstring") Piavca::AvatarMotionQueue::queueTopIsBackground "
bool AvatarMotionQueue::queueTopIsBackground()
         
tests whether the first motion on the queue is a background motion         
         
        ";
%feature("docstring") Piavca::AvatarMotionQueue::queueTopTime "
float AvatarMotionQueue::queueTopTime()
         
gets the minimum start time of the first motion on the queue         
         
        ";
%feature("docstring") Piavca::AvatarMotionQueue::dequeueMotion "
Motion * AvatarMotionQueue::dequeueMotion()
         
pops a motion off the queue         
         
        ";
%feature("docstring") Piavca::AvatarMotionQueue::getQueueSize "
int Piavca::AvatarMotionQueue::getQueueSize()
         
returns the number of motions on the queue         
         
        ";
%feature("docstring") Piavca::AvatarMotionQueue::updateDelay "
void Piavca::AvatarMotionQueue::updateDelay(float delay)
         
change the delay         
         
        ";
%feature("docstring") Piavca::AvatarMotionQueue::clearQueue "
void AvatarMotionQueue::clearQueue()
         
empties the queue         
         
        ";
%feature("docstring") Piavca::AvatarMotionQueue::removeMotion "
void AvatarMotionQueue::removeMotion(tstring name)
         
removes a named forground motion         
         
        ";
%feature("docstring") Piavca::AvatarMotionQueue::pauseMotion "
void Piavca::AvatarMotionQueue::pauseMotion(tstring name)
         
pauses a named forground motion         
         
        ";
%feature("docstring") Piavca::AvatarMotionQueue::unpauseMotion "
void Piavca::AvatarMotionQueue::unpauseMotion(tstring name)
         
unpauses a named forground motion         
         
        ";
%feature("docstring") Piavca::AvatarMotionQueue::clearAllBackgroundMotions "
void AvatarMotionQueue::clearAllBackgroundMotions()
         
removes all background motions from the queue         
         
        ";
%feature("docstring") Piavca::AvatarMotionQueue::clearFinishedBackgroundMotions "
void AvatarMotionQueue::clearFinishedBackgroundMotions()
         
removes any background motions that have stopped playing         
         
        ";
%feature("docstring") Piavca::AvatarMotionQueue::removeBackgroundMotion "
void AvatarMotionQueue::removeBackgroundMotion(tstring name)
         
removes a named background motion         
         
        ";
%feature("docstring") Piavca::AvatarMotionQueue::removeBackgroundMotionByType "
void AvatarMotionQueue::removeBackgroundMotionByType(const type_info &ty)
         
removes a background motion with a given type         
         
        ";
%feature("docstring") Piavca::AvatarMotionQueue::pauseBackgroundMotion "
void AvatarMotionQueue::pauseBackgroundMotion(tstring name)
         
pauses a named background motion         
         
        ";
%feature("docstring") Piavca::AvatarMotionQueue::unpauseBackgroundMotion "
void AvatarMotionQueue::unpauseBackgroundMotion(tstring name)
         
unpauses a named background motion         
         
        ";
%feature("docstring") Piavca::AvatarMotionQueue::interrupt "
void Piavca::AvatarMotionQueue::interrupt()
         
interrupts the queue         
         
so the next motion is played immediately, without waiting for the current one stop         ";
%feature("docstring") Piavca::AvatarMotionQueue::getMotion "
virtual Piavca::Motion* Piavca::AvatarMotionQueue::getMotion()
         
return the resulting motion         
         
        ";
%feature("docstring") Piavca::AvatarMotionQueue::blendMotion "
Motion * AvatarMotionQueue::blendMotion(Motion *m, Avatar *av, float scaleFactor)
         
        
         
        ";
%feature("docstring") Piavca::AvatarMotionQueue::addBackgroundMotion "
void AvatarMotionQueue::addBackgroundMotion(tstring name, Piavca::Motion *motion, float atTime=0.0)
         
adds a new background motion to the queue         
         
A background motion is played concurrently with any motions on the queue. You have to pass in a name and optionally minimum time at which it should start.         ";
%feature("docstring") Piavca::AvatarMotionQueue::AvatarMotionQueue::getQueue "
static AvatarMotionQueue* Piavca::AvatarMotionQueue::AvatarMotionQueue::getQueue(Avatar *avatar, bool facial=false)
         
        
         
a static method, given an avatar returns that avatar's queue. The avatar has a queue for body and one for facial motions the facial flag distinguishes them.         ";
%feature("docstring") Piavca::AvatarMotionQueue::AvatarMotionQueue "
Piavca::AvatarMotionQueue::AvatarMotionQueue(const AvatarMotionQueue &amq)
         
        
         
        ";
%feature("docstring") Piavca::AvatarPostureBlend " 

A motion blend operator that blends a motion into the current position of an avatar.     
       
This class will blend smoothly from the current postion of an avatar to the motion and will have the motion start at the current position and orientation of the avatar rather than its own start point (see SequentialBlend docs for some details)      see also: AvatarPostureBlend.h";

%feature("docstring") Piavca::AvatarPostureBlend::AvatarPostureBlend "
AvatarPostureBlend::AvatarPostureBlend(Motion *mot=NULL, float interval=0.2, bool tracksFromAvatar=false)
         
        
         
Pass in the motion to be blended in, the length of time over which the blend should happen, add a flag which specifies whether the tracks that the motion has should be those in the blended in motion or those in the avatar         ";
%feature("docstring") Piavca::AvatarPostureBlend::AvatarPostureBlend "
Piavca::AvatarPostureBlend::AvatarPostureBlend(const AvatarPostureBlend &apb)
         
        
         
        ";
%feature("docstring") Piavca::AvatarPostureBlend::clone "
virtual Motion* Piavca::AvatarPostureBlend::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") Piavca::AvatarPostureBlend::load "
void AvatarPostureBlend::load(Avatar *av)
         
called when the motion is loaded into an avatar         
         
        ";
%feature("docstring") Piavca::AvatarPostureBlend::setMotion "
void AvatarPostureBlend::setMotion(Motion *mot)
         
        
         
        ";
%feature("docstring") Piavca::AvatarPostureBlend::reblend "
void AvatarPostureBlend::reblend()
         
restart the blend (i.e. start blending from the current avatar posture) at the current time         
         
        ";
%feature("docstring") Piavca::AvatarPostureBlend::reblend "
void AvatarPostureBlend::reblend(float time)
         
restart the blend (i.e. start blending from the current avatar posture) at the current time         
         
        ";
%feature("docstring") Piavca::AvatarTimeCallback " 

A callback that is called by the API every frame on an avatar.     
       
It is very similar to the TimeCallback class but the changeTime method takes an avatar which can be updated.      see also: TimeCallback.h";

%feature("docstring") Piavca::AvatarTimeCallback::AvatarTimeCallback "
Piavca::AvatarTimeCallback::AvatarTimeCallback(tstring _name)
         
        
         
        ";
%feature("docstring") Piavca::AvatarTimeCallback::~AvatarTimeCallback "
virtual Piavca::AvatarTimeCallback::~AvatarTimeCallback()
         
        
         
        ";
%feature("docstring") Piavca::AvatarTimeCallback::getName "
tstring Piavca::AvatarTimeCallback::getName()
         
        
         
        ";
%feature("docstring") Piavca::AvatarTimeCallback::init "
virtual void Piavca::AvatarTimeCallback::init(Avatar *avatar)=0
         
This is a setup method for the callback.         
         
It's called when the callback is registered         ";
%feature("docstring") Piavca::AvatarTimeCallback::timeStep "
virtual void Piavca::AvatarTimeCallback::timeStep(Avatar *avatar, float time)=0
         
implement this to make the callback do things         
         
It's called every frame with by the API which passes in the avatar to which the callback is attatched         ";
%feature("docstring") Piavca::BaseMotionTrack " 

this is a base class for motion tracks (sequences of keyframes)     
       
The track holds a sequence of keyframes for one element (e.g. joint rotation). The reason there is a base class is that the tracks themselves are templates, they can be tracks of floats, Vecs or Quats. This is fine but you need to be able to handle a track irrespective of its type. For example, storing the tracks in a single data structure without knowing what type they are. This base type provides a way of doing this. You can access all the methods through the base type but trying to call a method of the wrong type (e.g. adding a float keyframe to a Vec track) results in an exception. Probably won't be part of the API itself as in some implementations this stuff might be handled in the underlying API.      see also: MotionTrack.h";

%feature("docstring") Piavca::BaseMotionTrack::getFloatValAtTime "
virtual float Piavca::BaseMotionTrack::getFloatValAtTime(float time) const =0
         
get the value of the keyframe at time (only for float tracks)         
         
        ";
%feature("docstring") Piavca::BaseMotionTrack::getVecValAtTime "
virtual Vec Piavca::BaseMotionTrack::getVecValAtTime(float time) const =0
         
get the value of the keyframe at time (only for Vec tracks)         
         
        ";
%feature("docstring") Piavca::BaseMotionTrack::getQuatValAtTime "
virtual Quat Piavca::BaseMotionTrack::getQuatValAtTime(float time) const =0
         
get the value of the keyframe at time (only for Quat tracks)         
         
        ";
%feature("docstring") Piavca::BaseMotionTrack::setFloatKeyframe "
virtual void Piavca::BaseMotionTrack::setFloatKeyframe(float time, float val)=0
         
create a float key frame or set the value of an existing one (only works for float tracks)         
         
        ";
%feature("docstring") Piavca::BaseMotionTrack::setFloatKeyframe "
virtual void Piavca::BaseMotionTrack::setFloatKeyframe(float time, float val, float vel)=0
         
create a float key frame or set the value of an existing one with a user specified velocity (only works for float tracks)         
         
        ";
%feature("docstring") Piavca::BaseMotionTrack::setVecKeyframe "
virtual void Piavca::BaseMotionTrack::setVecKeyframe(float time, Vec val)=0
         
create a Vec key frame or set the value of an existing one (only works for Vec tracks)         
         
        ";
%feature("docstring") Piavca::BaseMotionTrack::setVecKeyframe "
virtual void Piavca::BaseMotionTrack::setVecKeyframe(float time, Vec val, Vec vel)=0
         
create a Vec key frame or set the value of an existing one with a user specified velocity (only works for Vec tracks)         
         
        ";
%feature("docstring") Piavca::BaseMotionTrack::setQuatKeyframe "
virtual void Piavca::BaseMotionTrack::setQuatKeyframe(float time, Quat val)=0
         
create a Quat key frame or set the value of an existing one (only works for Quat tracks)         
         
        ";
%feature("docstring") Piavca::BaseMotionTrack::setQuatKeyframe "
virtual void Piavca::BaseMotionTrack::setQuatKeyframe(float time, Quat val, Quat vel)=0
         
create a Quat key frame or set the value of an existing one with a user specified velocity (only works for Quat tracks)         
         
        ";
%feature("docstring") Piavca::BaseMotionTrack::BaseMotionTrack "
Piavca::BaseMotionTrack::BaseMotionTrack(trackType _type)
         
        
         
        ";
%feature("docstring") Piavca::BaseMotionTrack::BaseMotionTrack "
Piavca::BaseMotionTrack::BaseMotionTrack(const BaseMotionTrack &track)
         
        
         
        ";
%feature("docstring") Piavca::BaseMotionTrack::~BaseMotionTrack "
virtual Piavca::BaseMotionTrack::~BaseMotionTrack()
         
        
         
        ";
%feature("docstring") Piavca::BaseMotionTrack::getOffset "
virtual const Vec& Piavca::BaseMotionTrack::getOffset() const =0
         
        
         
        ";
%feature("docstring") Piavca::BaseMotionTrack::setOffset "
virtual void Piavca::BaseMotionTrack::setOffset(const Vec &offs)=0
         
        
         
        ";
%feature("docstring") Piavca::BaseMotionTrack::clone "
virtual BaseMotionTrack* Piavca::BaseMotionTrack::clone()=0
         
Produces a copy of the track.         
         
Used to copy without knowing the type of the track         ";
%feature("docstring") Piavca::BaseMotionTrack::deleteKeyframeAtTime "
virtual void Piavca::BaseMotionTrack::deleteKeyframeAtTime(int time)=0
         
Delete the keyframe at time.         
         
        ";
%feature("docstring") Piavca::BaseMotionTrack::clear "
virtual void Piavca::BaseMotionTrack::clear(bool createFirstFrame=true)=0
         
Delete all keyframes.         
         
        ";
%feature("docstring") Piavca::BaseMotionTrack::getLength "
virtual float Piavca::BaseMotionTrack::getLength()=0
         
get the time of the last keyframe         
         
        ";
%feature("docstring") Piavca::BaseMotionTrack::getNumKeyframes "
virtual int Piavca::BaseMotionTrack::getNumKeyframes() const =0
         
gets the number of keyframes defined for the track         
         
        ";
%feature("docstring") Piavca::BaseMotionTrack::getTime "
virtual float Piavca::BaseMotionTrack::getTime(int i) const =0
         
gets the i th keyframe time         
         
        ";
%feature("docstring") Piavca::BaseMotionTrack::generateExceptionText "
tstring BaseMotionTrack::generateExceptionText(trackType calledType) const 
         
generate text for a wrong track type exception         
         
        ";
%feature("docstring") Piavca::BaseMotionTrack::calcVelocities "
virtual void Piavca::BaseMotionTrack::calcVelocities() const =0
         
Calculate the velocities at each keyframe.         
         
The client can explicitely specify velocities in which case they are not recalculated. The formula used is a varient of Catmull-Rom splines         ";
%feature("docstring") Piavca::BaseMotionTrack::getTrackType "
trackType Piavca::BaseMotionTrack::getTrackType() const 
         
get the type of the track         
         
        ";
%feature("docstring") Piavca::BlendBetween " 

A motion manipulator class that interpolates between two motions.     
       
The resulting motion is an interpolation between the two motion using slerp for quaternions with a parameter value blend. This class blends the two motions concurrently rather blending from one to another as sequential blend does.      see also: BlendBetween.h";

%feature("docstring") Piavca::BlendBetween::BlendBetween "
BlendBetween::BlendBetween(Motion *m1=NULL, Motion *m2=NULL, float _blend=0.0f)
         
Pass in the two motion and the interpolation parameter blend (has to be between 0 and 1).         
         
        ";
%feature("docstring") Piavca::BlendBetween::BlendBetween "
BlendBetween::BlendBetween(const BlendBetween &b)
         
        
         
        ";
%feature("docstring") Piavca::BlendBetween::clone "
virtual Motion* Piavca::BlendBetween::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") Piavca::BlendBetween::getFloatValueAtTimeInternal "
float BlendBetween::getFloatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe.         
         
The result is the linear interpolation of the values of the two motions or if the track does not exist in the one motion, the value of the other         ";
%feature("docstring") Piavca::BlendBetween::getVecValueAtTimeInternal "
Vec BlendBetween::getVecValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe.         
         
The result is the linear interpolation of the values of the two motions or if the track does not exist in the one motion, the value of the other         ";
%feature("docstring") Piavca::BlendBetween::getQuatValueAtTimeInternal "
Quat BlendBetween::getQuatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe.         
         
The result is the linear interpolation (slerp) of the values of the two motions or if the track does not exist in the one motion, the value of the other         ";
%feature("docstring") Piavca::BlendBetween::setBlendFactor "
void Piavca::BlendBetween::setBlendFactor(float _blend)
         
        
         
        ";
%feature("docstring") Piavca::BodyToFacial " 

a motion filter that takes a body motion and pretends its a facial one (or vice versa)     
       
     see also: BodyToFacial.h";

%feature("docstring") Piavca::BodyToFacial::BodyToFacial "
Piavca::BodyToFacial::BodyToFacial(Motion *m=NULL, bool _facial=true)
         
        
         
Pass in the motion to be filtered and a flag to say whether it is facial         ";
%feature("docstring") Piavca::BodyToFacial::BodyToFacial "
Piavca::BodyToFacial::BodyToFacial(const BodyToFacial &sm)
         
        
         
        ";
%feature("docstring") Piavca::BodyToFacial::clone "
virtual Motion* Piavca::BodyToFacial::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") Piavca::BodyToFacial::isFacial "
virtual bool Piavca::BodyToFacial::isFacial()
         
whether it is a face or body motion         
         
        ";
%feature("docstring") Piavca::BodyToFacial::getFloatValueAtTimeInternal "
virtual PIAVCA_EXPORT float Piavca::BodyToFacial::getFloatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") Piavca::BodyToFacial::getVecValueAtTimeInternal "
virtual PIAVCA_EXPORT Vec Piavca::BodyToFacial::getVecValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe (vec values are scaled)         
         
        ";
%feature("docstring") Piavca::BodyToFacial::getQuatValueAtTimeInternal "
virtual PIAVCA_EXPORT Quat Piavca::BodyToFacial::getQuatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") Piavca::BodyToFacial::setFacial "
void Piavca::BodyToFacial::setFacial(bool _facial)
         
Sets the scale factor for the postion components of the motion.         
         
        ";
%feature("docstring") Piavca::ChangeMotionLength " 

    
       
     see also: ChangeMotionLength.h";

%feature("docstring") Piavca::ChangeMotionLength::ChangeMotionLength "
Piavca::ChangeMotionLength::ChangeMotionLength(Motion *mot=NULL, float len=1.0f)
         
        
         
        ";
%feature("docstring") Piavca::ChangeMotionLength::ChangeMotionLength "
Piavca::ChangeMotionLength::ChangeMotionLength(const ChangeMotionLength &cml)
         
        
         
        ";
%feature("docstring") Piavca::ChangeMotionLength::clone "
virtual Motion* Piavca::ChangeMotionLength::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") Piavca::ChangeMotionLength::setMotionLength "
void Piavca::ChangeMotionLength::setMotionLength(float len)
         
        
         
        ";
%feature("docstring") Piavca::ChangeMotionLength::getMotionLength "
virtual float Piavca::ChangeMotionLength::getMotionLength() const 
         
gets the length of the motion in seconds         
         
        ";
%feature("docstring") Piavca::ChangeMotionLength::setMotion "
virtual void Piavca::ChangeMotionLength::setMotion(Motion *mot)
         
        
         
        ";
%feature("docstring") Piavca::ChangeMotionProp " 

a motion filter that scales the motion's speed     
       
     see also: ChangeMotionProp.h";

%feature("docstring") Piavca::ChangeMotionProp::ChangeMotionProp "
Piavca::ChangeMotionProp::ChangeMotionProp(Motion *m=NULL, float scale=1.0, float mscale=1, float sw=0.2, float ew=0.2)
         
        
         
Pass in the motion to be filtered and a scale factor         ";
%feature("docstring") Piavca::ChangeMotionProp::ChangeMotionProp "
Piavca::ChangeMotionProp::ChangeMotionProp(const ChangeMotionProp &sm)
         
        
         
        ";
%feature("docstring") Piavca::ChangeMotionProp::clone "
virtual Motion* Piavca::ChangeMotionProp::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") Piavca::ChangeMotionProp::getMotionLength "
float Piavca::ChangeMotionProp::getMotionLength() const 
         
gets the length of the motion in seconds         
         
        ";
%feature("docstring") Piavca::ChangeMotionProp::getFloatValueAtTimeInternal "
virtual PIAVCA_EXPORT float Piavca::ChangeMotionProp::getFloatValueAtTimeInternal(int trackId, float time)
         
gets the value of the motion for a given track at a given time (float -> morph target)         
         
        ";
%feature("docstring") Piavca::ChangeMotionProp::getVecValueAtTimeInternal "
virtual PIAVCA_EXPORT Vec Piavca::ChangeMotionProp::getVecValueAtTimeInternal(int trackId, float time)
         
gets the value of the motion for a given track at a given time (vec -> root)         
         
        ";
%feature("docstring") Piavca::ChangeMotionProp::getQuatValueAtTimeInternal "
virtual PIAVCA_EXPORT Quat Piavca::ChangeMotionProp::getQuatValueAtTimeInternal(int trackId, float time)
         
gets the value of the motion for a given track at a given time (quat -> joint rotation)         
         
        ";
%feature("docstring") Piavca::ChangeMotionProp::setScaleFactor "
void Piavca::ChangeMotionProp::setScaleFactor(float scale)
         
Sets the scale factor for the postion components of the motion.         
         
        ";
%feature("docstring") Piavca::ChangeMotionProp::setMidScaleFactor "
void Piavca::ChangeMotionProp::setMidScaleFactor(float scale)
         
Sets the scale factor for the postion components of the motion.         
         
        ";
%feature("docstring") Piavca::ChangeMotionProp::setStartWindow "
void Piavca::ChangeMotionProp::setStartWindow(float swin)
         
Sets the start window for the postion components of the motion.         
         
        ";
%feature("docstring") Piavca::ChangeMotionProp::setEndWindow "
void Piavca::ChangeMotionProp::setEndWindow(float ewin)
         
Sets the end window for the postion components of the motion.         
         
        ";
%feature("docstring") Piavca::ChoiceLoopMotion " 

a MultiMotionLoop where the client can choose which motion is played     
       
     see also: ChoiceLoopMotion.h";

%feature("docstring") Piavca::ChoiceLoopMotion::ChoiceLoopMotion "
Piavca::ChoiceLoopMotion::ChoiceLoopMotion()
         
        
         
        ";
%feature("docstring") Piavca::ChoiceLoopMotion::ChoiceLoopMotion "
Piavca::ChoiceLoopMotion::ChoiceLoopMotion(const MotionVec &mpv, float endTime=-1.0, float interval=0.01)
         
pass in a vector of motions to be used.         
         
        ";
%feature("docstring") Piavca::ChoiceLoopMotion::ChoiceLoopMotion "
Piavca::ChoiceLoopMotion::ChoiceLoopMotion(const ChoiceLoopMotion &cl)
         
        
         
        ";
%feature("docstring") Piavca::ChoiceLoopMotion::~ChoiceLoopMotion "
Piavca::ChoiceLoopMotion::~ChoiceLoopMotion()
         
        
         
        ";
%feature("docstring") Piavca::ChoiceLoopMotion::clone "
virtual Motion* Piavca::ChoiceLoopMotion::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") Piavca::ChoiceLoopMotion::setCurrentChoice "
void Piavca::ChoiceLoopMotion::setCurrentChoice(int i)
         
sets which motion is currently being played         
         
        ";
%feature("docstring") Piavca::ChoiceLoopMotion::setCurrentChoice "
void Piavca::ChoiceLoopMotion::setCurrentChoice(tstring name)
         
sets which motion is currently being played (by name)         
         
        ";
%feature("docstring") Piavca::ChoiceLoopMotion::reblend "
virtual void Piavca::ChoiceLoopMotion::reblend(float time)
         
called each time around the loop         
         
It can be called by the client to interrupt the current motion.         ";
%feature("docstring") compIds " 

    
       
     see also: ";

%feature("docstring") Piavca::Core " 

The core object is the central controller of the Piavca system.     
       
It maintains a list of avatars, and some motions. It has a list of global callbacks that are called every frame. It handles allocation of Joint IDs. It deals with initialisation and shut down and per frame events. It also manages creation of avatar and motions. There is only ever one core object (held as the core static member of the class).      see also: PiavcaCore.h";

%feature("docstring") Piavca::Core::getJointId "
int Core::getJointId(tstring name)
         
        
         
methods dealing with joint ids get an id corresponding to a joint name         ";
%feature("docstring") Piavca::Core::getMaxJointId "
int Piavca::Core::getMaxJointId()
         
gets the maximum joint id         
         
        ";
%feature("docstring") Piavca::Core::addJointNameSet "
void Core::addJointNameSet(StringVector names)
         
Adds in a set of joints all of which should have the same id.         
         
i.e. all the names correspond to the same joint e.g. (left_foot, LFoot, LeftFoot, PiedGauche)         ";
%feature("docstring") Piavca::Core::getJointName "
tstring Core::getJointName(int jointId)
         
returns a name corresponding to a track id (out of many possible)         
         
        ";
%feature("docstring") Piavca::Core::getJointNameAssociations "
std::vector< std::pair< tstring, int > > Core::getJointNameAssociations()
         
get all the joint name associations         
         
        ";
%feature("docstring") Piavca::Core::getExpressionId "
int Core::getExpressionId(tstring name)
         
        
         
methods dealing with expression ids get an id corresponding to an expression name         ";
%feature("docstring") Piavca::Core::getMaxExpressionId "
int Piavca::Core::getMaxExpressionId()
         
gets the maximum joint id         
         
        ";
%feature("docstring") Piavca::Core::addExpressionNameSet "
void Core::addExpressionNameSet(StringVector names)
         
Adds in a set of joints all of which should have the same id.         
         
i.e. all the names correspond to the same joint e.g. (left_foot, LFoot, LeftFoot, PiedGauche)         ";
%feature("docstring") Piavca::Core::getExpressionName "
tstring Core::getExpressionName(int expressionId)
         
returns a name corresponding to a track id (out of many possible)         
         
        ";
%feature("docstring") Piavca::Core::getExpressionNameAssociations "
std::vector< std::pair< tstring, int > > Core::getExpressionNameAssociations()
         
get all the expression name associations         
         
        ";
%feature("docstring") Piavca::Core::Core "
Core::Core()
         
        
         
        ";
%feature("docstring") Piavca::Core::~Core "
Core::~Core()
         
        
         
        ";
%feature("docstring") Piavca::Core::reset "
void Core::reset()
         
        
         
        ";
%feature("docstring") Piavca::Core::registerCallback "
void Core::registerCallback(TimeCallback *cb)
         
registers a callback to be called every frame         
         
        ";
%feature("docstring") Piavca::Core::timeStep "
void Piavca::Core::timeStep()
         
        
         
Performs all per frame actions (uses the current time) Can be run in parallel with the renderer.         ";
%feature("docstring") Piavca::Core::timeStep "
void Core::timeStep(float time)
         
        
         
Performs all per frame actions Can be run in parallel with the renderer.         ";
%feature("docstring") Piavca::Core::prerender "
void Core::prerender()
         
called before rendering (this cannot be called in parallel with the render)         
         
        ";
%feature("docstring") Piavca::Core::render "
void Core::render()
         
On certain platforms this needs to be called to render the avatars.         
         
        ";
%feature("docstring") Piavca::Core::loadMotion "
void Core::loadMotion(tstring motionName, tstring motionFileName, int flags=0, bool temp=false, Motion *basePosture=NULL)
         
loads in a motion from file and adds it to the list of motions         
         
        ";
%feature("docstring") Piavca::Core::loadMotion "
void Core::loadMotion(tstring motionName, Motion *mot, bool temp=false, Motion *basePosture=NULL)
         
adds a motion to its list of motions         
         
        ";
%feature("docstring") Piavca::Core::renameMotion "
void Core::renameMotion(tstring oldName, tstring newName)
         
changes the name of a motion         
         
        ";
%feature("docstring") Piavca::Core::unloadMotion "
void Core::unloadMotion(tstring name)
         
removes the motion from the core and deletes it (NB difference to disposeMotion)         
         
        ";
%feature("docstring") Piavca::Core::getMotion "
Motion * Core::getMotion(tstring motionName)
         
        
         
get a named motion NB the caller gets ownership of the motion and therefore must delete it (of course ownership can be given to an avatar by loading it)         ";
%feature("docstring") Piavca::Core::getMotionNames "
PIAVCA_EXPORT std::vector< std::string > Core::getMotionNames(int number=0)
         
get motion names         
         
        ";
%feature("docstring") Piavca::Core::getNumberOfMotions "
int Piavca::Core::getNumberOfMotions()
         
get number of motions         
         
        ";
%feature("docstring") Piavca::Core::getAllmotions "
PIAVCA_EXPORT std::list< tstring > Core::getAllmotions()
         
get all motion names         
         
        ";
%feature("docstring") Piavca::Core::getMotion "
Motion* Piavca::Core::getMotion(int i)
         
get a motion by its (arbitrary) index         
         
        ";
%feature("docstring") Piavca::Core::getAvatar "
Avatar * Core::getAvatar(tstring avatarName)
         
get a named avatar         
         
        ";
%feature("docstring") Piavca::Core::getAvatarNames "
std::vector< tstring > Core::getAvatarNames()
         
        
         
        ";
%feature("docstring") Piavca::Core::numAvatars "
int Piavca::Core::numAvatars()
         
get the number of avatars         
         
        ";
%feature("docstring") Piavca::Core::getAvatar "
Avatar * Core::getAvatar(int i)
         
get the ith avatar in the list (used for interating over all avatars)         
         
        ";
%feature("docstring") Piavca::Core::renameAvatar "
void Core::renameAvatar(tstring oldName, tstring newName)
         
changes the name of an avatar         
         
        ";
%feature("docstring") Piavca::Core::removeAvatar "
void Core::removeAvatar(Avatar *avatar)
         
removes and avatar         
         
        ";
%feature("docstring") Piavca::Core::initAvatar "
void Core::initAvatar(Avatar *avatar, tstring avatarId, bool bailOnMissedJoints=false, const Vec &Position=Vec(0.0, 0.0, 0.0), const Quat &Orientation=Quat(1.0, 0.0, 0.0, 0.0))
         
Initialises an avatar.         
         
You pass in a pointer to the avatar and an id with which to initialise it. It creates an implementation object which will actually be a platform dependant sub type of AvatarImp. It then sets some stuff up and stores a pointer to the avatar.         ";
%feature("docstring") Piavca::Core::getObject "
Object * Core::getObject(tstring objectName)
         
get a named object         
         
        ";
%feature("docstring") Piavca::Core::numObjects "
int Piavca::Core::numObjects()
         
get the number of avatars         
         
        ";
%feature("docstring") Piavca::Core::getObject "
Object * Core::getObject(int i)
         
get the ith avatar in the list (used for interating over all avatars)         
         
        ";
%feature("docstring") Piavca::Core::renameObject "
void Core::renameObject(tstring oldName, tstring newName)
         
changes the name of an avatar         
         
        ";
%feature("docstring") Piavca::Core::removeObject "
void Core::removeObject(Object *object)
         
removes and avatar         
         
        ";
%feature("docstring") Piavca::Core::initObject "
void Core::initObject(Object *object, tstring objectId, const Vec &Position=Vec(0.0, 0.0, 0.0), const Quat &Orientation=Quat(1.0, 0.0, 0.0, 0.0))
         
Initialises an object.         
         
You pass in a pointer to the object and an id with which to initialise it. It creates an implementation object which will actually be a platform dependant sub type of ObjectImp. It then sets some stuff up and stores a pointer to the object.         ";
%feature("docstring") Piavca::Core::initMotion "
void Core::initMotion(TrackMotion *mot, tstring filename=_PSTR(\"\"), bool facial=false, int flags=0, Motion *basePosture=NULL)
         
Initialises a TrackMotion object.         
         
You pass in a pointer to the TrackMotion and a filename with which to initialise it. It creates an implementation object which will actually be a platform dependant sub type of MotionImp.         ";
%feature("docstring") Piavca::Core::setDir "
void Piavca::Core::setDir(tstring _dir)
         
set the search directory         
         
        ";
%feature("docstring") Piavca::Core::getTime "
float Piavca::Core::getTime()
         
get the current time in seconds         
         
        ";
%feature("docstring") Piavca::Core::getSystemTime "
virtual float Piavca::Core::getSystemTime()=0
         
get the current time in seconds         
         
        ";
%feature("docstring") Piavca::Core::setAutoTimeOff "
void Piavca::Core::setAutoTimeOff()
         
turns off the automatic updating of the current time from the system clock         
         
        ";
%feature("docstring") Piavca::Core::setAutoTimeOn "
void Piavca::Core::setAutoTimeOn()
         
turns on the automatic updating of the current time from the system clock         
         
        ";
%feature("docstring") Piavca::Core::setCurrentTime "
void Piavca::Core::setCurrentTime(float t)
         
sets the current time (if its not linked to the system clock         
         
        ";
%feature("docstring") Piavca::Core::addError "
void Core::addError(tstring details)
         
        
         
        ";
%feature("docstring") Piavca::Core::error "
tostringstream& Piavca::Core::error()
         
        
         
        ";
%feature("docstring") Piavca::Core::clearErrors "
void Core::clearErrors()
         
        
         
        ";
%feature("docstring") Piavca::Core::getErrors "
tstring Piavca::Core::getErrors()
         
        
         
        ";
%feature("docstring") Piavca::Core::errorsPresent "
bool Piavca::Core::errorsPresent()
         
        
         
        ";
%feature("docstring") Piavca::Core::addWarning "
void Core::addWarning(tstring details)
         
        
         
        ";
%feature("docstring") Piavca::Core::Warning "
tostringstream& Piavca::Core::Warning()
         
        
         
        ";
%feature("docstring") Piavca::Core::clearWarnings "
void Core::clearWarnings()
         
        
         
        ";
%feature("docstring") Piavca::Core::getWarnings "
tstring Piavca::Core::getWarnings()
         
        
         
        ";
%feature("docstring") Piavca::Core::warningsPresent "
bool Piavca::Core::warningsPresent()
         
        
         
        ";
%feature("docstring") Piavca::Core::exceptionsOn "
bool Piavca::Core::exceptionsOn()
         
        
         
        ";
%feature("docstring") Piavca::Core::setExceptionsOn "
void Piavca::Core::setExceptionsOn()
         
        
         
        ";
%feature("docstring") Piavca::Core::setExceptionsOff "
void Piavca::Core::setExceptionsOff()
         
        
         
        ";
%feature("docstring") Piavca::Core::log "
std::ostream& Piavca::Core::log()
         
        
         
        ";
%feature("docstring") Piavca::Core::addProfilePoint "
int Piavca::Core::addProfilePoint(tstring name)
         
        
         
creates a new profile point for logging profile data. Returns and id which can be used to access the profile point. You would normally create the point id as a static variable within the function you are profiling.         ";
%feature("docstring") Piavca::Core::profilePointStart "
void Piavca::Core::profilePointStart(int i)
         
marks the start of a profile point         
         
        ";
%feature("docstring") Piavca::Core::profilePointEnd "
void Piavca::Core::profilePointEnd(int i)
         
marks the end of the profile point         
         
        ";
%feature("docstring") Piavca::Core::printProfileData "
void Core::printProfileData()
         
prints out the profiling data that has been collected.         
         
        ";
%feature("docstring") Piavca::Core::getCore "
static Core* Piavca::Core::getCore()
         
a static function to get the core instances (there is only one)         
         
        ";
%feature("docstring") Piavca::Core::createAvatarImp "
virtual AvatarImp* Piavca::Core::createAvatarImp(tstring avatarId, bool bailOnMissedJoints, const Vec &Position, const Quat &Orientation)=0
         
creates an avatar implementation         
         
(see Avatar.h for discussion of the interface implementation architecture)         ";
%feature("docstring") Piavca::Core::createObjectImp "
virtual ObjectImp* Piavca::Core::createObjectImp(tstring objectId, const Vec &Position, const Quat &Orientation)=0
         
creates an object implementation         
         
(see Object.h for discussion of the interface implementation architecture)         ";
%feature("docstring") Piavca::Core::createMotionImp "
virtual MotionImp* Piavca::Core::createMotionImp(tstring filename, bool facial, int flags, Motion *basePosture=NULL)=0
         
creates a motion implementation         
         
        ";
%feature("docstring") Piavca::Core::removeMotion "
void Core::removeMotion(Motion *mot)
         
removes a motion if its reference count is zero and its not owned by the core         
         
Though time is represented in floating point, keyframes can only be set as integers to avoid problems with rounding errors. The granularity is the conversion factor between the two.         ";
%feature("docstring") CTga " 

    
       
     see also: tga.h";

%feature("docstring") CTga::CTga "
CTga::CTga()
         
        
         
        ";
%feature("docstring") CTga::GetSizeX "
int CTga::GetSizeX()
         
        
         
        ";
%feature("docstring") CTga::GetSizeY "
int CTga::GetSizeY()
         
        
         
        ";
%feature("docstring") CTga::Bpp "
int CTga::Bpp()
         
        
         
        ";
%feature("docstring") CTga::GetPointer "
unsigned char* CTga::GetPointer()
         
        
         
        ";
%feature("docstring") CTga::ReadFile "
int CTga::ReadFile(const char *str)
         
        
         
        ";
%feature("docstring") CTga::Release "
int CTga::Release()
         
        
         
        ";
%feature("docstring") CTgaHeader " 

    
       
Read a TGA bitmap Le TGA file must been :
Greyscale 8 bit per pixel uncompressedColor 24 bit per pixel uncompressedColor 32 bit per pixel uncompressedColor 24 bit per pixel compressed (RLE)Color 32 bit per pixel compressed (RLE)


str


: File name 



dest


: Pointer on the destination Pointeur vers lequel l'image est située après la fonction 



SizeX


: width of the bitmap 



SizeY


: height of the bitmap 



Bpp


: Bit per pixel of the bitmap (8,24 or 32) 


     see also: tga.h";

%feature("docstring") Piavca::DiadicGazeMotion " 

    
       
     see also: DiadicGazeMotion.h";

%feature("docstring") Piavca::DiadicGazeMotion::DiadicGazeMotion "
Piavca::DiadicGazeMotion::DiadicGazeMotion(Avatar *other, float endTime=-1.0, float interval=0.01)
         
        
         
        ";
%feature("docstring") Piavca::DiadicGazeMotion::DiadicGazeMotion "
Piavca::DiadicGazeMotion::DiadicGazeMotion(const DiadicGazeMotion &dg)
         
        
         
        ";
%feature("docstring") Piavca::DiadicGazeMotion::~DiadicGazeMotion "
Piavca::DiadicGazeMotion::~DiadicGazeMotion()
         
        
         
        ";
%feature("docstring") Piavca::DiadicGazeMotion::clone "
virtual Motion* Piavca::DiadicGazeMotion::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") Piavca::DiadicGazeMotion::setTalking "
void Piavca::DiadicGazeMotion::setTalking(talkingstate t)
         
        
         
        ";
%feature("docstring") Piavca::DiadicGazeMotion::setTalkingLookAt "
void Piavca::DiadicGazeMotion::setTalkingLookAt(float f)
         
        
         
        ";
%feature("docstring") Piavca::DiadicGazeMotion::setTalkingLookAway "
void Piavca::DiadicGazeMotion::setTalkingLookAway(float f)
         
        
         
        ";
%feature("docstring") Piavca::DiadicGazeMotion::setListeningLookAt "
void Piavca::DiadicGazeMotion::setListeningLookAt(float f)
         
        
         
        ";
%feature("docstring") Piavca::DiadicGazeMotion::setListeningLookAway "
void Piavca::DiadicGazeMotion::setListeningLookAway(float f)
         
        
         
        ";
%feature("docstring") Piavca::DiadicGazeMotion::setNeitherLookAt "
void Piavca::DiadicGazeMotion::setNeitherLookAt(float f)
         
        
         
        ";
%feature("docstring") Piavca::DiadicGazeMotion::setNeitherLookAway "
void Piavca::DiadicGazeMotion::setNeitherLookAway(float f)
         
        
         
        ";
%feature("docstring") Piavca::DiadicGazeMotion::setGazeFollow "
void Piavca::DiadicGazeMotion::setGazeFollow(float f)
         
        
         
        ";
%feature("docstring") Piavca::DiadicGazeMotion::setOther "
void Piavca::DiadicGazeMotion::setOther(Avatar *other)
         
        
         
        ";
%feature("docstring") Piavca::DiadicGazeMotion::getOther "
Avatar* Piavca::DiadicGazeMotion::getOther()
         
        
         
        ";
%feature("docstring") Piavca::DiadicGazeMotion::addGazeFollowTarget "
void Piavca::DiadicGazeMotion::addGazeFollowTarget(tstring name)
         
        
         
        ";
%feature("docstring") Piavca::DiadicGazeMotion::notifyChange "
void Piavca::DiadicGazeMotion::notifyChange(tstring target)
         
        
         
        ";
%feature("docstring") Piavca::DiadicGazeMotion::lookAt "
virtual bool Piavca::DiadicGazeMotion::lookAt(tstring name, bool force=false)
         
        
         
        ";
%feature("docstring") Piavca::DiadicGazeMotion::reblend "
virtual void Piavca::DiadicGazeMotion::reblend(float time)
         
saves the state of the motion at time and start blending the motion back into that from the start         
         
        ";
%feature("docstring") Piavca::Exception " 

A base exception class for handling errors in the architecture.     
       
     see also: PiavcaException.h";

%feature("docstring") Piavca::Exception::Exception "
Piavca::Exception::Exception(tstring _details)
         
        
         
        ";
%feature("docstring") Piavca::Exception::Exception "
Piavca::Exception::Exception(const Exception &e)
         
        
         
        ";
%feature("docstring") Piavca::Exception::getDetails "
const tstring& Piavca::Exception::getDetails()
         
        
         
        ";
%feature("docstring") Piavca::FileErrorException " 

An exception class for file read errors.     
       
     see also: PiavcaException.h";

%feature("docstring") Piavca::FileErrorException::FileErrorException "
Piavca::FileErrorException::FileErrorException(tstring fileName, tstring error)
         
        
         
        ";
%feature("docstring") Piavca::FileNotFoundException " 

An exception class for file not found errors.     
       
     see also: PiavcaException.h";

%feature("docstring") Piavca::FileNotFoundException::FileNotFoundException "
Piavca::FileNotFoundException::FileNotFoundException(tstring fileName)
         
        
         
        ";
%feature("docstring") findId " 

    
       
     see also: ";

%feature("docstring") findId::findId "
findId::findId(int f)
         
        
         
        ";
%feature("docstring") Piavca::LookAtMotion " 

    
       
A motion class that makes the avatar look at a target. The avatar will turn to look at the given target with eyes, head, and body. The target can either be an avatar, an object or a vector location.      see also: LookAtMotion.h";

%feature("docstring") Piavca::LookAtMotion::LookAtMotion "
Piavca::LookAtMotion::LookAtMotion(Avatar *target, int joint, float _endTime=-1, float _interval=0.5)
         
        
         
create with an avatar target. Pass in an avatar, and a joint of that avatar to look at         ";
%feature("docstring") Piavca::LookAtMotion::LookAtMotion "
Piavca::LookAtMotion::LookAtMotion(Object *target, float _endTime=-1, float _interval=0.5)
         
create with an object target         
         
        ";
%feature("docstring") Piavca::LookAtMotion::LookAtMotion "
Piavca::LookAtMotion::LookAtMotion(const Vec &target, float _endTime=-1, bool _local=false, float _interval=0.5)
         
        
         
create with a location target There is also a local flag, to indicate whether the vector is local to the avatar or in world coordinates. NB: LookAtMotion assumes you are using a motion queue, it won't work properly otherwise.         ";
%feature("docstring") Piavca::LookAtMotion::LookAtMotion "
Piavca::LookAtMotion::LookAtMotion(const LookAtMotion &lam)
         
        
         
        ";
%feature("docstring") Piavca::LookAtMotion::clone "
virtual Motion* Piavca::LookAtMotion::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") Piavca::LookAtMotion::isFacial "
virtual bool Piavca::LookAtMotion::isFacial()
         
whether it is a face or body motion         
         
        ";
%feature("docstring") Piavca::LookAtMotion::isRandomAccess "
virtual bool Piavca::LookAtMotion::isRandomAccess()
         
whether you can access a motions value at frames other than the current one         
         
        ";
%feature("docstring") Piavca::LookAtMotion::load "
void LookAtMotion::load(Avatar *av)
         
called when the motion is loaded into an avatar         
         
        ";
%feature("docstring") Piavca::LookAtMotion::reblend "
void LookAtMotion::reblend(float time)
         
        
         
        ";
%feature("docstring") Piavca::LookAtMotion::setTarget "
void Piavca::LookAtMotion::setTarget(Avatar *target, int joint)
         
        
         
sets the target to an avatar. Pass in an avatar, and a joint of that avatar to look at         ";
%feature("docstring") Piavca::LookAtMotion::setTarget "
void Piavca::LookAtMotion::setTarget(Object *target)
         
sets the target to an object         
         
        ";
%feature("docstring") Piavca::LookAtMotion::setTarget "
void Piavca::LookAtMotion::setTarget(Vec target, bool _local=false)
         
        
         
sets the target to a location There is also a local flag, to indicate whether the vector is local to the avatar or in world coordinates         ";
%feature("docstring") Piavca::LookAtMotion::getTargetName "
tstring Piavca::LookAtMotion::getTargetName()
         
        
         
        ";
%feature("docstring") Piavca::LookAtMotion::setHeadActive "
void Piavca::LookAtMotion::setHeadActive(bool b=true)
         
        
         
        ";
%feature("docstring") Piavca::LookAtMotion::setBodyActive "
void Piavca::LookAtMotion::setBodyActive(bool b=true)
         
        
         
        ";
%feature("docstring") Piavca::LookAtMotion::setTurnBodyVertical "
void Piavca::LookAtMotion::setTurnBodyVertical(bool b=true)
         
        
         
        ";
%feature("docstring") Piavca::LookAtMotion::setTurnBodyFull "
void Piavca::LookAtMotion::setTurnBodyFull(bool b=true)
         
        
         
        ";
%feature("docstring") Piavca::LookAtMotion::setLeanTowards "
void Piavca::LookAtMotion::setLeanTowards(bool b=true)
         
        
         
        ";
%feature("docstring") Piavca::LookAtMotion::setEyesLimit "
void Piavca::LookAtMotion::setEyesLimit(float f)
         
        
         
        ";
%feature("docstring") Piavca::LookAtMotion::setHeadBodyLimit "
void Piavca::LookAtMotion::setHeadBodyLimit(float f)
         
        
         
        ";
%feature("docstring") Piavca::LookAtMotion::setEyesMorphAngle "
void Piavca::LookAtMotion::setEyesMorphAngle(float f)
         
        
         
        ";
%feature("docstring") Piavca::LookAtMotion::setEndTime "
void Piavca::LookAtMotion::setEndTime(float time)
         
sets when the avatar should stop looing         
         
        ";
%feature("docstring") Piavca::LookAtMotion::getMotionLength "
virtual float Piavca::LookAtMotion::getMotionLength() const 
         
returns the length of the motion         
         
        ";
%feature("docstring") Piavca::LookAtMotion::isNull "
bool Piavca::LookAtMotion::isNull(int trackId) const 
         
given a track ID tests whether it actually points to anything or if its null         
         
        ";
%feature("docstring") Piavca::LookAtMotion::isNullFacial "
bool Piavca::LookAtMotion::isNullFacial(int trackId) const 
         
this is a version of isNull that is used when the LookAtMotion is pretending to be facial         
         
        ";
%feature("docstring") Piavca::LookAtMotion::getTrackType "
virtual trackType Piavca::LookAtMotion::getTrackType(int trackId) const 
         
get the type of the track corresponding to an ID         
         
        ";
%feature("docstring") Piavca::LookAtMotion::canLookAt "
bool LookAtMotion::canLookAt(Vec location)
         
works out whether the avatar can comfortably turn to look at a position         
         
        ";
%feature("docstring") Piavca::LookAtMotion::getFloatValueAtTimeInternal "
float LookAtMotion::getFloatValueAtTimeInternal(int trackId, float time)
         
get the value of a track at a given time (only works for floats)         
         
        ";
%feature("docstring") Piavca::LookAtMotion::getVecValueAtTimeInternal "
Vec LookAtMotion::getVecValueAtTimeInternal(int trackId, float time)
         
get the value of a track at a given time (only works for Vecs)         
         
        ";
%feature("docstring") Piavca::LookAtMotion::getQuatValueAtTimeInternal "
Quat LookAtMotion::getQuatValueAtTimeInternal(int trackId, float time)
         
get the value of a track at a given time (only works for Quats)         
         
        ";
%feature("docstring") Piavca::LookAtMotion::init "
void LookAtMotion::init()
         
        
         
        ";
%feature("docstring") Piavca::LookAtToFacial " 

a motion filter that takes a LookAtMotion and pretends its a facial motion     
       
     see also: LookAtMotion.h";

%feature("docstring") Piavca::LookAtToFacial::LookAtToFacial "
Piavca::LookAtToFacial::LookAtToFacial(LookAtMotion *m)
         
        
         
Pass in the motion to be filtered and a scale factor         ";
%feature("docstring") Piavca::LookAtToFacial::LookAtToFacial "
Piavca::LookAtToFacial::LookAtToFacial(const LookAtToFacial &sm)
         
        
         
        ";
%feature("docstring") Piavca::LookAtToFacial::clone "
virtual Motion* Piavca::LookAtToFacial::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") Piavca::LookAtToFacial::load "
virtual void Piavca::LookAtToFacial::load(Avatar *av)
         
called when the motion is loaded into an avatar         
         
        ";
%feature("docstring") Piavca::LookAtToFacial::isFacial "
virtual bool Piavca::LookAtToFacial::isFacial()
         
whether it is a face or body motion         
         
        ";
%feature("docstring") Piavca::LookAtToFacial::isNull "
virtual bool Piavca::LookAtToFacial::isNull(int trackId) const 
         
given an iterator tests whether it actually points to anything or if its null         
         
        ";
%feature("docstring") Piavca::LookAtToFacial::getFloatValueAtTimeInternal "
virtual PIAVCA_EXPORT float Piavca::LookAtToFacial::getFloatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") Piavca::LookAtToFacial::getVecValueAtTimeInternal "
virtual PIAVCA_EXPORT Vec Piavca::LookAtToFacial::getVecValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe (vec values are scaled)         
         
        ";
%feature("docstring") Piavca::LookAtToFacial::getQuatValueAtTimeInternal "
virtual PIAVCA_EXPORT Quat Piavca::LookAtToFacial::getQuatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") Piavca::LoopMotion " 

a motion filter that makes a motion loop continuously     
       
     see also: LoopMotion.h";

%feature("docstring") Piavca::LoopMotion::LoopMotion "
Piavca::LoopMotion::LoopMotion(Motion *mot=NULL, float _endTime=-1, float interval=0.01)
         
pass in the motion to loop and an optional blend interval,         
         
(How long it takes to blend from the end back to the beginning)         ";
%feature("docstring") Piavca::LoopMotion::LoopMotion "
Piavca::LoopMotion::LoopMotion(const LoopMotion &l)
         
        
         
        ";
%feature("docstring") Piavca::LoopMotion::clone "
virtual Motion* Piavca::LoopMotion::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") Piavca::LoopMotion::getMotionLength "
virtual float Piavca::LoopMotion::getMotionLength() const 
         
gets the motion length (transition start + blend interval + length of second motion)         
         
        ";
%feature("docstring") Piavca::LoopMotion::setEndTime "
void Piavca::LoopMotion::setEndTime(float t)
         
        
         
        ";
%feature("docstring") Piavca::LoopMotion::getFloatValueAtTimeInternal "
virtual float Piavca::LoopMotion::getFloatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
if the end has been reached it reblends to start again at the beginning         ";
%feature("docstring") Piavca::LoopMotion::getVecValueAtTimeInternal "
virtual Vec Piavca::LoopMotion::getVecValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
if the end has been reached it reblends to start again at the beginning         ";
%feature("docstring") Piavca::LoopMotion::getQuatValueAtTimeInternal "
virtual Quat Piavca::LoopMotion::getQuatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
if the end has been reached it reblends to start again at the beginning         ";
%feature("docstring") Piavca::MaskedMotion " 

plays different motions on different joints.     
       
It uses a mask to tell which motion to play on which joint.      see also: MaskedMotion.h";

%feature("docstring") Piavca::MaskedMotion::MaskedMotion "
MaskedMotion::MaskedMotion()
         
        
         
        ";
%feature("docstring") Piavca::MaskedMotion::MaskedMotion "
MaskedMotion::MaskedMotion(Motion *_mot1, const MotionMask &_mask1, Motion *_mot2, const MotionMask &_mask2, bool _useSecondary=true)
         
initialise with 1 motions, each with its own mask         
         
If the useSecondary flag is set then if neither motion has a mask set then it will play the joint with motion1 if the track exists otherwise motion2. If it is not set then joints that are in neither mask are unaffected.         ";
%feature("docstring") Piavca::MaskedMotion::MaskedMotion "
MaskedMotion::MaskedMotion(const MaskedMotion &mm)
         
        
         
        ";
%feature("docstring") Piavca::MaskedMotion::clone "
virtual Motion* Piavca::MaskedMotion::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") Piavca::MaskedMotion::setUseSecondary "
void Piavca::MaskedMotion::setUseSecondary(bool val)
         
        
         
        ";
%feature("docstring") Piavca::MaskedMotion::setMask1 "
void Piavca::MaskedMotion::setMask1(const MotionMask &mask)
         
        
         
        ";
%feature("docstring") Piavca::MaskedMotion::setMask2 "
void Piavca::MaskedMotion::setMask2(const MotionMask &mask)
         
        
         
        ";
%feature("docstring") Piavca::MaskedMotion::addToMask1 "
void Piavca::MaskedMotion::addToMask1(int trackId)
         
        
         
        ";
%feature("docstring") Piavca::MaskedMotion::removeFromMask1 "
void Piavca::MaskedMotion::removeFromMask1(int trackId)
         
        
         
        ";
%feature("docstring") Piavca::MaskedMotion::addToMask2 "
void Piavca::MaskedMotion::addToMask2(int trackId)
         
        
         
        ";
%feature("docstring") Piavca::MaskedMotion::removeFromMask2 "
void Piavca::MaskedMotion::removeFromMask2(int trackId)
         
        
         
        ";
%feature("docstring") Piavca::MaskedMotion::getFloatValueAtTimeInternal "
float MaskedMotion::getFloatValueAtTimeInternal(int trackId, float time)
         
internal version of getFloatValueAtTime, to be overridden         
         
        ";
%feature("docstring") Piavca::MaskedMotion::getVecValueAtTimeInternal "
Vec MaskedMotion::getVecValueAtTimeInternal(int trackId, float time)
         
internal version of getVecValueAtTime, to be overridden         
         
        ";
%feature("docstring") Piavca::MaskedMotion::getQuatValueAtTimeInternal "
Quat MaskedMotion::getQuatValueAtTimeInternal(int trackId, float time)
         
internal version of getQuatValueAtTime, to be overridden         
         
        ";
%feature("docstring") Piavca::Motion " 

An abstract interface to represent motion.     
       
This is an abstract interface that represents all types of animation in a way that is independent of individual Avatars. It can be used to represent keyframe animation, motion combination, procedural animatio or real time animation streams. The key abstraction is that motion consists of a number of tracks, each normally corresponding to a joint of the avatar. The track is a continuous, time varying stream of data value (either of float, Vec or Quat type). The fundamental operation on a track is to query it for its value at a given time. Like joints tracks are represented by integer IDs, the IDs of a corresponding track and joint are the same so testing for equivelence is easy. Tracks are accessed by passing the appropriate ID to a method of the motion object.      see also: Motion.h";

%feature("docstring") Piavca::Motion::Motion "
Piavca::Motion::Motion()
         
default constructor         
         
Though time is represented in floating point, keyframes can only be set as integers to avoid problems with rounding errors. The granularity is the conversion factor between the two.         ";
%feature("docstring") Piavca::Motion::Motion "
Piavca::Motion::Motion(const Motion &mot)
         
        
         
        ";
%feature("docstring") Piavca::Motion::~Motion "
virtual Piavca::Motion::~Motion()
         
        
         
        ";
%feature("docstring") Piavca::Motion::clone "
virtual Motion* Piavca::Motion::clone()=0
         
creates a copy of the motion         
         
        ";
%feature("docstring") Piavca::Motion::printInfo "
void Motion::printInfo()
         
prints out info about the motion heirarchy         
         
        ";
%feature("docstring") Piavca::Motion::load "
virtual void Piavca::Motion::load(Avatar *av)
         
called when the motion is loaded into an avatar         
         
        ";
%feature("docstring") Piavca::Motion::unload "
virtual void Piavca::Motion::unload()
         
called when the motion is unloaded from an avatar         
         
        ";
%feature("docstring") Piavca::Motion::loaded "
virtual bool Piavca::Motion::loaded()
         
checks if the motion has been loaded into an avatar         
         
        ";
%feature("docstring") Piavca::Motion::setStartTime "
virtual void Piavca::Motion::setStartTime(float t)
         
sets the start time of the motion. Called when its loaded into an avatar.         
         
        ";
%feature("docstring") Piavca::Motion::getStartTime "
float Piavca::Motion::getStartTime()
         
return the start time of the motion         
         
        ";
%feature("docstring") Piavca::Motion::getEndTime "
float Piavca::Motion::getEndTime()
         
returns the end time of the motion         
         
        ";
%feature("docstring") Piavca::Motion::reset "
virtual void Piavca::Motion::reset()
         
does any resetting needed         
         
        ";
%feature("docstring") Piavca::Motion::Reference "
void Piavca::Motion::Reference()
         
registers an owner for a motion, the motion will not be deleted until disposed is called.         
         
Internally this increments the reference count.         ";
%feature("docstring") Piavca::Motion::Dispose "
void Motion::Dispose()
         
decrements the references count and deletes the motion if it reaches zero         
         
        ";
%feature("docstring") Piavca::Motion::makeTemp "
void Piavca::Motion::makeTemp()
         
makes a motion temporary so that it is removed when all avatars have finished with it         
         
        ";
%feature("docstring") Piavca::Motion::setName "
void Piavca::Motion::setName(tstring nm)
         
gives a name to the motion         
         
        ";
%feature("docstring") Piavca::Motion::getName "
tstring Piavca::Motion::getName()
         
returns the name of the motion         
         
        ";
%feature("docstring") Piavca::Motion::findSub "
virtual Motion* Piavca::Motion::findSub(tstring nm)
         
finds the first submotion with a given name         
         
        ";
%feature("docstring") Piavca::Motion::findSubByType "
virtual Motion* Piavca::Motion::findSubByType(const type_info &ty)
         
finds the first submotion with a given type         
         
        ";
%feature("docstring") Piavca::Motion::saveMotion "
void Motion::saveMotion(tstring filename)
         
saves the motion to file in bvh format         
         
        ";
%feature("docstring") Piavca::Motion::getMotionLength "
virtual float Piavca::Motion::getMotionLength() const =0
         
gets the time of the end of the motion         
         
Though time is represented in floating point, keyframes can only be set as integers to avoid problems with rounding errors. The granularity is the conversion factor between the two.         ";
%feature("docstring") Piavca::Motion::isFacial "
virtual bool Piavca::Motion::isFacial()
         
whether it is a face or body motion         
         
        ";
%feature("docstring") Piavca::Motion::isRandomAccess "
virtual bool Piavca::Motion::isRandomAccess()
         
whether you can access a motions value at frames other than the current one         
         
        ";
%feature("docstring") Piavca::Motion::begin "
int Piavca::Motion::begin() const 
         
the ID of the first track that is present in the motion (the ordering is arbitrary)         
         
        ";
%feature("docstring") Piavca::Motion::end "
int Motion::end() const 
         
the last track + 1         
         
        ";
%feature("docstring") Piavca::Motion::next "
int Motion::next(int &trackId) const 
         
given a track ID get the next valid ID         
         
        ";
%feature("docstring") Piavca::Motion::isNull "
virtual bool Piavca::Motion::isNull(int trackId) const =0
         
given a track ID tests whether it actually points to anything or if its null         
         
        ";
%feature("docstring") Piavca::Motion::getTrackType "
virtual trackType Piavca::Motion::getTrackType(int trackId) const =0
         
get the type of the track corresponding to an ID         
         
        ";
%feature("docstring") Piavca::Motion::pause "
void Motion::pause()
         
pause the motion so that it can be restarted from the current point         
         
        ";
%feature("docstring") Piavca::Motion::unpause "
void Motion::unpause()
         
        
         
        ";
%feature("docstring") Piavca::Motion::getFloatValueAtTime "
float Piavca::Motion::getFloatValueAtTime(int trackId, float time)
         
get the value of a track at a given time (only works for floats)         
         
        ";
%feature("docstring") Piavca::Motion::getVecValueAtTime "
Vec Piavca::Motion::getVecValueAtTime(int trackId, float time)
         
get the value of a track at a given time (only works for Vecs)         
         
        ";
%feature("docstring") Piavca::Motion::getQuatValueAtTime "
Quat Piavca::Motion::getQuatValueAtTime(int trackId, float time)
         
get the value of a track at a given time (only works for Quats)         
         
        ";
%feature("docstring") Piavca::Motion::getFloatValueAtTimeInternal "
virtual float Piavca::Motion::getFloatValueAtTimeInternal(int trackId, float time)=0
         
internal version of getFloatValueAtTime, to be overridden         
         
        ";
%feature("docstring") Piavca::Motion::getVecValueAtTimeInternal "
virtual Vec Piavca::Motion::getVecValueAtTimeInternal(int trackId, float time)=0
         
internal version of getVecValueAtTime, to be overridden         
         
        ";
%feature("docstring") Piavca::Motion::getQuatValueAtTimeInternal "
virtual Quat Piavca::Motion::getQuatValueAtTimeInternal(int trackId, float time)=0
         
internal version of getQuatValueAtTime, to be overridden         
         
        ";
%feature("docstring") Piavca::MotionAdder " 

Adds the result of two motions, performing them simultaneously.     
       
The results is the sum of the effects of both motions (in fact with rotations this is achieved with quaternion multiplication but the effect is similar to vector addition. An optional parameter can scale the effect of the second motion.      see also: MotionAdder.h";

%feature("docstring") Piavca::MotionAdder::MotionAdder "
Piavca::MotionAdder::MotionAdder(Motion *m1=NULL, Motion *m2=NULL, float _scaleSecond=1.0)
         
        
         
        ";
%feature("docstring") Piavca::MotionAdder::MotionAdder "
Piavca::MotionAdder::MotionAdder(const MotionAdder &ma)
         
        
         
        ";
%feature("docstring") Piavca::MotionAdder::clone "
virtual Motion* Piavca::MotionAdder::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") Piavca::MotionAdder::setScaleSecond "
void Piavca::MotionAdder::setScaleSecond(float s)
         
this is a scale factor applied to the second motion         
         
        ";
%feature("docstring") Piavca::MotionAdder::getFloatValueAtTimeInternal "
float MotionAdder::getFloatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
The results is the sum of the two motions.         ";
%feature("docstring") Piavca::MotionAdder::getVecValueAtTimeInternal "
Vec MotionAdder::getVecValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
The results is the sum of the two motions.         ";
%feature("docstring") Piavca::MotionAdder::getQuatValueAtTimeInternal "
Quat MotionAdder::getQuatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
The results is the quaternion multiplication of the two motions (which is similar to vector addition).         ";
%feature("docstring") Piavca::MotionCal3DImp " 

    
       
     see also: MotionCal3dImp.h";

%feature("docstring") Piavca::MotionCal3DImp::getFloatValueAtTimeInternal "
float MotionCal3DImp::getFloatValueAtTimeInternal(int trackId, float time)
         
get the keyframe value at time (only works for floats)         
         
        ";
%feature("docstring") Piavca::MotionCal3DImp::getVecValueAtTimeInternal "
Vec MotionCal3DImp::getVecValueAtTimeInternal(int trackId, float time)
         
get the keyframe value at time (only works for Vecs)         
         
        ";
%feature("docstring") Piavca::MotionCal3DImp::getQuatValueAtTimeInternal "
Quat MotionCal3DImp::getQuatValueAtTimeInternal(int trackId, float time)
         
get the keyframe value at time (only works for Quats)         
         
        ";
%feature("docstring") Piavca::MotionCal3DImp::addFloatTrack "
void MotionCal3DImp::addFloatTrack(int trackId, float initialValue)
         
add a float track         
         
        ";
%feature("docstring") Piavca::MotionCal3DImp::addVecTrack "
void MotionCal3DImp::addVecTrack(int trackId, const Vec &initialValue)
         
add a Vec track         
         
        ";
%feature("docstring") Piavca::MotionCal3DImp::addQuatTrack "
void MotionCal3DImp::addQuatTrack(int trackId, const Quat &initialValue)
         
add a Quat track         
         
        ";
%feature("docstring") Piavca::MotionCal3DImp::setFloatKeyframe "
void MotionCal3DImp::setFloatKeyframe(int trackId, float time, float value)
         
set keyframe value (or create a new one) (only works for floats)         
         
        ";
%feature("docstring") Piavca::MotionCal3DImp::setFloatKeyframe "
void MotionCal3DImp::setFloatKeyframe(int trackId, float time, float value, float velocity)
         
set keyframe value (or create a new one) with a user specified velocity (only works for floats)         
         
        ";
%feature("docstring") Piavca::MotionCal3DImp::setVecKeyframe "
void MotionCal3DImp::setVecKeyframe(int trackId, float time, Vec value)
         
set keyframe value (or create a new one) (only works for Vecs)         
         
        ";
%feature("docstring") Piavca::MotionCal3DImp::setVecKeyframe "
void MotionCal3DImp::setVecKeyframe(int trackId, float time, Vec value, Vec velocity)
         
set keyframe value (or create a new one) with a user specified velocity (only works for Vecs)         
         
        ";
%feature("docstring") Piavca::MotionCal3DImp::setQuatKeyframe "
void MotionCal3DImp::setQuatKeyframe(int trackId, float time, Quat value)
         
set keyframe value (or create a new one) (only works for Quats)         
         
        ";
%feature("docstring") Piavca::MotionCal3DImp::setQuatKeyframe "
void MotionCal3DImp::setQuatKeyframe(int trackId, float time, Quat value, Quat velocity)
         
set keyframe value (or create a new one) with a user specified velocity (only works for Quats)         
         
        ";
%feature("docstring") Piavca::MotionCal3DImp::deleteAllTracks "
void MotionCal3DImp::deleteAllTracks()
         
delete all tracks         
         
        ";
%feature("docstring") Piavca::MotionCal3DImp::clearTrack "
void MotionCal3DImp::clearTrack(int trackId, bool createFirstFrame=true)
         
clears a particular track (deletes all keyframes without deleting the track itself)         
         
        ";
%feature("docstring") Piavca::MotionCal3DImp::clearAllTracks "
void MotionCal3DImp::clearAllTracks(bool createFirstFrame=true)
         
clear all tracks (deletes all keyframes without deleting the tracks themselves)         
         
        ";
%feature("docstring") Piavca::MotionCal3DImp::MotionCal3DImp "
MotionCal3DImp::MotionCal3DImp(tstring motionFilename, CalCoreSkeleton *skel)
         
        
         
        ";
%feature("docstring") Piavca::MotionCal3DImp::~MotionCal3DImp "
MotionCal3DImp::~MotionCal3DImp(void)
         
        
         
        ";
%feature("docstring") Piavca::MotionCal3DImp::MotionCal3DImp "
MotionCal3DImp::MotionCal3DImp(const MotionCal3DImp &mot)
         
        
         
        ";
%feature("docstring") Piavca::MotionCal3DImp::clone "
MotionImp * MotionCal3DImp::clone()
         
creates a copy of the motion imp         
         
This is a virtual method in MotionImp which allows you to get a (pointer to a) copy of a motion imp correctly without knowing what type it is.         ";
%feature("docstring") Piavca::MotionCal3DImp::isNull "
bool Piavca::MotionCal3DImp::isNull(int trackId) const 
         
given an iterator tests whether it actually points to anything or if its null         
         
        ";
%feature("docstring") Piavca::MotionCal3DImp::getTrackType "
trackType Piavca::MotionCal3DImp::getTrackType(int trackId) const 
         
get the type of the track corresponding to an iterator         
         
        ";
%feature("docstring") Piavca::MotionCal3DImp::getMotionLength "
float MotionCal3DImp::getMotionLength() const 
         
returns the length of the motion         
         
        ";
%feature("docstring") Piavca::MotionCal3DImp::getNumKeyframes "
int MotionCal3DImp::getNumKeyframes(int trackId)
         
returns the number of keyframes that a particular track has         
         
        ";
%feature("docstring") Piavca::MotionCal3DImp::getKeyframeTime "
float MotionCal3DImp::getKeyframeTime(int trackId, int keyframe)
         
returns the time of a particular keyframe         
         
        ";
%feature("docstring") Piavca::MotionFilter " 

A motion class whose output is some transformation of another motion.     
       
This class is an abstract base class that just provides some common features between motion filters. To actaully do anything you have to override the get[Float/Quat/Vec]ValueAtTime methods to perform whatever opertation you want on the other motion.      see also: MotionFilter.h";

%feature("docstring") Piavca::MotionFilter::MotionFilter "
Piavca::MotionFilter::MotionFilter()
         
default constructor         
         
        ";
%feature("docstring") Piavca::MotionFilter::MotionFilter "
Piavca::MotionFilter::MotionFilter(Motion *mot)
         
pass in the motion to be filtered.         
         
        ";
%feature("docstring") Piavca::MotionFilter::MotionFilter "
Piavca::MotionFilter::MotionFilter(const MotionFilter &mf)
         
        
         
        ";
%feature("docstring") Piavca::MotionFilter::~MotionFilter "
virtual Piavca::MotionFilter::~MotionFilter()
         
        
         
        ";
%feature("docstring") Piavca::MotionFilter::printInfo "
void Piavca::MotionFilter::printInfo()
         
prints out info about the motion heirarchy         
         
        ";
%feature("docstring") Piavca::MotionFilter::findSub "
virtual Motion* Piavca::MotionFilter::findSub(tstring nm)
         
finds the first submotion with a given name         
         
        ";
%feature("docstring") Piavca::MotionFilter::findSubByType "
virtual Motion* Piavca::MotionFilter::findSubByType(const type_info &ty)
         
finds the first submotion with a given type         
         
        ";
%feature("docstring") Piavca::MotionFilter::load "
virtual void Piavca::MotionFilter::load(Avatar *av)
         
called when the motion is loaded into an avatar         
         
        ";
%feature("docstring") Piavca::MotionFilter::unload "
virtual void Piavca::MotionFilter::unload()
         
called when the motion is unloaded from an avatar         
         
        ";
%feature("docstring") Piavca::MotionFilter::loaded "
virtual bool Piavca::MotionFilter::loaded()
         
checks if the motion has been loaded into an avatar         
         
        ";
%feature("docstring") Piavca::MotionFilter::setStartTime "
virtual void Piavca::MotionFilter::setStartTime(float time)
         
sets the start time of the motion. Called when its loaded into an avatar.         
         
        ";
%feature("docstring") Piavca::MotionFilter::reset "
void Piavca::MotionFilter::reset()
         
does any resetting needed         
         
        ";
%feature("docstring") Piavca::MotionFilter::setMotion "
void Piavca::MotionFilter::setMotion(Motion *mot)
         
        
         
        ";
%feature("docstring") Piavca::MotionFilter::getMotionLength "
float Piavca::MotionFilter::getMotionLength() const 
         
gets the length of the motion in seconds         
         
        ";
%feature("docstring") Piavca::MotionFilter::isFacial "
virtual bool Piavca::MotionFilter::isFacial()
         
whether it is a face or body motion         
         
        ";
%feature("docstring") Piavca::MotionFilter::isRandomAccess "
virtual bool Piavca::MotionFilter::isRandomAccess()
         
whether you can access a motions value at frames other than the current one         
         
        ";
%feature("docstring") Piavca::MotionFilter::isNull "
virtual bool Piavca::MotionFilter::isNull(int trackId) const 
         
given an iterator tests whether it actually points to anything or if its null         
         
        ";
%feature("docstring") Piavca::MotionFilter::getTrackType "
trackType Piavca::MotionFilter::getTrackType(int trackId) const 
         
get the type of the track corresponding to an iterator         
         
        ";
%feature("docstring") Piavca::MotionImp " 

An implementation class for TrackMotions, see the track Motion object for full details.     
       
     see also: MotionImp.h";

%feature("docstring") Piavca::MotionImp::addFloatTrack "
virtual void Piavca::MotionImp::addFloatTrack(int trackId, float initialValue)=0
         
add a float track         
         
        ";
%feature("docstring") Piavca::MotionImp::addVecTrack "
virtual void Piavca::MotionImp::addVecTrack(int trackId, const Vec &initialValue)=0
         
add a Vec track         
         
        ";
%feature("docstring") Piavca::MotionImp::addQuatTrack "
virtual void Piavca::MotionImp::addQuatTrack(int trackId, const Quat &initialValue)=0
         
add a Quat track         
         
        ";
%feature("docstring") Piavca::MotionImp::setFloatKeyframe "
virtual void Piavca::MotionImp::setFloatKeyframe(int trackId, float time, float value)=0
         
set keyframe value (or create a new one) (only works for floats)         
         
        ";
%feature("docstring") Piavca::MotionImp::setFloatKeyframe "
virtual void Piavca::MotionImp::setFloatKeyframe(int trackId, float time, float value, float velocity)=0
         
set keyframe value (or create a new one) with a user specified velocity (only works for floats)         
         
        ";
%feature("docstring") Piavca::MotionImp::setVecKeyframe "
virtual void Piavca::MotionImp::setVecKeyframe(int trackId, float time, Vec value)=0
         
set keyframe value (or create a new one) (only works for Vecs)         
         
        ";
%feature("docstring") Piavca::MotionImp::setVecKeyframe "
virtual void Piavca::MotionImp::setVecKeyframe(int trackId, float time, Vec value, Vec velocity)=0
         
set keyframe value (or create a new one) with a user specified velocity (only works for Vecs)         
         
        ";
%feature("docstring") Piavca::MotionImp::setQuatKeyframe "
virtual void Piavca::MotionImp::setQuatKeyframe(int trackId, float time, Quat value)=0
         
set keyframe value (or create a new one) (only works for Quats)         
         
        ";
%feature("docstring") Piavca::MotionImp::setQuatKeyframe "
virtual void Piavca::MotionImp::setQuatKeyframe(int trackId, float time, Quat value, Quat velocity)=0
         
set keyframe value (or create a new one) with a user specified velocity (only works for Quats)         
         
        ";
%feature("docstring") Piavca::MotionImp::getNumKeyframes "
virtual int Piavca::MotionImp::getNumKeyframes(int trackId)=0
         
returns the number of keyframes that a particular track has         
         
        ";
%feature("docstring") Piavca::MotionImp::getKeyframeTime "
virtual float Piavca::MotionImp::getKeyframeTime(int trackId, int keyframe)=0
         
returns the time of a particular keyframe         
         
        ";
%feature("docstring") Piavca::MotionImp::getFloatValueAtTimeInternal "
virtual float Piavca::MotionImp::getFloatValueAtTimeInternal(int trackId, float time)=0
         
get the keyframe value at time (only works for floats)         
         
        ";
%feature("docstring") Piavca::MotionImp::getVecValueAtTimeInternal "
virtual Vec Piavca::MotionImp::getVecValueAtTimeInternal(int trackId, float time)=0
         
get the keyframe value at time (only works for Vecs)         
         
        ";
%feature("docstring") Piavca::MotionImp::getQuatValueAtTimeInternal "
virtual Quat Piavca::MotionImp::getQuatValueAtTimeInternal(int trackId, float time)=0
         
get the keyframe value at time (only works for Quats)         
         
        ";
%feature("docstring") Piavca::MotionImp::~MotionImp "
virtual Piavca::MotionImp::~MotionImp()
         
        
         
        ";
%feature("docstring") Piavca::MotionImp::clone "
virtual MotionImp* Piavca::MotionImp::clone()=0
         
returns a pointer to a copy of the motion imp         
         
This creates a clone that is of the same dynamic type of the Motion Imp. The caller now owns the clone.         ";
%feature("docstring") Piavca::MotionImp::isNull "
virtual bool Piavca::MotionImp::isNull(int trackId) const =0
         
given an iterator tests whether it actually points to anything or if its null         
         
        ";
%feature("docstring") Piavca::MotionImp::getTrackType "
virtual trackType Piavca::MotionImp::getTrackType(int trackId) const =0
         
get the type of the track corresponding to an iterator         
         
        ";
%feature("docstring") Piavca::MotionImp::getMotionLength "
virtual float Piavca::MotionImp::getMotionLength() const =0
         
returns the length of the motion         
         
        ";
%feature("docstring") Piavca::MotionImp::deleteAllTracks "
virtual void Piavca::MotionImp::deleteAllTracks()=0
         
delete all tracks         
         
        ";
%feature("docstring") Piavca::MotionImp::clearTrack "
virtual void Piavca::MotionImp::clearTrack(int trackId, bool createFirstFrame=true)=0
         
clears a particular track (deletes all keyframes without deleting the track itself)         
         
        ";
%feature("docstring") Piavca::MotionImp::clearAllTracks "
virtual void Piavca::MotionImp::clearAllTracks(bool createFirstFrame=true)=0
         
clear all tracks (deletes all keyframes without deleting the tracks themselves)         
         
        ";
%feature("docstring") Piavca::MotionImp::MotionImp "
Piavca::MotionImp::MotionImp(bool _facial=false)
         
        
         
        ";
%feature("docstring") Piavca::MotionMask " 

a set of masks specifying which joints should be played in a masked motion     
       
     see also: MaskedMotion.h";

%feature("docstring") Piavca::MotionMask::MotionMask "
MotionMask::MotionMask(bool _facial=false)
         
        
         
        ";
%feature("docstring") Piavca::MotionMask::MotionMask "
MotionMask::MotionMask(const MotionMask &mm)
         
        
         
        ";
%feature("docstring") Piavca::MotionMask::setMask "
void MotionMask::setMask(int track, bool val=true)
         
sets whether a given track should be played         
         
        ";
%feature("docstring") Piavca::MotionMask::getMask "
bool MotionMask::getMask(int track) const 
         
gets the mask value for a track         
         
        ";
/*        
%feature("docstring") Piavca::MotionParser " 

    
       
     see also: MotionParser.h";

%feature("docstring") Piavca::MotionParser::MotionParser "
Piavca::MotionParser::MotionParser()
         
        
         
        ";
%feature("docstring") Piavca::MotionParser::parseMotion "
virtual Piavca::Motion* Piavca::MotionParser::parseMotion(istringstream &is, std::string currentWord, float scaleFactor)=0
         
        
         
        ";
%feature("docstring") Piavca::MotionParser::editMotion "
virtual Piavca::Motion* Piavca::MotionParser::editMotion(istringstream &is)=0
         
        
         
        ";
%feature("docstring") Piavca::MotionParser::editAvatarMotion "
virtual void Piavca::MotionParser::editAvatarMotion(Avatar *av, bool facial, istringstream &is)=0
         
        
         
        ";
%feature("docstring") Piavca::MotionParser::parseMotion "
static Motion* Piavca::MotionParser::parseMotion(std::string s, float scaleFactor=1.0f)
         
        
         
        ";
%feature("docstring") Piavca::MotionParser::parseMotion "
static Motion* Piavca::MotionParser::parseMotion(istringstream &is, float scaleFactor, MotionParser **mp)
         
        
         
        ";
%feature("docstring") Piavca::MotionParser::parseMotion "
PIAVCA_DECL Piavca::Motion * MotionParser::parseMotion(istringstream &is, std::string currentWord, float scaleFactor, MotionParser **mp)
         
        
         
        ";
%feature("docstring") Piavca::MotionParser::addMotionCommand "
void MotionParser::addMotionCommand(tstring name, MotionParser *command)
         
        
         
        ";
%feature("docstring") Piavca::MotionParser::getMotionCommand "
MotionParser * MotionParser::getMotionCommand(tstring name)
         
        
         
        ";
%feature("docstring") Piavca::MotionParser::setUpMotionCommands "
void MotionParser::setUpMotionCommands()
         
        
         
        ";
%feature("docstring") Piavca::MotionParserTyped " 

    
       
     see also: ";

%feature("docstring") Piavca::MotionParserTyped::MotionParserTyped "
Piavca::MotionParserTyped< T >::MotionParserTyped()
         
        
         
        ";
%feature("docstring") Piavca::MotionParserTyped::parseMotion "
virtual Piavca::Motion* Piavca::MotionParserTyped< T >::parseMotion(istringstream &is, std::string currentWord, float scaleFactor)
         
        
         
        ";
%feature("docstring") Piavca::MotionParserTyped::editMotion "
virtual Piavca::Motion* Piavca::MotionParserTyped< T >::editMotion(istringstream &is)
         
        
         
        ";
%feature("docstring") Piavca::MotionParserTyped::editAvatarMotion "
virtual void Piavca::MotionParserTyped< T >::editAvatarMotion(Avatar *av, bool facial, istringstream &is)
         
        
         
        ";
%feature("docstring") Piavca::MotionParserTyped::editMotionInternal "
void Piavca::MotionParserTyped< T >::editMotionInternal(T *mot, istringstream &is)
         
        
         
        ";
%feature("docstring") Piavca::MotionSaver " 

    
       
Saves the kefyrames of a motion while its playing on a character This sits between a motion and a character passing the data unchanged between the two, but it also saves the data as keyframes. Call save to save it to file in the Piavca (.pia) format      see also: MotionSaver.h";

%feature("docstring") Piavca::MotionSaver::MotionSaver "
Piavca::MotionSaver::MotionSaver(Motion *mot)
         
        
         
        ";
%feature("docstring") Piavca::MotionSaver::MotionSaver "
Piavca::MotionSaver::MotionSaver(const MotionSaver &to)
         
        
         
        ";
%feature("docstring") Piavca::MotionSaver::clone "
virtual Motion* Piavca::MotionSaver::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") Piavca::MotionSaver::getFloatValueAtTimeInternal "
PIAVCA_EXPORT float MotionSaver::getFloatValueAtTimeInternal(int trackId, float time)
         
calculates the values of the filter motion on and saves them to a TrackMotion         
         
        ";
%feature("docstring") Piavca::MotionSaver::getVecValueAtTimeInternal "
PIAVCA_EXPORT Vec MotionSaver::getVecValueAtTimeInternal(int trackId, float time)
         
calculates the values of the filter motion on and saves them to a TrackMotion         
         
        ";
%feature("docstring") Piavca::MotionSaver::getQuatValueAtTimeInternal "
PIAVCA_EXPORT Quat MotionSaver::getQuatValueAtTimeInternal(int trackId, float time)
         
calculates the values of the filter motion on and saves them to a TrackMotion         
         
        ";
%feature("docstring") Piavca::MotionSaver::collectFrames "
PIAVCA_EXPORT void MotionSaver::collectFrames(float framerate)
         
runs through the motion storing frame at the given framerate         
         
        ";
%feature("docstring") Piavca::MotionSaver::save "
PIAVCA_EXPORT void MotionSaver::save(tstring filename)
         
        
         
        ";
*/
%feature("docstring") Piavca::MotionTrack " 

Concrete Motion track.     
       
This is the sub type of base motion track that actually does the work, it is a template so can contain different types, float Vec or Quat. Tracks only contain keyframes of a single type. Probably won't be part of the API itself as in some implementations this stuff might be handled in the underlying API.      see also: MotionTrack.h";

%feature("docstring") Piavca::MotionTrack::getFloatValAtTime "
virtual float Piavca::MotionTrack< T >::getFloatValAtTime(float t) const 
         
get the value of the keyframe at time (only for float tracks)         
         
        ";
%feature("docstring") Piavca::MotionTrack::getVecValAtTime "
virtual Vec Piavca::MotionTrack< T >::getVecValAtTime(float t) const 
         
get the value of the keyframe at time (only for Vec tracks)         
         
        ";
%feature("docstring") Piavca::MotionTrack::getQuatValAtTime "
virtual Quat Piavca::MotionTrack< T >::getQuatValAtTime(float t) const 
         
get the value of the keyframe at time (only for Quat tracks)         
         
        ";
%feature("docstring") Piavca::MotionTrack::setFloatKeyframe "
void Piavca::MotionTrack< T >::setFloatKeyframe(float time, float val)
         
create a float key frame or set the value of an existing one (only works for float tracks)         
         
        ";
%feature("docstring") Piavca::MotionTrack::setFloatKeyframe "
void Piavca::MotionTrack< T >::setFloatKeyframe(float time, float val, float vel)
         
create a float key frame or set the value of an existing one with a user specified velocity (only works for float tracks)         
         
        ";
%feature("docstring") Piavca::MotionTrack::setVecKeyframe "
void Piavca::MotionTrack< T >::setVecKeyframe(float time, Vec val)
         
create a Vec key frame or set the value of an existing one (only works for Vec tracks)         
         
        ";
%feature("docstring") Piavca::MotionTrack::setVecKeyframe "
void Piavca::MotionTrack< T >::setVecKeyframe(float time, Vec val, Vec vel)
         
create a Vec key frame or set the value of an existing one with a user specified velocity (only works for Vec tracks)         
         
        ";
%feature("docstring") Piavca::MotionTrack::setQuatKeyframe "
void Piavca::MotionTrack< T >::setQuatKeyframe(float time, Quat val)
         
create a Quat key frame or set the value of an existing one (only works for Quat tracks)         
         
        ";
%feature("docstring") Piavca::MotionTrack::setQuatKeyframe "
void Piavca::MotionTrack< T >::setQuatKeyframe(float time, Quat val, Quat vel)
         
create a Quat key frame or set the value of an existing one with a user specified velocity (only works for Quat tracks)         
         
        ";
%feature("docstring") Piavca::MotionTrack::MotionTrack "
Piavca::MotionTrack< T >::MotionTrack(const T &initialValue, trackType type)
         
create a track         
         
trackName is, of course, the name of the track and is used to match the track with its joint which will have the same name. initialValue is the value the track should have at time 0         ";
%feature("docstring") Piavca::MotionTrack::MotionTrack "
Piavca::MotionTrack< T >::MotionTrack(const MotionTrack< T > &mt)
         
        
         
        ";
%feature("docstring") Piavca::MotionTrack::~MotionTrack "
Piavca::MotionTrack< T >::~MotionTrack()
         
        
         
        ";
%feature("docstring") Piavca::MotionTrack::getOffset "
const Vec& Piavca::MotionTrack< T >::getOffset() const 
         
gets the values of the offset         
         
The offset is the distance of a joint from the start of the parent joint. This is read in from the heirarchy section of the bvh file.         ";
%feature("docstring") Piavca::MotionTrack::setOffset "
void Piavca::MotionTrack< T >::setOffset(const Vec &offs)
         
sets the values of the offset         
         
The offset is the distance of a joint from the start of the parent joint. This is read in from the heirarchy section of the bvh file.         ";
%feature("docstring") Piavca::MotionTrack::clone "
virtual BaseMotionTrack* Piavca::MotionTrack< T >::clone()
         
create a copy of the track         
         
Used by BaseMotionTrack to create a new track without knowing the type         ";
%feature("docstring") Piavca::MotionTrack::getLength "
virtual float Piavca::MotionTrack< T >::getLength()
         
get the time of the last keyframe         
         
        ";
%feature("docstring") Piavca::MotionTrack::getNumKeyframes "
virtual int Piavca::MotionTrack< T >::getNumKeyframes() const 
         
gets the number of keyframes defined for the track         
         
        ";
%feature("docstring") Piavca::MotionTrack::setKeyframe "
int Piavca::MotionTrack< T >::setKeyframe(float time, const T &value)
         
add a new keframe         
         
        ";
%feature("docstring") Piavca::MotionTrack::setKeyframe "
int Piavca::MotionTrack< T >::setKeyframe(float time, const T &value, const T &velocity)
         
add a new keframe with a user specified velocity         
         
        ";
%feature("docstring") Piavca::MotionTrack::getValAtTime "
T Piavca::MotionTrack< T >::getValAtTime(float t) const 
         
does an interpolation to get the value of the track at time t         
         
        ";
%feature("docstring") Piavca::MotionTrack::getVal "
const T& Piavca::MotionTrack< T >::getVal(int i)
         
get the value of keyframe i         
         
        ";
%feature("docstring") Piavca::MotionTrack::getVel "
const T& Piavca::MotionTrack< T >::getVel(int i)
         
get the velocity of keyframe i         
         
        ";
%feature("docstring") Piavca::MotionTrack::getTime "
float Piavca::MotionTrack< T >::getTime(int i) const 
         
get the time at which keyframe i happens         
         
        ";
%feature("docstring") Piavca::MotionTrack::getKeyframe "
const keyframe<T>& Piavca::MotionTrack< T >::getKeyframe(int i)
         
get a reference to keyframe i         
         
        ";
%feature("docstring") Piavca::MotionTrack::deleteKeyframeAtTime "
void Piavca::MotionTrack< T >::deleteKeyframeAtTime(int t)
         
Delete the keyframe at time.         
         
        ";
%feature("docstring") Piavca::MotionTrack::clear "
void Piavca::MotionTrack< T >::clear(bool createFirstFrame=true)
         
delete all keyframes         
         
        ";
%feature("docstring") Piavca::MotionTrack::getKeyframeBefore "
int Piavca::MotionTrack< T >::getKeyframeBefore(float time) const 
         
Gets the keyframe that happens immediately before time.         
         
Used to find which keyframes to interpolate to get the value at time         ";
%feature("docstring") Piavca::MotionTrack::calcVelocities "
void Piavca::MotionTrack< T >::calcVelocities() const 
         
Calculate the velocities at each keyframe.         
         
The client can explicitely specify velocities in which case they are not recalculated. The formula used is a varient of Catmull-Rom splines         ";
%feature("docstring") Piavca::MotionTrack::getFloatValAtTime "
float Piavca::MotionTrack< float >::getFloatValAtTime(float t) const
         
get the value of the keyframe at time (only for float tracks)         
         
        ";
%feature("docstring") Piavca::MotionTrack::getVecValAtTime "
Vec Piavca::MotionTrack< Vec >::getVecValAtTime(float t) const
         
get the value of the keyframe at time (only for Vec tracks)         
         
        ";
%feature("docstring") Piavca::MotionTrack::getQuatValAtTime "
Quat Piavca::MotionTrack< Quat >::getQuatValAtTime(float t) const
         
get the value of the keyframe at time (only for Quat tracks)         
         
        ";
%feature("docstring") Piavca::MotionTrack::setFloatKeyframe "
void Piavca::MotionTrack< float >::setFloatKeyframe(float time, float val)
         
create a float key frame or set the value of an existing one (only works for float tracks)         
         
        ";
%feature("docstring") Piavca::MotionTrack::setFloatKeyframe "
void Piavca::MotionTrack< float >::setFloatKeyframe(float time, float val, float vel)
         
create a float key frame or set the value of an existing one with a user specified velocity (only works for float tracks)         
         
        ";
%feature("docstring") Piavca::MotionTrack::setVecKeyframe "
void Piavca::MotionTrack< Vec >::setVecKeyframe(float time, Vec val)
         
create a Vec key frame or set the value of an existing one (only works for Vec tracks)         
         
        ";
%feature("docstring") Piavca::MotionTrack::setVecKeyframe "
void Piavca::MotionTrack< Vec >::setVecKeyframe(float time, Vec val, Vec vel)
         
create a Vec key frame or set the value of an existing one with a user specified velocity (only works for Vec tracks)         
         
        ";
%feature("docstring") Piavca::MotionTrack::setQuatKeyframe "
void Piavca::MotionTrack< Quat >::setQuatKeyframe(float time, Quat val)
         
create a Quat key frame or set the value of an existing one (only works for Quat tracks)         
         
        ";
%feature("docstring") Piavca::MotionTrack::setQuatKeyframe "
void Piavca::MotionTrack< Quat >::setQuatKeyframe(float time, Quat val, Quat vel)
         
create a Quat key frame or set the value of an existing one with a user specified velocity (only works for Quat tracks)         
         
        ";
%feature("docstring") Piavca::MultiMotionLoop " 

A loop class with a set of different motions.     
       
One of these motions is chosen each time around the loop. This is a base class for other loop classes. It is a template so that it can either be a sub class of a normal LoopMotion or a RandomTimingsLoop (or something else)      see also: MultiMotionLoop.h";

%feature("docstring") Piavca::MultiMotionLoop::MultiMotionLoop "
Piavca::MultiMotionLoop::MultiMotionLoop(const MotionVec &mv, float endTime=-1.0, float interval=0.01)
         
pass in a vector of motions to be used.         
         
        ";
%feature("docstring") Piavca::MultiMotionLoop::MultiMotionLoop "
Piavca::MultiMotionLoop::MultiMotionLoop(float endTime=-1.0, float interval=0.01)
         
create an empty multi-motionloop         
         
        ";
%feature("docstring") Piavca::MultiMotionLoop::MultiMotionLoop "
Piavca::MultiMotionLoop::MultiMotionLoop(const MultiMotionLoop &rl)
         
        
         
        ";
%feature("docstring") Piavca::MultiMotionLoop::~MultiMotionLoop "
Piavca::MultiMotionLoop::~MultiMotionLoop()
         
        
         
        ";
%feature("docstring") Piavca::MultiMotionLoop::clone "
virtual Motion* Piavca::MultiMotionLoop::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") Piavca::MultiMotionLoop::printInfo "
void Piavca::MultiMotionLoop::printInfo()
         
prints out info about the motion heirarchy         
         
        ";
%feature("docstring") Piavca::MultiMotionLoop::addMotion "
virtual void Piavca::MultiMotionLoop::addMotion(Motion *mot)
         
        
         
        ";
%feature("docstring") Piavca::MultiMotionLoop::findSub "
virtual Motion* Piavca::MultiMotionLoop::findSub(tstring nm)
         
finds the first submotion with a given name         
         
        ";
%feature("docstring") Piavca::MultiMotionLoop::findSubByType "
virtual Motion* Piavca::MultiMotionLoop::findSubByType(const type_info &ty)
         
finds the first submotion with a given type         
         
        ";
%feature("docstring") Piavca::MultiMotionLoop::load "
virtual void Piavca::MultiMotionLoop::load(Avatar *av)
         
called when the motion is loaded into an avatar         
         
        ";
%feature("docstring") Piavca::MultiMotionLoop::unload "
virtual void Piavca::MultiMotionLoop::unload()
         
called when the motion is unloaded from an avatar         
         
        ";
%feature("docstring") Piavca::MultiMotionLoop::loaded "
virtual bool Piavca::MultiMotionLoop::loaded(Avatar *av)
         
        
         
        ";
%feature("docstring") Piavca::MyEngineAvatarImp " 

the implemenataion class for the Avatars on the MyEngine platform     
       
This is a subtype of the AvatarImp class and does all the actual work of the avatar class. The platform independent UCLAvatar interface class forwards all method calls to an object of this type. (via a AvatarImp pointer).      see also: MyEngineAvatarImp.h";

%feature("docstring") Piavca::MyEngineAvatarImp::setRootPosition "
virtual void Piavca::MyEngineAvatarImp::setRootPosition(const Vec &Position)
         
        
         
get or set the root position and orientation of the avatar         ";
%feature("docstring") Piavca::MyEngineAvatarImp::getRootPosition "
virtual Vec Piavca::MyEngineAvatarImp::getRootPosition()
         
        
         
        ";
%feature("docstring") Piavca::MyEngineAvatarImp::setRootOrientation "
virtual void Piavca::MyEngineAvatarImp::setRootOrientation(const Quat &Orientation)
         
        
         
        ";
%feature("docstring") Piavca::MyEngineAvatarImp::getRootOrientation "
virtual Quat Piavca::MyEngineAvatarImp::getRootOrientation()
         
        
         
        ";
%feature("docstring") Piavca::MyEngineAvatarImp::~MyEngineAvatarImp "
virtual Piavca::MyEngineAvatarImp::~MyEngineAvatarImp()
         
destructor         
         
        ";
%feature("docstring") Piavca::MyEngineAvatarImp::createJoint "
bool Piavca::MyEngineAvatarImp::createJoint(tstring JointName)
         
creates a new joint         
         
It will only succeed if there is a piece of geometry corresponding to the name if not it returns false         ";
%feature("docstring") Piavca::MyEngineAvatarImp::getParent "
int Piavca::MyEngineAvatarImp::getParent(int jointId) const 
         
returns the ID of the parent of the joint in the joint heirarchy (or a negative value if it doesn't exist         
         
        ";
%feature("docstring") Piavca::MyEngineAvatarImp::isNull "
bool Piavca::MyEngineAvatarImp::isNull(int jointId) const 
         
whether a joint is actually present in the avatar         
         
        ";
%feature("docstring") Piavca::MyEngineAvatarImp::getJointName "
const tstring& Piavca::MyEngineAvatarImp::getJointName(int jointId)
         
get the name of the joint corresponding to an iterator         
         
        ";
%feature("docstring") Piavca::MyEngineAvatarImp::hasChanged "
bool Piavca::MyEngineAvatarImp::hasChanged(int jointId)
         
check whether the joint iterator has been changed         
         
        ";
%feature("docstring") Piavca::MyEngineAvatarImp::clearChange "
void Piavca::MyEngineAvatarImp::clearChange(int jointId)
         
clears the changed flag for the joint         
         
        ";
%feature("docstring") Piavca::MyEngineAvatarImp::setJointOrientation "
virtual void Piavca::MyEngineAvatarImp::setJointOrientation(int jointId, const Quat &val, jointCoord worldCoord=JOINTLOCAL_COORD)
         
set the value of the orientation of a joint         
         
The joint is specified via an ID. This can be done in various coordinate systems, jointlocal is the coordante space of the joint (default) local is the space of the avatar root world is the world coordinates using the second two is likely to be much less efficient         ";
%feature("docstring") Piavca::MyEngineAvatarImp::getJointOrientation "
virtual Quat Piavca::MyEngineAvatarImp::getJointOrientation(int jointId, jointCoord worldCoord=JOINTLOCAL_COORD)
         
get the orientation of a joint         
         
The joint is specified via an ID. This can be done in various coordinate systems, jointlocal is the coordante space of the joint (default) local is the space of the avatar root world is the world coordinates using the second two is likely to be much less efficient         ";
%feature("docstring") Piavca::MyEngineAvatarImp::getJointBasePosition "
virtual Vec Piavca::MyEngineAvatarImp::getJointBasePosition(int jointId, jointCoord worldCoord=LOCAL_COORD)
         
get the current position of the start point of the joint         
         
calculated from the root position and joint angles by forward kinematics This can be done in various coordinate systems, jointlocal is the coordante space of the joint local is the space of the avatar root (default) world is the world coordinates         ";
%feature("docstring") Piavca::MyEngineAvatarImp::getAvatarImp "
static MyEngineAvatarImp* Piavca::MyEngineAvatarImp::getAvatarImp(Avatar &avatar)
         
given an Avatar object get its implementation         
         
        ";
%feature("docstring") Piavca::MyEngineAvatarImp::MyEngineAvatarImp "
Piavca::MyEngineAvatarImp::MyEngineAvatarImp()
         
private constructor means that the user cannot create it         
         
Must be created via a MyEnginePiavcaCore object         ";
%feature("docstring") Piavca::MyEnginePiavcaCore " 

The Implementation of the core object.     
       
This is a subtype of the Piavca::Core class. It also subtypes the StdMotionCore as it uses the standard motion implementation      see also: MyEnginePiavcaCore.h";

%feature("docstring") Piavca::MyEnginePiavcaCore::MyEnginePiavcaCore "
Piavca::MyEnginePiavcaCore::MyEnginePiavcaCore(MyEngine::SceneGraph *graph)
         
The constructor takes a pointer to the scene graph in which the avatars are to be created.         
         
        ";
%feature("docstring") Piavca::MyEnginePiavcaCore::~MyEnginePiavcaCore "
virtual Piavca::MyEnginePiavcaCore::~MyEnginePiavcaCore()
         
        
         
        ";
%feature("docstring") Piavca::MyEnginePiavcaCore::getTime "
float Piavca::MyEnginePiavcaCore::getTime()
         
get the current time         
         
        ";
%feature("docstring") Piavca::MyEnginePiavcaCore::createAvatarImp "
AvatarImp* Piavca::MyEnginePiavcaCore::createAvatarImp(tstring avatarId, bool bailOnMissedJoints, const Vec &Position, const Quat &Orientation)
         
Creates an avatar implementation (actually creates a MyEngineAvatarImp object).         
         
        ";
%feature("docstring") Piavca::Object " 

A class for representing inanimate objects in PIAVCA.     
       
This works much like an avatar, except its only got a root and not joints/facial exprssions.      see also: Object.h";

%feature("docstring") Piavca::Object::setPosition "
void Piavca::Object::setPosition(const Vec &Position)
         
        
         
get or set the root position and orientation of the avatar         ";
%feature("docstring") Piavca::Object::getPosition "
Vec Piavca::Object::getPosition()
         
        
         
        ";
%feature("docstring") Piavca::Object::setOrientation "
void Piavca::Object::setOrientation(const Quat &Orientation)
         
        
         
        ";
%feature("docstring") Piavca::Object::setAngle "
void Piavca::Object::setAngle(float angle)
         
set the orientation from an angle in radians (assumed to be about the verticle)         
         
        ";
%feature("docstring") Piavca::Object::setAngleDeg "
void Piavca::Object::setAngleDeg(float angle)
         
set the orientation from an angle in degrees (assumed to be about the verticle)         
         
        ";
%feature("docstring") Piavca::Object::getOrientation "
Quat Piavca::Object::getOrientation()
         
        
         
        ";
%feature("docstring") Piavca::Object::Object "
Object::Object(const Object &av)
         
copy constructor         
         
        ";
%feature("docstring") Piavca::Object::Object "
Piavca::Object::Object(tstring objectId, const Vec &Position=Vec(0.0, 0.0, 0.0), const Quat &Orientation=Quat(1.0, 0.0, 0.0, 0.0))
         
create an object         
         
The object needs to be initialised with an implementation. The type of the implementation depends on the platform and so it cannot be created directly in platform independant code. To get around this it is created by a static factory method in the which itself uses the Piavca::Core class and its platform dependent implementation to create the implementation of the avatar. The constructor needs an identifier string that it uses to find platform specific data needed to create the avatar, for example the mesh file. The user can also pass in a position and orientation for the object.         ";
%feature("docstring") Piavca::Object::getName "
tstring Piavca::Object::getName()
         
get the name of the avatar         
         
        ";
%feature("docstring") Piavca::Object::setName "
tstring Piavca::Object::setName(tstring newName)
         
set the name of the avatar         
         
        ";
%feature("docstring") Piavca::Object::scale "
void Piavca::Object::scale(Vec scale)
         
scales the root by a non-uniform scale vector         
         
        ";
%feature("docstring") Piavca::Object::initObject "
void Object::initObject(tstring objectId, const Vec &Position, const Quat &Orientation)
         
initialise a Avatar in a platform dependent way using the core         
         
        ";
%feature("docstring") Piavca::Object::~Object "
virtual Piavca::Object::~Object()
         
destructor can only be called by the core, use Core::removeAvatar to delete an avatar         
         
        ";
%feature("docstring") Piavca::ObjectDiveImp " 

the implemenataion class for the Objects on the Dive platform     
       
This is a subtype of the ObjectImp class and does all the actual work of the Object class. The platform independent Object interface class forwards all method calls to an object of this type. (via a ObjectImp pointer).      see also: ObjectCal3dImp.h";

%feature("docstring") Piavca::ObjectDiveImp::setPosition "
void ObjectDiveImp::setPosition(const Vec &Position)
         
        
         
get or set the root position and orientation of the Object         ";
%feature("docstring") Piavca::ObjectDiveImp::getPosition "
Vec ObjectDiveImp::getPosition()
         
        
         
        ";
%feature("docstring") Piavca::ObjectDiveImp::setOrientation "
void ObjectDiveImp::setOrientation(const Quat &Orientation)
         
        
         
        ";
%feature("docstring") Piavca::ObjectDiveImp::getOrientation "
Quat ObjectDiveImp::getOrientation()
         
        
         
        ";
%feature("docstring") Piavca::ObjectDiveImp::ObjectDiveImp "
Piavca::ObjectDiveImp::ObjectDiveImp()
         
private constructor means that the user cannot create it         
         
Must be created via a TaraObjectFactory object         ";
%feature("docstring") Piavca::ObjectDiveImp::~ObjectDiveImp "
virtual Piavca::ObjectDiveImp::~ObjectDiveImp()
         
destructor         
         
        ";
%feature("docstring") Piavca::ObjectDiveImp::scale "
void ObjectDiveImp::scale(Vec scale)
         
scales the root by a non-uniform scale vector         
         
        ";
%feature("docstring") Piavca::ObjectDiveImp::getObjectImp "
static ObjectDiveImp* Piavca::ObjectDiveImp::getObjectImp(Object *Object)
         
given a UCLObject object get its implementation         
         
        ";
%feature("docstring") Piavca::ObjectImp " 

the implemenataion class for the Objects     
       
Each platform has a concrete subtype of this class which actually does the work of the Object class. The Object class is an interface class that contains a pointer to a ObjectImp object and forwards all method calls to this object. The object will be of the concrete type corresponding to the platform being used.      see also: ObjectImp.h";

%feature("docstring") Piavca::ObjectImp::setPosition "
virtual void Piavca::ObjectImp::setPosition(const Vec &Position)=0
         
        
         
get or set the position and orientation of the Object         ";
%feature("docstring") Piavca::ObjectImp::getPosition "
virtual Vec Piavca::ObjectImp::getPosition()=0
         
        
         
        ";
%feature("docstring") Piavca::ObjectImp::setOrientation "
virtual void Piavca::ObjectImp::setOrientation(const Quat &Orientation)=0
         
        
         
        ";
%feature("docstring") Piavca::ObjectImp::getOrientation "
virtual Quat Piavca::ObjectImp::getOrientation()=0
         
        
         
        ";
%feature("docstring") Piavca::ObjectImp::~ObjectImp "
virtual Piavca::ObjectImp::~ObjectImp()
         
destructor         
         
        ";
%feature("docstring") Piavca::ObjectImp::scale "
virtual void Piavca::ObjectImp::scale(Vec scale)=0
         
scales the object by a non-uniform scale vector         
         
        ";
%feature("docstring") Piavca::ObjectImp::ObjectImp "
Piavca::ObjectImp::ObjectImp()
         
        
         
        ";
%feature("docstring") Piavca::ObjectImp::getObjectImpInternal "
ObjectImp * ObjectImp::getObjectImpInternal(Object *oobject)
         
Given a Object object this returns its implementation.         
         
This is used by a similar method in the platform specific implementation that is used to get the implementation in platform specific code         ";
%feature("docstring") Piavca::OnTheSpot " 

a motion filter that zeros the root position motion so the avatar doesn't move     
       
     see also: OnTheSpot.h";

%feature("docstring") Piavca::OnTheSpot::OnTheSpot "
Piavca::OnTheSpot::OnTheSpot(Motion *m=NULL)
         
        
         
Pass in the motion to be filtered and a scale factor         ";
%feature("docstring") Piavca::OnTheSpot::OnTheSpot "
Piavca::OnTheSpot::OnTheSpot(const OnTheSpot &sm)
         
        
         
        ";
%feature("docstring") Piavca::OnTheSpot::clone "
virtual Motion* Piavca::OnTheSpot::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") Piavca::OnTheSpot::getFloatValueAtTimeInternal "
virtual PIAVCA_EXPORT float Piavca::OnTheSpot::getFloatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") Piavca::OnTheSpot::getVecValueAtTimeInternal "
virtual PIAVCA_EXPORT Vec Piavca::OnTheSpot::getVecValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") Piavca::OnTheSpot::getQuatValueAtTimeInternal "
virtual PIAVCA_EXPORT Quat Piavca::OnTheSpot::getQuatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") Piavca::PiavcaCal3DCore " 

A factory class that is used to create avatar object in the Tara implementation.     
       
This is a subtype of the UCL avatar factory. It also subtypes the StdMotionAvatarFactory as it uses the standard motion implementation      see also: PiavcaCal3dCore.h";

%feature("docstring") Piavca::PiavcaCal3DCore::PiavcaCal3DCore "
PiavcaCal3DCore::PiavcaCal3DCore()
         
        
         
        ";
%feature("docstring") Piavca::PiavcaCal3DCore::~PiavcaCal3DCore "
virtual Piavca::PiavcaCal3DCore::~PiavcaCal3DCore()
         
        
         
        ";
%feature("docstring") Piavca::PiavcaCal3DCore::setStartTime "
void Piavca::PiavcaCal3DCore::setStartTime(float s)
         
        
         
        ";
%feature("docstring") Piavca::PiavcaCal3DCore::getTimeInternal "
double PiavcaCal3DCore::getTimeInternal(bool print)
         
        
         
        ";
%feature("docstring") Piavca::PiavcaCal3DCore::getSystemTime "
virtual float Piavca::PiavcaCal3DCore::getSystemTime()
         
get the current time in seconds         
         
        ";
%feature("docstring") Piavca::PiavcaCal3DCore::prerender "
void PiavcaCal3DCore::prerender()
         
called before rendering (this cannot be called in parallel with the render)         
         
        ";
%feature("docstring") Piavca::PiavcaCal3DCore::render "
void PiavcaCal3DCore::render()
         
On certain platforms this needs to be called to render the avatars.         
         
        ";
%feature("docstring") Piavca::PiavcaCal3DCore::createAvatarImp "
AvatarImp * PiavcaCal3DCore::createAvatarImp(tstring avatarId, bool bailOnMissedJoints, const Vec &Position, const Quat &Orientation)
         
Creates an avatar implementation (actually creates a UCLAVatarTaraImp object).         
         
        ";
%feature("docstring") Piavca::PiavcaCal3DCore::createAvatarImp "
AvatarCal3DImp * PiavcaCal3DCore::createAvatarImp(tstring avatarId, TextureHandler *th, bool bailOnMissedJoints, const Vec &Position, const Quat &Orientation)
         
a version of createAvatarImp to be subclassed         
         
        ";
%feature("docstring") Piavca::PiavcaCal3DCore::createObjectImp "
ObjectImp * PiavcaCal3DCore::createObjectImp(tstring avatarId, const Vec &Position, const Quat &Orientation)
         
Creates an object implementation (actually creates a UCLAvatarTaraImp object).         
         
        ";
%feature("docstring") Piavca::PiavcaCal3DCore::createTextureHandler "
TextureHandler * PiavcaCal3DCore::createTextureHandler()
         
        
         
creates a texture handler (of the correct subtype corresponding to the dynamic type of the core)         ";
%feature("docstring") Piavca::ProxemicsLoop " 

a MultiMotionLoop that implements proxemics behaviour.     
       
Proxemics consists in maintianing a desired personal distance to another avatar (or group of avatars) by stepping forwards or backwards. It also consists in turning to face the other avatar.      see also: ProxemicsLoop.h";

%feature("docstring") Piavca::ProxemicsLoop::ProxemicsLoop "
Piavca::ProxemicsLoop::ProxemicsLoop(Motion *stepForward=NULL, Motion *stepBackward=NULL, Motion *rest=NULL, Motion *turnLeft=NULL, Motion *turnRight=NULL, float distance=1.0f, float endTime=-1.0f, float interval=0.01f)
         
        
         
You have to pass in 5 motions: as stepForward and back, a turn left and right and a rest motion which should be zero keyframes and is used to blend with the turning motions to get the exact angle of turn you want. You also pass in a desired distance to the other avatar, a time at which to stop and a blend interval.         ";
%feature("docstring") Piavca::ProxemicsLoop::ProxemicsLoop "
Piavca::ProxemicsLoop::ProxemicsLoop(const ProxemicsLoop &rl)
         
        
         
        ";
%feature("docstring") Piavca::ProxemicsLoop::~ProxemicsLoop "
Piavca::ProxemicsLoop::~ProxemicsLoop()
         
        
         
        ";
%feature("docstring") Piavca::ProxemicsLoop::clone "
virtual Motion* Piavca::ProxemicsLoop::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") Piavca::ProxemicsLoop::setDistance "
void Piavca::ProxemicsLoop::setDistance(float d)
         
sets the desired distance to another avatar         
         
        ";
%feature("docstring") Piavca::ProxemicsLoop::setThreshold "
void Piavca::ProxemicsLoop::setThreshold(float t)
         
sets the threshold, the allowable error in distance before moving         
         
        ";
%feature("docstring") Piavca::ProxemicsLoop::setAngleThreshold "
void Piavca::ProxemicsLoop::setAngleThreshold(float a)
         
sets the threshold, the allowable error in distance before moving         
         
        ";
%feature("docstring") Piavca::ProxemicsLoop::turnOff "
void Piavca::ProxemicsLoop::turnOff(bool b)
         
turns off maintaining distance         
         
        ";
%feature("docstring") Piavca::ProxemicsLoop::addAvatar "
void Piavca::ProxemicsLoop::addAvatar(Avatar *av)
         
adds an avatar to perform proxemics behaviour to         
         
        ";
%feature("docstring") Piavca::ProxemicsLoop::removeAvatar "
void Piavca::ProxemicsLoop::removeAvatar(tstring name)
         
removes an avatar         
         
        ";
%feature("docstring") Piavca::ProxemicsLoop::removeAllAvatars "
void Piavca::ProxemicsLoop::removeAllAvatars()
         
removes all avatar         
         
        ";
%feature("docstring") Piavca::ProxemicsLoop::reblend "
virtual void Piavca::ProxemicsLoop::reblend(float time)
         
called each time through the loop         
         
        ";
%feature("docstring") Piavca::PyAvatarTimeCallback " 

    
       
     see also: PyTimeCallback.h";

%feature("docstring") Piavca::PyAvatarTimeCallback::PyAvatarTimeCallback "
Piavca::PyAvatarTimeCallback::PyAvatarTimeCallback(PyObject *pyCallback, tstring name)
         
        
         
        ";
%feature("docstring") Piavca::PyAvatarTimeCallback::~PyAvatarTimeCallback "
Piavca::PyAvatarTimeCallback::~PyAvatarTimeCallback()
         
        
         
        ";
%feature("docstring") Piavca::PyAvatarTimeCallback::init "
PIAVCA_EXPORT void PyAvatarTimeCallback::init(Avatar *avatar)
         
This is a setup method for the callback.         
         
It's called when the callback is registered         ";
%feature("docstring") Piavca::PyAvatarTimeCallback::timeStep "
PIAVCA_EXPORT void PyAvatarTimeCallback::timeStep(Avatar *av, float time)
         
implement this to make the callback do things         
         
It's called every frame with by the API which passes in the avatar to which the callback is attatched         ";
%feature("docstring") Piavca::PyMotion " 

    
       
     see also: PyMotion.h";

%feature("docstring") Piavca::PyMotion::PyMotion "
Piavca::PyMotion::PyMotion()
         
        
         
        ";
%feature("docstring") Piavca::PyMotion::PyMotion "
PyMotion::PyMotion(PyObject *pObj)
         
        
         
        ";
%feature("docstring") Piavca::PyMotion::PyMotion "
Piavca::PyMotion::PyMotion(const PyMotion &pm)
         
        
         
        ";
%feature("docstring") Piavca::PyMotion::clone "
Motion* Piavca::PyMotion::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") Piavca::PyMotion::~PyMotion "
PyMotion::~PyMotion()
         
        
         
        ";
%feature("docstring") Piavca::PyMotion::setPyObj "
void Piavca::PyMotion::setPyObj(PyObject *pObj)
         
        
         
        ";
%feature("docstring") Piavca::PyMotion::getMotionPtr "
Motion* Piavca::PyMotion::getMotionPtr()
         
returns a point to the motion object as swig won't recognise the python overload?         
         
        ";
%feature("docstring") Piavca::PyMotion::getMotionLength "
float PyMotion::getMotionLength() const 
         
gets the time of the end of the motion         
         
        ";
%feature("docstring") Piavca::PyMotion::isNull "
bool PyMotion::isNull(int trackId) const 
         
given a track ID tests whether it actually points to anything or if its null         
         
        ";
%feature("docstring") Piavca::PyMotion::getTrackType "
trackType PyMotion::getTrackType(int trackId) const 
         
get the type of the track corresponding to an ID         
         
        ";
%feature("docstring") Piavca::PyMotion::getFloatValueAtTimeInternal "
float PyMotion::getFloatValueAtTimeInternal(int trackId, float time)
         
get the value of a track at a given time (only works for floats)         
         
        ";
%feature("docstring") Piavca::PyMotion::getVecValueAtTimeInternal "
Vec PyMotion::getVecValueAtTimeInternal(int trackId, float time)
         
get the value of a track at a given time (only works for Vecs)         
         
        ";
%feature("docstring") Piavca::PyMotion::getQuatValueAtTimeInternal "
Quat PyMotion::getQuatValueAtTimeInternal(int trackId, float time)
         
get the value of a track at a given time (only works for Quats)         
         
        ";
%feature("docstring") Piavca::PyTimeCallback " 

    
       
     see also: PyTimeCallback.h";

%feature("docstring") Piavca::PyTimeCallback::PyTimeCallback "
Piavca::PyTimeCallback::PyTimeCallback(PyObject *pyCallback, tstring name)
         
        
         
        ";
%feature("docstring") Piavca::PyTimeCallback::~PyTimeCallback "
Piavca::PyTimeCallback::~PyTimeCallback()
         
        
         
        ";
%feature("docstring") Piavca::PyTimeCallback::init "
PIAVCA_EXPORT void PyTimeCallback::init(Core *core)
         
This is a setup method for the callback.         
         
It's called when the callback is registered         ";
%feature("docstring") Piavca::PyTimeCallback::timeStep "
PIAVCA_EXPORT void PyTimeCallback::timeStep(Core *core, float time)
         
implement this to make the callback do things         
         
It's called every frame with by the API         ";
%feature("docstring") Piavca::Quat " 

A Quaternion class.     
       
Quaternions are representations of rotations that have a number of advantages over other representation. They are rather complicated but if you just want to use them as rotations this library should be quite simple, you can set them from a rotation angle and axis (either via a constructor or the setAngleAxis method) and then use the various methods. To concatenate rotation multiply them together, with the first rotation to be applied coming second in the multiplication. To rotate a vector use the transform methods. To interpolate quaternions use the slerp function.I won't talk too much about the internals there are plenty of good references on quaternions (just look on the net). Briefly a quaternion has four compontents, the last three of which are proportional to the axis of rotation. All the components also depend on the angle. The quaternions always have to have a magnitude of one to represent a valid rotation.      see also: Quat.h";

%feature("docstring") Piavca::Quat::S "
const float& Piavca::Quat::S() const 
         
        
         
        ";
%feature("docstring") Piavca::Quat::I "
const float& Piavca::Quat::I() const 
         
depends only on the angle         
         
        ";
%feature("docstring") Piavca::Quat::J "
const float& Piavca::Quat::J() const 
         
depends on the angle & X-component of the axis         
         
        ";
%feature("docstring") Piavca::Quat::K "
const float& Piavca::Quat::K() const 
         
depends on the angle & Y-component of the axis         
         
        ";
%feature("docstring") Piavca::Quat::S "
float& Piavca::Quat::S()
         
depends on the angle & Z-component of the axis         
         
        ";
%feature("docstring") Piavca::Quat::I "
float& Piavca::Quat::I()
         
depends only on the angle         
         
        ";
%feature("docstring") Piavca::Quat::J "
float& Piavca::Quat::J()
         
depends on the angle & X-component of the axis         
         
        ";
%feature("docstring") Piavca::Quat::K "
float& Piavca::Quat::K()
         
depends on the angle & Y-component of the axis         
         
        ";
%feature("docstring") Piavca::Quat::Quat "
Quat::Quat()
         
default constructor creates a zero rotation quaternion.         
         
        ";
%feature("docstring") Piavca::Quat::Quat "
Quat::Quat(float s, float i, float j, float k)
         
        
         
        ";
%feature("docstring") Piavca::Quat::Quat "
Quat::Quat(const float q[4])
         
        
         
        ";
%feature("docstring") Piavca::Quat::Quat "
Quat::Quat(float Angle, const Vec &Axis)
         
a constuctor from angle axis representation of a rotation         
         
        ";
%feature("docstring") Piavca::Quat::Quat "
Quat::Quat(const Quat &q)
         
        
         
        ";
%feature("docstring") Piavca::Quat::~Quat "
Piavca::Quat::~Quat()
         
        
         
        ";
%feature("docstring") Piavca::Quat::setAngleAxis "
void Piavca::Quat::setAngleAxis(float Angle, const Vec &Axis)
         
set the value of the Quat from the angle axis rotation representation         
         
        ";
%feature("docstring") Piavca::Quat::setAngleAxis "
void Quat::setAngleAxis(float Angle, float x, float y, float z)
         
set the value of the Quat from the angle axis rotation representation         
         
        ";
%feature("docstring") Piavca::Quat::getAngleAxis "
void Quat::getAngleAxis(float &Angle, Vec &Axis) const 
         
get rotation as an angle and an axis         
         
        ";
%feature("docstring") Piavca::Quat::getAngle "
float Quat::getAngle() const 
         
get the rotation angle (more efficient that getting angle and axis)         
         
        ";
%feature("docstring") Piavca::Quat::getAxis "
Vec Piavca::Quat::getAxis() const 
         
get the axis of rotation (a convenience function)         
         
        ";
%feature("docstring") Piavca::Quat::getEulerAngles "
void Quat::getEulerAngles(float &X, float &Y, float &Z)
         
get the rotation as a set of Euler angles         
         
        ";
%feature("docstring") Piavca::Quat::Xangle "
float Quat::Xangle()
         
get the component of the rotation about the X-axis         
         
        ";
%feature("docstring") Piavca::Quat::Yangle "
float Quat::Yangle()
         
get the component of the rotation about the Y-axis         
         
        ";
%feature("docstring") Piavca::Quat::Zangle "
float Quat::Zangle()
         
get the component of the rotation about the Z-axis         
         
        ";
%feature("docstring") Piavca::Quat::pointAt "
Quat & Quat::pointAt(const Vec &original, const Vec &desired)
         
set the Quat to the quaternion that would rotate original so it points in the direction of desired         
         
        ";
%feature("docstring") Piavca::Quat::Scale "
void Quat::Scale(float f)
         
scales a quaternion by a float value         
         
Not the same as just multiplying. It scales the angle without affecting the axis.         ";
%feature("docstring") Piavca::Quat::inverse "
Quat Piavca::Quat::inverse() const 
         
returns the inverse of the Quat while leaving it unchanged. (The inverse gives the oppostite rotation)         
         
        ";
%feature("docstring") Piavca::Quat::invert "
void Piavca::Quat::invert()
         
inverts the quaternion in place. (The inverse gives the oppostite rotation)         
         
        ";
%feature("docstring") Piavca::Quat::normalise "
void Quat::normalise()
         
normalizes the quaternion in place         
         
        ";
%feature("docstring") Piavca::Quat::transform "
Vec Piavca::Quat::transform(const Vec &v) const 
         
trasform (rotate) a vector by the quaternion         
         
        ";
%feature("docstring") Piavca::Quat::transformInPlace "
void Piavca::Quat::transformInPlace(Vec &v) const 
         
trasform (rotate) a vector by the quaternion in place         
         
        ";
%feature("docstring") Piavca::Quat::spherical_distance "
float Quat::spherical_distance(const Quat &q1, const Quat &q2)
         
        
         
calculates a distance measure between two quaternions. It uses spherical distance, the same measure used by slerp         ";
%feature("docstring") Piavca::RandomAddLoop " 

A MultiMotionLoop which, instead of choosing one motion at a time, adds together a groups of motions.     
       
The Motions to blend are chosen at random, as are the number of motions. Each of the motions is scaled by a random ammount before being added.      see also: RandomAddLoop.h";

%feature("docstring") Piavca::RandomAddLoop::RandomAddLoop "
Piavca::RandomAddLoop::RandomAddLoop()
         
        
         
        ";
%feature("docstring") Piavca::RandomAddLoop::RandomAddLoop "
Piavca::RandomAddLoop::RandomAddLoop(const MotionVec &mv, float endTime=-1.0, float interval=0.01)
         
pass in a vector of motions to be used.         
         
        ";
%feature("docstring") Piavca::RandomAddLoop::RandomAddLoop "
Piavca::RandomAddLoop::RandomAddLoop(const RandomAddLoop &rbl)
         
        
         
        ";
%feature("docstring") Piavca::RandomAddLoop::~RandomAddLoop "
Piavca::RandomAddLoop::~RandomAddLoop()
         
        
         
        ";
%feature("docstring") Piavca::RandomAddLoop::clone "
virtual Motion* Piavca::RandomAddLoop::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") Piavca::RandomAddLoop::setAutoShift "
void Piavca::RandomAddLoop::setAutoShift(bool b)
         
        
         
        ";
%feature("docstring") Piavca::RandomAddLoop::shift "
virtual void Piavca::RandomAddLoop::shift()
         
        
         
        ";
%feature("docstring") Piavca::RandomAddLoop::reblend "
virtual void Piavca::RandomAddLoop::reblend(float time)
         
called each time around the loop         
         
It can be called by the client to interrupt the current motion.         ";
%feature("docstring") Piavca::RandomBlendLoop " 

A MultiMotionLoop which, instead of choosing one motion at a time, blends between a groups of motions.     
       
The Motions to blend are chosen at random, as are the number of motions and the weights.      see also: RandomBlendLoop.h";

%feature("docstring") Piavca::RandomBlendLoop::RandomBlendLoop "
Piavca::RandomBlendLoop::RandomBlendLoop(const MotionVec &mv, float endTime=-1.0, float interval=0.01)
         
pass in a vector of motions to be used.         
         
        ";
%feature("docstring") Piavca::RandomBlendLoop::RandomBlendLoop "
Piavca::RandomBlendLoop::RandomBlendLoop(float endTime=-1.0, float interval=0.01)
         
create an empty loop         
         
        ";
%feature("docstring") Piavca::RandomBlendLoop::RandomBlendLoop "
Piavca::RandomBlendLoop::RandomBlendLoop(const RandomBlendLoop &rbl)
         
        
         
        ";
%feature("docstring") Piavca::RandomBlendLoop::~RandomBlendLoop "
Piavca::RandomBlendLoop::~RandomBlendLoop()
         
        
         
        ";
%feature("docstring") Piavca::RandomBlendLoop::clone "
virtual Motion* Piavca::RandomBlendLoop::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") Piavca::RandomBlendLoop::addMotion "
virtual void Piavca::RandomBlendLoop::addMotion(Motion *mot)
         
        
         
        ";
%feature("docstring") Piavca::RandomBlendLoop::addMotion "
virtual void Piavca::RandomBlendLoop::addMotion(Motion *mot, float weight)
         
        
         
        ";
%feature("docstring") Piavca::RandomBlendLoop::setAutoShift "
void Piavca::RandomBlendLoop::setAutoShift(bool b)
         
        
         
        ";
%feature("docstring") Piavca::RandomBlendLoop::shift "
virtual void Piavca::RandomBlendLoop::shift()
         
        
         
        ";
%feature("docstring") Piavca::RandomBlendLoop::reblend "
virtual void Piavca::RandomBlendLoop::reblend(float time)
         
called each time around the loop         
         
It can be called by the client to interrupt the current motion.         ";
%feature("docstring") Piavca::RandomGazeMotion " 

    
       
     see also: RandomGazeMotion.h";

%feature("docstring") Piavca::RandomGazeMotion::RandomGazeMotion "
Piavca::RandomGazeMotion::RandomGazeMotion(float endTime=-1.0, float interval=0.01)
         
        
         
        ";
%feature("docstring") Piavca::RandomGazeMotion::RandomGazeMotion "
Piavca::RandomGazeMotion::RandomGazeMotion(const RandomGazeMotion &rg)
         
        
         
        ";
%feature("docstring") Piavca::RandomGazeMotion::~RandomGazeMotion "
Piavca::RandomGazeMotion::~RandomGazeMotion()
         
        
         
        ";
%feature("docstring") Piavca::RandomGazeMotion::clone "
virtual Motion* Piavca::RandomGazeMotion::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") Piavca::RandomGazeMotion::clearDirectionTable "
void Piavca::RandomGazeMotion::clearDirectionTable()
         
        
         
        ";
%feature("docstring") Piavca::RandomGazeMotion::addDirection "
void Piavca::RandomGazeMotion::addDirection(const Vec &dir, float prob)
         
        
         
        ";
%feature("docstring") Piavca::RandomGazeMotion::normaliseDirectionTable "
void Piavca::RandomGazeMotion::normaliseDirectionTable()
         
        
         
        ";
%feature("docstring") Piavca::RandomGazeMotion::addAvatarTarget "
void Piavca::RandomGazeMotion::addAvatarTarget(Avatar *av, int joint, flagStruct f=flagStruct())
         
        
         
        ";
%feature("docstring") Piavca::RandomGazeMotion::addObjectTarget "
void Piavca::RandomGazeMotion::addObjectTarget(Object *obj, flagStruct f=flagStruct())
         
        
         
        ";
%feature("docstring") Piavca::RandomGazeMotion::setTargetFlags "
void Piavca::RandomGazeMotion::setTargetFlags(tstring name, flagStruct flags)
         
        
         
        ";
%feature("docstring") Piavca::RandomGazeMotion::setGazeParams "
void Piavca::RandomGazeMotion::setGazeParams(float coeff, float divisor)
         
        
         
        ";
%feature("docstring") Piavca::RandomGazeMotion::setLookAtLocationProb "
void Piavca::RandomGazeMotion::setLookAtLocationProb(float prob)
         
        
         
        ";
%feature("docstring") Piavca::RandomGazeMotion::setMeanGazeLength "
void Piavca::RandomGazeMotion::setMeanGazeLength(float f)
         
        
         
        ";
%feature("docstring") Piavca::RandomGazeMotion::setEyesLimit "
void Piavca::RandomGazeMotion::setEyesLimit(float f)
         
        
         
        ";
%feature("docstring") Piavca::RandomGazeMotion::setHeadBodyLimit "
void Piavca::RandomGazeMotion::setHeadBodyLimit(float f)
         
        
         
        ";
%feature("docstring") Piavca::RandomGazeMotion::setEyesMorphAngle "
void Piavca::RandomGazeMotion::setEyesMorphAngle(float f)
         
        
         
        ";
%feature("docstring") Piavca::RandomGazeMotion::randomLocation "
Vec Piavca::RandomGazeMotion::randomLocation()
         
        
         
        ";
%feature("docstring") Piavca::RandomGazeMotion::lookAt "
virtual bool Piavca::RandomGazeMotion::lookAt(tstring name, bool force=false)
         
        
         
        ";
%feature("docstring") Piavca::RandomGazeMotion::reblend "
virtual void Piavca::RandomGazeMotion::reblend(float time)
         
saves the state of the motion at time and start blending the motion back into that from the start         
         
        ";
%feature("docstring") Piavca::RandomGazeMotion::init "
void Piavca::RandomGazeMotion::init()
         
sets up values to those given by Lee, badler, badler paper         
         
        ";
%feature("docstring") Piavca::RandomLoopMotion " 

a MultiMotionLoop where a new motion is chosen each time around the loop.     
       
     see also: RandomLoopMotion.h";

%feature("docstring") Piavca::RandomLoopMotion::RandomLoopMotion "
Piavca::RandomLoopMotion::RandomLoopMotion()
         
        
         
        ";
%feature("docstring") Piavca::RandomLoopMotion::RandomLoopMotion "
Piavca::RandomLoopMotion::RandomLoopMotion(const MotionVec &mv, vector< float > ws, float endTime=-1.0, float interval=0.01)
         
pass in a vector of motions to be used, and a vector with a weight for each motion.         
         
The weights determine the probability of playing each motio         ";
%feature("docstring") Piavca::RandomLoopMotion::RandomLoopMotion "
Piavca::RandomLoopMotion::RandomLoopMotion(const RandomLoopMotion &rl)
         
        
         
        ";
%feature("docstring") Piavca::RandomLoopMotion::~RandomLoopMotion "
Piavca::RandomLoopMotion::~RandomLoopMotion()
         
        
         
        ";
%feature("docstring") Piavca::RandomLoopMotion::clone "
virtual Motion* Piavca::RandomLoopMotion::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") Piavca::RandomLoopMotion::addMotion "
virtual void Piavca::RandomLoopMotion::addMotion(Motion *mot, float weight=1.0f)
         
        
         
        ";
%feature("docstring") Piavca::RandomLoopMotion::setProbability "
void Piavca::RandomLoopMotion::setProbability(int index, float prob)
         
        
         
        ";
%feature("docstring") Piavca::RandomLoopMotion::reblend "
virtual void Piavca::RandomLoopMotion::reblend(float time)
         
called each time around the loop         
         
It can be called by the client to interrupt the current motion.         ";
%feature("docstring") Piavca::RandomLoopMotion::convertTo "
static RandomLoopMotion* Piavca::RandomLoopMotion::convertTo(Motion *m)
         
        
         
        ";
%feature("docstring") Piavca::RandomTimingsLoop " 

A loop motion where the speed is altered randomly on each time round.     
       
     see also: RandomTimingsLoop.h";

%feature("docstring") Piavca::RandomTimingsLoop::RandomTimingsLoop "
Piavca::RandomTimingsLoop::RandomTimingsLoop(Motion *mot=NULL, float endTime=-1.0, float interval=0.01, float min=1.0, float max=1.0)
         
        
         
pass in the motion to be looped, and optionally a time a which to stop add the interval between the start of the motion and when it restarts. and most importantly the minimum and maximum timings         ";
%feature("docstring") Piavca::RandomTimingsLoop::RandomTimingsLoop "
Piavca::RandomTimingsLoop::RandomTimingsLoop(const RandomTimingsLoop &rtl)
         
        
         
        ";
%feature("docstring") Piavca::RandomTimingsLoop::~RandomTimingsLoop "
Piavca::RandomTimingsLoop::~RandomTimingsLoop()
         
        
         
        ";
%feature("docstring") Piavca::RandomTimingsLoop::clone "
virtual Motion* Piavca::RandomTimingsLoop::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") Piavca::RandomTimingsLoop::setTimingParams "
virtual void Piavca::RandomTimingsLoop::setTimingParams(float minTimeScale, float maxTimeScale)
         
sets the minimum and maximum times that can be generated         
         
        ";
%feature("docstring") Piavca::RandomTimingsLoop::reblend "
virtual void Piavca::RandomTimingsLoop::reblend(float time)
         
This is called each time around the loop.         
         
        ";
%feature("docstring") Piavca::RandomTimingsLoop::setMotion "
virtual void Piavca::RandomTimingsLoop::setMotion(Motion *m)
         
sets the motion to be looped         
         
std::cout << \"setting motion for loop\n\";         ";
%feature("docstring") Piavca::ScaleMotion " 

a motion filter that scales the motion by a float factor     
       
     see also: ScaleMotion.h";

%feature("docstring") Piavca::ScaleMotion::ScaleMotion "
Piavca::ScaleMotion::ScaleMotion(Motion *m=NULL, float scale=1.0)
         
        
         
Pass in the motion to be filtered and a scale factor         ";
%feature("docstring") Piavca::ScaleMotion::ScaleMotion "
Piavca::ScaleMotion::ScaleMotion(const ScaleMotion &sm)
         
        
         
        ";
%feature("docstring") Piavca::ScaleMotion::clone "
virtual Motion* Piavca::ScaleMotion::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") Piavca::ScaleMotion::getFloatValueAtTimeInternal "
virtual PIAVCA_EXPORT float Piavca::ScaleMotion::getFloatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") Piavca::ScaleMotion::getVecValueAtTimeInternal "
virtual PIAVCA_EXPORT Vec Piavca::ScaleMotion::getVecValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") Piavca::ScaleMotion::getQuatValueAtTimeInternal "
virtual PIAVCA_EXPORT Quat Piavca::ScaleMotion::getQuatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") Piavca::ScaleMotion::setScaleFactor "
void Piavca::ScaleMotion::setScaleFactor(float scale)
         
Sets the scale factor for the postion components of the motion.         
         
        ";
%feature("docstring") Piavca::ScaleMotionRoot " 

a motion filter that scales the displacement (position) parts of the motion     
       
This is basically useful for converting bvh files that are expressed in feet and inches to metres but might also be useful for motion retargeting.      see also: ScaleMotionRoot.h";

%feature("docstring") Piavca::ScaleMotionRoot::ScaleMotionRoot "
Piavca::ScaleMotionRoot::ScaleMotionRoot(Motion *m=NULL, float scale=1.0)
         
        
         
Pass in the motion to be filtered and a scale factor         ";
%feature("docstring") Piavca::ScaleMotionRoot::ScaleMotionRoot "
Piavca::ScaleMotionRoot::ScaleMotionRoot(const ScaleMotionRoot &sm)
         
        
         
        ";
%feature("docstring") Piavca::ScaleMotionRoot::~ScaleMotionRoot "
virtual Piavca::ScaleMotionRoot::~ScaleMotionRoot()
         
        
         
        ";
%feature("docstring") Piavca::ScaleMotionRoot::clone "
virtual Motion* Piavca::ScaleMotionRoot::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") Piavca::ScaleMotionRoot::getFloatValueAtTimeInternal "
virtual PIAVCA_EXPORT float Piavca::ScaleMotionRoot::getFloatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") Piavca::ScaleMotionRoot::getVecValueAtTimeInternal "
virtual PIAVCA_EXPORT Vec Piavca::ScaleMotionRoot::getVecValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe (vec values are scaled)         
         
        ";
%feature("docstring") Piavca::ScaleMotionRoot::getQuatValueAtTimeInternal "
virtual PIAVCA_EXPORT Quat Piavca::ScaleMotionRoot::getQuatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") Piavca::ScaleMotionRoot::setScaleFactor "
void Piavca::ScaleMotionRoot::setScaleFactor(float scale)
         
Sets the scale factor for the postion components of the motion.         
         
        ";
%feature("docstring") Piavca::ScaleMotionSpeed " 

a motion filter that scales the motion's speed     
       
     see also: ScaleMotionSpeed.h";

%feature("docstring") Piavca::ScaleMotionSpeed::ScaleMotionSpeed "
Piavca::ScaleMotionSpeed::ScaleMotionSpeed(Motion *m=NULL, float scale=1.0)
         
        
         
Pass in the motion to be filtered and a scale factor         ";
%feature("docstring") Piavca::ScaleMotionSpeed::ScaleMotionSpeed "
Piavca::ScaleMotionSpeed::ScaleMotionSpeed(const ScaleMotionSpeed &sm)
         
        
         
        ";
%feature("docstring") Piavca::ScaleMotionSpeed::clone "
virtual Motion* Piavca::ScaleMotionSpeed::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") Piavca::ScaleMotionSpeed::getMotionLength "
virtual float Piavca::ScaleMotionSpeed::getMotionLength() const 
         
gets the length of the motion in seconds         
         
        ";
%feature("docstring") Piavca::ScaleMotionSpeed::getFloatValueAtTimeInternal "
virtual PIAVCA_EXPORT float Piavca::ScaleMotionSpeed::getFloatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") Piavca::ScaleMotionSpeed::getVecValueAtTimeInternal "
virtual PIAVCA_EXPORT Vec Piavca::ScaleMotionSpeed::getVecValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") Piavca::ScaleMotionSpeed::getQuatValueAtTimeInternal "
virtual PIAVCA_EXPORT Quat Piavca::ScaleMotionSpeed::getQuatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") Piavca::ScaleMotionSpeed::setScaleFactor "
void Piavca::ScaleMotionSpeed::setScaleFactor(float scale)
         
Sets the scale factor for the postion components of the motion.         
         
        ";
%feature("docstring") Piavca::SelfBlend " 

A SequentialBlend motion manipuator that blends a motion into itself.     
       
It contains a method reblend which when called will save the motions current state and then starts blending the motion in from the start. This is used in implementing the loop motion class but has other uses. For example if there is a parameterised motion and you want to change the parameters and blend the new motion in smoothly use a selfBlend. and call reblend just before changing the parameters.      see also: SelfBlend.h";

%feature("docstring") Piavca::SelfBlend::SelfBlend "
SelfBlend::SelfBlend(Motion *mot=NULL, float interval=0.2)
         
        
         
pass in the motion to be blended and an optional blend interval         ";
%feature("docstring") Piavca::SelfBlend::SelfBlend "
Piavca::SelfBlend::SelfBlend(const SelfBlend &sb)
         
        
         
        ";
%feature("docstring") Piavca::SelfBlend::clone "
virtual Motion* Piavca::SelfBlend::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") Piavca::SelfBlend::reset "
void SelfBlend::reset()
         
does any resetting needed         
         
        ";
%feature("docstring") Piavca::SelfBlend::reblend "
void SelfBlend::reblend()
         
saves the current state of the motion and start blending the motion back into that from the start         
         
        ";
%feature("docstring") Piavca::SelfBlend::reblend "
void SelfBlend::reblend(float time)
         
saves the state of the motion at time and start blending the motion back into that from the start         
         
        ";
%feature("docstring") Piavca::SelfBlend::setMotion "
void SelfBlend::setMotion(Motion *mot)
         
sets the motion to be blended in         
         
        ";
%feature("docstring") Piavca::SequentialBlend " 

Initially plays one motion up to a given time then blends into another motion.     
       
This can be used to smoothly transition between motions and is used to implement a number of different motion effects like LoopMotion and AvatarPostureBlend. The seoond motion starts in the ending root position and orientation of the first one rather than its own starting conditions. The transition is controlled by a start time and an interval (length of the transition). The smooth blend is not very sophisticated (just an interpolation) but it will look OK if the start of the second motion is not too different from the end of the first (don't use this to try to transition between lying down and standing up for instance)      see also: SequentialBlend.h";

%feature("docstring") Piavca::SequentialBlend::SequentialBlend "
Piavca::SequentialBlend::SequentialBlend(Motion *mot1=NULL, Motion *mot2=NULL, float interval=0.2, float start=0.0)
         
        
         
Pass in the two motions, the blend interval (length of the transition) and the start time of the transition. To get the second motion to start at the end of the first pass in the length of the second motion as the blend start time.         ";
%feature("docstring") Piavca::SequentialBlend::SequentialBlend "
Piavca::SequentialBlend::SequentialBlend(const SequentialBlend &sb)
         
        
         
        ";
%feature("docstring") Piavca::SequentialBlend::clone "
virtual Motion* Piavca::SequentialBlend::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") Piavca::SequentialBlend::setMaintainY "
virtual void Piavca::SequentialBlend::setMaintainY(bool b)
         
        
         
        ";
%feature("docstring") Piavca::SequentialBlend::setAccumulateRoot "
virtual void Piavca::SequentialBlend::setAccumulateRoot(bool b)
         
        
         
        ";
%feature("docstring") Piavca::SequentialBlend::setStartTime "
virtual void Piavca::SequentialBlend::setStartTime(float time)
         
        
         
std::cout << \"SequentialBlend::setStartTime \" << name << \" \"         ";
%feature("docstring") Piavca::SequentialBlend::getMotionLength "
float Piavca::SequentialBlend::getMotionLength() const 
         
gets the motion length (transition start + blend interval + length of second motion)         
         
        ";
%feature("docstring") Piavca::SequentialBlend::getFloatValueAtTimeInternal "
float SequentialBlend::getFloatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") Piavca::SequentialBlend::getVecValueAtTimeInternal "
Vec SequentialBlend::getVecValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") Piavca::SequentialBlend::getQuatValueAtTimeInternal "
Quat SequentialBlend::getQuatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") Piavca::SequentialBlend::setBlendStart "
void Piavca::SequentialBlend::setBlendStart(float start)
         
set the time at which tbe blend between the motions starts         
         
        ";
%feature("docstring") Piavca::SequentialBlend::setBlendInterval "
void Piavca::SequentialBlend::setBlendInterval(float interval)
         
sets the length of the transition between the two motions.         
         
        ";
%feature("docstring") Piavca::SequentialBlend::getBlendStart "
float Piavca::SequentialBlend::getBlendStart()
         
get the time at which tbe blend between the motions starts         
         
        ";
%feature("docstring") Piavca::SequentialBlend::getBlendInterval "
float Piavca::SequentialBlend::getBlendInterval()
         
gets the length of the transition between the two motions.         
         
        ";
%feature("docstring") Piavca::SequentialBlend::getTransformedVec "
Vec SequentialBlend::getTransformedVec(int trackId, float t) const 
         
get the value of a keyframed transformed appropriately if it is the root position         
         
        ";
%feature("docstring") Piavca::SequentialBlend::getTransformedQuat "
Quat SequentialBlend::getTransformedQuat(int trackId, float t) const 
         
get the value of a keyframed transformed appropriately if it is the root position         
         
        ";
%feature("docstring") Piavca::SequentialBlend::calculateRootOffsets "
void SequentialBlend::calculateRootOffsets()
         
        
         
        ";
%feature("docstring") Piavca::StandardMotionImp " 

This is the standard implementation of the Motions class.     
       
This is a platform independant implementation. Other subtypes can be made that use platform specific enhancements. The motion in contains a vector of motion tracks that can be accessed by name or through a trackiterator. The class itself should be created using the StdMotionAvatarFactory and only manipulated through the Motion interface class.      see also: StdMotionImp.h";

%feature("docstring") Piavca::StandardMotionImp::addFloatTrack "
void StandardMotionImp::addFloatTrack(int trackId, float initialValue)
         
add a float track         
         
        ";
%feature("docstring") Piavca::StandardMotionImp::addVecTrack "
void StandardMotionImp::addVecTrack(int trackId, const Vec &initialValue)
         
add a Vec track         
         
        ";
%feature("docstring") Piavca::StandardMotionImp::addQuatTrack "
void StandardMotionImp::addQuatTrack(int trackId, const Quat &initialValue)
         
add a Quat track         
         
        ";
%feature("docstring") Piavca::StandardMotionImp::setFloatKeyframe "
void StandardMotionImp::setFloatKeyframe(int trackId, float time, float value)
         
set keyframe value (or create a new one) (only works for floats)         
         
        ";
%feature("docstring") Piavca::StandardMotionImp::setFloatKeyframe "
void StandardMotionImp::setFloatKeyframe(int trackId, float time, float value, float velocity)
         
set keyframe value (or create a new one) with a user specified velocity (only works for floats)         
         
        ";
%feature("docstring") Piavca::StandardMotionImp::setVecKeyframe "
void StandardMotionImp::setVecKeyframe(int trackId, float time, Vec value)
         
set keyframe value (or create a new one) (only works for Vecs)         
         
        ";
%feature("docstring") Piavca::StandardMotionImp::setVecKeyframe "
void StandardMotionImp::setVecKeyframe(int trackId, float time, Vec value, Vec velocity)
         
set keyframe value (or create a new one) with a user specified velocity (only works for Vecs)         
         
        ";
%feature("docstring") Piavca::StandardMotionImp::setQuatKeyframe "
void StandardMotionImp::setQuatKeyframe(int trackId, float time, Quat value)
         
set keyframe value (or create a new one) (only works for Quats)         
         
        ";
%feature("docstring") Piavca::StandardMotionImp::setQuatKeyframe "
void StandardMotionImp::setQuatKeyframe(int trackId, float time, Quat value, Quat velocity)
         
set keyframe value (or create a new one) with a user specified velocity (only works for Quats)         
         
        ";
%feature("docstring") Piavca::StandardMotionImp::getNumKeyframes "
int StandardMotionImp::getNumKeyframes(int trackId)
         
returns the number of keyframes that a particular track has         
         
        ";
%feature("docstring") Piavca::StandardMotionImp::getKeyframeTime "
float StandardMotionImp::getKeyframeTime(int trackId, int keyframe)
         
returns the time of a particular keyframe         
         
        ";
%feature("docstring") Piavca::StandardMotionImp::getFloatValueAtTimeInternal "
float StandardMotionImp::getFloatValueAtTimeInternal(int trackId, float time)
         
get the keyframe value at time (only works for floats)         
         
        ";
%feature("docstring") Piavca::StandardMotionImp::getVecValueAtTimeInternal "
Vec StandardMotionImp::getVecValueAtTimeInternal(int trackId, float time)
         
get the keyframe value at time (only works for Vecs)         
         
        ";
%feature("docstring") Piavca::StandardMotionImp::getQuatValueAtTimeInternal "
Quat StandardMotionImp::getQuatValueAtTimeInternal(int trackId, float time)
         
get the keyframe value at time (only works for Quats)         
         
        ";
%feature("docstring") Piavca::StandardMotionImp::StandardMotionImp "
Piavca::StandardMotionImp::StandardMotionImp(bool _facial=false)
         
creates an empty motion (no tracks)         
         
        ";
%feature("docstring") Piavca::StandardMotionImp::StandardMotionImp "
StandardMotionImp::StandardMotionImp(tstring motionFileName, int flags, Motion *basePosture=NULL, bool test=false)
         
read in from a bvh file         
         
        ";
%feature("docstring") Piavca::StandardMotionImp::StandardMotionImp "
StandardMotionImp::StandardMotionImp(const StandardMotionImp &mot)
         
        
         
        ";
%feature("docstring") Piavca::StandardMotionImp::clone "
MotionImp * StandardMotionImp::clone()
         
creates a copy of the motion imp         
         
This is a virtual method in MotionImp which allows you to get a (pointer to a) copy of a motion imp correctly without knowing what type it is.         ";
%feature("docstring") Piavca::StandardMotionImp::~StandardMotionImp "
Piavca::StandardMotionImp::~StandardMotionImp()
         
        
         
        ";
%feature("docstring") Piavca::StandardMotionImp::isNull "
bool Piavca::StandardMotionImp::isNull(int trackId) const 
         
given an iterator tests whether it actually points to anything or if its null         
         
        ";
%feature("docstring") Piavca::StandardMotionImp::getTrackType "
trackType StandardMotionImp::getTrackType(int trackId) const 
         
get the type of the track corresponding to an iterator         
         
        ";
%feature("docstring") Piavca::StandardMotionImp::getMotionLength "
float StandardMotionImp::getMotionLength() const 
         
returns the length of the motion         
         
        ";
%feature("docstring") Piavca::StandardMotionImp::deleteAllTracks "
void StandardMotionImp::deleteAllTracks()
         
delete all tracks         
         
        ";
%feature("docstring") Piavca::StandardMotionImp::clearTrack "
void StandardMotionImp::clearTrack(int trackId, bool createFirstFrame=true)
         
clears a particular track (deletes all keyframes without deleting the track itself)         
         
        ";
%feature("docstring") Piavca::StandardMotionImp::clearAllTracks "
void StandardMotionImp::clearAllTracks(bool createFirstFrame=true)
         
clear all tracks (deletes all keyframes without deleting the tracks themselves)         
         
        ";
%feature("docstring") Piavca::StdMotionCore " 

A core class with a factory method that creates motion objects based on the standard implementation.     
       
This is a subtype of the UCL avatar factory      see also: StdMotionCore.h";

%feature("docstring") Piavca::StdMotionCore::StdMotionCore "
Piavca::StdMotionCore::StdMotionCore()
         
        
         
        ";
%feature("docstring") Piavca::StdMotionCore::~StdMotionCore "
virtual Piavca::StdMotionCore::~StdMotionCore()
         
        
         
        ";
%feature("docstring") Piavca::StdMotionCore::createMotionImp "
MotionImp * StdMotionCore::createMotionImp(tstring filename, bool facial, int flags, Motion *bsaePosture=NULL)
         
creates the motion implementation (it in fact creates a StandardMotionImp object)         
         
        ";
%feature("docstring") Piavca::SubMotion " 

    
       
     see also: SubMotion.h";

%feature("docstring") Piavca::SubMotion::SubMotion "
SubMotion::SubMotion()
         
        
         
        ";
%feature("docstring") Piavca::SubMotion::SubMotion "
SubMotion::SubMotion(Motion *m, float _start, float _end)
         
        
         
        ";
%feature("docstring") Piavca::SubMotion::SubMotion "
SubMotion::SubMotion(const SubMotion &sm)
         
        
         
        ";
%feature("docstring") Piavca::SubMotion::clone "
Motion * SubMotion::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") Piavca::SubMotion::getMotionLength "
float SubMotion::getMotionLength() const 
         
gets the length of the motion in seconds         
         
        ";
%feature("docstring") Piavca::SubMotion::setStart "
void SubMotion::setStart(float s)
         
Sets the start of the range to be played.         
         
        ";
%feature("docstring") Piavca::SubMotion::setEnd "
void SubMotion::setEnd(float e)
         
Sets the end of the range to be played.         
         
        ";
%feature("docstring") Piavca::SubMotion::getFloatValueAtTimeInternal "
PIAVCA_EXPORT float SubMotion::getFloatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") Piavca::SubMotion::getVecValueAtTimeInternal "
PIAVCA_EXPORT Vec SubMotion::getVecValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") Piavca::SubMotion::getQuatValueAtTimeInternal "
PIAVCA_EXPORT Quat SubMotion::getQuatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") Piavca::SubMotion::getAdjustedTime "
float SubMotion::getAdjustedTime(float time)
         
        
         
        ";
%feature("docstring") SwigDirector_AvatarTimeCallback " 

    
       
     see also: Piavca_wrap.h";

%feature("docstring") SwigDirector_AvatarTimeCallback::SwigDirector_AvatarTimeCallback "
SwigDirector_AvatarTimeCallback::SwigDirector_AvatarTimeCallback(PyObject *self, tstring _name)
         
        
         
        ";
%feature("docstring") SwigDirector_AvatarTimeCallback::timeStep "
virtual void SwigDirector_AvatarTimeCallback::timeStep(Piavca::Avatar *avatar, float time)
         
implement this to make the callback do things         
         
It's called every frame with by the API which passes in the avatar to which the callback is attatched         ";
%feature("docstring") SwigDirector_AvatarTimeCallback::~SwigDirector_AvatarTimeCallback "
virtual SwigDirector_AvatarTimeCallback::~SwigDirector_AvatarTimeCallback()
         
        
         
        ";
%feature("docstring") SwigDirector_AvatarTimeCallback::init "
virtual void SwigDirector_AvatarTimeCallback::init(Piavca::Avatar *avatar)
         
This is a setup method for the callback.         
         
It's called when the callback is registered         ";
%feature("docstring") SwigDirector_AvatarTimeCallback::swig_get_inner "
bool SwigDirector_AvatarTimeCallback::swig_get_inner(const char *name) const 
         
        
         
        ";
%feature("docstring") SwigDirector_AvatarTimeCallback::swig_set_inner "
void SwigDirector_AvatarTimeCallback::swig_set_inner(const char *name, bool val) const 
         
        
         
        ";
%feature("docstring") SwigDirector_BlendBetween " 

    
       
     see also: Piavca_wrap.h";

%feature("docstring") SwigDirector_BlendBetween::SwigDirector_BlendBetween "
SwigDirector_BlendBetween::SwigDirector_BlendBetween(PyObject *self, Piavca::Motion *m1=NULL, Piavca::Motion *m2=NULL, float _blend=0.0f)
         
        
         
        ";
%feature("docstring") SwigDirector_BlendBetween::SwigDirector_BlendBetween "
SwigDirector_BlendBetween::SwigDirector_BlendBetween(PyObject *self, Piavca::BlendBetween const &b)
         
        
         
        ";
%feature("docstring") SwigDirector_BlendBetween::findSub "
virtual Piavca::Motion* SwigDirector_BlendBetween::findSub(Piavca::tstring nm)
         
finds the first submotion with a given name         
         
        ";
%feature("docstring") SwigDirector_BlendBetween::load "
virtual void SwigDirector_BlendBetween::load(Piavca::Avatar *av)
         
called when the motion is loaded into an avatar         
         
        ";
%feature("docstring") SwigDirector_BlendBetween::setStartTime "
virtual void SwigDirector_BlendBetween::setStartTime(float time)
         
sets the start time of the motion. Called when its loaded into an avatar.         
         
        ";
%feature("docstring") SwigDirector_BlendBetween::getFloatValueAtTimeInternal "
virtual float SwigDirector_BlendBetween::getFloatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe.         
         
The result is the linear interpolation of the values of the two motions or if the track does not exist in the one motion, the value of the other         ";
%feature("docstring") SwigDirector_BlendBetween::getVecValueAtTimeInternal "
virtual Piavca::Vec SwigDirector_BlendBetween::getVecValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe.         
         
The result is the linear interpolation of the values of the two motions or if the track does not exist in the one motion, the value of the other         ";
%feature("docstring") SwigDirector_BlendBetween::getQuatValueAtTimeInternal "
virtual Piavca::Quat SwigDirector_BlendBetween::getQuatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe.         
         
The result is the linear interpolation (slerp) of the values of the two motions or if the track does not exist in the one motion, the value of the other         ";
%feature("docstring") SwigDirector_BlendBetween::isRandomAccess "
virtual bool SwigDirector_BlendBetween::isRandomAccess()
         
whether you can access a motions value at frames other than the current one         
         
        ";
%feature("docstring") SwigDirector_BlendBetween::~SwigDirector_BlendBetween "
virtual SwigDirector_BlendBetween::~SwigDirector_BlendBetween()
         
        
         
        ";
%feature("docstring") SwigDirector_BlendBetween::reset "
virtual void SwigDirector_BlendBetween::reset()
         
does any resetting needed         
         
        ";
%feature("docstring") SwigDirector_BlendBetween::clone "
virtual Piavca::Motion* SwigDirector_BlendBetween::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") SwigDirector_BlendBetween::getMotionLength "
virtual float SwigDirector_BlendBetween::getMotionLength() const 
         
gets the length of the combined motion (by default the length of the longer of the two)         
         
        ";
%feature("docstring") SwigDirector_BlendBetween::isFacial "
virtual bool SwigDirector_BlendBetween::isFacial()
         
whether it is a face or body motion         
         
        ";
%feature("docstring") SwigDirector_BlendBetween::unload "
virtual void SwigDirector_BlendBetween::unload()
         
called when the motion is unloaded from an avatar         
         
        ";
%feature("docstring") SwigDirector_BlendBetween::loaded "
virtual bool SwigDirector_BlendBetween::loaded()
         
checks if the motion has been loaded into an avatar         
         
        ";
%feature("docstring") SwigDirector_BlendBetween::printInfo "
virtual void SwigDirector_BlendBetween::printInfo()
         
prints out info about the motion heirarchy         
         
        ";
%feature("docstring") SwigDirector_BlendBetween::findSubByType "
virtual Piavca::Motion* SwigDirector_BlendBetween::findSubByType(type_info const &ty)
         
finds the first submotion with a given type         
         
        ";
%feature("docstring") SwigDirector_BlendBetween::isNull "
virtual bool SwigDirector_BlendBetween::isNull(int trackId) const 
         
given a track ID tests whether it actually points to anything or if its null         
         
is null if the track is null in both motions.         ";
%feature("docstring") SwigDirector_BlendBetween::getTrackType "
virtual Piavca::trackType SwigDirector_BlendBetween::getTrackType(int trackId) const 
         
get the type of the track corresponding to an iterator         
         
        ";
%feature("docstring") SwigDirector_BlendBetween::swig_get_inner "
bool SwigDirector_BlendBetween::swig_get_inner(const char *name) const 
         
        
         
        ";
%feature("docstring") SwigDirector_BlendBetween::swig_set_inner "
void SwigDirector_BlendBetween::swig_set_inner(const char *name, bool val) const 
         
        
         
        ";
%feature("docstring") SwigDirector_ChoiceLoopMotion " 

    
       
     see also: Piavca_wrap.h";

%feature("docstring") SwigDirector_ChoiceLoopMotion::SwigDirector_ChoiceLoopMotion "
SwigDirector_ChoiceLoopMotion::SwigDirector_ChoiceLoopMotion(PyObject *self)
         
        
         
        ";
%feature("docstring") SwigDirector_ChoiceLoopMotion::SwigDirector_ChoiceLoopMotion "
SwigDirector_ChoiceLoopMotion::SwigDirector_ChoiceLoopMotion(PyObject *self, Piavca::MotionVec const &mpv, float endTime=-1.0, float interval=0.01)
         
        
         
        ";
%feature("docstring") SwigDirector_ChoiceLoopMotion::SwigDirector_ChoiceLoopMotion "
SwigDirector_ChoiceLoopMotion::SwigDirector_ChoiceLoopMotion(PyObject *self, Piavca::ChoiceLoopMotion const &cl)
         
        
         
        ";
%feature("docstring") SwigDirector_ChoiceLoopMotion::findSub "
virtual Piavca::Motion* SwigDirector_ChoiceLoopMotion::findSub(Piavca::tstring nm)
         
finds the first submotion with a given name         
         
        ";
%feature("docstring") SwigDirector_ChoiceLoopMotion::load "
virtual void SwigDirector_ChoiceLoopMotion::load(Piavca::Avatar *av)
         
called when the motion is loaded into an avatar         
         
        ";
%feature("docstring") SwigDirector_ChoiceLoopMotion::loaded "
virtual bool SwigDirector_ChoiceLoopMotion::loaded(Piavca::Avatar *av)
         
        
         
        ";
%feature("docstring") SwigDirector_ChoiceLoopMotion::setStartTime "
virtual void SwigDirector_ChoiceLoopMotion::setStartTime(float time)
         
        
         
std::cout << \"SequentialBlend::setStartTime \" << name << \" \"         ";
%feature("docstring") SwigDirector_ChoiceLoopMotion::getFloatValueAtTimeInternal "
virtual float SwigDirector_ChoiceLoopMotion::getFloatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
if the end has been reached it reblends to start again at the beginning         ";
%feature("docstring") SwigDirector_ChoiceLoopMotion::getVecValueAtTimeInternal "
virtual Piavca::Vec SwigDirector_ChoiceLoopMotion::getVecValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
if the end has been reached it reblends to start again at the beginning         ";
%feature("docstring") SwigDirector_ChoiceLoopMotion::getQuatValueAtTimeInternal "
virtual Piavca::Quat SwigDirector_ChoiceLoopMotion::getQuatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
if the end has been reached it reblends to start again at the beginning         ";
%feature("docstring") SwigDirector_ChoiceLoopMotion::setTimingParams "
virtual void SwigDirector_ChoiceLoopMotion::setTimingParams(float minTimeScale, float maxTimeScale)
         
sets the minimum and maximum times that can be generated         
         
        ";
%feature("docstring") SwigDirector_ChoiceLoopMotion::reblend "
virtual void SwigDirector_ChoiceLoopMotion::reblend(float time)
         
called each time around the loop         
         
It can be called by the client to interrupt the current motion.         ";
%feature("docstring") SwigDirector_ChoiceLoopMotion::isRandomAccess "
virtual bool SwigDirector_ChoiceLoopMotion::isRandomAccess()
         
whether you can access a motions value at frames other than the current one         
         
        ";
%feature("docstring") SwigDirector_ChoiceLoopMotion::~SwigDirector_ChoiceLoopMotion "
virtual SwigDirector_ChoiceLoopMotion::~SwigDirector_ChoiceLoopMotion()
         
        
         
        ";
%feature("docstring") SwigDirector_ChoiceLoopMotion::reset "
virtual void SwigDirector_ChoiceLoopMotion::reset()
         
does any resetting needed         
         
        ";
%feature("docstring") SwigDirector_ChoiceLoopMotion::clone "
virtual Piavca::Motion* SwigDirector_ChoiceLoopMotion::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") SwigDirector_ChoiceLoopMotion::isFacial "
virtual bool SwigDirector_ChoiceLoopMotion::isFacial()
         
whether it is a face or body motion         
         
        ";
%feature("docstring") SwigDirector_ChoiceLoopMotion::getMotionLength "
virtual float SwigDirector_ChoiceLoopMotion::getMotionLength() const 
         
gets the motion length (transition start + blend interval + length of second motion)         
         
        ";
%feature("docstring") SwigDirector_ChoiceLoopMotion::loaded "
virtual bool SwigDirector_ChoiceLoopMotion::loaded()
         
checks if the motion has been loaded into an avatar         
         
        ";
%feature("docstring") SwigDirector_ChoiceLoopMotion::unload "
virtual void SwigDirector_ChoiceLoopMotion::unload()
         
called when the motion is unloaded from an avatar         
         
        ";
%feature("docstring") SwigDirector_ChoiceLoopMotion::setMaintainY "
virtual void SwigDirector_ChoiceLoopMotion::setMaintainY(bool b)
         
        
         
        ";
%feature("docstring") SwigDirector_ChoiceLoopMotion::setAccumulateRoot "
virtual void SwigDirector_ChoiceLoopMotion::setAccumulateRoot(bool b)
         
        
         
        ";
%feature("docstring") SwigDirector_ChoiceLoopMotion::printInfo "
virtual void SwigDirector_ChoiceLoopMotion::printInfo()
         
prints out info about the motion heirarchy         
         
        ";
%feature("docstring") SwigDirector_ChoiceLoopMotion::findSubByType "
virtual Piavca::Motion* SwigDirector_ChoiceLoopMotion::findSubByType(type_info const &ty)
         
finds the first submotion with a given type         
         
        ";
%feature("docstring") SwigDirector_ChoiceLoopMotion::setMotion "
virtual void SwigDirector_ChoiceLoopMotion::setMotion(Piavca::Motion *m)
         
sets the motion to be looped         
         
std::cout << \"setting motion for loop\n\";         ";
%feature("docstring") SwigDirector_ChoiceLoopMotion::addMotion "
virtual void SwigDirector_ChoiceLoopMotion::addMotion(Piavca::Motion *mot)
         
        
         
        ";
%feature("docstring") SwigDirector_ChoiceLoopMotion::isNull "
virtual bool SwigDirector_ChoiceLoopMotion::isNull(int trackId) const 
         
given a track ID tests whether it actually points to anything or if its null         
         
is null if the track is null in both motions.         ";
%feature("docstring") SwigDirector_ChoiceLoopMotion::getTrackType "
virtual Piavca::trackType SwigDirector_ChoiceLoopMotion::getTrackType(int trackId) const 
         
get the type of the track corresponding to an iterator         
         
        ";
%feature("docstring") SwigDirector_ChoiceLoopMotion::swig_get_inner "
bool SwigDirector_ChoiceLoopMotion::swig_get_inner(const char *name) const 
         
        
         
        ";
%feature("docstring") SwigDirector_ChoiceLoopMotion::swig_set_inner "
void SwigDirector_ChoiceLoopMotion::swig_set_inner(const char *name, bool val) const 
         
        
         
        ";
%feature("docstring") SwigDirector_DiadicGazeMotion " 

    
       
     see also: Piavca_wrap.h";

%feature("docstring") SwigDirector_DiadicGazeMotion::SwigDirector_DiadicGazeMotion "
SwigDirector_DiadicGazeMotion::SwigDirector_DiadicGazeMotion(PyObject *self, Piavca::Avatar *other, float endTime=-1.0, float interval=0.01)
         
        
         
        ";
%feature("docstring") SwigDirector_DiadicGazeMotion::SwigDirector_DiadicGazeMotion "
SwigDirector_DiadicGazeMotion::SwigDirector_DiadicGazeMotion(PyObject *self, Piavca::DiadicGazeMotion const &dg)
         
        
         
        ";
%feature("docstring") SwigDirector_DiadicGazeMotion::findSub "
virtual Piavca::Motion* SwigDirector_DiadicGazeMotion::findSub(Piavca::tstring nm)
         
finds the first submotion with a given name         
         
        ";
%feature("docstring") SwigDirector_DiadicGazeMotion::load "
virtual void SwigDirector_DiadicGazeMotion::load(Piavca::Avatar *av)
         
called when the motion is loaded into an avatar         
         
        ";
%feature("docstring") SwigDirector_DiadicGazeMotion::setStartTime "
virtual void SwigDirector_DiadicGazeMotion::setStartTime(float time)
         
        
         
std::cout << \"SequentialBlend::setStartTime \" << name << \" \"         ";
%feature("docstring") SwigDirector_DiadicGazeMotion::getFloatValueAtTimeInternal "
virtual float SwigDirector_DiadicGazeMotion::getFloatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
if the end has been reached it reblends to start again at the beginning         ";
%feature("docstring") SwigDirector_DiadicGazeMotion::getVecValueAtTimeInternal "
virtual Piavca::Vec SwigDirector_DiadicGazeMotion::getVecValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
if the end has been reached it reblends to start again at the beginning         ";
%feature("docstring") SwigDirector_DiadicGazeMotion::getQuatValueAtTimeInternal "
virtual Piavca::Quat SwigDirector_DiadicGazeMotion::getQuatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
if the end has been reached it reblends to start again at the beginning         ";
%feature("docstring") SwigDirector_DiadicGazeMotion::reblend "
virtual void SwigDirector_DiadicGazeMotion::reblend(float time)
         
saves the state of the motion at time and start blending the motion back into that from the start         
         
        ";
%feature("docstring") SwigDirector_DiadicGazeMotion::isRandomAccess "
virtual bool SwigDirector_DiadicGazeMotion::isRandomAccess()
         
whether you can access a motions value at frames other than the current one         
         
        ";
%feature("docstring") SwigDirector_DiadicGazeMotion::~SwigDirector_DiadicGazeMotion "
virtual SwigDirector_DiadicGazeMotion::~SwigDirector_DiadicGazeMotion()
         
        
         
        ";
%feature("docstring") SwigDirector_DiadicGazeMotion::reset "
virtual void SwigDirector_DiadicGazeMotion::reset()
         
does any resetting needed         
         
        ";
%feature("docstring") SwigDirector_DiadicGazeMotion::clone "
virtual Piavca::Motion* SwigDirector_DiadicGazeMotion::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") SwigDirector_DiadicGazeMotion::isFacial "
virtual bool SwigDirector_DiadicGazeMotion::isFacial()
         
whether it is a face or body motion         
         
        ";
%feature("docstring") SwigDirector_DiadicGazeMotion::getMotionLength "
virtual float SwigDirector_DiadicGazeMotion::getMotionLength() const 
         
gets the motion length (transition start + blend interval + length of second motion)         
         
        ";
%feature("docstring") SwigDirector_DiadicGazeMotion::unload "
virtual void SwigDirector_DiadicGazeMotion::unload()
         
called when the motion is unloaded from an avatar         
         
        ";
%feature("docstring") SwigDirector_DiadicGazeMotion::loaded "
virtual bool SwigDirector_DiadicGazeMotion::loaded()
         
checks if the motion has been loaded into an avatar         
         
        ";
%feature("docstring") SwigDirector_DiadicGazeMotion::printInfo "
virtual void SwigDirector_DiadicGazeMotion::printInfo()
         
prints out info about the motion heirarchy         
         
        ";
%feature("docstring") SwigDirector_DiadicGazeMotion::setMaintainY "
virtual void SwigDirector_DiadicGazeMotion::setMaintainY(bool b)
         
        
         
        ";
%feature("docstring") SwigDirector_DiadicGazeMotion::setAccumulateRoot "
virtual void SwigDirector_DiadicGazeMotion::setAccumulateRoot(bool b)
         
        
         
        ";
%feature("docstring") SwigDirector_DiadicGazeMotion::lookAt "
virtual bool SwigDirector_DiadicGazeMotion::lookAt(Piavca::tstring name, bool force=false)
         
        
         
        ";
%feature("docstring") SwigDirector_DiadicGazeMotion::findSubByType "
virtual Piavca::Motion* SwigDirector_DiadicGazeMotion::findSubByType(type_info const &ty)
         
finds the first submotion with a given type         
         
        ";
%feature("docstring") SwigDirector_DiadicGazeMotion::setMotion "
virtual void SwigDirector_DiadicGazeMotion::setMotion(Piavca::Motion *mot)
         
sets the motion to be blended in         
         
        ";
%feature("docstring") SwigDirector_DiadicGazeMotion::isNull "
virtual bool SwigDirector_DiadicGazeMotion::isNull(int trackId) const 
         
given a track ID tests whether it actually points to anything or if its null         
         
is null if the track is null in both motions.         ";
%feature("docstring") SwigDirector_DiadicGazeMotion::getTrackType "
virtual Piavca::trackType SwigDirector_DiadicGazeMotion::getTrackType(int trackId) const 
         
get the type of the track corresponding to an iterator         
         
        ";
%feature("docstring") SwigDirector_DiadicGazeMotion::swig_get_inner "
bool SwigDirector_DiadicGazeMotion::swig_get_inner(const char *name) const 
         
        
         
        ";
%feature("docstring") SwigDirector_DiadicGazeMotion::swig_set_inner "
void SwigDirector_DiadicGazeMotion::swig_set_inner(const char *name, bool val) const 
         
        
         
        ";
%feature("docstring") SwigDirector_LookAtMotion " 

    
       
     see also: Piavca_wrap.h";

%feature("docstring") SwigDirector_LookAtMotion::SwigDirector_LookAtMotion "
SwigDirector_LookAtMotion::SwigDirector_LookAtMotion(PyObject *self, Piavca::Avatar *target, int joint, float _endTime=-1, float _interval=0.5)
         
        
         
        ";
%feature("docstring") SwigDirector_LookAtMotion::SwigDirector_LookAtMotion "
SwigDirector_LookAtMotion::SwigDirector_LookAtMotion(PyObject *self, Piavca::Object *target, float _endTime=-1, float _interval=0.5)
         
        
         
        ";
%feature("docstring") SwigDirector_LookAtMotion::SwigDirector_LookAtMotion "
SwigDirector_LookAtMotion::SwigDirector_LookAtMotion(PyObject *self, Piavca::Vec const &target, float _endTime=-1, bool _local=false, float _interval=0.5)
         
        
         
        ";
%feature("docstring") SwigDirector_LookAtMotion::SwigDirector_LookAtMotion "
SwigDirector_LookAtMotion::SwigDirector_LookAtMotion(PyObject *self, Piavca::LookAtMotion const &lam)
         
        
         
        ";
%feature("docstring") SwigDirector_LookAtMotion::findSub "
virtual Piavca::Motion* SwigDirector_LookAtMotion::findSub(Piavca::tstring nm)
         
finds the first submotion with a given name         
         
        ";
%feature("docstring") SwigDirector_LookAtMotion::load "
virtual void SwigDirector_LookAtMotion::load(Piavca::Avatar *av)
         
called when the motion is loaded into an avatar         
         
        ";
%feature("docstring") SwigDirector_LookAtMotion::setStartTime "
virtual void SwigDirector_LookAtMotion::setStartTime(float t)
         
sets the start time of the motion. Called when its loaded into an avatar.         
         
        ";
%feature("docstring") SwigDirector_LookAtMotion::getFloatValueAtTimeInternal "
virtual float SwigDirector_LookAtMotion::getFloatValueAtTimeInternal(int trackId, float time)
         
get the value of a track at a given time (only works for floats)         
         
        ";
%feature("docstring") SwigDirector_LookAtMotion::getVecValueAtTimeInternal "
virtual Piavca::Vec SwigDirector_LookAtMotion::getVecValueAtTimeInternal(int trackId, float time)
         
get the value of a track at a given time (only works for Vecs)         
         
        ";
%feature("docstring") SwigDirector_LookAtMotion::getQuatValueAtTimeInternal "
virtual Piavca::Quat SwigDirector_LookAtMotion::getQuatValueAtTimeInternal(int trackId, float time)
         
get the value of a track at a given time (only works for Quats)         
         
        ";
%feature("docstring") SwigDirector_LookAtMotion::isRandomAccess "
virtual bool SwigDirector_LookAtMotion::isRandomAccess()
         
whether you can access a motions value at frames other than the current one         
         
        ";
%feature("docstring") SwigDirector_LookAtMotion::reset "
virtual void SwigDirector_LookAtMotion::reset()
         
does any resetting needed         
         
        ";
%feature("docstring") SwigDirector_LookAtMotion::~SwigDirector_LookAtMotion "
virtual SwigDirector_LookAtMotion::~SwigDirector_LookAtMotion()
         
        
         
        ";
%feature("docstring") SwigDirector_LookAtMotion::clone "
virtual Piavca::Motion* SwigDirector_LookAtMotion::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") SwigDirector_LookAtMotion::isFacial "
virtual bool SwigDirector_LookAtMotion::isFacial()
         
whether it is a face or body motion         
         
        ";
%feature("docstring") SwigDirector_LookAtMotion::getMotionLength "
virtual float SwigDirector_LookAtMotion::getMotionLength() const 
         
returns the length of the motion         
         
        ";
%feature("docstring") SwigDirector_LookAtMotion::loaded "
virtual bool SwigDirector_LookAtMotion::loaded()
         
checks if the motion has been loaded into an avatar         
         
        ";
%feature("docstring") SwigDirector_LookAtMotion::unload "
virtual void SwigDirector_LookAtMotion::unload()
         
called when the motion is unloaded from an avatar         
         
        ";
%feature("docstring") SwigDirector_LookAtMotion::printInfo "
virtual void SwigDirector_LookAtMotion::printInfo()
         
prints out info about the motion heirarchy         
         
        ";
%feature("docstring") SwigDirector_LookAtMotion::findSubByType "
virtual Piavca::Motion* SwigDirector_LookAtMotion::findSubByType(type_info const &ty)
         
finds the first submotion with a given type         
         
        ";
%feature("docstring") SwigDirector_LookAtMotion::isNull "
virtual bool SwigDirector_LookAtMotion::isNull(int trackId) const 
         
given a track ID tests whether it actually points to anything or if its null         
         
        ";
%feature("docstring") SwigDirector_LookAtMotion::getTrackType "
virtual Piavca::trackType SwigDirector_LookAtMotion::getTrackType(int trackId) const 
         
get the type of the track corresponding to an ID         
         
        ";
%feature("docstring") SwigDirector_LookAtMotion::swig_get_inner "
bool SwigDirector_LookAtMotion::swig_get_inner(const char *name) const 
         
        
         
        ";
%feature("docstring") SwigDirector_LookAtMotion::swig_set_inner "
void SwigDirector_LookAtMotion::swig_set_inner(const char *name, bool val) const 
         
        
         
        ";
%feature("docstring") SwigDirector_LoopMotion " 

    
       
     see also: Piavca_wrap.h";

%feature("docstring") SwigDirector_LoopMotion::SwigDirector_LoopMotion "
SwigDirector_LoopMotion::SwigDirector_LoopMotion(PyObject *self, Piavca::Motion *mot=NULL, float _endTime=-1, float interval=0.01)
         
        
         
        ";
%feature("docstring") SwigDirector_LoopMotion::SwigDirector_LoopMotion "
SwigDirector_LoopMotion::SwigDirector_LoopMotion(PyObject *self, Piavca::LoopMotion const &l)
         
        
         
        ";
%feature("docstring") SwigDirector_LoopMotion::findSub "
virtual Piavca::Motion* SwigDirector_LoopMotion::findSub(Piavca::tstring nm)
         
finds the first submotion with a given name         
         
        ";
%feature("docstring") SwigDirector_LoopMotion::load "
virtual void SwigDirector_LoopMotion::load(Piavca::Avatar *av)
         
called when the motion is loaded into an avatar         
         
        ";
%feature("docstring") SwigDirector_LoopMotion::setStartTime "
virtual void SwigDirector_LoopMotion::setStartTime(float time)
         
        
         
std::cout << \"SequentialBlend::setStartTime \" << name << \" \"         ";
%feature("docstring") SwigDirector_LoopMotion::reblend "
virtual void SwigDirector_LoopMotion::reblend(float time)
         
saves the state of the motion at time and start blending the motion back into that from the start         
         
        ";
%feature("docstring") SwigDirector_LoopMotion::getFloatValueAtTimeInternal "
virtual float SwigDirector_LoopMotion::getFloatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
if the end has been reached it reblends to start again at the beginning         ";
%feature("docstring") SwigDirector_LoopMotion::getVecValueAtTimeInternal "
virtual Piavca::Vec SwigDirector_LoopMotion::getVecValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
if the end has been reached it reblends to start again at the beginning         ";
%feature("docstring") SwigDirector_LoopMotion::getQuatValueAtTimeInternal "
virtual Piavca::Quat SwigDirector_LoopMotion::getQuatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
if the end has been reached it reblends to start again at the beginning         ";
%feature("docstring") SwigDirector_LoopMotion::isRandomAccess "
virtual bool SwigDirector_LoopMotion::isRandomAccess()
         
whether you can access a motions value at frames other than the current one         
         
        ";
%feature("docstring") SwigDirector_LoopMotion::~SwigDirector_LoopMotion "
virtual SwigDirector_LoopMotion::~SwigDirector_LoopMotion()
         
        
         
        ";
%feature("docstring") SwigDirector_LoopMotion::reset "
virtual void SwigDirector_LoopMotion::reset()
         
does any resetting needed         
         
        ";
%feature("docstring") SwigDirector_LoopMotion::clone "
virtual Piavca::Motion* SwigDirector_LoopMotion::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") SwigDirector_LoopMotion::isFacial "
virtual bool SwigDirector_LoopMotion::isFacial()
         
whether it is a face or body motion         
         
        ";
%feature("docstring") SwigDirector_LoopMotion::getMotionLength "
virtual float SwigDirector_LoopMotion::getMotionLength() const 
         
gets the motion length (transition start + blend interval + length of second motion)         
         
        ";
%feature("docstring") SwigDirector_LoopMotion::unload "
virtual void SwigDirector_LoopMotion::unload()
         
called when the motion is unloaded from an avatar         
         
        ";
%feature("docstring") SwigDirector_LoopMotion::loaded "
virtual bool SwigDirector_LoopMotion::loaded()
         
checks if the motion has been loaded into an avatar         
         
        ";
%feature("docstring") SwigDirector_LoopMotion::printInfo "
virtual void SwigDirector_LoopMotion::printInfo()
         
prints out info about the motion heirarchy         
         
        ";
%feature("docstring") SwigDirector_LoopMotion::setMaintainY "
virtual void SwigDirector_LoopMotion::setMaintainY(bool b)
         
        
         
        ";
%feature("docstring") SwigDirector_LoopMotion::setAccumulateRoot "
virtual void SwigDirector_LoopMotion::setAccumulateRoot(bool b)
         
        
         
        ";
%feature("docstring") SwigDirector_LoopMotion::findSubByType "
virtual Piavca::Motion* SwigDirector_LoopMotion::findSubByType(type_info const &ty)
         
finds the first submotion with a given type         
         
        ";
%feature("docstring") SwigDirector_LoopMotion::setMotion "
virtual void SwigDirector_LoopMotion::setMotion(Piavca::Motion *mot)
         
sets the motion to be blended in         
         
        ";
%feature("docstring") SwigDirector_LoopMotion::isNull "
virtual bool SwigDirector_LoopMotion::isNull(int trackId) const 
         
given a track ID tests whether it actually points to anything or if its null         
         
is null if the track is null in both motions.         ";
%feature("docstring") SwigDirector_LoopMotion::getTrackType "
virtual Piavca::trackType SwigDirector_LoopMotion::getTrackType(int trackId) const 
         
get the type of the track corresponding to an iterator         
         
        ";
%feature("docstring") SwigDirector_LoopMotion::swig_get_inner "
bool SwigDirector_LoopMotion::swig_get_inner(const char *name) const 
         
        
         
        ";
%feature("docstring") SwigDirector_LoopMotion::swig_set_inner "
void SwigDirector_LoopMotion::swig_set_inner(const char *name, bool val) const 
         
        
         
        ";
%feature("docstring") SwigDirector_MaskedMotion " 

    
       
     see also: Piavca_wrap.h";

%feature("docstring") SwigDirector_MaskedMotion::SwigDirector_MaskedMotion "
SwigDirector_MaskedMotion::SwigDirector_MaskedMotion(PyObject *self)
         
        
         
        ";
%feature("docstring") SwigDirector_MaskedMotion::SwigDirector_MaskedMotion "
SwigDirector_MaskedMotion::SwigDirector_MaskedMotion(PyObject *self, Piavca::Motion *_mot1, Piavca::MotionMask const &_mask1, Piavca::Motion *_mot2, Piavca::MotionMask const &_mask2, bool _useSecondary=true)
         
        
         
        ";
%feature("docstring") SwigDirector_MaskedMotion::SwigDirector_MaskedMotion "
SwigDirector_MaskedMotion::SwigDirector_MaskedMotion(PyObject *self, Piavca::MaskedMotion const &mm)
         
        
         
        ";
%feature("docstring") SwigDirector_MaskedMotion::findSub "
virtual Piavca::Motion* SwigDirector_MaskedMotion::findSub(Piavca::tstring nm)
         
finds the first submotion with a given name         
         
        ";
%feature("docstring") SwigDirector_MaskedMotion::load "
virtual void SwigDirector_MaskedMotion::load(Piavca::Avatar *av)
         
called when the motion is loaded into an avatar         
         
        ";
%feature("docstring") SwigDirector_MaskedMotion::setStartTime "
virtual void SwigDirector_MaskedMotion::setStartTime(float time)
         
sets the start time of the motion. Called when its loaded into an avatar.         
         
        ";
%feature("docstring") SwigDirector_MaskedMotion::getFloatValueAtTimeInternal "
virtual float SwigDirector_MaskedMotion::getFloatValueAtTimeInternal(int trackId, float time)
         
internal version of getFloatValueAtTime, to be overridden         
         
        ";
%feature("docstring") SwigDirector_MaskedMotion::getVecValueAtTimeInternal "
virtual Piavca::Vec SwigDirector_MaskedMotion::getVecValueAtTimeInternal(int trackId, float time)
         
internal version of getVecValueAtTime, to be overridden         
         
        ";
%feature("docstring") SwigDirector_MaskedMotion::getQuatValueAtTimeInternal "
virtual Piavca::Quat SwigDirector_MaskedMotion::getQuatValueAtTimeInternal(int trackId, float time)
         
internal version of getQuatValueAtTime, to be overridden         
         
        ";
%feature("docstring") SwigDirector_MaskedMotion::isRandomAccess "
virtual bool SwigDirector_MaskedMotion::isRandomAccess()
         
whether you can access a motions value at frames other than the current one         
         
        ";
%feature("docstring") SwigDirector_MaskedMotion::~SwigDirector_MaskedMotion "
virtual SwigDirector_MaskedMotion::~SwigDirector_MaskedMotion()
         
        
         
        ";
%feature("docstring") SwigDirector_MaskedMotion::reset "
virtual void SwigDirector_MaskedMotion::reset()
         
does any resetting needed         
         
        ";
%feature("docstring") SwigDirector_MaskedMotion::clone "
virtual Piavca::Motion* SwigDirector_MaskedMotion::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") SwigDirector_MaskedMotion::getMotionLength "
virtual float SwigDirector_MaskedMotion::getMotionLength() const 
         
gets the length of the combined motion (by default the length of the longer of the two)         
         
        ";
%feature("docstring") SwigDirector_MaskedMotion::isFacial "
virtual bool SwigDirector_MaskedMotion::isFacial()
         
whether it is a face or body motion         
         
        ";
%feature("docstring") SwigDirector_MaskedMotion::unload "
virtual void SwigDirector_MaskedMotion::unload()
         
called when the motion is unloaded from an avatar         
         
        ";
%feature("docstring") SwigDirector_MaskedMotion::loaded "
virtual bool SwigDirector_MaskedMotion::loaded()
         
checks if the motion has been loaded into an avatar         
         
        ";
%feature("docstring") SwigDirector_MaskedMotion::printInfo "
virtual void SwigDirector_MaskedMotion::printInfo()
         
prints out info about the motion heirarchy         
         
        ";
%feature("docstring") SwigDirector_MaskedMotion::findSubByType "
virtual Piavca::Motion* SwigDirector_MaskedMotion::findSubByType(type_info const &ty)
         
finds the first submotion with a given type         
         
        ";
%feature("docstring") SwigDirector_MaskedMotion::isNull "
virtual bool SwigDirector_MaskedMotion::isNull(int trackId) const 
         
given a track ID tests whether it actually points to anything or if its null         
         
is null if the track is null in both motions.         ";
%feature("docstring") SwigDirector_MaskedMotion::getTrackType "
virtual Piavca::trackType SwigDirector_MaskedMotion::getTrackType(int trackId) const 
         
get the type of the track corresponding to an iterator         
         
        ";
%feature("docstring") SwigDirector_MaskedMotion::swig_get_inner "
bool SwigDirector_MaskedMotion::swig_get_inner(const char *name) const 
         
        
         
        ";
%feature("docstring") SwigDirector_MaskedMotion::swig_set_inner "
void SwigDirector_MaskedMotion::swig_set_inner(const char *name, bool val) const 
         
        
         
        ";
%feature("docstring") SwigDirector_Motion " 

    
       
     see also: Piavca_wrap.h";

%feature("docstring") SwigDirector_Motion::SwigDirector_Motion "
SwigDirector_Motion::SwigDirector_Motion(PyObject *self)
         
        
         
        ";
%feature("docstring") SwigDirector_Motion::SwigDirector_Motion "
SwigDirector_Motion::SwigDirector_Motion(PyObject *self, Piavca::Motion const &mot)
         
        
         
        ";
%feature("docstring") SwigDirector_Motion::findSub "
virtual Piavca::Motion* SwigDirector_Motion::findSub(Piavca::tstring nm)
         
finds the first submotion with a given name         
         
        ";
%feature("docstring") SwigDirector_Motion::load "
virtual void SwigDirector_Motion::load(Piavca::Avatar *av)
         
called when the motion is loaded into an avatar         
         
        ";
%feature("docstring") SwigDirector_Motion::setStartTime "
virtual void SwigDirector_Motion::setStartTime(float t)
         
sets the start time of the motion. Called when its loaded into an avatar.         
         
        ";
%feature("docstring") SwigDirector_Motion::getFloatValueAtTimeInternal "
virtual float SwigDirector_Motion::getFloatValueAtTimeInternal(int trackId, float time)
         
internal version of getFloatValueAtTime, to be overridden         
         
        ";
%feature("docstring") SwigDirector_Motion::getVecValueAtTimeInternal "
virtual Piavca::Vec SwigDirector_Motion::getVecValueAtTimeInternal(int trackId, float time)
         
internal version of getVecValueAtTime, to be overridden         
         
        ";
%feature("docstring") SwigDirector_Motion::getQuatValueAtTimeInternal "
virtual Piavca::Quat SwigDirector_Motion::getQuatValueAtTimeInternal(int trackId, float time)
         
internal version of getQuatValueAtTime, to be overridden         
         
        ";
%feature("docstring") SwigDirector_Motion::isRandomAccess "
virtual bool SwigDirector_Motion::isRandomAccess()
         
whether you can access a motions value at frames other than the current one         
         
        ";
%feature("docstring") SwigDirector_Motion::reset "
virtual void SwigDirector_Motion::reset()
         
does any resetting needed         
         
        ";
%feature("docstring") SwigDirector_Motion::clone "
virtual Piavca::Motion* SwigDirector_Motion::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") SwigDirector_Motion::~SwigDirector_Motion "
virtual SwigDirector_Motion::~SwigDirector_Motion()
         
        
         
        ";
%feature("docstring") SwigDirector_Motion::isFacial "
virtual bool SwigDirector_Motion::isFacial()
         
whether it is a face or body motion         
         
        ";
%feature("docstring") SwigDirector_Motion::getMotionLength "
virtual float SwigDirector_Motion::getMotionLength() const 
         
gets the time of the end of the motion         
         
Though time is represented in floating point, keyframes can only be set as integers to avoid problems with rounding errors. The granularity is the conversion factor between the two.         ";
%feature("docstring") SwigDirector_Motion::loaded "
virtual bool SwigDirector_Motion::loaded()
         
checks if the motion has been loaded into an avatar         
         
        ";
%feature("docstring") SwigDirector_Motion::unload "
virtual void SwigDirector_Motion::unload()
         
called when the motion is unloaded from an avatar         
         
        ";
%feature("docstring") SwigDirector_Motion::printInfo "
virtual void SwigDirector_Motion::printInfo()
         
prints out info about the motion heirarchy         
         
        ";
%feature("docstring") SwigDirector_Motion::findSubByType "
virtual Piavca::Motion* SwigDirector_Motion::findSubByType(type_info const &ty)
         
finds the first submotion with a given type         
         
        ";
%feature("docstring") SwigDirector_Motion::isNull "
virtual bool SwigDirector_Motion::isNull(int trackId) const 
         
given a track ID tests whether it actually points to anything or if its null         
         
        ";
%feature("docstring") SwigDirector_Motion::getTrackType "
virtual Piavca::trackType SwigDirector_Motion::getTrackType(int trackId) const 
         
get the type of the track corresponding to an ID         
         
        ";
%feature("docstring") SwigDirector_Motion::swig_get_inner "
bool SwigDirector_Motion::swig_get_inner(const char *name) const 
         
        
         
        ";
%feature("docstring") SwigDirector_Motion::swig_set_inner "
void SwigDirector_Motion::swig_set_inner(const char *name, bool val) const 
         
        
         
        ";
%feature("docstring") SwigDirector_MotionAdder " 

    
       
     see also: Piavca_wrap.h";

%feature("docstring") SwigDirector_MotionAdder::SwigDirector_MotionAdder "
SwigDirector_MotionAdder::SwigDirector_MotionAdder(PyObject *self, Piavca::Motion *m1=NULL, Piavca::Motion *m2=NULL, float _scaleSecond=1.0)
         
        
         
        ";
%feature("docstring") SwigDirector_MotionAdder::SwigDirector_MotionAdder "
SwigDirector_MotionAdder::SwigDirector_MotionAdder(PyObject *self, Piavca::MotionAdder const &ma)
         
        
         
        ";
%feature("docstring") SwigDirector_MotionAdder::findSub "
virtual Piavca::Motion* SwigDirector_MotionAdder::findSub(Piavca::tstring nm)
         
finds the first submotion with a given name         
         
        ";
%feature("docstring") SwigDirector_MotionAdder::load "
virtual void SwigDirector_MotionAdder::load(Piavca::Avatar *av)
         
called when the motion is loaded into an avatar         
         
        ";
%feature("docstring") SwigDirector_MotionAdder::setStartTime "
virtual void SwigDirector_MotionAdder::setStartTime(float time)
         
sets the start time of the motion. Called when its loaded into an avatar.         
         
        ";
%feature("docstring") SwigDirector_MotionAdder::getFloatValueAtTimeInternal "
virtual float SwigDirector_MotionAdder::getFloatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
The results is the sum of the two motions.         ";
%feature("docstring") SwigDirector_MotionAdder::getVecValueAtTimeInternal "
virtual Piavca::Vec SwigDirector_MotionAdder::getVecValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
The results is the sum of the two motions.         ";
%feature("docstring") SwigDirector_MotionAdder::getQuatValueAtTimeInternal "
virtual Piavca::Quat SwigDirector_MotionAdder::getQuatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
The results is the quaternion multiplication of the two motions (which is similar to vector addition).         ";
%feature("docstring") SwigDirector_MotionAdder::isRandomAccess "
virtual bool SwigDirector_MotionAdder::isRandomAccess()
         
whether you can access a motions value at frames other than the current one         
         
        ";
%feature("docstring") SwigDirector_MotionAdder::~SwigDirector_MotionAdder "
virtual SwigDirector_MotionAdder::~SwigDirector_MotionAdder()
         
        
         
        ";
%feature("docstring") SwigDirector_MotionAdder::reset "
virtual void SwigDirector_MotionAdder::reset()
         
does any resetting needed         
         
        ";
%feature("docstring") SwigDirector_MotionAdder::clone "
virtual Piavca::Motion* SwigDirector_MotionAdder::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") SwigDirector_MotionAdder::getMotionLength "
virtual float SwigDirector_MotionAdder::getMotionLength() const 
         
gets the length of the combined motion (by default the length of the longer of the two)         
         
        ";
%feature("docstring") SwigDirector_MotionAdder::isFacial "
virtual bool SwigDirector_MotionAdder::isFacial()
         
whether it is a face or body motion         
         
        ";
%feature("docstring") SwigDirector_MotionAdder::unload "
virtual void SwigDirector_MotionAdder::unload()
         
called when the motion is unloaded from an avatar         
         
        ";
%feature("docstring") SwigDirector_MotionAdder::loaded "
virtual bool SwigDirector_MotionAdder::loaded()
         
checks if the motion has been loaded into an avatar         
         
        ";
%feature("docstring") SwigDirector_MotionAdder::printInfo "
virtual void SwigDirector_MotionAdder::printInfo()
         
prints out info about the motion heirarchy         
         
        ";
%feature("docstring") SwigDirector_MotionAdder::findSubByType "
virtual Piavca::Motion* SwigDirector_MotionAdder::findSubByType(type_info const &ty)
         
finds the first submotion with a given type         
         
        ";
%feature("docstring") SwigDirector_MotionAdder::isNull "
virtual bool SwigDirector_MotionAdder::isNull(int trackId) const 
         
given a track ID tests whether it actually points to anything or if its null         
         
is null if the track is null in both motions.         ";
%feature("docstring") SwigDirector_MotionAdder::getTrackType "
virtual Piavca::trackType SwigDirector_MotionAdder::getTrackType(int trackId) const 
         
get the type of the track corresponding to an iterator         
         
        ";
%feature("docstring") SwigDirector_MotionAdder::swig_get_inner "
bool SwigDirector_MotionAdder::swig_get_inner(const char *name) const 
         
        
         
        ";
%feature("docstring") SwigDirector_MotionAdder::swig_set_inner "
void SwigDirector_MotionAdder::swig_set_inner(const char *name, bool val) const 
         
        
         
        ";
%feature("docstring") SwigDirector_MotionSaver " 

    
       
     see also: Piavca_wrap.h";

%feature("docstring") SwigDirector_MotionSaver::SwigDirector_MotionSaver "
SwigDirector_MotionSaver::SwigDirector_MotionSaver(PyObject *self, Piavca::Motion *mot)
         
        
         
        ";
%feature("docstring") SwigDirector_MotionSaver::SwigDirector_MotionSaver "
SwigDirector_MotionSaver::SwigDirector_MotionSaver(PyObject *self, Piavca::MotionSaver const &to)
         
        
         
        ";
%feature("docstring") SwigDirector_MotionSaver::findSub "
virtual Piavca::Motion* SwigDirector_MotionSaver::findSub(Piavca::tstring nm)
         
finds the first submotion with a given name         
         
        ";
%feature("docstring") SwigDirector_MotionSaver::load "
virtual void SwigDirector_MotionSaver::load(Piavca::Avatar *av)
         
called when the motion is loaded into an avatar         
         
        ";
%feature("docstring") SwigDirector_MotionSaver::setStartTime "
virtual void SwigDirector_MotionSaver::setStartTime(float time)
         
sets the start time of the motion. Called when its loaded into an avatar.         
         
        ";
%feature("docstring") SwigDirector_MotionSaver::getFloatValueAtTimeInternal "
virtual float SwigDirector_MotionSaver::getFloatValueAtTimeInternal(int trackId, float time)
         
calculates the values of the filter motion on and saves them to a TrackMotion         
         
        ";
%feature("docstring") SwigDirector_MotionSaver::getVecValueAtTimeInternal "
virtual Piavca::Vec SwigDirector_MotionSaver::getVecValueAtTimeInternal(int trackId, float time)
         
calculates the values of the filter motion on and saves them to a TrackMotion         
         
        ";
%feature("docstring") SwigDirector_MotionSaver::getQuatValueAtTimeInternal "
virtual Piavca::Quat SwigDirector_MotionSaver::getQuatValueAtTimeInternal(int trackId, float time)
         
calculates the values of the filter motion on and saves them to a TrackMotion         
         
        ";
%feature("docstring") SwigDirector_MotionSaver::isRandomAccess "
virtual bool SwigDirector_MotionSaver::isRandomAccess()
         
whether you can access a motions value at frames other than the current one         
         
        ";
%feature("docstring") SwigDirector_MotionSaver::~SwigDirector_MotionSaver "
virtual SwigDirector_MotionSaver::~SwigDirector_MotionSaver()
         
        
         
        ";
%feature("docstring") SwigDirector_MotionSaver::reset "
virtual void SwigDirector_MotionSaver::reset()
         
does any resetting needed         
         
        ";
%feature("docstring") SwigDirector_MotionSaver::clone "
virtual Piavca::Motion* SwigDirector_MotionSaver::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") SwigDirector_MotionSaver::getMotionLength "
virtual float SwigDirector_MotionSaver::getMotionLength() const 
         
gets the length of the motion in seconds         
         
        ";
%feature("docstring") SwigDirector_MotionSaver::isFacial "
virtual bool SwigDirector_MotionSaver::isFacial()
         
whether it is a face or body motion         
         
        ";
%feature("docstring") SwigDirector_MotionSaver::unload "
virtual void SwigDirector_MotionSaver::unload()
         
called when the motion is unloaded from an avatar         
         
        ";
%feature("docstring") SwigDirector_MotionSaver::loaded "
virtual bool SwigDirector_MotionSaver::loaded()
         
checks if the motion has been loaded into an avatar         
         
        ";
%feature("docstring") SwigDirector_MotionSaver::printInfo "
virtual void SwigDirector_MotionSaver::printInfo()
         
prints out info about the motion heirarchy         
         
        ";
%feature("docstring") SwigDirector_MotionSaver::findSubByType "
virtual Piavca::Motion* SwigDirector_MotionSaver::findSubByType(type_info const &ty)
         
finds the first submotion with a given type         
         
        ";
%feature("docstring") SwigDirector_MotionSaver::isNull "
virtual bool SwigDirector_MotionSaver::isNull(int trackId) const 
         
given an iterator tests whether it actually points to anything or if its null         
         
        ";
%feature("docstring") SwigDirector_MotionSaver::getTrackType "
virtual Piavca::trackType SwigDirector_MotionSaver::getTrackType(int trackId) const 
         
get the type of the track corresponding to an iterator         
         
        ";
%feature("docstring") SwigDirector_MotionSaver::swig_get_inner "
bool SwigDirector_MotionSaver::swig_get_inner(const char *name) const 
         
        
         
        ";
%feature("docstring") SwigDirector_MotionSaver::swig_set_inner "
void SwigDirector_MotionSaver::swig_set_inner(const char *name, bool val) const 
         
        
         
        ";
%feature("docstring") SwigDirector_RandomAddLoop " 

    
       
     see also: Piavca_wrap.h";

%feature("docstring") SwigDirector_RandomAddLoop::SwigDirector_RandomAddLoop "
SwigDirector_RandomAddLoop::SwigDirector_RandomAddLoop(PyObject *self)
         
        
         
        ";
%feature("docstring") SwigDirector_RandomAddLoop::SwigDirector_RandomAddLoop "
SwigDirector_RandomAddLoop::SwigDirector_RandomAddLoop(PyObject *self, Piavca::MotionVec const &mv, float endTime=-1.0, float interval=0.01)
         
        
         
        ";
%feature("docstring") SwigDirector_RandomAddLoop::SwigDirector_RandomAddLoop "
SwigDirector_RandomAddLoop::SwigDirector_RandomAddLoop(PyObject *self, Piavca::RandomAddLoop const &rbl)
         
        
         
        ";
%feature("docstring") SwigDirector_RandomAddLoop::findSub "
virtual Piavca::Motion* SwigDirector_RandomAddLoop::findSub(Piavca::tstring nm)
         
finds the first submotion with a given name         
         
        ";
%feature("docstring") SwigDirector_RandomAddLoop::load "
virtual void SwigDirector_RandomAddLoop::load(Piavca::Avatar *av)
         
called when the motion is loaded into an avatar         
         
        ";
%feature("docstring") SwigDirector_RandomAddLoop::loaded "
virtual bool SwigDirector_RandomAddLoop::loaded(Piavca::Avatar *av)
         
        
         
        ";
%feature("docstring") SwigDirector_RandomAddLoop::shift "
virtual void SwigDirector_RandomAddLoop::shift()
         
        
         
        ";
%feature("docstring") SwigDirector_RandomAddLoop::setStartTime "
virtual void SwigDirector_RandomAddLoop::setStartTime(float time)
         
        
         
std::cout << \"SequentialBlend::setStartTime \" << name << \" \"         ";
%feature("docstring") SwigDirector_RandomAddLoop::getFloatValueAtTimeInternal "
virtual float SwigDirector_RandomAddLoop::getFloatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
if the end has been reached it reblends to start again at the beginning         ";
%feature("docstring") SwigDirector_RandomAddLoop::getVecValueAtTimeInternal "
virtual Piavca::Vec SwigDirector_RandomAddLoop::getVecValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
if the end has been reached it reblends to start again at the beginning         ";
%feature("docstring") SwigDirector_RandomAddLoop::getQuatValueAtTimeInternal "
virtual Piavca::Quat SwigDirector_RandomAddLoop::getQuatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
if the end has been reached it reblends to start again at the beginning         ";
%feature("docstring") SwigDirector_RandomAddLoop::setTimingParams "
virtual void SwigDirector_RandomAddLoop::setTimingParams(float minTimeScale, float maxTimeScale)
         
sets the minimum and maximum times that can be generated         
         
        ";
%feature("docstring") SwigDirector_RandomAddLoop::reblend "
virtual void SwigDirector_RandomAddLoop::reblend(float time)
         
called each time around the loop         
         
It can be called by the client to interrupt the current motion.         ";
%feature("docstring") SwigDirector_RandomAddLoop::isRandomAccess "
virtual bool SwigDirector_RandomAddLoop::isRandomAccess()
         
whether you can access a motions value at frames other than the current one         
         
        ";
%feature("docstring") SwigDirector_RandomAddLoop::~SwigDirector_RandomAddLoop "
virtual SwigDirector_RandomAddLoop::~SwigDirector_RandomAddLoop()
         
        
         
        ";
%feature("docstring") SwigDirector_RandomAddLoop::reset "
virtual void SwigDirector_RandomAddLoop::reset()
         
does any resetting needed         
         
        ";
%feature("docstring") SwigDirector_RandomAddLoop::clone "
virtual Piavca::Motion* SwigDirector_RandomAddLoop::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") SwigDirector_RandomAddLoop::isFacial "
virtual bool SwigDirector_RandomAddLoop::isFacial()
         
whether it is a face or body motion         
         
        ";
%feature("docstring") SwigDirector_RandomAddLoop::getMotionLength "
virtual float SwigDirector_RandomAddLoop::getMotionLength() const 
         
gets the motion length (transition start + blend interval + length of second motion)         
         
        ";
%feature("docstring") SwigDirector_RandomAddLoop::loaded "
virtual bool SwigDirector_RandomAddLoop::loaded()
         
checks if the motion has been loaded into an avatar         
         
        ";
%feature("docstring") SwigDirector_RandomAddLoop::unload "
virtual void SwigDirector_RandomAddLoop::unload()
         
called when the motion is unloaded from an avatar         
         
        ";
%feature("docstring") SwigDirector_RandomAddLoop::setMaintainY "
virtual void SwigDirector_RandomAddLoop::setMaintainY(bool b)
         
        
         
        ";
%feature("docstring") SwigDirector_RandomAddLoop::setAccumulateRoot "
virtual void SwigDirector_RandomAddLoop::setAccumulateRoot(bool b)
         
        
         
        ";
%feature("docstring") SwigDirector_RandomAddLoop::printInfo "
virtual void SwigDirector_RandomAddLoop::printInfo()
         
prints out info about the motion heirarchy         
         
        ";
%feature("docstring") SwigDirector_RandomAddLoop::findSubByType "
virtual Piavca::Motion* SwigDirector_RandomAddLoop::findSubByType(type_info const &ty)
         
finds the first submotion with a given type         
         
        ";
%feature("docstring") SwigDirector_RandomAddLoop::setMotion "
virtual void SwigDirector_RandomAddLoop::setMotion(Piavca::Motion *m)
         
sets the motion to be looped         
         
std::cout << \"setting motion for loop\n\";         ";
%feature("docstring") SwigDirector_RandomAddLoop::addMotion "
virtual void SwigDirector_RandomAddLoop::addMotion(Piavca::Motion *mot)
         
        
         
        ";
%feature("docstring") SwigDirector_RandomAddLoop::isNull "
virtual bool SwigDirector_RandomAddLoop::isNull(int trackId) const 
         
given a track ID tests whether it actually points to anything or if its null         
         
is null if the track is null in both motions.         ";
%feature("docstring") SwigDirector_RandomAddLoop::getTrackType "
virtual Piavca::trackType SwigDirector_RandomAddLoop::getTrackType(int trackId) const 
         
get the type of the track corresponding to an iterator         
         
        ";
%feature("docstring") SwigDirector_RandomAddLoop::swig_get_inner "
bool SwigDirector_RandomAddLoop::swig_get_inner(const char *name) const 
         
        
         
        ";
%feature("docstring") SwigDirector_RandomAddLoop::swig_set_inner "
void SwigDirector_RandomAddLoop::swig_set_inner(const char *name, bool val) const 
         
        
         
        ";
%feature("docstring") SwigDirector_RandomBlendLoop " 

    
       
     see also: Piavca_wrap.h";

%feature("docstring") SwigDirector_RandomBlendLoop::SwigDirector_RandomBlendLoop "
SwigDirector_RandomBlendLoop::SwigDirector_RandomBlendLoop(PyObject *self, Piavca::MotionVec const &mv, float endTime=-1.0, float interval=0.01)
         
        
         
        ";
%feature("docstring") SwigDirector_RandomBlendLoop::SwigDirector_RandomBlendLoop "
SwigDirector_RandomBlendLoop::SwigDirector_RandomBlendLoop(PyObject *self, float endTime=-1.0, float interval=0.01)
         
        
         
        ";
%feature("docstring") SwigDirector_RandomBlendLoop::SwigDirector_RandomBlendLoop "
SwigDirector_RandomBlendLoop::SwigDirector_RandomBlendLoop(PyObject *self, Piavca::RandomBlendLoop const &rbl)
         
        
         
        ";
%feature("docstring") SwigDirector_RandomBlendLoop::findSub "
virtual Piavca::Motion* SwigDirector_RandomBlendLoop::findSub(Piavca::tstring nm)
         
finds the first submotion with a given name         
         
        ";
%feature("docstring") SwigDirector_RandomBlendLoop::load "
virtual void SwigDirector_RandomBlendLoop::load(Piavca::Avatar *av)
         
called when the motion is loaded into an avatar         
         
        ";
%feature("docstring") SwigDirector_RandomBlendLoop::loaded "
virtual bool SwigDirector_RandomBlendLoop::loaded(Piavca::Avatar *av)
         
        
         
        ";
%feature("docstring") SwigDirector_RandomBlendLoop::shift "
virtual void SwigDirector_RandomBlendLoop::shift()
         
        
         
        ";
%feature("docstring") SwigDirector_RandomBlendLoop::setStartTime "
virtual void SwigDirector_RandomBlendLoop::setStartTime(float time)
         
        
         
std::cout << \"SequentialBlend::setStartTime \" << name << \" \"         ";
%feature("docstring") SwigDirector_RandomBlendLoop::getFloatValueAtTimeInternal "
virtual float SwigDirector_RandomBlendLoop::getFloatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
if the end has been reached it reblends to start again at the beginning         ";
%feature("docstring") SwigDirector_RandomBlendLoop::getVecValueAtTimeInternal "
virtual Piavca::Vec SwigDirector_RandomBlendLoop::getVecValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
if the end has been reached it reblends to start again at the beginning         ";
%feature("docstring") SwigDirector_RandomBlendLoop::getQuatValueAtTimeInternal "
virtual Piavca::Quat SwigDirector_RandomBlendLoop::getQuatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
if the end has been reached it reblends to start again at the beginning         ";
%feature("docstring") SwigDirector_RandomBlendLoop::setTimingParams "
virtual void SwigDirector_RandomBlendLoop::setTimingParams(float minTimeScale, float maxTimeScale)
         
sets the minimum and maximum times that can be generated         
         
        ";
%feature("docstring") SwigDirector_RandomBlendLoop::addMotion "
virtual void SwigDirector_RandomBlendLoop::addMotion(Piavca::Motion *mot, float weight)
         
        
         
        ";
%feature("docstring") SwigDirector_RandomBlendLoop::reblend "
virtual void SwigDirector_RandomBlendLoop::reblend(float time)
         
called each time around the loop         
         
It can be called by the client to interrupt the current motion.         ";
%feature("docstring") SwigDirector_RandomBlendLoop::isRandomAccess "
virtual bool SwigDirector_RandomBlendLoop::isRandomAccess()
         
whether you can access a motions value at frames other than the current one         
         
        ";
%feature("docstring") SwigDirector_RandomBlendLoop::~SwigDirector_RandomBlendLoop "
virtual SwigDirector_RandomBlendLoop::~SwigDirector_RandomBlendLoop()
         
        
         
        ";
%feature("docstring") SwigDirector_RandomBlendLoop::reset "
virtual void SwigDirector_RandomBlendLoop::reset()
         
does any resetting needed         
         
        ";
%feature("docstring") SwigDirector_RandomBlendLoop::clone "
virtual Piavca::Motion* SwigDirector_RandomBlendLoop::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") SwigDirector_RandomBlendLoop::isFacial "
virtual bool SwigDirector_RandomBlendLoop::isFacial()
         
whether it is a face or body motion         
         
        ";
%feature("docstring") SwigDirector_RandomBlendLoop::getMotionLength "
virtual float SwigDirector_RandomBlendLoop::getMotionLength() const 
         
gets the motion length (transition start + blend interval + length of second motion)         
         
        ";
%feature("docstring") SwigDirector_RandomBlendLoop::loaded "
virtual bool SwigDirector_RandomBlendLoop::loaded()
         
checks if the motion has been loaded into an avatar         
         
        ";
%feature("docstring") SwigDirector_RandomBlendLoop::unload "
virtual void SwigDirector_RandomBlendLoop::unload()
         
called when the motion is unloaded from an avatar         
         
        ";
%feature("docstring") SwigDirector_RandomBlendLoop::setMaintainY "
virtual void SwigDirector_RandomBlendLoop::setMaintainY(bool b)
         
        
         
        ";
%feature("docstring") SwigDirector_RandomBlendLoop::setAccumulateRoot "
virtual void SwigDirector_RandomBlendLoop::setAccumulateRoot(bool b)
         
        
         
        ";
%feature("docstring") SwigDirector_RandomBlendLoop::printInfo "
virtual void SwigDirector_RandomBlendLoop::printInfo()
         
prints out info about the motion heirarchy         
         
        ";
%feature("docstring") SwigDirector_RandomBlendLoop::findSubByType "
virtual Piavca::Motion* SwigDirector_RandomBlendLoop::findSubByType(type_info const &ty)
         
finds the first submotion with a given type         
         
        ";
%feature("docstring") SwigDirector_RandomBlendLoop::setMotion "
virtual void SwigDirector_RandomBlendLoop::setMotion(Piavca::Motion *m)
         
sets the motion to be looped         
         
std::cout << \"setting motion for loop\n\";         ";
%feature("docstring") SwigDirector_RandomBlendLoop::addMotion "
virtual void SwigDirector_RandomBlendLoop::addMotion(Piavca::Motion *mot)
         
        
         
        ";
%feature("docstring") SwigDirector_RandomBlendLoop::isNull "
virtual bool SwigDirector_RandomBlendLoop::isNull(int trackId) const 
         
given a track ID tests whether it actually points to anything or if its null         
         
is null if the track is null in both motions.         ";
%feature("docstring") SwigDirector_RandomBlendLoop::getTrackType "
virtual Piavca::trackType SwigDirector_RandomBlendLoop::getTrackType(int trackId) const 
         
get the type of the track corresponding to an iterator         
         
        ";
%feature("docstring") SwigDirector_RandomBlendLoop::swig_get_inner "
bool SwigDirector_RandomBlendLoop::swig_get_inner(const char *name) const 
         
        
         
        ";
%feature("docstring") SwigDirector_RandomBlendLoop::swig_set_inner "
void SwigDirector_RandomBlendLoop::swig_set_inner(const char *name, bool val) const 
         
        
         
        ";
%feature("docstring") SwigDirector_RandomGazeMotion " 

    
       
     see also: Piavca_wrap.h";

%feature("docstring") SwigDirector_RandomGazeMotion::SwigDirector_RandomGazeMotion "
SwigDirector_RandomGazeMotion::SwigDirector_RandomGazeMotion(PyObject *self, float endTime=-1.0, float interval=0.01)
         
        
         
        ";
%feature("docstring") SwigDirector_RandomGazeMotion::SwigDirector_RandomGazeMotion "
SwigDirector_RandomGazeMotion::SwigDirector_RandomGazeMotion(PyObject *self, Piavca::RandomGazeMotion const &rg)
         
        
         
        ";
%feature("docstring") SwigDirector_RandomGazeMotion::findSub "
virtual Piavca::Motion* SwigDirector_RandomGazeMotion::findSub(Piavca::tstring nm)
         
finds the first submotion with a given name         
         
        ";
%feature("docstring") SwigDirector_RandomGazeMotion::load "
virtual void SwigDirector_RandomGazeMotion::load(Piavca::Avatar *av)
         
called when the motion is loaded into an avatar         
         
        ";
%feature("docstring") SwigDirector_RandomGazeMotion::setStartTime "
virtual void SwigDirector_RandomGazeMotion::setStartTime(float time)
         
        
         
std::cout << \"SequentialBlend::setStartTime \" << name << \" \"         ";
%feature("docstring") SwigDirector_RandomGazeMotion::getFloatValueAtTimeInternal "
virtual float SwigDirector_RandomGazeMotion::getFloatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
if the end has been reached it reblends to start again at the beginning         ";
%feature("docstring") SwigDirector_RandomGazeMotion::getVecValueAtTimeInternal "
virtual Piavca::Vec SwigDirector_RandomGazeMotion::getVecValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
if the end has been reached it reblends to start again at the beginning         ";
%feature("docstring") SwigDirector_RandomGazeMotion::getQuatValueAtTimeInternal "
virtual Piavca::Quat SwigDirector_RandomGazeMotion::getQuatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
if the end has been reached it reblends to start again at the beginning         ";
%feature("docstring") SwigDirector_RandomGazeMotion::reblend "
virtual void SwigDirector_RandomGazeMotion::reblend(float time)
         
saves the state of the motion at time and start blending the motion back into that from the start         
         
        ";
%feature("docstring") SwigDirector_RandomGazeMotion::isRandomAccess "
virtual bool SwigDirector_RandomGazeMotion::isRandomAccess()
         
whether you can access a motions value at frames other than the current one         
         
        ";
%feature("docstring") SwigDirector_RandomGazeMotion::~SwigDirector_RandomGazeMotion "
virtual SwigDirector_RandomGazeMotion::~SwigDirector_RandomGazeMotion()
         
        
         
        ";
%feature("docstring") SwigDirector_RandomGazeMotion::reset "
virtual void SwigDirector_RandomGazeMotion::reset()
         
does any resetting needed         
         
        ";
%feature("docstring") SwigDirector_RandomGazeMotion::clone "
virtual Piavca::Motion* SwigDirector_RandomGazeMotion::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") SwigDirector_RandomGazeMotion::isFacial "
virtual bool SwigDirector_RandomGazeMotion::isFacial()
         
whether it is a face or body motion         
         
        ";
%feature("docstring") SwigDirector_RandomGazeMotion::getMotionLength "
virtual float SwigDirector_RandomGazeMotion::getMotionLength() const 
         
gets the motion length (transition start + blend interval + length of second motion)         
         
        ";
%feature("docstring") SwigDirector_RandomGazeMotion::unload "
virtual void SwigDirector_RandomGazeMotion::unload()
         
called when the motion is unloaded from an avatar         
         
        ";
%feature("docstring") SwigDirector_RandomGazeMotion::loaded "
virtual bool SwigDirector_RandomGazeMotion::loaded()
         
checks if the motion has been loaded into an avatar         
         
        ";
%feature("docstring") SwigDirector_RandomGazeMotion::printInfo "
virtual void SwigDirector_RandomGazeMotion::printInfo()
         
prints out info about the motion heirarchy         
         
        ";
%feature("docstring") SwigDirector_RandomGazeMotion::setMaintainY "
virtual void SwigDirector_RandomGazeMotion::setMaintainY(bool b)
         
        
         
        ";
%feature("docstring") SwigDirector_RandomGazeMotion::setAccumulateRoot "
virtual void SwigDirector_RandomGazeMotion::setAccumulateRoot(bool b)
         
        
         
        ";
%feature("docstring") SwigDirector_RandomGazeMotion::lookAt "
virtual bool SwigDirector_RandomGazeMotion::lookAt(Piavca::tstring name, bool force=false)
         
        
         
        ";
%feature("docstring") SwigDirector_RandomGazeMotion::findSubByType "
virtual Piavca::Motion* SwigDirector_RandomGazeMotion::findSubByType(type_info const &ty)
         
finds the first submotion with a given type         
         
        ";
%feature("docstring") SwigDirector_RandomGazeMotion::setMotion "
virtual void SwigDirector_RandomGazeMotion::setMotion(Piavca::Motion *mot)
         
sets the motion to be blended in         
         
        ";
%feature("docstring") SwigDirector_RandomGazeMotion::isNull "
virtual bool SwigDirector_RandomGazeMotion::isNull(int trackId) const 
         
given a track ID tests whether it actually points to anything or if its null         
         
is null if the track is null in both motions.         ";
%feature("docstring") SwigDirector_RandomGazeMotion::getTrackType "
virtual Piavca::trackType SwigDirector_RandomGazeMotion::getTrackType(int trackId) const 
         
get the type of the track corresponding to an iterator         
         
        ";
%feature("docstring") SwigDirector_RandomGazeMotion::swig_get_inner "
bool SwigDirector_RandomGazeMotion::swig_get_inner(const char *name) const 
         
        
         
        ";
%feature("docstring") SwigDirector_RandomGazeMotion::swig_set_inner "
void SwigDirector_RandomGazeMotion::swig_set_inner(const char *name, bool val) const 
         
        
         
        ";
%feature("docstring") SwigDirector_RandomLoopMotion " 

    
       
     see also: Piavca_wrap.h";

%feature("docstring") SwigDirector_RandomLoopMotion::SwigDirector_RandomLoopMotion "
SwigDirector_RandomLoopMotion::SwigDirector_RandomLoopMotion(PyObject *self)
         
        
         
        ";
%feature("docstring") SwigDirector_RandomLoopMotion::SwigDirector_RandomLoopMotion "
SwigDirector_RandomLoopMotion::SwigDirector_RandomLoopMotion(PyObject *self, Piavca::MotionVec const &mv, vector< float > ws, float endTime=-1.0, float interval=0.01)
         
        
         
        ";
%feature("docstring") SwigDirector_RandomLoopMotion::SwigDirector_RandomLoopMotion "
SwigDirector_RandomLoopMotion::SwigDirector_RandomLoopMotion(PyObject *self, Piavca::RandomLoopMotion const &rl)
         
        
         
        ";
%feature("docstring") SwigDirector_RandomLoopMotion::findSub "
virtual Piavca::Motion* SwigDirector_RandomLoopMotion::findSub(Piavca::tstring nm)
         
finds the first submotion with a given name         
         
        ";
%feature("docstring") SwigDirector_RandomLoopMotion::load "
virtual void SwigDirector_RandomLoopMotion::load(Piavca::Avatar *av)
         
called when the motion is loaded into an avatar         
         
        ";
%feature("docstring") SwigDirector_RandomLoopMotion::loaded "
virtual bool SwigDirector_RandomLoopMotion::loaded(Piavca::Avatar *av)
         
        
         
        ";
%feature("docstring") SwigDirector_RandomLoopMotion::setStartTime "
virtual void SwigDirector_RandomLoopMotion::setStartTime(float time)
         
        
         
std::cout << \"SequentialBlend::setStartTime \" << name << \" \"         ";
%feature("docstring") SwigDirector_RandomLoopMotion::getFloatValueAtTimeInternal "
virtual float SwigDirector_RandomLoopMotion::getFloatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
if the end has been reached it reblends to start again at the beginning         ";
%feature("docstring") SwigDirector_RandomLoopMotion::getVecValueAtTimeInternal "
virtual Piavca::Vec SwigDirector_RandomLoopMotion::getVecValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
if the end has been reached it reblends to start again at the beginning         ";
%feature("docstring") SwigDirector_RandomLoopMotion::getQuatValueAtTimeInternal "
virtual Piavca::Quat SwigDirector_RandomLoopMotion::getQuatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
if the end has been reached it reblends to start again at the beginning         ";
%feature("docstring") SwigDirector_RandomLoopMotion::setTimingParams "
virtual void SwigDirector_RandomLoopMotion::setTimingParams(float minTimeScale, float maxTimeScale)
         
sets the minimum and maximum times that can be generated         
         
        ";
%feature("docstring") SwigDirector_RandomLoopMotion::addMotion "
virtual void SwigDirector_RandomLoopMotion::addMotion(Piavca::Motion *mot, float weight=1.0f)
         
        
         
        ";
%feature("docstring") SwigDirector_RandomLoopMotion::reblend "
virtual void SwigDirector_RandomLoopMotion::reblend(float time)
         
called each time around the loop         
         
It can be called by the client to interrupt the current motion.         ";
%feature("docstring") SwigDirector_RandomLoopMotion::isRandomAccess "
virtual bool SwigDirector_RandomLoopMotion::isRandomAccess()
         
whether you can access a motions value at frames other than the current one         
         
        ";
%feature("docstring") SwigDirector_RandomLoopMotion::~SwigDirector_RandomLoopMotion "
virtual SwigDirector_RandomLoopMotion::~SwigDirector_RandomLoopMotion()
         
        
         
        ";
%feature("docstring") SwigDirector_RandomLoopMotion::reset "
virtual void SwigDirector_RandomLoopMotion::reset()
         
does any resetting needed         
         
        ";
%feature("docstring") SwigDirector_RandomLoopMotion::clone "
virtual Piavca::Motion* SwigDirector_RandomLoopMotion::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") SwigDirector_RandomLoopMotion::isFacial "
virtual bool SwigDirector_RandomLoopMotion::isFacial()
         
whether it is a face or body motion         
         
        ";
%feature("docstring") SwigDirector_RandomLoopMotion::getMotionLength "
virtual float SwigDirector_RandomLoopMotion::getMotionLength() const 
         
gets the motion length (transition start + blend interval + length of second motion)         
         
        ";
%feature("docstring") SwigDirector_RandomLoopMotion::loaded "
virtual bool SwigDirector_RandomLoopMotion::loaded()
         
checks if the motion has been loaded into an avatar         
         
        ";
%feature("docstring") SwigDirector_RandomLoopMotion::unload "
virtual void SwigDirector_RandomLoopMotion::unload()
         
called when the motion is unloaded from an avatar         
         
        ";
%feature("docstring") SwigDirector_RandomLoopMotion::setMaintainY "
virtual void SwigDirector_RandomLoopMotion::setMaintainY(bool b)
         
        
         
        ";
%feature("docstring") SwigDirector_RandomLoopMotion::setAccumulateRoot "
virtual void SwigDirector_RandomLoopMotion::setAccumulateRoot(bool b)
         
        
         
        ";
%feature("docstring") SwigDirector_RandomLoopMotion::printInfo "
virtual void SwigDirector_RandomLoopMotion::printInfo()
         
prints out info about the motion heirarchy         
         
        ";
%feature("docstring") SwigDirector_RandomLoopMotion::findSubByType "
virtual Piavca::Motion* SwigDirector_RandomLoopMotion::findSubByType(type_info const &ty)
         
finds the first submotion with a given type         
         
        ";
%feature("docstring") SwigDirector_RandomLoopMotion::setMotion "
virtual void SwigDirector_RandomLoopMotion::setMotion(Piavca::Motion *m)
         
sets the motion to be looped         
         
std::cout << \"setting motion for loop\n\";         ";
%feature("docstring") SwigDirector_RandomLoopMotion::isNull "
virtual bool SwigDirector_RandomLoopMotion::isNull(int trackId) const 
         
given a track ID tests whether it actually points to anything or if its null         
         
is null if the track is null in both motions.         ";
%feature("docstring") SwigDirector_RandomLoopMotion::getTrackType "
virtual Piavca::trackType SwigDirector_RandomLoopMotion::getTrackType(int trackId) const 
         
get the type of the track corresponding to an iterator         
         
        ";
%feature("docstring") SwigDirector_RandomLoopMotion::swig_get_inner "
bool SwigDirector_RandomLoopMotion::swig_get_inner(const char *name) const 
         
        
         
        ";
%feature("docstring") SwigDirector_RandomLoopMotion::swig_set_inner "
void SwigDirector_RandomLoopMotion::swig_set_inner(const char *name, bool val) const 
         
        
         
        ";
%feature("docstring") SwigDirector_RandomTimingsLoop " 

    
       
     see also: Piavca_wrap.h";

%feature("docstring") SwigDirector_RandomTimingsLoop::SwigDirector_RandomTimingsLoop "
SwigDirector_RandomTimingsLoop::SwigDirector_RandomTimingsLoop(PyObject *self, Piavca::Motion *mot=NULL, float endTime=-1.0, float interval=0.01, float min=1.0, float max=1.0)
         
        
         
        ";
%feature("docstring") SwigDirector_RandomTimingsLoop::SwigDirector_RandomTimingsLoop "
SwigDirector_RandomTimingsLoop::SwigDirector_RandomTimingsLoop(PyObject *self, Piavca::RandomTimingsLoop const &rtl)
         
        
         
        ";
%feature("docstring") SwigDirector_RandomTimingsLoop::findSub "
virtual Piavca::Motion* SwigDirector_RandomTimingsLoop::findSub(Piavca::tstring nm)
         
finds the first submotion with a given name         
         
        ";
%feature("docstring") SwigDirector_RandomTimingsLoop::load "
virtual void SwigDirector_RandomTimingsLoop::load(Piavca::Avatar *av)
         
called when the motion is loaded into an avatar         
         
        ";
%feature("docstring") SwigDirector_RandomTimingsLoop::setStartTime "
virtual void SwigDirector_RandomTimingsLoop::setStartTime(float time)
         
        
         
std::cout << \"SequentialBlend::setStartTime \" << name << \" \"         ";
%feature("docstring") SwigDirector_RandomTimingsLoop::getFloatValueAtTimeInternal "
virtual float SwigDirector_RandomTimingsLoop::getFloatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
if the end has been reached it reblends to start again at the beginning         ";
%feature("docstring") SwigDirector_RandomTimingsLoop::getVecValueAtTimeInternal "
virtual Piavca::Vec SwigDirector_RandomTimingsLoop::getVecValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
if the end has been reached it reblends to start again at the beginning         ";
%feature("docstring") SwigDirector_RandomTimingsLoop::getQuatValueAtTimeInternal "
virtual Piavca::Quat SwigDirector_RandomTimingsLoop::getQuatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
if the end has been reached it reblends to start again at the beginning         ";
%feature("docstring") SwigDirector_RandomTimingsLoop::setTimingParams "
virtual void SwigDirector_RandomTimingsLoop::setTimingParams(float minTimeScale, float maxTimeScale)
         
sets the minimum and maximum times that can be generated         
         
        ";
%feature("docstring") SwigDirector_RandomTimingsLoop::reblend "
virtual void SwigDirector_RandomTimingsLoop::reblend(float time)
         
This is called each time around the loop.         
         
        ";
%feature("docstring") SwigDirector_RandomTimingsLoop::isRandomAccess "
virtual bool SwigDirector_RandomTimingsLoop::isRandomAccess()
         
whether you can access a motions value at frames other than the current one         
         
        ";
%feature("docstring") SwigDirector_RandomTimingsLoop::~SwigDirector_RandomTimingsLoop "
virtual SwigDirector_RandomTimingsLoop::~SwigDirector_RandomTimingsLoop()
         
        
         
        ";
%feature("docstring") SwigDirector_RandomTimingsLoop::reset "
virtual void SwigDirector_RandomTimingsLoop::reset()
         
does any resetting needed         
         
        ";
%feature("docstring") SwigDirector_RandomTimingsLoop::clone "
virtual Piavca::Motion* SwigDirector_RandomTimingsLoop::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") SwigDirector_RandomTimingsLoop::isFacial "
virtual bool SwigDirector_RandomTimingsLoop::isFacial()
         
whether it is a face or body motion         
         
        ";
%feature("docstring") SwigDirector_RandomTimingsLoop::getMotionLength "
virtual float SwigDirector_RandomTimingsLoop::getMotionLength() const 
         
gets the motion length (transition start + blend interval + length of second motion)         
         
        ";
%feature("docstring") SwigDirector_RandomTimingsLoop::unload "
virtual void SwigDirector_RandomTimingsLoop::unload()
         
called when the motion is unloaded from an avatar         
         
        ";
%feature("docstring") SwigDirector_RandomTimingsLoop::loaded "
virtual bool SwigDirector_RandomTimingsLoop::loaded()
         
checks if the motion has been loaded into an avatar         
         
        ";
%feature("docstring") SwigDirector_RandomTimingsLoop::printInfo "
virtual void SwigDirector_RandomTimingsLoop::printInfo()
         
prints out info about the motion heirarchy         
         
        ";
%feature("docstring") SwigDirector_RandomTimingsLoop::setMaintainY "
virtual void SwigDirector_RandomTimingsLoop::setMaintainY(bool b)
         
        
         
        ";
%feature("docstring") SwigDirector_RandomTimingsLoop::setAccumulateRoot "
virtual void SwigDirector_RandomTimingsLoop::setAccumulateRoot(bool b)
         
        
         
        ";
%feature("docstring") SwigDirector_RandomTimingsLoop::findSubByType "
virtual Piavca::Motion* SwigDirector_RandomTimingsLoop::findSubByType(type_info const &ty)
         
finds the first submotion with a given type         
         
        ";
%feature("docstring") SwigDirector_RandomTimingsLoop::setMotion "
virtual void SwigDirector_RandomTimingsLoop::setMotion(Piavca::Motion *m)
         
sets the motion to be looped         
         
std::cout << \"setting motion for loop\n\";         ";
%feature("docstring") SwigDirector_RandomTimingsLoop::isNull "
virtual bool SwigDirector_RandomTimingsLoop::isNull(int trackId) const 
         
given a track ID tests whether it actually points to anything or if its null         
         
is null if the track is null in both motions.         ";
%feature("docstring") SwigDirector_RandomTimingsLoop::getTrackType "
virtual Piavca::trackType SwigDirector_RandomTimingsLoop::getTrackType(int trackId) const 
         
get the type of the track corresponding to an iterator         
         
        ";
%feature("docstring") SwigDirector_RandomTimingsLoop::swig_get_inner "
bool SwigDirector_RandomTimingsLoop::swig_get_inner(const char *name) const 
         
        
         
        ";
%feature("docstring") SwigDirector_RandomTimingsLoop::swig_set_inner "
void SwigDirector_RandomTimingsLoop::swig_set_inner(const char *name, bool val) const 
         
        
         
        ";
%feature("docstring") SwigDirector_ScaleMotion " 

    
       
     see also: Piavca_wrap.h";

%feature("docstring") SwigDirector_ScaleMotion::SwigDirector_ScaleMotion "
SwigDirector_ScaleMotion::SwigDirector_ScaleMotion(PyObject *self, Piavca::Motion *m=NULL, float scale=1.0)
         
        
         
        ";
%feature("docstring") SwigDirector_ScaleMotion::SwigDirector_ScaleMotion "
SwigDirector_ScaleMotion::SwigDirector_ScaleMotion(PyObject *self, Piavca::ScaleMotion const &sm)
         
        
         
        ";
%feature("docstring") SwigDirector_ScaleMotion::findSub "
virtual Piavca::Motion* SwigDirector_ScaleMotion::findSub(Piavca::tstring nm)
         
finds the first submotion with a given name         
         
        ";
%feature("docstring") SwigDirector_ScaleMotion::load "
virtual void SwigDirector_ScaleMotion::load(Piavca::Avatar *av)
         
called when the motion is loaded into an avatar         
         
        ";
%feature("docstring") SwigDirector_ScaleMotion::setStartTime "
virtual void SwigDirector_ScaleMotion::setStartTime(float time)
         
sets the start time of the motion. Called when its loaded into an avatar.         
         
        ";
%feature("docstring") SwigDirector_ScaleMotion::getFloatValueAtTimeInternal "
virtual float SwigDirector_ScaleMotion::getFloatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") SwigDirector_ScaleMotion::getVecValueAtTimeInternal "
virtual Piavca::Vec SwigDirector_ScaleMotion::getVecValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") SwigDirector_ScaleMotion::getQuatValueAtTimeInternal "
virtual Piavca::Quat SwigDirector_ScaleMotion::getQuatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") SwigDirector_ScaleMotion::isRandomAccess "
virtual bool SwigDirector_ScaleMotion::isRandomAccess()
         
whether you can access a motions value at frames other than the current one         
         
        ";
%feature("docstring") SwigDirector_ScaleMotion::~SwigDirector_ScaleMotion "
virtual SwigDirector_ScaleMotion::~SwigDirector_ScaleMotion()
         
        
         
        ";
%feature("docstring") SwigDirector_ScaleMotion::reset "
virtual void SwigDirector_ScaleMotion::reset()
         
does any resetting needed         
         
        ";
%feature("docstring") SwigDirector_ScaleMotion::clone "
virtual Piavca::Motion* SwigDirector_ScaleMotion::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") SwigDirector_ScaleMotion::getMotionLength "
virtual float SwigDirector_ScaleMotion::getMotionLength() const 
         
gets the length of the motion in seconds         
         
        ";
%feature("docstring") SwigDirector_ScaleMotion::isFacial "
virtual bool SwigDirector_ScaleMotion::isFacial()
         
whether it is a face or body motion         
         
        ";
%feature("docstring") SwigDirector_ScaleMotion::unload "
virtual void SwigDirector_ScaleMotion::unload()
         
called when the motion is unloaded from an avatar         
         
        ";
%feature("docstring") SwigDirector_ScaleMotion::loaded "
virtual bool SwigDirector_ScaleMotion::loaded()
         
checks if the motion has been loaded into an avatar         
         
        ";
%feature("docstring") SwigDirector_ScaleMotion::printInfo "
virtual void SwigDirector_ScaleMotion::printInfo()
         
prints out info about the motion heirarchy         
         
        ";
%feature("docstring") SwigDirector_ScaleMotion::findSubByType "
virtual Piavca::Motion* SwigDirector_ScaleMotion::findSubByType(type_info const &ty)
         
finds the first submotion with a given type         
         
        ";
%feature("docstring") SwigDirector_ScaleMotion::isNull "
virtual bool SwigDirector_ScaleMotion::isNull(int trackId) const 
         
given an iterator tests whether it actually points to anything or if its null         
         
        ";
%feature("docstring") SwigDirector_ScaleMotion::getTrackType "
virtual Piavca::trackType SwigDirector_ScaleMotion::getTrackType(int trackId) const 
         
get the type of the track corresponding to an iterator         
         
        ";
%feature("docstring") SwigDirector_ScaleMotion::swig_get_inner "
bool SwigDirector_ScaleMotion::swig_get_inner(const char *name) const 
         
        
         
        ";
%feature("docstring") SwigDirector_ScaleMotion::swig_set_inner "
void SwigDirector_ScaleMotion::swig_set_inner(const char *name, bool val) const 
         
        
         
        ";
%feature("docstring") SwigDirector_ScaleMotionRoot " 

    
       
     see also: Piavca_wrap.h";

%feature("docstring") SwigDirector_ScaleMotionRoot::SwigDirector_ScaleMotionRoot "
SwigDirector_ScaleMotionRoot::SwigDirector_ScaleMotionRoot(PyObject *self, Piavca::Motion *m=NULL, float scale=1.0)
         
        
         
        ";
%feature("docstring") SwigDirector_ScaleMotionRoot::SwigDirector_ScaleMotionRoot "
SwigDirector_ScaleMotionRoot::SwigDirector_ScaleMotionRoot(PyObject *self, Piavca::ScaleMotionRoot const &sm)
         
        
         
        ";
%feature("docstring") SwigDirector_ScaleMotionRoot::findSub "
virtual Piavca::Motion* SwigDirector_ScaleMotionRoot::findSub(Piavca::tstring nm)
         
finds the first submotion with a given name         
         
        ";
%feature("docstring") SwigDirector_ScaleMotionRoot::load "
virtual void SwigDirector_ScaleMotionRoot::load(Piavca::Avatar *av)
         
called when the motion is loaded into an avatar         
         
        ";
%feature("docstring") SwigDirector_ScaleMotionRoot::setStartTime "
virtual void SwigDirector_ScaleMotionRoot::setStartTime(float time)
         
sets the start time of the motion. Called when its loaded into an avatar.         
         
        ";
%feature("docstring") SwigDirector_ScaleMotionRoot::getFloatValueAtTimeInternal "
virtual float SwigDirector_ScaleMotionRoot::getFloatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") SwigDirector_ScaleMotionRoot::getVecValueAtTimeInternal "
virtual Piavca::Vec SwigDirector_ScaleMotionRoot::getVecValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe (vec values are scaled)         
         
        ";
%feature("docstring") SwigDirector_ScaleMotionRoot::getQuatValueAtTimeInternal "
virtual Piavca::Quat SwigDirector_ScaleMotionRoot::getQuatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") SwigDirector_ScaleMotionRoot::isRandomAccess "
virtual bool SwigDirector_ScaleMotionRoot::isRandomAccess()
         
whether you can access a motions value at frames other than the current one         
         
        ";
%feature("docstring") SwigDirector_ScaleMotionRoot::reset "
virtual void SwigDirector_ScaleMotionRoot::reset()
         
does any resetting needed         
         
        ";
%feature("docstring") SwigDirector_ScaleMotionRoot::~SwigDirector_ScaleMotionRoot "
virtual SwigDirector_ScaleMotionRoot::~SwigDirector_ScaleMotionRoot()
         
        
         
        ";
%feature("docstring") SwigDirector_ScaleMotionRoot::clone "
virtual Piavca::Motion* SwigDirector_ScaleMotionRoot::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") SwigDirector_ScaleMotionRoot::getMotionLength "
virtual float SwigDirector_ScaleMotionRoot::getMotionLength() const 
         
gets the length of the motion in seconds         
         
        ";
%feature("docstring") SwigDirector_ScaleMotionRoot::isFacial "
virtual bool SwigDirector_ScaleMotionRoot::isFacial()
         
whether it is a face or body motion         
         
        ";
%feature("docstring") SwigDirector_ScaleMotionRoot::unload "
virtual void SwigDirector_ScaleMotionRoot::unload()
         
called when the motion is unloaded from an avatar         
         
        ";
%feature("docstring") SwigDirector_ScaleMotionRoot::loaded "
virtual bool SwigDirector_ScaleMotionRoot::loaded()
         
checks if the motion has been loaded into an avatar         
         
        ";
%feature("docstring") SwigDirector_ScaleMotionRoot::printInfo "
virtual void SwigDirector_ScaleMotionRoot::printInfo()
         
prints out info about the motion heirarchy         
         
        ";
%feature("docstring") SwigDirector_ScaleMotionRoot::findSubByType "
virtual Piavca::Motion* SwigDirector_ScaleMotionRoot::findSubByType(type_info const &ty)
         
finds the first submotion with a given type         
         
        ";
%feature("docstring") SwigDirector_ScaleMotionRoot::isNull "
virtual bool SwigDirector_ScaleMotionRoot::isNull(int trackId) const 
         
given an iterator tests whether it actually points to anything or if its null         
         
        ";
%feature("docstring") SwigDirector_ScaleMotionRoot::getTrackType "
virtual Piavca::trackType SwigDirector_ScaleMotionRoot::getTrackType(int trackId) const 
         
get the type of the track corresponding to an iterator         
         
        ";
%feature("docstring") SwigDirector_ScaleMotionRoot::swig_get_inner "
bool SwigDirector_ScaleMotionRoot::swig_get_inner(const char *name) const 
         
        
         
        ";
%feature("docstring") SwigDirector_ScaleMotionRoot::swig_set_inner "
void SwigDirector_ScaleMotionRoot::swig_set_inner(const char *name, bool val) const 
         
        
         
        ";
%feature("docstring") SwigDirector_ScaleMotionSpeed " 

    
       
     see also: Piavca_wrap.h";

%feature("docstring") SwigDirector_ScaleMotionSpeed::SwigDirector_ScaleMotionSpeed "
SwigDirector_ScaleMotionSpeed::SwigDirector_ScaleMotionSpeed(PyObject *self, Piavca::Motion *m=NULL, float scale=1.0)
         
        
         
        ";
%feature("docstring") SwigDirector_ScaleMotionSpeed::SwigDirector_ScaleMotionSpeed "
SwigDirector_ScaleMotionSpeed::SwigDirector_ScaleMotionSpeed(PyObject *self, Piavca::ScaleMotionSpeed const &sm)
         
        
         
        ";
%feature("docstring") SwigDirector_ScaleMotionSpeed::findSub "
virtual Piavca::Motion* SwigDirector_ScaleMotionSpeed::findSub(Piavca::tstring nm)
         
finds the first submotion with a given name         
         
        ";
%feature("docstring") SwigDirector_ScaleMotionSpeed::load "
virtual void SwigDirector_ScaleMotionSpeed::load(Piavca::Avatar *av)
         
called when the motion is loaded into an avatar         
         
        ";
%feature("docstring") SwigDirector_ScaleMotionSpeed::setStartTime "
virtual void SwigDirector_ScaleMotionSpeed::setStartTime(float time)
         
sets the start time of the motion. Called when its loaded into an avatar.         
         
        ";
%feature("docstring") SwigDirector_ScaleMotionSpeed::getFloatValueAtTimeInternal "
virtual float SwigDirector_ScaleMotionSpeed::getFloatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") SwigDirector_ScaleMotionSpeed::getVecValueAtTimeInternal "
virtual Piavca::Vec SwigDirector_ScaleMotionSpeed::getVecValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") SwigDirector_ScaleMotionSpeed::getQuatValueAtTimeInternal "
virtual Piavca::Quat SwigDirector_ScaleMotionSpeed::getQuatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") SwigDirector_ScaleMotionSpeed::isRandomAccess "
virtual bool SwigDirector_ScaleMotionSpeed::isRandomAccess()
         
whether you can access a motions value at frames other than the current one         
         
        ";
%feature("docstring") SwigDirector_ScaleMotionSpeed::~SwigDirector_ScaleMotionSpeed "
virtual SwigDirector_ScaleMotionSpeed::~SwigDirector_ScaleMotionSpeed()
         
        
         
        ";
%feature("docstring") SwigDirector_ScaleMotionSpeed::reset "
virtual void SwigDirector_ScaleMotionSpeed::reset()
         
does any resetting needed         
         
        ";
%feature("docstring") SwigDirector_ScaleMotionSpeed::clone "
virtual Piavca::Motion* SwigDirector_ScaleMotionSpeed::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") SwigDirector_ScaleMotionSpeed::isFacial "
virtual bool SwigDirector_ScaleMotionSpeed::isFacial()
         
whether it is a face or body motion         
         
        ";
%feature("docstring") SwigDirector_ScaleMotionSpeed::getMotionLength "
virtual float SwigDirector_ScaleMotionSpeed::getMotionLength() const 
         
gets the length of the motion in seconds         
         
        ";
%feature("docstring") SwigDirector_ScaleMotionSpeed::unload "
virtual void SwigDirector_ScaleMotionSpeed::unload()
         
called when the motion is unloaded from an avatar         
         
        ";
%feature("docstring") SwigDirector_ScaleMotionSpeed::loaded "
virtual bool SwigDirector_ScaleMotionSpeed::loaded()
         
checks if the motion has been loaded into an avatar         
         
        ";
%feature("docstring") SwigDirector_ScaleMotionSpeed::printInfo "
virtual void SwigDirector_ScaleMotionSpeed::printInfo()
         
prints out info about the motion heirarchy         
         
        ";
%feature("docstring") SwigDirector_ScaleMotionSpeed::findSubByType "
virtual Piavca::Motion* SwigDirector_ScaleMotionSpeed::findSubByType(type_info const &ty)
         
finds the first submotion with a given type         
         
        ";
%feature("docstring") SwigDirector_ScaleMotionSpeed::isNull "
virtual bool SwigDirector_ScaleMotionSpeed::isNull(int trackId) const 
         
given an iterator tests whether it actually points to anything or if its null         
         
        ";
%feature("docstring") SwigDirector_ScaleMotionSpeed::getTrackType "
virtual Piavca::trackType SwigDirector_ScaleMotionSpeed::getTrackType(int trackId) const 
         
get the type of the track corresponding to an iterator         
         
        ";
%feature("docstring") SwigDirector_ScaleMotionSpeed::swig_get_inner "
bool SwigDirector_ScaleMotionSpeed::swig_get_inner(const char *name) const 
         
        
         
        ";
%feature("docstring") SwigDirector_ScaleMotionSpeed::swig_set_inner "
void SwigDirector_ScaleMotionSpeed::swig_set_inner(const char *name, bool val) const 
         
        
         
        ";
%feature("docstring") SwigDirector_SelfBlend " 

    
       
     see also: Piavca_wrap.h";

%feature("docstring") SwigDirector_SelfBlend::SwigDirector_SelfBlend "
SwigDirector_SelfBlend::SwigDirector_SelfBlend(PyObject *self, Piavca::Motion *mot=NULL, float interval=0.2)
         
        
         
        ";
%feature("docstring") SwigDirector_SelfBlend::SwigDirector_SelfBlend "
SwigDirector_SelfBlend::SwigDirector_SelfBlend(PyObject *self, Piavca::SelfBlend const &sb)
         
        
         
        ";
%feature("docstring") SwigDirector_SelfBlend::findSub "
virtual Piavca::Motion* SwigDirector_SelfBlend::findSub(Piavca::tstring nm)
         
finds the first submotion with a given name         
         
        ";
%feature("docstring") SwigDirector_SelfBlend::load "
virtual void SwigDirector_SelfBlend::load(Piavca::Avatar *av)
         
called when the motion is loaded into an avatar         
         
        ";
%feature("docstring") SwigDirector_SelfBlend::setStartTime "
virtual void SwigDirector_SelfBlend::setStartTime(float time)
         
        
         
std::cout << \"SequentialBlend::setStartTime \" << name << \" \"         ";
%feature("docstring") SwigDirector_SelfBlend::getFloatValueAtTimeInternal "
virtual float SwigDirector_SelfBlend::getFloatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") SwigDirector_SelfBlend::getVecValueAtTimeInternal "
virtual Piavca::Vec SwigDirector_SelfBlend::getVecValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") SwigDirector_SelfBlend::getQuatValueAtTimeInternal "
virtual Piavca::Quat SwigDirector_SelfBlend::getQuatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") SwigDirector_SelfBlend::reblend "
virtual void SwigDirector_SelfBlend::reblend(float time)
         
saves the state of the motion at time and start blending the motion back into that from the start         
         
        ";
%feature("docstring") SwigDirector_SelfBlend::isRandomAccess "
virtual bool SwigDirector_SelfBlend::isRandomAccess()
         
whether you can access a motions value at frames other than the current one         
         
        ";
%feature("docstring") SwigDirector_SelfBlend::~SwigDirector_SelfBlend "
virtual SwigDirector_SelfBlend::~SwigDirector_SelfBlend()
         
        
         
        ";
%feature("docstring") SwigDirector_SelfBlend::clone "
virtual Piavca::Motion* SwigDirector_SelfBlend::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") SwigDirector_SelfBlend::reset "
virtual void SwigDirector_SelfBlend::reset()
         
does any resetting needed         
         
        ";
%feature("docstring") SwigDirector_SelfBlend::isFacial "
virtual bool SwigDirector_SelfBlend::isFacial()
         
whether it is a face or body motion         
         
        ";
%feature("docstring") SwigDirector_SelfBlend::getMotionLength "
virtual float SwigDirector_SelfBlend::getMotionLength() const 
         
gets the motion length (transition start + blend interval + length of second motion)         
         
        ";
%feature("docstring") SwigDirector_SelfBlend::unload "
virtual void SwigDirector_SelfBlend::unload()
         
called when the motion is unloaded from an avatar         
         
        ";
%feature("docstring") SwigDirector_SelfBlend::loaded "
virtual bool SwigDirector_SelfBlend::loaded()
         
checks if the motion has been loaded into an avatar         
         
        ";
%feature("docstring") SwigDirector_SelfBlend::printInfo "
virtual void SwigDirector_SelfBlend::printInfo()
         
prints out info about the motion heirarchy         
         
        ";
%feature("docstring") SwigDirector_SelfBlend::setMaintainY "
virtual void SwigDirector_SelfBlend::setMaintainY(bool b)
         
        
         
        ";
%feature("docstring") SwigDirector_SelfBlend::setAccumulateRoot "
virtual void SwigDirector_SelfBlend::setAccumulateRoot(bool b)
         
        
         
        ";
%feature("docstring") SwigDirector_SelfBlend::findSubByType "
virtual Piavca::Motion* SwigDirector_SelfBlend::findSubByType(type_info const &ty)
         
finds the first submotion with a given type         
         
        ";
%feature("docstring") SwigDirector_SelfBlend::setMotion "
virtual void SwigDirector_SelfBlend::setMotion(Piavca::Motion *mot)
         
sets the motion to be blended in         
         
        ";
%feature("docstring") SwigDirector_SelfBlend::isNull "
virtual bool SwigDirector_SelfBlend::isNull(int trackId) const 
         
given a track ID tests whether it actually points to anything or if its null         
         
is null if the track is null in both motions.         ";
%feature("docstring") SwigDirector_SelfBlend::getTrackType "
virtual Piavca::trackType SwigDirector_SelfBlend::getTrackType(int trackId) const 
         
get the type of the track corresponding to an iterator         
         
        ";
%feature("docstring") SwigDirector_SelfBlend::swig_get_inner "
bool SwigDirector_SelfBlend::swig_get_inner(const char *name) const 
         
        
         
        ";
%feature("docstring") SwigDirector_SelfBlend::swig_set_inner "
void SwigDirector_SelfBlend::swig_set_inner(const char *name, bool val) const 
         
        
         
        ";
%feature("docstring") SwigDirector_SequentialBlend " 

    
       
     see also: Piavca_wrap.h";

%feature("docstring") SwigDirector_SequentialBlend::SwigDirector_SequentialBlend "
SwigDirector_SequentialBlend::SwigDirector_SequentialBlend(PyObject *self, Piavca::Motion *mot1=NULL, Piavca::Motion *mot2=NULL, float interval=0.2, float start=0.0)
         
        
         
        ";
%feature("docstring") SwigDirector_SequentialBlend::SwigDirector_SequentialBlend "
SwigDirector_SequentialBlend::SwigDirector_SequentialBlend(PyObject *self, Piavca::SequentialBlend const &sb)
         
        
         
        ";
%feature("docstring") SwigDirector_SequentialBlend::findSub "
virtual Piavca::Motion* SwigDirector_SequentialBlend::findSub(Piavca::tstring nm)
         
finds the first submotion with a given name         
         
        ";
%feature("docstring") SwigDirector_SequentialBlend::load "
virtual void SwigDirector_SequentialBlend::load(Piavca::Avatar *av)
         
called when the motion is loaded into an avatar         
         
        ";
%feature("docstring") SwigDirector_SequentialBlend::setStartTime "
virtual void SwigDirector_SequentialBlend::setStartTime(float time)
         
        
         
std::cout << \"SequentialBlend::setStartTime \" << name << \" \"         ";
%feature("docstring") SwigDirector_SequentialBlend::getFloatValueAtTimeInternal "
virtual float SwigDirector_SequentialBlend::getFloatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") SwigDirector_SequentialBlend::getVecValueAtTimeInternal "
virtual Piavca::Vec SwigDirector_SequentialBlend::getVecValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") SwigDirector_SequentialBlend::getQuatValueAtTimeInternal "
virtual Piavca::Quat SwigDirector_SequentialBlend::getQuatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") SwigDirector_SequentialBlend::isRandomAccess "
virtual bool SwigDirector_SequentialBlend::isRandomAccess()
         
whether you can access a motions value at frames other than the current one         
         
        ";
%feature("docstring") SwigDirector_SequentialBlend::~SwigDirector_SequentialBlend "
virtual SwigDirector_SequentialBlend::~SwigDirector_SequentialBlend()
         
        
         
        ";
%feature("docstring") SwigDirector_SequentialBlend::reset "
virtual void SwigDirector_SequentialBlend::reset()
         
does any resetting needed         
         
        ";
%feature("docstring") SwigDirector_SequentialBlend::clone "
virtual Piavca::Motion* SwigDirector_SequentialBlend::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") SwigDirector_SequentialBlend::isFacial "
virtual bool SwigDirector_SequentialBlend::isFacial()
         
whether it is a face or body motion         
         
        ";
%feature("docstring") SwigDirector_SequentialBlend::getMotionLength "
virtual float SwigDirector_SequentialBlend::getMotionLength() const 
         
gets the motion length (transition start + blend interval + length of second motion)         
         
        ";
%feature("docstring") SwigDirector_SequentialBlend::unload "
virtual void SwigDirector_SequentialBlend::unload()
         
called when the motion is unloaded from an avatar         
         
        ";
%feature("docstring") SwigDirector_SequentialBlend::loaded "
virtual bool SwigDirector_SequentialBlend::loaded()
         
checks if the motion has been loaded into an avatar         
         
        ";
%feature("docstring") SwigDirector_SequentialBlend::printInfo "
virtual void SwigDirector_SequentialBlend::printInfo()
         
prints out info about the motion heirarchy         
         
        ";
%feature("docstring") SwigDirector_SequentialBlend::setMaintainY "
virtual void SwigDirector_SequentialBlend::setMaintainY(bool b)
         
        
         
        ";
%feature("docstring") SwigDirector_SequentialBlend::setAccumulateRoot "
virtual void SwigDirector_SequentialBlend::setAccumulateRoot(bool b)
         
        
         
        ";
%feature("docstring") SwigDirector_SequentialBlend::findSubByType "
virtual Piavca::Motion* SwigDirector_SequentialBlend::findSubByType(type_info const &ty)
         
finds the first submotion with a given type         
         
        ";
%feature("docstring") SwigDirector_SequentialBlend::isNull "
virtual bool SwigDirector_SequentialBlend::isNull(int trackId) const 
         
given a track ID tests whether it actually points to anything or if its null         
         
is null if the track is null in both motions.         ";
%feature("docstring") SwigDirector_SequentialBlend::getTrackType "
virtual Piavca::trackType SwigDirector_SequentialBlend::getTrackType(int trackId) const 
         
get the type of the track corresponding to an iterator         
         
        ";
%feature("docstring") SwigDirector_SequentialBlend::swig_get_inner "
bool SwigDirector_SequentialBlend::swig_get_inner(const char *name) const 
         
        
         
        ";
%feature("docstring") SwigDirector_SequentialBlend::swig_set_inner "
void SwigDirector_SequentialBlend::swig_set_inner(const char *name, bool val) const 
         
        
         
        ";
%feature("docstring") SwigDirector_SubMotion " 

    
       
     see also: Piavca_wrap.h";

%feature("docstring") SwigDirector_SubMotion::SwigDirector_SubMotion "
SwigDirector_SubMotion::SwigDirector_SubMotion(PyObject *self)
         
        
         
        ";
%feature("docstring") SwigDirector_SubMotion::SwigDirector_SubMotion "
SwigDirector_SubMotion::SwigDirector_SubMotion(PyObject *self, Piavca::Motion *m, float _start, float _end)
         
        
         
        ";
%feature("docstring") SwigDirector_SubMotion::SwigDirector_SubMotion "
SwigDirector_SubMotion::SwigDirector_SubMotion(PyObject *self, Piavca::SubMotion const &sm)
         
        
         
        ";
%feature("docstring") SwigDirector_SubMotion::findSub "
virtual Piavca::Motion* SwigDirector_SubMotion::findSub(Piavca::tstring nm)
         
finds the first submotion with a given name         
         
        ";
%feature("docstring") SwigDirector_SubMotion::load "
virtual void SwigDirector_SubMotion::load(Piavca::Avatar *av)
         
called when the motion is loaded into an avatar         
         
        ";
%feature("docstring") SwigDirector_SubMotion::setStartTime "
virtual void SwigDirector_SubMotion::setStartTime(float time)
         
sets the start time of the motion. Called when its loaded into an avatar.         
         
        ";
%feature("docstring") SwigDirector_SubMotion::getFloatValueAtTimeInternal "
virtual float SwigDirector_SubMotion::getFloatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") SwigDirector_SubMotion::getVecValueAtTimeInternal "
virtual Piavca::Vec SwigDirector_SubMotion::getVecValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") SwigDirector_SubMotion::getQuatValueAtTimeInternal "
virtual Piavca::Quat SwigDirector_SubMotion::getQuatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") SwigDirector_SubMotion::isRandomAccess "
virtual bool SwigDirector_SubMotion::isRandomAccess()
         
whether you can access a motions value at frames other than the current one         
         
        ";
%feature("docstring") SwigDirector_SubMotion::~SwigDirector_SubMotion "
virtual SwigDirector_SubMotion::~SwigDirector_SubMotion()
         
        
         
        ";
%feature("docstring") SwigDirector_SubMotion::reset "
virtual void SwigDirector_SubMotion::reset()
         
does any resetting needed         
         
        ";
%feature("docstring") SwigDirector_SubMotion::clone "
virtual Piavca::Motion* SwigDirector_SubMotion::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") SwigDirector_SubMotion::isFacial "
virtual bool SwigDirector_SubMotion::isFacial()
         
whether it is a face or body motion         
         
        ";
%feature("docstring") SwigDirector_SubMotion::getMotionLength "
virtual float SwigDirector_SubMotion::getMotionLength() const 
         
gets the length of the motion in seconds         
         
        ";
%feature("docstring") SwigDirector_SubMotion::unload "
virtual void SwigDirector_SubMotion::unload()
         
called when the motion is unloaded from an avatar         
         
        ";
%feature("docstring") SwigDirector_SubMotion::loaded "
virtual bool SwigDirector_SubMotion::loaded()
         
checks if the motion has been loaded into an avatar         
         
        ";
%feature("docstring") SwigDirector_SubMotion::printInfo "
virtual void SwigDirector_SubMotion::printInfo()
         
prints out info about the motion heirarchy         
         
        ";
%feature("docstring") SwigDirector_SubMotion::findSubByType "
virtual Piavca::Motion* SwigDirector_SubMotion::findSubByType(type_info const &ty)
         
finds the first submotion with a given type         
         
        ";
%feature("docstring") SwigDirector_SubMotion::isNull "
virtual bool SwigDirector_SubMotion::isNull(int trackId) const 
         
given an iterator tests whether it actually points to anything or if its null         
         
        ";
%feature("docstring") SwigDirector_SubMotion::getTrackType "
virtual Piavca::trackType SwigDirector_SubMotion::getTrackType(int trackId) const 
         
get the type of the track corresponding to an iterator         
         
        ";
%feature("docstring") SwigDirector_SubMotion::swig_get_inner "
bool SwigDirector_SubMotion::swig_get_inner(const char *name) const 
         
        
         
        ";
%feature("docstring") SwigDirector_SubMotion::swig_set_inner "
void SwigDirector_SubMotion::swig_set_inner(const char *name, bool val) const 
         
        
         
        ";
%feature("docstring") SwigDirector_TimeCallback " 

    
       
     see also: Piavca_wrap.h";

%feature("docstring") SwigDirector_TimeCallback::SwigDirector_TimeCallback "
SwigDirector_TimeCallback::SwigDirector_TimeCallback(PyObject *self, tstring _name)
         
        
         
        ";
%feature("docstring") SwigDirector_TimeCallback::timeStep "
virtual void SwigDirector_TimeCallback::timeStep(Piavca::Core *core, float time)
         
implement this to make the callback do things         
         
It's called every frame with by the API         ";
%feature("docstring") SwigDirector_TimeCallback::~SwigDirector_TimeCallback "
virtual SwigDirector_TimeCallback::~SwigDirector_TimeCallback()
         
        
         
        ";
%feature("docstring") SwigDirector_TimeCallback::init "
virtual void SwigDirector_TimeCallback::init(Piavca::Core *core)
         
This is a setup method for the callback.         
         
It's called when the callback is registered         ";
%feature("docstring") SwigDirector_TimeCallback::swig_get_inner "
bool SwigDirector_TimeCallback::swig_get_inner(const char *name) const 
         
        
         
        ";
%feature("docstring") SwigDirector_TimeCallback::swig_set_inner "
void SwigDirector_TimeCallback::swig_set_inner(const char *name, bool val) const 
         
        
         
        ";
%feature("docstring") SwigDirector_TimeOffset " 

    
       
     see also: Piavca_wrap.h";

%feature("docstring") SwigDirector_TimeOffset::SwigDirector_TimeOffset "
SwigDirector_TimeOffset::SwigDirector_TimeOffset(PyObject *self, Piavca::Motion *mot=NULL, float offs=0.0f)
         
        
         
        ";
%feature("docstring") SwigDirector_TimeOffset::SwigDirector_TimeOffset "
SwigDirector_TimeOffset::SwigDirector_TimeOffset(PyObject *self, Piavca::TimeOffset const &to)
         
        
         
        ";
%feature("docstring") SwigDirector_TimeOffset::findSub "
virtual Piavca::Motion* SwigDirector_TimeOffset::findSub(Piavca::tstring nm)
         
finds the first submotion with a given name         
         
        ";
%feature("docstring") SwigDirector_TimeOffset::load "
virtual void SwigDirector_TimeOffset::load(Piavca::Avatar *av)
         
called when the motion is loaded into an avatar         
         
        ";
%feature("docstring") SwigDirector_TimeOffset::setStartTime "
virtual void SwigDirector_TimeOffset::setStartTime(float time)
         
sets the start time of the motion. Called when its loaded into an avatar.         
         
        ";
%feature("docstring") SwigDirector_TimeOffset::getFloatValueAtTimeInternal "
virtual float SwigDirector_TimeOffset::getFloatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") SwigDirector_TimeOffset::getVecValueAtTimeInternal "
virtual Piavca::Vec SwigDirector_TimeOffset::getVecValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe (vec values are scaled)         
         
        ";
%feature("docstring") SwigDirector_TimeOffset::getQuatValueAtTimeInternal "
virtual Piavca::Quat SwigDirector_TimeOffset::getQuatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") SwigDirector_TimeOffset::isRandomAccess "
virtual bool SwigDirector_TimeOffset::isRandomAccess()
         
whether you can access a motions value at frames other than the current one         
         
        ";
%feature("docstring") SwigDirector_TimeOffset::~SwigDirector_TimeOffset "
virtual SwigDirector_TimeOffset::~SwigDirector_TimeOffset()
         
        
         
        ";
%feature("docstring") SwigDirector_TimeOffset::reset "
virtual void SwigDirector_TimeOffset::reset()
         
does any resetting needed         
         
        ";
%feature("docstring") SwigDirector_TimeOffset::clone "
virtual Piavca::Motion* SwigDirector_TimeOffset::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") SwigDirector_TimeOffset::getMotionLength "
virtual float SwigDirector_TimeOffset::getMotionLength() const 
         
gets the length of the motion in seconds         
         
        ";
%feature("docstring") SwigDirector_TimeOffset::isFacial "
virtual bool SwigDirector_TimeOffset::isFacial()
         
whether it is a face or body motion         
         
        ";
%feature("docstring") SwigDirector_TimeOffset::unload "
virtual void SwigDirector_TimeOffset::unload()
         
called when the motion is unloaded from an avatar         
         
        ";
%feature("docstring") SwigDirector_TimeOffset::loaded "
virtual bool SwigDirector_TimeOffset::loaded()
         
checks if the motion has been loaded into an avatar         
         
        ";
%feature("docstring") SwigDirector_TimeOffset::printInfo "
virtual void SwigDirector_TimeOffset::printInfo()
         
prints out info about the motion heirarchy         
         
        ";
%feature("docstring") SwigDirector_TimeOffset::findSubByType "
virtual Piavca::Motion* SwigDirector_TimeOffset::findSubByType(type_info const &ty)
         
finds the first submotion with a given type         
         
        ";
%feature("docstring") SwigDirector_TimeOffset::isNull "
virtual bool SwigDirector_TimeOffset::isNull(int trackId) const 
         
given an iterator tests whether it actually points to anything or if its null         
         
        ";
%feature("docstring") SwigDirector_TimeOffset::getTrackType "
virtual Piavca::trackType SwigDirector_TimeOffset::getTrackType(int trackId) const 
         
get the type of the track corresponding to an iterator         
         
        ";
%feature("docstring") SwigDirector_TimeOffset::swig_get_inner "
bool SwigDirector_TimeOffset::swig_get_inner(const char *name) const 
         
        
         
        ";
%feature("docstring") SwigDirector_TimeOffset::swig_set_inner "
void SwigDirector_TimeOffset::swig_set_inner(const char *name, bool val) const 
         
        
         
        ";
%feature("docstring") SwigDirector_TimeRangeMotion " 

    
       
     see also: Piavca_wrap.h";

%feature("docstring") SwigDirector_TimeRangeMotion::SwigDirector_TimeRangeMotion "
SwigDirector_TimeRangeMotion::SwigDirector_TimeRangeMotion(PyObject *self)
         
        
         
        ";
%feature("docstring") SwigDirector_TimeRangeMotion::SwigDirector_TimeRangeMotion "
SwigDirector_TimeRangeMotion::SwigDirector_TimeRangeMotion(PyObject *self, Piavca::Motion *m, float _start, float _end)
         
        
         
        ";
%feature("docstring") SwigDirector_TimeRangeMotion::SwigDirector_TimeRangeMotion "
SwigDirector_TimeRangeMotion::SwigDirector_TimeRangeMotion(PyObject *self, Piavca::TimeRangeMotion const &sm)
         
        
         
        ";
%feature("docstring") SwigDirector_TimeRangeMotion::findSub "
virtual Piavca::Motion* SwigDirector_TimeRangeMotion::findSub(Piavca::tstring nm)
         
finds the first submotion with a given name         
         
        ";
%feature("docstring") SwigDirector_TimeRangeMotion::load "
virtual void SwigDirector_TimeRangeMotion::load(Piavca::Avatar *av)
         
called when the motion is loaded into an avatar         
         
        ";
%feature("docstring") SwigDirector_TimeRangeMotion::setStartTime "
virtual void SwigDirector_TimeRangeMotion::setStartTime(float time)
         
sets the start time of the motion. Called when its loaded into an avatar.         
         
        ";
%feature("docstring") SwigDirector_TimeRangeMotion::getFloatValueAtTimeInternal "
virtual float SwigDirector_TimeRangeMotion::getFloatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") SwigDirector_TimeRangeMotion::getVecValueAtTimeInternal "
virtual Piavca::Vec SwigDirector_TimeRangeMotion::getVecValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") SwigDirector_TimeRangeMotion::getQuatValueAtTimeInternal "
virtual Piavca::Quat SwigDirector_TimeRangeMotion::getQuatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") SwigDirector_TimeRangeMotion::isRandomAccess "
virtual bool SwigDirector_TimeRangeMotion::isRandomAccess()
         
whether you can access a motions value at frames other than the current one         
         
        ";
%feature("docstring") SwigDirector_TimeRangeMotion::~SwigDirector_TimeRangeMotion "
virtual SwigDirector_TimeRangeMotion::~SwigDirector_TimeRangeMotion()
         
        
         
        ";
%feature("docstring") SwigDirector_TimeRangeMotion::reset "
virtual void SwigDirector_TimeRangeMotion::reset()
         
does any resetting needed         
         
        ";
%feature("docstring") SwigDirector_TimeRangeMotion::clone "
virtual Piavca::Motion* SwigDirector_TimeRangeMotion::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") SwigDirector_TimeRangeMotion::getMotionLength "
virtual float SwigDirector_TimeRangeMotion::getMotionLength() const 
         
gets the length of the motion in seconds         
         
        ";
%feature("docstring") SwigDirector_TimeRangeMotion::isFacial "
virtual bool SwigDirector_TimeRangeMotion::isFacial()
         
whether it is a face or body motion         
         
        ";
%feature("docstring") SwigDirector_TimeRangeMotion::unload "
virtual void SwigDirector_TimeRangeMotion::unload()
         
called when the motion is unloaded from an avatar         
         
        ";
%feature("docstring") SwigDirector_TimeRangeMotion::loaded "
virtual bool SwigDirector_TimeRangeMotion::loaded()
         
checks if the motion has been loaded into an avatar         
         
        ";
%feature("docstring") SwigDirector_TimeRangeMotion::printInfo "
virtual void SwigDirector_TimeRangeMotion::printInfo()
         
prints out info about the motion heirarchy         
         
        ";
%feature("docstring") SwigDirector_TimeRangeMotion::findSubByType "
virtual Piavca::Motion* SwigDirector_TimeRangeMotion::findSubByType(type_info const &ty)
         
finds the first submotion with a given type         
         
        ";
%feature("docstring") SwigDirector_TimeRangeMotion::isNull "
virtual bool SwigDirector_TimeRangeMotion::isNull(int trackId) const 
         
given an iterator tests whether it actually points to anything or if its null         
         
        ";
%feature("docstring") SwigDirector_TimeRangeMotion::getTrackType "
virtual Piavca::trackType SwigDirector_TimeRangeMotion::getTrackType(int trackId) const 
         
get the type of the track corresponding to an iterator         
         
        ";
%feature("docstring") SwigDirector_TimeRangeMotion::swig_get_inner "
bool SwigDirector_TimeRangeMotion::swig_get_inner(const char *name) const 
         
        
         
        ";
%feature("docstring") SwigDirector_TimeRangeMotion::swig_set_inner "
void SwigDirector_TimeRangeMotion::swig_set_inner(const char *name, bool val) const 
         
        
         
        ";
%feature("docstring") SwigDirector_TimeWarp " 

    
       
     see also: Piavca_wrap.h";

%feature("docstring") SwigDirector_TimeWarp::SwigDirector_TimeWarp "
SwigDirector_TimeWarp::SwigDirector_TimeWarp(PyObject *self, Piavca::Motion *m=NULL, Piavca::Motion *warp=NULL)
         
        
         
        ";
%feature("docstring") SwigDirector_TimeWarp::SwigDirector_TimeWarp "
SwigDirector_TimeWarp::SwigDirector_TimeWarp(PyObject *self, Piavca::TimeWarp const &tw)
         
        
         
        ";
%feature("docstring") SwigDirector_TimeWarp::findSub "
virtual Piavca::Motion* SwigDirector_TimeWarp::findSub(Piavca::tstring nm)
         
finds the first submotion with a given name         
         
        ";
%feature("docstring") SwigDirector_TimeWarp::load "
virtual void SwigDirector_TimeWarp::load(Piavca::Avatar *av)
         
called when the motion is loaded into an avatar         
         
        ";
%feature("docstring") SwigDirector_TimeWarp::setStartTime "
virtual void SwigDirector_TimeWarp::setStartTime(float time)
         
sets the start time of the motion. Called when its loaded into an avatar.         
         
        ";
%feature("docstring") SwigDirector_TimeWarp::getFloatValueAtTimeInternal "
virtual float SwigDirector_TimeWarp::getFloatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") SwigDirector_TimeWarp::getVecValueAtTimeInternal "
virtual Piavca::Vec SwigDirector_TimeWarp::getVecValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") SwigDirector_TimeWarp::getQuatValueAtTimeInternal "
virtual Piavca::Quat SwigDirector_TimeWarp::getQuatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") SwigDirector_TimeWarp::isRandomAccess "
virtual bool SwigDirector_TimeWarp::isRandomAccess()
         
whether you can access a motions value at frames other than the current one         
         
        ";
%feature("docstring") SwigDirector_TimeWarp::~SwigDirector_TimeWarp "
virtual SwigDirector_TimeWarp::~SwigDirector_TimeWarp()
         
        
         
        ";
%feature("docstring") SwigDirector_TimeWarp::reset "
virtual void SwigDirector_TimeWarp::reset()
         
does any resetting needed         
         
        ";
%feature("docstring") SwigDirector_TimeWarp::clone "
virtual Piavca::Motion* SwigDirector_TimeWarp::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") SwigDirector_TimeWarp::isFacial "
virtual bool SwigDirector_TimeWarp::isFacial()
         
whether it is a face or body motion         
         
        ";
%feature("docstring") SwigDirector_TimeWarp::getMotionLength "
virtual float SwigDirector_TimeWarp::getMotionLength() const 
         
gets the length of the motion in seconds         
         
        ";
%feature("docstring") SwigDirector_TimeWarp::unload "
virtual void SwigDirector_TimeWarp::unload()
         
called when the motion is unloaded from an avatar         
         
        ";
%feature("docstring") SwigDirector_TimeWarp::loaded "
virtual bool SwigDirector_TimeWarp::loaded()
         
checks if the motion has been loaded into an avatar         
         
        ";
%feature("docstring") SwigDirector_TimeWarp::printInfo "
virtual void SwigDirector_TimeWarp::printInfo()
         
prints out info about the motion heirarchy         
         
        ";
%feature("docstring") SwigDirector_TimeWarp::findSubByType "
virtual Piavca::Motion* SwigDirector_TimeWarp::findSubByType(type_info const &ty)
         
finds the first submotion with a given type         
         
        ";
%feature("docstring") SwigDirector_TimeWarp::isNull "
virtual bool SwigDirector_TimeWarp::isNull(int trackId) const 
         
given an iterator tests whether it actually points to anything or if its null         
         
        ";
%feature("docstring") SwigDirector_TimeWarp::getTrackType "
virtual Piavca::trackType SwigDirector_TimeWarp::getTrackType(int trackId) const 
         
get the type of the track corresponding to an iterator         
         
        ";
%feature("docstring") SwigDirector_TimeWarp::swig_get_inner "
bool SwigDirector_TimeWarp::swig_get_inner(const char *name) const 
         
        
         
        ";
%feature("docstring") SwigDirector_TimeWarp::swig_set_inner "
void SwigDirector_TimeWarp::swig_set_inner(const char *name, bool val) const 
         
        
         
        ";
%feature("docstring") SwigDirector_TrackMotion " 

    
       
     see also: Piavca_wrap.h";

%feature("docstring") SwigDirector_TrackMotion::SwigDirector_TrackMotion "
SwigDirector_TrackMotion::SwigDirector_TrackMotion(PyObject *self, Piavca::tstring fileName, int flags=Piavca::TRANS_NONE, Piavca::Motion *basePosture=NULL)
         
        
         
        ";
%feature("docstring") SwigDirector_TrackMotion::SwigDirector_TrackMotion "
SwigDirector_TrackMotion::SwigDirector_TrackMotion(PyObject *self, bool _facial=false)
         
        
         
        ";
%feature("docstring") SwigDirector_TrackMotion::SwigDirector_TrackMotion "
SwigDirector_TrackMotion::SwigDirector_TrackMotion(PyObject *self, Piavca::MotionImp *_imp)
         
        
         
        ";
%feature("docstring") SwigDirector_TrackMotion::SwigDirector_TrackMotion "
SwigDirector_TrackMotion::SwigDirector_TrackMotion(PyObject *self, Piavca::TrackMotion const &mot)
         
        
         
        ";
%feature("docstring") SwigDirector_TrackMotion::SwigDirector_TrackMotion "
SwigDirector_TrackMotion::SwigDirector_TrackMotion(PyObject *self, Piavca::Motion &mot)
         
        
         
        ";
%feature("docstring") SwigDirector_TrackMotion::findSub "
virtual Piavca::Motion* SwigDirector_TrackMotion::findSub(Piavca::tstring nm)
         
finds the first submotion with a given name         
         
        ";
%feature("docstring") SwigDirector_TrackMotion::load "
virtual void SwigDirector_TrackMotion::load(Piavca::Avatar *av)
         
called when the motion is loaded into an avatar         
         
        ";
%feature("docstring") SwigDirector_TrackMotion::setStartTime "
virtual void SwigDirector_TrackMotion::setStartTime(float t)
         
sets the start time of the motion. Called when its loaded into an avatar.         
         
        ";
%feature("docstring") SwigDirector_TrackMotion::getFloatValueAtTimeInternal "
virtual float SwigDirector_TrackMotion::getFloatValueAtTimeInternal(int trackId, float time)
         
get the keyframe value at time (only works for floats)         
         
        ";
%feature("docstring") SwigDirector_TrackMotion::getVecValueAtTimeInternal "
virtual Piavca::Vec SwigDirector_TrackMotion::getVecValueAtTimeInternal(int trackId, float time)
         
get the keyframe value at time (only works for Vecs)         
         
        ";
%feature("docstring") SwigDirector_TrackMotion::getQuatValueAtTimeInternal "
virtual Piavca::Quat SwigDirector_TrackMotion::getQuatValueAtTimeInternal(int trackId, float time)
         
get the keyframe value at time (only works for Quats)         
         
        ";
%feature("docstring") SwigDirector_TrackMotion::isRandomAccess "
virtual bool SwigDirector_TrackMotion::isRandomAccess()
         
whether you can access a motions value at frames other than the current one         
         
        ";
%feature("docstring") SwigDirector_TrackMotion::reset "
virtual void SwigDirector_TrackMotion::reset()
         
does any resetting needed         
         
        ";
%feature("docstring") SwigDirector_TrackMotion::~SwigDirector_TrackMotion "
virtual SwigDirector_TrackMotion::~SwigDirector_TrackMotion()
         
        
         
        ";
%feature("docstring") SwigDirector_TrackMotion::clone "
virtual Piavca::Motion* SwigDirector_TrackMotion::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") SwigDirector_TrackMotion::getMotionLength "
virtual float SwigDirector_TrackMotion::getMotionLength() const 
         
gets the time of the last keyframe of the motion         
         
        ";
%feature("docstring") SwigDirector_TrackMotion::isFacial "
virtual bool SwigDirector_TrackMotion::isFacial()
         
whether it is a face or body motion         
         
        ";
%feature("docstring") SwigDirector_TrackMotion::loaded "
virtual bool SwigDirector_TrackMotion::loaded()
         
checks if the motion has been loaded into an avatar         
         
        ";
%feature("docstring") SwigDirector_TrackMotion::unload "
virtual void SwigDirector_TrackMotion::unload()
         
called when the motion is unloaded from an avatar         
         
        ";
%feature("docstring") SwigDirector_TrackMotion::printInfo "
virtual void SwigDirector_TrackMotion::printInfo()
         
prints out info about the motion heirarchy         
         
        ";
%feature("docstring") SwigDirector_TrackMotion::findSubByType "
virtual Piavca::Motion* SwigDirector_TrackMotion::findSubByType(type_info const &ty)
         
finds the first submotion with a given type         
         
        ";
%feature("docstring") SwigDirector_TrackMotion::isNull "
virtual bool SwigDirector_TrackMotion::isNull(int trackId) const 
         
given a track ID tests whether it actually points to anything or if its null         
         
        ";
%feature("docstring") SwigDirector_TrackMotion::getTrackType "
virtual Piavca::trackType SwigDirector_TrackMotion::getTrackType(int trackId) const 
         
get the type of the track corresponding to a track ID         
         
        ";
%feature("docstring") SwigDirector_TrackMotion::swig_get_inner "
bool SwigDirector_TrackMotion::swig_get_inner(const char *name) const 
         
        
         
        ";
%feature("docstring") SwigDirector_TrackMotion::swig_set_inner "
void SwigDirector_TrackMotion::swig_set_inner(const char *name, bool val) const 
         
        
         
        ";
%feature("docstring") SwigDirector_TurnMotion " 

    
       
     see also: Piavca_wrap.h";

%feature("docstring") SwigDirector_TurnMotion::SwigDirector_TurnMotion "
SwigDirector_TurnMotion::SwigDirector_TurnMotion(PyObject *self, Piavca::Motion *m=NULL, Piavca::Quat rot=Piavca::Quat())
         
        
         
        ";
%feature("docstring") SwigDirector_TurnMotion::SwigDirector_TurnMotion "
SwigDirector_TurnMotion::SwigDirector_TurnMotion(PyObject *self, Piavca::TurnMotion const &tm)
         
        
         
        ";
%feature("docstring") SwigDirector_TurnMotion::findSub "
virtual Piavca::Motion* SwigDirector_TurnMotion::findSub(Piavca::tstring nm)
         
finds the first submotion with a given name         
         
        ";
%feature("docstring") SwigDirector_TurnMotion::load "
virtual void SwigDirector_TurnMotion::load(Piavca::Avatar *av)
         
called when the motion is loaded into an avatar         
         
        ";
%feature("docstring") SwigDirector_TurnMotion::setStartTime "
virtual void SwigDirector_TurnMotion::setStartTime(float time)
         
sets the start time of the motion. Called when its loaded into an avatar.         
         
        ";
%feature("docstring") SwigDirector_TurnMotion::getFloatValueAtTimeInternal "
virtual float SwigDirector_TurnMotion::getFloatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") SwigDirector_TurnMotion::getVecValueAtTimeInternal "
virtual Piavca::Vec SwigDirector_TurnMotion::getVecValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") SwigDirector_TurnMotion::getQuatValueAtTimeInternal "
virtual Piavca::Quat SwigDirector_TurnMotion::getQuatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") SwigDirector_TurnMotion::isRandomAccess "
virtual bool SwigDirector_TurnMotion::isRandomAccess()
         
whether you can access a motions value at frames other than the current one         
         
        ";
%feature("docstring") SwigDirector_TurnMotion::~SwigDirector_TurnMotion "
virtual SwigDirector_TurnMotion::~SwigDirector_TurnMotion()
         
        
         
        ";
%feature("docstring") SwigDirector_TurnMotion::reset "
virtual void SwigDirector_TurnMotion::reset()
         
does any resetting needed         
         
        ";
%feature("docstring") SwigDirector_TurnMotion::clone "
virtual Piavca::Motion* SwigDirector_TurnMotion::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") SwigDirector_TurnMotion::getMotionLength "
virtual float SwigDirector_TurnMotion::getMotionLength() const 
         
gets the length of the motion in seconds         
         
        ";
%feature("docstring") SwigDirector_TurnMotion::isFacial "
virtual bool SwigDirector_TurnMotion::isFacial()
         
whether it is a face or body motion         
         
        ";
%feature("docstring") SwigDirector_TurnMotion::unload "
virtual void SwigDirector_TurnMotion::unload()
         
called when the motion is unloaded from an avatar         
         
        ";
%feature("docstring") SwigDirector_TurnMotion::loaded "
virtual bool SwigDirector_TurnMotion::loaded()
         
checks if the motion has been loaded into an avatar         
         
        ";
%feature("docstring") SwigDirector_TurnMotion::printInfo "
virtual void SwigDirector_TurnMotion::printInfo()
         
prints out info about the motion heirarchy         
         
        ";
%feature("docstring") SwigDirector_TurnMotion::findSubByType "
virtual Piavca::Motion* SwigDirector_TurnMotion::findSubByType(type_info const &ty)
         
finds the first submotion with a given type         
         
        ";
%feature("docstring") SwigDirector_TurnMotion::isNull "
virtual bool SwigDirector_TurnMotion::isNull(int trackId) const 
         
given an iterator tests whether it actually points to anything or if its null         
         
        ";
%feature("docstring") SwigDirector_TurnMotion::getTrackType "
virtual Piavca::trackType SwigDirector_TurnMotion::getTrackType(int trackId) const 
         
get the type of the track corresponding to an iterator         
         
        ";
%feature("docstring") SwigDirector_TurnMotion::swig_get_inner "
bool SwigDirector_TurnMotion::swig_get_inner(const char *name) const 
         
        
         
        ";
%feature("docstring") SwigDirector_TurnMotion::swig_set_inner "
void SwigDirector_TurnMotion::swig_set_inner(const char *name, bool val) const 
         
        
         
        ";
%feature("docstring") SwigDirector_TwoMotionCombiner " 

    
       
     see also: Piavca_wrap.h";

%feature("docstring") SwigDirector_TwoMotionCombiner::SwigDirector_TwoMotionCombiner "
SwigDirector_TwoMotionCombiner::SwigDirector_TwoMotionCombiner(PyObject *self)
         
        
         
        ";
%feature("docstring") SwigDirector_TwoMotionCombiner::SwigDirector_TwoMotionCombiner "
SwigDirector_TwoMotionCombiner::SwigDirector_TwoMotionCombiner(PyObject *self, Piavca::Motion *m1, Piavca::Motion *m2)
         
        
         
        ";
%feature("docstring") SwigDirector_TwoMotionCombiner::SwigDirector_TwoMotionCombiner "
SwigDirector_TwoMotionCombiner::SwigDirector_TwoMotionCombiner(PyObject *self, Piavca::TwoMotionCombiner const &tmc)
         
        
         
        ";
%feature("docstring") SwigDirector_TwoMotionCombiner::findSub "
virtual Piavca::Motion* SwigDirector_TwoMotionCombiner::findSub(Piavca::tstring nm)
         
finds the first submotion with a given name         
         
        ";
%feature("docstring") SwigDirector_TwoMotionCombiner::load "
virtual void SwigDirector_TwoMotionCombiner::load(Piavca::Avatar *av)
         
called when the motion is loaded into an avatar         
         
        ";
%feature("docstring") SwigDirector_TwoMotionCombiner::getFloatValueAtTimeInternal "
virtual float SwigDirector_TwoMotionCombiner::getFloatValueAtTimeInternal(int trackId, float time)
         
internal version of getFloatValueAtTime, to be overridden         
         
        ";
%feature("docstring") SwigDirector_TwoMotionCombiner::getVecValueAtTimeInternal "
virtual Piavca::Vec SwigDirector_TwoMotionCombiner::getVecValueAtTimeInternal(int trackId, float time)
         
internal version of getVecValueAtTime, to be overridden         
         
        ";
%feature("docstring") SwigDirector_TwoMotionCombiner::getQuatValueAtTimeInternal "
virtual Piavca::Quat SwigDirector_TwoMotionCombiner::getQuatValueAtTimeInternal(int trackId, float time)
         
internal version of getQuatValueAtTime, to be overridden         
         
        ";
%feature("docstring") SwigDirector_TwoMotionCombiner::setStartTime "
virtual void SwigDirector_TwoMotionCombiner::setStartTime(float time)
         
sets the start time of the motion. Called when its loaded into an avatar.         
         
        ";
%feature("docstring") SwigDirector_TwoMotionCombiner::isRandomAccess "
virtual bool SwigDirector_TwoMotionCombiner::isRandomAccess()
         
whether you can access a motions value at frames other than the current one         
         
        ";
%feature("docstring") SwigDirector_TwoMotionCombiner::clone "
virtual Piavca::Motion* SwigDirector_TwoMotionCombiner::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") SwigDirector_TwoMotionCombiner::~SwigDirector_TwoMotionCombiner "
virtual SwigDirector_TwoMotionCombiner::~SwigDirector_TwoMotionCombiner()
         
        
         
        ";
%feature("docstring") SwigDirector_TwoMotionCombiner::reset "
virtual void SwigDirector_TwoMotionCombiner::reset()
         
does any resetting needed         
         
        ";
%feature("docstring") SwigDirector_TwoMotionCombiner::getMotionLength "
virtual float SwigDirector_TwoMotionCombiner::getMotionLength() const 
         
gets the length of the combined motion (by default the length of the longer of the two)         
         
        ";
%feature("docstring") SwigDirector_TwoMotionCombiner::isFacial "
virtual bool SwigDirector_TwoMotionCombiner::isFacial()
         
whether it is a face or body motion         
         
        ";
%feature("docstring") SwigDirector_TwoMotionCombiner::unload "
virtual void SwigDirector_TwoMotionCombiner::unload()
         
called when the motion is unloaded from an avatar         
         
        ";
%feature("docstring") SwigDirector_TwoMotionCombiner::loaded "
virtual bool SwigDirector_TwoMotionCombiner::loaded()
         
checks if the motion has been loaded into an avatar         
         
        ";
%feature("docstring") SwigDirector_TwoMotionCombiner::printInfo "
virtual void SwigDirector_TwoMotionCombiner::printInfo()
         
prints out info about the motion heirarchy         
         
        ";
%feature("docstring") SwigDirector_TwoMotionCombiner::findSubByType "
virtual Piavca::Motion* SwigDirector_TwoMotionCombiner::findSubByType(type_info const &ty)
         
finds the first submotion with a given type         
         
        ";
%feature("docstring") SwigDirector_TwoMotionCombiner::isNull "
virtual bool SwigDirector_TwoMotionCombiner::isNull(int trackId) const 
         
given a track ID tests whether it actually points to anything or if its null         
         
is null if the track is null in both motions.         ";
%feature("docstring") SwigDirector_TwoMotionCombiner::getTrackType "
virtual Piavca::trackType SwigDirector_TwoMotionCombiner::getTrackType(int trackId) const 
         
get the type of the track corresponding to an iterator         
         
        ";
%feature("docstring") SwigDirector_TwoMotionCombiner::swig_get_inner "
bool SwigDirector_TwoMotionCombiner::swig_get_inner(const char *name) const 
         
        
         
        ";
%feature("docstring") SwigDirector_TwoMotionCombiner::swig_set_inner "
void SwigDirector_TwoMotionCombiner::swig_set_inner(const char *name, bool val) const 
         
        
         
        ";
%feature("docstring") SwigDirector_ZeroMotion " 

    
       
     see also: Piavca_wrap.h";

%feature("docstring") SwigDirector_ZeroMotion::SwigDirector_ZeroMotion "
SwigDirector_ZeroMotion::SwigDirector_ZeroMotion(PyObject *self, bool _facial=false)
         
        
         
        ";
%feature("docstring") SwigDirector_ZeroMotion::SwigDirector_ZeroMotion "
SwigDirector_ZeroMotion::SwigDirector_ZeroMotion(PyObject *self, Piavca::ZeroMotion const &zm)
         
        
         
        ";
%feature("docstring") SwigDirector_ZeroMotion::findSub "
virtual Piavca::Motion* SwigDirector_ZeroMotion::findSub(Piavca::tstring nm)
         
finds the first submotion with a given name         
         
        ";
%feature("docstring") SwigDirector_ZeroMotion::load "
virtual void SwigDirector_ZeroMotion::load(Piavca::Avatar *av)
         
called when the motion is loaded into an avatar         
         
        ";
%feature("docstring") SwigDirector_ZeroMotion::setStartTime "
virtual void SwigDirector_ZeroMotion::setStartTime(float t)
         
sets the start time of the motion. Called when its loaded into an avatar.         
         
        ";
%feature("docstring") SwigDirector_ZeroMotion::getFloatValueAtTimeInternal "
virtual float SwigDirector_ZeroMotion::getFloatValueAtTimeInternal(int trackId, float time)
         
get the value of a track at a given time (only works for floats)         
         
        ";
%feature("docstring") SwigDirector_ZeroMotion::getVecValueAtTimeInternal "
virtual Piavca::Vec SwigDirector_ZeroMotion::getVecValueAtTimeInternal(int trackId, float time)
         
get the value of a track at a given time (only works for Vecs)         
         
        ";
%feature("docstring") SwigDirector_ZeroMotion::getQuatValueAtTimeInternal "
virtual Piavca::Quat SwigDirector_ZeroMotion::getQuatValueAtTimeInternal(int trackId, float time)
         
get the value of a track at a given time (only works for Quats)         
         
        ";
%feature("docstring") SwigDirector_ZeroMotion::isRandomAccess "
virtual bool SwigDirector_ZeroMotion::isRandomAccess()
         
whether you can access a motions value at frames other than the current one         
         
        ";
%feature("docstring") SwigDirector_ZeroMotion::reset "
virtual void SwigDirector_ZeroMotion::reset()
         
does any resetting needed         
         
        ";
%feature("docstring") SwigDirector_ZeroMotion::~SwigDirector_ZeroMotion "
virtual SwigDirector_ZeroMotion::~SwigDirector_ZeroMotion()
         
        
         
        ";
%feature("docstring") SwigDirector_ZeroMotion::clone "
virtual Piavca::Motion* SwigDirector_ZeroMotion::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") SwigDirector_ZeroMotion::isFacial "
virtual bool SwigDirector_ZeroMotion::isFacial()
         
whether it is a face or body motion         
         
        ";
%feature("docstring") SwigDirector_ZeroMotion::getMotionLength "
virtual float SwigDirector_ZeroMotion::getMotionLength() const 
         
returns the length of the motion         
         
        ";
%feature("docstring") SwigDirector_ZeroMotion::loaded "
virtual bool SwigDirector_ZeroMotion::loaded()
         
checks if the motion has been loaded into an avatar         
         
        ";
%feature("docstring") SwigDirector_ZeroMotion::unload "
virtual void SwigDirector_ZeroMotion::unload()
         
called when the motion is unloaded from an avatar         
         
        ";
%feature("docstring") SwigDirector_ZeroMotion::printInfo "
virtual void SwigDirector_ZeroMotion::printInfo()
         
prints out info about the motion heirarchy         
         
        ";
%feature("docstring") SwigDirector_ZeroMotion::findSubByType "
virtual Piavca::Motion* SwigDirector_ZeroMotion::findSubByType(type_info const &ty)
         
finds the first submotion with a given type         
         
        ";
%feature("docstring") SwigDirector_ZeroMotion::isNull "
virtual bool SwigDirector_ZeroMotion::isNull(int trackId) const 
         
given a track ID tests whether it actually points to anything or if its null         
         
        ";
%feature("docstring") SwigDirector_ZeroMotion::getTrackType "
virtual Piavca::trackType SwigDirector_ZeroMotion::getTrackType(int trackId) const 
         
get the type of the track corresponding to an ID         
         
        ";
%feature("docstring") SwigDirector_ZeroMotion::swig_get_inner "
bool SwigDirector_ZeroMotion::swig_get_inner(const char *name) const 
         
        
         
        ";
%feature("docstring") SwigDirector_ZeroMotion::swig_set_inner "
void SwigDirector_ZeroMotion::swig_set_inner(const char *name, bool val) const 
         
        
         
        ";
%feature("docstring") Piavca::TextureHandler " 

A class for handling textures.     
       
The base version is pretty simple but it is set up so there can be a clever version for handling textures for multi-pipe rendering      see also: TextureHandler.h";

%feature("docstring") Piavca::TextureHandler::TextureHandler "
Piavca::TextureHandler::TextureHandler()
         
        
         
        ";
%feature("docstring") Piavca::TextureHandler::~TextureHandler "
virtual Piavca::TextureHandler::~TextureHandler()
         
        
         
        ";
%feature("docstring") Piavca::TextureHandler::loadTexture "
GLuint TextureHandler::loadTexture(const std::string &strFilename)
         
loads a texture and returns an id (NB but not the real texture id!)         
         
The id returned is specific to the texture handler and can be mapped to a real GL texture id using getTextureId. This is done to enable one texture handler id to map to multiple GL texture ids in multi-pipe renderers         ";
%feature("docstring") Piavca::TextureHandler::getTextureId "
GLuint TextureHandler::getTextureId(GLuint i)
         
maps from the texture handlers version of an id to the GL texture id         
         
        ";
%feature("docstring") Piavca::TimeCallback " 

A callback that is called by the API every frame, the user writes code by creating a subclass of the callback.     
       
The user can add data and implement the changeTime method (which is the one that is called everyframe). The callback system is currently under developement      see also: TimeCallback.h";

%feature("docstring") Piavca::TimeCallback::TimeCallback "
Piavca::TimeCallback::TimeCallback(tstring _name)
         
        
         
        ";
%feature("docstring") Piavca::TimeCallback::~TimeCallback "
virtual Piavca::TimeCallback::~TimeCallback()
         
        
         
        ";
%feature("docstring") Piavca::TimeCallback::getName "
tstring Piavca::TimeCallback::getName()
         
        
         
        ";
%feature("docstring") Piavca::TimeCallback::init "
virtual void Piavca::TimeCallback::init(Core *core)=0
         
This is a setup method for the callback.         
         
It's called when the callback is registered         ";
%feature("docstring") Piavca::TimeCallback::timeStep "
virtual void Piavca::TimeCallback::timeStep(Core *core, float time)=0
         
implement this to make the callback do things         
         
It's called every frame with by the API         ";
%feature("docstring") Piavca::TimeOffset " 

changes the start time of a motion by an offset     
       
     see also: TimeOffset.h";

%feature("docstring") Piavca::TimeOffset::TimeOffset "
Piavca::TimeOffset::TimeOffset(Motion *mot=NULL, float offs=0.0f)
         
        
         
        ";
%feature("docstring") Piavca::TimeOffset::TimeOffset "
Piavca::TimeOffset::TimeOffset(const TimeOffset &to)
         
        
         
        ";
%feature("docstring") Piavca::TimeOffset::clone "
virtual Motion* Piavca::TimeOffset::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") Piavca::TimeOffset::setStartTime "
virtual void Piavca::TimeOffset::setStartTime(float time)
         
sets the start time of the motion. Called when its loaded into an avatar.         
         
        ";
%feature("docstring") Piavca::TimeOffset::getFloatValueAtTimeInternal "
virtual PIAVCA_EXPORT float Piavca::TimeOffset::getFloatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") Piavca::TimeOffset::getVecValueAtTimeInternal "
virtual PIAVCA_EXPORT Vec Piavca::TimeOffset::getVecValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe (vec values are scaled)         
         
        ";
%feature("docstring") Piavca::TimeOffset::getQuatValueAtTimeInternal "
virtual PIAVCA_EXPORT Quat Piavca::TimeOffset::getQuatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") Piavca::TimeOffset::setOffset "
void Piavca::TimeOffset::setOffset(float offs)
         
Sets the scale factor for the postion components of the motion.         
         
        ";
%feature("docstring") Piavca::TimeRangeMotion " 

    
       
     see also: TimeRangeMotion.h";

%feature("docstring") Piavca::TimeRangeMotion::TimeRangeMotion "
TimeRangeMotion::TimeRangeMotion()
         
        
         
        ";
%feature("docstring") Piavca::TimeRangeMotion::TimeRangeMotion "
TimeRangeMotion::TimeRangeMotion(Motion *m, float _start, float _end)
         
        
         
        ";
%feature("docstring") Piavca::TimeRangeMotion::TimeRangeMotion "
TimeRangeMotion::TimeRangeMotion(const TimeRangeMotion &sm)
         
        
         
        ";
%feature("docstring") Piavca::TimeRangeMotion::clone "
Motion * TimeRangeMotion::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") Piavca::TimeRangeMotion::setStart "
void TimeRangeMotion::setStart(float s)
         
Sets the start of the range to be played.         
         
        ";
%feature("docstring") Piavca::TimeRangeMotion::setEnd "
void TimeRangeMotion::setEnd(float e)
         
Sets the end of the range to be played.         
         
        ";
%feature("docstring") Piavca::TimeRangeMotion::getFloatValueAtTimeInternal "
PIAVCA_EXPORT float TimeRangeMotion::getFloatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") Piavca::TimeRangeMotion::getVecValueAtTimeInternal "
PIAVCA_EXPORT Vec TimeRangeMotion::getVecValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") Piavca::TimeRangeMotion::getQuatValueAtTimeInternal "
PIAVCA_EXPORT Quat TimeRangeMotion::getQuatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") Piavca::TimeWarp " 

a motion filter that scales the motion's speed     
       
     see also: TimeWarp.h";

%feature("docstring") Piavca::TimeWarp::TimeWarp "
Piavca::TimeWarp::TimeWarp(Motion *m=NULL, Motion *warp=NULL)
         
        
         
Pass in the motion to be filtered and a scale factor         ";
%feature("docstring") Piavca::TimeWarp::TimeWarp "
Piavca::TimeWarp::TimeWarp(const TimeWarp &tw)
         
        
         
        ";
%feature("docstring") Piavca::TimeWarp::clone "
virtual Motion* Piavca::TimeWarp::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") Piavca::TimeWarp::getMotionLength "
virtual float Piavca::TimeWarp::getMotionLength() const 
         
gets the length of the motion in seconds         
         
        ";
%feature("docstring") Piavca::TimeWarp::getFloatValueAtTimeInternal "
virtual PIAVCA_EXPORT float Piavca::TimeWarp::getFloatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") Piavca::TimeWarp::getVecValueAtTimeInternal "
virtual PIAVCA_EXPORT Vec Piavca::TimeWarp::getVecValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") Piavca::TimeWarp::getQuatValueAtTimeInternal "
virtual PIAVCA_EXPORT Quat Piavca::TimeWarp::getQuatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") Piavca::TimeWarp::setWarp "
void Piavca::TimeWarp::setWarp(Motion *warp)
         
Sets the scale factor for the postion components of the motion.         
         
        ";
%feature("docstring") Piavca::TrackMotion " 

A specialisation of the Motion Interface to deal with keyframe motion data.     
       
Motion data can be read in from a bvh file. The actual underlying representation of the motion is forwarded to an implementation class (MotionImp) so that it can be implemented differently on different platforms if there are more efficient methods (a default implementatio is provided). Track motion provide the ability to create tracks and store data to them, if you want to create mtoion data on the fly. You can also cache the values of another motion object and save it as keyframe data.      see also: TrackMotion.h";

%feature("docstring") Piavca::TrackMotion::addFloatTrack "
void Piavca::TrackMotion::addFloatTrack(int trackId, float initialValue)
         
add a float track         
         
        ";
%feature("docstring") Piavca::TrackMotion::addVecTrack "
void Piavca::TrackMotion::addVecTrack(int trackId, const Vec &initialValue)
         
add a Vec track         
         
        ";
%feature("docstring") Piavca::TrackMotion::addQuatTrack "
void Piavca::TrackMotion::addQuatTrack(int trackId, const Quat &initialValue)
         
add a Quat track         
         
        ";
%feature("docstring") Piavca::TrackMotion::setFloatKeyframe "
void Piavca::TrackMotion::setFloatKeyframe(int trackId, float time, float value)
         
set keyframe value (or create a new one) (only works for floats)         
         
        ";
%feature("docstring") Piavca::TrackMotion::setFloatKeyframe "
void Piavca::TrackMotion::setFloatKeyframe(int trackId, float time, float value, float velocity)
         
set keyframe value (or create a new one) with a user specified velocity (only works for floats)         
         
        ";
%feature("docstring") Piavca::TrackMotion::setVecKeyframe "
void Piavca::TrackMotion::setVecKeyframe(int trackId, float time, Vec value)
         
set keyframe value (or create a new one) (only works for Vecs)         
         
        ";
%feature("docstring") Piavca::TrackMotion::setVecKeyframe "
void Piavca::TrackMotion::setVecKeyframe(int trackId, float time, Vec value, Vec velocity)
         
set keyframe value (or create a new one) with a user specified velocity (only works for Vecs)         
         
        ";
%feature("docstring") Piavca::TrackMotion::setQuatKeyframe "
void Piavca::TrackMotion::setQuatKeyframe(int trackId, float time, Quat value)
         
set keyframe value (or create a new one) (only works for Quats)         
         
        ";
%feature("docstring") Piavca::TrackMotion::setQuatKeyframe "
void Piavca::TrackMotion::setQuatKeyframe(int trackId, float time, Quat value, Quat velocity)
         
set keyframe value (or create a new one) with a user specified velocity (only works for Quats)         
         
        ";
%feature("docstring") Piavca::TrackMotion::getNumKeyframes "
int Piavca::TrackMotion::getNumKeyframes(int trackId)
         
returns the number of keyframes that a particular track has         
         
        ";
%feature("docstring") Piavca::TrackMotion::getKeyframeTime "
float Piavca::TrackMotion::getKeyframeTime(int trackId, int keyframe)
         
returns the time of a particular keyframe         
         
        ";
%feature("docstring") Piavca::TrackMotion::getFloatValueAtTimeInternal "
float Piavca::TrackMotion::getFloatValueAtTimeInternal(int trackId, float time)
         
get the keyframe value at time (only works for floats)         
         
        ";
%feature("docstring") Piavca::TrackMotion::getVecValueAtTimeInternal "
Vec Piavca::TrackMotion::getVecValueAtTimeInternal(int trackId, float time)
         
get the keyframe value at time (only works for Vecs)         
         
        ";
%feature("docstring") Piavca::TrackMotion::getQuatValueAtTimeInternal "
Quat Piavca::TrackMotion::getQuatValueAtTimeInternal(int trackId, float time)
         
get the keyframe value at time (only works for Quats)         
         
        ";
%feature("docstring") Piavca::TrackMotion::TrackMotion "
Piavca::TrackMotion::TrackMotion(tstring fileName, int flags=TRANS_NONE, Motion *basePosture=NULL)
         
create a motion object from a bvh motion data file.         
         
Pass in the file name and some flags that can perform some tweaks (see dscription of motion_corrections enum)         ";
%feature("docstring") Piavca::TrackMotion::TrackMotion "
Piavca::TrackMotion::TrackMotion(bool _facial=false)
         
default constructor, creates an empty motion         
         
        ";
%feature("docstring") Piavca::TrackMotion::TrackMotion "
TrackMotion::TrackMotion(MotionImp *_imp)
         
        
         
        ";
%feature("docstring") Piavca::TrackMotion::TrackMotion "
Piavca::TrackMotion::TrackMotion(const TrackMotion &mot)
         
copy constructor         
         
        ";
%feature("docstring") Piavca::TrackMotion::TrackMotion "
Piavca::TrackMotion::TrackMotion(Motion &mot)
         
copy constructor from any motion object         
         
The other motion object might not be a TrackMotion object and so might not consist of keyframe data, the new motion is sampled at regular intervals and the values saved as keyframes;         ";
%feature("docstring") Piavca::TrackMotion::~TrackMotion "
Piavca::TrackMotion::~TrackMotion()
         
        
         
        ";
%feature("docstring") Piavca::TrackMotion::clone "
virtual Motion* Piavca::TrackMotion::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") Piavca::TrackMotion::getMotionLength "
float Piavca::TrackMotion::getMotionLength() const 
         
gets the time of the last keyframe of the motion         
         
        ";
%feature("docstring") Piavca::TrackMotion::isFacial "
virtual bool Piavca::TrackMotion::isFacial()
         
whether it is a face or body motion         
         
        ";
%feature("docstring") Piavca::TrackMotion::isRandomAccess "
virtual bool Piavca::TrackMotion::isRandomAccess()
         
whether you can access a motions value at frames other than the current one         
         
        ";
%feature("docstring") Piavca::TrackMotion::isNull "
bool Piavca::TrackMotion::isNull(int trackId) const 
         
given a track ID tests whether it actually points to anything or if its null         
         
        ";
%feature("docstring") Piavca::TrackMotion::getTrackType "
trackType Piavca::TrackMotion::getTrackType(int trackId) const 
         
get the type of the track corresponding to a track ID         
         
        ";
%feature("docstring") Piavca::TrackMotion::deleteAllTracks "
void Piavca::TrackMotion::deleteAllTracks()
         
delete all tracks         
         
        ";
%feature("docstring") Piavca::TrackMotion::clearTrack "
void Piavca::TrackMotion::clearTrack(int trackId, bool createFirstFrame=true)
         
clears a particular track (deletes all keyframes without deleting the track itself)         
         
        ";
%feature("docstring") Piavca::TrackMotion::clearAllTracks "
void Piavca::TrackMotion::clearAllTracks(bool createFirstFrame=true)
         
clear all tracks (deletes all keyframes without deleting the tracks themselves)         
         
        ";
%feature("docstring") Piavca::TrackMotion::initMotion "
void TrackMotion::initMotion(tstring fileName, bool facial=false, int flags=0, Motion *basePosture=NULL)
         
initialise a Motion in a platform dependent way using the core         
         
        ";
%feature("docstring") Piavca::TurnMotion " 

turn a motion through a given rotation over the course of its run     
       
For now the turning method is pretty rubbish, just turning the root position and orientation.      see also: TurnMotion.h";

%feature("docstring") Piavca::TurnMotion::TurnMotion "
Piavca::TurnMotion::TurnMotion(Motion *m=NULL, Quat rot=Quat())
         
        
         
        ";
%feature("docstring") Piavca::TurnMotion::TurnMotion "
Piavca::TurnMotion::TurnMotion(const TurnMotion &tm)
         
        
         
        ";
%feature("docstring") Piavca::TurnMotion::clone "
virtual Motion* Piavca::TurnMotion::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") Piavca::TurnMotion::getFloatValueAtTimeInternal "
virtual PIAVCA_EXPORT float Piavca::TurnMotion::getFloatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") Piavca::TurnMotion::getVecValueAtTimeInternal "
virtual PIAVCA_EXPORT Vec Piavca::TurnMotion::getVecValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") Piavca::TurnMotion::getQuatValueAtTimeInternal "
virtual PIAVCA_EXPORT Quat Piavca::TurnMotion::getQuatValueAtTimeInternal(int trackId, float time)
         
calculates the values of a keyframe         
         
        ";
%feature("docstring") Piavca::TurnMotion::setRotation "
void Piavca::TurnMotion::setRotation(Quat rot)
         
        
         
        ";
%feature("docstring") Piavca::TwoMotionCombiner " 

A motion manipulator that combine two different motion.     
       
This class is an abstract base class that just provides some common features between motion filters. To actaully do anything you have to override the get[Float/Quat/Vec]ValueAtTime methods to perform whatever opertation you want on the two motion.      see also: TwoMotionCombiner.h";

%feature("docstring") Piavca::TwoMotionCombiner::TwoMotionCombiner "
TwoMotionCombiner::TwoMotionCombiner()
         
        
         
        ";
%feature("docstring") Piavca::TwoMotionCombiner::TwoMotionCombiner "
TwoMotionCombiner::TwoMotionCombiner(Motion *m1, Motion *m2)
         
        
         
Pass in the two motions you want to combine         ";
%feature("docstring") Piavca::TwoMotionCombiner::TwoMotionCombiner "
TwoMotionCombiner::TwoMotionCombiner(const TwoMotionCombiner &tmc)
         
        
         
        ";
%feature("docstring") Piavca::TwoMotionCombiner::~TwoMotionCombiner "
TwoMotionCombiner::~TwoMotionCombiner()
         
        
         
        ";
%feature("docstring") Piavca::TwoMotionCombiner::printInfo "
void TwoMotionCombiner::printInfo()
         
prints out info about the motion heirarchy         
         
        ";
%feature("docstring") Piavca::TwoMotionCombiner::findSub "
Motion * TwoMotionCombiner::findSub(tstring nm)
         
finds the first submotion with a given name         
         
        ";
%feature("docstring") Piavca::TwoMotionCombiner::findSubByType "
Motion * TwoMotionCombiner::findSubByType(const type_info &ty)
         
finds the first submotion with a given type         
         
        ";
%feature("docstring") Piavca::TwoMotionCombiner::load "
void TwoMotionCombiner::load(Avatar *av)
         
called when the motion is loaded into an avatar         
         
        ";
%feature("docstring") Piavca::TwoMotionCombiner::unload "
void TwoMotionCombiner::unload()
         
called when the motion is unloaded from an avatar         
         
        ";
%feature("docstring") Piavca::TwoMotionCombiner::loaded "
bool TwoMotionCombiner::loaded()
         
checks if the motion has been loaded into an avatar         
         
        ";
%feature("docstring") Piavca::TwoMotionCombiner::setStartTime "
void TwoMotionCombiner::setStartTime(float time)
         
sets the start time of the motion. Called when its loaded into an avatar.         
         
        ";
%feature("docstring") Piavca::TwoMotionCombiner::reset "
void TwoMotionCombiner::reset()
         
does any resetting needed         
         
        ";
%feature("docstring") Piavca::TwoMotionCombiner::getMotionLength "
float TwoMotionCombiner::getMotionLength() const 
         
gets the length of the combined motion (by default the length of the longer of the two)         
         
        ";
%feature("docstring") Piavca::TwoMotionCombiner::isFacial "
bool TwoMotionCombiner::isFacial()
         
whether it is a face or body motion         
         
        ";
%feature("docstring") Piavca::TwoMotionCombiner::isRandomAccess "
bool TwoMotionCombiner::isRandomAccess()
         
whether you can access a motions value at frames other than the current one         
         
        ";
%feature("docstring") Piavca::TwoMotionCombiner::isNull "
bool TwoMotionCombiner::isNull(int trackId) const 
         
given a track ID tests whether it actually points to anything or if its null         
         
is null if the track is null in both motions.         ";
%feature("docstring") Piavca::TwoMotionCombiner::getTrackType "
trackType TwoMotionCombiner::getTrackType(int trackId) const 
         
get the type of the track corresponding to an iterator         
         
        ";
%feature("docstring") Piavca::TwoMotionCombiner::setMotion1 "
void TwoMotionCombiner::setMotion1(Motion *mot)
         
        
         
        ";
%feature("docstring") Piavca::TwoMotionCombiner::setMotion2 "
void TwoMotionCombiner::setMotion2(Motion *mot)
         
        
         
        ";
%feature("docstring") Piavca::TwoMotionCombiner::getMotion1 "
Motion* Piavca::TwoMotionCombiner::getMotion1()
         
        
         
        ";
%feature("docstring") Piavca::TwoMotionCombiner::getMotion2 "
Motion* Piavca::TwoMotionCombiner::getMotion2()
         
        
         
        ";
%feature("docstring") Piavca::Vec " 

a vector class     
       
This should be a fairly standard implementation of 3-space vectors, with most normal operations. They are represented as an array of three floats.      see also: Vec.h";

%feature("docstring") Piavca::Vec::X "
float& Piavca::Vec::X()
         
        
         
        ";
%feature("docstring") Piavca::Vec::Y "
float& Piavca::Vec::Y()
         
        
         
        ";
%feature("docstring") Piavca::Vec::Z "
float& Piavca::Vec::Z()
         
        
         
        ";
%feature("docstring") Piavca::Vec::X "
const float& Piavca::Vec::X() const 
         
        
         
        ";
%feature("docstring") Piavca::Vec::Y "
const float& Piavca::Vec::Y() const 
         
        
         
        ";
%feature("docstring") Piavca::Vec::Z "
const float& Piavca::Vec::Z() const 
         
        
         
        ";
%feature("docstring") Piavca::Vec::inverse "
Vec Piavca::Vec::inverse() const 
         
        
         
returns the inverse of the vector while leaving it unchanged         ";
%feature("docstring") Piavca::Vec::invert "
void Piavca::Vec::invert()
         
inverts the vector in place         
         
        ";
%feature("docstring") Piavca::Vec::normalized "
Vec Piavca::Vec::normalized() const 
         
        
         
gets a normalized version of the Vec while leaving it unchanged         ";
%feature("docstring") Piavca::Vec::normalize "
void Piavca::Vec::normalize()
         
normalizes the Vec in place         
         
        ";
%feature("docstring") Piavca::Vec::XAxis "
static Vec Piavca::Vec::XAxis()
         
        
         
conveneience functions, get the axes         ";
%feature("docstring") Piavca::Vec::YAxis "
static Vec Piavca::Vec::YAxis()
         
        
         
        ";
%feature("docstring") Piavca::Vec::ZAxis "
static Vec Piavca::Vec::ZAxis()
         
        
         
        ";
%feature("docstring") Piavca::Vec::Vec "
Vec::Vec()
         
        
         
        ";
%feature("docstring") Piavca::Vec::Vec "
Vec::Vec(float x, float y, float z)
         
        
         
        ";
%feature("docstring") Piavca::Vec::Vec "
Vec::Vec(const float v[3])
         
        
         
        ";
%feature("docstring") Piavca::Vec::Vec "
Vec::Vec(const Vec &v)
         
        
         
        ";
%feature("docstring") Piavca::Vec::~Vec "
Vec::~Vec()
         
        
         
        ";
%feature("docstring") Piavca::Vec::mag "
float Vec::mag() const 
         
length of the vector         
         
        ";
%feature("docstring") Piavca::Vec::dot "
float Vec::dot(const Vec &v) const 
         
scalar (dot) product         
         
        ";
%feature("docstring") Piavca::Vec::cross "
Vec Vec::cross(const Vec &v) const 
         
vector (cross) product         
         
        ";
%feature("docstring") Piavca::Vec::crossinplace "
const Vec& Piavca::Vec::crossinplace(const Vec &v)
         
in place cross product         
         
        ";
%feature("docstring") Piavca::ZeroMotion " 

    
       
A motion class that makes the avatar look at a target. The avatar will turn to look at the given target with eyes, head, and body. The target can either be an avatar, an object or a vector location.      see also: ZeroMotion.h";

%feature("docstring") Piavca::ZeroMotion::ZeroMotion "
Piavca::ZeroMotion::ZeroMotion(bool _facial=false)
         
        
         
create with an avatar target. Pass in an avatar, and a joint of that avatar to look at         ";
%feature("docstring") Piavca::ZeroMotion::ZeroMotion "
Piavca::ZeroMotion::ZeroMotion(const ZeroMotion &zm)
         
        
         
        ";
%feature("docstring") Piavca::ZeroMotion::clone "
virtual Motion* Piavca::ZeroMotion::clone()
         
creates a copy of the motion         
         
        ";
%feature("docstring") Piavca::ZeroMotion::isFacial "
virtual bool Piavca::ZeroMotion::isFacial()
         
whether it is a face or body motion         
         
        ";
%feature("docstring") Piavca::ZeroMotion::isRandomAccess "
virtual bool Piavca::ZeroMotion::isRandomAccess()
         
whether you can access a motions value at frames other than the current one         
         
        ";
%feature("docstring") Piavca::ZeroMotion::getMotionLength "
virtual float Piavca::ZeroMotion::getMotionLength() const 
         
returns the length of the motion         
         
        ";
%feature("docstring") Piavca::ZeroMotion::isNull "
bool Piavca::ZeroMotion::isNull(int trackId) const 
         
given a track ID tests whether it actually points to anything or if its null         
         
        ";
%feature("docstring") Piavca::ZeroMotion::getTrackType "
virtual trackType Piavca::ZeroMotion::getTrackType(int trackId) const 
         
get the type of the track corresponding to an ID         
         
        ";
%feature("docstring") Piavca::ZeroMotion::getFloatValueAtTimeInternal "
virtual float Piavca::ZeroMotion::getFloatValueAtTimeInternal(int trackId, float time)
         
get the value of a track at a given time (only works for floats)         
         
        ";
%feature("docstring") Piavca::ZeroMotion::getVecValueAtTimeInternal "
virtual Vec Piavca::ZeroMotion::getVecValueAtTimeInternal(int trackId, float time)
         
get the value of a track at a given time (only works for Vecs)         
         
        ";
%feature("docstring") Piavca::ZeroMotion::getQuatValueAtTimeInternal "
virtual Quat Piavca::ZeroMotion::getQuatValueAtTimeInternal(int trackId, float time)
         
get the value of a track at a given time (only works for Quats)         
         
        ";
%feature("docstring") MyEngine " 

    
       
     see also: ";

%feature("docstring") Piavca " 

    
       
Functions for hermite interpolations.      see also: ";

%feature("docstring") Piavca::HermiteEvaluate "
float Piavca::HermiteEvaluate(float t, float length, float p0, float d0, float p1, float d1)
         
float hermite         
         
length is the length of time between the two successive keyframes. p0 and p1 are the two keyframes that bracket time t. d0 and d1 are the tangents (velocities) at these keyframes         ";
%feature("docstring") Piavca::HermiteEvaluate "
Vec Piavca::HermiteEvaluate(float t, float length, Vec p0, Vec d0, Vec p1, Vec d1)
         
Vec hermite.         
         
        ";
%feature("docstring") Piavca::HermiteEvaluate "
Quat Piavca::HermiteEvaluate(float t, float length, Quat p0, Quat d0, Quat p1, Quat d1)
         
Quat hermite.         
         
        ";
%feature("docstring") Piavca::checkNaN "
bool Piavca::checkNaN(float f)
         
        
         
        ";
%feature("docstring") Piavca::keyframeTangent "
T Piavca::keyframeTangent(T current, T prev, float prevTime, T next, float nextTime)
         
Calculates tangents for a hermite curve at the control points.         
         
The interpolation curves are piecewise hermite curves. This means that between two control points the curves are a cubic hermite curve. A hermite curve is defined by two control points which are the end points of the curve and the two tangents (velocities) at these end points. The keyframes give the successive control points of the motion curves but the tangents are also needed. They can be provided by the client but generally they will calculated automatically using this function. The method used is based on the average of the previous and successive keyframe. It is based on Catmull-Rom curves         ";
%feature("docstring") Piavca::keyframeTangent "
Quat Piavca::keyframeTangent(Quat current, Quat prev, float prevTime, Quat next, float nextTime)
         
A slightly different method is used for calculating tangents of quaternion curves.         
         
The maths is equivalent but it needs to be translated into quaternion speak         ";
%feature("docstring") Piavca::degToRad "
float Piavca::degToRad(float angle)
         
convert and angle in degrees to radians         
         
        ";
%feature("docstring") Piavca::radToDeg "
float Piavca::radToDeg(float angle)
         
convert and angle in radians to degrees         
         
        ";
%feature("docstring") Piavca::Error "
PIAVCA_DECL void Piavca::Error(tstring details)
         
        
         
        ";
%feature("docstring") Piavca::Warning "
PIAVCA_DECL void Piavca::Warning(tstring details)
         
        
         
        ";
%feature("docstring") Piavca::slerp "
PIAVCA_DECL Quat Piavca::slerp(const Quat &q1, const Quat &q2, float t)
         
        
         
        ";
%feature("docstring") Piavca::copyMotionPosture "
TrackMotion * Piavca::copyMotionPosture(Motion *mot, float time)
         
creates a Track Motion that is a copy of the given motion at a given time         
         
        ";
%feature("docstring") Piavca::checkNaN "
bool Piavca::checkNaN(Vec &v)
         
        
         
        ";
%feature("docstring") Piavca::PrintPythonErrors "
void Piavca::PrintPythonErrors()
         
        
         
        ";
%feature("docstring") Piavca::InitPiavcaPython "
void Piavca::InitPiavcaPython(Piavca::Core *core, tstring fileName)
         
        
         
        ";
%feature("docstring") Piavca::RunPythonMethod "
void Piavca::RunPythonMethod(Piavca::Core *core, char *methodName)
         
        
         
        ";
%feature("docstring") Piavca::EndPiavcaPython "
void Piavca::EndPiavcaPython(Piavca::Core *core)
         
        
         
        ";
%feature("docstring") Piavca::readBvhMotion "
void Piavca::readBvhMotion(Piavca::Core *core, MotionImp *mot, std::string fileName, int flags, Motion *basePosture=NULL, bool test=false)
         
        
         
        ";
