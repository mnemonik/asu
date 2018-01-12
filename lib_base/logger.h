#ifndef LOGGER_H
#define LOGGER_H
//
#include <QObject>
#include <QSettings>
#include <QFile>
#include <QCoreApplication>
//
#include "lib_base.h"
//
QT_FORWARD_DECLARE_CLASS(Config)
QT_BEGIN_NAMESPACE
//
/*!
 * \brief The Logger class
 * Класс журналирования событий. Журналирование поддерживает ротацию,
 * уровень журналирования, а так же исполнение команды для устаревшего
 * файла журнала (после ротации). При использовании стандартных
 * средств С++ (cout, cerr) и Qt (qDebug, qWarning и т.д.) сообщения
 * так же будут попадать в файлы журнала! Смотри конфигурационный файл
 * для настройки журнала.
 */
class ASU_RES Logger : public QObject
{
Q_OBJECT
public:
    enum MsgType
    {
        TraceMsg = 0,
        DebugMsg = 1,
        LogMsg = 2,
        InfoMsg = 3,
        NoticeMsg = 4,
        WarningMsg = 5,
        ErrorMsg = 6,
        CriticalMsg = 7,
        FatalMsg = 8
    };
    static QString MsgTypeToString(const MsgType& type);
private:
    Logger(QObject* _parent = 0);
    Q_DISABLE_COPY(Logger);
    static Logger* _instance;
public:
    ~Logger();
    static Logger* instance(QObject* _parent = 0);

public:
    static const QString RES;
    static const QString LOG_DIRECTORY;
    static const QString LOG_FILENAME;
    static const QString LOG_TRUNCATE;
    static const QString LOG_LEVEL;
    static const QString LOG_APPEND;
    static const QString LOG_PREPEND;
    static const QString LOG_LINE;
    static const QString LOG_ROTATION_AGE;
    static const QString LOG_ROTATION_SIZE;
    static const QString LOG_ROTATION_CMD;
private:
    QString log_directory;
    QString log_filename;
    bool log_truncate;
    MsgType log_level;
    QString log_append;
    QString log_prepend;
    QString log_line;
    int log_rotation_age;
    qint64 log_rotation_size;
    QString log_rotation_cmd;

private:
    //Писать сообщение в лог вне зависимости от уровня логирования
    void writeLog(const QString& msg);

public slots:
    //Писать сообщение в лог
    const char* message(const QString& msg, const MsgType& type = DebugMsg, const QMessageLogContext& context = QMessageLogContext());
    //Изменение уровня журналирования
    bool setLevel(const QString& _s, bool _f = false);
//
//    bool setDirectory(const QString& _s, bool _f = false);
//    bool setFileName(const QString& _s, bool _f = false);
//    bool setTruncate(const QString& _s, bool _f = false);
//    bool setAppend(const QString& _s, bool _f = false);
//    bool setPrepend(const QString& _s, bool _f = false);
//    bool setLine(const QString& _s, bool _f = false);
//Установка времени ротации журнала
//    bool setRotateAge(const QString& _s, bool _f = false);
//Установка размера ротации журнала
//    bool setRotateSize(const QString& _s, bool _f = false);
    //Установка команды, которая будет применена к файлу журнала
    //после ротации. Первый элемент - команда, далее - аргументы.
    //строка "%file%" в аргументах будет заменена на имя файла журнала
    //с полным путем, к которому применяется команда.
    //bool setRotateCommand(const QString& _s, bool _f = false);
    //Перенаправление стандартных потоков вывода в журнал
    //void redirectCoutCerrToLog(const bool& enable);

private:
    Config* conf;
    QString genLogFileName();
    QFile* file;
};
//
QT_END_NAMESPACE
//
#if defined(UNICODE)
//    #define zStr(__msg) (wchar_t*)__msg.utf16()
    #define zStr(__msg) __msg.toLocal8Bit().data()
#else
    #define zStr(__msg) __msg.toLocal8Bit().data()
#endif
//
#define zFatal(__msg) qFatal(__msg);
#define zAssert(__cond, __msg) if(!__cond) zFatal(__msg);
//
//#if defined(QT_DEBUG)
    #define zLog(__msg, __type) QT_PREPEND_NAMESPACE(Logger)::instance()->message(__msg, __type, QMessageLogContext(__FILE__, __LINE__, __FUNCTION__, zStr(QT_PREPEND_NAMESPACE(Logger)::MsgTypeToString(__type))))
//#else
//    #define zLog(__msg, __type) ""
//#endif
    #define zTrace(__msg) zLog(__msg, QT_PREPEND_NAMESPACE(Logger)::TraceMsg)
    #define zDebug(__msg) zLog(__msg, QT_PREPEND_NAMESPACE(Logger)::DebugMsg)
    #define zInfo(__msg) zLog(__msg, QT_PREPEND_NAMESPACE(Logger)::InfoMsg)
    #define zNotice(__msg) zLog(__msg, QT_PREPEND_NAMESPACE(Logger)::NoticeMsg)
    #define zWarning(__msg) zLog(__msg, QT_PREPEND_NAMESPACE(Logger)::WarningMsg)
    #define zError(__msg) zLog(__msg, QT_PREPEND_NAMESPACE(Logger)::ErrorMsg)
    #define zCritical(__msg) zLog(__msg, QT_PREPEND_NAMESPACE(Logger)::CriticalMsg)
    //
    #define zGroup(__name) zLog(tr("GROUP BEGIN %1").arg(__name), QT_PREPEND_NAMESPACE(Logger)::TraceMsg);
    #define zGroupEnd(__name) zLog(tr("GROUP END %1").arg(__name), QT_PREPEND_NAMESPACE(Logger)::TraceMsg);
//
#endif // LOGGER_H
