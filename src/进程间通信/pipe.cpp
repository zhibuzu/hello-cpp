/***************************************************************************
 * 
 * Copyright (c) 2019 Hulifa.cn, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file src/进程间通信/pipe.cpp
 * @author hulifa(hulifa@gmail.com)
 * @date 2019/09/25 15:13:56
 * @version $Revision$ 
 * @brief 
 *  
 **/
#include <cstdio>
#include <cerrno>
#include <unistd.h> // 匿名管道通信必须包含的头文件
#include <string.h>

/**
 * 匿名管道是半双工通信，只能从一端写，从另一端读
 * fd参数返回2个文件描述符，fd[0]指向管道读端，fd[1]指向管道写端，fd[1]的输出是fd[0]的输入
 * 创建成功返回0，出错返回-1
 */
// int pipe(int fd[2]);
int main()
{
    // 1) 创建一个匿名管道，返回两个文件描述符，fd[0]指向管道读端，fd[1]指向管道写端，fd[1]的输出是fd[0]的输入
    // 2) fork一个子进程，对于父进程，关闭管道读端，子进程关闭管道写端，父进程通过fd[1]往管道写信息，子进程通过fd[0]从同一个管道读信息
    // 3) 执行二进制程序结果：每隔2秒stdout输出"I am child"，重复5次

    int fd[2];
    int ret = pipe(fd);
    if (ret == -1) {
        perror("pipe error");
        return 1;
    }

    pid_t id = fork();
    if (id == 0) { // child process
        int j = 0;
        close(fd[1]); // close write fd
        char msg[100] = {0};
        while (1) {
            //size_t n = read(fd[0], msg, sizeof(msg));
            //if (n > 0) {
            //   msg[n - 1] = '\0';
            //    printf("%s\n", msg);
            //} else {
            //    printf("can't read nothing\n");
            //}
            ++j;
        }
    } else if (id > 0) { // parent process
        int i = 0;
        close(fd[0]); //close read fd
        char child[100] = {0};
        while (1) {
            sprintf(child, "I am child %d", i);
            write(fd[1], child, strlen(child) + 1);
            sleep(1);
            //if (i >= 5) {
             //   close(fd[1]);
            //}
            ++i;
        }
    } else {
        perror("fork error");
        return 2;
    }
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
