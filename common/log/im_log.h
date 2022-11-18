/*
    日志类
    暂时作为一个单例类实现, 不能支持多线程读写
*/

#include <QString>

class IMLog
{
public:
    IMLog() {}
    ~IMLog() {}

    static IMLog *Instance()
    {
        if (m_pLog == nullptr)
        {
            m_pLog = new IMLog();
        }
        return m_pLog;
    }

    void Info(QString log);  // 正常日志
    void Error(QString log); // 错误日志
    void Warn(QString log);  // 警告日志

private:
    static IMLog *m_pLog;
};