#ifndef USERINFO_H
#define USERINFO_H

/*
    单例类,主要用于当客户端登录之后存储客户端的基础信息
    方便其它功能类调用
*/

#include <QWidget>
#include "../../common/define/define.h"
#include "../../common/commonproto/home_account.pb.h"
#include "../../common/log/im_log.h"
#include "../../common/socket/socket.h"
#include <QImage>
#include <QDebug>
#include <QDir>
#include <QFile>

// proto结构里面的值全是const, 所以不能用,日了

struct UserData {
    int64_t UserID;
    QString UserName;
    int Region;
    QString Autograph;
    int Status;
    QString HeadImg;
    QString PhoneNumber;
};

struct ClientUserInfo {
    UserData mUserData;
    QString HeadPath;   // 本地头像地址
};

class UserInfo : public QWidget
{
    Q_OBJECT
public:
    explicit UserInfo(QWidget *parent = nullptr);

    static UserInfo *Instance()
    {
        if (m_info == nullptr)
        {
            m_info = new UserInfo();
        }
        return m_info;
    }

    void SetSelfUserInfoV1(const im_home_proto::UserInfo clientUserInfo)
    {
        m_pSelfUserInfo->mUserData.UserID = clientUserInfo.userid();
        m_pSelfUserInfo->mUserData.UserName = QString::fromStdString(clientUserInfo.username());
        m_pSelfUserInfo->mUserData.Region = clientUserInfo.region();
        m_pSelfUserInfo->mUserData.Autograph = QString::fromStdString(clientUserInfo.autograph());
        m_pSelfUserInfo->mUserData.Status = clientUserInfo.status();
        m_pSelfUserInfo->mUserData.HeadImg = QString::fromStdString(clientUserInfo.headimg());
        m_pSelfUserInfo->mUserData.PhoneNumber = QString::fromStdString(clientUserInfo.phonenumber());

        if (m_pSelfUserInfo->mUserData.HeadImg != "")
        {
            QString headPath = DynamicResource_Img_Head;

            QDir dir;
            if(!dir.exists(headPath))
            {
                if (!dir.mkpath(headPath)) {
                    IMLog::Instance()->Warn(QString("can't create file path %1 !").arg(headPath));
                }
            }
            headPath += QString::number(m_pSelfUserInfo->mUserData.UserID) + ".jpg";

            m_pSelfUserInfo->HeadPath = headPath;

            // 保存图片
            QImage imag;
            QByteArray data = QByteArray::fromBase64(m_pSelfUserInfo->mUserData.HeadImg.toLocal8Bit());
            QDataStream data_stream(&data,QIODevice::ReadOnly);
            data_stream>>imag;
            imag.save(headPath, "JPG");
        }
    }

    void AddOtherUserInfo(const im_home_proto::UserInfo clientUserInfo)
    {
        ClientUserInfo *pInfo = new ClientUserInfo();
        pInfo->mUserData.UserID = clientUserInfo.userid();
        pInfo->mUserData.UserName = QString::fromStdString(clientUserInfo.username());
        pInfo->mUserData.Region = clientUserInfo.region();
        pInfo->mUserData.Autograph = QString::fromStdString(clientUserInfo.autograph());
        pInfo->mUserData.Status = clientUserInfo.status();
        pInfo->mUserData.HeadImg = QString::fromStdString(clientUserInfo.headimg());
        pInfo->mUserData.PhoneNumber = QString::fromStdString(clientUserInfo.phonenumber());

        if (pInfo->mUserData.HeadImg != "")
        {
            QString headPath = DynamicResource_Img_Head;

            QDir dir;
            if(!dir.exists(headPath))
            {
                if (!dir.mkpath(headPath)) {
                    IMLog::Instance()->Warn(QString("can't create file path %1 !").arg(headPath));
                }
            }
            headPath += QString::number(pInfo->mUserData.UserID) + ".jpg";

            pInfo->HeadPath = headPath;

            // 保存图片
            QImage imag;
            QByteArray data = QByteArray::fromBase64(pInfo->mUserData.HeadImg.toLocal8Bit());
            QDataStream data_stream(&data,QIODevice::ReadOnly);
            data_stream>>imag;
            imag.save(headPath, "JPG");
        }
        m_mapOtherUserInfo[pInfo->mUserData.UserID] = pInfo;
    }

    // 读取本地存储的头像(如果服务器头像更新或者客户端没有存储, 则重新获取)
    QString GetUserHeadPath(int64_t userID, bool bUpdateHead)
    {
        QString headPath = DynamicResource_Img_Head;

        QDir dir;
        if(!dir.exists(headPath))
        {
            if (!dir.mkpath(headPath)) {
                IMLog::Instance()->Warn(QString("can't create file path %1 !").arg(headPath));
                return "";
            }
        }

        headPath += QString::number(userID) + ".jpg";

        if (bUpdateHead || !QFile::exists(headPath)) {
            im_home_proto::GetUserInfoReq *getUserInfoReq = new im_home_proto::GetUserInfoReq;
            getUserInfoReq->set_userid(userID);

            char *recvMessage = SocketControl::Instance()->BlockSendMessage(MessageTag_GetUserInfo.Req, MessageTag_GetUserInfo.Res, getUserInfoReq->SerializeAsString());

            im_home_proto::GetUserInfoRes *getUserInfoRes = new im_home_proto::GetUserInfoRes;
            getUserInfoRes->ParseFromString(recvMessage);
            AddOtherUserInfo(getUserInfoRes->data());
        }

        return headPath;
    }

    ClientUserInfo* GetSelfUserInfo()
    {
        return m_pSelfUserInfo;
    }

    ClientUserInfo* GetOtherUserInfo(int64_t userID)
    {
        return m_mapOtherUserInfo[userID];
    }

private:

    static UserInfo *m_info;

    // 服务器返回的数据, head_image是图片, 需要存储到本地, 然后给外部一个存储地址读取
    ClientUserInfo *m_pSelfUserInfo;                        // 自己的用户信息
    std::map<int64_t, ClientUserInfo *> m_mapOtherUserInfo;   // 其他人的用户信息
};

#endif // USERINFO_H
