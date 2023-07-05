#include "socket.h"
#include "../log/im_log.h"
#include <QDateTime>
#include "../define/define.h"
#include "../commonproto/errors.pb.h"
#include <QMessageBox>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <QCoreApplication>

SocketControl *SocketControl::m_this = nullptr;

Socket::Socket(QString ip, int port)
{
    m_sIP = ip;
    m_iPort = port;
    m_pBlockResData = nullptr;
    m_iType = 0;
}

Socket::~Socket()
{
}

BlockResData *Socket::GetBlockResMessage()
{
    return m_pBlockResData;
}

void Socket::run()
{
    m_iSocketFD = socket(AF_INET, SOCK_STREAM, 0);   //创建和服务器连接套接字
    if(m_iSocketFD == -1)
        {
            QMessageBox::information(nullptr, tr(u8"失败"), tr(u8"创建socket失败"), QMessageBox::Yes);
            perror("socket");
            return;
        }
        struct sockaddr_in addr;
        memset(&addr, 0, sizeof(addr));

        addr.sin_family = AF_INET;  /* Internet地址族 */
        addr.sin_port = htons(m_iPort);  /* 端口号 */
        addr.sin_addr.s_addr = htonl(INADDR_ANY);   /* IP地址 */
        inet_aton(m_sIP.toStdString().data() , &(addr.sin_addr));

        int addrlen = sizeof(addr);
        int listen_socket = ::connect(m_iSocketFD,  (struct sockaddr *)&addr, addrlen);  //连接服务器
        if(listen_socket == -1)
        {
            QMessageBox::information(nullptr, tr(u8"连接失败"), tr(u8"连接失败"), QMessageBox::Yes);
            perror("connect");
            return;
        }

        //接收服务器
        while(true)
        {
            if (readMessage(m_iSocketFD) == -1)
            {
                QMessageBox::information(nullptr, tr(u8"失败"), tr(u8"和服务器断开连接"), QMessageBox::Yes);
                break;
            }
        }
        close(listen_socket);
}

void Socket::slot_SendMessage(uint32_t type, QByteArray arrayMessage)
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

    QByteArray msg =  arrayMessage;
    messages.append(msg);

    write(m_iSocketFD, messages, messages.size());
}

void Socket::slot_SendBlockMessage(uint32_t reqType, uint32_t resType, QByteArray message)
{
    slot_SendMessage(reqType, message);
    m_iType = resType;
    m_pBlockResData = nullptr;
}

int Socket::readMessage(int iSocketFD)
{
    unsigned char messageType[4];
    int ret = read(iSocketFD, messageType, 4);
    if (ret != 4)
    {
        return ret;
    }
    uint32_t type = 0;
    type += (unsigned char)messageType[3];
    type += (unsigned char)messageType[2] << 8;
    type += (unsigned char)messageType[1] << 16;
    type += (unsigned char)messageType[0] << 24;

    // 消息长度
    unsigned char messageLen[4];
    ret = read(iSocketFD, messageLen, 4);
    int byteLen = 0;
    byteLen += (unsigned char)messageLen[3];
    byteLen += (unsigned char)messageLen[2] << 8;
    byteLen += (unsigned char)messageLen[1] << 16;
    byteLen += (unsigned char)messageLen[0] << 24;

    // 消息体
    char messages_recv[byteLen + 1];
    int len = byteLen;
    int lessLen = 0;
    while(len > 0) {
        ret = read(iSocketFD, messages_recv + lessLen, len);
        len -= ret;
        lessLen += ret;
    }

    if (m_iType != 0)
    {
        m_pBlockResData = new BlockResData{type, messages_recv};
        m_iType = 0;
        return ret;
    }

    QByteArray bArray(messages_recv, byteLen);
    emit sig_ReadMessage(type, bArray);
    return ret;
}

SocketControl::SocketControl(QWidget *parent, QString ip, int port):
    QWidget(parent)
{
    qRegisterMetaType<uint32_t>("uint32_t");

    m_pSocket = new Socket(ip, port);

    connect(m_pSocket, &Socket::sig_ReadMessage, this, &SocketControl::slot_ReadMessage);
    connect(m_pSocket, &QThread::finished, this, &QObject::deleteLater);
    connect(this, &SocketControl::sig_SendMessage, m_pSocket, &Socket::slot_SendMessage);
    connect(this, &SocketControl::sig_SendBlockMessage, m_pSocket, &Socket::slot_SendBlockMessage);

    m_pSocket->start();
}

SocketControl::~SocketControl()
{
    m_pSocket->quit();
    m_pSocket->wait();
}

void SocketControl::slot_ReadMessage(uint32_t type, QByteArray message)
{
    if (MessageTag_Error.Res == type) {
        im_error_proto::CommonError *commonError = new im_error_proto::CommonError;
        commonError->ParseFromString(message.data());
        QString errMessage = QString("ErrCode:%1").arg(commonError->code());
        QMessageBox::information(NULL,  "error",  errMessage, QMessageBox::Yes);
    }

    if (mapCallBackFunc.end() != mapCallBackFunc.find(type))
    {
        mapCallBackFunc[type]->Run(message.data());
    }
    else
    {
        IMLog::Instance()->Warn(QString("recv message[%1] but message is not define").arg(type));
    }
}

void SocketControl::SendMessage(uint32_t type, std::string message)
{
    emit sig_SendMessage(type, QByteArray::fromStdString(message));
}

char* SocketControl::BlockSendMessage(uint32_t reqType, uint32_t resType, std::string message)
{
    emit sig_SendBlockMessage(reqType, resType, QByteArray::fromStdString(message));

    int cnt = 0;
    while(1)
    {
        BlockResData *pBlockRes = m_pSocket->GetBlockResMessage();
        if (pBlockRes != nullptr)
        {
            if (MessageTag_Error.Res == pBlockRes->ResType) {
                im_error_proto::CommonError *commonError = new im_error_proto::CommonError;
                commonError->ParseFromString(message);
                QString errMessage = QString("ErrCode:%1").arg(commonError->code());
                QMessageBox::information(NULL,  "error",  errMessage, QMessageBox::Yes);
                return nullptr;
            }
            if (pBlockRes->ResType == resType)
            {
                return pBlockRes->ResMessage.data();
            }

            if (mapCallBackFunc.end() != mapCallBackFunc.find(pBlockRes->ResType))
            {
                mapCallBackFunc[pBlockRes->ResType]->Run(pBlockRes->ResMessage.data());
            }
            else
            {
                IMLog::Instance()->Warn(QString("recv message[%1] but message is not define").arg(pBlockRes->ResType));
                return nullptr;
            }

        }
        QThread::msleep(50);
        // 处理所有主线程阻塞的事件(预防可能出现的情况:在查询好友的时候, 来了一条消息), 废弃(在上面已经规避了这个问题)
//        QCoreApplication::processEvents();
        cnt++;
        if (cnt == 80)
        {
            // 4s
            return nullptr;
        }
    }
}
