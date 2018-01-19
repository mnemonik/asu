#ifndef PLUGIN_H
#define PLUGIN_H
//
#include <QString>
#include <QStringList>
//
#include "lib_core.h"
//
namespace Z {
//
class Config;
class Logger;
class Resources;
//
/*!
 * \brief The Plugin class
 * Класс интерфейса плагина.
 */
struct Version{
    uint major;
    uint minor;
    uint patch;
    uint build;
    Version(QString ver){
        QStringList list = ver.split(".", QString::SkipEmptyParts);
        major = list.at(0).toUInt();
        minor = list.at(1).toUInt();
        patch = list.at(2).toUInt();
        build = list.at(3).toUInt();
    }
    Version(uint _major = 0, uint _minor = 0, uint _patch = 0, uint _build = 0){
        major = _major;
        minor = _minor;
        patch = _patch;
        build = _build;
    }
};

struct PluginInfo
{
    QString name;
    Version version;
    QString description;
    QStringList depend;
    //
    PluginInfo(QString _name, Version _version, QString _description, QStringList _depend){
        name = _name;
        version = _version;
        description = _description;
        depend = _depend;
    }
};

class ASU_CORE Plugin
{
public:
    virtual ~Plugin(){}
    virtual void init() = 0;
    virtual PluginInfo info() const = 0;
};
//
Q_DECLARE_INTERFACE(Plugin, "com.str.asu.work.plugin/1.0")
//
} //END_NAMESPACE
//
#endif // PLUGIN_H
