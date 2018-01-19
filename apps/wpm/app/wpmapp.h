#ifndef WPMSERVICE_H
#define WPMSERVICE_H

#include <QCoreApplication>
#include "resources.h"
#include "config.h"
#include "core.h"
#include "service.h"

namespace Z {

class WpmApp : public QCoreApplication
{
    Q_OBJECT
public:
    explicit WpmApp(int argc, char *argv[]);
    //
public:
    QString file;
    QString dir;
    QString user;
    QString pswd;
    static const QString CONF_SERVICE_NAME;
    static const QString CONF_SERVICE_DESC;
    static const QString CONF_SERVICE_USER;
    static const QString CONF_SERVICE_PSWD;
    static const QString CONF_SERVICE_DEPS;
    static const QString CONF_GLOBAL_DIR;
    static const QString CONF_GLOBAL_USER;
    static const QString CONF_GLOBAL_PSWD;
    static const QString APP;
    static const QString SRV;
    //
    Q_ENUMS(oper)
    enum oper {
        OPER_HELP,
        OPER_REG,
        OPER_UNREG,
        OPER_START,
        OPER_STOP,
        OPER_PAUSE,
        OPER_RESUME,
    };
private:
    Resources* res;
    Config* conf;
    Core* core;
    Service* srv;
    QThread* thread;
    bool launch;
    void initApp();
    bool parseArg(const QString &arg, const QString &key, QString &val);
    void parseArgs();
public slots:
    void quitApp(int code = EXIT_SUCCESS);
private:
    void initRes();
    void initConf();
    void initCore();
    void initService();
    void showHelp();
    void loadApps();
    void runGUI();
public:
    int code;
    int ServiceReg();
    int ServiceUnreg();
    int ServiceStart();
    int ServiceStop();
    int ServiceStatus();
    int ServicePause();
    int ServiceResume();
    int ServiceInstall(const QString& app);
    int ServiceUninstall(const QString& app);
    int ServiceCheck(const QString& app);
    int ServiceUpdate(const QString& app);
    int ServiceUpdateAll();
    int ServiceList(const QString &app);
    int ServiceRun(const QString &app);
private:
    QString config;
    QString url;
};

};

#endif // WPMSERVICE_H
