#-------------------------------------------------
#
# Project created by QtCreator 2014-12-04T16:53:31
#
#-------------------------------------------------

QT       -= core gui

TARGET = test_dll
TEMPLATE = lib

DEFINES += TEST_DLL_LIBRARY

SOURCES += test_dll.cpp

HEADERS += test_dll.h\
        test_dll_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
