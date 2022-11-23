#include "friendchatbox.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>

FriendChatBox::FriendChatBox(QWidget *parent) : QWidget(parent)
{
    this->setObjectName("FriendChatBox");
    // 左边是头像,头像右上角有在线提示(用有颜色的点表示), 中间上面是好友名字,中间下面是最新消息, 右边是未读消息提示,最后消息的时间
    QHBoxLayout *pBoxLayout = new QHBoxLayout(this);

    // 左边是头像,在线提示
    m_pLbHead = new CircleLabel(this, ENUM_CircleStyle::ENUM_Head);
    m_pLbHead->setMinimumSize(100, 100);
    m_pLbHead->setMaximumSize(100, 100);

    // 中间上面是好友名字,中间下面是最新消息
    QVBoxLayout *pMiddleVboxLayout = new QVBoxLayout();
    m_pLbName = new QLabel(this);
    QFont nameFont("", 16, QFont::Normal, true);
    m_pLbName->setFont(nameFont);
    m_pLbMessage = new QLabel(this);

    // 右边是未读消息提示,最后消息的时间
    QVBoxLayout *pRightVboxLayout = new QVBoxLayout();
    m_pLbTips = new CircleLabel(this, ENUM_CircleStyle::ENUM_SolidNumber);
    m_pLbTips->SetFontColor(Qt::white);
    m_pLbTips->SetCircleColor(Qt::blue);
    m_pLbTime = new QLabel(this);

    pBoxLayout->addWidget(m_pLbHead, Qt::AlignHCenter);

    pMiddleVboxLayout->addStretch();
    pMiddleVboxLayout->addWidget(m_pLbName);
    pMiddleVboxLayout->addWidget(m_pLbMessage);
    pMiddleVboxLayout->addStretch();
    pBoxLayout->addLayout(pMiddleVboxLayout);

    pRightVboxLayout->addStretch();
    pRightVboxLayout->addWidget(m_pLbTips);
    pRightVboxLayout->addWidget(m_pLbTime);
    pRightVboxLayout->addStretch();
    pBoxLayout->addLayout(pRightVboxLayout);
}

void FriendChatBox::UpdateData(FriendChatBoxData data)
{
    if (data.m_HeadPath != "") {
        // 获取头像
        m_pLbHead->SetImgPath(data.m_HeadPath);
    }
    if (data.m_Online == ENUM_OnLineStatus::ENUM_OutLine) {
        //  离线
        m_pLbHead->SetCircleColor(Qt::gray);
    }else{
        // 在线
        m_pLbHead->SetCircleColor(Qt::green);
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
        m_pLbTips->SetCircleLabelText(QString::number(data.m_TipsNum));
        m_pLbTips->SetCircleLabelHide(false);
    }else{
        m_pLbTips->SetCircleLabelHide(true);
    }
    if (data.m_Time != ""){
        m_pLbTime->setText(data.m_Time);
    }
}
