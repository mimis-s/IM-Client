#ifndef HOME_H
#define HOME_H

/*
    chat
    friend
    group
*/

#include <QWidget>
#include "../chat/chat.h"
#include "../friends/friends.h"

namespace Ui {
class Home;
}

class Home : public QWidget
{
    Q_OBJECT

public:
    explicit Home(QWidget *parent = nullptr);
    ~Home();
//    QPushButton *pLeftBtnChat = new QPushButton(tr(u8"聊天"), pLeftWidget);
//    QPushButton *pLeftBtnFriends = new QPushButton(tr(u8"好友"), pLeftWidget);
//    QPushButton *pLeftBtnGroup = new QPushButton(tr(u8"群组"), pLeftWidget);

public slots:
    void slot_btnChatClick();       // 按钮切换到聊天界面
    void slot_btnFriendsClick();    // 按钮切换到好友界面
    void slot_btnGroupClick();      // 按钮切换到群组界面

    void slot_friends_addOneChat(ChatShortFrameData data);  // 好友界面发出信号,新增一个好友聊天

private:
    Ui::Home *ui;

    Chat *m_pChat;
    Friends *m_pFriends;
};

#endif // HOME_H
