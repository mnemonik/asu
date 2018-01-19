#-------------------------------------------------
#
# Project created by QtCreator 2014-12-04T16:55:15
#
#-------------------------------------------------

QT       -= core gui

TARGET = test_static_dll
TEMPLATE = lib
CONFIG += staticlib

SOURCES += x.cpp

HEADERS += x.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
