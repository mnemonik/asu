TEMPLATE = subdirs
CONFIG += ordered

SUBDIRS += lib_base
CONFIG(debug):{
    SUBDIRS += test_base
    test_base.depends = lib_base
}

SUBDIRS += lib_core
lib_core.depends = lib_base

CONFIG(debug):{
    SUBDIRS += test_core
    test_core.depends = lib_core
}

SUBDIRS += app_wpm
app_wpm.depends = lib_core
