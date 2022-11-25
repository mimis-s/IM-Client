#include "home.h"
#include "ui_home.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

Home::Home(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Home)
{
    ui->setupUi(this);
    resize(1000, 550);

    // 主界面分为左右两个板块
    QHBoxLayout *pHBoxLayout = new QHBoxLayout(this);

    // 左边主要是大功能导航按钮
    QWidget *pLeftWidget = new QWidget(this);
    QVBoxLayout *pLeftVBoxLayout = new QVBoxLayout(pLeftWidget);

    QLabel *pLeftLbLogo = new QLabel(pLeftWidget);
    pLeftLbLogo->setMinimumSize(50, 70);
    pLeftLbLogo->setStyleSheet("border-image:url(:/img/im_logo_home);");

    QPushButton *pLeftBtnChat = new QPushButton(tr(u8"聊天"), pLeftWidget);      // 按钮切换到聊天界面
    QPushButton *pLeftBtnFriends = new QPushButton(tr(u8"好友"), pLeftWidget);   // 按钮切换到好友界面
    QPushButton *pLeftBtnGroup = new QPushButton(tr(u8"群组"), pLeftWidget);     // 按钮切换到群组界面

    QPushButton *pLeftBtnBlack = new QPushButton(tr(u8"黑夜"), pLeftWidget);     // 按钮切换黑夜/白昼模式
    QPushButton *pLeftBtnHead = new QPushButton(tr(u8"head"), pLeftWidget);      // 头像按钮(查看个人信息)

    pLeftVBoxLayout->addWidget(pLeftLbLogo);
    pLeftVBoxLayout->addWidget(pLeftBtnChat);
    pLeftVBoxLayout->addWidget(pLeftBtnFriends);
    pLeftVBoxLayout->addWidget(pLeftBtnGroup);

    pLeftVBoxLayout->addStretch();

    pLeftVBoxLayout->addWidget(pLeftBtnBlack);
    pLeftVBoxLayout->addWidget(pLeftBtnHead);


    pHBoxLayout->addWidget(pLeftWidget, 1);

    // 右边是具体界面
    QWidget *pRightWidget = new QWidget(this);
    pRightWidget->setStyleSheet("background:skyblue;");
    QVBoxLayout *pVBoxLayoutRightWidget = new QVBoxLayout(pRightWidget);

    m_pChat  = new Chat(pRightWidget);
    ChatShortFrameData data{
        "",     // 好友头像路径
        ENUM_OnLineStatus::ENUM_OnLine, // 在线提示
        "zhangbin",                     // 好友名字
        123456,                         // 好友id
        "hello",                        // 最新消息
        1,                              // 未读消息提示
        "12:03"                         // 最后消息的时间
    };

    m_pChat->AddOneChat(data);
    pVBoxLayoutRightWidget->addWidget(m_pChat);

    m_pFriends = new Friends(pRightWidget);
    pVBoxLayoutRightWidget->addWidget(m_pFriends);
    m_pFriends->hide();

    pHBoxLayout->addWidget(pRightWidget, 9);

    connect(pLeftBtnChat, SIGNAL(clicked()), this, SLOT(slot_btnChatClick()));
    connect(pLeftBtnFriends, SIGNAL(clicked()), this, SLOT(slot_btnFriendsClick()));
    connect(pLeftBtnGroup, SIGNAL(clicked()), this, SLOT(slot_btnGroupClick()));

}

Home::~Home()
{
    delete ui;
}

void Home::slot_btnChatClick()
{
    m_pChat->show();
    m_pFriends->hide();
}

void Home::slot_btnFriendsClick()
{
    m_pChat->hide();
    m_pFriends->show();
}

void Home::slot_btnGroupClick()
{
    m_pChat->hide();
    m_pFriends->hide();
}

