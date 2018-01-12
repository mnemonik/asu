include(../_init.pri)
#
CONFIG += ASU_BASE_USE
include(../lib_base/lib_base.pri)
#
CONFIG += ASU_CORE_BUILD
include(lib_core.pri)
#
TEMPLATE    = lib
#
TARGET      = $${ASU_CORE_NAME}
#
include(../_install.pri)
