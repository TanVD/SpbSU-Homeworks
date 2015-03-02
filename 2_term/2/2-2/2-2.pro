TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    stackDouble.cpp \
    arrayStack.cpp \
    calculator.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    stackDouble.h \
    stack.h \
    arrayStack.h \
    calculator.h

