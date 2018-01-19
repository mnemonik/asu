#ifndef CONFIG_H
#define CONFIG_H
//
#include <QObject>
#include <QString>
#include <QVariant>
#include <QSettings>
//
#include "lib_base.h"
//
namespace Z {
//
/*!
 * \brief Класс для чтения конфигурационного файла.
 */
class ASU_BASE Config : public QObject
{
    Q_OBJECT
private:
    Config(QObject* _parent = 0);
    Q_DISABLE_COPY(Config);
    static Config* _instance;
public:
    ~Config();
    static Config* instance(QObject* _parent = 0);
public:
    static const QString RES;
public Q_SLOTS:
    //
    void save();
    void set(const QString &key, const QVariant &value);
    QVariant get(const QString &key, const QVariant &defaultValue = QVariant()) const;
private:
    QSettings* sf;
};
//
} //END_NAMESPACE
//
#endif // CONFIG_H
