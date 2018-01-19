TEMPLATE = subdirs
CONFIG += ordered


SUBDIRS += base

SUBDIRS += core
core.depends = base

SUBDIRS += service
core.depends = base core
