#ifndef LOCKEDFILE_H
#define LOCKEDFILE_H
//
#include "lib_core.h"
//
#include <QFile>
#ifdef Q_OS_WIN
    #include <QVector>
#endif
//
ASU_BEGIN_NAMESPACE
//
class ASU_CORE LockedFile : public QFile
{
public:
    enum LockMode { NoLock = 0, ReadLock, WriteLock };

    LockedFile();
    LockedFile(const QString &name);
    ~LockedFile();

    bool open(OpenMode mode);

    bool lock(LockMode mode, bool block = true);
    bool unlock();
    bool isLocked() const;
    LockMode lockMode() const;

private:
#ifdef Q_OS_WIN
    Qt::HANDLE wmutex;
    Qt::HANDLE rmutex;
    QVector<Qt::HANDLE> rmutexes;
    QString mutexname;

    Qt::HANDLE getMutexHandle(int idx, bool doCreate);
    bool waitMutex(Qt::HANDLE mutex, bool doBlock);

#endif
    LockMode m_lock_mode;
};
//
ASU_END_NAMESPACE
//
#endif // LOCKEDFILE_H
