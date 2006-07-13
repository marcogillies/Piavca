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
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, TimeCallback, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, TimeCallback, name)
    def __init__(self): raise RuntimeError, "No constructor defined"
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::TimeCallback instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __del__(self, destroy=_Piavca.delete_TimeCallback):
        try:
            if self.thisown: destroy(self)
        except: pass

    def getName(*args): return _Piavca.TimeCallback_getName(*args)
    def init(*args): return _Piavca.TimeCallback_init(*args)
    def timeStep(*args): return _Piavca.TimeCallback_timeStep(*args)

class TimeCallbackPtr(TimeCallback):
    def __init__(self, this):
        _swig_setattr(self, TimeCallback, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, TimeCallback, 'thisown', 0)
        self.__class__ = TimeCallback
_Piavca.TimeCallback_swigregister(TimeCallbackPtr)

class AvatarTimeCallback(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, AvatarTimeCallback, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, AvatarTimeCallback, name)
    def __init__(self): raise RuntimeError, "No constructor defined"
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::AvatarTimeCallback instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __del__(self, destroy=_Piavca.delete_AvatarTimeCallback):
        try:
            if self.thisown: destroy(self)
        except: pass

    def getName(*args): return _Piavca.AvatarTimeCallback_getName(*args)
    def init(*args): return _Piavca.AvatarTimeCallback_init(*args)
    def timeStep(*args): return _Piavca.AvatarTimeCallback_timeStep(*args)

class AvatarTimeCallbackPtr(AvatarTimeCallback):
    def __init__(self, this):
        _swig_setattr(self, AvatarTimeCallback, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, AvatarTimeCallback, 'thisown', 0)
        self.__class__ = AvatarTimeCallback
_Piavca.AvatarTimeCallback_swigregister(AvatarTimeCallbackPtr)

class Core(_object):
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
        try:
            if self.thisown: destroy(self)
        except: pass

    def reset(*args): return _Piavca.Core_reset(*args)
    __swig_getmethods__["getCore"] = lambda x: _Piavca.Core_getCore
    if _newclass:getCore = staticmethod(_Piavca.Core_getCore)
    def registerCallback(*args): return _Piavca.Core_registerCallback(*args)
    def timeStep(*args): return _Piavca.Core_timeStep(*args)
    def prerender(*args): return _Piavca.Core_prerender(*args)
    def render(*args): return _Piavca.Core_render(*args)
    def getJointId(*args): return _Piavca.Core_getJointId(*args)
    def getMaxJointId(*args): return _Piavca.Core_getMaxJointId(*args)
    def addJointNameSet(*args): return _Piavca.Core_addJointNameSet(*args)
    def getJointName(*args): return _Piavca.Core_getJointName(*args)
    def getJointNameAssociations(*args): return _Piavca.Core_getJointNameAssociations(*args)
    def getExpressionId(*args): return _Piavca.Core_getExpressionId(*args)
    def getMaxExpressionId(*args): return _Piavca.Core_getMaxExpressionId(*args)
    def addExpressionNameSet(*args): return _Piavca.Core_addExpressionNameSet(*args)
    def getExpressionName(*args): return _Piavca.Core_getExpressionName(*args)
    def getExpressionNameAssociations(*args): return _Piavca.Core_getExpressionNameAssociations(*args)
    def loadMotion(*args): return _Piavca.Core_loadMotion(*args)
    def renameMotion(*args): return _Piavca.Core_renameMotion(*args)
    def unloadMotion(*args): return _Piavca.Core_unloadMotion(*args)
    def getMotionNames(*args): return _Piavca.Core_getMotionNames(*args)
    def getNumberOfMotions(*args): return _Piavca.Core_getNumberOfMotions(*args)
    def getAllmotions(*args): return _Piavca.Core_getAllmotions(*args)
    def getMotion(*args): return _Piavca.Core_getMotion(*args)
    def getAvatarNames(*args): return _Piavca.Core_getAvatarNames(*args)
    def numAvatars(*args): return _Piavca.Core_numAvatars(*args)
    def getAvatar(*args): return _Piavca.Core_getAvatar(*args)
    def renameAvatar(*args): return _Piavca.Core_renameAvatar(*args)
    def removeAvatar(*args): return _Piavca.Core_removeAvatar(*args)
    def initAvatar(*args): return _Piavca.Core_initAvatar(*args)
    def numObjects(*args): return _Piavca.Core_numObjects(*args)
    def getObject(*args): return _Piavca.Core_getObject(*args)
    def renameObject(*args): return _Piavca.Core_renameObject(*args)
    def removeObject(*args): return _Piavca.Core_removeObject(*args)
    def initObject(*args): return _Piavca.Core_initObject(*args)
    def initMotion(*args): return _Piavca.Core_initMotion(*args)
    def setDir(*args): return _Piavca.Core_setDir(*args)
    def getTime(*args): return _Piavca.Core_getTime(*args)
    def getSystemTime(*args): return _Piavca.Core_getSystemTime(*args)
    def setAutoTimeOff(*args): return _Piavca.Core_setAutoTimeOff(*args)
    def setAutoTimeOn(*args): return _Piavca.Core_setAutoTimeOn(*args)
    def setCurrentTime(*args): return _Piavca.Core_setCurrentTime(*args)
    def addError(*args): return _Piavca.Core_addError(*args)
    def error(*args): return _Piavca.Core_error(*args)
    def clearErrors(*args): return _Piavca.Core_clearErrors(*args)
    def getErrors(*args): return _Piavca.Core_getErrors(*args)
    def errorsPresent(*args): return _Piavca.Core_errorsPresent(*args)
    def addWarning(*args): return _Piavca.Core_addWarning(*args)
    def Warning(*args): return _Piavca.Core_Warning(*args)
    def clearWarnings(*args): return _Piavca.Core_clearWarnings(*args)
    def getWarnings(*args): return _Piavca.Core_getWarnings(*args)
    def warningsPresent(*args): return _Piavca.Core_warningsPresent(*args)
    def exceptionsOn(*args): return _Piavca.Core_exceptionsOn(*args)
    def setExceptionsOn(*args): return _Piavca.Core_setExceptionsOn(*args)
    def setExceptionsOff(*args): return _Piavca.Core_setExceptionsOff(*args)
    def log(*args): return _Piavca.Core_log(*args)

class CorePtr(Core):
    def __init__(self, this):
        _swig_setattr(self, Core, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, Core, 'thisown', 0)
        self.__class__ = Core
_Piavca.Core_swigregister(CorePtr)

Core_getCore = _Piavca.Core_getCore


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
class Motion(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Motion, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Motion, name)
    def __init__(self): raise RuntimeError, "No constructor defined"
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::Motion instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __del__(self, destroy=_Piavca.delete_Motion):
        try:
            if self.thisown: destroy(self)
        except: pass

    def clone(*args): return _Piavca.Motion_clone(*args)
    def printInfo(*args): return _Piavca.Motion_printInfo(*args)
    def load(*args): return _Piavca.Motion_load(*args)
    def unload(*args): return _Piavca.Motion_unload(*args)
    def loaded(*args): return _Piavca.Motion_loaded(*args)
    def setStartTime(*args): return _Piavca.Motion_setStartTime(*args)
    def getStartTime(*args): return _Piavca.Motion_getStartTime(*args)
    def getEndTime(*args): return _Piavca.Motion_getEndTime(*args)
    def reset(*args): return _Piavca.Motion_reset(*args)
    def Reference(*args): return _Piavca.Motion_Reference(*args)
    def Dispose(*args): return _Piavca.Motion_Dispose(*args)
    def makeTemp(*args): return _Piavca.Motion_makeTemp(*args)
    def setName(*args): return _Piavca.Motion_setName(*args)
    def getName(*args): return _Piavca.Motion_getName(*args)
    def findSub(*args): return _Piavca.Motion_findSub(*args)
    def findSubByType(*args): return _Piavca.Motion_findSubByType(*args)
    def saveMotion(*args): return _Piavca.Motion_saveMotion(*args)
    def getMotionLength(*args): return _Piavca.Motion_getMotionLength(*args)
    def isFacial(*args): return _Piavca.Motion_isFacial(*args)
    def isRandomAccess(*args): return _Piavca.Motion_isRandomAccess(*args)
    def begin(*args): return _Piavca.Motion_begin(*args)
    def end(*args): return _Piavca.Motion_end(*args)
    def next(*args): return _Piavca.Motion_next(*args)
    def isNull(*args): return _Piavca.Motion_isNull(*args)
    def getTrackType(*args): return _Piavca.Motion_getTrackType(*args)
    def pause(*args): return _Piavca.Motion_pause(*args)
    def unpause(*args): return _Piavca.Motion_unpause(*args)
    def getFloatValueAtTime(*args): return _Piavca.Motion_getFloatValueAtTime(*args)
    def getVecValueAtTime(*args): return _Piavca.Motion_getVecValueAtTime(*args)
    def getQuatValueAtTime(*args): return _Piavca.Motion_getQuatValueAtTime(*args)
    def getFloatValueAtTimeInternal(*args): return _Piavca.Motion_getFloatValueAtTimeInternal(*args)
    def getVecValueAtTimeInternal(*args): return _Piavca.Motion_getVecValueAtTimeInternal(*args)
    def getQuatValueAtTimeInternal(*args): return _Piavca.Motion_getQuatValueAtTimeInternal(*args)

class MotionPtr(Motion):
    def __init__(self, this):
        _swig_setattr(self, Motion, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, Motion, 'thisown', 0)
        self.__class__ = Motion
_Piavca.Motion_swigregister(MotionPtr)

class TrackMotion(Motion):
    __swig_setmethods__ = {}
    for _s in [Motion]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, TrackMotion, name, value)
    __swig_getmethods__ = {}
    for _s in [Motion]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, TrackMotion, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::TrackMotion instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        _swig_setattr(self, TrackMotion, 'this', _Piavca.new_TrackMotion(*args))
        _swig_setattr(self, TrackMotion, 'thisown', 1)
    def __del__(self, destroy=_Piavca.delete_TrackMotion):
        try:
            if self.thisown: destroy(self)
        except: pass

    def clone(*args): return _Piavca.TrackMotion_clone(*args)
    def getMotionLength(*args): return _Piavca.TrackMotion_getMotionLength(*args)
    def isFacial(*args): return _Piavca.TrackMotion_isFacial(*args)
    def isRandomAccess(*args): return _Piavca.TrackMotion_isRandomAccess(*args)
    def isNull(*args): return _Piavca.TrackMotion_isNull(*args)
    def getTrackType(*args): return _Piavca.TrackMotion_getTrackType(*args)
    def addFloatTrack(*args): return _Piavca.TrackMotion_addFloatTrack(*args)
    def addVecTrack(*args): return _Piavca.TrackMotion_addVecTrack(*args)
    def addQuatTrack(*args): return _Piavca.TrackMotion_addQuatTrack(*args)
    def setFloatKeyframe(*args): return _Piavca.TrackMotion_setFloatKeyframe(*args)
    def setVecKeyframe(*args): return _Piavca.TrackMotion_setVecKeyframe(*args)
    def setQuatKeyframe(*args): return _Piavca.TrackMotion_setQuatKeyframe(*args)
    def getNumKeyframes(*args): return _Piavca.TrackMotion_getNumKeyframes(*args)
    def getKeyframeTime(*args): return _Piavca.TrackMotion_getKeyframeTime(*args)
    def getFloatValueAtTimeInternal(*args): return _Piavca.TrackMotion_getFloatValueAtTimeInternal(*args)
    def getVecValueAtTimeInternal(*args): return _Piavca.TrackMotion_getVecValueAtTimeInternal(*args)
    def getQuatValueAtTimeInternal(*args): return _Piavca.TrackMotion_getQuatValueAtTimeInternal(*args)
    def deleteAllTracks(*args): return _Piavca.TrackMotion_deleteAllTracks(*args)
    def clearTrack(*args): return _Piavca.TrackMotion_clearTrack(*args)
    def clearAllTracks(*args): return _Piavca.TrackMotion_clearAllTracks(*args)

class TrackMotionPtr(TrackMotion):
    def __init__(self, this):
        _swig_setattr(self, TrackMotion, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, TrackMotion, 'thisown', 0)
        self.__class__ = TrackMotion
_Piavca.TrackMotion_swigregister(TrackMotionPtr)


copyMotionPosture = _Piavca.copyMotionPosture
class Avatar(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Avatar, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Avatar, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::Avatar instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        _swig_setattr(self, Avatar, 'this', _Piavca.new_Avatar(*args))
        _swig_setattr(self, Avatar, 'thisown', 1)
    def isValid(*args): return _Piavca.Avatar_isValid(*args)
    def activate(*args): return _Piavca.Avatar_activate(*args)
    def deactivate(*args): return _Piavca.Avatar_deactivate(*args)
    def getName(*args): return _Piavca.Avatar_getName(*args)
    def setName(*args): return _Piavca.Avatar_setName(*args)
    def getForwardDirection(*args): return _Piavca.Avatar_getForwardDirection(*args)
    def setForwardDirection(*args): return _Piavca.Avatar_setForwardDirection(*args)
    def clearFacialExpressionWeights(*args): return _Piavca.Avatar_clearFacialExpressionWeights(*args)
    def beginExpression(*args): return _Piavca.Avatar_beginExpression(*args)
    def endExpression(*args): return _Piavca.Avatar_endExpression(*args)
    def nextExpression(*args): return _Piavca.Avatar_nextExpression(*args)
    def isExpressionNull(*args): return _Piavca.Avatar_isExpressionNull(*args)
    def setRootPosition(*args): return _Piavca.Avatar_setRootPosition(*args)
    def getRootPosition(*args): return _Piavca.Avatar_getRootPosition(*args)
    def setRootOrientation(*args): return _Piavca.Avatar_setRootOrientation(*args)
    def setRootAngle(*args): return _Piavca.Avatar_setRootAngle(*args)
    def setRootAngleDeg(*args): return _Piavca.Avatar_setRootAngleDeg(*args)
    def getRootOrientation(*args): return _Piavca.Avatar_getRootOrientation(*args)
    def createJoint(*args): return _Piavca.Avatar_createJoint(*args)
    def begin(*args): return _Piavca.Avatar_begin(*args)
    def end(*args): return _Piavca.Avatar_end(*args)
    def next(*args): return _Piavca.Avatar_next(*args)
    def getParent(*args): return _Piavca.Avatar_getParent(*args)
    def getJointName(*args): return _Piavca.Avatar_getJointName(*args)
    def isNull(*args): return _Piavca.Avatar_isNull(*args)
    def hasChanged(*args): return _Piavca.Avatar_hasChanged(*args)
    def clearChange(*args): return _Piavca.Avatar_clearChange(*args)
    def scaleRoot(*args): return _Piavca.Avatar_scaleRoot(*args)
    def scaleJoint(*args): return _Piavca.Avatar_scaleJoint(*args)
    def timeStep(*args): return _Piavca.Avatar_timeStep(*args)
    def loadMotion(*args): return _Piavca.Avatar_loadMotion(*args)
    def unloadMotion(*args): return _Piavca.Avatar_unloadMotion(*args)
    def getMotion(*args): return _Piavca.Avatar_getMotion(*args)
    def playMotion(*args): return _Piavca.Avatar_playMotion(*args)
    def playMotionDirect(*args): return _Piavca.Avatar_playMotionDirect(*args)
    def stopMotion(*args): return _Piavca.Avatar_stopMotion(*args)
    def restartMotion(*args): return _Piavca.Avatar_restartMotion(*args)
    def setMotionStartTime(*args): return _Piavca.Avatar_setMotionStartTime(*args)
    def getMotionStartTime(*args): return _Piavca.Avatar_getMotionStartTime(*args)
    def getMotionEndTime(*args): return _Piavca.Avatar_getMotionEndTime(*args)
    def showMotionAtTime(*args): return _Piavca.Avatar_showMotionAtTime(*args)
    def loadFacialMotion(*args): return _Piavca.Avatar_loadFacialMotion(*args)
    def unloadFacialMotion(*args): return _Piavca.Avatar_unloadFacialMotion(*args)
    def getFacialMotion(*args): return _Piavca.Avatar_getFacialMotion(*args)
    def playFacialMotion(*args): return _Piavca.Avatar_playFacialMotion(*args)
    def stopFacialMotion(*args): return _Piavca.Avatar_stopFacialMotion(*args)
    def restartFacialMotion(*args): return _Piavca.Avatar_restartFacialMotion(*args)
    def setFacialMotionStartTime(*args): return _Piavca.Avatar_setFacialMotionStartTime(*args)
    def getFacialMotionStartTime(*args): return _Piavca.Avatar_getFacialMotionStartTime(*args)
    def getFacialMotionEndTime(*args): return _Piavca.Avatar_getFacialMotionEndTime(*args)
    def showFacialMotionAtTime(*args): return _Piavca.Avatar_showFacialMotionAtTime(*args)
    def loadScaleMotion(*args): return _Piavca.Avatar_loadScaleMotion(*args)
    def unloadScaleMotion(*args): return _Piavca.Avatar_unloadScaleMotion(*args)
    def getScaleMotion(*args): return _Piavca.Avatar_getScaleMotion(*args)
    def playScaleMotion(*args): return _Piavca.Avatar_playScaleMotion(*args)
    def stopScaleMotion(*args): return _Piavca.Avatar_stopScaleMotion(*args)
    def restartScaleMotion(*args): return _Piavca.Avatar_restartScaleMotion(*args)
    def setScaleMotionStartTime(*args): return _Piavca.Avatar_setScaleMotionStartTime(*args)
    def getScaleMotionStartTime(*args): return _Piavca.Avatar_getScaleMotionStartTime(*args)
    def getScaleMotionEndTime(*args): return _Piavca.Avatar_getScaleMotionEndTime(*args)
    def showScaleMotionAtTime(*args): return _Piavca.Avatar_showScaleMotionAtTime(*args)
    def registerCallback(*args): return _Piavca.Avatar_registerCallback(*args)
    def removeCallback(*args): return _Piavca.Avatar_removeCallback(*args)
    def getNumCallbacks(*args): return _Piavca.Avatar_getNumCallbacks(*args)
    def getCallback(*args): return _Piavca.Avatar_getCallback(*args)
    def setFacialExpressionWeight(*args): return _Piavca.Avatar_setFacialExpressionWeight(*args)
    def getFacialExpressionWeight(*args): return _Piavca.Avatar_getFacialExpressionWeight(*args)
    def setJointOrientation(*args): return _Piavca.Avatar_setJointOrientation(*args)
    def getJointOrientation(*args): return _Piavca.Avatar_getJointOrientation(*args)
    def getJointBasePosition(*args): return _Piavca.Avatar_getJointBasePosition(*args)
    def play_motion(*args): return _Piavca.Avatar_play_motion(*args)
    def add_background_motion(*args): return _Piavca.Avatar_add_background_motion(*args)

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
    __swig_setmethods__ = {}
    for _s in [AvatarTimeCallback]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, AvatarMotionQueue, name, value)
    __swig_getmethods__ = {}
    for _s in [AvatarTimeCallback]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, AvatarMotionQueue, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::AvatarMotionQueue instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        _swig_setattr(self, AvatarMotionQueue, 'this', _Piavca.new_AvatarMotionQueue(*args))
        _swig_setattr(self, AvatarMotionQueue, 'thisown', 1)
    def __del__(self, destroy=_Piavca.delete_AvatarMotionQueue):
        try:
            if self.thisown: destroy(self)
        except: pass

    def init(*args): return _Piavca.AvatarMotionQueue_init(*args)
    def timeStep(*args): return _Piavca.AvatarMotionQueue_timeStep(*args)
    def isFacial(*args): return _Piavca.AvatarMotionQueue_isFacial(*args)
    def getCurrentMotionStart(*args): return _Piavca.AvatarMotionQueue_getCurrentMotionStart(*args)
    def reblend(*args): return _Piavca.AvatarMotionQueue_reblend(*args)
    def setBlendInterval(*args): return _Piavca.AvatarMotionQueue_setBlendInterval(*args)
    def enqueueMotion(*args): return _Piavca.AvatarMotionQueue_enqueueMotion(*args)
    def enqueueRandomMotions(*args): return _Piavca.AvatarMotionQueue_enqueueRandomMotions(*args)
    def queueTopIsBackground(*args): return _Piavca.AvatarMotionQueue_queueTopIsBackground(*args)
    def queueTopTime(*args): return _Piavca.AvatarMotionQueue_queueTopTime(*args)
    def dequeueMotion(*args): return _Piavca.AvatarMotionQueue_dequeueMotion(*args)
    def getQueueSize(*args): return _Piavca.AvatarMotionQueue_getQueueSize(*args)
    def updateDelay(*args): return _Piavca.AvatarMotionQueue_updateDelay(*args)
    def clearQueue(*args): return _Piavca.AvatarMotionQueue_clearQueue(*args)
    def removeMotion(*args): return _Piavca.AvatarMotionQueue_removeMotion(*args)
    def pauseMotion(*args): return _Piavca.AvatarMotionQueue_pauseMotion(*args)
    def unpauseMotion(*args): return _Piavca.AvatarMotionQueue_unpauseMotion(*args)
    def clearAllBackgroundMotions(*args): return _Piavca.AvatarMotionQueue_clearAllBackgroundMotions(*args)
    def clearFinishedBackgroundMotions(*args): return _Piavca.AvatarMotionQueue_clearFinishedBackgroundMotions(*args)
    def removeBackgroundMotion(*args): return _Piavca.AvatarMotionQueue_removeBackgroundMotion(*args)
    def removeBackgroundMotionByType(*args): return _Piavca.AvatarMotionQueue_removeBackgroundMotionByType(*args)
    def pauseBackgroundMotion(*args): return _Piavca.AvatarMotionQueue_pauseBackgroundMotion(*args)
    def unpauseBackgroundMotion(*args): return _Piavca.AvatarMotionQueue_unpauseBackgroundMotion(*args)
    def interrupt(*args): return _Piavca.AvatarMotionQueue_interrupt(*args)
    def getMotion(*args): return _Piavca.AvatarMotionQueue_getMotion(*args)
    def blendMotion(*args): return _Piavca.AvatarMotionQueue_blendMotion(*args)
    def addBackgroundMotion(*args): return _Piavca.AvatarMotionQueue_addBackgroundMotion(*args)

class AvatarMotionQueuePtr(AvatarMotionQueue):
    def __init__(self, this):
        _swig_setattr(self, AvatarMotionQueue, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, AvatarMotionQueue, 'thisown', 0)
        self.__class__ = AvatarMotionQueue
_Piavca.AvatarMotionQueue_swigregister(AvatarMotionQueuePtr)

class Object(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Object, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Object, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::Object instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        _swig_setattr(self, Object, 'this', _Piavca.new_Object(*args))
        _swig_setattr(self, Object, 'thisown', 1)
    def getName(*args): return _Piavca.Object_getName(*args)
    def setName(*args): return _Piavca.Object_setName(*args)
    def setPosition(*args): return _Piavca.Object_setPosition(*args)
    def getPosition(*args): return _Piavca.Object_getPosition(*args)
    def setOrientation(*args): return _Piavca.Object_setOrientation(*args)
    def setAngle(*args): return _Piavca.Object_setAngle(*args)
    def setAngleDeg(*args): return _Piavca.Object_setAngleDeg(*args)
    def getOrientation(*args): return _Piavca.Object_getOrientation(*args)
    def scale(*args): return _Piavca.Object_scale(*args)

class ObjectPtr(Object):
    def __init__(self, this):
        _swig_setattr(self, Object, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, Object, 'thisown', 0)
        self.__class__ = Object
_Piavca.Object_swigregister(ObjectPtr)

class PyTimeCallback(TimeCallback):
    __swig_setmethods__ = {}
    for _s in [TimeCallback]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, PyTimeCallback, name, value)
    __swig_getmethods__ = {}
    for _s in [TimeCallback]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, PyTimeCallback, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::PyTimeCallback instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        _swig_setattr(self, PyTimeCallback, 'this', _Piavca.new_PyTimeCallback(*args))
        _swig_setattr(self, PyTimeCallback, 'thisown', 1)
    def __del__(self, destroy=_Piavca.delete_PyTimeCallback):
        try:
            if self.thisown: destroy(self)
        except: pass

    def init(*args): return _Piavca.PyTimeCallback_init(*args)
    def timeStep(*args): return _Piavca.PyTimeCallback_timeStep(*args)

class PyTimeCallbackPtr(PyTimeCallback):
    def __init__(self, this):
        _swig_setattr(self, PyTimeCallback, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, PyTimeCallback, 'thisown', 0)
        self.__class__ = PyTimeCallback
_Piavca.PyTimeCallback_swigregister(PyTimeCallbackPtr)

class PyAvatarTimeCallback(AvatarTimeCallback):
    __swig_setmethods__ = {}
    for _s in [AvatarTimeCallback]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, PyAvatarTimeCallback, name, value)
    __swig_getmethods__ = {}
    for _s in [AvatarTimeCallback]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, PyAvatarTimeCallback, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::PyAvatarTimeCallback instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        _swig_setattr(self, PyAvatarTimeCallback, 'this', _Piavca.new_PyAvatarTimeCallback(*args))
        _swig_setattr(self, PyAvatarTimeCallback, 'thisown', 1)
    def __del__(self, destroy=_Piavca.delete_PyAvatarTimeCallback):
        try:
            if self.thisown: destroy(self)
        except: pass

    def init(*args): return _Piavca.PyAvatarTimeCallback_init(*args)
    def timeStep(*args): return _Piavca.PyAvatarTimeCallback_timeStep(*args)

class PyAvatarTimeCallbackPtr(PyAvatarTimeCallback):
    def __init__(self, this):
        _swig_setattr(self, PyAvatarTimeCallback, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, PyAvatarTimeCallback, 'thisown', 0)
        self.__class__ = PyAvatarTimeCallback
_Piavca.PyAvatarTimeCallback_swigregister(PyAvatarTimeCallbackPtr)

class PyMotion(Motion):
    __swig_setmethods__ = {}
    for _s in [Motion]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, PyMotion, name, value)
    __swig_getmethods__ = {}
    for _s in [Motion]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, PyMotion, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::PyMotion instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        _swig_setattr(self, PyMotion, 'this', _Piavca.new_PyMotion(*args))
        _swig_setattr(self, PyMotion, 'thisown', 1)
    def clone(*args): return _Piavca.PyMotion_clone(*args)
    def __del__(self, destroy=_Piavca.delete_PyMotion):
        try:
            if self.thisown: destroy(self)
        except: pass

    def setPyObj(*args): return _Piavca.PyMotion_setPyObj(*args)
    def getMotionPtr(*args): return _Piavca.PyMotion_getMotionPtr(*args)
    def getMotionLength(*args): return _Piavca.PyMotion_getMotionLength(*args)
    def isNull(*args): return _Piavca.PyMotion_isNull(*args)
    def getTrackType(*args): return _Piavca.PyMotion_getTrackType(*args)
    def getFloatValueAtTimeInternal(*args): return _Piavca.PyMotion_getFloatValueAtTimeInternal(*args)
    def getVecValueAtTimeInternal(*args): return _Piavca.PyMotion_getVecValueAtTimeInternal(*args)
    def getQuatValueAtTimeInternal(*args): return _Piavca.PyMotion_getQuatValueAtTimeInternal(*args)

class PyMotionPtr(PyMotion):
    def __init__(self, this):
        _swig_setattr(self, PyMotion, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, PyMotion, 'thisown', 0)
        self.__class__ = PyMotion
_Piavca.PyMotion_swigregister(PyMotionPtr)


degToRad = _Piavca.degToRad

radToDeg = _Piavca.radToDeg
class MotionFilter(Motion):
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
        try:
            if self.thisown: destroy(self)
        except: pass

    def printInfo(*args): return _Piavca.MotionFilter_printInfo(*args)
    def findSub(*args): return _Piavca.MotionFilter_findSub(*args)
    def findSubByType(*args): return _Piavca.MotionFilter_findSubByType(*args)
    def load(*args): return _Piavca.MotionFilter_load(*args)
    def unload(*args): return _Piavca.MotionFilter_unload(*args)
    def loaded(*args): return _Piavca.MotionFilter_loaded(*args)
    def setStartTime(*args): return _Piavca.MotionFilter_setStartTime(*args)
    def reset(*args): return _Piavca.MotionFilter_reset(*args)
    def setMotion(*args): return _Piavca.MotionFilter_setMotion(*args)
    def getMotionLength(*args): return _Piavca.MotionFilter_getMotionLength(*args)
    def isFacial(*args): return _Piavca.MotionFilter_isFacial(*args)
    def isRandomAccess(*args): return _Piavca.MotionFilter_isRandomAccess(*args)
    def isNull(*args): return _Piavca.MotionFilter_isNull(*args)
    def getTrackType(*args): return _Piavca.MotionFilter_getTrackType(*args)

class MotionFilterPtr(MotionFilter):
    def __init__(self, this):
        _swig_setattr(self, MotionFilter, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, MotionFilter, 'thisown', 0)
        self.__class__ = MotionFilter
_Piavca.MotionFilter_swigregister(MotionFilterPtr)
cvar = _Piavca.cvar
Pi = cvar.Pi

class TwoMotionCombiner(Motion):
    __swig_setmethods__ = {}
    for _s in [Motion]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, TwoMotionCombiner, name, value)
    __swig_getmethods__ = {}
    for _s in [Motion]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, TwoMotionCombiner, name)
    def __init__(self): raise RuntimeError, "No constructor defined"
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::TwoMotionCombiner instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __del__(self, destroy=_Piavca.delete_TwoMotionCombiner):
        try:
            if self.thisown: destroy(self)
        except: pass

    def printInfo(*args): return _Piavca.TwoMotionCombiner_printInfo(*args)
    def findSub(*args): return _Piavca.TwoMotionCombiner_findSub(*args)
    def findSubByType(*args): return _Piavca.TwoMotionCombiner_findSubByType(*args)
    def load(*args): return _Piavca.TwoMotionCombiner_load(*args)
    def unload(*args): return _Piavca.TwoMotionCombiner_unload(*args)
    def loaded(*args): return _Piavca.TwoMotionCombiner_loaded(*args)
    def setStartTime(*args): return _Piavca.TwoMotionCombiner_setStartTime(*args)
    def reset(*args): return _Piavca.TwoMotionCombiner_reset(*args)
    def getMotionLength(*args): return _Piavca.TwoMotionCombiner_getMotionLength(*args)
    def isFacial(*args): return _Piavca.TwoMotionCombiner_isFacial(*args)
    def isRandomAccess(*args): return _Piavca.TwoMotionCombiner_isRandomAccess(*args)
    def isNull(*args): return _Piavca.TwoMotionCombiner_isNull(*args)
    def getTrackType(*args): return _Piavca.TwoMotionCombiner_getTrackType(*args)
    def setMotion1(*args): return _Piavca.TwoMotionCombiner_setMotion1(*args)
    def setMotion2(*args): return _Piavca.TwoMotionCombiner_setMotion2(*args)
    def getMotion1(*args): return _Piavca.TwoMotionCombiner_getMotion1(*args)
    def getMotion2(*args): return _Piavca.TwoMotionCombiner_getMotion2(*args)

class TwoMotionCombinerPtr(TwoMotionCombiner):
    def __init__(self, this):
        _swig_setattr(self, TwoMotionCombiner, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, TwoMotionCombiner, 'thisown', 0)
        self.__class__ = TwoMotionCombiner
_Piavca.TwoMotionCombiner_swigregister(TwoMotionCombinerPtr)

class ScaleMotion(MotionFilter):
    __swig_setmethods__ = {}
    for _s in [MotionFilter]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, ScaleMotion, name, value)
    __swig_getmethods__ = {}
    for _s in [MotionFilter]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, ScaleMotion, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::ScaleMotion instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        _swig_setattr(self, ScaleMotion, 'this', _Piavca.new_ScaleMotion(*args))
        _swig_setattr(self, ScaleMotion, 'thisown', 1)
    def clone(*args): return _Piavca.ScaleMotion_clone(*args)
    def getFloatValueAtTimeInternal(*args): return _Piavca.ScaleMotion_getFloatValueAtTimeInternal(*args)
    def getVecValueAtTimeInternal(*args): return _Piavca.ScaleMotion_getVecValueAtTimeInternal(*args)
    def getQuatValueAtTimeInternal(*args): return _Piavca.ScaleMotion_getQuatValueAtTimeInternal(*args)
    def setScaleFactor(*args): return _Piavca.ScaleMotion_setScaleFactor(*args)
    def __del__(self, destroy=_Piavca.delete_ScaleMotion):
        try:
            if self.thisown: destroy(self)
        except: pass


class ScaleMotionPtr(ScaleMotion):
    def __init__(self, this):
        _swig_setattr(self, ScaleMotion, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, ScaleMotion, 'thisown', 0)
        self.__class__ = ScaleMotion
_Piavca.ScaleMotion_swigregister(ScaleMotionPtr)

class ScaleMotionSpeed(MotionFilter):
    __swig_setmethods__ = {}
    for _s in [MotionFilter]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, ScaleMotionSpeed, name, value)
    __swig_getmethods__ = {}
    for _s in [MotionFilter]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, ScaleMotionSpeed, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::ScaleMotionSpeed instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        _swig_setattr(self, ScaleMotionSpeed, 'this', _Piavca.new_ScaleMotionSpeed(*args))
        _swig_setattr(self, ScaleMotionSpeed, 'thisown', 1)
    def clone(*args): return _Piavca.ScaleMotionSpeed_clone(*args)
    def getMotionLength(*args): return _Piavca.ScaleMotionSpeed_getMotionLength(*args)
    def getFloatValueAtTimeInternal(*args): return _Piavca.ScaleMotionSpeed_getFloatValueAtTimeInternal(*args)
    def getVecValueAtTimeInternal(*args): return _Piavca.ScaleMotionSpeed_getVecValueAtTimeInternal(*args)
    def getQuatValueAtTimeInternal(*args): return _Piavca.ScaleMotionSpeed_getQuatValueAtTimeInternal(*args)
    def setScaleFactor(*args): return _Piavca.ScaleMotionSpeed_setScaleFactor(*args)
    def __del__(self, destroy=_Piavca.delete_ScaleMotionSpeed):
        try:
            if self.thisown: destroy(self)
        except: pass


class ScaleMotionSpeedPtr(ScaleMotionSpeed):
    def __init__(self, this):
        _swig_setattr(self, ScaleMotionSpeed, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, ScaleMotionSpeed, 'thisown', 0)
        self.__class__ = ScaleMotionSpeed
_Piavca.ScaleMotionSpeed_swigregister(ScaleMotionSpeedPtr)

class ScaleMotionRoot(MotionFilter):
    __swig_setmethods__ = {}
    for _s in [MotionFilter]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, ScaleMotionRoot, name, value)
    __swig_getmethods__ = {}
    for _s in [MotionFilter]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, ScaleMotionRoot, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::ScaleMotionRoot instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        _swig_setattr(self, ScaleMotionRoot, 'this', _Piavca.new_ScaleMotionRoot(*args))
        _swig_setattr(self, ScaleMotionRoot, 'thisown', 1)
    def __del__(self, destroy=_Piavca.delete_ScaleMotionRoot):
        try:
            if self.thisown: destroy(self)
        except: pass

    def clone(*args): return _Piavca.ScaleMotionRoot_clone(*args)
    def getFloatValueAtTimeInternal(*args): return _Piavca.ScaleMotionRoot_getFloatValueAtTimeInternal(*args)
    def getVecValueAtTimeInternal(*args): return _Piavca.ScaleMotionRoot_getVecValueAtTimeInternal(*args)
    def getQuatValueAtTimeInternal(*args): return _Piavca.ScaleMotionRoot_getQuatValueAtTimeInternal(*args)
    def setScaleFactor(*args): return _Piavca.ScaleMotionRoot_setScaleFactor(*args)

class ScaleMotionRootPtr(ScaleMotionRoot):
    def __init__(self, this):
        _swig_setattr(self, ScaleMotionRoot, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, ScaleMotionRoot, 'thisown', 0)
        self.__class__ = ScaleMotionRoot
_Piavca.ScaleMotionRoot_swigregister(ScaleMotionRootPtr)

class TimeOffset(MotionFilter):
    __swig_setmethods__ = {}
    for _s in [MotionFilter]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, TimeOffset, name, value)
    __swig_getmethods__ = {}
    for _s in [MotionFilter]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, TimeOffset, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::TimeOffset instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        _swig_setattr(self, TimeOffset, 'this', _Piavca.new_TimeOffset(*args))
        _swig_setattr(self, TimeOffset, 'thisown', 1)
    def clone(*args): return _Piavca.TimeOffset_clone(*args)
    def setStartTime(*args): return _Piavca.TimeOffset_setStartTime(*args)
    def getFloatValueAtTimeInternal(*args): return _Piavca.TimeOffset_getFloatValueAtTimeInternal(*args)
    def getVecValueAtTimeInternal(*args): return _Piavca.TimeOffset_getVecValueAtTimeInternal(*args)
    def getQuatValueAtTimeInternal(*args): return _Piavca.TimeOffset_getQuatValueAtTimeInternal(*args)
    def setOffset(*args): return _Piavca.TimeOffset_setOffset(*args)
    def __del__(self, destroy=_Piavca.delete_TimeOffset):
        try:
            if self.thisown: destroy(self)
        except: pass


class TimeOffsetPtr(TimeOffset):
    def __init__(self, this):
        _swig_setattr(self, TimeOffset, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, TimeOffset, 'thisown', 0)
        self.__class__ = TimeOffset
_Piavca.TimeOffset_swigregister(TimeOffsetPtr)

class TurnMotion(MotionFilter):
    __swig_setmethods__ = {}
    for _s in [MotionFilter]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, TurnMotion, name, value)
    __swig_getmethods__ = {}
    for _s in [MotionFilter]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, TurnMotion, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::TurnMotion instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        _swig_setattr(self, TurnMotion, 'this', _Piavca.new_TurnMotion(*args))
        _swig_setattr(self, TurnMotion, 'thisown', 1)
    def clone(*args): return _Piavca.TurnMotion_clone(*args)
    def getFloatValueAtTimeInternal(*args): return _Piavca.TurnMotion_getFloatValueAtTimeInternal(*args)
    def getVecValueAtTimeInternal(*args): return _Piavca.TurnMotion_getVecValueAtTimeInternal(*args)
    def getQuatValueAtTimeInternal(*args): return _Piavca.TurnMotion_getQuatValueAtTimeInternal(*args)
    def setRotation(*args): return _Piavca.TurnMotion_setRotation(*args)
    def __del__(self, destroy=_Piavca.delete_TurnMotion):
        try:
            if self.thisown: destroy(self)
        except: pass


class TurnMotionPtr(TurnMotion):
    def __init__(self, this):
        _swig_setattr(self, TurnMotion, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, TurnMotion, 'thisown', 0)
        self.__class__ = TurnMotion
_Piavca.TurnMotion_swigregister(TurnMotionPtr)

class SequentialBlend(TwoMotionCombiner):
    __swig_setmethods__ = {}
    for _s in [TwoMotionCombiner]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, SequentialBlend, name, value)
    __swig_getmethods__ = {}
    for _s in [TwoMotionCombiner]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, SequentialBlend, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::SequentialBlend instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        _swig_setattr(self, SequentialBlend, 'this', _Piavca.new_SequentialBlend(*args))
        _swig_setattr(self, SequentialBlend, 'thisown', 1)
    def clone(*args): return _Piavca.SequentialBlend_clone(*args)
    def setMaintainY(*args): return _Piavca.SequentialBlend_setMaintainY(*args)
    def setStartTime(*args): return _Piavca.SequentialBlend_setStartTime(*args)
    def getMotionLength(*args): return _Piavca.SequentialBlend_getMotionLength(*args)
    def getFloatValueAtTimeInternal(*args): return _Piavca.SequentialBlend_getFloatValueAtTimeInternal(*args)
    def getVecValueAtTimeInternal(*args): return _Piavca.SequentialBlend_getVecValueAtTimeInternal(*args)
    def getQuatValueAtTimeInternal(*args): return _Piavca.SequentialBlend_getQuatValueAtTimeInternal(*args)
    def setBlendStart(*args): return _Piavca.SequentialBlend_setBlendStart(*args)
    def setBlendInterval(*args): return _Piavca.SequentialBlend_setBlendInterval(*args)
    def getBlendStart(*args): return _Piavca.SequentialBlend_getBlendStart(*args)
    def getBlendInterval(*args): return _Piavca.SequentialBlend_getBlendInterval(*args)
    def __del__(self, destroy=_Piavca.delete_SequentialBlend):
        try:
            if self.thisown: destroy(self)
        except: pass


class SequentialBlendPtr(SequentialBlend):
    def __init__(self, this):
        _swig_setattr(self, SequentialBlend, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, SequentialBlend, 'thisown', 0)
        self.__class__ = SequentialBlend
_Piavca.SequentialBlend_swigregister(SequentialBlendPtr)

class SelfBlend(SequentialBlend):
    __swig_setmethods__ = {}
    for _s in [SequentialBlend]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, SelfBlend, name, value)
    __swig_getmethods__ = {}
    for _s in [SequentialBlend]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, SelfBlend, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::SelfBlend instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        _swig_setattr(self, SelfBlend, 'this', _Piavca.new_SelfBlend(*args))
        _swig_setattr(self, SelfBlend, 'thisown', 1)
    def clone(*args): return _Piavca.SelfBlend_clone(*args)
    def reset(*args): return _Piavca.SelfBlend_reset(*args)
    def reblend(*args): return _Piavca.SelfBlend_reblend(*args)
    def setMotion(*args): return _Piavca.SelfBlend_setMotion(*args)
    def __del__(self, destroy=_Piavca.delete_SelfBlend):
        try:
            if self.thisown: destroy(self)
        except: pass


class SelfBlendPtr(SelfBlend):
    def __init__(self, this):
        _swig_setattr(self, SelfBlend, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, SelfBlend, 'thisown', 0)
        self.__class__ = SelfBlend
_Piavca.SelfBlend_swigregister(SelfBlendPtr)

class LoopMotion(SelfBlend):
    __swig_setmethods__ = {}
    for _s in [SelfBlend]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, LoopMotion, name, value)
    __swig_getmethods__ = {}
    for _s in [SelfBlend]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, LoopMotion, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::LoopMotion instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        _swig_setattr(self, LoopMotion, 'this', _Piavca.new_LoopMotion(*args))
        _swig_setattr(self, LoopMotion, 'thisown', 1)
    def clone(*args): return _Piavca.LoopMotion_clone(*args)
    def getMotionLength(*args): return _Piavca.LoopMotion_getMotionLength(*args)
    def setEndTime(*args): return _Piavca.LoopMotion_setEndTime(*args)
    def getFloatValueAtTimeInternal(*args): return _Piavca.LoopMotion_getFloatValueAtTimeInternal(*args)
    def getVecValueAtTimeInternal(*args): return _Piavca.LoopMotion_getVecValueAtTimeInternal(*args)
    def getQuatValueAtTimeInternal(*args): return _Piavca.LoopMotion_getQuatValueAtTimeInternal(*args)
    def __del__(self, destroy=_Piavca.delete_LoopMotion):
        try:
            if self.thisown: destroy(self)
        except: pass


class LoopMotionPtr(LoopMotion):
    def __init__(self, this):
        _swig_setattr(self, LoopMotion, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, LoopMotion, 'thisown', 0)
        self.__class__ = LoopMotion
_Piavca.LoopMotion_swigregister(LoopMotionPtr)

class RandomTimingsLoop(LoopMotion):
    __swig_setmethods__ = {}
    for _s in [LoopMotion]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, RandomTimingsLoop, name, value)
    __swig_getmethods__ = {}
    for _s in [LoopMotion]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, RandomTimingsLoop, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::RandomTimingsLoop instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        _swig_setattr(self, RandomTimingsLoop, 'this', _Piavca.new_RandomTimingsLoop(*args))
        _swig_setattr(self, RandomTimingsLoop, 'thisown', 1)
    def __del__(self, destroy=_Piavca.delete_RandomTimingsLoop):
        try:
            if self.thisown: destroy(self)
        except: pass

    def clone(*args): return _Piavca.RandomTimingsLoop_clone(*args)
    def setTimingParams(*args): return _Piavca.RandomTimingsLoop_setTimingParams(*args)
    def reblend(*args): return _Piavca.RandomTimingsLoop_reblend(*args)
    def setMotion(*args): return _Piavca.RandomTimingsLoop_setMotion(*args)

class RandomTimingsLoopPtr(RandomTimingsLoop):
    def __init__(self, this):
        _swig_setattr(self, RandomTimingsLoop, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, RandomTimingsLoop, 'thisown', 0)
        self.__class__ = RandomTimingsLoop
_Piavca.RandomTimingsLoop_swigregister(RandomTimingsLoopPtr)

class AvatarPostureBlend(SequentialBlend):
    __swig_setmethods__ = {}
    for _s in [SequentialBlend]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, AvatarPostureBlend, name, value)
    __swig_getmethods__ = {}
    for _s in [SequentialBlend]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, AvatarPostureBlend, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::AvatarPostureBlend instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        _swig_setattr(self, AvatarPostureBlend, 'this', _Piavca.new_AvatarPostureBlend(*args))
        _swig_setattr(self, AvatarPostureBlend, 'thisown', 1)
    def clone(*args): return _Piavca.AvatarPostureBlend_clone(*args)
    def load(*args): return _Piavca.AvatarPostureBlend_load(*args)
    def reblend(*args): return _Piavca.AvatarPostureBlend_reblend(*args)
    def __del__(self, destroy=_Piavca.delete_AvatarPostureBlend):
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
    __swig_setmethods__ = {}
    for _s in [TwoMotionCombiner]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, BlendBetween, name, value)
    __swig_getmethods__ = {}
    for _s in [TwoMotionCombiner]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, BlendBetween, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::BlendBetween instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        _swig_setattr(self, BlendBetween, 'this', _Piavca.new_BlendBetween(*args))
        _swig_setattr(self, BlendBetween, 'thisown', 1)
    def clone(*args): return _Piavca.BlendBetween_clone(*args)
    def getFloatValueAtTimeInternal(*args): return _Piavca.BlendBetween_getFloatValueAtTimeInternal(*args)
    def getVecValueAtTimeInternal(*args): return _Piavca.BlendBetween_getVecValueAtTimeInternal(*args)
    def getQuatValueAtTimeInternal(*args): return _Piavca.BlendBetween_getQuatValueAtTimeInternal(*args)
    def setBlendFactor(*args): return _Piavca.BlendBetween_setBlendFactor(*args)
    def __del__(self, destroy=_Piavca.delete_BlendBetween):
        try:
            if self.thisown: destroy(self)
        except: pass


class BlendBetweenPtr(BlendBetween):
    def __init__(self, this):
        _swig_setattr(self, BlendBetween, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, BlendBetween, 'thisown', 0)
        self.__class__ = BlendBetween
_Piavca.BlendBetween_swigregister(BlendBetweenPtr)

class MotionAdder(TwoMotionCombiner):
    __swig_setmethods__ = {}
    for _s in [TwoMotionCombiner]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, MotionAdder, name, value)
    __swig_getmethods__ = {}
    for _s in [TwoMotionCombiner]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, MotionAdder, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::MotionAdder instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        _swig_setattr(self, MotionAdder, 'this', _Piavca.new_MotionAdder(*args))
        _swig_setattr(self, MotionAdder, 'thisown', 1)
    def clone(*args): return _Piavca.MotionAdder_clone(*args)
    def setScaleSecond(*args): return _Piavca.MotionAdder_setScaleSecond(*args)
    def getFloatValueAtTimeInternal(*args): return _Piavca.MotionAdder_getFloatValueAtTimeInternal(*args)
    def getVecValueAtTimeInternal(*args): return _Piavca.MotionAdder_getVecValueAtTimeInternal(*args)
    def getQuatValueAtTimeInternal(*args): return _Piavca.MotionAdder_getQuatValueAtTimeInternal(*args)
    def __del__(self, destroy=_Piavca.delete_MotionAdder):
        try:
            if self.thisown: destroy(self)
        except: pass


class MotionAdderPtr(MotionAdder):
    def __init__(self, this):
        _swig_setattr(self, MotionAdder, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, MotionAdder, 'thisown', 0)
        self.__class__ = MotionAdder
_Piavca.MotionAdder_swigregister(MotionAdderPtr)

class MotionMask(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, MotionMask, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, MotionMask, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::MotionMask instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        _swig_setattr(self, MotionMask, 'this', _Piavca.new_MotionMask(*args))
        _swig_setattr(self, MotionMask, 'thisown', 1)
    def setMask(*args): return _Piavca.MotionMask_setMask(*args)
    def getMask(*args): return _Piavca.MotionMask_getMask(*args)
    def __del__(self, destroy=_Piavca.delete_MotionMask):
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
    __swig_setmethods__ = {}
    for _s in [TwoMotionCombiner]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, MaskedMotion, name, value)
    __swig_getmethods__ = {}
    for _s in [TwoMotionCombiner]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, MaskedMotion, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::MaskedMotion instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        _swig_setattr(self, MaskedMotion, 'this', _Piavca.new_MaskedMotion(*args))
        _swig_setattr(self, MaskedMotion, 'thisown', 1)
    def clone(*args): return _Piavca.MaskedMotion_clone(*args)
    def setUseSecondary(*args): return _Piavca.MaskedMotion_setUseSecondary(*args)
    def setMask1(*args): return _Piavca.MaskedMotion_setMask1(*args)
    def setMask2(*args): return _Piavca.MaskedMotion_setMask2(*args)
    def addToMask1(*args): return _Piavca.MaskedMotion_addToMask1(*args)
    def removeFromMask1(*args): return _Piavca.MaskedMotion_removeFromMask1(*args)
    def addToMask2(*args): return _Piavca.MaskedMotion_addToMask2(*args)
    def removeFromMask2(*args): return _Piavca.MaskedMotion_removeFromMask2(*args)
    def getFloatValueAtTimeInternal(*args): return _Piavca.MaskedMotion_getFloatValueAtTimeInternal(*args)
    def getVecValueAtTimeInternal(*args): return _Piavca.MaskedMotion_getVecValueAtTimeInternal(*args)
    def getQuatValueAtTimeInternal(*args): return _Piavca.MaskedMotion_getQuatValueAtTimeInternal(*args)
    def __del__(self, destroy=_Piavca.delete_MaskedMotion):
        try:
            if self.thisown: destroy(self)
        except: pass


class MaskedMotionPtr(MaskedMotion):
    def __init__(self, this):
        _swig_setattr(self, MaskedMotion, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, MaskedMotion, 'thisown', 0)
        self.__class__ = MaskedMotion
_Piavca.MaskedMotion_swigregister(MaskedMotionPtr)

class MultiMotionLoop(RandomTimingsLoop):
    __swig_setmethods__ = {}
    for _s in [RandomTimingsLoop]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, MultiMotionLoop, name, value)
    __swig_getmethods__ = {}
    for _s in [RandomTimingsLoop]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, MultiMotionLoop, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::MultiMotionLoop instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        _swig_setattr(self, MultiMotionLoop, 'this', _Piavca.new_MultiMotionLoop(*args))
        _swig_setattr(self, MultiMotionLoop, 'thisown', 1)
    def __del__(self, destroy=_Piavca.delete_MultiMotionLoop):
        try:
            if self.thisown: destroy(self)
        except: pass

    def clone(*args): return _Piavca.MultiMotionLoop_clone(*args)
    def printInfo(*args): return _Piavca.MultiMotionLoop_printInfo(*args)
    def addMotion(*args): return _Piavca.MultiMotionLoop_addMotion(*args)
    def findSub(*args): return _Piavca.MultiMotionLoop_findSub(*args)
    def findSubByType(*args): return _Piavca.MultiMotionLoop_findSubByType(*args)
    def load(*args): return _Piavca.MultiMotionLoop_load(*args)
    def unload(*args): return _Piavca.MultiMotionLoop_unload(*args)
    def loaded(*args): return _Piavca.MultiMotionLoop_loaded(*args)

class MultiMotionLoopPtr(MultiMotionLoop):
    def __init__(self, this):
        _swig_setattr(self, MultiMotionLoop, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, MultiMotionLoop, 'thisown', 0)
        self.__class__ = MultiMotionLoop
_Piavca.MultiMotionLoop_swigregister(MultiMotionLoopPtr)

class ChoiceLoopMotion(MultiMotionLoop):
    __swig_setmethods__ = {}
    for _s in [MultiMotionLoop]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, ChoiceLoopMotion, name, value)
    __swig_getmethods__ = {}
    for _s in [MultiMotionLoop]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, ChoiceLoopMotion, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::ChoiceLoopMotion instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        _swig_setattr(self, ChoiceLoopMotion, 'this', _Piavca.new_ChoiceLoopMotion(*args))
        _swig_setattr(self, ChoiceLoopMotion, 'thisown', 1)
    def __del__(self, destroy=_Piavca.delete_ChoiceLoopMotion):
        try:
            if self.thisown: destroy(self)
        except: pass

    def clone(*args): return _Piavca.ChoiceLoopMotion_clone(*args)
    def setCurrentChoice(*args): return _Piavca.ChoiceLoopMotion_setCurrentChoice(*args)
    def reblend(*args): return _Piavca.ChoiceLoopMotion_reblend(*args)

class ChoiceLoopMotionPtr(ChoiceLoopMotion):
    def __init__(self, this):
        _swig_setattr(self, ChoiceLoopMotion, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, ChoiceLoopMotion, 'thisown', 0)
        self.__class__ = ChoiceLoopMotion
_Piavca.ChoiceLoopMotion_swigregister(ChoiceLoopMotionPtr)

class RandomLoopMotion(ChoiceLoopMotion):
    __swig_setmethods__ = {}
    for _s in [ChoiceLoopMotion]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, RandomLoopMotion, name, value)
    __swig_getmethods__ = {}
    for _s in [ChoiceLoopMotion]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, RandomLoopMotion, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::RandomLoopMotion instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        _swig_setattr(self, RandomLoopMotion, 'this', _Piavca.new_RandomLoopMotion(*args))
        _swig_setattr(self, RandomLoopMotion, 'thisown', 1)
    def __del__(self, destroy=_Piavca.delete_RandomLoopMotion):
        try:
            if self.thisown: destroy(self)
        except: pass

    def clone(*args): return _Piavca.RandomLoopMotion_clone(*args)
    __swig_getmethods__["convertTo"] = lambda x: _Piavca.RandomLoopMotion_convertTo
    if _newclass:convertTo = staticmethod(_Piavca.RandomLoopMotion_convertTo)
    def addMotion(*args): return _Piavca.RandomLoopMotion_addMotion(*args)
    def setProbability(*args): return _Piavca.RandomLoopMotion_setProbability(*args)
    def reblend(*args): return _Piavca.RandomLoopMotion_reblend(*args)

class RandomLoopMotionPtr(RandomLoopMotion):
    def __init__(self, this):
        _swig_setattr(self, RandomLoopMotion, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, RandomLoopMotion, 'thisown', 0)
        self.__class__ = RandomLoopMotion
_Piavca.RandomLoopMotion_swigregister(RandomLoopMotionPtr)

RandomLoopMotion_convertTo = _Piavca.RandomLoopMotion_convertTo

class RandomBlendLoop(MultiMotionLoop):
    __swig_setmethods__ = {}
    for _s in [MultiMotionLoop]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, RandomBlendLoop, name, value)
    __swig_getmethods__ = {}
    for _s in [MultiMotionLoop]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, RandomBlendLoop, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::RandomBlendLoop instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        _swig_setattr(self, RandomBlendLoop, 'this', _Piavca.new_RandomBlendLoop(*args))
        _swig_setattr(self, RandomBlendLoop, 'thisown', 1)
    def __del__(self, destroy=_Piavca.delete_RandomBlendLoop):
        try:
            if self.thisown: destroy(self)
        except: pass

    def clone(*args): return _Piavca.RandomBlendLoop_clone(*args)
    def addMotion(*args): return _Piavca.RandomBlendLoop_addMotion(*args)
    def setAutoShift(*args): return _Piavca.RandomBlendLoop_setAutoShift(*args)
    def shift(*args): return _Piavca.RandomBlendLoop_shift(*args)
    def reblend(*args): return _Piavca.RandomBlendLoop_reblend(*args)

class RandomBlendLoopPtr(RandomBlendLoop):
    def __init__(self, this):
        _swig_setattr(self, RandomBlendLoop, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, RandomBlendLoop, 'thisown', 0)
        self.__class__ = RandomBlendLoop
_Piavca.RandomBlendLoop_swigregister(RandomBlendLoopPtr)

class RandomAddLoop(MultiMotionLoop):
    __swig_setmethods__ = {}
    for _s in [MultiMotionLoop]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, RandomAddLoop, name, value)
    __swig_getmethods__ = {}
    for _s in [MultiMotionLoop]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, RandomAddLoop, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::RandomAddLoop instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        _swig_setattr(self, RandomAddLoop, 'this', _Piavca.new_RandomAddLoop(*args))
        _swig_setattr(self, RandomAddLoop, 'thisown', 1)
    def __del__(self, destroy=_Piavca.delete_RandomAddLoop):
        try:
            if self.thisown: destroy(self)
        except: pass

    def clone(*args): return _Piavca.RandomAddLoop_clone(*args)
    def setAutoShift(*args): return _Piavca.RandomAddLoop_setAutoShift(*args)
    def shift(*args): return _Piavca.RandomAddLoop_shift(*args)
    def reblend(*args): return _Piavca.RandomAddLoop_reblend(*args)

class RandomAddLoopPtr(RandomAddLoop):
    def __init__(self, this):
        _swig_setattr(self, RandomAddLoop, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, RandomAddLoop, 'thisown', 0)
        self.__class__ = RandomAddLoop
_Piavca.RandomAddLoop_swigregister(RandomAddLoopPtr)

class ProxemicsLoop(MultiMotionLoop):
    __swig_setmethods__ = {}
    for _s in [MultiMotionLoop]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, ProxemicsLoop, name, value)
    __swig_getmethods__ = {}
    for _s in [MultiMotionLoop]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, ProxemicsLoop, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::ProxemicsLoop instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        _swig_setattr(self, ProxemicsLoop, 'this', _Piavca.new_ProxemicsLoop(*args))
        _swig_setattr(self, ProxemicsLoop, 'thisown', 1)
    def __del__(self, destroy=_Piavca.delete_ProxemicsLoop):
        try:
            if self.thisown: destroy(self)
        except: pass

    def clone(*args): return _Piavca.ProxemicsLoop_clone(*args)
    def setDistance(*args): return _Piavca.ProxemicsLoop_setDistance(*args)
    def setThreshold(*args): return _Piavca.ProxemicsLoop_setThreshold(*args)
    def setAngleThreshold(*args): return _Piavca.ProxemicsLoop_setAngleThreshold(*args)
    def turnOff(*args): return _Piavca.ProxemicsLoop_turnOff(*args)
    def addAvatar(*args): return _Piavca.ProxemicsLoop_addAvatar(*args)
    def removeAvatar(*args): return _Piavca.ProxemicsLoop_removeAvatar(*args)
    def removeAllAvatars(*args): return _Piavca.ProxemicsLoop_removeAllAvatars(*args)
    def reblend(*args): return _Piavca.ProxemicsLoop_reblend(*args)

class ProxemicsLoopPtr(ProxemicsLoop):
    def __init__(self, this):
        _swig_setattr(self, ProxemicsLoop, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, ProxemicsLoop, 'thisown', 0)
        self.__class__ = ProxemicsLoop
_Piavca.ProxemicsLoop_swigregister(ProxemicsLoopPtr)

class LookAtMotion(Motion):
    __swig_setmethods__ = {}
    for _s in [Motion]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, LookAtMotion, name, value)
    __swig_getmethods__ = {}
    for _s in [Motion]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, LookAtMotion, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::LookAtMotion instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        _swig_setattr(self, LookAtMotion, 'this', _Piavca.new_LookAtMotion(*args))
        _swig_setattr(self, LookAtMotion, 'thisown', 1)
    def clone(*args): return _Piavca.LookAtMotion_clone(*args)
    def isFacial(*args): return _Piavca.LookAtMotion_isFacial(*args)
    def isRandomAccess(*args): return _Piavca.LookAtMotion_isRandomAccess(*args)
    def load(*args): return _Piavca.LookAtMotion_load(*args)
    def reblend(*args): return _Piavca.LookAtMotion_reblend(*args)
    def setTarget(*args): return _Piavca.LookAtMotion_setTarget(*args)
    def getTargetName(*args): return _Piavca.LookAtMotion_getTargetName(*args)
    def setHeadActive(*args): return _Piavca.LookAtMotion_setHeadActive(*args)
    def setBodyActive(*args): return _Piavca.LookAtMotion_setBodyActive(*args)
    def setTurnBodyVertical(*args): return _Piavca.LookAtMotion_setTurnBodyVertical(*args)
    def setTurnBodyFull(*args): return _Piavca.LookAtMotion_setTurnBodyFull(*args)
    def setLeanTowards(*args): return _Piavca.LookAtMotion_setLeanTowards(*args)
    def setEyesLimit(*args): return _Piavca.LookAtMotion_setEyesLimit(*args)
    def setHeadBodyLimit(*args): return _Piavca.LookAtMotion_setHeadBodyLimit(*args)
    def setEyesMorphAngle(*args): return _Piavca.LookAtMotion_setEyesMorphAngle(*args)
    def setEndTime(*args): return _Piavca.LookAtMotion_setEndTime(*args)
    def getMotionLength(*args): return _Piavca.LookAtMotion_getMotionLength(*args)
    def isNull(*args): return _Piavca.LookAtMotion_isNull(*args)
    def isNullFacial(*args): return _Piavca.LookAtMotion_isNullFacial(*args)
    def getTrackType(*args): return _Piavca.LookAtMotion_getTrackType(*args)
    def canLookAt(*args): return _Piavca.LookAtMotion_canLookAt(*args)
    def getFloatValueAtTimeInternal(*args): return _Piavca.LookAtMotion_getFloatValueAtTimeInternal(*args)
    def getVecValueAtTimeInternal(*args): return _Piavca.LookAtMotion_getVecValueAtTimeInternal(*args)
    def getQuatValueAtTimeInternal(*args): return _Piavca.LookAtMotion_getQuatValueAtTimeInternal(*args)
    def __del__(self, destroy=_Piavca.delete_LookAtMotion):
        try:
            if self.thisown: destroy(self)
        except: pass


class LookAtMotionPtr(LookAtMotion):
    def __init__(self, this):
        _swig_setattr(self, LookAtMotion, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, LookAtMotion, 'thisown', 0)
        self.__class__ = LookAtMotion
_Piavca.LookAtMotion_swigregister(LookAtMotionPtr)

class LookAtToFacial(MotionFilter):
    __swig_setmethods__ = {}
    for _s in [MotionFilter]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, LookAtToFacial, name, value)
    __swig_getmethods__ = {}
    for _s in [MotionFilter]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, LookAtToFacial, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::LookAtToFacial instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        _swig_setattr(self, LookAtToFacial, 'this', _Piavca.new_LookAtToFacial(*args))
        _swig_setattr(self, LookAtToFacial, 'thisown', 1)
    def clone(*args): return _Piavca.LookAtToFacial_clone(*args)
    def load(*args): return _Piavca.LookAtToFacial_load(*args)
    def isFacial(*args): return _Piavca.LookAtToFacial_isFacial(*args)
    def isNull(*args): return _Piavca.LookAtToFacial_isNull(*args)
    def getFloatValueAtTimeInternal(*args): return _Piavca.LookAtToFacial_getFloatValueAtTimeInternal(*args)
    def getVecValueAtTimeInternal(*args): return _Piavca.LookAtToFacial_getVecValueAtTimeInternal(*args)
    def getQuatValueAtTimeInternal(*args): return _Piavca.LookAtToFacial_getQuatValueAtTimeInternal(*args)
    def __del__(self, destroy=_Piavca.delete_LookAtToFacial):
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
    __swig_setmethods__ = {}
    for _s in [LoopMotion]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, RandomGazeMotion, name, value)
    __swig_getmethods__ = {}
    for _s in [LoopMotion]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, RandomGazeMotion, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::RandomGazeMotion instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        _swig_setattr(self, RandomGazeMotion, 'this', _Piavca.new_RandomGazeMotion(*args))
        _swig_setattr(self, RandomGazeMotion, 'thisown', 1)
    def __del__(self, destroy=_Piavca.delete_RandomGazeMotion):
        try:
            if self.thisown: destroy(self)
        except: pass

    def clone(*args): return _Piavca.RandomGazeMotion_clone(*args)
    def clearDirectionTable(*args): return _Piavca.RandomGazeMotion_clearDirectionTable(*args)
    def addDirection(*args): return _Piavca.RandomGazeMotion_addDirection(*args)
    def normaliseDirectionTable(*args): return _Piavca.RandomGazeMotion_normaliseDirectionTable(*args)
    def addAvatarTarget(*args): return _Piavca.RandomGazeMotion_addAvatarTarget(*args)
    def addObjectTarget(*args): return _Piavca.RandomGazeMotion_addObjectTarget(*args)
    def setTargetFlags(*args): return _Piavca.RandomGazeMotion_setTargetFlags(*args)
    def setGazeParams(*args): return _Piavca.RandomGazeMotion_setGazeParams(*args)
    def setLookAtLocationProb(*args): return _Piavca.RandomGazeMotion_setLookAtLocationProb(*args)
    def setMeanGazeLength(*args): return _Piavca.RandomGazeMotion_setMeanGazeLength(*args)
    def setEyesLimit(*args): return _Piavca.RandomGazeMotion_setEyesLimit(*args)
    def setHeadBodyLimit(*args): return _Piavca.RandomGazeMotion_setHeadBodyLimit(*args)
    def setEyesMorphAngle(*args): return _Piavca.RandomGazeMotion_setEyesMorphAngle(*args)
    def randomLocation(*args): return _Piavca.RandomGazeMotion_randomLocation(*args)
    def lookAt(*args): return _Piavca.RandomGazeMotion_lookAt(*args)
    def reblend(*args): return _Piavca.RandomGazeMotion_reblend(*args)

class RandomGazeMotionPtr(RandomGazeMotion):
    def __init__(self, this):
        _swig_setattr(self, RandomGazeMotion, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, RandomGazeMotion, 'thisown', 0)
        self.__class__ = RandomGazeMotion
_Piavca.RandomGazeMotion_swigregister(RandomGazeMotionPtr)

class ZeroMotion(Motion):
    __swig_setmethods__ = {}
    for _s in [Motion]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, ZeroMotion, name, value)
    __swig_getmethods__ = {}
    for _s in [Motion]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, ZeroMotion, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::ZeroMotion instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        _swig_setattr(self, ZeroMotion, 'this', _Piavca.new_ZeroMotion(*args))
        _swig_setattr(self, ZeroMotion, 'thisown', 1)
    def clone(*args): return _Piavca.ZeroMotion_clone(*args)
    def isFacial(*args): return _Piavca.ZeroMotion_isFacial(*args)
    def isRandomAccess(*args): return _Piavca.ZeroMotion_isRandomAccess(*args)
    def getMotionLength(*args): return _Piavca.ZeroMotion_getMotionLength(*args)
    def isNull(*args): return _Piavca.ZeroMotion_isNull(*args)
    def getTrackType(*args): return _Piavca.ZeroMotion_getTrackType(*args)
    def getFloatValueAtTimeInternal(*args): return _Piavca.ZeroMotion_getFloatValueAtTimeInternal(*args)
    def getVecValueAtTimeInternal(*args): return _Piavca.ZeroMotion_getVecValueAtTimeInternal(*args)
    def getQuatValueAtTimeInternal(*args): return _Piavca.ZeroMotion_getQuatValueAtTimeInternal(*args)
    def __del__(self, destroy=_Piavca.delete_ZeroMotion):
        try:
            if self.thisown: destroy(self)
        except: pass


class ZeroMotionPtr(ZeroMotion):
    def __init__(self, this):
        _swig_setattr(self, ZeroMotion, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, ZeroMotion, 'thisown', 0)
        self.__class__ = ZeroMotion
_Piavca.ZeroMotion_swigregister(ZeroMotionPtr)

class MotionSaver(MotionFilter):
    __swig_setmethods__ = {}
    for _s in [MotionFilter]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, MotionSaver, name, value)
    __swig_getmethods__ = {}
    for _s in [MotionFilter]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, MotionSaver, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::MotionSaver instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        _swig_setattr(self, MotionSaver, 'this', _Piavca.new_MotionSaver(*args))
        _swig_setattr(self, MotionSaver, 'thisown', 1)
    def clone(*args): return _Piavca.MotionSaver_clone(*args)
    def getFloatValueAtTimeInternal(*args): return _Piavca.MotionSaver_getFloatValueAtTimeInternal(*args)
    def getVecValueAtTimeInternal(*args): return _Piavca.MotionSaver_getVecValueAtTimeInternal(*args)
    def getQuatValueAtTimeInternal(*args): return _Piavca.MotionSaver_getQuatValueAtTimeInternal(*args)
    def collectFrames(*args): return _Piavca.MotionSaver_collectFrames(*args)
    def save(*args): return _Piavca.MotionSaver_save(*args)
    def __del__(self, destroy=_Piavca.delete_MotionSaver):
        try:
            if self.thisown: destroy(self)
        except: pass


class MotionSaverPtr(MotionSaver):
    def __init__(self, this):
        _swig_setattr(self, MotionSaver, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, MotionSaver, 'thisown', 0)
        self.__class__ = MotionSaver
_Piavca.MotionSaver_swigregister(MotionSaverPtr)

class MotionParser(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, MotionParser, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, MotionParser, name)
    def __init__(self): raise RuntimeError, "No constructor defined"
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::MotionParser instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def editMotion(*args): return _Piavca.MotionParser_editMotion(*args)
    def editAvatarMotion(*args): return _Piavca.MotionParser_editAvatarMotion(*args)
    __swig_getmethods__["parseMotion"] = lambda x: _Piavca.MotionParser_parseMotion
    if _newclass:parseMotion = staticmethod(_Piavca.MotionParser_parseMotion)
    __swig_getmethods__["addMotionCommand"] = lambda x: _Piavca.MotionParser_addMotionCommand
    if _newclass:addMotionCommand = staticmethod(_Piavca.MotionParser_addMotionCommand)
    __swig_getmethods__["getMotionCommand"] = lambda x: _Piavca.MotionParser_getMotionCommand
    if _newclass:getMotionCommand = staticmethod(_Piavca.MotionParser_getMotionCommand)
    __swig_getmethods__["setUpMotionCommands"] = lambda x: _Piavca.MotionParser_setUpMotionCommands
    if _newclass:setUpMotionCommands = staticmethod(_Piavca.MotionParser_setUpMotionCommands)
    def __del__(self, destroy=_Piavca.delete_MotionParser):
        try:
            if self.thisown: destroy(self)
        except: pass


class MotionParserPtr(MotionParser):
    def __init__(self, this):
        _swig_setattr(self, MotionParser, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, MotionParser, 'thisown', 0)
        self.__class__ = MotionParser
_Piavca.MotionParser_swigregister(MotionParserPtr)

MotionParser_parseMotion = _Piavca.MotionParser_parseMotion

MotionParser_addMotionCommand = _Piavca.MotionParser_addMotionCommand

MotionParser_getMotionCommand = _Piavca.MotionParser_getMotionCommand

MotionParser_setUpMotionCommands = _Piavca.MotionParser_setUpMotionCommands

class SubMotion(MotionFilter):
    __swig_setmethods__ = {}
    for _s in [MotionFilter]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, SubMotion, name, value)
    __swig_getmethods__ = {}
    for _s in [MotionFilter]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, SubMotion, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::SubMotion instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        _swig_setattr(self, SubMotion, 'this', _Piavca.new_SubMotion(*args))
        _swig_setattr(self, SubMotion, 'thisown', 1)
    def clone(*args): return _Piavca.SubMotion_clone(*args)
    def getMotionLength(*args): return _Piavca.SubMotion_getMotionLength(*args)
    def setStart(*args): return _Piavca.SubMotion_setStart(*args)
    def setEnd(*args): return _Piavca.SubMotion_setEnd(*args)
    def getFloatValueAtTimeInternal(*args): return _Piavca.SubMotion_getFloatValueAtTimeInternal(*args)
    def getVecValueAtTimeInternal(*args): return _Piavca.SubMotion_getVecValueAtTimeInternal(*args)
    def getQuatValueAtTimeInternal(*args): return _Piavca.SubMotion_getQuatValueAtTimeInternal(*args)
    def __del__(self, destroy=_Piavca.delete_SubMotion):
        try:
            if self.thisown: destroy(self)
        except: pass


class SubMotionPtr(SubMotion):
    def __init__(self, this):
        _swig_setattr(self, SubMotion, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, SubMotion, 'thisown', 0)
        self.__class__ = SubMotion
_Piavca.SubMotion_swigregister(SubMotionPtr)

class TimeRangeMotion(MotionFilter):
    __swig_setmethods__ = {}
    for _s in [MotionFilter]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, TimeRangeMotion, name, value)
    __swig_getmethods__ = {}
    for _s in [MotionFilter]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, TimeRangeMotion, name)
    def __repr__(self):
        return "<%s.%s; proxy of C++ Piavca::TimeRangeMotion instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args):
        _swig_setattr(self, TimeRangeMotion, 'this', _Piavca.new_TimeRangeMotion(*args))
        _swig_setattr(self, TimeRangeMotion, 'thisown', 1)
    def clone(*args): return _Piavca.TimeRangeMotion_clone(*args)
    def setStart(*args): return _Piavca.TimeRangeMotion_setStart(*args)
    def setEnd(*args): return _Piavca.TimeRangeMotion_setEnd(*args)
    def getFloatValueAtTimeInternal(*args): return _Piavca.TimeRangeMotion_getFloatValueAtTimeInternal(*args)
    def getVecValueAtTimeInternal(*args): return _Piavca.TimeRangeMotion_getVecValueAtTimeInternal(*args)
    def getQuatValueAtTimeInternal(*args): return _Piavca.TimeRangeMotion_getQuatValueAtTimeInternal(*args)
    def __del__(self, destroy=_Piavca.delete_TimeRangeMotion):
        try:
            if self.thisown: destroy(self)
        except: pass


class TimeRangeMotionPtr(TimeRangeMotion):
    def __init__(self, this):
        _swig_setattr(self, TimeRangeMotion, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, TimeRangeMotion, 'thisown', 0)
        self.__class__ = TimeRangeMotion
_Piavca.TimeRangeMotion_swigregister(TimeRangeMotionPtr)



