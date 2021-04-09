#include "BatteryCell.h"

BatteryCell::BatteryCell(IGpioInput& chargingLine, ISpi& batteryInfoSpi) :
    m_chargingLine(chargingLine),
    m_batteryInfoSpi(batteryInfoSpi)
{
}

double BatteryCell::chargePercent() const
{
    return 0.0;
}
