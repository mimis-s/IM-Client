#include "im_client.h"
#include <QApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
     IMClient w;
     w.show();
    qDebug() << "asdf";

    return a.exec();
}
