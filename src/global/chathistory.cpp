#include "chathistory.h"
#include "../../common/define/define.h"
#include "../../common/socket/socket.h"
#include "../../common/commonproto/home_message.pb.h"
#include "../../common/log/im_log.h"
#include "userinfo.h"
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonParseError>
#include <QDir>

ChatHistory *ChatHistory::m_info = nullptr;

ChatHistory::ChatHistory(QWidget *parent) : QWidget(parent)
{

}

// 读取离线消息,服务器返回消息,存储在本地存储
void ChatHistory::ReadOfflineMessage(int64_t friendID)
{
    im_home_proto::ReadOfflineMessageReq *readOfflineMessageReq = new im_home_proto::ReadOfflineMessageReq;
    readOfflineMessageReq->set_friendid(friendID);
    char *recvMessage = SocketControl::Instance()->BlockSendMessage(MessageTag_ReadOfflineMessage.Req, MessageTag_ReadOfflineMessage.Res, readOfflineMessageReq->SerializeAsString());

    im_home_proto::ReadOfflineMessageRes *readOfflineMessageRes = new im_home_proto::ReadOfflineMessageRes;
    readOfflineMessageRes->ParseFromString(recvMessage);


    int64_t selfUserID = UserInfo::Instance()->GetSelfUserInfo()->mUserData.UserID;
    QString filePath = DynamicResource + QString::number(selfUserID) + "/chat_history/";

    std::map<int64_t, LocalChatHistoryInfo> mapChatHistory;
    QJsonArray historyArray;

    QDir dir;
    if(!dir.exists(filePath))
    {
        if (!dir.mkpath(filePath)) {
            IMLog::Instance()->Warn(QString("can't create file path %1 !").arg(filePath));
        }
    }

    filePath += QString::number(friendID) +".json";
    // 本地查找
    QFile file(filePath);
    if (!file.open(QIODevice::ReadWrite)) {
        IMLog::Instance()->Warn(QString("can't open file %1 !").arg(filePath));
        file.close();
    }else{
        QString val = file.readAll();
        historyArray = QJsonDocument::fromJson(val.toUtf8()).object().value("chat_history").toArray();
    }

    for(int i = 0; i < readOfflineMessageRes->data_size(); i++){
        LocalChatHistoryInfo infoTemp;
        infoTemp.SenderID = readOfflineMessageRes->data(i).senderid();
        infoTemp.ReceiverID = readOfflineMessageRes->data(i).receiverid();
        infoTemp.MessageID = readOfflineMessageRes->data(i).messageid();
//        infoTemp.MessageType = readOfflineMessageRes->data(i).messagetype();
        infoTemp.SendTimeStamp = readOfflineMessageRes->data(i).sendtimestamp();
        infoTemp.MessageStatus = readOfflineMessageRes->data(i).messagestatus();
        infoTemp.messageData =  QString::fromStdString(readOfflineMessageRes->data(i).data());
        mapChatHistory[infoTemp.MessageID] = infoTemp;
    }

    historyArray = AddHistoryFile(historyArray, mapChatHistory);

    QFile file_2(filePath);
    if (!file_2.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        IMLog::Instance()->Warn(QString("can't open file %1 !").arg(filePath));
        file_2.close();
    }

    QTextStream stream(&file);
    stream.setCodec("UTF-8");		// 设置写入编码是UTF8
    // 写入文件
    QJsonDocument doc;
    doc.setArray(historyArray);
    stream << doc.toJson();
    file.close();
}

// 获取历史数据(先在本地寻找, 本地没有再请求服务器数据)
std::map<int64_t, LocalChatHistoryInfo> ChatHistory::GetHistoryChat(int64_t friendID, int64_t maxMessageID)
{
    int64_t selfUserID = UserInfo::Instance()->GetSelfUserInfo()->mUserData.UserID;
    QString filePath = DynamicResource + QString::number(selfUserID) + "/chat_history/";

    std::map<int64_t, LocalChatHistoryInfo> mapChatHistory;

    int64_t minMessageID = maxMessageID - 20 + 1 < 0?0:maxMessageID - 20 + 1;
    QJsonArray historyArray;

    QDir dir;
    if(!dir.exists(filePath))
    {
        if (!dir.mkpath(filePath)) {
            IMLog::Instance()->Warn(QString("can't create file path %1 !").arg(filePath));
        }
    }

    filePath += QString::number(friendID) +".json";
    // 本地查找
    QFile file(filePath);
    if (!file.open(QIODevice::ReadWrite)) {
        IMLog::Instance()->Warn(QString("can't open file %1 !").arg(filePath));
        file.close();
    }else{
        QString val = file.readAll();
        historyArray = QJsonDocument::fromJson(val.toUtf8()).object().value("chat_history").toArray();
        for (int i = 0; i < historyArray.size(); i++) {
            QJsonObject chatHistoryObject = historyArray.at(i).toObject();

            int64_t messageID = QString::number(chatHistoryObject.value("message_id").toDouble(), 'f', 0).toLongLong();
            if (messageID >= minMessageID && messageID <= maxMessageID) {
                int64_t senderID = QString::number(chatHistoryObject.value("sender_id").toDouble(), 'f', 0).toLongLong();
                int64_t receiverID = QString::number(chatHistoryObject.value("receiver_id").toDouble(), 'f', 0).toLongLong();
                int64_t sendTimeStamp = QString::number(chatHistoryObject.value("send_time_stamp").toDouble(), 'f', 0).toLongLong();

                LocalChatHistoryInfo infoTemp;
                infoTemp.SenderID = senderID;
                infoTemp.ReceiverID = receiverID;
                infoTemp.MessageID = messageID;
                infoTemp.MessageType = chatHistoryObject.value("message_type").toInt();
                infoTemp.SendTimeStamp = sendTimeStamp;
                infoTemp.MessageStatus = chatHistoryObject.value("message_status").toInt();
                infoTemp.messageData = chatHistoryObject.value("message_data").toString();
                mapChatHistory[messageID] = infoTemp;
            }
        }
    }

    if (mapChatHistory.size() != ulong(maxMessageID - minMessageID + 1)) {
        // 本地记录不完整(需要从服务器获取记录)
        im_home_proto::GetSingleChatHistoryReq *getSingleChatHistoryReq = new im_home_proto::GetSingleChatHistoryReq;
        getSingleChatHistoryReq->set_friendid(friendID);
        getSingleChatHistoryReq->set_maxnotgainmessageid(maxMessageID);
        char *recvMessage = SocketControl::Instance()->BlockSendMessage(MessageTag_GetSingleChatHistory.Req, MessageTag_GetSingleChatHistory.Res, getSingleChatHistoryReq->SerializeAsString());

        im_home_proto::GetSingleChatHistoryRes *getSingleChatHistoryRes = new im_home_proto::GetSingleChatHistoryRes;
        getSingleChatHistoryRes->ParseFromString(recvMessage);

        for(int i = 0; i < getSingleChatHistoryRes->data_size(); i++){
            LocalChatHistoryInfo infoTemp;
            infoTemp.SenderID = getSingleChatHistoryRes->data(i).senderid();
            infoTemp.ReceiverID = getSingleChatHistoryRes->data(i).receiverid();
            infoTemp.MessageID = getSingleChatHistoryRes->data(i).messageid();
//            infoTemp.MessageType = getSingleChatHistoryRes->data(i).messagetype();
            infoTemp.SendTimeStamp = getSingleChatHistoryRes->data(i).sendtimestamp();
            infoTemp.MessageStatus = getSingleChatHistoryRes->data(i).messagestatus();
            infoTemp.messageData =  QString::fromStdString(getSingleChatHistoryRes->data(i).data());
            mapChatHistory[infoTemp.MessageID] = infoTemp;
        }

        historyArray = AddHistoryFile(historyArray, mapChatHistory);

        QFile file(filePath);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
            IMLog::Instance()->Warn(QString("can't open file %1 !").arg(filePath));
            file.close();
            return mapChatHistory;
        }

        QTextStream stream(&file);
        stream.setCodec("UTF-8");		// 设置写入编码是UTF8
        // 写入文件
        QJsonDocument doc;
        doc.setArray(historyArray);
        stream << doc.toJson();
        file.close();
    }
    return mapChatHistory;
}

// 添加历史数据到文件里面
QJsonArray ChatHistory::AddHistoryFile(QJsonArray localHistoryArray, std::map<int64_t, LocalChatHistoryInfo> historys)
{
    for(auto info : historys) {
        bool bLocal = false;
        for (int i = 0; i < localHistoryArray.size(); i++) {
        QJsonObject chatHistoryObject = localHistoryArray.at(i).toObject();
        int64_t messageID = QString::number(chatHistoryObject.value("message_id").toDouble(), 'f', 0).toLongLong();
            if (messageID == info.second.MessageID) {
                   bLocal = true;
                   break;
            }
        }

        if (!bLocal) {
            QJsonObject jsonObject;
            jsonObject.insert("sender_id", QJsonValue(qint64(info.second.SenderID)));
            jsonObject.insert("receiver_id", QJsonValue(qint64(info.second.ReceiverID)));
            jsonObject.insert("message_id", QJsonValue(qint64(info.second.MessageID)));
            jsonObject.insert("message_type", info.second.MessageType);
            jsonObject.insert("send_time_stamp", QJsonValue(qint64(info.second.SendTimeStamp)));
            jsonObject.insert("message_status", info.second.MessageStatus);
            jsonObject.insert("message_data", info.second.messageData);

            localHistoryArray.append(jsonObject);
        }
    }

    return localHistoryArray;
}
