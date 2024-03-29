#ifndef CHAT_H
#define CHAT_H

/*
    聊天界面(包括左边的聊天简介列表,和右边的消息发送,查看框)
*/

#include <QWidget>
#include "../../common/base_widget/chatbox.h"
#include "../../common/base_widget/chatshortframe.h"
#include <QVBoxLayout>
#include <map>
#include <QScrollArea>
#include <QScrollBar>
#include <QListWidget>
#include <QListWidgetItem>

namespace Ui {
class Chat;
}

// 左边是聊天简介,右边是聊天内容
struct OneChatBox {
    ChatShortFrame* Left;
    ChatBox* Right;
};

class Chat : public QWidget
{
    Q_OBJECT

public:
    explicit Chat(QWidget *parent = nullptr);
    ~Chat();

    OneChatBox AddOneChat(ChatShortFrameData data);

protected slots:
    void slot_ChatSingleRelay(char *pMessage);
    void slot_UserMessageNotify(char *pMessage);
    void slot_ChatShortFramePress(ChatShortFrameData data);

private:
    Ui::Chat *ui;

    QListWidget *m_pChatShortFrameList;

    QWidget *m_pRightChatBox;
    QVBoxLayout *m_pChatBoxLayout;

    std::map<int64_t, OneChatBox> m_mapOneChatBox;

    std::map<int64_t, bool> m_bmapOffline;   // 是否存在离线消息<friend->true>

};

#endif // CHAT_H
