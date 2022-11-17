#ifndef IM_CLIENT_H
#define IM_CLIENT_H

#include <QWidget>

namespace Ui {
class IMClient;
}

class IMClient : public QWidget
{
    Q_OBJECT

public:
    explicit IMClient(QWidget *parent = 0);
    ~IMClient();

private:
    Ui::IMClient *ui;
};

#endif // IM_CLIENT_H
