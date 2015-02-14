TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    stringATD.cpp \
    rabin-carp.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    stringATD.h \
    rabin-carp.h

