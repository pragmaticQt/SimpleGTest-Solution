TEMPLATE = lib

CONFIG += c++11
CONFIG -= debug_and_release

TARGET = ApplicationLib

DEFINES += APPLICATIONLIB_LIBRARY

HEADERS += \
    ApplicationLibDecl.h \
    Battery.h \
    BatteryCell.h \
    GpioInput.h \
    Spi.h \
    IBattery.h \
    IBatteryCell.h \
    IGpioInput.h \
    ISpi.h \
    DivideExample.h


SOURCES += \
    Battery.cpp \
    BatteryCell.cpp \
    GpioInput.cpp \
    Spi.cpp \
    DivideExample.cpp
