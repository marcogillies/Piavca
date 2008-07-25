# This file was created automatically by SWIG 1.3.30.
# Don't modify this file, modify the SWIG interface instead.
# This file is compatible with both classic and new-style classes.

import _Piavca_base
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


class PySwigIterator(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, PySwigIterator, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, PySwigIterator, name)
    def __init__(self): raise AttributeError, "No constructor defined"
    __repr__ = _swig_repr
    __swig_destroy__ = _Piavca_base.delete_PySwigIterator
    __del__ = lambda self : None;
    def value(*args): return _Piavca_base.PySwigIterator_value(*args)
    def incr(*args): return _Piavca_base.PySwigIterator_incr(*args)
    def decr(*args): return _Piavca_base.PySwigIterator_decr(*args)
    def distance(*args): return _Piavca_base.PySwigIterator_distance(*args)
    def equal(*args): return _Piavca_base.PySwigIterator_equal(*args)
    def copy(*args): return _Piavca_base.PySwigIterator_copy(*args)
    def next(*args): return _Piavca_base.PySwigIterator_next(*args)
    def previous(*args): return _Piavca_base.PySwigIterator_previous(*args)
    def advance(*args): return _Piavca_base.PySwigIterator_advance(*args)
    def __eq__(*args): return _Piavca_base.PySwigIterator___eq__(*args)
    def __ne__(*args): return _Piavca_base.PySwigIterator___ne__(*args)
    def __iadd__(*args): return _Piavca_base.PySwigIterator___iadd__(*args)
    def __isub__(*args): return _Piavca_base.PySwigIterator___isub__(*args)
    def __add__(*args): return _Piavca_base.PySwigIterator___add__(*args)
    def __sub__(*args): return _Piavca_base.PySwigIterator___sub__(*args)
    def __iter__(self): return self
PySwigIterator_swigregister = _Piavca_base.PySwigIterator_swigregister
PySwigIterator_swigregister(PySwigIterator)

class vectorS(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, vectorS, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, vectorS, name)
    __repr__ = _swig_repr
    def iterator(*args): return _Piavca_base.vectorS_iterator(*args)
    def __iter__(self): return self.iterator()
    def __nonzero__(*args): return _Piavca_base.vectorS___nonzero__(*args)
    def __len__(*args): return _Piavca_base.vectorS___len__(*args)
    def pop(*args): return _Piavca_base.vectorS_pop(*args)
    def __getslice__(*args): return _Piavca_base.vectorS___getslice__(*args)
    def __setslice__(*args): return _Piavca_base.vectorS___setslice__(*args)
    def __delslice__(*args): return _Piavca_base.vectorS___delslice__(*args)
    def __delitem__(*args): return _Piavca_base.vectorS___delitem__(*args)
    def __getitem__(*args): return _Piavca_base.vectorS___getitem__(*args)
    def __setitem__(*args): return _Piavca_base.vectorS___setitem__(*args)
    def append(*args): return _Piavca_base.vectorS_append(*args)
    def empty(*args): return _Piavca_base.vectorS_empty(*args)
    def size(*args): return _Piavca_base.vectorS_size(*args)
    def clear(*args): return _Piavca_base.vectorS_clear(*args)
    def swap(*args): return _Piavca_base.vectorS_swap(*args)
    def get_allocator(*args): return _Piavca_base.vectorS_get_allocator(*args)
    def begin(*args): return _Piavca_base.vectorS_begin(*args)
    def end(*args): return _Piavca_base.vectorS_end(*args)
    def rbegin(*args): return _Piavca_base.vectorS_rbegin(*args)
    def rend(*args): return _Piavca_base.vectorS_rend(*args)
    def pop_back(*args): return _Piavca_base.vectorS_pop_back(*args)
    def erase(*args): return _Piavca_base.vectorS_erase(*args)
    def __init__(self, *args): 
        this = _Piavca_base.new_vectorS(*args)
        try: self.this.append(this)
        except: self.this = this
    def push_back(*args): return _Piavca_base.vectorS_push_back(*args)
    def front(*args): return _Piavca_base.vectorS_front(*args)
    def back(*args): return _Piavca_base.vectorS_back(*args)
    def assign(*args): return _Piavca_base.vectorS_assign(*args)
    def resize(*args): return _Piavca_base.vectorS_resize(*args)
    def insert(*args): return _Piavca_base.vectorS_insert(*args)
    def reserve(*args): return _Piavca_base.vectorS_reserve(*args)
    def capacity(*args): return _Piavca_base.vectorS_capacity(*args)
    __swig_destroy__ = _Piavca_base.delete_vectorS
    __del__ = lambda self : None;
vectorS_swigregister = _Piavca_base.vectorS_swigregister
vectorS_swigregister(vectorS)

class vectorI(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, vectorI, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, vectorI, name)
    __repr__ = _swig_repr
    def iterator(*args): return _Piavca_base.vectorI_iterator(*args)
    def __iter__(self): return self.iterator()
    def __nonzero__(*args): return _Piavca_base.vectorI___nonzero__(*args)
    def __len__(*args): return _Piavca_base.vectorI___len__(*args)
    def pop(*args): return _Piavca_base.vectorI_pop(*args)
    def __getslice__(*args): return _Piavca_base.vectorI___getslice__(*args)
    def __setslice__(*args): return _Piavca_base.vectorI___setslice__(*args)
    def __delslice__(*args): return _Piavca_base.vectorI___delslice__(*args)
    def __delitem__(*args): return _Piavca_base.vectorI___delitem__(*args)
    def __getitem__(*args): return _Piavca_base.vectorI___getitem__(*args)
    def __setitem__(*args): return _Piavca_base.vectorI___setitem__(*args)
    def append(*args): return _Piavca_base.vectorI_append(*args)
    def empty(*args): return _Piavca_base.vectorI_empty(*args)
    def size(*args): return _Piavca_base.vectorI_size(*args)
    def clear(*args): return _Piavca_base.vectorI_clear(*args)
    def swap(*args): return _Piavca_base.vectorI_swap(*args)
    def get_allocator(*args): return _Piavca_base.vectorI_get_allocator(*args)
    def begin(*args): return _Piavca_base.vectorI_begin(*args)
    def end(*args): return _Piavca_base.vectorI_end(*args)
    def rbegin(*args): return _Piavca_base.vectorI_rbegin(*args)
    def rend(*args): return _Piavca_base.vectorI_rend(*args)
    def pop_back(*args): return _Piavca_base.vectorI_pop_back(*args)
    def erase(*args): return _Piavca_base.vectorI_erase(*args)
    def __init__(self, *args): 
        this = _Piavca_base.new_vectorI(*args)
        try: self.this.append(this)
        except: self.this = this
    def push_back(*args): return _Piavca_base.vectorI_push_back(*args)
    def front(*args): return _Piavca_base.vectorI_front(*args)
    def back(*args): return _Piavca_base.vectorI_back(*args)
    def assign(*args): return _Piavca_base.vectorI_assign(*args)
    def resize(*args): return _Piavca_base.vectorI_resize(*args)
    def insert(*args): return _Piavca_base.vectorI_insert(*args)
    def reserve(*args): return _Piavca_base.vectorI_reserve(*args)
    def capacity(*args): return _Piavca_base.vectorI_capacity(*args)
    __swig_destroy__ = _Piavca_base.delete_vectorI
    __del__ = lambda self : None;
vectorI_swigregister = _Piavca_base.vectorI_swigregister
vectorI_swigregister(vectorI)

GetAvatarPointer = _Piavca_base.GetAvatarPointer
GetPiavcaCorePointer = _Piavca_base.GetPiavcaCorePointer
class Vec(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Vec, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Vec, name)
    def __init__(self, *args): 
        this = _Piavca_base.new_Vec(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca_base.delete_Vec
    __del__ = lambda self : None;
    def X(*args): return _Piavca_base.Vec_X(*args)
    def Y(*args): return _Piavca_base.Vec_Y(*args)
    def Z(*args): return _Piavca_base.Vec_Z(*args)
    __swig_getmethods__["XAxis"] = lambda x: _Piavca_base.Vec_XAxis
    if _newclass:XAxis = staticmethod(_Piavca_base.Vec_XAxis)
    __swig_getmethods__["YAxis"] = lambda x: _Piavca_base.Vec_YAxis
    if _newclass:YAxis = staticmethod(_Piavca_base.Vec_YAxis)
    __swig_getmethods__["ZAxis"] = lambda x: _Piavca_base.Vec_ZAxis
    if _newclass:ZAxis = staticmethod(_Piavca_base.Vec_ZAxis)
    def mag(*args): return _Piavca_base.Vec_mag(*args)
    def __add__(*args): return _Piavca_base.Vec___add__(*args)
    def __iadd__(*args): return _Piavca_base.Vec___iadd__(*args)
    def __sub__(*args): return _Piavca_base.Vec___sub__(*args)
    def __isub__(*args): return _Piavca_base.Vec___isub__(*args)
    def __neg__(*args): return _Piavca_base.Vec___neg__(*args)
    def __mul__(*args): return _Piavca_base.Vec___mul__(*args)
    def __imul__(*args): return _Piavca_base.Vec___imul__(*args)
    def __div__(*args): return _Piavca_base.Vec___div__(*args)
    def __idiv__(*args): return _Piavca_base.Vec___idiv__(*args)
    def __eq__(*args): return _Piavca_base.Vec___eq__(*args)
    def __ne__(*args): return _Piavca_base.Vec___ne__(*args)
    def inverse(*args): return _Piavca_base.Vec_inverse(*args)
    def invert(*args): return _Piavca_base.Vec_invert(*args)
    def dot(*args): return _Piavca_base.Vec_dot(*args)
    def cross(*args): return _Piavca_base.Vec_cross(*args)
    def crossinplace(*args): return _Piavca_base.Vec_crossinplace(*args)
    def normalized(*args): return _Piavca_base.Vec_normalized(*args)
    def normalize(*args): return _Piavca_base.Vec_normalize(*args)
    def __getitem__(*args): return _Piavca_base.Vec___getitem__(*args)
    def __setitem__(*args): return _Piavca_base.Vec___setitem__(*args)
    def __repr__(*args): return _Piavca_base.Vec___repr__(*args)
Vec_swigregister = _Piavca_base.Vec_swigregister
Vec_swigregister(Vec)
Vec_XAxis = _Piavca_base.Vec_XAxis
Vec_YAxis = _Piavca_base.Vec_YAxis
Vec_ZAxis = _Piavca_base.Vec_ZAxis

class Quat(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Quat, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Quat, name)
    def __init__(self, *args): 
        this = _Piavca_base.new_Quat(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca_base.delete_Quat
    __del__ = lambda self : None;
    def S(*args): return _Piavca_base.Quat_S(*args)
    def I(*args): return _Piavca_base.Quat_I(*args)
    def J(*args): return _Piavca_base.Quat_J(*args)
    def K(*args): return _Piavca_base.Quat_K(*args)
    def setAngleAxis(*args): return _Piavca_base.Quat_setAngleAxis(*args)
    def getAngleAxis(*args): return _Piavca_base.Quat_getAngleAxis(*args)
    def getAngle(*args): return _Piavca_base.Quat_getAngle(*args)
    def getAxis(*args): return _Piavca_base.Quat_getAxis(*args)
    def getEulerAngles(*args): return _Piavca_base.Quat_getEulerAngles(*args)
    def Xangle(*args): return _Piavca_base.Quat_Xangle(*args)
    def Yangle(*args): return _Piavca_base.Quat_Yangle(*args)
    def Zangle(*args): return _Piavca_base.Quat_Zangle(*args)
    def getAngleAboutAxis(*args): return _Piavca_base.Quat_getAngleAboutAxis(*args)
    def projectToAxis(*args): return _Piavca_base.Quat_projectToAxis(*args)
    def pointAt(*args): return _Piavca_base.Quat_pointAt(*args)
    def __mul__(*args): return _Piavca_base.Quat___mul__(*args)
    def __imul__(*args): return _Piavca_base.Quat___imul__(*args)
    def __div__(*args): return _Piavca_base.Quat___div__(*args)
    def __idiv__(*args): return _Piavca_base.Quat___idiv__(*args)
    def __eq__(*args): return _Piavca_base.Quat___eq__(*args)
    def __ne__(*args): return _Piavca_base.Quat___ne__(*args)
    def Scale(*args): return _Piavca_base.Quat_Scale(*args)
    def inverse(*args): return _Piavca_base.Quat_inverse(*args)
    def invert(*args): return _Piavca_base.Quat_invert(*args)
    def normalise(*args): return _Piavca_base.Quat_normalise(*args)
    def transform(*args): return _Piavca_base.Quat_transform(*args)
    def transformInPlace(*args): return _Piavca_base.Quat_transformInPlace(*args)
    __swig_getmethods__["spherical_distance"] = lambda x: _Piavca_base.Quat_spherical_distance
    if _newclass:spherical_distance = staticmethod(_Piavca_base.Quat_spherical_distance)
    def logMap(*args): return _Piavca_base.Quat_logMap(*args)
    __swig_getmethods__["expMap"] = lambda x: _Piavca_base.Quat_expMap
    if _newclass:expMap = staticmethod(_Piavca_base.Quat_expMap)
    def __getitem__(*args): return _Piavca_base.Quat___getitem__(*args)
    def __setitem__(*args): return _Piavca_base.Quat___setitem__(*args)
    def __repr__(*args): return _Piavca_base.Quat___repr__(*args)
Quat_swigregister = _Piavca_base.Quat_swigregister
Quat_swigregister(Quat)
Quat_spherical_distance = _Piavca_base.Quat_spherical_distance
Quat_expMap = _Piavca_base.Quat_expMap

slerp = _Piavca_base.slerp
class Bound(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Bound, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Bound, name)
    __repr__ = _swig_repr
    __swig_setmethods__["min"] = _Piavca_base.Bound_min_set
    __swig_getmethods__["min"] = _Piavca_base.Bound_min_get
    if _newclass:min = _swig_property(_Piavca_base.Bound_min_get, _Piavca_base.Bound_min_set)
    __swig_setmethods__["max"] = _Piavca_base.Bound_max_set
    __swig_getmethods__["max"] = _Piavca_base.Bound_max_get
    if _newclass:max = _swig_property(_Piavca_base.Bound_max_get, _Piavca_base.Bound_max_set)
    def __init__(self, *args): 
        this = _Piavca_base.new_Bound(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca_base.delete_Bound
    __del__ = lambda self : None;
    def __add__(*args): return _Piavca_base.Bound___add__(*args)
    def __iadd__(*args): return _Piavca_base.Bound___iadd__(*args)
    def __eq__(*args): return _Piavca_base.Bound___eq__(*args)
    def __ne__(*args): return _Piavca_base.Bound___ne__(*args)
Bound_swigregister = _Piavca_base.Bound_swigregister
Bound_swigregister(Bound)

StringToWString = _Piavca_base.StringToWString
WStringToString = _Piavca_base.WStringToString
LOCAL_COORD = _Piavca_base.LOCAL_COORD
JOINTLOCAL_COORD = _Piavca_base.JOINTLOCAL_COORD
BASE_COORD = _Piavca_base.BASE_COORD
INCLUDINGBASE_COORD = _Piavca_base.INCLUDINGBASE_COORD
WORLD_COORD = _Piavca_base.WORLD_COORD
root_position_id = _Piavca_base.root_position_id
root_orientation_id = _Piavca_base.root_orientation_id
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
        this = _Piavca_base.new_TimeCallback(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca_base.delete_TimeCallback
    __del__ = lambda self : None;
    def getName(*args):
        """
        tstring Piavca::TimeCallback::getName()
                 
                
                 
                
        """
        return _Piavca_base.TimeCallback_getName(*args)

    def init(*args):
        """
        virtual void Piavca::TimeCallback::init(Core *core)=0
                 
        This is a setup method for the callback.         
                 
        It's called when the callback is registered         
        """
        return _Piavca_base.TimeCallback_init(*args)

    def timeStep(*args):
        """
        virtual void Piavca::TimeCallback::timeStep(Core *core, float time)=0
                 
        implement this to make the callback do things         
                 
        It's called every frame with by the API         
        """
        return _Piavca_base.TimeCallback_timeStep(*args)

    def __disown__(self):
        self.this.disown()
        _Piavca_base.disown_TimeCallback(self)
        return weakref_proxy(self)
TimeCallback_swigregister = _Piavca_base.TimeCallback_swigregister
TimeCallback_swigregister(TimeCallback)
checkNaN = _Piavca_base.checkNaN

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
        this = _Piavca_base.new_AvatarTimeCallback(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca_base.delete_AvatarTimeCallback
    __del__ = lambda self : None;
    def getName(*args):
        """
        tstring Piavca::AvatarTimeCallback::getName()
                 
                
                 
                
        """
        return _Piavca_base.AvatarTimeCallback_getName(*args)

    def init(*args):
        """
        virtual void Piavca::AvatarTimeCallback::init(Avatar *avatar)=0
                 
        This is a setup method for the callback.         
                 
        It's called when the callback is registered         
        """
        return _Piavca_base.AvatarTimeCallback_init(*args)

    def timeStep(*args):
        """
        virtual void Piavca::AvatarTimeCallback::timeStep(Avatar *avatar, float time)=0
                 
        implement this to make the callback do things         
                 
        It's called every frame with by the API which passes in the avatar to which the callback is attatched         
        """
        return _Piavca_base.AvatarTimeCallback_timeStep(*args)

    def __disown__(self):
        self.this.disown()
        _Piavca_base.disown_AvatarTimeCallback(self)
        return weakref_proxy(self)
AvatarTimeCallback_swigregister = _Piavca_base.AvatarTimeCallback_swigregister
AvatarTimeCallback_swigregister(AvatarTimeCallback)

NULL_TYPE = _Piavca_base.NULL_TYPE
FLOAT_TYPE = _Piavca_base.FLOAT_TYPE
VEC_TYPE = _Piavca_base.VEC_TYPE
QUAT_TYPE = _Piavca_base.QUAT_TYPE
TRANS_NONE = _Piavca_base.TRANS_NONE
TRANS_SWAP_XZ = _Piavca_base.TRANS_SWAP_XZ
TRANS_SWAP_XY = _Piavca_base.TRANS_SWAP_XY
TRANS_SWAP_YZ = _Piavca_base.TRANS_SWAP_YZ
TRANS_CYCLE_YZX = _Piavca_base.TRANS_CYCLE_YZX
TRANS_CYCLE_ZXY = _Piavca_base.TRANS_CYCLE_ZXY
TRANS_NEG_X = _Piavca_base.TRANS_NEG_X
TRANS_NEG_Y = _Piavca_base.TRANS_NEG_Y
TRANS_NEG_Z = _Piavca_base.TRANS_NEG_Z
TRANS_ARM_UP = _Piavca_base.TRANS_ARM_UP
TRANS_ARM_DOWN = _Piavca_base.TRANS_ARM_DOWN
TRANS_REVERSE_ORDER = _Piavca_base.TRANS_REVERSE_ORDER
TRANS_SKIP_FIRST_FRAME = _Piavca_base.TRANS_SKIP_FIRST_FRAME
TRANS_NO_ROOT_POS_CORRECTION = _Piavca_base.TRANS_NO_ROOT_POS_CORRECTION
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
        this = _Piavca_base.new_Motion(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca_base.delete_Motion
    __del__ = lambda self : None;
    def clone(*args):
        """
        virtual Motion* Piavca::Motion::clone()=0
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca_base.Motion_clone(*args)

    def getClassName(*args): return _Piavca_base.Motion_getClassName(*args)
    __swig_getmethods__["castToThisType"] = lambda x: _Piavca_base.Motion_castToThisType
    if _newclass:castToThisType = staticmethod(_Piavca_base.Motion_castToThisType)
    def create(*args): return _Piavca_base.Motion_create(*args)
    def printInfo(*args):
        """
        void Motion::printInfo()
                 
        prints out info about the motion heirarchy         
                 
                
        """
        return _Piavca_base.Motion_printInfo(*args)

    def getId(*args): return _Piavca_base.Motion_getId(*args)
    def __eq__(*args): return _Piavca_base.Motion___eq__(*args)
    def __ne__(*args): return _Piavca_base.Motion___ne__(*args)
    def load(*args):
        """
        virtual void Piavca::Motion::load(Avatar *av)
                 
        called when the motion is loaded into an avatar         
                 
                
        """
        return _Piavca_base.Motion_load(*args)

    def unload(*args):
        """
        virtual void Piavca::Motion::unload()
                 
        called when the motion is unloaded from an avatar         
                 
                
        """
        return _Piavca_base.Motion_unload(*args)

    def loaded(*args):
        """
        virtual bool Piavca::Motion::loaded()
                 
        checks if the motion has been loaded into an avatar         
                 
                
        """
        return _Piavca_base.Motion_loaded(*args)

    def getAvatar(*args): return _Piavca_base.Motion_getAvatar(*args)
    def setStartTime(*args):
        """
        virtual void Piavca::Motion::setStartTime(float t)
                 
        sets the start time of the motion. Called when its loaded into an avatar.         
                 
                
        """
        return _Piavca_base.Motion_setStartTime(*args)

    def getStartTime(*args):
        """
        float Piavca::Motion::getStartTime()
                 
        return the start time of the motion         
                 
                
        """
        return _Piavca_base.Motion_getStartTime(*args)

    def getEndTime(*args):
        """
        float Piavca::Motion::getEndTime()
                 
        returns the end time of the motion         
                 
                
        """
        return _Piavca_base.Motion_getEndTime(*args)

    def reset(*args):
        """
        virtual void Piavca::Motion::reset()
                 
        does any resetting needed         
                 
                
        """
        return _Piavca_base.Motion_reset(*args)

    def event(*args): return _Piavca_base.Motion_event(*args)
    def getEventNames(*args): return _Piavca_base.Motion_getEventNames(*args)
    def cleanRecursionState(*args): return _Piavca_base.Motion_cleanRecursionState(*args)
    def wasVisited(*args): return _Piavca_base.Motion_wasVisited(*args)
    def sendEvent(*args): return _Piavca_base.Motion_sendEvent(*args)
    def Reference(*args):
        """
        void Piavca::Motion::Reference()
                 
        registers an owner for a motion, the motion will not be deleted until disposed is called.         
                 
        Internally this increments the reference count.         
        """
        return _Piavca_base.Motion_Reference(*args)

    def Dispose(*args):
        """
        void Motion::Dispose()
                 
        decrements the references count and deletes the motion if it reaches zero         
                 
                
        """
        return _Piavca_base.Motion_Dispose(*args)

    def makeTemp(*args):
        """
        void Piavca::Motion::makeTemp()
                 
        makes a motion temporary so that it is removed when all avatars have finished with it         
                 
                
        """
        return _Piavca_base.Motion_makeTemp(*args)

    def setName(*args):
        """
        void Piavca::Motion::setName(tstring nm)
                 
        gives a name to the motion         
                 
                
        """
        return _Piavca_base.Motion_setName(*args)

    def getName(*args):
        """
        tstring Piavca::Motion::getName()
                 
        returns the name of the motion         
                 
                
        """
        return _Piavca_base.Motion_getName(*args)

    def findSub(*args):
        """
        virtual Motion* Piavca::Motion::findSub(tstring nm)
                 
        finds the first submotion with a given name         
                 
                
        """
        return _Piavca_base.Motion_findSub(*args)

    def findSubByType(*args):
        """
        virtual Motion* Piavca::Motion::findSubByType(const type_info &ty)
                 
        finds the first submotion with a given type         
                 
                
        """
        return _Piavca_base.Motion_findSubByType(*args)

    def getMotionLength(*args):
        """
        virtual float Piavca::Motion::getMotionLength() const =0
                 
        gets the time of the end of the motion         
                 
        Though time is represented in floating point, keyframes can only be set as integers to avoid problems with rounding errors. The granularity is the conversion factor between the two.         
        """
        return _Piavca_base.Motion_getMotionLength(*args)

    def isFacial(*args):
        """
        virtual bool Piavca::Motion::isFacial()
                 
        whether it is a face or body motion         
                 
                
        """
        return _Piavca_base.Motion_isFacial(*args)

    def isRandomAccess(*args):
        """
        virtual bool Piavca::Motion::isRandomAccess()
                 
        whether you can access a motions value at frames other than the current one         
                 
                
        """
        return _Piavca_base.Motion_isRandomAccess(*args)

    def begin(*args):
        """
        int Piavca::Motion::begin() const 
                 
        the ID of the first track that is present in the motion (the ordering is arbitrary)         
                 
                
        """
        return _Piavca_base.Motion_begin(*args)

    def end(*args):
        """
        int Motion::end() const 
                 
        the last track + 1         
                 
                
        """
        return _Piavca_base.Motion_end(*args)

    def next(*args):
        """
        int Motion::next(int &trackId) const 
                 
        given a track ID get the next valid ID         
                 
                
        """
        return _Piavca_base.Motion_next(*args)

    def isNull(*args):
        """
        virtual bool Piavca::Motion::isNull(int trackId) const =0
                 
        given a track ID tests whether it actually points to anything or if its null         
                 
                
        """
        return _Piavca_base.Motion_isNull(*args)

    def getTrackType(*args):
        """
        virtual trackType Piavca::Motion::getTrackType(int trackId) const =0
                 
        get the type of the track corresponding to an ID         
                 
                
        """
        return _Piavca_base.Motion_getTrackType(*args)

    def pause(*args):
        """
        void Motion::pause()
                 
        pause the motion so that it can be restarted from the current point         
                 
                
        """
        return _Piavca_base.Motion_pause(*args)

    def unpause(*args):
        """
        void Motion::unpause()
                 
                
                 
                
        """
        return _Piavca_base.Motion_unpause(*args)

    def preFrame(*args): return _Piavca_base.Motion_preFrame(*args)
    def getFloatValueAtTime(*args):
        """
        float Piavca::Motion::getFloatValueAtTime(int trackId, float time)
                 
        get the value of a track at a given time (only works for floats)         
                 
                
        """
        return _Piavca_base.Motion_getFloatValueAtTime(*args)

    def getVecValueAtTime(*args):
        """
        Vec Piavca::Motion::getVecValueAtTime(int trackId, float time)
                 
        get the value of a track at a given time (only works for Vecs)         
                 
                
        """
        return _Piavca_base.Motion_getVecValueAtTime(*args)

    def getQuatValueAtTime(*args):
        """
        Quat Piavca::Motion::getQuatValueAtTime(int trackId, float time)
                 
        get the value of a track at a given time (only works for Quats)         
                 
                
        """
        return _Piavca_base.Motion_getQuatValueAtTime(*args)

    def getFloatValueAtTimeInternal(*args):
        """
        virtual float Piavca::Motion::getFloatValueAtTimeInternal(int trackId, float time)=0
                 
        internal version of getFloatValueAtTime, to be overridden         
                 
                
        """
        return _Piavca_base.Motion_getFloatValueAtTimeInternal(*args)

    def getVecValueAtTimeInternal(*args):
        """
        virtual Vec Piavca::Motion::getVecValueAtTimeInternal(int trackId, float time)=0
                 
        internal version of getVecValueAtTime, to be overridden         
                 
                
        """
        return _Piavca_base.Motion_getVecValueAtTimeInternal(*args)

    def getQuatValueAtTimeInternal(*args):
        """
        virtual Quat Piavca::Motion::getQuatValueAtTimeInternal(int trackId, float time)=0
                 
        internal version of getQuatValueAtTime, to be overridden         
                 
                
        """
        return _Piavca_base.Motion_getQuatValueAtTimeInternal(*args)

    def __disown__(self):
        self.this.disown()
        _Piavca_base.disown_Motion(self)
        return weakref_proxy(self)
Motion_swigregister = _Piavca_base.Motion_swigregister
Motion_swigregister(Motion)
Motion_castToThisType = _Piavca_base.Motion_castToThisType

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
    __swig_setmethods__["dir"] = _Piavca_base.Core_dir_set
    __swig_getmethods__["dir"] = _Piavca_base.Core_dir_get
    if _newclass:dir = _swig_property(_Piavca_base.Core_dir_get, _Piavca_base.Core_dir_set)
    __swig_destroy__ = _Piavca_base.delete_Core
    __del__ = lambda self : None;
    def reset(*args):
        """
        void Core::reset()
                 
                
                 
                
        """
        return _Piavca_base.Core_reset(*args)

    __swig_getmethods__["init"] = lambda x: _Piavca_base.Core_init
    if _newclass:init = staticmethod(_Piavca_base.Core_init)
    __swig_getmethods__["setCore"] = lambda x: _Piavca_base.Core_setCore
    if _newclass:setCore = staticmethod(_Piavca_base.Core_setCore)
    def getCore(*args):
        """
        static Core* Piavca::Core::getCore()
                 
        a static function to get the core instances (there is only one)         
                 
                
        """
        return _Piavca_base.Core_getCore(*args)

    if _newclass:getCore = staticmethod(getCore)
    __swig_getmethods__["getCore"] = lambda x: getCore
    __swig_getmethods__["getCorePointerAsLong"] = lambda x: _Piavca_base.Core_getCorePointerAsLong
    if _newclass:getCorePointerAsLong = staticmethod(_Piavca_base.Core_getCorePointerAsLong)
    def registerCallback(*args):
        """
        void Core::registerCallback(TimeCallback *cb)
                 
        registers a callback to be called every frame         
                 
                
        """
        return _Piavca_base.Core_registerCallback(*args)

    def timeStep(*args):
        """
        void Core::timeStep(float time)
                 
                
                 
        Performs all per frame actions Can be run in parallel with the renderer.         
        """
        return _Piavca_base.Core_timeStep(*args)

    def prerender(*args):
        """
        void Core::prerender()
                 
        called before rendering (this cannot be called in parallel with the render)         
                 
                
        """
        return _Piavca_base.Core_prerender(*args)

    def render(*args):
        """
        void Core::render()
                 
        On certain platforms this needs to be called to render the avatars.         
                 
                
        """
        return _Piavca_base.Core_render(*args)

    def setHardware(*args): return _Piavca_base.Core_setHardware(*args)
    def getHardware(*args): return _Piavca_base.Core_getHardware(*args)
    def getJointId(*args):
        """
        int Core::getJointId(tstring name)
                 
                
                 
        methods dealing with joint ids get an id corresponding to a joint name         
        """
        return _Piavca_base.Core_getJointId(*args)

    def getMaxJointId(*args):
        """
        int Piavca::Core::getMaxJointId()
                 
        gets the maximum joint id         
                 
                
        """
        return _Piavca_base.Core_getMaxJointId(*args)

    def addJointNameSet(*args):
        """
        void Core::addJointNameSet(StringVector names)
                 
        Adds in a set of joints all of which should have the same id.         
                 
        i.e. all the names correspond to the same joint e.g. (left_foot, LFoot, LeftFoot, PiedGauche)         
        """
        return _Piavca_base.Core_addJointNameSet(*args)

    def getJointName(*args):
        """
        tstring Core::getJointName(int jointId)
                 
        returns a name corresponding to a track id (out of many possible)         
                 
                
        """
        return _Piavca_base.Core_getJointName(*args)

    def getJointNameAssociations(*args):
        """
        std::vector< std::pair< tstring, int > > Core::getJointNameAssociations()
                 
        get all the joint name associations         
                 
                
        """
        return _Piavca_base.Core_getJointNameAssociations(*args)

    def getExpressionId(*args):
        """
        int Core::getExpressionId(tstring name)
                 
                
                 
        methods dealing with expression ids get an id corresponding to an expression name         
        """
        return _Piavca_base.Core_getExpressionId(*args)

    def getMaxExpressionId(*args):
        """
        int Piavca::Core::getMaxExpressionId()
                 
        gets the maximum joint id         
                 
                
        """
        return _Piavca_base.Core_getMaxExpressionId(*args)

    def addExpressionNameSet(*args):
        """
        void Core::addExpressionNameSet(StringVector names)
                 
        Adds in a set of joints all of which should have the same id.         
                 
        i.e. all the names correspond to the same joint e.g. (left_foot, LFoot, LeftFoot, PiedGauche)         
        """
        return _Piavca_base.Core_addExpressionNameSet(*args)

    def getExpressionName(*args):
        """
        tstring Core::getExpressionName(int expressionId)
                 
        returns a name corresponding to a track id (out of many possible)         
                 
                
        """
        return _Piavca_base.Core_getExpressionName(*args)

    def getExpressionNameAssociations(*args):
        """
        std::vector< std::pair< tstring, int > > Core::getExpressionNameAssociations()
                 
        get all the expression name associations         
                 
                
        """
        return _Piavca_base.Core_getExpressionNameAssociations(*args)

    def getTrackId(*args): return _Piavca_base.Core_getTrackId(*args)
    def getMaxTrackId(*args): return _Piavca_base.Core_getMaxTrackId(*args)
    def getMinTrackId(*args): return _Piavca_base.Core_getMinTrackId(*args)
    def getTrackName(*args): return _Piavca_base.Core_getTrackName(*args)
    def getTrackNameAssociations(*args): return _Piavca_base.Core_getTrackNameAssociations(*args)
    def loadMotion(*args):
        """
        void Core::loadMotion(tstring motionName, Motion *mot, bool temp=false, Motion *basePosture=NULL)
                 
        adds a motion to its list of motions         
                 
                
        """
        return _Piavca_base.Core_loadMotion(*args)

    def renameMotion(*args):
        """
        void Core::renameMotion(tstring oldName, tstring newName)
                 
        changes the name of a motion         
                 
                
        """
        return _Piavca_base.Core_renameMotion(*args)

    def unloadMotion(*args):
        """
        void Core::unloadMotion(tstring name)
                 
        removes the motion from the core and deletes it (NB difference to disposeMotion)         
                 
                
        """
        return _Piavca_base.Core_unloadMotion(*args)

    def getMotionNames(*args):
        """
        PIAVCA_EXPORT std::vector< std::string > Core::getMotionNames(int number=0)
                 
        get motion names         
                 
                
        """
        return _Piavca_base.Core_getMotionNames(*args)

    def getNumberOfMotions(*args):
        """
        int Piavca::Core::getNumberOfMotions()
                 
        get number of motions         
                 
                
        """
        return _Piavca_base.Core_getNumberOfMotions(*args)

    def getAllmotions(*args):
        """
        PIAVCA_EXPORT std::list< tstring > Core::getAllmotions()
                 
        get all motion names         
                 
                
        """
        return _Piavca_base.Core_getAllmotions(*args)

    def getMotion(*args):
        """
        Motion* Piavca::Core::getMotion(int i)
                 
        get a motion by its (arbitrary) index         
                 
                
        """
        return _Piavca_base.Core_getMotion(*args)

    def loadAvatar(*args): return _Piavca_base.Core_loadAvatar(*args)
    def getAvatarNames(*args):
        """
        std::vector< tstring > Core::getAvatarNames()
                 
                
                 
                
        """
        return _Piavca_base.Core_getAvatarNames(*args)

    def numAvatars(*args):
        """
        int Piavca::Core::numAvatars()
                 
        get the number of avatars         
                 
                
        """
        return _Piavca_base.Core_numAvatars(*args)

    def getAvatar(*args):
        """
        Avatar * Core::getAvatar(int i)
                 
        get the ith avatar in the list (used for interating over all avatars)         
                 
                
        """
        return _Piavca_base.Core_getAvatar(*args)

    def renameAvatar(*args):
        """
        void Core::renameAvatar(tstring oldName, tstring newName)
                 
        changes the name of an avatar         
                 
                
        """
        return _Piavca_base.Core_renameAvatar(*args)

    def removeAvatar(*args):
        """
        void Core::removeAvatar(Avatar *avatar)
                 
        removes and avatar         
                 
                
        """
        return _Piavca_base.Core_removeAvatar(*args)

    def initAvatar(*args):
        """
        void Core::initAvatar(Avatar *avatar, tstring avatarId, bool bailOnMissedJoints=false, const Vec &Position=Vec(0.0, 0.0, 0.0), const Quat &Orientation=Quat(1.0, 0.0, 0.0, 0.0))
                 
        Initialises an avatar.         
                 
        You pass in a pointer to the avatar and an id with which to initialise it. It creates an implementation object which will actually be a platform dependant sub type of AvatarImp. It then sets some stuff up and stores a pointer to the avatar.         
        """
        return _Piavca_base.Core_initAvatar(*args)

    def numObjects(*args):
        """
        int Piavca::Core::numObjects()
                 
        get the number of avatars         
                 
                
        """
        return _Piavca_base.Core_numObjects(*args)

    def getObject(*args):
        """
        Object * Core::getObject(int i)
                 
        get the ith avatar in the list (used for interating over all avatars)         
                 
                
        """
        return _Piavca_base.Core_getObject(*args)

    def renameObject(*args):
        """
        void Core::renameObject(tstring oldName, tstring newName)
                 
        changes the name of an avatar         
                 
                
        """
        return _Piavca_base.Core_renameObject(*args)

    def removeObject(*args):
        """
        void Core::removeObject(Object *object)
                 
        removes and avatar         
                 
                
        """
        return _Piavca_base.Core_removeObject(*args)

    def initObject(*args):
        """
        void Core::initObject(Object *object, tstring objectId, const Vec &Position=Vec(0.0, 0.0, 0.0), const Quat &Orientation=Quat(1.0, 0.0, 0.0, 0.0))
                 
        Initialises an object.         
                 
        You pass in a pointer to the object and an id with which to initialise it. It creates an implementation object which will actually be a platform dependant sub type of ObjectImp. It then sets some stuff up and stores a pointer to the object.         
        """
        return _Piavca_base.Core_initObject(*args)

    def initMotion(*args):
        """
        void Core::initMotion(TrackMotion *mot, tstring filename=_PSTR(""), bool facial=false, int flags=0, Motion *basePosture=NULL)
                 
        Initialises a TrackMotion object.         
                 
        You pass in a pointer to the TrackMotion and a filename with which to initialise it. It creates an implementation object which will actually be a platform dependant sub type of MotionImp.         
        """
        return _Piavca_base.Core_initMotion(*args)

    def setDir(*args):
        """
        void Piavca::Core::setDir(tstring _dir)
                 
        set the search directory         
                 
                
        """
        return _Piavca_base.Core_setDir(*args)

    def getTime(*args):
        """
        float Piavca::Core::getTime()
                 
        get the current time in seconds         
                 
                
        """
        return _Piavca_base.Core_getTime(*args)

    def getSystemTime(*args):
        """
        virtual float Piavca::Core::getSystemTime()=0
                 
        get the current time in seconds         
                 
                
        """
        return _Piavca_base.Core_getSystemTime(*args)

    def setAutoTimeOff(*args):
        """
        void Piavca::Core::setAutoTimeOff()
                 
        turns off the automatic updating of the current time from the system clock         
                 
                
        """
        return _Piavca_base.Core_setAutoTimeOff(*args)

    def setAutoTimeOn(*args):
        """
        void Piavca::Core::setAutoTimeOn()
                 
        turns on the automatic updating of the current time from the system clock         
                 
                
        """
        return _Piavca_base.Core_setAutoTimeOn(*args)

    def setCurrentTime(*args):
        """
        void Piavca::Core::setCurrentTime(float t)
                 
        sets the current time (if its not linked to the system clock         
                 
                
        """
        return _Piavca_base.Core_setCurrentTime(*args)

    def addError(*args):
        """
        void Core::addError(tstring details)
                 
                
                 
                
        """
        return _Piavca_base.Core_addError(*args)

    def error(*args):
        """
        tostringstream& Piavca::Core::error()
                 
                
                 
                
        """
        return _Piavca_base.Core_error(*args)

    def clearErrors(*args):
        """
        void Core::clearErrors()
                 
                
                 
                
        """
        return _Piavca_base.Core_clearErrors(*args)

    def getErrors(*args):
        """
        tstring Piavca::Core::getErrors()
                 
                
                 
                
        """
        return _Piavca_base.Core_getErrors(*args)

    def errorsPresent(*args):
        """
        bool Piavca::Core::errorsPresent()
                 
                
                 
                
        """
        return _Piavca_base.Core_errorsPresent(*args)

    def addWarning(*args):
        """
        void Core::addWarning(tstring details)
                 
                
                 
                
        """
        return _Piavca_base.Core_addWarning(*args)

    def Warning(*args):
        """
        tostringstream& Piavca::Core::Warning()
                 
                
                 
                
        """
        return _Piavca_base.Core_Warning(*args)

    def clearWarnings(*args):
        """
        void Core::clearWarnings()
                 
                
                 
                
        """
        return _Piavca_base.Core_clearWarnings(*args)

    def getWarnings(*args):
        """
        tstring Piavca::Core::getWarnings()
                 
                
                 
                
        """
        return _Piavca_base.Core_getWarnings(*args)

    def warningsPresent(*args):
        """
        bool Piavca::Core::warningsPresent()
                 
                
                 
                
        """
        return _Piavca_base.Core_warningsPresent(*args)

    def exceptionsOn(*args):
        """
        bool Piavca::Core::exceptionsOn()
                 
                
                 
                
        """
        return _Piavca_base.Core_exceptionsOn(*args)

    def setExceptionsOn(*args):
        """
        void Piavca::Core::setExceptionsOn()
                 
                
                 
                
        """
        return _Piavca_base.Core_setExceptionsOn(*args)

    def setExceptionsOff(*args):
        """
        void Piavca::Core::setExceptionsOff()
                 
                
                 
                
        """
        return _Piavca_base.Core_setExceptionsOff(*args)

    def log(*args):
        """
        std::ostream& Piavca::Core::log()
                 
                
                 
                
        """
        return _Piavca_base.Core_log(*args)

    def addProfilePoint(*args):
        """
        int Piavca::Core::addProfilePoint(tstring name)
                 
                
                 
        creates a new profile point for logging profile data. Returns and id which can be used to access the profile point. You would normally create the point id as a static variable within the function you are profiling.         
        """
        return _Piavca_base.Core_addProfilePoint(*args)

    def profilePointStart(*args):
        """
        void Piavca::Core::profilePointStart(int i)
                 
        marks the start of a profile point         
                 
                
        """
        return _Piavca_base.Core_profilePointStart(*args)

    def profilePointEnd(*args):
        """
        void Piavca::Core::profilePointEnd(int i)
                 
        marks the end of the profile point         
                 
                
        """
        return _Piavca_base.Core_profilePointEnd(*args)

    def printProfileData(*args):
        """
        void Core::printProfileData()
                 
        prints out the profiling data that has been collected.         
                 
                
        """
        return _Piavca_base.Core_printProfileData(*args)

    def output(*args): return _Piavca_base.Core_output(*args)
    def message(*args): return _Piavca_base.Core_message(*args)
    def getMessages(*args): return _Piavca_base.Core_getMessages(*args)
Core_swigregister = _Piavca_base.Core_swigregister
Core_swigregister(Core)
Core_init = _Piavca_base.Core_init
Core_setCore = _Piavca_base.Core_setCore

def Core_getCore(*args):
  """
    static Core* Piavca::Core::getCore()
             
    a static function to get the core instances (there is only one)         
             
            
    """
  return _Piavca_base.Core_getCore(*args)
Core_getCorePointerAsLong = _Piavca_base.Core_getCorePointerAsLong
cvar = _Piavca_base.cvar
Core.nullId = _Piavca_base.cvar.Core_nullId

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
        this = _Piavca_base.new_KeyframeMotion(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca_base.delete_KeyframeMotion
    __del__ = lambda self : None;
    def clone(*args):
        """
        virtual Motion* Piavca::Motion::clone()=0
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca_base.KeyframeMotion_clone(*args)

    def getClassName(*args): return _Piavca_base.KeyframeMotion_getClassName(*args)
    __swig_getmethods__["castToThisType"] = lambda x: _Piavca_base.KeyframeMotion_castToThisType
    if _newclass:castToThisType = staticmethod(_Piavca_base.KeyframeMotion_castToThisType)
    def getMotionLength(*args):
        """
        virtual float Piavca::Motion::getMotionLength() const =0
                 
        gets the time of the end of the motion         
                 
        Though time is represented in floating point, keyframes can only be set as integers to avoid problems with rounding errors. The granularity is the conversion factor between the two.         
        """
        return _Piavca_base.KeyframeMotion_getMotionLength(*args)

    def isFacial(*args):
        """
        virtual bool Piavca::Motion::isFacial()
                 
        whether it is a face or body motion         
                 
                
        """
        return _Piavca_base.KeyframeMotion_isFacial(*args)

    def setFacial(*args): return _Piavca_base.KeyframeMotion_setFacial(*args)
    def isRandomAccess(*args):
        """
        virtual bool Piavca::Motion::isRandomAccess()
                 
        whether you can access a motions value at frames other than the current one         
                 
                
        """
        return _Piavca_base.KeyframeMotion_isRandomAccess(*args)

    def isNull(*args):
        """
        virtual bool Piavca::Motion::isNull(int trackId) const =0
                 
        given a track ID tests whether it actually points to anything or if its null         
                 
                
        """
        return _Piavca_base.KeyframeMotion_isNull(*args)

    def getTrackType(*args):
        """
        virtual trackType Piavca::Motion::getTrackType(int trackId) const =0
                 
        get the type of the track corresponding to an ID         
                 
                
        """
        return _Piavca_base.KeyframeMotion_getTrackType(*args)

    def addFloatTrack(*args): return _Piavca_base.KeyframeMotion_addFloatTrack(*args)
    def addVecTrack(*args): return _Piavca_base.KeyframeMotion_addVecTrack(*args)
    def addQuatTrack(*args): return _Piavca_base.KeyframeMotion_addQuatTrack(*args)
    def setFloatKeyframe(*args): return _Piavca_base.KeyframeMotion_setFloatKeyframe(*args)
    def setVecKeyframe(*args): return _Piavca_base.KeyframeMotion_setVecKeyframe(*args)
    def setQuatKeyframe(*args): return _Piavca_base.KeyframeMotion_setQuatKeyframe(*args)
    def getNumKeyframes(*args): return _Piavca_base.KeyframeMotion_getNumKeyframes(*args)
    def getKeyframeTime(*args): return _Piavca_base.KeyframeMotion_getKeyframeTime(*args)
    def getFloatValueAtTimeInternal(*args):
        """
        virtual float Piavca::Motion::getFloatValueAtTimeInternal(int trackId, float time)=0
                 
        internal version of getFloatValueAtTime, to be overridden         
                 
                
        """
        return _Piavca_base.KeyframeMotion_getFloatValueAtTimeInternal(*args)

    def getVecValueAtTimeInternal(*args):
        """
        virtual Vec Piavca::Motion::getVecValueAtTimeInternal(int trackId, float time)=0
                 
        internal version of getVecValueAtTime, to be overridden         
                 
                
        """
        return _Piavca_base.KeyframeMotion_getVecValueAtTimeInternal(*args)

    def getQuatValueAtTimeInternal(*args):
        """
        virtual Quat Piavca::Motion::getQuatValueAtTimeInternal(int trackId, float time)=0
                 
        internal version of getQuatValueAtTime, to be overridden         
                 
                
        """
        return _Piavca_base.KeyframeMotion_getQuatValueAtTimeInternal(*args)

    def deleteAllTracks(*args): return _Piavca_base.KeyframeMotion_deleteAllTracks(*args)
    def clearTrack(*args): return _Piavca_base.KeyframeMotion_clearTrack(*args)
    def clearAllTracks(*args): return _Piavca_base.KeyframeMotion_clearAllTracks(*args)
    def __disown__(self):
        self.this.disown()
        _Piavca_base.disown_KeyframeMotion(self)
        return weakref_proxy(self)
KeyframeMotion_swigregister = _Piavca_base.KeyframeMotion_swigregister
KeyframeMotion_swigregister(KeyframeMotion)
KeyframeMotion_castToThisType = _Piavca_base.KeyframeMotion_castToThisType


def copyMotionPosture(*args):
  """
    TrackMotion * Piavca::copyMotionPosture(Motion *mot, float time)
             
    creates a Track Motion that is a copy of the given motion at a given time         
             
            
    """
  return _Piavca_base.copyMotionPosture(*args)
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
        this = _Piavca_base.new_Avatar(*args)
        try: self.this.append(this)
        except: self.this = this
    def isValid(*args):
        """
        bool Piavca::Avatar::isValid()
                 
        set the current piavca core object         
                 
                
        """
        return _Piavca_base.Avatar_isValid(*args)

    def activate(*args):
        """
        void Avatar::activate()
                 
        turn on updates on the avatar         
                 
                
        """
        return _Piavca_base.Avatar_activate(*args)

    def deactivate(*args):
        """
        void Avatar::deactivate()
                 
        turn off updates on the avatar         
                 
                
        """
        return _Piavca_base.Avatar_deactivate(*args)

    def getName(*args):
        """
        tstring Piavca::Avatar::getName()
                 
        get the name of the avatar         
                 
                
        """
        return _Piavca_base.Avatar_getName(*args)

    def setName(*args):
        """
        tstring Piavca::Avatar::setName(tstring newName)
                 
        set the name of the avatar         
                 
                
        """
        return _Piavca_base.Avatar_setName(*args)

    def setScale(*args): return _Piavca_base.Avatar_setScale(*args)
    def getScale(*args): return _Piavca_base.Avatar_getScale(*args)
    def hideBodyPart(*args): return _Piavca_base.Avatar_hideBodyPart(*args)
    def showBodyPart(*args): return _Piavca_base.Avatar_showBodyPart(*args)
    def clearFacialExpressionWeights(*args):
        """
        void Piavca::Avatar::clearFacialExpressionWeights()
                 
        set all expression weights to zero         
                 
                
        """
        return _Piavca_base.Avatar_clearFacialExpressionWeights(*args)

    def beginExpression(*args):
        """
        int Piavca::Avatar::beginExpression() const 
                 
        the ID of the first joint that is present in the avatar (the ordering is arbitrary)         
                 
                
        """
        return _Piavca_base.Avatar_beginExpression(*args)

    def endExpression(*args):
        """
        int Avatar::endExpression() const 
                 
        the last joint + 1         
                 
                
        """
        return _Piavca_base.Avatar_endExpression(*args)

    def nextExpression(*args):
        """
        int Avatar::nextExpression(int &expressionId)
                 
        given a joint ID this returns the next joint ID that is present in the avatar         
                 
                
        """
        return _Piavca_base.Avatar_nextExpression(*args)

    def isExpressionNull(*args):
        """
        bool Piavca::Avatar::isExpressionNull(int expressionId) const 
                 
        whether the joint is present in the avatar         
                 
                
        """
        return _Piavca_base.Avatar_isExpressionNull(*args)

    def setRootPosition(*args):
        """
        void Piavca::Avatar::setRootPosition(const Vec &Position)
                 
                
                 
        get or set the root position and orientation of the avatar         
        """
        return _Piavca_base.Avatar_setRootPosition(*args)

    def getRootPosition(*args):
        """
        Vec Piavca::Avatar::getRootPosition()
                 
                
                 
                
        """
        return _Piavca_base.Avatar_getRootPosition(*args)

    def setRootOrientation(*args):
        """
        void Piavca::Avatar::setRootOrientation(const Quat &Orientation)
                 
                
                 
                
        """
        return _Piavca_base.Avatar_setRootOrientation(*args)

    def setRootAngle(*args):
        """
        void Piavca::Avatar::setRootAngle(float angle)
                 
        set the root orientation from an angle in radians (assumed to be about the verticle)         
                 
                
        """
        return _Piavca_base.Avatar_setRootAngle(*args)

    def setRootAngleDeg(*args):
        """
        void Piavca::Avatar::setRootAngleDeg(float angle)
                 
        set the root orientation from an angle in degrees (assumed to be about the verticle)         
                 
                
        """
        return _Piavca_base.Avatar_setRootAngleDeg(*args)

    def getRootOrientation(*args):
        """
        Quat Piavca::Avatar::getRootOrientation()
                 
                
                 
                
        """
        return _Piavca_base.Avatar_getRootOrientation(*args)

    def createJoint(*args):
        """
        bool Piavca::Avatar::createJoint(tstring jointName)
                 
        creates a new joint         
                 
        It will only succeed if there is a piece of geometry corresponding to the name if not it returns false.         
        """
        return _Piavca_base.Avatar_createJoint(*args)

    def begin(*args):
        """
        int Piavca::Avatar::begin() const 
                 
        the ID of the first joint that is present in the avatar (the ordering is arbitrary)         
                 
                
        """
        return _Piavca_base.Avatar_begin(*args)

    def end(*args):
        """
        int Avatar::end() const 
                 
        the last joint + 1         
                 
                
        """
        return _Piavca_base.Avatar_end(*args)

    def next(*args):
        """
        int Avatar::next(int &jointId)
                 
        given a joint ID this returns the next joint ID that is present in the avatar         
                 
                
        """
        return _Piavca_base.Avatar_next(*args)

    def getParent(*args):
        """
        int Piavca::Avatar::getParent(int jointId) const 
                 
        returns the ID of the parent of the joint in the joint heirarchy (or a negative value if it doesn't exist         
                 
                
        """
        return _Piavca_base.Avatar_getParent(*args)

    def getJointName(*args):
        """
        const tstring Piavca::Avatar::getJointName(int jointId)
                 
        get the name of the joint corresponding to an ID         
                 
                
        """
        return _Piavca_base.Avatar_getJointName(*args)

    def isNull(*args):
        """
        bool Piavca::Avatar::isNull(int jointId) const 
                 
        whether the joint is present in the avatar         
                 
                
        """
        return _Piavca_base.Avatar_isNull(*args)

    def hasChanged(*args):
        """
        bool Piavca::Avatar::hasChanged(int jointId)
                 
        check whether the joint has been changed by user input         
                 
                
        """
        return _Piavca_base.Avatar_hasChanged(*args)

    def clearChange(*args):
        """
        void Piavca::Avatar::clearChange(int jointId)
                 
        clears the changed flag for the joint         
                 
                
        """
        return _Piavca_base.Avatar_clearChange(*args)

    def setJointPosition(*args): return _Piavca_base.Avatar_setJointPosition(*args)
    def scaleRoot(*args):
        """
        void Piavca::Avatar::scaleRoot(Vec scale)
                 
        scales the root by a non-uniform scale vector         
                 
                
        """
        return _Piavca_base.Avatar_scaleRoot(*args)

    def scaleJoint(*args):
        """
        void Piavca::Avatar::scaleJoint(int jointId, Vec scale)
                 
        scales a joint by a non-uniform scale vector         
                 
                
        """
        return _Piavca_base.Avatar_scaleJoint(*args)

    def getBoundBox(*args): return _Piavca_base.Avatar_getBoundBox(*args)
    def getBaseBoundBox(*args): return _Piavca_base.Avatar_getBaseBoundBox(*args)
    def timeStep(*args):
        """
        void Avatar::timeStep(float time)
                 
        set the current time         
                 
        This is used for animation, it sets the time within the current piece of motion and puts the avatar in the correct position for that motion at that time         
        """
        return _Piavca_base.Avatar_timeStep(*args)

    def loadMotion(*args):
        """
        void Avatar::loadMotion(Motion *motion)
                 
        load motion as a motion object         
                 
        The start time allows the client to specify a time in world time for the motion to start running         
        """
        return _Piavca_base.Avatar_loadMotion(*args)

    def unloadMotion(*args):
        """
        void Avatar::unloadMotion()
                 
                
                 
                
        """
        return _Piavca_base.Avatar_unloadMotion(*args)

    def getMotion(*args):
        """
        const Motion* Piavca::Avatar::getMotion() const 
                 
        get a const pointer to the motion so it can be seen by the client         
                 
                
        """
        return _Piavca_base.Avatar_getMotion(*args)

    def playMotion(*args):
        """
        void Avatar::playMotion(Motion *m)
                 
                
                 
                
        """
        return _Piavca_base.Avatar_playMotion(*args)

    def playMotionDirect(*args):
        """
        void Avatar::playMotion(Motion *m)
                 
                
                 
                
        """
        return _Piavca_base.Avatar_playMotionDirect(*args)

    def stopMotion(*args):
        """
        void Piavca::Avatar::stopMotion()
                 
        stops the motion playing         
                 
                
        """
        return _Piavca_base.Avatar_stopMotion(*args)

    def restartMotion(*args):
        """
        void Piavca::Avatar::restartMotion()
                 
        restarts the motion without changing the start time         
                 
                
        """
        return _Piavca_base.Avatar_restartMotion(*args)

    def setMotionStartTime(*args):
        """
        void Avatar::setMotionStartTime(float startTime)
                 
        changes the start time of the motion         
                 
                
        """
        return _Piavca_base.Avatar_setMotionStartTime(*args)

    def getMotionStartTime(*args):
        """
        float Avatar::getMotionStartTime()
                 
        get the time when the current motion starts         
                 
                
        """
        return _Piavca_base.Avatar_getMotionStartTime(*args)

    def getMotionEndTime(*args):
        """
        float Avatar::getMotionEndTime()
                 
        get the time when the current motion should end         
                 
                
        """
        return _Piavca_base.Avatar_getMotionEndTime(*args)

    def showMotionAtTime(*args):
        """
        void Avatar::showMotionAtTime(float time)
                 
        displays the motion on the avatar at time         
                 
                
        """
        return _Piavca_base.Avatar_showMotionAtTime(*args)

    def loadFacialMotion(*args):
        """
        void Avatar::loadFacialMotion(Motion *motion)
                 
        load a facial motion as a motion object         
                 
        The start time allows the client to specify a time in world time for the motion to start running         
        """
        return _Piavca_base.Avatar_loadFacialMotion(*args)

    def unloadFacialMotion(*args):
        """
        void Avatar::unloadFacialMotion()
                 
                
                 
                
        """
        return _Piavca_base.Avatar_unloadFacialMotion(*args)

    def getFacialMotion(*args):
        """
        const Motion* Piavca::Avatar::getFacialMotion() const 
                 
        get a const pointer to the motion so it can be seen by the client         
                 
                
        """
        return _Piavca_base.Avatar_getFacialMotion(*args)

    def playFacialMotion(*args):
        """
        void Avatar::playFacialMotion(Motion *m)
                 
        starts playing the motion at the current time         
                 
                
        """
        return _Piavca_base.Avatar_playFacialMotion(*args)

    def stopFacialMotion(*args):
        """
        void Piavca::Avatar::stopFacialMotion()
                 
        stops the motion playing         
                 
                
        """
        return _Piavca_base.Avatar_stopFacialMotion(*args)

    def restartFacialMotion(*args):
        """
        void Piavca::Avatar::restartFacialMotion()
                 
        restarts the motion without changing the start time         
                 
                
        """
        return _Piavca_base.Avatar_restartFacialMotion(*args)

    def setFacialMotionStartTime(*args):
        """
        void Avatar::setFacialMotionStartTime(float startTime)
                 
        changes the start time of the motion         
                 
                
        """
        return _Piavca_base.Avatar_setFacialMotionStartTime(*args)

    def getFacialMotionStartTime(*args):
        """
        float Avatar::getFacialMotionStartTime()
                 
        get the time when the current motion starts         
                 
                
        """
        return _Piavca_base.Avatar_getFacialMotionStartTime(*args)

    def getFacialMotionEndTime(*args):
        """
        float Avatar::getFacialMotionEndTime()
                 
        get the time when the current motion should end         
                 
                
        """
        return _Piavca_base.Avatar_getFacialMotionEndTime(*args)

    def showFacialMotionAtTime(*args):
        """
        void Avatar::showFacialMotionAtTime(float time)
                 
        displays the motion on the avatar at time         
                 
                
        """
        return _Piavca_base.Avatar_showFacialMotionAtTime(*args)

    def loadScaleMotion(*args):
        """
        void Avatar::loadScaleMotion(Motion *motion)
                 
        load a scale motion as a motion object         
                 
        The start time allows the client to specify a time in world time for the motion to start running         
        """
        return _Piavca_base.Avatar_loadScaleMotion(*args)

    def unloadScaleMotion(*args):
        """
        void Avatar::unloadScaleMotion()
                 
                
                 
                
        """
        return _Piavca_base.Avatar_unloadScaleMotion(*args)

    def getScaleMotion(*args):
        """
        const Motion* Piavca::Avatar::getScaleMotion() const 
                 
        get a const pointer to the motion so it can be seen by the client         
                 
                
        """
        return _Piavca_base.Avatar_getScaleMotion(*args)

    def playScaleMotion(*args):
        """
        void Avatar::playScaleMotion(Motion *m)
                 
        starts playing the motion at the current time         
                 
                
        """
        return _Piavca_base.Avatar_playScaleMotion(*args)

    def stopScaleMotion(*args):
        """
        void Piavca::Avatar::stopScaleMotion()
                 
        stops the motion playing         
                 
                
        """
        return _Piavca_base.Avatar_stopScaleMotion(*args)

    def restartScaleMotion(*args):
        """
        void Piavca::Avatar::restartScaleMotion()
                 
        restarts the motion without changing the start time         
                 
                
        """
        return _Piavca_base.Avatar_restartScaleMotion(*args)

    def setScaleMotionStartTime(*args):
        """
        void Avatar::setScaleMotionStartTime(float startTime)
                 
        changes the start time of the motion         
                 
                
        """
        return _Piavca_base.Avatar_setScaleMotionStartTime(*args)

    def getScaleMotionStartTime(*args):
        """
        float Avatar::getScaleMotionStartTime()
                 
        get the time when the current motion starts         
                 
                
        """
        return _Piavca_base.Avatar_getScaleMotionStartTime(*args)

    def getScaleMotionEndTime(*args):
        """
        float Avatar::getScaleMotionEndTime()
                 
        get the time when the current motion should end         
                 
                
        """
        return _Piavca_base.Avatar_getScaleMotionEndTime(*args)

    def showScaleMotionAtTime(*args):
        """
        void Avatar::showScaleMotionAtTime(float time)
                 
        displays the motion on the avatar at time         
                 
                
        """
        return _Piavca_base.Avatar_showScaleMotionAtTime(*args)

    def registerCallback(*args):
        """
        void Avatar::registerCallback(AvatarTimeCallback *cb)
                 
        registers a callback so that it is called on the avatar every frame         
                 
                
        """
        return _Piavca_base.Avatar_registerCallback(*args)

    def removeCallback(*args):
        """
        void Avatar::removeCallback(tstring cbName)
                 
        deletes a callback         
                 
                
        """
        return _Piavca_base.Avatar_removeCallback(*args)

    def getNumCallbacks(*args):
        """
        int Avatar::getNumCallbacks()
                 
        gets the number of registered callbacks (for iterating through them)         
                 
                
        """
        return _Piavca_base.Avatar_getNumCallbacks(*args)

    def getCallback(*args):
        """
        AvatarTimeCallback * Avatar::getCallback(int i)
                 
        get a callback based on its index (the indeces are arbitrary this is just useful for finding a callback)         
                 
                
        """
        return _Piavca_base.Avatar_getCallback(*args)

    def event(*args): return _Piavca_base.Avatar_event(*args)
    def setFacialExpressionWeight(*args):
        """
        bool Piavca::Avatar::setFacialExpressionWeight(int id, float weight, float timeInterval=0.5)
                 
        set the weight of a facial expression (used in the blend)         
                 
                
        """
        return _Piavca_base.Avatar_setFacialExpressionWeight(*args)

    def getFacialExpressionWeight(*args):
        """
        float Piavca::Avatar::getFacialExpressionWeight(int id)
                 
        get the weight of an expression         
                 
                
        """
        return _Piavca_base.Avatar_getFacialExpressionWeight(*args)

    def setJointOrientation(*args):
        """
        void Avatar::setJointOrientation(std::vector< std::pair< int, Quat > > jointOrientation, jointCoord worldCoord=JOINTLOCAL_COORD)
                 
        set all the joint orientations from a vector of joint IDs and values         
                 
        This can be done in various coordinate systems, jointlocal is the coordante space of the joint (default) local is the space of the avatar root world is the world coordinates using the second two is likely to be much less efficient         
        """
        return _Piavca_base.Avatar_setJointOrientation(*args)

    def getJointOrientation(*args):
        """
        Quat Piavca::Avatar::getJointOrientation(int jointId, jointCoord worldCoord=JOINTLOCAL_COORD)
                 
        get the orientation of a joint         
                 
        The joint is specified via an ID. This can be done in various coordinate systems, jointlocal is the coordante space of the joint (default) local is the space of the avatar root world is the world coordinates using the second two is likely to be much less efficient         
        """
        return _Piavca_base.Avatar_getJointOrientation(*args)

    def getJointBasePosition(*args):
        """
        Vec Piavca::Avatar::getJointBasePosition(int jointId, jointCoord worldCoord=LOCAL_COORD)
                 
        get the current position of the start point of the joint         
                 
        calculated from the root position and joint angles by forward kinematics This can be done in various coordinate systems, jointlocal is the coordante space of the joint local is the space of the avatar root (default) world is the world coordinates         
        """
        return _Piavca_base.Avatar_getJointBasePosition(*args)

    def play_motion(*args): return _Piavca_base.Avatar_play_motion(*args)
    def add_background_motion(*args): return _Piavca_base.Avatar_add_background_motion(*args)
    def interrupt_motion(*args): return _Piavca_base.Avatar_interrupt_motion(*args)
    def stop_motion(*args): return _Piavca_base.Avatar_stop_motion(*args)
    def reposition_relative(*args): return _Piavca_base.Avatar_reposition_relative(*args)
    def reposition_absolute(*args): return _Piavca_base.Avatar_reposition_absolute(*args)
Avatar_swigregister = _Piavca_base.Avatar_swigregister
Avatar_swigregister(Avatar)

class queueElement(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, queueElement, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, queueElement, name)
    __repr__ = _swig_repr
    __swig_setmethods__["mot"] = _Piavca_base.queueElement_mot_set
    __swig_getmethods__["mot"] = _Piavca_base.queueElement_mot_get
    if _newclass:mot = _swig_property(_Piavca_base.queueElement_mot_get, _Piavca_base.queueElement_mot_set)
    __swig_setmethods__["name"] = _Piavca_base.queueElement_name_set
    __swig_getmethods__["name"] = _Piavca_base.queueElement_name_get
    if _newclass:name = _swig_property(_Piavca_base.queueElement_name_get, _Piavca_base.queueElement_name_set)
    __swig_setmethods__["atTime"] = _Piavca_base.queueElement_atTime_set
    __swig_getmethods__["atTime"] = _Piavca_base.queueElement_atTime_get
    if _newclass:atTime = _swig_property(_Piavca_base.queueElement_atTime_get, _Piavca_base.queueElement_atTime_set)
    __swig_setmethods__["background"] = _Piavca_base.queueElement_background_set
    __swig_getmethods__["background"] = _Piavca_base.queueElement_background_get
    if _newclass:background = _swig_property(_Piavca_base.queueElement_background_get, _Piavca_base.queueElement_background_set)
    def __init__(self, *args): 
        this = _Piavca_base.new_queueElement(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca_base.delete_queueElement
    __del__ = lambda self : None;
queueElement_swigregister = _Piavca_base.queueElement_swigregister
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
        this = _Piavca_base.new_AvatarMotionQueue(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca_base.delete_AvatarMotionQueue
    __del__ = lambda self : None;
    __swig_getmethods__["getQueue"] = lambda x: _Piavca_base.AvatarMotionQueue_getQueue
    if _newclass:getQueue = staticmethod(_Piavca_base.AvatarMotionQueue_getQueue)
    __swig_getmethods__["hasQueue"] = lambda x: _Piavca_base.AvatarMotionQueue_hasQueue
    if _newclass:hasQueue = staticmethod(_Piavca_base.AvatarMotionQueue_hasQueue)
    def init(*args):
        """
        void AvatarMotionQueue::init(Piavca::Avatar *avatar)
                 
        This is a setup method for the callback.         
                 
        It's called when the callback is registered         
        """
        return _Piavca_base.AvatarMotionQueue_init(*args)

    def timeStep(*args):
        """
        void AvatarMotionQueue::timeStep(Piavca::Avatar *avatar, float time)
                 
        implement this to make the callback do things         
                 
        It's called every frame with by the API which passes in the avatar to which the callback is attatched         
        """
        return _Piavca_base.AvatarMotionQueue_timeStep(*args)

    def isFacial(*args):
        """
        bool Piavca::AvatarMotionQueue::isFacial()
                 
        whether the queue handles facial or body motions         
                 
                
        """
        return _Piavca_base.AvatarMotionQueue_isFacial(*args)

    def getCurrentMotionStart(*args):
        """
        float Piavca::AvatarMotionQueue::getCurrentMotionStart()
                 
        gets the start time of the current motion         
                 
                
        """
        return _Piavca_base.AvatarMotionQueue_getCurrentMotionStart(*args)

    def reblend(*args):
        """
        void Piavca::AvatarMotionQueue::reblend()
                 
                
                 
                
        """
        return _Piavca_base.AvatarMotionQueue_reblend(*args)

    def setBlendInterval(*args):
        """
        void Piavca::AvatarMotionQueue::setBlendInterval(float t)
                 
        sets how long it takes to blend between subsequent motions.         
                 
                
        """
        return _Piavca_base.AvatarMotionQueue_setBlendInterval(*args)

    def enqueueMotion(*args):
        """
        void AvatarMotionQueue::enqueueMotion(tstring name, Piavca::Motion *motion, float atTime=0.0)
                 
        adds a motion to the queue         
                 
        You have to pass in a name for the motion and optionally a minimum time for it to start.         
        """
        return _Piavca_base.AvatarMotionQueue_enqueueMotion(*args)

    def enqueueRandomMotions(*args):
        """
        void AvatarMotionQueue::enqueueRandomMotions(int num=0)
                 
        enqueue a number of randomly chosen motions         
                 
                
        """
        return _Piavca_base.AvatarMotionQueue_enqueueRandomMotions(*args)

    def queueTopIsBackground(*args):
        """
        bool AvatarMotionQueue::queueTopIsBackground()
                 
        tests whether the first motion on the queue is a background motion         
                 
                
        """
        return _Piavca_base.AvatarMotionQueue_queueTopIsBackground(*args)

    def queueTopTime(*args):
        """
        float AvatarMotionQueue::queueTopTime()
                 
        gets the minimum start time of the first motion on the queue         
                 
                
        """
        return _Piavca_base.AvatarMotionQueue_queueTopTime(*args)

    def dequeueMotion(*args):
        """
        Motion * AvatarMotionQueue::dequeueMotion()
                 
        pops a motion off the queue         
                 
                
        """
        return _Piavca_base.AvatarMotionQueue_dequeueMotion(*args)

    def getQueueSize(*args):
        """
        int Piavca::AvatarMotionQueue::getQueueSize()
                 
        returns the number of motions on the queue         
                 
                
        """
        return _Piavca_base.AvatarMotionQueue_getQueueSize(*args)

    def updateDelay(*args):
        """
        void Piavca::AvatarMotionQueue::updateDelay(float delay)
                 
        change the delay         
                 
                
        """
        return _Piavca_base.AvatarMotionQueue_updateDelay(*args)

    def clearQueue(*args):
        """
        void AvatarMotionQueue::clearQueue()
                 
        empties the queue         
                 
                
        """
        return _Piavca_base.AvatarMotionQueue_clearQueue(*args)

    def removeMotion(*args):
        """
        void AvatarMotionQueue::removeMotion(tstring name)
                 
        removes a named forground motion         
                 
                
        """
        return _Piavca_base.AvatarMotionQueue_removeMotion(*args)

    def pauseMotion(*args):
        """
        void Piavca::AvatarMotionQueue::pauseMotion(tstring name)
                 
        pauses a named forground motion         
                 
                
        """
        return _Piavca_base.AvatarMotionQueue_pauseMotion(*args)

    def unpauseMotion(*args):
        """
        void Piavca::AvatarMotionQueue::unpauseMotion(tstring name)
                 
        unpauses a named forground motion         
                 
                
        """
        return _Piavca_base.AvatarMotionQueue_unpauseMotion(*args)

    def clearAllBackgroundMotions(*args):
        """
        void AvatarMotionQueue::clearAllBackgroundMotions()
                 
        removes all background motions from the queue         
                 
                
        """
        return _Piavca_base.AvatarMotionQueue_clearAllBackgroundMotions(*args)

    def clearFinishedBackgroundMotions(*args):
        """
        void AvatarMotionQueue::clearFinishedBackgroundMotions()
                 
        removes any background motions that have stopped playing         
                 
                
        """
        return _Piavca_base.AvatarMotionQueue_clearFinishedBackgroundMotions(*args)

    def removeBackgroundMotion(*args):
        """
        void AvatarMotionQueue::removeBackgroundMotion(tstring name)
                 
        removes a named background motion         
                 
                
        """
        return _Piavca_base.AvatarMotionQueue_removeBackgroundMotion(*args)

    def removeBackgroundMotionByType(*args):
        """
        void AvatarMotionQueue::removeBackgroundMotionByType(const type_info &ty)
                 
        removes a background motion with a given type         
                 
                
        """
        return _Piavca_base.AvatarMotionQueue_removeBackgroundMotionByType(*args)

    def pauseBackgroundMotion(*args):
        """
        void AvatarMotionQueue::pauseBackgroundMotion(tstring name)
                 
        pauses a named background motion         
                 
                
        """
        return _Piavca_base.AvatarMotionQueue_pauseBackgroundMotion(*args)

    def unpauseBackgroundMotion(*args):
        """
        void AvatarMotionQueue::unpauseBackgroundMotion(tstring name)
                 
        unpauses a named background motion         
                 
                
        """
        return _Piavca_base.AvatarMotionQueue_unpauseBackgroundMotion(*args)

    def interrupt(*args):
        """
        void Piavca::AvatarMotionQueue::interrupt()
                 
        interrupts the queue         
                 
        so the next motion is played immediately, without waiting for the current one stop         
        """
        return _Piavca_base.AvatarMotionQueue_interrupt(*args)

    def repositionRelative(*args): return _Piavca_base.AvatarMotionQueue_repositionRelative(*args)
    def repositionAbsolute(*args): return _Piavca_base.AvatarMotionQueue_repositionAbsolute(*args)
    def getMotion(*args):
        """
        virtual Piavca::Motion* Piavca::AvatarMotionQueue::getMotion()
                 
        return the resulting motion         
                 
                
        """
        return _Piavca_base.AvatarMotionQueue_getMotion(*args)

    def blendMotion(*args):
        """
        Motion * AvatarMotionQueue::blendMotion(Motion *m, Avatar *av, float scaleFactor)
                 
                
                 
                
        """
        return _Piavca_base.AvatarMotionQueue_blendMotion(*args)

    def addBackgroundMotion(*args):
        """
        void AvatarMotionQueue::addBackgroundMotion(tstring name, Piavca::Motion *motion, float atTime=0.0)
                 
        adds a new background motion to the queue         
                 
        A background motion is played concurrently with any motions on the queue. You have to pass in a name and optionally minimum time at which it should start.         
        """
        return _Piavca_base.AvatarMotionQueue_addBackgroundMotion(*args)

AvatarMotionQueue_swigregister = _Piavca_base.AvatarMotionQueue_swigregister
AvatarMotionQueue_swigregister(AvatarMotionQueue)
AvatarMotionQueue_getQueue = _Piavca_base.AvatarMotionQueue_getQueue
AvatarMotionQueue_hasQueue = _Piavca_base.AvatarMotionQueue_hasQueue

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
        this = _Piavca_base.new_Object(*args)
        try: self.this.append(this)
        except: self.this = this
    def getName(*args):
        """
        tstring Piavca::Object::getName()
                 
        get the name of the avatar         
                 
                
        """
        return _Piavca_base.Object_getName(*args)

    def setName(*args):
        """
        tstring Piavca::Object::setName(tstring newName)
                 
        set the name of the avatar         
                 
                
        """
        return _Piavca_base.Object_setName(*args)

    def setPosition(*args):
        """
        void Piavca::Object::setPosition(const Vec &Position)
                 
                
                 
        get or set the root position and orientation of the avatar         
        """
        return _Piavca_base.Object_setPosition(*args)

    def getPosition(*args):
        """
        Vec Piavca::Object::getPosition()
                 
                
                 
                
        """
        return _Piavca_base.Object_getPosition(*args)

    def setOrientation(*args):
        """
        void Piavca::Object::setOrientation(const Quat &Orientation)
                 
                
                 
                
        """
        return _Piavca_base.Object_setOrientation(*args)

    def setAngle(*args):
        """
        void Piavca::Object::setAngle(float angle)
                 
        set the orientation from an angle in radians (assumed to be about the verticle)         
                 
                
        """
        return _Piavca_base.Object_setAngle(*args)

    def setAngleDeg(*args):
        """
        void Piavca::Object::setAngleDeg(float angle)
                 
        set the orientation from an angle in degrees (assumed to be about the verticle)         
                 
                
        """
        return _Piavca_base.Object_setAngleDeg(*args)

    def getOrientation(*args):
        """
        Quat Piavca::Object::getOrientation()
                 
                
                 
                
        """
        return _Piavca_base.Object_getOrientation(*args)

    def scale(*args):
        """
        void Piavca::Object::scale(Vec scale)
                 
        scales the root by a non-uniform scale vector         
                 
                
        """
        return _Piavca_base.Object_scale(*args)

Object_swigregister = _Piavca_base.Object_swigregister
Object_swigregister(Object)


def degToRad(*args):
  """
    float Piavca::degToRad(float angle)
             
    convert and angle in degrees to radians         
             
            
    """
  return _Piavca_base.degToRad(*args)

def radToDeg(*args):
  """
    float Piavca::radToDeg(float angle)
             
    convert and angle in radians to degrees         
             
            
    """
  return _Piavca_base.radToDeg(*args)
class CurrentValueMotion(KeyframeMotion):
    __swig_setmethods__ = {}
    for _s in [KeyframeMotion]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, CurrentValueMotion, name, value)
    __swig_getmethods__ = {}
    for _s in [KeyframeMotion]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, CurrentValueMotion, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _Piavca_base.new_CurrentValueMotion(*args)
        try: self.this.append(this)
        except: self.this = this
    def clone(*args):
        """
        virtual Motion* Piavca::Motion::clone()=0
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca_base.CurrentValueMotion_clone(*args)

    def getClassName(*args): return _Piavca_base.CurrentValueMotion_getClassName(*args)
    __swig_getmethods__["castToThisType"] = lambda x: _Piavca_base.CurrentValueMotion_castToThisType
    if _newclass:castToThisType = staticmethod(_Piavca_base.CurrentValueMotion_castToThisType)
    def setFloatValue(*args): return _Piavca_base.CurrentValueMotion_setFloatValue(*args)
    def setVecValue(*args): return _Piavca_base.CurrentValueMotion_setVecValue(*args)
    def setQuatValue(*args): return _Piavca_base.CurrentValueMotion_setQuatValue(*args)
    __swig_destroy__ = _Piavca_base.delete_CurrentValueMotion
    __del__ = lambda self : None;
CurrentValueMotion_swigregister = _Piavca_base.CurrentValueMotion_swigregister
CurrentValueMotion_swigregister(CurrentValueMotion)
Pi = cvar.Pi
CurrentValueMotion_castToThisType = _Piavca_base.CurrentValueMotion_castToThisType

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
    __repr__ = _swig_repr
    def __init__(self, *args): 
        """
        Piavca::MotionFilter::MotionFilter(const MotionFilter &mf)
                 
                
                 
                
        """
        if self.__class__ == MotionFilter:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca_base.new_MotionFilter(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca_base.delete_MotionFilter
    __del__ = lambda self : None;
    def clone(*args):
        """
        virtual Motion* Piavca::Motion::clone()=0
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca_base.MotionFilter_clone(*args)

    def getClassName(*args): return _Piavca_base.MotionFilter_getClassName(*args)
    __swig_getmethods__["castToThisType"] = lambda x: _Piavca_base.MotionFilter_castToThisType
    if _newclass:castToThisType = staticmethod(_Piavca_base.MotionFilter_castToThisType)
    def printInfo(*args):
        """
        void Piavca::MotionFilter::printInfo()
                 
        prints out info about the motion heirarchy         
                 
                
        """
        return _Piavca_base.MotionFilter_printInfo(*args)

    def findSub(*args):
        """
        virtual Motion* Piavca::MotionFilter::findSub(tstring nm)
                 
        finds the first submotion with a given name         
                 
                
        """
        return _Piavca_base.MotionFilter_findSub(*args)

    def findSubByType(*args):
        """
        virtual Motion* Piavca::MotionFilter::findSubByType(const type_info &ty)
                 
        finds the first submotion with a given type         
                 
                
        """
        return _Piavca_base.MotionFilter_findSubByType(*args)

    def load(*args):
        """
        virtual void Piavca::MotionFilter::load(Avatar *av)
                 
        called when the motion is loaded into an avatar         
                 
                
        """
        return _Piavca_base.MotionFilter_load(*args)

    def unload(*args):
        """
        virtual void Piavca::MotionFilter::unload()
                 
        called when the motion is unloaded from an avatar         
                 
                
        """
        return _Piavca_base.MotionFilter_unload(*args)

    def loaded(*args):
        """
        virtual bool Piavca::MotionFilter::loaded()
                 
        checks if the motion has been loaded into an avatar         
                 
                
        """
        return _Piavca_base.MotionFilter_loaded(*args)

    def preFrame(*args): return _Piavca_base.MotionFilter_preFrame(*args)
    def getAvatar(*args): return _Piavca_base.MotionFilter_getAvatar(*args)
    def setStartTime(*args):
        """
        virtual void Piavca::MotionFilter::setStartTime(float time)
                 
        sets the start time of the motion. Called when its loaded into an avatar.         
                 
                
        """
        return _Piavca_base.MotionFilter_setStartTime(*args)

    def reset(*args):
        """
        void Piavca::MotionFilter::reset()
                 
        does any resetting needed         
                 
                
        """
        return _Piavca_base.MotionFilter_reset(*args)

    def event(*args): return _Piavca_base.MotionFilter_event(*args)
    def cleanRecursionState(*args): return _Piavca_base.MotionFilter_cleanRecursionState(*args)
    def setMotion(*args):
        """
        void Piavca::MotionFilter::setMotion(Motion *mot)
                 
                
                 
                
        """
        return _Piavca_base.MotionFilter_setMotion(*args)

    def getMotion(*args): return _Piavca_base.MotionFilter_getMotion(*args)
    def getMotionLength(*args):
        """
        float Piavca::MotionFilter::getMotionLength() const 
                 
        gets the length of the motion in seconds         
                 
                
        """
        return _Piavca_base.MotionFilter_getMotionLength(*args)

    def isFacial(*args):
        """
        virtual bool Piavca::MotionFilter::isFacial()
                 
        whether it is a face or body motion         
                 
                
        """
        return _Piavca_base.MotionFilter_isFacial(*args)

    def isRandomAccess(*args):
        """
        virtual bool Piavca::MotionFilter::isRandomAccess()
                 
        whether you can access a motions value at frames other than the current one         
                 
                
        """
        return _Piavca_base.MotionFilter_isRandomAccess(*args)

    def isNull(*args):
        """
        virtual bool Piavca::MotionFilter::isNull(int trackId) const 
                 
        given an iterator tests whether it actually points to anything or if its null         
                 
                
        """
        return _Piavca_base.MotionFilter_isNull(*args)

    def getTrackType(*args):
        """
        trackType Piavca::MotionFilter::getTrackType(int trackId) const 
                 
        get the type of the track corresponding to an iterator         
                 
                
        """
        return _Piavca_base.MotionFilter_getTrackType(*args)

    def getFloatValueAtTimeInternal(*args):
        """
        virtual float Piavca::Motion::getFloatValueAtTimeInternal(int trackId, float time)=0
                 
        internal version of getFloatValueAtTime, to be overridden         
                 
                
        """
        return _Piavca_base.MotionFilter_getFloatValueAtTimeInternal(*args)

    def getVecValueAtTimeInternal(*args):
        """
        virtual Vec Piavca::Motion::getVecValueAtTimeInternal(int trackId, float time)=0
                 
        internal version of getVecValueAtTime, to be overridden         
                 
                
        """
        return _Piavca_base.MotionFilter_getVecValueAtTimeInternal(*args)

    def getQuatValueAtTimeInternal(*args):
        """
        virtual Quat Piavca::Motion::getQuatValueAtTimeInternal(int trackId, float time)=0
                 
        internal version of getQuatValueAtTime, to be overridden         
                 
                
        """
        return _Piavca_base.MotionFilter_getQuatValueAtTimeInternal(*args)

    def __disown__(self):
        self.this.disown()
        _Piavca_base.disown_MotionFilter(self)
        return weakref_proxy(self)
MotionFilter_swigregister = _Piavca_base.MotionFilter_swigregister
MotionFilter_swigregister(MotionFilter)
MotionFilter_castToThisType = _Piavca_base.MotionFilter_castToThisType

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
        this = _Piavca_base.new_TwoMotionCombiner(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca_base.delete_TwoMotionCombiner
    __del__ = lambda self : None;
    def clone(*args):
        """
        virtual Motion* Piavca::Motion::clone()=0
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca_base.TwoMotionCombiner_clone(*args)

    def getClassName(*args): return _Piavca_base.TwoMotionCombiner_getClassName(*args)
    __swig_getmethods__["castToThisType"] = lambda x: _Piavca_base.TwoMotionCombiner_castToThisType
    if _newclass:castToThisType = staticmethod(_Piavca_base.TwoMotionCombiner_castToThisType)
    def printInfo(*args):
        """
        void TwoMotionCombiner::printInfo()
                 
        prints out info about the motion heirarchy         
                 
                
        """
        return _Piavca_base.TwoMotionCombiner_printInfo(*args)

    def findSub(*args):
        """
        Motion * TwoMotionCombiner::findSub(tstring nm)
                 
        finds the first submotion with a given name         
                 
                
        """
        return _Piavca_base.TwoMotionCombiner_findSub(*args)

    def findSubByType(*args):
        """
        Motion * TwoMotionCombiner::findSubByType(const type_info &ty)
                 
        finds the first submotion with a given type         
                 
                
        """
        return _Piavca_base.TwoMotionCombiner_findSubByType(*args)

    def load(*args):
        """
        void TwoMotionCombiner::load(Avatar *av)
                 
        called when the motion is loaded into an avatar         
                 
                
        """
        return _Piavca_base.TwoMotionCombiner_load(*args)

    def unload(*args):
        """
        void TwoMotionCombiner::unload()
                 
        called when the motion is unloaded from an avatar         
                 
                
        """
        return _Piavca_base.TwoMotionCombiner_unload(*args)

    def loaded(*args):
        """
        bool TwoMotionCombiner::loaded()
                 
        checks if the motion has been loaded into an avatar         
                 
                
        """
        return _Piavca_base.TwoMotionCombiner_loaded(*args)

    def getAvatar(*args): return _Piavca_base.TwoMotionCombiner_getAvatar(*args)
    def setStartTime(*args):
        """
        void TwoMotionCombiner::setStartTime(float time)
                 
        sets the start time of the motion. Called when its loaded into an avatar.         
                 
                
        """
        return _Piavca_base.TwoMotionCombiner_setStartTime(*args)

    def reset(*args):
        """
        void TwoMotionCombiner::reset()
                 
        does any resetting needed         
                 
                
        """
        return _Piavca_base.TwoMotionCombiner_reset(*args)

    def event(*args): return _Piavca_base.TwoMotionCombiner_event(*args)
    def cleanRecursionState(*args): return _Piavca_base.TwoMotionCombiner_cleanRecursionState(*args)
    def getMotionLength(*args):
        """
        float TwoMotionCombiner::getMotionLength() const 
                 
        gets the length of the combined motion (by default the length of the longer of the two)         
                 
                
        """
        return _Piavca_base.TwoMotionCombiner_getMotionLength(*args)

    def isFacial(*args):
        """
        bool TwoMotionCombiner::isFacial()
                 
        whether it is a face or body motion         
                 
                
        """
        return _Piavca_base.TwoMotionCombiner_isFacial(*args)

    def isRandomAccess(*args):
        """
        bool TwoMotionCombiner::isRandomAccess()
                 
        whether you can access a motions value at frames other than the current one         
                 
                
        """
        return _Piavca_base.TwoMotionCombiner_isRandomAccess(*args)

    def preFrame(*args): return _Piavca_base.TwoMotionCombiner_preFrame(*args)
    def isNull(*args):
        """
        bool TwoMotionCombiner::isNull(int trackId) const 
                 
        given a track ID tests whether it actually points to anything or if its null         
                 
        is null if the track is null in both motions.         
        """
        return _Piavca_base.TwoMotionCombiner_isNull(*args)

    def getTrackType(*args):
        """
        trackType TwoMotionCombiner::getTrackType(int trackId) const 
                 
        get the type of the track corresponding to an iterator         
                 
                
        """
        return _Piavca_base.TwoMotionCombiner_getTrackType(*args)

    def setMotion1(*args):
        """
        void TwoMotionCombiner::setMotion1(Motion *mot)
                 
                
                 
                
        """
        return _Piavca_base.TwoMotionCombiner_setMotion1(*args)

    def setMotion2(*args):
        """
        void TwoMotionCombiner::setMotion2(Motion *mot)
                 
                
                 
                
        """
        return _Piavca_base.TwoMotionCombiner_setMotion2(*args)

    def getMotion1(*args):
        """
        Motion* Piavca::TwoMotionCombiner::getMotion1()
                 
                
                 
                
        """
        return _Piavca_base.TwoMotionCombiner_getMotion1(*args)

    def getMotion2(*args):
        """
        Motion* Piavca::TwoMotionCombiner::getMotion2()
                 
                
                 
                
        """
        return _Piavca_base.TwoMotionCombiner_getMotion2(*args)

    def __disown__(self):
        self.this.disown()
        _Piavca_base.disown_TwoMotionCombiner(self)
        return weakref_proxy(self)
TwoMotionCombiner_swigregister = _Piavca_base.TwoMotionCombiner_swigregister
TwoMotionCombiner_swigregister(TwoMotionCombiner)
TwoMotionCombiner_castToThisType = _Piavca_base.TwoMotionCombiner_castToThisType

class MultiMotionCombiner(MotionFilter):
    __swig_setmethods__ = {}
    for _s in [MotionFilter]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, MultiMotionCombiner, name, value)
    __swig_getmethods__ = {}
    for _s in [MotionFilter]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, MultiMotionCombiner, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        if self.__class__ == MultiMotionCombiner:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca_base.new_MultiMotionCombiner(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca_base.delete_MultiMotionCombiner
    __del__ = lambda self : None;
    def clone(*args):
        """
        virtual Motion* Piavca::Motion::clone()=0
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca_base.MultiMotionCombiner_clone(*args)

    def getClassName(*args): return _Piavca_base.MultiMotionCombiner_getClassName(*args)
    __swig_getmethods__["castToThisType"] = lambda x: _Piavca_base.MultiMotionCombiner_castToThisType
    if _newclass:castToThisType = staticmethod(_Piavca_base.MultiMotionCombiner_castToThisType)
    def printInfo(*args):
        """
        void Piavca::MotionFilter::printInfo()
                 
        prints out info about the motion heirarchy         
                 
                
        """
        return _Piavca_base.MultiMotionCombiner_printInfo(*args)

    def addMotion(*args): return _Piavca_base.MultiMotionCombiner_addMotion(*args)
    def getMotionIndex(*args): return _Piavca_base.MultiMotionCombiner_getMotionIndex(*args)
    def getNumMotions(*args): return _Piavca_base.MultiMotionCombiner_getNumMotions(*args)
    def getMotionByIndex(*args): return _Piavca_base.MultiMotionCombiner_getMotionByIndex(*args)
    def getMotion(*args): return _Piavca_base.MultiMotionCombiner_getMotion(*args)
    def removeMotionByIndex(*args): return _Piavca_base.MultiMotionCombiner_removeMotionByIndex(*args)
    def clear(*args): return _Piavca_base.MultiMotionCombiner_clear(*args)
    def findSub(*args):
        """
        virtual Motion* Piavca::MotionFilter::findSub(tstring nm)
                 
        finds the first submotion with a given name         
                 
                
        """
        return _Piavca_base.MultiMotionCombiner_findSub(*args)

    def findSubByType(*args):
        """
        virtual Motion* Piavca::MotionFilter::findSubByType(const type_info &ty)
                 
        finds the first submotion with a given type         
                 
                
        """
        return _Piavca_base.MultiMotionCombiner_findSubByType(*args)

    def load(*args):
        """
        virtual void Piavca::MotionFilter::load(Avatar *av)
                 
        called when the motion is loaded into an avatar         
                 
                
        """
        return _Piavca_base.MultiMotionCombiner_load(*args)

    def unload(*args):
        """
        virtual void Piavca::MotionFilter::unload()
                 
        called when the motion is unloaded from an avatar         
                 
                
        """
        return _Piavca_base.MultiMotionCombiner_unload(*args)

    def loaded(*args):
        """
        virtual bool Piavca::MotionFilter::loaded()
                 
        checks if the motion has been loaded into an avatar         
                 
                
        """
        return _Piavca_base.MultiMotionCombiner_loaded(*args)

    def getAvatar(*args): return _Piavca_base.MultiMotionCombiner_getAvatar(*args)
    def event(*args): return _Piavca_base.MultiMotionCombiner_event(*args)
    def cleanRecursionState(*args): return _Piavca_base.MultiMotionCombiner_cleanRecursionState(*args)
    def __disown__(self):
        self.this.disown()
        _Piavca_base.disown_MultiMotionCombiner(self)
        return weakref_proxy(self)
MultiMotionCombiner_swigregister = _Piavca_base.MultiMotionCombiner_swigregister
MultiMotionCombiner_swigregister(MultiMotionCombiner)
MultiMotionCombiner_castToThisType = _Piavca_base.MultiMotionCombiner_castToThisType

class MotionMask(_object):
    """
    a set of masks specifying which joints should be played in a masked motion     
           
         see also: MaskedMotion.h
    """
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, MotionMask, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, MotionMask, name)
    def __init__(self, *args): 
        """
        MotionMask::MotionMask(const MotionMask &mm)
                 
                
                 
                
        """
        this = _Piavca_base.new_MotionMask(*args)
        try: self.this.append(this)
        except: self.this = this
    def setMask(*args):
        """
        void MotionMask::setMask(int track, bool val=true)
                 
        sets whether a given track should be played         
                 
                
        """
        return _Piavca_base.MotionMask_setMask(*args)

    def setAllMask(*args): return _Piavca_base.MotionMask_setAllMask(*args)
    def getMask(*args):
        """
        bool MotionMask::getMask(int track) const 
                 
        gets the mask value for a track         
                 
                
        """
        return _Piavca_base.MotionMask_getMask(*args)

    def clearMask(*args): return _Piavca_base.MotionMask_clearMask(*args)
    def __repr__(*args): return _Piavca_base.MotionMask___repr__(*args)
    __swig_destroy__ = _Piavca_base.delete_MotionMask
    __del__ = lambda self : None;
MotionMask_swigregister = _Piavca_base.MotionMask_swigregister
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
        this = _Piavca_base.new_MaskedMotion(*args)
        try: self.this.append(this)
        except: self.this = this
    def isNull(*args):
        """
        virtual bool Piavca::MotionFilter::isNull(int trackId) const 
                 
        given an iterator tests whether it actually points to anything or if its null         
                 
                
        """
        return _Piavca_base.MaskedMotion_isNull(*args)

    def clone(*args):
        """
        virtual Motion* Piavca::MaskedMotion::clone()
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca_base.MaskedMotion_clone(*args)

    def getClassName(*args): return _Piavca_base.MaskedMotion_getClassName(*args)
    __swig_getmethods__["castToThisType"] = lambda x: _Piavca_base.MaskedMotion_castToThisType
    if _newclass:castToThisType = staticmethod(_Piavca_base.MaskedMotion_castToThisType)
    def setMask(*args): return _Piavca_base.MaskedMotion_setMask(*args)
    def getMask(*args): return _Piavca_base.MaskedMotion_getMask(*args)
    def addToMask(*args): return _Piavca_base.MaskedMotion_addToMask(*args)
    def removeFromMask(*args): return _Piavca_base.MaskedMotion_removeFromMask(*args)
    def addAllToMask(*args): return _Piavca_base.MaskedMotion_addAllToMask(*args)
    def removeAllFromMask(*args): return _Piavca_base.MaskedMotion_removeAllFromMask(*args)
    def getFloatValueAtTimeInternal(*args):
        """
        float MaskedMotion::getFloatValueAtTimeInternal(int trackId, float time)
                 
        internal version of getFloatValueAtTime, to be overridden         
                 
                
        """
        return _Piavca_base.MaskedMotion_getFloatValueAtTimeInternal(*args)

    def getVecValueAtTimeInternal(*args):
        """
        Vec MaskedMotion::getVecValueAtTimeInternal(int trackId, float time)
                 
        internal version of getVecValueAtTime, to be overridden         
                 
                
        """
        return _Piavca_base.MaskedMotion_getVecValueAtTimeInternal(*args)

    def getQuatValueAtTimeInternal(*args):
        """
        Quat MaskedMotion::getQuatValueAtTimeInternal(int trackId, float time)
                 
        internal version of getQuatValueAtTime, to be overridden         
                 
                
        """
        return _Piavca_base.MaskedMotion_getQuatValueAtTimeInternal(*args)

    __swig_destroy__ = _Piavca_base.delete_MaskedMotion
    __del__ = lambda self : None;
    def __disown__(self):
        self.this.disown()
        _Piavca_base.disown_MaskedMotion(self)
        return weakref_proxy(self)
MaskedMotion_swigregister = _Piavca_base.MaskedMotion_swigregister
MaskedMotion_swigregister(MaskedMotion)
MaskedMotion_castToThisType = _Piavca_base.MaskedMotion_castToThisType

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
        this = _Piavca_base.new_ScaleMotion(*args)
        try: self.this.append(this)
        except: self.this = this
    def clone(*args):
        """
        virtual Motion* Piavca::ScaleMotion::clone()
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca_base.ScaleMotion_clone(*args)

    def getClassName(*args): return _Piavca_base.ScaleMotion_getClassName(*args)
    __swig_getmethods__["castToThisType"] = lambda x: _Piavca_base.ScaleMotion_castToThisType
    if _newclass:castToThisType = staticmethod(_Piavca_base.ScaleMotion_castToThisType)
    def getFloatValueAtTimeInternal(*args):
        """
        virtual PIAVCA_EXPORT float Piavca::ScaleMotion::getFloatValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe         
                 
                
        """
        return _Piavca_base.ScaleMotion_getFloatValueAtTimeInternal(*args)

    def getVecValueAtTimeInternal(*args):
        """
        virtual PIAVCA_EXPORT Vec Piavca::ScaleMotion::getVecValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe         
                 
                
        """
        return _Piavca_base.ScaleMotion_getVecValueAtTimeInternal(*args)

    def getQuatValueAtTimeInternal(*args):
        """
        virtual PIAVCA_EXPORT Quat Piavca::ScaleMotion::getQuatValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe         
                 
                
        """
        return _Piavca_base.ScaleMotion_getQuatValueAtTimeInternal(*args)

    def setScaleFactor(*args):
        """
        void Piavca::ScaleMotion::setScaleFactor(float scale)
                 
        Sets the scale factor for the postion components of the motion.         
                 
                
        """
        return _Piavca_base.ScaleMotion_setScaleFactor(*args)

    def getScaleFactor(*args): return _Piavca_base.ScaleMotion_getScaleFactor(*args)
    __swig_destroy__ = _Piavca_base.delete_ScaleMotion
    __del__ = lambda self : None;
    def __disown__(self):
        self.this.disown()
        _Piavca_base.disown_ScaleMotion(self)
        return weakref_proxy(self)
ScaleMotion_swigregister = _Piavca_base.ScaleMotion_swigregister
ScaleMotion_swigregister(ScaleMotion)
ScaleMotion_castToThisType = _Piavca_base.ScaleMotion_castToThisType

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
        this = _Piavca_base.new_ScaleMotionSpeed(*args)
        try: self.this.append(this)
        except: self.this = this
    def clone(*args):
        """
        virtual Motion* Piavca::ScaleMotionSpeed::clone()
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca_base.ScaleMotionSpeed_clone(*args)

    def getClassName(*args): return _Piavca_base.ScaleMotionSpeed_getClassName(*args)
    __swig_getmethods__["castToThisType"] = lambda x: _Piavca_base.ScaleMotionSpeed_castToThisType
    if _newclass:castToThisType = staticmethod(_Piavca_base.ScaleMotionSpeed_castToThisType)
    def getMotionLength(*args):
        """
        virtual float Piavca::ScaleMotionSpeed::getMotionLength() const 
                 
        gets the length of the motion in seconds         
                 
                
        """
        return _Piavca_base.ScaleMotionSpeed_getMotionLength(*args)

    def getFloatValueAtTimeInternal(*args):
        """
        virtual PIAVCA_EXPORT float Piavca::ScaleMotionSpeed::getFloatValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe         
                 
                
        """
        return _Piavca_base.ScaleMotionSpeed_getFloatValueAtTimeInternal(*args)

    def getVecValueAtTimeInternal(*args):
        """
        virtual PIAVCA_EXPORT Vec Piavca::ScaleMotionSpeed::getVecValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe         
                 
                
        """
        return _Piavca_base.ScaleMotionSpeed_getVecValueAtTimeInternal(*args)

    def getQuatValueAtTimeInternal(*args):
        """
        virtual PIAVCA_EXPORT Quat Piavca::ScaleMotionSpeed::getQuatValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe         
                 
                
        """
        return _Piavca_base.ScaleMotionSpeed_getQuatValueAtTimeInternal(*args)

    def setScaleFactor(*args):
        """
        void Piavca::ScaleMotionSpeed::setScaleFactor(float scale)
                 
        Sets the scale factor for the postion components of the motion.         
                 
                
        """
        return _Piavca_base.ScaleMotionSpeed_setScaleFactor(*args)

    def getScaleFactor(*args): return _Piavca_base.ScaleMotionSpeed_getScaleFactor(*args)
    __swig_destroy__ = _Piavca_base.delete_ScaleMotionSpeed
    __del__ = lambda self : None;
    def __disown__(self):
        self.this.disown()
        _Piavca_base.disown_ScaleMotionSpeed(self)
        return weakref_proxy(self)
ScaleMotionSpeed_swigregister = _Piavca_base.ScaleMotionSpeed_swigregister
ScaleMotionSpeed_swigregister(ScaleMotionSpeed)
ScaleMotionSpeed_castToThisType = _Piavca_base.ScaleMotionSpeed_castToThisType

class ChangeMotionLength(ScaleMotionSpeed):
    """
    see also: ChangeMotionLength.h
    """
    __swig_setmethods__ = {}
    for _s in [ScaleMotionSpeed]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, ChangeMotionLength, name, value)
    __swig_getmethods__ = {}
    for _s in [ScaleMotionSpeed]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, ChangeMotionLength, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        """
        Piavca::ChangeMotionLength::ChangeMotionLength(const ChangeMotionLength &cml)
                 
                
                 
                
        """
        if self.__class__ == ChangeMotionLength:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca_base.new_ChangeMotionLength(*args)
        try: self.this.append(this)
        except: self.this = this
    def clone(*args):
        """
        virtual Motion* Piavca::ChangeMotionLength::clone()
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca_base.ChangeMotionLength_clone(*args)

    def getClassName(*args): return _Piavca_base.ChangeMotionLength_getClassName(*args)
    __swig_getmethods__["castToThisType"] = lambda x: _Piavca_base.ChangeMotionLength_castToThisType
    if _newclass:castToThisType = staticmethod(_Piavca_base.ChangeMotionLength_castToThisType)
    def setLength(*args): return _Piavca_base.ChangeMotionLength_setLength(*args)
    def getLength(*args): return _Piavca_base.ChangeMotionLength_getLength(*args)
    def getMotionLength(*args):
        """
        virtual float Piavca::ChangeMotionLength::getMotionLength() const 
                 
        gets the length of the motion in seconds         
                 
                
        """
        return _Piavca_base.ChangeMotionLength_getMotionLength(*args)

    def setMotion(*args):
        """
        virtual void Piavca::ChangeMotionLength::setMotion(Motion *mot)
                 
                
                 
                
        """
        return _Piavca_base.ChangeMotionLength_setMotion(*args)

    __swig_destroy__ = _Piavca_base.delete_ChangeMotionLength
    __del__ = lambda self : None;
    def __disown__(self):
        self.this.disown()
        _Piavca_base.disown_ChangeMotionLength(self)
        return weakref_proxy(self)
ChangeMotionLength_swigregister = _Piavca_base.ChangeMotionLength_swigregister
ChangeMotionLength_swigregister(ChangeMotionLength)
ChangeMotionLength_castToThisType = _Piavca_base.ChangeMotionLength_castToThisType

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
        this = _Piavca_base.new_ScaleMotionRoot(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca_base.delete_ScaleMotionRoot
    __del__ = lambda self : None;
    def clone(*args):
        """
        virtual Motion* Piavca::ScaleMotionRoot::clone()
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca_base.ScaleMotionRoot_clone(*args)

    def getClassName(*args): return _Piavca_base.ScaleMotionRoot_getClassName(*args)
    __swig_getmethods__["castToThisType"] = lambda x: _Piavca_base.ScaleMotionRoot_castToThisType
    if _newclass:castToThisType = staticmethod(_Piavca_base.ScaleMotionRoot_castToThisType)
    def getFloatValueAtTimeInternal(*args):
        """
        virtual PIAVCA_EXPORT float Piavca::ScaleMotionRoot::getFloatValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe         
                 
                
        """
        return _Piavca_base.ScaleMotionRoot_getFloatValueAtTimeInternal(*args)

    def getVecValueAtTimeInternal(*args):
        """
        virtual PIAVCA_EXPORT Vec Piavca::ScaleMotionRoot::getVecValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe (vec values are scaled)         
                 
                
        """
        return _Piavca_base.ScaleMotionRoot_getVecValueAtTimeInternal(*args)

    def getQuatValueAtTimeInternal(*args):
        """
        virtual PIAVCA_EXPORT Quat Piavca::ScaleMotionRoot::getQuatValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe         
                 
                
        """
        return _Piavca_base.ScaleMotionRoot_getQuatValueAtTimeInternal(*args)

    def setScaleFactor(*args):
        """
        void Piavca::ScaleMotionRoot::setScaleFactor(float scale)
                 
        Sets the scale factor for the postion components of the motion.         
                 
                
        """
        return _Piavca_base.ScaleMotionRoot_setScaleFactor(*args)

    def getScaleFactor(*args): return _Piavca_base.ScaleMotionRoot_getScaleFactor(*args)
    def __disown__(self):
        self.this.disown()
        _Piavca_base.disown_ScaleMotionRoot(self)
        return weakref_proxy(self)
ScaleMotionRoot_swigregister = _Piavca_base.ScaleMotionRoot_swigregister
ScaleMotionRoot_swigregister(ScaleMotionRoot)
ScaleMotionRoot_castToThisType = _Piavca_base.ScaleMotionRoot_castToThisType

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
        this = _Piavca_base.new_TimeOffset(*args)
        try: self.this.append(this)
        except: self.this = this
    def clone(*args):
        """
        virtual Motion* Piavca::TimeOffset::clone()
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca_base.TimeOffset_clone(*args)

    def getClassName(*args): return _Piavca_base.TimeOffset_getClassName(*args)
    __swig_getmethods__["castToThisType"] = lambda x: _Piavca_base.TimeOffset_castToThisType
    if _newclass:castToThisType = staticmethod(_Piavca_base.TimeOffset_castToThisType)
    def setStartTime(*args):
        """
        virtual void Piavca::TimeOffset::setStartTime(float time)
                 
        sets the start time of the motion. Called when its loaded into an avatar.         
                 
                
        """
        return _Piavca_base.TimeOffset_setStartTime(*args)

    def getFloatValueAtTimeInternal(*args):
        """
        virtual PIAVCA_EXPORT float Piavca::TimeOffset::getFloatValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe         
                 
                
        """
        return _Piavca_base.TimeOffset_getFloatValueAtTimeInternal(*args)

    def getVecValueAtTimeInternal(*args):
        """
        virtual PIAVCA_EXPORT Vec Piavca::TimeOffset::getVecValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe (vec values are scaled)         
                 
                
        """
        return _Piavca_base.TimeOffset_getVecValueAtTimeInternal(*args)

    def getQuatValueAtTimeInternal(*args):
        """
        virtual PIAVCA_EXPORT Quat Piavca::TimeOffset::getQuatValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe         
                 
                
        """
        return _Piavca_base.TimeOffset_getQuatValueAtTimeInternal(*args)

    def setOffset(*args):
        """
        void Piavca::TimeOffset::setOffset(float offs)
                 
        Sets the scale factor for the postion components of the motion.         
                 
                
        """
        return _Piavca_base.TimeOffset_setOffset(*args)

    def getOffset(*args): return _Piavca_base.TimeOffset_getOffset(*args)
    __swig_destroy__ = _Piavca_base.delete_TimeOffset
    __del__ = lambda self : None;
    def __disown__(self):
        self.this.disown()
        _Piavca_base.disown_TimeOffset(self)
        return weakref_proxy(self)
TimeOffset_swigregister = _Piavca_base.TimeOffset_swigregister
TimeOffset_swigregister(TimeOffset)
TimeOffset_castToThisType = _Piavca_base.TimeOffset_castToThisType

class Sequence(TwoMotionCombiner):
    __swig_setmethods__ = {}
    for _s in [TwoMotionCombiner]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, Sequence, name, value)
    __swig_getmethods__ = {}
    for _s in [TwoMotionCombiner]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, Sequence, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        if self.__class__ == Sequence:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca_base.new_Sequence(*args)
        try: self.this.append(this)
        except: self.this = this
    def clone(*args):
        """
        virtual Motion* Piavca::Motion::clone()=0
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca_base.Sequence_clone(*args)

    def getClassName(*args): return _Piavca_base.Sequence_getClassName(*args)
    __swig_getmethods__["castToThisType"] = lambda x: _Piavca_base.Sequence_castToThisType
    if _newclass:castToThisType = staticmethod(_Piavca_base.Sequence_castToThisType)
    def setStartTime(*args):
        """
        void TwoMotionCombiner::setStartTime(float time)
                 
        sets the start time of the motion. Called when its loaded into an avatar.         
                 
                
        """
        return _Piavca_base.Sequence_setStartTime(*args)

    def getMotionLength(*args):
        """
        float TwoMotionCombiner::getMotionLength() const 
                 
        gets the length of the combined motion (by default the length of the longer of the two)         
                 
                
        """
        return _Piavca_base.Sequence_getMotionLength(*args)

    def getFloatValueAtTimeInternal(*args):
        """
        virtual float Piavca::Motion::getFloatValueAtTimeInternal(int trackId, float time)=0
                 
        internal version of getFloatValueAtTime, to be overridden         
                 
                
        """
        return _Piavca_base.Sequence_getFloatValueAtTimeInternal(*args)

    def getVecValueAtTimeInternal(*args):
        """
        virtual Vec Piavca::Motion::getVecValueAtTimeInternal(int trackId, float time)=0
                 
        internal version of getVecValueAtTime, to be overridden         
                 
                
        """
        return _Piavca_base.Sequence_getVecValueAtTimeInternal(*args)

    def getQuatValueAtTimeInternal(*args):
        """
        virtual Quat Piavca::Motion::getQuatValueAtTimeInternal(int trackId, float time)=0
                 
        internal version of getQuatValueAtTime, to be overridden         
                 
                
        """
        return _Piavca_base.Sequence_getQuatValueAtTimeInternal(*args)

    __swig_destroy__ = _Piavca_base.delete_Sequence
    __del__ = lambda self : None;
    def __disown__(self):
        self.this.disown()
        _Piavca_base.disown_Sequence(self)
        return weakref_proxy(self)
Sequence_swigregister = _Piavca_base.Sequence_swigregister
Sequence_swigregister(Sequence)
Sequence_castToThisType = _Piavca_base.Sequence_castToThisType

class SmoothSequence(Sequence):
    __swig_setmethods__ = {}
    for _s in [Sequence]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, SmoothSequence, name, value)
    __swig_getmethods__ = {}
    for _s in [Sequence]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, SmoothSequence, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _Piavca_base.new_SmoothSequence(*args)
        try: self.this.append(this)
        except: self.this = this
    def clone(*args):
        """
        virtual Motion* Piavca::Motion::clone()=0
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca_base.SmoothSequence_clone(*args)

    def getClassName(*args): return _Piavca_base.SmoothSequence_getClassName(*args)
    __swig_getmethods__["castToThisType"] = lambda x: _Piavca_base.SmoothSequence_castToThisType
    if _newclass:castToThisType = staticmethod(_Piavca_base.SmoothSequence_castToThisType)
    def create(*args): return _Piavca_base.SmoothSequence_create(*args)
    def setMaintainY(*args): return _Piavca_base.SmoothSequence_setMaintainY(*args)
    def setAccumulateRoot(*args): return _Piavca_base.SmoothSequence_setAccumulateRoot(*args)
    def setMotion1(*args):
        """
        void TwoMotionCombiner::setMotion1(Motion *mot)
                 
                
                 
                
        """
        return _Piavca_base.SmoothSequence_setMotion1(*args)

    def setMotion2(*args):
        """
        void TwoMotionCombiner::setMotion2(Motion *mot)
                 
                
                 
                
        """
        return _Piavca_base.SmoothSequence_setMotion2(*args)

    def setBlendStart(*args): return _Piavca_base.SmoothSequence_setBlendStart(*args)
    def setBlendInterval(*args): return _Piavca_base.SmoothSequence_setBlendInterval(*args)
    def getBlendStart(*args): return _Piavca_base.SmoothSequence_getBlendStart(*args)
    def getBlendInterval(*args): return _Piavca_base.SmoothSequence_getBlendInterval(*args)
    __swig_destroy__ = _Piavca_base.delete_SmoothSequence
    __del__ = lambda self : None;
SmoothSequence_swigregister = _Piavca_base.SmoothSequence_swigregister
SmoothSequence_swigregister(SmoothSequence)
SmoothSequence_castToThisType = _Piavca_base.SmoothSequence_castToThisType

class MotionPosture(KeyframeMotion):
    __swig_setmethods__ = {}
    for _s in [KeyframeMotion]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, MotionPosture, name, value)
    __swig_getmethods__ = {}
    for _s in [KeyframeMotion]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, MotionPosture, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        if self.__class__ == MotionPosture:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca_base.new_MotionPosture(*args)
        try: self.this.append(this)
        except: self.this = this
    def clone(*args):
        """
        virtual Motion* Piavca::Motion::clone()=0
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca_base.MotionPosture_clone(*args)

    def getClassName(*args): return _Piavca_base.MotionPosture_getClassName(*args)
    __swig_getmethods__["castToThisType"] = lambda x: _Piavca_base.MotionPosture_castToThisType
    if _newclass:castToThisType = staticmethod(_Piavca_base.MotionPosture_castToThisType)
    def getPostureFromMotion(*args): return _Piavca_base.MotionPosture_getPostureFromMotion(*args)
    __swig_destroy__ = _Piavca_base.delete_MotionPosture
    __del__ = lambda self : None;
    def __disown__(self):
        self.this.disown()
        _Piavca_base.disown_MotionPosture(self)
        return weakref_proxy(self)
MotionPosture_swigregister = _Piavca_base.MotionPosture_swigregister
MotionPosture_swigregister(MotionPosture)
MotionPosture_castToThisType = _Piavca_base.MotionPosture_castToThisType

class AvatarPosture(KeyframeMotion):
    __swig_setmethods__ = {}
    for _s in [KeyframeMotion]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, AvatarPosture, name, value)
    __swig_getmethods__ = {}
    for _s in [KeyframeMotion]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, AvatarPosture, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        if self.__class__ == AvatarPosture:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca_base.new_AvatarPosture(*args)
        try: self.this.append(this)
        except: self.this = this
    def clone(*args):
        """
        virtual Motion* Piavca::Motion::clone()=0
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca_base.AvatarPosture_clone(*args)

    def getClassName(*args): return _Piavca_base.AvatarPosture_getClassName(*args)
    __swig_getmethods__["castToThisType"] = lambda x: _Piavca_base.AvatarPosture_castToThisType
    if _newclass:castToThisType = staticmethod(_Piavca_base.AvatarPosture_castToThisType)
    def load(*args):
        """
        virtual void Piavca::Motion::load(Avatar *av)
                 
        called when the motion is loaded into an avatar         
                 
                
        """
        return _Piavca_base.AvatarPosture_load(*args)

    def getPostureFromAvatar(*args): return _Piavca_base.AvatarPosture_getPostureFromAvatar(*args)
    __swig_destroy__ = _Piavca_base.delete_AvatarPosture
    __del__ = lambda self : None;
    def __disown__(self):
        self.this.disown()
        _Piavca_base.disown_AvatarPosture(self)
        return weakref_proxy(self)
AvatarPosture_swigregister = _Piavca_base.AvatarPosture_swigregister
AvatarPosture_swigregister(AvatarPosture)
AvatarPosture_castToThisType = _Piavca_base.AvatarPosture_castToThisType

class PostureBlend(Sequence):
    __swig_setmethods__ = {}
    for _s in [Sequence]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, PostureBlend, name, value)
    __swig_getmethods__ = {}
    for _s in [Sequence]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, PostureBlend, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        if self.__class__ == PostureBlend:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca_base.new_PostureBlend(*args)
        try: self.this.append(this)
        except: self.this = this
    def clone(*args):
        """
        virtual Motion* Piavca::Motion::clone()=0
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca_base.PostureBlend_clone(*args)

    def getClassName(*args): return _Piavca_base.PostureBlend_getClassName(*args)
    __swig_getmethods__["castToThisType"] = lambda x: _Piavca_base.PostureBlend_castToThisType
    if _newclass:castToThisType = staticmethod(_Piavca_base.PostureBlend_castToThisType)
    def setBlendInterval(*args): return _Piavca_base.PostureBlend_setBlendInterval(*args)
    def getBlendInterval(*args): return _Piavca_base.PostureBlend_getBlendInterval(*args)
    def setAccumulateRoot(*args): return _Piavca_base.PostureBlend_setAccumulateRoot(*args)
    def getAccumulateRoot(*args): return _Piavca_base.PostureBlend_getAccumulateRoot(*args)
    def reset(*args):
        """
        void TwoMotionCombiner::reset()
                 
        does any resetting needed         
                 
                
        """
        return _Piavca_base.PostureBlend_reset(*args)

    def reblend(*args): return _Piavca_base.PostureBlend_reblend(*args)
    def setMotion(*args): return _Piavca_base.PostureBlend_setMotion(*args)
    def getMotion(*args): return _Piavca_base.PostureBlend_getMotion(*args)
    __swig_destroy__ = _Piavca_base.delete_PostureBlend
    __del__ = lambda self : None;
    def __disown__(self):
        self.this.disown()
        _Piavca_base.disown_PostureBlend(self)
        return weakref_proxy(self)
PostureBlend_swigregister = _Piavca_base.PostureBlend_swigregister
PostureBlend_swigregister(PostureBlend)
PostureBlend_castToThisType = _Piavca_base.PostureBlend_castToThisType

class Reposition(MotionFilter):
    __swig_setmethods__ = {}
    for _s in [MotionFilter]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, Reposition, name, value)
    __swig_getmethods__ = {}
    for _s in [MotionFilter]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, Reposition, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        if self.__class__ == Reposition:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca_base.new_Reposition(*args)
        try: self.this.append(this)
        except: self.this = this
    def clone(*args):
        """
        virtual Motion* Piavca::Motion::clone()=0
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca_base.Reposition_clone(*args)

    def getClassName(*args): return _Piavca_base.Reposition_getClassName(*args)
    __swig_getmethods__["castToThisType"] = lambda x: _Piavca_base.Reposition_castToThisType
    if _newclass:castToThisType = staticmethod(_Piavca_base.Reposition_castToThisType)
    def setStartPosition(*args): return _Piavca_base.Reposition_setStartPosition(*args)
    def setStartOrientation(*args): return _Piavca_base.Reposition_setStartOrientation(*args)
    def setPosOffset(*args): return _Piavca_base.Reposition_setPosOffset(*args)
    def getPosOffset(*args): return _Piavca_base.Reposition_getPosOffset(*args)
    def getStartPosition(*args): return _Piavca_base.Reposition_getStartPosition(*args)
    def getStartOrientation(*args): return _Piavca_base.Reposition_getStartOrientation(*args)
    def setStartFromMotion(*args): return _Piavca_base.Reposition_setStartFromMotion(*args)
    def setMotion(*args):
        """
        void Piavca::MotionFilter::setMotion(Motion *mot)
                 
                
                 
                
        """
        return _Piavca_base.Reposition_setMotion(*args)

    def setMaintainY(*args): return _Piavca_base.Reposition_setMaintainY(*args)
    def setMaintainUp(*args): return _Piavca_base.Reposition_setMaintainUp(*args)
    def getMaintainUp(*args): return _Piavca_base.Reposition_getMaintainUp(*args)
    def setRotateAboutUp(*args): return _Piavca_base.Reposition_setRotateAboutUp(*args)
    def getRotateAboutUp(*args): return _Piavca_base.Reposition_getRotateAboutUp(*args)
    def setUpDirection(*args): return _Piavca_base.Reposition_setUpDirection(*args)
    def getUpDirection(*args): return _Piavca_base.Reposition_getUpDirection(*args)
    def isNull(*args):
        """
        virtual bool Piavca::MotionFilter::isNull(int trackId) const 
                 
        given an iterator tests whether it actually points to anything or if its null         
                 
                
        """
        return _Piavca_base.Reposition_isNull(*args)

    def getTrackType(*args):
        """
        trackType Piavca::MotionFilter::getTrackType(int trackId) const 
                 
        get the type of the track corresponding to an iterator         
                 
                
        """
        return _Piavca_base.Reposition_getTrackType(*args)

    def getFloatValueAtTimeInternal(*args):
        """
        virtual float Piavca::Motion::getFloatValueAtTimeInternal(int trackId, float time)=0
                 
        internal version of getFloatValueAtTime, to be overridden         
                 
                
        """
        return _Piavca_base.Reposition_getFloatValueAtTimeInternal(*args)

    def getVecValueAtTimeInternal(*args):
        """
        virtual Vec Piavca::Motion::getVecValueAtTimeInternal(int trackId, float time)=0
                 
        internal version of getVecValueAtTime, to be overridden         
                 
                
        """
        return _Piavca_base.Reposition_getVecValueAtTimeInternal(*args)

    def getQuatValueAtTimeInternal(*args):
        """
        virtual Quat Piavca::Motion::getQuatValueAtTimeInternal(int trackId, float time)=0
                 
        internal version of getQuatValueAtTime, to be overridden         
                 
                
        """
        return _Piavca_base.Reposition_getQuatValueAtTimeInternal(*args)

    __swig_destroy__ = _Piavca_base.delete_Reposition
    __del__ = lambda self : None;
    def __disown__(self):
        self.this.disown()
        _Piavca_base.disown_Reposition(self)
        return weakref_proxy(self)
Reposition_swigregister = _Piavca_base.Reposition_swigregister
Reposition_swigregister(Reposition)
Reposition_castToThisType = _Piavca_base.Reposition_castToThisType

class LoopMotion(MotionFilter):
    """
    a motion filter that makes a motion loop continuously     
           
         see also: LoopMotion.h
    """
    __swig_setmethods__ = {}
    for _s in [MotionFilter]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, LoopMotion, name, value)
    __swig_getmethods__ = {}
    for _s in [MotionFilter]: __swig_getmethods__.update(_s.__swig_getmethods__)
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
        this = _Piavca_base.new_LoopMotion(*args)
        try: self.this.append(this)
        except: self.this = this
    def clone(*args):
        """
        virtual Motion* Piavca::LoopMotion::clone()
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca_base.LoopMotion_clone(*args)

    def getClassName(*args): return _Piavca_base.LoopMotion_getClassName(*args)
    __swig_getmethods__["castToThisType"] = lambda x: _Piavca_base.LoopMotion_castToThisType
    if _newclass:castToThisType = staticmethod(_Piavca_base.LoopMotion_castToThisType)
    def getMotionLength(*args):
        """
        virtual float Piavca::LoopMotion::getMotionLength() const 
                 
        gets the motion length (transition start + blend interval + length of second motion)         
                 
                
        """
        return _Piavca_base.LoopMotion_getMotionLength(*args)

    def setEndTime(*args):
        """
        void Piavca::LoopMotion::setEndTime(float t)
                 
                
                 
                
        """
        return _Piavca_base.LoopMotion_setEndTime(*args)

    def preFrame(*args): return _Piavca_base.LoopMotion_preFrame(*args)
    def reset(*args):
        """
        void Piavca::MotionFilter::reset()
                 
        does any resetting needed         
                 
                
        """
        return _Piavca_base.LoopMotion_reset(*args)

    __swig_destroy__ = _Piavca_base.delete_LoopMotion
    __del__ = lambda self : None;
    def __disown__(self):
        self.this.disown()
        _Piavca_base.disown_LoopMotion(self)
        return weakref_proxy(self)
LoopMotion_swigregister = _Piavca_base.LoopMotion_swigregister
LoopMotion_swigregister(LoopMotion)
LoopMotion_castToThisType = _Piavca_base.LoopMotion_castToThisType

class SmoothLoop(LoopMotion):
    __swig_setmethods__ = {}
    for _s in [LoopMotion]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, SmoothLoop, name, value)
    __swig_getmethods__ = {}
    for _s in [LoopMotion]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, SmoothLoop, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _Piavca_base.new_SmoothLoop(*args)
        try: self.this.append(this)
        except: self.this = this
    def clone(*args):
        """
        virtual Motion* Piavca::LoopMotion::clone()
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca_base.SmoothLoop_clone(*args)

    def getClassName(*args): return _Piavca_base.SmoothLoop_getClassName(*args)
    __swig_getmethods__["castToThisType"] = lambda x: _Piavca_base.SmoothLoop_castToThisType
    if _newclass:castToThisType = staticmethod(_Piavca_base.SmoothLoop_castToThisType)
    def setMotion(*args):
        """
        void Piavca::MotionFilter::setMotion(Motion *mot)
                 
                
                 
                
        """
        return _Piavca_base.SmoothLoop_setMotion(*args)

    def getMotion(*args): return _Piavca_base.SmoothLoop_getMotion(*args)
    def setAccumulateRoot(*args): return _Piavca_base.SmoothLoop_setAccumulateRoot(*args)
    def getAccumulateRoot(*args): return _Piavca_base.SmoothLoop_getAccumulateRoot(*args)
    def setBlendInterval(*args): return _Piavca_base.SmoothLoop_setBlendInterval(*args)
    def getBlendInterval(*args): return _Piavca_base.SmoothLoop_getBlendInterval(*args)
    __swig_destroy__ = _Piavca_base.delete_SmoothLoop
    __del__ = lambda self : None;
SmoothLoop_swigregister = _Piavca_base.SmoothLoop_swigregister
SmoothLoop_swigregister(SmoothLoop)
SmoothLoop_castToThisType = _Piavca_base.SmoothLoop_castToThisType

class RandomTimingsMotion(ScaleMotionSpeed):
    __swig_setmethods__ = {}
    for _s in [ScaleMotionSpeed]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, RandomTimingsMotion, name, value)
    __swig_getmethods__ = {}
    for _s in [ScaleMotionSpeed]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, RandomTimingsMotion, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        if self.__class__ == RandomTimingsMotion:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca_base.new_RandomTimingsMotion(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca_base.delete_RandomTimingsMotion
    __del__ = lambda self : None;
    def clone(*args):
        """
        virtual Motion* Piavca::ScaleMotionSpeed::clone()
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca_base.RandomTimingsMotion_clone(*args)

    def getClassName(*args): return _Piavca_base.RandomTimingsMotion_getClassName(*args)
    __swig_getmethods__["castToThisType"] = lambda x: _Piavca_base.RandomTimingsMotion_castToThisType
    if _newclass:castToThisType = staticmethod(_Piavca_base.RandomTimingsMotion_castToThisType)
    def setTimingParams(*args): return _Piavca_base.RandomTimingsMotion_setTimingParams(*args)
    def setMinTimeScale(*args): return _Piavca_base.RandomTimingsMotion_setMinTimeScale(*args)
    def getMinTimeScale(*args): return _Piavca_base.RandomTimingsMotion_getMinTimeScale(*args)
    def setMaxTimeScale(*args): return _Piavca_base.RandomTimingsMotion_setMaxTimeScale(*args)
    def getMaxTimeScale(*args): return _Piavca_base.RandomTimingsMotion_getMaxTimeScale(*args)
    def reset(*args):
        """
        void Piavca::MotionFilter::reset()
                 
        does any resetting needed         
                 
                
        """
        return _Piavca_base.RandomTimingsMotion_reset(*args)

    def __disown__(self):
        self.this.disown()
        _Piavca_base.disown_RandomTimingsMotion(self)
        return weakref_proxy(self)
RandomTimingsMotion_swigregister = _Piavca_base.RandomTimingsMotion_swigregister
RandomTimingsMotion_swigregister(RandomTimingsMotion)
RandomTimingsMotion_castToThisType = _Piavca_base.RandomTimingsMotion_castToThisType

class AvatarPostureBlend(Sequence):
    """
    A motion blend operator that blends a motion into the current position of an avatar.     
           
    This class will blend smoothly from the current postion of an avatar to the motion and will have the motion start at the current position and orientation of the avatar rather than its own start point (see SequentialBlend docs for some details)      see also: AvatarPostureBlend.h
    """
    __swig_setmethods__ = {}
    for _s in [Sequence]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, AvatarPostureBlend, name, value)
    __swig_getmethods__ = {}
    for _s in [Sequence]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, AvatarPostureBlend, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        """
        Piavca::AvatarPostureBlend::AvatarPostureBlend(const AvatarPostureBlend &apb)
                 
                
                 
                
        """
        this = _Piavca_base.new_AvatarPostureBlend(*args)
        try: self.this.append(this)
        except: self.this = this
    def clone(*args):
        """
        virtual Motion* Piavca::AvatarPostureBlend::clone()
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca_base.AvatarPostureBlend_clone(*args)

    def getClassName(*args): return _Piavca_base.AvatarPostureBlend_getClassName(*args)
    __swig_getmethods__["castToThisType"] = lambda x: _Piavca_base.AvatarPostureBlend_castToThisType
    if _newclass:castToThisType = staticmethod(_Piavca_base.AvatarPostureBlend_castToThisType)
    def load(*args):
        """
        void AvatarPostureBlend::load(Avatar *av)
                 
        called when the motion is loaded into an avatar         
                 
                
        """
        return _Piavca_base.AvatarPostureBlend_load(*args)

    def setBlendInterval(*args): return _Piavca_base.AvatarPostureBlend_setBlendInterval(*args)
    def getBlendInterval(*args): return _Piavca_base.AvatarPostureBlend_getBlendInterval(*args)
    def isNull(*args):
        """
        bool TwoMotionCombiner::isNull(int trackId) const 
                 
        given a track ID tests whether it actually points to anything or if its null         
                 
        is null if the track is null in both motions.         
        """
        return _Piavca_base.AvatarPostureBlend_isNull(*args)

    def setMotion(*args):
        """
        void AvatarPostureBlend::setMotion(Motion *mot)
                 
                
                 
                
        """
        return _Piavca_base.AvatarPostureBlend_setMotion(*args)

    def getMotion(*args): return _Piavca_base.AvatarPostureBlend_getMotion(*args)
    def repositionRelative(*args): return _Piavca_base.AvatarPostureBlend_repositionRelative(*args)
    def repositionAbsolute(*args): return _Piavca_base.AvatarPostureBlend_repositionAbsolute(*args)
    def reblend(*args):
        """
        void AvatarPostureBlend::reblend(float time)
                 
        restart the blend (i.e. start blending from the current avatar posture) at the current time         
                 
                
        """
        return _Piavca_base.AvatarPostureBlend_reblend(*args)

    __swig_destroy__ = _Piavca_base.delete_AvatarPostureBlend
    __del__ = lambda self : None;
AvatarPostureBlend_swigregister = _Piavca_base.AvatarPostureBlend_swigregister
AvatarPostureBlend_swigregister(AvatarPostureBlend)
AvatarPostureBlend_castToThisType = _Piavca_base.AvatarPostureBlend_castToThisType

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
        this = _Piavca_base.new_BlendBetween(*args)
        try: self.this.append(this)
        except: self.this = this
    def clone(*args):
        """
        virtual Motion* Piavca::BlendBetween::clone()
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca_base.BlendBetween_clone(*args)

    def getClassName(*args): return _Piavca_base.BlendBetween_getClassName(*args)
    __swig_getmethods__["castToThisType"] = lambda x: _Piavca_base.BlendBetween_castToThisType
    if _newclass:castToThisType = staticmethod(_Piavca_base.BlendBetween_castToThisType)
    def getFloatValueAtTimeInternal(*args):
        """
        float BlendBetween::getFloatValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe.         
                 
        The result is the linear interpolation of the values of the two motions or if the track does not exist in the one motion, the value of the other         
        """
        return _Piavca_base.BlendBetween_getFloatValueAtTimeInternal(*args)

    def getVecValueAtTimeInternal(*args):
        """
        Vec BlendBetween::getVecValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe.         
                 
        The result is the linear interpolation of the values of the two motions or if the track does not exist in the one motion, the value of the other         
        """
        return _Piavca_base.BlendBetween_getVecValueAtTimeInternal(*args)

    def getQuatValueAtTimeInternal(*args):
        """
        Quat BlendBetween::getQuatValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe.         
                 
        The result is the linear interpolation (slerp) of the values of the two motions or if the track does not exist in the one motion, the value of the other         
        """
        return _Piavca_base.BlendBetween_getQuatValueAtTimeInternal(*args)

    def setBlendFactor(*args):
        """
        void Piavca::BlendBetween::setBlendFactor(float _blend)
                 
                
                 
                
        """
        return _Piavca_base.BlendBetween_setBlendFactor(*args)

    def getBlendFactor(*args): return _Piavca_base.BlendBetween_getBlendFactor(*args)
    __swig_destroy__ = _Piavca_base.delete_BlendBetween
    __del__ = lambda self : None;
    def __disown__(self):
        self.this.disown()
        _Piavca_base.disown_BlendBetween(self)
        return weakref_proxy(self)
BlendBetween_swigregister = _Piavca_base.BlendBetween_swigregister
BlendBetween_swigregister(BlendBetween)
BlendBetween_castToThisType = _Piavca_base.BlendBetween_castToThisType

class MotionAdder(MultiMotionCombiner):
    """
    Adds the result of two motions, performing them simultaneously.     
           
    The results is the sum of the effects of both motions (in fact with rotations this is achieved with quaternion multiplication but the effect is similar to vector addition. An optional parameter can scale the effect of the second motion.      see also: MotionAdder.h
    """
    __swig_setmethods__ = {}
    for _s in [MultiMotionCombiner]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, MotionAdder, name, value)
    __swig_getmethods__ = {}
    for _s in [MultiMotionCombiner]: __swig_getmethods__.update(_s.__swig_getmethods__)
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
        this = _Piavca_base.new_MotionAdder(*args)
        try: self.this.append(this)
        except: self.this = this
    def clone(*args):
        """
        virtual Motion* Piavca::MotionAdder::clone()
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca_base.MotionAdder_clone(*args)

    def getClassName(*args): return _Piavca_base.MotionAdder_getClassName(*args)
    __swig_getmethods__["castToThisType"] = lambda x: _Piavca_base.MotionAdder_castToThisType
    if _newclass:castToThisType = staticmethod(_Piavca_base.MotionAdder_castToThisType)
    def getFloatValueAtTimeInternal(*args):
        """
        float MotionAdder::getFloatValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe         
                 
        The results is the sum of the two motions.         
        """
        return _Piavca_base.MotionAdder_getFloatValueAtTimeInternal(*args)

    def getVecValueAtTimeInternal(*args):
        """
        Vec MotionAdder::getVecValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe         
                 
        The results is the sum of the two motions.         
        """
        return _Piavca_base.MotionAdder_getVecValueAtTimeInternal(*args)

    def getQuatValueAtTimeInternal(*args):
        """
        Quat MotionAdder::getQuatValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe         
                 
        The results is the quaternion multiplication of the two motions (which is similar to vector addition).         
        """
        return _Piavca_base.MotionAdder_getQuatValueAtTimeInternal(*args)

    __swig_destroy__ = _Piavca_base.delete_MotionAdder
    __del__ = lambda self : None;
    def __disown__(self):
        self.this.disown()
        _Piavca_base.disown_MotionAdder(self)
        return weakref_proxy(self)
MotionAdder_swigregister = _Piavca_base.MotionAdder_swigregister
MotionAdder_swigregister(MotionAdder)
MotionAdder_castToThisType = _Piavca_base.MotionAdder_castToThisType

class Subtract(TwoMotionCombiner):
    __swig_setmethods__ = {}
    for _s in [TwoMotionCombiner]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, Subtract, name, value)
    __swig_getmethods__ = {}
    for _s in [TwoMotionCombiner]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, Subtract, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        if self.__class__ == Subtract:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca_base.new_Subtract(*args)
        try: self.this.append(this)
        except: self.this = this
    def clone(*args):
        """
        virtual Motion* Piavca::Motion::clone()=0
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca_base.Subtract_clone(*args)

    def getClassName(*args): return _Piavca_base.Subtract_getClassName(*args)
    __swig_getmethods__["castToThisType"] = lambda x: _Piavca_base.Subtract_castToThisType
    if _newclass:castToThisType = staticmethod(_Piavca_base.Subtract_castToThisType)
    def getFloatValueAtTimeInternal(*args):
        """
        virtual float Piavca::Motion::getFloatValueAtTimeInternal(int trackId, float time)=0
                 
        internal version of getFloatValueAtTime, to be overridden         
                 
                
        """
        return _Piavca_base.Subtract_getFloatValueAtTimeInternal(*args)

    def getVecValueAtTimeInternal(*args):
        """
        virtual Vec Piavca::Motion::getVecValueAtTimeInternal(int trackId, float time)=0
                 
        internal version of getVecValueAtTime, to be overridden         
                 
                
        """
        return _Piavca_base.Subtract_getVecValueAtTimeInternal(*args)

    def getQuatValueAtTimeInternal(*args):
        """
        virtual Quat Piavca::Motion::getQuatValueAtTimeInternal(int trackId, float time)=0
                 
        internal version of getQuatValueAtTime, to be overridden         
                 
                
        """
        return _Piavca_base.Subtract_getQuatValueAtTimeInternal(*args)

    __swig_destroy__ = _Piavca_base.delete_Subtract
    __del__ = lambda self : None;
    def __disown__(self):
        self.this.disown()
        _Piavca_base.disown_Subtract(self)
        return weakref_proxy(self)
Subtract_swigregister = _Piavca_base.Subtract_swigregister
Subtract_swigregister(Subtract)
Subtract_castToThisType = _Piavca_base.Subtract_castToThisType

class TransitionFunction(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, TransitionFunction, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, TransitionFunction, name)
    def __init__(self): raise AttributeError, "No constructor defined"
    __repr__ = _swig_repr
    def eval(*args): return _Piavca_base.TransitionFunction_eval(*args)
    __swig_destroy__ = _Piavca_base.delete_TransitionFunction
    __del__ = lambda self : None;
TransitionFunction_swigregister = _Piavca_base.TransitionFunction_swigregister
TransitionFunction_swigregister(TransitionFunction)

class LinearTransition(TransitionFunction):
    __swig_setmethods__ = {}
    for _s in [TransitionFunction]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, LinearTransition, name, value)
    __swig_getmethods__ = {}
    for _s in [TransitionFunction]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, LinearTransition, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _Piavca_base.new_LinearTransition(*args)
        try: self.this.append(this)
        except: self.this = this
    def eval(*args): return _Piavca_base.LinearTransition_eval(*args)
    __swig_destroy__ = _Piavca_base.delete_LinearTransition
    __del__ = lambda self : None;
LinearTransition_swigregister = _Piavca_base.LinearTransition_swigregister
LinearTransition_swigregister(LinearTransition)

class SmoothTransition(TransitionFunction):
    __swig_setmethods__ = {}
    for _s in [TransitionFunction]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, SmoothTransition, name, value)
    __swig_getmethods__ = {}
    for _s in [TransitionFunction]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, SmoothTransition, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _Piavca_base.new_SmoothTransition(*args)
        try: self.this.append(this)
        except: self.this = this
    def eval(*args): return _Piavca_base.SmoothTransition_eval(*args)
    __swig_destroy__ = _Piavca_base.delete_SmoothTransition
    __del__ = lambda self : None;
SmoothTransition_swigregister = _Piavca_base.SmoothTransition_swigregister
SmoothTransition_swigregister(SmoothTransition)

class MotionTransition(TwoMotionCombiner):
    __swig_setmethods__ = {}
    for _s in [TwoMotionCombiner]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, MotionTransition, name, value)
    __swig_getmethods__ = {}
    for _s in [TwoMotionCombiner]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, MotionTransition, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _Piavca_base.new_MotionTransition(*args)
        try: self.this.append(this)
        except: self.this = this
    def clone(*args):
        """
        virtual Motion* Piavca::Motion::clone()=0
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca_base.MotionTransition_clone(*args)

    def getClassName(*args): return _Piavca_base.MotionTransition_getClassName(*args)
    __swig_getmethods__["castToThisType"] = lambda x: _Piavca_base.MotionTransition_castToThisType
    if _newclass:castToThisType = staticmethod(_Piavca_base.MotionTransition_castToThisType)
    MotionStart = _Piavca_base.MotionTransition_MotionStart
    MotionEnd = _Piavca_base.MotionTransition_MotionEnd
    def setTransitionFunction(*args): return _Piavca_base.MotionTransition_setTransitionFunction(*args)
    def setTransitionTime1(*args): return _Piavca_base.MotionTransition_setTransitionTime1(*args)
    def getTransitionTime1(*args): return _Piavca_base.MotionTransition_getTransitionTime1(*args)
    def setTransitionTime2(*args): return _Piavca_base.MotionTransition_setTransitionTime2(*args)
    def getTransitionTime2(*args): return _Piavca_base.MotionTransition_getTransitionTime2(*args)
    def setWindow(*args): return _Piavca_base.MotionTransition_setWindow(*args)
    def getWindow(*args): return _Piavca_base.MotionTransition_getWindow(*args)
    def setMotion1(*args):
        """
        void TwoMotionCombiner::setMotion1(Motion *mot)
                 
                
                 
                
        """
        return _Piavca_base.MotionTransition_setMotion1(*args)

    def setStartTime(*args):
        """
        void TwoMotionCombiner::setStartTime(float time)
                 
        sets the start time of the motion. Called when its loaded into an avatar.         
                 
                
        """
        return _Piavca_base.MotionTransition_setStartTime(*args)

    def getMotionLength(*args):
        """
        float TwoMotionCombiner::getMotionLength() const 
                 
        gets the length of the combined motion (by default the length of the longer of the two)         
                 
                
        """
        return _Piavca_base.MotionTransition_getMotionLength(*args)

    def getFloatValueAtTimeInternal(*args):
        """
        virtual float Piavca::Motion::getFloatValueAtTimeInternal(int trackId, float time)=0
                 
        internal version of getFloatValueAtTime, to be overridden         
                 
                
        """
        return _Piavca_base.MotionTransition_getFloatValueAtTimeInternal(*args)

    def getVecValueAtTimeInternal(*args):
        """
        virtual Vec Piavca::Motion::getVecValueAtTimeInternal(int trackId, float time)=0
                 
        internal version of getVecValueAtTime, to be overridden         
                 
                
        """
        return _Piavca_base.MotionTransition_getVecValueAtTimeInternal(*args)

    def getQuatValueAtTimeInternal(*args):
        """
        virtual Quat Piavca::Motion::getQuatValueAtTimeInternal(int trackId, float time)=0
                 
        internal version of getQuatValueAtTime, to be overridden         
                 
                
        """
        return _Piavca_base.MotionTransition_getQuatValueAtTimeInternal(*args)

    __swig_destroy__ = _Piavca_base.delete_MotionTransition
    __del__ = lambda self : None;
MotionTransition_swigregister = _Piavca_base.MotionTransition_swigregister
MotionTransition_swigregister(MotionTransition)
MotionTransition_castToThisType = _Piavca_base.MotionTransition_castToThisType

class ChoiceMotion(MotionFilter):
    __swig_setmethods__ = {}
    for _s in [MotionFilter]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, ChoiceMotion, name, value)
    __swig_getmethods__ = {}
    for _s in [MotionFilter]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, ChoiceMotion, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        if self.__class__ == ChoiceMotion:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca_base.new_ChoiceMotion(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca_base.delete_ChoiceMotion
    __del__ = lambda self : None;
    def clone(*args):
        """
        virtual Motion* Piavca::Motion::clone()=0
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca_base.ChoiceMotion_clone(*args)

    def getClassName(*args): return _Piavca_base.ChoiceMotion_getClassName(*args)
    __swig_getmethods__["castToThisType"] = lambda x: _Piavca_base.ChoiceMotion_castToThisType
    if _newclass:castToThisType = staticmethod(_Piavca_base.ChoiceMotion_castToThisType)
    def setSmooth(*args): return _Piavca_base.ChoiceMotion_setSmooth(*args)
    def getSmooth(*args): return _Piavca_base.ChoiceMotion_getSmooth(*args)
    def setResetTime(*args): return _Piavca_base.ChoiceMotion_setResetTime(*args)
    def getResetTime(*args): return _Piavca_base.ChoiceMotion_getResetTime(*args)
    def setWindowLength(*args): return _Piavca_base.ChoiceMotion_setWindowLength(*args)
    def getWindowLength(*args): return _Piavca_base.ChoiceMotion_getWindowLength(*args)
    def setResetOnEvent(*args): return _Piavca_base.ChoiceMotion_setResetOnEvent(*args)
    def getResetOnEvent(*args): return _Piavca_base.ChoiceMotion_getResetOnEvent(*args)
    def setAccumulateRoot(*args): return _Piavca_base.ChoiceMotion_setAccumulateRoot(*args)
    def getAccumulateRoot(*args): return _Piavca_base.ChoiceMotion_getAccumulateRoot(*args)
    def setMaintainUp(*args): return _Piavca_base.ChoiceMotion_setMaintainUp(*args)
    def getMaintainUp(*args): return _Piavca_base.ChoiceMotion_getMaintainUp(*args)
    def setRotateAboutUp(*args): return _Piavca_base.ChoiceMotion_setRotateAboutUp(*args)
    def getRotateAboutUp(*args): return _Piavca_base.ChoiceMotion_getRotateAboutUp(*args)
    def setUpDirection(*args): return _Piavca_base.ChoiceMotion_setUpDirection(*args)
    def getUpDirection(*args): return _Piavca_base.ChoiceMotion_getUpDirection(*args)
    def printInfo(*args):
        """
        void Piavca::MotionFilter::printInfo()
                 
        prints out info about the motion heirarchy         
                 
                
        """
        return _Piavca_base.ChoiceMotion_printInfo(*args)

    def getMotionLength(*args):
        """
        float Piavca::MotionFilter::getMotionLength() const 
                 
        gets the length of the motion in seconds         
                 
                
        """
        return _Piavca_base.ChoiceMotion_getMotionLength(*args)

    def addMotion(*args): return _Piavca_base.ChoiceMotion_addMotion(*args)
    def getMotionIndex(*args): return _Piavca_base.ChoiceMotion_getMotionIndex(*args)
    def getNumMotions(*args): return _Piavca_base.ChoiceMotion_getNumMotions(*args)
    def getMotionByIndex(*args): return _Piavca_base.ChoiceMotion_getMotionByIndex(*args)
    def getLeafMotion(*args): return _Piavca_base.ChoiceMotion_getLeafMotion(*args)
    def getMotion(*args): return _Piavca_base.ChoiceMotion_getMotion(*args)
    def removeMotionByIndex(*args): return _Piavca_base.ChoiceMotion_removeMotionByIndex(*args)
    def clear(*args): return _Piavca_base.ChoiceMotion_clear(*args)
    def findSub(*args):
        """
        virtual Motion* Piavca::MotionFilter::findSub(tstring nm)
                 
        finds the first submotion with a given name         
                 
                
        """
        return _Piavca_base.ChoiceMotion_findSub(*args)

    def findSubByType(*args):
        """
        virtual Motion* Piavca::MotionFilter::findSubByType(const type_info &ty)
                 
        finds the first submotion with a given type         
                 
                
        """
        return _Piavca_base.ChoiceMotion_findSubByType(*args)

    def cleanRecursionState(*args): return _Piavca_base.ChoiceMotion_cleanRecursionState(*args)
    def setChoice(*args): return _Piavca_base.ChoiceMotion_setChoice(*args)
    def getCurrentChoice(*args): return _Piavca_base.ChoiceMotion_getCurrentChoice(*args)
    def makeChoice(*args): return _Piavca_base.ChoiceMotion_makeChoice(*args)
    def event(*args): return _Piavca_base.ChoiceMotion_event(*args)
    def getEventNames(*args): return _Piavca_base.ChoiceMotion_getEventNames(*args)
    def reset(*args):
        """
        void Piavca::MotionFilter::reset()
                 
        does any resetting needed         
                 
                
        """
        return _Piavca_base.ChoiceMotion_reset(*args)

    def __disown__(self):
        self.this.disown()
        _Piavca_base.disown_ChoiceMotion(self)
        return weakref_proxy(self)
ChoiceMotion_swigregister = _Piavca_base.ChoiceMotion_swigregister
ChoiceMotion_swigregister(ChoiceMotion)
ChoiceMotion_castToThisType = _Piavca_base.ChoiceMotion_castToThisType

class ChoiceMotionWithDefault(ChoiceMotion):
    __swig_setmethods__ = {}
    for _s in [ChoiceMotion]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, ChoiceMotionWithDefault, name, value)
    __swig_getmethods__ = {}
    for _s in [ChoiceMotion]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, ChoiceMotionWithDefault, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _Piavca_base.new_ChoiceMotionWithDefault(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca_base.delete_ChoiceMotionWithDefault
    __del__ = lambda self : None;
    def clone(*args):
        """
        virtual Motion* Piavca::Motion::clone()=0
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca_base.ChoiceMotionWithDefault_clone(*args)

    def getClassName(*args): return _Piavca_base.ChoiceMotionWithDefault_getClassName(*args)
    __swig_getmethods__["castToThisType"] = lambda x: _Piavca_base.ChoiceMotionWithDefault_castToThisType
    if _newclass:castToThisType = staticmethod(_Piavca_base.ChoiceMotionWithDefault_castToThisType)
    def reset(*args):
        """
        void Piavca::MotionFilter::reset()
                 
        does any resetting needed         
                 
                
        """
        return _Piavca_base.ChoiceMotionWithDefault_reset(*args)

ChoiceMotionWithDefault_swigregister = _Piavca_base.ChoiceMotionWithDefault_swigregister
ChoiceMotionWithDefault_swigregister(ChoiceMotionWithDefault)
ChoiceMotionWithDefault_castToThisType = _Piavca_base.ChoiceMotionWithDefault_castToThisType

class SequentialChoiceMotion(ChoiceMotion):
    __swig_setmethods__ = {}
    for _s in [ChoiceMotion]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, SequentialChoiceMotion, name, value)
    __swig_getmethods__ = {}
    for _s in [ChoiceMotion]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, SequentialChoiceMotion, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _Piavca_base.new_SequentialChoiceMotion(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca_base.delete_SequentialChoiceMotion
    __del__ = lambda self : None;
    def clone(*args):
        """
        virtual Motion* Piavca::Motion::clone()=0
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca_base.SequentialChoiceMotion_clone(*args)

    def getClassName(*args): return _Piavca_base.SequentialChoiceMotion_getClassName(*args)
    __swig_getmethods__["castToThisType"] = lambda x: _Piavca_base.SequentialChoiceMotion_castToThisType
    if _newclass:castToThisType = staticmethod(_Piavca_base.SequentialChoiceMotion_castToThisType)
    def event(*args): return _Piavca_base.SequentialChoiceMotion_event(*args)
    def getEventNames(*args): return _Piavca_base.SequentialChoiceMotion_getEventNames(*args)
    def makeChoice(*args): return _Piavca_base.SequentialChoiceMotion_makeChoice(*args)
SequentialChoiceMotion_swigregister = _Piavca_base.SequentialChoiceMotion_swigregister
SequentialChoiceMotion_swigregister(SequentialChoiceMotion)
SequentialChoiceMotion_castToThisType = _Piavca_base.SequentialChoiceMotion_castToThisType

class RandomChoiceMotion(ChoiceMotion):
    __swig_setmethods__ = {}
    for _s in [ChoiceMotion]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, RandomChoiceMotion, name, value)
    __swig_getmethods__ = {}
    for _s in [ChoiceMotion]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, RandomChoiceMotion, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _Piavca_base.new_RandomChoiceMotion(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca_base.delete_RandomChoiceMotion
    __del__ = lambda self : None;
    def clone(*args):
        """
        virtual Motion* Piavca::Motion::clone()=0
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca_base.RandomChoiceMotion_clone(*args)

    def getClassName(*args): return _Piavca_base.RandomChoiceMotion_getClassName(*args)
    __swig_getmethods__["castToThisType"] = lambda x: _Piavca_base.RandomChoiceMotion_castToThisType
    if _newclass:castToThisType = staticmethod(_Piavca_base.RandomChoiceMotion_castToThisType)
    __swig_getmethods__["convertTo"] = lambda x: _Piavca_base.RandomChoiceMotion_convertTo
    if _newclass:convertTo = staticmethod(_Piavca_base.RandomChoiceMotion_convertTo)
    def addMotion(*args): return _Piavca_base.RandomChoiceMotion_addMotion(*args)
    def setProbability(*args): return _Piavca_base.RandomChoiceMotion_setProbability(*args)
    def setMotionProb(*args): return _Piavca_base.RandomChoiceMotion_setMotionProb(*args)
    def makeChoice(*args): return _Piavca_base.RandomChoiceMotion_makeChoice(*args)
RandomChoiceMotion_swigregister = _Piavca_base.RandomChoiceMotion_swigregister
RandomChoiceMotion_swigregister(RandomChoiceMotion)
RandomChoiceMotion_castToThisType = _Piavca_base.RandomChoiceMotion_castToThisType
RandomChoiceMotion_convertTo = _Piavca_base.RandomChoiceMotion_convertTo

class PointAt(MotionFilter):
    __swig_setmethods__ = {}
    for _s in [MotionFilter]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, PointAt, name, value)
    __swig_getmethods__ = {}
    for _s in [MotionFilter]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, PointAt, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        if self.__class__ == PointAt:
            args = (None,) + args
        else:
            args = (self,) + args
        this = _Piavca_base.new_PointAt(*args)
        try: self.this.append(this)
        except: self.this = this
    def clone(*args):
        """
        virtual Motion* Piavca::Motion::clone()=0
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca_base.PointAt_clone(*args)

    def getClassName(*args): return _Piavca_base.PointAt_getClassName(*args)
    __swig_getmethods__["castToThisType"] = lambda x: _Piavca_base.PointAt_castToThisType
    if _newclass:castToThisType = staticmethod(_Piavca_base.PointAt_castToThisType)
    def isRandomAccess(*args):
        """
        virtual bool Piavca::MotionFilter::isRandomAccess()
                 
        whether you can access a motions value at frames other than the current one         
                 
                
        """
        return _Piavca_base.PointAt_isRandomAccess(*args)

    def setTarget(*args): return _Piavca_base.PointAt_setTarget(*args)
    def getTarget(*args): return _Piavca_base.PointAt_getTarget(*args)
    def setMotion(*args):
        """
        void Piavca::MotionFilter::setMotion(Motion *mot)
                 
                
                 
                
        """
        return _Piavca_base.PointAt_setMotion(*args)

    def getMotion(*args): return _Piavca_base.PointAt_getMotion(*args)
    def setLocal(*args): return _Piavca_base.PointAt_setLocal(*args)
    def getLocal(*args): return _Piavca_base.PointAt_getLocal(*args)
    def setJointId(*args): return _Piavca_base.PointAt_setJointId(*args)
    def getJointId(*args): return _Piavca_base.PointAt_getJointId(*args)
    def setTargetJointId(*args): return _Piavca_base.PointAt_setTargetJointId(*args)
    def getTargetJointId(*args): return _Piavca_base.PointAt_getTargetJointId(*args)
    def setForwardDirection(*args): return _Piavca_base.PointAt_setForwardDirection(*args)
    def getForwardDirection(*args): return _Piavca_base.PointAt_getForwardDirection(*args)
    def setOffset(*args): return _Piavca_base.PointAt_setOffset(*args)
    def getOffset(*args): return _Piavca_base.PointAt_getOffset(*args)
    def isNull(*args):
        """
        virtual bool Piavca::MotionFilter::isNull(int trackId) const 
                 
        given an iterator tests whether it actually points to anything or if its null         
                 
                
        """
        return _Piavca_base.PointAt_isNull(*args)

    def getTrackType(*args):
        """
        trackType Piavca::MotionFilter::getTrackType(int trackId) const 
                 
        get the type of the track corresponding to an iterator         
                 
                
        """
        return _Piavca_base.PointAt_getTrackType(*args)

    def getFloatValueAtTimeInternal(*args):
        """
        virtual float Piavca::Motion::getFloatValueAtTimeInternal(int trackId, float time)=0
                 
        internal version of getFloatValueAtTime, to be overridden         
                 
                
        """
        return _Piavca_base.PointAt_getFloatValueAtTimeInternal(*args)

    def getVecValueAtTimeInternal(*args):
        """
        virtual Vec Piavca::Motion::getVecValueAtTimeInternal(int trackId, float time)=0
                 
        internal version of getVecValueAtTime, to be overridden         
                 
                
        """
        return _Piavca_base.PointAt_getVecValueAtTimeInternal(*args)

    def getQuatValueAtTimeInternal(*args):
        """
        virtual Quat Piavca::Motion::getQuatValueAtTimeInternal(int trackId, float time)=0
                 
        internal version of getQuatValueAtTime, to be overridden         
                 
                
        """
        return _Piavca_base.PointAt_getQuatValueAtTimeInternal(*args)

    __swig_destroy__ = _Piavca_base.delete_PointAt
    __del__ = lambda self : None;
    def __disown__(self):
        self.this.disown()
        _Piavca_base.disown_PointAt(self)
        return weakref_proxy(self)
PointAt_swigregister = _Piavca_base.PointAt_swigregister
PointAt_swigregister(PointAt)
PointAt_castToThisType = _Piavca_base.PointAt_castToThisType

class Proxemics(ChoiceMotion):
    __swig_setmethods__ = {}
    for _s in [ChoiceMotion]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, Proxemics, name, value)
    __swig_getmethods__ = {}
    for _s in [ChoiceMotion]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, Proxemics, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _Piavca_base.new_Proxemics(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _Piavca_base.delete_Proxemics
    __del__ = lambda self : None;
    def clone(*args):
        """
        virtual Motion* Piavca::Motion::clone()=0
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca_base.Proxemics_clone(*args)

    def getClassName(*args): return _Piavca_base.Proxemics_getClassName(*args)
    __swig_getmethods__["castToThisType"] = lambda x: _Piavca_base.Proxemics_castToThisType
    if _newclass:castToThisType = staticmethod(_Piavca_base.Proxemics_castToThisType)
    def load(*args):
        """
        virtual void Piavca::MotionFilter::load(Avatar *av)
                 
        called when the motion is loaded into an avatar         
                 
                
        """
        return _Piavca_base.Proxemics_load(*args)

    def addMotion(*args): return _Piavca_base.Proxemics_addMotion(*args)
    def removeMotionByIndex(*args): return _Piavca_base.Proxemics_removeMotionByIndex(*args)
    def setDistance(*args): return _Piavca_base.Proxemics_setDistance(*args)
    def getDistance(*args): return _Piavca_base.Proxemics_getDistance(*args)
    def setThreshold(*args): return _Piavca_base.Proxemics_setThreshold(*args)
    def getThreshold(*args): return _Piavca_base.Proxemics_getThreshold(*args)
    def setAngleThreshold(*args): return _Piavca_base.Proxemics_setAngleThreshold(*args)
    def getAngleThreshold(*args): return _Piavca_base.Proxemics_getAngleThreshold(*args)
    def setDistanceOff(*args): return _Piavca_base.Proxemics_setDistanceOff(*args)
    def getDistanceOff(*args): return _Piavca_base.Proxemics_getDistanceOff(*args)
    def setForwardDirection(*args): return _Piavca_base.Proxemics_setForwardDirection(*args)
    def getForwardDirection(*args): return _Piavca_base.Proxemics_getForwardDirection(*args)
    def setForwardMotionName(*args): return _Piavca_base.Proxemics_setForwardMotionName(*args)
    def getForwardMotionName(*args): return _Piavca_base.Proxemics_getForwardMotionName(*args)
    def setBackwardMotionName(*args): return _Piavca_base.Proxemics_setBackwardMotionName(*args)
    def getBackwardMotionName(*args): return _Piavca_base.Proxemics_getBackwardMotionName(*args)
    def setLeftMotionName(*args): return _Piavca_base.Proxemics_setLeftMotionName(*args)
    def getLeftMotionName(*args): return _Piavca_base.Proxemics_getLeftMotionName(*args)
    def setRightMotionName(*args): return _Piavca_base.Proxemics_setRightMotionName(*args)
    def getRightMotionName(*args): return _Piavca_base.Proxemics_getRightMotionName(*args)
    def setRestMotionName(*args): return _Piavca_base.Proxemics_setRestMotionName(*args)
    def getRestMotionName(*args): return _Piavca_base.Proxemics_getRestMotionName(*args)
    def setTargetMotionName(*args): return _Piavca_base.Proxemics_setTargetMotionName(*args)
    def getTargetMotionName(*args): return _Piavca_base.Proxemics_getTargetMotionName(*args)
    def setTarget(*args): return _Piavca_base.Proxemics_setTarget(*args)
    def getTarget(*args): return _Piavca_base.Proxemics_getTarget(*args)
    def setTargetId(*args): return _Piavca_base.Proxemics_setTargetId(*args)
    def refreshMotions(*args): return _Piavca_base.Proxemics_refreshMotions(*args)
    def makeChoice(*args): return _Piavca_base.Proxemics_makeChoice(*args)
Proxemics_swigregister = _Piavca_base.Proxemics_swigregister
Proxemics_swigregister(Proxemics)
Proxemics_castToThisType = _Piavca_base.Proxemics_castToThisType

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
        this = _Piavca_base.new_ZeroMotion(*args)
        try: self.this.append(this)
        except: self.this = this
    def clone(*args):
        """
        virtual Motion* Piavca::ZeroMotion::clone()
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca_base.ZeroMotion_clone(*args)

    def getClassName(*args): return _Piavca_base.ZeroMotion_getClassName(*args)
    __swig_getmethods__["castToThisType"] = lambda x: _Piavca_base.ZeroMotion_castToThisType
    if _newclass:castToThisType = staticmethod(_Piavca_base.ZeroMotion_castToThisType)
    def isFacial(*args):
        """
        virtual bool Piavca::ZeroMotion::isFacial()
                 
        whether it is a face or body motion         
                 
                
        """
        return _Piavca_base.ZeroMotion_isFacial(*args)

    def isRandomAccess(*args):
        """
        virtual bool Piavca::ZeroMotion::isRandomAccess()
                 
        whether you can access a motions value at frames other than the current one         
                 
                
        """
        return _Piavca_base.ZeroMotion_isRandomAccess(*args)

    def getMotionLength(*args):
        """
        virtual float Piavca::ZeroMotion::getMotionLength() const 
                 
        returns the length of the motion         
                 
                
        """
        return _Piavca_base.ZeroMotion_getMotionLength(*args)

    def isNull(*args):
        """
        bool Piavca::ZeroMotion::isNull(int trackId) const 
                 
        given a track ID tests whether it actually points to anything or if its null         
                 
                
        """
        return _Piavca_base.ZeroMotion_isNull(*args)

    def getTrackType(*args):
        """
        virtual trackType Piavca::ZeroMotion::getTrackType(int trackId) const 
                 
        get the type of the track corresponding to an ID         
                 
                
        """
        return _Piavca_base.ZeroMotion_getTrackType(*args)

    def getFloatValueAtTimeInternal(*args):
        """
        virtual float Piavca::ZeroMotion::getFloatValueAtTimeInternal(int trackId, float time)
                 
        get the value of a track at a given time (only works for floats)         
                 
                
        """
        return _Piavca_base.ZeroMotion_getFloatValueAtTimeInternal(*args)

    def getVecValueAtTimeInternal(*args):
        """
        virtual Vec Piavca::ZeroMotion::getVecValueAtTimeInternal(int trackId, float time)
                 
        get the value of a track at a given time (only works for Vecs)         
                 
                
        """
        return _Piavca_base.ZeroMotion_getVecValueAtTimeInternal(*args)

    def getQuatValueAtTimeInternal(*args):
        """
        virtual Quat Piavca::ZeroMotion::getQuatValueAtTimeInternal(int trackId, float time)
                 
        get the value of a track at a given time (only works for Quats)         
                 
                
        """
        return _Piavca_base.ZeroMotion_getQuatValueAtTimeInternal(*args)

    __swig_destroy__ = _Piavca_base.delete_ZeroMotion
    __del__ = lambda self : None;
    def __disown__(self):
        self.this.disown()
        _Piavca_base.disown_ZeroMotion(self)
        return weakref_proxy(self)
ZeroMotion_swigregister = _Piavca_base.ZeroMotion_swigregister
ZeroMotion_swigregister(ZeroMotion)
ZeroMotion_castToThisType = _Piavca_base.ZeroMotion_castToThisType

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
        this = _Piavca_base.new_SubMotion(*args)
        try: self.this.append(this)
        except: self.this = this
    def clone(*args):
        """
        Motion * SubMotion::clone()
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca_base.SubMotion_clone(*args)

    def getClassName(*args): return _Piavca_base.SubMotion_getClassName(*args)
    __swig_getmethods__["castToThisType"] = lambda x: _Piavca_base.SubMotion_castToThisType
    if _newclass:castToThisType = staticmethod(_Piavca_base.SubMotion_castToThisType)
    def getMotionLength(*args):
        """
        float SubMotion::getMotionLength() const 
                 
        gets the length of the motion in seconds         
                 
                
        """
        return _Piavca_base.SubMotion_getMotionLength(*args)

    def setStart(*args):
        """
        void SubMotion::setStart(float s)
                 
        Sets the start of the range to be played.         
                 
                
        """
        return _Piavca_base.SubMotion_setStart(*args)

    def setEnd(*args):
        """
        void SubMotion::setEnd(float e)
                 
        Sets the end of the range to be played.         
                 
                
        """
        return _Piavca_base.SubMotion_setEnd(*args)

    def getStart(*args): return _Piavca_base.SubMotion_getStart(*args)
    def getEnd(*args): return _Piavca_base.SubMotion_getEnd(*args)
    def getFloatValueAtTimeInternal(*args):
        """
        PIAVCA_EXPORT float SubMotion::getFloatValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe         
                 
                
        """
        return _Piavca_base.SubMotion_getFloatValueAtTimeInternal(*args)

    def getVecValueAtTimeInternal(*args):
        """
        PIAVCA_EXPORT Vec SubMotion::getVecValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe         
                 
                
        """
        return _Piavca_base.SubMotion_getVecValueAtTimeInternal(*args)

    def getQuatValueAtTimeInternal(*args):
        """
        PIAVCA_EXPORT Quat SubMotion::getQuatValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe         
                 
                
        """
        return _Piavca_base.SubMotion_getQuatValueAtTimeInternal(*args)

    __swig_destroy__ = _Piavca_base.delete_SubMotion
    __del__ = lambda self : None;
    def __disown__(self):
        self.this.disown()
        _Piavca_base.disown_SubMotion(self)
        return weakref_proxy(self)
SubMotion_swigregister = _Piavca_base.SubMotion_swigregister
SubMotion_swigregister(SubMotion)
SubMotion_castToThisType = _Piavca_base.SubMotion_castToThisType

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
        this = _Piavca_base.new_TimeWarp(*args)
        try: self.this.append(this)
        except: self.this = this
    def clone(*args):
        """
        virtual Motion* Piavca::TimeWarp::clone()
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca_base.TimeWarp_clone(*args)

    def getClassName(*args): return _Piavca_base.TimeWarp_getClassName(*args)
    __swig_getmethods__["castToThisType"] = lambda x: _Piavca_base.TimeWarp_castToThisType
    if _newclass:castToThisType = staticmethod(_Piavca_base.TimeWarp_castToThisType)
    def getMotionLength(*args):
        """
        virtual float Piavca::TimeWarp::getMotionLength() const 
                 
        gets the length of the motion in seconds         
                 
                
        """
        return _Piavca_base.TimeWarp_getMotionLength(*args)

    def getFloatValueAtTimeInternal(*args):
        """
        virtual PIAVCA_EXPORT float Piavca::TimeWarp::getFloatValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe         
                 
                
        """
        return _Piavca_base.TimeWarp_getFloatValueAtTimeInternal(*args)

    def getVecValueAtTimeInternal(*args):
        """
        virtual PIAVCA_EXPORT Vec Piavca::TimeWarp::getVecValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe         
                 
                
        """
        return _Piavca_base.TimeWarp_getVecValueAtTimeInternal(*args)

    def getQuatValueAtTimeInternal(*args):
        """
        virtual PIAVCA_EXPORT Quat Piavca::TimeWarp::getQuatValueAtTimeInternal(int trackId, float time)
                 
        calculates the values of a keyframe         
                 
                
        """
        return _Piavca_base.TimeWarp_getQuatValueAtTimeInternal(*args)

    def setWarp(*args):
        """
        void Piavca::TimeWarp::setWarp(Motion *warp)
                 
        Sets the scale factor for the postion components of the motion.         
                 
                
        """
        return _Piavca_base.TimeWarp_setWarp(*args)

    __swig_destroy__ = _Piavca_base.delete_TimeWarp
    __del__ = lambda self : None;
    def __disown__(self):
        self.this.disown()
        _Piavca_base.disown_TimeWarp(self)
        return weakref_proxy(self)
TimeWarp_swigregister = _Piavca_base.TimeWarp_swigregister
TimeWarp_swigregister(TimeWarp)
TimeWarp_castToThisType = _Piavca_base.TimeWarp_castToThisType

class OverrideMotion(TwoMotionCombiner):
    __swig_setmethods__ = {}
    for _s in [TwoMotionCombiner]: __swig_setmethods__.update(_s.__swig_setmethods__)
    __setattr__ = lambda self, name, value: _swig_setattr(self, OverrideMotion, name, value)
    __swig_getmethods__ = {}
    for _s in [TwoMotionCombiner]: __swig_getmethods__.update(_s.__swig_getmethods__)
    __getattr__ = lambda self, name: _swig_getattr(self, OverrideMotion, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _Piavca_base.new_OverrideMotion(*args)
        try: self.this.append(this)
        except: self.this = this
    def clone(*args):
        """
        virtual Motion* Piavca::Motion::clone()=0
                 
        creates a copy of the motion         
                 
                
        """
        return _Piavca_base.OverrideMotion_clone(*args)

    def getClassName(*args): return _Piavca_base.OverrideMotion_getClassName(*args)
    __swig_getmethods__["castToThisType"] = lambda x: _Piavca_base.OverrideMotion_castToThisType
    if _newclass:castToThisType = staticmethod(_Piavca_base.OverrideMotion_castToThisType)
    def getFloatValueAtTimeInternal(*args):
        """
        virtual float Piavca::Motion::getFloatValueAtTimeInternal(int trackId, float time)=0
                 
        internal version of getFloatValueAtTime, to be overridden         
                 
                
        """
        return _Piavca_base.OverrideMotion_getFloatValueAtTimeInternal(*args)

    def getVecValueAtTimeInternal(*args):
        """
        virtual Vec Piavca::Motion::getVecValueAtTimeInternal(int trackId, float time)=0
                 
        internal version of getVecValueAtTime, to be overridden         
                 
                
        """
        return _Piavca_base.OverrideMotion_getVecValueAtTimeInternal(*args)

    def getQuatValueAtTimeInternal(*args):
        """
        virtual Quat Piavca::Motion::getQuatValueAtTimeInternal(int trackId, float time)=0
                 
        internal version of getQuatValueAtTime, to be overridden         
                 
                
        """
        return _Piavca_base.OverrideMotion_getQuatValueAtTimeInternal(*args)

    __swig_destroy__ = _Piavca_base.delete_OverrideMotion
    __del__ = lambda self : None;
OverrideMotion_swigregister = _Piavca_base.OverrideMotion_swigregister
OverrideMotion_swigregister(OverrideMotion)
OverrideMotion_castToThisType = _Piavca_base.OverrideMotion_castToThisType



