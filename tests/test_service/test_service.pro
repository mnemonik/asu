include(../../_init.pri)

TEMPLATE = app

TARGET = test_service

QT       += core
QT       -= gui

CONFIG   += console
CONFIG   -= app_bundle

HEADERS += \
    httpservice.h \
    httpdaemon.h

SOURCES += main.cpp \
    httpservice.cpp \
    httpdaemon.cpp

DEFINES += QTSERVICE_LIBRARY

LIBS += -L$${Z}/libs -lqtservice

win32:QT += network
win32:LIBS += -luser32

include(../../_install.pri)



DESTDIR = $${Z}
