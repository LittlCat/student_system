#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "student.h"
#include "filetool.h"



void ClearLine(void);
char ShowMenu(void);


int main(void)
{
    puts("欢迎使用！");
    
    GlobalFileInit();
    printf("filecount = %ld\n", global_file_ptr->file_number);
    printf("filecount = %d\n", global_file_ptr->file_iscreate);
    printf("%s", global_file_ptr->file_ptr[0]);

    while(1) {
        char ch = ShowMenu();
        if(ch == 'q') break;
        
        switch (ch) {
            case 'a': AddStudentInfo();
                break;
            case 'b': DeleteStudentInfo();
                break;
            case 'c': ModStudentInfo();
                break;
            case 'd': FindStudentInfo();
                break;
        default:
            break;
        }
    }
    



    puts("欢迎下次使用,再见！");
    return 0;
}








char ShowMenu(void)
{
    char ch;
    char str[] = "abcdq";
    system("clear");
    printf("*********************************************\n");
    printf("*               学生管理系统                *\n");
    printf("*               a)添加学生信息              *\n");
    printf("*               b)删除学生信息              *\n");
    printf("*               c)修改学生信息              *\n");
    printf("*               d)查看学生信息              *\n");
    printf("*               q)退出学生系统              *\n");
    printf("*********************************************\n");

    ch = getchar();
    ClearLine();
    ch = tolower(ch);                      
    while(strchr(str, ch) == 0) {
        ch = getchar();
        ClearLine();
        ch = tolower(ch);                   //将获取的字符转换为小写
        fprintf(stderr, "输入错误,请重新输入:\n");
    }
    return ch;
}

char ShowSubMenu(void) { //显示子菜单
    printf("*********************************************\n");
    printf("*               学生管理系统                *\n");
    printf("*               a)添加学生信息              *\n");
    printf("*               b)删除学生信息              *\n");
    printf("*               c)修改学生信息              *\n");
    printf("*               d)查看学生信息              *\n");
    printf("*               q)退出学生系统              *\n");
    printf("*********************************************\n");
}



void ClearLine(void)
{
    while(getchar() != '\n')
        continue;
}

char *sfget(char *str, int len, FILE *fp)
{
    char *ret;
    int i = 0;

    ret = fgets(buf, len, fp);
    if(ret) {
        while(buf[i] != '\n' && buf[i] != '\0')
            i++;
        if(buf[i] == '\n') {
            buf[i] = '\0';
        }else {
            while(getchar() != '\n') 
                continue;
        }
    }
    return ret;
}