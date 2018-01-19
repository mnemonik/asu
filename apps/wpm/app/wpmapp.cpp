/*#include <QTextCodec>
#include <QFile>
#include <QFileInfo>
#include <QTextStream>
#include <QProcess>
#include <QThread>
#include <QCoreApplication>
#include <QFileInfo>
/*
#include "wpmapp.h"
#include "common.h"
#include "runthread.h"
#include "conctrl.h"
#include "app.h"

#include "windows.h"

using namespace Z;

const QString WpmApp::CONF_SERVICE_NAME = "service/name";
const QString WpmApp::CONF_SERVICE_DESC = "service/desc";
const QString WpmApp::CONF_SERVICE_USER = "service/user";
const QString WpmApp::CONF_SERVICE_PSWD = "service/pswd";
const QString WpmApp::CONF_SERVICE_DEPS = "service/deps";
const QString WpmApp::CONF_GLOBAL_DIR   = "global/dir";
const QString WpmApp::CONF_GLOBAL_USER  = "global/user";
const QString WpmApp::CONF_GLOBAL_PSWD  = "global/pswd";

const QString WpmApp::APP  = "app";
const QString WpmApp::SRV  = "srv";

WpmApp::WpmApp(int argc, char *argv[]) :
    QCoreApplication(argc, argv), res(0), conf(0), core(0), thread(0), launch(false)
{
    QTextCodec *locale = QTextCodec::codecForName(APP_LOCALE);
    QTextCodec::setCodecForLocale(locale);
    //
    zTrace(tr("Кодировка %1").arg(GetConsoleOutputCP()));
#if defined(Q_OS_WIN)
    if(GetConsoleOutputCP() == 866)
        ::SetConsoleOutputCP(1251);
    zTrace(tr("Новая кодировка %1").arg(GetConsoleOutputCP()));
#endif
    //
    zInfo(tr("Запуск приложения с %1 параметрами").arg(argc));
    initApp();
    initRes();
    initConf();
    initCore();
    initService();
    parseArgs();
}

void WpmApp::initApp()
{
    zInfo(tr("Инициализация приложения"));
    QCoreApplication::setOrganizationName(ORG_NAME);
    QCoreApplication::setOrganizationDomain(ORG_SITE);
    QCoreApplication::setApplicationName(APP_NAME);
    QCoreApplication::setApplicationVersion(tr("%1.%2.%3.%4").arg(APP_VER_MAJOR).arg(APP_VER_MINOR).arg(APP_VER_PATCH).arg(APP_VER_BUILD));
}

bool WpmApp::parseArg(const QString &arg, const QString &key, QString &val)
{
    zTrace(tr("\t%1 = %4 {left : %2, right : %3}").arg(key).arg(arg.section('=', 0, 0)).arg(arg.section('=', 1)).arg(arg.section('=', 0, 0) == key ? "true" : "false"));
    if(arg.section('=', 0, 0) == key){
        val = arg.section('=', 1);
        return true;
    }
    return false;
}

void WpmApp::parseArgs()
{
    zInfo(tr("Разбор переданных параметров"));
    QStringList args = arguments();
    //
    file = args.at(0);
    zError(tr("%1").arg(file));
    //
    if(args.size() > 1)
    {
        QString arg = args.at(1);
        QString vl;
        //
        if(this->parseArg(arg, "--help", vl)
         ||this->parseArg(arg, "/?", vl)){
            this->launch = false;
            this->showHelp();
            std::exit(EXIT_SUCCESS);
            return;
        }
        //
        if(this->parseArg(arg, "--init", vl)){
            if(!vl.isEmpty()){
                std::cout << zTrace(tr("Неверное использование команды")) << std::endl;
                std::exit(EXIT_FAILURE);
                return;
            }
            //
            std::cout << tr("Введите конфигурацию:").toLocal8Bit().data() << std::endl;
            std::cout << zStr(tr("Имя сервиса (По умолчанию: %1)").arg(srv->name));
            char _name[256]; std::cin.getline(_name, sizeof(_name));
            conf->set(WpmApp::CONF_SERVICE_NAME, strlen(_name)?_name:srv->name);
            std::cout << zStr(tr("Описание сервиса (%1):").arg(srv->desc));
            char _desc[256]; std::cin.getline(_desc, sizeof(_desc));
            conf->set(WpmApp::CONF_SERVICE_DESC, strlen(_desc)?_desc:srv->desc);
            std::cout << zStr(tr("Пользователь ОС (%1):").arg(srv->user));
            char _user[256]; std::cin.getline(_user, sizeof(_user));
            conf->set(WpmApp::CONF_SERVICE_USER, strlen(_user)?_user:srv->user);
            std::cout << zStr(tr("Пароль пользователя (%1):").arg(srv->pswd));
            char _pswd[256]; std::cin.getline(_pswd, sizeof(_pswd));
            conf->set(WpmApp::CONF_SERVICE_PSWD, strlen(_pswd)?_pswd:srv->pswd);
            std::cout << zStr(tr("Зависимости службы (%1):").arg(srv->deps));
            char _deps[256]; std::cin.getline(_deps, sizeof(_deps));
            conf->set(WpmApp::CONF_SERVICE_DEPS, strlen(_deps)?_deps:srv->deps);
            std::cout << zStr(tr("Каталог приложений (%1):").arg(this->dir));
            char _adir[256]; std::cin.getline(_adir, sizeof(_adir));
            conf->set(WpmApp::CONF_GLOBAL_DIR, strlen(_adir)?_adir:this->dir);
            std::cout << zStr(tr("Пользователь приложения (%1):").arg(this->user));
            char _auser[256]; std::cin.getline(_auser, sizeof(_auser));
            conf->set(WpmApp::CONF_GLOBAL_USER, strlen(_auser)?_auser:this->user);
            std::cout << zStr(tr("Пароль пользователя (%1):").arg(this->pswd));
            char _apswd[256]; std::cin.getline(_apswd, sizeof(_apswd));
            conf->set(WpmApp::CONF_GLOBAL_PSWD, strlen(_apswd)?_apswd:this->pswd);
            conf->save();
        }else if(this->parseArg(arg, "--reg", vl)){
            if(!vl.isEmpty()){
                std::cout << zTrace(tr("Неверное использование команды")) << std::endl;
                std::exit(EXIT_FAILURE);
                return;
            }
            //
            srv->path = tr("%1 --dir=%2 --user=%3 --password=%4").arg(this->file).arg(this->dir).arg(this->user).arg(this->pswd);
            code = this->ServiceReg();
            //
        }else if(this->parseArg(arg, "--unreg", vl)){
            if(!vl.isEmpty()){
                std::cout << zTrace(tr("Неверное использование команды")) << std::endl;
                std::exit(EXIT_FAILURE);
                return;
            }
            //
            code = this->ServiceUnreg();
            //
        }else if(this->parseArg(arg, "--start", vl)){
            if(!vl.isEmpty()){
                std::cout << zTrace(tr("Неверное использование команды")) << std::endl;
                std::exit(EXIT_FAILURE);
                return;
            }
            //
            code = this->ServiceStart();
        }else if(this->parseArg(arg, "--stop", vl)){
            if(!vl.isEmpty()){
                std::cout << zTrace(tr("Неверное использование команды")) << std::endl;
                std::exit(EXIT_FAILURE);
                return;
            }
            //
            code = this->ServiceStop();
        }else if(this->parseArg(arg, "--status", vl)){
            if(!vl.isEmpty()){
                std::cout << zTrace(tr("Неверное использование команды")) << std::endl;
                std::exit(EXIT_FAILURE);
                return;
            }
            //
            code = this->ServiceStatus();
        }else if(this->parseArg(arg, "--pause", vl)){
            if(!vl.isEmpty()){
                std::cout << zTrace(tr("Неверное использование команды")) << std::endl;
                std::exit(EXIT_FAILURE);
                return;
            }
            //
            code = this->ServicePause();
        }else if(this->parseArg(arg, "--resume", vl)){
            if(!vl.isEmpty()){
                std::cout << zTrace(tr("Неверное использование команды")) << std::endl;
                std::exit(EXIT_FAILURE);
                return;
            }
            //
            code = this->ServiceResume();
        }else if(this->parseArg(arg, "--list", vl)
               ||this->parseArg(arg, "-l", vl)){
            code = this->ServiceList(vl);
        }else if(this->parseArg(arg, "--install", vl)
               ||this->parseArg(arg, "-i", vl)){
            if(vl.isEmpty()){
                std::cout << zTrace(tr("Ошибка: Нет обязательного параметра")) << std::endl;
                std::exit(EXIT_FAILURE);
                return;
            }
            //
            code = this->ServiceInstall(vl);
        }else if(this->parseArg(arg, "--uninstall", srv->app)
               ||this->parseArg(arg, "-u", srv->app)){
            if(srv->app.isEmpty()){
                std::cout << zTrace(tr("Ошибка: Нет обязательного параметра")) << std::endl;
                std::exit(EXIT_FAILURE);
                return;
            }
            //
            code = this->ServiceUninstall(srv->app);
        }else if(this->parseArg(arg, "--check", srv->app)){
            if(srv->app.isEmpty()){
                std::cout << zTrace(tr("Ошибка: Нет обязательного параметра")) << std::endl;
                std::exit(EXIT_FAILURE);
                return;
            }
            //
            code = this->ServiceCheck(srv->app);
        }else if(this->parseArg(arg, "--update", srv->app)){
            if(srv->app.isEmpty()) code = this->ServiceUpdateAll();
            else code = this->ServiceUpdate(srv->app);
        }else if(this->parseArg(arg, "--run", srv->app)
               ||this->parseArg(arg, "-r", srv->app)){
            if(srv->app.isEmpty()){
                std::cout << zTrace(tr("Ошибка: Нет обязательного параметра")) << std::endl;
                std::exit(EXIT_FAILURE);
                return;
            }
            //
            code = this->ServiceRun(srv->app);
        }else{
            runGUI();
        }
        zTrace(tr("std::exit"));
        std::exit(EXIT_SUCCESS);
    }
}

void WpmApp::quitApp(int code)
{
    zInfo(tr("Выход %1").arg(code));
    std::exit(code);
}

void WpmApp::initConf()
{
    zDebug(tr("Инициализация конфигурации"));
    conf = Config::instance(this);
    if(!conf){
        zCritical(tr("Не могу создать конфигурацию"));
        std::exit(EXIT_FAILURE);
    }else{
//        if(config.isEmpty())
//            config = QFileInfo(QCoreApplication::applicationFilePath()).baseName()+".conf";
//        conf->load(config);
    }
}

void WpmApp::initRes()
{
    zDebug(tr("Инициализация ресурсов"));
    res = Resources::instance(this);
    if(!res){
        zCritical(tr("Не могу создать ресурсы"));
        std::exit(EXIT_FAILURE);
    }
    res->add(WpmApp::APP, this);
}

void WpmApp::initCore()
{
    zDebug(tr("Инициализация ядра"));
    core = Core::instance(this);
    if(!core){
        zCritical(tr("Не могу создать ядро"));
        std::exit(EXIT_FAILURE);
    }
}

void WpmApp::initService()
{
    zDebug(tr("Инициализация службы"));
    srv = Service::instance();
    if(!srv){
        zCritical(tr("Не могу создать службу"));
        std::exit(EXIT_FAILURE);
    }
    this->dir = conf->get(WpmApp::CONF_GLOBAL_DIR, "apps/").toString();
    this->user= conf->get(WpmApp::CONF_GLOBAL_USER, "").toString();
    this->pswd= conf->get(WpmApp::CONF_GLOBAL_PSWD, "").toString();
    srv->name = conf->get(WpmApp::CONF_SERVICE_NAME, APP_NAME).toString();
    srv->desc = conf->get(WpmApp::CONF_SERVICE_DESC, APP_DESC).toString();
    srv->user = conf->get(WpmApp::CONF_SERVICE_USER, "NT AUTHORITY\\NetworkService").toString();
    srv->pswd = conf->get(WpmApp::CONF_SERVICE_PSWD, "").toString();
    srv->deps = conf->get(WpmApp::CONF_SERVICE_DEPS, "").toString();
    zTrace(tr("file %1").arg(this->file));
    zTrace(tr("user %1").arg(this->user));
    zTrace(tr("pswd %1").arg(this->pswd));
    zTrace(tr("name %1").arg(srv->name));
    zTrace(tr("desc %1").arg(srv->desc));
    zTrace(tr("path %1").arg(srv->path));
    zTrace(tr("deps %1").arg(srv->deps));
    zTrace(tr("user %1").arg(srv->user));
    zTrace(tr("pswd %1").arg(srv->pswd));
    res->add(WpmApp::SRV, srv);
}

//! Запуск GUI приложения
void WpmApp::runGUI(){
    zTrace(tr("Запуск графического приложения"));
//    QStringList arguments;
//    arguments << "key" << "value" << "k=v";
    QProcess process;
    process.startDetached(APP_FILE_GUI);
}

int WpmApp::ServiceReg()
{
    std::cout << zTrace(tr("Регистрация сервиса в системе")) << std::endl;
    //
    ConsoleController ctrl;
    int code = srv->work(SLOT(install()), ctrl);
    if(code == ERROR_CANCELLED){
        std::cout << zInfo(tr("Отмена операции")) << std::endl;
    } else if(code == NO_ERROR){
        std::cout << zInfo(tr("Сервис %1 устанавился").arg(srv->name)) << std::endl;
    } else {
        std::cout << zInfo(tr("Ошибка установки сервиса %1").arg(srv->name)) << std::endl;
        std::cout << srv->ErrorMessage(code).toLocal8Bit().data() << std::endl;
    }
    return code;
}

int WpmApp::ServiceUnreg()
{
    std::cout << zTrace(tr("Удаление сервиса из системы")) << std::endl;
    //
    ConsoleController ctrl;
    int code = srv->work(SLOT(uninstall()), ctrl);
    if(code == ERROR_CANCELLED){
        std::cout << zInfo(tr("Отмена операции")) << std::endl;
    } else if(code == NO_ERROR){
        std::cout << zInfo(tr("Сервис %1 удалился").arg(srv->name)) << std::endl;
    } else {
        std::cout << zInfo(tr("Ошибка удаления сервиса %1").arg(srv->name)) << std::endl;
        std::cout << srv->ErrorMessage(code).toLocal8Bit().data() << std::endl;
    }
    return code;
}

int WpmApp::ServiceStart()
{
    std::cout << zTrace(tr("Запуск сервиса")) << std::endl;
    //
    ConsoleController ctrl;
    int code = srv->work(SLOT(start()), ctrl);
    if(code == ERROR_CANCELLED){
        std::cout << zInfo(tr("Отмена операции")) << std::endl;
    } else if(code == NO_ERROR){
        std::cout << zInfo(tr("Сервис %1 запущен").arg(srv->name)) << std::endl;
    } else {
        std::cout << zInfo(tr("Ошибка запуска сервиса %1").arg(srv->name)) << std::endl;
        std::cout << srv->ErrorMessage(code).toLocal8Bit().data() << std::endl;
    }
    return code;
}

int WpmApp::ServiceStop()
{
    std::cout << zTrace(tr("Остановка сервиса")) << std::endl;
    //
    ConsoleController ctrl;
    int code = srv->work(SLOT(stop()), ctrl);
    if(code == ERROR_CANCELLED){
        std::cout << zInfo(tr("Отмена операции")) << std::endl;
    } else if(code == NO_ERROR){
        std::cout << zInfo(tr("Сервис %1 остановлен").arg(srv->name)) << std::endl;
    } else {
        std::cout << zInfo(tr("Ошибка остановки сервиса %1").arg(srv->name)) << std::endl;
        std::cout << srv->ErrorMessage(code).toLocal8Bit().data() << std::endl;
    }
    return code;
}

int WpmApp::ServiceStatus()
{
    std::cout << zTrace(tr("Статус сервиса")) << std::endl;
    //
    ConsoleController ctrl;
    int code = srv->work(SLOT(status()), ctrl);
    if(code == ERROR_CANCELLED){
        std::cout << zInfo(tr("Отмена операции")) << std::endl;
    } else if(code == NO_ERROR){
        switch(srv->tStatus.dwCurrentState){
        case SERVICE_STOPPED: std::cout << zTrace(tr("Сервис %1 остановлен").arg(srv->name)) << std::endl; break;
        case SERVICE_START_PENDING: std::cout << zTrace(tr("Сервис %1 запускается").arg(srv->name)) << std::endl; break;
        case SERVICE_STOP_PENDING: std::cout << zTrace(tr("Сервис %1 останавливается").arg(srv->name)) << std::endl; break;
        case SERVICE_RUNNING: std::cout << zTrace(tr("Сервис %1 работает").arg(srv->name)) << std::endl; break;
        case SERVICE_CONTINUE_PENDING: std::cout << zTrace(tr("Сервис %1 возобновляется").arg(srv->name)) << std::endl; break;
        case SERVICE_PAUSE_PENDING: std::cout << zTrace(tr("Сервис %1 становится на паузу").arg(srv->name)) << std::endl; break;
        case SERVICE_PAUSED: std::cout << zTrace(tr("Сервис %1 на паузе").arg(srv->name)) << std::endl; break;
        }
        if(srv->tStatus.dwWin32ExitCode != NO_ERROR){
            if(srv->tStatus.dwWin32ExitCode != ERROR_SERVICE_SPECIFIC_ERROR){
                std::cout << zTrace(tr("Сервис %1 вернул специфическую ошибку %2").arg(srv->name).arg(srv->tStatus.dwServiceSpecificExitCode)) << std::endl;
            }else{
                std::cout << zTrace(tr("Сервис %1 вернул win32 ошибку %2").arg(srv->name).arg(srv->tStatus.dwWin32ExitCode)) << std::endl;
            }
        }
    } else {
        std::cout << zInfo(tr("Ошибка статуса сервиса %1").arg(srv->name)) << std::endl;
        std::cout << srv->ErrorMessage(code).toLocal8Bit().data() << std::endl;
    }
    return code;
}

int WpmApp::ServicePause()
{
    std::cout << zTrace(tr("Приостоновление сервиса")) << std::endl;
    //
    ConsoleController ctrl;
    int code = srv->work(SLOT(stop()), ctrl);
    if(code == ERROR_CANCELLED){
        std::cout << zInfo(tr("Отмена операции")) << std::endl;
    } else if(code == NO_ERROR){
        std::cout << zInfo(tr("Сервис %1 приостановлен").arg(srv->name)) << std::endl;
    } else {
        std::cout << zInfo(tr("Ошибка приостановки сервиса %1").arg(srv->name)) << std::endl;
        std::cout << srv->ErrorMessage(code).toLocal8Bit().data() << std::endl;
    }
    return code;
}

int WpmApp::ServiceResume()
{
    std::cout << zTrace(tr("Возобновление сервиса")) << std::endl;
    //
    ConsoleController ctrl;
    int code = srv->work(SLOT(stop()), ctrl);
    if(code == ERROR_CANCELLED){
        std::cout << zInfo(tr("Отмена операции")) << std::endl;
    } else if(code == NO_ERROR){
        std::cout << zInfo(tr("Сервис %1 возобновлен").arg(srv->name)) << std::endl;
    } else {
        std::cout << zInfo(tr("Ошибка возобновления сервиса %1").arg(srv->name)) << std::endl;
        std::cout << srv->ErrorMessage(code).toLocal8Bit().data() << std::endl;
    }
    return code;
}

int WpmApp::ServiceInstall(const QString& app)
{
    srv->app = app;
    std::cout << zTrace(tr("Установка приложения %1").arg(srv->app)) << std::endl;
    //
    ConsoleController ctrl;
    int code = srv->work(SLOT(install()), ctrl);
    if(code == ERROR_CANCELLED){
        std::cout << zInfo(tr("Отмена операции")) << std::endl;
    } else if(code == NO_ERROR){
        std::cout << zInfo(tr("Программа %1 устанавилась").arg(srv->app)) << std::endl;
    } else {
        std::cout << zInfo(tr("Ошибка: программа %1 не устанавливается").arg(srv->app)) << std::endl;
        std::cout << srv->ErrorMessage(code).toLocal8Bit().data() << std::endl;
    }
    return code;
}

int WpmApp::ServiceUninstall(const QString& app)
{
    srv->app = app;
    std::cout << zTrace(tr("Удаление приложения %1").arg(srv->app)) << std::endl;
    //
    ConsoleController ctrl;
    int code = srv->work(SLOT(uninstall()), ctrl);
    if(code == ERROR_CANCELLED){
        std::cout << zInfo(tr("Отмена операции")) << std::endl;
    } else if(code == NO_ERROR){
        std::cout << zInfo(tr("Программа %1 удалилась").arg(srv->app)) << std::endl;
    } else {
        std::cout << zInfo(tr("Ошибка: удаления программы %1").arg(srv->app)) << std::endl;
        std::cout << srv->ErrorMessage(code).toLocal8Bit().data() << std::endl;
    }
    return code;
}

int WpmApp::ServiceCheck(const QString& app)
{
    srv->app = app;
    std::cout << zTrace(tr("Проверка установленного приложения %1").arg(srv->app)) << std::endl;
    //
    ConsoleController ctrl;
    int code = srv->work(SLOT(check()), ctrl);
    if(code == ERROR_CANCELLED){
        std::cout << zInfo(tr("Отмена операции")) << std::endl;
    } else if(code == NO_ERROR){
        std::cout << zInfo(tr("Программа %1 прошла проверки").arg(srv->app)) << std::endl;
    } else {
        std::cout << zInfo(tr("Ошибка: проверки программы %1").arg(srv->app)) << std::endl;
        std::cout << srv->ErrorMessage(code).toLocal8Bit().data() << std::endl;
    }
    return code;
}

int WpmApp::ServiceUpdate(const QString &app)
{
    srv->app = app;
    std::cout << zTrace(tr("Обновление установленного приложения %1").arg(srv->app)) << std::endl;
    //
    ConsoleController ctrl;
    int code = srv->work(SLOT(update()), ctrl);
    if(code == ERROR_CANCELLED){
        std::cout << zInfo(tr("Отмена операции")) << std::endl;
    } else if(code == NO_ERROR){
        std::cout << zInfo(tr("Программа %1 обновилась").arg(srv->app)) << std::endl;
    } else {
        std::cout << zInfo(tr("Ошибка: обновления программы %1").arg(srv->app)) << std::endl;
        std::cout << srv->ErrorMessage(code).toLocal8Bit().data() << std::endl;
    }
    return code;
}

int WpmApp::ServiceUpdateAll()
{
    std::cout << zTrace(tr("Обновление всех установленных приложений")) << std::endl;
    ConsoleController ctrl;
    int code = srv->work(SLOT(update_all()), ctrl);
    if(code == ERROR_CANCELLED){
        std::cout << zInfo(tr("Отмена операции")) << std::endl;
    } else if(code == NO_ERROR){
        std::cout << zInfo(tr("Программа %1 обновилась").arg(srv->app)) << std::endl;
    } else {
        std::cout << zInfo(tr("Ошибка: обновления программы %1").arg(srv->app)) << std::endl;
        std::cout << srv->ErrorMessage(code).toLocal8Bit().data() << std::endl;
    }
    return code;
}

int WpmApp::ServiceList(const QString &app)
{
    srv->app = app;
    if(srv->app.isEmpty()){
        std::cout << zTrace(tr("Список установленных приложений")) << std::endl;
    }else if(srv->app == "*"){
        std::cout << zTrace(tr("Список доступных приложений")) << std::endl;
    }else if(srv->app == "!"){
        std::cout << zTrace(tr("Список доступных, но не установленных приложения")) << std::endl;
    }else {
        std::cout << zTrace(tr("Список приложений c фильтром по имени и описанию: %1").arg(srv->app)) << std::endl;
    }
    return code;
}

int WpmApp::ServiceRun(const QString &app)
{
    srv->app = app;
    std::cout << zTrace(tr("Запуск установленного приложения %1").arg(srv->app)) << std::endl;
    ConsoleController ctrl;
    int code = srv->work(SLOT(run()), ctrl);
    if(code == ERROR_CANCELLED){
        std::cout << zInfo(tr("Отмена операции")) << std::endl;
    } else if(code == NO_ERROR){
        std::cout << zInfo(tr("Программа %1 запутилась").arg(srv->app)) << std::endl;
    } else {
        std::cout << zInfo(tr("Ошибка: Программа %1 не запускается").arg(srv->app)) << std::endl;
        std::cout << srv->ErrorMessage(code).toLocal8Bit().data() << std::endl;
    }
    return code;
}

void WpmApp::showHelp()
{
    zInfo(tr("Вывод помощи приложения"));
    //
    QFile file(":/res/help.txt");
    QString str;
    if(file.open(QIODevice::ReadOnly))
    {
        QFileInfo info(APP_FILE);
        QTextStream stream(&file);
        str = stream.readAll().toLocal8Bit().data();
        std::cout << str.arg(ORG_NAME).arg(ORG_SITE).arg(ORG_COPY)
            .arg(APP_NAME).arg(APP_VER_MAJOR).arg(APP_VER_MINOR).arg(APP_VER_PATCH).arg(APP_VER_BUILD).arg(APP_DESC)
            .arg(APP_FILE)
            .toLocal8Bit().data();
        if(stream.status() != QTextStream::Ok){
            std::cout << zError(tr("Ошибка вывода помощи"));
        }
        file.close();
    }else{
        std::cout << zError(tr("Ошибка открытия файла помощи"));
    }
    //
}

void WpmApp::loadApps()
{
    zInfo(tr("Загрузить данные установленных приложений"));
}

/*


    switch(installApp(_v)){
    case APP_SUCCESS:
        std::cout << tr("Приложение %1 установлено успешно.").arg(_v).toLocal8Bit().data() << _NL;
        break;
    case APP_NOT_FOUND:
        std::cout << tr("Ошибка: Приложение %1 не найдено.").arg(_v).toLocal8Bit().data() << _NL;
        break;
    default:
        std::cout << tr("Ошибка: По неизвестным причинам приложение %1 не установлено.").arg(_v).toLocal8Bit().data() << _NL;
    }


    thread = new QThread(this);
    service->moveToThread(thread);
    service->setProperty("args", args);
    QObject::connect(thread, SIGNAL(started()), service, SLOT(reg()));
    QObject::connect(service, SIGNAL(finished()), thread, SLOT(quit()));
    QObject::connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    QObject::connect(thread, SIGNAL(finished()), this, SLOT(quitApp()));
    ConsoleController* cc = new ConsoleController();
    QObject::connect(service, SIGNAL(started()), cc, SLOT(started()));
    QObject::connect(service, SIGNAL(finished()), cc, SLOT(finished()));
    QObject::connect(service, SIGNAL(message(QString)), cc, SLOT(message(QString)));
//            std::cout << zTrace();
    thread->start();
}else if(oper == Service::OPER_UNREG){

//            LaunchThread* lt = new LaunchThread(service, SLOT(unreg()), new ConsoleController());
//            lt->start();
//            Service::instance(this)->install(args);
//            Service::instance(this)->uninstall(args);


    QString _conf("--conf");
    if(opt.startsWith(_conf)){
        zTrace(tr("Альтернативная конфигурация %1").arg(opt.mid(_conf.length())));
//        setConfig(opt.mid(_conf.length()));
    }
    //
    QString _url("--url");
    if(opt.startsWith(_url)){
        zTrace(tr("Альтернативный репозитарий %1").arg(opt.mid(_url.length())));
        //set*****(opt.mid(_url.length()));
    }
    //
    QString _user("--user");
    if(opt.startsWith(_user)){
        zTrace(tr("Установить пользователя (%1)").arg(opt.mid(_user.length())));
        //set*****(opt.mid(_user.length()));
    }
    //
    QString _password("--password");
    if(opt.startsWith(_password)){
        zTrace(tr("Установить пароль (%1)").arg(opt.mid(_password.length())));
        //set*****(opt.mid(_password.length()));
    }
    //
*/
