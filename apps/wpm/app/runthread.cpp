#include "runthread.h"

using namespace Z;

RunThread::RunThread(const QObject *object, const char *slot, const QObject *controller)
    : QThread()
{
    QObject::connect(this, SIGNAL(started()), object, slot);
    QObject::connect(object, SIGNAL(finished(int)), this, SLOT(quit()));
    //object->moveToThread(this);
    if(controller){
        QObject::connect(object, SIGNAL(started()), controller, SLOT(started()));
        QObject::connect(object, SIGNAL(finished()), controller, SLOT(finished()));
        QObject::connect(object, SIGNAL(message(QString)), controller, SLOT(message(QString)));
    }
}
