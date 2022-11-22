/*
-------网络相关功能的类------------
-------单例类----------------------
*/
#pragma once

#include <QWidget>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <map>

class Closure
{
public:
    Closure(){};
    ~Closure(){};

    virtual void Run(char *message) = 0;
};

class MethodClosure2 : public Closure
{
public:
    typedef std::function<void(char *)> MethodType;

    MethodClosure2(MethodType method)
        : method_(method) {}
    ~MethodClosure2() {}

    void Run(char *message)
    {
        method_(message);
    }

private:
    MethodType method_;
};

class Socket : public QWidget
{
    Q_OBJECT

public:
    ~Socket();
    static Socket *Instance(QString ip = "", int port = 0)
    {
        if (Socket::m_this == nullptr && ip != "" && port != 0)
        {
            m_this = new Socket(nullptr, ip, port);
        }
        return m_this;
    }

    // 注册各个功能的recv函数(回调函数)
    void RegisterRecvFunc(uint32_t type, std::function<void(char *)> func)
    {
        mapCallBackFunc[type] = new MethodClosure2(func);
    }

    void SendMessage(uint32_t type, std::string message); // 外部调用发送消息

public slots:
    void slot_Connected();   // 处理成功连接到服务器的槽
    void slot_RecvMessage(); // 接收来自服务器的消息的槽
    void slot_Disconnect();  // 取消与服务器连接的槽
private:
    Socket(QWidget *parent = nullptr, QString ip = "", int port = 0);

    static Socket *m_this;
    QTcpSocket *TCP_SendMesSocket; //发送消息套接字

    std::map<uint32_t, Closure *> mapCallBackFunc;
};
