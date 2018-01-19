#ifndef SERVICE_H
#define SERVICE_H

#include <QCoreApplication>

#include "service_global.h"

#include "windows.h"


namespace Z {

class Service : public QCoreApplication
{
    Q_OBJECT
    Q_CLASSINFO("Author", "")
    Q_CLASSINFO("URL", "http://")
    //Q_DECLARE_PRIVATE(Service)
public:
    Service(int argc, char *argv[], const QString &name);
    //
public:
    Q_ENUMS(StartupType)
    enum StartupType { AutoStartup = 0, ManualStartup };
private:
    StartupType _startuptype;
public:
    void setStartupType(StartupType startuptype){ _startuptype = startuptype; };
    StartupType getStartupType() const { return _startuptype; };
    //
public:
    Q_ENUMS(MessageType)
    enum MessageType { Success = 0, Error, Warning, Information };
private:
    MessageType _messagetype;
public:
    void setMessageType(MessageType messagetype){ _messagetype = messagetype; };
    MessageType getMessageType() const { return _messagetype; };
    //
public:
    Q_FLAGS(ServiceFlag serviceflag)
    enum ServiceFlag { Default = 0x00, CanBeSuspended = 0x01, CannotBeStopped = 0x02, NeedsStopOnShutdown = 0x04 };
private:
    ServiceFlag _serviceflag;
public:
    void setServiceFlag(ServiceFlag serviceflag){ _serviceflag = serviceflag; };
    ServiceFlag getServiceFlag() const { return _serviceflag; };
    Q_DECLARE_FLAGS(serviceflag, ServiceFlag)
    //
private:
    QString serviceName;
public:
    QString getServiceName() const { return serviceName; };
    //
private:
    QString serviceDescription;
public:
    QString getServiceDescription() const  { return serviceDescription; };
    void setServiceDescription(const QString &description){ serviceDescription = description; };
    //
public:
    SC_HANDLE handle(const QStringList &params);
    bool install(const QStringList &params);
    bool uninstall(const QStringList &params);
    QString ErrorMessage() const;
    
 /*   
    QString serviceFilePath() const;
    //
    bool uninstall();

    bool start(const QStringList &arguments);
    bool start();
    bool stop();
    bool pause();
    bool resume();
    //
    bool isInstalled() const;
    bool isRunning() const;
    int exec();

    void logMessage(const QString &message, MessageType type = Success,
                int id = 0, uint category = 0, const QByteArray &data = QByteArray());*/

};

};

#endif // SERVICE_H
