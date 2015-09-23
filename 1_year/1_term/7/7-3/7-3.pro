TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    list.cpp \
    stringATD.cpp \
    hashTab.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    list.h \
    stringATD.h \
    hashTab.h

