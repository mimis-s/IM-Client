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

private:
    Ui::CUserRegister *ui;
};

#endif // REGISTER_H
