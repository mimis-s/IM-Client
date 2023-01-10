#include "home.h"
#include "ui_home.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QFileDialog>
#include <QMessageBox>
#include "../../common/base_widget/circlelabel.h"
#include "../global/userinfo.h"
#include "../register/cutouthead.h"
#include "../../common/socket/socket.h"
#include "../../common/define/define.h"
#include "../../common/commonproto/home_account.pb.h"
#include "../../common/log/im_log.h"

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

    // 头像
    m_pLeftLbHead = new CircleLabel(pLeftWidget, ENUM_CircleStyle::ENUM_Head);
    m_pLeftLbHead->setMinimumSize(100, 100);
    m_pLeftLbHead->setMaximumSize(100, 100);
    QString headPath = UserInfo::Instance()->GetSelfUserInfo()->HeadPath;
    m_pLeftLbHead->SetImgPath(headPath);

    QPushButton *pLeftBtnChat = new QPushButton(tr(u8"聊天"), pLeftWidget);      // 按钮切换到聊天界面
    QPushButton *pLeftBtnFriends = new QPushButton(tr(u8"好友"), pLeftWidget);   // 按钮切换到好友界面
    QPushButton *pLeftBtnGroup = new QPushButton(tr(u8"群组"), pLeftWidget);     // 按钮切换到群组界面

    QPushButton *pLeftBtnBlack = new QPushButton(tr(u8"黑夜"), pLeftWidget);     // 按钮切换黑夜/白昼模式
    QPushButton *pLeftBtnHead = new QPushButton(tr(u8"head"), pLeftWidget);      // 头像按钮(查看个人信息)

    pLeftVBoxLayout->addWidget(m_pLeftLbHead);
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

    pVBoxLayoutRightWidget->addWidget(m_pChat);

    m_pFriends = new Friends(pRightWidget);
    pVBoxLayoutRightWidget->addWidget(m_pFriends);
    m_pFriends->hide();

    pHBoxLayout->addWidget(pRightWidget, 9);

    connect(m_pLeftLbHead, SIGNAL(sig_clicked()), this, SLOT(slot_changeHeadClick()));

    connect(pLeftBtnChat, SIGNAL(clicked()), this, SLOT(slot_btnChatClick()));
    connect(pLeftBtnFriends, SIGNAL(clicked()), this, SLOT(slot_btnFriendsClick()));
    connect(pLeftBtnGroup, SIGNAL(clicked()), this, SLOT(slot_btnGroupClick()));

    connect(m_pFriends, SIGNAL(sig_AddOneChat(ChatShortFrameData)), this, SLOT(slot_friends_addOneChat(ChatShortFrameData)));
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
    m_pFriends->GetFriendsList();
}

void Home::slot_btnGroupClick()
{
    m_pChat->hide();
    m_pFriends->hide();
}

// 好友界面发出信号,新增一个好友聊天
void Home::slot_friends_addOneChat(ChatShortFrameData data)
{
    m_pChat->AddOneChat(data);
    m_pChat->show();
    m_pFriends->hide();
}

void Home::slot_changeHeadClick()
{
    QString path = QFileDialog::getOpenFileName(this, tr("选择头像"), ".", tr("Image Files(*.jpg *.png)"));
    QImage* img = new QImage;
    if(!(img->load(path))) //加载图像
    {
       QMessageBox::information(this, tr("打开图像失败"), tr("打开图像失败!"));
       delete img;
       return;
    }

    CutOutHead *pHead = new CutOutHead(nullptr, *img);
    connect(pHead, SIGNAL(sig_cutImag(QImage)), this, SLOT(slot_cutChangeHead(QImage)));
    pHead->exec();
}

void Home::slot_cutChangeHead(QImage imag)
{
    im_home_proto::ModifyUserInfoReq *pModifyUserInfoReq = new im_home_proto::ModifyUserInfoReq;
    im_home_proto::UserInfo* userInfo = new im_home_proto::UserInfo();
    userInfo->set_userid(UserInfo::Instance()->GetSelfUserInfo()->mUserData.UserID);

    // head
    QByteArray headByte;
    QDataStream ds(&headByte, QIODevice::WriteOnly);
    ds<<imag;
    QString str = QString::fromLocal8Bit(headByte.toBase64());
    userInfo->set_headimg(str.toStdString().c_str());

    pModifyUserInfoReq->set_allocated_data(userInfo);


    char *recvMessage = SocketControl::Instance()->BlockSendMessage(MessageTag_ModifyUserInfo.Req, MessageTag_ModifyUserInfo.Res, pModifyUserInfoReq->SerializeAsString());

    im_home_proto::ModifyUserInfoRes *pModifyUserInfoRes = new im_home_proto::ModifyUserInfoRes;
    pModifyUserInfoRes->ParseFromString(recvMessage);

    // 更新本地头像内存
    UserInfo::Instance()->SetSelfUserInfoV1(pModifyUserInfoRes->data());

    QString headPath = UserInfo::Instance()->GetUserHeadPath(pModifyUserInfoRes->data().userid());
    m_pLeftLbHead->SetImgPath(headPath);
}
