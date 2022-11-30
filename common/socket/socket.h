/*
-------网络相关功能的类------------
-------单例类----------------------
*/
#pragma once

#include <QWidget>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <map>
#include <QThread>

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

class Socket : public QThread
{
    Q_OBJECT

public:
    explicit Socket(QString ip = "", int port = 0);
    ~Socket();

    void run() override;

signals:
    void sig_ReadMessage(uint32_t type, char* message); // 通过这个槽回发读取到的消息

public slots:
    void slot_SendMessage(uint32_t type, std::string message); // 外部通过这个槽发送消息进来


protected:
    int readMessage(int iSocketFD);

private:
    QString m_sIP;
    int m_iPort;

    int m_iSocketFD = 0;
};


// socket control
class SocketControl : public QWidget
{
    Q_OBJECT

public:
    ~SocketControl();

    static SocketControl *Instance(QString ip = "", int port = 0)
    {
        if (SocketControl::m_this == nullptr && ip != "" && port != 0)
        {
            m_this = new SocketControl(nullptr, ip, port);
        }
        return m_this;
    }
    void SendMessage(uint32_t type, std::string message);

    // 注册各个功能的recv函数(回调函数)
    void RegisterRecvFunc(uint32_t type, std::function<void(char *)> func)
    {
        mapCallBackFunc[type] = new MethodClosure2(func);
    }

signals:
    // 给socket线程发送消息的信号
    void sig_SendMessage(uint32_t type, std::string message);
public slots:
    // 从socket线程里面接收回发消息的槽
    void slot_ReadMessage(uint32_t type, char* message);

private:
    explicit SocketControl(QWidget *parent = nullptr, QString ip = "", int port = 0);

    Socket *m_pSocket;

    static SocketControl *m_this;

    std::map<uint32_t, Closure *> mapCallBackFunc;

};

