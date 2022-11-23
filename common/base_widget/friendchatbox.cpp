#include "friendchatbox.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>

FriendChatBox::FriendChatBox(QWidget *parent) : QWidget(parent)
{
    // 左边是头像,头像右上角有在线提示(用有颜色的点表示), 中间上面是好友名字,中间下面是最新消息, 右边是未读消息提示,最后消息的时间
    QHBoxLayout *pBoxLayout = new QHBoxLayout(this);

    // 左边是头像,在线提示
    m_pLbHead = new CircleLabel(this, ENUM_CircleStyle::ENUM_Head);

    // 中间上面是好友名字,中间下面是最新消息
    QVBoxLayout *pMiddleVboxLayout = new QVBoxLayout(this);
    m_pLbName = new QLabel(this);
    m_pLbMessage = new QLabel(this);

    // 右边是未读消息提示,最后消息的时间
    QVBoxLayout *pRightVboxLayout = new QVBoxLayout(this);
    m_pLbTips = new QLabel(this);
    m_pLbTime = new QLabel(this);

    pBoxLayout->addWidget(m_pLbHead);

    pMiddleVboxLayout->addWidget(m_pLbName);
    pMiddleVboxLayout->addWidget(m_pLbMessage);
    pBoxLayout->addLayout(pMiddleVboxLayout);

    pRightVboxLayout->addWidget(m_pLbTips);
    pRightVboxLayout->addWidget(m_pLbTime);
    pBoxLayout->addLayout(pRightVboxLayout);
}

//设置样式(黑夜/白昼)
void FriendChatBox::SetStyleModel(ENUM_StyleModel model)
{
    switch (model) {
    case ENUM_WHITE:
        this->setStyleSheet("background-color:white;color:black;");
        break;
    case ENUM_BLACK:
        this->setStyleSheet("background-color:black;color:white;border:1px;");
        break;
    }
}

void FriendChatBox::UpdateData(FriendChatBoxData data)
{
    if (data.m_HeadPath != "") {
        // 获取头像
        m_pLbHead->SetImgPath(data.m_HeadPath);
    }
    if (data.m_Online == ENUM_OnLineStatus::ENUM_OutLine) {
        //  离线
        m_pLbHead->SetColor(Qt::gray);
    }else{
        // 在线
        m_pLbHead->SetColor(Qt::green);
    }
    if (data.m_Name != ""){
        // 好友名字
        m_pLbName->setText(data.m_Name);
    }
    if (data.m_Message != ""){
        // 最新消息
        m_pLbMessage->setText(data.m_Message);
    }
    if (data.m_TipsNum != 0){
        // 未读消息提示
        m_pLbTips->setText("2");
    }
    if (data.m_Time != ""){
        m_pLbTime->setText(data.m_Time);
    }
}
