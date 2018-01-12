#include "cookie.h"

#include <QNetworkCookie>
#include <QFile>
#include <QDebug>
#include <QDir>

QT_USE_NAMESPACE

void Cookie::loadCookies()
{
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly))
    {
        QByteArray cookies = file.readAll();
        setAllCookies(QNetworkCookie::parseCookies(cookies));
    }
    else
    {
        emit loadCookiesFailed(file.errorString());
    }
}

void Cookie::saveCookies()
{
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        QByteArray cookies;
        foreach (QNetworkCookie cookie, allCookies())
            cookies += cookie.toRawForm();
        file.write(cookies);
    }
    else
    {
        emit saveCookiesFailed(file.errorString());
    }
}
