
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
 * The Original Code is SpeechToText.cpp.
 *
 * The Initial Developer of the Original Code is Sailesh Varsarni.
 * Portions created by the Initial Developer are Copyright (C) BT plc. 2004
 * All Rights Reserved.
 *
 * Contributor(s): Marco Gillies
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


#include <windows.h>
#include <sapi.h>
#include <stdio.h>
#include <string.h>
#include <atlbase.h>
//extern "C" {
#include "sphelper.h"
//}
#include "SpeechToText.h"

using namespace Piavca;

/* 
 * This method inputs two types of parameters, an ISpRecoContext and an ISpRecoResult.
 * This method waits until a word has been recognised by the SR engine,
 * once the word is recognised it is then referenced and the object hr is returned
 */

inline HRESULT BlockForResult(ISpRecoContext * pRecoCtxt, ISpRecoResult ** ppResult)
{
    
	// Defines weather a function has successfully completed
	HRESULT hr = S_OK;
	CSpEvent event;

    while (SUCCEEDED(hr) &&
           SUCCEEDED(hr = event.GetFrom(pRecoCtxt)) &&
           hr == S_FALSE)
    {
        hr = pRecoCtxt->WaitForNotifyEvent(INFINITE);
    }

    *ppResult = event.RecoResult();
    if (*ppResult)
    {
        (*ppResult)->AddRef();
    }

    return hr;
}


/* 
 * This method uses the COM object with the SAPI to 
 * recognise the words spoken by the human
 * (Dictation method). The words are then returned 
 * back to the console. 
 */

char* SpeechToText::getText()
{
    HRESULT hr = E_FAIL;

	//Initialising COM
    if (SUCCEEDED(hr = ::CoInitialize(NULL)))
    {
        {
			//Initialising ISpRecoContext enables this program
			//to create different functional views or contexts 
			//of the SR engine.

            CComPtr<ISpRecoContext> cpRecoCtxt;

			//Initialising ISpRecoGrammar enables this program
			//to manage the words and phrases that the SR 
			//engine will recognise.

            CComPtr<ISpRecoGrammar> cpGrammar;

            hr = cpRecoCtxt.CoCreateInstance(CLSID_SpSharedRecoContext);
           
            if (cpRecoCtxt && 
                SUCCEEDED(hr = cpRecoCtxt->SetNotifyWin32Event()) &&
                SUCCEEDED(hr = cpRecoCtxt->SetInterest(SPFEI(SPEI_RECOGNITION), SPFEI(SPEI_RECOGNITION))) &&
                SUCCEEDED(hr = cpRecoCtxt->CreateGrammar(0, &cpGrammar)) &&
                SUCCEEDED(hr = cpGrammar->LoadDictation(NULL, SPLO_STATIC)) &&
                SUCCEEDED(hr = cpGrammar->SetDictationState(SPRS_ACTIVE)))
            {
                USES_CONVERSION;
                            
                //Initialising ISpRecoResult enables this program
				//to retrieve information about the SR engine's 
				//hypotheses, recognitions, and false recognitions.
				
				CComPtr<ISpRecoResult> cpResult;

                while (SUCCEEDED(hr = BlockForResult(cpRecoCtxt, &cpResult)))
				{
                    //Activate the dictation topic to receive recognitions
					cpGrammar->SetDictationState( SPRS_ACTIVE );

                    CSpDynamicString dstrText;

                    if (SUCCEEDED(cpResult->GetText(SP_GETWHOLEPHRASE, SP_GETWHOLEPHRASE, 
                                                    TRUE, &dstrText, NULL)))
                    { 
						//Releases the speech object from the SR engine
						cpResult.Release();
						return (dstrText.CopyToChar());
                    }
					//Deactivate the dictation topic to stop receiving recognitions
					cpGrammar->SetDictationState( SPRS_INACTIVE );
                } 
            }
        }
        ::CoUninitialize();
    }
    char *idle= "-";
	return idle;
}