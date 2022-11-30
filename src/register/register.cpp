#include "register.h"
#include "ui_register.h"
#include "../../common/socket/socket.h"
#include "../../common/define/define.h"
#include "../../common/commonproto/home_account.pb.h"
#include "../../common/log/im_log.h"
#include <QMessageBox>

CUserRegister::CUserRegister(QDialog *parent) : QDialog(parent),
    ui(new Ui::CUserRegister)
{
    ui->setupUi(this);

    connect(ui->btn_register, SIGNAL(clicked(void)), this, SLOT(slot_btn_register()));

    // socket
    SocketControl::Instance()->RegisterRecvFunc(MessageTag_Register.Res, std::bind(&CUserRegister::RegisterBack, this, std::placeholders::_1));
}

CUserRegister::~CUserRegister()
{
    delete ui;
}

void CUserRegister::slot_btn_register()
{
    // send register
    if (ui->edit_register_password->text() != ui->edit_register_password_again->text() || ui->edit_register_name->text() == "" || ui->edit_register_password->text() == "")
    {
        QMessageBox::information(nullptr, "register fail", "name or password error", QMessageBox::Yes);
    }
    else
    {
        im_home_proto::RegisterReq *registerReq = new im_home_proto::RegisterReq;
        registerReq->set_username(ui->edit_register_name->text().toStdString());
        registerReq->set_password(ui->edit_register_password_again->text().toStdString());

        IMLog::Instance()->Info(QString("send registerReq %1").arg(MessageTag_Register.Req));

        SocketControl::Instance()->SendMessage(MessageTag_Register.Req, registerReq->SerializeAsString());
    }

}

void CUserRegister::RegisterBack(char * recvMessage)
{
    im_home_proto::RegisterRes *registerRes = new im_home_proto::RegisterRes;
    registerRes->ParseFromString(recvMessage);

    QString msg = QString("id:%1; name:%2").arg(registerRes->userid()).arg(QString::fromStdString(registerRes->username()));

    QMessageBox::information(nullptr, "register succssed", msg, QMessageBox::Yes);

    this->close();
}
