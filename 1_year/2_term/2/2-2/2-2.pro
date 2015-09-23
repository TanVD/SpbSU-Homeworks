#-------------------------------------------------
#
# Project created by QtCreator 2015-03-14T21:01:11
#
#-------------------------------------------------

QT       += core

QT       -= gui

QT       += testlib


TARGET = 2-2
CONFIG   += console c++11
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    arrayStack.cpp \
    calculator.cpp \
    stackDouble.cpp

HEADERS += \
    arrayStack.h \
    calculator.h \
    stack.h \
    stackDouble.h \
    testStack.h \
    testCalc.h
