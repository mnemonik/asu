#include "service.h"

#include "logger.h"

namespace Z {

Service::Service(int argc, char *argv[], const QString &name)
    : QCoreApplication(argc, argv), serviceName(name)
{
}

SC_HANDLE Service::handle(const QStringList &params)
{
    SC_HANDLE SCM = OpenSCManager(NULL,NULL,SC_MANAGER_ALL_ACCESS);
    if(!SCM){
        return 0;
    }
    SC_HANDLE SRV = OpenService(SCM,getServiceName().toStdWString().data(),SERVICE_ALL_ACCESS);
    if(!SRV){
        return 0;
    }
    return SRV;
}

bool Service::install(const QStringList &params)
{
    zDebug(("Создание службы %1").arg(1));

    SC_HANDLE SCM = OpenSCManager(NULL,NULL,SC_MANAGER_CREATE_SERVICE);
    if(!SCM){
        zTrace("OpenSCManager");
        return false;
    }
    //
    SC_HANDLE CS = CreateService(SCM,
        getServiceName().toStdWString().data(),
        getServiceName().toStdWString().data(),
        SERVICE_ALL_ACCESS,
        SERVICE_WIN32_OWN_PROCESS | SERVICE_INTERACTIVE_PROCESS,
        SERVICE_AUTO_START,
        SERVICE_ERROR_IGNORE,
        NULL, //path.c_str(),
        NULL,
        NULL,
        NULL, //dependencies.c_str(),
        NULL,
        NULL);
    if(!CS){
        zTrace("CreateService");
        CloseServiceHandle(SCM);    	            	
        return false;
    }
    
    CloseServiceHandle(SCM);
    CloseServiceHandle(CS);
    return true;
}

bool Service::uninstall(const QStringList &params)
{
    SC_HANDLE SRV = handle(params);
    if(!SRV){
        return false;
    }
    if(!DeleteService(SRV)){
        return false;
    }
    CloseServiceHandle(SRV);
    return true;
}

QString Service::ErrorMessage() const
{
    QString mess;
    DWORD code = GetLastError();
    char *err;
    if (!FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
        NULL,
        code,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // default language
        (LPTSTR) &err, 0, NULL)){
        return QString("%1 : UNKNOWN ERROR").arg(code);
    }
    mess = QString("%1 : %2").arg(code).arg(err);
    zError(mess);
    LocalFree( err );
    return mess;
}

}//Z
