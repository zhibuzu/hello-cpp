/***************************************************************************
 * 
 * Copyright (c) 2019 Hulifa.cn, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file src/openFileMode/main.cpp
 * @author hulifa(hulifa@gmail.com)
 * @date 2019/11/21 11:23:31
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <cstdio>
#include <unistd.h>

void readfile(const char* filename) {
    FILE *fp = fopen(filename, "r");
    char *buffer;
    // Get file size
    fseek(fp, 0, SEEK_END);
    long fsize = ftell(fp);
    // set the position of stream to the begining
    rewind(fp);
    buffer = (char*)malloc(sizeof(char) * fsize);
    size_t read_n = fread(buffer, 1, fsize, fp);
    printf("read %lu character: %s\n", read_n, buffer);
    fclose(fp);
    free(buffer);
};

int main(int argc, char *argv[]) {
    // Get inputing filename
    char filename[100] = {0};
    puts("Please input filename to read:");
    scanf("%s", filename);

    // 1. Read not exist file
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("opening file error");
    } else {
        printf("%s has exist, exit pragram", filename);
        return 0;
    }
    fclose(fp);

    // 2. Write not exist file
    fp = fopen(filename, "w");
    fputs("line1: hello world\n", fp);
    fclose(fp);

    // 3. Read exist file
    fp = fopen(filename, "r");
    char *buffer;
    // Get file size
    fseek(fp, 0, SEEK_END);
    long fsize = ftell(fp);
    // set the position of stream to the begining
    rewind(fp);
    buffer = (char*)malloc(sizeof(char) * fsize);
    size_t read_n = fread(buffer, 1, fsize, fp);
    printf("read %lu character: %s\n", read_n, buffer);
    fclose(fp);
    free(buffer);

    // 4. Append to exist file but not truncate file: a
    fp = fopen(filename, "a");
    fputs("line2: 2222\n", fp);
    fclose(fp);
    puts("test mode:a");
    readfile(filename);
    

    // 5. Write to exist file and truncate file: w
    fp = fopen(filename, "w");
    fputs("newline: 3333\n", fp);
    char buffer1[10] = {0};
    if (fgets(buffer1, 10, fp) == NULL) {
        perror("read error");
    }
    fclose(fp);
    puts("test mode: w");
    readfile(filename);

    // 6. Reading and Writing, truncate : w+
    fp = fopen(filename, "w+");
    fputs("Newnewline: 4444\n", fp);
    char buffer2[10] = {0};
    if (fgets(buffer2, 10, fp) == NULL) {
        perror("read error");
    }
    fclose(fp);
    puts("test mode: w+");
    readfile(filename);
    

    // 7. Reading and Writing, not truncate, initial position: r+
    fp = fopen(filename, "r+");
    char buffer3[10] = {0};
    if (fgets(buffer3, 10, fp) == NULL) {
        perror("read error");
    }
    fputs("NNewline: 555\n", fp);
    
    fclose(fp);
    puts("test mode: r+");
    readfile(filename);
    

    // 8. Reading and Writing, not truncate, not initial position : a+
    fp = fopen(filename, "a+");
    fputs("Newnewnewnewline: 666\n", fp);
    fclose(fp);
    puts("test mode: a+");
    readfile(filename);
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
