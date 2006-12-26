# This file was created automatically by SWIG 1.3.30.
# Don't modify this file, modify the SWIG interface instead.
# This file is compatible with both classic and new-style classes.

import _Piavca
import new
new_instancemethod = new.instancemethod
try:
    _swig_property = property
except NameError:
    pass # Python < 2.2 doesn't have 'property'.
def _swig_setattr_nondynamic(self,class_type,name,value,static=1):
    if (name == "thisown"): return self.this.own(value)
    if (name == "this"):
        if type(value).__name__ == 'PySwigObject':
            self.__dict__[name] = value
            return
    method = class_type.__swig_setmethods__.get(name,None)
    if method: return method(self,value)
    if (not static) or hasattr(self,name):
        self.__dict__[name] = value
    else:
        raise AttributeError("You cannot add attributes to %s" % self)

def _swig_setattr(self,class_type,name,value):
    return _swig_setattr_nondynamic(self,class_type,name,value,0)

def _swig_getattr(self,class_type,name):
    if (name == "thisown"): return self.this.own()
    method = class_type.__swig_getmethods__.get(name,None)
    if method: return method(self)
    raise AttributeError,name

def _swig_repr(self):
    try: strthis = "proxy of " + self.this.__repr__()
    except: strthis = ""
    return "<%s.%s; %s >" % (self.__class__.__module__, self.__class__.__name__, strthis,)

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
        this = _Piavca.new_Vec(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca.delete_Vec
    __del__ = lambda self : None;
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
Vec_swigregister = _Piavca.Vec_swigregister
Vec_swigregister(Vec)
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
        this = _Piavca.new_Quat(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca.delete_Quat
    __del__ = lambda self : None;
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
Quat_swigregister = _Piavca.Quat_swigregister
Quat_swigregister(Quat)
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
    __repr__ = _swig_repr
    def __init__(self, *args): 
        """
        Piavca::TimeCallback::TimeCallback(tstring _name)
                 
                
                 
                
        """
        if self.__class__ == TimeCallback:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_TimeCallback(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca.delete_TimeCallback
    __del__ = lambda self : None;
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
        self.this.disown()
        _Piavca.disown_TimeCallback(self)
        return weakref_proxy(self)
TimeCallback_swigregister = _Piavca.TimeCallback_swigregister
TimeCallback_swigregister(TimeCallback)

class AvatarTimeCallback(_object):
    """
    A callback that is called by the API every frame on an avatar.     
           
    It is very similar to the TimeCallback class but the changeTime method takes an avatar which can be updated.      see also: TimeCallback.h
    """
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, AvatarTimeCallback, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, AvatarTimeCallback, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        """
        Piavca::AvatarTimeCallback::AvatarTimeCallback(tstring _name)
                 
                
                 
                
        """
        if self.__class__ == AvatarTimeCallback:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_AvatarTimeCallback(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca.delete_AvatarTimeCallback
    __del__ = lambda self : None;
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
        self.this.disown()
        _Piavca.disown_AvatarTimeCallback(self)
        return weakref_proxy(self)
AvatarTimeCallback_swigregister = _Piavca.AvatarTimeCallback_swigregister
AvatarTimeCallback_swigregister(AvatarTimeCallback)

class Core(_object):
    """
    The core object is the central controller of the Piavca system.     
           
    It maintains a list of avatars, and some motions. It has a list of global callbacks that are called every frame. It handles allocation of Joint IDs. It deals with initialisation and shut down and per frame events. It also manages creation of avatar and motions. There is only ever one core object (held as the core static member of the class).      see also: PiavcaCore.h
    """
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Core, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Core, name)
    def __init__(self): raise AttributeError, "No constructor defined"
    __repr__ = _swig_repr
    __swig_setmethods__["dir"] = _Piavca.Core_dir_set
    __swig_getmethods__["dir"] = _Piavca.Core_dir_get
    if _newclass:dir = _swig_property(_Piavca.Core_dir_get, _Piavca.Core_dir_set)
    __swig_destroy__ = _Piavca.delete_Core
    __del__ = lambda self : None;
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

    def output(*args): return _Piavca.Core_output(*args)
    def message(*args): return _Piavca.Core_message(*args)
    def getMessages(*args): return _Piavca.Core_getMessages(*args)
Core_swigregister = _Piavca.Core_swigregister
Core_swigregister(Core)

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
    __repr__ = _swig_repr
    def __init__(self, *args): 
        """
        Piavca::Motion::Motion(const Motion &mot)
                 
                
                 
                
        """
        if self.__class__ == Motion:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_Motion(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca.delete_Motion
    __del__ = lambda self : None;
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
        self.this.disown()
        _Piavca.disown_Motion(self)
        return weakref_proxy(self)
Motion_swigregister = _Piavca.Motion_swigregister
Motion_swigregister(Motion)

class KeyframeMotion(Motion):
    __swig_setmethods__ = {}
    for _s in [Motion]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, KeyframeMotion, name, value)
    __swig_getmethods__ = {}
    for _s in [Motion]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, KeyframeMotion, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        if self.__class__ == KeyframeMotion:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_KeyframeMotion(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca.delete_KeyframeMotion
    __del__ = lambda self : None;
    def clone(*args):
        """
        virtual Motion* Piavca::Motion::clone()=0
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca.KeyframeMotion_clone(*args)

    def getMotionLength(*args):
        """
        virtual float Piavca::Motion::getMotionLength() const =0
                 
        gets the time of the end of the motion         
                 
        Though time is represented in floating point, keyframes can only be set as integers to avoid problems with rounding errors. The granularity is the conversion factor between the two.         
        """
        return _Piavca.KeyframeMotion_getMotionLength(*args)

    def isFacial(*args):
        """
        virtual bool Piavca::Motion::isFacial()
                 
        whether it is a face or body motion         
                 
                
        """
        return _Piavca.KeyframeMotion_isFacial(*args)

    def isRandomAccess(*args):
        """
        virtual bool Piavca::Motion::isRandomAccess()
                 
        whether you can access a motions value at frames other than the current one         
                 
                
        """
        return _Piavca.KeyframeMotion_isRandomAccess(*args)

    def isNull(*args):
        """
        virtual bool Piavca::Motion::isNull(int trackId) const =0
                 
        given a track ID tests whether it actually points to anything or if its null         
                 
                
        """
        return _Piavca.KeyframeMotion_isNull(*args)

    def getTrackType(*args):
        """
        virtual trackType Piavca::Motion::getTrackType(int trackId) const =0
                 
        get the type of the track corresponding to an ID         
                 
                
        """
        return _Piavca.KeyframeMotion_getTrackType(*args)

    def addFloatTrack(*args): return _Piavca.KeyframeMotion_addFloatTrack(*args)
    def addVecTrack(*args): return _Piavca.KeyframeMotion_addVecTrack(*args)
    def addQuatTrack(*args): return _Piavca.KeyframeMotion_addQuatTrack(*args)
    def setFloatKeyframe(*args): return _Piavca.KeyframeMotion_setFloatKeyframe(*args)
    def setVecKeyframe(*args): return _Piavca.KeyframeMotion_setVecKeyframe(*args)
    def setQuatKeyframe(*args): return _Piavca.KeyframeMotion_setQuatKeyframe(*args)
    def getNumKeyframes(*args): return _Piavca.KeyframeMotion_getNumKeyframes(*args)
    def getKeyframeTime(*args): return _Piavca.KeyframeMotion_getKeyframeTime(*args)
    def getFloatValueAtTimeInternal(*args):
        """
        virtual float Piavca::Motion::getFloatValueAtTimeInternal(int trackId, float time)=0
                 
        internal version of getFloatValueAtTime, to be overridden         
                 
                
        """
        return _Piavca.KeyframeMotion_getFloatValueAtTimeInternal(*args)

    def getVecValueAtTimeInternal(*args):
        """
        virtual Vec Piavca::Motion::getVecValueAtTimeInternal(int trackId, float time)=0
                 
        internal version of getVecValueAtTime, to be overridden         
                 
                
        """
        return _Piavca.KeyframeMotion_getVecValueAtTimeInternal(*args)

    def getQuatValueAtTimeInternal(*args):
        """
        virtual Quat Piavca::Motion::getQuatValueAtTimeInternal(int trackId, float time)=0
                 
        internal version of getQuatValueAtTime, to be overridden         
                 
                
        """
        return _Piavca.KeyframeMotion_getQuatValueAtTimeInternal(*args)

    def deleteAllTracks(*args): return _Piavca.KeyframeMotion_deleteAllTracks(*args)
    def clearTrack(*args): return _Piavca.KeyframeMotion_clearTrack(*args)
    def clearAllTracks(*args): return _Piavca.KeyframeMotion_clearAllTracks(*args)
    def __disown__(self):
        self.this.disown()
        _Piavca.disown_KeyframeMotion(self)
        return weakref_proxy(self)
KeyframeMotion_swigregister = _Piavca.KeyframeMotion_swigregister
KeyframeMotion_swigregister(KeyframeMotion)


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
    __repr__ = _swig_repr
    def __init__(self, *args): 
        """
        Avatar::Avatar(tstring avatarId, bool bailOnMissedJoints=false, const Vec &Position=Vec(0.0, 0.0, 0.0), const Quat &Orientation=Quat(1.0, 0.0, 0.0, 0.0), const Vec &forwardDir=Vec(0.0, 0.0, 1.0))
                 
        create an avatar         
                 
        The avatar needs to be initialised with an implementation. The type of the implementation depends on the platform and so it cannot be created directly in platform independant code. To get around this it is created by a static factory method in the which itself uses the Piavca::Core class and its platform dependent implementation to create the implementation of the avatar. The constructor needs an identifier string that it uses to find platform specific data needed to create the avatar, for example the mesh file. The user can also pass in a position and orientation for the avatar. If bail on missed joints is true it will fail to create the avatar if not all the needed joints are present in the model and will result in an invalid avatar (this can be tested with the isValid method).         
        """
        this = _Piavca.new_Avatar(*args)
        try: self.this.append(this)
        except: self.this = this
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
Avatar_swigregister = _Piavca.Avatar_swigregister
Avatar_swigregister(Avatar)

class queueElement(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, queueElement, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, queueElement, name)
    __repr__ = _swig_repr
    __swig_setmethods__["mot"] = _Piavca.queueElement_mot_set
    __swig_getmethods__["mot"] = _Piavca.queueElement_mot_get
    if _newclass:mot = _swig_property(_Piavca.queueElement_mot_get, _Piavca.queueElement_mot_set)
    __swig_setmethods__["name"] = _Piavca.queueElement_name_set
    __swig_getmethods__["name"] = _Piavca.queueElement_name_get
    if _newclass:name = _swig_property(_Piavca.queueElement_name_get, _Piavca.queueElement_name_set)
    __swig_setmethods__["atTime"] = _Piavca.queueElement_atTime_set
    __swig_getmethods__["atTime"] = _Piavca.queueElement_atTime_get
    if _newclass:atTime = _swig_property(_Piavca.queueElement_atTime_get, _Piavca.queueElement_atTime_set)
    __swig_setmethods__["background"] = _Piavca.queueElement_background_set
    __swig_getmethods__["background"] = _Piavca.queueElement_background_get
    if _newclass:background = _swig_property(_Piavca.queueElement_background_get, _Piavca.queueElement_background_set)
    def __init__(self, *args): 
        this = _Piavca.new_queueElement(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca.delete_queueElement
    __del__ = lambda self : None;
queueElement_swigregister = _Piavca.queueElement_swigregister
queueElement_swigregister(queueElement)

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
    __repr__ = _swig_repr
    def __init__(self, *args): 
        """
        Piavca::AvatarMotionQueue::AvatarMotionQueue(const AvatarMotionQueue &amq)
                 
                
                 
                
        """
        this = _Piavca.new_AvatarMotionQueue(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca.delete_AvatarMotionQueue
    __del__ = lambda self : None;
    __swig_getmethods__["getQueue"] = lambda x: _Piavca.AvatarMotionQueue_getQueue
    if _newclass:getQueue = staticmethod(_Piavca.AvatarMotionQueue_getQueue)
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

AvatarMotionQueue_swigregister = _Piavca.AvatarMotionQueue_swigregister
AvatarMotionQueue_swigregister(AvatarMotionQueue)
AvatarMotionQueue_getQueue = _Piavca.AvatarMotionQueue_getQueue

class Object(_object):
    """
    A class for representing inanimate objects in PIAVCA.     
           
    This works much like an avatar, except its only got a root and not joints/facial exprssions.      see also: Object.h
    """
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Object, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Object, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        """
        Piavca::Object::Object(tstring objectId, const Vec &Position=Vec(0.0, 0.0, 0.0), const Quat &Orientation=Quat(1.0, 0.0, 0.0, 0.0))
                 
        create an object         
                 
        The object needs to be initialised with an implementation. The type of the implementation depends on the platform and so it cannot be created directly in platform independant code. To get around this it is created by a static factory method in the which itself uses the Piavca::Core class and its platform dependent implementation to create the implementation of the avatar. The constructor needs an identifier string that it uses to find platform specific data needed to create the avatar, for example the mesh file. The user can also pass in a position and orientation for the object.         
        """
        this = _Piavca.new_Object(*args)
        try: self.this.append(this)
        except: self.this = this
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

Object_swigregister = _Piavca.Object_swigregister
Object_swigregister(Object)

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
    __repr__ = _swig_repr
    def __init__(self, *args): 
        """
        Piavca::PyTimeCallback::PyTimeCallback(PyObject *pyCallback, tstring name)
                 
                
                 
                
        """
        this = _Piavca.new_PyTimeCallback(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca.delete_PyTimeCallback
    __del__ = lambda self : None;
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

PyTimeCallback_swigregister = _Piavca.PyTimeCallback_swigregister
PyTimeCallback_swigregister(PyTimeCallback)

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
    __repr__ = _swig_repr
    def __init__(self, *args): 
        """
        Piavca::PyAvatarTimeCallback::PyAvatarTimeCallback(PyObject *pyCallback, tstring name)
                 
                
                 
                
        """
        this = _Piavca.new_PyAvatarTimeCallback(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca.delete_PyAvatarTimeCallback
    __del__ = lambda self : None;
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

PyAvatarTimeCallback_swigregister = _Piavca.PyAvatarTimeCallback_swigregister
PyAvatarTimeCallback_swigregister(PyAvatarTimeCallback)

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
    __repr__ = _swig_repr
    def __init__(self, *args): 
        """
        Piavca::PyMotion::PyMotion(const PyMotion &pm)
                 
                
                 
                
        """
        this = _Piavca.new_PyMotion(*args)
        try: self.this.append(this)
        except: self.this = this
    def clone(*args):
        """
        Motion* Piavca::PyMotion::clone()
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca.PyMotion_clone(*args)

    __swig_destroy__ = _Piavca.delete_PyMotion
    __del__ = lambda self : None;
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

PyMotion_swigregister = _Piavca.PyMotion_swigregister
PyMotion_swigregister(PyMotion)


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
    def __init__(self): raise AttributeError, "No constructor defined"
    __repr__ = _swig_repr
    __swig_destroy__ = _Piavca.delete_MotionFilter
    __del__ = lambda self : None;
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

    def getFloatValueAtTimeInternal(*args):
        """
        virtual float Piavca::Motion::getFloatValueAtTimeInternal(int trackId, float time)=0
                 
        internal version of getFloatValueAtTime, to be overridden         
                 
                
        """
        return _Piavca.MotionFilter_getFloatValueAtTimeInternal(*args)

    def getVecValueAtTimeInternal(*args):
        """
        virtual Vec Piavca::Motion::getVecValueAtTimeInternal(int trackId, float time)=0
                 
        internal version of getVecValueAtTime, to be overridden         
                 
                
        """
        return _Piavca.MotionFilter_getVecValueAtTimeInternal(*args)

    def getQuatValueAtTimeInternal(*args):
        """
        virtual Quat Piavca::Motion::getQuatValueAtTimeInternal(int trackId, float time)=0
                 
        internal version of getQuatValueAtTime, to be overridden         
                 
                
        """
        return _Piavca.MotionFilter_getQuatValueAtTimeInternal(*args)

MotionFilter_swigregister = _Piavca.MotionFilter_swigregister
MotionFilter_swigregister(MotionFilter)
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
    __repr__ = _swig_repr
    def __init__(self, *args): 
        """
        TwoMotionCombiner::TwoMotionCombiner(const TwoMotionCombiner &tmc)
                 
                
                 
                
        """
        if self.__class__ == TwoMotionCombiner:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_TwoMotionCombiner(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca.delete_TwoMotionCombiner
    __del__ = lambda self : None;
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
        self.this.disown()
        _Piavca.disown_TwoMotionCombiner(self)
        return weakref_proxy(self)
TwoMotionCombiner_swigregister = _Piavca.TwoMotionCombiner_swigregister
TwoMotionCombiner_swigregister(TwoMotionCombiner)

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
    __repr__ = _swig_repr
    def __init__(self, *args): 
        """
        Piavca::ScaleMotion::ScaleMotion(const ScaleMotion &sm)
                 
                
                 
                
        """
        if self.__class__ == ScaleMotion:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_ScaleMotion(*args)
        try: self.this.append(this)
        except: self.this = this
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

    __swig_destroy__ = _Piavca.delete_ScaleMotion
    __del__ = lambda self : None;
    def __disown__(self):
        self.this.disown()
        _Piavca.disown_ScaleMotion(self)
        return weakref_proxy(self)
ScaleMotion_swigregister = _Piavca.ScaleMotion_swigregister
ScaleMotion_swigregister(ScaleMotion)

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
    __repr__ = _swig_repr
    def __init__(self, *args): 
        """
        Piavca::ScaleMotionSpeed::ScaleMotionSpeed(const ScaleMotionSpeed &sm)
                 
                
                 
                
        """
        if self.__class__ == ScaleMotionSpeed:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_ScaleMotionSpeed(*args)
        try: self.this.append(this)
        except: self.this = this
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

    __swig_destroy__ = _Piavca.delete_ScaleMotionSpeed
    __del__ = lambda self : None;
    def __disown__(self):
        self.this.disown()
        _Piavca.disown_ScaleMotionSpeed(self)
        return weakref_proxy(self)
ScaleMotionSpeed_swigregister = _Piavca.ScaleMotionSpeed_swigregister
ScaleMotionSpeed_swigregister(ScaleMotionSpeed)

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
    __repr__ = _swig_repr
    def __init__(self, *args): 
        """
        Piavca::ScaleMotionRoot::ScaleMotionRoot(const ScaleMotionRoot &sm)
                 
                
                 
                
        """
        if self.__class__ == ScaleMotionRoot:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_ScaleMotionRoot(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca.delete_ScaleMotionRoot
    __del__ = lambda self : None;
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
        self.this.disown()
        _Piavca.disown_ScaleMotionRoot(self)
        return weakref_proxy(self)
ScaleMotionRoot_swigregister = _Piavca.ScaleMotionRoot_swigregister
ScaleMotionRoot_swigregister(ScaleMotionRoot)

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
    __repr__ = _swig_repr
    def __init__(self, *args): 
        """
        Piavca::TimeOffset::TimeOffset(const TimeOffset &to)
                 
                
                 
                
        """
        if self.__class__ == TimeOffset:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_TimeOffset(*args)
        try: self.this.append(this)
        except: self.this = this
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

    __swig_destroy__ = _Piavca.delete_TimeOffset
    __del__ = lambda self : None;
    def __disown__(self):
        self.this.disown()
        _Piavca.disown_TimeOffset(self)
        return weakref_proxy(self)
TimeOffset_swigregister = _Piavca.TimeOffset_swigregister
TimeOffset_swigregister(TimeOffset)

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
    __repr__ = _swig_repr
    def __init__(self, *args): 
        """
        Piavca::TurnMotion::TurnMotion(const TurnMotion &tm)
                 
                
                 
                
        """
        if self.__class__ == TurnMotion:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_TurnMotion(*args)
        try: self.this.append(this)
        except: self.this = this
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

    __swig_destroy__ = _Piavca.delete_TurnMotion
    __del__ = lambda self : None;
    def __disown__(self):
        self.this.disown()
        _Piavca.disown_TurnMotion(self)
        return weakref_proxy(self)
TurnMotion_swigregister = _Piavca.TurnMotion_swigregister
TurnMotion_swigregister(TurnMotion)

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
    __repr__ = _swig_repr
    def __init__(self, *args): 
        """
        Piavca::SequentialBlend::SequentialBlend(const SequentialBlend &sb)
                 
                
                 
                
        """
        if self.__class__ == SequentialBlend:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_SequentialBlend(*args)
        try: self.this.append(this)
        except: self.this = this
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

    __swig_destroy__ = _Piavca.delete_SequentialBlend
    __del__ = lambda self : None;
    def __disown__(self):
        self.this.disown()
        _Piavca.disown_SequentialBlend(self)
        return weakref_proxy(self)
SequentialBlend_swigregister = _Piavca.SequentialBlend_swigregister
SequentialBlend_swigregister(SequentialBlend)

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
    __repr__ = _swig_repr
    def __init__(self, *args): 
        """
        Piavca::SelfBlend::SelfBlend(const SelfBlend &sb)
                 
                
                 
                
        """
        if self.__class__ == SelfBlend:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_SelfBlend(*args)
        try: self.this.append(this)
        except: self.this = this
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

    def getMotion(*args): return _Piavca.SelfBlend_getMotion(*args)
    __swig_destroy__ = _Piavca.delete_SelfBlend
    __del__ = lambda self : None;
    def __disown__(self):
        self.this.disown()
        _Piavca.disown_SelfBlend(self)
        return weakref_proxy(self)
SelfBlend_swigregister = _Piavca.SelfBlend_swigregister
SelfBlend_swigregister(SelfBlend)

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
    __repr__ = _swig_repr
    def __init__(self, *args): 
        """
        Piavca::LoopMotion::LoopMotion(const LoopMotion &l)
                 
                
                 
                
        """
        if self.__class__ == LoopMotion:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_LoopMotion(*args)
        try: self.this.append(this)
        except: self.this = this
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

    __swig_destroy__ = _Piavca.delete_LoopMotion
    __del__ = lambda self : None;
    def __disown__(self):
        self.this.disown()
        _Piavca.disown_LoopMotion(self)
        return weakref_proxy(self)
LoopMotion_swigregister = _Piavca.LoopMotion_swigregister
LoopMotion_swigregister(LoopMotion)

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
    __repr__ = _swig_repr
    def __init__(self, *args): 
        """
        Piavca::RandomTimingsLoop::RandomTimingsLoop(const RandomTimingsLoop &rtl)
                 
                
                 
                
        """
        if self.__class__ == RandomTimingsLoop:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_RandomTimingsLoop(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca.delete_RandomTimingsLoop
    __del__ = lambda self : None;
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
        self.this.disown()
        _Piavca.disown_RandomTimingsLoop(self)
        return weakref_proxy(self)
RandomTimingsLoop_swigregister = _Piavca.RandomTimingsLoop_swigregister
RandomTimingsLoop_swigregister(RandomTimingsLoop)

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
    __repr__ = _swig_repr
    def __init__(self, *args): 
        """
        Piavca::AvatarPostureBlend::AvatarPostureBlend(const AvatarPostureBlend &apb)
                 
                
                 
                
        """
        this = _Piavca.new_AvatarPostureBlend(*args)
        try: self.this.append(this)
        except: self.this = this
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

    __swig_destroy__ = _Piavca.delete_AvatarPostureBlend
    __del__ = lambda self : None;
AvatarPostureBlend_swigregister = _Piavca.AvatarPostureBlend_swigregister
AvatarPostureBlend_swigregister(AvatarPostureBlend)

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
    __repr__ = _swig_repr
    def __init__(self, *args): 
        """
        BlendBetween::BlendBetween(const BlendBetween &b)
                 
                
                 
                
        """
        if self.__class__ == BlendBetween:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_BlendBetween(*args)
        try: self.this.append(this)
        except: self.this = this
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

    __swig_destroy__ = _Piavca.delete_BlendBetween
    __del__ = lambda self : None;
    def __disown__(self):
        self.this.disown()
        _Piavca.disown_BlendBetween(self)
        return weakref_proxy(self)
BlendBetween_swigregister = _Piavca.BlendBetween_swigregister
BlendBetween_swigregister(BlendBetween)

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
    __repr__ = _swig_repr
    def __init__(self, *args): 
        """
        Piavca::MotionAdder::MotionAdder(const MotionAdder &ma)
                 
                
                 
                
        """
        if self.__class__ == MotionAdder:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_MotionAdder(*args)
        try: self.this.append(this)
        except: self.this = this
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

    __swig_destroy__ = _Piavca.delete_MotionAdder
    __del__ = lambda self : None;
    def __disown__(self):
        self.this.disown()
        _Piavca.disown_MotionAdder(self)
        return weakref_proxy(self)
MotionAdder_swigregister = _Piavca.MotionAdder_swigregister
MotionAdder_swigregister(MotionAdder)

class MotionMask(_object):
    """
    a set of masks specifying which joints should be played in a masked motion     
           
         see also: MaskedMotion.h
    """
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, MotionMask, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, MotionMask, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        """
        MotionMask::MotionMask(const MotionMask &mm)
                 
                
                 
                
        """
        this = _Piavca.new_MotionMask(*args)
        try: self.this.append(this)
        except: self.this = this
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

    __swig_destroy__ = _Piavca.delete_MotionMask
    __del__ = lambda self : None;
MotionMask_swigregister = _Piavca.MotionMask_swigregister
MotionMask_swigregister(MotionMask)

class MaskedMotion(MotionFilter):
    """
    plays different motions on different joints.     
           
    It uses a mask to tell which motion to play on which joint.      see also: MaskedMotion.h
    """
    __swig_setmethods__ = {}
    for _s in [MotionFilter]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, MaskedMotion, name, value)
    __swig_getmethods__ = {}
    for _s in [MotionFilter]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, MaskedMotion, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        """
        MaskedMotion::MaskedMotion(const MaskedMotion &mm)
                 
                
                 
                
        """
        if self.__class__ == MaskedMotion:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_MaskedMotion(*args)
        try: self.this.append(this)
        except: self.this = this
    def clone(*args):
        """
        virtual Motion* Piavca::MaskedMotion::clone()
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca.MaskedMotion_clone(*args)

    def setMask(*args): return _Piavca.MaskedMotion_setMask(*args)
    def addToMask(*args): return _Piavca.MaskedMotion_addToMask(*args)
    def removeFromMask(*args): return _Piavca.MaskedMotion_removeFromMask(*args)
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

    __swig_destroy__ = _Piavca.delete_MaskedMotion
    __del__ = lambda self : None;
    def __disown__(self):
        self.this.disown()
        _Piavca.disown_MaskedMotion(self)
        return weakref_proxy(self)
MaskedMotion_swigregister = _Piavca.MaskedMotion_swigregister
MaskedMotion_swigregister(MaskedMotion)

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
    __repr__ = _swig_repr
    def __init__(self, *args): 
        """
        Piavca::MultiMotionLoop::MultiMotionLoop(const MultiMotionLoop &rl)
                 
                
                 
                
        """
        this = _Piavca.new_MultiMotionLoop(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca.delete_MultiMotionLoop
    __del__ = lambda self : None;
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

MultiMotionLoop_swigregister = _Piavca.MultiMotionLoop_swigregister
MultiMotionLoop_swigregister(MultiMotionLoop)

class ChoiceLoopMotion(RandomTimingsLoop):
    """
    a MultiMotionLoop where the client can choose which motion is played     
           
         see also: ChoiceLoopMotion.h
    """
    __swig_setmethods__ = {}
    for _s in [RandomTimingsLoop]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, ChoiceLoopMotion, name, value)
    __swig_getmethods__ = {}
    for _s in [RandomTimingsLoop]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, ChoiceLoopMotion, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        """
        Piavca::ChoiceLoopMotion::ChoiceLoopMotion(const ChoiceLoopMotion &cl)
                 
                
                 
                
        """
        if self.__class__ == ChoiceLoopMotion:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_ChoiceLoopMotion(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca.delete_ChoiceLoopMotion
    __del__ = lambda self : None;
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

    def addMotion(*args): return _Piavca.ChoiceLoopMotion_addMotion(*args)
    def __disown__(self):
        self.this.disown()
        _Piavca.disown_ChoiceLoopMotion(self)
        return weakref_proxy(self)
ChoiceLoopMotion_swigregister = _Piavca.ChoiceLoopMotion_swigregister
ChoiceLoopMotion_swigregister(ChoiceLoopMotion)

class RandomLoopMotion(RandomTimingsLoop):
    """
    a MultiMotionLoop where a new motion is chosen each time around the loop.     
           
         see also: RandomLoopMotion.h
    """
    __swig_setmethods__ = {}
    for _s in [RandomTimingsLoop]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, RandomLoopMotion, name, value)
    __swig_getmethods__ = {}
    for _s in [RandomTimingsLoop]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, RandomLoopMotion, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        """
        Piavca::RandomLoopMotion::RandomLoopMotion(const RandomLoopMotion &rl)
                 
                
                 
                
        """
        if self.__class__ == RandomLoopMotion:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_RandomLoopMotion(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca.delete_RandomLoopMotion
    __del__ = lambda self : None;
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

    def shift(*args): return _Piavca.RandomLoopMotion_shift(*args)
    def __disown__(self):
        self.this.disown()
        _Piavca.disown_RandomLoopMotion(self)
        return weakref_proxy(self)
RandomLoopMotion_swigregister = _Piavca.RandomLoopMotion_swigregister
RandomLoopMotion_swigregister(RandomLoopMotion)

def RandomLoopMotion_convertTo(*args):
  """
    static RandomLoopMotion* Piavca::RandomLoopMotion::convertTo(Motion *m)
             
            
             
            
    """
  return _Piavca.RandomLoopMotion_convertTo(*args)

class RandomBlendLoop(RandomTimingsLoop):
    """
    A MultiMotionLoop which, instead of choosing one motion at a time, blends between a groups of motions.     
           
    The Motions to blend are chosen at random, as are the number of motions and the weights.      see also: RandomBlendLoop.h
    """
    __swig_setmethods__ = {}
    for _s in [RandomTimingsLoop]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, RandomBlendLoop, name, value)
    __swig_getmethods__ = {}
    for _s in [RandomTimingsLoop]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, RandomBlendLoop, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        """
        Piavca::RandomBlendLoop::RandomBlendLoop(const RandomBlendLoop &rbl)
                 
                
                 
                
        """
        if self.__class__ == RandomBlendLoop:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_RandomBlendLoop(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca.delete_RandomBlendLoop
    __del__ = lambda self : None;
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

    def shift(*args):
        """
        virtual void Piavca::RandomBlendLoop::shift()
                 
                
                 
                
        """
        return _Piavca.RandomBlendLoop_shift(*args)

    def __disown__(self):
        self.this.disown()
        _Piavca.disown_RandomBlendLoop(self)
        return weakref_proxy(self)
RandomBlendLoop_swigregister = _Piavca.RandomBlendLoop_swigregister
RandomBlendLoop_swigregister(RandomBlendLoop)

class RandomAddLoop(RandomTimingsLoop):
    """
    A MultiMotionLoop which, instead of choosing one motion at a time, adds together a groups of motions.     
           
    The Motions to blend are chosen at random, as are the number of motions. Each of the motions is scaled by a random ammount before being added.      see also: RandomAddLoop.h
    """
    __swig_setmethods__ = {}
    for _s in [RandomTimingsLoop]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, RandomAddLoop, name, value)
    __swig_getmethods__ = {}
    for _s in [RandomTimingsLoop]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, RandomAddLoop, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        """
        Piavca::RandomAddLoop::RandomAddLoop(const RandomAddLoop &rbl)
                 
                
                 
                
        """
        if self.__class__ == RandomAddLoop:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_RandomAddLoop(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca.delete_RandomAddLoop
    __del__ = lambda self : None;
    def clone(*args):
        """
        virtual Motion* Piavca::RandomAddLoop::clone()
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca.RandomAddLoop_clone(*args)

    def addMotion(*args): return _Piavca.RandomAddLoop_addMotion(*args)
    def shift(*args):
        """
        virtual void Piavca::RandomAddLoop::shift()
                 
                
                 
                
        """
        return _Piavca.RandomAddLoop_shift(*args)

    def __disown__(self):
        self.this.disown()
        _Piavca.disown_RandomAddLoop(self)
        return weakref_proxy(self)
RandomAddLoop_swigregister = _Piavca.RandomAddLoop_swigregister
RandomAddLoop_swigregister(RandomAddLoop)

class ProxemicsLoop(RandomTimingsLoop):
    """
    a MultiMotionLoop that implements proxemics behaviour.     
           
    Proxemics consists in maintianing a desired personal distance to another avatar (or group of avatars) by stepping forwards or backwards. It also consists in turning to face the other avatar.      see also: ProxemicsLoop.h
    """
    __swig_setmethods__ = {}
    for _s in [RandomTimingsLoop]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, ProxemicsLoop, name, value)
    __swig_getmethods__ = {}
    for _s in [RandomTimingsLoop]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, ProxemicsLoop, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        """
        Piavca::ProxemicsLoop::ProxemicsLoop(const ProxemicsLoop &rl)
                 
                
                 
                
        """
        this = _Piavca.new_ProxemicsLoop(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca.delete_ProxemicsLoop
    __del__ = lambda self : None;
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

ProxemicsLoop_swigregister = _Piavca.ProxemicsLoop_swigregister
ProxemicsLoop_swigregister(ProxemicsLoop)

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
    __repr__ = _swig_repr
    def __init__(self, *args): 
        """
        Piavca::LookAtMotion::LookAtMotion(const LookAtMotion &lam)
                 
                
                 
                
        """
        if self.__class__ == LookAtMotion:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_LookAtMotion(*args)
        try: self.this.append(this)
        except: self.this = this
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

    __swig_destroy__ = _Piavca.delete_LookAtMotion
    __del__ = lambda self : None;
    def __disown__(self):
        self.this.disown()
        _Piavca.disown_LookAtMotion(self)
        return weakref_proxy(self)
LookAtMotion_swigregister = _Piavca.LookAtMotion_swigregister
LookAtMotion_swigregister(LookAtMotion)

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
    __repr__ = _swig_repr
    def __init__(self, *args): 
        """
        Piavca::LookAtToFacial::LookAtToFacial(const LookAtToFacial &sm)
                 
                
                 
                
        """
        this = _Piavca.new_LookAtToFacial(*args)
        try: self.this.append(this)
        except: self.this = this
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

    __swig_destroy__ = _Piavca.delete_LookAtToFacial
    __del__ = lambda self : None;
LookAtToFacial_swigregister = _Piavca.LookAtToFacial_swigregister
LookAtToFacial_swigregister(LookAtToFacial)

class flagStruct(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, flagStruct, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, flagStruct, name)
    __repr__ = _swig_repr
    __swig_setmethods__["headActive"] = _Piavca.flagStruct_headActive_set
    __swig_getmethods__["headActive"] = _Piavca.flagStruct_headActive_get
    if _newclass:headActive = _swig_property(_Piavca.flagStruct_headActive_get, _Piavca.flagStruct_headActive_set)
    __swig_setmethods__["bodyActive"] = _Piavca.flagStruct_bodyActive_set
    __swig_getmethods__["bodyActive"] = _Piavca.flagStruct_bodyActive_get
    if _newclass:bodyActive = _swig_property(_Piavca.flagStruct_bodyActive_get, _Piavca.flagStruct_bodyActive_set)
    __swig_setmethods__["turnBodyVertical"] = _Piavca.flagStruct_turnBodyVertical_set
    __swig_getmethods__["turnBodyVertical"] = _Piavca.flagStruct_turnBodyVertical_get
    if _newclass:turnBodyVertical = _swig_property(_Piavca.flagStruct_turnBodyVertical_get, _Piavca.flagStruct_turnBodyVertical_set)
    __swig_setmethods__["turnBodyFull"] = _Piavca.flagStruct_turnBodyFull_set
    __swig_getmethods__["turnBodyFull"] = _Piavca.flagStruct_turnBodyFull_get
    if _newclass:turnBodyFull = _swig_property(_Piavca.flagStruct_turnBodyFull_get, _Piavca.flagStruct_turnBodyFull_set)
    __swig_setmethods__["leanTowards"] = _Piavca.flagStruct_leanTowards_set
    __swig_getmethods__["leanTowards"] = _Piavca.flagStruct_leanTowards_get
    if _newclass:leanTowards = _swig_property(_Piavca.flagStruct_leanTowards_get, _Piavca.flagStruct_leanTowards_set)
    def __init__(self, *args): 
        this = _Piavca.new_flagStruct(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca.delete_flagStruct
    __del__ = lambda self : None;
flagStruct_swigregister = _Piavca.flagStruct_swigregister
flagStruct_swigregister(flagStruct)

class AvatarTargetStruct(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, AvatarTargetStruct, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, AvatarTargetStruct, name)
    __repr__ = _swig_repr
    __swig_setmethods__["avatar"] = _Piavca.AvatarTargetStruct_avatar_set
    __swig_getmethods__["avatar"] = _Piavca.AvatarTargetStruct_avatar_get
    if _newclass:avatar = _swig_property(_Piavca.AvatarTargetStruct_avatar_get, _Piavca.AvatarTargetStruct_avatar_set)
    __swig_setmethods__["joint"] = _Piavca.AvatarTargetStruct_joint_set
    __swig_getmethods__["joint"] = _Piavca.AvatarTargetStruct_joint_get
    if _newclass:joint = _swig_property(_Piavca.AvatarTargetStruct_joint_get, _Piavca.AvatarTargetStruct_joint_set)
    __swig_setmethods__["flags"] = _Piavca.AvatarTargetStruct_flags_set
    __swig_getmethods__["flags"] = _Piavca.AvatarTargetStruct_flags_get
    if _newclass:flags = _swig_property(_Piavca.AvatarTargetStruct_flags_get, _Piavca.AvatarTargetStruct_flags_set)
    def __init__(self, *args): 
        this = _Piavca.new_AvatarTargetStruct(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca.delete_AvatarTargetStruct
    __del__ = lambda self : None;
AvatarTargetStruct_swigregister = _Piavca.AvatarTargetStruct_swigregister
AvatarTargetStruct_swigregister(AvatarTargetStruct)

class ObjectTargetStruct(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, ObjectTargetStruct, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, ObjectTargetStruct, name)
    __repr__ = _swig_repr
    __swig_setmethods__["object"] = _Piavca.ObjectTargetStruct_object_set
    __swig_getmethods__["object"] = _Piavca.ObjectTargetStruct_object_get
    if _newclass:object = _swig_property(_Piavca.ObjectTargetStruct_object_get, _Piavca.ObjectTargetStruct_object_set)
    __swig_setmethods__["flags"] = _Piavca.ObjectTargetStruct_flags_set
    __swig_getmethods__["flags"] = _Piavca.ObjectTargetStruct_flags_get
    if _newclass:flags = _swig_property(_Piavca.ObjectTargetStruct_flags_get, _Piavca.ObjectTargetStruct_flags_set)
    def __init__(self, *args): 
        this = _Piavca.new_ObjectTargetStruct(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca.delete_ObjectTargetStruct
    __del__ = lambda self : None;
ObjectTargetStruct_swigregister = _Piavca.ObjectTargetStruct_swigregister
ObjectTargetStruct_swigregister(ObjectTargetStruct)

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
    __repr__ = _swig_repr
    def __init__(self, *args): 
        """
        Piavca::RandomGazeMotion::RandomGazeMotion(const RandomGazeMotion &rg)
                 
                
                 
                
        """
        if self.__class__ == RandomGazeMotion:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_RandomGazeMotion(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca.delete_RandomGazeMotion
    __del__ = lambda self : None;
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
        self.this.disown()
        _Piavca.disown_RandomGazeMotion(self)
        return weakref_proxy(self)
RandomGazeMotion_swigregister = _Piavca.RandomGazeMotion_swigregister
RandomGazeMotion_swigregister(RandomGazeMotion)

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
    __repr__ = _swig_repr
    def __init__(self, *args): 
        """
        Piavca::ZeroMotion::ZeroMotion(const ZeroMotion &zm)
                 
                
                 
                
        """
        if self.__class__ == ZeroMotion:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_ZeroMotion(*args)
        try: self.this.append(this)
        except: self.this = this
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

    __swig_destroy__ = _Piavca.delete_ZeroMotion
    __del__ = lambda self : None;
    def __disown__(self):
        self.this.disown()
        _Piavca.disown_ZeroMotion(self)
        return weakref_proxy(self)
ZeroMotion_swigregister = _Piavca.ZeroMotion_swigregister
ZeroMotion_swigregister(ZeroMotion)

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
    __repr__ = _swig_repr
    def __init__(self, *args): 
        """
        Piavca::MotionSaver::MotionSaver(const MotionSaver &to)
                 
                
                 
                
        """
        if self.__class__ == MotionSaver:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_MotionSaver(*args)
        try: self.this.append(this)
        except: self.this = this
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

    __swig_destroy__ = _Piavca.delete_MotionSaver
    __del__ = lambda self : None;
    def __disown__(self):
        self.this.disown()
        _Piavca.disown_MotionSaver(self)
        return weakref_proxy(self)
MotionSaver_swigregister = _Piavca.MotionSaver_swigregister
MotionSaver_swigregister(MotionSaver)

class MotionParser(_object):
    """
    see also: MotionParser.h
    """
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, MotionParser, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, MotionParser, name)
    def __init__(self): raise AttributeError, "No constructor defined"
    __repr__ = _swig_repr
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
    __swig_destroy__ = _Piavca.delete_MotionParser
    __del__ = lambda self : None;
MotionParser_swigregister = _Piavca.MotionParser_swigregister
MotionParser_swigregister(MotionParser)

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
    __repr__ = _swig_repr
    def __init__(self, *args): 
        """
        SubMotion::SubMotion(const SubMotion &sm)
                 
                
                 
                
        """
        if self.__class__ == SubMotion:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_SubMotion(*args)
        try: self.this.append(this)
        except: self.this = this
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

    __swig_destroy__ = _Piavca.delete_SubMotion
    __del__ = lambda self : None;
    def __disown__(self):
        self.this.disown()
        _Piavca.disown_SubMotion(self)
        return weakref_proxy(self)
SubMotion_swigregister = _Piavca.SubMotion_swigregister
SubMotion_swigregister(SubMotion)

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
    __repr__ = _swig_repr
    def __init__(self, *args): 
        """
        TimeRangeMotion::TimeRangeMotion(const TimeRangeMotion &sm)
                 
                
                 
                
        """
        if self.__class__ == TimeRangeMotion:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_TimeRangeMotion(*args)
        try: self.this.append(this)
        except: self.this = this
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

    __swig_destroy__ = _Piavca.delete_TimeRangeMotion
    __del__ = lambda self : None;
    def __disown__(self):
        self.this.disown()
        _Piavca.disown_TimeRangeMotion(self)
        return weakref_proxy(self)
TimeRangeMotion_swigregister = _Piavca.TimeRangeMotion_swigregister
TimeRangeMotion_swigregister(TimeRangeMotion)

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
    __repr__ = _swig_repr
    def __init__(self, *args): 
        """
        Piavca::TimeWarp::TimeWarp(const TimeWarp &tw)
                 
                
                 
                
        """
        if self.__class__ == TimeWarp:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_TimeWarp(*args)
        try: self.this.append(this)
        except: self.this = this
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

    __swig_destroy__ = _Piavca.delete_TimeWarp
    __del__ = lambda self : None;
    def __disown__(self):
        self.this.disown()
        _Piavca.disown_TimeWarp(self)
        return weakref_proxy(self)
TimeWarp_swigregister = _Piavca.TimeWarp_swigregister
TimeWarp_swigregister(TimeWarp)

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
    __repr__ = _swig_repr
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
        this = _Piavca.new_DiadicGazeMotion(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca.delete_DiadicGazeMotion
    __del__ = lambda self : None;
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
        self.this.disown()
        _Piavca.disown_DiadicGazeMotion(self)
        return weakref_proxy(self)
DiadicGazeMotion_swigregister = _Piavca.DiadicGazeMotion_swigregister
DiadicGazeMotion_swigregister(DiadicGazeMotion)



