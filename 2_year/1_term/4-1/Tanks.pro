#-------------------------------------------------
#
# Project created by QtCreator 2015-09-26T23:43:01
#
#-------------------------------------------------

QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tanks
TEMPLATE = app

CONFIG += c++11 warn_on

SOURCES += main.cpp\
        tankgamewindow.cpp \
    Avatar.cpp \
    TrajectoryImage.cpp \
    BulletImage.cpp \
    ExplosionImage.cpp \
    FramesUpdater.cpp \
    GameGraphicsItem.cpp \
    KeyControl.cpp \
    KeyManager.cpp \
    GameRules.cpp \
    AvatarImage.cpp

HEADERS  += tankgamewindow.h \
    Avatar.h \
    TrajectoryImage.h \
    BulletImage.h \
    ExplosionImage.h \
    FramesUpdater.h \
    GameGraphicsItem.h \
    AvatarControl.h \
    KeyControl.h \
    KeyManager.h \
    GameRules.h \
    AvatarImage.h

FORMS    += tankgamewindow.ui
