#include <QTextCodec>
#include <iostream>
#include "app.h"
//
using namespace std;
//
int main(int argc, char *argv[])
{
    QTextCodec *locale = QTextCodec::codecForName(APP_LOCALE);
    QTextCodec::setCodecForLocale(locale);
    //TODO: Если 866 Изменить кодировку на 1251 и проверить вывод
    //
    cout << APP_FILE << " " << APP_DESC << endl;
}
//
