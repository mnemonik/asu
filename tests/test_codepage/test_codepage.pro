include(../../_init.pri)

TEMPLATE = app

TARGET = test_codepage

QT       += core
QT       -= gui

CONFIG   += console
CONFIG   -= app_bundle

SOURCES += main.cpp

include(../../_install.pri)
