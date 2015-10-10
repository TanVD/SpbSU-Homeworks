QT += core testlib
QT -= gui

TARGET = lanSurvey
CONFIG += console с++11

CONFIG -= app_bundle
CONFIG += warn_on c++11

TEMPLATE = app

SOURCES += main.cpp \
    Computer.cpp \
    LanNetwork.cpp \
    VirusModel.cpp \
    OSMac.cpp \
    OSWindows.cpp \
    OSLinux.cpp \
    OSSwitcher.cpp \
    RandomGeneratorFake.cpp \
    RandomGenerator.cpp

HEADERS += \
    RandomGenerator.h \
    OS.h \
    LanNetwork.h \
    Computer.h \
    VirusModel.h \
    VirusModelTests.h \
    OSMac.h \
    OSWindows.h \
    OSLinux.h \
    OSSwitcher.h \
    RandomGeneratorFake.h \
    RandomGeneratorInterface.h

