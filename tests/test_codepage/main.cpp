#include <QCoreApplication>
#include <QTextCodec>

#include <iostream>

#define LOCALE "windows-866"
//#define LOCALE "windows-1251"
#define TEXT "Организация:"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextCodec *locale = QTextCodec::codecForName(LOCALE);
    QTextCodec::setCodecForLocale(locale);

    QString s(TEXT);
    
    std::cout
        << LOCALE << "\n"
        << TEXT << "\n"
        << s.data() << "\n"
        << s.toLatin1().data() << "\n"
        << s.toCaseFolded().data() << "\n"
        << s.toHtmlEscaped().data() << "\n"
        << s.toLocal8Bit().data() << "\n"
        << s.toStdString() << "\n"
        << s.toStdString().data() << "\n"
        << s.toUtf8().data() << "\n";
}
