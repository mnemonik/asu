#ifndef WPMSESSION_H
#define WPMSESSION_H
//
#include "lib_core.h"
#include "session.h"
//
QT_BEGIN_NAMESPACE
//
class WPMBuild{
    uint bid;
    uint aid;
    QString bversion;
    QString btags;
    QString burl;
    QString bdownload;
    WPMBuild& operator=(const QJsonObject& o);
    operator QJsonObject();
};
//
class ASU_CORE WPMSession : public Session
{
    Q_OBJECT
public:
    explicit WPMSession(QObject *parent = 0);
    ~WPMSession();
    QString host;
    bool getLastBuild(int app);
signals:

public slots:
};
//
QT_END_NAMESPACE
//
#endif // WPMSESSION_H
