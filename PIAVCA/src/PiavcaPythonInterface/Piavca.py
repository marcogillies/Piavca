# This file was created automatically by SWIG 1.3.29.
# Don't modify this file, modify the SWIG interface instead.
# This file is compatible with both classic and new-style classes.

import _Piavca
import new
new_instancemethod = new.instancemethod
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
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, TimeCallback, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, TimeCallback, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        if self.__class__ == TimeCallback:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_TimeCallback(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca.delete_TimeCallback
    __del__ = lambda self : None;
    def getName(*args): return _Piavca.TimeCallback_getName(*args)
    def init(*args): return _Piavca.TimeCallback_init(*args)
    def timeStep(*args): return _Piavca.TimeCallback_timeStep(*args)
    def __disown__(self):
        self.this.disown()
        _Piavca.disown_TimeCallback(self)
        return weakref_proxy(self)
TimeCallback_swigregister = _Piavca.TimeCallback_swigregister
TimeCallback_swigregister(TimeCallback)

class AvatarTimeCallback(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, AvatarTimeCallback, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, AvatarTimeCallback, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        if self.__class__ == AvatarTimeCallback:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_AvatarTimeCallback(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca.delete_AvatarTimeCallback
    __del__ = lambda self : None;
    def getName(*args): return _Piavca.AvatarTimeCallback_getName(*args)
    def init(*args): return _Piavca.AvatarTimeCallback_init(*args)
    def timeStep(*args): return _Piavca.AvatarTimeCallback_timeStep(*args)
    def __disown__(self):
        self.this.disown()
        _Piavca.disown_AvatarTimeCallback(self)
        return weakref_proxy(self)
AvatarTimeCallback_swigregister = _Piavca.AvatarTimeCallback_swigregister
AvatarTimeCallback_swigregister(AvatarTimeCallback)

class Core(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Core, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Core, name)
    def __init__(self): raise AttributeError, "No constructor defined"
    __repr__ = _swig_repr
    __swig_setmethods__["dir"] = _Piavca.Core_dir_set
    __swig_getmethods__["dir"] = _Piavca.Core_dir_get
    if _newclass:dir = property(_Piavca.Core_dir_get, _Piavca.Core_dir_set)
    __swig_destroy__ = _Piavca.delete_Core
    __del__ = lambda self : None;
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
    def addProfilePoint(*args): return _Piavca.Core_addProfilePoint(*args)
    def profilePointStart(*args): return _Piavca.Core_profilePointStart(*args)
    def profilePointEnd(*args): return _Piavca.Core_profilePointEnd(*args)
    def printProfileData(*args): return _Piavca.Core_printProfileData(*args)
Core_swigregister = _Piavca.Core_swigregister
Core_swigregister(Core)
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
TRANS_NO_ROOT_POS_CORRECTION = _Piavca.TRANS_NO_ROOT_POS_CORRECTION
class Motion(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Motion, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Motion, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        if self.__class__ == Motion:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_Motion(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca.delete_Motion
    __del__ = lambda self : None;
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
    def __disown__(self):
        self.this.disown()
        _Piavca.disown_Motion(self)
        return weakref_proxy(self)
Motion_swigregister = _Piavca.Motion_swigregister
Motion_swigregister(Motion)

class TrackMotion(Motion):
    __swig_setmethods__ = {}
    for _s in [Motion]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, TrackMotion, name, value)
    __swig_getmethods__ = {}
    for _s in [Motion]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, TrackMotion, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        if self.__class__ == TrackMotion:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_TrackMotion(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca.delete_TrackMotion
    __del__ = lambda self : None;
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
    def __disown__(self):
        self.this.disown()
        _Piavca.disown_TrackMotion(self)
        return weakref_proxy(self)
TrackMotion_swigregister = _Piavca.TrackMotion_swigregister
TrackMotion_swigregister(TrackMotion)

copyMotionPosture = _Piavca.copyMotionPosture
class Avatar(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Avatar, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Avatar, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _Piavca.new_Avatar(*args)
        try: self.this.append(this)
        except: self.this = this
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
        this = _Piavca.new_queueElement(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca.delete_queueElement
    __del__ = lambda self : None;
queueElement_swigregister = _Piavca.queueElement_swigregister
queueElement_swigregister(queueElement)

class AvatarMotionQueue(AvatarTimeCallback):
    __swig_setmethods__ = {}
    for _s in [AvatarTimeCallback]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, AvatarMotionQueue, name, value)
    __swig_getmethods__ = {}
    for _s in [AvatarTimeCallback]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, AvatarMotionQueue, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _Piavca.new_AvatarMotionQueue(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca.delete_AvatarMotionQueue
    __del__ = lambda self : None;
    __swig_getmethods__["getQueue"] = lambda x: _Piavca.AvatarMotionQueue_getQueue
    if _newclass:getQueue = staticmethod(_Piavca.AvatarMotionQueue_getQueue)
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
AvatarMotionQueue_swigregister = _Piavca.AvatarMotionQueue_swigregister
AvatarMotionQueue_swigregister(AvatarMotionQueue)
AvatarMotionQueue_getQueue = _Piavca.AvatarMotionQueue_getQueue

class Object(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Object, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Object, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _Piavca.new_Object(*args)
        try: self.this.append(this)
        except: self.this = this
    def getName(*args): return _Piavca.Object_getName(*args)
    def setName(*args): return _Piavca.Object_setName(*args)
    def setPosition(*args): return _Piavca.Object_setPosition(*args)
    def getPosition(*args): return _Piavca.Object_getPosition(*args)
    def setOrientation(*args): return _Piavca.Object_setOrientation(*args)
    def setAngle(*args): return _Piavca.Object_setAngle(*args)
    def setAngleDeg(*args): return _Piavca.Object_setAngleDeg(*args)
    def getOrientation(*args): return _Piavca.Object_getOrientation(*args)
    def scale(*args): return _Piavca.Object_scale(*args)
Object_swigregister = _Piavca.Object_swigregister
Object_swigregister(Object)

class PyTimeCallback(TimeCallback):
    __swig_setmethods__ = {}
    for _s in [TimeCallback]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, PyTimeCallback, name, value)
    __swig_getmethods__ = {}
    for _s in [TimeCallback]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, PyTimeCallback, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _Piavca.new_PyTimeCallback(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca.delete_PyTimeCallback
    __del__ = lambda self : None;
    def init(*args): return _Piavca.PyTimeCallback_init(*args)
    def timeStep(*args): return _Piavca.PyTimeCallback_timeStep(*args)
PyTimeCallback_swigregister = _Piavca.PyTimeCallback_swigregister
PyTimeCallback_swigregister(PyTimeCallback)

class PyAvatarTimeCallback(AvatarTimeCallback):
    __swig_setmethods__ = {}
    for _s in [AvatarTimeCallback]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, PyAvatarTimeCallback, name, value)
    __swig_getmethods__ = {}
    for _s in [AvatarTimeCallback]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, PyAvatarTimeCallback, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _Piavca.new_PyAvatarTimeCallback(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca.delete_PyAvatarTimeCallback
    __del__ = lambda self : None;
    def init(*args): return _Piavca.PyAvatarTimeCallback_init(*args)
    def timeStep(*args): return _Piavca.PyAvatarTimeCallback_timeStep(*args)
PyAvatarTimeCallback_swigregister = _Piavca.PyAvatarTimeCallback_swigregister
PyAvatarTimeCallback_swigregister(PyAvatarTimeCallback)

class PyMotion(Motion):
    __swig_setmethods__ = {}
    for _s in [Motion]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, PyMotion, name, value)
    __swig_getmethods__ = {}
    for _s in [Motion]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, PyMotion, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _Piavca.new_PyMotion(*args)
        try: self.this.append(this)
        except: self.this = this
    def clone(*args): return _Piavca.PyMotion_clone(*args)
    __swig_destroy__ = _Piavca.delete_PyMotion
    __del__ = lambda self : None;
    def setPyObj(*args): return _Piavca.PyMotion_setPyObj(*args)
    def getMotionPtr(*args): return _Piavca.PyMotion_getMotionPtr(*args)
    def getMotionLength(*args): return _Piavca.PyMotion_getMotionLength(*args)
    def isNull(*args): return _Piavca.PyMotion_isNull(*args)
    def getTrackType(*args): return _Piavca.PyMotion_getTrackType(*args)
    def getFloatValueAtTimeInternal(*args): return _Piavca.PyMotion_getFloatValueAtTimeInternal(*args)
    def getVecValueAtTimeInternal(*args): return _Piavca.PyMotion_getVecValueAtTimeInternal(*args)
    def getQuatValueAtTimeInternal(*args): return _Piavca.PyMotion_getQuatValueAtTimeInternal(*args)
PyMotion_swigregister = _Piavca.PyMotion_swigregister
PyMotion_swigregister(PyMotion)

degToRad = _Piavca.degToRad
radToDeg = _Piavca.radToDeg
class MotionFilter(Motion):
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
MotionFilter_swigregister = _Piavca.MotionFilter_swigregister
MotionFilter_swigregister(MotionFilter)
cvar = _Piavca.cvar
Pi = cvar.Pi

class TwoMotionCombiner(Motion):
    __swig_setmethods__ = {}
    for _s in [Motion]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, TwoMotionCombiner, name, value)
    __swig_getmethods__ = {}
    for _s in [Motion]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, TwoMotionCombiner, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        if self.__class__ == TwoMotionCombiner:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_TwoMotionCombiner(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca.delete_TwoMotionCombiner
    __del__ = lambda self : None;
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
    def __disown__(self):
        self.this.disown()
        _Piavca.disown_TwoMotionCombiner(self)
        return weakref_proxy(self)
TwoMotionCombiner_swigregister = _Piavca.TwoMotionCombiner_swigregister
TwoMotionCombiner_swigregister(TwoMotionCombiner)

class ScaleMotion(MotionFilter):
    __swig_setmethods__ = {}
    for _s in [MotionFilter]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, ScaleMotion, name, value)
    __swig_getmethods__ = {}
    for _s in [MotionFilter]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, ScaleMotion, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        if self.__class__ == ScaleMotion:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_ScaleMotion(*args)
        try: self.this.append(this)
        except: self.this = this
    def clone(*args): return _Piavca.ScaleMotion_clone(*args)
    def getFloatValueAtTimeInternal(*args): return _Piavca.ScaleMotion_getFloatValueAtTimeInternal(*args)
    def getVecValueAtTimeInternal(*args): return _Piavca.ScaleMotion_getVecValueAtTimeInternal(*args)
    def getQuatValueAtTimeInternal(*args): return _Piavca.ScaleMotion_getQuatValueAtTimeInternal(*args)
    def setScaleFactor(*args): return _Piavca.ScaleMotion_setScaleFactor(*args)
    __swig_destroy__ = _Piavca.delete_ScaleMotion
    __del__ = lambda self : None;
    def __disown__(self):
        self.this.disown()
        _Piavca.disown_ScaleMotion(self)
        return weakref_proxy(self)
ScaleMotion_swigregister = _Piavca.ScaleMotion_swigregister
ScaleMotion_swigregister(ScaleMotion)

class ScaleMotionSpeed(MotionFilter):
    __swig_setmethods__ = {}
    for _s in [MotionFilter]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, ScaleMotionSpeed, name, value)
    __swig_getmethods__ = {}
    for _s in [MotionFilter]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, ScaleMotionSpeed, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        if self.__class__ == ScaleMotionSpeed:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_ScaleMotionSpeed(*args)
        try: self.this.append(this)
        except: self.this = this
    def clone(*args): return _Piavca.ScaleMotionSpeed_clone(*args)
    def getMotionLength(*args): return _Piavca.ScaleMotionSpeed_getMotionLength(*args)
    def getFloatValueAtTimeInternal(*args): return _Piavca.ScaleMotionSpeed_getFloatValueAtTimeInternal(*args)
    def getVecValueAtTimeInternal(*args): return _Piavca.ScaleMotionSpeed_getVecValueAtTimeInternal(*args)
    def getQuatValueAtTimeInternal(*args): return _Piavca.ScaleMotionSpeed_getQuatValueAtTimeInternal(*args)
    def setScaleFactor(*args): return _Piavca.ScaleMotionSpeed_setScaleFactor(*args)
    __swig_destroy__ = _Piavca.delete_ScaleMotionSpeed
    __del__ = lambda self : None;
    def __disown__(self):
        self.this.disown()
        _Piavca.disown_ScaleMotionSpeed(self)
        return weakref_proxy(self)
ScaleMotionSpeed_swigregister = _Piavca.ScaleMotionSpeed_swigregister
ScaleMotionSpeed_swigregister(ScaleMotionSpeed)

class ScaleMotionRoot(MotionFilter):
    __swig_setmethods__ = {}
    for _s in [MotionFilter]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, ScaleMotionRoot, name, value)
    __swig_getmethods__ = {}
    for _s in [MotionFilter]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, ScaleMotionRoot, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        if self.__class__ == ScaleMotionRoot:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_ScaleMotionRoot(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca.delete_ScaleMotionRoot
    __del__ = lambda self : None;
    def clone(*args): return _Piavca.ScaleMotionRoot_clone(*args)
    def getFloatValueAtTimeInternal(*args): return _Piavca.ScaleMotionRoot_getFloatValueAtTimeInternal(*args)
    def getVecValueAtTimeInternal(*args): return _Piavca.ScaleMotionRoot_getVecValueAtTimeInternal(*args)
    def getQuatValueAtTimeInternal(*args): return _Piavca.ScaleMotionRoot_getQuatValueAtTimeInternal(*args)
    def setScaleFactor(*args): return _Piavca.ScaleMotionRoot_setScaleFactor(*args)
    def __disown__(self):
        self.this.disown()
        _Piavca.disown_ScaleMotionRoot(self)
        return weakref_proxy(self)
ScaleMotionRoot_swigregister = _Piavca.ScaleMotionRoot_swigregister
ScaleMotionRoot_swigregister(ScaleMotionRoot)

class TimeOffset(MotionFilter):
    __swig_setmethods__ = {}
    for _s in [MotionFilter]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, TimeOffset, name, value)
    __swig_getmethods__ = {}
    for _s in [MotionFilter]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, TimeOffset, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        if self.__class__ == TimeOffset:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_TimeOffset(*args)
        try: self.this.append(this)
        except: self.this = this
    def clone(*args): return _Piavca.TimeOffset_clone(*args)
    def setStartTime(*args): return _Piavca.TimeOffset_setStartTime(*args)
    def getFloatValueAtTimeInternal(*args): return _Piavca.TimeOffset_getFloatValueAtTimeInternal(*args)
    def getVecValueAtTimeInternal(*args): return _Piavca.TimeOffset_getVecValueAtTimeInternal(*args)
    def getQuatValueAtTimeInternal(*args): return _Piavca.TimeOffset_getQuatValueAtTimeInternal(*args)
    def setOffset(*args): return _Piavca.TimeOffset_setOffset(*args)
    __swig_destroy__ = _Piavca.delete_TimeOffset
    __del__ = lambda self : None;
    def __disown__(self):
        self.this.disown()
        _Piavca.disown_TimeOffset(self)
        return weakref_proxy(self)
TimeOffset_swigregister = _Piavca.TimeOffset_swigregister
TimeOffset_swigregister(TimeOffset)

class TurnMotion(MotionFilter):
    __swig_setmethods__ = {}
    for _s in [MotionFilter]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, TurnMotion, name, value)
    __swig_getmethods__ = {}
    for _s in [MotionFilter]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, TurnMotion, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        if self.__class__ == TurnMotion:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_TurnMotion(*args)
        try: self.this.append(this)
        except: self.this = this
    def clone(*args): return _Piavca.TurnMotion_clone(*args)
    def getFloatValueAtTimeInternal(*args): return _Piavca.TurnMotion_getFloatValueAtTimeInternal(*args)
    def getVecValueAtTimeInternal(*args): return _Piavca.TurnMotion_getVecValueAtTimeInternal(*args)
    def getQuatValueAtTimeInternal(*args): return _Piavca.TurnMotion_getQuatValueAtTimeInternal(*args)
    def setRotation(*args): return _Piavca.TurnMotion_setRotation(*args)
    __swig_destroy__ = _Piavca.delete_TurnMotion
    __del__ = lambda self : None;
    def __disown__(self):
        self.this.disown()
        _Piavca.disown_TurnMotion(self)
        return weakref_proxy(self)
TurnMotion_swigregister = _Piavca.TurnMotion_swigregister
TurnMotion_swigregister(TurnMotion)

class SequentialBlend(TwoMotionCombiner):
    __swig_setmethods__ = {}
    for _s in [TwoMotionCombiner]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, SequentialBlend, name, value)
    __swig_getmethods__ = {}
    for _s in [TwoMotionCombiner]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, SequentialBlend, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        if self.__class__ == SequentialBlend:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_SequentialBlend(*args)
        try: self.this.append(this)
        except: self.this = this
    def clone(*args): return _Piavca.SequentialBlend_clone(*args)
    def setMaintainY(*args): return _Piavca.SequentialBlend_setMaintainY(*args)
    def setAccumulateRoot(*args): return _Piavca.SequentialBlend_setAccumulateRoot(*args)
    def setStartTime(*args): return _Piavca.SequentialBlend_setStartTime(*args)
    def getMotionLength(*args): return _Piavca.SequentialBlend_getMotionLength(*args)
    def getFloatValueAtTimeInternal(*args): return _Piavca.SequentialBlend_getFloatValueAtTimeInternal(*args)
    def getVecValueAtTimeInternal(*args): return _Piavca.SequentialBlend_getVecValueAtTimeInternal(*args)
    def getQuatValueAtTimeInternal(*args): return _Piavca.SequentialBlend_getQuatValueAtTimeInternal(*args)
    def setBlendStart(*args): return _Piavca.SequentialBlend_setBlendStart(*args)
    def setBlendInterval(*args): return _Piavca.SequentialBlend_setBlendInterval(*args)
    def getBlendStart(*args): return _Piavca.SequentialBlend_getBlendStart(*args)
    def getBlendInterval(*args): return _Piavca.SequentialBlend_getBlendInterval(*args)
    __swig_destroy__ = _Piavca.delete_SequentialBlend
    __del__ = lambda self : None;
    def __disown__(self):
        self.this.disown()
        _Piavca.disown_SequentialBlend(self)
        return weakref_proxy(self)
SequentialBlend_swigregister = _Piavca.SequentialBlend_swigregister
SequentialBlend_swigregister(SequentialBlend)

class SelfBlend(SequentialBlend):
    __swig_setmethods__ = {}
    for _s in [SequentialBlend]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, SelfBlend, name, value)
    __swig_getmethods__ = {}
    for _s in [SequentialBlend]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, SelfBlend, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        if self.__class__ == SelfBlend:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_SelfBlend(*args)
        try: self.this.append(this)
        except: self.this = this
    def clone(*args): return _Piavca.SelfBlend_clone(*args)
    def reset(*args): return _Piavca.SelfBlend_reset(*args)
    def reblend(*args): return _Piavca.SelfBlend_reblend(*args)
    def setMotion(*args): return _Piavca.SelfBlend_setMotion(*args)
    __swig_destroy__ = _Piavca.delete_SelfBlend
    __del__ = lambda self : None;
    def __disown__(self):
        self.this.disown()
        _Piavca.disown_SelfBlend(self)
        return weakref_proxy(self)
SelfBlend_swigregister = _Piavca.SelfBlend_swigregister
SelfBlend_swigregister(SelfBlend)

class LoopMotion(SelfBlend):
    __swig_setmethods__ = {}
    for _s in [SelfBlend]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, LoopMotion, name, value)
    __swig_getmethods__ = {}
    for _s in [SelfBlend]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, LoopMotion, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        if self.__class__ == LoopMotion:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_LoopMotion(*args)
        try: self.this.append(this)
        except: self.this = this
    def clone(*args): return _Piavca.LoopMotion_clone(*args)
    def getMotionLength(*args): return _Piavca.LoopMotion_getMotionLength(*args)
    def setEndTime(*args): return _Piavca.LoopMotion_setEndTime(*args)
    def getFloatValueAtTimeInternal(*args): return _Piavca.LoopMotion_getFloatValueAtTimeInternal(*args)
    def getVecValueAtTimeInternal(*args): return _Piavca.LoopMotion_getVecValueAtTimeInternal(*args)
    def getQuatValueAtTimeInternal(*args): return _Piavca.LoopMotion_getQuatValueAtTimeInternal(*args)
    __swig_destroy__ = _Piavca.delete_LoopMotion
    __del__ = lambda self : None;
    def __disown__(self):
        self.this.disown()
        _Piavca.disown_LoopMotion(self)
        return weakref_proxy(self)
LoopMotion_swigregister = _Piavca.LoopMotion_swigregister
LoopMotion_swigregister(LoopMotion)

class RandomTimingsLoop(LoopMotion):
    __swig_setmethods__ = {}
    for _s in [LoopMotion]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, RandomTimingsLoop, name, value)
    __swig_getmethods__ = {}
    for _s in [LoopMotion]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, RandomTimingsLoop, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        if self.__class__ == RandomTimingsLoop:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_RandomTimingsLoop(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca.delete_RandomTimingsLoop
    __del__ = lambda self : None;
    def clone(*args): return _Piavca.RandomTimingsLoop_clone(*args)
    def setTimingParams(*args): return _Piavca.RandomTimingsLoop_setTimingParams(*args)
    def reblend(*args): return _Piavca.RandomTimingsLoop_reblend(*args)
    def setMotion(*args): return _Piavca.RandomTimingsLoop_setMotion(*args)
    def __disown__(self):
        self.this.disown()
        _Piavca.disown_RandomTimingsLoop(self)
        return weakref_proxy(self)
RandomTimingsLoop_swigregister = _Piavca.RandomTimingsLoop_swigregister
RandomTimingsLoop_swigregister(RandomTimingsLoop)

class AvatarPostureBlend(SequentialBlend):
    __swig_setmethods__ = {}
    for _s in [SequentialBlend]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, AvatarPostureBlend, name, value)
    __swig_getmethods__ = {}
    for _s in [SequentialBlend]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, AvatarPostureBlend, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _Piavca.new_AvatarPostureBlend(*args)
        try: self.this.append(this)
        except: self.this = this
    def clone(*args): return _Piavca.AvatarPostureBlend_clone(*args)
    def load(*args): return _Piavca.AvatarPostureBlend_load(*args)
    def setMotion(*args): return _Piavca.AvatarPostureBlend_setMotion(*args)
    def reblend(*args): return _Piavca.AvatarPostureBlend_reblend(*args)
    __swig_destroy__ = _Piavca.delete_AvatarPostureBlend
    __del__ = lambda self : None;
AvatarPostureBlend_swigregister = _Piavca.AvatarPostureBlend_swigregister
AvatarPostureBlend_swigregister(AvatarPostureBlend)

class BlendBetween(TwoMotionCombiner):
    __swig_setmethods__ = {}
    for _s in [TwoMotionCombiner]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, BlendBetween, name, value)
    __swig_getmethods__ = {}
    for _s in [TwoMotionCombiner]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, BlendBetween, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        if self.__class__ == BlendBetween:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_BlendBetween(*args)
        try: self.this.append(this)
        except: self.this = this
    def clone(*args): return _Piavca.BlendBetween_clone(*args)
    def getFloatValueAtTimeInternal(*args): return _Piavca.BlendBetween_getFloatValueAtTimeInternal(*args)
    def getVecValueAtTimeInternal(*args): return _Piavca.BlendBetween_getVecValueAtTimeInternal(*args)
    def getQuatValueAtTimeInternal(*args): return _Piavca.BlendBetween_getQuatValueAtTimeInternal(*args)
    def setBlendFactor(*args): return _Piavca.BlendBetween_setBlendFactor(*args)
    __swig_destroy__ = _Piavca.delete_BlendBetween
    __del__ = lambda self : None;
    def __disown__(self):
        self.this.disown()
        _Piavca.disown_BlendBetween(self)
        return weakref_proxy(self)
BlendBetween_swigregister = _Piavca.BlendBetween_swigregister
BlendBetween_swigregister(BlendBetween)

class MotionAdder(TwoMotionCombiner):
    __swig_setmethods__ = {}
    for _s in [TwoMotionCombiner]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, MotionAdder, name, value)
    __swig_getmethods__ = {}
    for _s in [TwoMotionCombiner]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, MotionAdder, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        if self.__class__ == MotionAdder:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_MotionAdder(*args)
        try: self.this.append(this)
        except: self.this = this
    def clone(*args): return _Piavca.MotionAdder_clone(*args)
    def setScaleSecond(*args): return _Piavca.MotionAdder_setScaleSecond(*args)
    def getFloatValueAtTimeInternal(*args): return _Piavca.MotionAdder_getFloatValueAtTimeInternal(*args)
    def getVecValueAtTimeInternal(*args): return _Piavca.MotionAdder_getVecValueAtTimeInternal(*args)
    def getQuatValueAtTimeInternal(*args): return _Piavca.MotionAdder_getQuatValueAtTimeInternal(*args)
    __swig_destroy__ = _Piavca.delete_MotionAdder
    __del__ = lambda self : None;
    def __disown__(self):
        self.this.disown()
        _Piavca.disown_MotionAdder(self)
        return weakref_proxy(self)
MotionAdder_swigregister = _Piavca.MotionAdder_swigregister
MotionAdder_swigregister(MotionAdder)

class MotionMask(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, MotionMask, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, MotionMask, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _Piavca.new_MotionMask(*args)
        try: self.this.append(this)
        except: self.this = this
    def setMask(*args): return _Piavca.MotionMask_setMask(*args)
    def getMask(*args): return _Piavca.MotionMask_getMask(*args)
    __swig_destroy__ = _Piavca.delete_MotionMask
    __del__ = lambda self : None;
MotionMask_swigregister = _Piavca.MotionMask_swigregister
MotionMask_swigregister(MotionMask)

class MaskedMotion(TwoMotionCombiner):
    __swig_setmethods__ = {}
    for _s in [TwoMotionCombiner]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, MaskedMotion, name, value)
    __swig_getmethods__ = {}
    for _s in [TwoMotionCombiner]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, MaskedMotion, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        if self.__class__ == MaskedMotion:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_MaskedMotion(*args)
        try: self.this.append(this)
        except: self.this = this
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
    __swig_destroy__ = _Piavca.delete_MaskedMotion
    __del__ = lambda self : None;
    def __disown__(self):
        self.this.disown()
        _Piavca.disown_MaskedMotion(self)
        return weakref_proxy(self)
MaskedMotion_swigregister = _Piavca.MaskedMotion_swigregister
MaskedMotion_swigregister(MaskedMotion)

class MultiMotionLoop(RandomTimingsLoop):
    __swig_setmethods__ = {}
    for _s in [RandomTimingsLoop]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, MultiMotionLoop, name, value)
    __swig_getmethods__ = {}
    for _s in [RandomTimingsLoop]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, MultiMotionLoop, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _Piavca.new_MultiMotionLoop(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca.delete_MultiMotionLoop
    __del__ = lambda self : None;
    def clone(*args): return _Piavca.MultiMotionLoop_clone(*args)
    def printInfo(*args): return _Piavca.MultiMotionLoop_printInfo(*args)
    def addMotion(*args): return _Piavca.MultiMotionLoop_addMotion(*args)
    def findSub(*args): return _Piavca.MultiMotionLoop_findSub(*args)
    def findSubByType(*args): return _Piavca.MultiMotionLoop_findSubByType(*args)
    def load(*args): return _Piavca.MultiMotionLoop_load(*args)
    def unload(*args): return _Piavca.MultiMotionLoop_unload(*args)
    def loaded(*args): return _Piavca.MultiMotionLoop_loaded(*args)
MultiMotionLoop_swigregister = _Piavca.MultiMotionLoop_swigregister
MultiMotionLoop_swigregister(MultiMotionLoop)

class ChoiceLoopMotion(MultiMotionLoop):
    __swig_setmethods__ = {}
    for _s in [MultiMotionLoop]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, ChoiceLoopMotion, name, value)
    __swig_getmethods__ = {}
    for _s in [MultiMotionLoop]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, ChoiceLoopMotion, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        if self.__class__ == ChoiceLoopMotion:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_ChoiceLoopMotion(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca.delete_ChoiceLoopMotion
    __del__ = lambda self : None;
    def clone(*args): return _Piavca.ChoiceLoopMotion_clone(*args)
    def setCurrentChoice(*args): return _Piavca.ChoiceLoopMotion_setCurrentChoice(*args)
    def reblend(*args): return _Piavca.ChoiceLoopMotion_reblend(*args)
    def __disown__(self):
        self.this.disown()
        _Piavca.disown_ChoiceLoopMotion(self)
        return weakref_proxy(self)
ChoiceLoopMotion_swigregister = _Piavca.ChoiceLoopMotion_swigregister
ChoiceLoopMotion_swigregister(ChoiceLoopMotion)

class RandomLoopMotion(ChoiceLoopMotion):
    __swig_setmethods__ = {}
    for _s in [ChoiceLoopMotion]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, RandomLoopMotion, name, value)
    __swig_getmethods__ = {}
    for _s in [ChoiceLoopMotion]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, RandomLoopMotion, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        if self.__class__ == RandomLoopMotion:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_RandomLoopMotion(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca.delete_RandomLoopMotion
    __del__ = lambda self : None;
    def clone(*args): return _Piavca.RandomLoopMotion_clone(*args)
    __swig_getmethods__["convertTo"] = lambda x: _Piavca.RandomLoopMotion_convertTo
    if _newclass:convertTo = staticmethod(_Piavca.RandomLoopMotion_convertTo)
    def addMotion(*args): return _Piavca.RandomLoopMotion_addMotion(*args)
    def setProbability(*args): return _Piavca.RandomLoopMotion_setProbability(*args)
    def reblend(*args): return _Piavca.RandomLoopMotion_reblend(*args)
    def __disown__(self):
        self.this.disown()
        _Piavca.disown_RandomLoopMotion(self)
        return weakref_proxy(self)
RandomLoopMotion_swigregister = _Piavca.RandomLoopMotion_swigregister
RandomLoopMotion_swigregister(RandomLoopMotion)
RandomLoopMotion_convertTo = _Piavca.RandomLoopMotion_convertTo

class RandomBlendLoop(MultiMotionLoop):
    __swig_setmethods__ = {}
    for _s in [MultiMotionLoop]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, RandomBlendLoop, name, value)
    __swig_getmethods__ = {}
    for _s in [MultiMotionLoop]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, RandomBlendLoop, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        if self.__class__ == RandomBlendLoop:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_RandomBlendLoop(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca.delete_RandomBlendLoop
    __del__ = lambda self : None;
    def clone(*args): return _Piavca.RandomBlendLoop_clone(*args)
    def addMotion(*args): return _Piavca.RandomBlendLoop_addMotion(*args)
    def setAutoShift(*args): return _Piavca.RandomBlendLoop_setAutoShift(*args)
    def shift(*args): return _Piavca.RandomBlendLoop_shift(*args)
    def reblend(*args): return _Piavca.RandomBlendLoop_reblend(*args)
    def __disown__(self):
        self.this.disown()
        _Piavca.disown_RandomBlendLoop(self)
        return weakref_proxy(self)
RandomBlendLoop_swigregister = _Piavca.RandomBlendLoop_swigregister
RandomBlendLoop_swigregister(RandomBlendLoop)

class RandomAddLoop(MultiMotionLoop):
    __swig_setmethods__ = {}
    for _s in [MultiMotionLoop]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, RandomAddLoop, name, value)
    __swig_getmethods__ = {}
    for _s in [MultiMotionLoop]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, RandomAddLoop, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        if self.__class__ == RandomAddLoop:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_RandomAddLoop(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca.delete_RandomAddLoop
    __del__ = lambda self : None;
    def clone(*args): return _Piavca.RandomAddLoop_clone(*args)
    def setAutoShift(*args): return _Piavca.RandomAddLoop_setAutoShift(*args)
    def shift(*args): return _Piavca.RandomAddLoop_shift(*args)
    def reblend(*args): return _Piavca.RandomAddLoop_reblend(*args)
    def __disown__(self):
        self.this.disown()
        _Piavca.disown_RandomAddLoop(self)
        return weakref_proxy(self)
RandomAddLoop_swigregister = _Piavca.RandomAddLoop_swigregister
RandomAddLoop_swigregister(RandomAddLoop)

class ProxemicsLoop(MultiMotionLoop):
    __swig_setmethods__ = {}
    for _s in [MultiMotionLoop]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, ProxemicsLoop, name, value)
    __swig_getmethods__ = {}
    for _s in [MultiMotionLoop]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, ProxemicsLoop, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _Piavca.new_ProxemicsLoop(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca.delete_ProxemicsLoop
    __del__ = lambda self : None;
    def clone(*args): return _Piavca.ProxemicsLoop_clone(*args)
    def setDistance(*args): return _Piavca.ProxemicsLoop_setDistance(*args)
    def setThreshold(*args): return _Piavca.ProxemicsLoop_setThreshold(*args)
    def setAngleThreshold(*args): return _Piavca.ProxemicsLoop_setAngleThreshold(*args)
    def turnOff(*args): return _Piavca.ProxemicsLoop_turnOff(*args)
    def addAvatar(*args): return _Piavca.ProxemicsLoop_addAvatar(*args)
    def removeAvatar(*args): return _Piavca.ProxemicsLoop_removeAvatar(*args)
    def removeAllAvatars(*args): return _Piavca.ProxemicsLoop_removeAllAvatars(*args)
    def reblend(*args): return _Piavca.ProxemicsLoop_reblend(*args)
ProxemicsLoop_swigregister = _Piavca.ProxemicsLoop_swigregister
ProxemicsLoop_swigregister(ProxemicsLoop)

class LookAtMotion(Motion):
    __swig_setmethods__ = {}
    for _s in [Motion]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, LookAtMotion, name, value)
    __swig_getmethods__ = {}
    for _s in [Motion]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, LookAtMotion, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        if self.__class__ == LookAtMotion:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_LookAtMotion(*args)
        try: self.this.append(this)
        except: self.this = this
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
    __swig_destroy__ = _Piavca.delete_LookAtMotion
    __del__ = lambda self : None;
    def __disown__(self):
        self.this.disown()
        _Piavca.disown_LookAtMotion(self)
        return weakref_proxy(self)
LookAtMotion_swigregister = _Piavca.LookAtMotion_swigregister
LookAtMotion_swigregister(LookAtMotion)

class LookAtToFacial(MotionFilter):
    __swig_setmethods__ = {}
    for _s in [MotionFilter]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, LookAtToFacial, name, value)
    __swig_getmethods__ = {}
    for _s in [MotionFilter]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, LookAtToFacial, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _Piavca.new_LookAtToFacial(*args)
        try: self.this.append(this)
        except: self.this = this
    def clone(*args): return _Piavca.LookAtToFacial_clone(*args)
    def load(*args): return _Piavca.LookAtToFacial_load(*args)
    def isFacial(*args): return _Piavca.LookAtToFacial_isFacial(*args)
    def isNull(*args): return _Piavca.LookAtToFacial_isNull(*args)
    def getFloatValueAtTimeInternal(*args): return _Piavca.LookAtToFacial_getFloatValueAtTimeInternal(*args)
    def getVecValueAtTimeInternal(*args): return _Piavca.LookAtToFacial_getVecValueAtTimeInternal(*args)
    def getQuatValueAtTimeInternal(*args): return _Piavca.LookAtToFacial_getQuatValueAtTimeInternal(*args)
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
    if _newclass:avatar = property(_Piavca.AvatarTargetStruct_avatar_get, _Piavca.AvatarTargetStruct_avatar_set)
    __swig_setmethods__["joint"] = _Piavca.AvatarTargetStruct_joint_set
    __swig_getmethods__["joint"] = _Piavca.AvatarTargetStruct_joint_get
    if _newclass:joint = property(_Piavca.AvatarTargetStruct_joint_get, _Piavca.AvatarTargetStruct_joint_set)
    __swig_setmethods__["flags"] = _Piavca.AvatarTargetStruct_flags_set
    __swig_getmethods__["flags"] = _Piavca.AvatarTargetStruct_flags_get
    if _newclass:flags = property(_Piavca.AvatarTargetStruct_flags_get, _Piavca.AvatarTargetStruct_flags_set)
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
    if _newclass:object = property(_Piavca.ObjectTargetStruct_object_get, _Piavca.ObjectTargetStruct_object_set)
    __swig_setmethods__["flags"] = _Piavca.ObjectTargetStruct_flags_set
    __swig_getmethods__["flags"] = _Piavca.ObjectTargetStruct_flags_get
    if _newclass:flags = property(_Piavca.ObjectTargetStruct_flags_get, _Piavca.ObjectTargetStruct_flags_set)
    def __init__(self, *args): 
        this = _Piavca.new_ObjectTargetStruct(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca.delete_ObjectTargetStruct
    __del__ = lambda self : None;
ObjectTargetStruct_swigregister = _Piavca.ObjectTargetStruct_swigregister
ObjectTargetStruct_swigregister(ObjectTargetStruct)

class RandomGazeMotion(LoopMotion):
    __swig_setmethods__ = {}
    for _s in [LoopMotion]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, RandomGazeMotion, name, value)
    __swig_getmethods__ = {}
    for _s in [LoopMotion]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, RandomGazeMotion, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        if self.__class__ == RandomGazeMotion:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_RandomGazeMotion(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca.delete_RandomGazeMotion
    __del__ = lambda self : None;
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
    def __disown__(self):
        self.this.disown()
        _Piavca.disown_RandomGazeMotion(self)
        return weakref_proxy(self)
RandomGazeMotion_swigregister = _Piavca.RandomGazeMotion_swigregister
RandomGazeMotion_swigregister(RandomGazeMotion)

class ZeroMotion(Motion):
    __swig_setmethods__ = {}
    for _s in [Motion]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, ZeroMotion, name, value)
    __swig_getmethods__ = {}
    for _s in [Motion]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, ZeroMotion, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        if self.__class__ == ZeroMotion:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_ZeroMotion(*args)
        try: self.this.append(this)
        except: self.this = this
    def clone(*args): return _Piavca.ZeroMotion_clone(*args)
    def isFacial(*args): return _Piavca.ZeroMotion_isFacial(*args)
    def isRandomAccess(*args): return _Piavca.ZeroMotion_isRandomAccess(*args)
    def getMotionLength(*args): return _Piavca.ZeroMotion_getMotionLength(*args)
    def isNull(*args): return _Piavca.ZeroMotion_isNull(*args)
    def getTrackType(*args): return _Piavca.ZeroMotion_getTrackType(*args)
    def getFloatValueAtTimeInternal(*args): return _Piavca.ZeroMotion_getFloatValueAtTimeInternal(*args)
    def getVecValueAtTimeInternal(*args): return _Piavca.ZeroMotion_getVecValueAtTimeInternal(*args)
    def getQuatValueAtTimeInternal(*args): return _Piavca.ZeroMotion_getQuatValueAtTimeInternal(*args)
    __swig_destroy__ = _Piavca.delete_ZeroMotion
    __del__ = lambda self : None;
    def __disown__(self):
        self.this.disown()
        _Piavca.disown_ZeroMotion(self)
        return weakref_proxy(self)
ZeroMotion_swigregister = _Piavca.ZeroMotion_swigregister
ZeroMotion_swigregister(ZeroMotion)

class MotionSaver(MotionFilter):
    __swig_setmethods__ = {}
    for _s in [MotionFilter]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, MotionSaver, name, value)
    __swig_getmethods__ = {}
    for _s in [MotionFilter]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, MotionSaver, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        if self.__class__ == MotionSaver:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_MotionSaver(*args)
        try: self.this.append(this)
        except: self.this = this
    def clone(*args): return _Piavca.MotionSaver_clone(*args)
    def getFloatValueAtTimeInternal(*args): return _Piavca.MotionSaver_getFloatValueAtTimeInternal(*args)
    def getVecValueAtTimeInternal(*args): return _Piavca.MotionSaver_getVecValueAtTimeInternal(*args)
    def getQuatValueAtTimeInternal(*args): return _Piavca.MotionSaver_getQuatValueAtTimeInternal(*args)
    def collectFrames(*args): return _Piavca.MotionSaver_collectFrames(*args)
    def save(*args): return _Piavca.MotionSaver_save(*args)
    __swig_destroy__ = _Piavca.delete_MotionSaver
    __del__ = lambda self : None;
    def __disown__(self):
        self.this.disown()
        _Piavca.disown_MotionSaver(self)
        return weakref_proxy(self)
MotionSaver_swigregister = _Piavca.MotionSaver_swigregister
MotionSaver_swigregister(MotionSaver)

class MotionParser(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, MotionParser, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, MotionParser, name)
    def __init__(self): raise AttributeError, "No constructor defined"
    __repr__ = _swig_repr
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
    __swig_destroy__ = _Piavca.delete_MotionParser
    __del__ = lambda self : None;
MotionParser_swigregister = _Piavca.MotionParser_swigregister
MotionParser_swigregister(MotionParser)
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
    __repr__ = _swig_repr
    def __init__(self, *args): 
        if self.__class__ == SubMotion:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_SubMotion(*args)
        try: self.this.append(this)
        except: self.this = this
    def clone(*args): return _Piavca.SubMotion_clone(*args)
    def getMotionLength(*args): return _Piavca.SubMotion_getMotionLength(*args)
    def setStart(*args): return _Piavca.SubMotion_setStart(*args)
    def setEnd(*args): return _Piavca.SubMotion_setEnd(*args)
    def getFloatValueAtTimeInternal(*args): return _Piavca.SubMotion_getFloatValueAtTimeInternal(*args)
    def getVecValueAtTimeInternal(*args): return _Piavca.SubMotion_getVecValueAtTimeInternal(*args)
    def getQuatValueAtTimeInternal(*args): return _Piavca.SubMotion_getQuatValueAtTimeInternal(*args)
    __swig_destroy__ = _Piavca.delete_SubMotion
    __del__ = lambda self : None;
    def __disown__(self):
        self.this.disown()
        _Piavca.disown_SubMotion(self)
        return weakref_proxy(self)
SubMotion_swigregister = _Piavca.SubMotion_swigregister
SubMotion_swigregister(SubMotion)

class TimeRangeMotion(MotionFilter):
    __swig_setmethods__ = {}
    for _s in [MotionFilter]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, TimeRangeMotion, name, value)
    __swig_getmethods__ = {}
    for _s in [MotionFilter]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, TimeRangeMotion, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        if self.__class__ == TimeRangeMotion:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_TimeRangeMotion(*args)
        try: self.this.append(this)
        except: self.this = this
    def clone(*args): return _Piavca.TimeRangeMotion_clone(*args)
    def setStart(*args): return _Piavca.TimeRangeMotion_setStart(*args)
    def setEnd(*args): return _Piavca.TimeRangeMotion_setEnd(*args)
    def getFloatValueAtTimeInternal(*args): return _Piavca.TimeRangeMotion_getFloatValueAtTimeInternal(*args)
    def getVecValueAtTimeInternal(*args): return _Piavca.TimeRangeMotion_getVecValueAtTimeInternal(*args)
    def getQuatValueAtTimeInternal(*args): return _Piavca.TimeRangeMotion_getQuatValueAtTimeInternal(*args)
    __swig_destroy__ = _Piavca.delete_TimeRangeMotion
    __del__ = lambda self : None;
    def __disown__(self):
        self.this.disown()
        _Piavca.disown_TimeRangeMotion(self)
        return weakref_proxy(self)
TimeRangeMotion_swigregister = _Piavca.TimeRangeMotion_swigregister
TimeRangeMotion_swigregister(TimeRangeMotion)

class TimeWarp(MotionFilter):
    __swig_setmethods__ = {}
    for _s in [MotionFilter]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, TimeWarp, name, value)
    __swig_getmethods__ = {}
    for _s in [MotionFilter]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, TimeWarp, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        if self.__class__ == TimeWarp:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_TimeWarp(*args)
        try: self.this.append(this)
        except: self.this = this
    def clone(*args): return _Piavca.TimeWarp_clone(*args)
    def getMotionLength(*args): return _Piavca.TimeWarp_getMotionLength(*args)
    def getFloatValueAtTimeInternal(*args): return _Piavca.TimeWarp_getFloatValueAtTimeInternal(*args)
    def getVecValueAtTimeInternal(*args): return _Piavca.TimeWarp_getVecValueAtTimeInternal(*args)
    def getQuatValueAtTimeInternal(*args): return _Piavca.TimeWarp_getQuatValueAtTimeInternal(*args)
    def setWarp(*args): return _Piavca.TimeWarp_setWarp(*args)
    __swig_destroy__ = _Piavca.delete_TimeWarp
    __del__ = lambda self : None;
    def __disown__(self):
        self.this.disown()
        _Piavca.disown_TimeWarp(self)
        return weakref_proxy(self)
TimeWarp_swigregister = _Piavca.TimeWarp_swigregister
TimeWarp_swigregister(TimeWarp)

class DiadicGazeMotion(RandomGazeMotion):
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
        if self.__class__ == DiadicGazeMotion:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca.new_DiadicGazeMotion(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca.delete_DiadicGazeMotion
    __del__ = lambda self : None;
    def clone(*args): return _Piavca.DiadicGazeMotion_clone(*args)
    def setTalking(*args): return _Piavca.DiadicGazeMotion_setTalking(*args)
    def setTalkingLookAt(*args): return _Piavca.DiadicGazeMotion_setTalkingLookAt(*args)
    def setTalkingLookAway(*args): return _Piavca.DiadicGazeMotion_setTalkingLookAway(*args)
    def setListeningLookAt(*args): return _Piavca.DiadicGazeMotion_setListeningLookAt(*args)
    def setListeningLookAway(*args): return _Piavca.DiadicGazeMotion_setListeningLookAway(*args)
    def setNeitherLookAt(*args): return _Piavca.DiadicGazeMotion_setNeitherLookAt(*args)
    def setNeitherLookAway(*args): return _Piavca.DiadicGazeMotion_setNeitherLookAway(*args)
    def setGazeFollow(*args): return _Piavca.DiadicGazeMotion_setGazeFollow(*args)
    def setOther(*args): return _Piavca.DiadicGazeMotion_setOther(*args)
    def getOther(*args): return _Piavca.DiadicGazeMotion_getOther(*args)
    def addGazeFollowTarget(*args): return _Piavca.DiadicGazeMotion_addGazeFollowTarget(*args)
    def notifyChange(*args): return _Piavca.DiadicGazeMotion_notifyChange(*args)
    def lookAt(*args): return _Piavca.DiadicGazeMotion_lookAt(*args)
    def reblend(*args): return _Piavca.DiadicGazeMotion_reblend(*args)
    def __disown__(self):
        self.this.disown()
        _Piavca.disown_DiadicGazeMotion(self)
        return weakref_proxy(self)
DiadicGazeMotion_swigregister = _Piavca.DiadicGazeMotion_swigregister
DiadicGazeMotion_swigregister(DiadicGazeMotion)



