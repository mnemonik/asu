#include <QCoreApplication>
#include <QDialog>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
    //return a.exec();
    
    QCoreApplication a(argc, argv);
    QStringList arguments = a.arguments();
    if (arguments.count() == 1) {
        QDialog *w = new QDialog;
        w->show();
        return a.exec();
    } else {
        std::cout << "Work done!";
        return 0;
    }
}
