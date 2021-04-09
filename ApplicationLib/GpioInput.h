#ifndef GPIOINPUT_H
#define GPIOINPUT_H

#include "ApplicationLibDecl.h"

#include "IGpioInput.h"

/* This class interacts with the Operating System. Test via sideffect.
 * Make this class configurable to subscribe to any Gpio on the system.
 */

class APPLICATIONLIB_EXPORT GpioInput : public IGpioInput
{
    Q_OBJECT
public:
    GpioInput();
};

#endif // IGPIOINPUT_H
