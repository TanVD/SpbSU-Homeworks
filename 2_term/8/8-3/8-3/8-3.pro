#-------------------------------------------------
#
# Project created by QtCreator 2015-05-13T20:43:57
#
#-------------------------------------------------

QT       += core gui testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 8-3
TEMPLATE = app
CONFIG += c++11


SOURCES += main.cpp\
        ticTacToeUI.cpp \
    modelTicTacToe.cpp

HEADERS  += ticTacToeUI.h \
    modelTicTacToe.h \
    tictactoetest.h

FORMS    += ticTacToeUI.ui
