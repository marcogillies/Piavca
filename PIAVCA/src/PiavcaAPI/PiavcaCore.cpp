/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basi,s
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is PIAVCACore.cpp.
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


//#ifdef PIAVCA_DLL
//#define PIAVCA_EXPORT __declspec( dllexport ) 
//#else
//#define PIAVCA_EXPORT
//#endif

#include "PiavcaCore.h"
#include "PiavcaError.h"
#include <algorithm>

using namespace Piavca;

#include "Avatar.h"
#include "Object.h"
#include "KeyframeMotion.h"
#include "TimeCallback.h"

Piavca::Core *Piavca::Core::core = NULL;



Core::Core()
	:maxJointId(0), maxExpressionId(0), 
	exceptionFlag(true), log_file("piavca_log.txt"),
	autoTimeOff(false)
{
	addJointNameSet(StringVector(1, _T("Root Position")));
	addJointNameSet(StringVector(1, _T("Root Orientation")));
	core = this;
};	

Core::~Core()
{	
	reset(); 
};


void Core::reset()
{
	unsigned int i;
	for (i = 0; i < callbacks.size(); i++)
		delete callbacks[i];
	callbacks.clear();
	for (i = 0; i < avatars.size(); i++)
		delete avatars[i];
	avatars.clear();
	for (i = 0; i < objects.size(); i++)
		delete objects[i];
	objects.clear();
	for (i = 0; i < motions.size(); i++)
		delete motions[i].second;
	motions.clear();
};

void Core::registerCallback(TimeCallback *cb) 
{
	if(!cb)
	{
		Piavca::Error(_T("Trying to register a null pointer as a callback"));
		return;
	}
	callbacks.push_back(cb);
	cb->init(this);
};

void Core::timeStep(float time)
{
	//std::cout << "time stepping " << time << std::endl;
	static bool firstime = true;
	static float prev_time = time;
	if(firstime)
	{
		firstime = false;
		return;
	}
	if(time < 0.0)
	{
		//std::cout << time << std::endl;
		std::cout.flush();
		time = 0.0;
		//Piavca::Error("Weird and crazy error, somehow got a zero time");
		//return;
	};
	unsigned int i;
	for (i = 0; i < callbacks.size(); i++)
		callbacks[i]->timeStep(this, time);
	for (i = 0; i < avatars.size(); i++)
		if(avatars[i]->active) avatars[i]->timeStep(time);

	if((time - prev_time) > 10.0f)
	{
		prev_time = time;
		printProfileData();
	}
};


void Core::prerender()
{
	
};

void Core::render()
{
	
};


int Core::getJointId(tstring name)
{
	std::map<tstring, int> ::iterator it = jointMap.find(name);
	if(it == jointMap.end())return -1;
	return (*it).second;
}

class compIds
{
public:
	bool operator()(std::pair<tstring, int> id1, std::pair<tstring, int> id2)
	{
		return id1.second < id2.second;
	}
};

void Core::addJointNameSet(Piavca::StringVector names)
{
	// hunt through the joint map searching either for a name that 
	// matches one in the new list, or the max value
	int id = -1;
	unsigned int i;
	std::map<tstring, int> ::iterator it;
	for(i = 0; i < names.size(); i++)
	{
		it = jointMap.find(names[i]);
		if(it != jointMap.end())
		{
			if(id >= 0 && id != (*it).second)
				Piavca::Error(_T("trying to load inconsistent joint names, problem: ") + names[i]);
			else
				id = (*it).second;
		}
	}
	// if you didn't find a matching name use max+1 as the new id

	if(id < 0)
	{
		it = std::max_element(jointMap.begin(), jointMap.end(), compIds());
		if(it == jointMap.end()) 
			id = 0;
		else
			id = (*it).second+1;
		maxJointId = id;
		//for (i = 0; i < avatars.size(); i++)
		//	avatars[i]->newJoint();
		//for (i = 0; i < motions.size(); i++)
		//	motions[i].second->newJoint();
	}
	for(i = 0; i < names.size(); i++)
		jointMap[names[i]] = id;
}


class findId
{
	int equalVal;
public:
	findId(int f):equalVal(f){};
	bool operator()(std::pair<tstring, int> id)
	{
		return id.second == equalVal;
	}
};

tstring Core::getJointName(int jointId)
{
	std::map<tstring, int> ::iterator it = std::find_if(jointMap.begin(), jointMap.end(), findId(jointId));
	return (*it).first;
};


std::vector<std::pair<tstring, int> > Core::getJointNameAssociations()
{
	std::vector<std::pair<tstring, int> > v(jointMap.begin(), jointMap.end());
	return v;
}

int Core::getExpressionId(tstring name)
{
	std::map<tstring, int> ::iterator it = expressionMap.find(name);
	if(it == expressionMap.end())return -1;
	return (*it).second;
}

void Core::addExpressionNameSet(Piavca::StringVector names)
{
	// hunt through the joint map searching either for a name that 
	// matches one in the new list, or the max value
	int id = -1;
	unsigned int i;
	std::map<tstring, int> ::iterator it;
	for(i = 0; i < names.size(); i++)
	{
		it = expressionMap.find(names[i]);
		if(it != expressionMap.end())
		{
			if(id >= 0 && id != (*it).second)
				Piavca::Error(_T("trying to load inconsistent expression names, problem: ") + names[i]);
			else
				id = (*it).second;
		}
	}
	// if you didn't find a matching name use max+1 as the new id

	if(id < 0)
	{
		it = std::max_element(expressionMap.begin(), expressionMap.end(), compIds());
		if(it == expressionMap.end()) 
			id = 0;
		else
			id = (*it).second+1;
		maxExpressionId = id;
		//for (i = 0; i < avatars.size(); i++)
		//	avatars[i]->newExpression();
		//for (i = 0; i < motions.size(); i++)
		//	motions[i].second->newExpression();
	}
	for(i = 0; i < names.size(); i++)
		expressionMap[names[i]] = id;
}


tstring Core::getExpressionName(int expressionId)
{
	std::map<tstring, int> ::iterator it = std::find_if(expressionMap.begin(), expressionMap.end(), findId(expressionId));
	return (*it).first;
};

std::vector<std::pair<tstring, int> > Core::getExpressionNameAssociations()
{
	std::vector<std::pair<tstring, int> > v(expressionMap.begin(), expressionMap.end());
	return v;
}

void Core::loadMotion(tstring motionName, Motion *mot, bool temp, Motion *basePosture)
{
	mot->setName(motionName);
	//if(!temp) mot->Reference();
	unloadMotion(motionName);
	mot->ownedByCore = temp;
	motions.push_back(std::make_pair(motionName, mot));
};

void Core::loadMotion(tstring motionName, tstring motionFileName, int flags, bool temp, Motion *basePosture)
{
	Motion * mot = new KeyframeMotion(motionFileName, flags, basePosture);
	mot->setName(motionName);
	//if(!temp) mot->Reference();
	unloadMotion(motionName);
	mot->ownedByCore = temp;
	motions.push_back(std::make_pair(motionName, mot));
};


//! changes the name of a motion
void Core::renameMotion(tstring oldName, tstring newName)
{
	if(newName == oldName) return;

	for (unsigned int i = 0; i < motions.size(); i++)
	{
		if(motions[i].first == newName)
		{
			Piavca::Error(_T("Trying to rename motion") + oldName + _T("to the name of an exisiting motion: ") + newName);
		}
	}
 	for (unsigned int i = 0; i < motions.size(); i++)
	{
		if(motions[i].first == oldName)
		{
			motions[i].first = newName;
			return;
		}
	}
}

void Core::removeMotion(Motion *mot)
{
	if(mot && mot->refCount <= 0 && !mot->ownedByCore)
	{
		for (vector<std::pair<tstring, Motion *> >::iterator i = motions.begin(); i != motions.end(); i++)
		{
			if((*i).second == mot)
				i = motions.erase(i);
		}
		delete mot;
	}
};

void Core::unloadMotion(tstring name)
{
	for (vector<std::pair<tstring, Motion *> >::iterator i = motions.begin(); i != motions.end(); i++)
	{
		if((*i).first == name)
		{
			Motion *mot = i->second;
			i = motions.erase(i);
			if(mot)
			{
				mot->ownedByCore = false;
				mot->Dispose();
			}
			break;
		}
	}
};


Motion *Core::getMotion(tstring motionName)
{
	std::cout << "looking for motion " << motionName << std::endl;
	for (unsigned int i = 0; i < motions.size(); i++)
	{
		if(motions[i].first == motionName)
		{
			std::cout << "found motion\n";
			return motions[i].second->clone();
		}
	}
	std::cout << "no motion Found\n";
	return NULL;
};

//! get motion names
PIAVCA_EXPORT std::vector<std::string> Core::getMotionNames(int number)
{
    std::vector<std::string> motionNames;
	int maxNumber = static_cast<int>(motions.size());
    
    // If the number of motion names to extract is ZERO or greater than the total number then extract all the names
    if (number == 0 || number > maxNumber)
        number = maxNumber;
	motionNames.reserve(number);

	for (int i = 0; i < number; i++)
	{
		motionNames.push_back(motions[i].first);
	}
    
    return motionNames;
}


PIAVCA_EXPORT std::list<tstring> Core::getAllmotions()
{
	std::list<tstring> tmpNames;

	for (unsigned int i = 0; i < motions.size(); i++)
	{
		tmpNames.push_back(motions[i].first);
	}
	return tmpNames;
};

Avatar *Core::getAvatar(tstring avatarName)
{
	for (unsigned int i = 0; i < avatars.size(); i++)
	{
		if(avatars[i]->getName() == avatarName)
		{
			return avatars[i];
		}
	}
	std::cout << "looking for avatar " << avatarName << std::endl;
	std::cout << "no avatar Found\n";
	return NULL;
};


Avatar *Core::getAvatar(int i)
{
	if(i >= 0 && i < numAvatars())
		return avatars[i];
	else
	{
		Piavca::Error(_T("trying to get an avatar from an invalid index"));
		return NULL;
	}
};

std::vector<tstring> Core::getAvatarNames()
{
	std::vector<tstring> names;
	names.reserve(avatars.size());
	for(std::vector<Avatar *>::size_type i=0; i < avatars.size(); i++)
		names.push_back(avatars[i]->getName());
	return names;
}



//! changes the name of an avatar
void Core::renameAvatar(tstring oldName, tstring newName)
{
	if(newName == oldName) return;

 	for (unsigned int i = 0; i < avatars.size(); i++)
	{
		if(avatars[i]->getName() == newName)
		{
			Piavca::Error(_T("Trying to rename motion") + oldName + _T("to the name of an exisiting motion: ") + newName);
		}
	}
 	for (unsigned int i = 0; i < avatars.size(); i++)
	{
		if(avatars[i]->getName() == oldName)
		{
			avatars[i]->name = newName;
			return;
		}
	}
}

//! removes and avatar
void Core::removeAvatar(Avatar *avatar)
{
	std::vector<Avatar *>::iterator it = std::find(avatars.begin(), avatars.end(), avatar);
	avatars.erase(it);
	delete avatar;
};


void Core::initAvatar(
			Avatar *avatar,
			tstring avatarId, 
			bool bailOnMissedJoints,
			const Vec &Position, 
			const Quat &Orientation)
{
	avatar->imp = createAvatarImp(avatarId, bailOnMissedJoints, Position, Orientation);
	if(avatar->imp)
		{
		//avatar->setCore(this);
		avatars.push_back(avatar);
		}
};


Object *Core::getObject(tstring objectName)
{
	for (unsigned int i = 0; i < objects.size(); i++)
	{
		if(objects[i]->getName() == objectName)
		{
			return objects[i];
		}
	}
	std::cout << "looking for object " << objectName << std::endl;
	std::cout << "no object Found\n";
	return NULL;
};

Object *Core::getObject(int i)
{
	if(i >= 0 && i < numObjects())
		return objects[i];
	else
	{
		Piavca::Error("trying to get an object from an invalid index");
		return NULL;
	}
};

//! changes the name of an avatar
void Core::renameObject(tstring oldName, tstring newName)
{
	if(newName == oldName) return;

 	for (unsigned int i = 0; i < objects.size(); i++)
	{
		if(objects[i]->getName() == newName)
		{
			Piavca::Error(_T("Trying to rename object") + oldName + _T("to the name of an exisiting object: ") + newName);
		}
	}
 	for (unsigned int i = 0; i < objects.size(); i++)
	{
		if(objects[i]->getName() == oldName)
		{
			objects[i]->name = newName;
			return;
		}
	}
}

//! removes and avatar
void Core::removeObject(Object *object)
{
	std::vector<Object *>::iterator it = std::find(objects.begin(), objects.end(), object);
	objects.erase(it);
	delete object;
};


void Core::initObject(
			Object *object,
			tstring objectId, 
			const Vec &Position, 
			const Quat &Orientation)
{
	object->imp = createObjectImp(objectId, Position, Orientation);
	if(object->imp)
	{
		objects.push_back(object);
	}
};

void Core::initMotion(KeyframeMotion *mot, tstring filename, bool facial, int flags, Motion *basePosture)
{
	//if(mot->imp) delete mot->imp;
	mot->imp = createMotionImp(filename, facial, flags, basePosture);
	//if(mot->imp) mot->imp->frontEnd = mot;
	//mot->setCore(this);
};

void Core::addError(tstring details)
{
	errorstrm << details << std::endl;
};
void Core::clearErrors()
{
	errorstrm.str(_T(""));
};
		

void Core::addWarning(tstring details)
{
	warningstrm << details << std::endl;
};
		
void Core::clearWarnings()
{
	warningstrm.str(_T(""));
};

void Core::printProfileData()
{
	for (int i = 0; i < (int) m_profilePoints.size(); i++)
	{
		std::cout <<  TStringToString(m_profilePoints[i].m_name) << ": " << m_profilePoints[i].m_accumulated_time << std::endl;
		m_profilePoints[i].m_accumulated_time = 0.0f;
	}
}

void Core::output(tstring str)
{
	std::cout << str;	
}

	