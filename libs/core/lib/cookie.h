#ifndef COOKIE_H
#define COOKIE_H
//
#include <QtCore/QObject>
#include <QNetworkCookieJar>
//
#include "lib_core.h"
//
ASU_BEGIN_NAMESPACE
//
class ASU_CORE Cookie : public QNetworkCookieJar
{
    Q_OBJECT
private:
    QString filename;
public:
//    QList<QNetworkCookie> getAllCookies() { return allCookies(); }
    void setFilename(const QString& _filename){ filename = _filename; };
signals:
    void loadCookiesFailed(const QString& msg);
    void saveCookiesFailed(const QString& msg);
public slots:
    void loadCookies();
    void saveCookies();
};
//
ASU_END_NAMESPACE
//
#endif // COOKIE_H
