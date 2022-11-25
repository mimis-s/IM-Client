#include "chat.h"
#include "ui_chat.h"
#include <QHBoxLayout>
#include <QAbstractItemView>
#include <QListWidgetItem>

Chat::Chat(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Chat)
{
    ui->setupUi(this);

    QHBoxLayout *pHBoxLayout = new QHBoxLayout(this);

    m_pChatShortFrameList = new QListWidget(this);
    m_pChatShortFrameList->setStyleSheet("background-color:white;");
    m_pChatShortFrameList->setResizeMode(QListView::Adjust);
    m_pChatShortFrameList->setAutoScroll(true);
    m_pChatShortFrameList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_pChatShortFrameList->setSizeAdjustPolicy(QListWidget::AdjustToContents);
    m_pChatShortFrameList->setMinimumWidth(250);
    m_pChatShortFrameList->setMaximumWidth(250);

    m_pRightChatBox = new QWidget(this);
    m_pChatBoxLayout = new QVBoxLayout(m_pRightChatBox);


    pHBoxLayout->addWidget(m_pChatShortFrameList, 3);
    pHBoxLayout->addWidget(m_pRightChatBox, 7);
}

Chat::~Chat()
{
    delete ui;
}

void Chat::AddOneChat(ChatShortFrameData data)
{
    if (m_mapOneChatBox.find(data.m_FriendID) != m_mapOneChatBox.end()) {
        // 聊天框已经存在
        return;
    }
    // 左边是聊天简介
    QListWidgetItem *Item_left = new QListWidgetItem(m_pChatShortFrameList);
    Item_left->setFlags(Item_left->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
    Item_left->setSizeHint(QSize(100, 100));
    ChatShortFrame *pChatShortFrame = new ChatShortFrame(m_pChatShortFrameList);
    pChatShortFrame->UpdateData(data);

    m_pChatShortFrameList->setItemWidget(Item_left, pChatShortFrame);

    // 右边是聊天内容
    ChatBox *pBox = new ChatBox(m_pRightChatBox);
    m_pChatBoxLayout->addWidget(pBox);

    m_mapOneChatBox[data.m_FriendID] = {pChatShortFrame, pBox};
}
