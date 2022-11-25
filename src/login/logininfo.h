#ifndef LOGININFO_H
#define LOGININFO_H

/*
    单例类,主要用于当客户端登录之后存储客户端的基础信息
    方便其它功能类调用
*/

#include <QWidget>
#include "../../common/commonproto/home_account.pb.h"

class LoginInfo : public QWidget
{
    Q_OBJECT
public:
    explicit LoginInfo(QWidget *parent = nullptr);

    static LoginInfo *Instance()
    {
        if (m_info == nullptr)
        {
            m_info = new LoginInfo();
        }
        return m_info;
    }

    void SetClientUserInfo(const im_home_proto::UserInfo *clientUserInfo)
    {
        m_clientUserInfo = clientUserInfo;
    }

    const im_home_proto::UserInfo* GetClientUserInfo()
    {
        return m_clientUserInfo;
    }



private:

    static LoginInfo *m_info;

    const im_home_proto::UserInfo *m_clientUserInfo;

};

#endif // LOGININFO_H
