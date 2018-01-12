//
#ifndef APP_H
#define APP_H
//
#include "app_gen.h"
//
#if defined(Q_OS_WIN)
    #define APP_LOCALE "windows-1251"
#else
    #define APP_LOCALE "utf-8"
#endif
//
#define APP_ICON ":/res/app.png"
//
#endif // APP_H
