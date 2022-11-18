#ifndef REGISTER_H
#define REGISTER_H

#include <QWidget>

namespace Ui
{
    class CUserRegister;
}

class CUserRegister : public QWidget
{
    Q_OBJECT

public:
    explicit CUserRegister(QWidget *parent = 0);
    ~CUserRegister();

private:
    Ui::CUserRegister *ui;
};

#endif // REGISTER_H
