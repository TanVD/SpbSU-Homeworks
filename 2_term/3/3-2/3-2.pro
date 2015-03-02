TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    consoleOut.cpp \
    fileOut.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    consoleOut.h \
    outputInterface.h \
    fileOut.h

