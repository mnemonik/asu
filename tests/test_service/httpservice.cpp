#include "httpservice.h"

HttpService::HttpService(int argc, char **argv)
    : QtService<QCoreApplication>(argc, argv, "Qt HTTP Daemon")
{
    setServiceDescription("A dummy HTTP service implemented with Qt");
    setServiceFlags(QtServiceBase::CanBeSuspended);
}

void HttpService::start()
{
    QCoreApplication *app = application();
    
#if QT_VERSION < 0x040100
    quint16 port = (app->argc() > 1) ?
                QString::fromLocal8Bit(app->argv()[1]).toUShort() : 8080;
#else
    const QStringList arguments = QCoreApplication::arguments();
    quint16 port = (arguments.size() > 1) ?
                arguments.at(1).toUShort() : 8080;
#endif
    daemon = new HttpDaemon(port, app);
    
    if (!daemon->isListening()) {
        logMessage(QString("Failed to bind to port %1").arg(daemon->serverPort()), QtServiceBase::Error);
        app->quit();
    }
}

void HttpService::pause()
{
    daemon->pause();
}

void HttpService::resume()
{
    daemon->resume();
}
