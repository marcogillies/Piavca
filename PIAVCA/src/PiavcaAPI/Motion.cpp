/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is Motion.cpp.
 *
 * The Initial Developer of the Original Code is Marco (Mark) Gillies.
 * Portions created by the Initial Developer are Copyright (C) BT plc. 2004
 * All Rights Reserved.
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */


//#ifdef PIAVCA_DLL
//#define PIAVCA_EXPORT __declspec( dllexport ) 
//#else
//#define PIAVCA_EXPORT
//#endif
//#define PIAVCA_IMPORT __declspec( dllimport ) 

#include "PiavcaDefs.h"
#include "PiavcaCore.h"
#include "Motion.h"
#include "KeyframeMotion.h"
#include "Avatar.h"
#include "PiavcaError.h"

#include <assert.h>
#include <algorithm>

using namespace Piavca;

int Motion::debug_prefix = 0;

void Motion::create()
{
	
};

void Motion::printInfo()
{
	for(int i = 0; i < debug_prefix; i++)
		std::cout << " > ";
	std::cout << typeid(*this).name() << " " << getName() << std::endl;
};

// the granularity at which keyframes can be set 
//float Motion::keyframeGranularity = 1.0/1000.0;

int Motion::begin() const 
{
	int i=Core::getCore()->getMinTrackId(); 
	while(i <= end() && isNull(i))i++; 
	return i;
};
int Motion::end() const 
{
	return Core::getCore()->getMaxTrackId()+1;
};
int Motion::next(int &trackId)const 
{
	int maxTrack = Core::getCore()->getMaxTrackId();
	while(isNull(++trackId)&&trackId<=maxTrack);
	return trackId;
};

void Motion::Dispose()
{	
	//Core::getCore()->disposeMotion(mot);
	refCount--;
	if(refCount <= 0)
		Core::getCore()->removeMotion(this);
};

void Motion::pause()
{
	// negative pausedTime == not paused
	// if you are already paused this command should have no effect
	if(pausedTime < 0)
		pausedTime = Core::getCore()->getTime();
}

void Motion::unpause()
{
	// negative pausedTime == not paused
	if(pausedTime >= 0)
	{
		// reset the start time so that the motion restarts at the 
		// place it started
		offsetTime = -(Core::getCore()->getTime()-pausedTime);
		pausedTime = -1;
	}
}

void Motion::preFrame(float time)
{
	//std::cout << "Motion.preFrame\n";
}
