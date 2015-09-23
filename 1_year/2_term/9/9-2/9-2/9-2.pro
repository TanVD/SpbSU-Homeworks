#-------------------------------------------------
#
# Project created by QtCreator 2015-05-24T23:49:28
#
#-------------------------------------------------

QT       += core gui network

QT       += xml webkit

QT       += webkitwidgets


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 9-2
TEMPLATE = app


SOURCES += main.cpp\
        uiBash.cpp \
    bashAsker.cpp \
    parseCitations.cpp

HEADERS  += uiBash.h \
    bashAsker.h \
    parseCitations.h

FORMS    += uiBash.ui
