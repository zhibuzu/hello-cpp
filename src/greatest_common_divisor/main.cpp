/***************************************************************************
 * 
 * Copyright (c) 2019 Hulifa.cn, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file src/greatest_common_divisor/main.cpp
 * @author hulifa(hulifa@gmail.com)
 * @date 2019/11/11 16:12:41
 * @version $Revision$ 
 * @brief 欧几里得法求最大公约数
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

// 欧几里得算法递归版本
int gcd_euclid_recu(int a, int b) {
    if (b == 0) {
        return a;
    }

    return gcd_euclid_recu(b, rem_to_mod(a, b));
};

// 欧几里得算法非递归版本
int gcd_euclid_norecu(int a, int b) {
    int tmp;
    while (b) {
        tmp = rem_to_mod(a, b);
        a = b;
        b = tmp;
    }
    return a;
};

// stein算法递归版本
// c的初始值为1
int gcd_stein_recu(int a, int b, int c = 1);
int gcd_stein_recu(int a, int b, int c) {
    if (a == 0) {
        return b*c;
    } else if (b == 0) {
        return a*c;
    }

    if (a%2 == 0 && b%2 == 0) {
        a >>= 1;
        b >>= 1;
        c <<= 1;
    } else if (a%2 == 0 && b%2 != 0) {
        a >>= 1;
    } else if (a%2 != 0 && b%2 == 0) {
        b >>= 1;
    } else {
        a -= b;
        b = a > 0 ? b : a + b;
        a = a >= 0 ? a : -a;
    }
    
    return gcd_stein_recu(a, b, c);
};

// stein算法非递归版本
int gcd_stein_norecu(int a, int b, int c = 1);
int gcd_stein_norecu(int a, int b, int c) {
    while (a*b) {
        if (a%2 == 0 && b%2 == 0) {
            a >>= 1;
            b >>= 1;
            c <<= 1;
        } else if (a%2 == 0 && b%2 != 0) {
            a >>= 1;
        } else if (a%2 != 0 && b%2 == 0) {
            b >>= 1;
        } else {
            a -= b;
            b = a > 0 ? b : a + b;
            a = a >= 0 ? a : -a;
        }
    }
};

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " num1 num2" << std::endl;
        return -1;
    }

    std::cout << "gcd_euclid_recu: " << gcd_euclid_recu(atoi(argv[1]), atoi(argv[2])) << std::endl;
    std::cout << "gcd_euclid_norecu: " << gcd_euclid_norecu(atoi(argv[1]), atoi(argv[2])) << std::endl;
    std::cout << "gcd_stein_recu: " << gcd_stein_recu(atoi(argv[1]), atoi(argv[2])) << std::endl;
    return 0;
}


/* vim: set ts=4 sw=4 sts=4 tw=100 */
