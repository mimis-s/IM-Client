#include "socket.h"
#include "../log/im_log.h"
#include <QDateTime>
// #include "define.h"

Socket *Socket::m_this = nullptr;

Socket::Socket(QWidget *parent)
    : QWidget(parent)
{
    TCP_SendMesSocket = new QTcpSocket();
    TCP_SendMesSocket->abort();                          //终止之前的连接，重置套接字
    TCP_SendMesSocket->connectToHost("localhost", 8888); //给定IP和端口号，连接服务器

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

void Socket::SendMessage(int type, char *arrayMessage)
{
    QByteArray messages;
    // 消息类型
    messages[0] = type;
    messages[1] = type >> 8;
    messages[2] = type >> 16;
    messages[3] = type >> 24;

    // 消息长度
    int byteLen = strlen(arrayMessage);
    messages[4] = byteLen;
    messages[5] = byteLen >> 8;
    messages[6] = byteLen >> 16;
    messages[7] = byteLen >> 24;

    QByteArray msg = arrayMessage;
    messages.append(msg);

    TCP_SendMesSocket->write(messages);
}

void Socket::slot_RecvMessage()
{
    // 消息类型
    QByteArray messageType = TCP_SendMesSocket->read(4);
    int type = 0;
    type += (unsigned char)messageType[0];
    type += (unsigned char)messageType[1] << 8;
    type += (unsigned char)messageType[2] << 16;
    type += (unsigned char)messageType[3] << 24;

    // 消息长度
    QByteArray messageLen = TCP_SendMesSocket->read(4);
    int byteLen = 0;
    byteLen += (unsigned char)messageLen[0];
    byteLen += (unsigned char)messageLen[1] << 8;
    byteLen += (unsigned char)messageLen[2] << 16;
    byteLen += (unsigned char)messageLen[3] << 24;

    // 消息体
    char *messages_recv = new char[byteLen];
    TCP_SendMesSocket->read(messages_recv, byteLen);

    mapCallBackFunc[type]->Run(messages_recv);
}