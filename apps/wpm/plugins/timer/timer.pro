include(../../../../_init.pri)
#
CONFIG += ASU_BASE_BUILD
include(../../../../libs/base/lib/lib_base.pri)
#
CONFIG += ASU_CORE_BUILD
include(../../../../libs/core/lib/lib_core.pri)
#
TEMPLATE = lib
#
TARGET = timer
#
CONFIG += qt
CONFIG += plugin
QT += core
#
DEFINES += TIMER_LIBRARY
#
SOURCES += \
    timer.cpp
#
HEADERS += \
    timer.h \
    timer_global.h
#
include(../../../../_install.pri)
#
