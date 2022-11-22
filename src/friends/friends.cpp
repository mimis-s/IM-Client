#include "friends.h"
#include "ui_friends.h"

friends::friends(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::friends)
{
    ui->setupUi(this);
}

friends::~friends()
{
    delete ui;
}
