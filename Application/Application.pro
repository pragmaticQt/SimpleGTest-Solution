TEMPLATE = app
QT += core gui
CONFIG += c++11

TARGET = Application

INCLUDEPATH += ../ApplicationLib
LIBS += -L../ApplicationLib -lApplicationLib

SOURCES += main.cpp
