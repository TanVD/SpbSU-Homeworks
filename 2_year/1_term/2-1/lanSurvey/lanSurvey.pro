QT += core
QT -= gui

TARGET = lanSurvey
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Computer.cpp \
    ComputerList.cpp \
    LanNetwork.cpp \
    OS.cpp \
    RandomGenerator.cpp

HEADERS += \
    RandomGenerator.h \
    OS.h \
    LanNetwork.h \
    ComputerList.h \
    Computer.h

