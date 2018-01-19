#include "wpmapp.h"

int main(int argc, char *argv[])
{
#if !defined(Q_OS_WIN)
//    QSettings::setPath(QSettings::NativeFormat, QSettings::SystemScope, QDir::tempPath());
#endif

    return 0;//(Z::WpmApp(argc, argv).exec());
}
