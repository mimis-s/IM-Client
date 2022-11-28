#include "frienddetails.h"
#include "ui_frienddetails.h"
#include "../../common/base_widget/circlelabel.h"
#include "../login/logininfo.h"
#include "../../common/socket/socket.h"
#include "../../common/commonproto/home_friends.pb.h"
#include "../../common/log/im_log.h"
#include "../../common/define/define.h"
#include <QMessageBox>

FriendDetails::FriendDetails(QWidget *parent, im_home_proto::GetUserInfoRes *info) :
    QDialog(parent),
    ui(new Ui::FriendDetails)
{
    ui->setupUi(this);
    m_userInfo = info;

    if (info == nullptr)
    {
        return;
    }

    CircleLabel *pLbHead = new CircleLabel(this, ENUM_CircleStyle::ENUM_Head);
    pLbHead->setGeometry(120, 20, 90, 90);
    if (m_userInfo->data().status() == im_home_proto::Enum_UserStatus::Enum_UserStatus_Online)
    {
        pLbHead->SetCircleColor(Qt::green);
    }else{
        pLbHead->SetCircleColor(Qt::gray);
    }
//    pLbHead->SetImgPath(QString::fromStdString(m_userInfo.headimg()));

    ui->lb_id_show->setText(QString::number(m_userInfo->data().userid()));
    ui->lb_name_show->setText(QString::fromStdString(m_userInfo->data().username()));
    ui->lb_region_show->setText(QString::number(m_userInfo->data().region()));
    ui->lb_autograph_show->setText(QString::fromStdString(m_userInfo->data().autograph()));

    if (LoginInfo::Instance()->GetClientUserInfo()->userid() == m_userInfo->data().userid())
    {
        // 搜索的是自己
        ui->btn_add_friend->hide();
        ui->btn_trun_send_message->hide();
    }else{
        if (m_userInfo->relation() == im_home_proto::Enum_UserRelation::Enum_UserRelation_Friend)
        {
            ui->btn_add_friend->setText(tr(u8"删除好友"));
            ui->btn_trun_send_message->setDisabled(false);
        }else{
            ui->btn_add_friend->setText(tr(u8"加好友"));
            ui->btn_trun_send_message->setDisabled(true);
        }
    }

}

FriendDetails::~FriendDetails()
{
    delete ui;
}

// 加好友
void FriendDetails::on_btn_add_friend_clicked()
{
    im_home_proto::ApplyFriendsReq *applyFriendsReq = new im_home_proto::ApplyFriendsReq;
    applyFriendsReq->set_applyfriendsid(m_userInfo->data().userid());

    IMLog::Instance()->Info(QString("send applyFriendsReq %1").arg(m_userInfo->data().userid()));

    Socket::Instance()->SendMessage(MessageTag_ApplyFriends.Req, applyFriendsReq->SerializeAsString());
}
