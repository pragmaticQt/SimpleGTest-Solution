TEMPLATE = app

QT += testlib #Include QtTest to use SignalSpy, QTest::mouseClick, etc

CONFIG += testcase #Creates 'check' target in Makefile.
CONFIG += c++11
CONFIG -= debug_and_release
CONFIG += console

TARGET = Tests

INCLUDEPATH += ../ApplicationLib
LIBS += -L../ApplicationLib -lApplicationLib

include(../GoogleTest/GoogleTest.pri)

HEADERS += \
    QtTypePrinters.h \
    Mocks/MockBatteryCell.h

SOURCES += main.cpp \
    BatteryTest.cpp \
    DivideExampleTest.cpp \
    QStringTest.cpp
