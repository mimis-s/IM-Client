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

private:
    Ui::Friends *ui;

    QPushButton *m_pBtnSearch;
    QLineEdit *m_pEditSearchFriend;
    QListWidget *m_pFriendsList;
    QListWidget *m_pFriendApplyList;
};

#endif // FRIENDS_H
