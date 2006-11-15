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
 *
 * ***** END LICENSE BLOCK ***** */


#ifndef PIAVCA_EXCEPTION_H
#define PIAVCA_EXCEPTION_H

#include <iostream>
#include "PiavcaDefs.h"
//#include "PiavcaCore.h"

namespace Piavca{

	//! A base exception class for handling errors in the architecture
	class PIAVCA_DECL Exception
	{
	protected:
		//! a string that gives the details of what went wrong
		tstring details;
	public:
		Exception(tstring _details):details(_details)
		    {
				std::cout << "Piavca Exception: " << details << std::endl;
		    };
		Exception(const Exception &e):details(e.details){};
		const Exception &operator=(const Exception &e){details=e.details; return (*this);};

		const tstring &getDetails(){return details;};
	};

	
	//! An exception class for file not found errors
	class FileNotFoundException : public Exception{
		
	public:
		FileNotFoundException(tstring fileName)
			:Exception(_PSTR("file ") + fileName + _PSTR(" could not be opened")){};
	};

	//! An exception class for file read errors
	class FileErrorException : public Exception{
		
	public:
		FileErrorException(tstring fileName, tstring error)
			:Exception(_PSTR("error found in file ") + fileName + _PSTR(": ") + error){};
	};



	


};

#endif //PIAVCA_EXCEPTION_H
