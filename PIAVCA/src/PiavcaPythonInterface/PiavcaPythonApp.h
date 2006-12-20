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
 * The Original Code is PiavcaPythonApp.h.
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


#ifndef PIAVCA_PYTHON_APP
#define PIAVCA_PYTHON_APP

typedef struct _object PyObject;

//#include <Python.h>

#include "PiavcaAPI/PiavcaCore.h"


namespace Piavca
{
//! Initialise the Python bindings and load the python module in filename
void InitPiavcaPython(Piavca::Core *core, tstring fileName, bool no_console = false);
//! Close down the Python bindings
void EndPiavcaPython(Piavca::Core *core);

//! print out any outstanding python errors
void PrintPythonErrors();

//! Run a method from the loaded python module (no arguments)
void RunPythonMethod(Piavca::Core *core, char *methodName);
//! Run a method from the loaded python module (integer argument)
void RunPythonMethod(Piavca::Core *core, char *methodName, int arg);
//! Run a method from the loaded python module (float argument)
void RunPythonMethod(Piavca::Core *core, char *methodName, float arg);
//! Run a method from the loaded python module (string argument)
void RunPythonMethod(Piavca::Core *core, char *methodName, std::string arg);
//! Run a method from the loaded python module (Vec argument)
void RunPythonMethod(Piavca::Core *core, char *methodName, const Vec &arg);
//! Run a method from the loaded python module (float and Vec (angle axis) argument)
void RunPythonMethod(Piavca::Core *core, char *methodName, float farg, const Vec &varg);
//! Run a method from the loaded python module with an arbitrary python object as an argument
/*!
 *	This can be used for passing arbitrary arguments by creating the
 *  argument with Py_BuildValue.
 */
void RunPythonMethod(Piavca::Core *core, char *methodName, PyObject *arg);

};

#endif //PIAVCA_PYTHON_APP
