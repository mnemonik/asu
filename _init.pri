#
ROOT = $${PWD}
#
ASU_PRODUCT = Asu
ASU_SITE = http://172.16.3.40/
ASU_URL = ftp://user:qwerty@worker.asu/apps.json
ASU_COMPANY = LTD Synthesis Rubber
ASU_COPYRIGHT = Copyright © 2015 ASUTP
ASU_VERSION = 1.0
ASU_MAJOR_VERSION = 1
ASU_MINOR_VERSION = 0
ASU_INSTALL_BINS = $${PWD}/_build/
ASU_INSTALL_APPS = $${PWD}/_bin/
#
CONFIG -= debug_and_release
CONFIG -= debug_and_release_target
CONFIG -= build_all
CONFIG -= lex
CONFIG -= yacc
CONFIG -= exceptions
CONFIG -= depend_includepath
CONFIG -= testcase_targets
CONFIG -= import_plugins
CONFIG -= import_qpa_plugin
CONFIG -= rtti_off
CONFIG -= rtti
CONFIG -= incremental_off
CONFIG -= warn_on
CONFIG -= qt
CONFIG -= link_prl
CONFIG -= shared
CONFIG -= precompile_header
CONFIG -= no_plugin_manifest
CONFIG -= qpa
CONFIG -= mingw
CONFIG -= gcc
CONFIG -= console
CONFIG -= app_bundle
#
CONFIG += debug
CONFIG -= release
#
#CONFIG -= x86
#CONFIG -= x86_64
#
CONFIG -= silent
#
QT -= gui core widgets
#
DEFINES -= UNICODE
#
windows: {
    DEFINES += WIN32
    DEFINES += _WIN
    DEFINES += __WIN32__
    ASU_INSTALL_APPS = $${ASU_INSTALL_APPS}win
    CONFIG(x86_64): {
        ASU_INSTALL_APPS = $${ASU_INSTALL_APPS}64
    }
}
unix: {
    DEFINES += _LINUX
    DEFINES += __linux__
    ASU_INSTALL_APPS = $${ASU_INSTALL_APPS}unix
    CONFIG(x86_64): {
        ASU_INSTALL_APPS = $${ASU_INSTALL_APPS}64
    }
}
!windows: !unix: {
    error("This platform no support")
}
#
ASU_INSTALL_APPS = $${ASU_INSTALL_APPS}_qt$${QT_MAJOR_VERSION}$${QT_MINOR_VERSION}$${QT_PATCH_VERSION}
#
DEFINES += _RELEASE
DEFINES -= _DEBUG
CONFIG(debug): {
    ASU_INSTALL_APPS = $${ASU_INSTALL_APPS}_d
    DEFINES -= _RELEASE
    DEFINES += _DEBUG
}
#
MOC_DIR		= $${_PRO_FILE_PWD_}/_/
UI_DIR		= $${_PRO_FILE_PWD_}/_/
RCC_DIR		= $${_PRO_FILE_PWD_}/_/
OBJECTS_DIR	= $${_PRO_FILE_PWD_}/_/
#
defineTest(write){
    val = $$1
    op = $$2
    fl = $$3

    windows: val ~= s/>/^>
    windows: val ~= s/</^<

    windows: system (echo $$val $$op $$fl)
    else:  system (echo \"$$val\" $$op $$fl)

    return (true)
}
#
DLLDESTDIR = $${ASU_INSTALL_APPS}
QMAKE_DISTCLEAN += $${ASU_INSTALL_APPS}
DESTDIR = $${ASU_INSTALL_BINS}
QMAKE_DISTCLEAN += $${ASU_INSTALL_BINS}
#
