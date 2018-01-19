#ifndef SERVICE_GLOBAL_H
#define SERVICE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SERVICE_LIBRARY)
#  define SERVICE_LIBRARY_SHARED Q_DECL_EXPORT
#else
#  define SERVICE_LIBRARY_SHARED Q_DECL_IMPORT
#endif

#endif // SERVICE_GLOBAL_H
