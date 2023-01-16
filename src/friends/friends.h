#ifndef FRIENDS_H
#define FRIENDS_H

#include <QWidget>
#include <QScrollArea>
#include <QScrollBar>
#include <QListWidget>
#include <QListWidgetItem>
#include <QLineEdit>
#include <QPushButton>
#include "../../common/base_widget/chatshortframe.h"

namespace Ui {
class Friends;
}

class Friends : public QWidget
{
    Q_OBJECT

public:
    explicit Friends(QWidget *parent = nullptr);
    ~Friends();

    void AddApplyFriendItem(const im_home_proto::UserInfo pUserInfo, bool isApply);
    void AddFriendItem(const im_home_proto::UserInfo pUserInfo, bool bUpdateHead);

signals:
    void sig_AddOneChat(ChatShortFrameData data);   // 新增一个好友聊天, 如果存在则跳转

protected slots:
    void slot_btnSearchClick();
    void slot_ApplyFriendsRelay(char * recvMessage);
    void slot_AgreeFriendApplyRes(char * recvMessage);
    void slot_AgreeFriendApplyRelay(char * recvMessage);
    void slot_ApplyFriendsRes(char * recvMessage);
    void slot_NotifyFriendsStatusList(char * recvMessage);

    // 双击好友跳转到聊天界面
    void slot_ChatShortFrameClickDouble(ChatShortFrameData data);


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
