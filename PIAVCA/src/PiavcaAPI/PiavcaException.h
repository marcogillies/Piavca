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
 * The Original Code is PiavcaException.h.
 *
 * The Initial Developer of the Original Code is Marco (Mark) Gillies.
 * Portions created by the Initial Developer are Copyright (C) BT plc. 2004
 * All Rights Reserved.
 *
 * ***** END LICENSE BLOCK ***** */


#ifndef PIAVCA_EXCEPTION_H
#define PIAVCA_EXCEPTION_H

#include <iostream>
#include "PiavcaDefs.h"
#include "PiavcaCore.h"

namespace Piavca{

	//! A base exception class for handling errors in the architecture
	class PIAVCA_DECL CException
	{
	protected:
		//! a string that gives the details of what went wrong
		tstring details;
	public:
		CException(tstring _details):details(_details)
		    {
				std::cout << "Piavca Exception: " << details << std::endl;
		    };
		CException(const CException &e):details(e.details){};
		const CException &operator=(const CException &e){details=e.details; return (*this);};

		const tstring &getDetails(){return details;};
	};

	
	//! An exception class for file not found errors
	class FileNotFoundException : public CException{
		
	public:
		FileNotFoundException(tstring fileName)
			:CException(_PSTR("file ") + fileName + _PSTR(" could not be opened")){};
	};

	//! An exception class for file read errors
	class FileErrorException : public CException{
		
	public:
		FileErrorException(tstring fileName, tstring error)
			:CException(_PSTR("error found in file ") + fileName + _PSTR(": ") + error){};
	};



	


};

#endif //PIAVCA_EXCEPTION_H
