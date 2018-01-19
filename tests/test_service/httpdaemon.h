#ifndef HTTPDAEMON_H
#define HTTPDAEMON_H

#include <QTcpServer>

// HttpDaemon is the the class that implements the simple HTTP server.
class HttpDaemon : public QTcpServer
{
    Q_OBJECT
public:
    HttpDaemon(quint16 port, QObject* parent = 0);

    void incomingConnection(int socket);

    void pause();

    void resume();

private slots:
    void readClient();
    void discardClient();

private:
    bool disabled;
};

#endif // HTTPDAEMON_H
