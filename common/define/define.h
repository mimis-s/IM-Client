#pragma once

#include "../crc32/crc32.h"

struct MessageTag {
    uint32_t Req;
    uint32_t Res;
    uint32_t Relay;
};

const MessageTag MessageTag_Error =         {Res: CRC32("CommonError")};
const MessageTag MessageTag_Login =         {Req: CRC32("LoginReq"), Res: CRC32("LoginRes")};
const MessageTag MessageTag_Register =      {Req: CRC32("RegisterReq"), Res: CRC32("RegisterRes")};
const MessageTag MessageTag_ChatSingle =    {Req: CRC32("ChatSingleReq"), Res: CRC32("ChatSingleRes"), Relay: CRC32("ChatSingleToReceiver")};
