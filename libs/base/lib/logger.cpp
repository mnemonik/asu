#include <QDir>
#include <QDebug>
#include <QCoreApplication>
#include <QDateTime>
#include "config.h"
#include "logger.h"

using namespace Z;

Logger* Logger::_instance = 0;
const QString Logger::RES = "logger";
const QString Logger::LOG_DIRECTORY = "log_directory";
const QString Logger::LOG_FILENAME = "log_filename";
const QString Logger::LOG_TRUNCATE = "log_truncate";
const QString Logger::LOG_LEVEL = "log_level";
const QString Logger::LOG_APPEND = "log_append";
const QString Logger::LOG_PREPEND = "log_prepend";
const QString Logger::LOG_LINE = "log_line";
const QString Logger::LOG_ROTATION_AGE = "log_rotation_age";
const QString Logger::LOG_ROTATION_SIZE = "log_rotation_size";
const QString Logger::LOG_ROTATION_CMD = "log_rotation_cmd";

void myMessageOutput(QtMsgType t, const QMessageLogContext& context, const QString &msg)
{
    Logger* log = Logger::instance();
    if(!log)
        return;

    Logger::MsgType type;
    if(t == QtDebugMsg) type = Logger::DebugMsg;
    else if(t == QtWarningMsg) type = Logger::WarningMsg;
    else if(t == QtCriticalMsg) type = Logger::CriticalMsg;
    else if(t == QtFatalMsg) type = Logger::FatalMsg;
    else type = Logger::DebugMsg;

    log->message(msg, type, context);
}

Logger::Logger(QObject* _parent)
    :   QObject(_parent),
        conf(0),
        log_directory("/logs/"),
        log_filename("%a.log"),
        log_truncate(true),
//#ifdef QT_DEBUG
        log_level(TraceMsg),
//#else
//        log_level(ErrorMsg),
//#endif
        log_line("[%p] %t (%l) %m (%s:%d %f) %c"),
        log_rotation_age(24*60*60), // 1day
        log_rotation_size(10*1024*1024), // 10Mb
        log_rotation_cmd("bzip2 -z -9 %1")
{
    setObjectName(Logger::RES);
    qInstallMessageHandler(myMessageOutput);

    conf = Config::instance();
    //
    if(conf){
        setLevel(conf->get(Logger::LOG_LEVEL).toString());
//        setDirectory(conf->value(Logger::LOG_DIRECTORY, log_directory).toString());
//        setFileName(conf->value(Logger::LOG_FILENAME).toString());
//        setTruncate(conf->value(Logger::LOG_TRUNCATE).toString());
//        setAppend(conf->value(Logger::LOG_APPEND).toString());
//        setPrepend(conf->value(Logger::LOG_PREPEND).toString());
//        setLine(conf->value(Logger::LOG_LINE).toString());
//        setRotateAge(conf->value(Logger::LOG_ROTATION_AGE).toString());
//        setRotateSize(conf->value(Logger::LOG_ROTATION_SIZE).toString());
//        setRotateCommand(conf->value(Logger::LOG_ROTATION_CMD).toString());
    }
    //
    file = new QFile();
    QString filename = genLogFileName();
    file->setFileName(filename);
    if(!file->open(QIODevice::WriteOnly | QIODevice::Text | (log_truncate ? QIODevice::Truncate : QIODevice::Append)))
    {
        //zCritical(tr("%1: could not open file %2 for loging: %3").arg(objectName()).arg(filename).arg(file->errorString()));
    }
    writeLog(log_append);
}

Logger::~Logger()
{
    if(file->isOpen())
    {
        writeLog(log_prepend);
        QString s = file->fileName();
        file->close();
//        if(!rotateCmd.isEmpty())
//            rotateCommand(s);
    }
//    if(coutRedirector)
//        delete coutRedirector;
//    if(cerrRedirector)
//        delete cerrRedirector;
    delete file;
    _instance = 0;
}

// TODO: ADD CONG IN INIT
// TODO: ADD EMIT IN CHANGE PARAM
Logger* Logger::instance(QObject *_parent){
    if(_instance==0) _instance = new Logger(_parent);
    Q_ASSERT_X(_instance, "_instance", "is not null");
    return _instance;
}

bool Logger::setLevel(const QString& _s, bool _f){
    if(_s.isEmpty()) return false;
    if(_s == "trace") log_level = TraceMsg;
    else if(_s == "debug") log_level = DebugMsg;
    else if(_s == "log") log_level = LogMsg;
    else if(_s == "info") log_level = InfoMsg;
    else if(_s == "notice") log_level = NoticeMsg;
    else if(_s == "warning") log_level = WarningMsg;
    else if(_s == "error") log_level = ErrorMsg;
    else if(_s == "critical") log_level = CriticalMsg;
    else if(_s == "fatal") log_level = FatalMsg;
    else{
        zDebug(tr("%1: %2 неверное значение %3").arg(objectName()).arg(Logger::LOG_LEVEL).arg(_s));
        return false;
    }
    if(_f && conf) conf->set(Logger::LOG_FILENAME, _s);
    return true;
}

//bool Logger::setDirectory(const QString& _s, bool _f){
//    if(_s.isEmpty()) return false;
//    log_directory = _s;
//    if(_f) conf->set(Logger::LOG_DIRECTORY, _s);
//    return true;
//}

//bool Logger::setFileName(const QString& _s, bool _f){
//    if(_s.isEmpty()) return false;
//    log_filename = _s;
//    if(_f) conf->set(Logger::LOG_FILENAME, _s);
//    return true;
//}

//bool Logger::setTruncate(const QString& _s, bool _f){
//    if(_s.isEmpty()) return false;
//    if(_s == "true" || _s == "on" || _s == "1") log_truncate = true;
//    else if(_s == "false" || _s == "off" || _s == "1") log_truncate = false;
//    else{
//        qWarning() << tr("%1: %2 неверное значение %3").arg(objectName()).arg(Logger::LOG_TRUNCATE).arg(_s);
//        return false;
//    }
//    if(_f) conf->set(Logger::LOG_TRUNCATE, _s);
//    return true;
//}

//bool Logger::setAppend(const QString& _s, bool _f){
//    if(_s.isEmpty()) return false;
//    log_append = _s;
//    if(_f) conf->set(Logger::LOG_APPEND, _s);
//    return true;
//}

//bool Logger::setPrepend(const QString &_s, bool _f)
//{
//    if(_s.isEmpty()) return false;
//    log_prepend = _s;
//    if(_f) conf->set(Logger::LOG_PREPEND, _s);
//    return true;
//}

//bool Logger::setLine(const QString& _s, bool _f){
//    if(_s.isEmpty()) return false;
//    log_line = _s;
//    if(_f) conf->set(Logger::LOG_LINE, _s);
//    return true;
//}

//bool Logger::setRotateAge(const QString& _s, bool _f){
//    if(_s.isEmpty()) return false;
//    return false;
//    log_rotation_age = _s;
//    if(_f) conf->set(Logger::LOG_ROTATION_AGE, _s);
//    return true;
//}

//bool Logger::setRotateSize(const QString& _s, bool _f){
//    if(_s.isEmpty()) return false;
//    return false;
//    log_rotation_size = _s;
//    if(_f) conf->set(Logger::LOG_ROTATION_SIZE, _s);
//    return true;
//}

//bool Logger::setRotateCommand(const QString& _s, bool _f){
//    if(_s.isEmpty()) return false;
//    return false;
//    log_rotation_cmd = _s;
//    if(_f) conf->set(Logger::LOG_ROTATION_CMD, _s);
//    return true;
//}

QString Logger::genLogFileName()
{
    QString filename = qApp->applicationDirPath() + log_directory;
    QDir dir(filename);
    if(!dir.exists())
    {
        //dir.setPath(qApp->applicationDirPath());
        if(!dir.mkdir(qApp->applicationDirPath() + log_directory))
            qCritical() << tr("%1: could not create logs directory.").arg(objectName());
    }

    filename += log_filename;
    filename.replace("%a", QFileInfo(QCoreApplication::applicationFilePath()).baseName());
    filename.replace("%y", QDateTime::currentDateTime().toString("yyyy"));
    filename.replace("%m", QDateTime::currentDateTime().toString("MM"));
    filename.replace("%d", QDateTime::currentDateTime().toString("dd"));
    filename.replace("%h", QDateTime::currentDateTime().toString("hh"));
    filename.replace("%i", QDateTime::currentDateTime().toString("mm"));
    filename.replace("%s", QDateTime::currentDateTime().toString("ss"));

    return filename;
}

void Logger::writeLog(const QString& msg)
{
    if(file->isOpen())
    {
        qint64 wrote = file->write(msg.toLocal8Bit());
        file->flush();
//        if(wrote != -1)
//            lastSize += wrote;
//        if(rotateTime)
//            checkRotateTime();
//        if(rotateSize)
//            checkRotateSize();
    }
    else
    {
        //std::cout << msg.toStdString() << std::flush;
    }
}

const char* Logger::message(const QString& msg, const MsgType& type, const QMessageLogContext& context){
    if(type >= log_level)
    {
        QString str = log_line;
        str.replace("%t", QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
        str.replace("%p", QString::number(QCoreApplication::applicationPid()));
        str.replace("%l", MsgTypeToString(type));
        str.replace("%s", context.file);
        str.replace("%d", QString::number(context.line));
        str.replace("%f", context.function);
        str.replace("%c", context.category);
        str.replace("%m", msg);
        str += "\n";
        writeLog(str);
    }
    return msg.toLocal8Bit().data();
}

QString Logger::MsgTypeToString(const MsgType& type){
    if(type == TraceMsg) return "T";
    else if(type == DebugMsg) return "D";
    else if(type == LogMsg) return "L";
    else if(type == InfoMsg) return "I";
    else if(type == NoticeMsg) return "N";
    else if(type == WarningMsg) return "W";
    else if(type == ErrorMsg) return "E";
    else if(type == CriticalMsg) return "C";
    else if(type == FatalMsg) return "F";
    return "";
}
