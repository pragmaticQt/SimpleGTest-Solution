#include <QCoreApplication>

#include "Battery.h"
#include "BatteryCell.h"
#include "GpioInput.h"
#include "Spi.h"

#include <QDebug>
#include <QGuiApplication>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // Build production system via dependancy injection

    GpioInput batteryOneChargingLine;
    Spi batteryOneInfoSpi;
    BatteryCell batteryCellOne(batteryOneChargingLine, batteryOneInfoSpi);

    GpioInput batteryTwoChargingLine;
    Spi batteryTwoInfoSpi;
    BatteryCell batteryCellTwo(batteryTwoChargingLine, batteryTwoInfoSpi);

    Battery battery(batteryCellOne, batteryCellTwo);

    /* Presentation and Visualization Layers need to be built here */

    qDebug() << "Stack is built";
    return 0;
}
