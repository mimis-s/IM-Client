#ifndef CHATHISTORY_H
#define CHATHISTORY_H

/*
    存储,读取,修改本地历史记录
*/

#include <QWidget>
#include <QFile>

// 本地存储结构
struct LocalChatHistoryInfo {
    int64_t SenderID;
    int64_t ReceiverID;
    int64_t MessageID;
    int MessageType;
    int64_t SendTimeStamp;  // 发送消息的时间戳
    int MessageStatus;      // 消息状态
    QString messageData;    // 消息
};

class ChatHistory : public QWidget
{
    Q_OBJECT
public:

    static ChatHistory *Instance()
    {
        if (m_info == nullptr)
        {
            m_info = new ChatHistory();
        }
        return m_info;
    }

    explicit ChatHistory(QWidget *parent = nullptr);
    // 获取历史数据(先在本地寻找, 本地没有再请求服务器数据, 然后存储到本地存储)
    std::map<int64_t, LocalChatHistoryInfo> GetHistoryChat(int64_t friendID, int64_t maxMessageID);
    // 读取离线消息,服务器返回消息,存储在本地存储
    void ReadOfflineMessage(int64_t friendID);

protected:
    QJsonArray AddHistoryFile(QJsonArray localHistoryArray, std::map<int64_t, LocalChatHistoryInfo> info);

signals:

private:
    static ChatHistory *m_info;

};

#endif // CHATHISTORY_H
