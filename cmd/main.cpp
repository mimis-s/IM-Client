#include "im_client.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IMClient w;
    w.show();

    return a.exec();
}
