include(../../_init.pri)

TEMPLATE = app

TARGET = test_codepage

CONFIG += console
CONFIG += qt
QT     += core


SOURCES += main.cpp

message($${CONFIG})

include(../../_install.pri)
