#ifndef LOGGER_TS_H
#define LOGGER_TS_H
//
#include <QObject>
#include <QHash>
//
#include "lib_base.h"
//
QT_BEGIN_NAMESPACE
//
class ASU_RES Timers : public QObject
{
    Q_OBJECT
private:
    Timers(QObject* _parent = 0);
    Q_DISABLE_COPY(Timers);
    static Timers* _instance;
public:
    static Timers* instance(QObject* _parent = 0);
private:
    QHash<QString, QTime*> _timers;
public:
    void insert(const QString& name);
    void remove(const QString& name);
    int elapsed(const QString& name);
};
//
#define zTime(__name) Timers::instance()->insert(__name);
#define zTimeEnd(__name) LOG(tr("TIME %1 = %2 ms").arg(__name).arg(Timers::instance()->elapsed(__name)), Z::Logger::TraceMsg); Timers::instance()->remove(__name);
//
QT_END_NAMESPACE
//
#endif // LOGGER_TS_H
