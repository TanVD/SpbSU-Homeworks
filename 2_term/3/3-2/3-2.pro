TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    consoleOut.cpp \
    fileOut.cpp \
    matrix.cpp \
    outputInterface.cpp

HEADERS += \
    consoleOut.h \
    outputInterface.h \
    fileOut.h \
    matrix.h

