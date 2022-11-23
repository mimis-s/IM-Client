#include "im_client.h"
#include "ui_im_client.h"
#include <QHBoxLayout>

IMClient::IMClient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IMClient)
{
    ui->setupUi(this);

    pbox = new FriendChatBox(this);
    pbox->resize(300,150);
    FriendChatBoxData data;
    data.m_Name = "xiaoyu";
    data.m_Online = ENUM_OnLineStatus::ENUM_OutLine;
    data.m_TipsNum = 0;
    pbox->UpdateData(data);
}

IMClient::~IMClient()
{
    delete ui;
}

int a = 1;

void IMClient::on_pushButton_clicked()
{
    FriendChatBoxData data;
    data.m_Name = "zhangbin";
    data.m_Online = ENUM_OnLineStatus::ENUM_OnLine;
    data.m_Message = "123";
    if (a % 5 == 0){
        data.m_TipsNum = 0;
    }else{
        data.m_TipsNum = a;
    }
    a++;
    data.m_HeadPath = tr(u8"/home/zhangbin/图片/546508.jpg");
    data.m_Time = "13:0" + QString::number(a);
    pbox->UpdateData(data);
}
