#include "friends.h"
#include "ui_friends.h"
#include "../../common/base_widget/chatbox.h"
#include "../../common/base_widget/chatshortframe.h"
#include "../../common/socket/socket.h"
#include "../../common/define/define.h"
#include "../../common/commonproto/home_account.pb.h"
#include "../../common/log/im_log.h"
#include "frienddetails.h"

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
    m_pFriendsList= new QListWidget(this);
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
    Socket::Instance()->RegisterRecvFunc(MessageTag_GetUserInfo.Res, std::bind(&Friends::slot_GetUserInfoRes, this, std::placeholders::_1));

}

Friends::~Friends()
{
    delete ui;
}

void Friends::GetFriendsList()
{

}


void Friends::GetFriendApplyList()
{

}

void Friends::slot_btnSearchClick()
{
    // send login
    im_home_proto::GetUserInfoReq *getUserInfoReq = new im_home_proto::GetUserInfoReq;
    getUserInfoReq->set_userid(m_pEditSearchFriend->text().toUInt());

    IMLog::Instance()->Info(QString("send getUserInfoReq %1").arg(MessageTag_GetUserInfo.Req));

    Socket::Instance()->SendMessage(MessageTag_GetUserInfo.Req, getUserInfoReq->SerializeAsString());
}

void Friends::slot_GetUserInfoRes(char * recvMessage)
{
    im_home_proto::GetUserInfoRes *getUserInfoRes = new im_home_proto::GetUserInfoRes;
    getUserInfoRes->ParseFromString(recvMessage);

    // 展示获取到的用户信息
    FriendDetails friendDetails(this, getUserInfoRes);
    friendDetails.exec();
}
