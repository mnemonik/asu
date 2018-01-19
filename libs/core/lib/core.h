#ifndef CORE_H
#define CORE_H
//
#include <QObject>
#include <QMap>
#include <QStringList>
#include <QPluginLoader>
//
#include "lib_core.h"
//
namespace Z {
//
class Config;
class Logger;
class Resources;
//
#define CORE_PATH ""
#define CORE_PLUGINS ""
//
/*!
 * \brief The Core class
 * Основной класс службы, который занимается загрузкой и выгрузкой службы
 * и плагинов. Так же слоты этого класса могут быть вызваны из плагинов.
 * Z_CORE_EXPORT
 */
class ASU_CORE Core : public QObject
{
    Q_OBJECT
private:
    Core(QObject* _parent = 0);
    Q_DISABLE_COPY(Core);
    static Core* _instance;
public:
    ~Core();
    static Core* instance(QObject* _parent = 0);
public:
    static const QString RES;
    static const QString PLUGINS;
    static const QString PATH;
private:
    Config* conf;
    Logger* log;
    Resources* res;
    QMap<QString,QPluginLoader*> chain;
private:
    bool running;
public:
    bool isRunning();
public Q_SLOTS:
    bool start();
    bool stop();
    bool restart();
    bool loadPlugin(const QString& name);
    bool unloadPlugin(const QString& name);
    bool pluginIsLoaded(const QString& name);

     QStringList plugins();
     bool resolveLibraries();
private:
    bool loadPlugins();
    bool unloadPlugins();
    bool loadPlugin(const QString& name, QPluginLoader* loader);
    bool unloadPlugin(const QString& name, QPluginLoader* loader);
Q_SIGNALS:
    void beforeLoadPlugin(const QString& name);
    //Сигнал подается, когда все плагины загружены и готовы к взаимодействию.
    //Можно понимать этот сигнал как разрешение к началу работы.
    void afterStarted();
    //Сигнал подается перед выгрузкой плагинов. Он какбэ намекает на то, что
    //сейчас будет остановка службы и пора прекратить работу и высвободить
    //все ресурсы. Сразу после этого сигнала следует попытка захвата всех ресурсов,
    //дабы дождаться их высвобождения, чтобы корректно остановить службу!
    //Смотри конфигурационный файл для настройки таймаута освобождения ресурсов.
    void beforeStop();
private:
};
//
} //END_NAMESPACE
//
#endif // CORE_H
