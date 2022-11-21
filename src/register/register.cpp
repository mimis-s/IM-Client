#include "register.h"
#include "ui_register.h"

CUserRegister::CUserRegister(QWidget *parent) : QWidget(parent),
    ui(new Ui::CUserRegister)
{
    ui->setupUi(this);
}

CUserRegister::~CUserRegister()
{
    delete ui;
}
