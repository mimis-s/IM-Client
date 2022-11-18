#include "im_client.h"
#include "ui_im_client.h"

IMClient::IMClient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IMClient)
{
    ui->setupUi(this);
}

IMClient::~IMClient()
{
    delete ui;
}
