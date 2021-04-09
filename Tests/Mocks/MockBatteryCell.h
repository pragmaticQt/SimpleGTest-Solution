#ifndef MOCKBATTERYCELL_H
#define MOCKBATTERYCELL_H

#include "IBatteryCell.h"

#include <gmock/gmock.h>

class MockBatteryCell : public IBatteryCell
{
    Q_OBJECT
public:
    MOCK_CONST_METHOD0(chargePercent, double());
};

#endif // MOCKBATTERYCELL_H
