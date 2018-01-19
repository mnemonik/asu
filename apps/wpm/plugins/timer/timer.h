#ifndef TIMERPLUGIN_H
#define TIMERPLUGIN_H

#include <QTimer>

#include "timer_global.h"
#include "plugin.h"

namespace Z
{

class TIMER_EXPORT TimerPlugin: public QObject, public Plugin
{
    Q_OBJECT
public:
    TimerPlugin();
    void init(const QString& name, Resources* res);
    PluginInfo info() const;
public slots:
    void onAfterStart();
    void onBeforStop();
    void onTimer();
private:
    QTimer timer;
    int counter;
};

};//namespace Z

#endif // TIMERPLUGIN_H
