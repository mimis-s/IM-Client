/*
    crc32编码用于给每个msg生成一个唯一的编码
*/
#include <inttypes.h>
#include <stdio.h>
#include <string>

uint32_t CRC32(std::string s)
{
    uint32_t crc = 0xffffffff;

    for (int i = 0; i < s.size(); i++)
    {
        uint8_t byte = s[i];
        crc = crc ^ byte;
        for (uint8_t j = 8; j > 0; --j)
        {
            crc = (crc >> 1) ^ (0xEDB88320 & (-(crc & 1)));
        }

        i++;
    }
    return crc ^ 0xffffffff;
}
