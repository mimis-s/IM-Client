#ifndef FRIENDCHATBOX_H
#define FRIENDCHATBOX_H

/*
    好友聊天界面旁边的消息,简介框(点击之后可进入对应好友聊天)
*/

#include <QWidget>
#include <QLabel>
#include <QDateTime>
#include "circlelabel.h"
#include "../define/define.h"

enum ENUM_OnLineStatus {
    ENUM_OutLine = 0,   // 离线
    ENUM_OnLine = 1,    // 在线
};

struct ChatShortFrameData {
    QString m_HeadPath;             // 头像路径
    ENUM_OnLineStatus m_Online;     // 在线提示
    QString m_Name;                 // 好友名字
    int64_t m_FriendID;             // 好友id
    QString m_Message;              // 最新消息
    int m_TipsNum;                  // 未读消息提示
    QString m_Time;                 // 最后消息的时间
};

class ChatShortFrame : public QWidget
{
    Q_OBJECT
public:
    explicit ChatShortFrame(QWidget *parent = nullptr);

    // 更新数据
    void UpdateData(ChatShortFrameData data);
signals:

private:
    CircleLabel *m_pLbHead;     // 头像
    QLabel *m_pLbName;          // 好友名字
    QLabel *m_pLbMessage;       // 最新消息
    CircleLabel *m_pLbTips;     // 未读消息提示
    QLabel *m_pLbTime;          // 最后消息的时间

    ENUM_OnLineStatus m_OnlineStatus;        // 在线提示
};

#endif // FRIENDCHATBOX_H
