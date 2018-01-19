include(../../_init.pri)

TEMPLATE = app

TARGET = test_consolegui

QT       += core
QT       -= gui
QT       += widgets

CONFIG   += console
CONFIG   -= app_bundle

SOURCES += main.cpp

include(../../_install.pri)
