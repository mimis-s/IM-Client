#include "src/login/login.h""
#include <QApplication>
#include "common/socket/socket.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Socket::Instance("localhost", 8888);
     login w;
     w.show();

    return a.exec();
}
