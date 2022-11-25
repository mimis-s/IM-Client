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

    pchat->AddMessage(true, "hello", "");
    pchat->AddMessage(false, "hi", "");
    pchat->AddMessage(true, "listWidget_File换成你自己实例化的", "");
    pchat->AddMessage(false, "直接复制以下代码即可实现横向滚动条", "");
    pchat->AddMessage(true, "直接复制以下代码即可实现竖直滚动条，注意：listWidget_File换成你自己实例化的QListwidget。", "");
    pchat->AddMessage(false, "因为在网上看到的都是比较复杂的操作，而对于新手来说需要实现的东西都是很简单的，所以随手记录一下笔记方便路过的新手们。", "");
}

IMClient::~IMClient()
{
    delete ui;
}

