#include "friends.h"
#include "ui_friends.h"
#include "../../common/base_widget/chatbox.h"
#include "../../common/socket/socket.h"
#include "../../common/define/define.h"
#include "../../common/commonproto/home_account.pb.h"
#include "../../common/log/im_log.h"
#include "frienddetails.h"
#include "../../common/commonproto/home_relay.pb.h"
#include <QMessageBox>
#include "../../common/commonproto/home_friends.pb.h"
#include "friendapplybox.h"
#include "../global/userinfo.h"

Friends::Friends(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Friends)
{
    ui->setupUi(this);


    QHBoxLayout *pMainLayout = new QHBoxLayout(this);

    QWidget *pLeftWidget = new QWidget(this);
    QVBoxLayout *pVBoxLayout = new QVBoxLayout(pLeftWidget);

    QWidget *pSearchWidget = new QWidget(pLeftWidget);
    QHBoxLayout *pSearchLayout = new QHBoxLayout(pSearchWidget);
    m_pEditSearchFriend = new QLineEdit(pSearchWidget);
    m_pBtnSearch = new QPushButton(tr(u8"搜索"), pSearchWidget);

    pSearchLayout->addWidget(m_pEditSearchFriend, 8);
    pSearchLayout->addWidget(m_pBtnSearch, 2);

    // 好友列表
    m_pFriendsList= new QListWidget(pLeftWidget);
    m_pFriendsList->setStyleSheet("background-color:white;");
    m_pFriendsList->setResizeMode(QListView::Adjust);
    m_pFriendsList->setAutoScroll(true);
    m_pFriendsList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_pFriendsList->setSizeAdjustPolicy(QListWidget::AdjustToContents);

    pVBoxLayout->addWidget(pSearchWidget, 1);
    pVBoxLayout->addWidget(m_pFriendsList, 9);

    // 好友申请列表
    m_pFriendApplyList= new QListWidget(this);
    m_pFriendApplyList->setStyleSheet("background-color:white;");
    m_pFriendApplyList->setResizeMode(QListView::Adjust);
    m_pFriendApplyList->setAutoScroll(true);
    m_pFriendApplyList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_pFriendApplyList->setSizeAdjustPolicy(QListWidget::AdjustToContents);

    pMainLayout->addWidget(pLeftWidget, 3);
    pMainLayout->addWidget(m_pFriendApplyList, 7);

    // connect
    connect(m_pBtnSearch, SIGNAL(clicked()), this, SLOT(slot_btnSearchClick()));

    // socket
    SocketControl::Instance()->RegisterRecvFunc(MessageTag_ApplyFriends.Relay, std::bind(&Friends::slot_ApplyFriendsRelay, this, std::placeholders::_1));
    SocketControl::Instance()->RegisterRecvFunc(MessageTag_ApplyFriends.Res, std::bind(&Friends::slot_ApplyFriendsRes, this, std::placeholders::_1));

    SocketControl::Instance()->RegisterRecvFunc(MessageTag_AgreeFriendApply.Res, std::bind(&Friends::slot_AgreeFriendApplyRes, this, std::placeholders::_1));
    SocketControl::Instance()->RegisterRecvFunc(MessageTag_AgreeFriendApply.Relay, std::bind(&Friends::slot_AgreeFriendApplyRelay, this, std::placeholders::_1));

    SocketControl::Instance()->RegisterRecvFunc(MessageTag_NotifyFriendsStatusList.Notify, std::bind(&Friends::slot_NotifyFriendsStatusList, this, std::placeholders::_1));
}

Friends::~Friends()
{
    delete ui;
}

void Friends::slot_NotifyFriendsStatusList(char * recvMessage)
{
    im_home_proto::FriendsStatusList *notifyFriendsStatusList = new im_home_proto::FriendsStatusList;
    notifyFriendsStatusList->ParseFromString(recvMessage);

    m_pFriendsList->clear();

    // 好友列表
    for (int i = 0 ; i < notifyFriendsStatusList->friendsstatuslist_size(); i++)
    {
        AddFriendItem(notifyFriendsStatusList->friendsstatuslist(i).friend_(), notifyFriendsStatusList->friendsstatuslist(i).isupdatehead());
    }

    // 好友申请列表
    for (int i = 0 ; i < notifyFriendsStatusList->sendfriendapplylist_size(); i++)
    {
        AddApplyFriendItem(notifyFriendsStatusList->sendfriendapplylist(i).friend_(), true);
    }

    // 收到好友申请列表
    for (int i = 0 ; i < notifyFriendsStatusList->receivefriendapplylist_size(); i++)
    {
        AddApplyFriendItem(notifyFriendsStatusList->receivefriendapplylist(i).friend_(), false);
    }
}

void Friends::AddFriendItem(const im_home_proto::UserInfo pUserInfo, bool bUpdateHead)
{
    QListWidgetItem *Item_friend = new QListWidgetItem(m_pFriendsList);
    Item_friend->setFlags(Item_friend->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
    Item_friend->setSizeHint(QSize(100, 100));

    ChatShortFrameData data = ChatShortFrameData{};
    data.m_FriendID = pUserInfo.userid();
    if (pUserInfo.status() == im_home_proto::Enum_UserStatus::Enum_UserStatus_Online)
    {
        data.m_UserStatus = im_home_proto::Enum_UserStatus::Enum_UserStatus_Online;
    }else{
        data.m_UserStatus = im_home_proto::Enum_UserStatus::Enum_UserStatus_Outline;
    }
    data.m_HeadPath = UserInfo::Instance()->GetUserHeadPath(pUserInfo.userid(), bUpdateHead);
    data.m_Name = QString::fromStdString(pUserInfo.username());
    IMLog::Instance()->Info(QString("friend data[%2]").arg(data.m_FriendID));

    ChatShortFrame *friendBox = new ChatShortFrame(m_pFriendsList);
    friendBox->UpdateData(data);
    connect(friendBox, SIGNAL(sig_mouseDoubleClick(ChatShortFrameData)), this, SLOT(slot_ChatShortFrameClickDouble(ChatShortFrameData)));

    m_pFriendsList->setItemWidget(Item_friend, friendBox);

    UserInfo::Instance()->AddOtherUserInfo(pUserInfo);
}

void Friends::AddApplyFriendItem(const im_home_proto::UserInfo pUserInfo, bool isApply) {
    QListWidgetItem *Item_apply = new QListWidgetItem(m_pFriendApplyList);
    Item_apply->setFlags(Item_apply->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
    Item_apply->setSizeHint(QSize(110, 110));

    ChatShortFrameData data = ChatShortFrameData{};
    data.m_FriendID = pUserInfo.userid();
    if (pUserInfo.status() == im_home_proto::Enum_UserStatus::Enum_UserStatus_Online)
    {
        data.m_UserStatus = im_home_proto::Enum_UserStatus::Enum_UserStatus_Online;
    }else{
        data.m_UserStatus = im_home_proto::Enum_UserStatus::Enum_UserStatus_Outline;
    }
    data.m_HeadPath = UserInfo::Instance()->GetUserHeadPath(pUserInfo.userid(), false);
    data.m_Name = QString::fromStdString(pUserInfo.username());

    FriendApplyBox *friendApplyBox = new FriendApplyBox(m_pFriendApplyList, data, isApply);

    m_pFriendApplyList->setItemWidget(Item_apply, friendApplyBox);
    m_mapApplyBox[data.m_FriendID] = Item_apply;

    UserInfo::Instance()->AddOtherUserInfo(pUserInfo);
}

void Friends::slot_ChatShortFrameClickDouble(ChatShortFrameData data)
{
    emit sig_AddOneChat(data);   // 新增一个好友聊天, 如果存在则跳转
}

void Friends::slot_btnSearchClick()
{
    // send get user info
    im_home_proto::GetUserInfoReq *getUserInfoReq = new im_home_proto::GetUserInfoReq;
    getUserInfoReq->set_userid(m_pEditSearchFriend->text().toLongLong());

    IMLog::Instance()->Info(QString("send getUserInfoReq %1").arg(MessageTag_GetUserInfo.Req));

    char *recvMessage = SocketControl::Instance()->BlockSendMessage(MessageTag_GetUserInfo.Req, MessageTag_GetUserInfo.Res, getUserInfoReq->SerializeAsString());

    im_home_proto::GetUserInfoRes *getUserInfoRes = new im_home_proto::GetUserInfoRes;
    getUserInfoRes->ParseFromString(recvMessage);

    // 展示获取到的用户信息
    FriendDetails friendDetails(this, getUserInfoRes);
    friendDetails.exec();
}

void Friends::slot_ApplyFriendsRelay(char * recvMessage)
{
    // 接收对方发来的好友申请
    im_home_proto::ApplyFriendsToReceiver *applyFriendsToReceiver = new im_home_proto::ApplyFriendsToReceiver;
    applyFriendsToReceiver->ParseFromString(recvMessage);

    AddApplyFriendItem(applyFriendsToReceiver->applyerinfo(), false);
}

void Friends::slot_AgreeFriendApplyRes(char * recvMessage)
{
    im_home_proto::AgreeFriendApplyRes *agreeFriendApplyRes = new im_home_proto::AgreeFriendApplyRes;
    agreeFriendApplyRes->ParseFromString(recvMessage);

    if (m_mapApplyBox[agreeFriendApplyRes->friendsid()])
    {
        m_pFriendApplyList->removeItemWidget(m_mapApplyBox[agreeFriendApplyRes->friendsid()]);
        m_mapApplyBox.erase(agreeFriendApplyRes->friendsid());
    }else{
        IMLog::Instance()->Warn(QString("agreeFriendApplyRes friend[%1] no item").arg(agreeFriendApplyRes->friendsid()));
    }

    // 加入好友列表
    if (UserInfo::Instance()->GetOtherUserInfo(agreeFriendApplyRes->friendsid()) != nullptr) {
        AddFriendItem(UserInfo::Instance()->GetOtherUserInfo(agreeFriendApplyRes->friendsid())->mUserData.ProtoUserInfo, false);
    }else{
        im_home_proto::GetUserInfoReq *getUserInfoReq = new im_home_proto::GetUserInfoReq;
        getUserInfoReq->set_userid(agreeFriendApplyRes->friendsid());

        char *recvMessage = SocketControl::Instance()->BlockSendMessage(MessageTag_GetUserInfo.Req, MessageTag_GetUserInfo.Res, getUserInfoReq->SerializeAsString());

        im_home_proto::GetUserInfoRes *getUserInfoRes = new im_home_proto::GetUserInfoRes;
        getUserInfoRes->ParseFromString(recvMessage);
        AddFriendItem(getUserInfoRes->data(), false);
    }
}

void Friends::slot_AgreeFriendApplyRelay(char * recvMessage)
{
    im_home_proto::AgreeApplyFriendsToReceiver *agreeApplyFriendsToReceiver = new im_home_proto::AgreeApplyFriendsToReceiver;
    agreeApplyFriendsToReceiver->ParseFromString(recvMessage);

    if (m_mapApplyBox[agreeApplyFriendsToReceiver->senderid()])
    {
        m_pFriendApplyList->removeItemWidget(m_mapApplyBox[agreeApplyFriendsToReceiver->senderid()]);
        m_mapApplyBox.erase(agreeApplyFriendsToReceiver->senderid());
    }else{
        IMLog::Instance()->Warn(QString("agreeApplyFriendsToReceiver friend[%1] no item").arg(agreeApplyFriendsToReceiver->senderid()));
    }

    // 加入好友列表
    if (UserInfo::Instance()->GetOtherUserInfo(agreeApplyFriendsToReceiver->senderid()) != nullptr) {
        AddFriendItem(UserInfo::Instance()->GetOtherUserInfo(agreeApplyFriendsToReceiver->senderid())->mUserData.ProtoUserInfo, false);
    }else{
        im_home_proto::GetUserInfoReq *getUserInfoReq = new im_home_proto::GetUserInfoReq;
        getUserInfoReq->set_userid(agreeApplyFriendsToReceiver->senderid());

        char *recvMessage = SocketControl::Instance()->BlockSendMessage(MessageTag_GetUserInfo.Req, MessageTag_GetUserInfo.Res, getUserInfoReq->SerializeAsString());

        im_home_proto::GetUserInfoRes *getUserInfoRes = new im_home_proto::GetUserInfoRes;
        getUserInfoRes->ParseFromString(recvMessage);
        AddFriendItem(getUserInfoRes->data(), false);
    }
}

void Friends::slot_ApplyFriendsRes(char * recvMessage)
{
    QMessageBox::information(nullptr, tr(u8"成功"), tr(u8"发送好友申请成功"), QMessageBox::Yes);
    // 发送好友申请成功
    im_home_proto::ApplyFriendsRes *applyFriendsRes = new im_home_proto::ApplyFriendsRes;
    applyFriendsRes->ParseFromString(recvMessage);

    AddApplyFriendItem(applyFriendsRes->friendinfo(), true);
}
