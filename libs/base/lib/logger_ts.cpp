#include <QTime>
//
#include "logger_ts.h"
//
using namespace Z;
//
Timers* Timers::_instance = 0;
//
Timers::Timers(QObject *_parent) :
    QObject(_parent)
{
}

Timers *Timers::instance(QObject *_parent){
    if(_instance==0) _instance = new Timers(_parent);
    Q_ASSERT_X(_instance, "_instance", "is not null");
    return _instance;
}

void Timers::insert(const QString &name)
{
    QTime* time = new QTime();
    time->start();
    _timers.insert(name, time);
}

void Timers::remove(const QString &name)
{
    QTime* time = _timers[name];
    delete time; time = 0;
    _timers.remove(name);
}

int Timers::elapsed(const QString &name)
{
    QTime* time = _timers[name];
    return time->elapsed();
}
//
