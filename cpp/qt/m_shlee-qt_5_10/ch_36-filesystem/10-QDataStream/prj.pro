TEMPLATE = app
TARGET = prj
INCLUDEPATH += .
CONFIG += console debug
QT += core widgets testlib

QMAKE_CXXFLAGS += -std=c++17 -Wall -Wextra -pedantic

SOURCES += main.cpp 
RESOURCES += res.qrc
