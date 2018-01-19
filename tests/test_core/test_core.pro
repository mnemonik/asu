include(../../_init.pri)

TEMPLATE = app

TARGET    = test_core

QT       += core
QT       -= gui
QT       += widgets

CONFIG   += console
CONFIG   -= app_bundle

SOURCES += main.cpp

CONFIG += ASU_CORE_USE
include(../../libs/core/lib/lib_core.pri)

include(../../_install.pri)
