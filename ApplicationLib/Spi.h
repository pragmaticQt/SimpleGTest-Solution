#ifndef SPI_H
#define SPI_H

#include "ApplicationLibDecl.h"

#include "ISpi.h"

/* This class interacts with the Operating System. Test via sideffect.
 * Make this class general enough to be used by anything needing spi bus.
 * More classes under this one may be necessary to satify the Single
 * Responsibility Principle
 */

class APPLICATIONLIB_EXPORT Spi : public ISpi
{
    Q_OBJECT
public:
    Spi();
};

#endif // SPI_H
