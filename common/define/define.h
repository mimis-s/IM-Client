#include <inttypes.h>
#include <stdio.h>
#include <string>
#include "../crc32/crc32.h"

struct MessageTag {
    uint32_t Req;
    uint32_t Res;
    uint32_t Relay;
};

MessageTag MessageTag_Login = {
    Req: CRC32("loginReq"),
    Res: CRC32("loginRes"),
};
