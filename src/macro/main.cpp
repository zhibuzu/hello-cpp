/***************************************************************************
 * 
 * Copyright (c) 2019 Hulifa.cn, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file src/macro/main.cpp
 * @author hulifa(hulifa@gmail.com)
 * @date 2019/10/14 16:41:47
 * @version $Revision$ 
 * @brief 
 *  
 **/

#define ADD(x, ...) add(x, name_##__VA_ARGS__)

int add(int a, int b) {
    return a + b;
};

int main() {
    int a = 1, b = 2;
    ADD(a, b, "sss");
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
