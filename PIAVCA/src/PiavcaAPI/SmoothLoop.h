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
 * The Original Code is SmoothLoop.h.
 *
 * The Initial Developer of the Original Code is Marco (Mark) Gillies.
 * Portions created by the Initial Developer are Copyright (C) BT plc. 2008
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

#ifndef SMOOTH_LOOP_H
#define SMOOTH_LOOP_H

#include "LoopMotion.h"
#include "ChoiceMotion.h"

namespace Piavca
{
    //! a motion filter that makes a motion loop continuously
	class PIAVCA_DECL SmoothLoop : public LoopMotion
	{
		ChoiceMotion *choiceMot;
		Motion *originalMot;
	public:
		//! pass in the motion to loop and an optional blend interval, 
		/*!  (How long it takes to blend from the end back to the beginning)
		 */
		SmoothLoop(Motion *mot = NULL, float _endTime = -1, float interval = 0.5f)
			:LoopMotion(NULL, _endTime) 
		{
			choiceMot = new ChoiceMotion();
			choiceMot->Reference();
			setMotion(mot);
			setBlendInterval(interval);
		};
		SmoothLoop(const SmoothLoop &l)
			:LoopMotion(l){};

		virtual Motion *clone(){return new SmoothLoop(*this);};

		//! returns the name of the type
		Piavca::tstring getClassName(){return "SmoothLoop";};

		//! casts a motion to this type
		static SmoothLoop *castToThisType(Motion *m){return dynamic_cast<SmoothLoop *>(m);};

		void setMotion(Motion *mot)
		{
			originalMot = mot;
			choiceMot->clear();
			choiceMot->addMotion(originalMot);
			if (choiceMot->getNumMotions() > 0)
				choiceMot->setChoice(0);
			else
				choiceMot->setMotion(NULL);
			choiceMot->reset();
			LoopMotion::setMotion(choiceMot);
		};

		Motion *getMotion()
		{
			return originalMot;
		}

		void setAccumulateRoot(bool b)
		{
		};

		void setBlendInterval(float interval)
		{
			choiceMot->setWindowLength(interval);
		};

		float getBlendInterval()
		{
			return choiceMot->getWindowLength();
		};
	};
};


#endif //SMOOTH_LOOP_H
