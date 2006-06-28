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
 * The Original Code is PiavcaDefs.h.
 *
 * The Initial Developer of the Original Code is Marco (Mark) Gillies.
 * Portions created by the Initial Developer are Copyright (C) BT plc. 2004
 * All Rights Reserved.
 *
 * ***** END LICENSE BLOCK ***** */

#ifndef PIAVCA_DEFS_H
#define PIAVCA_DEFS_H


#ifdef WIN32


#ifndef		PIAVCA_DECL


//#ifdef			PIAVCA_DLL
#ifdef				PIAVCA_CLIENT

#define					PIAVCA_DECL __declspec( dllimport )

#else

#define					PIAVCA_DECL __declspec( dllexport )

#endif

//#else

//#define				PIAVCA_DECL

//#endif

#endif

#else


#define PIAVCA_DECL

#endif



/*!
 *	General definitions for the API
 */

#ifndef PIAVCA_EXPORT
#define PIAVCA_EXPORT
#endif

#include <vector>
#include <string>
//#include "PlatformDefs.h";

#ifdef WIN32
#include <tchar.h>
#endif

#include <iostream>
#include <fstream>
#include <sstream>

// stuff to do with porting between unicode and non unicode platforms

// fix some VC6 brokeness
#ifdef MS_VC6
#define get_facet(x) std::use_facet<std::ctype<wchar_t> > ( loc1, NULL, true )
#else
#define get_facet(x) std::use_facet<std::ctype<wchar_t> > ( loc1 )
#endif

//! convert an ansi string to a unicode string
inline std::wstring StringToWString(const std::string &str)
{
	static std::locale loc1 ( "English" );
	
	wchar_t *str2 = new wchar_t[str.size()+1];
	
	//bool result1 = 
//#ifdef WIN32
//	get_facet ( loc1 )._Widen_s
//	  ( str.c_str(), str.c_str() + str.size(), &str2[0], str.size()+1 );
//#else
	get_facet ( loc1 ).widen
	  ( str.c_str(), str.c_str() + str.size(), &str2[0] );
//#endif
	str2[str.size()] = '\0';
	std::wstring wstr(str2);
	delete str2;
	return wstr;
};


//! convert an unicode string to a ansi string
inline std::string WStringToString(const std::wstring &str)
{
   static std::locale loc1 ( "English" );
   
   char *str2 = new char[str.size()+1];

   //bool result1 = 
   
//#ifdef WIN32
//	get_facet ( loc1 )._Narrow_s
//	  ( str.c_str(), str.c_str() + str.size(), '*', &str2[0], str.size()+1 );
//#else
   get_facet ( loc1 ).narrow
	   ( str.c_str(), str.c_str() + str.size(), '*', &str2[0] );
//#endif
   str2[str.size()] = '\0';
   std::string wstr(str2);
   delete str2;
   return wstr;
}

// THIS IS TARA SPECIFIC: the Tara version of PIAVCA always uses unicode
//#ifndef _UNICODE
//#define _UNICODE
//#endif


#ifndef _UNICODE
#ifdef UNICODE
#define _UNICODE
#endif
#endif

#ifdef _UNICODE

#define _PSTR(x)       L ## x

#ifndef __T		
/*! a macro to apply to string literals to convert them to tstrings.
 *	Should be defined as standard but defining it here just in case.
 */
#define __T(x)      _PSTR(x)
typedef wchar_t _TCHAR;
//#define _TCHAR wchar_t
#endif //_T

//! \name conversion between string/wstrings and tstrings
//!@{
#define StringToTString(x) StringToWString(x)
#define TStringToString(x) WStringToString(x)
#define WStringToTString(x) (x) 
#define TStringToWString(x) (x) 
//!@}

// this bit gets parsed by the SWIG interface generator, fools it into thinking
// that tstrings are just strings
//#ifdef SWIG

//#define tstring const wchar *

//#else

namespace Piavca
{
	//!	A string class that handles either ascii  or unicode text
	/*! The aim of this class is to provide an STL string equivalent of the TCHAR type
	 *	which either stands for a normal (acsii) or wide (unicode) character
	 *	depending on whether _UNICODE is defined. Use this for all Piavca string handling.
	 *	To make a string literal into a tstring wrap it in the _T() macro
	 */
	typedef std::wstring tstring;
	
	//! \name unicode/ascii neutral stream classes
	//!@{
	typedef std::wofstream tofstream;
	typedef std::wifstream tifstream;
	typedef std::wfstream tfstream;

	typedef std::wostringstream tostringstream;
	typedef std::wistringstream tistringstream;
	typedef std::wstringstream tstringstream;

#define tcout std::wcout
#define tcin std::wcin
#define tcerr std::wcerr
	//!@}
};

inline std::ostream &operator<<(std::ostream &os, const Piavca::tstring &s)
{
	return os << TStringToString(s);	
};

//#endif

#else //_UNICODE

#define _PSTR(x)       x

#ifndef __T
#define __T(x)       _PSTR(x)
typedef char _TCHAR;
#endif //_T


#define StringToTString(x) (x)
#define TStringToString(x) (x)
#define WStringToTString(x) WStringToString(x) 
#define TStringToWString(x) StringToWString(x) 


// this bit gets parsed by the SWIG interface generator, fools it into thinking
// that tstrings are just strings
//#ifdef SWIG

//#define tstring const char *

//#else

namespace Piavca
{
	//!	A string class that handles either ascii  or unicode text
	/*! The aim of this class is to provide an STL string equivalent of the TCHAR type
	 *	which either stands for a normal (acsii) or wide (unicode) character
	 *	depending on whether _UNICODE is defined. Use this for all Piavca string handling.
	 *	To make a string literal into a tstring wrap it in the _T() macro
	 */
	typedef std::string tstring;

	typedef std::ofstream tofstream;
	typedef std::ifstream tifstream;
	typedef std::fstream tfstream;

	typedef std::ostringstream tostringstream;
	typedef std::istringstream tistringstream;
	typedef std::stringstream tstringstream;

#define tcout std::cout
#define tcin  std::cin
#define tcerr std::cerr
};

//#endif

#endif //_UNICODE

#ifndef _T
#define _T(x)       __T(x)
#endif
#ifndef _TEXT
#define _TEXT(x)    __T(x)
#endif



namespace Piavca
{

	//! this is enum used to define coordinate systems that you want a joint position etc in
	enum jointCoord 
	{
		LOCAL_COORD, //!< the lcoal coordinate system of the avatar
		JOINTLOCAL_COORD, //!< the coordinate system of the joint itself
		BASE_COORD, //!< the base orientation of the joint in the rest postures
		INCLUDINGBASE_COORD, //!< the the local coordinate system but including the base orientation
		WORLD_COORD //!< get the coordinate in world coordinates
	};

	
	//! the joints/tracks corresponding to the root position and orientation always have the IDs 0 and 1
	enum joint_ids 
	{
		root_position_id = 0, 
		root_orientation_id = 1
	};

	//! a typedef for a vector of piavca strings
	typedef std::vector<tstring> StringVector;
};

#endif //PIAVCA_DEFS_H
