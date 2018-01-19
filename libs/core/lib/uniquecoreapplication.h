#ifndef UNIQUECOREAPPLICATION_H
#define UNIQUECOREAPPLICATION_H
//
#include <QCoreApplication>
#include "lib_core.h"
//
ASU_FORWARD_DECLARE_CLASS(LocalPeer)
ASU_BEGIN_NAMESPACE
//
class ASU_CORE UniqueCoreApplication : public QCoreApplication
{
    Q_OBJECT

public:
    UniqueCoreApplication(int &argc, char **argv);
    UniqueCoreApplication(const QString &id, int &argc, char **argv);

    bool isRunning();
    QString id() const;

public Q_SLOTS:
    bool sendMessage(const QString &message, int timeout = 5000);

Q_SIGNALS:
    void messageReceived(const QString &message);

private:
    LocalPeer* peer;
};
//
ASU_END_NAMESPACE
//
#endif // UNIQUECOREAPPLICATION_H
