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
 * The Original Code is StdMotionCore.cpp.
 *
 * The Initial Developer of the Original Code is Marco (Mark) Gillies.
 * Portions created by the Initial Developer are Copyright (C) BT plc. 2004
 * All Rights Reserved.
 *
 * ***** END LICENSE BLOCK ***** */


//#ifdef PIAVCA_DLL
//#define PIAVCA_EXPORT __declspec( dllimport ) 
//#else
//#define PIAVCA_EXPORT
//#endif

#include "StdMotionCore.h"
#include "StdMotionImp.h"

using namespace Piavca;

#include <assert.h>

MotionImp *StdMotionCore::createMotionImp(tstring filename, bool facial, int flags, Motion *basePosture)
{
	// if a null string is passed in (or the method is called with no arguments)
	// create an empty motion
	// otherwise read from file
	if(filename == _T(""))
	{
		return new StandardMotionImp(facial);
	}
	else 
	{
		return new StandardMotionImp(filename, flags, basePosture, false);//test);
	}
}
