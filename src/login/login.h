#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();
    void LoginBack(char * recvMessage);

private slots:
    void slot_btn_login();
    void slot_btn_register();

private:
    Ui::login *ui;
};

#endif // LOGIN_H
