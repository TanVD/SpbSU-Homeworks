#-------------------------------------------------
#
# Project created by QtCreator 2015-05-15T21:16:02
#
#-------------------------------------------------

QT       += core gui network testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 9-1Client
TEMPLATE = app


SOURCES += main.cpp\
        myclient.cpp \
    transmissionCoder.cpp

HEADERS  += myclient.h \
    transmissionCoder.h \
    unreliableTransmission.h

FORMS    += myclient.ui
