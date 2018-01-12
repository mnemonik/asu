ASU_CORE_VERSION = 1.0.0
ASU_CORE_MAJOR_VERSION = 1
ASU_CORE_MINOR_VERSION = 0
ASU_CORE_PATCH_VERSION = 0
ASU_CORE_BUILD_VERSION = 0
ASU_CORE_ID = 0
ASU_CORE_FILE = Core
ASU_CORE_DESC = Core library
ASU_CORE_SITE = $${ASU_SITE}app/$${ASU_CORE_FILE}
ASU_CORE_ICON = res/app.ico
ASU_CORE_NAME = $${ASU_PRODUCT}$${ASU_MAJOR_VERSION}$${ASU_CORE_FILE}$${ASU_CORE_MAJOR_VERSION}
CONFIG(debug): ASU_CORE_NAME = $${ASU_CORE_NAME}D
#
QT += core network
#
INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD
#
ASU_CORE_BUILD: DEFINES += ASU_CORE_EXPORT
ASU_CORE_USE: DEFINES += ASU_CORE_IMPORT
#
ASU_CORE_USE:!ASU_CORE_BUILD: {
    LIBS += -L$${ASU_INSTALL_BINS} -l$${ASU_CORE_NAME}
    COMMONS.files += $${ASU_INSTALL_BINS}$${ASU_CORE_NAME}.dll
} else {
    HEADERS += $$PWD/app.h
    HEADERS += $$PWD/apps.h
    HEADERS += $$PWD/app_gen.h
    HEADERS += $$PWD/lib_core.h
    HEADERS += $$PWD/session.h
    SOURCES += $$PWD/session.cpp
    HEADERS += $$PWD/cookie.h
    SOURCES += $$PWD/cookie.cpp
    HEADERS += $$PWD/core.h
    SOURCES += $$PWD/core.cpp
    HEADERS += $$PWD/plugin.h
    HEADERS += $$PWD/wpmsession.h
    SOURCES += $$PWD/wpmsession.cpp

    RESOURCES += $$PWD/lib_core.qrc

    windows: {
        RC_FILE += $$PWD/lib_core.rc
        OTHER_FILES += $$PWD/lib_core.rc
    }
}
#
windows: {
    ASU_CORE_BUILD:shared:DEFINES += ASU_CORE_EXPORT
    else:ASU_CORE_USE:DEFINES += ASU_CORE_IMPORT
}
#
FILEDEF = app_gen.h
#
windows: QUOTES=\"
else: QUOTES=\\\"
#
system(chcp 65001)
write("$${LITERAL_HASH}ifndef APP_GEN_H", >, $${FILEDEF})
write("$${LITERAL_HASH}define APP_GEN_H", >>, $${FILEDEF})
write("//", >>, $${FILEDEF})
write("$${LITERAL_HASH}define ORG_NAME $${QUOTES}$${ASU_PRODUCT}$${QUOTES}", >>, $${FILEDEF})
write("$${LITERAL_HASH}define ORG_SITE $${QUOTES}$${ASU_SITE}$${QUOTES}", >>, $${FILEDEF})
write("$${LITERAL_HASH}define APP_ID $${ASU_CORE_ID}", >>, $${FILEDEF})
write("$${LITERAL_HASH}define APP_DIR $${QUOTES}$${ASU_CORE_NAME}$${QUOTES}", >>, $${FILEDEF})
write("$${LITERAL_HASH}define APP_FILE $${QUOTES}$${ASU_CORE_NAME}$${QUOTES}", >>, $${FILEDEF})
write("$${LITERAL_HASH}define APP_NAME $${QUOTES}$${ASU_CORE_NAME}$${QUOTES}", >>, $${FILEDEF})
write("$${LITERAL_HASH}define APP_DESC $${QUOTES}$${ASU_CORE_DESC}$${QUOTES}", >>, $${FILEDEF})
write("$${LITERAL_HASH}define APP_SITE $${QUOTES}$${ASU_CORE_SITE}$${QUOTES}", >>, $${FILEDEF})
write("$${LITERAL_HASH}define APP_COPYRIGHT $${QUOTES}$${ASU_COMPANY}$${QUOTES}", >>, $${FILEDEF})
write("$${LITERAL_HASH}define APP_VERSION $${QUOTES}$${ASU_CORE_VERSION}$${QUOTES}", >>, $${FILEDEF})
write("$${LITERAL_HASH}define APP_MAJOR_VERSION $${ASU_CORE_MAJOR_VERSION}", >>, $${FILEDEF})
write("$${LITERAL_HASH}define APP_MINOR_VERSION $${ASU_CORE_MINOR_VERSION}", >>, $${FILEDEF})
write("$${LITERAL_HASH}define APP_PATCH_VERSION $${ASU_CORE_PATCH_VERSION}", >>, $${FILEDEF})
write("$${LITERAL_HASH}define APP_BUILD_VERSION $${ASU_CORE_BUILD_VERSION}", >>, $${FILEDEF})
write("$${LITERAL_HASH}define APP_PICT $${QUOTES}$${ASU_CORE_ICON}$${QUOTES}", >>, $${FILEDEF})
write("//", >>, $${FILEDEF})
write("$${LITERAL_HASH}endif // APP_GEN_H", >>, $${FILEDEF})
#
