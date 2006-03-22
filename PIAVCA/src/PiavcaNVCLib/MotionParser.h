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
 * The Original Code is MotionParser.h.
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


#ifndef MOTION_PARSER_H
#define MOTION_PARSER_H
//
//#include "PiavcaAPI/Motion.h"
//#include "PiavcaAPI/Avatar.h"
//#include "PiavcaAPI/SequentialBlend.h"
//#include "PiavcaNVCLib/ScaleMotionRoot.h"
//#include "PiavcaNVCLib/ScaleMotion.h"
//#include "PiavcaNVCLib/ScaleMotionSpeed.h"
//#include "PiavcaNVCLib/ChangeMotionProp.h"
//#include "PiavcaNVCLib/ChangeMotionLength.h"
//#include "PiavcaAPI/LoopMotion.h"
//#include "PiavcaNVCLib/TurnMotion.h"
//#include "PiavcaAPI/BlendBetween.h"
//#include "PiavcaAPI/MotionAdder.h"
//#include "PiavcaAPI/AvatarPostureBlend.h"
//#include "PiavcaNVCLib/LookAtMotion.h"
//#include "PiavcaNVCLib/ChoiceLoopMotion.h"
//#include "PiavcaNVCLib/RandomLoopMotion.h"
//#include "PiavcaNVCLib/RandomBlendLoop.h"
//#include "PiavcaNVCLib/RandomAddLoop.h"
//#include "PiavcaNVCLib/RandomGazeMotion.h"
//#include "PiavcaNVCLib/DiadicGazeMotion.h"
//#include "PiavcaNVCLib/ProxemicsLoop.h"
//#include "PiavcaNVCLib/RandomTimingsLoop.h"
//#include "PiavcaNVCLib/MaskedMotion.h"
//#include "PiavcaNVCLib/ZeroMotion.h"

//#include "PiavcaTCLInterface.h"

#include <sstream>
using std::istringstream;
#include <map>

#include "PiavcaAPI/PiavcaDefs.h"

namespace Piavca
{

class Motion;
class Avatar;

class MotionParser
{
	static std::map<tstring, MotionParser *> commandLookup;
public:
	MotionParser(){};
	
	virtual Piavca::Motion *parseMotion(istringstream &is, std::string currentWord, float scaleFactor)=0; 
	virtual Piavca::Motion *editMotion(istringstream &is)=0;
	virtual void editAvatarMotion(Avatar *av, bool facial, istringstream &is)=0;

	static Motion *parseMotion(const char *s, float scaleFactor = 1.0f)
	{
		return parseMotion(std::string(s), scaleFactor);
	}
	
	static Motion *parseMotion(std::string s, float scaleFactor = 1.0f)
	{
		MotionParser *mp = NULL;
		return parseMotion(istringstream(s), scaleFactor, &mp);
	}

	static Motion *parseMotion(istringstream &is, float scaleFactor, MotionParser **mp)
	{
		return parseMotion(is, "", scaleFactor, mp);
	}
	PIAVCA_DECL static Motion *parseMotion(istringstream &is, std::string currentWord, float scaleFactor, MotionParser **mp);
	PIAVCA_DECL static void addMotionCommand(tstring name, MotionParser *command);
	PIAVCA_DECL static MotionParser *getMotionCommand(tstring name);
	PIAVCA_DECL static void setUpMotionCommands();
};

};

#endif //MOTION_PARSER_H
