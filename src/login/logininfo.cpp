#include "logininfo.h"

LoginInfo *LoginInfo::m_info = nullptr;

LoginInfo::LoginInfo(QWidget *parent) : QWidget(parent)
{
    m_clientUserInfo = nullptr;
}
