include(../../../_init.pri)
#
CONFIG += ASU_BASE_USE
include(../../../libs/base/lib/lib_base.pri)
#
CONFIG += ASU_CORE_BUILD
include(lib_core.pri)
#
TEMPLATE    = lib
#
TARGET      = $${ASU_CORE_NAME}
#
include(../../../_install.pri)
