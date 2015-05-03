#-------------------------------------------------
#
# Project created by QtCreator 2015-04-30T23:25:08
#
#-------------------------------------------------

QT       += core

QT       -= gui

QT       += testlib

TARGET = 7-2
CONFIG   += console c++11
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    list.cpp \
    listunique.cpp \
    addExistedElementException.cpp \
    deleteNonExistedElementException.cpp \
    outOfIndexes.cpp

HEADERS += \
    list.h \
    listunique.h \
    outofindexes.h \
    testlistunique.h \
    addExistedElementException.h \
    deleteNonExistedElementException.h
