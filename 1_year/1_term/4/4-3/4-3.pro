TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    stackdouble.cpp \
    postcalculate.cpp

HEADERS += \
    stackdouble.h \
    postcalculate.h

QMAKE_CXXFLAGS += -std=c++11
