include(../_init.pri)
#
CONFIG += ASU_BASE_USE
include(../lib_base/lib_base.pri)
#
QT += core
CONFIG += console
CONFIG -= app_bundle
#
TEMPLATE    = app
#
TARGET      = test_base
#
SOURCES += main.cpp
#
include(../_install.pri)
#
