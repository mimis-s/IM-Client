#include "login.h"
#include "ui_login.h"
#include <QDebug>
#include "../register/register.h"
#include "../../common/socket/socket.h"
#include "../../common/define/define.h"
#include "../../common/commonproto/home_account.pb.h"
#include "../../common/log/im_log.h"
#include "../global/userinfo.h"

login::login(QWidget *parent, QString id) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);

    connect(ui->btn_login, SIGNAL(clicked(void)), this, SLOT(slot_btn_login()));
    connect(ui->btn_login_register, SIGNAL(clicked(void)), this, SLOT(slot_btn_register()));

    ui->edit_login_id->setText(id);
    ui->edit_login_password->setText("123");

    // socket
    SocketControl::Instance()->RegisterRecvFunc(MessageTag_Login.Res, std::bind(&login::LoginBack, this, std::placeholders::_1));
}

login::~login()
{
    delete ui;
}

void login::slot_btn_login()
{
    // send login
    im_home_proto::LoginReq *loginReq = new im_home_proto::LoginReq;
    loginReq->set_userid(ui->edit_login_id->text().toLongLong());
    loginReq->set_password(ui->edit_login_password->text().toStdString());

    IMLog::Instance()->Info(QString("send loginreq %1").arg(MessageTag_Login.Req));

    SocketControl::Instance()->SendMessage(MessageTag_Login.Req, loginReq->SerializeAsString());
}

void login::slot_btn_register()
{
    this->hide();
    CUserRegister c;
    c.exec();
    this->setHidden(false);
}

void login::LoginBack(char * recvMessage)
{
    im_home_proto::LoginRes *loginRes = new im_home_proto::LoginRes;
    loginRes->ParseFromString(recvMessage);
    this->hide();

    UserInfo::Instance()->SetSelfUserInfoV1(loginRes->info());

    m_pHomeWidget = new Home();
    m_pHomeWidget->show();
}
