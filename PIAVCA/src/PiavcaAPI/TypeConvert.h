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
 * The Original Code is TypeConvert.h.
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


#ifndef TYPE_CONVERT_H
#define TYPE_CONVERT_H

#include "PiavcaAPI/PiavcaDefs.h"
#include "PiavcaAPI/PiavcaCore.h"
#include <strstream>

namespace Piavca
{
	template <class T>
	inline T convert(Piavca::tstring value)
	{
		std::istrstream is(TStringToString(value).c_str());
		T retval;
		is >> retval;
		return retval;
	}
	
	template<>
	inline Motion *convert<Motion *>(Piavca::tstring value)
	{
		return Piavca::Core::getCore()->getMotion(value);
	}
	
	template<>
	inline Avatar *convert<Avatar *>(Piavca::tstring value)
	{
		return Piavca::Core::getCore()->getAvatar(value);
	}
	
	template<>
	inline std::vector<std::string> convert<std::vector<std::string> >(Piavca::tstring value)
	{
		std::vector<std::string> retval;
		std::istrstream is(TStringToString(value).c_str());
		do
		{
			std::string sub;
			is >> sub;
			retval.push_back(sub);
		} while (is);
		
		return retval;
	}
	
	
}

#endif //TYPE_CONVERT_H