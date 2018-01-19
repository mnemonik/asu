#ifndef Z_CONTROLLER_H
#define Z_CONTROLLER_H
//
#include <QObject>
//
#include "lib_core.h"
//
ASU_BEGIN_NAMESPACE
//
class Controller : public QObject {
    Q_OBJECT
public:
    explicit Controller(QObject* _parent = 0) : QObject(_parent) {};
    ~Controller(){};
public slots:
    virtual void start(){};
    virtual void quit(){};
};
//
ASU_END_NAMESPACE
//
#endif // Z_CONTROLLER_H
