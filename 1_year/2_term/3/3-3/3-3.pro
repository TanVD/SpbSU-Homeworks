#-------------------------------------------------
#
# Project created by QtCreator 2015-03-14T22:24:16
#
#-------------------------------------------------

QT       += core

QT       -= gui

QT      += testlib

TARGET = 3-3
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += c++11

TEMPLATE = app

SOURCES += main.cpp \
    linkedList.cpp \
    sortedSet.cpp

HEADERS += \
    IComparable.h \
    linkedList.h \
    sortedSet.h \
    testsortedset.h
