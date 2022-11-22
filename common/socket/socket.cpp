#include "socket.h"
#include "../log/im_log.h"
#include <QDateTime>
#include "../define/define.h"
#include "../commonproto/errors.pb.h"
#include <QMessageBox>

Socket *Socket::m_this = nullptr;

Socket::Socket(QWidget *parent, QString ip, int port)
    : QWidget(parent)
{
    TCP_SendMesSocket = new QTcpSocket();
    TCP_SendMesSocket->abort();                          //终止之前的连接，重置套接字
    TCP_SendMesSocket->connectToHost(ip, port); //给定IP和端口号，连接服务器

    connect(TCP_SendMesSocket, SIGNAL(connected()), this, SLOT(slot_Connected()));
    connect(TCP_SendMesSocket, SIGNAL(readyRead()), this, SLOT(slot_RecvMessage()));
    connect(TCP_SendMesSocket, SIGNAL(disconnected()), this, SLOT(slot_Disconnect()));
}

Socket::~Socket()
{
}

void Socket::slot_Connected()
{
    IMLog::Instance()->Info(tr(u8"connect service success"));
}

void Socket::slot_Disconnect()
{
    IMLog::Instance()->Info(tr(u8"与服务器的连接中断"));
    //关闭并随后删除socket
    TCP_SendMesSocket->close();
    TCP_SendMesSocket->deleteLater();
}

void Socket::SendMessage(uint32_t type, std::string arrayMessage)
{
    QByteArray messages;
    // 消息类型
    messages[3] = type;
    messages[2] = type >> 8;
    messages[1] = type >> 16;
    messages[0] = type >> 24;

    // 消息长度
    int byteLen = arrayMessage.size();
    messages[7] = byteLen;
    messages[6] = byteLen >> 8;
    messages[5] = byteLen >> 16;
    messages[4] = byteLen >> 24;

    QByteArray msg =  QByteArray::fromStdString(arrayMessage);
    messages.append(msg);

    TCP_SendMesSocket->write(messages);
}

void Socket::slot_RecvMessage()
{
    // 消息类型
    QByteArray messageType = TCP_SendMesSocket->read(4);
    uint32_t type = 0;
    type += (unsigned char)messageType[3];
    type += (unsigned char)messageType[2] << 8;
    type += (unsigned char)messageType[1] << 16;
    type += (unsigned char)messageType[0] << 24;

    // 消息长度
    QByteArray messageLen = TCP_SendMesSocket->read(4);
    int byteLen = 0;
    byteLen += (unsigned char)messageLen[3];
    byteLen += (unsigned char)messageLen[2] << 8;
    byteLen += (unsigned char)messageLen[1] << 16;
    byteLen += (unsigned char)messageLen[0] << 24;

    // 消息体
    char *messages_recv = new char[byteLen];
    TCP_SendMesSocket->read(messages_recv, byteLen);

    if (MessageTag_Error.Res == type) {
//         error
        im_error_proto::CommonError *commonError = new im_error_proto::CommonError;
        commonError->ParseFromString(messages_recv);
        QString errMessage = QString("ErrCode:%1").arg(commonError->code());
        QMessageBox::information(NULL,  "error",  errMessage, QMessageBox::Yes);
    }

    if (mapCallBackFunc[type]) {
        mapCallBackFunc[type]->Run(messages_recv);
    }else{
        IMLog::Instance()->Warn(QString("recv message[%1] but message is not define").arg(type));
    }
}
