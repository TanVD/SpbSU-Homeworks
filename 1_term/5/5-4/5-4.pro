TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    phonebaselist.cpp

HEADERS += \
    phonebaselist.h
QMAKE_CXXFLAGS += -std=c++11
