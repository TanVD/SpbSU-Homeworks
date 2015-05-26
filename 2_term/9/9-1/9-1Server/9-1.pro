#-------------------------------------------------
#
# Project created by QtCreator 2015-05-15T20:38:56
#
#-------------------------------------------------

QT       += core gui network testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 9-1
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
        myserver.cpp \
    ../transmissionCoder.cpp

HEADERS  += myserver.h \
    ../transmissionCoder.h \
    unreliableTransmission.h \

FORMS    += myserver.ui
