#ifndef __filetool_h
#define __filetool_h

#define GLOBLE_FILE_NAME "file_global_info.dat"
#define FILE_CREATE_MAX_NUMBER  32

struct file_global_info {
    size_t file_number;
    unsigned int file_iscreate;       //用来判断文件是否创建
    char (*file_ptr)[30];             //该指针是一个二维数组的指针
};

struct file_global_info *global_file_ptr;


struct file_info {
    unsigned int file_id;
    char file_name[30];
    size_t file_size;
};


/* 判断文件是否存在 存在返回0 */
int IsFileCreate(const char *filename);

/* 系统初始化 成功返回0 */
int GlobalFileInit(void);


int IsClassFileCreate(unsigned int class_id);


#endif /* __filetool_h */
