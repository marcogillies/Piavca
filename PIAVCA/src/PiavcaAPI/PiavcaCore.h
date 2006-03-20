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
 * The Original Code is PIAVCACore.h.
 *
 * The Initial Developer of the Original Code is Marco (Mark) Gillies.
 * Portions created by the Initial Developer are Copyright (C) BT plc. 2004
 * All Rights Reserved.
 *
 * ***** END LICENSE BLOCK ***** */

#ifndef PIAVCA_CORE_H
#define PIAVCA_CORE_H

#include "PiavcaDefs.h"
#include "TimeCallback.h"

#include <vector>
#include <map>
#include <list>
#include <fstream>

#include "Vec.h"
#include "Quat.h"

//#include <fstream>
#include <sstream>

namespace Piavca{
	class PIAVCA_DECL Core;
};

/*PIAVCA_EXPORT*/ //void PiavcaMain(Piavca::Core *core);
/*PIAVCA_EXPORT*/ //void PiavcaEnd(Piavca::Core *core);


namespace Piavca
{
	class PIAVCA_DECL Motion;
	class PIAVCA_DECL MotionImp;
	class PIAVCA_DECL TrackMotion;
	class PIAVCA_DECL Avatar;
	class PIAVCA_DECL AvatarImp;
	class PIAVCA_DECL Object;
	class PIAVCA_DECL ObjectImp;

	//! the joints/tracks corresponding to the root position and orientation always have the IDs 0 and 1
	enum joint_ids {root_position_id = 0, root_orientation_id = 1};

	// call in case of error, calls an exception if exceptions are enabled
	PIAVCA_DECL void Error(tstring details);
	// call in case of problem that is not a fatal error but that should be reported
	PIAVCA_DECL void Warning(tstring details);

	//! The core object is the central controller of the Piavca system.
	/*!	It maintains a list of avatars, and some motions. It has a list of global
	 *	callbacks that are called every frame. It handles allocation of Joint IDs.
	 *  It deals with initialisation and shut down and per frame events. It also manages 
	 *	creation of avatar and motions. There is only ever one core object (held as the
	 *	core static member of the class).
	 */
	class PIAVCA_DECL Core
	{
	protected:
		//! the instance of the piavca core
		static Core *core;

		std::vector<TimeCallback *> callbacks;
		std::vector<Avatar *> avatars;
		std::vector<Object *> objects;
		//std::map<tstring, Motion *> motions;
		std::vector<std::pair<tstring, Motion *> > motions;
		//! a map between joint names and ids (there may be mutliple joint names corresponding to a single id
		std::map<tstring, int> jointMap;
		//! the maximum joint Id
		int maxJointId;
		//! a map between facial expressions and ids (there may be mutliple expression names corresponding to a single id
		std::map<tstring, int> expressionMap;
		//! the maximum expression Id
		int maxExpressionId;

		//! this flag turns off real time running of Piavca
		bool autoTimeOff;
		//! the current time (if it isn't linked to the real time clock)
		float currentTime;

		//! creates an avatar implementation 
		/*!
		* (see Avatar.h for discussion of the interface implementation architecture)
		*/
		virtual AvatarImp *createAvatarImp(tstring avatarId, bool bailOnMissedJoints, const Vec &Position, const Quat &Orientation) = 0;
		
		//! creates an object implementation 
		/*!
		* (see Object.h for discussion of the interface implementation architecture)
		*/
		virtual ObjectImp *createObjectImp(tstring objectId, const Vec &Position, const Quat &Orientation) = 0;
		//! creates a motion implementation
		virtual MotionImp *createMotionImp(tstring filename, bool facial, int flags, Motion *basePosture = NULL) = 0;//! the granularity at which keyframes can be set 
		//! the granularity at which motion keyframes can be set 
		/*!
		*  Though time is represented in floating point, keyframes can only be 
		*	set as integers to avoid problems with rounding errors. The granularity is 
		*	the conversion factor between the two.
		*/
		//float keyframeGranularity;
		//! removes a motion if its reference count is zero and its not owned by the core
		void removeMotion(Motion *mot);

		//! a string stream to hold errors thrown by piavca
		tostringstream errorstrm;
		//! a string stream to hold warnings thrown by piavca
		tostringstream warningstrm;

		//! an output file for logging data
		std::ofstream log_file;

		//! a flag that controls whether exceptions are thrown or not
		bool exceptionFlag;
	public:

		//! the search directory for Piavca files
		tstring dir;

		Core();
		virtual ~Core()
		{	
			reset(); 
		};

		virtual void reset();

		//! a static function to get the core instances (there is only one)
		//virtual static Core *getCore()=0;//{};

		static Core *getCore() {return core;};
		
		//! registers a callback to be called every frame
		void registerCallback(TimeCallback *cb) 
		{
			if(!cb)
			{
				Piavca::Error(_T("Trying to register a null pointer as a callback"));
				return;
			}
			callbacks.push_back(cb);
			cb->init(this);
		};
		/*! Performs all per frame actions (uses the current time)
		 *	Can be run in parallel with the renderer.
		 */
		void timeStep(){timeStep(getTime());};
		/*! Performs all per frame actions
		 *	Can be run in parallel with the renderer.
		 */
		virtual void timeStep(float time);
		
		//! called before rendering (this cannot be called in parallel with the render)
		virtual void prerender();

		//! On certain platforms this needs to be called to render the avatars
		virtual void render();

		/*! methods dealing with joint ids
		 *
		 */
		//!@{
		//! get an id corresponding to a joint name
		int getJointId(tstring name);
		//! gets the maximum joint id
		int getMaxJointId(){return maxJointId;};
		//! Adds in a set of joints all of which should have the same id
		/*! i.e. all the names correspond to the same joint e.g. (left_foot, LFoot, LeftFoot, PiedGauche)
		 */
		void addJointNameSet(Piavca::StringVector names);
		//! returns a name corresponding to a track id (out of many possible)
		tstring getJointName(int jointId);
		//! get all the joint name associations
		std::vector<std::pair<tstring, int> > getJointNameAssociations()
		{
			std::vector<std::pair<tstring, int> > v(jointMap.begin(), jointMap.end());
			return v;
		}
		//!@}

		/*! methods dealing with expression ids
		 *
		 */
		//!@{
		//! get an id corresponding to an expression name
		int getExpressionId(tstring name);
		//! gets the maximum joint id
		int getMaxExpressionId(){return maxExpressionId;};
		//! Adds in a set of joints all of which should have the same id
		/*! i.e. all the names correspond to the same joint e.g. (left_foot, LFoot, LeftFoot, PiedGauche)
		 */
		void addExpressionNameSet(Piavca::StringVector names);
		//! returns a name corresponding to a track id (out of many possible)
		tstring getExpressionName(int expressionId);
		//! get all the expression name associations
		std::vector<std::pair<tstring, int> > getExpressionNameAssociations()
		{
			std::vector<std::pair<tstring, int> > v(expressionMap.begin(), expressionMap.end());
			return v;
		}
		//!@}

		//! loads in a motion from file and adds it to the list of motions
		void loadMotion(tstring motionName, tstring motionFileName, int flags = 0, bool temp=false, Motion *basePosture = NULL);
		
		//! adds a motion to its list of motions
		void loadMotion(tstring motionName, Motion *mot, bool temp = false, Motion *basePosture = NULL);
		

		//! changes the name of a motion
		void renameMotion(tstring oldName, tstring newName);
		//! removes the motion from the core and deletes it (NB difference to disposeMotion)
		void unloadMotion(tstring name);

		/*! get a named motion 
		 *  NB the caller gets ownership of the motion and therefore
		 *  must delete it (of course ownership can be given to an avatar
		 *  by loading it)
		 */
		Motion *getMotion(tstring motionName);

        //! get motion names
        PIAVCA_EXPORT std::vector<std::string> getMotionNames(int number = 0);

        //! get number of motions
        int getNumberOfMotions() { return motions.size(); };

		//! get all motion names
		PIAVCA_EXPORT std::list<tstring> getAllmotions();

        //! get a motion by its (arbitrary) index
        Motion *getMotion(int i) { return motions[i].second; };


		/*! \brief Delete the motion if it is not a motion belonging to the core 
		 *  (NB difference to removeMotion)
		 *  this is the correct process to go through when deleting a motion
		 */
		//void disposeMotion(const Motion *mot);

		//! get a named avatar
		Avatar *getAvatar(tstring avatarName);
		//Avatar *getAvatar(char *avatarName){return getAvatar(StringToTString(avatarName));};
		//Avatar *getAvatar(const char *avatarName){return getAvatar(StringToTString(avatarName));};

		std::vector<tstring> getAvatarNames();

		//! get the number of avatars 
		int numAvatars () {return static_cast<int>(avatars.size());};
		//! get the ith avatar in the list (used for interating over all avatars)
		Avatar *getAvatar(int i)
		{
			if(i >= 0 && i < numAvatars())
				return avatars[i];
			else
			{
				Piavca::Error(_T("trying to get an avatar from an invalid index"));
				return NULL;
			}
		};

		//! changes the name of an avatar
		void renameAvatar(tstring oldName, tstring newName);

		//! removes and avatar
		void removeAvatar(Avatar *avatar);

		//! Initialises an avatar.
		/*!
		*	You pass in a pointer to the avatar and an id with which to initialise it.
		*	It creates an implementation object which will actually be a platform dependant 
		*	sub type of AvatarImp. It then sets some stuff up and stores a pointer to 
		*	the avatar.
		*/
		virtual void initAvatar(
					Avatar *avatar,
					tstring avatarId, 
					bool bailOnMissedJoints = false,
					const Vec &Position = Vec(0.0, 0.0, 0.0), 
					const Quat &Orientation = Quat(1.0, 0.0, 0.0, 0.0));

		
		//! get a named object
		Object *getObject(tstring objectName);

		//! get the number of avatars 
		int numObjects () {return static_cast<int>(objects.size());};
		//! get the ith avatar in the list (used for interating over all avatars)
		Object *getObject(int i)
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
		void renameObject(tstring oldName, tstring newName);

		//! removes and avatar
		void removeObject(Object *object);

		//! Initialises an object.
		/*!
		*	You pass in a pointer to the object and an id with which to initialise it.
		*	It creates an implementation object which will actually be a platform dependant 
		*	sub type of ObjectImp. It then sets some stuff up and stores a pointer to 
		*	the object.
		*/
		virtual void initObject(
					Object *object,
					tstring objectId, 
					const Vec &Position = Vec(0.0, 0.0, 0.0), 
					const Quat &Orientation = Quat(1.0, 0.0, 0.0, 0.0));


		//! Initialises a TrackMotion object.
		/*!
		*	You pass in a pointer to the TrackMotion and a filename with which to initialise it.
		*	It creates an implementation object which will actually be a platform dependant 
		*	sub type of MotionImp. 
		*/
		virtual void initMotion(
					TrackMotion *mot, 
					tstring filename = _PSTR(""), 
					bool facial = false,
					int flags = 0, 
					Motion *basePosture = NULL);

		//! set the search directory
		void setDir(tstring _dir){dir = _dir;};

		//! get the current time in seconds
	    float getTime()
		{
			if(autoTimeOff)
				return currentTime;
			else
				return getTimeInternal();
		}
		//! get the current time in seconds
	    virtual float getTimeInternal()=0;
		//! turns off the automatic updating of the current time from the system clock
		void setAutoTimeOff(){autoTimeOff = true;};
		//! turns on the automatic updating of the current time from the system clock
		void setAutoTimeOn(){autoTimeOff = true;};
		//! sets the current time (if its not linked to the system clock
		void setCurrentTime(float t){currentTime = t;};

		void addError(tstring details){errorstrm << details << std::endl;};
		tostringstream &error(){return errorstrm;};
		void clearErrors(){errorstrm.str(_T(""));};
		tstring getErrors(){return errorstrm.str();};
		bool errorsPresent(){return errorstrm.str() != _T("");};

		void addWarning(tstring details){warningstrm << details << std::endl;};
		tostringstream &Warning(){return warningstrm;};
		void clearWarnings(){warningstrm.str(_T(""));};
		tstring getWarnings(){return warningstrm.str();};
		bool warningsPresent(){return warningstrm.str() != _T("");};

		bool exceptionsOn(){return exceptionFlag;};
		void setExceptionsOn(){exceptionFlag = true;};
		void setExceptionsOff(){exceptionFlag = false;};

		std::ostream &log(){return log_file;};

		friend class Motion;
	};

};
#endif //PIAVCA_CORE_H
