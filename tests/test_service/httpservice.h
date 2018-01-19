#ifndef HTTPSERVICE_H
#define HTTPSERVICE_H

#include <QCoreApplication>

#include "qtservice.h"
#include "httpdaemon.h"

class HttpService : public QtService<QCoreApplication>
{
public:
    HttpService(int argc, char **argv);

protected:
    void start();

    void pause();

    void resume();

private:
    HttpDaemon *daemon;
};

#endif // HTTPSERVICE_H
