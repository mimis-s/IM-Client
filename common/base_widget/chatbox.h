#ifndef CHATBOX_H
#define CHATBOX_H

/*
    带有发送按钮,输入框, 聊天展示框等功能的聊天框
*/

#include <QWidget>
#include "circlelabel.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QTextEdit>
#include <QScrollArea>
#include <QScrollBar>
#include <QListWidget>
#include <QListWidgetItem>
#include "chatshortframe.h"
#include "../commonproto/home_chat.pb.h"
#include "common/base_widget/chatheadandbubble.h"

class ChatBox : public QWidget
{
    Q_OBJECT
public:
    explicit ChatBox(QWidget *parent = nullptr, ChatShortFrameData data = ChatShortFrameData{});
    void AddMessage(const im_home_proto::ChatMessage &pMessage);
    void AddOneQueryHistoryBtn(); // 添加一个查询历史记录的按钮(类似于qq那个在聊天框中的刷新按钮)
    void InsertMessage(const im_home_proto::ChatMessage pMessage);
signals:

public slots:
    void slot_btnSendClick();
    void slot_btnQueryHistoryClick();

private:

    CircleLabel *m_pLbHead;
    QLabel *m_pLbName;
    QPushButton *m_pBtnPhone;
    QPushButton *m_pBtnVideo;
    QListWidget *m_pMiddleListWidget;
    QPushButton *m_pBtnEmoj;
    QTextEdit *m_pTextInput;
    QPushButton *m_pBtnSend;

    ChatShortFrameData m_chatShortFrameData;

    int64_t m_maxMessageHistoryID = 0; //最大不可见历史消息id
};

#endif // CHATBOX_H
