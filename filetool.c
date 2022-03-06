#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filetool.h"


/* 判断文件是否存在 存在返回0 */
int IsFileCreate(const char *filename) {
    FILE *fp;
    fp = fopen(filename, "r"); 
    if(fp == NULL) {
        return -1;
    }
    fclose(fp);
    return 0;
}

/* 系统初始化 成功返回0 */
int GlobalFileInit(void) {
    int ret = IsFileCreate(GLOBLE_FILE_NAME);  //判断文件是否存在
    FILE *fp = fopen(GLOBLE_FILE_NAME, "a+");
    global_file_ptr = (struct file_global_info *)malloc(sizeof(struct file_global_info));
    memset(global_file_ptr, 0, sizeof(struct file_global_info));

    if(ret < 0)  {  //文件不存在
        global_file_ptr->file_number = 0;
        global_file_ptr->file_iscreate = 0;
        global_file_ptr->file_ptr = NULL;
        fputs("file_count=0\n", fp);
        fputs("file_iscreate=0\n", fp);
    }else {   //文件存在

        char file_str[30];
        char *strptr;

        fgets(file_str, 30, fp);
        strptr = strchr(file_str, '=');
        global_file_ptr->file_number = atoi((++strptr));

        fgets(file_str, 30, fp);
        strptr = strchr(file_str, '=');
        global_file_ptr->file_iscreate = (unsigned int)atoi((++strptr));
        
        global_file_ptr->file_ptr = (char (*)[30])malloc(global_file_ptr->file_number*30);
        if(!global_file_ptr->file_ptr) {
            fprintf(stderr, "内存分配失败\n");
            exit(1);
        }
        
        int i = 0;
        for(i = 0; i < global_file_ptr->file_number; i++) {
            fgets(global_file_ptr->file_ptr[i], 30, fp);
        }
    }

    fclose(fp);
    return 0;
}


/* 判断该文件是否建立 */
int IsClassFileCreate(unsigned int class_id)
{
    unsigned int mask = 0x01;   
    class_id--;
    if(global_file_ptr->file_iscreate & (mask << class_id)) {
        return 1;
    }
    return 0;
}


