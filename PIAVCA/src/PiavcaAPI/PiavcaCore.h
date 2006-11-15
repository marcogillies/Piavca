/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/l
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

#ifndef PIAVCA_CORE_H
#define PIAVCA_CORE_H

#include "PiavcaDefs.h"
//#include "TimeCallback.h"

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
	class PIAVCA_DECL TimeCallback;


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

		//! a flag that controls whether exceptions are thrown or not
		bool exceptionFlag;

		//! an output file for logging data
		std::ofstream log_file;

		//! a structure for holding profiling data
		struct ProfilePoint 
		{
			tstring m_name;
			float m_start_time;
			float m_accumulated_time;

			ProfilePoint(tstring name, float time):m_name(name), m_start_time(time), m_accumulated_time(0.0f){}
			ProfilePoint(const ProfilePoint &pp):m_name(pp.m_name), m_start_time(pp.m_start_time), m_accumulated_time(m_accumulated_time){}
		};
		std::vector <ProfilePoint> m_profilePoints;
	public:

		//! the search directory for Piavca files
		tstring dir;

		Core();
		virtual ~Core();

		virtual void reset();

		//! a static function to get the core instances (there is only one)
		//virtual static Core *getCore()=0;//{};

		static Core *getCore() 
		{
			return core;
		};
		
		//! registers a callback to be called every frame
		void registerCallback(TimeCallback *cb);

		/*! Performs all per frame actions (uses the current time)
		 *	Can be run in parallel with the renderer.
		 */
		void timeStep()
		{
			timeStep(getTime());
		};
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
		void addJointNameSet(StringVector names);
		//! returns a name corresponding to a track id (out of many possible)
		tstring getJointName(int jointId);
		//! get all the joint name associations
		std::vector<std::pair<tstring, int> > getJointNameAssociations();
		//!@}

		/*! methods dealing with expression ids
		 *
		 */
		//!@{
		//! get an id corresponding to an expression name
		int getExpressionId(tstring name);
		//! gets the maximum joint id
		int getMaxExpressionId()
		{
			return maxExpressionId;
		};
		//! Adds in a set of joints all of which should have the same id
		/*! i.e. all the names correspond to the same joint e.g. (left_foot, LFoot, LeftFoot, PiedGauche)
		 */
		void addExpressionNameSet(StringVector names);
		//! returns a name corresponding to a track id (out of many possible)
		tstring getExpressionName(int expressionId);
		//! get all the expression name associations
		std::vector<std::pair<tstring, int> > getExpressionNameAssociations();
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
		int getNumberOfMotions() 
		{ 
			return static_cast<int>(motions.size()); 
		};

		//! get all motion names
		PIAVCA_EXPORT std::list<tstring> getAllmotions();

        //! get a motion by its (arbitrary) index
        Motion *getMotion(int i) 
		{ 
			return motions[i].second; 
		};

		//! get a named avatar
		Avatar *getAvatar(tstring avatarName);
		std::vector<tstring> getAvatarNames();

		//! get the number of avatars 
		int numAvatars () 
		{
			return static_cast<int>(avatars.size());
		};
		//! get the ith avatar in the list (used for interating over all avatars)
		Avatar *getAvatar(int i);

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
		int numObjects () 
		{
			return static_cast<int>(objects.size());
		};
		//! get the ith avatar in the list (used for interating over all avatars)
		Object *getObject(int i);

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
				return getSystemTime();
		}
		//! get the current time in seconds
	    virtual float getSystemTime()=0;
		//! turns off the automatic updating of the current time from the system clock
		void setAutoTimeOff()
		{
			autoTimeOff = true;
		};
		//! turns on the automatic updating of the current time from the system clock
		void setAutoTimeOn()
		{
			autoTimeOff = true;
		};
		//! sets the current time (if its not linked to the system clock
		void setCurrentTime(float t)
		{
			currentTime = t;
		};

		void addError(tstring details);
		tostringstream &error()
		{
			return errorstrm;
		};
		void clearErrors();
		tstring getErrors()
		{
			return errorstrm.str();
		};
		bool errorsPresent()
		{
			return errorstrm.str() != _T("");
		};

		void addWarning(tstring details);
		tostringstream &Warning()
		{
			return warningstrm;
		};
		void clearWarnings();
		tstring getWarnings()
		{
			return warningstrm.str();
		};
		bool warningsPresent()
		{
			return warningstrm.str() != _T("");
		};

		bool exceptionsOn()
		{
			return exceptionFlag;
		};
		void setExceptionsOn()
		{
			exceptionFlag = true;
		};
		void setExceptionsOff()
		{
			exceptionFlag = false;
		};

		std::ostream &log()
		{
			return log_file;
		};

		/*! creates a new profile point for logging profile data.
		 *	Returns and id which can be used to access the profile point.
		 *  You would normally create the point id as a static variable 
		 *  within the function you are profiling.
		 */
		int addProfilePoint(tstring name)
		{
			m_profilePoints.push_back(ProfilePoint(name, getTime()));
			return ((int)m_profilePoints.size()-1);
		};

		//! marks the start of a profile point
		void profilePointStart(int i)
		{
			m_profilePoints[i].m_start_time = getTime();
		};

		//! marks the end of the profile point
		void profilePointEnd(int i)
		{
			m_profilePoints[i].m_accumulated_time += getTime() - m_profilePoints[i].m_start_time;
		};

		//! prints out the profiling data that has been collected.
		void printProfileData();

		friend class Motion;
	};

};
#endif //PIAVCA_CORE_H
