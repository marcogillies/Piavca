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
 * The Original Code is EventMapChoice.cpp.
 *
 * The Initial Developer of the Original Code is Marco (Mark) Gillies.
 * Portions created by the Initial Developer are Copyright (C) 2009
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


#include "EventMapChoice.h"

using namespace Piavca;

void EventMapChoice::event(tstring ev)
{
	// if the event is in the lookup, choose that motion
	// otherwise try the motion filter (ignore the 
	// choice motion event handler)
	std::map<tstring, unsigned int>::iterator pos;
    pos = lookup.find(ev);
    if (pos != lookup.end()) 
	{
		setChoice(lookup[ev]);
		eventHappened = true;
		if(getResetOnEvent())
			reset();
		return;
	}
	// propagate to children
	if (getEventsToAllChildren())
	{
		for(int i = 0; i < int(mots.size()); i++)
			mots[i]->event(ev);
	}
	else
	{
		MotionFilter::event(ev);
	}
};

bool EventMapChoice::canHandleEvent(tstring ev)
{
	std::map<tstring, unsigned int>::iterator pos;
    pos = lookup.find(ev);
    if (pos != lookup.end()) {
		return true;
	}	
	else
	{
		return ChoiceMotion::canHandleEvent(ev);
	}
};
