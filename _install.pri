#
contains($$list($$[QT_VERSION]), 5.5.*) {
    COMMONS.files += \
        $$[QT_INSTALL_BINS]/libgcc_s_dw2-1.dll \
        $$[QT_INSTALL_BINS]/libwinpthread-1.dll \
        $$[QT_INSTALL_BINS]/libstdc++-6.dll \
        $$[QT_INSTALL_BINS]/icuin54.dll \
        $$[QT_INSTALL_BINS]/icuuc54.dll \
        $$[QT_INSTALL_BINS]/icudt54.dll
}
contains($$list($$[QT_VERSION]), 5.4.*) {
    COMMONS.files += \
        $$[QT_INSTALL_BINS]/libgcc_s_dw2-1.dll \
        $$[QT_INSTALL_BINS]/libwinpthread-1.dll \
        $$[QT_INSTALL_BINS]/libstdc++-6.dll \
        $$[QT_INSTALL_BINS]/icuin53.dll \
        $$[QT_INSTALL_BINS]/icuuc53.dll \
        $$[QT_INSTALL_BINS]/icudt53.dll
}
contains($$list($$[QT_VERSION]), 5.3.*) {
    COMMONS.files += \
        $$[QT_INSTALL_BINS]/libgcc_s_dw2-1.dll \
        $$[QT_INSTALL_BINS]/libwinpthread-1.dll \
        $$[QT_INSTALL_BINS]/libstdc++-6.dll \
        $$[QT_INSTALL_BINS]/icuin52.dll \
        $$[QT_INSTALL_BINS]/icuuc52.dll \
        $$[QT_INSTALL_BINS]/icudt52.dll
}
contains($$list($$[QT_VERSION]), 5.3.*) {
    COMMONS.files += \
        $$[QT_INSTALL_BINS]/libgcc_s_dw2-1.dll \
        $$[QT_INSTALL_BINS]/libwinpthread-1.dll \
        $$[QT_INSTALL_BINS]/libstdc++-6.dll
}
#
contains($$list($$[QT_VERSION]), 5.*.*) {
    contains(QT, core): {
        CONFIG(debug): COMMONS.files += $$[QT_INSTALL_BINS]/Qt5Cored.dll
        CONFIG(release): COMMONS.files += $$[QT_INSTALL_BINS]/Qt5Core.dll
    }
    contains(QT, gui): {
        CONFIG(debug): COMMONS.files += $$[QT_INSTALL_BINS]/Qt5Guid.dll
        CONFIG(release): COMMONS.files += $$[QT_INSTALL_BINS]/Qt5Gui.dll
    }
    contains(QT, widgets): {
        CONFIG(debug): COMMONS.files += $$[QT_INSTALL_BINS]/Qt5Widgetsd.dll
        CONFIG(release): COMMONS.files += $$[QT_INSTALL_BINS]/Qt5Widgets.dll
    }
    contains(QT, network): {
        CONFIG(debug): COMMONS.files += $$[QT_INSTALL_BINS]/Qt5Networkd.dll
        CONFIG(release): COMMONS.files += $$[QT_INSTALL_BINS]/Qt5Network.dll
    }
    contains(QT, sql): {
        CONFIG(debug): COMMONS.files += $$[QT_INSTALL_BINS]/Qt5Sqld.dll
        CONFIG(release): COMMONS.files += $$[QT_INSTALL_BINS]/Qt5Sql.dll
    }
    contains(QT, xml): {
        CONFIG(debug): COMMONS.files += $$[QT_INSTALL_BINS]/Qt5Xmld.dll
        CONFIG(release): COMMONS.files += $$[QT_INSTALL_BINS]/Qt5Xml.dll
    }
}
#
contains($$list($$[QT_VERSION]), 4.*.*) {
    contains(QT, core): {
        CONFIG(debug): COMMONS.files += $$[QT_INSTALL_BINS]/QtCored4.dll
        CONFIG(release): COMMONS.files += $$[QT_INSTALL_BINS]/QtCore4.dll
    }
    contains(QT, gui): {
        CONFIG(debug): COMMONS.files += $$[QT_INSTALL_BINS]/QtGuid4.dll
        CONFIG(release): COMMONS.files += $$[QT_INSTALL_BINS]/QtGui4.dll
    }
    contains(QT, network): {
        CONFIG(debug): COMMONS.files += $$[QT_INSTALL_BINS]/QtNetworkd4.dll
        CONFIG(release): COMMONS.files += $$[QT_INSTALL_BINS]/QtNetwork4.dll
    }
    contains(QT, sql): {
        CONFIG(debug): COMMONS.files += $$[QT_INSTALL_BINS]/QtSqld4.dll
        CONFIG(release): COMMONS.files += $$[QT_INSTALL_BINS]/QtSql4.dll
    }
    contains(QT, xml): {
        CONFIG(debug): COMMONS.files += $$[QT_INSTALL_BINS]/QtXmld4.dll
        CONFIG(release): COMMONS.files += $$[QT_INSTALL_BINS]/QtXml4.dll
    }
}
#
COMMONS.path = $${DLLDESTDIR}
#COMMONS.path ~= s,/,\\,g
#
for(FILE, COMMONS.files){
    FILE ~= s,/,\\,g
    QMAKE_POST_LINK += $${QMAKE_COPY} \"$${FILE}\" \"$${COMMONS.path}\" $$escape_expand(\\n\\t)
}
INSTALLS += COMMONS
#
