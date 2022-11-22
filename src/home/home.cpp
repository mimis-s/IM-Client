#include "home.h"
#include "ui_home.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

Home::Home(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Home)
{
    ui->setupUi(this);
    resize(1000, 550);



}

Home::~Home()
{
    delete ui;
}
