#include "Battery.h"

Battery::Battery(IBatteryCell &cellOne, IBatteryCell &cellTwo) :
    m_cellOne(cellOne),
    m_cellTwo(cellTwo)
{
    connect(&m_cellOne, SIGNAL(chargePercentChanged()),
            this, SIGNAL(chargePercentChanged()));

    connect(&m_cellTwo, SIGNAL(chargePercentChanged()),
            this, SIGNAL(chargePercentChanged()));
}

double Battery::chargePercent() const
{
    double cellOnePercent = m_cellOne.chargePercent();
    double cellTwoPercent = m_cellTwo.chargePercent();

    if(cellOnePercent == 0.0 || cellTwoPercent == 0.0)
        return 0;

    return (cellOnePercent + cellTwoPercent) / 2;
}
