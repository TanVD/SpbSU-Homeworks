TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    list.cpp

HEADERS += \
    list.h
QMAKE_CXXFLAGS += -std=c++11
