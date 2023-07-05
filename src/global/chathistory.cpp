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
#include <QDebug>

ChatHistory *ChatHistory::m_info = nullptr;

ChatHistory::ChatHistory(QWidget *parent) : QWidget(parent)
{

}

// 获取历史数据(先在本地寻找, 本地没有再请求服务器数据)
std::map<int64_t, LocalChatHistoryInfo> ChatHistory::GetHistoryChat(int64_t friendID, int64_t maxMessageID)
{
    int64_t selfUserID = UserInfo::Instance()->GetSelfUserInfo()->mUserData.UserID;
    QString filePath = DynamicResource + QString::number(selfUserID) + "/chat_history/";
    QString fileChatFilePath = DynamicResource + QString::number(selfUserID) + "/chat_history/file/";

    QDir dir;
    if(!dir.exists(fileChatFilePath))
    {
        if (!dir.mkpath(fileChatFilePath)) {
            IMLog::Instance()->Warn(QString("can't create file path %1 !").arg(fileChatFilePath));
        }
    }

    std::map<int64_t, LocalChatHistoryInfo> mapChatHistory;

    int64_t minMessageID = maxMessageID - 20 + 1 < 0?0:maxMessageID - 20 + 1;
    QJsonArray historyArray;

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
//                infoTemp.MessageType = chatHistoryObject.value("message_type").toInt();
                infoTemp.SendTimeStamp = sendTimeStamp;
                infoTemp.MessageStatus = chatHistoryObject.value("message_status").toInt();
                infoTemp.messageData = chatHistoryObject.value("message_data").toString();

                QJsonArray messageFileInfosArray = chatHistoryObject.value("message_file_infos").toArray();
                for (int j = 0; j < messageFileInfosArray.size(); j++) {
                    QJsonObject messageFileInfosObject = messageFileInfosArray.at(j).toObject();
                    MessageFileRecap messageFileRecap;
                    messageFileRecap.FileName = messageFileInfosObject.value("file_name").toString();
                    messageFileRecap.FileExtension = messageFileInfosObject.value("file_extension").toString();
                    messageFileRecap.FileSize = QString::number(messageFileInfosObject.value("file_size").toDouble(), 'f', 0).toLongLong();

                    messageFileRecap.FileIndex = messageFileInfosObject.value("file_index").toInt();
                    messageFileRecap.FileLocalPath = messageFileInfosObject.value("file_local_path").toString();
                    messageFileRecap.MessageFileType = im_home_proto::MessageFileType_Enum(messageFileInfosObject.value("message_file_type").toInt());
                }

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

            for (int j = 0; j < getSingleChatHistoryRes->data(i).messagefileinfos().size(); j++){

                MessageFileRecap messageFileRecap;
                messageFileRecap.FileName = QString::fromStdString(getSingleChatHistoryRes->data(i).messagefileinfos(j).filename());
                messageFileRecap.FileExtension = QString::fromStdString(getSingleChatHistoryRes->data(i).messagefileinfos(j).fileextension());
                messageFileRecap.FileSize = getSingleChatHistoryRes->data(i).messagefileinfos(j).filesize();
                messageFileRecap.FileIndex = getSingleChatHistoryRes->data(i).messagefileinfos(j).fileindex();
                messageFileRecap.MessageFileType = getSingleChatHistoryRes->data(i).messagefileinfos(j).messagefiletype();

                QString fileChatFilePathMessage = fileChatFilePath +
                        QString::number(getSingleChatHistoryRes->data(i).senderid()) + "-" +
                        QString::number(getSingleChatHistoryRes->data(i).receiverid()) + "-" +
                        QString::number(getSingleChatHistoryRes->data(i).messageid()) + "-" +
                        QString::number(getSingleChatHistoryRes->data(i).messagefileinfos(j).fileindex()) + ".jpg";

                // 存储本地文件
                QFile file2(fileChatFilePathMessage);
                if (!file2.open(QIODevice::ReadWrite)) {
                    IMLog::Instance()->Warn(QString("can't open file %1 !").arg(filePath));
                    file2.close();
                }
                if (messageFileRecap.MessageFileType == im_home_proto::EnumImgType){
                    QString imgData = QString::fromStdString(getSingleChatHistoryRes->data(i).messagefileinfos(j).filedata());
                    // 保存图片
                    QImage imag;
                    QByteArray data = QByteArray::fromBase64(imgData.toLocal8Bit());
                    QDataStream data_stream(&data,QIODevice::ReadOnly);
                    data_stream>>imag;
                    imag.save(fileChatFilePathMessage, "JPG");
                }
                messageFileRecap.FileLocalPath = fileChatFilePathMessage;

                infoTemp.MessageFileInfos.push_back(messageFileRecap);
            }


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
//            jsonObject.insert("message_type", info.second.MessageType);
            jsonObject.insert("send_time_stamp", QJsonValue(qint64(info.second.SendTimeStamp)));
            jsonObject.insert("message_status", info.second.MessageStatus);
            jsonObject.insert("message_data", info.second.messageData);

            QJsonArray fileInfosArray;
            for (int i = 0; i < info.second.MessageFileInfos.size(); i++) {
                QJsonObject fileInfoJsonObject;
                fileInfoJsonObject.insert("file_name", QJsonValue(info.second.MessageFileInfos[i].FileName));
                fileInfoJsonObject.insert("file_extension", QJsonValue(info.second.MessageFileInfos[i].FileExtension));
                fileInfoJsonObject.insert("file_size", QJsonValue(qint64(info.second.MessageFileInfos[i].FileSize)));
                fileInfoJsonObject.insert("file_index",info.second.MessageFileInfos[i].FileIndex);
                fileInfoJsonObject.insert("file_local_path",QJsonValue(info.second.MessageFileInfos[i].FileLocalPath));
                fileInfoJsonObject.insert("message_file_type",info.second.MessageFileInfos[i].MessageFileType);
                fileInfosArray.append(fileInfoJsonObject);
            }
            jsonObject.insert("message_file_infos", fileInfosArray);

            localHistoryArray.append(jsonObject);
        }
    }

    return localHistoryArray;
}
