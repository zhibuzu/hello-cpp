/***************************************************************************
 * 
 * Copyright (c) 2019 Hulifa.cn, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file /Users/hulifa/code/github/hello-cpp/src/rem_to_mod/main.cpp
 * @author hulifa(hulifa@gmail.com)
 * @date 2019/11/11 15:54:30
 * @version $Revision$ 
 * @brief 在c/c++中，%表示求余运算，基于求余运算设计取模函数
 *  
 **/

#include <iostream>
#include <cstdlib>

int rem_to_mod(int a, int b) {
    int c = a / b;
    // a、b符号不同
    if ((a^b) < 0) {
        c -= 1;
    }
    return a - (c * b);
};

int main(int argc, char *argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " num1 num2" << std::endl;
        return -1;
    }

    std::cout << (rem_to_mod(atoi(argv[1]), atoi(argv[2]))) << std::endl;
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
