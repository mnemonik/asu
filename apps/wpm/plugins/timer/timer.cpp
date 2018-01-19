#include <QDebug>

#include <iostream>

#include "timer.h"
#include "core.h"

using namespace Z;
using namespace std;

TimerPlugin::TimerPlugin()
    : QObject(0), timer(this), counter(0)
{
    setObjectName("TimerPlugin");
    //Инициализируем таймер который будет писать в лог каждые 5 секунд.
    timer.setSingleShot(false);
    connect(&timer,SIGNAL(timeout()),this,SLOT(onTimer()));
    timer.setInterval(5000);
}

void TimerPlugin::init(const QString &name, Resources *res)
{
    Q_UNUSED(res);

    Core* core = Core::instance();
    setParent(core);
    //Соединяем слоты с сигналами службы о начале работы и
    connect(core,SIGNAL(afterStarted()),this,SLOT(onAfterStart()));
    connect(core,SIGNAL(beforeStop()),this,SLOT(onBeforStop()));
    //Инициализация плагина, создание ресурсов плагина

}

PluginInfo TimerPlugin::info() const
{
    return PluginInfo(QString(PLUGIN_NAME), QString(PLUGIN_VERSION), QString(PLUGIN_DESCRIPTION), QStringList(PLUGIN_DEPEND));
}

void TimerPlugin::onAfterStart()
{
    //Сюда мы попадаем по сигналу службы afterStart(), когда все плагины и
    //ресурсы созданы и готовы к работе. При необходимости, захватываем ресурсы
    //и начинаем работу плагина

    //Мы просто стартуем таймер
    timer.start();

    //Вывод в журнал
    qDebug() << tr("%1: plugin onAfterStart().").arg(objectName());
}

void TimerPlugin::onBeforStop()
{
    //Сюда мы попадаем по сигналу о том, что служба будет останволена и требует
    //прекратить работу и высвободить все ресурсы. Если ресурсы были захвачены,
    //плагин обязан их освободить и завешить свою работу

    //Мы просто останавливаем таймер.
    timer.stop();

    //Вывод в журнал
    qDebug() << tr("%1: plugin onBeforStop().").arg(objectName());
}

void TimerPlugin::onTimer()
{
    //Вывод сообщения в журнал по таймеру.
    qDebug() << tr("%1: this is test onTimer counter=%2.").arg(objectName()).arg(counter++);

    //Примеры использования стандартных средств С++ и Qt для журналирования событий
    cout << "string to standard output" << endl;
    cerr << "string to error output" << endl;
    qDebug("string to qDebug");
    qWarning("string to qWarning");
    qCritical("string to qCritical");
    //qFatal("string to qFatal");
}

