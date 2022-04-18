#ifndef HEADER_FILE
#define HEADER_FILE

#define BLOCK_NUM 4611       //总块数
#define BLOCK_SIZE 512       //每块字节数
#define INODE_SIZE 64        //索引长度
#define DATA_BEGIN_BLOCK 515 //数据开始块
#define DIR_SIZE 32          //目录体长度
#define EXT2_NAME_LEN 15     //文件名长度
#define PATH "vdisk"         //文件系统
#define _u32 unsigned int

#define NONE                 "\e[0m"
#define BLACK                "\e[0;30m"
#define L_BLACK              "\e[1;30m"
#define RED                  "\e[0;31m"
#define L_RED                "\e[1;31m"
#define GREEN                "\e[0;32m"
#define L_GREEN              "\e[1;32m"
#define BROWN                "\e[0;33m"
#define YELLOW               "\e[1;33m"
#define BLUE                 "\e[0;34m"
#define L_BLUE               "\e[1;34m"
#define PURPLE               "\e[0;35m"
#define L_PURPLE             "\e[1;35m"
#define CYAN                 "\e[0;36m"
#define L_CYAN               "\e[1;36m"
#define GRAY                 "\e[0;37m"
#define WHITE                "\e[1;37m"
 
#define BOLD                 "\e[1m"
#define UNDERLINE            "\e[4m"
#define BLINK                "\e[5m"
#define REVERSE              "\e[7m"
#define HIDE                 "\e[8m"
#define CLEAR                "\e[2J"
#define CLRLINE              "\r\e[K" //or "\e[1K\r"
 
#define printr(format, arg...) do{printf(RED format NONE,## arg);}while(0)
#define printg(format, arg...) do{printf(GREEN format NONE,## arg);}while(0)
#define printb(format, arg...) do{printf(BLUE format NONE,## arg);}while(0)
#define printk(format, arg...) do{printf(BLACK format NONE,## arg);}while(0)
#define printw(format, arg...) do{printf(WHITE format NONE,## arg);}while(0)
#define printy(format, arg...) do{printf(YELLOW format NONE,## arg);}while(0)
#define printc(format, arg...) do{printf(CYAN format NONE,## arg);}while(0)
#define printp(format, arg...) do{printf(PURPLE format NONE,## arg);}while(0)	
	
#define printlr(format, arg...) do{printf(L_RED format NONE,## arg);}while(0)
#define printlg(format, arg...) do{printf(L_GREEN format NONE,## arg);}while(0)
#define printlb(format, arg...) do{printf(L_BLUE format NONE,## arg);}while(0)
#define printlk(format, arg...) do{printf(L_BLACK format NONE,## arg);}while(0)
#define printlw(format, arg...) do{printf(L_WHITE format NONE,## arg);}while(0)
//#define printly(format, arg...) do{printf(L_YELLOW format NONE,## arg);}while(0)
#define printlc(format, arg...) do{printf(L_CYAN format NONE,## arg);}while(0)
#define printlp(format, arg...) do{printf(L_PURPLE format NONE,## arg);}while(0)


//字节=24+16+40 = 80
typedef struct ext2_group_desc
{
    char bg_volume_name[16];
    int bg_block_bitmap;
    int bg_inode_bitmap;
    int bg_inode_table;
    int bg_free_blocks_count;
    int bg_free_inodes_count;
    int bg_used_dirs_count;
    char psw[16]; //password
    char bg_pad[24];
} ext2_group_desc;

//字节=4*3+4*8+32+24=100
typedef struct ext2_inode
{
    int i_mode;
    int i_size;
    int i_blocks;
    time_t access_time;
    time_t create_time;
    time_t modify_time;
    time_t delete_time;
    int i_block[8]; //指向数据块的指针
    char i_pad[24];
} ext2_inode;

//16+15+1=32
//这个目录入口属于文件和目录共有的
typedef struct ext2_dir_entry
{
    int inode;
    int rec_len; //目录项长度
    int name_len;
    int file_type; //1.普通文件2.目录文件
    char name[EXT2_NAME_LEN];
    char dir_pad;
} ext2_entry;

extern ext2_group_desc group_desc;
extern ext2_inode inode;
extern ext2_entry dir;
extern FILE *f;
extern _u32 last_allco_inode; //上次分配的索引节点
extern _u32 last_allco_block; //上次分配的数据块号

#endif