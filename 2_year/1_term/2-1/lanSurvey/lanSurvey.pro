QT += core testlib
QT -= gui

TARGET = lanSurvey
CONFIG += console с++11

CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Computer.cpp \
    LanNetwork.cpp \
    OS.cpp \
    RandomGenerator.cpp \
    VirusModel.cpp

HEADERS += \
    RandomGenerator.h \
    OS.h \
    LanNetwork.h \
    Computer.h \
    VirusModel.h \
    virusmodeltests.h

