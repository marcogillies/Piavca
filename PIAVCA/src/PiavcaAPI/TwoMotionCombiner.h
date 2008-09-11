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
 * The Original Code is TwoMotionCombiner.h.
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
 *
 * ***** END LICENSE BLOCK ***** */


#ifndef TWO_MOTION_COMBINER_H
#define TWO_MOTION_COMBINER_H

#include "Motion.h"
//#include <algorithm>

namespace Piavca
{
	//! A motion manipulator that combine two different motion 
	/*!  This class is an abstract base class that just provides some common features between motion filters.
	 *	To actaully do anything you have to override the get[Float/Quat/Vec]ValueAtTime
	 *  methods to perform whatever opertation you want on the two motion.
	 */
    class PIAVCA_DECL TwoMotionCombiner : public Motion
	{
	protected:
	    Motion *mot1, *mot2;
	public:
		TwoMotionCombiner();
		/*!
		 *	Pass in the two motions you want to combine
		 */
	    TwoMotionCombiner(Motion *m1, Motion *m2) ;
		TwoMotionCombiner(const TwoMotionCombiner &tmc);
		virtual ~TwoMotionCombiner();
	
		virtual Motion *clone(){return new TwoMotionCombiner(*this);};

		//! returns the name of the type
		Piavca::tstring getClassName(){return "TwoMotionCombiner";};

		//! casts a motion to this type
		static TwoMotionCombiner *castToThisType(Motion *m){return dynamic_cast<TwoMotionCombiner *>(m);};
	
		void printInfo();

		//! finds the first submotion with a given name
		virtual Motion *findSub(tstring nm);
		//! finds the first submotion with a given type
		virtual Motion *findSubByType(const type_info &ty);

		virtual void load(Avatar *av);
		virtual void unload();
		virtual bool loaded();
		
		//! gets the avatar that the motion is loaded into
		virtual Avatar *getAvatar();

		virtual void setStartTime(float time);

		//! does any resetting needed 
		bool reset();
		
		virtual void event(tstring ev);

		virtual void cleanRecursionState();
	    
		//! gets the length of the combined motion (by default the length of the longer of the two)
		float getMotionLength() const;

		//! whether it is a face or body motion
		virtual bool isFacial();

		//! whether you can access a motions value at frames other than the current one
		virtual bool isRandomAccess();
		
		/*! do any processing that needs to be done at the start of a frame.
		*	This is called before get{Float/Vec/Quat}ValueAtTime
		*/
		virtual void preFrame(float time);
		
		//! given a track ID tests whether it actually points to anything or if its null
		/*!
		 *	is null if the track is null in both motions.
		 */
		bool isNull(int trackId)const;
		
		//! get the type of the track corresponding to an iterator
		int getTrackType(int trackId)const ;

		void setMotion1(Motion *mot);
		void setMotion2(Motion *mot);

		Motion *getMotion1(){return mot1;};
		Motion *getMotion2(){return mot2;}; 

		//! gets a combined value of two float tracks if both are valid
		virtual float getCombinedFloatValue (int trackId, float time);

		//! gets a combined value of two Vec tracks if both are valid
		virtual Vec  getCombinedVecValue (int trackId, float time);

		//! gets a combined value of two quaternion tracks if both are valid
		virtual Quat getCombinedQuatValue (int trackId, float time);

	    //! calculates the values of a keyframe.
		/*!	The result is the linear interpolation of the values of the two motions
		 *  or if the track does not exist in the one motion, the value of the other
		 */
	    virtual float getFloatValueAtTimeInternal (int trackId, float time);
	    
	    //! calculates the values of a keyframe.
		/*!	The result is the linear interpolation of the values of the two motions
		 *  or if the track does not exist in the one motion, the value of the other
		 */
	    virtual Vec   getVecValueAtTimeInternal   (int trackId, float time);
	    
	    //! calculates the values of a keyframe.
		/*!	The result is the linear interpolation (slerp) of the values of the two motions
		 *  or if the track does not exist in the one motion, the value of the other
		 */
	    virtual Quat  getQuatValueAtTimeInternal  (int trackId, float time);
	};
};

#endif //TWO_MOTION_COMBINER_H
