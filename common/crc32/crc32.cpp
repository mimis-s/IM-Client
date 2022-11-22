#include "crc32.h"

unsigned int CRC_32_Table[256];//用来保存CRC码表

////生成table
void makeCRCTable()
{
    unsigned int CRC;//int的大小是32位，作32位CRC寄存器
    for (int i = 0; i<256; ++i)//用++i以提高效率
    {
        CRC = i;
        for (int j = 0; j<8; ++j)
        {
            if (CRC & 1)// LSM为1
                CRC = (CRC >> 1) ^ 0xEDB88320;//采取反向校验
            else //0xEDB88320就是CRC-32多项表达式的reversed值
                CRC >>= 1;
        }
        CRC_32_Table[i] = CRC;
    }
}

uint32_t CRC32(std::string buff)
{
    makeCRCTable();
    uint32_t crc = 0 ^ (-1);
    for (int i = 0; i < buff.size(); i++)
    {
        crc = (crc >> 8) ^ CRC_32_Table[(crc ^ buff[i]) & 0xff];
    }
    qDebug() << "name:" << QString::fromStdString(buff) << " id:" <<~crc;
    return ~crc;
}
