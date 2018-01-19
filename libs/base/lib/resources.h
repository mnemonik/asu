#ifndef RESOURCES_H
#define RESOURCES_H
//
#include <QObject>
#include <QStringList>
#include <QHash>
#include <QMutex>
#include <QHash>
#include <QStringList>
#include <QSemaphore>
//
#include "lib_base.h"
//
namespace Z {
//
//class Logger;

/*!
 * \class Resources
 * \brief Класс представляет собой коллекцию именованных ресурсов.
    Он предоставляет средства работы с ресурсами службы.
    После загрузки службы в коллекции присутствуют следующие объекты:
logger - объект класса Logger;
core - объект класса Core;
config - объект класса Config;
... - ресурсы, которые плагины регистрируют при загрузке
    (и которые обязаны корректно уничтожить при выгрузке)
 */
class ASU_BASE Resources: public QObject
{
    Q_OBJECT
private: //Реализация синглтона
    Resources(QObject* parent = 0, const int _avail = 10000);
    Q_DISABLE_COPY(Resources);
    static Resources* _instance;
public:
    ~Resources();
    static Resources* instance(QObject* _parent = 0);

public Q_SLOTS:
    /*!
     * \fn add
     * \brief Добавление ресурса.
     * \param QString name - имя ресурса
     * \param QObject* resource - ссылка на ресурс
     * \return bool - результат выполнения
     */
    bool add(const QString& name, QObject* resource);

    /*!
     * \fn remove
     * \brief Удаление ресурса.
     * \param QString name - имя ресурса
     * \return boolean - результат выполнения
     */
    bool remove(const QString& name);

    /*!
     * \fn get
     * \brief Возвращает указатель на именованый ресурс коллекции.
     * \param QString name - имя ресурса
     * \return QObject* указатель на ресурс
     */
    QObject* get(const QString& name, QObject* def = NULL);

    /*!
     * \fn list
     * \brief Список доступных ресурсов
     * \param bool _use = false Список всех доступных ресурсов, или список ресурсов которые используются (не высвобождены).
     * \return QStringList
     */
    QStringList list(const bool& _use = false) const;

    /*!
     * \fn acquire
     * \brief Пометить ресурс используемым (захватить ресурс).
     * \param QString name - имя ресурса
     * \return boolean - результат выполнения
     */
    bool acquire(const QString& name);

    /*!
     * \fn release
     * \brief Снять отметку использования (освободить ресурс).
     * \param QString name - имя ресурса
     * \return boolean - результат выполнения
     */
    bool release(const QString& name);

public:
    // Даем возможность вызова get<T>(QString)
    template<typename T> T get(const QString& name)
    {
        QMutexLocker locker(&lock);
        return(qobject_cast<T>(get(name)));
    }

private:
    //! \brief lock - используется при обращении к ресурсам
    mutable QMutex lock;
    //! \brief hash - ссылки на добавленные объекты
    QHash<QString, QObject*> hash;
    //! \brief counter - счетчик захватов объекта
    QHash<QString, int> counter;
    //! \brief avail - максимум
    int avail;
};
//
} //END_NAMESPACE
//
#endif // RESOURCES_H
