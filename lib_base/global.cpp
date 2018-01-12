#include <QCoreApplication>
#include <QFileInfo>

#include "global.h"
#include "logger.h"
#include "app.h"

QT_USE_NAMESPACE

Global* Global::_instance = 0;
const QString Global::RES = "global";
const QString Global::PATH = "global/path";
const QString Global::URL = "global/url";
//
Global::Global(QObject* _parent)
    :   QSettings(QSettings::IniFormat, QSettings::UserScope, ORG_NAME, QString(), _parent)
{
    setObjectName(tr("Конфигурация"));
}

Global::~Global()
{
}

Global* Global::instance(QObject *_parent){
    if(_instance==0) _instance = new Global(_parent);
    Q_ASSERT_X(_instance, "_instance", "is not null");
    return _instance;
}

void Global::save()
{
    zTrace(tr("save"));
    this->sync();
}

void Global::set(const QString &key, const QVariant &value)
{
    zTrace(tr("set %1 = %2").arg(key).arg(value.toString()));
    this->setValue(key, value);
}

QVariant Global::get(const QString &key, const QVariant &defaultValue) const
{
    zTrace(tr("get %1 = [%2]").arg(key).arg(defaultValue.toString()));
    return this->value(key, defaultValue);
}
