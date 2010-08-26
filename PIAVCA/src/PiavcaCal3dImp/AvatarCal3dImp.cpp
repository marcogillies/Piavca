
/* LICENCE BLOCK
AvatarCal3DImp.cpp
Copyright (C) 2005 Marco (Mark) Gillies

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

//#ifdef PIAVCA_DLL
//#define PIAVCA_EXPORT __declspec( dllimport ) 
//#else
//#define PIAVCA_EXPORT
//#endif



//#ifdef _WIN32
//#include <windows.h>
//#include <direct.h>
//#endif

#include "glew.h"

//#include <GL/gl.h>
//#include <GL/glu.h>
//#include <GL/glut.h>

#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>

/*"MUL result.color.front.primary, R0, diffuse;\n"\ */
/* "MOV result.color.front.primary, constwhite;\n"\ */
/*
/// GPU skinner, thanks to Cal3d
char vertexProgramStr[]= 
"!!ARBvp1.0\n"\
"PARAM constant = { 1, 3, 0, 1 };\n"\
"PARAM ldir = { 1.5, 0.0, 0.0, 1.0 };\n"\
/ *"PARAM constwhite = { 1.0, 1.0, 1.0, 1.0 };\n"\* /
"TEMP R0, R1, R2, R3, R4, R5;\n"\
"ADDRESS A0;\n"\
"ATTRIB texCoord = vertex.attrib[8];\n"\
"ATTRIB normal = vertex.attrib[2];\n"\
"ATTRIB index = vertex.attrib[3];\n"\
"ATTRIB weight = vertex.attrib[1];\n"\
"ATTRIB position = vertex.attrib[0];\n"\
"PARAM worldViewProjMatrix[4] = { state.matrix.mvp };\n"\
"PARAM diffuse = state.material.diffuse;\n"\
"PARAM ambient = state.material.ambient;\n"\
"PARAM lightDir = state.light[0].position;\n"\
"PARAM matrix[87] = { program.local[0..86] };\n"\
"\n"\
"MOV result.texcoord[0].xy, texCoord.xyxx;	\n"\
"\n"\
"MUL R4, index, constant.y;	\n"\
"\n"\
"ARL A0.x, R4.y;\n"\
"DP3 R0.x, matrix[A0.x].xyzx, normal.xyzx;\n"\
"DP3 R0.y, matrix[A0.x + 1].xyzx, normal.xyzx;\n"\
"DP3 R0.z, matrix[A0.x + 2].xyzx, normal.xyzx;\n"\
"MUL R1.yzw, R0.xxyz, weight.y;\n"\
"\n"\
"ARL A0.x, R4.x;\n"\
"DP3 R0.x, matrix[A0.x].xyzx, normal.xyzx;\n"\
"DP3 R0.y, matrix[A0.x + 1].xyzx, normal.xyzx;\n"\
"DP3 R0.z, matrix[A0.x + 2].xyzx, normal.xyzx;\n"\
"MAD R1.yzw, R0.xxyz, weight.x, R1.yyzw;\n"\
"\n"\
"DP3 R0.x, R1.yzwy, R1.yzwy;\n"\
"RSQ R0.x, R0.x;\n"\
"MUL R0.xyz, R0.x, R1.yzwy;\n"\
"DP3 R1.x, lightDir.xyzx, lightDir.xyzx;\n"\
"RSQ R1.x, R1.x;\n"\
"MUL R2.xyz, R1.x, lightDir.xyzx;\n"\
/* to use the hard coded shader uncomment the next line and comment the one after* /
/*"DP3 R0.x, R0.xyzx, ldir.xyzx;\n"\* /
"DP3 R0.x, R0.xyzx, R2.xyzx;\n"\
"MAX R0.x, R0.x, constant.z;\n"\
"MUL R0, R0.x, diffuse;\n"\
/*"MUL diffuse, constant.y, diffuse;\n"\* /
"ADD result.color.front.primary, R0, ambient;\n"\
/*"MUL result.color.front.primary.xyz, 1.2, result.color.front.primary.xyzy;\n"\* /
"MOV result.color.front.primary.w, ldir.w;\n"\
"\n"\
"ARL A0.x, R4.w;\n"\
"DPH R0.x, position.xyzx, matrix[A0.x];\n"\
"DPH R0.y, position.xyzx, matrix[A0.x + 1];\n"\
"DPH R0.z, position.xyzx, matrix[A0.x + 2];\n"\
"\n"\
"ARL A0.x, R4.z;\n"\
"DPH R3.x, position.xyzx, matrix[A0.x];\n"\
"DPH R3.y, position.xyzx, matrix[A0.x + 1];\n"\
"DPH R3.z, position.xyzx, matrix[A0.x + 2];\n"\
"\n"\
"ARL A0.x, R4.y;\n"\
"DPH R1.y, position.xyzx, matrix[A0.x];\n"\
"DPH R1.z, position.xyzx, matrix[A0.x + 1];\n"\
"DPH R1.w, position.xyzx, matrix[A0.x + 2];\n"\
"MUL R2.xyz, R1.yzwy, weight.y;\n"\
"\n"\
"ARL A0.x, R4.x;\n"\
"DPH R1.x, position.xyzx, matrix[A0.x];\n"\
"DPH R1.y, position.xyzx, matrix[A0.x + 1];\n"\
"DPH R1.z, position.xyzx, matrix[A0.x + 2];\n"\
"\n"\
"MAD R1.xyz, R1.xyzx, weight.x, R2.xyzx;\n"\
"MAD R1.xyz, R3.xyzx, weight.z, R1.xyzx;\n"\
"MAD R0.xyz, R0.xyzx, weight.w, R1.xyzx;\n"\
"\n"\
"DPH result.position.x, R0.xyzx, worldViewProjMatrix[0];\n"\
"DPH result.position.y, R0.xyzx, worldViewProjMatrix[1];\n"\
"DPH result.position.z, R0.xyzx, worldViewProjMatrix[2];\n"\
"DPH result.position.w, R0.xyzx, worldViewProjMatrix[3];\n"\
"END\n";
*/

// GLSL shader
const char *vertexProgramStr= 
"#version 110\n"\
"uniform mat4 Transforms[24];\n"\
"attribute vec4 Weights;\n"\
"attribute vec4 MatrixIndices;\n"\
"\n"\
"void DirectionalLight(in int i,\n"\
"                      in vec3 normal,\n"\
"                      inout vec4 ambient,\n"\
"                      inout vec4 diffuse,\n"\
"                      inout vec4 specular)\n"\
"{\n"\
"     float nDotVP;         // normal . light direction\n"\
"     float nDotHV;         // normal . light half vector\n"\
"     float pf;             // power factor\n"\
"\n"\
"     nDotVP = max(0.0, dot(normal,\n"\
"                   normalize(vec3(gl_LightSource[i].position))));\n"\
"     nDotHV = max(0.0, dot(normal, vec3(gl_LightSource[i].halfVector)));\n"\
"\n"\
"     if (nDotVP == 0.0)\n"\
"         pf = 0.0;\n"\
"     else\n"\
"         pf = pow(nDotHV, gl_FrontMaterial.shininess);\n"\
"\n"\
"     ambient  += gl_LightSource[i].ambient;\n"\
"     diffuse  += gl_LightSource[i].diffuse * nDotVP;\n"\
"     specular += gl_LightSource[i].specular * pf;\n"\
"}\n"\
"\n"\
"\n"\
"\n"\
"void PointLight(in int i,\n"\
"                in vec3 eye,\n"\
"                in vec3 ecPosition3,\n"\
"                in vec3 normal,\n"\
"                inout vec4 ambient,\n"\
"                inout vec4 diffuse,\n"\
"                inout vec4 specular)\n"\
"{\n"\
"    float nDotVP;         // normal . light direction\n"\
"    float nDotHV;         // normal . light half vector\n"\
"    float pf;             // power factor\n"\
"    float attenuation;    // computed attenuation factor\n"\
"    float d;              // distance from surface to light source\n"\
"    vec3  VP;             // direction from surface to light position\n"\
"    vec3  halfVector;     // direction of maximum highlights\n"\
"\n"\
"    // Compute vector from surface to light position\n"\
"    VP = vec3(gl_LightSource[i].position) - ecPosition3;\n"\
"\n"\
"    // Compute distance between surface and light position\n"\
"    d = length(VP);\n"\
"\n"\
"    // Normalize the vector from surface to light position\n"\
"    VP = normalize(VP);\n"\
"\n"\
"    // Compute attenuation\n"\
"    attenuation = 1.0 / (gl_LightSource[i].constantAttenuation +\n"\
"                         gl_LightSource[i].linearAttenuation * d +\n"\
"                         gl_LightSource[i].quadraticAttenuation * d * d);\n"\
"\n"\
"    halfVector = normalize(VP + eye);\n"\
"\n"\
"    nDotVP = max(0.0, dot(normal, VP));\n"\
"    nDotHV = max(0.0, dot(normal, halfVector));\n"\
"\n"\
"    if (nDotVP == 0.0)\n"\
"        pf = 0.0;\n"\
"    else\n"\
"        pf = pow(nDotHV, gl_FrontMaterial.shininess);\n"\
"\n"\
"    ambient += gl_LightSource[i].ambient * attenuation;\n"\
"    diffuse += gl_LightSource[i].diffuse * nDotVP * attenuation;\n"\
"    specular += gl_LightSource[i].specular * pf * attenuation;\n"\
"}\n"\
"\n"\
"\n"\
"void SpotLight(in int i,\n"\
"               in vec3 eye,\n"\
"               in vec3 ecPosition3,\n"\
"               in vec3 normal,\n"\
"               inout vec4 ambient,\n"\
"               inout vec4 diffuse,\n"\
"               inout vec4 specular)\n"\
"{\n"\
"    float nDotVP;           // normal . light direction\n"\
"    float nDotHV;           // normal . light half vector\n"\
"    float pf;               // power factor\n"\
"    float spotDot;          // cosine of angle between spotlight\n"\
"    float spotAttenuation;  // spotlight attenuation factor\n"\
"    float attenuation;      // computed attenuation factor\n"\
"    float d;                // distance from surface to light source\n"\
"    vec3 VP;                // direction from surface to light position\n"\
"    vec3 halfVector;        // direction of maximum highlights\n"\
"\n"\
"    // Compute vector from surface to light position\n"\
"    VP = vec3(gl_LightSource[i].position) - ecPosition3;\n"\
"\n"\
"    // Compute distance between surface and light position\n"\
"    d = length(VP);\n"\
"\n"\
"    // Normalize the vector from surface to light position\n"\
"    VP = normalize(VP);\n"\
"\n"\
"    // Compute attenuation\n"\
"    attenuation = 1.0 / (gl_LightSource[i].constantAttenuation +\n"\
"                         gl_LightSource[i].linearAttenuation * d +\n"\
"                         gl_LightSource[i].quadraticAttenuation * d * d);\n"\
"\n"\
"    // See if point on surface is inside cone of illumination\n"\
"    spotDot = dot(-VP, normalize(gl_LightSource[i].spotDirection));\n"\
"\n"\
"    if (spotDot < gl_LightSource[i].spotCosCutoff)\n"\
"        spotAttenuation = 0.0; // light adds no contribution\n"\
"    else\n"\
"        spotAttenuation = pow(spotDot, gl_LightSource[i].spotExponent);\n"\
"\n"\
"    // Combine the spotlight and distance attenuation.\n"\
"    attenuation *= spotAttenuation;\n"\
"\n"\
"    halfVector = normalize(VP + eye);\n"\
"\n"\
"    nDotVP = max(0.0, dot(normal, VP));\n"\
"    nDotHV = max(0.0, dot(normal, halfVector));\n"\
"\n"\
"    if (nDotVP == 0.0)\n"\
"        pf = 0.0;\n"\
"    else\n"\
"        pf = pow(nDotHV, gl_FrontMaterial.shininess);\n"\
"\n"\
"    ambient  += gl_LightSource[i].ambient * attenuation;\n"\
"    diffuse  += gl_LightSource[i].diffuse * nDotVP * attenuation;\n"\
"    specular += gl_LightSource[i].specular * pf * attenuation;\n"\
"}\n"\
"\n"\
"	const vec4 AMBIENT_BLACK = vec4(0.0, 0.0, 0.0, 1.0);\n"\
"	const vec4 DEFAULT_BLACK = vec4(0.0, 0.0, 0.0, 0.0);\n"\
"	\n"\
"	bool isLightEnabled(in int i)\n"\
"	{\n"\
"	    // A separate variable is used to get\n"\
"	    // rid of a linker error.\n"\
"	    bool enabled = true;\n"\
"\n"\
"	    // If all the colors of the Light are set\n"\
"	    // to BLACK then we know we don't need to bother\n"\
"	    // doing a lighting calculation on it.\n"\
"	    if ((gl_LightSource[i].ambient  == AMBIENT_BLACK) &&\n"\
"	        (gl_LightSource[i].diffuse  == DEFAULT_BLACK) &&\n"\
"	        (gl_LightSource[i].specular == DEFAULT_BLACK))\n"\
"	        enabled = false;\n"\
"\n"\
"	    return(enabled);\n"\
"	}\n"\
"\n"\
"\n"\
"//void doLight(in int i, vec3 ecPosition3, vec3 eye, vec3 normal, vec4 amb, vec4 diff, vec4 spec)\n"\
"//{\n"\
"//		if (!isLightEnabled(i))\n"\
"//			return;\n"\
"//	    if (gl_LightSource[i].position.w == 0.0)\n"\
"//	        DirectionalLight(i, normal, amb, diff, spec);\n"\
"//	    else if (gl_LightSource[i].spotCutoff == 180.0)\n"\
"//	        PointLight(i, eye, ecPosition3, normal, amb, diff, spec);\n"\
"//	    else\n"\
"//	        SpotLight(i, eye, ecPosition3, normal, amb, diff, spec);\n"\
"//}\n"\
"\n"\
"void lighting(vec3 normal)\n"\
"{\n"\
"	vec4 ecPosition;\n"\
"	vec3 ecPosition3;    // in 3 space\n"\
"\n"\
"	// Transform vertex to eye coordinates\n"\
"	//if (NeedEyePosition)\n"\
"	//{\n"\
"		ecPosition  = gl_ModelViewMatrix * gl_Vertex;\n"\
"		ecPosition3 = (vec3(ecPosition)) / ecPosition.w;\n"\
"	//}\n"\
"\n"\
"	vec3 eye;\n"\
"	//if (LocalViewer)\n"\
"	//   eye = -normalize(ecPosition3);\n"\
"	//else\n"\
"	   eye = vec3(0.0, 0.0, 1.0);\n"\
"\n"\
"	vec4 amb = vec4(0.0);\n"\
"	vec4 diff = vec4(0.0);\n"\
"	vec4 spec = vec4(0.0);\n"\
"\n"\
"	// Loop through enabled lights, compute contribution from each\n"\
"   //doLight(0, ecPosition3, eye, normal, amb, diff, spec);\n"\
"   //doLight(1, ecPosition3, eye, normal, amb, diff, spec);\n"\
"   //doLight(2, ecPosition3, eye, normal, amb, diff, spec);\n"\
"   //doLight(3, ecPosition3, eye, normal, amb, diff, spec);\n"\
"	for (int i = 0; i < 8; i++)\n"\
"	{\n"\
"		if (!isLightEnabled(i))\n"\
"			continue;\n"\
"	    if (gl_LightSource[i].position.w == 0.0)\n"\
"	        DirectionalLight(i, normal, amb, diff, spec);\n"\
"	    else if (gl_LightSource[i].spotCutoff == 180.0)\n"\
"	        PointLight(i, eye, ecPosition3, normal, amb, diff, spec);\n"\
"	    else\n"\
"	        SpotLight(i, eye, ecPosition3, normal, amb, diff, spec);\n"\
"	}\n"\
"\n"\
"	vec4 color = gl_FrontLightModelProduct.sceneColor +\n"\
"            amb * gl_FrontMaterial.ambient +\n"\
"            diff * gl_FrontMaterial.diffuse +\n"\
"			 spec * gl_FrontMaterial.specular;\n"\
"	gl_FrontColor = color;\n"\
"\n"\
"}\n"\
"\n"\
"void main()\n"\
"{\n"\
"   mat4 transform  = Weights.x*Transforms[int(MatrixIndices.x)];\n"\
"        transform += Weights.y*Transforms[int(MatrixIndices.y)];\n"\
"        transform += Weights.z*Transforms[int(MatrixIndices.x)];\n"\
"        transform += Weights.w*Transforms[int(MatrixIndices.w)];\n"\
"	gl_Position = transform * gl_Vertex;\n"\
"\n"\
"   mat3 normalTransform;\n"\
"	normalTransform[0] = transform[0].xyz;\n"\
"	normalTransform[1] = transform[1].xyz;\n"\
"	normalTransform[2] = transform[2].xyz;\n"\
"	// Skin the vertex normal, then compute lighting.\n"\
"   vec3 normal = normalize(normalTransform* gl_Normal);\n"\
"\n"\
"	lighting(normal);\n"\
"\n"\
"	//if (SecondaryColor)\n"\
"	//	gl_FrontSecondaryColor = gl_SecondaryColor;\n"\
"	//gl_FrontColor = gl_FrontMaterial.diffuse;\n"\
"\n"\
"	gl_TexCoord[0] = gl_MultiTexCoord0;\n"\
"	gl_Position = gl_ModelViewProjectionMatrix * gl_Position;\n"\
"}\n";



// GLSL shader
const char *vertexProgramMorphsStr= 
"uniform mat4 Transforms[24];\n"\
"uniform vec4 MorphWeights;\n"\
"attribute vec4 Weights;\n"\
"attribute vec4 MatrixIndices;\n"\
"attribute vec3 MorphPosition1;\n"\
"attribute vec3 MorphNormal1;\n"\
"attribute vec3 MorphPosition2;\n"\
"attribute vec3 MorphNormal2;\n"\
"attribute vec3 MorphPosition3;\n"\
"attribute vec3 MorphNormal3;\n"\
"attribute vec3 MorphPosition4;\n"\
"attribute vec3 MorphNormal4;\n"\
"\n"\
"void DirectionalLight(in int i,\n"\
"                      in vec3 normal,\n"\
"                      inout vec4 ambient,\n"\
"                      inout vec4 diffuse,\n"\
"                      inout vec4 specular)\n"\
"{\n"\
"     float nDotVP;         // normal . light direction\n"\
"     float nDotHV;         // normal . light half vector\n"\
"     float pf;             // power factor\n"\
"\n"\
"     nDotVP = max(0.0, dot(normal,\n"\
"                   normalize(vec3(gl_LightSource[i].position))));\n"\
"     nDotHV = max(0.0, dot(normal, vec3(gl_LightSource[i].halfVector)));\n"\
"\n"\
"     if (nDotVP == 0.0)\n"\
"         pf = 0.0;\n"\
"     else\n"\
"         pf = pow(nDotHV, gl_FrontMaterial.shininess);\n"\
"\n"\
"     ambient  += gl_LightSource[i].ambient;\n"\
"     diffuse  += gl_LightSource[i].diffuse * nDotVP;\n"\
"     specular += gl_LightSource[i].specular * pf;\n"\
"}\n"\
"\n"\
"\n"\
"\n"\
"void PointLight(in int i,\n"\
"                in vec3 eye,\n"\
"                in vec3 ecPosition3,\n"\
"                in vec3 normal,\n"\
"                inout vec4 ambient,\n"\
"                inout vec4 diffuse,\n"\
"                inout vec4 specular)\n"\
"{\n"\
"    float nDotVP;         // normal . light direction\n"\
"    float nDotHV;         // normal . light half vector\n"\
"    float pf;             // power factor\n"\
"    float attenuation;    // computed attenuation factor\n"\
"    float d;              // distance from surface to light source\n"\
"    vec3  VP;             // direction from surface to light position\n"\
"    vec3  halfVector;     // direction of maximum highlights\n"\
"\n"\
"    // Compute vector from surface to light position\n"\
"    VP = vec3(gl_LightSource[i].position) - ecPosition3;\n"\
"\n"\
"    // Compute distance between surface and light position\n"\
"    d = length(VP);\n"\
"\n"\
"    // Normalize the vector from surface to light position\n"\
"    VP = normalize(VP);\n"\
"\n"\
"    // Compute attenuation\n"\
"    attenuation = 1.0 / (gl_LightSource[i].constantAttenuation +\n"\
"                         gl_LightSource[i].linearAttenuation * d +\n"\
"                         gl_LightSource[i].quadraticAttenuation * d * d);\n"\
"\n"\
"    halfVector = normalize(VP + eye);\n"\
"\n"\
"    nDotVP = max(0.0, dot(normal, VP));\n"\
"    nDotHV = max(0.0, dot(normal, halfVector));\n"\
"\n"\
"    if (nDotVP == 0.0)\n"\
"        pf = 0.0;\n"\
"    else\n"\
"        pf = pow(nDotHV, gl_FrontMaterial.shininess);\n"\
"\n"\
"    ambient += gl_LightSource[i].ambient * attenuation;\n"\
"    diffuse += gl_LightSource[i].diffuse * nDotVP * attenuation;\n"\
"    specular += gl_LightSource[i].specular * pf * attenuation;\n"\
"}\n"\
"\n"\
"\n"\
"void SpotLight(in int i,\n"\
"               in vec3 eye,\n"\
"               in vec3 ecPosition3,\n"\
"               in vec3 normal,\n"\
"               inout vec4 ambient,\n"\
"               inout vec4 diffuse,\n"\
"               inout vec4 specular)\n"\
"{\n"\
"    float nDotVP;           // normal . light direction\n"\
"    float nDotHV;           // normal . light half vector\n"\
"    float pf;               // power factor\n"\
"    float spotDot;          // cosine of angle between spotlight\n"\
"    float spotAttenuation;  // spotlight attenuation factor\n"\
"    float attenuation;      // computed attenuation factor\n"\
"    float d;                // distance from surface to light source\n"\
"    vec3 VP;                // direction from surface to light position\n"\
"    vec3 halfVector;        // direction of maximum highlights\n"\
"\n"\
"    // Compute vector from surface to light position\n"\
"    VP = vec3(gl_LightSource[i].position) - ecPosition3;\n"\
"\n"\
"    // Compute distance between surface and light position\n"\
"    d = length(VP);\n"\
"\n"\
"    // Normalize the vector from surface to light position\n"\
"    VP = normalize(VP);\n"\
"\n"\
"    // Compute attenuation\n"\
"    attenuation = 1.0 / (gl_LightSource[i].constantAttenuation +\n"\
"                         gl_LightSource[i].linearAttenuation * d +\n"\
"                         gl_LightSource[i].quadraticAttenuation * d * d);\n"\
"\n"\
"    // See if point on surface is inside cone of illumination\n"\
"    spotDot = dot(-VP, normalize(gl_LightSource[i].spotDirection));\n"\
"\n"\
"    if (spotDot < gl_LightSource[i].spotCosCutoff)\n"\
"        spotAttenuation = 0.0; // light adds no contribution\n"\
"    else\n"\
"        spotAttenuation = pow(spotDot, gl_LightSource[i].spotExponent);\n"\
"\n"\
"    // Combine the spotlight and distance attenuation.\n"\
"    attenuation *= spotAttenuation;\n"\
"\n"\
"    halfVector = normalize(VP + eye);\n"\
"\n"\
"    nDotVP = max(0.0, dot(normal, VP));\n"\
"    nDotHV = max(0.0, dot(normal, halfVector));\n"\
"\n"\
"    if (nDotVP == 0.0)\n"\
"        pf = 0.0;\n"\
"    else\n"\
"        pf = pow(nDotHV, gl_FrontMaterial.shininess);\n"\
"\n"\
"    ambient  += gl_LightSource[i].ambient * attenuation;\n"\
"    diffuse  += gl_LightSource[i].diffuse * nDotVP * attenuation;\n"\
"    specular += gl_LightSource[i].specular * pf * attenuation;\n"\
"}\n"\
"\n"\
"	const vec4 AMBIENT_BLACK = vec4(0.0, 0.0, 0.0, 1.0);\n"\
"	const vec4 DEFAULT_BLACK = vec4(0.0, 0.0, 0.0, 0.0);\n"\
"	\n"\
"	bool isLightEnabled(in int i)\n"\
"	{\n"\
"	    // A separate variable is used to get\n"\
"	    // rid of a linker error.\n"\
"	    bool enabled = true;\n"\
"\n"\
"	    // If all the colors of the Light are set\n"\
"	    // to BLACK then we know we don't need to bother\n"\
"	    // doing a lighting calculation on it.\n"\
"	    if ((gl_LightSource[i].ambient  == AMBIENT_BLACK) &&\n"\
"	        (gl_LightSource[i].diffuse  == DEFAULT_BLACK) &&\n"\
"	        (gl_LightSource[i].specular == DEFAULT_BLACK))\n"\
"	        enabled = false;\n"\
"\n"\
"	    return(enabled);\n"\
"	}\n"\
"\n"\
"\n"\
"//void doLight(in int i, vec3 ecPosition3, vec3 eye, vec3 normal, vec4 amb, vec4 diff, vec4 spec)\n"\
"//{\n"\
"//		if (!isLightEnabled(i))\n"\
"//			return;\n"\
"//	    if (gl_LightSource[i].position.w == 0.0)\n"\
"//	        DirectionalLight(i, normal, amb, diff, spec);\n"\
"//	    else if (gl_LightSource[i].spotCutoff == 180.0)\n"\
"//	        PointLight(i, eye, ecPosition3, normal, amb, diff, spec);\n"\
"//	    else\n"\
"//	        SpotLight(i, eye, ecPosition3, normal, amb, diff, spec);\n"\
"//}\n"\
"\n"\
"void lighting(vec3 normal)\n"\
"{\n"\
"	vec4 ecPosition;\n"\
"	vec3 ecPosition3;    // in 3 space\n"\
"\n"\
"	// Transform vertex to eye coordinates\n"\
"	//if (NeedEyePosition)\n"\
"	//{\n"\
"		ecPosition  = gl_ModelViewMatrix * gl_Vertex;\n"\
"		ecPosition3 = (vec3(ecPosition)) / ecPosition.w;\n"\
"	//}\n"\
"\n"\
"	vec3 eye;\n"\
"	//if (LocalViewer)\n"\
"	//   eye = -normalize(ecPosition3);\n"\
"	//else\n"\
"	   eye = vec3(0.0, 0.0, 1.0);\n"\
"\n"\
"	vec4 amb = vec4(0.0);\n"\
"	vec4 diff = vec4(0.0);\n"\
"	vec4 spec = vec4(0.0);\n"\
"\n"\
"	// Loop through enabled lights, compute contribution from each\n"\
"   //doLight(0, ecPosition3, eye, normal, amb, diff, spec);\n"\
"   //doLight(1, ecPosition3, eye, normal, amb, diff, spec);\n"\
"   //doLight(2, ecPosition3, eye, normal, amb, diff, spec);\n"\
"   //doLight(3, ecPosition3, eye, normal, amb, diff, spec);\n"\
"	for (int i = 0; i < 8; i++)\n"\
"	{\n"\
"		if (!isLightEnabled(i))\n"\
"			continue;\n"\
"	    if (gl_LightSource[i].position.w == 0.0)\n"\
"	        DirectionalLight(i, normal, amb, diff, spec);\n"\
"	    else if (gl_LightSource[i].spotCutoff == 180.0)\n"\
"	        PointLight(i, eye, ecPosition3, normal, amb, diff, spec);\n"\
"	    else\n"\
"	        SpotLight(i, eye, ecPosition3, normal, amb, diff, spec);\n"\
"	}\n"\
"\n"\
"	vec4 color = gl_FrontLightModelProduct.sceneColor +\n"\
"            amb * gl_FrontMaterial.ambient +\n"\
"            diff * gl_FrontMaterial.diffuse +\n"\
"			 spec * gl_FrontMaterial.specular;\n"\
"	gl_FrontColor = color;\n"\
"\n"\
"}\n"\
"\n"\
"void main()\n"\
"{\n"\
"	vec4 position = gl_Vertex;\n"\
"	position.xyz += MorphWeights.x*MorphPosition1.xyz;\n"\
"	position.xyz += MorphWeights.y*MorphPosition2.xyz;\n"\
"	position.xyz += MorphWeights.z*MorphPosition3.xyz;\n"\
"	position.xyz += MorphWeights.w*MorphPosition4.xyz;\n"\
"   mat4 transform  = Weights.x*Transforms[int(MatrixIndices.x)];\n"\
"        transform += Weights.y*Transforms[int(MatrixIndices.y)];\n"\
"        transform += Weights.z*Transforms[int(MatrixIndices.x)];\n"\
"        transform += Weights.w*Transforms[int(MatrixIndices.w)];\n"\
"	gl_Position = transform * position;\n"\
"\n"\
"   mat3 normalTransform;\n"\
"	normalTransform[0] = transform[0].xyz;\n"\
"	normalTransform[1] = transform[1].xyz;\n"\
"	normalTransform[2] = transform[2].xyz;\n"\
"	// Skin the vertex normal, then compute lighting.\n"\
"   vec3 normal = gl_Normal;\n"\
"	normal += MorphWeights.x*MorphNormal1;\n"\
"	normal += MorphWeights.y*MorphNormal2;\n"\
"	normal += MorphWeights.z*MorphNormal3;\n"\
"	normal += MorphWeights.w*MorphNormal4;\n"\
"   normal = normalize(normalTransform* normal);\n"\
"\n"\
"	lighting(normal);\n"\
"\n"\
"	//if (SecondaryColor)\n"\
"	//	gl_FrontSecondaryColor = gl_SecondaryColor;\n"\
"	//gl_FrontColor = gl_FrontMaterial.diffuse;\n"\
"\n"\
"	gl_TexCoord[0] = gl_MultiTexCoord0;\n"\
"	gl_Position = gl_ModelViewProjectionMatrix * gl_Position;\n"\
"}\n";


int printOglError()
{
        GLenum  glErr;
        int     retCode = 0;
        char    *err;

  //std::cout << "printing GL Errors \n";
  // returns 1 if an OpenGL error occurred, 0 otherwise.
  glErr = glGetError();
  while (glErr != GL_NO_ERROR) {
    err = (char*)gluErrorString(glErr);
	std::cout << "glError: " << err << std::endl;
    retCode = 1;
    glErr = glGetError();
  }
  return retCode;
}

void printShaderInfoLog(GLuint shader)
{
        GLint   infologLength = 0, shaderType;
        GLint   charsWritten = 0;
        GLchar  *infoLog;

  printOglError();

  glGetShaderiv(shader,GL_SHADER_TYPE,&shaderType);
  glGetShaderiv(shader,GL_INFO_LOG_LENGTH,&infologLength);

  printOglError();

  if(infologLength > 0) {
    if((infoLog = (GLchar *)malloc(infologLength)) == NULL) {
      fprintf(stderr,"ERROR: Could not allocate InfoLog buffer\n");
      exit(1);
    }
    glGetShaderInfoLog(shader,infologLength,&charsWritten,infoLog);
    if(charsWritten) {
      if(shaderType == GL_VERTEX_SHADER)
		  std::cerr << "Vertex Shader InfoLog:\n" << infoLog << "\n\n";
      else if(shaderType == GL_FRAGMENT_SHADER)
		  std::cerr << "Fragment Shader InfoLog:\n" << infoLog << "\n\n";
      else
		  std::cerr << "Unknown Shader InfoLog:\n" << infoLog << "\n\n";
    }
    free(infoLog);
  }
  printOglError();
}

void printProgramInfoLog(GLuint obj)
{
        GLint   infologLength = 0;
        GLint   charsWritten = 0;
        GLchar  *infoLog;

  glGetProgramiv(obj,GL_INFO_LOG_LENGTH,&infologLength);

  printOglError();

  if(infologLength > 0) {
    if((infoLog = (GLchar *)malloc(infologLength)) == NULL) {
      fprintf(stderr,"ERROR: Could not allocate program infolog buffer\n");
      exit(1);
    }
    glGetProgramInfoLog(obj,infologLength,&charsWritten,infoLog);
	if(charsWritten) std::cerr << "Progarm InfoLog:\n" << infoLog << std::endl;
    free(infoLog);
  }
  printOglError();
}




#include "AvatarCal3dImp.h"

#include "PiavcaAPI/Avatar.h"
#include "PiavcaAPI/Motion.h"
#include "PiavcaAPI/PiavcaCore.h"
#include "StdMotionImp/StdMotionImp.h"
#include "PiavcaAPI/Vec.h"
#include "PiavcaAPI/Quat.h"
#include "Cal3dMathsConversion.h"

#include "MotionCal3dImp.h"

// hack to make everything work with both cal3d 10 and 11
#ifndef CAL_REF_PTR_H
typedef CalCoreMesh *CalCoreMeshPtr;
#define get_pointer(x) (x)
#endif


//#ifdef _WIN32
//#include <windows.h>
//#endif

#include <string>
#include <sstream>

#include "TextureHandler.h"

using namespace Piavca;

#include <assert.h>
#include <algorithm>
using std::cout;
using std::endl;


AvatarCal3DImp *AvatarCal3DImp::getAvatarImp(Avatar *avatar) 
{
	AvatarCal3DImp *Cal3Dimp = dynamic_cast<AvatarCal3DImp *>(getAvatarImpInternal(avatar)); 
	if(Cal3Dimp)
		return Cal3Dimp;
	else
	{
		Piavca::Error(_T("Trying to use a non Cal3D avatar in Cal3D"));
		return NULL;
	}
};

std::string strPath;

AvatarCal3DImp::AvatarCal3DImp(tstring avatarId, TextureHandler *_textureHandler, bool bailOnMissedJoints, const Vec &Position, const Quat &Orientation)
  : cal_model(NULL), previous_time(0), renderBuffer(0), hardware(false), m_calHardwareModel(NULL),
    updateBuffer(0), textureHandler(_textureHandler), bb_dirty_flag(true), scaleFactor(1.0f) 
{
	std::cout << "start of the AvatarCal3dimp constructor\n";

	if(doubleBuffer) 
	{
		renderBuffer = 0;
		updateBuffer = 1;
	}

	expressions.assign((-Piavca::Core::getCore()->getMaxExpressionId())+1, FacialExpressionHolder());
  
    // open the model configuration file
	std::string strFilename = avatarId + ".cfg";
	std::ifstream file;
	file.open(strFilename.c_str(), std::ios::in | std::ios::binary);
	if(!file)
	{
		Piavca::Error("Failed to open model configuration file '" + strFilename + "'." );
	}
	// flip Z and Y axis to fix max outputs
	//CalLoader::setLoadingMode(LOADER_ROTATE_X_AXIS);

	CalCoreModel *cal_core_model = new CalCoreModel("dummy");

	// initialize the data path
	strPath = strFilename.substr(0, strFilename.find_last_of("\\/") + 1);

	int lastMeshId = -1;
	// parse all lines from the model configuration file
	int line;
	
	float scale = 1.0f;
	for(line = 1; ; line++)
	{
		// read the next model configuration line
		std::string strBuffer;
		std::getline(file, strBuffer);

		// stop if we reached the end of file
		if(file.eof()) break;

		// check if an error happend while reading from the file
		if(!file)
		{
			Piavca::Error("Error while reading from the model configuration file '" + strFilename + "'.");

		}

		// find the first non-whitespace character
		std::string::size_type pos;
		pos = strBuffer.find_first_not_of(" \t");

		// check for empty lines
		if((pos == std::string::npos) || (strBuffer[pos] == '\n') || (strBuffer[pos] == '\r') || (strBuffer[pos] == 0)) continue;

		// check for comment lines
		if(strBuffer[pos] == '#') continue;

		// get the key
		std::string strKey;
		strKey = strBuffer.substr(pos, strBuffer.find_first_of(" =\t\n\r", pos) - pos);
		pos += strKey.size();

		// get the '=' character
		pos = strBuffer.find_first_not_of(" \t", pos);
		if((pos == std::string::npos) || (strBuffer[pos] != '='))
		{
			std::ostringstream os;
			os << strFilename << "(" << line << "): Invalid syntax.";
			Piavca::Error(StringToTString(os.str()));
		}

		// find the first non-whitespace character after the '=' character
		pos = strBuffer.find_first_not_of(" \t", pos + 1);

		// get the data
		std::string strData;
		strData = strBuffer.substr(pos, strBuffer.find_first_of("\n\r", pos) - pos);

		// handle the model creation
		if(strKey[0] == '#')
		{
			// do nothing this is a comment
		}
		else if(strKey == "path")
		{
			// set the new path for the data files if one hasn't been set already
			strPath = strData;
		}
		else if(strKey == "skeleton")
		{
			// load core skeleton
			std::cout << "Loading skeleton lala  '" << strData << "'..." << std::endl;
			if(!cal_core_model->loadCoreSkeleton(strPath + strData))
			{
				CalError::printLastError();
				Piavca::Error(_T("Error loading skeleton"));
			}
			CalCoreSkeleton *skel = cal_core_model->getCoreSkeleton();
			// if there are any joints in the Cal3d Skeleton that don't already exist in 
			// Piavca add them
			std::vector<CalCoreBone *>& bones = skel->getVectorCoreBone();
			for(int i = 0; i < (int) bones.size(); i++)
			{
				int jointid = Piavca::Core::getCore()->getJointId(StringToTString(bones[i]->getName()));
				if (jointid == Piavca::Core::nullId)//< 0)
				{
					StringVector jointNames;
					if (i == 0)
					{
						std::cout << "ROOT JOINT " <<  bones[i]->getName() << std::endl;
						jointNames.push_back(_T("Root Orientation"));
					}
					jointNames.push_back(StringToTString(bones[i]->getName()));
					std::cout << "Adding Joint "<< i << ": " << bones[i]->getName() << std::endl;
					Piavca::Core::getCore()->addJointNameSet(jointNames);
				}	
			}
			joints.assign(Piavca::Core::getCore()->getMaxJointId()+1, JointHolder());
		}
		else if(strKey == "mesh")
		{
			// load core mesh
			std::string strFilename = strPath + strData;
			std::cout << "Loading mesh '" << strFilename << "'..." << std::endl;
			lastMeshId = cal_core_model->loadCoreMesh(strFilename);
			std::cout << "Finished Loading mesh '" << strFilename << "'..." << std::endl;
			if(lastMeshId == -1)
			{
				CalError::printLastError();
				Piavca::Error(_T("Error loading mesh"));
			}
			int pos = strData.rfind(".");
			std::string meshname = strData.substr(0, pos);
			meshes.push_back(std::make_pair(StringToTString(meshname), false));
			std::cout << "added mesh" << meshname << std::endl;
			if (meshes.size()-1 != lastMeshId)
				Piavca::Error(_T("Meshid doesn't match"));
		}
		else if(strKey == "material")
		{
			// load core material
			std::string strFilename = strPath + strData;
			std::cout << "Loading material '" << strFilename << "'..." << std::endl;
			if(cal_core_model->loadCoreMaterial(strFilename) == -1)
			{
				CalError::printLastError();
				Piavca::Error(_T("Error loading material"));
			}
		}
		else if(strKey == "morphtarget")
		{
			std::string strFilename = strPath + strData;
			//std::cout << "Loading mesh as morph target '" << strFilename << "'..." << std::endl;
			CalCoreMeshPtr pCoreMesh = CalLoader::loadCoreMesh(strFilename);
			if(pCoreMesh == 0 || lastMeshId < 0) 
			{
				CalError::printLastError();
				Piavca::Error(_T("Error loading morph targets"));
			}
			int morphtargetId = cal_core_model->getCoreMesh(lastMeshId)->addAsMorphTarget(get_pointer(pCoreMesh));
			if(morphtargetId < 0) 
			{
				CalError::printLastError();
				Piavca::Error(_T("Error loading morph targets"));
			}

			// find the first non-whitespace character
			std::string::size_type pos = 0;
			pos = strData.find_first_of(".", pos);
			std::string strName = strData.substr(0, pos);
			int expressionId = Piavca::Core::getCore()->getExpressionId(StringToTString(strName));
			if(expressionId == Piavca::Core::nullId)
			{
				StringVector exprNames;
				exprNames.push_back(StringToTString(strName));
				//std::cout << "Adding Joint "<< strName << std::endl;
				Piavca::Core::getCore()->addExpressionNameSet(exprNames);
				expressionId = Piavca::Core::getCore()->getExpressionId(StringToTString(strName));
			}
			// facial expression ids are negative, to distinguish then from
			// joint ids
			//std::cout << "Expression id " << expressionId << std::endl;
			expressionId = -expressionId;
			if(expressionId >= expressions.size())
			{
				expressions.insert(expressions.end(), expressionId - (expressions.size()-1), FacialExpressionHolder());
			}
			expressions[expressionId].name = StringToTString(strName);
			expressions[expressionId].meshId = lastMeshId;
			expressions[expressionId].morphtargetId = morphtargetId;
		}
		else if(strKey == "animation")
		{
			std::string strFilename = strPath + strData;
			std::cout << "Loading animation '" << strFilename << "'..." << std::endl;
			// extract the animation name
 			std::string::size_type pos = 0;
			pos = strData.find_first_of(".", pos);
			std::string strName = strData.substr(0, pos);
			// load an animation
			MotionImp *imp = new MotionCal3DImp(strFilename, cal_core_model->getCoreSkeleton());
			Motion *tmot = new KeyframeMotion(imp);
			Piavca::Core::getCore()->loadMotion(StringToTString(strName), tmot); 
		}
		else if(strKey == "scale")
		{
			std::stringstream s;
			s.str(strData);
			s >> scale;
			std::cout << "scaleFactor " << scale << std::endl;
		}
		else if(strKey == "vertexshader")
		{
			std::string strFilename = strPath + strData;
			std::cout << "vertex shader " << strFilename << std::endl;
			std::ifstream file;
			file.open(strFilename.c_str(), std::ios::in | std::ios::binary);
			if(!file)
			{
				Piavca::Error("Failed to open vertex shader file '" + strFilename + "'." );
			}
			vertexShader = "";
			while (true)
			{
				// read the next model configuration line
				std::string strBuffer;
				std::getline(file, strBuffer);
				
				// stop if we reached the end of file
				if(file.eof()) break;
				vertexShader.append(strBuffer + "\n");
			}
			std::cout << vertexShader << std::endl;
		}
		else if(strKey == "fragmentshader")
		{
			std::string strFilename = strPath + strData;
			std::cout << "fragment shader " << strFilename << std::endl;
			std::ifstream file;
			file.open(strFilename.c_str(), std::ios::in | std::ios::binary);
			if(!file)
			{
				Piavca::Error("Failed to open fragment shader file '" + strFilename + "'." );
			}
			fragmentShader = "";
			while (true)
			{
				// read the next model configuration line
				std::string strBuffer;
				std::getline(file, strBuffer);
				
				// stop if we reached the end of file
				if(file.eof()) break;
				fragmentShader.append(strBuffer + "\n");
			}
			std::cout << fragmentShader << std::endl;
		}
		else
		{
			std::ostringstream os;
			os << strFilename << "(" << line << "): Invalid syntax.";
			Piavca::Error(StringToTString(os.str()));
		}
	}

	// explicitely close the file
	file.close();


	// make one material thread for each material
	// NOTE: this is not the right way to do it, but this viewer can't do the right
	// mapping without further information on the model etc.
	int materialId;
	for(materialId = 0; materialId < cal_core_model->getCoreMaterialCount(); materialId++)
	{
		// create the a material thread
		cal_core_model->createCoreMaterialThread(materialId);

		// initialize the material thread
		cal_core_model->setCoreMaterialId(materialId, 0, materialId);
	}

  // Calculate Bounding Boxes

	cal_core_model->getCoreSkeleton()->calculateBoundingBoxes(cal_core_model);

	// create the model from the core model
	cal_model = new CalModel(cal_core_model);

	// attach all meshes to the model
	int meshId;
	for(meshId = 0; meshId < cal_core_model->getCoreMeshCount(); meshId++)
	{
		//std::cout << meshId << " ";
		cal_model->attachMesh(meshId);
	}

	// set the material set of the whole model
	cal_model->setMaterialSet(0);

	//std::cout << "looking for joints\n";
	int i,j;
	// load the joint map
	CalSkeleton *skel = cal_model->getSkeleton();
	std::vector< std::pair< tstring, int > > jointAssociations = Piavca::Core::getCore()->getJointNameAssociations();
	for(i = 0; i < (int) jointAssociations.size(); i++)
	{
		int cal3Did = skel->getCoreSkeleton()->getCoreBoneId(TStringToString(jointAssociations[i].first));
		if(cal3Did > 0)
		{
			//std::cout << "found joint " << "[" << cal3Did << "] " << jointAssociations[i].first << std::endl;
			joints[jointAssociations[i].second].cal3dId = cal3Did;
			joints[jointAssociations[i].second].name = jointAssociations[i].first;
		}
	}
	// find the parents of each joint
	for(i = 0; i < (int) joints.size(); i++)
	{	  
		if(joints[i].cal3dId < 0) continue;
		CalCoreBone *corebone = skel->getBone(joints[i].cal3dId)->getCoreBone();
		int parentId = corebone->getParentId();
		for(j = 0; j < (int) joints.size(); j++)
			if(joints[j].cal3dId == parentId)
			{
				joints[i].parent = j;
				break;
			}
	}

	setScale(scale); 
	
	//Find the amounts of memory we will need for each submesh
	CalRenderer* renderer = new CalRenderer(cal_model->getRenderer());

	int meshCount = renderer->getMeshCount();

	int numBuffers = 1;
	if(doubleBuffer) numBuffers = 2;

	//Initialize mVertices, mNormals, mFaces, mTextureCoordCounts sizes for
	//the mesh count with dummy vectors
	std::vector< float* > tempVecF; tempVecF.clear();
	std::vector< int* > tempVecI; tempVecI.clear();
	std::vector< int > tempVec0; tempVec0.clear();

	std::vector< std::vector< float* > > tempVecVecF; tempVecF.clear();
	std::vector< std::vector< int* > > tempVecVecI; tempVecI.clear();
	std::vector< std::vector< int > > tempVecVec0; tempVec0.clear();

	mVertices.resize(numBuffers, tempVecVecF);
	mNormals.resize(numBuffers, tempVecVecF);
	mFaces.resize(numBuffers, tempVecVecI);
	mTextureCoords.resize(numBuffers, tempVecVecF);
	mTextureCoordCounts.resize(numBuffers, tempVecVec0);
	mFaceCounts.resize(numBuffers, tempVecVec0);

	int buffer;
	for (buffer = 0; buffer < numBuffers; buffer++)
	{
		mVertices[buffer].resize(meshCount, tempVecF);
		mNormals[buffer].resize(meshCount, tempVecF);
		mFaces[buffer].resize(meshCount, tempVecI);
		mTextureCoords[buffer].resize(meshCount, tempVecF);
		mTextureCoordCounts[buffer].resize(meshCount, tempVec0);
		mFaceCounts[buffer].resize(meshCount, tempVec0);

		for (i=0; i < meshCount; i++)
		{
			int submeshCount = renderer->getSubmeshCount( i );

			//Initialize the data vectors for proper submesh size (with NULL data)
			mVertices[buffer][i].resize(submeshCount, NULL);
			mNormals[buffer][i].resize(submeshCount, NULL);
			mFaces[buffer][i].resize(submeshCount, NULL);
			mTextureCoords[buffer][i].resize(submeshCount, NULL);
			mTextureCoordCounts[buffer][i].resize(submeshCount, 0);
			mFaceCounts[buffer][i].resize(submeshCount, 0);

			for (j=0; j < submeshCount; j++)
			{
				renderer->selectMeshSubmesh( i, j );

				//Get vertex count (equal numbers of vertices, normals, and texture coords)
				int vertexCount = renderer->getVertexCount();

				//Get face count
				int faceCount = renderer->getFaceCount();

				//Declare all the memory
				mVertices[buffer][i][j] = new float[vertexCount * 3];
				mNormals[buffer][i][j] = new float[vertexCount * 3];
				mFaces[buffer][i][j] = new int[faceCount * 3];

				// set the texture coordinate buffer and state if necessary
				if(renderer->getMapCount() > 0)
				{
					mTextureCoords[buffer][i][j] = new float[vertexCount * 2];
				}
				else
				{
					//If there are no texture coords, allocate space for a dummy value
					mTextureCoords[buffer][i][j] = new float[1];
				}

			}
		}
	}
	delete renderer;


	/*
  // create a rest pose motion for the avatar
  KeyframeMotion *tmot = new KeyframeMotion(false);
  //std::cout << getRootPosition() << std::endl;
  tmot->addVecTrack(root_position_id, getRootPosition());
  //std::cout << avatarImp->getRootOrientation() << std::endl;
  tmot->addQuatTrack(root_orientation_id, getRootOrientation());
  for(int track = 0; track < Piavca::Core::getCore()->getMaxJointId(); track++)
	  if(!isNull(track))
	  {
		//std::cout << getJointOrientation(track) << std::endl;
		tmot->addQuatTrack(track, getJointOrientation(track));
	  }
  Core::getCore()->loadMotion(avatarId + _T("_rest"), tmot);
  */
 
	
  platformSpecific_timeStep(Piavca::Core::getCore()->getTime());
  
  renderer = cal_model->getRenderer();
  renderer = new CalRenderer(cal_model->getRenderer());
  for (buffer = 0; buffer < numBuffers; buffer++)
	{
	  for (i=0; i < meshCount; i++)
	  {
		int submeshCount = renderer->getSubmeshCount( i );
	
		for (j=0; j < submeshCount; j++)
		{
		  renderer->selectMeshSubmesh( i, j );
		  // get the texture coordinates of the submesh
		  if(renderer->getMapCount() > 0)
		  {
				mTextureCoordCounts[buffer][i][j] = renderer->getTextureCoordinates(0, mTextureCoords[buffer][i][j] ) ;
		  };
		
		  // get the faces of the submesh
		  mFaceCounts[buffer][i][j] = renderer->getFaces( mFaces[buffer][i][j] ) ;
		}
	  }
	}
  
   delete renderer;

   platformSpecific_timeStep (Piavca::Core::getCore()->getTime());
   base_bb = getBoundBox();
   std::cout << "at end of Cal3dAvatar constructor\n";
};


AvatarCal3DImp::~AvatarCal3DImp()
{
	mVertices.clear();
	mNormals.clear();
	mFaces.clear();
	mTextureCoords.clear();
	mTextureCoordCounts.clear();
	mFaceCounts.clear();
  
	delete cal_model;
  
	if (hardware)
	{
	  delete m_calHardwareModel;
	  
	  glDeleteProgram(m_vertexProgramId);
	  glDeleteBuffers(6, m_bufferObject);
	}

};

void AvatarCal3DImp::hideBodyPart(tstring partname)
{
	for(int i = 0; i < (int) meshes.size(); i++)
		if (meshes[i].first == partname)
		{
			meshes[i].second = true;
			return;
		}
	std::cout << "could not find body part " << partname << std::endl;
};

void AvatarCal3DImp::showBodyPart(tstring partname)
{
	for(int i = 0; i < (int) meshes.size(); i++)
		if (meshes[i].first == partname)
		{
			meshes[i].second = false;
			return;
		}
	std::cout << "could not find body part " << partname << std::endl;
};


void AvatarCal3DImp::setScale(float scale)
{
	scaleFactor = scale;
	/*
	return;
	float multiplier = scale/scaleFactor;
	CalCoreSkeleton *skel = cal_model->getSkeleton()->getCoreSkeleton();

	std::vector<CalCoreBone *> &bones = skel->getVectorCoreBone();
	
	int i,j;
	for (i = 0; i < (int) bones.size(); i++)
	{
		int parentId = bones[i]->getParentId();
		std::cout << "parent id " << parentId << std::endl;
		CalVector parent_trans;
		if (parentId >= 0)
		{
			CalCoreBone *parent = NULL;
			parent = skel->getCoreBone(parentId);
			parent_trans = parent->getTranslation();
		}
		CalVector trans = bones[i]->getTranslation();
		std::cout << "parent trans " << parent_trans[0] <<  " " << parent_trans[1] << " " << parent_trans[2] << std::endl;
		std::cout << "before scaling avatar " << trans[0] <<  " " << trans[1] << " " << trans[2] << std::endl;
		trans -= parent_trans;
		trans *= multiplier;
		trans += parent_trans;
		std::cout << trans[0] <<  " " << trans[1] << " " << trans[2] << std::endl;
		bones[i]->setTranslation(trans);
	}
	
	std::vector<CalMesh *> &meshes = cal_model->getVectorMesh(); 
	for (i = 0; i < (int) meshes.size(); i++)
	{
		std::cout << "Mesh " << i << " of " << meshes.size() << std::endl;
		int num_meshes = meshes[i]->getSubmeshCount();
		for (j = 0; j < num_meshes; j++)
		{
			std::cout << "Submesh " << j << " of " << num_meshes << std::endl;
			CalCoreSubmesh *submesh = meshes[i]->getSubmesh(j)->getCoreSubmesh();
			std::vector<CalCoreSubmesh::Vertex> &verts = submesh->getVectorVertex();
			for (int v = 0; v < (int)verts.size(); v++)
			{
				CalVector pos = verts[v].position;
				pos *= multiplier;
				verts[v].position = pos;
			}
		}
	}
	
	scaleFactor = scale;
	*/
}

float AvatarCal3DImp::getScale()
{
	return scaleFactor;
};

void AvatarCal3DImp::loadTextures()
{
	// initialize the data path
	//std::string strPath = "./";
	// load all textures and store the opengl texture id in the corresponding map in the material
	// NB this bit is GL specific!!!
	std::cout << "loading textures: If OpenGL isn't initialised now it will crash" << std::endl;
	CalCoreModel *cal_core_model = cal_model->getCoreModel();
	int materialId;
	for(materialId = 0; materialId < cal_core_model->getCoreMaterialCount(); materialId++)
	{
		// get the core material
		CalCoreMaterial *pCoreMaterial;
		pCoreMaterial = cal_core_model->getCoreMaterial(materialId);

		// loop through all maps of the core material
		int mapId;
		for(mapId = 0; mapId < pCoreMaterial->getMapCount(); mapId++)
		{
			// get the filename of the texture
			std::string strFilename;
			strFilename = pCoreMaterial->getMapFilename(mapId);

			// load the texture from the file
			GLuint textureId;
			//std::cout << "loading texture" << strFilename << std::endl;
			textureId = textureHandler->loadTexture(strPath + strFilename);
			//std::cout << "finished loading texture" << std::endl;

			// store the opengl texture id in the user data of the map
			pCoreMaterial->setMapUserData(mapId, (Cal::UserData)textureId);
		}
	}
	std::cout << "finished loading textures" << std::endl;

}

void  AvatarCal3DImp::enableHardware()
{
	
	// Disable internal data
	// this disable spring system


	//std::cout << "Disable internal." << std::endl;

	
	std::cout << "GL version " << glGetString(GL_VERSION) << std::endl;
	
	std::string vers = std::string ((const char *)glGetString(GL_VERSION));
	size_t dotpos = vers.find('.');
	int major = atoi(vers.substr(0, dotpos).c_str());
	int minor = atoi(vers.substr(dotpos+1, dotpos+2).c_str());
	
	if(major < 2 || (major == 2 && minor < 1))
	{
		std::cout << "For hardware skinning the GL version has to be 2.1 or more\n";	
		return;
	}

	glewInit();

	if (!GLEW_ARB_vertex_program)
	{
		  std::cerr << "Error ARB_vertex_program OpenGL extension not found." << std::endl;
		return ;
	}

	if (!GLEW_ARB_vertex_buffer_object)
	{
	  std::cerr << "Error ARB_vertex_buffer_object OpenGL extension not found." << std::endl;
	  return ;
	}

	
	
	GLint maxVertAttrs, maxVertUni;
	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &maxVertAttrs);
	std::cout << "Max number of vertex attrbutes " << maxVertAttrs << std::endl;
	glGetIntegerv(GL_MAX_VERTEX_UNIFORM_COMPONENTS, &maxVertUni);
	std::cout << "Max number of vertex uniform components " << maxVertUni << std::endl;
	
	
	if(!loadBufferObject())
	{
      std::cerr << "Error loading vertex buffer object." << std::endl;
	  return ;
	}


	if(!loadVertexProgram())
	{
      std::cerr << "Error loading vertex program." << std::endl;
	  return ;
	}

	
	mVertices.clear();
	mNormals.clear();
	mFaces.clear();
	mTextureCoords.clear();
	mTextureCoordCounts.clear();
	mFaceCounts.clear();

	hardware = true;
	cal_model->disableInternalData();
  
}

bool AvatarCal3DImp::loadBufferObject()
{
    CalRenderer* renderer = new CalRenderer(cal_model->getRenderer());

	int meshCount = renderer->getMeshCount();

	int i,j;
	int numVerts=0, numFaces=0, numMorphVerts = 0, numMorphs = 0;
	for (i=0; i < meshCount; i++)
	{
		int submeshCount = renderer->getSubmeshCount( i );
		CalMesh *mesh = cal_model->getMesh( i );

		int numVerts_=0, numFaces_=0;
		for (j=0; j < submeshCount; j++)
		{
				renderer->selectMeshSubmesh( i, j );

				//Get vertex count (equal numbers of vertices, normals, and texture coords)
				//if (numVerts < renderer->getVertexCount())
				numVerts += renderer->getVertexCount();

				//Get face count
				//if (numFaces < renderer->getFaceCount())
				numFaces += renderer->getFaceCount();

				CalSubmesh *submesh = mesh->getSubmesh(j);
				int morphCount = submesh->getMorphTargetWeightCount();
				if(morphCount > 0)
				{
					if (morphCount > numMorphs)
						numMorphs = morphCount;
					numMorphVerts += renderer->getVertexCount();
				}
		}
		if (numVerts < numVerts_)
			numVerts = numVerts_;
		if (numFaces < numFaces_)
			numFaces = numFaces_;

	}
	//std::cout << "Verts " << numVerts << " faces " << numFaces << std::endl;


  float *pVertexBuffer = (float*)malloc(numVerts*3*sizeof(float));
  float *pWeightBuffer = (float*)malloc(numVerts*4*sizeof(float));
  float *pMatrixIndexBuffer = (float*)malloc(numVerts*4*sizeof(float));
  float *pNormalBuffer = (float*)malloc(numVerts*3*sizeof(float));
  float *pTexCoordBuffer = (float*)malloc(numVerts*2*sizeof(float));
  CalIndex *pIndexBuffer = (CalIndex*)malloc(numFaces*3*sizeof(CalIndex));

  std::vector<float *> MorphVertexBuffers;
  std::vector<float *> MorphNormalBuffers;
  for (size_t i = 0; i < numMorphs; i++)
  {
	  MorphVertexBuffers.push_back((float*)malloc(numMorphVerts*3*sizeof(float)));
	  MorphNormalBuffers.push_back((float*)malloc(numMorphVerts*3*sizeof(float)));
	  if(MorphVertexBuffers.back() == NULL || MorphNormalBuffers.back() == NULL)
		  return false;
  }	

  if(pVertexBuffer==NULL || pWeightBuffer == NULL
	 || pMatrixIndexBuffer==NULL || pNormalBuffer == NULL
	 || pTexCoordBuffer==NULL || pIndexBuffer == NULL)
  {
	  return false;
  }	  


  m_calHardwareModel = new PiavcaHardwareModel(cal_model->getCoreModel());
  m_calHardwareModel->setVertexBuffer((char*)pVertexBuffer,3*sizeof(float));
  m_calHardwareModel->setNormalBuffer((char*)pNormalBuffer,3*sizeof(float));
  m_calHardwareModel->setWeightBuffer((char*)pWeightBuffer,4*sizeof(float));
  m_calHardwareModel->setMatrixIndexBuffer((char*)pMatrixIndexBuffer,4*sizeof(float));
  m_calHardwareModel->setTextureCoordNum(1);
  m_calHardwareModel->setTextureCoordBuffer(0,(char*)pTexCoordBuffer,2*sizeof(float));
  m_calHardwareModel->setIndexBuffer(pIndexBuffer);

  for (size_t i = 0; i < numMorphs; i++)
  {
	m_calHardwareModel->addMorphBuffer((char*)(MorphVertexBuffers[i]), (char*)(MorphNormalBuffers[i]));
  }

  m_calHardwareModel->load( 0, 0, MAXBONESPERMESH);



  // the index index in pIndexBuffer are relative to the begining of the hardware mesh,
  // we make them relative to the begining of the buffer.

  int meshId;
  for(meshId = 0; meshId < m_calHardwareModel->getHardwareMeshCount(); meshId++)
  {
	  m_calHardwareModel->selectHardwareMesh(meshId);

	  int faceId;
	  for(faceId = 0; faceId < m_calHardwareModel->getFaceCount(); faceId++)
	  {
		  if (m_calHardwareModel->hasMorphTargets())
		  {
			  pIndexBuffer[faceId*3+ m_calHardwareModel->getStartIndex()]+=m_calHardwareModel->getBaseMorphVertexIndex();
			  pIndexBuffer[faceId*3+1+ m_calHardwareModel->getStartIndex()]+=m_calHardwareModel->getBaseMorphVertexIndex();
			  pIndexBuffer[faceId*3+2+ m_calHardwareModel->getStartIndex()]+=m_calHardwareModel->getBaseMorphVertexIndex();
		  }
		  else
		  {
			  pIndexBuffer[faceId*3+ m_calHardwareModel->getStartIndex()]+=m_calHardwareModel->getBaseVertexIndex();
			  pIndexBuffer[faceId*3+1+ m_calHardwareModel->getStartIndex()]+=m_calHardwareModel->getBaseVertexIndex();
			  pIndexBuffer[faceId*3+2+ m_calHardwareModel->getStartIndex()]+=m_calHardwareModel->getBaseVertexIndex();
		  }
	  }

  }
	
  // normalize the weights in the weight buffer
  for (i = 0; i < numVerts*4; i += 4)
	{
		float sum = pWeightBuffer[i]+pWeightBuffer[i+1]+pWeightBuffer[i+2]+pWeightBuffer[i+3];
		if (fabs(sum) < 0.00001)
			pWeightBuffer[i]=1.0f;
		else{
			pWeightBuffer[i  ] /= sum;
			pWeightBuffer[i+1] /= sum;
			pWeightBuffer[i+2] /= sum;
			pWeightBuffer[i+3] /= sum;
		}
	}

  // We use ARB_vertex_buffer_object extension,
  // it provide better performance

  m_bufferObject = new GLuint[6 + 2*numMorphs];

  glGenBuffers(6 + 2*numMorphs, m_bufferObject);

  glBindBuffer(GL_ARRAY_BUFFER, m_bufferObject[0]);
  glBufferData(GL_ARRAY_BUFFER, m_calHardwareModel->getTotalVertexCount()*3*sizeof(float),(const void*)pVertexBuffer, GL_STATIC_DRAW);

  glBindBuffer(GL_ARRAY_BUFFER, m_bufferObject[1]);
  glBufferData(GL_ARRAY_BUFFER, m_calHardwareModel->getTotalVertexCount()*4*sizeof(float),(const void*)pWeightBuffer, GL_STATIC_DRAW);

  glBindBuffer(GL_ARRAY_BUFFER, m_bufferObject[2]);
  glBufferData(GL_ARRAY_BUFFER, m_calHardwareModel->getTotalVertexCount()*3*sizeof(float),(const void*)pNormalBuffer, GL_STATIC_DRAW);
  
  glBindBuffer(GL_ARRAY_BUFFER, m_bufferObject[3]);
  glBufferData(GL_ARRAY_BUFFER, m_calHardwareModel->getTotalVertexCount()*4*sizeof(float),(const void*)pMatrixIndexBuffer, GL_STATIC_DRAW);

  glBindBuffer(GL_ARRAY_BUFFER, m_bufferObject[4]);
  glBufferData(GL_ARRAY_BUFFER, m_calHardwareModel->getTotalVertexCount()*2*sizeof(float),(const void*)pTexCoordBuffer, GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufferObject[5]);

  glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_calHardwareModel->getTotalFaceCount()*3*sizeof(CalIndex),(const void*)pIndexBuffer, GL_STATIC_DRAW);

  
  
  //for (int j = 0; j < numMorphVerts*3; j++)
	//  std::cout << MorphVertexBuffers[0][j] << " ";
  //std::cout << std::endl;

  for (size_t i = 0; i < numMorphs; i++)
  {
	  glBindBuffer(GL_ARRAY_BUFFER, m_bufferObject[6+2*i]);
	  glBufferData(GL_ARRAY_BUFFER, numMorphVerts*3*sizeof(float),(const void*)(MorphVertexBuffers[i]), GL_STATIC_DRAW);

	  glBindBuffer(GL_ARRAY_BUFFER, m_bufferObject[6+2*i+1]);
	  glBufferData(GL_ARRAY_BUFFER, numMorphVerts*3*sizeof(float),(const void*)(MorphNormalBuffers[i]), GL_STATIC_DRAW);
  }
  
  

  
  free(pVertexBuffer);
  free(pWeightBuffer);
  free(pNormalBuffer);
  free(pMatrixIndexBuffer);
  free(pIndexBuffer);

  for (size_t i = 0; i < numMorphs; i++)
  {
	  free (MorphVertexBuffers[i]);
	  free (MorphNormalBuffers[i]);
  }	

  return true;

}


bool AvatarCal3DImp::loadVertexProgram()
{
	/*
	glGenProgramsARB( 1, &m_vertexProgramId );
	
	glBindProgramARB( GL_VERTEX_PROGRAM_ARB, m_vertexProgramId );
	
	glProgramStringARB( GL_VERTEX_PROGRAM_ARB, GL_PROGRAM_FORMAT_ASCII_ARB,
		strlen(vertexProgramStr), vertexProgramStr );
	
	if ( GL_INVALID_OPERATION == glGetError() )
	{
		// Find the error position
		GLint errPos;
		glGetIntegerv( GL_PROGRAM_ERROR_POSITION_ARB,
			&errPos );
		// Print implementation-dependent program
		// errors and warnings string.
		const unsigned char *errString = glGetString( GL_PROGRAM_ERROR_STRING_ARB);
		fprintf( stderr, "error at position: %d\n%s\n",
			errPos, errString );
		return false;
	}
	
	
	glBindProgramARB( GL_VERTEX_PROGRAM_ARB, 0 );
	*/

	m_vertexProgramId = glCreateProgram();
	
	// load the program without morphs
	GLuint shaderId = glCreateShader(GL_VERTEX_SHADER);
	if (vertexShader == "")
		glShaderSource(shaderId, 1, &vertexProgramStr, NULL);
	else {
		const char *shaderString = vertexShader.c_str();
		glShaderSource(shaderId, 1, &shaderString, NULL);
	}

	glCompileShader(shaderId);
	printOglError();
	GLint compile_status = 0;
	glGetShaderiv(shaderId, GL_COMPILE_STATUS, &compile_status);
	printShaderInfoLog(shaderId);

	if (!compile_status)
		Piavca::Error(_T("could not compile the shader"));
	
	glAttachShader(m_vertexProgramId, shaderId);
	
	
	glBindAttribLocation(m_vertexProgramId, 1, "Weights");
	glBindAttribLocation(m_vertexProgramId, 3, "MatrixIndices");

	if (fragmentShader != "")
	{
		GLuint shaderId = glCreateShader(GL_FRAGMENT_SHADER);
		const char *shaderString = fragmentShader.c_str();
		glShaderSource(shaderId, 1, &shaderString, NULL);
		
		glCompileShader(shaderId);
		printOglError();
		GLint compile_status = 0;
		glGetShaderiv(shaderId, GL_COMPILE_STATUS, &compile_status);
		printShaderInfoLog(shaderId);
		
		if (!compile_status)
			Piavca::Error(_T("could not compile the shader"));
		
		glAttachShader(m_vertexProgramId, shaderId);
		
		
	}

	glLinkProgram(m_vertexProgramId);
	
	printOglError();
	glGetProgramiv(m_vertexProgramId, GL_LINK_STATUS, &compile_status);
	printProgramInfoLog(m_vertexProgramId);
	
	
	// load the one with morphs
	shaderId = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(shaderId, 1, &vertexProgramMorphsStr, NULL);

	glCompileShader(shaderId);
	printOglError();
	compile_status = 0;
	glGetShaderiv(shaderId, GL_COMPILE_STATUS, &compile_status);
	printShaderInfoLog(shaderId);

	if (!compile_status)
		Piavca::Error(_T("could not compile the shader"));

	m_vertexProgramMorphsId = glCreateProgram();
	glAttachShader(m_vertexProgramMorphsId, shaderId);

	glBindAttribLocation(m_vertexProgramMorphsId, 1,  "Weights");
	glBindAttribLocation(m_vertexProgramMorphsId, 3,  "MatrixIndices");
	glBindAttribLocation(m_vertexProgramMorphsId, 4,  "MorphPosition1");
	glBindAttribLocation(m_vertexProgramMorphsId, 5,  "MorphNormal1");
	glBindAttribLocation(m_vertexProgramMorphsId, 6,  "MorphPosition2");
	glBindAttribLocation(m_vertexProgramMorphsId, 7,  "MorphNormal2");
	glBindAttribLocation(m_vertexProgramMorphsId, 9,  "MorphPosition3");
	glBindAttribLocation(m_vertexProgramMorphsId, 10, "MorphNormal3");
	glBindAttribLocation(m_vertexProgramMorphsId, 11, "MorphPosition4");
	glBindAttribLocation(m_vertexProgramMorphsId, 12, "MorphNormal4");

	glLinkProgram(m_vertexProgramMorphsId);
	
	printOglError();
	glGetProgramiv(m_vertexProgramMorphsId, GL_LINK_STATUS, &compile_status);
	printProgramInfoLog(m_vertexProgramMorphsId);

	if (!compile_status)
		Piavca::Error(_T("could not link the shader"));


  return true;
	
	
}

std::vector <AvatarCal3DImp::morphItem> AvatarCal3DImp::getMorphWeights()
{
	std::vector <morphItem> items;

   for (size_t i = 0; i < expressions.size(); i++)
   {
		if(expressions[i].meshId >= 0 && expressions[i].morphtargetId >= 0)
		{
			items.push_back(morphItem(expressions[i].morphtargetId, getFacialExpressionWeight(-i)));
		}
   }

   
   sort(items.begin(), items.end(), std::greater<morphItem>());
   
   return items;
}

bool  AvatarCal3DImp::setNeutralFacialExpression(tstring expressionName)
{
	return true;
};

bool AvatarCal3DImp::addFacialExpression(tstring expressionName)
{
  return true;
};

int   AvatarCal3DImp::getFacialExpressionId(tstring expressionName)
{
	return Piavca::Core::getCore()->getExpressionId(expressionName);
};

bool  AvatarCal3DImp::setFacialExpressionWeight(int id, float weight, float timeInterval)
{
	//std::cout << "Setting facial expression weight " << id << " " << weight << std::endl;
	if(id == Piavca::Core::nullId)
	{
		std::cout << "Null expression id passed to setFacialExpressionWeight" << std::endl;
		return false;
	}
	id = -id;
	if(id < 0 || id >= (int)expressions.size())
	{
		std::cout << "Unknown facial expression id " << id << std::endl;
		return false;
	}
	if(expressions[id].meshId < 0 
		//|| expressions[id].subMeshId < 0 
		|| expressions[id].morphtargetId < 0)
	{
		std::cout << "Facial expression not present " << id << std::endl;
		return false;
	}
   if(!cal_model)
   {
       Piavca::Error("setFacialExpressionWeight called on empty avatar");
	   return false;
   }

   CalMesh *mesh = cal_model->getMesh(expressions[id].meshId);
   if(!mesh)
   {
       Piavca::Error("setJointOrientation called on avatar with no head mesh");
	   return false;
   }
   for (int i = 0; i < mesh->getSubmeshCount(); i++)
   {
		CalSubmesh *subMesh = mesh->getSubmesh(i);
		if(expressions[id].morphtargetId >= subMesh->getMorphTargetWeightCount())
		{
			Piavca::Error("setFacialExpressionWeight called on expression that does not exist");
			return false;
		}
		//std::cout << "Setting submesh  expression weight " << id << " " << weight << std::endl;
		subMesh->setMorphTargetWeight(expressions[id].morphtargetId, weight);
   }
   return true;
};

void AvatarCal3DImp::updateFacialExpressions()
{
}

float AvatarCal3DImp::getFacialExpressionWeight(int id)
{
	if(id == Piavca::Core::nullId)
	{
		std::cout << "Null expression id passed to getFacialExpressionWeight" << std::endl;
		return false;
	}
	id = -id;
	if(id < 0 || id >= (int)expressions.size())
	{
		std::cout << "Unknown facial expression id " << id << std::endl;
		return false;
	}
	if(expressions[id].meshId < 0 
		//|| expressions[id].subMeshId < 0 
		|| expressions[id].morphtargetId < 0)
	{
		std::cout << "Facial expression not present " << id << std::endl;
		return 0.0;
	}
   if(!cal_model)
   {
       Piavca::Error("getFacialExpressionWeight called on empty avatar");
	   return 0.0;
   }

   CalMesh *mesh = cal_model->getMesh(expressions[id].meshId);
   if(!mesh)
   {
       Piavca::Error("getFacialExpressionWeight called on avatar with no head mesh");
	   return 0.0;
   }
   CalSubmesh *subMesh = mesh->getSubmesh(0);
   if(!subMesh)
   {
       Piavca::Error("getFacialExpressionWeight called on avatar with no face submesh");
	   return 0.0;
   }
   if(expressions[id].morphtargetId >= subMesh->getMorphTargetWeightCount())
   {
       Piavca::Error("getFacialExpressionWeight called on expression that does not exist");
	   return 0.0;
   }
   return subMesh->getMorphTargetWeight(expressions[id].morphtargetId);
};

int AvatarCal3DImp::getParent(int jointId)const
{
	if(jointId < 0)
	{
		Piavca::Error("Null jointId passed in to getParent");
		return -1;
	}
	if(joints[jointId].name == "")
	{
		Piavca::Error("getParent called on joint missing in avatar");
		return -1;
	}
	return joints[jointId].parent;
};

const tstring AvatarCal3DImp::getJointName(int jointId)
{
	if(jointId < 0)
	{
		Piavca::Error("Null jointId passed in to getJointName");
		return _T("");
	}
	if(joints[jointId].name == _T(""))
	{
		Piavca::Error("getJointName called on joint missing in avatar");
	}
	return joints[jointId].name;
};

bool AvatarCal3DImp::createJoint(tstring JointName)
{
	while(Piavca::Core::getCore()->getMaxJointId() >= (int)joints.size())
		joints.push_back(JointHolder());
    
    int jointId = Piavca::Core::getCore()->getJointId(JointName);
    if(jointId < 0) 
		return false;
    
	CalSkeleton *skel = cal_model->getSkeleton();
	int cal3Did = skel->getCoreSkeleton()->getCoreBoneId(TStringToString(JointName));
	if(cal3Did > 0)
	{
		joints[jointId].cal3dId = cal3Did;
		joints[jointId].name = JointName;
		CalCoreBone *corebone = skel->getBone(cal3Did)->getCoreBone();
		joints[jointId].parent = corebone->getParentId();
		return true;
	}
	return false;
}

bool AvatarCal3DImp::hasChanged(int jointId)
{
	if(jointId < 0)
	{
		Piavca::Error("Null jointId passed in to hasChanged");
		return false;
	}
	if(joints[jointId].name == "")
	{
		Piavca::Error("hasChanged called on joint missing in avatar");
		return false;
	}
	return joints[jointId].changed;
};

void AvatarCal3DImp::clearChange(int jointId)
{
	if(jointId < 0)
	{
		Piavca::Error("Null jointId passed in to clearChange");
		return;
	}
	if(joints[jointId].name == "")
	{
		Piavca::Error("clearChange called on joint missing in avatar");
		return;
	}
	joints[jointId].changed = false;
};

void	AvatarCal3DImp::setRootPosition (const Vec &Position)
{
	bb_dirty_flag = true;
  if(!cal_model)
   {
       Piavca::Error("setJointOrientation called on empty avatar");
	   return;
   }

   CalVector calv(VecToCalVec(Position));
   
   CalSkeleton *skel = cal_model->getSkeleton();
   if(!skel)
   {
       Piavca::Error("setJointOrientation called on avatar with no skeleton");
	   return;
   }
   CalBone *bone = skel->getBone(0);
   if(!bone)
   {
       Piavca::Error("setJointOrientation called on joint that does not exist in avatar");
	   return;
   }

   
   //Quat q1_p(0.707, 0.0, 0.0, 0.707);
   //CalQuaternion q1_c = QuatToCalQuat(q1_p);
   //CalQuaternion q2_c(0.0, 0.0, 0.707, 0.707);
   //std::cout << "q1_p " << q1_p << std::endl;
   //std::cout << "q1_c " << q1_c.w << " " << q1_c.x << " " <<q1_c.y << " " << q1_c.z << " " << std::endl;
   //std::cout << "q2_c " << q2_c.w << " " << q2_c.x << " " <<q2_c.y << " " << q2_c.z << " " << std::endl;
   
   //std::cout << "Position " << Position << std::endl;
   //std::cout << "Position " << q1_p.transform(Position) << std::endl;
   //std::cout << "q1_p.inverse*Orientation " << q1_p.inverse().transform(Position) << std::endl;
   
   //CalVector calv_copy(calv); 
   
   //std::cout << "calv_copy " << 	 calv_copy.x << " " << calv_copy.y << " " << calv_copy.z << " " << std::endl;
   
   //calv_copy *= q2_c;
   
   //std::cout << "calv_copy*q2_c "  << calv_copy.x << " " << calv_copy.y << " " << calv_copy.z << " " << std::endl;
   
   //calv += bone->getCoreBone()->getTranslation();
   //CalQuaternion q(0.707, 0.0, 0.707, 0.0);
   //calv *= q;
   bone->setTranslation(calv);
}
Vec		AvatarCal3DImp::getRootPosition ()
{
   cal_model->getSkeleton()->calculateState();
   if(!cal_model)
   {
       Piavca::Error("setJointOrientation called on empty avatar");
	   return Vec();
   }   
   CalSkeleton *skel = cal_model->getSkeleton();
   if(!skel)
   {
       Piavca::Error("setJointOrientation called on avatar with no skeleton");
	   return Vec();
   }
   CalBone *bone = skel->getBone(0);
   if(!bone)
   {
       Piavca::Error("setJointOrientation called on joint that does not exist in avatar");
	   return Vec();
   }
   return CalVecToVec(bone->getTranslationAbsolute());
}
void	AvatarCal3DImp::setRootOrientation	(const Quat &Orientation)
{
   bb_dirty_flag = true;
   cal_model->getSkeleton()->calculateState();
   if(!cal_model)
   {
       Piavca::Error("setJointOrientation called on empty avatar");
	   return;
   }

   CalQuaternion calq = QuatToCalQuat(Orientation);
   
   CalSkeleton *skel = cal_model->getSkeleton();
   if(!skel)
   {
       Piavca::Error("setJointOrientation called on avatar with no skeleton");
	   return;
   }
   CalBone *bone = skel->getBone(0);
   if(!bone)
   {
       Piavca::Error("setJointOrientation called on joint that does not exist in avatar");
	   return;
   }
   //calq *= bone->getCoreBone()->getRotation();
   //calq *= q;
   bone->setRotation(calq);
};

Quat	AvatarCal3DImp::getRootOrientation ()
{	
   if(!cal_model)
   {
       Piavca::Error("setJointOrientation called on empty avatar");
	   return Quat();
   }   
   CalSkeleton *skel = cal_model->getSkeleton();
   if(!skel)
   {
       Piavca::Error("setJointOrientation called on avatar with no skeleton");
	   return Quat();
   }
   CalBone *bone = skel->getBone(0);
   if(!bone)
   {
       Piavca::Error("setJointOrientation called on joint that does not exist in avatar");
	   return Quat();
   }
   return CalQuatToQuat(bone->getRotationAbsolute());
};


void AvatarCal3DImp::setJointOrientation(int jointId, const Quat &Orientation, jointCoord worldCoord)
{
   bb_dirty_flag = true;
   if(jointId < 0)
   {
       Piavca::Error("Null joint Id passed in to setJointOrientation");
	   return;
   }
   if(joints[jointId].cal3dId < 0)
   {
       Piavca::Error("setJointOrientation called on joint missing in avatar");
	   return;
   }
   if(!cal_model)
   {
       Piavca::Error("setJointOrientation called on empty avatar");
	   return;
   }

   CalQuaternion calq = QuatToCalQuat(Orientation);
   
   CalSkeleton *skel = cal_model->getSkeleton();
   if(!skel)
   {
       Piavca::Error("setJointOrientation called on avatar with no skeleton");
	   return;
   }
   CalBone *bone = skel->getBone(joints[jointId].cal3dId);
   if(!bone)
   {
       Piavca::Error("setJointOrientation called on joint that does not exist in avatar");
	   return;
   }
   //calq = bone->getCoreBone()->getRotation()*calq;
   calq = calq*bone->getCoreBone()->getRotation();
   bone->setRotation(calq);
   //bone->setTranslation(bone->getCoreBone()->getTranslation());
};
	
Quat AvatarCal3DImp::getJointOrientation	(int jointId, jointCoord worldCoord)
{
  
  if(jointId < 0)
  {
      Piavca::Error("Null joint Id passed in to getJointOrientation");
	  return Quat();
  }
  if(joints[jointId].cal3dId < 0)
  {
      Piavca::Error("getJointOrientation called on joint missing in avatar");
	  return Quat();
  }
   if(!cal_model)
   {
       Piavca::Error("getJointOrientation called on empty avatar");
	   return Quat();
   }

   CalQuaternion calq;
   
   CalSkeleton *skel = cal_model->getSkeleton();
   if(!skel)
   {
       Piavca::Error("getJointOrientation called on avatar with no skeleton");
	   return Quat();
   }
   CalBone *bone = skel->getBone(joints[jointId].cal3dId);
   if(!bone)
   {
       Piavca::Error("getJointOrientation called on joint that does not exist in avatar");
	   return Quat();
   }

  switch (worldCoord)	
      {
      case JOINTLOCAL_COORD:	
		  {
			calq = bone->getRotation();
			Quat q = CalQuatToQuat(calq);
			q = q * CalQuatToQuat(bone->getCoreBone()->getRotation()).inverse();
			return q;
		  }
	  break;
      case WORLD_COORD:
			calq = bone->getRotationAbsolute();
			return CalQuatToQuat(calq);
	  break;
      case LOCAL_COORD:
		  {
			calq = bone->getRotationAbsolute();
			Quat q = CalQuatToQuat(calq);
			q = getRootOrientation().inverse()*q;
			return q;
		  }
	  break;
      case BASE_COORD:
		  {
			calq = bone->getCoreBone()->getRotation();
			return CalQuatToQuat(calq);
		  }
			break;
      case INCLUDINGBASE_COORD:	
			calq = bone->getRotation();
			return CalQuatToQuat(calq);
	  break;
      default:	assert(0);
      }
  return Quat();
}


void AvatarCal3DImp::setJointPosition(int jointId, const Vec &Position, jointCoord worldCoord)
{
   bb_dirty_flag = true;
   if(jointId < 0)
   {
       Piavca::Error("Null joint Id passed in to setJointOrientation");
	   return;
   }
   if(joints[jointId].cal3dId < 0)
   {
       Piavca::Error("setJointOrientation called on joint missing in avatar");
	   return;
   }
   if(!cal_model)
   {
       Piavca::Error("setJointOrientation called on empty avatar");
	   return;
   }

   CalVector calv = VecToCalVec(Position);
   
   CalSkeleton *skel = cal_model->getSkeleton();
   if(!skel)
   {
       Piavca::Error("setJointOrientation called on avatar with no skeleton");
	   return;
   }
   CalBone *bone = skel->getBone(joints[jointId].cal3dId);
   if(!bone)
   {
       Piavca::Error("setJointOrientation called on joint that does not exist in avatar");
	   return;
   }
   calv += bone->getCoreBone()->getTranslation();
   //bone->setRotation(bone->getCoreBone()->getRotation());
   bone->setTranslation(calv);
};


Vec AvatarCal3DImp::getJointBasePosition (int jointId, jointCoord worldCoord)
{

  if(jointId < 0)
  {
      Piavca::Error("Null joint Id passed in to getJointBasePosition");
	  return Vec();
  }
  if(joints[jointId].cal3dId < 0)
  {
      Piavca::Error("getJointBasePosition called on joint missing in avatar");
	  return Vec();
  }
   if(!cal_model)
   {
       Piavca::Error("getJointBasePosition called on empty avatar");
	   return Vec();
   }

   CalVector calv;
   
   CalSkeleton *skel = cal_model->getSkeleton();
   if(!skel)
   {
       Piavca::Error("getJointBasePosition called on avatar with no skeleton");
	   return Vec();
   }
   CalBone *bone = skel->getBone(joints[jointId].cal3dId);
   if(!bone)
   {
       Piavca::Error("getJointBasePosition called on joint that does not exist in avatar");
	   return Vec();
   }

  switch (worldCoord)	
      {
      case JOINTLOCAL_COORD:	
			calv = bone->getTranslation();
			return CalVecToVec(calv);
	  break;
      case WORLD_COORD:
			calv = bone->getTranslationAbsolute();
			return CalVecToVec(calv);
	  break;
      case LOCAL_COORD:
		  {
			calv = bone->getTranslationAbsolute();
			Vec v = CalVecToVec(calv);
			v -= getRootPosition();
			return v;
		  }
	  break;
      default:	assert(0);
      }
  return Vec(); 
};

void AvatarCal3DImp::scaleRoot(Vec scale)
{
	Piavca::Warning(_T("Scaling unimplemented under Cal3D"));
}

void   AvatarCal3DImp::scaleJoint (int jointId, Vec scale)
{
	Piavca::Warning(_T("Scaling unimplemented under Cal3D"));
};

#ifndef min
#	define min(a,b) (((a) < (b)) ? (a) : (b))
#endif
#ifndef max
#	define max(a,b) (((a) > (b)) ? (a) : (b))
#endif

void	AvatarCal3DImp::platformSpecific_timeStep (float time)
{
	// calculate the amount of elapsed seconds
	float elapsedSeconds = Core::getCore()->getTime() - previous_time;
	previous_time = Core::getCore()->getTime();

	
	// don't do a full Cal3D update as that plays the cal3d animations
	// which overwrites any animations that piavca has played
	//cal_model->update(elapsedSeconds);
	cal_model->getSkeleton()->calculateState();
	cal_model->getPhysique()->update();
    cal_model->getSpringSystem()->update(previous_time);

	if (! hardware)
		software_skinning();

};

void	AvatarCal3DImp::software_skinning()
{
	CalRenderer* renderer = new CalRenderer(cal_model->getRenderer());

	//Get the mesh data for all meshes and submeshes
	int meshCount = renderer->getMeshCount() ;

	// get all meshes of the model
	int meshId;
	for(meshId = 0; meshId < meshCount; meshId++)
	{
      int submeshId, submeshCount ;

      submeshCount = renderer->getSubmeshCount( meshId ) ;

      // get all submeshes of the mesh
      for(submeshId = 0; submeshId < submeshCount; submeshId++)
      {

         // select mesh and submesh and grab all the data
         if ( renderer->selectMeshSubmesh(meshId, submeshId) )
         {

            // get the transformed vertices of the submesh
			float *vertexArray = mVertices[renderBuffer][meshId][submeshId];
            int vertexCount = renderer->getVertices(vertexArray);

            // get the transformed normals of the submesh
            renderer->getNormals( mNormals[renderBuffer][meshId][submeshId] ) ;

            // get the texture coordinates of the submesh
            //mTextureCoordCounts[renderBuffer][meshId][submeshId] = renderer->getTextureCoordinates(0, mTextureCoords[renderBuffer][meshId][submeshId] ) ;

            // get the faces of the submesh
            //mFaceCounts[renderBuffer][meshId][submeshId] = renderer->getFaces( mFaces[renderBuffer][meshId][submeshId] ) ;	 
		 }
         else
         {
			 Piavca::Error(_T("AvatarCal3DImp: Attempting to update for an invalid submesh (this is bad)"));
         }

      }
   }

   //renderer->destroy();
   delete renderer;

}

void	AvatarCal3DImp::render ()
{
	if (hardware)
		render_hardware();
	else
		render_software();
}


void	AvatarCal3DImp::render_hardware ()
{
	//std::cout << "in render hardware" << std::endl;
	
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glPushMatrix();

	//glBindProgramARB( GL_VERTEX_PROGRAM_ARB, m_vertexProgramId );
	glUseProgram(m_vertexProgramId);
	printOglError();

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
	glEnableVertexAttribArray(3);
    glEnableVertexAttribArray(8);
	
	glEnable(GL_TEXTURE_2D);
	// set global OpenGL states
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);		
	glEnable(GL_VERTEX_PROGRAM_ARB);
	glEnable(GL_CULL_FACE);

	//glEnable (GL_BLEND); 
	//glBlendFunc (GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	

    glBindBuffer(GL_ARRAY_BUFFER, m_bufferObject[0]);
	glVertexAttribPointer(0, 3 , GL_FLOAT, false, 0, NULL);
	printOglError();

    glBindBuffer(GL_ARRAY_BUFFER, m_bufferObject[1]);
	glVertexAttribPointer(1, 4 , GL_FLOAT, false, 0, NULL);
	printOglError();

	glBindBuffer(GL_ARRAY_BUFFER, m_bufferObject[2]);
    glVertexAttribPointer(2, 3 , GL_FLOAT, false, 0, NULL);
	printOglError();

    glBindBuffer(GL_ARRAY_BUFFER, m_bufferObject[3]);
	glVertexAttribPointer(3, 4 , GL_FLOAT, false, 0, NULL);
	printOglError();

    glBindBuffer(GL_ARRAY_BUFFER, m_bufferObject[4]);
	glVertexAttribPointer(8, 2 , GL_FLOAT, false, 0, NULL);
	printOglError();

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufferObject[5]);
	printOglError();
	
	
	glScalef(scaleFactor, scaleFactor, scaleFactor);
	printOglError();
		

	//std::cout << "rendering non-morph meshes" << std::endl;
	
	int hardwareMeshId;
	
	// first render everthing without morph targets
	for(hardwareMeshId=0;hardwareMeshId<m_calHardwareModel->getHardwareMeshCount() ; hardwareMeshId++)
	{
		m_calHardwareModel->selectHardwareMesh(hardwareMeshId);
		if (m_calHardwareModel->hasMorphTargets())
			continue;
		

		//std::cout << "setting materials" << std::endl;

		unsigned char meshColor[4];	
		float materialColor[4];
		// set the material ambient color
		m_calHardwareModel->getAmbientColor(&meshColor[0]);
		materialColor[0] = meshColor[0] / 255.0f;  materialColor[1] = meshColor[1] / 255.0f; materialColor[2] = meshColor[2] / 255.0f; materialColor[3] = meshColor[3] / 255.0f;
		glMaterialfv(GL_FRONT, GL_AMBIENT, materialColor);
		printOglError();
		
		// set the material diffuse color
		m_calHardwareModel->getDiffuseColor(&meshColor[0]);
		materialColor[0] = meshColor[0] / 255.0f;  materialColor[1] = meshColor[1] / 255.0f; materialColor[2] = meshColor[2] / 255.0f; materialColor[3] = meshColor[3] / 255.0f;
		glMaterialfv(GL_FRONT, GL_DIFFUSE, materialColor);
		printOglError();
		
		// set the material specular color
		m_calHardwareModel->getSpecularColor(&meshColor[0]);
		materialColor[0] = meshColor[0] / 255.0f;  materialColor[1] = meshColor[1] / 255.0f; materialColor[2] = meshColor[2] / 255.0f; materialColor[3] = meshColor[3] / 255.0f;
		glMaterialfv(GL_FRONT, GL_SPECULAR, materialColor);
		printOglError();
		
		
		// set the material shininess factor
		float shininess;
		shininess = 50.0f; //m_calHardwareModel->getShininess();
		glMaterialfv(GL_FRONT, GL_SHININESS, &shininess);


		//std::cout << "loading bone transforms. Num Transforms: " << m_calHardwareModel->getBoneCount() << std::endl;
		
		int boneId;
		//float *transformation = new float[16*m_calHardwareModel->getBoneCount()];
		for(boneId = 0; boneId < m_calHardwareModel->getBoneCount(); boneId++)
		{
			CalQuaternion rotationBoneSpace = m_calHardwareModel->getRotationBoneSpace(boneId, cal_model->getSkeleton());
			CalVector translationBoneSpace = m_calHardwareModel->getTranslationBoneSpace(boneId, cal_model->getSkeleton());

			CalMatrix rotationMatrix = rotationBoneSpace;

			float transformation[16];

			transformation[0]=rotationMatrix.dxdx;transformation[1]=rotationMatrix.dxdy;transformation[2]=rotationMatrix.dxdz;transformation[3]=translationBoneSpace.x;
			transformation[4]=rotationMatrix.dydx;transformation[5]=rotationMatrix.dydy;transformation[6]=rotationMatrix.dydz;transformation[7]=translationBoneSpace.y;
			transformation[8]=rotationMatrix.dzdx;transformation[9]=rotationMatrix.dzdy;transformation[10]=rotationMatrix.dzdz;transformation[11]=translationBoneSpace.z;
			transformation[12]=0.0f;transformation[13]=0.0f;transformation[14]=0.0f;transformation[15]=1.0f;

			std::ostringstream is;
			is << "Transforms[" << boneId << "]";
			//std::cout << is.str();
			GLint transformArrayId = glGetUniformLocation(m_vertexProgramId, is.str().c_str());	
			if (transformArrayId < 0)
				std::cout << "failed to load transform " << is.str() << std::endl;
			//std::cout  << " " << transformArrayId << std::endl;

			glUniformMatrix4fv(transformArrayId, 1, GL_TRUE, &transformation[0]);
			printOglError();
			
			
			
			//glProgramLocalParameter4fvARB(GL_VERTEX_PROGRAM_ARB,boneId*3,&transformation[0]);
			//glProgramLocalParameter4fvARB(GL_VERTEX_PROGRAM_ARB,boneId*3+1,&transformation[4]);
			//glProgramLocalParameter4fvARB(GL_VERTEX_PROGRAM_ARB,boneId*3+2,&transformation[8]);			
			
		}

		
		//GLint transformArrayId = glGetUniformLocation(m_vertexProgramId, "Transforms");
		//transformArrayId = glGetUniformLocation(m_vertexProgramId, "Transforms[0]");
		//transformArrayId = glGetUniformLocation(m_vertexProgramId, "Transforms[1]");
		//glUniformMatrix4fv(transformArrayId, m_calHardwareModel->getBoneCount(), GL_FALSE, &transformation[0]);
		


		//std::cout << "getting texture" << std::endl;
		
        // set the texture id we stored in the map user data
		
		
		//std::cout << "texture id " << m_calHardwareModel->getMapUserData(0) <<std::endl;
        GLuint textureId = (GLuint)m_calHardwareModel->getMapUserData(0);
		if (textureId > 0)
		{
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, (GLuint)textureId);
			GLint texSamplerId = glGetUniformLocation(m_vertexProgramId, "tex");
			if(texSamplerId >= 0)
				glUniform1i(texSamplerId, 0);
			GLint textureAvailableId = glGetUniformLocation(m_vertexProgramId, "textureAvailable");
			if(textureAvailableId >= 0)
				glUniform1i(textureAvailableId, 1);
		}
		else {
			GLint textureAvailableId = glGetUniformLocation(m_vertexProgramId, "textureAvailable");
			if(textureAvailableId >= 0)
				glUniform1i(textureAvailableId, 0);
		}

		printOglError();


		//std::cout << "rendering" << std::endl;
		
		//std::cout << "index size " << sizeof(CalIndex) << std::endl;
		
		if(sizeof(CalIndex)==2)
			glDrawElements(GL_TRIANGLES, m_calHardwareModel->getFaceCount() * 3, GL_UNSIGNED_SHORT, (((CalIndex *)NULL)+ m_calHardwareModel->getStartIndex()));
		else
			glDrawElements(GL_TRIANGLES, m_calHardwareModel->getFaceCount() * 3, GL_UNSIGNED_INT, (((CalIndex *)NULL)+ m_calHardwareModel->getStartIndex()));
		
		printOglError();

	}
	
	// then render the meshes with morph targets

	//std::cout << "rendering non-morph meshes" << std::endl;

	//load the morphs enabled vertex program
	glUseProgram(m_vertexProgramMorphsId);
	printOglError();

	std::vector <morphItem> morphWeights = getMorphWeights();

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
	glEnableVertexAttribArray(3);
	if(morphWeights.size() > 0)
	{
		glEnableVertexAttribArray(4);
		glEnableVertexAttribArray(5);
	}
	if(morphWeights.size() > 1)
	{
		glEnableVertexAttribArray(6);
		glEnableVertexAttribArray(7);
	}
    glEnableVertexAttribArray(8);
	if(morphWeights.size() > 2)
	{
		glEnableVertexAttribArray(9);
		glEnableVertexAttribArray(10);
	}
	if(morphWeights.size() > 3)
	{
		glEnableVertexAttribArray(11);
		glEnableVertexAttribArray(12);
	}
	

	bool prevHadMorphs = false;
	for(hardwareMeshId=0;hardwareMeshId<m_calHardwareModel->getHardwareMeshCount() ; hardwareMeshId++)
	{
		m_calHardwareModel->selectHardwareMesh(hardwareMeshId);
		if (!m_calHardwareModel->hasMorphTargets())
		{
			prevHadMorphs = false;
			continue;
		}
		std::cout << "using morph target shader" << std::endl;
		if (!prevHadMorphs)
		{
			prevHadMorphs = true;
			    
			glBindBuffer(GL_ARRAY_BUFFER, m_bufferObject[0]);
			glVertexAttribPointer(0, 3 , GL_FLOAT, false, 0, (const void *)(3*sizeof(float)*m_calHardwareModel->getBaseVertexIndex()));
			printOglError();

			glBindBuffer(GL_ARRAY_BUFFER, m_bufferObject[1]);
			glVertexAttribPointer(1, 4 , GL_FLOAT, false, 0, (const void *)(4*sizeof(float)*m_calHardwareModel->getBaseVertexIndex()));
			printOglError();

			glBindBuffer(GL_ARRAY_BUFFER, m_bufferObject[2]);
			glVertexAttribPointer(2, 3 , GL_FLOAT, false, 0, (const void *)(3*sizeof(float)*m_calHardwareModel->getBaseVertexIndex()));
			printOglError();

			glBindBuffer(GL_ARRAY_BUFFER, m_bufferObject[3]);
			glVertexAttribPointer(3, 4 , GL_FLOAT, false, 0, (const void *)(4*sizeof(float)*m_calHardwareModel->getBaseVertexIndex()));
			printOglError();

			

			// load morphs
			for (int i = 0; i < 4 && i < morphWeights.size(); i++)
			{
				int index = morphWeights[i].index;
				glBindBuffer(GL_ARRAY_BUFFER, m_bufferObject[6+2*index]);
				std::ostringstream is1;

				std::ostringstream is;
				is << "MorphPosition" << i+1 ;
				glVertexAttribPointer(glGetAttribLocation(m_vertexProgramMorphsId, is.str().c_str()), 3 , GL_FLOAT, false, 0, NULL);
				printOglError();
				is.str("");

				glBindBuffer(GL_ARRAY_BUFFER, m_bufferObject[6+2*index+1]);
				is << "MorphNormal" << i+1 ;
				glVertexAttribPointer(glGetAttribLocation(m_vertexProgramMorphsId, is.str().c_str()), 3 , GL_FLOAT, false, 0, NULL);
				printOglError();

			}
			

			

			glBindBuffer(GL_ARRAY_BUFFER, m_bufferObject[4]);
			glVertexAttribPointer(8, 2 , GL_FLOAT, false, 0, (const void *)(2*sizeof(float)*m_calHardwareModel->getBaseVertexIndex()));
			printOglError();

			
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufferObject[5]);
			
			printOglError();
		}

		unsigned char meshColor[4];	
		float materialColor[4];
		// set the material ambient color
		m_calHardwareModel->getAmbientColor(&meshColor[0]);
		materialColor[0] = meshColor[0] / 255.0f;  materialColor[1] = meshColor[1] / 255.0f; materialColor[2] = meshColor[2] / 255.0f; materialColor[3] = meshColor[3] / 255.0f;
		glMaterialfv(GL_FRONT, GL_AMBIENT, materialColor);
		printOglError();
		
		// set the material diffuse color
		m_calHardwareModel->getDiffuseColor(&meshColor[0]);
		materialColor[0] = meshColor[0] / 255.0f;  materialColor[1] = meshColor[1] / 255.0f; materialColor[2] = meshColor[2] / 255.0f; materialColor[3] = meshColor[3] / 255.0f;
		glMaterialfv(GL_FRONT, GL_DIFFUSE, materialColor);
		printOglError();
		
		// set the material specular color
		m_calHardwareModel->getSpecularColor(&meshColor[0]);
		materialColor[0] = meshColor[0] / 255.0f;  materialColor[1] = meshColor[1] / 255.0f; materialColor[2] = meshColor[2] / 255.0f; materialColor[3] = meshColor[3] / 255.0f;
		glMaterialfv(GL_FRONT, GL_SPECULAR, materialColor);
		printOglError();
		
		
		// set the material shininess factor
		float shininess;
		shininess = 50.0f; //m_calHardwareModel->getShininess();
		glMaterialfv(GL_FRONT, GL_SHININESS, &shininess);

		int boneId;
		//float *transformation = new float[16*m_calHardwareModel->getBoneCount()];
		for(boneId = 0; boneId < m_calHardwareModel->getBoneCount(); boneId++)
		{
			CalQuaternion rotationBoneSpace = m_calHardwareModel->getRotationBoneSpace(boneId, cal_model->getSkeleton());
			CalVector translationBoneSpace = m_calHardwareModel->getTranslationBoneSpace(boneId, cal_model->getSkeleton());

			CalMatrix rotationMatrix = rotationBoneSpace;

			float transformation[16];

			transformation[0]=rotationMatrix.dxdx;transformation[1]=rotationMatrix.dxdy;transformation[2]=rotationMatrix.dxdz;transformation[3]=translationBoneSpace.x;
			transformation[4]=rotationMatrix.dydx;transformation[5]=rotationMatrix.dydy;transformation[6]=rotationMatrix.dydz;transformation[7]=translationBoneSpace.y;
			transformation[8]=rotationMatrix.dzdx;transformation[9]=rotationMatrix.dzdy;transformation[10]=rotationMatrix.dzdz;transformation[11]=translationBoneSpace.z;
			transformation[12]=0.0f;transformation[13]=0.0f;transformation[14]=0.0f;transformation[15]=1.0f;

			std::ostringstream is;
			is << "Transforms[" << boneId << "]";
			//std::cout << is.str();
			GLint transformArrayId = glGetUniformLocation(m_vertexProgramMorphsId, is.str().c_str());	
			//std::cout  << " " << transformArrayId << std::endl;

			glUniformMatrix4fv(transformArrayId, 1, GL_TRUE, &transformation[0]);
			printOglError();
			//glProgramLocalParameter4fvARB(GL_VERTEX_PROGRAM_ARB,boneId*3,&transformation[0]);
			//glProgramLocalParameter4fvARB(GL_VERTEX_PROGRAM_ARB,boneId*3+1,&transformation[4]);
			//glProgramLocalParameter4fvARB(GL_VERTEX_PROGRAM_ARB,boneId*3+2,&transformation[8]);			
			
		}

		
		GLint morphWeightId = glGetUniformLocation(m_vertexProgramMorphsId, "MorphWeights");
		
		float morphWeight1 = 0;
		if (morphWeights.size() > 0)
			morphWeight1 = morphWeights[0].weight;
		float morphWeight2 = 0;
		if (morphWeights.size() > 1)
			morphWeight2 = morphWeights[1].weight;
		float morphWeight3 = 0;
		if (morphWeights.size() > 2)
			morphWeight3 = morphWeights[2].weight;
		float morphWeight4 = 0;
		if (morphWeights.size() > 3)
			morphWeight4 = morphWeights[3].weight;
		glUniform4f(morphWeightId, morphWeight1, morphWeight2, morphWeight3, morphWeight4);
		printOglError();

		
		//GLint transformArrayId = glGetUniformLocation(m_vertexProgramId, "Transforms");
		//transformArrayId = glGetUniformLocation(m_vertexProgramId, "Transforms[0]");
		//transformArrayId = glGetUniformLocation(m_vertexProgramId, "Transforms[1]");
		//glUniformMatrix4fv(transformArrayId, m_calHardwareModel->getBoneCount(), GL_FALSE, &transformation[0]);
		

        // set the texture id we stored in the map user data
        glBindTexture(GL_TEXTURE_2D, (GLuint)m_calHardwareModel->getMapUserData(0));
		printOglError();

		if(sizeof(CalIndex)==2)
			glDrawElements(GL_TRIANGLES, m_calHardwareModel->getFaceCount() * 3, GL_UNSIGNED_SHORT, (((CalIndex *)NULL)+ m_calHardwareModel->getStartIndex()));
		else
			glDrawElements(GL_TRIANGLES, m_calHardwareModel->getFaceCount() * 3, GL_UNSIGNED_INT, (((CalIndex *)NULL)+ m_calHardwareModel->getStartIndex()));
		
		printOglError();

	}
	

    // clear vertex array state    

	//glDisableVertexAttribArrayARB(0);
	//glDisableVertexAttribArrayARB(1);
    //glDisableVertexAttribArrayARB(2);
	//glDisableVertexAttribArrayARB(3);
    //glDisableVertexAttribArrayARB(8);

    //glBindBufferARB(GL_ARRAY_BUFFER_ARB, 0);
	//glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, 0);

    // clear light
    //glDisable(GL_LIGHTING);
    //glDisable(GL_LIGHT0);
    //glDisable(GL_DEPTH_TEST);
	//glDisable(GL_VERTEX_PROGRAM_ARB);

	
	glUseProgram(0);
	//glBindProgramARB( GL_VERTEX_PROGRAM_ARB, 0 );
	glPopMatrix();
	glPopAttrib();
	

	//std::cout << "finished rendering" << std::endl;

}

void	AvatarCal3DImp::render_software ()
{
  //std::cout << "avatar.prerender\n";
  // get the renderer of the model
  CalRenderer *pCalRenderer = cal_model->getRenderer();

  // begin the rendering loop
  if(pCalRenderer->beginRendering())
  {
    // set global OpenGL states
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glPushMatrix();

    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

	glEnable (GL_BLEND); 
	glBlendFunc (GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

    // we will use vertex arrays, so enable them
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);

	glScalef(scaleFactor, scaleFactor, scaleFactor);

    // get the number of meshes
    int meshCount = pCalRenderer->getMeshCount();

    // render all meshes of the model
    for(int meshId = 0; meshId < meshCount; meshId++)
    {
	  // check if the mesh is supposed to be hidden
	  if (meshes[meshId].second)
		  continue;
      
	  // get the number of submeshes
      int submeshCount = pCalRenderer->getSubmeshCount(meshId);

      // render all submeshes of the mesh
      for(int submeshId = 0; submeshId < submeshCount; submeshId++)
      {
        // select mesh and submesh for further data access
        if(pCalRenderer->selectMeshSubmesh(meshId, submeshId))
        {
          unsigned char meshColor[4];
          GLfloat materialColor[4];

          // set the material ambient color
          pCalRenderer->getAmbientColor(&meshColor[0]);
          materialColor[0] = meshColor[0] / 255.0f;  materialColor[1] = meshColor[1] / 255.0f; materialColor[2] = meshColor[2] / 255.0f; materialColor[3] = meshColor[3] / 255.0f;
          glMaterialfv(GL_FRONT, GL_AMBIENT, materialColor);

          // set the material diffuse color
          pCalRenderer->getDiffuseColor(&meshColor[0]);
		  // if the object is transparent, don't bother rendering it
		  if( meshColor[3] == 0) 
				continue;
          materialColor[0] = meshColor[0] / 255.0f;  materialColor[1] = meshColor[1] / 255.0f; materialColor[2] = meshColor[2] / 255.0f; materialColor[3] = meshColor[3] / 255.0f;
          glMaterialfv(GL_FRONT, GL_DIFFUSE, materialColor);
		  glColor3fv(materialColor);

          // set the material specular color
          pCalRenderer->getSpecularColor(&meshColor[0]);
          materialColor[0] = meshColor[0] / 255.0f;  materialColor[1] = meshColor[1] / 255.0f; materialColor[2] = meshColor[2] / 255.0f; materialColor[3] = meshColor[3] / 255.0f;
          glMaterialfv(GL_FRONT, GL_SPECULAR, materialColor);

          // set the material shininess factor
          float shininess;
          shininess = 50.0f; //pCalRenderer->getShininess();
          glMaterialfv(GL_FRONT, GL_SHININESS, &shininess);

          // get the transformed vertices of the submesh
          //static float meshVertices[30000][3];
          //int vertexCount = pCalRenderer->getVertices(&meshVertices[0][0]);

          // get the transformed normals of the submesh
          //static float meshNormals[30000][3];
          //pCalRenderer->getNormals(&meshNormals[0][0]);

          // get the texture coordinates of the submesh
          //static float meshTextureCoordinates[30000][2];
          //int textureCoordinateCount = pCalRenderer->getTextureCoordinates(0, &meshTextureCoordinates[0][0]);

          // get the faces of the submesh
          //static CalIndex meshFaces[50000][3];
          //int faceCount = pCalRenderer->getFaces(&meshFaces[0][0]);

          // set the vertex and normal buffers
          glVertexPointer(3, GL_FLOAT, 0, mVertices[renderBuffer][meshId][submeshId]);
          glNormalPointer(GL_FLOAT, 0, mNormals[renderBuffer][meshId][submeshId]);

          // set the texture coordinate buffer and state if necessary
          if((pCalRenderer->getMapCount() > 0) && (mTextureCoordCounts[renderBuffer][meshId][submeshId] > 0))
          {
            glEnable(GL_TEXTURE_2D);
            glEnableClientState(GL_TEXTURE_COORD_ARRAY);
            glEnable(GL_COLOR_MATERIAL);

            // set the texture id we stored in the map user data
			GLuint textureId = (long)pCalRenderer->getMapUserData(0);
			textureId = textureHandler->getTextureId(textureId);
            glBindTexture(GL_TEXTURE_2D, textureId);

            // set the texture coordinate buffer
            glTexCoordPointer(2, GL_FLOAT, 0, mTextureCoords[renderBuffer][meshId][submeshId]);
            glColor3f(1.0f, 1.0f, 1.0f);
          }

          // draw the submesh
		  
          if(sizeof(CalIndex)==2)
            glDrawElements(GL_TRIANGLES, mFaceCounts[renderBuffer][meshId][submeshId] * 3, GL_UNSIGNED_SHORT, mFaces[renderBuffer][meshId][submeshId]);
          else
            glDrawElements(GL_TRIANGLES, mFaceCounts[renderBuffer][meshId][submeshId] * 3, GL_UNSIGNED_INT, mFaces[renderBuffer][meshId][submeshId]);

          // disable the texture coordinate state if necessary
          if((pCalRenderer->getMapCount() > 0) && (mTextureCoordCounts[renderBuffer][meshId][submeshId] > 0))
          {
            glDisable(GL_COLOR_MATERIAL);
            glDisableClientState(GL_TEXTURE_COORD_ARRAY);
            glDisable(GL_TEXTURE_2D);
          }

          // adjust the vertex and face counter
          //m_vertexCount += vertexCount;
          //m_faceCount += faceCount;

        }
      }
    }

	glPopMatrix();
	glPopAttrib();
    // clear vertex array state
    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);

    // clear light
    //glDisable(GL_LIGHTING);
    //glDisable(GL_LIGHT0);
    //glDisable(GL_DEPTH_TEST);

    // end the rendering
    pCalRenderer->endRendering();
  }

};

#include <float.h>

Bound Piavca::AvatarCal3DImp::getBoundBox(void)
{
	if (bb_dirty_flag && !hardware)
	{
		//std::cout << "recalculating bb\n";
		bb_dirty_flag = false;
		// get the number of meshes
		CalRenderer *pCalRenderer = cal_model->getRenderer();
		int meshCount = pCalRenderer->getMeshCount();

		// resets bounding box
		bb.min[0] = FLT_MAX/2;
		bb.min[1] = FLT_MAX/2;
		bb.min[2] = FLT_MAX/2;
		bb.max[0] = -FLT_MAX/2;
		bb.max[1] = -FLT_MAX/2;
		bb.max[2] = -FLT_MAX/2;

		// render all meshes of the model
		for(int meshId = 0; meshId < meshCount; meshId++)
		{
			// check if the mesh is supposed to be hidden
			if (meshes[meshId].second) continue;

			// get the number of submeshes
			int submeshCount = pCalRenderer->getSubmeshCount(meshId);

			// render all submeshes of the mesh
			for(int submeshId = 0; submeshId < submeshCount; submeshId++)
			{
				// select mesh and submesh for further data access
				if(pCalRenderer->selectMeshSubmesh(meshId, submeshId))
				{
					float *vertexArray = mVertices[renderBuffer][meshId][submeshId];
					int vertexCount = pCalRenderer->getVertexCount();

					for (int vertexID=0;vertexID<vertexCount;vertexID++)
					{
						bb.max[0] = max(bb.max[0], vertexArray[vertexID*3+0]);
						bb.max[1] = max(bb.max[1], vertexArray[vertexID*3+1]);
						bb.max[2] = max(bb.max[2], vertexArray[vertexID*3+2]);

						bb.min[0] = min(bb.min[0], vertexArray[vertexID*3+0]);
						bb.min[1] = min(bb.min[1], vertexArray[vertexID*3+1]);
						bb.min[2] = min(bb.min[2], vertexArray[vertexID*3+2]);
					}
				}
			}
		}
	}

	return bb;
}

Bound Piavca::AvatarCal3DImp::getBaseBoundBox(void)
{
	return base_bb;	
};
