#ifndef LIB_CORE_H
#define LIB_CORE_H
//
#if defined(_WIN32)
    #if defined( ASU_CORE_EXPORT )
        #define ASU_CORE __declspec( dllexport )
    #elif defined( ASU_CORE_IMPORT )
        #define ASU_CORE __declspec( dllimport )
    #else
        #define ASU_CORE
    #endif // ASU_CORE
#else // !WIN32
    #define ASU_CORE
#endif
//
#endif // LIB_CORE_H
