#ifndef LIB_BASE_H
#define LIB_BASE_H
//
#include "define.h"
//
#if defined(_WIN32)
    #if defined( ASU_BASE_EXPORT )
        #define ASU_BASE __declspec( dllexport )
    #elif defined( ASU_BASE_IMPORT )
        #define ASU_BASE __declspec( dllimport )
    #else
        #define ASU_BASE
    #endif // ASU_BASE
#else // !WIN32
    #define ASU_BASE
#endif
//
#endif // LIB_BASE_H
