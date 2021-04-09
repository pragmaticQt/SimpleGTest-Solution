#ifndef BATTERYCELL_H
#define BATTERYCELL_H

#include "ApplicationLibDecl.h"

#include "IBatteryCell.h"
#include "IGpioInput.h"
#include "ISpi.h"

class APPLICATIONLIB_EXPORT BatteryCell : public IBatteryCell
{
    Q_OBJECT
public:
    BatteryCell(IGpioInput& chargingLine, ISpi& batteryInfoSpi);

    double chargePercent() const override;

private:
    IGpioInput& m_chargingLine;
    ISpi& m_batteryInfoSpi;
};

#endif // BATTERY_H
