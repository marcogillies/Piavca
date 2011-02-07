
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
# The Original Code is CoreProxy.py
#
# The Initial Developer of the Original Code is
# Marco Gillies
# Portions created by the Initial Developer are Copyright (C) 2007
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

#import Piavca
import Piavca_base
from Piavca_base import Core, Motion
import PiavcaWXApp

import types

vertexShaderText = """

uniform mat4 Transforms[24];
uniform bool textureAvailable;
uniform vec4 AmbientMaterial;
uniform vec4 DiffuseMaterial;
uniform vec4 SpecularMaterial;
uniform vec4 MorphWeights;

attribute vec4 Vertex;
attribute vec3 Normal;
attribute vec4 Weights;
attribute vec4 MatrixIndices;
attribute vec2 TextureCoordinates;

attribute vec3 MorphPosition1;
attribute vec3 MorphNormal1;
attribute vec3 MorphPosition2;
attribute vec3 MorphNormal2;
attribute vec3 MorphPosition3;
attribute vec3 MorphNormal3;
attribute vec3 MorphPosition4;
attribute vec3 MorphNormal4;

varying vec4 Color;
varying vec2 TexCoord;

const vec4 AMBIENT_BLACK = vec4(0.0, 0.0, 0.0, 1.0);
const vec4 DEFAULT_BLACK = vec4(0.0, 0.0, 0.0, 0.0);

bool isLightEnabled(in int i)
	{
	    // A separate variable is used to get
	    // rid of a linker error.
	    bool enabled = true;

	    // If all the colors of the Light are set
	    // to BLACK then we know we don't need to bother
	    // doing a lighting calculation on it.
	    if ((gl_LightSource[i].ambient  == AMBIENT_BLACK) &&
	        (gl_LightSource[i].diffuse  == DEFAULT_BLACK) &&
	        (gl_LightSource[i].specular == DEFAULT_BLACK))
	        enabled = false;

	    return(enabled);
	}

void DirectionalLight(in int i, in vec3 normal, inout vec4 ambient, inout vec4 diffuse, inout vec4 specular)
{
	float nDotVP = max(0.0, dot(normal, normalize(vec3(gl_LightSource[i].position))));
	
	float nDotHV = max(0.0, dot(normal, vec3(gl_LightSource[i].halfVector)));

	float pf;	
	if (nDotVP == 0.0)
		pf = 0.0;
	else
		pf = pow(nDotHV, gl_FrontMaterial.shininess);

	ambient  += gl_LightSource[i].ambient;
	diffuse  += gl_LightSource[i].diffuse*nDotVP;
	specular += gl_LightSource[i].specular*pf;
}

void PointLight(in int i,
                in vec3 eye,
                in vec3 ecPosition3,
                in vec3 normal,
                inout vec4 ambient,
                inout vec4 diffuse,
                inout vec4 specular)
{
    float nDotVP;         // normal . light direction
    float nDotHV;         // normal . light half vector
    float pf;             // power factor
    float attenuation;    // computed attenuation factor
    float d;              // distance from surface to light source
    vec3  VP;             // direction from surface to light position
    vec3  halfVector;     // direction of maximum highlights

    // Compute vector from surface to light position
    VP = vec3(gl_LightSource[i].position) - ecPosition3;

    // Compute distance between surface and light position
    d = length(VP);

    // Normalize the vector from surface to light position
    VP = normalize(VP);

    // Compute attenuation
    attenuation = 1.0 / (gl_LightSource[i].constantAttenuation +
                         gl_LightSource[i].linearAttenuation * d +
                         gl_LightSource[i].quadraticAttenuation * d * d);

    halfVector = normalize(VP + eye);

    nDotVP = max(0.0, dot(normal, VP));
    nDotHV = max(0.0, dot(normal, halfVector));

    if (nDotVP == 0.0)
        pf = 0.0;
    else
        pf = pow(nDotHV, gl_FrontMaterial.shininess);

    ambient += gl_LightSource[i].ambient * attenuation;
    diffuse += gl_LightSource[i].diffuse * nDotVP * attenuation;
    specular += gl_LightSource[i].specular * pf * attenuation;
}

void SpotLight(in int i,
               in vec3 eye,
               in vec3 ecPosition3,
               in vec3 normal,
               inout vec4 ambient,
               inout vec4 diffuse,
               inout vec4 specular)
{
    float nDotVP;           // normal . light direction
    float nDotHV;           // normal . light half vector
    float pf;               // power factor
    float spotDot;          // cosine of angle between spotlight
    float spotAttenuation;  // spotlight attenuation factor
    float attenuation;      // computed attenuation factor
    float d;                // distance from surface to light source
    vec3 VP;                // direction from surface to light position
    vec3 halfVector;        // direction of maximum highlights

    // Compute vector from surface to light position
    VP = vec3(gl_LightSource[i].position) - ecPosition3;

    // Compute distance between surface and light position
    d = length(VP);

    // Normalize the vector from surface to light position
    VP = normalize(VP);

    // Compute attenuation
    attenuation = 1.0 / (gl_LightSource[i].constantAttenuation +
                         gl_LightSource[i].linearAttenuation * d +
                         gl_LightSource[i].quadraticAttenuation * d * d);

    // See if point on surface is inside cone of illumination
    spotDot = dot(-VP, normalize(gl_LightSource[i].spotDirection));

    if (spotDot < gl_LightSource[i].spotCosCutoff)
        spotAttenuation = 0.0; // light adds no contribution
    else
        spotAttenuation = pow(spotDot, gl_LightSource[i].spotExponent);

    // Combine the spotlight and distance attenuation.
    attenuation *= spotAttenuation;

    halfVector = normalize(VP + eye);

    nDotVP = max(0.0, dot(normal, VP));
    nDotHV = max(0.0, dot(normal, halfVector));

    if (nDotVP == 0.0)
        pf = 0.0;
    else
        pf = pow(nDotHV, gl_FrontMaterial.shininess);

    ambient  += gl_LightSource[i].ambient * attenuation;
    diffuse  += gl_LightSource[i].diffuse * nDotVP * attenuation;
    specular += gl_LightSource[i].specular * pf * attenuation;
}

float round(float a)
{
	if (fract(a) >= 0.5)
		return ceil(a);
	else 
		return floor(a);

}


void main()
	{	
		vec4 position = Vertex;
		vec3 normal = Normal;
		
		if(length(MorphWeights) > 0.01)
		{
			
			position.xyz += MorphWeights.x*MorphPosition1.xyz;
			position.xyz += MorphWeights.y*MorphPosition2.xyz;
			position.xyz += MorphWeights.z*MorphPosition3.xyz;
			position.xyz += MorphWeights.w*MorphPosition4.xyz;
			
			normal += MorphWeights.x*MorphNormal1;
			normal += MorphWeights.y*MorphNormal2;
			normal += MorphWeights.z*MorphNormal3;
			normal += MorphWeights.w*MorphNormal4;
			
		}
		
	
		mat4 transform  = Weights.x*Transforms[int(round(MatrixIndices.x))];
        	transform += Weights.y*Transforms[int(round(MatrixIndices.y))];
        	transform += Weights.z*Transforms[int(round(MatrixIndices.x))];
        	transform += Weights.w*Transforms[int(round(MatrixIndices.w))];
	 	
		//gl_Position = transform *Vertex;
		gl_Position = transform *position;
		//gl_Position = Vertex;

		vec3 ecPosition = vec3(gl_ModelViewMatrix*Vertex);

		vec3 eye = -normalize(ecPosition);

		normal = vec3(transform*vec4(normal,0.0));
		
		normal = normalize(gl_NormalMatrix * normal);


		vec4 ambient = vec4(0.0);
		vec4 diffuse = vec4(0.0);
		vec4 specular = vec4(0.0);


		for (int i = 0; i < gl_MaxLights; i++)
		{
			if(isLightEnabled(i))
			{
				if (gl_LightSource[i].position.w == 0.0)
        				DirectionalLight(i, normal, ambient, diffuse, specular);
    				else if (gl_LightSource[i].spotCutoff == 180.0)
        				PointLight(i, eye, ecPosition, normal, ambient, diffuse, specular);
				else
        				SpotLight(i, eye, ecPosition, normal, ambient, diffuse, specular);

			}
		}
		
		
		if (textureAvailable)
		{
			Color = length(vec3(AmbientMaterial))*ambient 
					+ length(vec3(DiffuseMaterial))*diffuse 
					+ length(vec3(SpecularMaterial))*specular ;
		}
		else 
		{
			Color = ambient*AmbientMaterial// gl_FrontLightModelProduct.sceneColor 
					+ diffuse*DiffuseMaterial 
					+ specular*SpecularMaterial;
		}
		
		TexCoord = TextureCoordinates;

		gl_Position = gl_ModelViewProjectionMatrix* gl_Position;
	}

"""

fragmentShaderText = """

uniform sampler2D tex;
uniform bool textureAvailable;

varying vec2 TexCoord;
varying vec4 Color;

void main()
{	
	if (textureAvailable)
	{
		vec3 texColor = vec3(texture2D(tex, TexCoord.st));
		gl_FragColor = Color*vec4(texColor, 1.0);
	}
	else
	{
		gl_FragColor = Color;
	}
}

"""

Core.getCore().setVertexShaderText(vertexShaderText)
Core.getCore().setFragmentShaderText(fragmentShaderText)

def getTime():
	return Core.getCore().getTime()

_motionLookup = {}

def loadMotion(name, motion):
	global _motionLookup
	print "loading motion", name
	if type(motion) != type(""):
		print "loading motion to lookup", name
		_motionLookup[name] = motion
	#print "proxy core", Core.getCore()
	Core.getCore().loadMotion(name, motion)
	
def getRealMotionType(motion):
	if motion != None and type(motion) == Motion:
		typeName = motion.getClassName()
		#print "typename", typeName
		motionType = getattr(Piavca_base, typeName)
		#print motionType
		if type(motionType) == types.TypeType and issubclass(motionType, Motion):
				return motionType.castToThisType(motion)
	return motion
	
def getMotion(name):
	global _motionLookup
	#print _motionLookup.keys()
	print "getting motion", name
	#print "getMotion"
	if _motionLookup.has_key(name):
		print "core proxy: found motion,", name
		return _motionLookup[name]
	else:
		motion = Core.getCore().getMotion(name)
		if motion != None:
			motion.Reference()
			motion.thisown = False
		return getRealMotionType(motion)
	
_events = {}

def addEvents(avatar, events):
	global _events
	if not _events.has_key(avatar.getName()):
		_events[avatar.getName()] = []
	uniqueevents = filter(lambda x: not x in _events[avatar.getName()], events)
	_events[avatar.getName()] = _events[avatar.getName()] + uniqueevents
	
def addEvent(avatar, event):
	global _events
	if not _events.has_key(avatar.getName()):
		_events[avatar.getName()] = []
	if not event in _events[avatar.getName()]:
		_events[avatar.getName()].append(event)
	
def getEvents(avatar):
	global _events
	if _events.has_key(avatar.getName()):
		return list(_events[avatar.getName()])
	else:
		return []

def removeEvent(avatareventname):
	global _events
	try:
		if _events.has_key(avatar.getName()):
			_events[avatar.getName()].remove(eventname)
	except ValueError:
		print "no such event", eventname
		
def clear():
	_motionLookup = {}
	_events = {}
	PiavcaWXApp.getWXApp().clear()
	Core.getCore().reset()
	
def joints(o):
	j = o.begin()
	while (True):
		if j == o.end():
			break
		yield j
		j = o.next(j)
		
def getValAtTime(mot, joint, t, joint_type):
	if joint_type == Piavca_base.FLOAT_TYPE: 
		return mot.getFloatValueAtTime(joint, t)
	if joint_type == Piavca_base.VEC_TYPE: 
		return mot.getVecValueAtTime(joint, t)
	if joint_type == Piavca_base.QUAT_TYPE: 
		return mot.getQuatValueAtTime(joint, t)
	
		