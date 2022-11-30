#include "src/login/login.h""
#include <QApplication>
#include "common/socket/socket.h"
#include <QDebug>
#include "im_client.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SocketControl::Instance("localhost", 8888);

    login w;
    w.show();


//    IMClient w;
//    w.show();

    return a.exec();
}
