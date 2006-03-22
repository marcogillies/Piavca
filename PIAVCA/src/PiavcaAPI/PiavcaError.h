#ifndef PIAVCA_ERROR_H
#define PIAVCA_ERROR_H

#include "PiavcaDefs.h"

namespace Piavca
{
	// call in case of error, calls an exception if exceptions are enabled
	PIAVCA_DECL void Error(tstring details);
	// call in case of problem that is not a fatal error but that should be reported
	PIAVCA_DECL void Warning(tstring details);
};

#endif //PIAVCA_ERROR_H