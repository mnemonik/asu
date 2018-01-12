#include <QCoreApplication>
#include <core.h>

//using namespace Z;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    Core* core = Core::instance();
    core->start();
    
    std::exit(EXIT_SUCCESS);
}
