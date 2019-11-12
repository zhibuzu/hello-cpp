/***************************************************************************
 * 
 * Copyright (c) 2019 Hulifa.cn, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file src/endian/test_endian.cpp
 * @author hulifa(hulifa@gmail.com)
 * @date 2019/10/31 15:04:18
 * @version $Revision$ 
 * @brief 测试大小端 
 *  
 **/
#include <iostream>

static union { char c[4]; unsigned long l; } endian_test = { { 'l',  '?', '?', 'b'} };
#define ENDIANNESS ((char)endian_test.l)

int main() {
    if (ENDIANNESS == 'l') {
        std::cout << "Little endian" << std::endl;
    } else if (ENDIANNESS == 'b') {
        std::cout << "Big endian" << std::endl;
    } else {
        std::cout << "Something error" << std::endl;
    }
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
