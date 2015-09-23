#-------------------------------------------------
#
# Project created by QtCreator 2015-03-14T22:24:16
#
#-------------------------------------------------

QT       += core

QT       -= gui

QT      += testlib

TARGET = 3-2
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += c++11

TEMPLATE = app

SOURCES += main.cpp \
    consoleOut.cpp \
    fileOut.cpp \
    matrix.cpp \
    outputInterface.cpp

HEADERS += \
    consoleOut.h \
    outputInterface.h \
    fileOut.h \
    matrix.h \
    testBypassMatrix.h

