#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "../home/home.h"

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr, QString id = "");
    ~login();
    void LoginBack(char * recvMessage);

private slots:
    void slot_btn_login();
    void slot_btn_register();

private:
    Ui::login *ui;
    Home *m_pHomeWidget;
};

#endif // LOGIN_H
