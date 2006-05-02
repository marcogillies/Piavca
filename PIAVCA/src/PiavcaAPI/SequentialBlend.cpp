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
 * The Original Code is SequentialBlend.cpp.
 *
 * The Initial Developer of the Original Code is Marco (Mark) Gillies.
 * Portions created by the Initial Developer are Copyright (C) BT plc. 2004
 * All Rights Reserved.
 *
 * ***** END LICENSE BLOCK ***** */


//#ifdef PIAVCA_DLL
//#define PIAVCA_EXPORT __declspec( dllexport ) 
//#else
//#define PIAVCA_EXPORT
//#endif

#include "SequentialBlend.h"
#include "PiavcaError.h"

using namespace Piavca;


void SequentialBlend::calculateRootOffsets()
{
	if(isFacial())
		return;
	m1End     = Vec();
	m2Start   = Vec();
	oriOffset = Quat();
	if(mot1 && !mot1->isNull(root_position_id))
		m1End  = mot1->getVecValueAtTime(root_position_id, blendStart);
	float m2startTime=0;
	if(mot2 && !mot2->isNull(root_position_id))
	{
		m2startTime = mot2->getStartTime();
		m2Start = mot2->getVecValueAtTime(root_position_id, mot2->getStartTime());
	}
	
	std::cout << "sequential blend root offsets " << m1End << " " << m2Start 
		<< " " << blendStart << " " << m2startTime << std::endl;

	if(mot1 && !mot1->isNull(root_orientation_id)) 
	{
		oriOffset = mot1->getQuatValueAtTime(root_orientation_id, blendStart);
	}
	if(mot1 && !mot2->isNull(root_orientation_id))
	{
		Quat otherOri = mot2->getQuatValueAtTime(root_orientation_id, mot2->getStartTime());
		oriOffset = oriOffset/otherOri;
	}
};

float SequentialBlend::getFloatValueAtTimeInternal(int trackId, float time)
{
	if(!mot1 || mot1->isNull(trackId)) 
	{
		if(!mot2 || mot2->isNull(trackId)) 
		{
			Piavca::Error(_T("trying to blend two null tracks"));
			return 0.0;
		}
		return mot2->getFloatValueAtTime(trackId, time);
	}
	if(!mot2 ||mot2->isNull(trackId)) return mot1->getFloatValueAtTime(trackId, time);
    //float t = time - startTime;
	// if its before the start of the blend return the value from the first motion
    if(time < blendStart)
	    return mot1->getFloatValueAtTime(trackId, time);
	// if its during the blend interpolate
	//t -= blendStart;
	if(time - blendStart < blendInterval)
	{
		float t = time - blendStart;
		return (1-t/blendInterval)*mot1->getFloatValueAtTime(trackId, blendStart) + (t/blendInterval)*mot2->getFloatValueAtTime(trackId, time);
	}
	// otherwise its the value from the second motion
	//t -= blendInterval;
    return mot2->getFloatValueAtTime(trackId, time);
};

Vec SequentialBlend::getTransformedVec(int trackId, float t)const
{
	/*Vec m1End  = mot1->getVecValueAtTime(trackId, blendStart);
	//std::cout << "m1 end: " << m1End << std::endl;
	Vec m2Start = mot2->getVecValueAtTime(trackId, 0.0);
	
	Quat oriOffset;
	if(!mot1->isNull(root_orientation_id)) 
	{
		oriOffset = mot1->getQuatValueAtTime(root_orientation_id, blendStart);
	}
	if(!mot2->isNull(root_orientation_id))
	{
		Quat otherOri = mot2->getQuatValueAtTime(root_orientation_id, 0.0);
		oriOffset = oriOffset/otherOri;
	}*/
	Vec subtractedVec = oriOffset.transform(mot2->getVecValueAtTime(trackId, t) - m2Start);
	//std::cout << t << " " << mot2->getStartTime() << " ";
	//std::cout << "sequential blend " << m1End[1] << " " << m2Start[1] << " " << subtractedVec[1] << " " << (subtractedVec + m1End)[1] << std::endl;
	// we normally only maintian the x-z coordinates of
	// the previous position, and blend back the y (to 
	// stop the character flying away)
	if(true/*maintainY*/)
		return subtractedVec + m1End;
	else
		return Vec(subtractedVec[0] + m1End[0], mot2->getVecValueAtTime(trackId, t)[1], subtractedVec[2] + m1End[2]);
}

Vec SequentialBlend::getVecValueAtTimeInternal(int trackId, float time)
{
	if(mot1->isNull(trackId))  
	{
		if(mot2->isNull(trackId)) 
		{
			Piavca::Error(_T("trying to blend two null tracks"));
			return Vec();
		}
		return mot2->getVecValueAtTime(trackId, time);
	}
	if(!mot2 || mot2->isNull(trackId)) return mot1->getVecValueAtTime(trackId, time);
    //float t = time - startTime;
	
	// if its the root we do something special, otherwise just return the above
	if(trackId == root_position_id)
	{
		// if its before the start of the blend return the value from the first motion
		if(time < blendStart)
		{
			std::cout << "sequential blend, before blend start\n";		
			return mot1->getVecValueAtTime(trackId, time);
		
		}
		if(time - blendStart < blendInterval)
		{
			std::cout << "sequential blend, during blend\n";
			float t = time - blendStart;
			return /*mot1->getVecValueAtTime(trackId, blendStart)*/m1End*(1-t/blendInterval) +getTransformedVec(trackId, mot2->getStartTime())*(t/blendInterval);
				
			//Vec rootVal = mot1->getVecValueAtTime(trackId, blendStart);
			// we normally only maintian the x-z coordinates of
			// the previous position, and blend back the y (to 
			// stop the character flying away)
			//if(maintainY)
			//	return rootVal;
			//else 
			//{
			//	float t = time - blendStart;
			//	Vec v = mot1->getVecValueAtTime(trackId, blendStart)*(1-t/blendInterval) +getTransformedVec(trackId, 0.0)*(t/blendInterval);
			//	return Vec(rootVal[0], v[1], rootVal[2]);
			//}
		}
		else
			return getTransformedVec(trackId, time);
	}
	else
	{
		// if its before the start of the blend return the value from the first motion
		if(time < blendStart)
			return mot1->getVecValueAtTime(trackId, time);
		// if its during the blend interpolate
		if(time - blendStart < blendInterval)
		{
			float t = time - blendStart;
			return mot1->getVecValueAtTime(trackId, blendStart)*(1-t/blendInterval) + mot2->getVecValueAtTime(trackId, mot2->getStartTime())*(t/blendInterval);
		}
		else
		{
			// otherwise its the value from the second motion
			return  mot2->getVecValueAtTime(trackId, time);
		}
	}
};

Quat SequentialBlend::getTransformedQuat(int trackId, float t) const
{
	if(trackId == root_orientation_id)
	{
	    /*Quat startOffset;
		if(!mot1->isNull(root_orientation_id))
			startOffset = mot1->getQuatValueAtTime(trackId, blendStart);
		//std::cout << "*" << startOffset << std::endl;
		if(!mot2->isNull(root_orientation_id))
		{
			startOffset = startOffset/mot2->getQuatValueAtTime(root_orientation_id, 0.0);
			//std::cout << startOffset << std::endl;
		}*/
		//std::cout << mot2->getQuatValueAtTime(trackId, t) << std::endl;
	    return oriOffset * mot2->getQuatValueAtTime(trackId, t);
	}
	else
		return mot2->getQuatValueAtTime(trackId, t);
}

Quat SequentialBlend::getQuatValueAtTimeInternal(int trackId, float time)
{
    if(!mot1 || mot1->isNull(trackId))  
	{
		if(!mot2 || mot2->isNull(trackId)) 
		{
			Piavca::Error(_T("trying to blend two null tracks"));
			return Quat();
		}
		return mot2->getQuatValueAtTime(trackId, time);
	}
	if(!mot2 || mot2->isNull(trackId)) return mot1->getQuatValueAtTime(trackId, time);
    //float t = time - startTime;
    //if(trackId == 8) std::cout << "time " << time << "blend start " << blendStart << " blend interval " << blendInterval << std::endl;
    //std::cout << "*" << mot1->getQuatValueAtTime(trackId, t) << std::endl;
    //std::cout << mot2->getQuatValueAtTime(trackId, t) << std::endl;
	// if its before the start of the blend return the value from the first motion
    if(time < blendStart)
	{
		//if(trackId == 8) 
		//	std::cout << "before blend "
		//	<< time << " " << blendStart << " " << Core::getCore()->getTime() << std::endl;
	    return mot1->getQuatValueAtTime(trackId, time);
	}
	if(trackId == root_orientation_id)
	{
	    //std::cout << "hello mum\n";
	    //t -= blendStart;   
	    if(time - blendStart < blendInterval)
			return mot1->getQuatValueAtTime(trackId, blendStart);
		else
		{
		    Quat retval = getTransformedQuat(trackId, time);//-blendInterval);
			//std::cout << retval << std::endl; 
			return retval;
		}
	}
	else
	{
		// if its during the blend interpolate
		//t -= blendStart;
		if(time - blendStart < blendInterval)
		{
			float t = time - blendStart;
			//if(trackId == 8) std::cout << "in blend\n";
			Quat q = slerp(mot1->getQuatValueAtTime(trackId, blendStart), mot2->getQuatValueAtTime(trackId, mot2->getStartTime()), t/blendInterval);
			q.normalise();
			return q;
		}// otherwise its the value from the second motion
		//t -= blendInterval;
		//if(trackId == 8) std::cout << "after blend\n";
		//std::cout << mot2->getQuatValueAtTime(trackId, t) << std::endl;
		return mot2->getQuatValueAtTime(trackId, time);
	}
};
