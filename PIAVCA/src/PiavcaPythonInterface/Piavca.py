# This file was created automatically by SWIG 1.3.27.
# Don't modify this file, modify the SWIG interface instead.

import _Piavca

# This file is compatible with both classic and new-style classes.
def _swig_setattr_nondynamic(self,class_type,name,value,static=1):
    if (name == "this"):
        if isinstance(value, class_type):
            self.__dict__[name] = value.this
            if hasattr(value,"thisown"): self.__dict__["thisown"] = value.thisown
            del value.thisown
            return
    method = class_type.__swig_setmethods__.get(name,None)
    if method: return method(self,value)
    if (not static) or hasattr(self,name) or (name == "thisown"):
        self.__dict__[name] = value
    else:
        raise AttributeError("You cannot add attributes to %s" % self)

def _swig_setattr(self,class_type,name,value):
    return _swig_setattr_nondynamic(self,class_type,name,value,0)

def _swig_getattr(self,class_type,name):
    method = class_type.__swig_getmethods__.get(name,None)
    if method: return method(self)
    raise AttributeError,name

import types
try:
    _object = types.ObjectType
    _newclass = 1
except AttributeError:
    class _object : pass
    _newclass = 0
del types


try:
    import weakref
    weakref_proxy = weakref.proxy
except:
    weakref_proxy = lambda x: x



GetAvatarPointer = _Piavca.GetAvatarPointer

GetPiavcaCorePointer = _Piavca.GetPiavcaCorePointer
class Vec(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Vec, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Vec, name)
    def __init__(self, *args):
        _swig_setattr(self, Vec, 'this', _Piavca.new_Vec(*args))
        _swig_setattr(self, Vec, 'thisown', 1)
    def __del__(self, destroy=_Piavca.delete_Vec):
        try:
            if self.thisown: destroy(self)
        except: pass

    def X(*args): return _Piavca.Vec_X(*args)
    def Y(*args): return _Piavca.Vec_Y(*args)
    def Z(*args): return _Piavca.Vec_Z(*args)
    __swig_getmethods__["XAxis"] = lambda x: _Piavca.Vec_XAxis
    if _newclass:XAxis = staticmethod(_Piavca.Vec_XAxis)
    __swig_getmethods__["YAxis"] = lambda x: _Piavca.Vec_YAxis
    if _newclass:YAxis = staticmethod(_Piavca.Vec_YAxis)
    __swig_getmethods__["ZAxis"] = lambda x: _Piavca.Vec_ZAxis
    if _newclass:ZAxis = staticmethod(_Piavca.Vec_ZAxis)
    def mag(*args): return _Piavca.Vec_mag(*args)
    def __add__(*args): return _Piavca.Vec___add__(*args)
    def __iadd__(*args): return _Piavca.Vec___iadd__(*args)
    def __sub__(*args): return _Piavca.Vec___sub__(*args)
    def __isub__(*args): return _Piavca.Vec___isub__(*args)
    def __neg__(*args): return _Piavca.Vec___neg__(*args)
    def __mul__(*args): return _Piavca.Vec___mul__(*args)
    def __imul__(*args): return _Piavca.Vec___imul__(*args)
    def __div__(*args): return _Piavca.Vec___div__(*args)
    def __idiv__(*args): return _Piavca.Vec___idiv__(*args)
    def __eq__(*args): return _Piavca.Vec___eq__(*args)
    def __ne__(*args): return _Piavca.Vec___ne__(*args)
    def inverse(*args): return _Piavca.Vec_inverse(*args)
    def invert(*args): return _Piavca.Vec_invert(*args)
    def dot(*args): return _Piavca.Vec_dot(*args)
    def cross(*args): return _Piavca.Vec_cross(*args)
    def crossinplace(*args): return _Piavca.Vec_crossinplace(*args)
    def normalized(*args): return _Piavca.Vec_normalized(*args)
    def normalize(*args): return _Piavca.Vec_normalize(*args)
    def __getitem__(*args): return _Piavca.Vec___getitem__(*args)
    def __setitem__(*args): return _Piavca.Vec___setitem__(*args)
    def __repr__(*args): return _Piavca.Vec___repr__(*args)

class VecPtr(Vec):
    def __init__(self, this):
        _swig_setattr(self, Vec, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, Vec, 'thisown', 0)
        self.__class__ = Vec
_Piavca.Vec_swigregister(VecPtr)

Vec_XAxis = _Piavca.Vec_XAxis

Vec_YAxis = _Piavca.Vec_YAxis

Vec_ZAxis = _Piavca.Vec_ZAxis


checkNaN = _Piavca.checkNaN
class Quat(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Quat, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Quat, name)
    def __init__(self, *args):
        _swig_setattr(self, Quat, 'this', _Piavca.new_Quat(*args))
        _swig_setattr(self, Quat, 'thisown', 1)
    def __del__(self, destroy=_Piavca.delete_Quat):
        try:
            if self.thisown: destroy(self)
        except: pass

    def S(*args): return _Piavca.Quat_S(*args)
    def I(*args): return _Piavca.Quat_I(*args)
    def J(*args): return _Piavca.Quat_J(*args)
    def K(*args): return _Piavca.Quat_K(*args)
    def setAngleAxis(*args): return _Piavca.Quat_setAngleAxis(*args)
    def getAngleAxis(*args): return _Piavca.Quat_getAngleAxis(*args)
    def getAngle(*args): return _Piavca.Quat_getAngle(*args)
    def getAxis(*args): return _Piavca.Quat_getAxis(*args)
    def getEulerAngles(*args): return _Piavca.Quat_getEulerAngles(*args)
    def Xangle(*args): return _Piavca.Quat_Xangle(*args)
    def Yangle(*args): return _Piavca.Quat_Yangle(*args)
    def Zangle(*args): return _Piavca.Quat_Zangle(*args)
    def pointAt(*args): return _Piavca.Quat_pointAt(*args)
    def __mul__(*args): return _Piavca.Quat___mul__(*args)
    def __imul__(*args): return _Piavca.Quat___imul__(*args)
    def __div__(*args): return _Piavca.Quat___div__(*args)
    def __idiv__(*args): return _Piavca.Quat___idiv__(*args)
    def __eq__(*args): return _Piavca.Quat___eq__(*args)
    def __ne__(*args): return _Piavca.Quat___ne__(*args)
    def Scale(*args): return _Piavca.Quat_Scale(*args)
    def inverse(*args): return _Piavca.Quat_inverse(*args)
    def invert(*args): return _Piavca.Quat_invert(*args)
    def normalise(*args): return _Piavca.Quat_normalise(*args)
    def transform(*args): return _Piavca.Quat_transform(*args)
    def transformInPlace(*args): return _Piavca.Quat_transformInPlace(*args)
    __swig_getmethods__["spherical_distance"] = lambda x: _Piavca.Quat_spherical_distance
    if _newclass:spherical_distance = staticmethod(_Piavca.Quat_spherical_distance)
    def __getitem__(*args): return _Piavca.Quat___getitem__(*args)
    def __setitem__(*args): return _Piavca.Quat___setitem__(*args)
    def __repr__(*args): return _Piavca.Quat___repr__(*args)

class QuatPtr(Quat):
    def __init__(self, this):
        _swig_setattr(self, Quat, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, Quat, 'thisown', 0)
        self.__class__ = Quat
_Piavca.Quat_swigregister(QuatPtr)

Quat_spherical_distance = _Piavca.Quat_spherical_distance

slerp = _Piavca.slerp

class TimeCallback(_object):
    """
    A callback that is called by the API every frame, the user writes code by creating a subclass of the callback.     
           
    The user can add data and implement the changeTime method (which is the one that is called everyframe). The callback system is currently under developement      see also: TimeCallback.h
    """
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, TimeCallback, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, TimeCallback, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::TimeCallback instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        """
        Piavca::TimeCallback::TimeCallback(tstring _name)
                 
                
                 
                
        """
        if self.__class__ == TimeCallback:
            args = (None,) + args
        else:
            args = (self,) + args
        _swig_setattr(self, TimeCallback, 'this', _Piavca.new_TimeCallback(*args))
        _swig_setattr(self, TimeCallback, 'thisown', 1)
    def __del__(self, destroy=_Piavca.delete_TimeCallback):
        """
        virtual Piavca::TimeCallback::~TimeCallback()
                 
                
                 
                
        """
        try:
            if self.thisown: destroy(self)
        except: pass

    def getName(*args):
        """
        tstring Piavca::TimeCallback::getName()
                 
                
                 
                
        """
        return _Piavca.TimeCallback_getName(*args)

    def init(*args):
        """
        virtual void Piavca::TimeCallback::init(Core *core)=0
                 
        This is a setup method for the callback.         
                 
        It's called when the callback is registered         
        """
        return _Piavca.TimeCallback_init(*args)

    def timeStep(*args):
        """
        virtual void Piavca::TimeCallback::timeStep(Core *core, float time)=0
                 
        implement this to make the callback do things         
                 
        It's called every frame with by the API         
        """
        return _Piavca.TimeCallback_timeStep(*args)

    def __disown__(self):
        self.thisown = 0
        _Piavca.disown_TimeCallback(self)
        return weakref_proxy(self)

class TimeCallbackPtr(TimeCallback):
    def __init__(self, this):
        _swig_setattr(self, TimeCallback, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, TimeCallback, 'thisown', 0)
        self.__class__ = TimeCallback
_Piavca.TimeCallback_swigregister(TimeCallbackPtr)

class AvatarTimeCallback(_object):
    """
    A callback that is called by the API every frame on an avatar.     
           
    It is very similar to the TimeCallback class but the changeTime method takes an avatar which can be updated.      see also: TimeCallback.h
    """
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, AvatarTimeCallback, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, AvatarTimeCallback, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::AvatarTimeCallback instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        """
        Piavca::AvatarTimeCallback::AvatarTimeCallback(tstring _name)
                 
                
                 
                
        """
        if self.__class__ == AvatarTimeCallback:
            args = (None,) + args
        else:
            args = (self,) + args
        _swig_setattr(self, AvatarTimeCallback, 'this', _Piavca.new_AvatarTimeCallback(*args))
        _swig_setattr(self, AvatarTimeCallback, 'thisown', 1)
    def __del__(self, destroy=_Piavca.delete_AvatarTimeCallback):
        """
        virtual Piavca::AvatarTimeCallback::~AvatarTimeCallback()
                 
                
                 
                
        """
        try:
            if self.thisown: destroy(self)
        except: pass

    def getName(*args):
        """
        tstring Piavca::AvatarTimeCallback::getName()
                 
                
                 
                
        """
        return _Piavca.AvatarTimeCallback_getName(*args)

    def init(*args):
        """
        virtual void Piavca::AvatarTimeCallback::init(Avatar *avatar)=0
                 
        This is a setup method for the callback.         
                 
        It's called when the callback is registered         
        """
        return _Piavca.AvatarTimeCallback_init(*args)

    def timeStep(*args):
        """
        virtual void Piavca::AvatarTimeCallback::timeStep(Avatar *avatar, float time)=0
                 
        implement this to make the callback do things         
                 
        It's called every frame with by the API which passes in the avatar to which the callback is attatched         
        """
        return _Piavca.AvatarTimeCallback_timeStep(*args)

    def __disown__(self):
        self.thisown = 0
        _Piavca.disown_AvatarTimeCallback(self)
        return weakref_proxy(self)

class AvatarTimeCallbackPtr(AvatarTimeCallback):
    def __init__(self, this):
        _swig_setattr(self, AvatarTimeCallback, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, AvatarTimeCallback, 'thisown', 0)
        self.__class__ = AvatarTimeCallback
_Piavca.AvatarTimeCallback_swigregister(AvatarTimeCallbackPtr)

class Core(_object):
    """
    The core object is the central controller of the Piavca system.     
           
    It maintains a list of avatars, and some motions. It has a list of global callbacks that are called every frame. It handles allocation of Joint IDs. It deals with initialisation and shut down and per frame events. It also manages creation of avatar and motions. There is only ever one core object (held as the core static member of the class).      see also: PiavcaCore.h
    """
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Core, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Core, name)
    def __init__(self): raise RuntimeError, "No constructor defined"
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::Core instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    __swig_setmethods__["dir"] = _Piavca.Core_dir_set
    __swig_getmethods__["dir"] = _Piavca.Core_dir_get
    if _newclass:dir = property(_Piavca.Core_dir_get, _Piavca.Core_dir_set)
    def __del__(self, destroy=_Piavca.delete_Core):
        """
        Core::~Core()
                 
                
                 
                
        """
        try:
            if self.thisown: destroy(self)
        except: pass

    def reset(*args):
        """
        void Core::reset()
                 
                
                 
                
        """
        return _Piavca.Core_reset(*args)

    def getCore(*args):
        """
        static Core* Piavca::Core::getCore()
                 
        a static function to get the core instances (there is only one)         
                 
                
        """
        return _Piavca.Core_getCore(*args)

    if _newclass:getCore = staticmethod(getCore)
    __swig_getmethods__["getCore"] = lambda x: getCore
    def registerCallback(*args):
        """
        void Core::registerCallback(TimeCallback *cb)
                 
        registers a callback to be called every frame         
                 
                
        """
        return _Piavca.Core_registerCallback(*args)

    def timeStep(*args):
        """
        void Core::timeStep(float time)
                 
                
                 
        Performs all per frame actions Can be run in parallel with the renderer.         
        """
        return _Piavca.Core_timeStep(*args)

    def prerender(*args):
        """
        void Core::prerender()
                 
        called before rendering (this cannot be called in parallel with the render)         
                 
                
        """
        return _Piavca.Core_prerender(*args)

    def render(*args):
        """
        void Core::render()
                 
        On certain platforms this needs to be called to render the avatars.         
                 
                
        """
        return _Piavca.Core_render(*args)

    def getJointId(*args):
        """
        int Core::getJointId(tstring name)
                 
                
                 
        methods dealing with joint ids get an id corresponding to a joint name         
        """
        return _Piavca.Core_getJointId(*args)

    def getMaxJointId(*args):
        """
        int Piavca::Core::getMaxJointId()
                 
        gets the maximum joint id         
                 
                
        """
        return _Piavca.Core_getMaxJointId(*args)

    def addJointNameSet(*args):
        """
        void Core::addJointNameSet(StringVector names)
                 
        Adds in a set of joints all of which should have the same id.         
                 
        i.e. all the names correspond to the same joint e.g. (left_foot, LFoot, LeftFoot, PiedGauche)         
        """
        return _Piavca.Core_addJointNameSet(*args)

    def getJointName(*args):
        """
        tstring Core::getJointName(int jointId)
                 
        returns a name corresponding to a track id (out of many possible)         
                 
                
        """
        return _Piavca.Core_getJointName(*args)

    def getJointNameAssociations(*args):
        """
        std::vector< std::pair< tstring, int > > Core::getJointNameAssociations()
                 
        get all the joint name associations         
                 
                
        """
        return _Piavca.Core_getJointNameAssociations(*args)

    def getExpressionId(*args):
        """
        int Core::getExpressionId(tstring name)
                 
                
                 
        methods dealing with expression ids get an id corresponding to an expression name         
        """
        return _Piavca.Core_getExpressionId(*args)

    def getMaxExpressionId(*args):
        """
        int Piavca::Core::getMaxExpressionId()
                 
        gets the maximum joint id         
                 
                
        """
        return _Piavca.Core_getMaxExpressionId(*args)

    def addExpressionNameSet(*args):
        """
        void Core::addExpressionNameSet(StringVector names)
                 
        Adds in a set of joints all of which should have the same id.         
                 
        i.e. all the names correspond to the same joint e.g. (left_foot, LFoot, LeftFoot, PiedGauche)         
        """
        return _Piavca.Core_addExpressionNameSet(*args)

    def getExpressionName(*args):
        """
        tstring Core::getExpressionName(int expressionId)
                 
        returns a name corresponding to a track id (out of many possible)         
                 
                
        """
        return _Piavca.Core_getExpressionName(*args)

    def getExpressionNameAssociations(*args):
        """
        std::vector< std::pair< tstring, int > > Core::getExpressionNameAssociations()
                 
        get all the expression name associations         
                 
                
        """
        return _Piavca.Core_getExpressionNameAssociations(*args)

    def loadMotion(*args):
        """
        void Core::loadMotion(tstring motionName, Motion *mot, bool temp=false, Motion *basePosture=NULL)
                 
        adds a motion to its list of motions         
                 
                
        """
        return _Piavca.Core_loadMotion(*args)

    def renameMotion(*args):
        """
        void Core::renameMotion(tstring oldName, tstring newName)
                 
        changes the name of a motion         
                 
                
        """
        return _Piavca.Core_renameMotion(*args)

    def unloadMotion(*args):
        """
        void Core::unloadMotion(tstring name)
                 
        removes the motion from the core and deletes it (NB difference to disposeMotion)         
                 
                
        """
        return _Piavca.Core_unloadMotion(*args)

    def getMotionNames(*args):
        """
        PIAVCA_EXPORT std::vector< std::string > Core::getMotionNames(int number=0)
                 
        get motion names         
                 
                
        """
        return _Piavca.Core_getMotionNames(*args)

    def getNumberOfMotions(*args):
        """
        int Piavca::Core::getNumberOfMotions()
                 
        get number of motions         
                 
                
        """
        return _Piavca.Core_getNumberOfMotions(*args)

    def getAllmotions(*args):
        """
        PIAVCA_EXPORT std::list< tstring > Core::getAllmotions()
                 
        get all motion names         
                 
                
        """
        return _Piavca.Core_getAllmotions(*args)

    def getMotion(*args):
        """
        Motion* Piavca::Core::getMotion(int i)
                 
        get a motion by its (arbitrary) index         
                 
                
        """
        return _Piavca.Core_getMotion(*args)

    def getAvatarNames(*args):
        """
        std::vector< tstring > Core::getAvatarNames()
                 
                
                 
                
        """
        return _Piavca.Core_getAvatarNames(*args)

    def numAvatars(*args):
        """
        int Piavca::Core::numAvatars()
                 
        get the number of avatars         
                 
                
        """
        return _Piavca.Core_numAvatars(*args)

    def getAvatar(*args):
        """
        Avatar * Core::getAvatar(int i)
                 
        get the ith avatar in the list (used for interating over all avatars)         
                 
                
        """
        return _Piavca.Core_getAvatar(*args)

    def renameAvatar(*args):
        """
        void Core::renameAvatar(tstring oldName, tstring newName)
                 
        changes the name of an avatar         
                 
                
        """
        return _Piavca.Core_renameAvatar(*args)

    def removeAvatar(*args):
        """
        void Core::removeAvatar(Avatar *avatar)
                 
        removes and avatar         
                 
                
        """
        return _Piavca.Core_removeAvatar(*args)

    def initAvatar(*args):
        """
        void Core::initAvatar(Avatar *avatar, tstring avatarId, bool bailOnMissedJoints=false, const Vec &Position=Vec(0.0, 0.0, 0.0), const Quat &Orientation=Quat(1.0, 0.0, 0.0, 0.0))
                 
        Initialises an avatar.         
                 
        You pass in a pointer to the avatar and an id with which to initialise it. It creates an implementation object which will actually be a platform dependant sub type of AvatarImp. It then sets some stuff up and stores a pointer to the avatar.         
        """
        return _Piavca.Core_initAvatar(*args)

    def numObjects(*args):
        """
        int Piavca::Core::numObjects()
                 
        get the number of avatars         
                 
                
        """
        return _Piavca.Core_numObjects(*args)

    def getObject(*args):
        """
        Object * Core::getObject(int i)
                 
        get the ith avatar in the list (used for interating over all avatars)         
                 
                
        """
        return _Piavca.Core_getObject(*args)

    def renameObject(*args):
        """
        void Core::renameObject(tstring oldName, tstring newName)
                 
        changes the name of an avatar         
                 
                
        """
        return _Piavca.Core_renameObject(*args)

    def removeObject(*args):
        """
        void Core::removeObject(Object *object)
                 
        removes and avatar         
                 
                
        """
        return _Piavca.Core_removeObject(*args)

    def initObject(*args):
        """
        void Core::initObject(Object *object, tstring objectId, const Vec &Position=Vec(0.0, 0.0, 0.0), const Quat &Orientation=Quat(1.0, 0.0, 0.0, 0.0))
                 
        Initialises an object.         
                 
        You pass in a pointer to the object and an id with which to initialise it. It creates an implementation object which will actually be a platform dependant sub type of ObjectImp. It then sets some stuff up and stores a pointer to the object.         
        """
        return _Piavca.Core_initObject(*args)

    def initMotion(*args):
        """
        void Core::initMotion(TrackMotion *mot, tstring filename=_PSTR(""), bool facial=false, int flags=0, Motion *basePosture=NULL)
                 
        Initialises a TrackMotion object.         
                 
        You pass in a pointer to the TrackMotion and a filename with which to initialise it. It creates an implementation object which will actually be a platform dependant sub type of MotionImp.         
        """
        return _Piavca.Core_initMotion(*args)

    def setDir(*args):
        """
        void Piavca::Core::setDir(tstring _dir)
                 
        set the search directory         
                 
                
        """
        return _Piavca.Core_setDir(*args)

    def getTime(*args):
        """
        float Piavca::Core::getTime()
                 
        get the current time in seconds         
                 
                
        """
        return _Piavca.Core_getTime(*args)

    def getSystemTime(*args):
        """
        virtual float Piavca::Core::getSystemTime()=0
                 
        get the current time in seconds         
                 
                
        """
        return _Piavca.Core_getSystemTime(*args)

    def setAutoTimeOff(*args):
        """
        void Piavca::Core::setAutoTimeOff()
                 
        turns off the automatic updating of the current time from the system clock         
                 
                
        """
        return _Piavca.Core_setAutoTimeOff(*args)

    def setAutoTimeOn(*args):
        """
        void Piavca::Core::setAutoTimeOn()
                 
        turns on the automatic updating of the current time from the system clock         
                 
                
        """
        return _Piavca.Core_setAutoTimeOn(*args)

    def setCurrentTime(*args):
        """
        void Piavca::Core::setCurrentTime(float t)
                 
        sets the current time (if its not linked to the system clock         
                 
                
        """
        return _Piavca.Core_setCurrentTime(*args)

    def addError(*args):
        """
        void Core::addError(tstring details)
                 
                
                 
                
        """
        return _Piavca.Core_addError(*args)

    def error(*args):
        """
        tostringstream& Piavca::Core::error()
                 
                
                 
                
        """
        return _Piavca.Core_error(*args)

    def clearErrors(*args):
        """
        void Core::clearErrors()
                 
                
                 
                
        """
        return _Piavca.Core_clearErrors(*args)

    def getErrors(*args):
        """
        tstring Piavca::Core::getErrors()
                 
                
                 
                
        """
        return _Piavca.Core_getErrors(*args)

    def errorsPresent(*args):
        """
        bool Piavca::Core::errorsPresent()
                 
                
                 
                
        """
        return _Piavca.Core_errorsPresent(*args)

    def addWarning(*args):
        """
        void Core::addWarning(tstring details)
                 
                
                 
                
        """
        return _Piavca.Core_addWarning(*args)

    def Warning(*args):
        """
        tostringstream& Piavca::Core::Warning()
                 
                
                 
                
        """
        return _Piavca.Core_Warning(*args)

    def clearWarnings(*args):
        """
        void Core::clearWarnings()
                 
                
                 
                
        """
        return _Piavca.Core_clearWarnings(*args)

    def getWarnings(*args):
        """
        tstring Piavca::Core::getWarnings()
                 
                
                 
                
        """
        return _Piavca.Core_getWarnings(*args)

    def warningsPresent(*args):
        """
        bool Piavca::Core::warningsPresent()
                 
                
                 
                
        """
        return _Piavca.Core_warningsPresent(*args)

    def exceptionsOn(*args):
        """
        bool Piavca::Core::exceptionsOn()
                 
                
                 
                
        """
        return _Piavca.Core_exceptionsOn(*args)

    def setExceptionsOn(*args):
        """
        void Piavca::Core::setExceptionsOn()
                 
                
                 
                
        """
        return _Piavca.Core_setExceptionsOn(*args)

    def setExceptionsOff(*args):
        """
        void Piavca::Core::setExceptionsOff()
                 
                
                 
                
        """
        return _Piavca.Core_setExceptionsOff(*args)

    def log(*args):
        """
        std::ostream& Piavca::Core::log()
                 
                
                 
                
        """
        return _Piavca.Core_log(*args)

    def addProfilePoint(*args):
        """
        int Piavca::Core::addProfilePoint(tstring name)
                 
                
                 
        creates a new profile point for logging profile data. Returns and id which can be used to access the profile point. You would normally create the point id as a static variable within the function you are profiling.         
        """
        return _Piavca.Core_addProfilePoint(*args)

    def profilePointStart(*args):
        """
        void Piavca::Core::profilePointStart(int i)
                 
        marks the start of a profile point         
                 
                
        """
        return _Piavca.Core_profilePointStart(*args)

    def profilePointEnd(*args):
        """
        void Piavca::Core::profilePointEnd(int i)
                 
        marks the end of the profile point         
                 
                
        """
        return _Piavca.Core_profilePointEnd(*args)

    def printProfileData(*args):
        """
        void Core::printProfileData()
                 
        prints out the profiling data that has been collected.         
                 
                
        """
        return _Piavca.Core_printProfileData(*args)


class CorePtr(Core):
    def __init__(self, this):
        _swig_setattr(self, Core, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, Core, 'thisown', 0)
        self.__class__ = Core
_Piavca.Core_swigregister(CorePtr)

def Core_getCore(*args):
    """
    static Core* Piavca::Core::getCore()
             
    a static function to get the core instances (there is only one)         
             
            
    """
    return _Piavca.Core_getCore(*args)


StringToWString = _Piavca.StringToWString

WStringToString = _Piavca.WStringToString
LOCAL_COORD = _Piavca.LOCAL_COORD
JOINTLOCAL_COORD = _Piavca.JOINTLOCAL_COORD
BASE_COORD = _Piavca.BASE_COORD
INCLUDINGBASE_COORD = _Piavca.INCLUDINGBASE_COORD
WORLD_COORD = _Piavca.WORLD_COORD
root_position_id = _Piavca.root_position_id
root_orientation_id = _Piavca.root_orientation_id
NULL_TYPE = _Piavca.NULL_TYPE
FLOAT_TYPE = _Piavca.FLOAT_TYPE
VEC_TYPE = _Piavca.VEC_TYPE
QUAT_TYPE = _Piavca.QUAT_TYPE
TRANS_NONE = _Piavca.TRANS_NONE
TRANS_SWAP_XZ = _Piavca.TRANS_SWAP_XZ
TRANS_SWAP_XY = _Piavca.TRANS_SWAP_XY
TRANS_SWAP_YZ = _Piavca.TRANS_SWAP_YZ
TRANS_CYCLE_YZX = _Piavca.TRANS_CYCLE_YZX
TRANS_CYCLE_ZXY = _Piavca.TRANS_CYCLE_ZXY
TRANS_NEG_X = _Piavca.TRANS_NEG_X
TRANS_NEG_Y = _Piavca.TRANS_NEG_Y
TRANS_NEG_Z = _Piavca.TRANS_NEG_Z
TRANS_ARM_UP = _Piavca.TRANS_ARM_UP
TRANS_ARM_DOWN = _Piavca.TRANS_ARM_DOWN
TRANS_REVERSE_ORDER = _Piavca.TRANS_REVERSE_ORDER
TRANS_SKIP_FIRST_FRAME = _Piavca.TRANS_SKIP_FIRST_FRAME
TRANS_NO_ROOT_POS_CORRECTION = _Piavca.TRANS_NO_ROOT_POS_CORRECTION
class Motion(_object):
    """
    An abstract interface to represent motion.     
           
    This is an abstract interface that represents all types of animation in a way that is independent of individual Avatars. It can be used to represent keyframe animation, motion combination, procedural animatio or real time animation streams. The key abstraction is that motion consists of a number of tracks, each normally corresponding to a joint of the avatar. The track is a continuous, time varying stream of data value (either of float, Vec or Quat type). The fundamental operation on a track is to query it for its value at a given time. Like joints tracks are represented by integer IDs, the IDs of a corresponding track and joint are the same so testing for equivelence is easy. Tracks are accessed by passing the appropriate ID to a method of the motion object.      see also: Motion.h
    """
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Motion, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Motion, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::Motion instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        """
        Piavca::Motion::Motion(const Motion &mot)
                 
                
                 
                
        """
        if self.__class__ == Motion:
            args = (None,) + args
        else:
            args = (self,) + args
        _swig_setattr(self, Motion, 'this', _Piavca.new_Motion(*args))
        _swig_setattr(self, Motion, 'thisown', 1)
    def __del__(self, destroy=_Piavca.delete_Motion):
        """
        virtual Piavca::Motion::~Motion()
                 
                
                 
                
        """
        try:
            if self.thisown: destroy(self)
        except: pass

    def clone(*args):
        """
        virtual Motion* Piavca::Motion::clone()=0
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca.Motion_clone(*args)

    def printInfo(*args):
        """
        void Motion::printInfo()
                 
        prints out info about the motion heirarchy         
                 
                
        """
        return _Piavca.Motion_printInfo(*args)

    def load(*args):
        """
        virtual void Piavca::Motion::load(Avatar *av)
                 
        called when the motion is loaded into an avatar         
                 
                
        """
        return _Piavca.Motion_load(*args)

    def unload(*args):
        """
        virtual void Piavca::Motion::unload()
                 
        called when the motion is unloaded from an avatar         
                 
                
        """
        return _Piavca.Motion_unload(*args)

    def loaded(*args):
        """
        virtual bool Piavca::Motion::loaded()
                 
        checks if the motion has been loaded into an avatar         
                 
                
        """
        return _Piavca.Motion_loaded(*args)

    def setStartTime(*args):
        """
        virtual void Piavca::Motion::setStartTime(float t)
                 
        sets the start time of the motion. Called when its loaded into an avatar.         
                 
                
        """
        return _Piavca.Motion_setStartTime(*args)

    def getStartTime(*args):
        """
        float Piavca::Motion::getStartTime()
                 
        return the start time of the motion         
                 
                
        """
        return _Piavca.Motion_getStartTime(*args)

    def getEndTime(*args):
        """
        float Piavca::Motion::getEndTime()
                 
        returns the end time of the motion         
                 
                
        """
        return _Piavca.Motion_getEndTime(*args)

    def reset(*args):
        """
        virtual void Piavca::Motion::reset()
                 
        does any resetting needed         
                 
                
        """
        return _Piavca.Motion_reset(*args)

    def Reference(*args):
        """
        void Piavca::Motion::Reference()
                 
        registers an owner for a motion, the motion will not be deleted until disposed is called.         
                 
        Internally this increments the reference count.         
        """
        return _Piavca.Motion_Reference(*args)

    def Dispose(*args):
        """
        void Motion::Dispose()
                 
        decrements the references count and deletes the motion if it reaches zero         
                 
                
        """
        return _Piavca.Motion_Dispose(*args)

    def makeTemp(*args):
        """
        void Piavca::Motion::makeTemp()
                 
        makes a motion temporary so that it is removed when all avatars have finished with it         
                 
                
        """
        return _Piavca.Motion_makeTemp(*args)

    def setName(*args):
        """
        void Piavca::Motion::setName(tstring nm)
                 
        gives a name to the motion         
                 
                
        """
        return _Piavca.Motion_setName(*args)

    def getName(*args):
        """
        tstring Piavca::Motion::getName()
                 
        returns the name of the motion         
                 
                
        """
        return _Piavca.Motion_getName(*args)

    def findSub(*args):
        """
        virtual Motion* Piavca::Motion::findSub(tstring nm)
                 
        finds the first submotion with a given name         
                 
                
        """
        return _Piavca.Motion_findSub(*args)

    def findSubByType(*args):
        """
        virtual Motion* Piavca::Motion::findSubByType(const type_info &ty)
                 
        finds the first submotion with a given type         
                 
                
        """
        return _Piavca.Motion_findSubByType(*args)

    def saveMotion(*args):
        """
        void Motion::saveMotion(tstring filename)
                 
        saves the motion to file in bvh format         
                 
                
        """
        return _Piavca.Motion_saveMotion(*args)

    def getMotionLength(*args):
        """
        virtual float Piavca::Motion::getMotionLength() const =0
                 
        gets the time of the end of the motion         
                 
        Though time is represented in floating point, keyframes can only be set as integers to avoid problems with rounding errors. The granularity is the conversion factor between the two.         
        """
        return _Piavca.Motion_getMotionLength(*args)

    def isFacial(*args):
        """
        virtual bool Piavca::Motion::isFacial()
                 
        whether it is a face or body motion         
                 
                
        """
        return _Piavca.Motion_isFacial(*args)

    def isRandomAccess(*args):
        """
        virtual bool Piavca::Motion::isRandomAccess()
                 
        whether you can access a motions value at frames other than the current one         
                 
                
        """
        return _Piavca.Motion_isRandomAccess(*args)

    def begin(*args):
        """
        int Piavca::Motion::begin() const 
                 
        the ID of the first track that is present in the motion (the ordering is arbitrary)         
                 
                
        """
        return _Piavca.Motion_begin(*args)

    def end(*args):
        """
        int Motion::end() const 
                 
        the last track + 1         
                 
                
        """
        return _Piavca.Motion_end(*args)

    def next(*args):
        """
        int Motion::next(int &trackId) const 
                 
        given a track ID get the next valid ID         
                 
                
        """
        return _Piavca.Motion_next(*args)

    def isNull(*args):
        """
        virtual bool Piavca::Motion::isNull(int trackId) const =0
                 
        given a track ID tests whether it actually points to anything or if its null         
                 
                
        """
        return _Piavca.Motion_isNull(*args)

    def getTrackType(*args):
        """
        virtual trackType Piavca::Motion::getTrackType(int trackId) const =0
                 
        get the type of the track corresponding to an ID         
                 
                
        """
        return _Piavca.Motion_getTrackType(*args)

    def pause(*args):
        """
        void Motion::pause()
                 
        pause the motion so that it can be restarted from the current point         
                 
                
        """
        return _Piavca.Motion_pause(*args)

    def unpause(*args):
        """
        void Motion::unpause()
                 
                
                 
                
        """
        return _Piavca.Motion_unpause(*args)

    def getFloatValueAtTime(*args):
        """
        float Piavca::Motion::getFloatValueAtTime(int trackId, float time)
                 
        get the value of a track at a given time (only works for floats)         
                 
                
        """
        return _Piavca.Motion_getFloatValueAtTime(*args)

    def getVecValueAtTime(*args):
        """
        Vec Piavca::Motion::getVecValueAtTime(int trackId, float time)
                 
        get the value of a track at a given time (only works for Vecs)         
                 
                
        """
        return _Piavca.Motion_getVecValueAtTime(*args)

    def getQuatValueAtTime(*args):
        """
        Quat Piavca::Motion::getQuatValueAtTime(int trackId, float time)
                 
        get the value of a track at a given time (only works for Quats)         
                 
                
        """
        return _Piavca.Motion_getQuatValueAtTime(*args)

    def getFloatValueAtTimeInternal(*args):
        """
        virtual float Piavca::Motion::getFloatValueAtTimeInternal(int trackId, float time)=0
                 
        internal version of getFloatValueAtTime, to be overridden         
                 
                
        """
        return _Piavca.Motion_getFloatValueAtTimeInternal(*args)

    def getVecValueAtTimeInternal(*args):
        """
        virtual Vec Piavca::Motion::getVecValueAtTimeInternal(int trackId, float time)=0
                 
        internal version of getVecValueAtTime, to be overridden         
                 
                
        """
        return _Piavca.Motion_getVecValueAtTimeInternal(*args)

    def getQuatValueAtTimeInternal(*args):
        """
        virtual Quat Piavca::Motion::getQuatValueAtTimeInternal(int trackId, float time)=0
                 
        internal version of getQuatValueAtTime, to be overridden         
                 
                
        """
        return _Piavca.Motion_getQuatValueAtTimeInternal(*args)

    def __disown__(self):
        self.thisown = 0
        _Piavca.disown_Motion(self)
        return weakref_proxy(self)

class MotionPtr(Motion):
    def __init__(self, this):
        _swig_setattr(self, Motion, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, Motion, 'thisown', 0)
        self.__class__ = Motion
_Piavca.Motion_swigregister(MotionPtr)

class TrackMotion(Motion):
    """
    A specialisation of the Motion Interface to deal with keyframe motion data.     
           
    Motion data can be read in from a bvh file. The actual underlying representation of the motion is forwarded to an implementation class (MotionImp) so that it can be implemented differently on different platforms if there are more efficient methods (a default implementatio is provided). Track motion provide the ability to create tracks and store data to them, if you want to create mtoion data on the fly. You can also cache the values of another motion object and save it as keyframe data.      see also: TrackMotion.h
    """
    __swig_setmethods__ = {}
    for _s in [Motion]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, TrackMotion, name, value)
    __swig_getmethods__ = {}
    for _s in [Motion]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, TrackMotion, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::TrackMotion instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        """
        Piavca::TrackMotion::TrackMotion(Motion &mot)
                 
        copy constructor from any motion object         
                 
        The other motion object might not be a TrackMotion object and so might not consist of keyframe data, the new motion is sampled at regular intervals and the values saved as keyframes;         
        """
        if self.__class__ == TrackMotion:
            args = (None,) + args
        else:
            args = (self,) + args
        _swig_setattr(self, TrackMotion, 'this', _Piavca.new_TrackMotion(*args))
        _swig_setattr(self, TrackMotion, 'thisown', 1)
    def __del__(self, destroy=_Piavca.delete_TrackMotion):
        """
        Piavca::TrackMotion::~TrackMotion()
                 
                
                 
                
        """
        try:
            if self.thisown: destroy(self)
        except: pass

    def clone(*args):
        """
        virtual Motion* Piavca::TrackMotion::clone()
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca.TrackMotion_clone(*args)

    def getMotionLength(*args):
        """
        float Piavca::TrackMotion::getMotionLength() const 
                 
        gets the time of the last keyframe of the motion         
                 
                
        """
        return _Piavca.TrackMotion_getMotionLength(*args)

    def isFacial(*args):
        """
        virtual bool Piavca::TrackMotion::isFacial()
                 
        whether it is a face or body motion         
                 
                
        """
        return _Piavca.TrackMotion_isFacial(*args)

    def isRandomAccess(*args):
        """
        virtual bool Piavca::TrackMotion::isRandomAccess()
                 
        whether you can access a motions value at frames other than the current one         
                 
                
        """
        return _Piavca.TrackMotion_isRandomAccess(*args)

    def isNull(*args):
        """
        bool Piavca::TrackMotion::isNull(int trackId) const 
                 
        given a track ID tests whether it actually points to anything or if its null         
                 
                
        """
        return _Piavca.TrackMotion_isNull(*args)

    def getTrackType(*args):
        """
        trackType Piavca::TrackMotion::getTrackType(int trackId) const 
                 
        get the type of the track corresponding to a track ID         
                 
                
        """
        return _Piavca.TrackMotion_getTrackType(*args)

    def addFloatTrack(*args):
        """
        void Piavca::TrackMotion::addFloatTrack(int trackId, float initialValue)
                 
        add a float track         
                 
                
        """
        return _Piavca.TrackMotion_addFloatTrack(*args)

    def addVecTrack(*args):
        """
        void Piavca::TrackMotion::addVecTrack(int trackId, const Vec &initialValue)
                 
        add a Vec track         
                 
                
        """
        return _Piavca.TrackMotion_addVecTrack(*args)

    def addQuatTrack(*args):
        """
        void Piavca::TrackMotion::addQuatTrack(int trackId, const Quat &initialValue)
                 
        add a Quat track         
                 
                
        """
        return _Piavca.TrackMotion_addQuatTrack(*args)

    def setFloatKeyframe(*args):
        """
        void Piavca::TrackMotion::setFloatKeyframe(int trackId, float time, float value, float velocity)
                 
        set keyframe value (or create a new one) with a user specified velocity (only works for floats)         
                 
                
        """
        return _Piavca.TrackMotion_setFloatKeyframe(*args)

    def setVecKeyframe(*args):
        """
        void Piavca::TrackMotion::setVecKeyframe(int trackId, float time, Vec value, Vec velocity)
                 
        set keyframe value (or create a new one) with a user specified velocity (only works for Vecs)         
                 
                
        """
        return _Piavca.TrackMotion_setVecKeyframe(*args)

    def setQuatKeyframe(*args):
        """
        void Piavca::TrackMotion::setQuatKeyframe(int trackId, float time, Quat value, Quat velocity)
                 
        set keyframe value (or create a new one) with a user specified velocity (only works for Quats)         
                 
                
        """
        return _Piavca.TrackMotion_setQuatKeyframe(*args)

    def getNumKeyframes(*args):
        """
        int Piavca::TrackMotion::getNumKeyframes(int trackId)
                 
        returns the number of keyframes that a particular track has         
                 
                
        """
        return _Piavca.TrackMotion_getNumKeyframes(*args)

    def getKeyframeTime(*args):
        """
        float Piavca::TrackMotion::getKeyframeTime(int trackId, int keyframe)
                 
        returns the time of a particular keyframe         
                 
                
        """
        return _Piavca.TrackMotion_getKeyframeTime(*args)

    def getFloatValueAtTimeInternal(*args):
        """
        float Piavca::TrackMotion::getFloatValueAtTimeInternal(int trackId, float time)
                 
        get the keyframe value at time (only works for floats)         
                 
                
        """
        return _Piavca.TrackMotion_getFloatValueAtTimeInternal(*args)

    def getVecValueAtTimeInternal(*args):
        """
        Vec Piavca::TrackMotion::getVecValueAtTimeInternal(int trackId, float time)
                 
        get the keyframe value at time (only works for Vecs)         
                 
                
        """
        return _Piavca.TrackMotion_getVecValueAtTimeInternal(*args)

    def getQuatValueAtTimeInternal(*args):
        """
        Quat Piavca::TrackMotion::getQuatValueAtTimeInternal(int trackId, float time)
                 
        get the keyframe value at time (only works for Quats)         
                 
                
        """
        return _Piavca.TrackMotion_getQuatValueAtTimeInternal(*args)

    def deleteAllTracks(*args):
        """
        void Piavca::TrackMotion::deleteAllTracks()
                 
        delete all tracks         
                 
                
        """
        return _Piavca.TrackMotion_deleteAllTracks(*args)

    def clearTrack(*args):
        """
        void Piavca::TrackMotion::clearTrack(int trackId, bool createFirstFrame=true)
                 
        clears a particular track (deletes all keyframes without deleting the track itself)         
                 
                
        """
        return _Piavca.TrackMotion_clearTrack(*args)

    def clearAllTracks(*args):
        """
        void Piavca::TrackMotion::clearAllTracks(bool createFirstFrame=true)
                 
        clear all tracks (deletes all keyframes without deleting the tracks themselves)         
                 
                
        """
        return _Piavca.TrackMotion_clearAllTracks(*args)

    def __disown__(self):
        self.thisown = 0
        _Piavca.disown_TrackMotion(self)
        return weakref_proxy(self)

class TrackMotionPtr(TrackMotion):
    def __init__(self, this):
        _swig_setattr(self, TrackMotion, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, TrackMotion, 'thisown', 0)
        self.__class__ = TrackMotion
_Piavca.TrackMotion_swigregister(TrackMotionPtr)


def copyMotionPosture(*args):
    """
    TrackMotion * Piavca::copyMotionPosture(Motion *mot, float time)
             
    creates a Track Motion that is a copy of the given motion at a given time         
             
            
    """
    return _Piavca.copyMotionPosture(*args)
class Avatar(_object):
    """
    The actual avatar class.     
           
    This class is the main component of the Piavca API and represents a character for skeletal animation. It has fairly basic simple functionality, just altering root position and orientation, loading and playing motion and directly altering joint orientations It is an interfaces class that forwards all its method calls to an implementation class which is an platform specific class that does all the work. The class is structured as a bridge pattern from Design Patterns. An interface class contains a pointer to an implementation object and forwards all method calls to it. The implementation object is in fact of a platform specific sub-type of the implementation class. The joints themselves are not exposed to the client and are accessed via integer IDs. These IDs are unique for a given joint across all avatars and motions. any actions on joints area achieved by passing the ID to an appropriate method      see also: Avatar.h
    """
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Avatar, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Avatar, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::Avatar instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        """
        Avatar::Avatar(tstring avatarId, bool bailOnMissedJoints=false, const Vec &Position=Vec(0.0, 0.0, 0.0), const Quat &Orientation=Quat(1.0, 0.0, 0.0, 0.0), const Vec &forwardDir=Vec(0.0, 0.0, 1.0))
                 
        create an avatar         
                 
        The avatar needs to be initialised with an implementation. The type of the implementation depends on the platform and so it cannot be created directly in platform independant code. To get around this it is created by a static factory method in the which itself uses the Piavca::Core class and its platform dependent implementation to create the implementation of the avatar. The constructor needs an identifier string that it uses to find platform specific data needed to create the avatar, for example the mesh file. The user can also pass in a position and orientation for the avatar. If bail on missed joints is true it will fail to create the avatar if not all the needed joints are present in the model and will result in an invalid avatar (this can be tested with the isValid method).         
        """
        _swig_setattr(self, Avatar, 'this', _Piavca.new_Avatar(*args))
        _swig_setattr(self, Avatar, 'thisown', 1)
    def isValid(*args):
        """
        bool Piavca::Avatar::isValid()
                 
        set the current piavca core object         
                 
                
        """
        return _Piavca.Avatar_isValid(*args)

    def activate(*args):
        """
        void Avatar::activate()
                 
        turn on updates on the avatar         
                 
                
        """
        return _Piavca.Avatar_activate(*args)

    def deactivate(*args):
        """
        void Avatar::deactivate()
                 
        turn off updates on the avatar         
                 
                
        """
        return _Piavca.Avatar_deactivate(*args)

    def getName(*args):
        """
        tstring Piavca::Avatar::getName()
                 
        get the name of the avatar         
                 
                
        """
        return _Piavca.Avatar_getName(*args)

    def setName(*args):
        """
        tstring Piavca::Avatar::setName(tstring newName)
                 
        set the name of the avatar         
                 
                
        """
        return _Piavca.Avatar_setName(*args)

    def getForwardDirection(*args):
        """
        const Vec& Piavca::Avatar::getForwardDirection()
                 
        returns the local direction at which the avatar points forward         
                 
                
        """
        return _Piavca.Avatar_getForwardDirection(*args)

    def setForwardDirection(*args):
        """
        void Piavca::Avatar::setForwardDirection(const Vec &dir)
                 
        sets the local direction at which the avatar points forward         
                 
                
        """
        return _Piavca.Avatar_setForwardDirection(*args)

    def clearFacialExpressionWeights(*args):
        """
        void Piavca::Avatar::clearFacialExpressionWeights()
                 
        set all expression weights to zero         
                 
                
        """
        return _Piavca.Avatar_clearFacialExpressionWeights(*args)

    def beginExpression(*args):
        """
        int Piavca::Avatar::beginExpression() const 
                 
        the ID of the first joint that is present in the avatar (the ordering is arbitrary)         
                 
                
        """
        return _Piavca.Avatar_beginExpression(*args)

    def endExpression(*args):
        """
        int Avatar::endExpression() const 
                 
        the last joint + 1         
                 
                
        """
        return _Piavca.Avatar_endExpression(*args)

    def nextExpression(*args):
        """
        int Avatar::nextExpression(int &expressionId)
                 
        given a joint ID this returns the next joint ID that is present in the avatar         
                 
                
        """
        return _Piavca.Avatar_nextExpression(*args)

    def isExpressionNull(*args):
        """
        bool Piavca::Avatar::isExpressionNull(int expressionId) const 
                 
        whether the joint is present in the avatar         
                 
                
        """
        return _Piavca.Avatar_isExpressionNull(*args)

    def setRootPosition(*args):
        """
        void Piavca::Avatar::setRootPosition(const Vec &Position)
                 
                
                 
        get or set the root position and orientation of the avatar         
        """
        return _Piavca.Avatar_setRootPosition(*args)

    def getRootPosition(*args):
        """
        Vec Piavca::Avatar::getRootPosition()
                 
                
                 
                
        """
        return _Piavca.Avatar_getRootPosition(*args)

    def setRootOrientation(*args):
        """
        void Piavca::Avatar::setRootOrientation(const Quat &Orientation)
                 
                
                 
                
        """
        return _Piavca.Avatar_setRootOrientation(*args)

    def setRootAngle(*args):
        """
        void Piavca::Avatar::setRootAngle(float angle)
                 
        set the root orientation from an angle in radians (assumed to be about the verticle)         
                 
                
        """
        return _Piavca.Avatar_setRootAngle(*args)

    def setRootAngleDeg(*args):
        """
        void Piavca::Avatar::setRootAngleDeg(float angle)
                 
        set the root orientation from an angle in degrees (assumed to be about the verticle)         
                 
                
        """
        return _Piavca.Avatar_setRootAngleDeg(*args)

    def getRootOrientation(*args):
        """
        Quat Piavca::Avatar::getRootOrientation()
                 
                
                 
                
        """
        return _Piavca.Avatar_getRootOrientation(*args)

    def createJoint(*args):
        """
        bool Piavca::Avatar::createJoint(tstring jointName)
                 
        creates a new joint         
                 
        It will only succeed if there is a piece of geometry corresponding to the name if not it returns false.         
        """
        return _Piavca.Avatar_createJoint(*args)

    def begin(*args):
        """
        int Piavca::Avatar::begin() const 
                 
        the ID of the first joint that is present in the avatar (the ordering is arbitrary)         
                 
                
        """
        return _Piavca.Avatar_begin(*args)

    def end(*args):
        """
        int Avatar::end() const 
                 
        the last joint + 1         
                 
                
        """
        return _Piavca.Avatar_end(*args)

    def next(*args):
        """
        int Avatar::next(int &jointId)
                 
        given a joint ID this returns the next joint ID that is present in the avatar         
                 
                
        """
        return _Piavca.Avatar_next(*args)

    def getParent(*args):
        """
        int Piavca::Avatar::getParent(int jointId) const 
                 
        returns the ID of the parent of the joint in the joint heirarchy (or a negative value if it doesn't exist         
                 
                
        """
        return _Piavca.Avatar_getParent(*args)

    def getJointName(*args):
        """
        const tstring Piavca::Avatar::getJointName(int jointId)
                 
        get the name of the joint corresponding to an ID         
                 
                
        """
        return _Piavca.Avatar_getJointName(*args)

    def isNull(*args):
        """
        bool Piavca::Avatar::isNull(int jointId) const 
                 
        whether the joint is present in the avatar         
                 
                
        """
        return _Piavca.Avatar_isNull(*args)

    def hasChanged(*args):
        """
        bool Piavca::Avatar::hasChanged(int jointId)
                 
        check whether the joint has been changed by user input         
                 
                
        """
        return _Piavca.Avatar_hasChanged(*args)

    def clearChange(*args):
        """
        void Piavca::Avatar::clearChange(int jointId)
                 
        clears the changed flag for the joint         
                 
                
        """
        return _Piavca.Avatar_clearChange(*args)

    def scaleRoot(*args):
        """
        void Piavca::Avatar::scaleRoot(Vec scale)
                 
        scales the root by a non-uniform scale vector         
                 
                
        """
        return _Piavca.Avatar_scaleRoot(*args)

    def scaleJoint(*args):
        """
        void Piavca::Avatar::scaleJoint(int jointId, Vec scale)
                 
        scales a joint by a non-uniform scale vector         
                 
                
        """
        return _Piavca.Avatar_scaleJoint(*args)

    def timeStep(*args):
        """
        void Avatar::timeStep(float time)
                 
        set the current time         
                 
        This is used for animation, it sets the time within the current piece of motion and puts the avatar in the correct position for that motion at that time         
        """
        return _Piavca.Avatar_timeStep(*args)

    def loadMotion(*args):
        """
        void Avatar::loadMotion(Motion *motion)
                 
        load motion as a motion object         
                 
        The start time allows the client to specify a time in world time for the motion to start running         
        """
        return _Piavca.Avatar_loadMotion(*args)

    def unloadMotion(*args):
        """
        void Avatar::unloadMotion()
                 
                
                 
                
        """
        return _Piavca.Avatar_unloadMotion(*args)

    def getMotion(*args):
        """
        const Motion* Piavca::Avatar::getMotion() const 
                 
        get a const pointer to the motion so it can be seen by the client         
                 
                
        """
        return _Piavca.Avatar_getMotion(*args)

    def playMotion(*args):
        """
        void Avatar::playMotion(Motion *m)
                 
                
                 
                
        """
        return _Piavca.Avatar_playMotion(*args)

    def playMotionDirect(*args):
        """
        void Avatar::playMotion(Motion *m)
                 
                
                 
                
        """
        return _Piavca.Avatar_playMotionDirect(*args)

    def stopMotion(*args):
        """
        void Piavca::Avatar::stopMotion()
                 
        stops the motion playing         
                 
                
        """
        return _Piavca.Avatar_stopMotion(*args)

    def restartMotion(*args):
        """
        void Piavca::Avatar::restartMotion()
                 
        restarts the motion without changing the start time         
                 
                
        """
        return _Piavca.Avatar_restartMotion(*args)

    def setMotionStartTime(*args):
        """
        void Avatar::setMotionStartTime(float startTime)
                 
        changes the start time of the motion         
                 
                
        """
        return _Piavca.Avatar_setMotionStartTime(*args)

    def getMotionStartTime(*args):
        """
        float Avatar::getMotionStartTime()
                 
        get the time when the current motion starts         
                 
                
        """
        return _Piavca.Avatar_getMotionStartTime(*args)

    def getMotionEndTime(*args):
        """
        float Avatar::getMotionEndTime()
                 
        get the time when the current motion should end         
                 
                
        """
        return _Piavca.Avatar_getMotionEndTime(*args)

    def showMotionAtTime(*args):
        """
        void Avatar::showMotionAtTime(float time)
                 
        displays the motion on the avatar at time         
                 
                
        """
        return _Piavca.Avatar_showMotionAtTime(*args)

    def loadFacialMotion(*args):
        """
        void Avatar::loadFacialMotion(Motion *motion)
                 
        load a facial motion as a motion object         
                 
        The start time allows the client to specify a time in world time for the motion to start running         
        """
        return _Piavca.Avatar_loadFacialMotion(*args)

    def unloadFacialMotion(*args):
        """
        void Avatar::unloadFacialMotion()
                 
                
                 
                
        """
        return _Piavca.Avatar_unloadFacialMotion(*args)

    def getFacialMotion(*args):
        """
        const Motion* Piavca::Avatar::getFacialMotion() const 
                 
        get a const pointer to the motion so it can be seen by the client         
                 
                
        """
        return _Piavca.Avatar_getFacialMotion(*args)

    def playFacialMotion(*args):
        """
        void Avatar::playFacialMotion(Motion *m)
                 
        starts playing the motion at the current time         
                 
                
        """
        return _Piavca.Avatar_playFacialMotion(*args)

    def stopFacialMotion(*args):
        """
        void Piavca::Avatar::stopFacialMotion()
                 
        stops the motion playing         
                 
                
        """
        return _Piavca.Avatar_stopFacialMotion(*args)

    def restartFacialMotion(*args):
        """
        void Piavca::Avatar::restartFacialMotion()
                 
        restarts the motion without changing the start time         
                 
                
        """
        return _Piavca.Avatar_restartFacialMotion(*args)

    def setFacialMotionStartTime(*args):
        """
        void Avatar::setFacialMotionStartTime(float startTime)
                 
        changes the start time of the motion         
                 
                
        """
        return _Piavca.Avatar_setFacialMotionStartTime(*args)

    def getFacialMotionStartTime(*args):
        """
        float Avatar::getFacialMotionStartTime()
                 
        get the time when the current motion starts         
                 
                
        """
        return _Piavca.Avatar_getFacialMotionStartTime(*args)

    def getFacialMotionEndTime(*args):
        """
        float Avatar::getFacialMotionEndTime()
                 
        get the time when the current motion should end         
                 
                
        """
        return _Piavca.Avatar_getFacialMotionEndTime(*args)

    def showFacialMotionAtTime(*args):
        """
        void Avatar::showFacialMotionAtTime(float time)
                 
        displays the motion on the avatar at time         
                 
                
        """
        return _Piavca.Avatar_showFacialMotionAtTime(*args)

    def loadScaleMotion(*args):
        """
        void Avatar::loadScaleMotion(Motion *motion)
                 
        load a scale motion as a motion object         
                 
        The start time allows the client to specify a time in world time for the motion to start running         
        """
        return _Piavca.Avatar_loadScaleMotion(*args)

    def unloadScaleMotion(*args):
        """
        void Avatar::unloadScaleMotion()
                 
                
                 
                
        """
        return _Piavca.Avatar_unloadScaleMotion(*args)

    def getScaleMotion(*args):
        """
        const Motion* Piavca::Avatar::getScaleMotion() const 
                 
        get a const pointer to the motion so it can be seen by the client         
                 
                
        """
        return _Piavca.Avatar_getScaleMotion(*args)

    def playScaleMotion(*args):
        """
        void Avatar::playScaleMotion(Motion *m)
                 
        starts playing the motion at the current time         
                 
                
        """
        return _Piavca.Avatar_playScaleMotion(*args)

    def stopScaleMotion(*args):
        """
        void Piavca::Avatar::stopScaleMotion()
                 
        stops the motion playing         
                 
                
        """
        return _Piavca.Avatar_stopScaleMotion(*args)

    def restartScaleMotion(*args):
        """
        void Piavca::Avatar::restartScaleMotion()
                 
        restarts the motion without changing the start time         
                 
                
        """
        return _Piavca.Avatar_restartScaleMotion(*args)

    def setScaleMotionStartTime(*args):
        """
        void Avatar::setScaleMotionStartTime(float startTime)
                 
        changes the start time of the motion         
                 
                
        """
        return _Piavca.Avatar_setScaleMotionStartTime(*args)

    def getScaleMotionStartTime(*args):
        """
        float Avatar::getScaleMotionStartTime()
                 
        get the time when the current motion starts         
                 
                
        """
        return _Piavca.Avatar_getScaleMotionStartTime(*args)

    def getScaleMotionEndTime(*args):
        """
        float Avatar::getScaleMotionEndTime()
                 
        get the time when the current motion should end         
                 
                
        """
        return _Piavca.Avatar_getScaleMotionEndTime(*args)

    def showScaleMotionAtTime(*args):
        """
        void Avatar::showScaleMotionAtTime(float time)
                 
        displays the motion on the avatar at time         
                 
                
        """
        return _Piavca.Avatar_showScaleMotionAtTime(*args)

    def registerCallback(*args):
        """
        void Avatar::registerCallback(AvatarTimeCallback *cb)
                 
        registers a callback so that it is called on the avatar every frame         
                 
                
        """
        return _Piavca.Avatar_registerCallback(*args)

    def removeCallback(*args):
        """
        void Avatar::removeCallback(tstring cbName)
                 
        deletes a callback         
                 
                
        """
        return _Piavca.Avatar_removeCallback(*args)

    def getNumCallbacks(*args):
        """
        int Avatar::getNumCallbacks()
                 
        gets the number of registered callbacks (for iterating through them)         
                 
                
        """
        return _Piavca.Avatar_getNumCallbacks(*args)

    def getCallback(*args):
        """
        AvatarTimeCallback * Avatar::getCallback(int i)
                 
        get a callback based on its index (the indeces are arbitrary this is just useful for finding a callback)         
                 
                
        """
        return _Piavca.Avatar_getCallback(*args)

    def setFacialExpressionWeight(*args):
        """
        bool Piavca::Avatar::setFacialExpressionWeight(int id, float weight, float timeInterval=0.5)
                 
        set the weight of a facial expression (used in the blend)         
                 
                
        """
        return _Piavca.Avatar_setFacialExpressionWeight(*args)

    def getFacialExpressionWeight(*args):
        """
        float Piavca::Avatar::getFacialExpressionWeight(int id)
                 
        get the weight of an expression         
                 
                
        """
        return _Piavca.Avatar_getFacialExpressionWeight(*args)

    def setJointOrientation(*args):
        """
        void Avatar::setJointOrientation(std::vector< std::pair< int, Quat > > jointOrientation, jointCoord worldCoord=JOINTLOCAL_COORD)
                 
        set all the joint orientations from a vector of joint IDs and values         
                 
        This can be done in various coordinate systems, jointlocal is the coordante space of the joint (default) local is the space of the avatar root world is the world coordinates using the second two is likely to be much less efficient         
        """
        return _Piavca.Avatar_setJointOrientation(*args)

    def getJointOrientation(*args):
        """
        Quat Piavca::Avatar::getJointOrientation(int jointId, jointCoord worldCoord=JOINTLOCAL_COORD)
                 
        get the orientation of a joint         
                 
        The joint is specified via an ID. This can be done in various coordinate systems, jointlocal is the coordante space of the joint (default) local is the space of the avatar root world is the world coordinates using the second two is likely to be much less efficient         
        """
        return _Piavca.Avatar_getJointOrientation(*args)

    def getJointBasePosition(*args):
        """
        Vec Piavca::Avatar::getJointBasePosition(int jointId, jointCoord worldCoord=LOCAL_COORD)
                 
        get the current position of the start point of the joint         
                 
        calculated from the root position and joint angles by forward kinematics This can be done in various coordinate systems, jointlocal is the coordante space of the joint local is the space of the avatar root (default) world is the world coordinates         
        """
        return _Piavca.Avatar_getJointBasePosition(*args)

    def play_motion(*args): return _Piavca.Avatar_play_motion(*args)
    def add_background_motion(*args): return _Piavca.Avatar_add_background_motion(*args)
    def interrupt_motion(*args): return _Piavca.Avatar_interrupt_motion(*args)

class AvatarPtr(Avatar):
    def __init__(self, this):
        _swig_setattr(self, Avatar, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, Avatar, 'thisown', 0)
        self.__class__ = Avatar
_Piavca.Avatar_swigregister(AvatarPtr)

class queueElement(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, queueElement, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, queueElement, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::queueElement instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    __swig_setmethods__["mot"] = _Piavca.queueElement_mot_set
    __swig_getmethods__["mot"] = _Piavca.queueElement_mot_get
    if _newclass:mot = property(_Piavca.queueElement_mot_get, _Piavca.queueElement_mot_set)
    __swig_setmethods__["name"] = _Piavca.queueElement_name_set
    __swig_getmethods__["name"] = _Piavca.queueElement_name_get
    if _newclass:name = property(_Piavca.queueElement_name_get, _Piavca.queueElement_name_set)
    __swig_setmethods__["atTime"] = _Piavca.queueElement_atTime_set
    __swig_getmethods__["atTime"] = _Piavca.queueElement_atTime_get
    if _newclass:atTime = property(_Piavca.queueElement_atTime_get, _Piavca.queueElement_atTime_set)
    __swig_setmethods__["background"] = _Piavca.queueElement_background_set
    __swig_getmethods__["background"] = _Piavca.queueElement_background_get
    if _newclass:background = property(_Piavca.queueElement_background_get, _Piavca.queueElement_background_set)
    def __init__(self, *args):
        _swig_setattr(self, queueElement, 'this', _Piavca.new_queueElement(*args))
        _swig_setattr(self, queueElement, 'thisown', 1)
    def __del__(self, destroy=_Piavca.delete_queueElement):
        try:
            if self.thisown: destroy(self)
        except: pass


class queueElementPtr(queueElement):
    def __init__(self, this):
        _swig_setattr(self, queueElement, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, queueElement, 'thisown', 0)
        self.__class__ = queueElement
_Piavca.queueElement_swigregister(queueElementPtr)

class AvatarMotionQueue(AvatarTimeCallback):
    """
    A Queue for managing motions.     
           
    You can put motions on the queue and they will be played in sequence each waiting for the previous to finish. You can also add background motions that continuing playing at the same time as the motions on the queue.      see also: AvatarMotionQueue.h
    """
    __swig_setmethods__ = {}
    for _s in [AvatarTimeCallback]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, AvatarMotionQueue, name, value)
    __swig_getmethods__ = {}
    for _s in [AvatarTimeCallback]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, AvatarMotionQueue, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::AvatarMotionQueue instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        """
        Piavca::AvatarMotionQueue::AvatarMotionQueue(const AvatarMotionQueue &amq)
                 
                
                 
                
        """
        _swig_setattr(self, AvatarMotionQueue, 'this', _Piavca.new_AvatarMotionQueue(*args))
        _swig_setattr(self, AvatarMotionQueue, 'thisown', 1)
    def __del__(self, destroy=_Piavca.delete_AvatarMotionQueue):
        """
        virtual Piavca::AvatarMotionQueue::~AvatarMotionQueue()
                 
                
                 
                
        """
        try:
            if self.thisown: destroy(self)
        except: pass

    def init(*args):
        """
        void AvatarMotionQueue::init(Piavca::Avatar *avatar)
                 
        This is a setup method for the callback.         
                 
        It's called when the callback is registered         
        """
        return _Piavca.AvatarMotionQueue_init(*args)

    def timeStep(*args):
        """
        void AvatarMotionQueue::timeStep(Piavca::Avatar *avatar, float time)
                 
        implement this to make the callback do things         
                 
        It's called every frame with by the API which passes in the avatar to which the callback is attatched         
        """
        return _Piavca.AvatarMotionQueue_timeStep(*args)

    def isFacial(*args):
        """
        bool Piavca::AvatarMotionQueue::isFacial()
                 
        whether the queue handles facial or body motions         
                 
                
        """
        return _Piavca.AvatarMotionQueue_isFacial(*args)

    def getCurrentMotionStart(*args):
        """
        float Piavca::AvatarMotionQueue::getCurrentMotionStart()
                 
        gets the start time of the current motion         
                 
                
        """
        return _Piavca.AvatarMotionQueue_getCurrentMotionStart(*args)

    def reblend(*args):
        """
        void Piavca::AvatarMotionQueue::reblend()
                 
                
                 
                
        """
        return _Piavca.AvatarMotionQueue_reblend(*args)

    def setBlendInterval(*args):
        """
        void Piavca::AvatarMotionQueue::setBlendInterval(float t)
                 
        sets how long it takes to blend between subsequent motions.         
                 
                
        """
        return _Piavca.AvatarMotionQueue_setBlendInterval(*args)

    def enqueueMotion(*args):
        """
        void AvatarMotionQueue::enqueueMotion(tstring name, Piavca::Motion *motion, float atTime=0.0)
                 
        adds a motion to the queue         
                 
        You have to pass in a name for the motion and optionally a minimum time for it to start.         
        """
        return _Piavca.AvatarMotionQueue_enqueueMotion(*args)

    def enqueueRandomMotions(*args):
        """
        void AvatarMotionQueue::enqueueRandomMotions(int num=0)
                 
        enqueue a number of randomly chosen motions         
                 
                
        """
        return _Piavca.AvatarMotionQueue_enqueueRandomMotions(*args)

    def queueTopIsBackground(*args):
        """
        bool AvatarMotionQueue::queueTopIsBackground()
                 
        tests whether the first motion on the queue is a background motion         
                 
                
        """
        return _Piavca.AvatarMotionQueue_queueTopIsBackground(*args)

    def queueTopTime(*args):
        """
        float AvatarMotionQueue::queueTopTime()
                 
        gets the minimum start time of the first motion on the queue         
                 
                
        """
        return _Piavca.AvatarMotionQueue_queueTopTime(*args)

    def dequeueMotion(*args):
        """
        Motion * AvatarMotionQueue::dequeueMotion()
                 
        pops a motion off the queue         
                 
                
        """
        return _Piavca.AvatarMotionQueue_dequeueMotion(*args)

    def getQueueSize(*args):
        """
        int Piavca::AvatarMotionQueue::getQueueSize()
                 
        returns the number of motions on the queue         
                 
                
        """
        return _Piavca.AvatarMotionQueue_getQueueSize(*args)

    def updateDelay(*args):
        """
        void Piavca::AvatarMotionQueue::updateDelay(float delay)
                 
        change the delay         
                 
                
        """
        return _Piavca.AvatarMotionQueue_updateDelay(*args)

    def clearQueue(*args):
        """
        void AvatarMotionQueue::clearQueue()
                 
        empties the queue         
                 
                
        """
        return _Piavca.AvatarMotionQueue_clearQueue(*args)

    def removeMotion(*args):
        """
        void AvatarMotionQueue::removeMotion(tstring name)
                 
        removes a named forground motion         
                 
                
        """
        return _Piavca.AvatarMotionQueue_removeMotion(*args)

    def pauseMotion(*args):
        """
        void Piavca::AvatarMotionQueue::pauseMotion(tstring name)
                 
        pauses a named forground motion         
                 
                
        """
        return _Piavca.AvatarMotionQueue_pauseMotion(*args)

    def unpauseMotion(*args):
        """
        void Piavca::AvatarMotionQueue::unpauseMotion(tstring name)
                 
        unpauses a named forground motion         
                 
                
        """
        return _Piavca.AvatarMotionQueue_unpauseMotion(*args)

    def clearAllBackgroundMotions(*args):
        """
        void AvatarMotionQueue::clearAllBackgroundMotions()
                 
        removes all background motions from the queue         
                 
                
        """
        return _Piavca.AvatarMotionQueue_clearAllBackgroundMotions(*args)

    def clearFinishedBackgroundMotions(*args):
        """
        void AvatarMotionQueue::clearFinishedBackgroundMotions()
                 
        removes any background motions that have stopped playing         
                 
                
        """
        return _Piavca.AvatarMotionQueue_clearFinishedBackgroundMotions(*args)

    def removeBackgroundMotion(*args):
        """
        void AvatarMotionQueue::removeBackgroundMotion(tstring name)
                 
        removes a named background motion         
                 
                
        """
        return _Piavca.AvatarMotionQueue_removeBackgroundMotion(*args)

    def removeBackgroundMotionByType(*args):
        """
        void AvatarMotionQueue::removeBackgroundMotionByType(const type_info &ty)
                 
        removes a background motion with a given type         
                 
                
        """
        return _Piavca.AvatarMotionQueue_removeBackgroundMotionByType(*args)

    def pauseBackgroundMotion(*args):
        """
        void AvatarMotionQueue::pauseBackgroundMotion(tstring name)
                 
        pauses a named background motion         
                 
                
        """
        return _Piavca.AvatarMotionQueue_pauseBackgroundMotion(*args)

    def unpauseBackgroundMotion(*args):
        """
        void AvatarMotionQueue::unpauseBackgroundMotion(tstring name)
                 
        unpauses a named background motion         
                 
                
        """
        return _Piavca.AvatarMotionQueue_unpauseBackgroundMotion(*args)

    def interrupt(*args):
        """
        void Piavca::AvatarMotionQueue::interrupt()
                 
        interrupts the queue         
                 
        so the next motion is played immediately, without waiting for the current one stop         
        """
        return _Piavca.AvatarMotionQueue_interrupt(*args)

    def getMotion(*args):
        """
        virtual Piavca::Motion* Piavca::AvatarMotionQueue::getMotion()
                 
        return the resulting motion         
                 
                
        """
        return _Piavca.AvatarMotionQueue_getMotion(*args)

    def blendMotion(*args):
        """
        Motion * AvatarMotionQueue::blendMotion(Motion *m, Avatar *av, float scaleFactor)
                 
                
                 
                
        """
        return _Piavca.AvatarMotionQueue_blendMotion(*args)

    def addBackgroundMotion(*args):
        """
        void AvatarMotionQueue::addBackgroundMotion(tstring name, Piavca::Motion *motion, float atTime=0.0)
                 
        adds a new background motion to the queue         
                 
        A background motion is played concurrently with any motions on the queue. You have to pass in a name and optionally minimum time at which it should start.         
        """
        return _Piavca.AvatarMotionQueue_addBackgroundMotion(*args)


class AvatarMotionQueuePtr(AvatarMotionQueue):
    def __init__(self, this):
        _swig_setattr(self, AvatarMotionQueue, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, AvatarMotionQueue, 'thisown', 0)
        self.__class__ = AvatarMotionQueue
_Piavca.AvatarMotionQueue_swigregister(AvatarMotionQueuePtr)

class Object(_object):
    """
    A class for representing inanimate objects in PIAVCA.     
           
    This works much like an avatar, except its only got a root and not joints/facial exprssions.      see also: Object.h
    """
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Object, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Object, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::Object instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        """
        Piavca::Object::Object(tstring objectId, const Vec &Position=Vec(0.0, 0.0, 0.0), const Quat &Orientation=Quat(1.0, 0.0, 0.0, 0.0))
                 
        create an object         
                 
        The object needs to be initialised with an implementation. The type of the implementation depends on the platform and so it cannot be created directly in platform independant code. To get around this it is created by a static factory method in the which itself uses the Piavca::Core class and its platform dependent implementation to create the implementation of the avatar. The constructor needs an identifier string that it uses to find platform specific data needed to create the avatar, for example the mesh file. The user can also pass in a position and orientation for the object.         
        """
        _swig_setattr(self, Object, 'this', _Piavca.new_Object(*args))
        _swig_setattr(self, Object, 'thisown', 1)
    def getName(*args):
        """
        tstring Piavca::Object::getName()
                 
        get the name of the avatar         
                 
                
        """
        return _Piavca.Object_getName(*args)

    def setName(*args):
        """
        tstring Piavca::Object::setName(tstring newName)
                 
        set the name of the avatar         
                 
                
        """
        return _Piavca.Object_setName(*args)

    def setPosition(*args):
        """
        void Piavca::Object::setPosition(const Vec &Position)
                 
                
                 
        get or set the root position and orientation of the avatar         
        """
        return _Piavca.Object_setPosition(*args)

    def getPosition(*args):
        """
        Vec Piavca::Object::getPosition()
                 
                
                 
                
        """
        return _Piavca.Object_getPosition(*args)

    def setOrientation(*args):
        """
        void Piavca::Object::setOrientation(const Quat &Orientation)
                 
                
                 
                
        """
        return _Piavca.Object_setOrientation(*args)

    def setAngle(*args):
        """
        void Piavca::Object::setAngle(float angle)
                 
        set the orientation from an angle in radians (assumed to be about the verticle)         
                 
                
        """
        return _Piavca.Object_setAngle(*args)

    def setAngleDeg(*args):
        """
        void Piavca::Object::setAngleDeg(float angle)
                 
        set the orientation from an angle in degrees (assumed to be about the verticle)         
                 
                
        """
        return _Piavca.Object_setAngleDeg(*args)

    def getOrientation(*args):
        """
        Quat Piavca::Object::getOrientation()
                 
                
                 
                
        """
        return _Piavca.Object_getOrientation(*args)

    def scale(*args):
        """
        void Piavca::Object::scale(Vec scale)
                 
        scales the root by a non-uniform scale vector         
                 
                
        """
        return _Piavca.Object_scale(*args)


class ObjectPtr(Object):
    def __init__(self, this):
        _swig_setattr(self, Object, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, Object, 'thisown', 0)
        self.__class__ = Object
_Piavca.Object_swigregister(ObjectPtr)

class PyTimeCallback(TimeCallback):
    """
    see also: PyTimeCallback.h
    """
    __swig_setmethods__ = {}
    for _s in [TimeCallback]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, PyTimeCallback, name, value)
    __swig_getmethods__ = {}
    for _s in [TimeCallback]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, PyTimeCallback, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::PyTimeCallback instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        """
        Piavca::PyTimeCallback::PyTimeCallback(PyObject *pyCallback, tstring name)
                 
                
                 
                
        """
        _swig_setattr(self, PyTimeCallback, 'this', _Piavca.new_PyTimeCallback(*args))
        _swig_setattr(self, PyTimeCallback, 'thisown', 1)
    def __del__(self, destroy=_Piavca.delete_PyTimeCallback):
        """
        Piavca::PyTimeCallback::~PyTimeCallback()
                 
                
                 
                
        """
        try:
            if self.thisown: destroy(self)
        except: pass

    def init(*args):
        """
        PIAVCA_EXPORT void PyTimeCallback::init(Core *core)
                 
        This is a setup method for the callback.         
                 
        It's called when the callback is registered         
        """
        return _Piavca.PyTimeCallback_init(*args)

    def timeStep(*args):
        """
        PIAVCA_EXPORT void PyTimeCallback::timeStep(Core *core, float time)
                 
        implement this to make the callback do things         
                 
        It's called every frame with by the API         
        """
        return _Piavca.PyTimeCallback_timeStep(*args)


class PyTimeCallbackPtr(PyTimeCallback):
    def __init__(self, this):
        _swig_setattr(self, PyTimeCallback, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, PyTimeCallback, 'thisown', 0)
        self.__class__ = PyTimeCallback
_Piavca.PyTimeCallback_swigregister(PyTimeCallbackPtr)

class PyAvatarTimeCallback(AvatarTimeCallback):
    """
    see also: PyTimeCallback.h
    """
    __swig_setmethods__ = {}
    for _s in [AvatarTimeCallback]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, PyAvatarTimeCallback, name, value)
    __swig_getmethods__ = {}
    for _s in [AvatarTimeCallback]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, PyAvatarTimeCallback, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::PyAvatarTimeCallback instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        """
        Piavca::PyAvatarTimeCallback::PyAvatarTimeCallback(PyObject *pyCallback, tstring name)
                 
                
                 
                
        """
        _swig_setattr(self, PyAvatarTimeCallback, 'this', _Piavca.new_PyAvatarTimeCallback(*args))
        _swig_setattr(self, PyAvatarTimeCallback, 'thisown', 1)
    def __del__(self, destroy=_Piavca.delete_PyAvatarTimeCallback):
        """
        Piavca::PyAvatarTimeCallback::~PyAvatarTimeCallback()
                 
                
                 
                
        """
        try:
            if self.thisown: destroy(self)
        except: pass

    def init(*args):
        """
        PIAVCA_EXPORT void PyAvatarTimeCallback::init(Avatar *avatar)
                 
        This is a setup method for the callback.         
                 
        It's called when the callback is registered         
        """
        return _Piavca.PyAvatarTimeCallback_init(*args)

    def timeStep(*args):
        """
        PIAVCA_EXPORT void PyAvatarTimeCallback::timeStep(Avatar *av, float time)
                 
        implement this to make the callback do things         
                 
        It's called every frame with by the API which passes in the avatar to which the callback is attatched         
        """
        return _Piavca.PyAvatarTimeCallback_timeStep(*args)


class PyAvatarTimeCallbackPtr(PyAvatarTimeCallback):
    def __init__(self, this):
        _swig_setattr(self, PyAvatarTimeCallback, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, PyAvatarTimeCallback, 'thisown', 0)
        self.__class__ = PyAvatarTimeCallback
_Piavca.PyAvatarTimeCallback_swigregister(PyAvatarTimeCallbackPtr)

class PyMotion(Motion):
    """
    see also: PyMotion.h
    """
    __swig_setmethods__ = {}
    for _s in [Motion]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, PyMotion, name, value)
    __swig_getmethods__ = {}
    for _s in [Motion]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, PyMotion, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::PyMotion instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        """
        Piavca::PyMotion::PyMotion(const PyMotion &pm)
                 
                
                 
                
        """
        _swig_setattr(self, PyMotion, 'this', _Piavca.new_PyMotion(*args))
        _swig_setattr(self, PyMotion, 'thisown', 1)
    def clone(*args):
        """
        Motion* Piavca::PyMotion::clone()
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca.PyMotion_clone(*args)

    def __del__(self, destroy=_Piavca.delete_PyMotion):
        """
        PyMotion::~PyMotion()
                 
                
                 
                
        """
        try:
            if self.thisown: destroy(self)
        except: pass

    def setPyObj(*args):
        """
        void Piavca::PyMotion::setPyObj(PyObject *pObj)
                 
                
                 
                
        """
        return _Piavca.PyMotion_setPyObj(*args)

    def getMotionPtr(*args):
        """
        Motion* Piavca::PyMotion::getMotionPtr()
                 
        returns a point to the motion object as swig won't recognise the python overload?         
                 
                
        """
        return _Piavca.PyMotion_getMotionPtr(*args)

    def getMotionLength(*args):
        """
        float PyMotion::getMotionLength() const 
                 
        gets the time of the end of the motion         
                 
                
        """
        return _Piavca.PyMotion_getMotionLength(*args)

    def isNull(*args):
        """
        bool PyMotion::isNull(int trackId) const 
                 
        given a track ID tests whether it actually points to anything or if its null         
                 
                
        """
        return _Piavca.PyMotion_isNull(*args)

    def getTrackType(*args):
        """
        trackType PyMotion::getTrackType(int trackId) const 
                 
        get the type of the track corresponding to an ID         
                 
                
        """
        return _Piavca.PyMotion_getTrackType(*args)

    def getFloatValueAtTimeInternal(*args):
        """
        float PyMotion::getFloatValueAtTimeInternal(int trackId, float time)
                 
        get the value of a track at a given time (only works for floats)         
                 
                
        """
        return _Piavca.PyMotion_getFloatValueAtTimeInternal(*args)

    def getVecValueAtTimeInternal(*args):
        """
        Vec PyMotion::getVecValueAtTimeInternal(int trackId, float time)
                 
        get the value of a track at a given time (only works for Vecs)         
                 
                
        """
        return _Piavca.PyMotion_getVecValueAtTimeInternal(*args)

    def getQuatValueAtTimeInternal(*args):
        """
        Quat PyMotion::getQuatValueAtTimeInternal(int trackId, float time)
                 
        get the value of a track at a given time (only works for Quats)         
                 
                
        """
        return _Piavca.PyMotion_getQuatValueAtTimeInternal(*args)


class PyMotionPtr(PyMotion):
    def __init__(self, this):
        _swig_setattr(self, PyMotion, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, PyMotion, 'thisown', 0)
        self.__class__ = PyMotion
_Piavca.PyMotion_swigregister(PyMotionPtr)


def degToRad(*args):
    """
    float Piavca::degToRad(float angle)
             
    convert and angle in degrees to radians         
             
            
    """
    return _Piavca.degToRad(*args)

def radToDeg(*args):
    """
    float Piavca::radToDeg(float angle)
             
    convert and angle in radians to degrees         
             
            
    """
    return _Piavca.radToDeg(*args)
class MotionFilter(Motion):
    """
    A motion class whose output is some transformation of another motion.     
           
    This class is an abstract base class that just provides some common features between motion filters. To actaully do anything you have to override the get[Float/Quat/Vec]ValueAtTime methods to perform whatever opertation you want on the other motion.      see also: MotionFilter.h
    """
    __swig_setmethods__ = {}
    for _s in [Motion]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, MotionFilter, name, value)
    __swig_getmethods__ = {}
    for _s in [Motion]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, MotionFilter, name)
    def __init__(self): raise RuntimeError, "No constructor defined"
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::MotionFilter instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __del__(self, destroy=_Piavca.delete_MotionFilter):
        """
        virtual Piavca::MotionFilter::~MotionFilter()
                 
                
                 
                
        """
        try:
            if self.thisown: destroy(self)
        except: pass

    def printInfo(*args):
        """
        void Piavca::MotionFilter::printInfo()
                 
        prints out info about the motion heirarchy         
                 
                
        """
        return _Piavca.MotionFilter_printInfo(*args)

    def findSub(*args):
        """
        virtual Motion* Piavca::MotionFilter::findSub(tstring nm)
                 
        finds the first submotion with a given name         
                 
                
        """
        return _Piavca.MotionFilter_findSub(*args)

    def findSubByType(*args):
        """
        virtual Motion* Piavca::MotionFilter::findSubByType(const type_info &ty)
                 
        finds the first submotion with a given type         
                 
                
        """
        return _Piavca.MotionFilter_findSubByType(*args)

    def load(*args):
        """
        virtual void Piavca::MotionFilter::load(Avatar *av)
                 
        called when the motion is loaded into an avatar         
                 
                
        """
        return _Piavca.MotionFilter_load(*args)

    def unload(*args):
        """
        virtual void Piavca::MotionFilter::unload()
                 
        called when the motion is unloaded from an avatar         
                 
                
        """
        return _Piavca.MotionFilter_unload(*args)

    def loaded(*args):
        """
        virtual bool Piavca::MotionFilter::loaded()
                 
        checks if the motion has been loaded into an avatar         
                 
                
        """
        return _Piavca.MotionFilter_loaded(*args)

    def setStartTime(*args):
        """
        virtual void Piavca::MotionFilter::setStartTime(float time)
                 
        sets the start time of the motion. Called when its loaded into an avatar.         
                 
                
        """
        return _Piavca.MotionFilter_setStartTime(*args)

    def reset(*args):
        """
        void Piavca::MotionFilter::reset()
                 
        does any resetting needed         
                 
                
        """
        return _Piavca.MotionFilter_reset(*args)

    def setMotion(*args):
        """
        void Piavca::MotionFilter::setMotion(Motion *mot)
                 
                
                 
                
        """
        return _Piavca.MotionFilter_setMotion(*args)

    def getMotionLength(*args):
        """
        float Piavca::MotionFilter::getMotionLength() const 
                 
        gets the length of the motion in seconds         
                 
                
        """
        return _Piavca.MotionFilter_getMotionLength(*args)

    def isFacial(*args):
        """
        virtual bool Piavca::MotionFilter::isFacial()
                 
        whether it is a face or body motion         
                 
                
        """
        return _Piavca.MotionFilter_isFacial(*args)

    def isRandomAccess(*args):
        """
        virtual bool Piavca::MotionFilter::isRandomAccess()
                 
        whether you can access a motions value at frames other than the current one         
                 
                
        """
        return _Piavca.MotionFilter_isRandomAccess(*args)

    def isNull(*args):
        """
        virtual bool Piavca::MotionFilter::isNull(int trackId) const 
                 
        given an iterator tests whether it actually points to anything or if its null         
                 
                
        """
        return _Piavca.MotionFilter_isNull(*args)

    def getTrackType(*args):
        """
        trackType Piavca::MotionFilter::getTrackType(int trackId) const 
                 
        get the type of the track corresponding to an iterator         
                 
                
        """
        return _Piavca.MotionFilter_getTrackType(*args)


class MotionFilterPtr(MotionFilter):
    def __init__(self, this):
        _swig_setattr(self, MotionFilter, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, MotionFilter, 'thisown', 0)
        self.__class__ = MotionFilter
_Piavca.MotionFilter_swigregister(MotionFilterPtr)
cvar = _Piavca.cvar
Pi = cvar.Pi

class TwoMotionCombiner(Motion):
    """
    A motion manipulator that combine two different motion.     
           
    This class is an abstract base class that just provides some common features between motion filters. To actaully do anything you have to override the get[Float/Quat/Vec]ValueAtTime methods to perform whatever opertation you want on the two motion.      see also: TwoMotionCombiner.h
    """
    __swig_setmethods__ = {}
    for _s in [Motion]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, TwoMotionCombiner, name, value)
    __swig_getmethods__ = {}
    for _s in [Motion]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, TwoMotionCombiner, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::TwoMotionCombiner instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        """
        TwoMotionCombiner::TwoMotionCombiner(const TwoMotionCombiner &tmc)
                 
                
                 
                
        """
        if self.__class__ == TwoMotionCombiner:
            args = (None,) + args
        else:
            args = (self,) + args
        _swig_setattr(self, TwoMotionCombiner, 'this', _Piavca.new_TwoMotionCombiner(*args))
        _swig_setattr(self, TwoMotionCombiner, 'thisown', 1)
    def __del__(self, destroy=_Piavca.delete_TwoMotionCombiner):
        """
        TwoMotionCombiner::~TwoMotionCombiner()
                 
                
                 
                
        """
        try:
            if self.thisown: destroy(self)
        except: pass

    def printInfo(*args):
        """
        void TwoMotionCombiner::printInfo()
                 
        prints out info about the motion heirarchy         
                 
                
        """
        return _Piavca.TwoMotionCombiner_printInfo(*args)

    def findSub(*args):
        """
        Motion * TwoMotionCombiner::findSub(tstring nm)
                 
        finds the first submotion with a given name         
                 
                
        """
        return _Piavca.TwoMotionCombiner_findSub(*args)

    def findSubByType(*args):
        """
        Motion * TwoMotionCombiner::findSubByType(const type_info &ty)
                 
        finds the first submotion with a given type         
                 
                
        """
        return _Piavca.TwoMotionCombiner_findSubByType(*args)

    def load(*args):
        """
        void TwoMotionCombiner::load(Avatar *av)
                 
        called when the motion is loaded into an avatar         
                 
                
        """
        return _Piavca.TwoMotionCombiner_load(*args)

    def unload(*args):
        """
        void TwoMotionCombiner::unload()
                 
        called when the motion is unloaded from an avatar         
                 
                
        """
        return _Piavca.TwoMotionCombiner_unload(*args)

    def loaded(*args):
        """
        bool TwoMotionCombiner::loaded()
                 
        checks if the motion has been loaded into an avatar         
                 
                
        """
        return _Piavca.TwoMotionCombiner_loaded(*args)

    def setStartTime(*args):
        """
        void TwoMotionCombiner::setStartTime(float time)
                 
        sets the start time of the motion. Called when its loaded into an avatar.         
                 
                
        """
        return _Piavca.TwoMotionCombiner_setStartTime(*args)

    def reset(*args):
        """
        void TwoMotionCombiner::reset()
                 
        does any resetting needed         
                 
                
        """
        return _Piavca.TwoMotionCombiner_reset(*args)

    def getMotionLength(*args):
        """
        float TwoMotionCombiner::getMotionLength() const 
                 
        gets the length of the combined motion (by default the length of the longer of the two)         
                 
                
        """
        return _Piavca.TwoMotionCombiner_getMotionLength(*args)

    def isFacial(*args):
        """
        bool TwoMotionCombiner::isFacial()
                 
        whether it is a face or body motion         
                 
                
        """
        return _Piavca.TwoMotionCombiner_isFacial(*args)

    def isRandomAccess(*args):
        """
        bool TwoMotionCombiner::isRandomAccess()
                 
        whether you can access a motions value at frames other than the current one         
                 
                
        """
        return _Piavca.TwoMotionCombiner_isRandomAccess(*args)

    def isNull(*args):
        """
        bool TwoMotionCombiner::isNull(int trackId) const 
                 
        given a track ID tests whether it actually points to anything or if its null         
                 
        is null if the track is null in both motions.         
        """
        return _Piavca.TwoMotionCombiner_isNull(*args)

    def getTrackType(*args):
        """
        trackType TwoMotionCombiner::getTrackType(int trackId) const 
                 
        get the type of the track corresponding to an iterator         
                 
                
        """
        return _Piavca.TwoMotionCombiner_getTrackType(*args)

    def setMotion1(*args):
        """
        void TwoMotionCombiner::setMotion1(Motion *mot)
                 
                
                 
                
        """
        return _Piavca.TwoMotionCombiner_setMotion1(*args)

    def setMotion2(*args):
        """
        void TwoMotionCombiner::setMotion2(Motion *mot)
                 
                
                 
                
        """
        return _Piavca.TwoMotionCombiner_setMotion2(*args)

    def getMotion1(*args):
        """
        Motion* Piavca::TwoMotionCombiner::getMotion1()
                 
                
                 
                
        """
        return _Piavca.TwoMotionCombiner_getMotion1(*args)

    def getMotion2(*args):
        """
        Motion* Piavca::TwoMotionCombiner::getMotion2()
                 
                
                 
                
        """
        return _Piavca.TwoMotionCombiner_getMotion2(*args)

    def __disown__(self):
        self.thisown = 0
        _Piavca.disown_TwoMotionCombiner(self)
        return weakref_proxy(self)

class TwoMotionCombinerPtr(TwoMotionCombiner):
    def __init__(self, this):
        _swig_setattr(self, TwoMotionCombiner, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, TwoMotionCombiner, 'thisown', 0)
        self.__class__ = TwoMotionCombiner
_Piavca.TwoMotionCombiner_swigregister(TwoMotionCombinerPtr)

class ScaleMotion(MotionFilter):
    """
    a motion filter that scales the motion by a float factor     
           
         see also: ScaleMotion.h
    """
    __swig_setmethods__ = {}
    for _s in [MotionFilter]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, ScaleMotion, name, value)
    __swig_getmethods__ = {}
    for _s in [MotionFilter]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, ScaleMotion, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::ScaleMotion instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        """
        Piavca::ScaleMotion::ScaleMotion(const ScaleMotion &sm)
                 
                
                 
                
        """
        if self.__class__ == ScaleMotion:
            args = (None,) + args
        else:
            args = (self,) + args
        _swig_setattr(self, ScaleMotion, 'this', _Piavca.new_ScaleMotion(*args))
        _swig_setattr(self, ScaleMotion, 'thisown', 1)
    def clone(*args):
        """
        virtual Motion* Piavca::ScaleMotion::clone()
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca.ScaleMotion_clone(*args)

    def getFloatValueAtTimeInternal(*args):
        """
        virtual PIAVCA_EXPORT float Piavca::ScaleMotion::getFloatValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe         
                 
                
        """
        return _Piavca.ScaleMotion_getFloatValueAtTimeInternal(*args)

    def getVecValueAtTimeInternal(*args):
        """
        virtual PIAVCA_EXPORT Vec Piavca::ScaleMotion::getVecValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe         
                 
                
        """
        return _Piavca.ScaleMotion_getVecValueAtTimeInternal(*args)

    def getQuatValueAtTimeInternal(*args):
        """
        virtual PIAVCA_EXPORT Quat Piavca::ScaleMotion::getQuatValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe         
                 
                
        """
        return _Piavca.ScaleMotion_getQuatValueAtTimeInternal(*args)

    def setScaleFactor(*args):
        """
        void Piavca::ScaleMotion::setScaleFactor(float scale)
                 
        Sets the scale factor for the postion components of the motion.         
                 
                
        """
        return _Piavca.ScaleMotion_setScaleFactor(*args)

    def __del__(self, destroy=_Piavca.delete_ScaleMotion):
        """
        a motion filter that scales the motion by a float factor     
               
             see also: ScaleMotion.h
        """
        try:
            if self.thisown: destroy(self)
        except: pass

    def __disown__(self):
        self.thisown = 0
        _Piavca.disown_ScaleMotion(self)
        return weakref_proxy(self)

class ScaleMotionPtr(ScaleMotion):
    def __init__(self, this):
        _swig_setattr(self, ScaleMotion, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, ScaleMotion, 'thisown', 0)
        self.__class__ = ScaleMotion
_Piavca.ScaleMotion_swigregister(ScaleMotionPtr)

class ScaleMotionSpeed(MotionFilter):
    """
    a motion filter that scales the motion's speed     
           
         see also: ScaleMotionSpeed.h
    """
    __swig_setmethods__ = {}
    for _s in [MotionFilter]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, ScaleMotionSpeed, name, value)
    __swig_getmethods__ = {}
    for _s in [MotionFilter]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, ScaleMotionSpeed, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::ScaleMotionSpeed instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        """
        Piavca::ScaleMotionSpeed::ScaleMotionSpeed(const ScaleMotionSpeed &sm)
                 
                
                 
                
        """
        if self.__class__ == ScaleMotionSpeed:
            args = (None,) + args
        else:
            args = (self,) + args
        _swig_setattr(self, ScaleMotionSpeed, 'this', _Piavca.new_ScaleMotionSpeed(*args))
        _swig_setattr(self, ScaleMotionSpeed, 'thisown', 1)
    def clone(*args):
        """
        virtual Motion* Piavca::ScaleMotionSpeed::clone()
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca.ScaleMotionSpeed_clone(*args)

    def getMotionLength(*args):
        """
        virtual float Piavca::ScaleMotionSpeed::getMotionLength() const 
                 
        gets the length of the motion in seconds         
                 
                
        """
        return _Piavca.ScaleMotionSpeed_getMotionLength(*args)

    def getFloatValueAtTimeInternal(*args):
        """
        virtual PIAVCA_EXPORT float Piavca::ScaleMotionSpeed::getFloatValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe         
                 
                
        """
        return _Piavca.ScaleMotionSpeed_getFloatValueAtTimeInternal(*args)

    def getVecValueAtTimeInternal(*args):
        """
        virtual PIAVCA_EXPORT Vec Piavca::ScaleMotionSpeed::getVecValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe         
                 
                
        """
        return _Piavca.ScaleMotionSpeed_getVecValueAtTimeInternal(*args)

    def getQuatValueAtTimeInternal(*args):
        """
        virtual PIAVCA_EXPORT Quat Piavca::ScaleMotionSpeed::getQuatValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe         
                 
                
        """
        return _Piavca.ScaleMotionSpeed_getQuatValueAtTimeInternal(*args)

    def setScaleFactor(*args):
        """
        void Piavca::ScaleMotionSpeed::setScaleFactor(float scale)
                 
        Sets the scale factor for the postion components of the motion.         
                 
                
        """
        return _Piavca.ScaleMotionSpeed_setScaleFactor(*args)

    def __del__(self, destroy=_Piavca.delete_ScaleMotionSpeed):
        """
        a motion filter that scales the motion's speed     
               
             see also: ScaleMotionSpeed.h
        """
        try:
            if self.thisown: destroy(self)
        except: pass

    def __disown__(self):
        self.thisown = 0
        _Piavca.disown_ScaleMotionSpeed(self)
        return weakref_proxy(self)

class ScaleMotionSpeedPtr(ScaleMotionSpeed):
    def __init__(self, this):
        _swig_setattr(self, ScaleMotionSpeed, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, ScaleMotionSpeed, 'thisown', 0)
        self.__class__ = ScaleMotionSpeed
_Piavca.ScaleMotionSpeed_swigregister(ScaleMotionSpeedPtr)

class ScaleMotionRoot(MotionFilter):
    """
    a motion filter that scales the displacement (position) parts of the motion     
           
    This is basically useful for converting bvh files that are expressed in feet and inches to metres but might also be useful for motion retargeting.      see also: ScaleMotionRoot.h
    """
    __swig_setmethods__ = {}
    for _s in [MotionFilter]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, ScaleMotionRoot, name, value)
    __swig_getmethods__ = {}
    for _s in [MotionFilter]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, ScaleMotionRoot, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::ScaleMotionRoot instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        """
        Piavca::ScaleMotionRoot::ScaleMotionRoot(const ScaleMotionRoot &sm)
                 
                
                 
                
        """
        if self.__class__ == ScaleMotionRoot:
            args = (None,) + args
        else:
            args = (self,) + args
        _swig_setattr(self, ScaleMotionRoot, 'this', _Piavca.new_ScaleMotionRoot(*args))
        _swig_setattr(self, ScaleMotionRoot, 'thisown', 1)
    def __del__(self, destroy=_Piavca.delete_ScaleMotionRoot):
        """
        virtual Piavca::ScaleMotionRoot::~ScaleMotionRoot()
                 
                
                 
                
        """
        try:
            if self.thisown: destroy(self)
        except: pass

    def clone(*args):
        """
        virtual Motion* Piavca::ScaleMotionRoot::clone()
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca.ScaleMotionRoot_clone(*args)

    def getFloatValueAtTimeInternal(*args):
        """
        virtual PIAVCA_EXPORT float Piavca::ScaleMotionRoot::getFloatValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe         
                 
                
        """
        return _Piavca.ScaleMotionRoot_getFloatValueAtTimeInternal(*args)

    def getVecValueAtTimeInternal(*args):
        """
        virtual PIAVCA_EXPORT Vec Piavca::ScaleMotionRoot::getVecValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe (vec values are scaled)         
                 
                
        """
        return _Piavca.ScaleMotionRoot_getVecValueAtTimeInternal(*args)

    def getQuatValueAtTimeInternal(*args):
        """
        virtual PIAVCA_EXPORT Quat Piavca::ScaleMotionRoot::getQuatValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe         
                 
                
        """
        return _Piavca.ScaleMotionRoot_getQuatValueAtTimeInternal(*args)

    def setScaleFactor(*args):
        """
        void Piavca::ScaleMotionRoot::setScaleFactor(float scale)
                 
        Sets the scale factor for the postion components of the motion.         
                 
                
        """
        return _Piavca.ScaleMotionRoot_setScaleFactor(*args)

    def __disown__(self):
        self.thisown = 0
        _Piavca.disown_ScaleMotionRoot(self)
        return weakref_proxy(self)

class ScaleMotionRootPtr(ScaleMotionRoot):
    def __init__(self, this):
        _swig_setattr(self, ScaleMotionRoot, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, ScaleMotionRoot, 'thisown', 0)
        self.__class__ = ScaleMotionRoot
_Piavca.ScaleMotionRoot_swigregister(ScaleMotionRootPtr)

class TimeOffset(MotionFilter):
    """
    changes the start time of a motion by an offset     
           
         see also: TimeOffset.h
    """
    __swig_setmethods__ = {}
    for _s in [MotionFilter]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, TimeOffset, name, value)
    __swig_getmethods__ = {}
    for _s in [MotionFilter]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, TimeOffset, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::TimeOffset instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        """
        Piavca::TimeOffset::TimeOffset(const TimeOffset &to)
                 
                
                 
                
        """
        if self.__class__ == TimeOffset:
            args = (None,) + args
        else:
            args = (self,) + args
        _swig_setattr(self, TimeOffset, 'this', _Piavca.new_TimeOffset(*args))
        _swig_setattr(self, TimeOffset, 'thisown', 1)
    def clone(*args):
        """
        virtual Motion* Piavca::TimeOffset::clone()
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca.TimeOffset_clone(*args)

    def setStartTime(*args):
        """
        virtual void Piavca::TimeOffset::setStartTime(float time)
                 
        sets the start time of the motion. Called when its loaded into an avatar.         
                 
                
        """
        return _Piavca.TimeOffset_setStartTime(*args)

    def getFloatValueAtTimeInternal(*args):
        """
        virtual PIAVCA_EXPORT float Piavca::TimeOffset::getFloatValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe         
                 
                
        """
        return _Piavca.TimeOffset_getFloatValueAtTimeInternal(*args)

    def getVecValueAtTimeInternal(*args):
        """
        virtual PIAVCA_EXPORT Vec Piavca::TimeOffset::getVecValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe (vec values are scaled)         
                 
                
        """
        return _Piavca.TimeOffset_getVecValueAtTimeInternal(*args)

    def getQuatValueAtTimeInternal(*args):
        """
        virtual PIAVCA_EXPORT Quat Piavca::TimeOffset::getQuatValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe         
                 
                
        """
        return _Piavca.TimeOffset_getQuatValueAtTimeInternal(*args)

    def setOffset(*args):
        """
        void Piavca::TimeOffset::setOffset(float offs)
                 
        Sets the scale factor for the postion components of the motion.         
                 
                
        """
        return _Piavca.TimeOffset_setOffset(*args)

    def __del__(self, destroy=_Piavca.delete_TimeOffset):
        """
        changes the start time of a motion by an offset     
               
             see also: TimeOffset.h
        """
        try:
            if self.thisown: destroy(self)
        except: pass

    def __disown__(self):
        self.thisown = 0
        _Piavca.disown_TimeOffset(self)
        return weakref_proxy(self)

class TimeOffsetPtr(TimeOffset):
    def __init__(self, this):
        _swig_setattr(self, TimeOffset, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, TimeOffset, 'thisown', 0)
        self.__class__ = TimeOffset
_Piavca.TimeOffset_swigregister(TimeOffsetPtr)

class TurnMotion(MotionFilter):
    """
    turn a motion through a given rotation over the course of its run     
           
    For now the turning method is pretty rubbish, just turning the root position and orientation.      see also: TurnMotion.h
    """
    __swig_setmethods__ = {}
    for _s in [MotionFilter]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, TurnMotion, name, value)
    __swig_getmethods__ = {}
    for _s in [MotionFilter]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, TurnMotion, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::TurnMotion instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        """
        Piavca::TurnMotion::TurnMotion(const TurnMotion &tm)
                 
                
                 
                
        """
        if self.__class__ == TurnMotion:
            args = (None,) + args
        else:
            args = (self,) + args
        _swig_setattr(self, TurnMotion, 'this', _Piavca.new_TurnMotion(*args))
        _swig_setattr(self, TurnMotion, 'thisown', 1)
    def clone(*args):
        """
        virtual Motion* Piavca::TurnMotion::clone()
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca.TurnMotion_clone(*args)

    def getFloatValueAtTimeInternal(*args):
        """
        virtual PIAVCA_EXPORT float Piavca::TurnMotion::getFloatValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe         
                 
                
        """
        return _Piavca.TurnMotion_getFloatValueAtTimeInternal(*args)

    def getVecValueAtTimeInternal(*args):
        """
        virtual PIAVCA_EXPORT Vec Piavca::TurnMotion::getVecValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe         
                 
                
        """
        return _Piavca.TurnMotion_getVecValueAtTimeInternal(*args)

    def getQuatValueAtTimeInternal(*args):
        """
        virtual PIAVCA_EXPORT Quat Piavca::TurnMotion::getQuatValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe         
                 
                
        """
        return _Piavca.TurnMotion_getQuatValueAtTimeInternal(*args)

    def setRotation(*args):
        """
        void Piavca::TurnMotion::setRotation(Quat rot)
                 
                
                 
                
        """
        return _Piavca.TurnMotion_setRotation(*args)

    def __del__(self, destroy=_Piavca.delete_TurnMotion):
        """
        turn a motion through a given rotation over the course of its run     
               
        For now the turning method is pretty rubbish, just turning the root position and orientation.      see also: TurnMotion.h
        """
        try:
            if self.thisown: destroy(self)
        except: pass

    def __disown__(self):
        self.thisown = 0
        _Piavca.disown_TurnMotion(self)
        return weakref_proxy(self)

class TurnMotionPtr(TurnMotion):
    def __init__(self, this):
        _swig_setattr(self, TurnMotion, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, TurnMotion, 'thisown', 0)
        self.__class__ = TurnMotion
_Piavca.TurnMotion_swigregister(TurnMotionPtr)

class SequentialBlend(TwoMotionCombiner):
    """
    Initially plays one motion up to a given time then blends into another motion.     
           
    This can be used to smoothly transition between motions and is used to implement a number of different motion effects like LoopMotion and AvatarPostureBlend. The seoond motion starts in the ending root position and orientation of the first one rather than its own starting conditions. The transition is controlled by a start time and an interval (length of the transition). The smooth blend is not very sophisticated (just an interpolation) but it will look OK if the start of the second motion is not too different from the end of the first (don't use this to try to transition between lying down and standing up for instance)      see also: SequentialBlend.h
    """
    __swig_setmethods__ = {}
    for _s in [TwoMotionCombiner]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, SequentialBlend, name, value)
    __swig_getmethods__ = {}
    for _s in [TwoMotionCombiner]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, SequentialBlend, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::SequentialBlend instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        """
        Piavca::SequentialBlend::SequentialBlend(const SequentialBlend &sb)
                 
                
                 
                
        """
        if self.__class__ == SequentialBlend:
            args = (None,) + args
        else:
            args = (self,) + args
        _swig_setattr(self, SequentialBlend, 'this', _Piavca.new_SequentialBlend(*args))
        _swig_setattr(self, SequentialBlend, 'thisown', 1)
    def clone(*args):
        """
        virtual Motion* Piavca::SequentialBlend::clone()
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca.SequentialBlend_clone(*args)

    def setMaintainY(*args):
        """
        virtual void Piavca::SequentialBlend::setMaintainY(bool b)
                 
                
                 
                
        """
        return _Piavca.SequentialBlend_setMaintainY(*args)

    def setAccumulateRoot(*args):
        """
        virtual void Piavca::SequentialBlend::setAccumulateRoot(bool b)
                 
                
                 
                
        """
        return _Piavca.SequentialBlend_setAccumulateRoot(*args)

    def setStartTime(*args):
        """
        virtual void Piavca::SequentialBlend::setStartTime(float time)
                 
                
                 
        std::cout << "SequentialBlend::setStartTime " << name << " "         
        """
        return _Piavca.SequentialBlend_setStartTime(*args)

    def getMotionLength(*args):
        """
        float Piavca::SequentialBlend::getMotionLength() const 
                 
        gets the motion length (transition start + blend interval + length of second motion)         
                 
                
        """
        return _Piavca.SequentialBlend_getMotionLength(*args)

    def getFloatValueAtTimeInternal(*args):
        """
        float SequentialBlend::getFloatValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe         
                 
                
        """
        return _Piavca.SequentialBlend_getFloatValueAtTimeInternal(*args)

    def getVecValueAtTimeInternal(*args):
        """
        Vec SequentialBlend::getVecValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe         
                 
                
        """
        return _Piavca.SequentialBlend_getVecValueAtTimeInternal(*args)

    def getQuatValueAtTimeInternal(*args):
        """
        Quat SequentialBlend::getQuatValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe         
                 
                
        """
        return _Piavca.SequentialBlend_getQuatValueAtTimeInternal(*args)

    def setBlendStart(*args):
        """
        void Piavca::SequentialBlend::setBlendStart(float start)
                 
        set the time at which tbe blend between the motions starts         
                 
                
        """
        return _Piavca.SequentialBlend_setBlendStart(*args)

    def setBlendInterval(*args):
        """
        void Piavca::SequentialBlend::setBlendInterval(float interval)
                 
        sets the length of the transition between the two motions.         
                 
                
        """
        return _Piavca.SequentialBlend_setBlendInterval(*args)

    def getBlendStart(*args):
        """
        float Piavca::SequentialBlend::getBlendStart()
                 
        get the time at which tbe blend between the motions starts         
                 
                
        """
        return _Piavca.SequentialBlend_getBlendStart(*args)

    def getBlendInterval(*args):
        """
        float Piavca::SequentialBlend::getBlendInterval()
                 
        gets the length of the transition between the two motions.         
                 
                
        """
        return _Piavca.SequentialBlend_getBlendInterval(*args)

    def __del__(self, destroy=_Piavca.delete_SequentialBlend):
        """
        Initially plays one motion up to a given time then blends into another motion.     
               
        This can be used to smoothly transition between motions and is used to implement a number of different motion effects like LoopMotion and AvatarPostureBlend. The seoond motion starts in the ending root position and orientation of the first one rather than its own starting conditions. The transition is controlled by a start time and an interval (length of the transition). The smooth blend is not very sophisticated (just an interpolation) but it will look OK if the start of the second motion is not too different from the end of the first (don't use this to try to transition between lying down and standing up for instance)      see also: SequentialBlend.h
        """
        try:
            if self.thisown: destroy(self)
        except: pass

    def __disown__(self):
        self.thisown = 0
        _Piavca.disown_SequentialBlend(self)
        return weakref_proxy(self)

class SequentialBlendPtr(SequentialBlend):
    def __init__(self, this):
        _swig_setattr(self, SequentialBlend, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, SequentialBlend, 'thisown', 0)
        self.__class__ = SequentialBlend
_Piavca.SequentialBlend_swigregister(SequentialBlendPtr)

class SelfBlend(SequentialBlend):
    """
    A SequentialBlend motion manipuator that blends a motion into itself.     
           
    It contains a method reblend which when called will save the motions current state and then starts blending the motion in from the start. This is used in implementing the loop motion class but has other uses. For example if there is a parameterised motion and you want to change the parameters and blend the new motion in smoothly use a selfBlend. and call reblend just before changing the parameters.      see also: SelfBlend.h
    """
    __swig_setmethods__ = {}
    for _s in [SequentialBlend]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, SelfBlend, name, value)
    __swig_getmethods__ = {}
    for _s in [SequentialBlend]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, SelfBlend, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::SelfBlend instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        """
        Piavca::SelfBlend::SelfBlend(const SelfBlend &sb)
                 
                
                 
                
        """
        if self.__class__ == SelfBlend:
            args = (None,) + args
        else:
            args = (self,) + args
        _swig_setattr(self, SelfBlend, 'this', _Piavca.new_SelfBlend(*args))
        _swig_setattr(self, SelfBlend, 'thisown', 1)
    def clone(*args):
        """
        virtual Motion* Piavca::SelfBlend::clone()
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca.SelfBlend_clone(*args)

    def reset(*args):
        """
        void SelfBlend::reset()
                 
        does any resetting needed         
                 
                
        """
        return _Piavca.SelfBlend_reset(*args)

    def reblend(*args):
        """
        void SelfBlend::reblend(float time)
                 
        saves the state of the motion at time and start blending the motion back into that from the start         
                 
                
        """
        return _Piavca.SelfBlend_reblend(*args)

    def setMotion(*args):
        """
        void SelfBlend::setMotion(Motion *mot)
                 
        sets the motion to be blended in         
                 
                
        """
        return _Piavca.SelfBlend_setMotion(*args)

    def __del__(self, destroy=_Piavca.delete_SelfBlend):
        """
        A SequentialBlend motion manipuator that blends a motion into itself.     
               
        It contains a method reblend which when called will save the motions current state and then starts blending the motion in from the start. This is used in implementing the loop motion class but has other uses. For example if there is a parameterised motion and you want to change the parameters and blend the new motion in smoothly use a selfBlend. and call reblend just before changing the parameters.      see also: SelfBlend.h
        """
        try:
            if self.thisown: destroy(self)
        except: pass

    def __disown__(self):
        self.thisown = 0
        _Piavca.disown_SelfBlend(self)
        return weakref_proxy(self)

class SelfBlendPtr(SelfBlend):
    def __init__(self, this):
        _swig_setattr(self, SelfBlend, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, SelfBlend, 'thisown', 0)
        self.__class__ = SelfBlend
_Piavca.SelfBlend_swigregister(SelfBlendPtr)

class LoopMotion(SelfBlend):
    """
    a motion filter that makes a motion loop continuously     
           
         see also: LoopMotion.h
    """
    __swig_setmethods__ = {}
    for _s in [SelfBlend]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, LoopMotion, name, value)
    __swig_getmethods__ = {}
    for _s in [SelfBlend]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, LoopMotion, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::LoopMotion instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        """
        Piavca::LoopMotion::LoopMotion(const LoopMotion &l)
                 
                
                 
                
        """
        if self.__class__ == LoopMotion:
            args = (None,) + args
        else:
            args = (self,) + args
        _swig_setattr(self, LoopMotion, 'this', _Piavca.new_LoopMotion(*args))
        _swig_setattr(self, LoopMotion, 'thisown', 1)
    def clone(*args):
        """
        virtual Motion* Piavca::LoopMotion::clone()
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca.LoopMotion_clone(*args)

    def getMotionLength(*args):
        """
        virtual float Piavca::LoopMotion::getMotionLength() const 
                 
        gets the motion length (transition start + blend interval + length of second motion)         
                 
                
        """
        return _Piavca.LoopMotion_getMotionLength(*args)

    def setEndTime(*args):
        """
        void Piavca::LoopMotion::setEndTime(float t)
                 
                
                 
                
        """
        return _Piavca.LoopMotion_setEndTime(*args)

    def getFloatValueAtTimeInternal(*args):
        """
        virtual float Piavca::LoopMotion::getFloatValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe         
                 
        if the end has been reached it reblends to start again at the beginning         
        """
        return _Piavca.LoopMotion_getFloatValueAtTimeInternal(*args)

    def getVecValueAtTimeInternal(*args):
        """
        virtual Vec Piavca::LoopMotion::getVecValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe         
                 
        if the end has been reached it reblends to start again at the beginning         
        """
        return _Piavca.LoopMotion_getVecValueAtTimeInternal(*args)

    def getQuatValueAtTimeInternal(*args):
        """
        virtual Quat Piavca::LoopMotion::getQuatValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe         
                 
        if the end has been reached it reblends to start again at the beginning         
        """
        return _Piavca.LoopMotion_getQuatValueAtTimeInternal(*args)

    def __del__(self, destroy=_Piavca.delete_LoopMotion):
        """
        a motion filter that makes a motion loop continuously     
               
             see also: LoopMotion.h
        """
        try:
            if self.thisown: destroy(self)
        except: pass

    def __disown__(self):
        self.thisown = 0
        _Piavca.disown_LoopMotion(self)
        return weakref_proxy(self)

class LoopMotionPtr(LoopMotion):
    def __init__(self, this):
        _swig_setattr(self, LoopMotion, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, LoopMotion, 'thisown', 0)
        self.__class__ = LoopMotion
_Piavca.LoopMotion_swigregister(LoopMotionPtr)

class RandomTimingsLoop(LoopMotion):
    """
    A loop motion where the speed is altered randomly on each time round.     
           
         see also: RandomTimingsLoop.h
    """
    __swig_setmethods__ = {}
    for _s in [LoopMotion]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, RandomTimingsLoop, name, value)
    __swig_getmethods__ = {}
    for _s in [LoopMotion]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, RandomTimingsLoop, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::RandomTimingsLoop instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        """
        Piavca::RandomTimingsLoop::RandomTimingsLoop(const RandomTimingsLoop &rtl)
                 
                
                 
                
        """
        if self.__class__ == RandomTimingsLoop:
            args = (None,) + args
        else:
            args = (self,) + args
        _swig_setattr(self, RandomTimingsLoop, 'this', _Piavca.new_RandomTimingsLoop(*args))
        _swig_setattr(self, RandomTimingsLoop, 'thisown', 1)
    def __del__(self, destroy=_Piavca.delete_RandomTimingsLoop):
        """
        Piavca::RandomTimingsLoop::~RandomTimingsLoop()
                 
                
                 
                
        """
        try:
            if self.thisown: destroy(self)
        except: pass

    def clone(*args):
        """
        virtual Motion* Piavca::RandomTimingsLoop::clone()
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca.RandomTimingsLoop_clone(*args)

    def setTimingParams(*args):
        """
        virtual void Piavca::RandomTimingsLoop::setTimingParams(float minTimeScale, float maxTimeScale)
                 
        sets the minimum and maximum times that can be generated         
                 
                
        """
        return _Piavca.RandomTimingsLoop_setTimingParams(*args)

    def reblend(*args):
        """
        virtual void Piavca::RandomTimingsLoop::reblend(float time)
                 
        This is called each time around the loop.         
                 
                
        """
        return _Piavca.RandomTimingsLoop_reblend(*args)

    def setMotion(*args):
        """
        virtual void Piavca::RandomTimingsLoop::setMotion(Motion *m)
                 
        sets the motion to be looped         
                 
        std::cout << "setting motion for loop
        ";         
        """
        return _Piavca.RandomTimingsLoop_setMotion(*args)

    def __disown__(self):
        self.thisown = 0
        _Piavca.disown_RandomTimingsLoop(self)
        return weakref_proxy(self)

class RandomTimingsLoopPtr(RandomTimingsLoop):
    def __init__(self, this):
        _swig_setattr(self, RandomTimingsLoop, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, RandomTimingsLoop, 'thisown', 0)
        self.__class__ = RandomTimingsLoop
_Piavca.RandomTimingsLoop_swigregister(RandomTimingsLoopPtr)

class AvatarPostureBlend(SequentialBlend):
    """
    A motion blend operator that blends a motion into the current position of an avatar.     
           
    This class will blend smoothly from the current postion of an avatar to the motion and will have the motion start at the current position and orientation of the avatar rather than its own start point (see SequentialBlend docs for some details)      see also: AvatarPostureBlend.h
    """
    __swig_setmethods__ = {}
    for _s in [SequentialBlend]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, AvatarPostureBlend, name, value)
    __swig_getmethods__ = {}
    for _s in [SequentialBlend]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, AvatarPostureBlend, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::AvatarPostureBlend instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        """
        Piavca::AvatarPostureBlend::AvatarPostureBlend(const AvatarPostureBlend &apb)
                 
                
                 
                
        """
        _swig_setattr(self, AvatarPostureBlend, 'this', _Piavca.new_AvatarPostureBlend(*args))
        _swig_setattr(self, AvatarPostureBlend, 'thisown', 1)
    def clone(*args):
        """
        virtual Motion* Piavca::AvatarPostureBlend::clone()
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca.AvatarPostureBlend_clone(*args)

    def load(*args):
        """
        void AvatarPostureBlend::load(Avatar *av)
                 
        called when the motion is loaded into an avatar         
                 
                
        """
        return _Piavca.AvatarPostureBlend_load(*args)

    def setMotion(*args):
        """
        void AvatarPostureBlend::setMotion(Motion *mot)
                 
                
                 
                
        """
        return _Piavca.AvatarPostureBlend_setMotion(*args)

    def reblend(*args):
        """
        void AvatarPostureBlend::reblend(float time)
                 
        restart the blend (i.e. start blending from the current avatar posture) at the current time         
                 
                
        """
        return _Piavca.AvatarPostureBlend_reblend(*args)

    def __del__(self, destroy=_Piavca.delete_AvatarPostureBlend):
        """
        A motion blend operator that blends a motion into the current position of an avatar.     
               
        This class will blend smoothly from the current postion of an avatar to the motion and will have the motion start at the current position and orientation of the avatar rather than its own start point (see SequentialBlend docs for some details)      see also: AvatarPostureBlend.h
        """
        try:
            if self.thisown: destroy(self)
        except: pass


class AvatarPostureBlendPtr(AvatarPostureBlend):
    def __init__(self, this):
        _swig_setattr(self, AvatarPostureBlend, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, AvatarPostureBlend, 'thisown', 0)
        self.__class__ = AvatarPostureBlend
_Piavca.AvatarPostureBlend_swigregister(AvatarPostureBlendPtr)

class BlendBetween(TwoMotionCombiner):
    """
    A motion manipulator class that interpolates between two motions.     
           
    The resulting motion is an interpolation between the two motion using slerp for quaternions with a parameter value blend. This class blends the two motions concurrently rather blending from one to another as sequential blend does.      see also: BlendBetween.h
    """
    __swig_setmethods__ = {}
    for _s in [TwoMotionCombiner]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, BlendBetween, name, value)
    __swig_getmethods__ = {}
    for _s in [TwoMotionCombiner]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, BlendBetween, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::BlendBetween instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        """
        BlendBetween::BlendBetween(const BlendBetween &b)
                 
                
                 
                
        """
        if self.__class__ == BlendBetween:
            args = (None,) + args
        else:
            args = (self,) + args
        _swig_setattr(self, BlendBetween, 'this', _Piavca.new_BlendBetween(*args))
        _swig_setattr(self, BlendBetween, 'thisown', 1)
    def clone(*args):
        """
        virtual Motion* Piavca::BlendBetween::clone()
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca.BlendBetween_clone(*args)

    def getFloatValueAtTimeInternal(*args):
        """
        float BlendBetween::getFloatValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe.         
                 
        The result is the linear interpolation of the values of the two motions or if the track does not exist in the one motion, the value of the other         
        """
        return _Piavca.BlendBetween_getFloatValueAtTimeInternal(*args)

    def getVecValueAtTimeInternal(*args):
        """
        Vec BlendBetween::getVecValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe.         
                 
        The result is the linear interpolation of the values of the two motions or if the track does not exist in the one motion, the value of the other         
        """
        return _Piavca.BlendBetween_getVecValueAtTimeInternal(*args)

    def getQuatValueAtTimeInternal(*args):
        """
        Quat BlendBetween::getQuatValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe.         
                 
        The result is the linear interpolation (slerp) of the values of the two motions or if the track does not exist in the one motion, the value of the other         
        """
        return _Piavca.BlendBetween_getQuatValueAtTimeInternal(*args)

    def setBlendFactor(*args):
        """
        void Piavca::BlendBetween::setBlendFactor(float _blend)
                 
                
                 
                
        """
        return _Piavca.BlendBetween_setBlendFactor(*args)

    def __del__(self, destroy=_Piavca.delete_BlendBetween):
        """
        A motion manipulator class that interpolates between two motions.     
               
        The resulting motion is an interpolation between the two motion using slerp for quaternions with a parameter value blend. This class blends the two motions concurrently rather blending from one to another as sequential blend does.      see also: BlendBetween.h
        """
        try:
            if self.thisown: destroy(self)
        except: pass

    def __disown__(self):
        self.thisown = 0
        _Piavca.disown_BlendBetween(self)
        return weakref_proxy(self)

class BlendBetweenPtr(BlendBetween):
    def __init__(self, this):
        _swig_setattr(self, BlendBetween, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, BlendBetween, 'thisown', 0)
        self.__class__ = BlendBetween
_Piavca.BlendBetween_swigregister(BlendBetweenPtr)

class MotionAdder(TwoMotionCombiner):
    """
    Adds the result of two motions, performing them simultaneously.     
           
    The results is the sum of the effects of both motions (in fact with rotations this is achieved with quaternion multiplication but the effect is similar to vector addition. An optional parameter can scale the effect of the second motion.      see also: MotionAdder.h
    """
    __swig_setmethods__ = {}
    for _s in [TwoMotionCombiner]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, MotionAdder, name, value)
    __swig_getmethods__ = {}
    for _s in [TwoMotionCombiner]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, MotionAdder, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::MotionAdder instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        """
        Piavca::MotionAdder::MotionAdder(const MotionAdder &ma)
                 
                
                 
                
        """
        if self.__class__ == MotionAdder:
            args = (None,) + args
        else:
            args = (self,) + args
        _swig_setattr(self, MotionAdder, 'this', _Piavca.new_MotionAdder(*args))
        _swig_setattr(self, MotionAdder, 'thisown', 1)
    def clone(*args):
        """
        virtual Motion* Piavca::MotionAdder::clone()
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca.MotionAdder_clone(*args)

    def setScaleSecond(*args):
        """
        void Piavca::MotionAdder::setScaleSecond(float s)
                 
        this is a scale factor applied to the second motion         
                 
                
        """
        return _Piavca.MotionAdder_setScaleSecond(*args)

    def getFloatValueAtTimeInternal(*args):
        """
        float MotionAdder::getFloatValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe         
                 
        The results is the sum of the two motions.         
        """
        return _Piavca.MotionAdder_getFloatValueAtTimeInternal(*args)

    def getVecValueAtTimeInternal(*args):
        """
        Vec MotionAdder::getVecValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe         
                 
        The results is the sum of the two motions.         
        """
        return _Piavca.MotionAdder_getVecValueAtTimeInternal(*args)

    def getQuatValueAtTimeInternal(*args):
        """
        Quat MotionAdder::getQuatValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe         
                 
        The results is the quaternion multiplication of the two motions (which is similar to vector addition).         
        """
        return _Piavca.MotionAdder_getQuatValueAtTimeInternal(*args)

    def __del__(self, destroy=_Piavca.delete_MotionAdder):
        """
        Adds the result of two motions, performing them simultaneously.     
               
        The results is the sum of the effects of both motions (in fact with rotations this is achieved with quaternion multiplication but the effect is similar to vector addition. An optional parameter can scale the effect of the second motion.      see also: MotionAdder.h
        """
        try:
            if self.thisown: destroy(self)
        except: pass

    def __disown__(self):
        self.thisown = 0
        _Piavca.disown_MotionAdder(self)
        return weakref_proxy(self)

class MotionAdderPtr(MotionAdder):
    def __init__(self, this):
        _swig_setattr(self, MotionAdder, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, MotionAdder, 'thisown', 0)
        self.__class__ = MotionAdder
_Piavca.MotionAdder_swigregister(MotionAdderPtr)

class MotionMask(_object):
    """
    a set of masks specifying which joints should be played in a masked motion     
           
         see also: MaskedMotion.h
    """
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, MotionMask, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, MotionMask, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::MotionMask instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        """
        MotionMask::MotionMask(const MotionMask &mm)
                 
                
                 
                
        """
        _swig_setattr(self, MotionMask, 'this', _Piavca.new_MotionMask(*args))
        _swig_setattr(self, MotionMask, 'thisown', 1)
    def setMask(*args):
        """
        void MotionMask::setMask(int track, bool val=true)
                 
        sets whether a given track should be played         
                 
                
        """
        return _Piavca.MotionMask_setMask(*args)

    def getMask(*args):
        """
        bool MotionMask::getMask(int track) const 
                 
        gets the mask value for a track         
                 
                
        """
        return _Piavca.MotionMask_getMask(*args)

    def __del__(self, destroy=_Piavca.delete_MotionMask):
        """
        a set of masks specifying which joints should be played in a masked motion     
               
             see also: MaskedMotion.h
        """
        try:
            if self.thisown: destroy(self)
        except: pass


class MotionMaskPtr(MotionMask):
    def __init__(self, this):
        _swig_setattr(self, MotionMask, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, MotionMask, 'thisown', 0)
        self.__class__ = MotionMask
_Piavca.MotionMask_swigregister(MotionMaskPtr)

class MaskedMotion(TwoMotionCombiner):
    """
    plays different motions on different joints.     
           
    It uses a mask to tell which motion to play on which joint.      see also: MaskedMotion.h
    """
    __swig_setmethods__ = {}
    for _s in [TwoMotionCombiner]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, MaskedMotion, name, value)
    __swig_getmethods__ = {}
    for _s in [TwoMotionCombiner]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, MaskedMotion, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::MaskedMotion instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        """
        MaskedMotion::MaskedMotion(const MaskedMotion &mm)
                 
                
                 
                
        """
        if self.__class__ == MaskedMotion:
            args = (None,) + args
        else:
            args = (self,) + args
        _swig_setattr(self, MaskedMotion, 'this', _Piavca.new_MaskedMotion(*args))
        _swig_setattr(self, MaskedMotion, 'thisown', 1)
    def clone(*args):
        """
        virtual Motion* Piavca::MaskedMotion::clone()
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca.MaskedMotion_clone(*args)

    def setUseSecondary(*args):
        """
        void Piavca::MaskedMotion::setUseSecondary(bool val)
                 
                
                 
                
        """
        return _Piavca.MaskedMotion_setUseSecondary(*args)

    def setMask1(*args):
        """
        void Piavca::MaskedMotion::setMask1(const MotionMask &mask)
                 
                
                 
                
        """
        return _Piavca.MaskedMotion_setMask1(*args)

    def setMask2(*args):
        """
        void Piavca::MaskedMotion::setMask2(const MotionMask &mask)
                 
                
                 
                
        """
        return _Piavca.MaskedMotion_setMask2(*args)

    def addToMask1(*args):
        """
        void Piavca::MaskedMotion::addToMask1(int trackId)
                 
                
                 
                
        """
        return _Piavca.MaskedMotion_addToMask1(*args)

    def removeFromMask1(*args):
        """
        void Piavca::MaskedMotion::removeFromMask1(int trackId)
                 
                
                 
                
        """
        return _Piavca.MaskedMotion_removeFromMask1(*args)

    def addToMask2(*args):
        """
        void Piavca::MaskedMotion::addToMask2(int trackId)
                 
                
                 
                
        """
        return _Piavca.MaskedMotion_addToMask2(*args)

    def removeFromMask2(*args):
        """
        void Piavca::MaskedMotion::removeFromMask2(int trackId)
                 
                
                 
                
        """
        return _Piavca.MaskedMotion_removeFromMask2(*args)

    def getFloatValueAtTimeInternal(*args):
        """
        float MaskedMotion::getFloatValueAtTimeInternal(int trackId, float time)
                 
        internal version of getFloatValueAtTime, to be overridden         
                 
                
        """
        return _Piavca.MaskedMotion_getFloatValueAtTimeInternal(*args)

    def getVecValueAtTimeInternal(*args):
        """
        Vec MaskedMotion::getVecValueAtTimeInternal(int trackId, float time)
                 
        internal version of getVecValueAtTime, to be overridden         
                 
                
        """
        return _Piavca.MaskedMotion_getVecValueAtTimeInternal(*args)

    def getQuatValueAtTimeInternal(*args):
        """
        Quat MaskedMotion::getQuatValueAtTimeInternal(int trackId, float time)
                 
        internal version of getQuatValueAtTime, to be overridden         
                 
                
        """
        return _Piavca.MaskedMotion_getQuatValueAtTimeInternal(*args)

    def __del__(self, destroy=_Piavca.delete_MaskedMotion):
        """
        plays different motions on different joints.     
               
        It uses a mask to tell which motion to play on which joint.      see also: MaskedMotion.h
        """
        try:
            if self.thisown: destroy(self)
        except: pass

    def __disown__(self):
        self.thisown = 0
        _Piavca.disown_MaskedMotion(self)
        return weakref_proxy(self)

class MaskedMotionPtr(MaskedMotion):
    def __init__(self, this):
        _swig_setattr(self, MaskedMotion, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, MaskedMotion, 'thisown', 0)
        self.__class__ = MaskedMotion
_Piavca.MaskedMotion_swigregister(MaskedMotionPtr)

class MultiMotionLoop(RandomTimingsLoop):
    """
    A loop class with a set of different motions.     
           
    One of these motions is chosen each time around the loop. This is a base class for other loop classes. It is a template so that it can either be a sub class of a normal LoopMotion or a RandomTimingsLoop (or something else)      see also: MultiMotionLoop.h
    """
    __swig_setmethods__ = {}
    for _s in [RandomTimingsLoop]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, MultiMotionLoop, name, value)
    __swig_getmethods__ = {}
    for _s in [RandomTimingsLoop]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, MultiMotionLoop, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::MultiMotionLoop instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        """
        Piavca::MultiMotionLoop::MultiMotionLoop(const MultiMotionLoop &rl)
                 
                
                 
                
        """
        _swig_setattr(self, MultiMotionLoop, 'this', _Piavca.new_MultiMotionLoop(*args))
        _swig_setattr(self, MultiMotionLoop, 'thisown', 1)
    def __del__(self, destroy=_Piavca.delete_MultiMotionLoop):
        """
        Piavca::MultiMotionLoop::~MultiMotionLoop()
                 
                
                 
                
        """
        try:
            if self.thisown: destroy(self)
        except: pass

    def clone(*args):
        """
        virtual Motion* Piavca::MultiMotionLoop::clone()
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca.MultiMotionLoop_clone(*args)

    def printInfo(*args):
        """
        void Piavca::MultiMotionLoop::printInfo()
                 
        prints out info about the motion heirarchy         
                 
                
        """
        return _Piavca.MultiMotionLoop_printInfo(*args)

    def addMotion(*args):
        """
        virtual void Piavca::MultiMotionLoop::addMotion(Motion *mot)
                 
                
                 
                
        """
        return _Piavca.MultiMotionLoop_addMotion(*args)

    def findSub(*args):
        """
        virtual Motion* Piavca::MultiMotionLoop::findSub(tstring nm)
                 
        finds the first submotion with a given name         
                 
                
        """
        return _Piavca.MultiMotionLoop_findSub(*args)

    def findSubByType(*args):
        """
        virtual Motion* Piavca::MultiMotionLoop::findSubByType(const type_info &ty)
                 
        finds the first submotion with a given type         
                 
                
        """
        return _Piavca.MultiMotionLoop_findSubByType(*args)

    def load(*args):
        """
        virtual void Piavca::MultiMotionLoop::load(Avatar *av)
                 
        called when the motion is loaded into an avatar         
                 
                
        """
        return _Piavca.MultiMotionLoop_load(*args)

    def unload(*args):
        """
        virtual void Piavca::MultiMotionLoop::unload()
                 
        called when the motion is unloaded from an avatar         
                 
                
        """
        return _Piavca.MultiMotionLoop_unload(*args)

    def loaded(*args):
        """
        virtual bool Piavca::MultiMotionLoop::loaded(Avatar *av)
                 
                
                 
                
        """
        return _Piavca.MultiMotionLoop_loaded(*args)


class MultiMotionLoopPtr(MultiMotionLoop):
    def __init__(self, this):
        _swig_setattr(self, MultiMotionLoop, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, MultiMotionLoop, 'thisown', 0)
        self.__class__ = MultiMotionLoop
_Piavca.MultiMotionLoop_swigregister(MultiMotionLoopPtr)

class ChoiceLoopMotion(MultiMotionLoop):
    """
    a MultiMotionLoop where the client can choose which motion is played     
           
         see also: ChoiceLoopMotion.h
    """
    __swig_setmethods__ = {}
    for _s in [MultiMotionLoop]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, ChoiceLoopMotion, name, value)
    __swig_getmethods__ = {}
    for _s in [MultiMotionLoop]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, ChoiceLoopMotion, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::ChoiceLoopMotion instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        """
        Piavca::ChoiceLoopMotion::ChoiceLoopMotion(const ChoiceLoopMotion &cl)
                 
                
                 
                
        """
        if self.__class__ == ChoiceLoopMotion:
            args = (None,) + args
        else:
            args = (self,) + args
        _swig_setattr(self, ChoiceLoopMotion, 'this', _Piavca.new_ChoiceLoopMotion(*args))
        _swig_setattr(self, ChoiceLoopMotion, 'thisown', 1)
    def __del__(self, destroy=_Piavca.delete_ChoiceLoopMotion):
        """
        Piavca::ChoiceLoopMotion::~ChoiceLoopMotion()
                 
                
                 
                
        """
        try:
            if self.thisown: destroy(self)
        except: pass

    def clone(*args):
        """
        virtual Motion* Piavca::ChoiceLoopMotion::clone()
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca.ChoiceLoopMotion_clone(*args)

    def setCurrentChoice(*args):
        """
        void Piavca::ChoiceLoopMotion::setCurrentChoice(tstring name)
                 
        sets which motion is currently being played (by name)         
                 
                
        """
        return _Piavca.ChoiceLoopMotion_setCurrentChoice(*args)

    def reblend(*args):
        """
        virtual void Piavca::ChoiceLoopMotion::reblend(float time)
                 
        called each time around the loop         
                 
        It can be called by the client to interrupt the current motion.         
        """
        return _Piavca.ChoiceLoopMotion_reblend(*args)

    def __disown__(self):
        self.thisown = 0
        _Piavca.disown_ChoiceLoopMotion(self)
        return weakref_proxy(self)

class ChoiceLoopMotionPtr(ChoiceLoopMotion):
    def __init__(self, this):
        _swig_setattr(self, ChoiceLoopMotion, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, ChoiceLoopMotion, 'thisown', 0)
        self.__class__ = ChoiceLoopMotion
_Piavca.ChoiceLoopMotion_swigregister(ChoiceLoopMotionPtr)

class RandomLoopMotion(ChoiceLoopMotion):
    """
    a MultiMotionLoop where a new motion is chosen each time around the loop.     
           
         see also: RandomLoopMotion.h
    """
    __swig_setmethods__ = {}
    for _s in [ChoiceLoopMotion]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, RandomLoopMotion, name, value)
    __swig_getmethods__ = {}
    for _s in [ChoiceLoopMotion]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, RandomLoopMotion, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::RandomLoopMotion instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        """
        Piavca::RandomLoopMotion::RandomLoopMotion(const RandomLoopMotion &rl)
                 
                
                 
                
        """
        if self.__class__ == RandomLoopMotion:
            args = (None,) + args
        else:
            args = (self,) + args
        _swig_setattr(self, RandomLoopMotion, 'this', _Piavca.new_RandomLoopMotion(*args))
        _swig_setattr(self, RandomLoopMotion, 'thisown', 1)
    def __del__(self, destroy=_Piavca.delete_RandomLoopMotion):
        """
        Piavca::RandomLoopMotion::~RandomLoopMotion()
                 
                
                 
                
        """
        try:
            if self.thisown: destroy(self)
        except: pass

    def clone(*args):
        """
        virtual Motion* Piavca::RandomLoopMotion::clone()
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca.RandomLoopMotion_clone(*args)

    def convertTo(*args):
        """
        static RandomLoopMotion* Piavca::RandomLoopMotion::convertTo(Motion *m)
                 
                
                 
                
        """
        return _Piavca.RandomLoopMotion_convertTo(*args)

    if _newclass:convertTo = staticmethod(convertTo)
    __swig_getmethods__["convertTo"] = lambda x: convertTo
    def addMotion(*args):
        """
        virtual void Piavca::RandomLoopMotion::addMotion(Motion *mot, float weight=1.0f)
                 
                
                 
                
        """
        return _Piavca.RandomLoopMotion_addMotion(*args)

    def setProbability(*args):
        """
        void Piavca::RandomLoopMotion::setProbability(int index, float prob)
                 
                
                 
                
        """
        return _Piavca.RandomLoopMotion_setProbability(*args)

    def reblend(*args):
        """
        virtual void Piavca::RandomLoopMotion::reblend(float time)
                 
        called each time around the loop         
                 
        It can be called by the client to interrupt the current motion.         
        """
        return _Piavca.RandomLoopMotion_reblend(*args)

    def __disown__(self):
        self.thisown = 0
        _Piavca.disown_RandomLoopMotion(self)
        return weakref_proxy(self)

class RandomLoopMotionPtr(RandomLoopMotion):
    def __init__(self, this):
        _swig_setattr(self, RandomLoopMotion, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, RandomLoopMotion, 'thisown', 0)
        self.__class__ = RandomLoopMotion
_Piavca.RandomLoopMotion_swigregister(RandomLoopMotionPtr)

def RandomLoopMotion_convertTo(*args):
    """
    static RandomLoopMotion* Piavca::RandomLoopMotion::convertTo(Motion *m)
             
            
             
            
    """
    return _Piavca.RandomLoopMotion_convertTo(*args)

class RandomBlendLoop(MultiMotionLoop):
    """
    A MultiMotionLoop which, instead of choosing one motion at a time, blends between a groups of motions.     
           
    The Motions to blend are chosen at random, as are the number of motions and the weights.      see also: RandomBlendLoop.h
    """
    __swig_setmethods__ = {}
    for _s in [MultiMotionLoop]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, RandomBlendLoop, name, value)
    __swig_getmethods__ = {}
    for _s in [MultiMotionLoop]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, RandomBlendLoop, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::RandomBlendLoop instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        """
        Piavca::RandomBlendLoop::RandomBlendLoop(const RandomBlendLoop &rbl)
                 
                
                 
                
        """
        if self.__class__ == RandomBlendLoop:
            args = (None,) + args
        else:
            args = (self,) + args
        _swig_setattr(self, RandomBlendLoop, 'this', _Piavca.new_RandomBlendLoop(*args))
        _swig_setattr(self, RandomBlendLoop, 'thisown', 1)
    def __del__(self, destroy=_Piavca.delete_RandomBlendLoop):
        """
        Piavca::RandomBlendLoop::~RandomBlendLoop()
                 
                
                 
                
        """
        try:
            if self.thisown: destroy(self)
        except: pass

    def clone(*args):
        """
        virtual Motion* Piavca::RandomBlendLoop::clone()
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca.RandomBlendLoop_clone(*args)

    def addMotion(*args):
        """
        virtual void Piavca::RandomBlendLoop::addMotion(Motion *mot, float weight)
                 
                
                 
                
        """
        return _Piavca.RandomBlendLoop_addMotion(*args)

    def setAutoShift(*args):
        """
        void Piavca::RandomBlendLoop::setAutoShift(bool b)
                 
                
                 
                
        """
        return _Piavca.RandomBlendLoop_setAutoShift(*args)

    def shift(*args):
        """
        virtual void Piavca::RandomBlendLoop::shift()
                 
                
                 
                
        """
        return _Piavca.RandomBlendLoop_shift(*args)

    def reblend(*args):
        """
        virtual void Piavca::RandomBlendLoop::reblend(float time)
                 
        called each time around the loop         
                 
        It can be called by the client to interrupt the current motion.         
        """
        return _Piavca.RandomBlendLoop_reblend(*args)

    def __disown__(self):
        self.thisown = 0
        _Piavca.disown_RandomBlendLoop(self)
        return weakref_proxy(self)

class RandomBlendLoopPtr(RandomBlendLoop):
    def __init__(self, this):
        _swig_setattr(self, RandomBlendLoop, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, RandomBlendLoop, 'thisown', 0)
        self.__class__ = RandomBlendLoop
_Piavca.RandomBlendLoop_swigregister(RandomBlendLoopPtr)

class RandomAddLoop(MultiMotionLoop):
    """
    A MultiMotionLoop which, instead of choosing one motion at a time, adds together a groups of motions.     
           
    The Motions to blend are chosen at random, as are the number of motions. Each of the motions is scaled by a random ammount before being added.      see also: RandomAddLoop.h
    """
    __swig_setmethods__ = {}
    for _s in [MultiMotionLoop]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, RandomAddLoop, name, value)
    __swig_getmethods__ = {}
    for _s in [MultiMotionLoop]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, RandomAddLoop, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::RandomAddLoop instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        """
        Piavca::RandomAddLoop::RandomAddLoop(const RandomAddLoop &rbl)
                 
                
                 
                
        """
        if self.__class__ == RandomAddLoop:
            args = (None,) + args
        else:
            args = (self,) + args
        _swig_setattr(self, RandomAddLoop, 'this', _Piavca.new_RandomAddLoop(*args))
        _swig_setattr(self, RandomAddLoop, 'thisown', 1)
    def __del__(self, destroy=_Piavca.delete_RandomAddLoop):
        """
        Piavca::RandomAddLoop::~RandomAddLoop()
                 
                
                 
                
        """
        try:
            if self.thisown: destroy(self)
        except: pass

    def clone(*args):
        """
        virtual Motion* Piavca::RandomAddLoop::clone()
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca.RandomAddLoop_clone(*args)

    def setAutoShift(*args):
        """
        void Piavca::RandomAddLoop::setAutoShift(bool b)
                 
                
                 
                
        """
        return _Piavca.RandomAddLoop_setAutoShift(*args)

    def shift(*args):
        """
        virtual void Piavca::RandomAddLoop::shift()
                 
                
                 
                
        """
        return _Piavca.RandomAddLoop_shift(*args)

    def reblend(*args):
        """
        virtual void Piavca::RandomAddLoop::reblend(float time)
                 
        called each time around the loop         
                 
        It can be called by the client to interrupt the current motion.         
        """
        return _Piavca.RandomAddLoop_reblend(*args)

    def __disown__(self):
        self.thisown = 0
        _Piavca.disown_RandomAddLoop(self)
        return weakref_proxy(self)

class RandomAddLoopPtr(RandomAddLoop):
    def __init__(self, this):
        _swig_setattr(self, RandomAddLoop, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, RandomAddLoop, 'thisown', 0)
        self.__class__ = RandomAddLoop
_Piavca.RandomAddLoop_swigregister(RandomAddLoopPtr)

class ProxemicsLoop(MultiMotionLoop):
    """
    a MultiMotionLoop that implements proxemics behaviour.     
           
    Proxemics consists in maintianing a desired personal distance to another avatar (or group of avatars) by stepping forwards or backwards. It also consists in turning to face the other avatar.      see also: ProxemicsLoop.h
    """
    __swig_setmethods__ = {}
    for _s in [MultiMotionLoop]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, ProxemicsLoop, name, value)
    __swig_getmethods__ = {}
    for _s in [MultiMotionLoop]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, ProxemicsLoop, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::ProxemicsLoop instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        """
        Piavca::ProxemicsLoop::ProxemicsLoop(const ProxemicsLoop &rl)
                 
                
                 
                
        """
        _swig_setattr(self, ProxemicsLoop, 'this', _Piavca.new_ProxemicsLoop(*args))
        _swig_setattr(self, ProxemicsLoop, 'thisown', 1)
    def __del__(self, destroy=_Piavca.delete_ProxemicsLoop):
        """
        Piavca::ProxemicsLoop::~ProxemicsLoop()
                 
                
                 
                
        """
        try:
            if self.thisown: destroy(self)
        except: pass

    def clone(*args):
        """
        virtual Motion* Piavca::ProxemicsLoop::clone()
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca.ProxemicsLoop_clone(*args)

    def setDistance(*args):
        """
        void Piavca::ProxemicsLoop::setDistance(float d)
                 
        sets the desired distance to another avatar         
                 
                
        """
        return _Piavca.ProxemicsLoop_setDistance(*args)

    def setThreshold(*args):
        """
        void Piavca::ProxemicsLoop::setThreshold(float t)
                 
        sets the threshold, the allowable error in distance before moving         
                 
                
        """
        return _Piavca.ProxemicsLoop_setThreshold(*args)

    def setAngleThreshold(*args):
        """
        void Piavca::ProxemicsLoop::setAngleThreshold(float a)
                 
        sets the threshold, the allowable error in distance before moving         
                 
                
        """
        return _Piavca.ProxemicsLoop_setAngleThreshold(*args)

    def turnOff(*args):
        """
        void Piavca::ProxemicsLoop::turnOff(bool b)
                 
        turns off maintaining distance         
                 
                
        """
        return _Piavca.ProxemicsLoop_turnOff(*args)

    def addAvatar(*args):
        """
        void Piavca::ProxemicsLoop::addAvatar(Avatar *av)
                 
        adds an avatar to perform proxemics behaviour to         
                 
                
        """
        return _Piavca.ProxemicsLoop_addAvatar(*args)

    def removeAvatar(*args):
        """
        void Piavca::ProxemicsLoop::removeAvatar(tstring name)
                 
        removes an avatar         
                 
                
        """
        return _Piavca.ProxemicsLoop_removeAvatar(*args)

    def removeAllAvatars(*args):
        """
        void Piavca::ProxemicsLoop::removeAllAvatars()
                 
        removes all avatar         
                 
                
        """
        return _Piavca.ProxemicsLoop_removeAllAvatars(*args)

    def reblend(*args):
        """
        virtual void Piavca::ProxemicsLoop::reblend(float time)
                 
        called each time through the loop         
                 
                
        """
        return _Piavca.ProxemicsLoop_reblend(*args)


class ProxemicsLoopPtr(ProxemicsLoop):
    def __init__(self, this):
        _swig_setattr(self, ProxemicsLoop, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, ProxemicsLoop, 'thisown', 0)
        self.__class__ = ProxemicsLoop
_Piavca.ProxemicsLoop_swigregister(ProxemicsLoopPtr)

class LookAtMotion(Motion):
    """
    A motion class that makes the avatar look at a target. The avatar will turn to look at the given target with eyes, head, and body. The target can either be an avatar, an object or a vector location.      see also: LookAtMotion.h
    """
    __swig_setmethods__ = {}
    for _s in [Motion]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, LookAtMotion, name, value)
    __swig_getmethods__ = {}
    for _s in [Motion]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, LookAtMotion, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::LookAtMotion instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        """
        Piavca::LookAtMotion::LookAtMotion(const LookAtMotion &lam)
                 
                
                 
                
        """
        if self.__class__ == LookAtMotion:
            args = (None,) + args
        else:
            args = (self,) + args
        _swig_setattr(self, LookAtMotion, 'this', _Piavca.new_LookAtMotion(*args))
        _swig_setattr(self, LookAtMotion, 'thisown', 1)
    def clone(*args):
        """
        virtual Motion* Piavca::LookAtMotion::clone()
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca.LookAtMotion_clone(*args)

    def isFacial(*args):
        """
        virtual bool Piavca::LookAtMotion::isFacial()
                 
        whether it is a face or body motion         
                 
                
        """
        return _Piavca.LookAtMotion_isFacial(*args)

    def isRandomAccess(*args):
        """
        virtual bool Piavca::LookAtMotion::isRandomAccess()
                 
        whether you can access a motions value at frames other than the current one         
                 
                
        """
        return _Piavca.LookAtMotion_isRandomAccess(*args)

    def load(*args):
        """
        void LookAtMotion::load(Avatar *av)
                 
        called when the motion is loaded into an avatar         
                 
                
        """
        return _Piavca.LookAtMotion_load(*args)

    def reblend(*args):
        """
        void LookAtMotion::reblend(float time)
                 
                
                 
                
        """
        return _Piavca.LookAtMotion_reblend(*args)

    def setTarget(*args):
        """
        void Piavca::LookAtMotion::setTarget(Vec target, bool _local=false)
                 
                
                 
        sets the target to a location There is also a local flag, to indicate whether the vector is local to the avatar or in world coordinates         
        """
        return _Piavca.LookAtMotion_setTarget(*args)

    def getTargetName(*args):
        """
        tstring Piavca::LookAtMotion::getTargetName()
                 
                
                 
                
        """
        return _Piavca.LookAtMotion_getTargetName(*args)

    def setHeadActive(*args):
        """
        void Piavca::LookAtMotion::setHeadActive(bool b=true)
                 
                
                 
                
        """
        return _Piavca.LookAtMotion_setHeadActive(*args)

    def setBodyActive(*args):
        """
        void Piavca::LookAtMotion::setBodyActive(bool b=true)
                 
                
                 
                
        """
        return _Piavca.LookAtMotion_setBodyActive(*args)

    def setTurnBodyVertical(*args):
        """
        void Piavca::LookAtMotion::setTurnBodyVertical(bool b=true)
                 
                
                 
                
        """
        return _Piavca.LookAtMotion_setTurnBodyVertical(*args)

    def setTurnBodyFull(*args):
        """
        void Piavca::LookAtMotion::setTurnBodyFull(bool b=true)
                 
                
                 
                
        """
        return _Piavca.LookAtMotion_setTurnBodyFull(*args)

    def setLeanTowards(*args):
        """
        void Piavca::LookAtMotion::setLeanTowards(bool b=true)
                 
                
                 
                
        """
        return _Piavca.LookAtMotion_setLeanTowards(*args)

    def setEyesLimit(*args):
        """
        void Piavca::LookAtMotion::setEyesLimit(float f)
                 
                
                 
                
        """
        return _Piavca.LookAtMotion_setEyesLimit(*args)

    def setHeadBodyLimit(*args):
        """
        void Piavca::LookAtMotion::setHeadBodyLimit(float f)
                 
                
                 
                
        """
        return _Piavca.LookAtMotion_setHeadBodyLimit(*args)

    def setEyesMorphAngle(*args):
        """
        void Piavca::LookAtMotion::setEyesMorphAngle(float f)
                 
                
                 
                
        """
        return _Piavca.LookAtMotion_setEyesMorphAngle(*args)

    def setEndTime(*args):
        """
        void Piavca::LookAtMotion::setEndTime(float time)
                 
        sets when the avatar should stop looing         
                 
                
        """
        return _Piavca.LookAtMotion_setEndTime(*args)

    def getMotionLength(*args):
        """
        virtual float Piavca::LookAtMotion::getMotionLength() const 
                 
        returns the length of the motion         
                 
                
        """
        return _Piavca.LookAtMotion_getMotionLength(*args)

    def isNull(*args):
        """
        bool Piavca::LookAtMotion::isNull(int trackId) const 
                 
        given a track ID tests whether it actually points to anything or if its null         
                 
                
        """
        return _Piavca.LookAtMotion_isNull(*args)

    def isNullFacial(*args):
        """
        bool Piavca::LookAtMotion::isNullFacial(int trackId) const 
                 
        this is a version of isNull that is used when the LookAtMotion is pretending to be facial         
                 
                
        """
        return _Piavca.LookAtMotion_isNullFacial(*args)

    def getTrackType(*args):
        """
        virtual trackType Piavca::LookAtMotion::getTrackType(int trackId) const 
                 
        get the type of the track corresponding to an ID         
                 
                
        """
        return _Piavca.LookAtMotion_getTrackType(*args)

    def canLookAt(*args):
        """
        bool LookAtMotion::canLookAt(Vec location)
                 
        works out whether the avatar can comfortably turn to look at a position         
                 
                
        """
        return _Piavca.LookAtMotion_canLookAt(*args)

    def getFloatValueAtTimeInternal(*args):
        """
        float LookAtMotion::getFloatValueAtTimeInternal(int trackId, float time)
                 
        get the value of a track at a given time (only works for floats)         
                 
                
        """
        return _Piavca.LookAtMotion_getFloatValueAtTimeInternal(*args)

    def getVecValueAtTimeInternal(*args):
        """
        Vec LookAtMotion::getVecValueAtTimeInternal(int trackId, float time)
                 
        get the value of a track at a given time (only works for Vecs)         
                 
                
        """
        return _Piavca.LookAtMotion_getVecValueAtTimeInternal(*args)

    def getQuatValueAtTimeInternal(*args):
        """
        Quat LookAtMotion::getQuatValueAtTimeInternal(int trackId, float time)
                 
        get the value of a track at a given time (only works for Quats)         
                 
                
        """
        return _Piavca.LookAtMotion_getQuatValueAtTimeInternal(*args)

    def __del__(self, destroy=_Piavca.delete_LookAtMotion):
        """
        A motion class that makes the avatar look at a target. The avatar will turn to look at the given target with eyes, head, and body. The target can either be an avatar, an object or a vector location.      see also: LookAtMotion.h
        """
        try:
            if self.thisown: destroy(self)
        except: pass

    def __disown__(self):
        self.thisown = 0
        _Piavca.disown_LookAtMotion(self)
        return weakref_proxy(self)

class LookAtMotionPtr(LookAtMotion):
    def __init__(self, this):
        _swig_setattr(self, LookAtMotion, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, LookAtMotion, 'thisown', 0)
        self.__class__ = LookAtMotion
_Piavca.LookAtMotion_swigregister(LookAtMotionPtr)

class LookAtToFacial(MotionFilter):
    """
    a motion filter that takes a LookAtMotion and pretends its a facial motion     
           
         see also: LookAtMotion.h
    """
    __swig_setmethods__ = {}
    for _s in [MotionFilter]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, LookAtToFacial, name, value)
    __swig_getmethods__ = {}
    for _s in [MotionFilter]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, LookAtToFacial, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::LookAtToFacial instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        """
        Piavca::LookAtToFacial::LookAtToFacial(const LookAtToFacial &sm)
                 
                
                 
                
        """
        _swig_setattr(self, LookAtToFacial, 'this', _Piavca.new_LookAtToFacial(*args))
        _swig_setattr(self, LookAtToFacial, 'thisown', 1)
    def clone(*args):
        """
        virtual Motion* Piavca::LookAtToFacial::clone()
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca.LookAtToFacial_clone(*args)

    def load(*args):
        """
        virtual void Piavca::LookAtToFacial::load(Avatar *av)
                 
        called when the motion is loaded into an avatar         
                 
                
        """
        return _Piavca.LookAtToFacial_load(*args)

    def isFacial(*args):
        """
        virtual bool Piavca::LookAtToFacial::isFacial()
                 
        whether it is a face or body motion         
                 
                
        """
        return _Piavca.LookAtToFacial_isFacial(*args)

    def isNull(*args):
        """
        virtual bool Piavca::LookAtToFacial::isNull(int trackId) const 
                 
        given an iterator tests whether it actually points to anything or if its null         
                 
                
        """
        return _Piavca.LookAtToFacial_isNull(*args)

    def getFloatValueAtTimeInternal(*args):
        """
        virtual PIAVCA_EXPORT float Piavca::LookAtToFacial::getFloatValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe         
                 
                
        """
        return _Piavca.LookAtToFacial_getFloatValueAtTimeInternal(*args)

    def getVecValueAtTimeInternal(*args):
        """
        virtual PIAVCA_EXPORT Vec Piavca::LookAtToFacial::getVecValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe (vec values are scaled)         
                 
                
        """
        return _Piavca.LookAtToFacial_getVecValueAtTimeInternal(*args)

    def getQuatValueAtTimeInternal(*args):
        """
        virtual PIAVCA_EXPORT Quat Piavca::LookAtToFacial::getQuatValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe         
                 
                
        """
        return _Piavca.LookAtToFacial_getQuatValueAtTimeInternal(*args)

    def __del__(self, destroy=_Piavca.delete_LookAtToFacial):
        """
        a motion filter that takes a LookAtMotion and pretends its a facial motion     
               
             see also: LookAtMotion.h
        """
        try:
            if self.thisown: destroy(self)
        except: pass


class LookAtToFacialPtr(LookAtToFacial):
    def __init__(self, this):
        _swig_setattr(self, LookAtToFacial, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, LookAtToFacial, 'thisown', 0)
        self.__class__ = LookAtToFacial
_Piavca.LookAtToFacial_swigregister(LookAtToFacialPtr)

class flagStruct(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, flagStruct, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, flagStruct, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::flagStruct instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    __swig_setmethods__["headActive"] = _Piavca.flagStruct_headActive_set
    __swig_getmethods__["headActive"] = _Piavca.flagStruct_headActive_get
    if _newclass:headActive = property(_Piavca.flagStruct_headActive_get, _Piavca.flagStruct_headActive_set)
    __swig_setmethods__["bodyActive"] = _Piavca.flagStruct_bodyActive_set
    __swig_getmethods__["bodyActive"] = _Piavca.flagStruct_bodyActive_get
    if _newclass:bodyActive = property(_Piavca.flagStruct_bodyActive_get, _Piavca.flagStruct_bodyActive_set)
    __swig_setmethods__["turnBodyVertical"] = _Piavca.flagStruct_turnBodyVertical_set
    __swig_getmethods__["turnBodyVertical"] = _Piavca.flagStruct_turnBodyVertical_get
    if _newclass:turnBodyVertical = property(_Piavca.flagStruct_turnBodyVertical_get, _Piavca.flagStruct_turnBodyVertical_set)
    __swig_setmethods__["turnBodyFull"] = _Piavca.flagStruct_turnBodyFull_set
    __swig_getmethods__["turnBodyFull"] = _Piavca.flagStruct_turnBodyFull_get
    if _newclass:turnBodyFull = property(_Piavca.flagStruct_turnBodyFull_get, _Piavca.flagStruct_turnBodyFull_set)
    __swig_setmethods__["leanTowards"] = _Piavca.flagStruct_leanTowards_set
    __swig_getmethods__["leanTowards"] = _Piavca.flagStruct_leanTowards_get
    if _newclass:leanTowards = property(_Piavca.flagStruct_leanTowards_get, _Piavca.flagStruct_leanTowards_set)
    def __init__(self, *args):
        _swig_setattr(self, flagStruct, 'this', _Piavca.new_flagStruct(*args))
        _swig_setattr(self, flagStruct, 'thisown', 1)
    def __del__(self, destroy=_Piavca.delete_flagStruct):
        try:
            if self.thisown: destroy(self)
        except: pass


class flagStructPtr(flagStruct):
    def __init__(self, this):
        _swig_setattr(self, flagStruct, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, flagStruct, 'thisown', 0)
        self.__class__ = flagStruct
_Piavca.flagStruct_swigregister(flagStructPtr)

class AvatarTargetStruct(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, AvatarTargetStruct, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, AvatarTargetStruct, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::AvatarTargetStruct instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    __swig_setmethods__["avatar"] = _Piavca.AvatarTargetStruct_avatar_set
    __swig_getmethods__["avatar"] = _Piavca.AvatarTargetStruct_avatar_get
    if _newclass:avatar = property(_Piavca.AvatarTargetStruct_avatar_get, _Piavca.AvatarTargetStruct_avatar_set)
    __swig_setmethods__["joint"] = _Piavca.AvatarTargetStruct_joint_set
    __swig_getmethods__["joint"] = _Piavca.AvatarTargetStruct_joint_get
    if _newclass:joint = property(_Piavca.AvatarTargetStruct_joint_get, _Piavca.AvatarTargetStruct_joint_set)
    __swig_setmethods__["flags"] = _Piavca.AvatarTargetStruct_flags_set
    __swig_getmethods__["flags"] = _Piavca.AvatarTargetStruct_flags_get
    if _newclass:flags = property(_Piavca.AvatarTargetStruct_flags_get, _Piavca.AvatarTargetStruct_flags_set)
    def __init__(self, *args):
        _swig_setattr(self, AvatarTargetStruct, 'this', _Piavca.new_AvatarTargetStruct(*args))
        _swig_setattr(self, AvatarTargetStruct, 'thisown', 1)
    def __del__(self, destroy=_Piavca.delete_AvatarTargetStruct):
        try:
            if self.thisown: destroy(self)
        except: pass


class AvatarTargetStructPtr(AvatarTargetStruct):
    def __init__(self, this):
        _swig_setattr(self, AvatarTargetStruct, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, AvatarTargetStruct, 'thisown', 0)
        self.__class__ = AvatarTargetStruct
_Piavca.AvatarTargetStruct_swigregister(AvatarTargetStructPtr)

class ObjectTargetStruct(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, ObjectTargetStruct, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, ObjectTargetStruct, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::ObjectTargetStruct instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    __swig_setmethods__["object"] = _Piavca.ObjectTargetStruct_object_set
    __swig_getmethods__["object"] = _Piavca.ObjectTargetStruct_object_get
    if _newclass:object = property(_Piavca.ObjectTargetStruct_object_get, _Piavca.ObjectTargetStruct_object_set)
    __swig_setmethods__["flags"] = _Piavca.ObjectTargetStruct_flags_set
    __swig_getmethods__["flags"] = _Piavca.ObjectTargetStruct_flags_get
    if _newclass:flags = property(_Piavca.ObjectTargetStruct_flags_get, _Piavca.ObjectTargetStruct_flags_set)
    def __init__(self, *args):
        _swig_setattr(self, ObjectTargetStruct, 'this', _Piavca.new_ObjectTargetStruct(*args))
        _swig_setattr(self, ObjectTargetStruct, 'thisown', 1)
    def __del__(self, destroy=_Piavca.delete_ObjectTargetStruct):
        try:
            if self.thisown: destroy(self)
        except: pass


class ObjectTargetStructPtr(ObjectTargetStruct):
    def __init__(self, this):
        _swig_setattr(self, ObjectTargetStruct, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, ObjectTargetStruct, 'thisown', 0)
        self.__class__ = ObjectTargetStruct
_Piavca.ObjectTargetStruct_swigregister(ObjectTargetStructPtr)

class RandomGazeMotion(LoopMotion):
    """
    see also: RandomGazeMotion.h
    """
    __swig_setmethods__ = {}
    for _s in [LoopMotion]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, RandomGazeMotion, name, value)
    __swig_getmethods__ = {}
    for _s in [LoopMotion]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, RandomGazeMotion, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::RandomGazeMotion instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        """
        Piavca::RandomGazeMotion::RandomGazeMotion(const RandomGazeMotion &rg)
                 
                
                 
                
        """
        if self.__class__ == RandomGazeMotion:
            args = (None,) + args
        else:
            args = (self,) + args
        _swig_setattr(self, RandomGazeMotion, 'this', _Piavca.new_RandomGazeMotion(*args))
        _swig_setattr(self, RandomGazeMotion, 'thisown', 1)
    def __del__(self, destroy=_Piavca.delete_RandomGazeMotion):
        """
        Piavca::RandomGazeMotion::~RandomGazeMotion()
                 
                
                 
                
        """
        try:
            if self.thisown: destroy(self)
        except: pass

    def clone(*args):
        """
        virtual Motion* Piavca::RandomGazeMotion::clone()
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca.RandomGazeMotion_clone(*args)

    def clearDirectionTable(*args):
        """
        void Piavca::RandomGazeMotion::clearDirectionTable()
                 
                
                 
                
        """
        return _Piavca.RandomGazeMotion_clearDirectionTable(*args)

    def addDirection(*args):
        """
        void Piavca::RandomGazeMotion::addDirection(const Vec &dir, float prob)
                 
                
                 
                
        """
        return _Piavca.RandomGazeMotion_addDirection(*args)

    def normaliseDirectionTable(*args):
        """
        void Piavca::RandomGazeMotion::normaliseDirectionTable()
                 
                
                 
                
        """
        return _Piavca.RandomGazeMotion_normaliseDirectionTable(*args)

    def addAvatarTarget(*args):
        """
        void Piavca::RandomGazeMotion::addAvatarTarget(Avatar *av, int joint, flagStruct f=flagStruct())
                 
                
                 
                
        """
        return _Piavca.RandomGazeMotion_addAvatarTarget(*args)

    def addObjectTarget(*args):
        """
        void Piavca::RandomGazeMotion::addObjectTarget(Object *obj, flagStruct f=flagStruct())
                 
                
                 
                
        """
        return _Piavca.RandomGazeMotion_addObjectTarget(*args)

    def setTargetFlags(*args):
        """
        void Piavca::RandomGazeMotion::setTargetFlags(tstring name, flagStruct flags)
                 
                
                 
                
        """
        return _Piavca.RandomGazeMotion_setTargetFlags(*args)

    def setGazeParams(*args):
        """
        void Piavca::RandomGazeMotion::setGazeParams(float coeff, float divisor)
                 
                
                 
                
        """
        return _Piavca.RandomGazeMotion_setGazeParams(*args)

    def setLookAtLocationProb(*args):
        """
        void Piavca::RandomGazeMotion::setLookAtLocationProb(float prob)
                 
                
                 
                
        """
        return _Piavca.RandomGazeMotion_setLookAtLocationProb(*args)

    def setMeanGazeLength(*args):
        """
        void Piavca::RandomGazeMotion::setMeanGazeLength(float f)
                 
                
                 
                
        """
        return _Piavca.RandomGazeMotion_setMeanGazeLength(*args)

    def setEyesLimit(*args):
        """
        void Piavca::RandomGazeMotion::setEyesLimit(float f)
                 
                
                 
                
        """
        return _Piavca.RandomGazeMotion_setEyesLimit(*args)

    def setHeadBodyLimit(*args):
        """
        void Piavca::RandomGazeMotion::setHeadBodyLimit(float f)
                 
                
                 
                
        """
        return _Piavca.RandomGazeMotion_setHeadBodyLimit(*args)

    def setEyesMorphAngle(*args):
        """
        void Piavca::RandomGazeMotion::setEyesMorphAngle(float f)
                 
                
                 
                
        """
        return _Piavca.RandomGazeMotion_setEyesMorphAngle(*args)

    def randomLocation(*args):
        """
        Vec Piavca::RandomGazeMotion::randomLocation()
                 
                
                 
                
        """
        return _Piavca.RandomGazeMotion_randomLocation(*args)

    def lookAt(*args):
        """
        virtual bool Piavca::RandomGazeMotion::lookAt(tstring name, bool force=false)
                 
                
                 
                
        """
        return _Piavca.RandomGazeMotion_lookAt(*args)

    def reblend(*args):
        """
        virtual void Piavca::RandomGazeMotion::reblend(float time)
                 
        saves the state of the motion at time and start blending the motion back into that from the start         
                 
                
        """
        return _Piavca.RandomGazeMotion_reblend(*args)

    def __disown__(self):
        self.thisown = 0
        _Piavca.disown_RandomGazeMotion(self)
        return weakref_proxy(self)

class RandomGazeMotionPtr(RandomGazeMotion):
    def __init__(self, this):
        _swig_setattr(self, RandomGazeMotion, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, RandomGazeMotion, 'thisown', 0)
        self.__class__ = RandomGazeMotion
_Piavca.RandomGazeMotion_swigregister(RandomGazeMotionPtr)

class ZeroMotion(Motion):
    """
    A motion class that makes the avatar look at a target. The avatar will turn to look at the given target with eyes, head, and body. The target can either be an avatar, an object or a vector location.      see also: ZeroMotion.h
    """
    __swig_setmethods__ = {}
    for _s in [Motion]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, ZeroMotion, name, value)
    __swig_getmethods__ = {}
    for _s in [Motion]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, ZeroMotion, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::ZeroMotion instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        """
        Piavca::ZeroMotion::ZeroMotion(const ZeroMotion &zm)
                 
                
                 
                
        """
        if self.__class__ == ZeroMotion:
            args = (None,) + args
        else:
            args = (self,) + args
        _swig_setattr(self, ZeroMotion, 'this', _Piavca.new_ZeroMotion(*args))
        _swig_setattr(self, ZeroMotion, 'thisown', 1)
    def clone(*args):
        """
        virtual Motion* Piavca::ZeroMotion::clone()
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca.ZeroMotion_clone(*args)

    def isFacial(*args):
        """
        virtual bool Piavca::ZeroMotion::isFacial()
                 
        whether it is a face or body motion         
                 
                
        """
        return _Piavca.ZeroMotion_isFacial(*args)

    def isRandomAccess(*args):
        """
        virtual bool Piavca::ZeroMotion::isRandomAccess()
                 
        whether you can access a motions value at frames other than the current one         
                 
                
        """
        return _Piavca.ZeroMotion_isRandomAccess(*args)

    def getMotionLength(*args):
        """
        virtual float Piavca::ZeroMotion::getMotionLength() const 
                 
        returns the length of the motion         
                 
                
        """
        return _Piavca.ZeroMotion_getMotionLength(*args)

    def isNull(*args):
        """
        bool Piavca::ZeroMotion::isNull(int trackId) const 
                 
        given a track ID tests whether it actually points to anything or if its null         
                 
                
        """
        return _Piavca.ZeroMotion_isNull(*args)

    def getTrackType(*args):
        """
        virtual trackType Piavca::ZeroMotion::getTrackType(int trackId) const 
                 
        get the type of the track corresponding to an ID         
                 
                
        """
        return _Piavca.ZeroMotion_getTrackType(*args)

    def getFloatValueAtTimeInternal(*args):
        """
        virtual float Piavca::ZeroMotion::getFloatValueAtTimeInternal(int trackId, float time)
                 
        get the value of a track at a given time (only works for floats)         
                 
                
        """
        return _Piavca.ZeroMotion_getFloatValueAtTimeInternal(*args)

    def getVecValueAtTimeInternal(*args):
        """
        virtual Vec Piavca::ZeroMotion::getVecValueAtTimeInternal(int trackId, float time)
                 
        get the value of a track at a given time (only works for Vecs)         
                 
                
        """
        return _Piavca.ZeroMotion_getVecValueAtTimeInternal(*args)

    def getQuatValueAtTimeInternal(*args):
        """
        virtual Quat Piavca::ZeroMotion::getQuatValueAtTimeInternal(int trackId, float time)
                 
        get the value of a track at a given time (only works for Quats)         
                 
                
        """
        return _Piavca.ZeroMotion_getQuatValueAtTimeInternal(*args)

    def __del__(self, destroy=_Piavca.delete_ZeroMotion):
        """
        A motion class that makes the avatar look at a target. The avatar will turn to look at the given target with eyes, head, and body. The target can either be an avatar, an object or a vector location.      see also: ZeroMotion.h
        """
        try:
            if self.thisown: destroy(self)
        except: pass

    def __disown__(self):
        self.thisown = 0
        _Piavca.disown_ZeroMotion(self)
        return weakref_proxy(self)

class ZeroMotionPtr(ZeroMotion):
    def __init__(self, this):
        _swig_setattr(self, ZeroMotion, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, ZeroMotion, 'thisown', 0)
        self.__class__ = ZeroMotion
_Piavca.ZeroMotion_swigregister(ZeroMotionPtr)

class MotionSaver(MotionFilter):
    """
    Saves the kefyrames of a motion while its playing on a character This sits between a motion and a character passing the data unchanged between the two, but it also saves the data as keyframes. Call save to save it to file in the Piavca (.pia) format      see also: MotionSaver.h
    """
    __swig_setmethods__ = {}
    for _s in [MotionFilter]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, MotionSaver, name, value)
    __swig_getmethods__ = {}
    for _s in [MotionFilter]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, MotionSaver, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::MotionSaver instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        """
        Piavca::MotionSaver::MotionSaver(const MotionSaver &to)
                 
                
                 
                
        """
        if self.__class__ == MotionSaver:
            args = (None,) + args
        else:
            args = (self,) + args
        _swig_setattr(self, MotionSaver, 'this', _Piavca.new_MotionSaver(*args))
        _swig_setattr(self, MotionSaver, 'thisown', 1)
    def clone(*args):
        """
        virtual Motion* Piavca::MotionSaver::clone()
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca.MotionSaver_clone(*args)

    def getFloatValueAtTimeInternal(*args):
        """
        PIAVCA_EXPORT float MotionSaver::getFloatValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of the filter motion on and saves them to a TrackMotion         
                 
                
        """
        return _Piavca.MotionSaver_getFloatValueAtTimeInternal(*args)

    def getVecValueAtTimeInternal(*args):
        """
        PIAVCA_EXPORT Vec MotionSaver::getVecValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of the filter motion on and saves them to a TrackMotion         
                 
                
        """
        return _Piavca.MotionSaver_getVecValueAtTimeInternal(*args)

    def getQuatValueAtTimeInternal(*args):
        """
        PIAVCA_EXPORT Quat MotionSaver::getQuatValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of the filter motion on and saves them to a TrackMotion         
                 
                
        """
        return _Piavca.MotionSaver_getQuatValueAtTimeInternal(*args)

    def collectFrames(*args):
        """
        PIAVCA_EXPORT void MotionSaver::collectFrames(float framerate)
                 
        runs through the motion storing frame at the given framerate         
                 
                
        """
        return _Piavca.MotionSaver_collectFrames(*args)

    def save(*args):
        """
        PIAVCA_EXPORT void MotionSaver::save(tstring filename)
                 
                
                 
                
        """
        return _Piavca.MotionSaver_save(*args)

    def __del__(self, destroy=_Piavca.delete_MotionSaver):
        """
        Saves the kefyrames of a motion while its playing on a character This sits between a motion and a character passing the data unchanged between the two, but it also saves the data as keyframes. Call save to save it to file in the Piavca (.pia) format      see also: MotionSaver.h
        """
        try:
            if self.thisown: destroy(self)
        except: pass

    def __disown__(self):
        self.thisown = 0
        _Piavca.disown_MotionSaver(self)
        return weakref_proxy(self)

class MotionSaverPtr(MotionSaver):
    def __init__(self, this):
        _swig_setattr(self, MotionSaver, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, MotionSaver, 'thisown', 0)
        self.__class__ = MotionSaver
_Piavca.MotionSaver_swigregister(MotionSaverPtr)

class MotionParser(_object):
    """
    see also: MotionParser.h
    """
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, MotionParser, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, MotionParser, name)
    def __init__(self): raise RuntimeError, "No constructor defined"
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::MotionParser instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def editMotion(*args):
        """
        virtual Piavca::Motion* Piavca::MotionParser::editMotion(istringstream &is)=0
                 
                
                 
                
        """
        return _Piavca.MotionParser_editMotion(*args)

    def editAvatarMotion(*args):
        """
        virtual void Piavca::MotionParser::editAvatarMotion(Avatar *av, bool facial, istringstream &is)=0
                 
                
                 
                
        """
        return _Piavca.MotionParser_editAvatarMotion(*args)

    def parseMotion(*args):
        """
        PIAVCA_DECL Piavca::Motion * MotionParser::parseMotion(istringstream &is, std::string currentWord, float scaleFactor, MotionParser **mp)
                 
                
                 
                
        """
        return _Piavca.MotionParser_parseMotion(*args)

    if _newclass:parseMotion = staticmethod(parseMotion)
    __swig_getmethods__["parseMotion"] = lambda x: parseMotion
    def addMotionCommand(*args):
        """
        void MotionParser::addMotionCommand(tstring name, MotionParser *command)
                 
                
                 
                
        """
        return _Piavca.MotionParser_addMotionCommand(*args)

    if _newclass:addMotionCommand = staticmethod(addMotionCommand)
    __swig_getmethods__["addMotionCommand"] = lambda x: addMotionCommand
    def getMotionCommand(*args):
        """
        MotionParser * MotionParser::getMotionCommand(tstring name)
                 
                
                 
                
        """
        return _Piavca.MotionParser_getMotionCommand(*args)

    if _newclass:getMotionCommand = staticmethod(getMotionCommand)
    __swig_getmethods__["getMotionCommand"] = lambda x: getMotionCommand
    def setUpMotionCommands(*args):
        """
        void MotionParser::setUpMotionCommands()
                 
                
                 
                
        """
        return _Piavca.MotionParser_setUpMotionCommands(*args)

    if _newclass:setUpMotionCommands = staticmethod(setUpMotionCommands)
    __swig_getmethods__["setUpMotionCommands"] = lambda x: setUpMotionCommands
    def __del__(self, destroy=_Piavca.delete_MotionParser):
        """
        see also: MotionParser.h
        """
        try:
            if self.thisown: destroy(self)
        except: pass


class MotionParserPtr(MotionParser):
    def __init__(self, this):
        _swig_setattr(self, MotionParser, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, MotionParser, 'thisown', 0)
        self.__class__ = MotionParser
_Piavca.MotionParser_swigregister(MotionParserPtr)

def MotionParser_parseMotion(*args):
    """
    PIAVCA_DECL Piavca::Motion * MotionParser::parseMotion(istringstream &is, std::string currentWord, float scaleFactor, MotionParser **mp)
             
            
             
            
    """
    return _Piavca.MotionParser_parseMotion(*args)

def MotionParser_addMotionCommand(*args):
    """
    void MotionParser::addMotionCommand(tstring name, MotionParser *command)
             
            
             
            
    """
    return _Piavca.MotionParser_addMotionCommand(*args)

def MotionParser_getMotionCommand(*args):
    """
    MotionParser * MotionParser::getMotionCommand(tstring name)
             
            
             
            
    """
    return _Piavca.MotionParser_getMotionCommand(*args)

def MotionParser_setUpMotionCommands(*args):
    """
    void MotionParser::setUpMotionCommands()
             
            
             
            
    """
    return _Piavca.MotionParser_setUpMotionCommands(*args)

class SubMotion(MotionFilter):
    """
    see also: SubMotion.h
    """
    __swig_setmethods__ = {}
    for _s in [MotionFilter]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, SubMotion, name, value)
    __swig_getmethods__ = {}
    for _s in [MotionFilter]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, SubMotion, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::SubMotion instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        """
        SubMotion::SubMotion(const SubMotion &sm)
                 
                
                 
                
        """
        if self.__class__ == SubMotion:
            args = (None,) + args
        else:
            args = (self,) + args
        _swig_setattr(self, SubMotion, 'this', _Piavca.new_SubMotion(*args))
        _swig_setattr(self, SubMotion, 'thisown', 1)
    def clone(*args):
        """
        Motion * SubMotion::clone()
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca.SubMotion_clone(*args)

    def getMotionLength(*args):
        """
        float SubMotion::getMotionLength() const 
                 
        gets the length of the motion in seconds         
                 
                
        """
        return _Piavca.SubMotion_getMotionLength(*args)

    def setStart(*args):
        """
        void SubMotion::setStart(float s)
                 
        Sets the start of the range to be played.         
                 
                
        """
        return _Piavca.SubMotion_setStart(*args)

    def setEnd(*args):
        """
        void SubMotion::setEnd(float e)
                 
        Sets the end of the range to be played.         
                 
                
        """
        return _Piavca.SubMotion_setEnd(*args)

    def getFloatValueAtTimeInternal(*args):
        """
        PIAVCA_EXPORT float SubMotion::getFloatValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe         
                 
                
        """
        return _Piavca.SubMotion_getFloatValueAtTimeInternal(*args)

    def getVecValueAtTimeInternal(*args):
        """
        PIAVCA_EXPORT Vec SubMotion::getVecValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe         
                 
                
        """
        return _Piavca.SubMotion_getVecValueAtTimeInternal(*args)

    def getQuatValueAtTimeInternal(*args):
        """
        PIAVCA_EXPORT Quat SubMotion::getQuatValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe         
                 
                
        """
        return _Piavca.SubMotion_getQuatValueAtTimeInternal(*args)

    def __del__(self, destroy=_Piavca.delete_SubMotion):
        """
        see also: SubMotion.h
        """
        try:
            if self.thisown: destroy(self)
        except: pass

    def __disown__(self):
        self.thisown = 0
        _Piavca.disown_SubMotion(self)
        return weakref_proxy(self)

class SubMotionPtr(SubMotion):
    def __init__(self, this):
        _swig_setattr(self, SubMotion, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, SubMotion, 'thisown', 0)
        self.__class__ = SubMotion
_Piavca.SubMotion_swigregister(SubMotionPtr)

class TimeRangeMotion(MotionFilter):
    """
    see also: TimeRangeMotion.h
    """
    __swig_setmethods__ = {}
    for _s in [MotionFilter]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, TimeRangeMotion, name, value)
    __swig_getmethods__ = {}
    for _s in [MotionFilter]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, TimeRangeMotion, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::TimeRangeMotion instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        """
        TimeRangeMotion::TimeRangeMotion(const TimeRangeMotion &sm)
                 
                
                 
                
        """
        if self.__class__ == TimeRangeMotion:
            args = (None,) + args
        else:
            args = (self,) + args
        _swig_setattr(self, TimeRangeMotion, 'this', _Piavca.new_TimeRangeMotion(*args))
        _swig_setattr(self, TimeRangeMotion, 'thisown', 1)
    def clone(*args):
        """
        Motion * TimeRangeMotion::clone()
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca.TimeRangeMotion_clone(*args)

    def setStart(*args):
        """
        void TimeRangeMotion::setStart(float s)
                 
        Sets the start of the range to be played.         
                 
                
        """
        return _Piavca.TimeRangeMotion_setStart(*args)

    def setEnd(*args):
        """
        void TimeRangeMotion::setEnd(float e)
                 
        Sets the end of the range to be played.         
                 
                
        """
        return _Piavca.TimeRangeMotion_setEnd(*args)

    def getFloatValueAtTimeInternal(*args):
        """
        PIAVCA_EXPORT float TimeRangeMotion::getFloatValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe         
                 
                
        """
        return _Piavca.TimeRangeMotion_getFloatValueAtTimeInternal(*args)

    def getVecValueAtTimeInternal(*args):
        """
        PIAVCA_EXPORT Vec TimeRangeMotion::getVecValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe         
                 
                
        """
        return _Piavca.TimeRangeMotion_getVecValueAtTimeInternal(*args)

    def getQuatValueAtTimeInternal(*args):
        """
        PIAVCA_EXPORT Quat TimeRangeMotion::getQuatValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe         
                 
                
        """
        return _Piavca.TimeRangeMotion_getQuatValueAtTimeInternal(*args)

    def __del__(self, destroy=_Piavca.delete_TimeRangeMotion):
        """
        see also: TimeRangeMotion.h
        """
        try:
            if self.thisown: destroy(self)
        except: pass

    def __disown__(self):
        self.thisown = 0
        _Piavca.disown_TimeRangeMotion(self)
        return weakref_proxy(self)

class TimeRangeMotionPtr(TimeRangeMotion):
    def __init__(self, this):
        _swig_setattr(self, TimeRangeMotion, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, TimeRangeMotion, 'thisown', 0)
        self.__class__ = TimeRangeMotion
_Piavca.TimeRangeMotion_swigregister(TimeRangeMotionPtr)

class TimeWarp(MotionFilter):
    """
    a motion filter that scales the motion's speed     
           
         see also: TimeWarp.h
    """
    __swig_setmethods__ = {}
    for _s in [MotionFilter]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, TimeWarp, name, value)
    __swig_getmethods__ = {}
    for _s in [MotionFilter]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, TimeWarp, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::TimeWarp instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        """
        Piavca::TimeWarp::TimeWarp(const TimeWarp &tw)
                 
                
                 
                
        """
        if self.__class__ == TimeWarp:
            args = (None,) + args
        else:
            args = (self,) + args
        _swig_setattr(self, TimeWarp, 'this', _Piavca.new_TimeWarp(*args))
        _swig_setattr(self, TimeWarp, 'thisown', 1)
    def clone(*args):
        """
        virtual Motion* Piavca::TimeWarp::clone()
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca.TimeWarp_clone(*args)

    def getMotionLength(*args):
        """
        virtual float Piavca::TimeWarp::getMotionLength() const 
                 
        gets the length of the motion in seconds         
                 
                
        """
        return _Piavca.TimeWarp_getMotionLength(*args)

    def getFloatValueAtTimeInternal(*args):
        """
        virtual PIAVCA_EXPORT float Piavca::TimeWarp::getFloatValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe         
                 
                
        """
        return _Piavca.TimeWarp_getFloatValueAtTimeInternal(*args)

    def getVecValueAtTimeInternal(*args):
        """
        virtual PIAVCA_EXPORT Vec Piavca::TimeWarp::getVecValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe         
                 
                
        """
        return _Piavca.TimeWarp_getVecValueAtTimeInternal(*args)

    def getQuatValueAtTimeInternal(*args):
        """
        virtual PIAVCA_EXPORT Quat Piavca::TimeWarp::getQuatValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe         
                 
                
        """
        return _Piavca.TimeWarp_getQuatValueAtTimeInternal(*args)

    def setWarp(*args):
        """
        void Piavca::TimeWarp::setWarp(Motion *warp)
                 
        Sets the scale factor for the postion components of the motion.         
                 
                
        """
        return _Piavca.TimeWarp_setWarp(*args)

    def __del__(self, destroy=_Piavca.delete_TimeWarp):
        """
        a motion filter that scales the motion's speed     
               
             see also: TimeWarp.h
        """
        try:
            if self.thisown: destroy(self)
        except: pass

    def __disown__(self):
        self.thisown = 0
        _Piavca.disown_TimeWarp(self)
        return weakref_proxy(self)

class TimeWarpPtr(TimeWarp):
    def __init__(self, this):
        _swig_setattr(self, TimeWarp, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, TimeWarp, 'thisown', 0)
        self.__class__ = TimeWarp
_Piavca.TimeWarp_swigregister(TimeWarpPtr)

class DiadicGazeMotion(RandomGazeMotion):
    """
    see also: DiadicGazeMotion.h
    """
    __swig_setmethods__ = {}
    for _s in [RandomGazeMotion]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, DiadicGazeMotion, name, value)
    __swig_getmethods__ = {}
    for _s in [RandomGazeMotion]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, DiadicGazeMotion, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::DiadicGazeMotion instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    talking = _Piavca.DiadicGazeMotion_talking
    listening = _Piavca.DiadicGazeMotion_listening
    neither = _Piavca.DiadicGazeMotion_neither
    def __init__(self, *args):
        """
        Piavca::DiadicGazeMotion::DiadicGazeMotion(const DiadicGazeMotion &dg)
                 
                
                 
                
        """
        if self.__class__ == DiadicGazeMotion:
            args = (None,) + args
        else:
            args = (self,) + args
        _swig_setattr(self, DiadicGazeMotion, 'this', _Piavca.new_DiadicGazeMotion(*args))
        _swig_setattr(self, DiadicGazeMotion, 'thisown', 1)
    def __del__(self, destroy=_Piavca.delete_DiadicGazeMotion):
        """
        Piavca::DiadicGazeMotion::~DiadicGazeMotion()
                 
                
                 
                
        """
        try:
            if self.thisown: destroy(self)
        except: pass

    def clone(*args):
        """
        virtual Motion* Piavca::DiadicGazeMotion::clone()
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca.DiadicGazeMotion_clone(*args)

    def setTalking(*args):
        """
        void Piavca::DiadicGazeMotion::setTalking(talkingstate t)
                 
                
                 
                
        """
        return _Piavca.DiadicGazeMotion_setTalking(*args)

    def setTalkingLookAt(*args):
        """
        void Piavca::DiadicGazeMotion::setTalkingLookAt(float f)
                 
                
                 
                
        """
        return _Piavca.DiadicGazeMotion_setTalkingLookAt(*args)

    def setTalkingLookAway(*args):
        """
        void Piavca::DiadicGazeMotion::setTalkingLookAway(float f)
                 
                
                 
                
        """
        return _Piavca.DiadicGazeMotion_setTalkingLookAway(*args)

    def setListeningLookAt(*args):
        """
        void Piavca::DiadicGazeMotion::setListeningLookAt(float f)
                 
                
                 
                
        """
        return _Piavca.DiadicGazeMotion_setListeningLookAt(*args)

    def setListeningLookAway(*args):
        """
        void Piavca::DiadicGazeMotion::setListeningLookAway(float f)
                 
                
                 
                
        """
        return _Piavca.DiadicGazeMotion_setListeningLookAway(*args)

    def setNeitherLookAt(*args):
        """
        void Piavca::DiadicGazeMotion::setNeitherLookAt(float f)
                 
                
                 
                
        """
        return _Piavca.DiadicGazeMotion_setNeitherLookAt(*args)

    def setNeitherLookAway(*args):
        """
        void Piavca::DiadicGazeMotion::setNeitherLookAway(float f)
                 
                
                 
                
        """
        return _Piavca.DiadicGazeMotion_setNeitherLookAway(*args)

    def setGazeFollow(*args):
        """
        void Piavca::DiadicGazeMotion::setGazeFollow(float f)
                 
                
                 
                
        """
        return _Piavca.DiadicGazeMotion_setGazeFollow(*args)

    def setOther(*args):
        """
        void Piavca::DiadicGazeMotion::setOther(Avatar *other)
                 
                
                 
                
        """
        return _Piavca.DiadicGazeMotion_setOther(*args)

    def getOther(*args):
        """
        Avatar* Piavca::DiadicGazeMotion::getOther()
                 
                
                 
                
        """
        return _Piavca.DiadicGazeMotion_getOther(*args)

    def addGazeFollowTarget(*args):
        """
        void Piavca::DiadicGazeMotion::addGazeFollowTarget(tstring name)
                 
                
                 
                
        """
        return _Piavca.DiadicGazeMotion_addGazeFollowTarget(*args)

    def notifyChange(*args):
        """
        void Piavca::DiadicGazeMotion::notifyChange(tstring target)
                 
                
                 
                
        """
        return _Piavca.DiadicGazeMotion_notifyChange(*args)

    def lookAt(*args):
        """
        virtual bool Piavca::DiadicGazeMotion::lookAt(tstring name, bool force=false)
                 
                
                 
                
        """
        return _Piavca.DiadicGazeMotion_lookAt(*args)

    def reblend(*args):
        """
        virtual void Piavca::DiadicGazeMotion::reblend(float time)
                 
        saves the state of the motion at time and start blending the motion back into that from the start         
                 
                
        """
        return _Piavca.DiadicGazeMotion_reblend(*args)

    def __disown__(self):
        self.thisown = 0
        _Piavca.disown_DiadicGazeMotion(self)
        return weakref_proxy(self)

class DiadicGazeMotionPtr(DiadicGazeMotion):
    def __init__(self, this):
        _swig_setattr(self, DiadicGazeMotion, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, DiadicGazeMotion, 'thisown', 0)
        self.__class__ = DiadicGazeMotion
_Piavca.DiadicGazeMotion_swigregister(DiadicGazeMotionPtr)



