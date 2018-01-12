include(../_init.pri)
#
CONFIG += ASU_CORE_USE
include(../lib_core/lib_core.pri)
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
