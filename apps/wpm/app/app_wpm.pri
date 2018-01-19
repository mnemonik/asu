APP_VERSION = 1.0.0.0
APP_MAJOR_VERSION = 1
APP_MINOR_VERSION = 0
APP_PATCH_VERSION = 0
APP_BUILD_VERSION = 0
APP_ID = 3
APP_TYPE = app
APP_NAME = wpm
APP_DESC = Worker Package Manager
APP_SITE = $${ASU_SITE}app/$${APP_FILE}
APP_ICON = res/app.ico
APP_AUTHOR = Eugene Karpenko
APP_LICENSE = Apache-2.0
APP_FILE = $${TARGET}
#
QT += core
CONFIG += console
#
INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD
#
ASU_BASE_BUILD: DEFINES += ASU_BASE_EXPORT
ASU_BASE_USE: DEFINES += ASU_BASE_IMPORT
#
COMMONS.files += $${ASU_INSTALL_BINS}$${APP_NAME}.exe
INSTALLS += COMMONS
#
HEADERS += \
    $$PWD/app.h \
    $$PWD/app_gen.h \
    $$PWD/common.h \
    $$PWD/wpmapp.h \
#    $$PWD/conctrl.h \
#    $$PWD/runthread.h

SOURCES += \
    $$PWD/main.cpp \
    $$PWD/wpmapp.cpp \
#    $$PWD/conctrl.cpp \
#    $$PWD/runthread.cpp

OTHER_FILES += \
    app.json \
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
