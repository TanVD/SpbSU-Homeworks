TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt
QT     += testlib

SOURCES += main.cpp \
    BST.cpp \
    set.cpp

HEADERS += \
    BST.h \
    settest.h \
    set.h

