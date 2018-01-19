ASU_BASE_VERSION = 1.0.0.0
ASU_BASE_MAJOR_VERSION = 1
ASU_BASE_MINOR_VERSION = 0
ASU_BASE_PATCH_VERSION = 0
ASU_BASE_BUILD_VERSION = 0
ASU_BASE_ID = 0
ASU_BASE_FILE = Base
ASU_BASE_DESC = Base library
ASU_BASE_SITE = $${ASU_SITE}app/$${ASU_BASE_FILE}
ASU_BASE_ICON = res/app.ico
ASU_BASE_NAME = $${ASU_PRODUCT}$${ASU_MAJOR_VERSION}$${ASU_BASE_FILE}$${ASU_BASE_MAJOR_VERSION}
CONFIG(debug): ASU_BASE_NAME = $${ASU_BASE_NAME}D
#
QT += core network
#
INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD
#
ASU_BASE_BUILD: DEFINES += ASU_BASE_EXPORT
ASU_BASE_USE: DEFINES += ASU_BASE_IMPORT
#
ASU_BASE_USE:!ASU_BASE_BUILD: {
    LIBS += -L$${ASU_INSTALL_BINS} -l$${ASU_BASE_NAME}
    COMMONS.files += $${ASU_INSTALL_BINS}$${ASU_BASE_NAME}.dll
} else {
    HEADERS += $$PWD/define.h
    HEADERS += $$PWD/app.h
    HEADERS += $$PWD/apps.h
    HEADERS += $$PWD/app_gen.h
    HEADERS += $$PWD/lib_base.h
    HEADERS += $$PWD/config.h
    SOURCES += $$PWD/config.cpp
    HEADERS += $$PWD/logger.h
    SOURCES += $$PWD/logger.cpp
    HEADERS += $$PWD/logger_ts.h
    SOURCES += $$PWD/logger_ts.cpp
    HEADERS += $$PWD/global.h
    SOURCES += $$PWD/global.cpp
    HEADERS += $$PWD/resources.h
    SOURCES += $$PWD/resources.cpp

    RESOURCES += $$PWD/lib_base.qrc

    windows: {
        RC_FILE += $$PWD/lib_base.rc
        OTHER_FILES += $$PWD/lib_base.rc
    }

}
#
windows: {
    ASU_BASE_BUILD:shared:DEFINES += ASU_BASE_EXPORT
    else:ASU_BASE_USE:DEFINES += ASU_BASE_IMPORT
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
write("$${LITERAL_HASH}define APP_ID $${ASU_BASE_ID}", >>, $${FILEDEF})
write("$${LITERAL_HASH}define APP_DIR $${QUOTES}$${ASU_BASE_NAME}$${QUOTES}", >>, $${FILEDEF})
write("$${LITERAL_HASH}define APP_FILE $${QUOTES}$${ASU_BASE_NAME}$${QUOTES}", >>, $${FILEDEF})
write("$${LITERAL_HASH}define APP_NAME $${QUOTES}$${ASU_BASE_NAME}$${QUOTES}", >>, $${FILEDEF})
write("$${LITERAL_HASH}define APP_DESC $${QUOTES}$${ASU_BASE_DESC}$${QUOTES}", >>, $${FILEDEF})
write("$${LITERAL_HASH}define APP_SITE $${QUOTES}$${ASU_BASE_SITE}$${QUOTES}", >>, $${FILEDEF})
write("$${LITERAL_HASH}define APP_COPYRIGHT $${QUOTES}$${ASU_COMPANY}$${QUOTES}", >>, $${FILEDEF})
write("$${LITERAL_HASH}define APP_VERSION $${QUOTES}$${ASU_BASE_VERSION}$${QUOTES}", >>, $${FILEDEF})
write("$${LITERAL_HASH}define APP_MAJOR_VERSION $${ASU_BASE_MAJOR_VERSION}", >>, $${FILEDEF})
write("$${LITERAL_HASH}define APP_MINOR_VERSION $${ASU_BASE_MINOR_VERSION}", >>, $${FILEDEF})
write("$${LITERAL_HASH}define APP_PATCH_VERSION $${ASU_BASE_PATCH_VERSION}", >>, $${FILEDEF})
write("$${LITERAL_HASH}define APP_BUILD_VERSION $${ASU_BASE_BUILD_VERSION}", >>, $${FILEDEF})
write("$${LITERAL_HASH}define APP_PICT $${QUOTES}$${ASU_BASE_ICON}$${QUOTES}", >>, $${FILEDEF})
write("//", >>, $${FILEDEF})
write("$${LITERAL_HASH}endif // APP_GEN_H", >>, $${FILEDEF})
#
