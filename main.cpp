#include <QCoreApplication>

#include "mytcpserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyTcpServer myServer;

    return a.exec();
}
