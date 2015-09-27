#-------------------------------------------------
#
# Project created by QtCreator 2015-09-26T23:43:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tanks
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        tankgamewindow.cpp \
    KeyManager.cpp \
    Avatar.cpp \
    TrajectoryImage.cpp \
    BulletImage.cpp

HEADERS  += tankgamewindow.h \
    KeyManager.h \
    Avatar.h \
    TrajectoryImage.h \
    BulletImage.h

FORMS    += tankgamewindow.ui
