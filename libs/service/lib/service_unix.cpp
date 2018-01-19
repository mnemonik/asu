#include "service.h"

namespace Z {

Service::Service(int argc, char *argv[], const QString &name)
    : QCoreApplication(argc, argv), serviceName(name)
{
}

bool Service::install(const QStringList &params)
{
}

}//Z
