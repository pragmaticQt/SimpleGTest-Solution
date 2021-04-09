#ifndef BATTERY_H
#define BATTERY_H

#include "ApplicationLibDecl.h"

#include "IBattery.h"
#include "IBatteryCell.h"

#include <QList>

class APPLICATIONLIB_EXPORT Battery : public IBattery
{
    Q_OBJECT
public:
    Battery(IBatteryCell &cellOne, IBatteryCell &cellTwo);

    double chargePercent() const override;

private:
    IBatteryCell &m_cellOne;
    IBatteryCell &m_cellTwo;
};

#endif // BATTERY_H
