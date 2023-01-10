#include "im_client.h"
#include "ui_im_client.h"
#include <QHBoxLayout>
#include "common/base_widget/chatbox.h"
#include "common/base_widget/chatbubble.h"
#include "common/base_widget/chatheadandbubble.h"
IMClient::IMClient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IMClient)
{
    ui->setupUi(this);

    QHBoxLayout *pLayout = new QHBoxLayout(this);
    ChatBox *pchat = new ChatBox(this);

    pLayout->addWidget(pchat);
}

IMClient::~IMClient()
{
    delete ui;
}

