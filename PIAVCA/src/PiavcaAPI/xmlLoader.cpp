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
 * The Original Code is xmlLoader.cpp.
 *
 * The Initial Developer of the Original Code is Marco (Mark) Gillies.
 * Portions created by the Initial Developer are Copyright (C) Mark Gillies. 2009
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

#include "xmlLoader.h"
#include "PiavcaAPI/PiavcaCore.h"
#include "PiavcaAPI/PiavcaError.h"
#include "PiavcaAPI/Motion.h"
#include "PiavcaAPI/Avatar.h"
#include "cal3d/tinyxml.h"
#include <vector>

using namespace Piavca;
using namespace cal3d;


struct motspec
{
	Motion *mot;
	TiXmlElement *element;
	std::vector < std::pair<tstring, tstring> > params;
};


std::vector<motspec> readMotions(TiXmlElement *parent);

tstring getName(TiXmlElement *element)
{
	if(element->Attribute("Name")!=NULL)
	{
		return StringToTString(std::string(element->Attribute("Name")));
	}
	
	if(element->Attribute("name")!=NULL)
	{
		return StringToTString(std::string(element->Attribute("name")));
	}
	return _T("");
}

motspec readMotion(TiXmlElement *element)
{
	std::string motType = std::string(element->Value() );
	motspec spec;
	spec.mot = NULL;
	spec.element = element;
	if(motType == "Avatar" || motType == "avatar")
	{
		tstring avatarname = getName(element);
		if(avatarname == _T(""))
			Piavca::Error("Avatar without name");
		
		Piavca::Avatar *av = new Piavca::Avatar(avatarname);
		return spec;
	}
	if(motType == "Motion" || motType == "motion")
	{
		tstring motionname = getName(element);
		if(motionname == _T(""))
			Piavca::Error("Motion without name");
		
		spec.mot = Piavca::Core::getCore()->getMotion(motionname);
		return spec;
	}
	
	spec.mot = Piavca::Core::getCore()->createMotion(StringToTString(motType));
	for(TiXmlAttribute *attr = element->FirstAttribute(); attr; attr = attr->Next())
	{
		bool added = spec.mot->setParameter(StringToTString(attr->Name()), StringToTString(attr->Value()));
		if(!added)
		{
			spec.params.push_back(std::make_pair(StringToTString(attr->Name()), StringToTString(attr->Value())));
		}
	}
	
	tstring motionname = spec.mot->getName();
	if(motionname != _T(""))
	{
		Piavca::Core::getCore()->loadMotion(motionname, spec.mot);
	}
	
	return spec;
}

std::vector<motspec> readMotions(TiXmlElement *parent)
{
	std::vector<motspec>  mots;
	for(TiXmlElement* element = parent->FirstChildElement();element;element = element->NextSiblingElement() )
	{
		motspec mot = readMotion(element);
		if (mot.mot)
		{
			std::cout << "loaded Motion " << mot.mot->getName() << std::endl;
			mots.push_back(mot);
		}
	}
	for (int i =0; i < mots.size(); i++)
	{
		std::cout << "loading childredn for motion "  << mots[i].mot->getName() << std::endl;
		std::vector<motspec> childmots = readMotions(mots[i].element);
		for (int j = 0; j < childmots.size(); j++)
		{
			mots[i].mot->addMotion(childmots[j].mot, childmots[j].params);
		}
		mots[i].mot->create();
	}
	return mots;
}

void Piavca::loadFile(Piavca::tstring filename)
{
	TiXmlDocument doc(TStringToString(filename));
	if(!doc.LoadFile())
	{
		Piavca::Error(_T("Could not open file ")+filename);
					  return;
	}
					  
	TiXmlNode* node;
	TiXmlElement*main = doc.FirstChildElement();
	if(!main)
	{
		  Piavca::Error(_T("Invalid format") + filename);
	}
	for( main = doc.FirstChildElement();main;main = main->NextSiblingElement() )
	{
		if(std::string(main->Value()) == "PiavcaMotions")
		   readMotions(main);
	}
	
	doc.Clear();
}

