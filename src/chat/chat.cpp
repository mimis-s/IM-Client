#include "chat.h"
#include "ui_chat.h"
#include <QHBoxLayout>
#include <QAbstractItemView>
#include <QListWidgetItem>
#include <QDateTime>
#include "../../common/commonproto/home_chat.pb.h"
#include "../../common/commonproto/home_relay.pb.h"
#include "../../common/define/define.h"
#include "../../common/socket/socket.h"
#include "../global/userinfo.h"
#include "../global/chathistory.h"

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
    SocketControl::Instance()->RegisterRecvFunc(MessageTag_ChatSingle.Relay, std::bind(&Chat::slot_ChatSingleRelay, this, std::placeholders::_1));
    SocketControl::Instance()->RegisterRecvFunc(MessageTag_NotifyUserMessage.Notify, std::bind(&Chat::slot_OfflineNotify, this, std::placeholders::_1));
}

Chat::~Chat()
{
    delete ui;
}

void Chat::slot_ChatSingleRelay(char *pMessage)
{
    im_home_proto::ChatSingleToReceiver *chatSingleToReceiver = new im_home_proto::ChatSingleToReceiver;
    chatSingleToReceiver->ParseFromString(pMessage);

    ClientUserInfo* pOtherUserInfo = UserInfo::Instance()->AddOtherUserInfo(chatSingleToReceiver->senderinfo());

    ChatShortFrameData data;
    data.m_Name = pOtherUserInfo->mUserData.UserName;
    data.m_Time = QDateTime::fromTime_t(chatSingleToReceiver->data().sendtimestamp()).toString(TimeFormat);
    data.m_Message = QString::fromStdString(chatSingleToReceiver->data().data());
    data.m_FriendID = chatSingleToReceiver->data().senderid();
    data.m_HeadPath = UserInfo::Instance()->GetUserHeadPath(chatSingleToReceiver->senderinfo().userid(), false);
    data.m_UserStatus = pOtherUserInfo->mUserData.ProtoUserInfo.status();

    // 这里有两种情况,收到消息的好友在当前聊天列表中,没有在当前聊天列表中

    // 收到消息的好友在当前聊天列表中
    if (m_mapOneChatBox.end() != m_mapOneChatBox.find(chatSingleToReceiver->data().senderid()))
    {
        OneChatBox oneChatBox = m_mapOneChatBox[chatSingleToReceiver->data().senderid()];
        int tipsNum = oneChatBox.Left->GetInfo().m_TipsNum;
        data.m_TipsNum = tipsNum + 1;
        oneChatBox.Left->UpdateData(data);
        oneChatBox.Right->InsertMessage(chatSingleToReceiver->data());
        return;
    }

    // 没有在当前聊天列表中
    data.m_TipsNum = 1;
    AddOneChat(data);

    m_mapOneChatBox[chatSingleToReceiver->data().senderid()].Right->AddMessage(chatSingleToReceiver->data());
}

void Chat::slot_OfflineNotify(char *pMessage)
{
    im_home_proto::NotifyUserMessage *notifyUserMessage = new im_home_proto::NotifyUserMessage;
    notifyUserMessage->ParseFromString(pMessage);

    ClientUserInfo* selfInfo = UserInfo::Instance()->GetSelfUserInfo();
    // 登录下发离线消息
    for (int i = 0; i < notifyUserMessage->offlinesinglechat_size(); i++){

        OneChatBox oneChatBox;

        // 好友信息
        // 是否存在离线消息<friend->true>
        m_bmapOffline[notifyUserMessage->offlinesinglechat(i).user().userid()] = true;
        if (m_mapOneChatBox.end() != m_mapOneChatBox.find(notifyUserMessage->offlinesinglechat(i).user().userid()))
        {
            oneChatBox = m_mapOneChatBox[notifyUserMessage->offlinesinglechat(i).user().userid()];
        }else{

            ChatShortFrameData data;
            data.m_Name = QString::fromStdString(notifyUserMessage->offlinesinglechat(i).user().username());
            data.m_FriendID = notifyUserMessage->offlinesinglechat(i).user().userid();
            data.m_HeadPath = UserInfo::Instance()->GetUserHeadPath(notifyUserMessage->offlinesinglechat(i).user().userid(), false);
            data.m_UserStatus = notifyUserMessage->offlinesinglechat(i).user().status();
            oneChatBox = AddOneChat(data);
        }

        int messageNum = 0;

        // 消息
        for(int j = 0; j < notifyUserMessage->offlinesinglechat(i).data_size(); j++) {
            ChatShortFrameData data;
            data.m_Time = QDateTime::fromTime_t(notifyUserMessage->offlinesinglechat(i).data(i).sendtimestamp()).toString(TimeFormat);
            data.m_TipsNum = ++messageNum;
            data.m_Message = QString::fromStdString(notifyUserMessage->offlinesinglechat(i).data(i).data());

            oneChatBox.Left->UpdateData(data);
            oneChatBox.Right->AddMessage(notifyUserMessage->offlinesinglechat(i).data(i));
        }
    }
}


OneChatBox Chat::AddOneChat(ChatShortFrameData data)
{
    if (m_mapOneChatBox.find(data.m_FriendID) != m_mapOneChatBox.end()) {
        // 聊天框已经存在
        return OneChatBox{};
    }
    // 左边是聊天简介
    QListWidgetItem *Item_left = new QListWidgetItem(m_pChatShortFrameList);
    Item_left->setFlags(Item_left->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
    Item_left->setSizeHint(QSize(100, 100));
    ChatShortFrame *pChatShortFrame = new ChatShortFrame(m_pChatShortFrameList);
    pChatShortFrame->UpdateData(data);

    m_pChatShortFrameList->setItemWidget(Item_left, pChatShortFrame);

    connect(pChatShortFrame, SIGNAL(sig_mousePress(ChatShortFrameData)), this, SLOT(slot_ChatShortFramePress(ChatShortFrameData)));

    // 右边是聊天内容
    ChatBox *pBox = new ChatBox(m_pRightChatBox, data);
    m_pChatBoxLayout->addWidget(pBox);

    OneChatBox chatBox = OneChatBox{pChatShortFrame, pBox};

    m_mapOneChatBox[data.m_FriendID] = chatBox;
    return chatBox;
}

void Chat::slot_ChatShortFramePress(ChatShortFrameData data)
{

    ChatHistory::Instance()->ReadOfflineMessage(data.m_FriendID);

    QList<ChatShortFrame*> itemList = m_pChatShortFrameList->findChildren<ChatShortFrame*>();  // 获取所有的QChatHeadAndBubble
    QPushButton *pBtn=qobject_cast<QPushButton *>(sender());

    for (int i = 0; i < m_pChatShortFrameList->count(); i++) {
        ChatShortFrame *pWidget = (ChatShortFrame *)m_pChatShortFrameList->itemWidget(m_pChatShortFrameList->item(i));
        if (pWidget->GetInfo().m_FriendID == data.m_FriendID) {
            m_bmapOffline[data.m_FriendID] = false;
            ChatShortFrameData data;
            data.m_TipsNum = 0;
            pWidget->UpdateData(data);
        }
    }
}
