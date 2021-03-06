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
 * The Original Code is LoopMotion.h.
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

#ifndef LOOP_MOTION_H
#define LOOP_MOTION_H

#include "MotionFilter.h"
#include "PiavcaCore.h"
#include "TypeConvert.h"

namespace Piavca
{
    //! A motion filter that makes a motion loop continuously
	class PIAVCA_DECL LoopMotion : public MotionFilter
	{
		bool lock;
		float endTime;
		float finishTime;
	protected:
		bool reblend_flag;
	public:
		//! pass in the motion to loop and an optional blend interval, 
		/*!  (How long it takes to blend from the end back to the beginning)
		 */
		LoopMotion(Motion *mot = NULL, float _endTime = -1)
			:MotionFilter(mot), lock(false), reblend_flag(false), endTime(_endTime), finishTime(-1) {} ;
		LoopMotion(const LoopMotion &l)
			:MotionFilter(l), lock(false), reblend_flag(false), endTime(l.endTime), finishTime(-1){};

		virtual Motion *clone(){return new LoopMotion(*this);};

		//! returns the name of the type
		Piavca::tstring getClassName(){return "LoopMotion";};

		//! casts a motion to this type
		static LoopMotion *castToThisType(Motion *m){return dynamic_cast<LoopMotion *>(m);};

		virtual float getMotionLength()const
		{
			if (finishTime >=0)
				return finishTime;
			else if (endTime >= 0)
				return endTime;
			else
				return Motion::getMotionLength();
		};

		//! sets an end time after which the motion stops looping
		void setEndTime(float t){endTime = t;};
		float getEndTime(){return endTime;};
		
		//! a generic function for setting parameters
		virtual bool setParameter(tstring paramName, tstring value)
		{
			if(paramName == _T("EndTime") || paramName == _T("endTime") || paramName == _T("endtime"))
			{
				setEndTime(convert<float>(value));
				return true;
			}
			return MotionFilter::setParameter(paramName, value);
		}
		
				
		virtual void preFrame(float time)
		{
			//std::cout << "loop motion.preframe\n";
			//if (filterMot)
			//{
			//	std::cout << time << " ";
			//	std::cout << filterMot->getMotionLength()  << " ";
			//	std::cout << filterMot->getEndTime()  << std::endl;
			//}
			if (!lock 
				&& (reblend_flag
				|| (finishTime < 0 && (endTime < 0 || time < endTime)
				&& (!filterMot ||
				(/*filterMot->getMotionLength() >= 0 &&*/ time > filterMot->getEndTime())))))
				{
				    LoopMotion *nonConstThis = const_cast<LoopMotion *>(this);
					nonConstThis->lock = true;
					// rest the child motion, and if its finished set the end time to now
					if(nonConstThis->reset() == false)
					{
						finishTime = Piavca::Core::getCore()->getTime() - getStartTime();
					}
					nonConstThis->lock = false;
					reblend_flag = false;
				}
			MotionFilter::preFrame(time);
		}

		virtual void handleEvent(Piavca::tstring ev)
		{
			if (ev == "__chosen__")
				finishTime = -1;
			MotionFilter::handleEvent(ev);
		}

		//! called each time around the loop
		/*!
		 * It can be called by the client to interrupt the current motion.
		 */
		virtual bool reset(bool restart=false)
		{
			if(restart)
				finishTime = -1;
			bool retval = MotionFilter::reset(restart);
			if (retval)
				setStartTime(Piavca::Core::getCore()->getTime());	
			return retval;
		};
	    
	};
};


#endif //LOOP_MOTION_H
