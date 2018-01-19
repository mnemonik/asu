include(../../../_init.pri)
#
CONFIG += ASU_BASE_USE
include(../../../libs/base/lib/lib_base.pri)

CONFIG += ASU_CORE_USE
include(../../../libs/core/lib/lib_core.pri)
#
QT += core
CONFIG += console
CONFIG -= app_bundle
#
TEMPLATE    = app
#
TARGET      = wpm
#
HEADERS += \
    $$PWD/app.h \
    $$PWD/app_gen.h \
    $$PWD/common.h \
    $$PWD/wpmapp.h \
    $$PWD/conctrl.h \
    $$PWD/runthread.h

SOURCES += \
    $$PWD/main.cpp \
    $$PWD/wpmapp.cpp \
    $$PWD/conctrl.cpp \
    $$PWD/runthread.cpp

OTHER_FILES += \
    wpm.json \
    readme.md

FORMS    += \

RESOURCES += \
    res.qrc

windows: {
    RC_FILE += res.rc
    OTHER_FILES += res.rc
}

TRANSLATIONS = lang/ru lang/en
#
include(../../../_install.pri)
#
