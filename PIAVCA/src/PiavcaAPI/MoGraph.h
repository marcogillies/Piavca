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
 * The Original Code is MotionGraph.h.
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

#ifndef MOTION_GRAPH_H
#define MOTION_GRAPH_H

#include "ChoiceMotion.h"
#include <map>
#include <vector>

namespace Piavca
{
typedef std::map<tstring, std::map<tstring, int> > NodeLookupTable;

//! a choice motion where a new motion is chosen randomly at each reset
class MotionGraph : public ChoiceMotion
{
protected:
	NodeLookupTable nodeLookup;
	tstring currentEvent;
public:
	MotionGraph():currentEvent(_T("")){};
	MotionGraph(const MotionVec &mv):ChoiceMotion(mv),currentEvent(_T("")){};
	MotionGraph(const MotionGraph &mg)
		:ChoiceMotion(mg), nodeLookup(mg.nodeLookup), currentEvent(mg.currentEvent){};
	~MotionGraph(){};
	
	virtual Motion *clone(){return new MotionGraph(*this);};

	//! returns the name of the type
	Piavca::tstring getClassName(){return "MotionGraph";};

	//! casts a motion to this type
	static MotionGraph *castToThisType(Motion *m){return dynamic_cast<MotionGraph *>(m);};

	static MotionGraph *convertTo(Motion *m)
	{
		return dynamic_cast<MotionGraph *>(m);
	};

	void addEvent(tstring ev)
	{
		nodeLookup[ev] = std::map<tstring, int>();
		if (nodeLookup.size() == 1)
			currentEvent = ev;
	};

	void addNextNode(tstring ev, tstring motionName, int nextNode)
	{
		NodeLookupTable::iterator pos;
        pos = nodeLookup.find(ev);
        if (pos == nodeLookup.end()) {
			addEvent(ev);
		}
		nodeLookup[ev][motionName] = nextNode;
	};

	//! handles an event 
	void event(tstring ev);
	virtual bool canHandleEvent(tstring ev);

	virtual int makeChoice();

};

};

#endif //MOTION_GRAPH_H