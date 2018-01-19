include(../../../_init.pri)
#
CONFIG += ASU_BASE_USE
include(../../../libs/base/lib/lib_base.pri)
#
CONFIG += ASU_CORE_BUILD
include(../../../libs/core/lib/lib_core.pri)
#
TEMPLATE    = lib
#
DEFINES += SERVICE_LIBRARY
TARGET = service
#
HEADERS += \
        service.h \
        service_global.h \

SOURCES += \

windows:SOURCES += \
    service_win.cpp \

#unix:SOURCES += \
#    service_unix.cpp \

include(../../../_install.pri)
