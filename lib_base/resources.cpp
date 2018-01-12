#include "resources.h"
#include "logger.h"

QT_USE_NAMESPACE

Resources* Resources::_instance = 0;

Resources::Resources(QObject* parent, const int _avail)
:QObject(parent), lock(QMutex::Recursive), avail(_avail)
{
    setObjectName("Песочница");
    zDebug(tr("%1 создана").arg(objectName()));
}



Resources::~Resources()
{
    zDebug(tr("%1 уничтожена").arg(objectName()));
}

Resources* Resources::instance(QObject *_parent){
    if(_instance==0){
        _instance = new Resources(_parent);
    }
    zAssert(_instance, "_instance is not null");
    return _instance;
}

bool Resources::add(const QString& name, QObject* resource)
{
    QMutexLocker locker(&lock);
    if(hash.contains(name))
    {
        zWarning(tr("%1 ключ %2 уже существует").arg(objectName()).arg(name));
        return false;
    }
    hash[name] = resource;
    counter[name] = 0;
    zDebug(tr("%1 ключ %2 добавлен").arg(objectName()).arg(name));
    return true;
}

bool Resources::remove(const QString& name)
{
    QMutexLocker locker(&lock);
    if(!hash.contains(name))
    {
        zWarning(tr("%1 ключ %2 не найден").arg(objectName()).arg(name));
        return false;
    }
    hash.remove(name);
    counter.remove(name);
    zDebug(tr("%1 ключ %2 удален").arg(objectName()).arg(name));
    return true;
}

QObject* Resources::get(const QString& name, QObject* def)
{
    QMutexLocker locker(&lock);
    if(hash.contains(name))
        return hash[name];
    else
        return def;
}

QStringList Resources::list(const bool& _use) const
{
    QMutexLocker locker(&lock);
    QStringList ret;
    QHashIterator<QString, QObject*> i(hash);
    while (i.hasNext()){
        i.next();
        if(_use){
            if(counter[i.key()])
                ret << i.key();
        }else
            ret << i.key();
    }
    return ret;
}

bool Resources::acquire(const QString& name)
{
    QMutexLocker locker(&lock);
    if(!hash.contains(name))
    {
        zWarning(tr("%1 ключ %2 не найден").arg(objectName()).arg(name));
        return false;
    }
    counter.insert(name, counter[name] + 1);
    return true;
}

bool Resources::release(const QString& name)
{
    QMutexLocker locker(&lock);
    if(!hash.contains(name))
    {
        zWarning(tr("%1 ключ %2 не найден").arg(objectName()).arg(name));
        return false;
    }
    counter.insert(name, counter[name] - 1);
    return true;
}
