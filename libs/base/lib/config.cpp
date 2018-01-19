#include <QCoreApplication>
#include <QFileInfo>

#include "config.h"

using namespace Z;

Config* Config::_instance = 0;
const QString Config::RES = "config";

Config::Config(QObject* _parent)
    :   QObject(_parent), sf(0)
{
    setObjectName("Настройки");
    sf = new QSettings(QFileInfo(QCoreApplication::applicationFilePath()).baseName()+".conf", QSettings::IniFormat);
    Q_ASSERT_X(sf, "sf", "is not null");
}

Config::~Config()
{
    delete sf;
}

Config* Config::instance(QObject *_parent){
    if(_instance==0) _instance = new Config(_parent);
    Q_ASSERT_X(_instance, "_instance", "is not null");
    return _instance;
}

void Config::save()
{
    sf->sync();
}

void Config::set(const QString &key, const QVariant &value)
{
    sf->setValue(key, value);
};

QVariant Config::get(const QString &key, const QVariant &defaultValue) const
{
    return sf->value(key, defaultValue);
}
