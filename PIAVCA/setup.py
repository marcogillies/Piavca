#!/usr/bin/env python


# ***** BEGIN LICENSE BLOCK *****
# Version: MPL 1.1/GPL 2.0/LGPL 2.1
#
# The contents of this file are subject to the Mozilla Public License Version
# 1.1 (the "License"); you may not use this file except in compliance with
# the License. You may obtain a copy of the License at
# http://www.mozilla.org/MPL/
#
# Software distributed under the License is distributed on an "AS IS" basis,
# WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
# for the specific language governing rights and limitations under the
# License.
#
# The Original Code is setup.y
#
# The Initial Developer of the Original Code is
# Marco (Mark) Gillies.
# Portions created by the Initial Developer are Copyright (C) 2009
# the Initial Developer. All Rights Reserved.
#
# Contributor(s): 
#
# Alternatively, the contents of this file may be used under the terms of
# either the GNU General Public License Version 2 or later (the "GPL"), or
# the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
# in which case the provisions of the GPL or the LGPL are applicable instead
# of those above. If you wish to allow use of your version of this file only
# under the terms of either the GPL or the LGPL, and not to allow others to
# use your version of this file under the terms of the MPL, indicate your
# decision by deleting the provisions above and replace them with the notice
# and other provisions required by the GPL or the LGPL. If you do not delete
# the provisions above, a recipient may use your version of this file under
# the terms of any one of the MPL, the GPL or the LGPL.
#
# ***** END LICENSE BLOCK *****

from distutils.core import setup, Extension
import commands
import sys, os
from glob import glob

swig_sources = [os.path.join('Python','Piavca','Piavca_base','Piavca_wrap.cpp')]
PiavcaAPI_sources = glob(os.path.join(os.curdir,'src','PiavcaAPI','*.cpp'))
#print PiavcaAPI_sources
StdMotionImp_sources = glob(os.path.join(os.curdir,'src','StdMotionImp','*.cpp'))
PiavcaCal3dImp_sources = glob(os.path.join(os.curdir,'src','PiavcaCal3dImp','*.cpp')) + glob(os.path.join(os.curdir,'src','PiavcaCal3dImp','*.c'))

sources = swig_sources + PiavcaAPI_sources + StdMotionImp_sources + PiavcaCal3dImp_sources

external_libs = ["cal3d"]

includes = [ os.path.join(os.curdir,'src')]

if sys.platform != "win32":
	includes = includes + ["/usr/local/include"]

if sys.platform == "win32":
	try:
		cal3ddir = os.environ["CAL3DDIR"]
		includes = includes + [os.path.join(cal3ddir,'src')]
	except KeyError:
		includes = includes + ['../cal3d-0.11.0/src/', '../cal3d/src/', '../cal3d/cal3d/src/' '../cal3d-0.10.0/src/']

defines = [('GLEW_STATIC', '1')]

if sys.platform == "win32":
	defines = defines + [('WIN32', 1)]

swig_opts = ['-modern', '-c++', '-I./src']

extra_link_args = []
library_dirs = []

if sys.platform == "win32":
	try:
		cal3ddir = os.environ["CAL3DDIR"]
		library_dirs = library_dirs + [os.path.join(cal3ddir,'bin','Release')]
	except KeyError:
		library_dirs = library_dirs + ['..\\cal3d-0.11.0\\bin\\Release', '..\\cal3d\\bin\\Release', '..\\cal3d\cal3d\\bin\\Release' '..\\cal3d-0.10.0\\bin\\Release']

if sys.platform == "darwin":
	extra_link_args = extra_link_args + ['-framework', 'OpenGL']
elif sys.platform == "win32":
	external_libs = external_libs + ["opengl32", "glu32"]
else:
	external_libs = external_libs + ["GL", "GLU"]

setup(name='Piavca',
      version='1.0',
      package_dir={'':'Python'},
      packages=['Piavca', 'Piavca.PiavcaDesigner', 'Piavca.CreationScripts', 'Piavca.PiavcaDesigner.AutoCreators'],
      ext_modules=[Extension('Piavca.Piavca_base._Piavca_base', sources,
                             swig_opts=swig_opts,
                             libraries=external_libs,
                             include_dirs=includes,
                             extra_link_args=extra_link_args,
                             define_macros=defines,
							 library_dirs=library_dirs)
      					   	],
      py_modules=['Piavca.Piavca_base.Piavca_base'],
      scripts=['Python/PiavcaDesigner.py', 'Python/wxViewer.py', 'Python/FreeCameraViewer.py']
      )

