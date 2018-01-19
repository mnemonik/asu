#ifndef SESSION_H
#define SESSION_H
//
#include <QNetworkAccessManager>
#include <QNetworkReply>
//
#include "lib_core.h"
//
ASU_FORWARD_DECLARE_CLASS(Cookie);
QT_FORWARD_DECLARE_CLASS(QNetworkDiskCache);
//
ASU_BEGIN_NAMESPACE
//
class ASU_CORE Session : public QNetworkAccessManager
{
    Q_OBJECT
public:
    explicit Session(QObject *parent = 0);
    ~Session();
private:
    QString s_UserAgent;
    Cookie* m_cookie;
    QNetworkDiskCache* m_cache;
    void wait(const QObject *sender, const char* signal);
public:
    QNetworkReply::NetworkError get(const QString& url, QByteArray& ret);
signals:

public slots:
};
//
ASU_END_NAMESPACE
//
#endif // SESSION_H
