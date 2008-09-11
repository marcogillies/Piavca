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
 * The Original Code is Sequence.cpp.
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


#include "Sequence.h"
#include "PiavcaError.h"

using namespace Piavca;

void Sequence::setStartTime(float time)
{
	//std::cout << "setStartTime " << time << " ";
	Motion::setStartTime(time);
	if(mot1) 
	{
		mot1->setStartTime(time);
		if(mot2) 
		{
			mot2->setStartTime(mot1->getEndTime());
			//std::cout << " motion2 start time " << mot1->getEndTime() << std::endl;
		}
	}
	else
	{
		if(mot2) 
		{
			mot2->setStartTime(time);
			//std::cout << " motion2 start time " << time << std::endl;
		}
	}
}


float Sequence::getCombinedFloatValue (int trackId, float time) 
{
	// if its before the start of the blend return the value from the first motion
	if(time < mot1->getEndTime())
	    return mot1->getFloatValueAtTime(trackId, time);
	else
	    return mot2->getFloatValueAtTime(trackId, time);	
};

Vec  Sequence::getCombinedVecValue (int trackId, float time)
{
	// if its before the start of the blend return the value from the first motion
	if(time < mot1->getEndTime())
	    return mot1->getVecValueAtTime(trackId, time);
	else
	    return mot2->getVecValueAtTime(trackId, time);	
};

Quat Sequence::getCombinedQuatValue (int trackId, float time)
{
	// if its before the start of the blend return the value from the first motion
	if(time < mot1->getEndTime())
	    return mot1->getQuatValueAtTime(trackId, time);
	else
	    return mot2->getQuatValueAtTime(trackId, time);
};
