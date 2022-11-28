#ifndef FRIENDS_H
#define FRIENDS_H

#include <QWidget>
#include <QScrollArea>
#include <QScrollBar>
#include <QListWidget>
#include <QListWidgetItem>
#include <QLineEdit>
#include <QPushButton>

namespace Ui {
class Friends;
}

class Friends : public QWidget
{
    Q_OBJECT

public:
    explicit Friends(QWidget *parent = nullptr);
    ~Friends();
    // 获取好友列表
    void GetFriendsList();

    // 获取好友申请列表
    void GetFriendApplyList();

protected slots:
    void slot_btnSearchClick();
    void slot_GetUserInfoRes(char * recvMessage);
    void slot_ApplyFriendsRelay(char * recvMessage);
    void slot_AgreeFriendApplyRes(char * recvMessage);
    void slot_AgreeFriendApplyRelay(char * recvMessage);
    void slot_ApplyFriendsRes(char * recvMessage);
    void slot_GetFriendsListRes(char * recvMessage);

private:
    Ui::Friends *ui;

    QPushButton *m_pBtnSearch;
    QLineEdit *m_pEditSearchFriend;
    QListWidget *m_pFriendsList;
    QListWidget *m_pFriendApplyList;

    // 朋友id和申请做一个映射,方便申请同意之后删除
    std::map<int64_t, QListWidgetItem *> m_mapApplyBox;
};

#endif // FRIENDS_H
