#-------------------------------------------------
#
# Project created by QtCreator 2015-03-14T00:12:29
#
#-------------------------------------------------

QT       += core gui
QT       += testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 5-1
TEMPLATE = app


SOURCES += main.cpp\
        hashtableui.cpp \
    linkedList.cpp \
    hashTable.cpp
CONFIG += c++11

HEADERS  += hashtableui.h \
    linkedList.h \
    hashTable.h \
    hashtabletest.h

FORMS    += hashtableui.ui
