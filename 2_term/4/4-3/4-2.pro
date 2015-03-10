#-------------------------------------------------
#
# Project created by QtCreator 2015-03-07T22:54:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 4-2
TEMPLATE = app
CONFIG += c++11


SOURCES += main.cpp\
        calculatorUberUI.cpp \
    arrayStack.cpp \
    calculator.cpp \
    stackDouble.cpp

HEADERS  += calculatorUberUI.h \
    arrayStack.h \
    calculator.h \
    stack.h \
    stackDouble.h

FORMS    += calculatorUberUI.ui
