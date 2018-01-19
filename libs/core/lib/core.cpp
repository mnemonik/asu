#include <QCoreApplication>
#include <QDir>
#include <QFile>
#include <QFileInfo>

#include "plugin.h"
#include "core.h"
#include "config.h"
#include "logger.h"
#include "resources.h"

using namespace Z;

Core* Core::_instance = 0;
const QString Core::RES = "core";
const QString Core::PLUGINS = "plugins";
const QString Core::PATH = "path";

Core::Core(QObject* _parent)
    : QObject(_parent), conf(0), log(0), res(0), running(false)
{
    setObjectName("Ядро");
    zDebug(tr("%1 создаётся").arg(objectName()));
    //
    conf = Config::instance();
    log = Logger::instance();
    res = Resources::instance();
    //
    res->add(Core::RES, this);
    res->add(Config::RES, conf);
    res->add(Logger::RES, log);
    //
    zDebug(tr("%1 создано").arg(objectName()));
}

Core::~Core()
{
    zDebug(tr("%1 удаляется").arg(objectName()));
    //
    res->remove(Logger::RES);
    res->remove(Config::RES);
    res->remove(Core::RES);
    //
    delete res;
    if(conf){
        delete conf;
        conf = 0;
    }
    //
    zDebug(tr("%1 удалено").arg(objectName()));
    if(log){
        delete log;
        log = 0;
    }
}

Core *Core::instance(QObject *_parent)
{
    if(_instance==0){
        _instance = new Core(_parent);
    }
    zAssert(_instance, "_instance is not null");
    return _instance;
}

bool Core::start()
{
    zDebug(tr("%1 стартует").arg(objectName()));
    if(!loadPlugins())
        return false;
    //
    emit afterStarted();
    running = true;
    zDebug(tr("%1 стартовал").arg(objectName()));
    return true;
}

bool Core::stop()
{
    zDebug(tr("%1 останавливается").arg(objectName()));
    running = false;
    emit beforeStop();
    //
    if(!unloadPlugins())
        return false;
    //
    zDebug(tr("%1 остановился").arg(objectName()));
    return true;
}
bool Core::restart()
{
    zDebug(tr("%1 перестартует").arg(objectName()));
    if(!stop())
        return false;
    if(!start())
        return false;
    zDebug(tr("%1 перестартовал").arg(objectName()));
    return true;
}

bool Core::isRunning()
{
    return running;
}

bool Core::loadPlugins()
{
    zDebug(tr("%1 загрузка плагинов").arg(objectName()));
    QString path = conf->get(Core::PATH, CORE_PATH).toString();
    zTrace(tr("path = %1").arg(path));
    QCoreApplication::addLibraryPath(path);

    QStringList plugins = conf->get(Core::PLUGINS, CORE_PLUGINS).toStringList();
    zTrace(tr("plugins = %1").arg(plugins.join(",")));
    //
    if(plugins.empty()){
        zDebug(tr("Список плагинов пуст - загружаем все: %1").arg(qApp->applicationDirPath()));
        QDir dir(qApp->applicationDirPath());
        if(dir.exists()){
            plugins = dir.entryList(QStringList("*.dll"), QDir::Files | QDir::NoSymLinks);
        }
    }
    //
    zDebug(tr("Загрузка пдагинов: %1").arg(plugins.join(",")));
    QListIterator<QString> i(plugins);
    while (i.hasNext()) {
        QString plg = i.next();
        if(!loadPlugin(plg)){
            zWarning(tr("%1 плагин %2 не загружен").arg(objectName()).arg(plg));
            //return false;
        }
    }
    //
    zDebug(tr("%1 плагины загружены").arg(objectName()));
    return true;
}

bool Core::resolveLibraries()
{/*
    ConfigReader cr(this, log, config->root());
    bool ok;
    QMap<QString,QString> map = cr.bootChain(ok);
    if(!ok)
        return false;
    if(!map.size())
    {
        log->logMessage("core: no plugins. done.", Logger::error);
        return false;
    }
    QMap<QString,QString> map2;
    QMapIterator<QString, QString> i(map);
    while (i.hasNext()) {
        i.next();
        if(QFile::exists(i.value()))
        {
            map2[i.key()] = i.value();
        }
        else
        {
            QString lib = qApp->applicationDirPath()
                            + "/plugins/" + i.value();
            if(QFile::exists(lib))
            {
                map2[i.key()] = lib;
            }
            else
            {
                log->logMessage("core: library " + i.value()
                    + " of plugin " + i.key() + " not found!", Logger::error);
                return false;
            }
        }
    }
    QMapIterator<QString, QString> i2(map2);
    while (i2.hasNext()) {
        i2.next();
        chain[i2.key()] = new QPluginLoader(i2.value());
    }*/
    return true;
}

bool Core::unloadPlugins()
{
    zDebug(tr("%1 unload plugins...").arg(objectName()));
    //
    QMapIterator<QString, QPluginLoader*> i(chain);
    while (i.hasNext()) {
        i.next();
        if(!unloadPlugin(i.key(),i.value()))
        {
            zCritical(tr("could not unload plugin %1 : %2").arg(i.key()).arg(i.value()->errorString()));
        }
        delete i.value();
    }
    chain.clear();
    //
    zDebug(tr("%1 plugins unloaded.").arg(objectName()));
    return true;
}

bool Core::loadPlugin(const QString& name)
{
    zDebug(tr("%1 загрузка плагина %2").arg(objectName()).arg(name));
    QString lib = qApp->applicationDirPath() + "/plugins/" + name;
    if(!QFile::exists(name)){
        zCritical(tr("%1 плагин %2 не найден").arg(objectName()).arg(name));
        return false;
    }
    chain[name] = new QPluginLoader(name);
    return loadPlugin(name, chain[name]);
}

bool Core::unloadPlugin(const QString& name)
{
    if(chain.contains(name)) {
        return unloadPlugin(name,chain[name]);
    } else {
        zWarning(tr("%1 unload plugin %2 not found in chain boot!").arg(objectName()).arg(name));
        return false;
    }
}

bool Core::pluginIsLoaded(const QString& name)
{
    if(!chain.contains(name)){
        zWarning(tr("%1 isload plugin %2 not found in chain boot!").arg(objectName()).arg(name));
        return false;
    }
    if(chain[name])
        return chain[name]->isLoaded();
    else
        return false;
}

bool Core::loadPlugin(const QString& name, QPluginLoader* loader)
{
    zDebug(tr("%1 загрузка плагина %2 ...").arg(objectName()).arg(name));
    if(!loader->load())
    {
        zCritical(tr("%1 could not load plugin %2 : %3").arg(objectName()).arg(name).arg(loader->errorString()));
        return false;
    }
    QObject* obj = loader->instance();
    if(!obj)
    {
        zCritical(tr("%1 could not create root object of plugin %2 : %3").arg(objectName()).arg(name).arg(loader->errorString()));
        return false;
    }
    Plugin* plugin = qobject_cast<Plugin*>(obj);
    if(!plugin)
    {
        zCritical(tr("%1 could not cast root object of plugin %2 to Plugin").arg(objectName()).arg(name));
        return false;
    }
    plugin->init();

    if(!res->add(name, obj))
    {
        zCritical(tr("%1 could not add plugin %2 to resources.").arg(objectName()).arg(name));
        loader->unload();
        return false;
    }

    zDebug(tr("%1 plugin %2 loaded.").arg(objectName()).arg(name));
    return true;
}

bool Core::unloadPlugin(const QString& name, QPluginLoader* loader)
{
    zDebug(tr("%1 unloading plugin %2 ...").arg(objectName()).arg(name));
    //
    if(!loader->unload())
    {
        zCritical(tr("%1 could not unload plugin %2 : %3").arg(objectName()).arg(name).arg(loader->errorString()));
        return false;
    }
    res->remove(name);
    //
    zDebug(tr("%1 plugin %2 unloaded.").arg(objectName()).arg(name));
    return true;
}

QStringList Core::plugins()
{
    return chain.keys();
}
