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
 * The Original Code is SequentialChoiceMotion.cpp.
 *
 * The Initial Developer of the Original Code is Marco (Mark) Gillies.
 * Portions created by the Initial Developer are Copyright (C) 2008
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


#include "SequentialChoiceMotion.h"

#include <iostream>

using namespace Piavca;

//! sets the start time of the motion. Called when its loaded into an avatar.
void  SequentialChoiceMotion::setStartTime(float t)
{
	if (t < startTime)
	{
		//setChoice(0);
	}
	ChoiceMotion::setStartTime(t);
}

//! handles an event (plays the motion with the same name as the event)
void SequentialChoiceMotion::handleEvent(tstring ev)
{
	if(ev == _T("next"))
	{
		if(passEventsToChildren && getMotion()->canHandleEvent(_T("next")))
		{
			getMotion()->passEvent("next");
		}
		else
		{
			reset();
		}
	}
	
	else if(ev == _T("previous"))
	{
		setChoice(getCurrentChoice()-1);
		reset();
	}
	else if(ev == _T("first"))
	{
		setChoice(-1);
		reset();
	}
	else if (ev == _T("__chosen__"))
	{
			setChoice(-1);
			reset();
	}
	else
			MotionFilter::handleEvent(ev);
}

bool SequentialChoiceMotion::canHandleEvent(tstring ev)
{
	if(ev == _T("next") && getCurrentChoice()+1 < getNumMotions() )
		return true;
	if(ev == _T("previous") && getCurrentChoice() > 0 )
		return true;
	if(ev == _T("first") )
		return true;
	if(ev == _T("__chosen__") )
		return true;
	return MotionFilter::canHandleEvent(ev);
}

//! gets the names of all events
std::vector<Piavca::tstring> SequentialChoiceMotion::getEventNames()
{
	std::vector<Piavca::tstring> ret;
	ret.push_back(_T("next"));
	ret.push_back(_T("previous"));
	ret.push_back(_T("first"));
	return ret;
}


int SequentialChoiceMotion::makeChoice()
{
	int current = getCurrentChoice();

	//if(getMotion()->canHandleEvent(_T("next")))
	//{
	//	getMotion()->event("next");
	//	return current;
	//}

	std::cout << "SequentialChoiceMotion::makeChoice() " << getName() << " "  << current << std::endl;
	if (current+1 < getNumMotions())
	{
		std::cout << "increment " << current+1 << std::endl;
		return current +1;
	}
	else
	{
		std::cout << "same " << std::endl;
		return -1;
	}
}
