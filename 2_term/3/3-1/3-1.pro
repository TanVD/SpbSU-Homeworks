#-------------------------------------------------
#
# Project created by QtCreator 2015-03-14T21:35:31
#
#-------------------------------------------------

QT       += core

QT       -= gui

QT       += testlib

TARGET = 3-1
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    bubbleSort.cpp \
    quickSort.cpp \
    sortinterface.cpp

HEADERS += \
    bubbleSort.h \
    quickSort.h \
    sortInterface.h \
    testSort.h
