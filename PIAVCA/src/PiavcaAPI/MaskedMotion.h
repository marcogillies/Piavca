/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
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
 * The Original Code is MaskedMotion.h.
 *
 * The Initial Developer of the Original Code is Marco (Mark) Gillies.
 * Portions created by the Initial Developer are Copyright (C) 2005
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
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


#ifndef MASK_MOTION_H
#define MASK_MOTION_H

#include "PiavcaAPI/MotionFilter.h"

namespace Piavca
{

//! a set of masks specifying which joints should be played in a masked motion
class PIAVCA_DECL MotionMask
{
	std::vector<bool> m_body;
	std::vector<bool> m_facial;
public:
	MotionMask(){};
	MotionMask(const MotionMask &mm);
	const MotionMask &operator=(const MotionMask &mm);
	//! sets whether a given track should be played
	void setMask(int track, bool val = true);
	//! sets a mask value for all tracks
	void setAllMask(bool val);
	//! gets the mask value for a track
	bool getMask(int track) const;
	//! clears all values in the mask
	void clearMask();
};



//! Only plays a motion on certain joints, not others.
/*!
 *	It uses a mask to tell which motion to play on which joint.
 */
class PIAVCA_DECL MaskedMotion : public MotionFilter
{
	MotionMask mask;
public:
	MaskedMotion();
	//! initialise with 1 motions, each with its own mask
	/*!
	 *  If the useSecondary flag is set then if neither motion has a mask
	 *  set then it will play the joint with motion1 if the track exists
	 *  otherwise motion2. If it is not set then joints that are in neither mask
	 *  are unaffected.
	 */
	MaskedMotion(Motion *_mot, const MotionMask &_mask) ;
	MaskedMotion(const MaskedMotion &mm);
	
	//! given an iterator tests whether it actually points to anything or if its null
	virtual bool isNull(int trackId)const 
	{
		if(filterMot)
			return filterMot->isNull(trackId) || !(mask.getMask(trackId));
		else
			return true;
	};

	//! get the type of the track corresponding to an iterator
	int getTrackType(int trackId)const;

	virtual Motion *clone(){return new MaskedMotion(*this);};

	//! returns the name of the type
	Piavca::tstring getClassName(){return "MaskedMotion";};

	//! casts a motion to this type
	static MaskedMotion *castToThisType(Motion *m){return dynamic_cast<MaskedMotion *>(m);};

	void setMask(const MotionMask &_mask){mask = _mask;};
	void setMask(std::vector<std::string>  v);
	MotionMask getMask()
	{
		std::cout << "getMask" << std::endl;
		return mask;
	};
	

	void addToMask(int trackId){mask.setMask(trackId, true);};
	void removeFromMask(int trackId){mask.setMask(trackId, false);};

	void addAllToMask();
	void removeAllFromMask();

	//void setMotionMask(std::vector<std::string>  v);
	//StringVector getMotionMask();

	virtual float getFloatValueAtTimeInternal (int trackId, float time);
	virtual Vec getVecValueAtTimeInternal (int trackId, float time);	
	virtual Quat getQuatValueAtTimeInternal (int trackId, float time);
};
};


PIAVCA_DECL std::ostream &operator<<(std::ostream &os, const Piavca::MotionMask &m);

#endif //MASK_MOTION_H
