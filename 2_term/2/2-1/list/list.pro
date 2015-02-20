TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    linkedList.cpp \
    doubleLinkedList.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    list.h \
    linkedList.h \
    doubleLinkedList.h

