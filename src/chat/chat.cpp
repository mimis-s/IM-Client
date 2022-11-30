#include "chat.h"
#include "ui_chat.h"
#include <QHBoxLayout>
#include <QAbstractItemView>
#include <QListWidgetItem>
#include "../../common/commonproto/home_chat.pb.h"
#include "../../common/commonproto/home_relay.pb.h"
#include "../../common/define/define.h"
#include "../../common/socket/socket.h"

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

    // socket
    SocketControl::Instance()->RegisterRecvFunc(MessageTag_ChatSingle.Res, std::bind(&Chat::slot_ChatSingleRes, this, std::placeholders::_1));
    SocketControl::Instance()->RegisterRecvFunc(MessageTag_ChatSingle.Relay, std::bind(&Chat::slot_ChatSingleRelay, this, std::placeholders::_1));
}

Chat::~Chat()
{
    delete ui;
}

void Chat::slot_ChatSingleRes(char *pMessage)
{
    im_home_proto::ChatSingleRes *chatSingleRes = new im_home_proto::ChatSingleRes;
    chatSingleRes->ParseFromString(pMessage);
}

void Chat::slot_ChatSingleRelay(char *pMessage)
{
    im_home_proto::ChatSingleToReceiver *chatSingleToReceiver = new im_home_proto::ChatSingleToReceiver;
    chatSingleToReceiver->ParseFromString(pMessage);

    // 这里有两种情况,收到消息的好友在当前聊天列表中,没有在当前聊天列表中

    // 收到消息的好友在当前聊天列表中
    if (m_mapOneChatBox.end() != m_mapOneChatBox.find(chatSingleToReceiver->data().senderid()))
    {
        OneChatBox oneChatBox = m_mapOneChatBox[chatSingleToReceiver->data().senderid()];
        oneChatBox.Right->AddMessage(false, QString::fromStdString(chatSingleToReceiver->data().data()), oneChatBox.Left->GetInfo().m_HeadPath);
        return;
    }

    // 没有在当前聊天列表中, 先获取用户信息
    im_home_proto::GetUserInfoReq *getUserInfoReq = new im_home_proto::GetUserInfoReq;
    getUserInfoReq->set_userid(chatSingleToReceiver->data().senderid());

    char *recvMessage = SocketControl::Instance()->BlockSendMessage(MessageTag_GetUserInfo.Req, MessageTag_GetUserInfo.Res, getUserInfoReq->SerializeAsString());

    im_home_proto::GetUserInfoRes *getUserInfoRes = new im_home_proto::GetUserInfoRes;
    getUserInfoRes->ParseFromString(recvMessage);

    ChatShortFrameData data;
    data.m_Name = QString::fromStdString(getUserInfoRes->data().username());
    data.m_Time = chatSingleToReceiver->data().sendtimestamp();
    data.m_Message = QString::fromStdString(chatSingleToReceiver->data().data());
    data.m_TipsNum = 1;
    data.m_FriendID = chatSingleToReceiver->data().senderid();
    data.m_HeadPath = QString::fromStdString(getUserInfoRes->data().headimg());
    data.m_UserStatus = getUserInfoRes->data().status();

    AddOneChat(data);

    m_mapOneChatBox[chatSingleToReceiver->data().senderid()].Right->AddMessage(false, QString::fromStdString(chatSingleToReceiver->data().data()), QString::fromStdString(getUserInfoRes->data().headimg()));
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
    ChatBox *pBox = new ChatBox(m_pRightChatBox, data);
    m_pChatBoxLayout->addWidget(pBox);

    m_mapOneChatBox[data.m_FriendID] = {pChatShortFrame, pBox};
}
