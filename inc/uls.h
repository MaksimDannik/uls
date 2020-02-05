#ifndef PATH_H
#define PATH_H

#include <errno.h>
#include "libmx/inc/libmx.h"
#include "sys/stat.h"
#include <sys/types.h>//opendir
#include <dirent.h> // opendir readdir
#include <limits.h> // limits PATH_MAX

#define MX_IS_BLK(mode) (((mode) & S_IFMT) == S_IFBLK)
#define MX_IS_CHR(mode) (((mode) & S_IFMT) == S_IFCHR)
#define MX_IS_DIR(mode) (((mode) & S_IFMT) == S_IFDIR)
#define MX_IS_LNK(mode) (((mode) & S_IFMT) == S_IFLNK)
#define MX_IS_SOCK(mode) (((mode) & S_IFMT) == S_IFSOCK)
#define MX_IS_FIFO(mode) (((mode) & S_IFMT) == S_IFIFO)
#define MX_IS_WHT(mode) (((mode) & S_IFMT) == S_IFWHT)
#define MX_IS_REG(mode) (((mode) & S_IFMT) == S_IFREG)

#define MY_FLAGS "LARarls" //our flags

typedef struct stat t_st;





// typedef struct s_li {
//     char *name;
//     char *path;
//     char *error// = mx_strdup(strerror(errno));
//     int index;
//     struct stat info;
//     struct s_li *open;// open dir // reddir//////
//     struct s_li *next;
// }   t_li;






typedef struct s_dir{
    char *name;

    struct stat st;
    //char *permis;
    
    struct s_dir *next;
} t_dir;

typedef struct s_file {
     char *name; 
     struct s_file *next;
 } t_file;

typedef struct s_mistake {
    char *name; 
    struct s_mistake *next;
} t_mistake;

typedef struct s_head {
    // t_ignore *ignore;
    // t_flag  *flag;
    t_dir *dir;
    t_file *file;
    t_mistake *mistake;


    
    char *check_flag;


} t_head;

void mx_check_mode(char **file, int argc, t_head *head); // file or dir
int mx_check_flag(char *file); //check flag valid or no whith error
t_dir *mx_create_dir(char *name);
t_file *mx_create_file(char *name);
void mx_write_dir_data(char *file, t_head *head, DIR *dir);

//mx_open_dir.c


#endif


