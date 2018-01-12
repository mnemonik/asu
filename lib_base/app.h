//
#ifndef APP_H
#define APP_H
//
#if defined(Q_OS_WIN)
    #define APP_LOCALE "windows-1251"
#else
    #define APP_LOCALE "utf-8"
#endif
//
#include "app_gen.h"
//
//#define APP_MAIN "worker"
#define APP_ICON ":/res/app.png"
//
#endif // APP_H
