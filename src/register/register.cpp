#include "register.h"
#include "ui_register.h"
#include "../../common/socket/socket.h"
#include "../../common/define/define.h"
#include "../../common/commonproto/home_account.pb.h"
#include "../../common/log/im_log.h"
#include <QMessageBox>
#include <QFileDialog>
#include "./cutouthead.h"
#include <QImage>

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
        registerReq->set_autograph(ui->edit_register_autograph->toPlainText().toStdString());
        registerReq->set_phonenumber(ui->edit_register_phone->text().toStdString());
        registerReq->set_region(ui->cb_register_region->currentText().toInt());

        // head
        QByteArray headByte;
        QDataStream ds(&headByte, QIODevice::WriteOnly);
        ds<<m_imageHead;
        QString str = QString::fromLocal8Bit(headByte.toBase64());
        registerReq->set_headimg(str.toStdString().c_str());


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

void CUserRegister::on_btn_register_head_clicked()
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
    connect(pHead, SIGNAL(sig_cutImag(QImage)), this, SLOT(slot_cutHead(QImage)));
    pHead->exec();
}

void CUserRegister::slot_cutHead(QImage image)
{
    m_imageHead = image;
    ui->btn_register_head->setIcon(QPixmap::fromImage(image));
    ui->btn_register_head->setIconSize(QSize(ui->btn_register_head->width(), ui->btn_register_head->height()));
}
