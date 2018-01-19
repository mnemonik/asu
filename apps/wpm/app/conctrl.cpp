#include "conctrl.h"

using namespace Z;

ConsoleController::ConsoleController(QObject *parent) :
    Controller(parent), c(0), mess(""), tm(0), th(0)
{
}

ConsoleController::~ConsoleController()
{
    this->quit();
}

void ConsoleController::progress(){
    std::cout << "\r";
    switch(c++){
    case 0: std::cout << "\\"; break;
    case 1: std::cout << "|"; break;
    case 2: std::cout << "/"; break;
    case 3: std::cout << "-"; c = 0; break;
    }
    std::cout << " " << mess.toLocal8Bit().data();
}

void ConsoleController::message(const QString &m){
    mess = m;
}

void ConsoleController::start()
{
    c = 0;
    tm = new QTimer();
    tm->setInterval(100);
    QObject::connect(tm, SIGNAL(timeout()), this, SLOT(progress()));
    tm->start();
    this->progress();
}

void ConsoleController::quit()
{
    if(tm){
        std::cout << "\r";
        tm->stop();
        delete tm;
        tm = 0;
    }
}
