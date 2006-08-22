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
 * The Original Code is MotionParser.cpp.
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

#include "MotionParser.h"
#include "Piavca.h"

#include "PiavcaAPI/TrackMotion.h"

#include <string>
using std::string;

namespace Piavca 
{
template <class T> 
class MotionParserTyped : public MotionParser 
{
	void editMotionInternal(T *mot, istringstream &is);
public:
	MotionParserTyped(){};
	
	virtual Piavca::Motion *parseMotion(istringstream &is, std::string currentWord, float scaleFactor); 
	virtual Piavca::Motion *editMotion(istringstream &is)
	{
		string motName;
		is >> motName;
		Motion *mot = Piavca::Core::getCore()->getMotion(motName);
		if(mot) mot = mot->clone();
		T *m = dynamic_cast<T *>(mot);
		if(m)
		{
			editMotionInternal(m, is);
			return m;
		}
		else
		{
			Piavca::Error(_T("Motion: ") + StringToTString(motName) 
				+ _T(" is not of type ") + StringToTString(typeid(T).name()));
			return NULL;
		}
	}
	virtual void editAvatarMotion(Avatar *av, bool facial, istringstream &is)
	{
		Motion *mot;
		T *m;
		string motName;
		is >> motName;
		if(facial)
			mot = av->getFacialMotion();
		else
			mot = av->getMotion();
		if(mot)
		{
			m = dynamic_cast<T *>(mot->findSub(motName));
			if(!m) m = dynamic_cast<T *>(mot->findSubByType(typeid(T)));
		}
		if(m)
		{
			editMotionInternal(m, is);
		}
		else
		{
			Piavca::Error(_T("Avatar: ") + av->getName() 
				+ _T(" is not playing a motion of called, or of type ")
				+ StringToTString(motName));
		}	
	};
};

};

using namespace Piavca;


template<> 
Piavca::Motion *MotionParserTyped<ZeroMotion>::parseMotion(istringstream &is, std::string currentWord, float scaleFactor)
{
		bool facial = false;
		//if(currentWord == "")
		//	if(!(is >> currentWord)) currentWord = "";
				
		//if(currentWord == "-facial")
		//{
		//	facial = true;
		//	currentWord = "";
		//}
		return new ZeroMotion(facial);
};

template<>
void MotionParserTyped<ZeroMotion>::editMotionInternal(ZeroMotion *mot, istringstream &is)
{
		
};



template<> 
Piavca::Motion *MotionParserTyped<LoopMotion>::parseMotion(istringstream &is, std::string currentWord, float scaleFactor)
{
		float endTime = -1.0f;
		float interval = 0.01f;
		bool accumulateRoot = true;
		if(currentWord == "")
			if(!(is >> currentWord)) currentWord = "";
				
		while (currentWord != "")
		{
			if(currentWord == "endTime")
			{
				if(!(is >> endTime))
				{
					Piavca::Error(_T("no value given for end time\n"));
					return NULL;
				}
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "interval")
			{
				if(!(is >> interval))
				{
					Piavca::Error(_T("no value given for end time\n"));
					return NULL;
				}
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "forget_root_transform")
			{
				accumulateRoot = false;
				if(!(is >> currentWord)) break;
			}
			else
				break;

		}
		MotionParser *mp = NULL;
		Motion *mot = MotionParser::parseMotion(is, currentWord, scaleFactor, &mp);
		if(Piavca::Core::getCore()->errorsPresent()) return NULL;
		LoopMotion *loop = new LoopMotion(mot, endTime, interval);
		loop->setAccumulateRoot(accumulateRoot);;
};

template<>
void MotionParserTyped<LoopMotion>::editMotionInternal(LoopMotion *mot, istringstream &is)
{
		float endTime = -1.0f;
		float interval = 0.01f;
		string currentWord;
		while(is >> currentWord)
		{
			if(currentWord == "endTime")
			{
				if(!(is >> endTime))
				{
					Piavca::Error(_T("no value given for end time"));
					return;
				}
				mot->setEndTime(endTime);
			}
			if(currentWord == "interval")
			{
				if(!(is >> interval))
				{
					Piavca::Error(_T("no value given for interval"));
					return;
				}
				mot->setBlendInterval(interval);
			}
			else if(currentWord == "forget_root_transform")
			{
				mot->setAccumulateRoot(false);
				if(!(is >> currentWord)) break;
			}
			Piavca::Error(_T("unknown option ") + StringToTString(currentWord));
			return;
		}
};

template<>  Piavca::Motion *MotionParserTyped<ScaleMotionRoot>::parseMotion(istringstream &is, std::string currentWord, float scaleFactor)
{
		if(!(is >> scaleFactor))
		{
			Piavca::Error(_T("scale factor is not a number"));
			return NULL;
		}
		currentWord= "";
		MotionParser *mp = NULL;
		return MotionParser::parseMotion(is, currentWord, scaleFactor, &mp);
};


template<> void MotionParserTyped<ScaleMotionRoot>::editMotionInternal(ScaleMotionRoot *mot, istringstream &is)
{
		float scaleFactor;
		if(!(is >> scaleFactor))
		{
			Piavca::Error(_T("scale factor is not a number"));
		}
		else
			mot->setScaleFactor(scaleFactor);
};

template<> Piavca::Motion *MotionParserTyped<ScaleMotion>::parseMotion(istringstream &is, std::string currentWord, float scaleFactor)
{
		float sf;
		if(!(is >> sf))
		{
			Piavca::Error("scale factor is not a number");
			return NULL;
		}
		currentWord = "";
		MotionParser *mp = NULL;
		Motion *mot = MotionParser::parseMotion(is, currentWord, scaleFactor, &mp);
		if(Piavca::Core::getCore()->errorsPresent()) return NULL;
		return new ScaleMotion(mot, sf);
};

template<> void MotionParserTyped<ScaleMotion>::editMotionInternal(ScaleMotion *mot, istringstream &is)
{
		float sf;
		if(!(is >> sf))
		{
			Piavca::Error(_T("scale factor is not a number"));
		}
		else
			mot->setScaleFactor(sf);
};

template<> Piavca::Motion *MotionParserTyped<ScaleMotionSpeed>::parseMotion(istringstream &is, std::string currentWord, float scaleFactor)
{
		float sf;
		if(!(is >> sf))
		{
			Piavca::Error(_T("scale factor is not a number"));
			return NULL;
		}
		currentWord = "";
		MotionParser *mp = NULL;
		Motion *mot = MotionParser::parseMotion(is, currentWord, scaleFactor, &mp);
		if(Piavca::Core::getCore()->errorsPresent()) return NULL;
		return new ScaleMotionSpeed(mot, sf);
};

template<> void MotionParserTyped<ScaleMotionSpeed>::editMotionInternal(ScaleMotionSpeed *mot, istringstream &is)
{
		float sf;
		if(!(is >> sf))
		{
			Piavca::Error(_T("scale factor is not a number"));
		}
		else
			mot->setScaleFactor(sf);
};

template<> Piavca::Motion *MotionParserTyped<ChangeMotionProp>::parseMotion(istringstream &is, std::string currentWord, float scaleFactor)
{
		float sf = 1.0f;
		float swin = 0.2f;
		float ewin = 0.2f;
		float scale = 1.0f;
		
		if(currentWord == "")
			if(!(is >> currentWord)) currentWord = "";

		while (currentWord != "")
		{
			if(currentWord == "mult")
			{
				if(!(is >> sf))
				{
					Piavca::Error(_T("no value given for mult"));
					return NULL;
				}
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "scale")
			{
				if(!(is >> sf))
				{
					Piavca::Error(_T("no value given for scale"));
					return NULL;
				}
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "swin")
			{
				if(!(is >> sf))
				{
					Piavca::Error(_T("no value given for start window"));
					return NULL;
				}
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "ewin")
			{
				if(!(is >> sf))
				{
					Piavca::Error(_T("no value given for end window"));
					return NULL;
				}
				if(!(is >> currentWord)) break;
			}
		}
		MotionParser *mp = NULL;
		Motion *mot = MotionParser::parseMotion(is, currentWord, scaleFactor, &mp);
		if(Piavca::Core::getCore()->errorsPresent()) return NULL;
		return new ChangeMotionProp(mot, sf, scale, swin, ewin);
};

template<> void MotionParserTyped<ChangeMotionProp>::editMotionInternal(ChangeMotionProp *mot, istringstream &is)
{
		float sf = 1.0f;
		float swin = 0.2f;
		float ewin = 0.2f;
		float scale = 1.0f;

		string currentWord = "";
		while (is >> currentWord)
		{
			if(currentWord == "mult")
			{
				if(!(is >> sf))
				{
					Piavca::Error(_T("no value given for mult"));
					return;
				}
				mot->setScaleFactor(sf);
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "scale")
			{
				if(!(is >> sf))
				{
					Piavca::Error(_T("no value given for scale"));
					return;
				}
				mot->setMidScaleFactor(sf);
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "swin")
			{
				if(!(is >> sf))
				{
					Piavca::Error(_T("no value given for start window"));
					return;
				}
				mot->setStartWindow(swin);
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "ewin")
			{
				if(!(is >> sf))
				{
					Piavca::Error(_T("no value given for end window"));
					return;
				}
				mot->setEndWindow(ewin);
				if(!(is >> currentWord)) break;
			}
			else
			{
				Piavca::Error(_T("unknown option ") + StringToTString(currentWord));
				return;
			}
		}
};



template<> Piavca::Motion *MotionParserTyped<ChangeMotionLength>::parseMotion(istringstream &is, std::string currentWord, float scaleFactor)
{
		float len;
		if(!(is >> len))
		{
			Piavca::Error(_T("length is not a number"));
			return NULL;
		}
		currentWord = "";
		MotionParser *mp = NULL;
		Motion *mot = MotionParser::parseMotion(is, currentWord, scaleFactor, &mp);
		if(Piavca::Core::getCore()->errorsPresent()) return NULL;
		return new ChangeMotionLength(mot, len);
};


template<> void MotionParserTyped<ChangeMotionLength>::editMotionInternal(ChangeMotionLength *mot, istringstream &is)
{
		float len;
		if(!(is >> len))
		{
			Piavca::Error(_T("length is not a number"));
		}
		else
			mot->setMotionLength(len);
};


template<> Piavca::Motion *MotionParserTyped<TurnMotion>::parseMotion(istringstream &is, std::string currentWord, float scaleFactor)
{
		float angle;
		if(!(is >> angle))
		{
			Piavca::Error(_T("angle is not a number"));
			return NULL;
		}
		currentWord = "";
		MotionParser *mp = NULL;
		Motion *mot = MotionParser::parseMotion(is, currentWord, scaleFactor, &mp);
		if(Piavca::Core::getCore()->errorsPresent()) return NULL;
		Quat q(Piavca::degToRad(angle), Vec(0.0, 1.0, 0.0));
		return new TurnMotion(mot, q);
};

template<> void MotionParserTyped<TurnMotion>::editMotionInternal(TurnMotion *mot, istringstream &is)
{
		float angle;
		if(!(is >> angle))
		{
			Piavca::Error(_T("angle is not a number"));
		}
		else
			mot->setRotation(Quat(degToRad(angle), Vec::YAxis()));
};


template<> Piavca::Motion *MotionParserTyped<BlendBetween>::parseMotion(istringstream &is, std::string currentWord, float scaleFactor)
{
		float blendFactor;
		if(!(is >> blendFactor))
		{
			Piavca::Error(_T("blend factor is not a number"));
			return NULL;
		}
		else
		{
			currentWord = "";
			MotionParser *mp = NULL;
			Piavca::Motion *m1 = MotionParser::parseMotion(is, currentWord, scaleFactor, &mp);
			if(Piavca::Core::getCore()->errorsPresent()) return NULL;
			Piavca::Motion *m2 = MotionParser::parseMotion(is, currentWord, scaleFactor, &mp);
			if(Piavca::Core::getCore()->errorsPresent()) return NULL;
			return new BlendBetween(m1, m2, static_cast<float>(blendFactor));
		}
};


template<> void MotionParserTyped<BlendBetween>::editMotionInternal(BlendBetween *mot, istringstream &is)
{
	string currentWord;
	while(is >> currentWord)
	{
		if(currentWord == "factor")
		{
			float blendFactor;
			if(!(is >> blendFactor))
			{
				Piavca::Error(_T("blend factor was not a number"));
				return;
			}
			mot->setBlendFactor(blendFactor);
			if(!(is >> currentWord)) break;
			continue;
		}
		if(currentWord == "mot1")
		{
			float scaleFactor = 1.0f;
			MotionParser *mp = NULL;
			Piavca::Motion *m1 = MotionParser::parseMotion(is, "", scaleFactor, &mp);
			if(Piavca::Core::getCore()->errorsPresent()) return;
			mot->setMotion1(m1);
			continue;
		}
		if(currentWord == "mot2")
		{
			float scaleFactor = 1.0f;
			MotionParser *mp = NULL;
			Piavca::Motion *m2 = MotionParser::parseMotion(is, "", scaleFactor, &mp);
			if(Piavca::Core::getCore()->errorsPresent()) return;
			mot->setMotion2(m2);
			continue;
		}
		Piavca::Error(_T("unknown option ") + StringToTString(currentWord));
		return;
	}
};


template<> Piavca::Motion *MotionParserTyped<MotionAdder>::parseMotion(istringstream &is, std::string currentWord, float scaleFactor)
{
	MotionParser *mp = NULL;
	Piavca::Motion *m1 = MotionParser::parseMotion(is, currentWord, scaleFactor, &mp);
	if(Piavca::Core::getCore()->errorsPresent()) return NULL;
	Piavca::Motion *m2 = MotionParser::parseMotion(is, currentWord, scaleFactor, &mp);
	if(Piavca::Core::getCore()->errorsPresent()) return NULL;
	return new MotionAdder(m1, m2);
};

template<> void MotionParserTyped<MotionAdder>::editMotionInternal(MotionAdder *mot, istringstream &is)
{
	string currentWord;
	while(is >> currentWord)
	{
		if(currentWord == "scale_second")
		{
			float scaleFactor;
			if(!(is >> scaleFactor))
			{
				Piavca::Error(_T("scale factor was not a number"));
				return;
			}
			mot->setScaleSecond(scaleFactor);
			if(!(is >> currentWord)) break;
			continue;
		}
		if(currentWord == "mot1")
		{
			float scaleFactor = 1.0;
			MotionParser *mp = NULL;
			Piavca::Motion *m1 = MotionParser::parseMotion(is, "", scaleFactor, &mp);
			if(Piavca::Core::getCore()->errorsPresent()) return;
			mot->setMotion1(m1);
			continue;
		}
		if(currentWord == "mot2")
		{
			float scaleFactor = 1.0;
			MotionParser *mp = NULL;
			Piavca::Motion *m2 = MotionParser::parseMotion(is, "", scaleFactor, &mp);
			if(Piavca::Core::getCore()->errorsPresent()) return;
			mot->setMotion2(m2);
			continue;
		}
		Piavca::Error(_T("unknown option ") + StringToTString(currentWord));
		return;
	}
};


template<> Piavca::Motion *MotionParserTyped<MaskedMotion>::parseMotion(istringstream &is, std::string currentWord, float scaleFactor)
{
	    MotionMask mask1, mask2;
		bool useSecondary = false;
		if(currentWord == "")
			if(!(is >> currentWord)) 
			{
				Piavca::Error(_T("no arguments given for mask motion"));
				return NULL;
			}
		
		if(currentWord == "use_secondary")
		{
			bool useSecondary = true;
			if(!(is >> currentWord)) 
			{
				Piavca::Error(_T("not enough arguments given for mask motion"));
				return NULL;
			}
		}
		while (currentWord != "")
		{
			int jointId = Piavca::Core::getCore()->getJointId(StringToTString(currentWord));
			if(Piavca::Core::getCore()->errorsPresent()) return NULL;
			if(jointId >=0)
				mask1.setMask(jointId);
			else
				break;
			if(!(is >> currentWord))
			{
				Piavca::Error(_T("No motions given for Masked motion"));
			}	
		}
		MotionParser *mp = NULL;
		Piavca::Motion *mot1 = MotionParser::parseMotion(is, currentWord, scaleFactor, &mp);
		if(Piavca::Core::getCore()->errorsPresent()) return NULL;
		while (currentWord != "")
		{
			int jointId = Piavca::Core::getCore()->getJointId(StringToTString(currentWord));
			if(Piavca::Core::getCore()->errorsPresent()) return NULL;
			if(jointId >=0)
				mask2.setMask(jointId);
			else
				break;
			if(!(is >> currentWord))
			{
				Piavca::Error(_T("No motions given for Masked motion"));
			}	
		}
		Piavca::Motion *mot2 = MotionParser::parseMotion(is, currentWord, scaleFactor, &mp);
		if(Piavca::Core::getCore()->errorsPresent()) return NULL;
		
		return new MaskedMotion(mot1, mask1, mot2, mask2, useSecondary);
};

template<> void MotionParserTyped<MaskedMotion>::editMotionInternal(MaskedMotion *mot, istringstream &is)
{
	string currentWord;
	if(!(is >> currentWord))currentWord = "";
	while(currentWord != "")
	{
		if(currentWord == "mask1")
		{
			MotionMask mask;
			while (is >> currentWord)
			{
				int jointId = Piavca::Core::getCore()->getJointId(StringToTString(currentWord));
				if(Piavca::Core::getCore()->errorsPresent()) return;
				if(jointId >=0)
					mask.setMask(jointId);
				else
					break;
			}
			mot->setMask1(mask);
			continue;
		}
		if(currentWord == "mask2")
		{
			MotionMask mask;
			while (is >> currentWord)
			{
				int jointId = Piavca::Core::getCore()->getJointId(StringToTString(currentWord));
				if(Piavca::Core::getCore()->errorsPresent()) return;
				if(jointId >=0)
					mask.setMask(jointId);
				else
					break;
			}
			mot->setMask2(mask);
			continue;
		}
		if(currentWord == "mot1")
		{
			float scaleFactor = 1.0;
			MotionParser *mp = NULL;
			Piavca::Motion *m1 = MotionParser::parseMotion(is, "", scaleFactor, &mp);
			if(Piavca::Core::getCore()->errorsPresent()) return;
			mot->setMotion1(m1);
			continue;
		}
		if(currentWord == "mot2")
		{
			float scaleFactor = 1.0;
			MotionParser *mp = NULL;
			Piavca::Motion *m2 = MotionParser::parseMotion(is, "", scaleFactor, &mp);
			if(Piavca::Core::getCore()->errorsPresent()) return;
			mot->setMotion2(m2);
			continue;
		}
		Piavca::Error(_T("unknown option ") + StringToTString(currentWord));
		return;
	}
};

template<> Piavca::Motion *MotionParserTyped<LookAtMotion>::parseMotion(istringstream &is, std::string currentWord, float scaleFactor)
{
	    float endTime = -1.0;

		if(currentWord == "")
			if(!(is >> currentWord))
			{
				Piavca::Error(_T("no target given for look at motion"));
				return NULL;
			}
		
		if(currentWord == "endTime")
		{
			if(!(is >> endTime))
			{
				Piavca::Error(_T("no value given for end time"));
				return NULL;
			}
			if(!(is >> currentWord))
			{
				Piavca::Error(_T("no target given for look at motion"));
				return NULL;
			}
		}
		Piavca::Avatar *av = Piavca::Core::getCore()->getAvatar(currentWord);
		if(av)
		{
			if(!(is >> currentWord))
			{
				Piavca::Error(_T("no joint given for avatar target of look at motion"));
				return NULL;
			} 
			int jointId = -1;
			jointId = Piavca::Core::getCore()->getJointId(currentWord);
			if(jointId < -1)
			{
				Piavca::Error(_T("unknown joint ") +  StringToTString(currentWord));
				return NULL;
			}
			LookAtMotion *lookat = new LookAtMotion(av, jointId, endTime); 
			return lookat;
		}
		Piavca::Object *obj = Piavca::Core::getCore()->getObject(currentWord);
		if(obj)
		{
			LookAtMotion *lookat = new LookAtMotion(obj, endTime); 
			return lookat;
		}
		if(currentWord == "location")
		{
			Vec location; 
			if(!(is >> location))
			{
				Piavca::Error(_T("Expecting a vector for location target"));
				return NULL;
			};
			LookAtMotion *lookat = new LookAtMotion(location, endTime); 
			return lookat;
		}
		Piavca::Error(_T("No target given for look at motion"));
		return NULL;
};


template<> void MotionParserTyped<LookAtMotion>::editMotionInternal(LookAtMotion *mot, istringstream &is)
{
	string currentWord;
	while(is >> currentWord)
	{
		if(currentWord == "endTime")
		{
			float endTime;
			if(!(is >> endTime))
			{
				Piavca::Error(_T("end time was not a number"));
				return;
			}
			mot->setEndTime(endTime);
			if(!(is >> currentWord)) break;
			continue;
		}
		Piavca::Avatar *av = Piavca::Core::getCore()->getAvatar(currentWord);
		if(av)
		{
			if(!(is >> currentWord))
			{
				Piavca::Error(_T("no joint given for avatar target of look at motion"));
				return;
			} 
			int jointId = -1;
			jointId = Piavca::Core::getCore()->getJointId(currentWord);
			if(jointId < -1)
			{
				Piavca::Error(_T("unknown joint ") +  StringToTString(currentWord));
				return;
			}
			mot->setTarget(av, jointId);
			continue;
		}
		Piavca::Object *obj = Piavca::Core::getCore()->getObject(currentWord);
		if(obj)
		{
			mot->setTarget(obj);
			continue;
		}
		if(currentWord == "location")
		{
			Vec location; 
			if(!(is >> location))
			{
				Piavca::Error(_T("was expecting a vector for location target"));
				return;
			};
			mot->setTarget(location);
			continue;
		}
		Piavca::Error(_T("unknown option") + StringToTString(currentWord));
	}
};

template<> Piavca::Motion *MotionParserTyped<RandomGazeMotion>::parseMotion(istringstream &is, std::string currentWord, float scaleFactor)
{
	    float endTime = -1.0f;
		float interval = 0.01f;
		
		if(currentWord == "")
			if(!(is >> currentWord)) currentWord = "";
				
		while (currentWord != "")
		{
			if(currentWord == "endTime")
			{
				if(!(is >> endTime))
				{
					Piavca::Error(_T("no value given for end time\n"));
					return NULL;
				}
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "interval")
			{
				if(!(is >> interval))
				{
					Piavca::Error(_T("no value given for end time\n"));
					return NULL;
				}
				if(!(is >> currentWord)) break;
			}
			else
				break;

		}

		RandomGazeMotion *random_gaze = new RandomGazeMotion(endTime, interval);
		
		while (currentWord != "")
		{
			if(currentWord == "end")
			{
				currentWord = "";
				break;
			}
			Piavca::Avatar *av = Piavca::Core::getCore()->getAvatar(currentWord);
			if(av)
			{
				if(!(is >> currentWord))
				{
					Piavca::Error(_T("no joint given for avatar target of look at motion"));
					return NULL;
				} 
				int jointId = -1;
				jointId = Piavca::Core::getCore()->getJointId(currentWord);
				if(jointId < -1)
				{
					Piavca::Error(_T("unknown joint ") +  StringToTString(currentWord));
					return NULL;
				}
				random_gaze->addAvatarTarget(av, jointId);
				continue;
			}
			Piavca::Object *obj = Piavca::Core::getCore()->getObject(currentWord);
			if(obj)
			{
				random_gaze->addObjectTarget(obj);
				continue;
			}
			break;
		};
		return random_gaze;
};

template<> void MotionParserTyped<RandomGazeMotion>::editMotionInternal(RandomGazeMotion *mot, istringstream &is)
{
	    float endTime = -1.0f;
		float interval = 0.01f;
		string currentWord;
				
		while (is >> currentWord)
		{
			if(currentWord == "endTime")
			{
				if(!(is >> endTime))
				{
					Piavca::Error(_T("no value given for end time\n"));
					return;
				}
				mot->setEndTime(endTime);
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "interval")
			{
				if(!(is >> interval))
				{
					Piavca::Error(_T("no value given for end time\n"));
					return;
				}
				mot->setBlendInterval(interval);
				if(!(is >> currentWord)) break;
			}
			else
				break;

		}
		while (currentWord != "")
		{
			if(currentWord == "end")
			{
				currentWord = "";
				break;
			}
			Piavca::Avatar *av = Piavca::Core::getCore()->getAvatar(currentWord);
			if(av)
			{
				if(!(is >> currentWord))
				{
					Piavca::Error(_T("no joint given for avatar target of look at motion"));
					return;
				} 
				int jointId = -1;
				jointId = Piavca::Core::getCore()->getJointId(currentWord);
				if(jointId < -1)
				{
					Piavca::Error(_T("unknown joint ") +  StringToTString(currentWord));
					return;
				}
				mot->addAvatarTarget(av, jointId);
				continue;
			}
			Piavca::Object *obj = Piavca::Core::getCore()->getObject(currentWord);
			if(obj)
			{
				mot->addObjectTarget(obj);
				continue;
			}
			break;
		};
};

template<> Piavca::Motion *MotionParserTyped<DiadicGazeMotion>::parseMotion(istringstream &is, std::string currentWord, float scaleFactor)
{
	float endTime = -1.0f;
	float interval = 0.01f;
	Avatar *av = NULL;	
	if(currentWord == "")
			if(!(is >> currentWord)) currentWord = "";
				
	while (currentWord != "")
	{
		if(currentWord == "endTime")
		{
			if(!(is >> endTime))
			{
				Piavca::Error(_T("no value given for end time\n"));
				return NULL;
			}
			if(!(is >> currentWord)) break;
		}
		else if(currentWord == "interval")
		{
			if(!(is >> interval))
			{
				Piavca::Error(_T("no value given for end time\n"));
				return NULL;
			}
			if(!(is >> currentWord)) break;
		}
		else if(currentWord == "set_avatar")
		{
			Piavca::Avatar *av = Piavca::Core::getCore()->getAvatar(currentWord);
			if(!av)
			{
				Piavca::Error(_T("unknown avatar ") + StringToTString(currentWord));
				return NULL;
			}
			if(!(is >> currentWord)) break;
		}
		else
			break;
	} 
	return new DiadicGazeMotion(av, endTime, interval);
};

template<> void MotionParserTyped<DiadicGazeMotion>::editMotionInternal(DiadicGazeMotion *mot, istringstream &is)
{
	string currentWord;
	while (is >> currentWord)
	{
		if(currentWord == "endTime")
		{
			float endTime;
			if(!(is >> endTime))
			{
				Piavca::Error(_T("no value given for end time\n"));
				return;
			}
			mot->setEndTime(endTime);
			if(!(is >> currentWord)) break;
		}
		else if(currentWord == "interval")
		{
			float interval;
			if(!(is >> interval))
			{
				Piavca::Error(_T("no value given for end time\n"));
				return;
			}
			mot->setBlendInterval(interval);
			if(!(is >> currentWord)) break;
		}
		else if(currentWord == "set_avatar")
		{
			Piavca::Avatar *av = Piavca::Core::getCore()->getAvatar(currentWord);
			if(!av)
			{
				Piavca::Error(_T("unknown avatar ") + StringToTString(currentWord));
				return;
			}
			if(!(is >> currentWord)) break;
		}
		else if(currentWord == "set_talk_state")
		{
			if(!(is >> currentWord))
			{
				Piavca::Error(_T("no argument given for talk state"));
				return;
			}
			if(currentWord == "talking") mot->setTalking(Piavca::DiadicGazeMotion::talking);
			else { if(currentWord == "listening") mot->setTalking(Piavca::DiadicGazeMotion::listening);
			else { if(currentWord == "neither") mot->setTalking(Piavca::DiadicGazeMotion::neither);
			else 
			{
				Piavca::Error(_T("unknown talk state: ") + StringToTString(currentWord));
				return;
			}}};
			if(!(is >> currentWord)) break;
		}
		else if(currentWord == "talking_look_at")
		{
			float val = 0.1f;
			if(!(is >> val))
			{
				Piavca::Error(_T("no value given for talking_look_at\n"));
				return;
			}
			mot->setTalkingLookAt(val);
			if(!(is >> currentWord)) break;
		}
		else if(currentWord == "talking_look_away")
		{
			float val = 0.1f;
			if(!(is >> val))
			{
				Piavca::Error(_T("no value given for talking_look_away\n"));
				return;
			}
			mot->setTalkingLookAway(val);
			if(!(is >> currentWord)) break;
		}
		else if(currentWord == "listening_look_at")
		{
			float val = 0.1f;
			if(!(is >> val))
			{
				Piavca::Error(_T("no value given for listening_look_at\n"));
				return;
			}
			mot->setListeningLookAt(val);
			if(!(is >> currentWord)) break;
		}
		else if(currentWord == "listening_look_away")
		{
			float val = 0.1f;
			if(!(is >> val))
			{
				Piavca::Error(_T("no value given for listening_look_away\n"));
				return;
			}
			mot->setListeningLookAway(val);
			if(!(is >> currentWord)) break;
		}
		else if(currentWord == "neither_look_at")
		{
			float val = 0.1f;
			if(!(is >> val))
			{
				Piavca::Error(_T("no value given for neither_look_at\n"));
				return;
			}
			mot->setNeitherLookAt(val);
			if(!(is >> currentWord)) break;
		}
		else if(currentWord == "neither_look_away")
		{
			float val = 0.1f;
			if(!(is >> val))
			{
				Piavca::Error(_T("no value given for neither_look_away\n"));
				return;
			}
			mot->setNeitherLookAway(val);
			if(!(is >> currentWord)) break;
		}
		else if(currentWord == "gaze_follow")
		{
			float val = 0.1f;
			if(!(is >> val))
			{
				Piavca::Error(_T("no value given for gaze_follow\n"));
				return;
			}
			mot->setGazeFollow(val);
			if(!(is >> currentWord)) break;
		}
		else if(currentWord == "eyes_limit")
		{
			float val = 0.1f;
			if(!(is >> val))
			{
				Piavca::Error(_T("no value given for eyes_limit\n"));
				return;
			}
			mot->setEyesLimit(val);
			if(!(is >> currentWord)) break;
		}
		else if(currentWord == "eyes_morph_angle")
		{
			float val = 0.1f;
			if(!(is >> val))
			{
				Piavca::Error(_T("no value given for eyes_morph_angle\n"));
				return;
			}
			mot->setEyesMorphAngle(val);
			if(!(is >> currentWord)) break;
		}
		else if(currentWord == "head_body_limit")
		{
			float val = 0.1f;
			if(!(is >> val))
			{
				Piavca::Error(_T("no value given for head_body_limit\n"));
				return;
			}
			mot->setHeadBodyLimit(val);
			if(!(is >> currentWord)) break;
		}
		else if(currentWord == "gaze_follow_target")
		{
			if(!(is >> currentWord))
			{
				Piavca::Error(_T("No gaze follow target given"));
				return;
			}
			mot->addGazeFollowTarget(currentWord);
			if(!(is >> currentWord)) break;
		}
		else if(currentWord == "look_at")
		{
			if(!(is >> currentWord))
			{
				Piavca::Error(_T("No look at target given"));
				return;
			}
			mot->lookAt(currentWord);
			if(!(is >> currentWord)) break;
		}
		else
			break;

	}    
};

template<> Piavca::Motion *MotionParserTyped<RandomLoopMotion>::parseMotion(istringstream &is, std::string currentWord, float scaleFactor)
{
	    MotionVec mv;
		vector<float> fv;
		float endTime = -1.0f;
		float interval = 0.01f;
		bool accumulateRoot = true;
		bool randomTimings = false;
		float min = 0.0, max = 1.0;
		if(currentWord == "")
			if(!(is >> currentWord)) currentWord = "";
				
		while (currentWord != "")
		{
			if(currentWord == "endTime")
			{
				if(!(is >> endTime))
				{
					Piavca::Error(_T("no value given for end time\n"));
					return NULL;
				}
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "interval")
			{
				if(!(is >> interval))
				{
					Piavca::Error(_T("no value given for end time\n"));
					return NULL;
				}
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "forget_root_transform")
			{
				accumulateRoot = false;
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "random_timings")
			{
				randomTimings = true;
				if(!(is >> min))
				{
					Piavca::Error(_T("no value given for end time\n"));
					return NULL;
				}
				if(!(is >> max))
				{
					Piavca::Error(_T("no value given for end time\n"));
					return NULL;
				}
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "end")
			{
				currentWord = "";
				break;
			}
			else
			{
				float prob = 1;
				if(currentWord == string("prob"))
				{
					if(!(is >> min))
					{
						Piavca::Error(_T("no value given for probablility\n"));
						return NULL;
					}
					if(!(is >> currentWord))
					{
						Piavca::Error(_T("expected a motion as an argument to Ramdom loop motion"));
						return NULL;
					}
				}
				MotionParser *mp = NULL;
				Motion *mot = MotionParser::parseMotion(is, currentWord, scaleFactor, &mp);
				if(Piavca::Core::getCore()->errorsPresent()) return NULL;
				if(mot == NULL) 
				{
					return NULL;
				}
				mv.push_back(mot);
				fv.push_back((float) prob);
				if(!(is >> currentWord)) break;

			}

		}
		
		Motion *m = new RandomLoopMotion(mv, fv, endTime, interval);
		dynamic_cast<RandomLoopMotion *>(m)->setAccumulateRoot(accumulateRoot);
		if(randomTimings)
			dynamic_cast<RandomLoopMotion *>(m)->setTimingParams(min, max);
		return m;
};

template<> void MotionParserTyped<RandomLoopMotion >::editMotionInternal(RandomLoopMotion *mot, istringstream &is)
{
	    float endTime = -1.0f;
		float interval = 0.01f;
		float min = 1.0f, max = 1.0f;
		string currentWord;
				
		while (is >> currentWord)
		{
			if(currentWord == "endTime")
			{
				if(!(is >> endTime))
				{
					Piavca::Error(_T("no value given for end time\n"));
					return;
				}
				mot->setEndTime(endTime);
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "interval")
			{
				if(!(is >> interval))
				{
					Piavca::Error(_T("no value given for end time\n"));
					return;
				}
				mot->setBlendInterval(interval);
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "forget_root_transform")
			{
				mot->setAccumulateRoot(false);
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "random_timings")
			{
				bool randomTimings = true;
				if(!(is >> min))
				{
					Piavca::Error(_T("no value given for end time\n"));
					return;
				}
				if(!(is >> max))
				{
					Piavca::Error(_T("no value given for end time\n"));
					return;
				}
				mot->setTimingParams(min, max);
				if(!(is >> currentWord)) break;
			}
			else
			{				
				Piavca::Error(_T("unknown option") + StringToTString(currentWord));
				break;
			}

		}
};

template<> Piavca::Motion *MotionParserTyped<ChoiceLoopMotion>::parseMotion(istringstream &is, std::string currentWord, float scaleFactor)
{
	    MotionVec mv;
		float endTime = -1.0f;
		float interval = 0.01f;
		bool accumulateRoot = true;
		bool randomTimings = false;
		float min = 0.0, max = 1.0;
		if(currentWord == "")
			if(!(is >> currentWord)) currentWord = "";
				
		while (currentWord != "")
		{
			if(currentWord == "endTime")
			{
				if(!(is >> endTime))
				{
					Piavca::Error(_T("no value given for end time\n"));
					return NULL;
				}
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "interval")
			{
				if(!(is >> interval))
				{
					Piavca::Error(_T("no value given for end time\n"));
					return NULL;
				}
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "forget_root_transform")
			{
				accumulateRoot = false;
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "random_timings")
			{
				randomTimings = true;
				if(!(is >> min))
				{
					Piavca::Error(_T("no value given for end time\n"));
					return NULL;
				}
				if(!(is >> max))
				{
					Piavca::Error(_T("no value given for end time\n"));
					return NULL;
				}
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "end")
			{
				currentWord = "";
				break;
			}
			else
			{
				MotionParser *mp = NULL;
				Motion *mot = MotionParser::parseMotion(is, currentWord, scaleFactor, &mp);
				if(Piavca::Core::getCore()->errorsPresent()) return NULL;
				if(mot == NULL) 
				{
					return NULL;
				}
				mv.push_back(mot);
			}
		}
		Motion *m = new ChoiceLoopMotion(mv, endTime, interval);
		dynamic_cast<ChoiceLoopMotion *>(m)->setAccumulateRoot(accumulateRoot);
		if(randomTimings)
			dynamic_cast<ChoiceLoopMotion *>(m)->setTimingParams(min, max);
		return m;
};

template<> void MotionParserTyped<ChoiceLoopMotion>::editMotionInternal(ChoiceLoopMotion *mot, istringstream &is)
{
	    float endTime = -1.0f;
		float interval = 0.01f;
		float min = 1.0f, max = 1.0f;
		string currentWord;
				
		while (is >> currentWord)
		{
			if(currentWord == "endTime")
			{
				if(!(is >> endTime))
				{
					Piavca::Error(_T("no value given for end time\n"));
					return;
				}
				mot->setEndTime(endTime);
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "interval")
			{
				if(!(is >> interval))
				{
					Piavca::Error(_T("no value given for end time\n"));
					return;
				}
				mot->setBlendInterval(interval);
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "forget_root_transform")
			{
				mot->setAccumulateRoot(false);
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "random_timings")
			{
				bool randomTimings = true;
				if(!(is >> min))
				{
					Piavca::Error(_T("no value given for end time\n"));
					return;
				}
				if(!(is >> max))
				{
					Piavca::Error(_T("no value given for end time\n"));
					return;
				}
				mot->setTimingParams(min, max);
				if(!(is >> currentWord)) break;
			} 
			else  if(currentWord == "set_choice")
			{
				if(!(is >> currentWord))
				{
					Piavca::Error(_T("no value given for choice\n"));
					return;
				}
				mot->setCurrentChoice(currentWord);
				if(!(is >> currentWord)) break;
			} 
			else
			{				
				Piavca::Error(_T("unknown option") + StringToTString(currentWord));
				break;
			}

		}
};

template<> Piavca::Motion *MotionParserTyped<RandomBlendLoop>::parseMotion(istringstream &is, std::string currentWord, float scaleFactor)
{
	    MotionVec mv;
		float endTime = -1.0f;
		float interval = 0.01f;
		bool accumulateRoot = true;
		bool randomTimings = false;
		bool autoshift = true;
		float min = 0.0, max = 1.0;
		if(currentWord == "")
			if(!(is >> currentWord)) currentWord = "";
				
		while (currentWord != "")
		{
			if(currentWord == "endTime")
			{
				if(!(is >> endTime))
				{
					Piavca::Error(_T("no value given for end time\n"));
					return NULL;
				}
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "interval")
			{
				if(!(is >> interval))
				{
					Piavca::Error(_T("no value given for end time\n"));
					return NULL;
				}
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "forget_root_transform")
			{
				accumulateRoot = false;
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "random_timings")
			{
				randomTimings = true;
				if(!(is >> min))
				{
					Piavca::Error(_T("no value given for end time\n"));
					return NULL;
				}
				if(!(is >> max))
				{
					Piavca::Error(_T("no value given for end time\n"));
					return NULL;
				}
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "autoshift")
			{
				autoshift = true;
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "autoshift_off")
			{
				autoshift = false;
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "end")
			{
				currentWord = "";
				break;
			}
			else
			{
				MotionParser *mp = NULL;
				Motion *mot = MotionParser::parseMotion(is, currentWord, scaleFactor, &mp);
				if(Piavca::Core::getCore()->errorsPresent()) return NULL;
				if(mot == NULL) 
				{
					return NULL;
				}
				mv.push_back(mot);
				if(!(is >> currentWord)) break;
			}
		}
			
		Motion *m = new RandomBlendLoop(mv, endTime, interval);
		dynamic_cast<RandomBlendLoop *>(m)->setAccumulateRoot(accumulateRoot);
		if(randomTimings)
			dynamic_cast<RandomBlendLoop *>(m)->setTimingParams(min, max);
		dynamic_cast<RandomBlendLoop *>(m)->setAutoShift(autoshift);
		return m;
};

template<> void MotionParserTyped<RandomBlendLoop>::editMotionInternal(RandomBlendLoop *mot, istringstream &is)
{
	    float endTime = -1.0f;
		float interval = 0.01f;
		float min = 1.0f, max = 1.0f;
		string currentWord;
				
		while (is >> currentWord)
		{
			if(currentWord == "endTime")
			{
				if(!(is >> endTime))
				{
					Piavca::Error(_T("no value given for end time\n"));
					return;
				}
				mot->setEndTime(endTime);
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "interval")
			{
				if(!(is >> interval))
				{
					Piavca::Error(_T("no value given for end time\n"));
					return;
				}
				mot->setBlendInterval(interval);
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "forget_root_transform")
			{
				mot->setAccumulateRoot(false);
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "random_timings")
			{
				bool randomTimings = true;
				if(!(is >> min))
				{
					Piavca::Error(_T("no value given for end time\n"));
					return;
				}
				if(!(is >> max))
				{
					Piavca::Error(_T("no value given for end time\n"));
					return;
				}
				mot->setTimingParams(min, max);
				if(!(is >> currentWord)) break;
			} 
			else if(currentWord == "autoshift")
			{
				mot->setAutoShift(true);
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "autoshift_off")
			{
				mot->setAutoShift(false);
				if(!(is >> currentWord)) break;
			} 
			else if(currentWord == "shift")
			{
				mot->SelfBlend::reblend();
				mot->shift();
				if(!(is >> currentWord)) break;
			}
			else
			{				
				Piavca::Error(_T("unknown option") + StringToTString(currentWord));
				break;
			}

		}
};

template<> Piavca::Motion *MotionParserTyped<RandomAddLoop>::parseMotion(istringstream &is, std::string currentWord, float scaleFactor)
{
	    MotionVec mv;
		float endTime = -1.0f;
		float interval = 0.01f;
		bool accumulateRoot = true;
		bool randomTimings = false;
		bool autoshift = true;
		float min = 0.0f, max = 1.0f;
		if(currentWord == "")
			if(!(is >> currentWord)) currentWord = "";
				
		while (currentWord != "")
		{
			if(currentWord == "endTime")
			{
				if(!(is >> endTime))
				{
					Piavca::Error(_T("no value given for end time\n"));
					return NULL;
				}
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "interval")
			{
				if(!(is >> interval))
				{
					Piavca::Error(_T("no value given for end time\n"));
					return NULL;
				}
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "forget_root_transform")
			{
				accumulateRoot = false;
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "random_timings")
			{
				randomTimings = true;
				if(!(is >> min))
				{
					Piavca::Error(_T("no value given for end time\n"));
					return NULL;
				}
				if(!(is >> max))
				{
					Piavca::Error(_T("no value given for end time\n"));
					return NULL;
				}
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "autoshift")
			{
				autoshift = true;
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "autoshift_off")
			{
				autoshift = false;
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "end")
			{
				currentWord = "";
				break;
			}
			else
			{
				MotionParser *mp = NULL;
				Motion *mot = MotionParser::parseMotion(is, currentWord, scaleFactor, &mp);
				if(Piavca::Core::getCore()->errorsPresent()) return NULL;
				if(mot == NULL) 
				{
					return NULL;
				}
				mv.push_back(mot);
				if(!(is >> currentWord)) break;
			}
		}
		
		Motion *m = new RandomAddLoop(mv, endTime, interval);
		dynamic_cast<RandomAddLoop *>(m)->setAccumulateRoot(accumulateRoot);
		if(randomTimings)
			dynamic_cast<RandomAddLoop *>(m)->setTimingParams(min, max);
		dynamic_cast<RandomAddLoop *>(m)->setAutoShift(autoshift);
		return m;
};

template<> void MotionParserTyped<RandomAddLoop>::editMotionInternal(RandomAddLoop *mot, istringstream &is)
{
	    float endTime = -1.0f;
		float interval = 0.01f;
		float min = 1.0f, max = 1.0f;
				
		string currentWord;
		while (is >> currentWord)
		{
			if(currentWord == "endTime")
			{
				if(!(is >> endTime))
				{
					Piavca::Error(_T("no value given for end time\n"));
					return;
				}
				mot->setEndTime(endTime);
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "interval")
			{
				if(!(is >> interval))
				{
					Piavca::Error(_T("no value given for end time\n"));
					return;
				}
				mot->setBlendInterval(interval);
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "forget_root_transform")
			{
				mot->setAccumulateRoot(false);
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "random_timings")
			{
				bool randomTimings = true;
				if(!(is >> min))
				{
					Piavca::Error(_T("no value given for end time\n"));
					return;
				}
				if(!(is >> max))
				{
					Piavca::Error(_T("no value given for end time\n"));
					return;
				}
				mot->setTimingParams(min, max);
				if(!(is >> currentWord)) break;
			} 
			else if(currentWord == "autoshift")
			{
				mot->setAutoShift(true);
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "autoshift_off")
			{
				mot->setAutoShift(false);
				if(!(is >> currentWord)) break;
			} 
			else if(currentWord == "shift")
			{
				mot->SelfBlend::reblend();
				mot->shift();
				if(!(is >> currentWord)) break;
			}
			else
			{				
				Piavca::Error(_T("unknown option") + StringToTString(currentWord));
				break;
			}

		}
};

template<> Piavca::Motion *MotionParserTyped<ProxemicsLoop>::parseMotion(istringstream &is, std::string currentWord, float scaleFactor)
{
	    float endTime = -1.0f;
		float interval = 0.01f;
		bool randomTimings = false;
		float min = 0.0f, max = 1.0f;
		Motion *forward = NULL, *back = NULL, *left = NULL, *right = NULL, *rest = NULL;
		float distance = 1.0f, threshold = 0.2f, anglethreshold = 22.5f;
		vector <Avatar *> avatars;
		if(currentWord == "")
			if(!(is >> currentWord)) currentWord = "";
				
		while (currentWord != "")
		{
			if(currentWord == "endTime")
			{
				if(!(is >> endTime))
				{
					Piavca::Error(_T("no value given for end time\n"));
					return NULL;
				}
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "interval")
			{
				if(!(is >> interval))
				{
					Piavca::Error(_T("no value given for end time\n"));
					return NULL;
				}
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "random_timings")
			{
				randomTimings = true;
				if(!(is >> min))
				{
					Piavca::Error(_T("no value given for end time\n"));
					return NULL;
				}
				if(!(is >> max))
				{
					Piavca::Error(_T("no value given for end time\n"));
					return NULL;
				}
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "-distance")
			{
				if(!(is >> distance))
				{
					Piavca::Error(_T("no value given for distance\n"));
					return NULL;
				}
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "-threshold")
			{
				if(!(is >> threshold))
				{
					Piavca::Error(_T("no value given for threshold\n"));
					return NULL;
				}
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "-anglethreshold")
			{
				if(!(is >> anglethreshold))
				{
					Piavca::Error(_T("no value given for anglethreshold\n"));
					return NULL;
				}
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "-forward")
			{
				currentWord = "";
				MotionParser *mp = NULL;
				forward = MotionParser::parseMotion(is, currentWord, scaleFactor, &mp);
				if(Piavca::Core::getCore()->errorsPresent()) return NULL;
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "-backward")
			{
				currentWord = "";
				MotionParser *mp = NULL;
				back = MotionParser::parseMotion(is, currentWord, scaleFactor, &mp);
				if(Piavca::Core::getCore()->errorsPresent()) return NULL;
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "-turnleft")
			{
				currentWord = "";
				MotionParser *mp = NULL;
				left = MotionParser::parseMotion(is, currentWord, scaleFactor, &mp);
				if(Piavca::Core::getCore()->errorsPresent()) return NULL;
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "-turnright")
			{
				currentWord = "";
				MotionParser *mp = NULL;
				right = MotionParser::parseMotion(is, currentWord, scaleFactor, &mp);
				if(Piavca::Core::getCore()->errorsPresent()) return NULL;
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "-rest")
			{
				currentWord = "";
				MotionParser *mp = NULL;
				rest = MotionParser::parseMotion(is, currentWord, scaleFactor, &mp);
				if(Piavca::Core::getCore()->errorsPresent()) return NULL;
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "-avatar")
			{
				if(!(is >> currentWord))
				{
					Piavca::Error(_T("no avatar parameter given for proxemics"));
					return NULL;
				}
				Avatar *avatar = Piavca::Core::getCore()->getAvatar(currentWord);
				if(!avatar)
				{
					Piavca::Error(_T("Unknown avatar ") + StringToTString(currentWord));
					return NULL;
				}
				avatars.push_back(avatar);
				if(Piavca::Core::getCore()->errorsPresent()) return NULL;
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "end")
			{
				currentWord = "";
				break;
			}
			else
			{
				Piavca::Error(_T("Unknown option ") + StringToTString(currentWord));
			}
		}
			
		Motion *m = new ProxemicsLoop(forward, back,rest, left, right, distance, endTime, interval);
		dynamic_cast<ProxemicsLoop *>(m)->setThreshold(threshold);
		dynamic_cast<ProxemicsLoop *>(m)->setAngleThreshold(Piavca::degToRad(anglethreshold));
		for (vector <Avatar *>::size_type i = 0; i < avatars.size(); i++)
			dynamic_cast<ProxemicsLoop *>(m)->addAvatar(avatars[i]);
		if(randomTimings)
				dynamic_cast<ProxemicsLoop *>(m)->setTimingParams(min, max);
		return m;
};


template<> void MotionParserTyped<ProxemicsLoop>::editMotionInternal(ProxemicsLoop *mot, istringstream &is)
{
	    float endTime = -1.0f;
		float interval = 0.01f;
		float min = 1.0f, max = 1.0f;
		string currentWord;		

		while (is >> currentWord)
		{
			if(currentWord == "endTime")
			{
				if(!(is >> endTime))
				{
					Piavca::Error(_T("no value given for end time\n"));
					return;
				}
				mot->setEndTime(endTime);
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "interval")
			{
				if(!(is >> interval))
				{
					Piavca::Error(_T("no value given for end time\n"));
					return;
				}
				mot->setBlendInterval(interval);
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "random_timings")
			{
				bool randomTimings = true;
				if(!(is >> min))
				{
					Piavca::Error(_T("no value given for end time\n"));
					return;
				}
				if(!(is >> max))
				{
					Piavca::Error(_T("no value given for end time\n"));
					return;
				}
				mot->setTimingParams(min, max);
				if(!(is >> currentWord)) break;
			} 
			else if(currentWord == "-distance")
			{
				float distance;
				if(!(is >> distance))
				{
					Piavca::Error(_T("no value given for end time\n"));
					return;
				}
				mot->setDistance(distance);
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "set_avatar")
			{
				if(!(is >> currentWord))
				{
					Piavca::Error(_T("no avatar parameter given for proxemics"));
					return;
				}
				Avatar *avatar = Piavca::Core::getCore()->getAvatar(currentWord);
				if(!avatar)
				{
					Piavca::Error(_T("Unknown avatar ") + StringToTString(currentWord));
					return ;
				}
				mot->removeAllAvatars();
				mot->addAvatar(avatar);
				if(Piavca::Core::getCore()->errorsPresent()) return;
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "add_avatar")
			{
				if(!(is >> currentWord))
				{
					Piavca::Error(_T("no avatar parameter given for proxemics"));
					return ;
				}
				Avatar *avatar = Piavca::Core::getCore()->getAvatar(currentWord);
				if(!avatar)
				{
					Piavca::Error(_T("Unknown avatar ") + StringToTString(currentWord));
					return ;
				}
				mot->addAvatar(avatar);
				if(Piavca::Core::getCore()->errorsPresent()) return;
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "add_avatar")
			{
				if(!(is >> currentWord))
				{
					Piavca::Error(_T("no avatar parameter given for proxemics"));
					return ;
				}
				Avatar *avatar = Piavca::Core::getCore()->getAvatar(currentWord);
				if(!avatar)
				{
					Piavca::Error(_T("Unknown avatar ") + StringToTString(currentWord));
					return ;
				}
				mot->removeAvatar(currentWord);
				if(Piavca::Core::getCore()->errorsPresent()) return;
				if(!(is >> currentWord)) break;
			}
			else if(currentWord == "remove_all_avatars")
			{
				mot->removeAllAvatars();
				if(!(is >> currentWord)) break;
			}
			else
			{				
				Piavca::Error(_T("unknown option") + StringToTString(currentWord));
				break;
			}

		}
};


std::map<tstring, MotionParser *> MotionParser::commandLookup = std::map<tstring, MotionParser *>();


void MotionParser::addMotionCommand(tstring name, MotionParser *command)
{
	int isNew = 0;

    if(name != _T(""))
        std::cout << "creating command " << name << "...";
    else
        std::cout << "unknown commands name\n";

    commandLookup[name] = command;
    std::cout << " finished adding command\n";
}


MotionParser *MotionParser::getMotionCommand(tstring name)
{
	std::map<tstring, MotionParser *>::iterator com = commandLookup.find(name);
	if(com != commandLookup.end())
		return com->second;
	else 
		return NULL;
}

void MotionParser::setUpMotionCommands()
{
    addMotionCommand(_T("zero"), new MotionParserTyped<ZeroMotion>());
	addMotionCommand(_T("-loop"), new MotionParserTyped<LoopMotion>());
	addMotionCommand(_T("-scale_root"), new MotionParserTyped<ScaleMotionRoot>());
	addMotionCommand(_T("-scale"), new MotionParserTyped<ScaleMotion>());
	addMotionCommand(_T("-speed"), new MotionParserTyped<ScaleMotionSpeed>());
	addMotionCommand(_T("-change"), new MotionParserTyped<ChangeMotionProp>());

	addMotionCommand(_T("-length"), new MotionParserTyped<ChangeMotionLength>());
	addMotionCommand(_T("-turn"), new MotionParserTyped<TurnMotion>());

	addMotionCommand(_T("blend"), new MotionParserTyped<BlendBetween>());
	addMotionCommand(_T("add"), new MotionParserTyped<MotionAdder>());
	addMotionCommand(_T("mask"), new MotionParserTyped<MaskedMotion>());

	addMotionCommand(_T("look_at"), new MotionParserTyped<LookAtMotion>());
	addMotionCommand(_T("random_gaze"), new MotionParserTyped<RandomGazeMotion>());
	addMotionCommand(_T("diadic_gaze"), new MotionParserTyped<DiadicGazeMotion>());

	addMotionCommand(_T("choice_loop"), new MotionParserTyped<ChoiceLoopMotion>());
	addMotionCommand(_T("random_loop"), new MotionParserTyped<RandomLoopMotion>());
	addMotionCommand(_T("random_blend"), new MotionParserTyped<RandomBlendLoop>());
	addMotionCommand(_T("random_add"), new MotionParserTyped<RandomAddLoop>());
	addMotionCommand(_T("proxemics"), new MotionParserTyped<ProxemicsLoop>());
}

PIAVCA_DECL Piavca::Motion *MotionParser::parseMotion(istringstream &is, std::string currentWord, float scaleFactor, MotionParser **mp)
{
	if(currentWord == "")
		is >> currentWord;
	Piavca::Motion *mot = Piavca::Core::getCore()->getMotion(currentWord);
	if(Piavca::Core::getCore()->errorsPresent()) return NULL;
	if(mot) 
	{
		currentWord = "";
		return mot;
	}

	*mp = getMotionCommand(StringToTString(currentWord));
	if(*mp)
		return (*mp)->parseMotion(is, "", scaleFactor);

	if(currentWord == "keyframes")
	{
		if(!(is >> currentWord))
			Piavca::Error(_T("Not enough arguments for keyframe motion"));
		bool facial = false;
		if(currentWord == string("-facial"))
		{
			facial = true;
			if(!(is >> currentWord))
				Piavca::Error(_T("Not enough arguments for keyframe motion"));
		}	
	
		TrackMotion *tmot = new TrackMotion(facial);

		while ( true )
		{
			if(currentWord == string("end"))
			{
				currentWord = "";
				break;
			}

			int jointId = -1;
			if(tmot->isFacial())
				jointId = Piavca::Core::getCore()->getExpressionId(StringToTString(currentWord));
			else
				jointId = Piavca::Core::getCore()->getJointId(StringToTString(currentWord));
			
			if(Piavca::Core::getCore()->errorsPresent()) 
			{
				return NULL;
			};
			if(jointId < 0)
			{
				if(tmot->isFacial()) 
					Piavca::Error(_T("unknown expression " + currentWord));
				else
					Piavca::Error(_T("unknown joint " + currentWord));
				delete tmot;
				return NULL;
			}

			float time; 
			if(!(is >> time))
			{
				Piavca::Error(_T("was expecting a number for keyframe time"));
				delete tmot;
				return NULL;
			}
			
			if(!(is >> currentWord))
			{
				Piavca::Error(_T("Not enough arguments for keyframe motion"));
				return NULL;
			}
			if(currentWord == "FLOAT")
			{
				if(tmot->isNull(jointId))
					tmot->addFloatTrack(jointId, 0.0);
				float value;
				if(!(is >> value))
				{
					Piavca::Error(_T("was expecting a number for keyframe value"));
					return NULL;
				}
				tmot->setFloatKeyframe(jointId, time, value);
				if(Piavca::Core::getCore()->errorsPresent()) 
				{
					delete tmot;
					return NULL;
				};
				if(!(is >> currentWord))
				{
					Piavca::Error(_T("Not enough arguments for keyframe motion"));
					return NULL;
				}
				continue;
			}
			if(currentWord == "VEC")
			{
				if(tmot->isNull(jointId))
					tmot->addVecTrack(jointId, Vec());
				Vec value; 
				if(!(is >> value))
				{
					Piavca::Error(_T("was expecting a Vec for keyframe value"));
					return NULL;
				}
				tmot->setVecKeyframe(jointId, time, value);
				if(Piavca::Core::getCore()->errorsPresent()) 
				{
					delete tmot;
					return NULL;
				};
				if(!(is >> currentWord))
				{
					Piavca::Error(_T("Not enough arguments for keyframe motion"));
					return NULL;
				}
				continue;
			}
			if(currentWord == "QUAT")
			{
				if(tmot->isNull(jointId))
					tmot->addQuatTrack(jointId, Quat());
				Quat value;
				if(!(is >> value))
				{
					Piavca::Error(_T("was expecting a Quat for keyframe value"));
					return NULL;
				}
				tmot->setQuatKeyframe(jointId, time, value);
				if(Piavca::Core::getCore()->errorsPresent()) 
				{
					delete tmot;
					return NULL;
				};
				if(!(is >> currentWord))
				{
					Piavca::Error(_T("Not enough arguments for keyframe motion"));
					return NULL;
				}
				continue;
			}	
		}
		if(!Piavca::Core::getCore()->errorsPresent())
			return tmot;
		else
		{
			delete tmot;
			return NULL;
		}
	  }
	else
	{
		Piavca::Error(_T("could not find motion ") + StringToTString(currentWord));
		return NULL;
	}
};
