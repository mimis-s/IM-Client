/*
    crc32编码用于给每个msg生成一个唯一的编码
*/
#pragma once

#include <inttypes.h>
#include <stdio.h>
#include <QDebug>
#include <string>

//生成table
void makeCRCTable();

uint32_t CRC32(std::string buff);
