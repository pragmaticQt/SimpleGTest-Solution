#ifndef IBATTERY_H
#define IBATTERY_H

#include "ApplicationLibDecl.h"

#include <QObject>

class APPLICATIONLIB_EXPORT IBattery : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double chargePercent READ chargePercent NOTIFY chargePercentChanged)
public:
    virtual double chargePercent() const = 0;

signals:
    void chargePercentChanged();
};

#endif // IBATTERY_H
