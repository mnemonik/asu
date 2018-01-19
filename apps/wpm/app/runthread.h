#ifndef LAUNCHTHREAD_H
#define LAUNCHTHREAD_H

#include <QThread>

namespace Z {

class RunThread : public QThread
{
    Q_OBJECT
public:
    explicit RunThread(const QObject *object, const char *slot, const QObject *controller = NULL);
    
signals:
    
public slots:
};

};

#endif // LAUNCHTHREAD_H
