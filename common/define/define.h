#pragma once

#include "../crc32/crc32.h"
#include <QDateTime>

struct MessageTag {
    uint32_t Req;
    uint32_t Res;
    uint32_t Relay;
    uint32_t Notify;
};

const QString TimeFormat = "yyyy-MM-dd hh:mm:ss";
const QString StartTime = QDateTime::currentDateTime().toString(TimeFormat);
const QString ClientMainPath = "/home/zhangbin/work/qt_pro/IM-Client/";
const QString DynamicResource = ClientMainPath + "dynamic_resource/";

const MessageTag MessageTag_Error                   = {Res: CRC32("CommonError")};
const MessageTag MessageTag_Login                   = {Req: CRC32("LoginReq"), Res: CRC32("LoginRes")};
const MessageTag MessageTag_Register                = {Req: CRC32("RegisterReq"), Res: CRC32("RegisterRes")};
const MessageTag MessageTag_ChatSingle              = {Req: CRC32("ChatSingleReq"), Res: CRC32("ChatSingleRes"), Relay: CRC32("ChatSingleToReceiver"), Notify: CRC32("ChatSingleToReceiver")};
const MessageTag MessageTag_GetUserInfo             = {Req: CRC32("GetUserInfoReq"), Res: CRC32("GetUserInfoRes")};
const MessageTag MessageTag_ApplyFriends            = {Req: CRC32("ApplyFriendsReq"), Res: CRC32("ApplyFriendsRes"), Relay: CRC32("ApplyFriendsToReceiver")};
const MessageTag MessageTag_AgreeFriendApply        = {Req: CRC32("AgreeFriendApplyReq"), Res: CRC32("AgreeFriendApplyRes"), Relay: CRC32("AgreeApplyFriendsToReceiver")};
const MessageTag MessageTag_DelFriends              = {Req: CRC32("DelFriendsReq"), Res: CRC32("DelFriendsRes")};
const MessageTag MessageTag_ModifyUserInfo          = {Req: CRC32("ModifyUserInfoReq"), Res: CRC32("ModifyUserInfoRes")};
const MessageTag MessageTag_GetSingleChatHistory    = {Req: CRC32("GetSingleChatHistoryReq"), Res: CRC32("GetSingleChatHistoryRes")};
const MessageTag MessageTag_ReadOfflineMessage      = {Req: CRC32("ReadOfflineMessageReq"), Res: CRC32("ReadOfflineMessageRes")};

const MessageTag MessageTag_NotifyUserMessage       = {Notify: CRC32("NotifyUserMessage")};
const MessageTag MessageTag_NotifyFriendsStatusList = {Notify: CRC32("FriendsStatusList")};


