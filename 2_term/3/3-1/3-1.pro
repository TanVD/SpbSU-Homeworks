TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    bubbleSort.cpp \
    quickSort.cpp \
    sortinterface.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    sortInterface.h \
    bubbleSort.h \
    quickSort.h \
    sortinterface.h

