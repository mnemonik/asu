#ifndef CONCTRL_H
#define CONCTRL_H
//
#include <iostream>
#include <QTimer>
#include <QThread>
#include "controller.h"
#include "logger.h"
#include "common.h"
//
namespace Z {

class ConsoleController : public Controller
{
    Q_OBJECT
public:
    explicit ConsoleController(QObject *parent = 0);
    ~ConsoleController();
    int c;
    QString mess;
    QTimer* tm;
    QThread* th;
signals:
public slots:
    void progress();
    void message(const QString &m);
    void start();
    void quit();
};

};
//
#endif // CONCTRL_H
