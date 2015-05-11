TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt
QT     += testlib

SOURCES += main.cpp \
    BST.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    BST.h \
    settest.h

