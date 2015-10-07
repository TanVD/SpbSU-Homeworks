#-------------------------------------------------
#
# Project created by QtCreator 2015-09-26T23:43:01
#
#-------------------------------------------------

QT += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tanks
TEMPLATE = app

CONFIG += c++11 warn_on

SOURCES += main.cpp\
        tankgamewindow.cpp \
    Avatar/Avatar.cpp \
    GameGraphics/AvatarImage\/TrajectoryImage.cpp \
    GameGraphics/Explosion/ExplosionImage.cpp \
    FramesUpdater/FramesUpdater.cpp \
    GameGraphics/GameGraphicsItem.cpp \
    Controls/KeyControls/KeyControl.cpp \
    Controls/KeyControls/KeyManager.cpp \
    Rules/GameRules.cpp \
    GameGraphics/AvatarImage/AvatarImage.cpp \
    GameGraphics/Ground/GroundImage.cpp \
    GameGraphics/Bullets/BulletGeneral.cpp \
    GameGraphics/Bullets/Bullet50.cpp \
    GameGraphics/Bullets/Bullet20.cpp \
    Controls/NetworkControls/NetworkControl.cpp \
    Network/Transmission/TransmissionCoder.cpp \
    Network/Server/ServerNetwork.cpp \
    Network/Client/ClientNetwork.cpp \
    Network/networkinterface.cpp

HEADERS  += tankgamewindow.h \
    Avatar/Avatar.h \
    GameGraphics/AvatarImage/TrajectoryImage.h \
    GameGraphics/Explosion/ExplosionImage.h \
    FramesUpdater/FramesUpdater.h \
    GameGraphics/GameGraphicsItem.h \
    Controls/AvatarControl.h \
    Controls/KeyControls/KeyControl.h \
    Controls/KeyControls/KeyManager.h \
    Rules/GameRules.h \
    GameGraphics/AvatarImage/AvatarImage.h \
    GameGraphics/Ground/GroundImage.h \
    GameGraphics/Bullets/BulletGeneral.h \
    GameGraphics/Bullets/Bullet50.h \
    GameGraphics/Bullets/Bullet20.h \
    Controls/NetworkControls/NetworkControl.h \
    Network/Transmission/TransmissionCoder.h \
    Network/Transmission/unreliabletransmission.h \
    Network/Server/ServerNetwork.h \
    Network/Client/ClientNetwork.h \
    Network/networkinterface.h

FORMS    += tankgamewindow.ui

INCLUDEPATH += Avatar \
Controls\
Controls/KeyControls\
FramesUpdater\
GameGraphics\
GameGraphics/AvatarImage\
GameGraphics/Bullets\
GameGraphics/Explosion\
GameGraphics/Ground\
Rules\
Controls/NetworkControls\
Network/Transmission\
Network/Client\
Network/Server\
Network

