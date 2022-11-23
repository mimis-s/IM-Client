#include "im_client.h"
#include "ui_im_client.h"
#include "common/base_widget/friendchatbox.h"
#include <QHBoxLayout>

IMClient::IMClient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IMClient)
{
    ui->setupUi(this);
//    QHBoxLayout *pLayout = new QHBoxLayout(this);

//    FriendChatBox *pbox = new FriendChatBox(this);
//    pbox->resize(300,150);
//    FriendChatBoxData data;
//    data.m_Name = "zhangbin";
//    data.m_Online = ENUM_OnLineStatus::ENUM_OnLine;
//    data.m_Message = "123";
//    data.m_TipsNum = 2;
//    data.m_HeadPath = tr(u8"/home/zhangbin/图片/546508.jpg");
//    data.m_Time = "13:03";
//    pbox->UpdateData(data);
//    pbox->SetStyleModel(ENUM_WHITE);

//    pLayout->addWidget(pbox);
}

IMClient::~IMClient()
{
    delete ui;
}
