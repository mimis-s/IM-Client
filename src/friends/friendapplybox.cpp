#include "friendapplybox.h"
#include "ui_friendapplybox.h"
#include <QHBoxLayout>
#include "../../common/commonproto/home_friends.pb.h"
#include "../../common/define/define.h"
#include "../../common/socket/socket.h"
#include "../../common/log/im_log.h"

FriendApplyBox::FriendApplyBox(QWidget *parent, ChatShortFrameData data, bool bSend) : QWidget(parent),
    ui(new Ui::FriendApplyBox)
{
    ui->setupUi(this);

    m_applyFriendData = data;

    QHBoxLayout *pHBoxLayout = new QHBoxLayout(this);

    m_pChatShortFrame = new ChatShortFrame(this);
    m_pChatShortFrame->UpdateData(data);

    m_pBtnAgree = new QPushButton(tr(u8"同意"), this);   // 同意
    m_pBtnIgnore = new QPushButton(tr(u8"忽略"), this);  // 忽略
    m_pLbAlreadySend = new QLabel("已发送申请", this);    // 已发送好友申请

    pHBoxLayout->addWidget(m_pChatShortFrame);

    pHBoxLayout->addWidget(m_pBtnAgree);
    pHBoxLayout->addWidget(m_pBtnIgnore);
    pHBoxLayout->addWidget(m_pLbAlreadySend);

    if (bSend) {
        m_pBtnAgree->hide();
        m_pBtnIgnore->hide();
    }else{
        m_pLbAlreadySend->hide();
    }

    connect(m_pBtnAgree, SIGNAL(clicked()), this, SLOT(slot_agreeFriendApplyClick()));
    connect(m_pBtnIgnore, SIGNAL(clicked()), this, SLOT(slot_ignoreFriendApplyClick()));

}

FriendApplyBox::~FriendApplyBox()
{
    delete ui;
}

// 同意好友申请
void FriendApplyBox::slot_agreeFriendApplyClick()
{
    im_home_proto::AgreeFriendApplyReq *agreeFriendApplyReq = new im_home_proto::AgreeFriendApplyReq;
    agreeFriendApplyReq->set_friendsid(m_applyFriendData.m_FriendID);

    IMLog::Instance()->Info(QString("send agreeFriendApplyReq %1").arg(m_applyFriendData.m_FriendID));

    Socket::Instance()->SendMessage(MessageTag_AgreeFriendApply.Req, agreeFriendApplyReq->SerializeAsString());
}

// 忽略好友申请
void FriendApplyBox::slot_ignoreFriendApplyClick()
{
//    im_home_proto::ApplyFriendsReq *applyFriendsReq = new im_home_proto::ApplyFriendsReq;
//    applyFriendsReq->set_applyfriendsid(m_userInfo->data().userid());

//    IMLog::Instance()->Info(QString("send applyFriendsReq %1").arg(m_userInfo->data().userid()));

//    Socket::Instance()->SendMessage(MessageTag_ApplyFriends.Req, applyFriendsReq->SerializeAsString());
}
