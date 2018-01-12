#include(../../_init.pri)
#include(_app.pri)
#
QMAKE_CXXFLAGS += -std=gnu++11

CONFIG  += console
CONFIG  -= app_bundle

QT  += core

TEMPLATE = app

TARGET = $${APP.file}

DEFINES +=

INCLUDEPATH += $$PWD

DEPENDPATH += $$PWD

HEADERS += $$PWD/app_gen.h $$PWD/app.h

SOURCES += $$PWD/main.cpp

OTHER_FILES += \

FORMS    += \

RESOURCES += \
    res.qrc

windows: {
    RC_FILE += res.rc
    OTHER_FILES += res.rc
}

TRANSLATIONS = lang/ru lang/en
#
#CONFIG += asu_core_use
#include(../asu_core/src/asu_core.pri)
#CONFIG += asu_updater_use
#include(../asu_updater/src/asu_updater.pri)
#CONFIG += asu_uniqueapp_use
#include(../asu_uniqueapp/src/asu_uniqueapp.pri)
#
#DLLDESTDIR = $${Z}$${APP.file}
#
#include(../../_install.pri)
#
#BUILDS.files += $${PWD}/res/app.png
#
#BUILDS.path = $${DLLDESTDIR}
#BUILDS.path ~= s,/,\\,g
#for(FILE, BUILDS.files){
#        FILE ~= s,/,\\,g
#        QMAKE_POST_LINK += $${QMAKE_COPY} \"$${FILE}\" \"$${BUILDS.path}\" $$escape_expand(\\n\\t)
#}
#INSTALLS += BUILDS
#
#include(../_xml.pri)
#
