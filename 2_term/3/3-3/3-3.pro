TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    linkedList.cpp \
    sortedSet.cpp

include(deployment.pri)

HEADERS += \
    linkedList.h \
    sortedSet.h \
    IComparable.h

