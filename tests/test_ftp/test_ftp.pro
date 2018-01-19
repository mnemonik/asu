include(../../_init.pri)

TEMPLATE = app

TARGET = test_ftp

QT       += core widgets
QT       -= gui

CONFIG   += console
CONFIG   -= app_bundle

SOURCES += main.cpp

include(../../_install.pri)
