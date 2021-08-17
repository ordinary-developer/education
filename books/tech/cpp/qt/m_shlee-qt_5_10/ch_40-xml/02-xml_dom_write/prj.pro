TEMPLATE = app
TARGET = prj
INCLUDEPATH += .
CONFIG += console debug
QT += xml
QMAKE_CXXFLAGS += -std=c++17 -Wall -Wextra -pedantic

DEFINES += QT_DEPRECATED_WARNINGS

# Input
SOURCES += main.cpp