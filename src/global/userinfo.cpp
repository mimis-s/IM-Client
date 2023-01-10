#include "userinfo.h"

UserInfo *UserInfo::m_info = nullptr;

UserInfo::UserInfo(QWidget *parent) : QWidget(parent)
{
    m_pSelfUserInfo = new ClientUserInfo();
}
