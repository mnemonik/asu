include(../../../_init.pri)
#
#CONFIG += ASU_BASE_USE
#include(../../../libs/base/lib/lib_base.pri)

#CONFIG += ASU_CORE_USE
#include(../../../libs/core/lib/lib_core.pri)
#
include(app_wpm.pri)

TEMPLATE = $${APP_TYPE}

TARGET = $${APP_NAME}
#
#include(../../../_json.pri)
#
include(../../../_install.pri)
