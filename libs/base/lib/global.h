#ifndef GLOBAL_H
#define GLOBAL_H
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
class ASU_BASE Global : private QSettings
{
    Q_OBJECT
private:
    Global(QObject* _parent = 0);
    Q_DISABLE_COPY(Global);
    static Global* _instance;
public:
    ~Global();
    static Global* instance(QObject* _parent = 0);
public:
    static const QString RES;
    static const QString PATH;
    static const QString URL;
public Q_SLOTS:
    /*!
     * \brief save dsfdfsdfsdfdsf
     */
    void save();
    void set(const QString &key, const QVariant &value);
    QVariant get(const QString &key, const QVariant &defaultValue = QVariant()) const;
};
//
} //END_NAMESPACE
//
#endif // GLOBAL_H
