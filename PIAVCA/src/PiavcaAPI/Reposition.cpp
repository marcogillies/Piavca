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
 * The Original Code is Reposition.cpp.
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

#include "Reposition.h"
#include "PiavcaError.h"
#include "TypeConvert.h"

using namespace Piavca;



//! a generic function for setting parameters
bool Reposition::setParameter(tstring paramName, tstring value)
{
	if(paramName == _T("StartPosition") || paramName == _T("startPosition") || paramName == _T("startposition"))
	{
		setStartPosition(convert<Vec>(value));
		return true;
	}
	if(paramName == _T("StartOrientation") || paramName == _T("startOrientation") || paramName == _T("startorientation"))
	{
		setStartOrientation(convert<Quat>(value));
		return true;
	}
	if(paramName == _T("PosOffset") || paramName == _T("posOffset") || paramName == _T("posoffset"))
	{
		setPosOffset(convert<Vec>(value));
		return true;
	}
	if(paramName == _T("MaintainUp") || paramName == _T("maintainUp") || paramName == _T("maintainup"))
	{
		setMaintainUp(convert<bool>(value));
		return true;
	}
	if(paramName == _T("RotateAboutUp") || paramName == _T("rotateAboutUp") || paramName == _T("rotateaboutup"))
	{
		setRotateAboutUp(convert<bool>(value));
		return true;
	}
	if(paramName == _T("UpDirection") || paramName == _T("upDirection") || paramName == _T("updirection"))
	{
		setUpDirection(convert<Vec>(value));
		return true;
	}
	return MotionFilter::setParameter(paramName, value);
}


void Reposition::calculateRootOffsets()
{
	//if(isFacial())
	//	return;
	
	//start_orientation = Quat();
	//start_position = Vec();
	
	originalStart   = Vec();
	oriOffset = start_orientation;
	//oriOffset = Quat(start_orientation.Zangle(), Vec::ZAxis());
	float startTime=0;

	if (filterMot)
	{
		startTime = filterMot->getStartTime();
		filterMot->preFrame(filterMot->getStartTime());
	}
		
	if(filterMot && !filterMot->isNull(root_orientation_id))
	{
		Quat otherOri = filterMot->getQuatValueAtTime(root_orientation_id, filterMot->getStartTime());
		//otherOri = Quat(otherOri.Zangle(), Vec::ZAxis());
		oriOffset = oriOffset/otherOri;
	}

	if(filterMot && !filterMot->isNull(root_position_id))
	{
		Quat offs(oriOffset);
		offs.normalise();
		if (rotateAboutUp)
		{
			offs.projectToAxis(upDirection);
		}
		originalStart = filterMot->getVecValueAtTime(root_position_id, filterMot->getStartTime());
		originalStart = offs.transform(originalStart);
	}
	//oriOffset = Quat(oriOffset.Zangle(), Vec::ZAxis());
	//oriOffset = Quat();
	//oriOffset = Quat(1.57, Vec::ZAxis());
};

void Reposition::setMotion(Motion *m)
{
	MotionFilter::setMotion(m);
	calculateRootOffsets();
};

void Reposition::setStartFromMotion(Motion *m, float time)
{
	if (!m->isNull(root_position_id))
		setStartPosition(m->getVecValueAtTime(root_position_id, time));
	else
		setStartPosition(Vec());
	if (!m->isNull(root_orientation_id))
		setStartOrientation(m->getQuatValueAtTime(root_orientation_id, time));	
	else
		setStartOrientation(Quat());
	//std::cout << "Repositioner, time" << time << " start Position: " << start_position << std::endl;

};


bool Reposition::isNull(int trackId) const
{
	Reposition *non_const_this = const_cast<Reposition *>(this);
	if (//!non_const_this->isFacial() 
		/*&&*/ (trackId == root_position_id 
		|| trackId == root_orientation_id))
		return false;
	else
		return MotionFilter::isNull(trackId);
};

int Reposition::getTrackType(int trackId)const
{
	if (trackId == root_position_id)
		return VEC_TYPE;
	if( trackId == root_orientation_id)
		return QUAT_TYPE;
	else
		return MotionFilter::getTrackType(trackId);
};


float Reposition::getFloatValueAtTimeInternal(int trackId, float time)
{
	if(!filterMot)
	{
		Piavca::Error(_T("Reposition motion: trying to get a value from a null motion"));
	}
	//std::cout << "Scale Motion" << time << " " << filterMot->getFloatValueAtTime(trackId, time) << " " << scaleFactor << std::endl;
    return filterMot->getFloatValueAtTime(trackId, time);
};

Vec Reposition::getVecValueAtTimeInternal(int trackId, float time)
{
    if(trackId == root_position_id)
	{
		if(!filterMot || filterMot->isNull(trackId))
			return start_position;
		Vec OriginalValue = filterMot->getVecValueAtTime(trackId, time);
		//return OriginalValue;
		//Vec subtractedVec = oriOffset.transform(OriginalValue - originalStart) + posOffset;
		Vec subtraction = originalStart;
		
		if (!maintainUp)
		{
			subtraction = subtraction - upDirection*(upDirection.dot(subtraction));
		}
		Quat offs(oriOffset);
		offs.normalise();
		if (rotateAboutUp)
		{
			offs.projectToAxis(upDirection);
		}
		Vec rotatedValue = offs.transform(OriginalValue);
		Vec subtractedVec = rotatedValue - subtraction;
		subtractedVec += posOffset;
		//return oriOffset.transform(OriginalValue);
		//Vec subtractedVec = OriginalValue - originalStart;
		//return OriginalValue;
		Vec addition = start_position;
		if (!maintainUp)
		{
			addition = addition - upDirection*(upDirection.dot(addition));
		}
		//if(maintainY)
		return subtractedVec + addition;//+ start_position;
		//else
		//{
			
			//return Vec(subtractedVec[0] + start_position[0], OriginalValue[1], subtractedVec[2] + start_position[2]);
		//};
	}
	else
	{
		if(!filterMot)
		{
			Piavca::Error(_T("Reposition motion: trying to get a value from a null motion"));
		}
		return  filterMot->getVecValueAtTime(trackId, time);
	}
};


Quat Reposition::getQuatValueAtTimeInternal(int trackId, float time)
{
   if(trackId == root_orientation_id)
	{
		if(!filterMot || filterMot->isNull(trackId))
			return start_orientation;
		//return filterMot->getQuatValueAtTime(trackId, time);
		Quat offs(oriOffset);
		offs.normalise();
		if (rotateAboutUp)
		{
			offs.projectToAxis(upDirection);
		}
		return offs*filterMot->getQuatValueAtTime(trackId, time);
	}
	else
	{
		 if(!filterMot)
		{
			Piavca::Error(_T("Reposition motion: trying to get a value from a null motion"));
		}
		return filterMot->getQuatValueAtTime(trackId, time);
	}
};
