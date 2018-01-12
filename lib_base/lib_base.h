#ifndef ASURES_H
#define ASURES_H
//
#if defined( _WIN32 )
    #if defined( ASU_RES_EXPORT )
    #define ASU_RES __declspec( dllexport )
    #elif defined( ASU_RES_IMPORT )
    #define ASU_RES __declspec( dllimport )
    #else
    #define ASU_RES
    #endif // ASU_RES
#else // !WIN32
    #define ASU_RES
#endif
//
#endif // ASURES_H
