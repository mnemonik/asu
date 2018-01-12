//#include <uniqueapplication.h>
//#include <QMainWindow>
#include <QTextCodec>
#include <iostream>
#include "app.h"
#include "logger.h"

using namespace std;

int main(int argc, char *argv[])
{
//    UniqueApplication app(argc, argv);

//    if (app.isRunning())
//        return !app.sendMessage("someDataString");

//    QMainWindow mmw;
//    app.setActivationWindow(&mmw);
//    mmw.show();
//    return app.exec();

    cout << "Start" << endl;
    cout << "Stop" << endl;

    QTextCodec *locale = QTextCodec::codecForName(APP_LOCALE);
    QTextCodec::setCodecForLocale(locale);
    //TODO: Если 866 Изменить кодировку на 1251 и проверить вывод
    //
    cout << APP_FILE << " " << APP_DESC << endl;


    QCoreApplication a(argc, argv);
    cout << zInfo("begin") << endl;
    cout << endl << zWarning("end");

    cout << "test" << endl;
    cout << ORG_NAME << endl;
    Global* global = Global::instance();
    //
    cout << "global " << global << endl;
    cout << global->get(Global::PATH).toString().toLocal8Bit().data() << endl;
    //
//    QVariant var3( "Hello" );
    //cout << global->set("Z", &var3) << endl;
//    zDebug(global->get("Z"));
    //
    delete global;
    global = NULL;
    cout << "ok " << global << endl;
    return 0;

}
