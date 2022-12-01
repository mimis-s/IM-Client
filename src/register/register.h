#ifndef REGISTER_H
#define REGISTER_H

#include <QWidget>
#include <QDialog>

namespace Ui
{
    class CUserRegister;
}

class CUserRegister : public QDialog
{
    Q_OBJECT

public:
    explicit CUserRegister(QDialog *parent = 0);
    ~CUserRegister();
    void RegisterBack(char * recvMessage);

public slots:
    void slot_btn_register();

private slots:
    void on_btn_register_head_clicked();

private:
    Ui::CUserRegister *ui;
};

#endif // REGISTER_H
