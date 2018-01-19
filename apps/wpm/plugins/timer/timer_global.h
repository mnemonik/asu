#ifndef TIMER_GLOBAL_H
#define TIMER_GLOBAL_H
//
#include <QtCore/qglobal.h>
//
#if defined(TIMER_LIBRARY)
    #define TIMER_EXPORT Q_DECL_EXPORT
#else
    #define TIMER_EXPORT Q_DECL_IMPORT
#endif
//
#define PLUGIN_NAME "Timer"
#define PLUGIN_VERSION "0.0.0.0"
#define PLUGIN_DESCRIPTION "Sample plugin for worker"
#define PLUGIN_DEPEND ""
//
#endif // TIMER_GLOBAL_H
