TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    stackdouble.cpp \
    postcalculate.cpp \
    inftopostform.cpp

HEADERS += \
    stackdouble.h \
    postcalculate.h \
    inftopostform.h

QMAKE_CXXFLAGS += -std=c++11
