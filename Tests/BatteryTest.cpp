#include "Battery.h"

#include "QtTypePrinters.h"

#include "Mocks/MockBatteryCell.h"

#include <QSignalSpy>

#include "gtest/gtest.h"

using namespace ::testing;

class BatteryTest : public Test
{
public:
    BatteryTest() :
        m_battery(m_batteryCellOne, m_batteryCellTwo)
    {
    }

protected:
    //Dependancies
    NiceMock<MockBatteryCell> m_batteryCellOne;
    NiceMock<MockBatteryCell> m_batteryCellTwo;

    //Class Under Test
    Battery m_battery;
};

TEST_F(BatteryTest, ChargePercentCallsChargePercentOnCellOne)
{
    EXPECT_CALL(m_batteryCellOne, chargePercent()).Times(1);
    m_battery.chargePercent();
}

TEST_F(BatteryTest, ChargePercentCallsChargePercentOnCellTwo)
{
    EXPECT_CALL(m_batteryCellTwo, chargePercent()).Times(1);
    m_battery.chargePercent();
}

TEST_F(BatteryTest, ChargePercentReturnsAverageChargePercentOfBothCells)
{
    ON_CALL(m_batteryCellOne, chargePercent()).WillByDefault(Return(0.75));
    ON_CALL(m_batteryCellTwo, chargePercent()).WillByDefault(Return(0.25));
    ASSERT_DOUBLE_EQ(0.5, m_battery.chargePercent());
}

TEST_F(BatteryTest, ChargePercentReturnsAverageChargePercentOfBothCellsWithDifferentValues)
{
    ON_CALL(m_batteryCellOne, chargePercent()).WillByDefault(Return(0.5));
    ON_CALL(m_batteryCellTwo, chargePercent()).WillByDefault(Return(1.0));
    ASSERT_DOUBLE_EQ(0.75, m_battery.chargePercent());
}

TEST_F(BatteryTest, ChargePercentReturnsZeroWhenBatteryOneChargeIsZero)
{
    ON_CALL(m_batteryCellOne, chargePercent()).WillByDefault(Return(0));
    ON_CALL(m_batteryCellTwo, chargePercent()).WillByDefault(Return(55.0));
    ASSERT_DOUBLE_EQ(0, m_battery.chargePercent());
}

TEST_F(BatteryTest, ChargePercentReturnsZeroWhenBatteryTwoChargeIsZero)
{
    ON_CALL(m_batteryCellOne, chargePercent()).WillByDefault(Return(99.995));
    ON_CALL(m_batteryCellTwo, chargePercent()).WillByDefault(Return(0));
    ASSERT_DOUBLE_EQ(0, m_battery.chargePercent());
}

TEST_F(BatteryTest, EmitsChargePercentChangedWhenCellOneEmitsChargePercentChanged)
{
    QSignalSpy spy(&m_battery, SIGNAL(chargePercentChanged()));
    emit m_batteryCellOne.chargePercentChanged();
    ASSERT_EQ(1, spy.count());
}

TEST_F(BatteryTest, EmitsChargePercentChangedWhenCellTwoEmitsChargePercentChanged)
{
    QSignalSpy spy(&m_battery, SIGNAL(chargePercentChanged()));
    emit m_batteryCellTwo.chargePercentChanged();
    ASSERT_EQ(1, spy.count());
}

TEST_F(BatteryTest, ChargePercentPropertyCallsChargePercentOnCellOne)
{
    EXPECT_CALL(m_batteryCellOne, chargePercent()).Times(1);
    m_battery.property("chargePercent");
}

TEST_F(BatteryTest, ChargePercentPropertyCallsChargePercentOnCellTwo)
{
    EXPECT_CALL(m_batteryCellTwo, chargePercent()).Times(1);
    m_battery.property("chargePercent");
}

TEST_F(BatteryTest, ChargePercentPropertyReturnsAverageChargePercentOfBothCells)
{
    ON_CALL(m_batteryCellOne, chargePercent()).WillByDefault(Return(0.75));
    ON_CALL(m_batteryCellTwo, chargePercent()).WillByDefault(Return(0.25));
    ASSERT_DOUBLE_EQ(0.5, m_battery.property("chargePercent").toDouble());
}

TEST_F(BatteryTest, ChargePercentPropertyReturnsAverageChargePercentOfBothCellsWithDifferentValues)
{
    ON_CALL(m_batteryCellOne, chargePercent()).WillByDefault(Return(0.5));
    ON_CALL(m_batteryCellTwo, chargePercent()).WillByDefault(Return(1.0));
    ASSERT_DOUBLE_EQ(0.75, m_battery.property("chargePercent").toDouble());
}

TEST_F(BatteryTest, ChargePercentPropertyReturnsZeroWhenBatteryOneChargeIsZero)
{
    ON_CALL(m_batteryCellOne, chargePercent()).WillByDefault(Return(0));
    ON_CALL(m_batteryCellTwo, chargePercent()).WillByDefault(Return(55.0));
    ASSERT_DOUBLE_EQ(0, m_battery.property("chargePercent").toDouble());
}

TEST_F(BatteryTest, ChargePercentPropertyReturnsZeroWhenBatteryTwoChargeIsZero)
{
    ON_CALL(m_batteryCellOne, chargePercent()).WillByDefault(Return(99.995));
    ON_CALL(m_batteryCellTwo, chargePercent()).WillByDefault(Return(0));
    ASSERT_DOUBLE_EQ(0, m_battery.property("chargePercent").toDouble());
}

TEST_F(BatteryTest, ChargePercentPropertyNotifySignalIsChargePercentChanged)
{
    int propertyIndex = m_battery.metaObject()->indexOfProperty("chargePercent");
    QMetaProperty property = m_battery.metaObject()->property(propertyIndex);
    ASSERT_STREQ("chargePercentChanged", property.notifySignal().name().data());
}

