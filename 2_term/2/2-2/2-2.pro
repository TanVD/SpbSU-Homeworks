TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    infToPostForm.cpp \
    postCalculate.cpp \
    stackDouble.cpp \
    arrayStack.cpp \
    calculator.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    infToPostForm.h \
    postCalculate.h \
    stackDouble.h \
    stack.h \
    arrayStack.h \
    calculator.h

