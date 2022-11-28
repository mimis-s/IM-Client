#ifndef FRIENDDETAILS_H
#define FRIENDDETAILS_H

#include <QDialog>
#include "../../common/commonproto/home_account.pb.h"

namespace Ui {
class FriendDetails;
}

class FriendDetails : public QDialog
{
    Q_OBJECT

public:
    explicit FriendDetails(QWidget *parent = nullptr, im_home_proto::GetUserInfoRes* info = nullptr);
    ~FriendDetails();

private slots:
    void on_btn_add_friend_clicked();

private:
    Ui::FriendDetails *ui;

    im_home_proto::GetUserInfoRes* m_userInfo;
};

#endif // FRIENDDETAILS_H
