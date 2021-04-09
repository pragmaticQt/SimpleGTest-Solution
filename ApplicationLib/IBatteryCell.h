#ifndef IBATTERYCELL_H
#define IBATTERYCELL_H

#include "ApplicationLibDecl.h"

#include <QObject>

class APPLICATIONLIB_EXPORT IBatteryCell : public QObject
{
    Q_OBJECT
public:
    virtual double chargePercent() const = 0;

signals:
    void chargePercentChanged();
};

#endif // IBATTERYCELL_H
