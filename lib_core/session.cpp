#include <QCoreApplication>
#include <QNetworkRequest>
#include <QEventLoop>
#include <QSysInfo>
#include <QNetworkDiskCache>
#include <QDir>
#include "session.h"
#include "cookie.h"
#include "logger.h"

QT_USE_NAMESPACE

Session::Session(QObject *parent) : QNetworkAccessManager(parent)
{
    m_cookie = new Cookie();
    m_cookie->setFilename(qApp->applicationDirPath() + QDir::separator() + qApp->applicationName()+ ".cookie");
    this->setCookieJar(m_cookie);
    m_cookie->loadCookies();
    s_UserAgent = tr("%1/%2 (%3 %4 %5; %6 %7; %8 %9 %10)")
        .arg(qApp->applicationName()).arg(qApp->applicationVersion())
        .arg(QSysInfo::productType()).arg(QSysInfo::productVersion()).arg(QSysInfo::prettyProductName())
        .arg(QSysInfo::kernelType()).arg(QSysInfo::kernelVersion())
        .arg(QSysInfo::buildAbi()).arg(QSysInfo::buildCpuArchitecture()).arg(QSysInfo::currentCpuArchitecture());

//    m_cache = new QNetworkDiskCache(parent);
//    m_cache->setCacheDirectory(qApp->applicationDirPath()+QDir::separator()+"cache");
//    this->setCache(m_cache);
}

Session::~Session()
{
}

void Session::wait(const QObject *sender, const char* signal)
{
    QEventLoop loop;
    QObject::connect(sender, signal, &loop, SLOT(quit()));
    loop.exec();
}

QNetworkReply::NetworkError Session::get(const QString& url, QByteArray& responce)
{
    zDebug(tr("Session::get %1").arg(url));
    QUrl _url(url);
    QNetworkRequest m_request(_url);

    m_request.setRawHeader("User-Agent", s_UserAgent.toLocal8Bit());
//    m_request.setAttribute(QNetworkRequest::CacheLoadControlAttribute, QNetworkRequest::PreferCache);

    QNetworkReply* reply = QNetworkAccessManager::get(m_request);
    //
    wait(reply, SIGNAL(finished()));
    //
    m_cookie->saveCookies();
    if(reply->error() == QNetworkReply::NoError){
        responce = reply->readAll();
    } else {
        zWarning(tr("Ошибка запроса %1: %2").arg(url).arg(reply->errorString()));
    }
    //
    reply->deleteLater();
    return(reply->error());
}

