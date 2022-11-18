#include "register.h"
#include "ui_register.ui"

CUserRegister::CUserRegister(QWidget *parent) : QWidget(parent),
                                                ui(new Ui::CUserRegister)
{
    ui->setupUi(this);
}

CUserRegister::~CUserRegister()
{
    delete ui;
}
