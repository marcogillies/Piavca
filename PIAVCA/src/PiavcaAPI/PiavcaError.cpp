
#include "PiavcaCore.h"
#include "PiavcaError.h"
#include "PiavcaException.h"

using namespace Piavca;

PIAVCA_DECL void Piavca::Error(tstring details)
{
	std::cout << "Piavca Error: " << TStringToString(details) << std::endl;
	Piavca::Core::getCore()->addError(_T("Piavca Error:") + details);
	if(Piavca::Core::getCore()->exceptionsOn())
		throw Piavca::Exception(details);
}

PIAVCA_DECL void Piavca::Warning(tstring details)
{
	std::cout << "Piavca Error: " << TStringToString(details) << std::endl;
	Piavca::Core::getCore()->addWarning(_T("Piavca Error:") + details);
}
