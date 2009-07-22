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
 * The Original Code is MotionGraph.cpp.
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


#include "MoGraph.h"

using namespace Piavca;

void MotionGraph::handleEvent(tstring ev)
{
	NodeLookupTable::iterator pos;
    pos = nodeLookup.find(ev);
    if (pos != nodeLookup.end()) {
		currentEvent = ev;
	}	
	else
	{
		ChoiceMotion::handleEvent(ev);
	}
};

bool MotionGraph::canHandleEvent(tstring ev)
{
	NodeLookupTable::iterator pos;
    pos = nodeLookup.find(ev);
    if (pos != nodeLookup.end()) {
		return true;
	}	
	else
	{
		return ChoiceMotion::canHandleEvent(ev);
	}
};

int MotionGraph::makeChoice()
{
	Motion *current = getMotionByIndex(getCurrentChoice());
	if (!current)
		current = getMotionByIndex(0);
	ChoiceMotion *currentChoice = dynamic_cast<ChoiceMotion *>(current);
	if (!currentChoice)
		Piavca::Error(_T("MotionGraph: current child motion is not a choice motion"));
	Motion *lastEdge = currentChoice->getMotionByIndex(currentChoice->getCurrentChoice());
	if (!lastEdge)
		Piavca::Error(_T("MotionGraph: current child motion does not have a current child"));
	std::cout << currentEvent << " " << lastEdge->getName() << " " << nodeLookup[currentEvent][lastEdge->getName()] << std::endl;
	return nodeLookup[currentEvent][lastEdge->getName()]; 
}