#ifndef LOCALPEER_H
#define LOCALPEER_H
//
#include "lib_core.h"
#include "lockedfile.h"
//
ASU_FORWARD_DECLARE_CLASS(QLocalServer)
ASU_FORWARD_DECLARE_CLASS(QLocalSocket)
//
ASU_BEGIN_NAMESPACE
//
class ASU_CORE LocalPeer : public QObject
{
    Q_OBJECT

public:
    LocalPeer(QObject *parent = 0, const QString &appId = QString());
    bool isClient();
    bool sendMessage(const QString &message, int timeout);
    QString applicationId() const
        { return id; }

Q_SIGNALS:
    void messageReceived(const QString &message);

protected Q_SLOTS:
    void receiveConnection();

protected:
    QString id;
    QString socketName;
    QLocalServer* server;
    LockedFile lockFile;

private:
    static const char* ack;
};
//
ASU_END_NAMESPACE
//
#endif // LOCALPEER_H
