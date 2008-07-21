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



//! handles an event (plays the motion with the same name as the event)
void SequentialChoiceMotion::event(tstring ev)
{
	if(ev == _T("next"))
		reset();
}

//! gets the names of all events
std::vector<Piavca::tstring> SequentialChoiceMotion::getEventNames()
{
	std::vector<Piavca::tstring> ret;
	ret.push_back(_T("next"));
	return ret;
}


int SequentialChoiceMotion::makeChoice()
{
	int current = getCurrentChoice();
	std::cout << "SequentialChoiceMotion::makeChoice() " << current << std::endl;
	if (current+1 < getNumMotions())
	{
		std::cout << "increment " << current+1 << std::endl;
		return current +1;
	}
	else
	{
		std::cout << "same " << std::endl;
		return current;
	}
}