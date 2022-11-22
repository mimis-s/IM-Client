#include "register.h"
#include "ui_register.h"

CUserRegister::CUserRegister(QDialog *parent) : QDialog(parent),
    ui(new Ui::CUserRegister)
{
    ui->setupUi(this);
}

CUserRegister::~CUserRegister()
{
    delete ui;
}
